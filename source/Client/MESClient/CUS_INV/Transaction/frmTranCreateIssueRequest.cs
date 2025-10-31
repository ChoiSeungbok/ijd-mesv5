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
    public partial class frmTranCreateIssueRequest : CUS_COM.frmTranForm01
    {
        public frmTranCreateIssueRequest()
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
            CHK,                     // 1 : CHECK
            MAT_ID,                  // 2 : 제품
            MAT_VER,                 // 3 : 버전
            MAT_DESC,                // 4 : 제품명
            QTY,                     // 5 : 수량
            UNIT                     // 6 : 단위
        }

        private enum REQ_MAT
        {
            CHK,                     // 1 : CHECK
            MAT_ID,                  // 2 : 제품
            MAT_VER,                 // 3 : 버전
            MAT_DESC,                // 4 : 제품명
            QTY,                     // 5 : 수량
            REQ_QTY,                 // 6 : 요청 수량
            UNIT                     // 76 : 단위
        }

        #endregion

        #region " Variable Definition "
        bool newFlag = false;
        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnMatView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnConfirm.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnCancelConfirm.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnNew.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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

                dvcArgu[4].sCondition_ID = "REQ_USER";
                dvcArgu[4].sCondition_Value = cdvRequestUser.Text;

                dvcArgu[5].sCondition_ID = "REQ_NO";
                dvcArgu[5].sCondition_Value = txtRequestNo.Text;

                dvcArgu[6].sCondition_ID = "OPER";
                dvcArgu[6].sCondition_Value = cdvFromOper.Text;

                dvcArgu[7].sCondition_ID = "FROM_DATE";
                dvcArgu[7].sCondition_Value = dtpFromWorkDate.Text.Replace("-", "") + "000000";

                dvcArgu[8].sCondition_ID = "TO_DATE";
                dvcArgu[8].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";

                if (TPDR.GetDataOne("", ref dt, "CINV2009-002", dvcArgu, false, false, ref sSql) == false)
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

                newFlag = false;

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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REQ_NO";
                dvcArgu[1].sCondition_Value = sReqNo;

                dvcArgu[2].sCondition_ID = "AREA_ID";
                dvcArgu[2].sCondition_Value = cdvDept.Text;

                if (TPDR.GetDataOne("", ref dt, "CINV2009-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdIssueMatList);
                    return;
                }

                MPCF.ClearList(spdIssueMatList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdIssueMatList_Sheet1.RowCount++;

                    spdIssueMatList_Sheet1.SetValue(i, (int)REQ_MAT.CHK, false);
                    spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.MAT_ID].Value = dt.Rows[i]["REQ_MAT_ID"];
                    spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.MAT_VER].Value = dt.Rows[i]["REQ_MAT_VER"];
                    spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.QTY].Value = dt.Rows[i]["QTY"];
                    spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.REQ_QTY].Value = dt.Rows[i]["REQ_QTY"];
                    spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.UNIT].Value = dt.Rows[i]["UNIT"];
                }
                MPCF.FitColumnHeader(spdIssueMatList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //자재 리스트 조회 함수
        private void ViewMatList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_TYPE";
                dvcArgu[1].sCondition_Value = cdvMatType.Text + "%";

                dvcArgu[2].sCondition_ID = "AREA_ID";
                dvcArgu[2].sCondition_Value = cdvDept.Text;
                
                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvFromOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CINV2009-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdMatList);
                    return;
                }

                MPCF.ClearList(spdMatList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMatList_Sheet1.RowCount++;

                    spdMatList_Sheet1.SetValue(i, (int)MAT.CHK, false);
                    spdMatList_Sheet1.Cells[i, (int)MAT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMatList_Sheet1.Cells[i, (int)MAT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMatList_Sheet1.Cells[i, (int)MAT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdMatList_Sheet1.Cells[i, (int)MAT.QTY].Value = dt.Rows[i]["QTY"];
                    spdMatList_Sheet1.Cells[i, (int)MAT.UNIT].Value = dt.Rows[i]["UNIT"];
                }

                MPCF.FitColumnHeader(spdMatList);

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
            TRSNode in_node = new TRSNode("save_Issue_Request_In");
            TRSNode out_node = new TRSNode("save_Issue_Request_Out");
            TRSNode Req_Mat_list;

            try
            {
                MPCR.SetInMsg(in_node);

                if (newFlag == true)
                {
                    in_node.ProcStep = '1';
                    in_node.AddString("REQ_NO", "");
                }
                else
                {
                    in_node.ProcStep = '2';
                    in_node.AddString("REQ_NO", spdRequestList.ActiveSheet.Cells[spdRequestList.ActiveSheet.ActiveRowIndex, (int)REQUEST.REQ_NO].Text);
                }

                in_node.AddString("FROM_OPER", cdvFromOper.Text);
                in_node.AddString("REQ_OPER", cdvReqOper.Text);
                in_node.AddString("REQ_WORKER_ID", cdvRequestUser.Text);
                in_node.AddString("TRAN_COMMENT", "");

                for (int i = 0; i < spdIssueMatList_Sheet1.RowCount; i++)
                {
                    if (spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        Req_Mat_list = in_node.AddNode("REQ_MAT_LIST");
                        Req_Mat_list.AddString("REQ_MAT_ID", spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.MAT_ID].Text);
                        Req_Mat_list.AddInt("REQ_MAT_VER", MPCF.ToInt(spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.MAT_VER].Text));
                        Req_Mat_list.AddDouble("REQ_QTY", MPCF.ToDbl(spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.REQ_QTY].Text));

                        // 재고 수량, 요청 수량 Validation
                        if(MPCF.ToDbl(spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.REQ_QTY].Text) > MPCF.ToDbl(spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.QTY].Text))
                        {
                            //CMN126 ERROR -입력한 값이 한계값을 넘었습니다.다른 수를 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(126));
                            return false;
                        }

                        // 재고 수량, 요청 수량 Validation
                        if (MPCF.ToDbl(spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.REQ_QTY].Text) <= 0)
                        {
                            //CMN114 ERROR -0보다 큰 값을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(114));
                            return false;
                        }
                    }
                }

                if (MPCR.CallService("CUS_INV", "CUS_INV_Create_Issue_Request", in_node, ref out_node) == false)
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

        // 불출 요청 삭제
        private bool DeleteIssueRequest()
        {
            TRSNode in_node = new TRSNode("delete_Issue_Request_In");
            TRSNode out_node = new TRSNode("delete_Issue_Request_Out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("REQ_NO", spdRequestList.ActiveSheet.Cells[spdRequestList.ActiveSheet.ActiveRowIndex, (int)REQUEST.REQ_NO].Text);
                
                if (MPCR.CallService("CUS_INV", "CUS_INV_Delete_Issue_Request", in_node, ref out_node) == false)
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

        // 불출 요청 확정
        private bool ConfirmIssueRequest()
        {
            TRSNode in_node = new TRSNode("confirm_Issue_Request_In");
            TRSNode out_node = new TRSNode("confirm_Issue_Request_Out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("REQ_NO", spdRequestList.ActiveSheet.Cells[spdRequestList.ActiveSheet.ActiveRowIndex, (int)REQUEST.REQ_NO].Text);

                if (MPCR.CallService("CUS_INV", "CUS_INV_Confirm_Issue_Request", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);

                ViewPrintLabel(in_node);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        // 불출 요청 확정
        private bool CancelConfirmIssueRequest()
        {
            TRSNode in_node = new TRSNode("confirm_Issue_Request_In");
            TRSNode out_node = new TRSNode("confirm_Issue_Request_Out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("REQ_NO", spdRequestList.ActiveSheet.Cells[spdRequestList.ActiveSheet.ActiveRowIndex, (int)REQUEST.REQ_NO].Text);

                if (MPCR.CallService("CUS_INV", "CUS_INV_Confirm_Issue_Request", in_node, ref out_node) == false)
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

                if (MPCF.Trim(cdvReqOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblRequestOper.Text + "]");
                    cdvReqOper.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvFromOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFromOper.Text + "]");
                    cdvFromOper.Focus();
                    return false;
                }

                switch (sType)
                {
                    case "SAVE":
                        if(newFlag == true)
                        {
                            if (MPCF.Trim(cdvRequestUser.Text) == "")
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblRequestUser.Text + "]");
                                cdvRequestUser.Focus();
                                return false;
                            }
                        }
                        else
                        {
                            if (spdRequestList.ActiveSheet.RowCount == 0)
                            {
                                //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(109));
                                return false;
                            }
                        }
                        
                        if (spdIssueMatList_Sheet1.RowCount == 0)
                        {
                            return false;
                        }
                        break;

                    case "DELETE":
                    case "CONFIRM":
                    case "CANCEL_CONFIRM":
                    case "PRINT":
                        if (spdRequestList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
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

                        this.txtRequestNo.ReadOnly = false;
                        MPCF.ClearList(spdRequestList);
                        MPCF.ClearList(spdMatList);
                        MPCF.ClearList(spdIssueMatList);
                        
                        this.cdvMatType.Text = "";
                        this.txtMatDesc.Text = "";
                        break;
                        
                    case "ALL":

                        this.cdvDept.Text = "";
                        //this.cdvWorkPlace.Text = "";
                        this.cdvFromOper.Text = "";
                        this.cdvReqOper.Text = "";
                        this.cdvRequestUser.Text = "";
                        this.txtRequestNo.Text = "";
                        this.txtRequestNo.ReadOnly = false;
                        newFlag = false;
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);

                        MPCF.ClearList(spdRequestList);
                        MPCF.ClearList(spdMatList);
                        MPCF.ClearList(spdIssueMatList);

                        this.cdvMatType.Text = "";
                        this.txtMatDesc.Text = "";
                        break;

                    case "REQ_CLICK":

                        this.txtRequestNo.ReadOnly = false;
                        MPCF.ClearList(spdMatList);
                        MPCF.ClearList(spdIssueMatList);

                        this.cdvMatType.Text = "";
                        this.txtMatDesc.Text = "";
                        break;

                    case "NEW":

                        this.cdvRequestUser.Text = "";
                        this.txtRequestNo.Text = "";
                        this.txtRequestNo.ReadOnly = true;

                        MPCF.ClearList(spdRequestList);
                        MPCF.ClearList(spdMatList);
                        MPCF.ClearList(spdIssueMatList);

                        this.cdvMatType.Text = "";
                        this.txtMatDesc.Text = "";
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public bool ViewPrintLabel(TRSNode in_node)
        {
            string sFileName = "prd702q";
            try
            {
                CSCF.ViewLabelList(sFileName, in_node, 'I');

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        #endregion

        #region Event
        private void frmTranCreateIssueRequest_Load(object sender, EventArgs e)
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

        private void btnAdd_Click(object sender, EventArgs e)
        {
            try
            {
                string sMatId = "";
                bool addFlag = true;
                int iRow = 0;

                for (int i = spdMatList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdMatList_Sheet1.Cells[i, (int)MAT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        addFlag = true;

                        sMatId = spdMatList_Sheet1.Cells[i, (int)MAT.MAT_ID].Text;

                        for (int k = 0; k < spdIssueMatList_Sheet1.RowCount; k++)
                        {
                            if (string.Equals(spdIssueMatList_Sheet1.Cells[k, (int)REQ_MAT.MAT_ID].Text, sMatId))
                            {
                                addFlag = false;
                                continue;
                            }
                        }

                        if(addFlag == true)
                        {
                            iRow = spdIssueMatList_Sheet1.RowCount++;

                            spdIssueMatList_Sheet1.SetValue(iRow, (int)REQ_MAT.CHK, true);
                            spdIssueMatList_Sheet1.Cells[iRow, (int)REQ_MAT.MAT_ID].Value = spdMatList_Sheet1.Cells[i, (int)MAT.MAT_ID].Text;
                            spdIssueMatList_Sheet1.Cells[iRow, (int)REQ_MAT.MAT_VER].Value = spdMatList_Sheet1.Cells[i, (int)MAT.MAT_VER].Text;
                            spdIssueMatList_Sheet1.Cells[iRow, (int)REQ_MAT.MAT_DESC].Value = spdMatList_Sheet1.Cells[i, (int)MAT.MAT_DESC].Text;
                            spdIssueMatList_Sheet1.Cells[iRow, (int)REQ_MAT.QTY].Value = spdMatList_Sheet1.Cells[i, (int)MAT.QTY].Text;
                            spdIssueMatList_Sheet1.Cells[iRow, (int)REQ_MAT.REQ_QTY].Value = spdMatList_Sheet1.Cells[i, (int)MAT.QTY].Text;
                            spdIssueMatList_Sheet1.Cells[iRow, (int)REQ_MAT.UNIT].Value = spdMatList_Sheet1.Cells[i, (int)MAT.UNIT].Text;
                        }

                        spdMatList_Sheet1.RemoveRows(i, 1);
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
            try
            {
                string sMatId = "";
                bool addFlag = true;
                int iRow = 0;

                for (int i = spdIssueMatList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdIssueMatList_Sheet1.Cells[i, (int)MAT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        addFlag = true;

                        sMatId = spdIssueMatList_Sheet1.Cells[i, (int)MAT.MAT_ID].Text;

                        for (int k = 0; k < spdMatList_Sheet1.RowCount; k++)
                        {
                            if (string.Equals(spdMatList_Sheet1.Cells[k, (int)REQ_MAT.MAT_ID].Text, sMatId))
                            {
                                addFlag = false;
                                continue;
                            }
                        }

                        if (addFlag == true)
                        {
                            iRow = spdMatList_Sheet1.RowCount++;

                            spdMatList_Sheet1.SetValue(iRow, (int)REQ_MAT.CHK, true);
                            spdMatList_Sheet1.Cells[iRow, (int)MAT.MAT_ID].Value = spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.MAT_ID].Text;
                            spdMatList_Sheet1.Cells[iRow, (int)MAT.MAT_VER].Value = spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.MAT_VER].Text;
                            spdMatList_Sheet1.Cells[iRow, (int)MAT.MAT_DESC].Value = spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.MAT_DESC].Text;
                            spdMatList_Sheet1.Cells[iRow, (int)MAT.QTY].Value = spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.QTY].Text;
                            spdMatList_Sheet1.Cells[iRow, (int)MAT.UNIT].Value = spdIssueMatList_Sheet1.Cells[i, (int)REQ_MAT.UNIT].Text;
                        }

                        spdIssueMatList_Sheet1.RemoveRows(i, 1);
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

        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("DELETE") == false)
                    return;

                if (DeleteIssueRequest())
                {
                    btnView_Click(null, null);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnMatView_Click(object sender, EventArgs e)
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

                if (MPCF.Trim(cdvFromOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFromOper.Text + "]");
                    cdvFromOper.Focus();
                    return;
                }

                ViewMatList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnNew_Click(object sender, EventArgs e)
        {
            try
            {
                ClearList("NEW");
                newFlag = true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnConfirm_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("CONFIRM") == false)
                    return;

                if (ConfirmIssueRequest())
                {
                    btnView_Click(null, null);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnCancelConfirm_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("CANCEL_CONFIRM") == false)
                    return;

                if (CancelConfirmIssueRequest())
                {
                    btnView_Click(null, null);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("PRINT") == false)
                    return;

                TRSNode in_node = new TRSNode("print_label_Request_In");
                TRSNode out_node = new TRSNode("print_label_Request_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                if(string.Equals(spdRequestList.ActiveSheet.Cells[spdRequestList.ActiveSheet.ActiveRowIndex, (int)REQUEST.REQ_STATUS].Text, "REQUEST"))
                {
                    in_node.AddString("REQ_NO", spdRequestList.ActiveSheet.Cells[spdRequestList.ActiveSheet.ActiveRowIndex, (int)REQUEST.REQ_NO].Text);
                    ViewPrintLabel(in_node);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
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

        private void cdvMatType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvMatType.Init();
                MPCF.InitListView(cdvMatType.GetListView);
                cdvMatType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvMatType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvMatType.SelectedSubItemIndex = 0;
                cdvMatType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvMatType.GetListView, '1', MPGC.MP_WIP_MATERIAL_TYPE) == false)
                {
                    return;
                }

                cdvMatType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
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

        private void spdMatList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdMatList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdMatList, e.Row, e.Column, true, true, false);
                }
            }
        }

        private void spdIssueMatList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdIssueMatList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdIssueMatList, e.Row, e.Column, true, true, false);
                }
            }
        }

        #endregion

        
    }
}
