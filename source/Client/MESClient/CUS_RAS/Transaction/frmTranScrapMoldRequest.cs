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
using Miracom.UI.Controls.MCCodeView;

namespace CUS_RAS
{
    public partial class frmTranScrapMoldRequest : CUS_COM.frmTranForm01
    {
        public frmTranScrapMoldRequest()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum REQUEST_INFO : int
        {
            REQ_NO,             // 1. 요청번호
            REQ_USER_ID,        // 2. 요청자 ID
            REQ_USER_DESC,      // 3. 요청자명
            OPER,               // 4. 요청 공정
            OPER_DESC,          // 5. 요청 공정명
            REQ_TIME,           // 6. 요청 일시
            REQ_STATUS,         // 7. 요청 상태
            REQ_STATUS_DESC,    // 7. 요청 상태명
            REQ_COMMENT,        // 8. 요청 비고
            AREA_ID,            // 9. 사업부
            AREA_DESC,          // 10. 사업부명
            SUB_AREA_ID,        // 11.사업장
            SUB_AREA_DESC,      // 12.사업장명
        }

        private enum SCRAP_MOLD_INFO : int
        {
            REQ_NO,             // 1. 요청번호
            TOOL_ID,            // 2. 금형 번호
            TOOL_DESC,          // 3. 금형 명
            TOOL_GRP_DESC,      // 4, 금형 모델 명
            TOOL_TYPE_DESC,     // 5. 금형 구분 명
            UNIT,               // 6. 단위
            QTY                 // 7. 수량
        }

        private enum MOLD_INFO : int
        {
            CHECK,          // 1. 선택
            MOLD_CODE,      // 2. 금형 코드
            MOLD_DESC       // 3. 금형 명
        }

        #endregion

        #region " Variable Definition "

        int selected_row = -1;
        string selected_request_no = "";
        string selected_oper = "";
        bool newFlag = false;

        #endregion

        #region " Function Defintion "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnConfirm.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnCancelConfirm.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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

