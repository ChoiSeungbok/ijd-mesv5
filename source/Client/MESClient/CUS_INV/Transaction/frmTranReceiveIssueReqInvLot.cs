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

namespace CUS_INV
{
    public partial class frmTranReceiveIssueReqInvLot : CUS_COM.frmTranForm01
    {
        public frmTranReceiveIssueReqInvLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "
        
        private enum REQUEST
        {
            REQ_NO,                 // 1 : 불출 요청 NO
            REQ_USER,               // 2 : 불출 요청자
            FROM_OPER,              // 3 : FROM 공정
            FROM_OPER_DESC,         // 4 : FROM 공정명
            AREA_ID,                // 5 : 불출 요청 사업부
            SUB_AREA_ID,            // 6 : 불출 요청 작업장
            OPER,                   // 7 : 불출 요청 공정
            OPER_DESC,              // 8 : 불출 요청 공정명
            REQ_TIME,               // 9 : 불출 요청 시간
            REQ_STATUS              // 10 : 불출 요청 상태
        }
        private enum MAT
        {
            REQ_NO,                  // 1 : 불출 요청 NO
            MAT_ID,                  // 2 : 제품
            MAT_VER,                 // 3 : 버전
            MAT_DESC,                // 4 : 제품명
            REQ_STATUS,              // 5 : 불출 요청 상태
            REQ_QTY,                 // 6 : 요청 수량
            REG_QTY,                 // 7 : 등록 수량
            UNIT                     // 8 : 단위
        }

        private enum LOT
        {
            CHK,                     // 1 : CHECK
            INV_LOT_ID,              // 2 : 자재 LOT ID
            REQ_NO,                  // 3 : 불출 요청 NO
            REQ_STATUS,              // 4 : 불출 요청 상태
            MAT_ID,                  // 5 : 제품
            MAT_VER,                 // 6 : 버전
            MAT_DESC,                // 7 : 제품명
            QTY,                     // 8 : 수량
            UNIT,                    // 9 : 단위
        }

        #endregion

        #region " Variable Definition "
        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 자재 불출 요청 마스터 정보 조회
        private void ViewIssueRequestList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[9];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;
                
                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = "";

                dvcArgu[3].sCondition_ID = "TO_OPER";
                dvcArgu[3].sCondition_Value = cdvReqOper.Text;

                dvcArgu[4].sCondition_ID = "REQ_NO";
                dvcArgu[4].sCondition_Value = txtRequestNo.Text;

                dvcArgu[5].sCondition_ID = "REQ_USER";
                dvcArgu[5].sCondition_Value = cdvRequestUser.Text;

                dvcArgu[6].sCondition_ID = "OPER";
                dvcArgu[6].sCondition_Value = cdvFromOper.Text;

                dvcArgu[7].sCondition_ID = "FROM_DATE";
                dvcArgu[7].sCondition_Value = dtpFromWorkDate.Text.Replace("-", "") + "000000";

                dvcArgu[8].sCondition_ID = "TO_DATE";
                dvcArgu[8].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";

