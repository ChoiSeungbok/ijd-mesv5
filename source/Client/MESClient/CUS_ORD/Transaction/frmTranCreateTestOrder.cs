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
using Microsoft.Office.Interop.Excel;

//CORD2002
namespace CUS_ORD
{
    public partial class frmTranCreateTestOrder : CUS_COM.frmTranForm06
    {
        public frmTranCreateTestOrder()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum WORKORDER
        {
            CHK,                    // 0 : 체크
            ORDER_ID,               // 1 : 작업지시번호
            CREATE_CODE,
            CREATE_CODE_SELECT,
            CREATE_DESC,
            AUTO_PROD_CHANGE,
            START_DATE,             // 2 : 시작일
            END_DATE,               // 3 : 완료일
            MAT_ID,                 // 4 : 제품코드
            MAT_SELECT,             // 5 : 제품 선택
            MAT_DESC,               // 6 : 제품명
            UNIT,                   // 7 : 단위
            MAT_VER,                // 8 : 
            ORDER_QTY,              // 9 : 지시수량
            STOCK_CODE,             //10 : 창고
            STOCK,                  //11 : 창고
            ORDER_STATUS,           //12 : 작업지시 상태
            FLOW,                   //13 : 플로우
            FLOW_DESC,              //14 : 플로우명
            COMMENT
        }

        private enum FLOW_OPER
        {
            OPER,                   // 1 : 공정코드
            OPER_DESC               // 2 : 공정명
        }

        private enum BOM
        {
            CHK,                    // 1 : 공정코드
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

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewOrder()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[9];
                System.Data.DataTable dt = null;
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
                dvcArgu[4].sCondition_Value = cdvWorkPlace.Text + "%";

                dvcArgu[5].sCondition_ID = "ORDER_ID";
                dvcArgu[5].sCondition_Value = cdvOrder.Text + "%";

                dvcArgu[6].sCondition_ID = "MAT_ID";
                dvcArgu[6].sCondition_Value = cdvMat.Text + "%";

                dvcArgu[7].sCondition_ID = "STATUS";
                dvcArgu[7].sCondition_Value = cdvStatus.Text + "%";

                dvcArgu[8].sCondition_ID = "CREATE_CODE";
                dvcArgu[8].sCondition_Value = cdvOrderType.Text + "%";

                if (TPDR.GetDataOne("", ref dt, "CORD2002-001", dvcArgu, false, false, ref sSql) == false)
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

                    spdWorkOrder_Sheet1.SetValue(i, (int)WORKORDER.CHK, false);
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.CREATE_DESC].Value = dt.Rows[i]["CREATE_CODE_DESC"];