                        if (MPCF.Trim(cdvWorkPlace.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                            cdvWorkPlace.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
                            return false;
                        }

                        break;

                    case CSGC.CHECK.SAVE:
                        if(newFlag!= true && MPCF.Trim(txtReqNo.Text)=="")
                        {
                            //CMN458 ERROR - 선택된 요청 번호가 없습니다. 먼저 요청 번호를 선택하여 주세요
                            MPCF.ShowMsgBox(MPCF.GetMessage(458));
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

                        if (MPCF.Trim(cdvRequestOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblRequestOper.Text + "]");
                            cdvRequestOper.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvRequestUserId.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblRequestUserId.Text + "]");
                            cdvRequestUserId.Focus();
                            return false;
                        }
                        break;

                    case CSGC.CHECK.CONFIRM:
                    case CSGC.CHECK.CANCEL:
                    case CSGC.CHECK.DELETE:
                        if (MPCF.Trim(txtReqNo.Text) == "")
                        {
                            //CMN458 ERROR - 선택된 요청 번호가 없습니다. 먼저 요청 번호를 선택하여 주세요
                            MPCF.ShowMsgBox(MPCF.GetMessage(458));
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

        // 초기화 함수
        public void ClearData(string sType)
        {
            try
            {
                switch(sType)
                {
                    case "ALL":
                        selected_row = -1;
                        selected_request_no = "";
                        selected_oper = "";
                        newFlag = false;

                        ClearRequestInfo();

                        //상세 정보리스트 초기화
                        MPCF.ClearList(spdDetailInfo);

                        //금형리스트, 요청 리스트 초기화
                        MPCF.ClearList(spdMoldList);
                        MPCF.ClearList(spdRequestList);                      
                        break;

                    case "VIEW":
                        newFlag = false;

                        //상세 정보리스트 초기화
                        MPCF.ClearList(spdDetailInfo);

                        //금형리스트, 요청 리스트 초기화
                        MPCF.ClearList(spdMoldList);
                        MPCF.ClearList(spdRequestList);

                        break;

                    case "NEW":                      
                        MPCF.ClearList(spdRequestList);
                        selected_oper = "";
                        newFlag = true;

                        ClearRequestInfo();

                        break;
                }
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //요청 정보 초기화
        public void ClearRequestInfo()
        {
            try
            {
                txtReqNo.Text = "";
                cdvReqStatus.Text = "";
                cdvAreaId.Text = "";
                cdvSubAreaId.Text = "";
                cdvRequestOper.Text = "";
                cdvRequestUserId.Text = "";
                txtConfirmComment.Text = "";
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 요청 공정 변경
        private void ChangeRequestOper()
        {
            try
            {
                selected_oper = cdvRequestOper.Text;

                ViewMoldList(selected_oper);
                ViewRequestList(selected_oper);
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 요청 상태 조회
        private  bool ViewGcmCodeList_Status(Control control, string sKey_1 = "")
        {
            string sViewID = "";
           
            try
            {
                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";
                int i = 0;

                sViewID = "CRAS2006-006";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "KEY_1";
                dvcArgu[1].sCondition_Value = sKey_1;

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return false;

                for (i = 0; i < dt.Rows.Count; i++)
                {                    
                    ((MCCodeView)control).Text = dt.Rows[i]["KEY_1"].ToString();
                    ((MCCodeView)control).DisplayText = dt.Rows[i]["DATA_1"].ToString();
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
        private void ViewRequestInfo()
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CRAS2006-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvOper.Text;

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
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.REQ_USER_ID].Value = dt.Rows[i]["REQ_USER_ID"];
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.REQ_USER_DESC].Value = dt.Rows[i]["REQ_USER_DESC"];
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.REQ_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["REQ_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME).Substring(0, 16);
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.REQ_STATUS].Value = dt.Rows[i]["REQ_STATUS"];
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.REQ_STATUS_DESC].Value = dt.Rows[i]["REQ_STATUS_DESC"];
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.REQ_COMMENT].Value = dt.Rows[i]["REQ_COMMENT"];
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_ID"];
                    spdRequestInfo_Sheet1.Cells[i, (int)REQUEST_INFO.SUB_AREA_DESC].Value = dt.Rows[i]["SUB_AREA_DESC"];

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

        // 금형 폐기 요청 상세 정보 조회(1)
        private void ViewDetailRequestInfo(int selectedRow)
        {
            try
            {
                txtReqNo.Text = spdRequestInfo_Sheet1.Cells[selectedRow, (int)REQUEST_INFO.REQ_NO].Text;
                cdvReqStatus.Text = spdRequestInfo_Sheet1.Cells[selectedRow, (int)REQUEST_INFO.REQ_STATUS].Text;
                cdvReqStatus.DisplayText = spdRequestInfo_Sheet1.Cells[selectedRow, (int)REQUEST_INFO.REQ_STATUS_DESC].Text;
                cdvAreaId.Text = spdRequestInfo_Sheet1.Cells[selectedRow, (int)REQUEST_INFO.AREA_ID].Text;
                cdvAreaId.DisplayText = spdRequestInfo_Sheet1.Cells[selectedRow, (int)REQUEST_INFO.AREA_DESC].Text; 
                cdvSubAreaId.Text = spdRequestInfo_Sheet1.Cells[selectedRow, (int)REQUEST_INFO.SUB_AREA_ID].Text; 
                cdvSubAreaId.DisplayText = spdRequestInfo_Sheet1.Cells[selectedRow, (int)REQUEST_INFO.SUB_AREA_DESC].Text;
                cdvRequestOper.Text = spdRequestInfo_Sheet1.Cells[selectedRow, (int)REQUEST_INFO.OPER].Text;
                cdvRequestOper.DisplayText = spdRequestInfo_Sheet1.Cells[selectedRow, (int)REQUEST_INFO.OPER_DESC].Text;
                cdvRequestUserId.Text = spdRequestInfo_Sheet1.Cells[selectedRow, (int)REQUEST_INFO.REQ_USER_ID].Text;
                cdvRequestUserId.DisplayText = spdRequestInfo_Sheet1.Cells[selectedRow, (int)REQUEST_INFO.REQ_USER_DESC].Text;
                txtConfirmComment.Text = spdRequestInfo_Sheet1.Cells[selectedRow, (int)REQUEST_INFO.REQ_COMMENT].Text;

                ChangeRequestOper();
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //금형 폐기 요청 상세 정보 조회(2)
        private void ViewDetailRequestInfo(string reqNo)
        {
            string sView_Id = "";
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CRAS2006-005";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REQ_NO";
                dvcArgu[1].sCondition_Value = reqNo;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    txtReqNo.Text = dt.Rows[i]["REQ_NO"].ToString();
                    cdvReqStatus.Text = dt.Rows[i]["REQ_STATUS"].ToString();
                    cdvReqStatus.DisplayText = dt.Rows[i]["REQ_STATUS_DESC"].ToString(); 
                    cdvAreaId.Text = dt.Rows[i]["AREA_ID"].ToString();
                    cdvAreaId.DisplayText = dt.Rows[i]["AREA_DESC"].ToString();
                    cdvSubAreaId.Text = dt.Rows[i]["SUB_AREA_ID"].ToString();
                    cdvSubAreaId.DisplayText = dt.Rows[i]["SUB_AREA_DESC"].ToString();
                    cdvRequestOper.Text = dt.Rows[i]["OPER"].ToString();
                    cdvRequestOper.DisplayText = dt.Rows[i]["OPER_DESC"].ToString();
                    cdvRequestUserId.Text = dt.Rows[i]["REQ_USER_ID"].ToString();
                    cdvRequestUserId.DisplayText = dt.Rows[i]["REQ_USER_DESC"].ToString();
                    txtConfirmComment.Text = dt.Rows[i]["REQ_COMMENT"].ToString();
                }

                ChangeRequestOper();
                return;             
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 폐기 요청된 금형 리스트 조회
        public void ViewScrapMoldList(string requestNo)
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
                    spdDetailInfo_Sheet1.RowCount++;

                    spdDetailInfo_Sheet1.Cells[i, (int)SCRAP_MOLD_INFO.REQ_NO].Value = dt.Rows[i]["REQ_NO"];
                    spdDetailInfo_Sheet1.Cells[i, (int)SCRAP_MOLD_INFO.TOOL_ID].Value = dt.Rows[i]["TOOL_ID"];
                    spdDetailInfo_Sheet1.Cells[i, (int)SCRAP_MOLD_INFO.TOOL_DESC].Value = dt.Rows[i]["TOOL_DESC"];
                    spdDetailInfo_Sheet1.Cells[i, (int)SCRAP_MOLD_INFO.TOOL_GRP_DESC].Value = dt.Rows[i]["TOOL_GRP_DESC"];
                    spdDetailInfo_Sheet1.Cells[i, (int)SCRAP_MOLD_INFO.TOOL_TYPE_DESC].Value = dt.Rows[i]["TOOL_TYPE_DESC"];
                    spdDetailInfo_Sheet1.Cells[i, (int)SCRAP_MOLD_INFO.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdDetailInfo_Sheet1.Cells[i, (int)SCRAP_MOLD_INFO.QTY].Value = dt.Rows[i]["QTY"];
                }
                MPCF.FitColumnHeader(spdDetailInfo);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //금형 리스트 조회
        private void ViewMoldList(string selectedOper)
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CRAS2006-003";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = selectedOper;

                MPCF.ClearList(spdMoldList);

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMoldList_Sheet1.RowCount++;
                    spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.MOLD_CODE].Value = dt.Rows[i]["MOLD_CODE"];
                    spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.MOLD_DESC].Value = dt.Rows[i]["MOLD_DESC"];
                }
                MPCF.FitColumnHeader(spdMoldList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //요청 리스트 조회
        private void ViewRequestList(string selectedOper)
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CRAS2006-004";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = selectedOper;

                dvcArgu[2].sCondition_ID = "REQ_NO";
                dvcArgu[2].sCondition_Value = txtReqNo.Text;

                MPCF.ClearList(spdRequestList);

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdRequestList_Sheet1.RowCount++;
                    spdRequestList_Sheet1.Cells[i, (int)MOLD_INFO.MOLD_CODE].Value = dt.Rows[i]["MOLD_CODE"];
                    spdRequestList_Sheet1.Cells[i, (int)MOLD_INFO.MOLD_DESC].Value = dt.Rows[i]["MOLD_DESC"];
                }
                MPCF.FitColumnHeader(spdRequestList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //요청 정보 저장
        private bool SaveRequest()
        {
            try
            {
                TRSNode in_node = new TRSNode("Tran In");
                TRSNode out_node = new TRSNode("Tran Out");
                TRSNode request_list;

                MPCR.SetInMsg(in_node);

                //cStep 1. Create
                if (newFlag == true)
                {
                    in_node.ProcStep = '1';
                }
                //cStep 2.  Save
                else
                {
                    in_node.ProcStep = '2';
                    in_node.AddString("REQ_NO", txtReqNo.Text);
                }

                //요청 정보 저장               
                in_node.AddString("AREA_ID", cdvAreaId.Text);
                in_node.AddString("SUB_AREA_ID", cdvSubAreaId.Text);
                in_node.AddString("OPER", cdvRequestOper.Text);
                in_node.AddString("REQ_USER_ID", cdvRequestUserId.Text);
                in_node.AddString("REQ_COMMENT", txtConfirmComment.Text);

                //요청 리스트 정보 저장
                for(int i=0;i<spdRequestList_Sheet1.RowCount;i++)
                {
                    request_list = in_node.AddNode("REQUEST_TOOL_LIST");
                    request_list.AddString("TOOL_ID", spdRequestList_Sheet1.Cells[i, (int)MOLD_INFO.MOLD_CODE].Text);
                }

                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Scrap_Mold_Request", in_node, ref out_node) == false)
                {
                    return false;
                }

                ClearRequestInfo();

                selected_request_no = out_node.GetString("REQ_NO");
                txtReqNo.Text = selected_request_no;

                MPCF.ShowMsgBox(MPCF.GetMessage(52));

                return true;
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //요청 정보 확정
        private bool ConfirmRequest()
        {
            try
            {
                TRSNode in_node = new TRSNode("Confirm In");
                TRSNode out_node = new TRSNode("Confrim Out");

                MPCR.SetInMsg(in_node);

                // cStep 3 : Confirm
                in_node.ProcStep = '3';

                in_node.AddString("REQ_NO", txtReqNo.Text);

                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Scrap_Mold_Request", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                return true;
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //요청 정보 확정 취소
        private bool CancelConfirmRequest()
        {
            try
            {
                TRSNode in_node = new TRSNode("Confirm Cancel In");
                TRSNode out_node = new TRSNode("Confrim Cancel Out");

                MPCR.SetInMsg(in_node);

                // cStep 4 : Confirm Cancel
                in_node.ProcStep = '4';

                in_node.AddString("REQ_NO", txtReqNo.Text);

                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Scrap_Mold_Request", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                return true;
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //요청 정보 삭제
        private bool DeleteRequest()
        {
            try
            {
                TRSNode in_node = new TRSNode("Delete In");
                TRSNode out_node = new TRSNode("Delete Out");

                MPCR.SetInMsg(in_node);

                // cStep 5 : Delete
                in_node.ProcStep = '5';

                in_node.AddString("REQ_NO", txtReqNo.Text);

                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Scrap_Mold_Request", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

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
                    return;

                ClearData("ALL");

                ViewRequestInfo();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

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
         
        private void cdvAreaId_ButtonPress(object sender, EventArgs e)
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

        private void cdvAreaId_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvSubAreaId.Text = "";
                cdvRequestOper.Text = "";
                cdvRequestUserId.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvRequestOper_ButtonPress(object sender, EventArgs e)
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

                cdvRequestOper.Init();
                MPCF.InitListView(cdvRequestOper.GetListView);
                cdvRequestOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvRequestOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvRequestOper.SelectedSubItemIndex = 0;
                cdvRequestOper.DisplaySubItemIndex = 1;

                //요청창고 호출
                if (COM_LIST.ViewOperationList(cdvRequestOper.GetListView, '3', cdvAreaId.Text, cdvSubAreaId.Text, "", "", 'Y') == false)
                {
                    return;
                }

                cdvRequestOper.InsertEmptyRow(0, 1);
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
                ClearData("ALL");

                for (int i = 0; i < spdRequestInfo.ActiveSheet.RowCount; i++)
                {
                    spdRequestInfo.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                if (e.ColumnHeader || e.Row < 0)
                {
                    return;
                }

                selected_row = e.Row;
                spdRequestInfo.ActiveSheet.Rows[selected_row].BackColor = Color.FromArgb(255, 192, 255);
                selected_request_no = spdRequestInfo_Sheet1.Cells[selected_row, (int)REQUEST_INFO.REQ_NO].Text;
                selected_oper = spdRequestInfo_Sheet1.Cells[selected_row, (int)REQUEST_INFO.OPER].Text;

                ViewScrapMoldList(selected_request_no);

                ViewDetailRequestInfo(selected_row);
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
                ClearData("NEW");

                ViewGcmCodeList_Status(cdvReqStatus, CSGC.CP_REQ_STATUS_REQUEST);

                cdvAreaId.Text = cdvDept.Text;
                cdvAreaId.DisplayText = cdvDept.DisplayText;

                cdvSubAreaId.Text = cdvWorkPlace.Text;
                cdvSubAreaId.DisplayText = cdvSubAreaId.DisplayText;

                cdvRequestOper.Text = cdvOper.Text;
                cdvRequestOper.DisplayText = cdvOper.DisplayText;

                ChangeRequestOper();

            }
            catch(Exception ex)
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
                for (int i = spdMoldList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        c_flag = true;

                        sTmp = spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.MOLD_CODE].Text;

                        for (int k = 0; k < spdRequestList_Sheet1.RowCount; k++)
                        {
                            if (spdRequestList_Sheet1.Cells[k, (int)MOLD_INFO.MOLD_CODE].Text == sTmp)
                            {
                                c_flag = false;
                                continue;
                            }
                        }

                        if (c_flag)
                        {
                            iRow = spdRequestList_Sheet1.RowCount;
                            spdRequestList_Sheet1.RowCount++;

                            spdRequestList_Sheet1.SetValue(iRow, (int)MOLD_INFO.CHECK, true);
                            spdRequestList_Sheet1.Cells[iRow, (int)MOLD_INFO.MOLD_CODE].Value = spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.MOLD_CODE].Text;
                            spdRequestList_Sheet1.Cells[iRow, (int)MOLD_INFO.MOLD_DESC].Value = spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.MOLD_DESC].Text;
                        }

                        spdMoldList_Sheet1.RemoveRows(i, 1);
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
                for (int i = spdRequestList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdRequestList_Sheet1.Cells[i, (int)MOLD_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        c_flag = true;

                        sTmp = spdRequestList_Sheet1.Cells[i, (int)MOLD_INFO.MOLD_CODE].Text;

                        for (int k = 0; k < spdMoldList_Sheet1.RowCount; k++)
                        {
                            if (spdMoldList_Sheet1.Cells[k, (int)MOLD_INFO.MOLD_CODE].Text == sTmp)
                            {
                                c_flag = false;
                                continue;
                            }
                        }

                        if (c_flag)
                        {
                            iRow = spdMoldList_Sheet1.RowCount;
                            spdMoldList_Sheet1.RowCount++;

                            spdMoldList_Sheet1.SetValue(iRow, (int)MOLD_INFO.CHECK, true);
                            spdMoldList_Sheet1.Cells[iRow, (int)MOLD_INFO.MOLD_CODE].Value = spdRequestList_Sheet1.Cells[i, (int)MOLD_INFO.MOLD_CODE].Text;
                            spdMoldList_Sheet1.Cells[iRow, (int)MOLD_INFO.MOLD_DESC].Value = spdRequestList_Sheet1.Cells[i, (int)MOLD_INFO.MOLD_DESC].Text;
                        }

                        spdRequestList_Sheet1.RemoveRows(i, 1);
                    }
                }

                spdMoldList_Sheet1.SortRows((int)MOLD_INFO.MOLD_CODE, true, false);
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

                if(SaveRequest())
                {
                    ClearData("VIEW");

                    ViewRequestInfo();
                    ViewScrapMoldList(selected_request_no);
                    ViewDetailRequestInfo(selected_request_no);

                    
                }
            }
            catch(Exception ex)
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

        private void cdvSubAreaId_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvRequestOper.Text = "";
                cdvRequestUserId.Text = "";
            }
            catch(Exception ex)
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

                if (DeleteRequest())
                {
                    ClearData("ALL");

                    ViewRequestInfo();
                }
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
                if(CheckCondition(CSGC.CHECK.CONFIRM) == false)
                        return;

                if (ConfirmRequest())
                {
                    ClearData("VIEW");

                    ViewRequestInfo();
                    ViewScrapMoldList(selected_request_no);

                    ViewDetailRequestInfo(selected_row);
                }
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnCancelConfirm_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.CANCEL) == false)
                    return;

                if (CancelConfirmRequest())
                {
                    ClearData("VIEW");
                   
                    ViewRequestInfo();
                    ViewScrapMoldList(selected_request_no);

                    ViewDetailRequestInfo(selected_row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvRequestUserId_ButtonPress(object sender, EventArgs e)
        {
            string sViewID = "";
            try
            {
                sViewID = "CINV2009-004";

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
                
                cdvRequestUserId.Init();
                MPCF.InitListView(cdvRequestUserId.GetListView);
                cdvRequestUserId.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvRequestUserId.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvRequestUserId.SelectedSubItemIndex = 0;
                cdvRequestUserId.DisplaySubItemIndex = 1;

                //요청자 호출 (Sub Area 는 넣지 않음)
                if (COM_LIST.ViewWorkerList(cdvRequestUserId.GetListView, sViewID, cdvAreaId.Text, "") == false)
                {
                    return;
                }

                cdvRequestUserId.InsertEmptyRow(0, 1);
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

        private void cdvRequestOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                ChangeRequestOper();
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}
