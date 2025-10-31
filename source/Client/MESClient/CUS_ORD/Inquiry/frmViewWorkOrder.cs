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
using Miracom.MsgHandler;

namespace CUS_ORD
{
    public partial class frmViewWorkOrder : CUS_COM.frmTranForm02
    {
        public frmViewWorkOrder()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum WORKORDER
        {
            ORDER_ID,               // 1 : 작업지시번호
            START_DATE,             // 2 : 시작일
            END_DATE,               // 3 : 완료일
            MAT_ID,                 // 4 : 제품코드
            MAT_DESC,               // 5 : 제품명
            MAT_VER,                // 6 : 제품 버전
            UNIT,                   // 7 : 단위
            ORDER_QTY,              // 8 : 지시수량
            PROD_QTY,               // 9 : 생산수량
            LOSS_QTY,               //
            STOCK,                  //10 : 창고
            ORDER_STATUS,           //11 : 작업지시 상태
            ORDER_TYPE,             //12 : 작업지시 타입
            FLOW,                   //13 : 플로우
            FLOW_DESC,              //14 : 플로우명
            PO_NO,
            COMMENT
        }

        private enum OPER
        {
            OPER,                   // 1 : 공정코드
            OPER_DESC,              // 2 : 공정명
            ERP_OPER,               // 3 : ERP공정코드
            ERP_OPER_DESC,          // 4 : ERP공정명
            OPTION_1,               // 5 : 옵션1
            OPTION_2,               // 6 : 옵션2
            OPER_START_TIME,
            OPER_END_TIME,
            OPER_IN_QTY,
            OPER_OUT_QTY,
            OPER_LOSS_QTY,
            OPER_CV_QTY
        }

        private enum ERP_OPER
        {
            ERP_OPER,               // 1 : ERP공정코드
            ERP_OPER_DESC           // 2 : ERP공정명
        }

        private enum BOM
        {
            CHK,                    // 1 : 공정코드
            ORDER_ID,               // 2 : ORDER_ID
            OPER,                   // 3 : 공정명
            OPER_SELECT,            // 4 : 공정 선택
            OPER_DESC,              // 5 : ERP공정코드
            MAT_ID,                 // 6 : 자재코드
            MAT_SELECT,             // 7 : 자재 선택
            MAT_DESC,               // 8 : 자재명
            UNIT_QTY,               // 9 : 단위소요량
            TOTAL_QTY,              // 10: 총소요량
            UNIT,                   // 11: 단위
            OUT_OPER,               // 12: 출고창고
            OUT_OPER_DESC           // 13: 출고창고
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
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnCommentSave.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                btnReIf.Anchor = AnchorStyles.Top | AnchorStyles.Left;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //작업지시 조회 함수
        private void ViewOrder()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[10];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FROM_DATE";
                dvcArgu[1].sCondition_Value = string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text.Replace("-", "");

                dvcArgu[2].sCondition_ID = "TO_DATE";
                dvcArgu[2].sCondition_Value = dtpToDate.Text.Replace("-", "") + "000000";

                dvcArgu[3].sCondition_ID = "AREA_ID";
                dvcArgu[3].sCondition_Value = cdvDept.Text;

                dvcArgu[4].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[4].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[5].sCondition_ID = "OPER";
                dvcArgu[5].sCondition_Value = cdvOper.Text + "%";

                dvcArgu[6].sCondition_ID = "ORDER_ID";
                dvcArgu[6].sCondition_Value = cdvOrder.Text + "%";

                dvcArgu[7].sCondition_ID = "MAT_ID";
                dvcArgu[7].sCondition_Value = cdvMat.Text + "%";

                dvcArgu[8].sCondition_ID = "STATUS";
                dvcArgu[8].sCondition_Value = cdvStatus.Text + "%";

                dvcArgu[9].sCondition_ID = "CREATE_CODE";
                dvcArgu[9].sCondition_Value = cdvOrderType.Text + "%";