                    // 한국만 자동양산품전환 적용
                    if (cdvDept.Text == "CTM")
                    {
                        spdWorkOrder_Sheet1.Columns[(int)WORKORDER.AUTO_PROD_CHANGE].Visible = true;

                        if (dt.Rows[i]["AUTO_PROD_CHANGE"].ToString().Trim() == "")
                        {
                            spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.AUTO_PROD_CHANGE].Value = "N";
                        }
                        else
                        {
                            spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.AUTO_PROD_CHANGE].Value = dt.Rows[i]["AUTO_PROD_CHANGE"];
                        }
                    }
                    else
                    {
                        spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.AUTO_PROD_CHANGE].Value = "N";
                        spdWorkOrder_Sheet1.Columns[(int)WORKORDER.AUTO_PROD_CHANGE].Visible = false;
                    }



                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.START_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["START_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.END_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["END_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_QTY].Value = dt.Rows[i]["ORDER_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.STOCK_CODE].Value = dt.Rows[i]["STOCK_CODE"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.STOCK].Value = dt.Rows[i]["STOCK"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_STATUS].Value = dt.Rows[i]["STATUS"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.FLOW].Value = dt.Rows[i]["FLOW"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.FLOW_DESC].Value = dt.Rows[i]["FLOW_DESC"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.COMMENT].Value = dt.Rows[i]["ORDER_DESC"];
                }

                MPCF.FitColumnHeader(spdOper);


                if (spdWorkOrder_Sheet1.RowCount != 0)
                {
                    ViewBom(spdWorkOrder_Sheet1.Cells[0, (int)WORKORDER.ORDER_ID].Text);

                    cdvFlow.Text = spdWorkOrder_Sheet1.Cells[0, (int)WORKORDER.FLOW].Text;
                    cdvFlow.DisplayText = spdWorkOrder_Sheet1.Cells[0, (int)WORKORDER.FLOW_DESC].Text;
                    ViewOper();

                }
                else
                {
                    ClearData("ALL");
                }


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewOper()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                System.Data.DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FLOW";
                dvcArgu[1].sCondition_Value = cdvFlow.Text;

                if (TPDR.GetDataOne("", ref dt, "CORD2002-002", dvcArgu, false, false, ref sSql) == false)
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

                    spdOper_Sheet1.Cells[i, (int)FLOW_OPER.OPER].Value = dt.Rows[i]["MES_OPER"];
                    spdOper_Sheet1.Cells[i, (int)FLOW_OPER.OPER_DESC].Value = dt.Rows[i]["MES_OPER_DESC"];
                }
                MPCF.FitColumnHeader(spdOper);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewBom(string sOrder_id)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                System.Data.DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORDER_ID";
                dvcArgu[1].sCondition_Value = sOrder_id;

                if (TPDR.GetDataOne("", ref dt, "CORD2002-003", dvcArgu, false, false, ref sSql) == false)
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

        private bool SaveOrder(char sStep)
        {
            try
            {

                /*
                //일단 현업 실수한 여지가 많아서, 해당플로우만 자동 양산품 전환 가능하도록 막아놓음.
                if (cdvFlow.Text != "FC475" && spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.AUTO_PROD_CHANGE].Text == "Y")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(587));
                    return false;

                }
                */
                //SKY다이아에서 진행하는것은 일단 무조건 자동양산품 전환 되어야함...(2025/05/30)
                if (cdvFlow.Text == "FC612" && spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.AUTO_PROD_CHANGE].Text != "Y")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(611));
                    return false;

                }



                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode lot_list;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = sStep;

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("ORDER_ID", spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_ID].Text);

                if (sStep != '2')
                {
                    //

                    if (cdvDept.Text.Trim() == "CTM" && txtComment.Text.Trim().ToString() == "")
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(575) + " [" + lblComment.Text + "]");
                        txtComment.Focus();
                        txtComment.BackColor = System.Drawing.Color.Red;
                        return false;
                    }
                    else
                    {
                        txtComment.BackColor = System.Drawing.SystemColors.Control;

                    }

                    in_node.AddString("COMMENT", txtComment.Text);
                    in_node.AddString("FLOW", cdvFlow.Text);
                    in_node.AddString("MAT_ID", spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.MAT_ID].Text);
                    in_node.AddDouble("ORD_QTY", MPCF.ToDbl(spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_QTY].Text));
                    in_node.AddString("FROM_DATE", dtpFromDate.Text.Replace("-", "") + "000000");
                    in_node.AddString("TO_DATE", dtpToDate.Text.Replace("-", "") + "000000");
                    in_node.AddString("CREATE_CODE", spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.CREATE_CODE].Text);
                    in_node.AddString("ORD_CMF_9", spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.AUTO_PROD_CHANGE].Text);

                    for (int i = 0; i < spdBom.ActiveSheet.RowCount; i++)
                    {
                        lot_list = in_node.AddNode("BOM_LIST");

                        lot_list.AddString("OPER", spdBom.ActiveSheet.Cells[i, (int)BOM.OPER].Text);
                        lot_list.AddString("MAT_ID", spdBom.ActiveSheet.Cells[i, (int)BOM.MAT_ID].Text);
                        lot_list.AddDouble("UNIT_QTY", MPCF.ToDbl(spdBom.ActiveSheet.Cells[i, (int)BOM.UNIT_QTY].Text));



                        //베트남에서 TOTAL Use Qty 값 이상하게 계속 넣는 문제 발생(엑셀로 붙여넣기 하는듯...입력한거 배제하고 계산해서 들어가계 수정
                        double dOrderQty = 0;
                        double dTotalQty = 0;
                        double dUnit = 0;

                        dOrderQty = MPCF.ToDbl(spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_QTY].Text);
                        dUnit = MPCF.ToDbl(spdBom.ActiveSheet.Cells[i, (int)BOM.UNIT_QTY].Text);
                        dTotalQty = Math.Round(dUnit * dOrderQty, 5);
                        if (Math.Abs(dTotalQty - MPCF.ToDbl(spdBom.ActiveSheet.Cells[i, (int)BOM.TOTAL_QTY].Text)) >= 1)
                        {
                            if (MPCF.ShowMsgBox("Check Please BOM: " + spdBom.ActiveSheet.Cells[i, (int)BOM.MAT_DESC].Text + " // Total Use Qty: " + spdBom.ActiveSheet.Cells[i, (int)BOM.TOTAL_QTY].Text + "?", MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                            {
                                return false;
                            }
                        }



                        lot_list.AddDouble("QTY", MPCF.ToDbl(spdBom.ActiveSheet.Cells[i, (int)BOM.TOTAL_QTY].Text));
                    }
                }

                if (MPCR.CallService("CUS_ORD", "CUS_ORD_Create_Test_Order", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                if (sStep != '2')
                {
                    if (spdOper_Sheet1.Cells[0, (int)FLOW_OPER.OPER].Text == "OC05001")
                    {


                        //CMN INFO - 작업지시공정 LOT진행 바로 하시겠습니까?
                        if (MPCF.ShowMsgBox(MPCF.GetMessage(588), MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                        {

                            frmTranLotMapping popup = new frmTranLotMapping();
                            popup.StartPosition = FormStartPosition.CenterParent;
                            popup.sArea_id = cdvDept.Text;
                            popup.sArea_desc = cdvDept.DisplayText;
                            popup.sSub_area_id = "";
                            popup.sSub_area_desc = "";
                            popup.sOper_id = "OC05001";
                            popup.sOper_desc = "작업지시";
                            popup.sOrder_id = out_node.GetString("ORDER_ID");
                            popup.sLot_id = "";



                            if (popup.ShowDialog() == DialogResult.OK)
                            {
                                popup = null;
                            }



                        }


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

                //작업장 없는 공정들있어서 일단 조회조건에서 빼버림 삭제하려고 조회할떄 문제발생(20210713)
                /*
                                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                                {
                                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                                    cdvWorkPlace.Focus();
                                    return false;
                                }
                 */
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        break;

                    case CSGC.CHECK.SAVE:

                        for (int i = 0; i < spdWorkOrder.ActiveSheet.RowCount; i++)
                        {
                            if (spdWorkOrder.ActiveSheet.Cells[i, (int)WORKORDER.CHK].Value.ToString().ToUpper() == "TRUE")
                                iCount++;
                        }

                        if (iCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305));
                            return false;
                        }

                        //CTM 작업지시공정은 무조건 BOM 들어가야함.
                        if (spdOper_Sheet1.Cells[0, (int)FLOW_OPER.OPER].Text == "OC05001")
                        {
                            if (spdBom_Sheet1.RowCount == 0)
                            {
                                //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(589));
                                return false;
                            }
                        }

                        break;

                    case CSGC.CHECK.DELETE:

                        //CMN453 INFO - 정말 삭제하시겠습니까?
                        if (MPCF.ShowMsgBox(MPCF.GetMessage(453), MessageBoxButtons.YesNo, 1) == DialogResult.No)
                        {
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

        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "ORDER":

                        MPCF.ClearList(spdWorkOrder);
                        MPCF.ClearList(spdOper);
                        MPCF.ClearList(spdBom);
                        cdvFlow.Text = "";
                        txtComment.Text = "";

                        break;

                    case "FLOW":

                        MPCF.ClearList(spdOper);
                        MPCF.ClearList(spdBom);
                        cdvFlow.Text = "";
                        txtComment.Text = "";

                        break;

                    case "ALL":

                        cdvOrder.Text = "";
                        cdvWorkPlace.Text = "";
                        cdvMat.Text = "";
                        cdvStatus.Text = "";

                        cdvFlow.Text = "";
                        txtComment.Text = "";

                        MPCF.ClearList(spdWorkOrder);
                        MPCF.ClearList(spdOper);
                        MPCF.ClearList(spdBom);

                        break;

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmTranCreateTestOrder_Load(object sender, EventArgs e)
        {
            try
            {



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
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                CUS_COM.Popup.frmPopWorkOrderList popup = new CUS_COM.Popup.frmPopWorkOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_AreaCode = cdvDept.Text;
                popup.g_AreaDesc = cdvDept.DisplayText;
                popup.g_SubAreaCode = cdvWorkPlace.Text;
                popup.g_SubAreaDesc = cdvWorkPlace.DisplayText;
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

        private void cdvFlow_ButtonPress(object sender, EventArgs e)
        {
            string sMat_id = "";
            int iMat_ver = 0;

            try
            {
                if (spdWorkOrder.ActiveSheet.RowCount == 0)
                {
                    //CMN452 CONFIRM  - 선택된 작업지시가 없습니다. 작업지시를 선택하세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(452));
                    return;
                }

                sMat_id = spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.MAT_ID].Text;
                iMat_ver = MPCF.ToInt(spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.MAT_VER].Text);

                if (iMat_ver == 0)
                    iMat_ver = 1;

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
            try
            {
                if (MPCF.Trim(cdvFlow.Text) != "")
                {
                    ViewOper();
                }
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

                //양산품은 뺀다.
                for (int i = cdvOrderType.GetListView.Items.Count; i > 0; i--)
                {
                    if (cdvOrderType.GetListView.Items[i - 1].SubItems[0].Text == "PROD")
                    {
                        cdvOrderType.GetListView.Items[i - 1].Remove();
                    }
                }

                cdvOrderType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdWorkOrder_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                if (e.Column == (int)WORKORDER.CHK)
                {
                    for (int i = 0; i < spdWorkOrder.ActiveSheet.RowCount; i++)
                    {
                        if (i == e.Row)
                            continue;

                        spdWorkOrder.ActiveSheet.SetValue(i, (int)WORKORDER.CHK, false);
                    }
                }
                else if (e.Column == (int)WORKORDER.MAT_SELECT || e.Column == (int)WORKORDER.CREATE_CODE_SELECT)
                {
                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                    if (e.Column == (int)WORKORDER.MAT_SELECT)
                    {
                        frmPopMaterialList popup = new frmPopMaterialList();
                        popup.StartPosition = FormStartPosition.CenterParent;
                        popup.sArea_id = cdvDept.Text;
                        popup.sArea_desc = cdvDept.DisplayText;

                        if (popup.ShowDialog() == DialogResult.OK)
                        {
                            spdWorkOrder.ActiveSheet.SetValue(spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.MAT_ID, popup.sMat_id);
                            spdWorkOrder.ActiveSheet.SetValue(spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.MAT_DESC, popup.sMat_Desc);
                            spdWorkOrder.ActiveSheet.SetValue(spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.UNIT, popup.sUnit);
                            spdWorkOrder.ActiveSheet.SetValue(spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.MAT_VER, popup.sMat_ver);

                            popup = null;
                        }
                        else
                            return;
                    }
                    else if (e.Column == (int)WORKORDER.CREATE_CODE_SELECT)
                    {
                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', MPGC.MP_WIP_CREATE_CODE) == false)
                            return;

                        //양산품은 뺀다.
                        for (int i = cdvGridButton.GetListView.Items.Count; i > 0; i--)
                        {
                            if (cdvGridButton.GetListView.Items[i - 1].SubItems[0].Text == "PROD")
                            {
                                cdvGridButton.GetListView.Items[i - 1].Remove();
                            }
                        }

                        cdvGridButton.ShowPopupList(e.Row, e.Column);
                        cdvGridButton.AddEmptyRow(1);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdWorkOrder_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            try
            {
                if (spdWorkOrder.ActiveSheet.ActiveColumnIndex == (int)WORKORDER.CREATE_CODE ||
                    spdWorkOrder.ActiveSheet.ActiveColumnIndex == (int)WORKORDER.START_DATE ||
                    spdWorkOrder.ActiveSheet.ActiveColumnIndex == (int)WORKORDER.END_DATE ||
                    spdWorkOrder.ActiveSheet.ActiveColumnIndex == (int)WORKORDER.MAT_ID ||
                    spdWorkOrder.ActiveSheet.ActiveColumnIndex == (int)WORKORDER.ORDER_QTY)
                {
                    for (int i = 0; i < spdWorkOrder.ActiveSheet.RowCount; i++)
                    {
                        if (i == e.Row)
                        {
                            spdWorkOrder.ActiveSheet.SetValue(i, (int)WORKORDER.CHK, true);
                        }
                        else
                        {
                            spdWorkOrder.ActiveSheet.SetValue(i, (int)WORKORDER.CHK, false);
                        }
                    }
                }

                if (spdWorkOrder.ActiveSheet.ActiveColumnIndex == (int)WORKORDER.ORDER_QTY)
                {

                    if (MPCF.ShowMsgBox(MPCF.GetMessage(590), MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                    {
                        BomQttyChange();
                    }

                   
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
                if (spdWorkOrder.ActiveSheet.ActiveColumnIndex == (int)WORKORDER.CREATE_CODE_SELECT)
                {
                    spdWorkOrder.ActiveSheet.SetValue(e.Row, (int)WORKORDER.CREATE_CODE, e.SelectedItem.SubItems[0].Text);
                    spdWorkOrder.ActiveSheet.SetValue(e.Row, (int)WORKORDER.CREATE_DESC, e.SelectedItem.SubItems[1].Text);

                    for (int i = 0; i < spdWorkOrder.ActiveSheet.RowCount; i++)
                    {
                        if (i == e.Row)
                        {
                            spdWorkOrder.ActiveSheet.SetValue(i, (int)WORKORDER.CHK, true);
                        }
                        else
                        {
                            spdWorkOrder.ActiveSheet.SetValue(i, (int)WORKORDER.CHK, false);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdWorkOrder_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            string sOrder_id = "";
            string sflow = "";
            string sflow_desc = "";

            try
            {
                if (e.ColumnHeader)
                    return;


                for (int i = 0; i < spdWorkOrder.ActiveSheet.RowCount; i++)
                {
                    spdWorkOrder.ActiveSheet.SetValue(i, (int)WORKORDER.CHK, false);
                    spdWorkOrder.ActiveSheet.Cells[i, (int)WORKORDER.CHK].BackColor = System.Drawing.Color.White;

                }
                spdWorkOrder.ActiveSheet.SetValue(e.Row, (int)WORKORDER.CHK, true);
                spdWorkOrder.ActiveSheet.Cells[e.Row, (int)WORKORDER.CHK].BackColor = System.Drawing.Color.Red;


                sOrder_id = spdWorkOrder.ActiveSheet.Cells[e.Row, (int)WORKORDER.ORDER_ID].Text;
                sflow = spdWorkOrder.ActiveSheet.Cells[e.Row, (int)WORKORDER.FLOW].Text;
                sflow_desc = spdWorkOrder.ActiveSheet.Cells[e.Row, (int)WORKORDER.FLOW_DESC].Text;
                txtComment.Text = spdWorkOrder.ActiveSheet.Cells[e.Row, (int)WORKORDER.COMMENT].Text;


                if (spdWorkOrder.ActiveSheet.ActiveRowIndex == e.Row)
                {
                    return;
                }


                if (MPCF.Trim(sOrder_id) != "")
                {
                    ViewBom(sOrder_id);

                    if (MPCF.Trim(sflow) != "")
                    {
                        cdvFlow.Text = sflow;
                        cdvFlow.DisplayText = sflow_desc;

                        ViewOper();
                    }
                }
                else
                {
                    ClearData("FLOW");
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdBom_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            string stmp = "";

            try
            {
                if (e.Column == (int)BOM.OPER_SELECT || e.Column == (int)BOM.MAT_SELECT)
                {
                    cdvGridButton1.Init();
                    MPCF.InitListView(cdvGridButton1.GetListView);
                    cdvGridButton1.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridButton1.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                    if (e.Column == (int)BOM.OPER_SELECT)
                    {
                        //공정 조회
                        if (WIPLIST.ViewOperationList(cdvGridButton1.GetListView, '2', cdvFlow.Text) == false)
                            return;

                        cdvGridButton1.ShowPopupList(e.Row, e.Column);
                        cdvGridButton1.InsertEmptyRow(0, 1);
                    }
                    else if (e.Column == (int)BOM.MAT_SELECT)
                    {
                        if (MPCF.Trim(spdBom.ActiveSheet.Cells[spdBom.ActiveSheet.ActiveRowIndex, (int)BOM.OPER].Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + "Operation" + "]");
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

        private void cdvGridButton1_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
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

        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            try
            {
                if (spdWorkOrder_Sheet1.RowCount != 0)
                {
                    //무조건 한줄에 하나씩.
                    if (spdWorkOrder_Sheet1.Cells[spdWorkOrder_Sheet1.RowCount - 1, (int)WORKORDER.ORDER_ID].Text.Trim() == "")
                    {

                        if (MPCF.ShowMsgBox(MPCF.GetMessage(591), MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                        {
                            spdWorkOrder.ActiveSheet.RemoveRows(spdWorkOrder_Sheet1.RowCount - 1, 1);
                        }
                        else
                        {
                            return;
                        }
                    }
                }



                spdWorkOrder.ActiveSheet.Rows.Add(spdWorkOrder.ActiveSheet.RowCount, 1);
                spdWorkOrder.ActiveSheet.SetValue(spdWorkOrder.ActiveSheet.RowCount - 1, (int)WORKORDER.ORDER_QTY, 0);
                spdWorkOrder.ActiveSheet.SetValue(spdWorkOrder.ActiveSheet.RowCount - 1, (int)WORKORDER.AUTO_PROD_CHANGE, "N");


                spdWorkOrder.ActiveSheet.ActiveRowIndex = spdWorkOrder.ActiveSheet.RowCount - 1;
                spdWorkOrder.SetViewportTopRow(0, spdWorkOrder.ActiveSheet.RowCount - 1);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnRowDelete_Click(object sender, EventArgs e)
        {
            try
            {

                if (spdWorkOrder_Sheet1.RowCount != 0)
                {


                    if (MPCF.Trim(spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_ID].Text) != "")
                    {
                        //CMN527 INFO -  이미 등록된 작업지시는 삭제할 수 없습니다.
                        MPCF.ShowMsgBox(MPCF.GetMessage(527));
                        return;
                    }
                    else
                    {
                        spdWorkOrder.ActiveSheet.RemoveRows(spdWorkOrder.ActiveSheet.ActiveRowIndex, 1);
                        spdWorkOrder.ActiveSheet.ActiveRowIndex = spdWorkOrder.ActiveSheet.RowCount - 1;
                        spdWorkOrder.SetViewportTopRow(0, spdWorkOrder.ActiveSheet.RowCount - 1);

                        if (spdWorkOrder_Sheet1.RowCount != 0)
                        {

                            if (MPCF.Trim(spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_ID].Text) != "")
                            {
                                ViewBom(spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_ID].Text);
                                cdvFlow.Text = spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.FLOW].Text;
                                cdvFlow.DisplayText = spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.FLOW_DESC].Text;
                                ViewOper();
                            }
                            else
                            {
                                ClearData("FLOW");
                            }
                        }

                    }

                }




            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnRowAddBom_Click(object sender, EventArgs e)
        {
            try
            {
                if (spdWorkOrder.ActiveSheet.RowCount == 0)
                {
                    //CMN452 CONFIRM  - 선택된 작업지시가 없습니다. 작업지시를 선택하세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(452));
                    return;
                }

                if (MPCF.Trim(cdvFlow.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFlow.Text + "]");
                    cdvFlow.Focus();
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

        private void btnRowDeleteBom_Click(object sender, EventArgs e)
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

        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                ClearData("ALL");
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

                ViewOrder();
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

                if (SaveOrder('1'))
                {
                    ClearData("ORDER");

                    ViewOrder();
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

                if (spdWorkOrder_Sheet1.RowCount != 0)
                {


                    if (CheckCondition(CSGC.CHECK.DELETE) == false)
                        return;

                    if (SaveOrder('2'))
                    {
                        ViewOrder();
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }





        #endregion

        private void btnCopyPaste_Click(object sender, EventArgs e)
        {

            try
            {
                if (spdWorkOrder_Sheet1.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_ID].Text.Trim() == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(592));
                    return;
                }



                if (spdWorkOrder_Sheet1.Cells[spdWorkOrder_Sheet1.RowCount - 1, (int)WORKORDER.ORDER_ID].Text.Trim() == "")
                {
                    spdWorkOrder.ActiveSheet.RemoveRows(spdWorkOrder_Sheet1.RowCount - 1, 1);
                }



                int iActiveRow = spdWorkOrder.ActiveSheet.ActiveRowIndex;


                spdWorkOrder.ActiveSheet.Rows.Add(spdWorkOrder.ActiveSheet.RowCount, 1);
                // spdWorkOrder.ActiveSheet.SetValue(spdWorkOrder.ActiveSheet.RowCount - 1, (int)WORKORDER.ORDER_QTY, 0);
                // spdWorkOrder.ActiveSheet.SetValue(spdWorkOrder.ActiveSheet.RowCount - 1, (int)WORKORDER.AUTO_PROD_CHANGE, "N");

                int iInsertRow = spdWorkOrder.ActiveSheet.RowCount - 1;

                spdWorkOrder_Sheet1.SetValue(iInsertRow, (int)WORKORDER.CHK, true);
                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.ORDER_ID].Text = "";
                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.CREATE_CODE].Value = spdWorkOrder_Sheet1.Cells[iActiveRow, (int)WORKORDER.CREATE_CODE].Value;
                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.CREATE_DESC].Value = spdWorkOrder_Sheet1.Cells[iActiveRow, (int)WORKORDER.CREATE_DESC].Value;
                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.AUTO_PROD_CHANGE].Value = spdWorkOrder_Sheet1.Cells[iActiveRow, (int)WORKORDER.AUTO_PROD_CHANGE].Value;


                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.START_DATE].Value = DateTime.Now.ToString("yyyy-MM-dd"); //MPCF.MakeDateFormat(dt.Rows[i]["START_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.END_DATE].Value = DateTime.Now.ToString("yyyy-MM-dd"); //MPCF.MakeDateFormat(dt.Rows[i]["END_DATE"].ToString(), DATE_TIME_FORMAT.DATE);


                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.MAT_ID].Value = spdWorkOrder_Sheet1.Cells[iActiveRow, (int)WORKORDER.MAT_ID].Value;
                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.MAT_DESC].Value = spdWorkOrder_Sheet1.Cells[iActiveRow, (int)WORKORDER.MAT_DESC].Value;
                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.UNIT].Value = spdWorkOrder_Sheet1.Cells[iActiveRow, (int)WORKORDER.UNIT].Value;
                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.MAT_VER].Value = spdWorkOrder_Sheet1.Cells[iActiveRow, (int)WORKORDER.MAT_VER].Value;
                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.ORDER_QTY].Value = spdWorkOrder_Sheet1.Cells[iActiveRow, (int)WORKORDER.ORDER_QTY].Value;
                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.STOCK_CODE].Value = spdWorkOrder_Sheet1.Cells[iActiveRow, (int)WORKORDER.STOCK_CODE].Value;
                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.STOCK].Value = spdWorkOrder_Sheet1.Cells[iActiveRow, (int)WORKORDER.STOCK].Value;
                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.ORDER_STATUS].Value = spdWorkOrder_Sheet1.Cells[iActiveRow, (int)WORKORDER.ORDER_STATUS].Value;
                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.FLOW].Value = spdWorkOrder_Sheet1.Cells[iActiveRow, (int)WORKORDER.FLOW].Value;
                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.FLOW_DESC].Value = spdWorkOrder_Sheet1.Cells[iActiveRow, (int)WORKORDER.FLOW_DESC].Value;
                spdWorkOrder_Sheet1.Cells[iInsertRow, (int)WORKORDER.COMMENT].Value = spdWorkOrder_Sheet1.Cells[iActiveRow, (int)WORKORDER.COMMENT].Value;

                txtComment.Text = spdWorkOrder_Sheet1.Cells[iActiveRow, (int)WORKORDER.COMMENT].Text;


                spdWorkOrder.ActiveSheet.ActiveRowIndex = iInsertRow;


                spdWorkOrder.SetViewportTopRow(0, iInsertRow);


                for (int i = 0; i < spdWorkOrder.ActiveSheet.RowCount; i++)
                {
                    spdWorkOrder.ActiveSheet.SetValue(i, (int)WORKORDER.CHK, false);
                    spdWorkOrder.ActiveSheet.Cells[i, (int)WORKORDER.CHK].BackColor = System.Drawing.Color.White;

                }
                spdWorkOrder.ActiveSheet.SetValue(iInsertRow, (int)WORKORDER.CHK, true);
                spdWorkOrder.ActiveSheet.Cells[iInsertRow, (int)WORKORDER.CHK].BackColor = System.Drawing.Color.Red;



            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }



        private void BomQttyChange()
        {
            double dOrderQty = 0;
            double dTotalQty = 0;
            double dUnit = 0;

            try
            {
               if(spdBom.ActiveSheet.RowCount == 0 )
                {
                    return;
                }


                for (int iRow = 0; iRow < spdBom.ActiveSheet.RowCount; iRow++)
                {

                    dOrderQty = MPCF.ToDbl(spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_QTY].Text);


                    dUnit = MPCF.ToDbl(spdBom.ActiveSheet.Cells[iRow, (int)BOM.UNIT_QTY].Text);
                    dTotalQty = Math.Round(dUnit * dOrderQty, 5);

                    spdBom.ActiveSheet.SetValue(iRow, (int)BOM.TOTAL_QTY, dTotalQty);
                    spdBom.ActiveSheet.SetValue(iRow, (int)BOM.CHK, true);

                    /*
                    if (spdBom.ActiveSheet.ActiveColumnIndex == (int)BOM.TOTAL_QTY)
                    {
                        dTotalQty = MPCF.ToDbl(spdBom.ActiveSheet.Cells[iRow, (int)BOM.TOTAL_QTY].Text);
                        dUnit = Math.Round(dTotalQty / dOrderQty, 5);

                        spdBom.ActiveSheet.SetValue(iRow, (int)BOM.UNIT_QTY, dUnit);
                        spdBom.ActiveSheet.SetValue(iRow, (int)BOM.CHK, true);
                    }
                    else if (spdBom.ActiveSheet.ActiveColumnIndex == (int)BOM.UNIT_QTY)
                    {
                        dUnit = MPCF.ToDbl(spdBom.ActiveSheet.Cells[iRow, (int)BOM.UNIT_QTY].Text);
                        dTotalQty = Math.Round(dUnit * dOrderQty, 5);

                        spdBom.ActiveSheet.SetValue(iRow, (int)BOM.TOTAL_QTY, dTotalQty);
                        spdBom.ActiveSheet.SetValue(iRow, (int)BOM.CHK, true);
                    }
                    */
                }


                  
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdOper_CellDoubleClick(object sender, CellClickEventArgs e)
        {
            if (spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_ID].Text != "")
                //CMN INFO - 작업지시공정 LOT진행 바로 하시겠습니까?
                if (MPCF.ShowMsgBox(MPCF.GetMessage(588), MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                {

                    frmTranLotMapping popup = new frmTranLotMapping();
                    popup.StartPosition = FormStartPosition.CenterParent;
                    popup.sArea_id = cdvDept.Text;
                    popup.sArea_desc = cdvDept.DisplayText;
                    popup.sSub_area_id = "";
                    popup.sSub_area_desc = "";
                    popup.sOper_id = "OC05001";
                    popup.sOper_desc = "작업지시(WORK ORDER)";
                    popup.sOrder_id = spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_ID].Text;
                    popup.sLot_id = "";



                    if (popup.ShowDialog() == DialogResult.OK)
                    {
                        popup = null;
                    }



                }
        }
    }
}
