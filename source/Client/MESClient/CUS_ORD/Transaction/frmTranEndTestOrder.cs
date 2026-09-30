using CUS_COM;
using FarPoint.Win.Spread;
using Microsoft.Office.Interop.Excel;
using Miracom.CliFrx;
using Miracom.DNMCore;
using Miracom.MESCore;
using Miracom.TRSCore;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;
using System.Xml.Linq;

namespace CUS_ORD
{
    public partial class frmTranEndTestOrder : CUS_COM.frmTranForm06
    {
        public frmTranEndTestOrder()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum WORKORDER
        {
            CHK,                    // 0 : 체크
            ORDER_ID,               // 1 : 작업지시번호
            CREATE_CODE,            // 2 : 지시 유형
            CREATE_DESC,            // 3 : 지시 유형명
            AUTO_PROD_CHANGE,       // 4 : 자동 양산품 전환 여부
            START_DATE,             // 5 : 시작일
            END_DATE,               // 6 : 완료일
            MAT_ID,                 // 7 : 제품코드 
            MAT_DESC,               // 8 : 제품명
            UNIT,                   // 9 : 단위
            MAT_VER,                //10 : 제품버전 
            ORDER_QTY,              //11 : 지시수량
            STOCK_CODE,             //12 : 창고
            STOCK,                  //13 : 창고
            ORDER_STATUS,           //14 : 지시 상태
            FLOW,                   //15 : 플로우
            FLOW_DESC,              //16 : 플로우명
            COMMENT                 //17 : 주석
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

                if (spdWorkOrder_Sheet1.RowCount == 0)
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
                
        private bool SaveOrder(char sStep)
        {
            try
            {
                
                //    for (int i = 0; i < spdETCLotList_Sheet1.RowCount; i++)
                //    {
                //        if (spdETCLotList_Sheet1.Cells[i, (int)LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                //        {
                //            lot_list = in_node.AddNode("LOT_LIST");
                //            lot_list.AddString("LOT_ID", spdETCLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text);
                //            lot_list.AddInt("SEQ", MPCF.ToInt(spdETCLotList_Sheet1.Cells[i, (int)LOT.SEQ].Text));
                //            lot_list.AddString("COMMENT", spdETCLotList_Sheet1.Cells[i, (int)LOT.COMMENT].Text);
                //            send_flag = true;
                //        }
                //    }

                //    if (send_flag == false)
                //    {
                //        //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                //        MPCF.ShowMsgBox(MPCF.GetMessage(109));
                //        return false;
                //    }

                //    if (MPCR.CallService("CUS_INV", "CUS_INV_Change_Etc_Comment", in_node, ref out_node) == false)
                //        return false;

                //    MPCR.ShowSuccessMsg(out_node);

                //    return true;
                //}
                //catch (Exception ex)
                //{
                //    MPCF.ShowMsgBox(ex.Message);
                //    return false;
                //}


                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode order_list;
                bool send_flag = false;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = sStep;
                // for (int i = 0; i < spdETCLotList_Sheet1.RowCount; i++)
                for (int i = 0; i < spdWorkOrder_Sheet1.RowCount; i++)
                {
                    if (spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        order_list = in_node.AddNode("ORDER_LIST");
                        order_list.AddString("AREA_ID", cdvDept.Text); 
                        order_list.AddString("ORDER_ID", spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_ID].Text);
                        send_flag = true;
                    } 

                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }
                 

                if (MPCR.CallService("CUS_ORD", "CUS_ORD_Create_Test_Order", in_node, ref out_node) == false)
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
                        break;

                    case "ALL":

                        cdvOrder.Text = "";
                        cdvWorkPlace.Text = "";
                        cdvMat.Text = "";
                        cdvStatus.Text = "";
                        
                        MPCF.ClearList(spdWorkOrder);
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

        private void frmTranEndTestOrder_Load(object sender, EventArgs e)
        {
            try
            {
                dtpFromDate.Value = dtpToDate.Value.AddDays(-7);
                dtpToDate.Value = dtpToDate.Value.AddDays(7);
                                
                //cdvOrderType.Text = "TEST";
                //cdvOrderType.DisplayText = "Test Lot(생산)";
                //cdvStatus.Text = "W";
                //cdvStatus.DisplayText = "Wait";
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
        

        private void spdWorkOrder_CellClick(object sender, CellClickEventArgs e)
        {           
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)WORKORDER.CHK)
                    {
                        CSCF.CheckSpreadCell(spdWorkOrder, 0, 0, true, true);
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
                //if (MPCF.ShowMsgBox("PO LINE OPEN? (Please process ERP separately)? \r\n  해당라인 OPEN 하시겠습니까?(ERP는 별도 확인 및 처리하셔야합니다.) ", MessageBoxButtons.YesNo, 2) == DialogResult.Yes)
                 
                if (MPCF.ShowMsgBox(MPCF.GetMessage(626), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                {
                    return;
                }

                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                // 테스트작업지시 CLOSE
                if (SaveOrder('3'))
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

        #endregion


    }
}