                if (TPDR.GetDataOne("", ref dt, "CINV2011-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdRequestList);
                    return;
                }

                MPCF.ClearList(spdRequestList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdRequestList_Sheet1.RowCount++;

                    spdRequestList_Sheet1.Cells[i, (int)REQUEST.REQ_NO].Value = dt.Rows[i]["REQ_NO"];
                    spdRequestList_Sheet1.Cells[i, (int)REQUEST.REQ_USER].Value = dt.Rows[i]["REQ_USER"];
                    spdRequestList_Sheet1.Cells[i, (int)REQUEST.FROM_OPER].Value = dt.Rows[i]["OPER"];
                    spdRequestList_Sheet1.Cells[i, (int)REQUEST.FROM_OPER_DESC].Value = dt.Rows[i]["FROM_OPER_DESC"];
                    spdRequestList_Sheet1.Cells[i, (int)REQUEST.AREA_ID].Value = dt.Rows[i]["TO_AREA_ID"];
                    spdRequestList_Sheet1.Cells[i, (int)REQUEST.SUB_AREA_ID].Value = dt.Rows[i]["TO_SUB_AREA_ID"];
                    spdRequestList_Sheet1.Cells[i, (int)REQUEST.OPER].Value = dt.Rows[i]["TO_OPER"];
                    spdRequestList_Sheet1.Cells[i, (int)REQUEST.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdRequestList_Sheet1.Cells[i, (int)REQUEST.REQ_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["REQ_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdRequestList_Sheet1.Cells[i, (int)REQUEST.REQ_STATUS].Value = dt.Rows[i]["REQ_STATUS"];
                }
                MPCF.FitColumnHeader(spdRequestList);
                
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 자재 불출 요청 세부 정보 조회
        private void ViewIssueRequestDetailList(string sReqNo)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REQ_NO";
                dvcArgu[1].sCondition_Value = sReqNo;

                if (TPDR.GetDataOne("", ref dt, "CINV2010-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdReqDetailList);
                    return;
                }

                MPCF.ClearList(spdReqDetailList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdReqDetailList_Sheet1.RowCount++;

                    spdReqDetailList_Sheet1.Cells[i, (int)MAT.REQ_NO].Value = dt.Rows[i]["REQ_NO"];
                    spdReqDetailList_Sheet1.Cells[i, (int)MAT.MAT_ID].Value = dt.Rows[i]["REQ_MAT_ID"];
                    spdReqDetailList_Sheet1.Cells[i, (int)MAT.MAT_VER].Value = dt.Rows[i]["REQ_MAT_VER"];
                    spdReqDetailList_Sheet1.Cells[i, (int)MAT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdReqDetailList_Sheet1.Cells[i, (int)MAT.REQ_STATUS].Value = dt.Rows[i]["REQ_STATUS"];
                    spdReqDetailList_Sheet1.Cells[i, (int)MAT.REQ_QTY].Value = dt.Rows[i]["REQ_QTY"];
                    spdReqDetailList_Sheet1.Cells[i, (int)MAT.REG_QTY].Value = dt.Rows[i]["REG_QTY"];
                    spdReqDetailList_Sheet1.Cells[i, (int)MAT.UNIT].Value = dt.Rows[i]["UNIT"];
                }
                MPCF.FitColumnHeader(spdReqDetailList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 자재 불출 요청 LOT 정보 조회
        private void ViewIssueRequestInvLotList(string sReqNo, string sReqMatId, string sReqMatVer)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REQ_NO";
                dvcArgu[1].sCondition_Value = sReqNo;

                dvcArgu[2].sCondition_ID = "REQ_MAT_ID";
                dvcArgu[2].sCondition_Value = sReqMatId;

                dvcArgu[3].sCondition_ID = "REQ_MAT_VER";
                dvcArgu[3].sCondition_Value = sReqMatVer;

                if (TPDR.GetDataOne("", ref dt, "CINV2010-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdIssueInvLotList);
                    return;
                }

                MPCF.ClearList(spdIssueInvLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdIssueInvLotList_Sheet1.RowCount++;

                    spdIssueInvLotList_Sheet1.SetValue(i, (int)LOT.CHK, false);
                    spdIssueInvLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Value = dt.Rows[i]["INV_LOT_ID"];
                    spdIssueInvLotList_Sheet1.Cells[i, (int)LOT.REQ_NO].Value = dt.Rows[i]["REQ_NO"];
                    spdIssueInvLotList_Sheet1.Cells[i, (int)LOT.REQ_STATUS].Value = dt.Rows[i]["REQ_STATUS"];
                    spdIssueInvLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdIssueInvLotList_Sheet1.Cells[i, (int)LOT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdIssueInvLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdIssueInvLotList_Sheet1.Cells[i, (int)LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdIssueInvLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                }

                MPCF.FitColumnHeader(spdIssueInvLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 불출 요청 생성 및 수정
        private bool SaveIssueRequest()
        {
            TRSNode in_node = new TRSNode("save_Issue_Request_Lot_In");
            TRSNode out_node = new TRSNode("save_Issue_Request_Lot_Out");
            TRSNode Req_Lot_list;

            int i_count = 0;
            double d_total_qty = 0;
            bool b_check_flag = false;

            try
            {
                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '2';
                in_node.AddString("REQ_NO", spdReqDetailList.ActiveSheet.Cells[spdReqDetailList.ActiveSheet.ActiveRowIndex, (int)MAT.REQ_NO].Text);
                in_node.AddString("REQ_MAT_ID", spdReqDetailList.ActiveSheet.Cells[spdReqDetailList.ActiveSheet.ActiveRowIndex, (int)MAT.MAT_ID].Text);
                in_node.AddInt("REQ_MAT_VER", MPCF.ToInt(spdReqDetailList.ActiveSheet.Cells[spdReqDetailList.ActiveSheet.ActiveRowIndex, (int)MAT.MAT_VER].Text));
                in_node.AddString("TRAN_COMMENT", "");
                
                for (int i = 0; i < spdIssueInvLotList_Sheet1.RowCount; i++)
                {
                    if (spdIssueInvLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        b_check_flag = true;

                        if (spdIssueInvLotList_Sheet1.Cells[i, (int)LOT.REQ_STATUS].Text.ToString().ToUpper() == "ISSUE")
                        {
                            Req_Lot_list = in_node.AddNode("REQ_LOT_LIST");
                            Req_Lot_list.AddString("REQ_LOT_ID", spdIssueInvLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Text);
                            d_total_qty += MPCF.ToDbl(spdIssueInvLotList_Sheet1.Cells[i, (int)LOT.QTY].Text);
                            i_count++;
                        }
                    }
                }

                in_node.AddDouble("QTY", d_total_qty);

                if(i_count <= 0)
                {
                    if(b_check_flag == true)
                    {
                        //CMN468 ERROR - 선택된 데이터는 이미 처리되었습니다.
                        MPCF.ShowMsgBox(MPCF.GetMessage(468));
                    }
                    else
                    {
                        //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    }
                    
                    return false;
                }
                
                if (MPCR.CallService("CUS_INV", "CUS_INV_Receive_Issue_Request_Lot", in_node, ref out_node) == false)
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

        //벨리데이션 체크
        private bool CheckCondition(string sType)
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

                //if (MPCF.Trim(cdvWorkPlace.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                //    cdvWorkPlace.Focus();
                //    return false;
                //}

                switch (sType)
                {
                    case "SAVE":

                        if (spdReqDetailList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdIssueInvLotList_Sheet1.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
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

        //초기화 함수
        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":
                        
                        MPCF.ClearList(spdRequestList);
                        MPCF.ClearList(spdReqDetailList);
                        MPCF.ClearList(spdIssueInvLotList);
                        break;
                        
                    case "ALL":

                        this.cdvDept.Text = "";
                        this.cdvFromOper.Text = "";
                        //this.cdvWorkPlace.Text = "";
                        this.cdvReqOper.Text = "";
                        this.txtRequestNo.Text = "";
                        this.cdvRequestUser.Text = "";
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);

                        MPCF.ClearList(spdRequestList);
                        MPCF.ClearList(spdReqDetailList);
                        MPCF.ClearList(spdIssueInvLotList);
                        break;

                    case "REQ_CLICK":

                        MPCF.ClearList(spdReqDetailList);
                        MPCF.ClearList(spdIssueInvLotList);
                        break;

                    case "REQ_DETAIL_CLICK":

                        MPCF.ClearList(spdIssueInvLotList);
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region Event
        private void frmTranReceiveIssueReqInvLot_Load(object sender, EventArgs e)
        {
            try
            {
                this.dtpToWorkDate.Value = DateTime.Now;
                this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        

        //전체 클리어
        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                ClearList("ALL");
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
                if (CheckCondition("VIEW") == false)
                    return;

                ClearList("VIEW");

                ViewIssueRequestList();
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
                if (CheckCondition("SAVE") == false)
                    return;

                if (SaveIssueRequest())
                {
                    btnView_Click(null, null);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvReqOper_ButtonPress(object sender, EventArgs e)
        {
            cdvReqOper.Init();
            MPCF.InitListView(cdvReqOper.GetListView);
            cdvReqOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
            cdvReqOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvReqOper.SelectedSubItemIndex = 0;
            cdvReqOper.DisplaySubItemIndex = 1;

            if (COM_LIST.ViewOperationList(cdvReqOper.GetListView, '4', cdvDept.Text, "", "", "", 'Y') == false)
            {
                return;
            }

            cdvReqOper.InsertEmptyRow(0, 1);

            ClearList("VIEW");
        }

        private void cdvFromOper_ButtonPress(object sender, EventArgs e)
        {
            cdvFromOper.Init();
            MPCF.InitListView(cdvFromOper.GetListView);
            cdvFromOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
            cdvFromOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvFromOper.SelectedSubItemIndex = 0;
            cdvFromOper.DisplaySubItemIndex = 1;

            if (COM_LIST.ViewOperationList(cdvFromOper.GetListView, 'G', cdvDept.Text, "", "", "", 'Y') == false)
            {
                return;
            }

            cdvFromOper.InsertEmptyRow(0, 1);
        }

        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                ClearList("ALL");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvRequestUser_ButtonPress(object sender, EventArgs e)
        {
            cdvRequestUser.Init();
            MPCF.InitListView(cdvRequestUser.GetListView);
            cdvRequestUser.Columns.Add("Operation", 50, HorizontalAlignment.Left);
            cdvRequestUser.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvRequestUser.SelectedSubItemIndex = 0;
            cdvRequestUser.DisplaySubItemIndex = 1;

            if (COM_LIST.ViewWorkerList(cdvRequestUser.GetListView, "CINV2009-004", cdvDept.Text, "") == false)
            {
                return;
            }

            cdvRequestUser.InsertEmptyRow(0, 1);
        }
        
        private void spdRequestList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.Row < 0)
                {
                    return;
                }

                if (e.ColumnHeader == true)
                {
                    return;
                }

                string sReqNo = "";
                ClearList("REQ_CLICK");

                for (int i = 0; i < spdRequestList.ActiveSheet.RowCount; i++)
                {
                    spdRequestList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdRequestList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                sReqNo = spdRequestList.ActiveSheet.Cells[e.Row, (int)REQUEST.REQ_NO].Text;

                ViewIssueRequestDetailList(sReqNo);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdReqDetailList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.Row < 0)
                {
                    return;
                }

                if (e.ColumnHeader == true)
                {
                    return;
                }

                string sReqNo = "";
                string sReqMatId = "";
                string sReqMatVer = "";

                ClearList("REQ_DETAIL_CLICK");

                for (int i = 0; i < spdReqDetailList.ActiveSheet.RowCount; i++)
                {
                    spdReqDetailList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdReqDetailList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                sReqNo = spdReqDetailList.ActiveSheet.Cells[e.Row, (int)MAT.REQ_NO].Text;
                sReqMatId = spdReqDetailList.ActiveSheet.Cells[e.Row, (int)MAT.MAT_ID].Text;
                sReqMatVer = spdReqDetailList.ActiveSheet.Cells[e.Row, (int)MAT.MAT_VER].Text;

                //불출 요청된 LOT 조회
                ViewIssueRequestInvLotList(sReqNo, sReqMatId, sReqMatVer);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdIssueInvLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdIssueInvLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdIssueInvLotList, e.Row, e.Column, true, true, false);
                }
            }
        }
        #endregion
    }
}
