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

namespace CUS_SHP
{
    public partial class frmViewShippingOrder : CUS_COM.frmViewForm01
    {
        public frmViewShippingOrder()
        {
            InitializeComponent();

            InitControl();
        }


        #region " Constant Definition "

        private enum SHIP_MST
        {
            SHIP_ORDER_ID,          // 1 : 출하 지시 번호
            SHIP_ORD_DATE,          // 2 : 출하 지시 일자
            CUSTOMER_ID,            // 3 : 거래선번호
            CUSTOMER_NUMBER,        // 4 : 거래선번호
            CUSTOMER_NAME,          // 5 : 거래선명
            AREA_DESC,              // 6 : 사업부
            OPER,                   // 7 : 출하창고
            OPER_DESC,              // 8 : 출하창고 명
            DELIVERY,               // 9 : 납품처
            DELIVERY_ID,            // 10 : 납품처 ID
            DELIVERY_NAME,          // 11 : 납품처명
            DELIVERY_LOCATION,      // 12 : 납품 위치
            DELIVERY_PHONE_NO,      // 13 : 납품사 핸드폰 번호
            DELIVERY_USER_ID,       // 14 : 납품자
            SHIP_ORD_STATUS,        // 15 : 출하 지시 상태
            DELETE_FLAG             // 16 : 삭제여부
        }

        private enum SHIP_DTL
        {
            SHIP_ORDER_ID,         // 1 : 출하 지시 번호
            SEQ,                   // 2 : 출하 순번
            MAT_ID,                // 3 : 제품
            MAT_VER,               // 4 : 버전
            MAT_DESC,              // 5 : 제품명
            SHIP_ORD_STATUS,       // 6 : 출하 상태
            PACK_ORDER_ID,         // 7 : 포장 지시 번호
            PACK_LINE_NO,          // 8 : 포장 라인 번호
            ERP_PACK_ORDER_ID,     // 9 : ERP 포장 지시 번호
            QTY,                   // 10 : 수량
            SHIPPED_QTY,           // 11 : 출하 완료 수량
            UNIT,                  // 12 : 단위
            DELETE_FLAG            // 13 : 삭제여부
        }

        #endregion

        #region " Variable Definition "

        string shipOrderId = "";
        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 초기화
        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":
                        MPCF.ClearList(spdOrderList);
                        MPCF.ClearList(spdOrderDetailList);
                        break;
                    case "ORDER_CLICK_CELL":
                        MPCF.ClearList(spdOrderDetailList);
                        break;
                }
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


        private void ViewShippingOrderList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[10];
                DataTable dt = null;
                string sSql = "";

                int i = 0;
                               
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text.Trim();

                dvcArgu[2].sCondition_ID = "SHIP_ORDER_ID";
                dvcArgu[2].sCondition_Value = txtShippingOrderNo.Text.Trim();

                dvcArgu[3].sCondition_ID = "MAT_ID";
                dvcArgu[3].sCondition_Value = cdvMatId.Text.Trim();

                dvcArgu[4].sCondition_ID = "CUSTOMER_ID";
                dvcArgu[4].sCondition_Value = cdvCustomerID.Text.Trim();