                if (TPDR.GetDataOne("", ref dt, "CORD3001-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    MPCF.ClearList(spdWorkOrder);
                    GC.Collect();
                    return;
                }

                MPCF.ClearList(spdWorkOrder);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdWorkOrder_Sheet1.RowCount++;
                    
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.START_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["START_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.END_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["END_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_QTY].Value = dt.Rows[i]["ORDER_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.PROD_QTY].Value = dt.Rows[i]["PROD_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.LOSS_QTY].Value = dt.Rows[i]["LOSS_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.STOCK].Value = dt.Rows[i]["STOCK"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_STATUS].Value = dt.Rows[i]["STATUS"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_TYPE].Value = dt.Rows[i]["CREATE_CODE_DESC"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.FLOW].Value = dt.Rows[i]["FLOW"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.FLOW_DESC].Value = dt.Rows[i]["FLOW_DESC"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.PO_NO].Value = dt.Rows[i]["PO_NO"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.COMMENT].Value = dt.Rows[i]["ORDER_DESC"];
                }
                MPCF.FitColumnHeader(spdOper);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //작업지시에 대한 공정 조회 함수
        private void ViewOper(string sOrder_id, string sFlow)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORDER_ID";
                dvcArgu[1].sCondition_Value = sOrder_id;

                //dvcArgu[2].sCondition_ID = "AREA_ID";
                //dvcArgu[2].sCondition_Value = cdvDept.Text;

                //dvcArgu[3].sCondition_ID = "SUB_AREA_ID";
                //dvcArgu[3].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[2].sCondition_ID = "FLOW";
                dvcArgu[2].sCondition_Value = cdvFlow.Text;

                if (TPDR.GetDataOne("", ref dt, "CORD3001-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdOper);
                    return;
                }

                MPCF.ClearList(spdOper);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdOper_Sheet1.RowCount++;
                    
                    spdOper_Sheet1.Cells[i, (int)OPER.OPER].Value = dt.Rows[i]["MES_OPER"];
                    spdOper_Sheet1.Cells[i, (int)OPER.OPER_DESC].Value = dt.Rows[i]["MES_OPER_DESC"];                    
                    spdOper_Sheet1.Cells[i, (int)OPER.ERP_OPER].Value = dt.Rows[i]["ERP_OPER"];
                    spdOper_Sheet1.Cells[i, (int)OPER.ERP_OPER_DESC].Value = dt.Rows[i]["ERP_OPER_DESC"];
                    spdOper_Sheet1.Cells[i, (int)OPER.OPTION_1].Value = dt.Rows[i]["OPTION_1"];
                    spdOper_Sheet1.Cells[i, (int)OPER.OPTION_2].Value = dt.Rows[i]["OPTION_2"];
                    spdOper_Sheet1.Cells[i, (int)OPER.OPER_START_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["OPER_START_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdOper_Sheet1.Cells[i, (int)OPER.OPER_END_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["OPER_END_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdOper_Sheet1.Cells[i, (int)OPER.OPER_IN_QTY].Value = dt.Rows[i]["OPER_IN_QTY"];
                    spdOper_Sheet1.Cells[i, (int)OPER.OPER_OUT_QTY].Value = dt.Rows[i]["OPER_OUT_QTY"];
                    spdOper_Sheet1.Cells[i, (int)OPER.OPER_LOSS_QTY].Value = dt.Rows[i]["OPER_LOSS_QTY"];
                    spdOper_Sheet1.Cells[i, (int)OPER.OPER_CV_QTY].Value = dt.Rows[i]["OPER_CV_QTY"];
                }
                MPCF.FitColumnHeader(spdOper);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //ERP 작업 공정 조회 함수
        private void ViewERPOper(string sOrder_id)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORDER_ID";
                dvcArgu[1].sCondition_Value = sOrder_id;

                if (TPDR.GetDataOne("", ref dt, "CORD3001-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdErpOper);
                    return;
                }

                MPCF.ClearList(spdErpOper);
                
                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdErpOper_Sheet1.RowCount++;

                    spdErpOper_Sheet1.Cells[i, (int)ERP_OPER.ERP_OPER].Value = dt.Rows[i]["ERP_OPER"];
                    spdErpOper_Sheet1.Cells[i, (int)ERP_OPER.ERP_OPER_DESC].Value = dt.Rows[i]["ERP_OPER_DESC"];
                }
                MPCF.FitColumnHeader(spdErpOper);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //자재소요정보 조회 함수
        private void ViewBom(string sOrder_id)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORDER_ID";
                dvcArgu[1].sCondition_Value = sOrder_id;

                if (TPDR.GetDataOne("", ref dt, "CORD3001-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdBom);
                    return;
                }

                MPCF.ClearList(spdBom);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdBom_Sheet1.RowCount++;

                    spdBom_Sheet1.SetValue(i, (int)BOM.CHK, false);

                    spdBom_Sheet1.Cells[i, (int)BOM.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdBom_Sheet1.Cells[i, (int)BOM.OPER].Value = dt.Rows[i]["OPER"];
                    spdBom_Sheet1.Cells[i, (int)BOM.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdBom_Sheet1.Cells[i, (int)BOM.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdBom_Sheet1.Cells[i, (int)BOM.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdBom_Sheet1.Cells[i, (int)BOM.UNIT_QTY].Value = dt.Rows[i]["UNIT_QTY"];
                    spdBom_Sheet1.Cells[i, (int)BOM.TOTAL_QTY].Value = dt.Rows[i]["TOTAL_QTY"];
                    spdBom_Sheet1.Cells[i, (int)BOM.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdBom_Sheet1.Cells[i, (int)BOM.OUT_OPER].Value = dt.Rows[i]["OUT_OPER"];
                    spdBom_Sheet1.Cells[i, (int)BOM.OUT_OPER_DESC].Value = dt.Rows[i]["OUT_OPER_DESC"];
                }
                MPCF.FitColumnHeader(spdBom);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //BOM 정보 저장 함수
        private bool SaveBom()
        {
            string sOrder_id = "";

            try
            {
                sOrder_id = spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_ID].Text;

                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode lot_list;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("ORDER_ID", sOrder_id);
                in_node.AddString("COMMENT", txtComment.Text);
                in_node.AddString("FLOW", cdvFlow.Text);

                for (int i = 0; i < spdBom.ActiveSheet.RowCount; i++)
                {
                    lot_list = in_node.AddNode("BOM_LIST");

                    lot_list.AddString("ORDER_ID", spdBom.ActiveSheet.Cells[i, (int)BOM.ORDER_ID].Text);
                    lot_list.AddString("OPER", spdBom.ActiveSheet.Cells[i, (int)BOM.OPER].Text);
                    lot_list.AddString("MAT_ID", spdBom.ActiveSheet.Cells[i, (int)BOM.MAT_ID].Text);
                    lot_list.AddDouble("UNIT_QTY", MPCF.ToDbl(spdBom.ActiveSheet.Cells[i, (int)BOM.UNIT_QTY].Text));



                    //베트남에서 TOTAL Use Qty 값 이상하게 계속 넣는 문제 발생 (엑셀로 붙여넣기 하는듯... 계산한 값과 1 이상 차이나면 경고 메세지 한번 날림)
                    double dOrderQty = 0;
                    double dTotalQty = 0;
                    double dUnit = 0;

                    dOrderQty = MPCF.ToDbl(spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_QTY].Text);
                    dUnit = MPCF.ToDbl(spdBom.ActiveSheet.Cells[i, (int)BOM.UNIT_QTY].Text);
                    dTotalQty = Math.Round(dUnit * dOrderQty, 5);
                   
                    if(Math.Abs(dTotalQty - MPCF.ToDbl(spdBom.ActiveSheet.Cells[i, (int)BOM.TOTAL_QTY].Text)) >=1)
                    {

                        if (MPCF.ShowMsgBox("Check Please BOM: " + spdBom.ActiveSheet.Cells[i, (int)BOM.MAT_DESC].Text + " // Total Use Qty: " + spdBom.ActiveSheet.Cells[i, (int)BOM.TOTAL_QTY].Text + "?", MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                        {
                            return false;
                        }

                    }

                    lot_list.AddDouble("QTY", MPCF.ToDbl(spdBom.ActiveSheet.Cells[i, (int)BOM.TOTAL_QTY].Text));






                }

                if (MPCR.CallService("CUS_ORD", "CUS_ORD_Update_Order_Bom", in_node, ref out_node) == false)
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

        //벨리데이션 체크
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            int iCount = 0;

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

                switch (CHECK)
                {
                    case CSGC.CHECK.SAVE:

                        for(int i = 0; i < spdBom.ActiveSheet.RowCount; i++)
                        {
                            if (spdBom.ActiveSheet.Cells[i, (int)BOM.CHK].Text.ToString().ToUpper() == "TRUE")
                                iCount++;
                        }

                        //전체 저장으로 인해 의미 없음.
                        //if (iCount == 0)
                        //{
                        //    //CMN133 ERROR - 최소한 1개 이상의 아이템을 선택해 주세요.
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(133));
                        //    return false;
                        //}

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

        //초기화
        private void ClearList()
        {
            try
            {
                MPCF.ClearList(spdWorkOrder);
                MPCF.ClearList(spdOper);
                MPCF.ClearList(spdBom);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmViewWorkOrder_Load(object sender, EventArgs e)
        {
            try
            {
                dtpFromDate.Value = dtpToDate.Value.AddDays(-7);
                dtpToDate.Value = dtpToDate.Value.AddDays(7);

                //조회 조건 최조 세팅
                cdvOrderType.Text = "PROD";
                cdvOrderType.DisplayText = "Product Lot";
                cdvStatus.Text = "W";
                cdvStatus.DisplayText = "Wait";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMat_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                // 제품 팝업으로 변경
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMat.Text = popup.sMat_id;
                    popup = null;
                }
                else
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvFlow_ButtonPress(object sender, EventArgs e)
        {
            string sMat_id = "";
            string sOrder_id = "";
            int iMat_ver = 0;

            try
            {
                if (spdWorkOrder.ActiveSheet.RowCount == 0)
                {
                    //CMN452 CONFIRM  - 선택된 작업지시가 없습니다. 작업지시를 선택하세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(452));
                    return;
                }

                sOrder_id = spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_ID].Text;
                sMat_id = spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.MAT_ID].Text;
                iMat_ver = MPCF.ToInt(spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.MAT_VER].Text);

                cdvFlow.Init();
                MPCF.InitListView(cdvFlow.GetListView);
                cdvFlow.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvFlow.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvFlow.SelectedSubItemIndex = 0;
                cdvFlow.DisplaySubItemIndex = 1;

                if (WIPLIST.ViewFlowList(cdvFlow.GetListView, '2', sMat_id, iMat_ver, null) == false)
                {
                    return;
                }

                cdvFlow.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvFlow_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            string sOrder_id = "";

            try
            {
                if (MPCF.Trim(cdvFlow.Text) == "")
                {
                    MPCF.ClearList(spdOper);
                }

                sOrder_id = spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_ID].Text;

                ViewOper(sOrder_id, cdvFlow.Text);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOrder_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }

                CUS_COM.Popup.frmPopWorkOrderList popup = new CUS_COM.Popup.frmPopWorkOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_AreaCode = cdvDept.Text;
                popup.g_AreaDesc = cdvDept.DisplayText;
                popup.g_SubAreaCode = cdvWorkPlace.Text;
                popup.g_SubAreaDesc = cdvWorkPlace.DisplayText;
                popup.g_OperCode = cdvOper.Text;
                popup.g_OperDesc = cdvOper.DisplayText;
                popup.g_WorkOrder = cdvOrder.Text;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvOrder.Text = popup.g_WorkOrder;
                    popup = null;
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvStatus_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvStatus.Init();
                MPCF.InitListView(cdvStatus.GetListView);
                cdvStatus.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvStatus.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvStatus.SelectedSubItemIndex = 0;
                cdvStatus.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvStatus.GetListView, '1', MPGC.MP_WIP_ORDER_STATUS) == false)
                {
                    return;
                }

                cdvStatus.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOrderType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOrderType.Init();
                MPCF.InitListView(cdvOrderType.GetListView);
                cdvOrderType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOrderType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOrderType.SelectedSubItemIndex = 0;
                cdvOrderType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvOrderType.GetListView, '1', MPGC.MP_WIP_CREATE_CODE) == false)
                    return;

                cdvOrderType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //자재소요 그리드 버튼 이벤트 - 공정, 자재 정보 조회
        private void spdBom_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            string stmp = "";

            try
            {
                if (e.Column == (int)BOM.OPER_SELECT || e.Column == (int)BOM.MAT_SELECT)
                {
                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                    if (e.Column == (int)BOM.OPER_SELECT)
                    {
                        ////공정 조회
                        //if (COM_LIST.ViewOperationList(cdvGridButton.GetListView, '1', cdvDept.Text, cdvWorkPlace.Text) == false)
                        //    return;

                        //공정 조회
                        if (WIPLIST.ViewOperationList(cdvGridButton.GetListView, '2', cdvFlow.Text) == false)
                            return;

                        cdvGridButton.ShowPopupList(e.Row, e.Column);
                        cdvGridButton.InsertEmptyRow(0, 1);
                    }
                    else if (e.Column == (int)BOM.MAT_SELECT)
                    {
                        if (MPCF.Trim(spdBom.ActiveSheet.Cells[spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.OPER].Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            return;
                        }

                        frmPopMaterialList popup = new frmPopMaterialList();
                        popup.StartPosition = FormStartPosition.CenterParent;
                        popup.sArea_id = cdvDept.Text;
                        popup.sArea_desc = cdvDept.DisplayText;

                        if (popup.ShowDialog() == DialogResult.OK)
                        {
                            //기존 공정 BOM정보에 들어간 MAT_ID가 있으면 중복해서 선택되지 않는다.
                            stmp = spdBom.ActiveSheet.Cells[spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.OPER].Text;

                            for (int k = 0; k < spdBom.ActiveSheet.RowCount; k++)
                            {
                                if (stmp == spdBom.ActiveSheet.Cells[k, (int)BOM.OPER].Text)
                                {
                                    if (spdBom.ActiveSheet.Cells[k, (int)BOM.MAT_ID].Text == popup.sMat_id)
                                    {
                                        //CMN166 ERROR - 이 Material는 이미 존재 합니다.
                                        MPCF.ShowMsgBox(MPCF.GetMessage(166));
                                        return;
                                    }
                                }
                            }

                            spdBom.ActiveSheet.SetValue(spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.MAT_ID, popup.sMat_id);
                            spdBom.ActiveSheet.SetValue(spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.MAT_DESC, popup.sMat_Desc);

                            popup = null;
                        }
                        else
                            return;

                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //bom그리드에서 고정 및 자재 선택시 선택된 값을 넣어주며 자동 체크
        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (spdBom.ActiveSheet.ActiveColumnIndex == (int)BOM.OPER_SELECT)
                {
                    spdBom_Sheet1.SetValue(e.Row, (int)BOM.OPER, e.SelectedItem.SubItems[0].Text);
                    spdBom_Sheet1.SetValue(e.Row, (int)BOM.OPER_DESC, e.SelectedItem.SubItems[1].Text);
                }

                spdBom.ActiveSheet.SetValue(spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.CHK, true);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //작업지시 선택 시 공정정보, 자재소요정보 조회
        private void spdWorkOrder_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            string sOrder_id = "";

            try
            {
                if (e.ColumnHeader)
                    return;

                for (int i = 0; i < spdWorkOrder.ActiveSheet.RowCount; i++)
                {
                    spdWorkOrder.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdWorkOrder.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);


                txtComment.Text = spdWorkOrder.ActiveSheet.Cells[e.Row, (int)WORKORDER.COMMENT].Text;
                cdvFlow.Text = spdWorkOrder.ActiveSheet.Cells[e.Row, (int)WORKORDER.FLOW].Text;
                cdvFlow.DisplayText = spdWorkOrder.ActiveSheet.Cells[e.Row, (int)WORKORDER.FLOW_DESC].Text;

                sOrder_id = spdWorkOrder.ActiveSheet.Cells[e.Row, (int)WORKORDER.ORDER_ID].Text;
                if (MPCF.Trim(sOrder_id) != "")
                {
                    ViewOper(sOrder_id, cdvFlow.Text);
                    ViewERPOper(sOrder_id);
                    ViewBom(sOrder_id);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //소요량 변경시 자동 체크
        //단위소요량 및 총 소요량 변경 시 자동 변경
        private void spdBom_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            double dOrderQty = 0;
            double dTotalQty = 0;
            double dUnit = 0;

            try
            {
                dOrderQty = MPCF.ToDbl(spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_QTY].Text);

                if (spdBom.ActiveSheet.ActiveColumnIndex == (int)BOM.TOTAL_QTY)
                {
                    dTotalQty = MPCF.ToDbl(spdBom.ActiveSheet.Cells[spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.TOTAL_QTY].Text);
                    dUnit = Math.Round(dTotalQty / dOrderQty, 5);

                    spdBom.ActiveSheet.SetValue(spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.UNIT_QTY, dUnit);
                    spdBom.ActiveSheet.SetValue(spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.CHK, true);
                }
                else if (spdBom.ActiveSheet.ActiveColumnIndex == (int)BOM.UNIT_QTY)
                {
                    dUnit = MPCF.ToDbl(spdBom.ActiveSheet.Cells[spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.UNIT_QTY].Text);
                    dTotalQty = Math.Round(dUnit * dOrderQty, 5);

                    spdBom.ActiveSheet.SetValue(spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.TOTAL_QTY, dTotalQty);
                    spdBom.ActiveSheet.SetValue(spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.CHK, true);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdBom_ClipboardPasted(object sender, FarPoint.Win.Spread.ClipboardPastedEventArgs e)
        {
            double dOrderQty = 0;
            double dTotalQty = 0;
            double dUnit = 0;

            try
            {
                dOrderQty = MPCF.ToDbl(spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_QTY].Text);

                if (spdBom.ActiveSheet.ActiveColumnIndex == (int)BOM.TOTAL_QTY)
                {
                    dTotalQty = MPCF.ToDbl(spdBom.ActiveSheet.Cells[spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.TOTAL_QTY].Text);
                    dUnit = Math.Round(dTotalQty / dOrderQty, 5);

                    spdBom.ActiveSheet.SetValue(spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.UNIT_QTY, dUnit);
                    spdBom.ActiveSheet.SetValue(spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.CHK, true);
                }
                else if (spdBom.ActiveSheet.ActiveColumnIndex == (int)BOM.UNIT_QTY)
                {
                    dUnit = MPCF.ToDbl(spdBom.ActiveSheet.Cells[spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.UNIT_QTY].Text);
                    dTotalQty = Math.Round(dUnit * dOrderQty, 5);

                    spdBom.ActiveSheet.SetValue(spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.TOTAL_QTY, dTotalQty);
                    spdBom.ActiveSheet.SetValue(spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.CHK, true);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //행추가
        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            try
            {
                if (spdWorkOrder.ActiveSheet.RowCount == 0)
                {
                    //CMN452 CONFIRM  - 선택된 작업지시가 없습니다. 작업지시를 선택하세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(452));
                    return;
                }

                spdBom.ActiveSheet.Rows.Add(spdBom.ActiveSheet.RowCount, 1);
                spdBom.ActiveSheet.SetValue(spdBom.ActiveSheet.RowCount - 1, (int)BOM.UNIT_QTY, 0);
                spdBom.ActiveSheet.SetValue(spdBom.ActiveSheet.RowCount - 1, (int)BOM.TOTAL_QTY, 0);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //행삭제
        private void btnRowDelete_Click(object sender, EventArgs e)
        {
            try
            {
                for (int i = spdBom.ActiveSheet.RowCount - 1; i >= 0; i--)
                {
                    if (spdBom.ActiveSheet.Cells[i, (int)BOM.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        spdBom.ActiveSheet.RemoveRows(i, 1);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //작업지시 조회
        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.NONE) == false)
                    return;

                ClearList();

                ViewOrder();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //BOM 정보 저장
        private void btnProcess_Click(object sender, EventArgs e)
        {
            string sOrder_id = "";
            int iRow = 0;
            int iCol = 0;

            try
            {              
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                sOrder_id = spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_ID].Text;

                if (SaveBom())
                {
                    ViewOrder();

                    spdWorkOrder.Search(0, sOrder_id, false, false, false, false, 0, 0, spdWorkOrder.ActiveSheet.RowCount - 1, (int)WORKORDER.ORDER_ID, ref iRow, ref iCol);
                    spdWorkOrder.ActiveSheet.ActiveRowIndex = iRow;
                    spdWorkOrder.ActiveSheet.Rows[iRow].BackColor = Color.FromArgb(255, 192, 255);

                    cdvFlow.Text = spdWorkOrder.ActiveSheet.Cells[iRow, (int)WORKORDER.FLOW].Text;
                    cdvFlow.DisplayText = spdWorkOrder.ActiveSheet.Cells[iRow, (int)WORKORDER.FLOW_DESC].Text;

                    ViewOper(sOrder_id, cdvFlow.Text);
                    ViewBom(sOrder_id);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOrder_TextBoxTextChanged(object sender, EventArgs e)
        {

            if (cdvOrder.DisplayText == "")
                cdvOrder.Text = "";
        }

        private void cdvMat_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMat.DisplayText == "")
                cdvMat.Text = "";
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

        #endregion

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdWorkOrder, "WorkOrderList");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void dtpFromDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromDate.CustomFormat = "yyyy-MM-dd";
        }

        private void btnReIf_Click(object sender, EventArgs e)
        {
            TRSNode in_node = new TRSNode("BATSERVER_IN");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.AddString("JOB_PROC_ID", "EM-WIP-04");

                if (MPCR.CallService("CUS_BAT", "CUS_BAT_Erp_Mes_Wo_Info", in_node, "/IDK1/INFServer", 0, DeliveryMode.Unicast, false) == false)
                {
                    return;
                }
                MPCF.ShowMsgBox(MPCF.GetMessage(52));
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnCommentSave_Click(object sender, EventArgs e)
        {
            string ssql = "";
            string sOrder_id = "";

            try
            {
                if(spdWorkOrder.ActiveSheet.ActiveRowIndex < 0)
                {
                    return;
                }

              if(spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_ID].Text == "")
                {
                    return;
                }


                sOrder_id = spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_ID].Text;

                ssql = "UPDATE MWIPORDSTS SET ORDER_DESC ='" + txtComment.Text + "  " +  "' WHERE FACTORY = '" + MPGV.gsFactory + "' AND ORDER_ID = '" + sOrder_id + "'";

                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("SQL", ssql);


                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return;
                }

                MPCR.ShowSuccessMsg(out_node);


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
    }
}