                dvcArgu[5].sCondition_ID = "FROM_DATE";
                dvcArgu[5].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));

                dvcArgu[6].sCondition_ID = "TO_DATE";
                dvcArgu[6].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";

                dvcArgu[7].sCondition_ID = "OPER";
                dvcArgu[7].sCondition_Value = cdvOper.Text.Trim();

                dvcArgu[8].sCondition_ID = "ERP_SHIP_ORDER_ID";
                dvcArgu[8].sCondition_Value = txtERPPackingOrderNo.Text.Trim();

                dvcArgu[9].sCondition_ID = "SHIP_ORD_STATUS";
                dvcArgu[9].sCondition_Value = cdvShipStatus.Text;

                if (TPDR.GetDataOne("", ref dt, "CSHP3001-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdOrderList);
                    return;
                }

                MPCF.ClearList(spdOrderList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdOrderList_Sheet1.RowCount++;

                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.SHIP_ORDER_ID].Value = dt.Rows[i]["SHIP_ORDER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.SHIP_ORD_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["SHIP_ORD_DATE"].ToString(), DATE_TIME_FORMAT.DATE); 
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.CUSTOMER_ID].Value = dt.Rows[i]["CUSTOMER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.CUSTOMER_NUMBER].Value = dt.Rows[i]["CUSTOMER_NUMBER"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.CUSTOMER_NAME].Value = dt.Rows[i]["CUSTOMER_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.OPER].Value = dt.Rows[i]["OPER"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.DELIVERY].Value = dt.Rows[i]["DELIVERY"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.DELIVERY_ID].Value = dt.Rows[i]["DELIVERY_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.DELIVERY_NAME].Value = dt.Rows[i]["DELIVERY_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.DELIVERY_LOCATION].Value = dt.Rows[i]["DELIVERY_LOCATION"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.DELIVERY_PHONE_NO].Value = dt.Rows[i]["DELIVERY_PHONE_NO"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.DELIVERY_USER_ID].Value = dt.Rows[i]["DELIVERY_USER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.SHIP_ORD_STATUS].Value = dt.Rows[i]["SHIP_ORD_STATUS"];
                    spdOrderList_Sheet1.Cells[i, (int)SHIP_MST.DELETE_FLAG].Value = dt.Rows[i]["DELETE_FLAG"];

                }
                MPCF.FitColumnHeader(spdOrderList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewShippingOrderDetailList(string sShipOrderId)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";

                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "SHIP_ORDER_ID";
                dvcArgu[1].sCondition_Value = sShipOrderId;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatId.Text.Trim();            

                if (TPDR.GetDataOne("", ref dt, "CSHP3001-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdOrderDetailList);
                    return;
                }

                MPCF.ClearList(spdOrderDetailList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdOrderDetailList_Sheet1.RowCount++;

                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.SHIP_ORDER_ID].Value = dt.Rows[i]["SHIP_ORDER_ID"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.SEQ].Value = dt.Rows[i]["SEQ"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.SHIP_ORD_STATUS].Value = dt.Rows[i]["SHIP_ORD_STATUS"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.PACK_LINE_NO].Value = dt.Rows[i]["PACK_LINE_NO"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.ERP_PACK_ORDER_ID].Value = dt.Rows[i]["CMF_1"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.QTY].Value = dt.Rows[i]["QTY"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.SHIPPED_QTY].Value = dt.Rows[i]["SHIPPED_QTY"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdOrderDetailList_Sheet1.Cells[i, (int)SHIP_DTL.DELETE_FLAG].Value = dt.Rows[i]["DELETE_FLAG"];
                }
                MPCF.FitColumnHeader(spdOrderDetailList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //출하지시 마스터 정보 조회
        private void ViewShippingOrderList_OLD()
        {
            TRSNode in_node = new TRSNode("VIEW_SHIPPING_ORDER_IN ");
            TRSNode out_node = new TRSNode("VIEW_SHIPPING_ORDER_OUT");

            int iRow = 0;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("SHIP_ORDER_ID", MPCF.Trim(txtShippingOrderNo.Text));
                in_node.AddString("FROM_DATE", string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", "")));
                in_node.AddString("TO_DATE", dtpToWorkDate.Text.Replace("-", "") + "235959");

                do
                {
                    if (MPCR.CallService("CUS_SHP", "CUS_SHP_View_Order_List", in_node, ref out_node) == false)
                    {
                        return ;
                    }

                    for (int i = 0; i < out_node.GetList("ORDER_TBL").Count; i++)
                    {
                        iRow = spdOrderList_Sheet1.RowCount;

                        spdOrderList_Sheet1.RowCount++;

                        spdOrderList_Sheet1.Cells[iRow, (int)SHIP_MST.SHIP_ORDER_ID].Value = out_node.GetList("ORDER_TBL")[i].GetString("SHIP_ORDER_ID");
                        spdOrderList_Sheet1.Cells[iRow, (int)SHIP_MST.SHIP_ORD_DATE].Value = MPCF.MakeDateFormat(out_node.GetList("ORDER_TBL")[i].GetString("SHIP_ORD_DATE"), DATE_TIME_FORMAT.DATE);
                        spdOrderList_Sheet1.Cells[iRow, (int)SHIP_MST.CUSTOMER_ID].Value = out_node.GetList("ORDER_TBL")[i].GetString("CUSTOMER_ID");
                        spdOrderList_Sheet1.Cells[iRow, (int)SHIP_MST.CUSTOMER_NUMBER].Value = out_node.GetList("ORDER_TBL")[i].GetString("CUSTOMER_NUMBER");
                        spdOrderList_Sheet1.Cells[iRow, (int)SHIP_MST.CUSTOMER_NAME].Value = out_node.GetList("ORDER_TBL")[i].GetString("CUSTOMER_NAME");
                        spdOrderList_Sheet1.Cells[iRow, (int)SHIP_MST.AREA_DESC].Value = out_node.GetList("ORDER_TBL")[i].GetString("AREA_DESC");
                        spdOrderList_Sheet1.Cells[iRow, (int)SHIP_MST.OPER].Value = "";
                        spdOrderList_Sheet1.Cells[iRow, (int)SHIP_MST.OPER_DESC].Value = "";
                        spdOrderList_Sheet1.Cells[iRow, (int)SHIP_MST.DELIVERY].Value = out_node.GetList("ORDER_TBL")[i].GetString("DELIVERY");
                        spdOrderList_Sheet1.Cells[iRow, (int)SHIP_MST.DELIVERY_ID].Value = out_node.GetList("ORDER_TBL")[i].GetInt("DELIVERY_ID");
                        spdOrderList_Sheet1.Cells[iRow, (int)SHIP_MST.DELIVERY_NAME].Value = out_node.GetList("ORDER_TBL")[i].GetString("DELIVERY_NAME");
                        spdOrderList_Sheet1.Cells[iRow, (int)SHIP_MST.DELIVERY_LOCATION].Value = out_node.GetList("ORDER_TBL")[i].GetString("DELIVERY_LOCATION");
                        spdOrderList_Sheet1.Cells[iRow, (int)SHIP_MST.DELIVERY_PHONE_NO].Value = out_node.GetList("ORDER_TBL")[i].GetString("DELIVERY_PHONE_NO");
                        spdOrderList_Sheet1.Cells[iRow, (int)SHIP_MST.DELIVERY_USER_ID].Value = out_node.GetList("ORDER_TBL")[i].GetString("DELIVERY_USER_ID");
                        spdOrderList_Sheet1.Cells[iRow, (int)SHIP_MST.SHIP_ORD_STATUS].Value = out_node.GetList("ORDER_TBL")[i].GetString("SHIP_ORD_STATUS");
                        spdOrderList_Sheet1.Cells[iRow, (int)SHIP_MST.DELETE_FLAG].Value = out_node.GetList("ORDER_TBL")[i].GetChar("DELETE_FLAG");
                    }
                    if (out_node.GetString("NEXT_SHIP_ORDER_ID") != "")
                        in_node.SetString("NEXT_SHIP_ORDER_ID", out_node.GetString("NEXT_SHIP_ORDER_ID"));
                    else
                        in_node.SetString("NEXT_SHIP_ORDER_ID", "");
                } while (in_node.GetString("NEXT_SHIP_ORDER_ID") != "");

                MPCF.FitColumnHeader(spdOrderList);

            }      
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 출하지시 상세 정보 조회
        private void  ViewShippingOrderDetailList_OLD(string orderId)
        {
            TRSNode in_node = new TRSNode("VIEW_SHIPPING_ORDER_IN ");
            TRSNode out_node = new TRSNode("VIEW_SHIPPING_ORDER_OUT");

            int iRow = 0;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';

                in_node.AddString("SHIP_ORDER_ID", orderId);

                do
                {
                    if (MPCR.CallService("CUS_SHP", "CUS_SHP_View_Order_List", in_node, ref out_node) == false)
                    {
                        return;
                    }

                    for (int i = 0; i < out_node.GetList("ORDER_TBL").Count; i++)
                    {
                        iRow = spdOrderDetailList_Sheet1.RowCount;

                        spdOrderDetailList_Sheet1.RowCount++;

                        spdOrderDetailList_Sheet1.Cells[iRow, (int)SHIP_DTL.SHIP_ORDER_ID].Value = out_node.GetList("ORDER_TBL")[i].GetString("SHIP_ORDER_ID");
                        spdOrderDetailList_Sheet1.Cells[iRow, (int)SHIP_DTL.SEQ].Value = out_node.GetList("ORDER_TBL")[i].GetInt("SEQ");
                        spdOrderDetailList_Sheet1.Cells[iRow, (int)SHIP_DTL.MAT_ID].Value = out_node.GetList("ORDER_TBL")[i].GetString("MAT_ID");
                        spdOrderDetailList_Sheet1.Cells[iRow, (int)SHIP_DTL.MAT_VER].Value = out_node.GetList("ORDER_TBL")[i].GetInt("MAT_VER");
                        spdOrderDetailList_Sheet1.Cells[iRow, (int)SHIP_DTL.MAT_DESC].Value = out_node.GetList("ORDER_TBL")[i].GetString("MAT_DESC");
                        spdOrderDetailList_Sheet1.Cells[iRow, (int)SHIP_DTL.SHIP_ORD_STATUS].Value = out_node.GetList("ORDER_TBL")[i].GetString("SHIP_ORD_STATUS");
                        spdOrderDetailList_Sheet1.Cells[iRow, (int)SHIP_DTL.PACK_ORDER_ID].Value = out_node.GetList("ORDER_TBL")[i].GetString("PACK_ORDER_ID");
                        spdOrderDetailList_Sheet1.Cells[iRow, (int)SHIP_DTL.PACK_LINE_NO].Value = out_node.GetList("ORDER_TBL")[i].GetInt("PACK_LINE_NO");
                        spdOrderDetailList_Sheet1.Cells[iRow, (int)SHIP_DTL.ERP_PACK_ORDER_ID].Value = out_node.GetList("ORDER_TBL")[i].GetString("CMF_1");
                        spdOrderDetailList_Sheet1.Cells[iRow, (int)SHIP_DTL.QTY].Value = out_node.GetList("ORDER_TBL")[i].GetDouble("QTY");
                        spdOrderDetailList_Sheet1.Cells[iRow, (int)SHIP_DTL.SHIPPED_QTY].Value = out_node.GetList("ORDER_TBL")[i].GetDouble("SHIPPED_QTY");
                        spdOrderDetailList_Sheet1.Cells[iRow, (int)SHIP_DTL.UNIT].Value = out_node.GetList("ORDER_TBL")[i].GetString("UNIT");
                        spdOrderDetailList_Sheet1.Cells[iRow, (int)SHIP_DTL.DELETE_FLAG].Value = out_node.GetList("ORDER_TBL")[i].GetChar("DELETE_FLAG");
                    }
                    in_node.SetInt("NEXT_SEQ", out_node.GetInt("NEXT_SEQ"));

                } while (in_node.GetInt("NEXT_SEQ") >0);

                MPCF.FitColumnHeader(spdOrderDetailList);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion

        #region " Event Definition"

        private void frmViewShippingOrder_Load(object sender, EventArgs e)
        {
            try
            {
                dtpToWorkDate.Value = DateTime.Now;
                dtpFromWorkDate.Value = DateTime.Now;
                dtpFromWorkDate.Format = DateTimePickerFormat.Custom;
                dtpFromWorkDate.CustomFormat = " ";
                
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

                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, '5', cdvDept.Text, "", "", "", 'Y', "", ' ', 'Y') == false)
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

        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Init();
                MPCF.InitListView(cdvDept.GetListView);
                cdvDept.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvDept.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDept.SelectedSubItemIndex = 0;
                cdvDept.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDept.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                {
                    return;
                }
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
                cdvOper.Text = "";
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

                ClearData("VIEW");

                ViewShippingOrderList();
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdOrderList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                

                ClearData("ORDER_CLICK_CELL");

                if (e.ColumnHeader||e.Row < 0)
                {
                    return;
                }
                //for (int i = 0; i < spdOrderList.ActiveSheet.RowCount; i++)
                //{
                //    spdOrderList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                //}

                //spdOrderList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdOrderList, e.Row);

                }

                shipOrderId = spdOrderList.ActiveSheet.Cells[e.Row, (int)SHIP_MST.SHIP_ORDER_ID].Text;

                ViewShippingOrderDetailList(shipOrderId);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOper_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvOper.DisplayText == "")
                cdvOper.Text = "";
        }

        private void spdOrderDetailList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdOrderDetailList, e.Row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                FpSpread excelSp = new FpSpread();              
                spdOrderList_Sheet1.SheetName = "Sheet1";
                excelSp.Sheets.Add(spdOrderList_Sheet1);
                spdOrderDetailList_Sheet1.SheetName = "Sheet2";
                excelSp.Sheets.Add(spdOrderDetailList_Sheet1);

                EXTFUC.SaveExcel(excelSp, "ShippingOrderList");
              
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }
        private void dtpFromWorkDate_ValueChanged(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";

        }

        private void dtpFromWorkDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtpFromWorkDate.CustomFormat = " ";
                    break;
            }

        }

        private void cdvMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatId.DisplayText == "")
                cdvMatId.Text = "";
        }

        private void cdvMatId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMatId.Text = popup.sMat_id;
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

        private void txtShippingOrderNo_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvCustomerID_TextBoxTextChanged(object sender, EventArgs e)
        {

            if (cdvCustomerID.DisplayText == "")
                cdvCustomerID.Text = "";
        }

        private void cdvCustomerID_ButtonPress(object sender, EventArgs e)
        {
            try
            {

                frmPopCustomerList popup = new frmPopCustomerList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvCustomerID.Text = popup.g_CustomerId;
                    this.cdvCustomerID.DisplayText = popup.g_CustomerDesc;
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

        private void txtERPPackingOrderNo_KeyPress(object sender, KeyPressEventArgs e)
        {

            try
            {
                if (e.KeyChar == (char)13)
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void dtpFromWorkDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";
        }

        private void cdvShipStatus_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvShipStatus.Init();
                MPCF.InitListView(cdvShipStatus.GetListView);
                cdvShipStatus.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvShipStatus.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvShipStatus.SelectedSubItemIndex = 0;
                cdvShipStatus.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvShipStatus.GetListView, '1', CSGC.CP_GCM_SHIP_ORDER_STATUS) == false)
                {
                    return;
                }

                cdvShipStatus.InsertEmptyRow(0, 1);
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
                if (spdOrderList.ActiveSheet.RowCount == 0)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return;
                }

                TRSNode order_list;
                TRSNode in_node = new TRSNode("print_label_In");
                string file_name = "sal510q";
                
                MPCR.SetInMsg(in_node);
                order_list = in_node.AddNode("SHIP_ORDER_LIST");
                order_list.AddString("SHIP_ORDER_ID", shipOrderId);

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion
    }
}
