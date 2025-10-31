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
using CUS_COM.Reports;
using FarPoint.Excel.EntityClassLibrary.DrawingVML;

namespace CUS_SHP
{
    public partial class frmViewShippingLot : CUS_COM.frmViewForm01
    {
        public frmViewShippingLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum SHIPPING_LOT
        {
            CHK,                     // 1 : CHK
            ORG_LOT_ID,              // 2 : 공정 LOT ID
            PACK_LOT_ID,             // 3 : 포장 LOT ID       
            INSPECTION_LOT_ID,       // 4 : 검사 LOT ID             
            MAT_ID,                  // 5 : 제품
            MAT_VER,                 // 6 : 버전
            MAT_DESC,                // 7 : 제품명
            LABEL_NAME,              // 8 : 라벨명
            OPERATION_MAT_ID,                 // 육면적때문에 추가(생산 품목코드)
            OPERATION_MAT_DESC,                 // 육면적때문에 추가(생산 품명)
            UT_MIN,
            UT_MAX,
            UT_DEV,
            FLATENSS,
            QTY,                     // 9 : 수량
            UNIT,                    // 10 : 단위
            CONV_UNIT_QTY,           // 11 : 제품 단위 수량           
            CONV_STOCK_QTY,          // 12 : 환산 재고 수량           
            CONV_UNIT,               // 13 : 환산 단위
            AREA_DESC,               // 14 : 사업부
            CUSTOMER_ID,             // 15 : 고객사 
            CUSTOMER_NAME,           // 16 : 고객사명
            DELIVERY_ID,             // 17 : 고객사 
            DELIVERY_NAME,           // 18 : 고객사명
            PACK_FLAG,               // 19 : 포장 여부
            IN_WH_DATE,
            PACK_DATE,               // 20 : 포장 일자
            PACK_ORDER_ID,           // 21 : 포장 지시 번호
            PACK_LINE_NO,            // 22 : 포장 지시 라인 번호
            PACK_ORD_DATE,           // 23 : 포장 지시 일자
            ERP_PACK_ORDER_ID,       // 24 : ERP 포장 지시 번호
            SHIP_FLAG,               // 25 : 출하 상태
            SHIP_DATE,               // 26 : 출하 일자
            SHIP_ORDER_ID,           // 27 : 출하 지시 번호
            SHIP_ORDER_SEQ,          // 28 : 출하 지시 순번
            BOX_ID_1,                // 29 : 중 박스 ID
            BOX_ID_2,                // 30 : 대 박스 ID
            PACKING_INSTRUCTIONS,     // 31 : 용기
            USER_ID,     
            USER_NAME     
        }

        #endregion

        #region " Variable Definition "
        string file_name = "";
        public string g_Popup_yn = "N";
        public string g_Dept = "";
        public string g_ERPPackingOrderNo = "";
        public string g_ERPPackingOrderLine = "";



        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                chkMeshDeleteFlag.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblLableSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                cdvLabelSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnCsvDirect.Anchor = AnchorStyles.Top | AnchorStyles.Left;


                //cdvLotType.Text = "SHIP";
                //cdvLotType.DisplayText = "출하LOT(SHIP LOT)";

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
                        MPCF.ClearList(spdShippingLotList);
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
        private void fnPrintShipReportHM(string sViewID, string sFileName)
        {
            try
            {
                //string sLots = "";
                string sLots = "";

                if (spdShippingLotList.ActiveSheet.RowCount == 0)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return;
                }

                else
                {

                    for (int i = 0; i < spdShippingLotList_Sheet1.RowCount; i++)
                    {

                        if (spdShippingLotList.ActiveSheet.Cells[i, (int)SHIPPING_LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                        {

                            sLots = sLots + ",'" + spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_LOT_ID].Value.ToString() + "'";
                        }


                    }
                }



                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int iRowCount = 0;
                // int i = 0;



                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "SHIP_ORDER_ID";
                dvcArgu[1].sCondition_Value = spdShippingLotList_Sheet1.Cells[spdShippingLotList.ActiveSheet.ActiveRowIndex, (int)SHIPPING_LOT.SHIP_ORDER_ID].Value;

                dvcArgu[2].sCondition_ID = "SHIP_ORDR_SEQ";
                dvcArgu[2].sCondition_Value = spdShippingLotList_Sheet1.Cells[spdShippingLotList.ActiveSheet.ActiveRowIndex, (int)SHIPPING_LOT.SHIP_ORDER_SEQ].Value;

                dvcArgu[3].sCondition_ID = "SQL_TEXT";
                dvcArgu[3].sCondition_Type = "TEXT";

                if (sLots == "")
                {
                    dvcArgu[3].sCondition_Value = "AND 1=1";
                }
                else
                {
                    dvcArgu[3].sCondition_Value = "AND   A.PACK_LOT_ID IN ('Z'" + sLots + ")";
                }


                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                dt.Columns.Add("IMAGE_A", typeof(Byte[]));
                dt.Columns.Add("IMAGE_B", typeof(Byte[]));

                iRowCount = dt.Rows.Count;

                // 이미지 조회 ( row별로 Loop )
                for (int i = 0; i < iRowCount; i++)
                {
                    string sReportNo = dt.Rows[i]["REPORT_NO"].ToString();
                    string sPackLotID = dt.Rows[i]["IMAGE_LOT_ID"].ToString();

                    TPDR.DirectViewCond[] dvcArgu_img = new TPDR.DirectViewCond[3];
                    DataTable dtImage = null;


                    dvcArgu_img[0].sCondition_ID = "FACTORY";
                    dvcArgu_img[0].sCondition_Value = MPGV.gsFactory;

                    dvcArgu_img[1].sCondition_ID = "REPORT_NO";
                    dvcArgu_img[1].sCondition_Value = sReportNo;

                    dvcArgu_img[2].sCondition_ID = "LOT_ID";
                    dvcArgu_img[2].sCondition_Value = sPackLotID;


                    if (TPDR.GetDataOne("", ref dtImage, "CQCM2101-010", dvcArgu_img, false, false, ref sSql) == false)
                    {
                        if (dtImage != null)
                            dtImage.Dispose();

                        GC.Collect();
                        return;
                    }

                    dt.Rows[i]["IMAGE_A"] = dtImage.Rows[0]["IMAGE_A"];
                    dt.Rows[i]["IMAGE_B"] = dtImage.Rows[0]["IMAGE_B"];

                }


                //일반성적서 pip510p

                DevReport.PreviewXtraReport(dt, sFileName);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        public bool ViewPrintLabel(string sFileName, TRSNode in_node)
        {
            try
            {
                CSCF.ViewLabelList(sFileName, in_node);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }



        private void ViewShipLotCount(int iOutPutType)
        {
            TRSNode in_node = new TRSNode("VIEW_SHIPPING_LOT_IN ");
            TRSNode out_node = new TRSNode("VIEW_SHIPPING_LOT_OUT");



            try
            {

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[14];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                DateTime dSearchTime = DateTime.Now;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatId.Text;

                dvcArgu[3].sCondition_ID = "CUSTOMER_ID";
                dvcArgu[3].sCondition_Value = cdvCustomerId.Text;

                dvcArgu[4].sCondition_ID = "SHIP_ORDER_ID";
                dvcArgu[4].sCondition_Value = txtShippingOrderNo.Text;

                dvcArgu[5].sCondition_ID = "FROM_DATE";
                dvcArgu[5].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));

                dvcArgu[6].sCondition_ID = "TO_DATE";
                dvcArgu[6].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";

                dvcArgu[7].sCondition_ID = "ERP_PACK_ORDER_ID";
                dvcArgu[7].sCondition_Value = txtERPPackingOrderNo.Text;

                dvcArgu[8].sCondition_ID = "DELIVERY_ID";
                dvcArgu[8].sCondition_Value = cdvVendorId.Text;

                dvcArgu[9].sCondition_ID = "MAT_DESC";
                dvcArgu[9].sCondition_Value = txtMatDesc.Text.Trim();

                dvcArgu[10].sCondition_ID = "ORG_LOT_ID";
                dvcArgu[10].sCondition_Value = txtOrgLotId.Text;

                dvcArgu[11].sCondition_ID = "PACK_LOT_ID";
                dvcArgu[11].sCondition_Value = txtPackLotId.Text;

                dvcArgu[12].sCondition_ID = "ERP_PACK_ORDER_LINE";
                dvcArgu[12].sCondition_Value = txtERPPackingOrderLine.Text;


                dvcArgu[13].sCondition_ID = "SHIP_ORDER_LINE";
                dvcArgu[13].sCondition_Value = txtShippingOrderLine.Text;




                if (cdvLotType.Text == "OPER")
                {
                    if (TPDR.GetDataOne("", ref dt, "CSHP3002-004", dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt != null)
                            dt.Dispose();

                        GC.Collect();

                        MPCF.ClearList(spdShippingLotList);
                        return;
                    }
                }
                else
                {
                    if (TPDR.GetDataOne("", ref dt, "CSHP3002-003", dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt != null)
                            dt.Dispose();

                        GC.Collect();

                        MPCF.ClearList(spdShippingLotList);
                        return;
                    }
                }
                MPCF.ClearList(spdShippingLotList);



                if (dt.Rows.Count > 1)
                {

                    //조회 데이터가 50000건이상입니다. CSV파일로 바로출력됩니다.진행하시겠습니까 ?(50000건단위로 분할출력됩니다.)
                    if (MPCF.ShowMsgBox(MPCF.GetMessage(600), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                    {
                        return;
                    }
                    else
                    {

                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            //무조건 CSV파일로
                            ViewShipLot(2, dt.Rows[i]["SHIP_DATE_BEFORE"].ToString(), dt.Rows[i]["SHIP_DATE_AFTER"].ToString(), dSearchTime);
                        }
                    }


                }
                else
                {
                    if (iOutPutType == 2)
                    {
                        ViewShipLot(2, dt.Rows[i]["SHIP_DATE_BEFORE"].ToString(), dt.Rows[0]["SHIP_DATE_AFTER"].ToString(), dSearchTime);
                    }
                    else
                    {
                        ViewShipLot(1, dt.Rows[i]["SHIP_DATE_BEFORE"].ToString(), dt.Rows[0]["SHIP_DATE_AFTER"].ToString(), dSearchTime);
                    }
                }


                return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 출하 포장 LOT 정보 조회
        private void ViewShipLot(int iOutPutType, string FromDt, string ToDt, DateTime dSearchTime)
        {
            TRSNode in_node = new TRSNode("VIEW_SHIPPING_LOT_IN ");
            TRSNode out_node = new TRSNode("VIEW_SHIPPING_LOT_OUT");

    

            try
            {
                /*
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("MAT_ID", cdvMatId.Text);
                in_node.AddString("CUSTOMER_ID", cdvCustomerId.Text);
                in_node.AddString("SHIP_ORDER_ID", MPCF.Trim(txtShippingOrderNo.Text));
                in_node.AddString("FROM_DATE", string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", "")));
                in_node.AddString("TO_DATE", dtpToWorkDate.Text.Replace("-", "") + "235959");
                in_node.AddString("ERP_PACK_ORDER_ID", MPCF.Trim(txtERPPackingOrderNo.Text));
                in_node.AddInt("DELIVERY_ID", MPCF.Trim(cdvVendorId.Text));
                in_node.AddString("MAT_DESC", MPCF.Trim(txtMatDesc.Text));


                    do
                {
                    if (MPCR.CallService("CUS_SHP", "CUS_SHP_View_Ship_Lot_List", in_node, ref out_node) == false)
                    {
                        return;
                    }

                    for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                    {
                        iRow = spdShippingLotList_Sheet1.RowCount;

                        spdShippingLotList_Sheet1.RowCount++;

                        spdShippingLotList_Sheet1.SetValue(i, (int)SHIPPING_LOT.CHK, false);
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.ORG_LOT_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("ORG_LOT_ID");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_LOT_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("PACK_LOT_ID");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.INSPECTION_LOT_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("CMF_2");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.MAT_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("MAT_ID");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.MAT_VER].Value = out_node.GetList("LOT_TBL")[i].GetInt("MAT_VER");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.MAT_DESC].Value = out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.QTY].Value = out_node.GetList("LOT_TBL")[i].GetDouble("QTY");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.UNIT].Value = out_node.GetList("LOT_TBL")[i].GetString("UNIT");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.AREA_DESC].Value = out_node.GetList("LOT_TBL")[i].GetString("AREA_DESC");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.CUSTOMER_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("CUSTOMER_ID");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.CUSTOMER_NAME].Value = out_node.GetList("LOT_TBL")[i].GetString("CUSTOMER_NAME");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.DELIVERY_ID].Value = out_node.GetList("LOT_TBL")[i].GetInt("DELIVERY_ID");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.DELIVERY_NAME].Value = out_node.GetList("LOT_TBL")[i].GetString("DELIVERY_NAME");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_FLAG].Value = out_node.GetList("LOT_TBL")[i].GetChar("PACK_FLAG");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_DATE].Value = MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("PACK_DATE"), DATE_TIME_FORMAT.DATE);
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_ORDER_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("PACK_ORDER_ID");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_LINE_NO].Value = out_node.GetList("LOT_TBL")[i].GetInt("PACK_LINE_NO");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_ORD_DATE].Value = MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("PACK_ORD_DATE"), DATE_TIME_FORMAT.DATE);
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.ERP_PACK_ORDER_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("CMF_5");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.SHIP_FLAG].Value = out_node.GetList("LOT_TBL")[i].GetChar("SHIP_FLAG");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.SHIP_DATE].Value = MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("SHIP_DATE"), DATE_TIME_FORMAT.DATE);
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.SHIP_ORDER_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("SHIP_ORDER_ID");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.SHIP_ORDER_SEQ].Value = out_node.GetList("LOT_TBL")[i].GetDouble("SHIP_ORDER_SEQ");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.BOX_ID_1].Value = out_node.GetList("LOT_TBL")[i].GetString("BOX_ID_1");
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.BOX_ID_2].Value = out_node.GetList("LOT_TBL")[i].GetString("BOX_ID_2");
                    }
                    if (out_node.GetString("NEXT_LOT_ID") != "")
                        in_node.SetString("NEXT_LOT_ID", out_node.GetString("NEXT_LOT_ID"));
                    else
                        in_node.SetString("NEXT_LOT_ID", "");
                } while (in_node.GetString("NEXT_LOT_ID") != "");
                */



                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[14];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatId.Text;

                dvcArgu[3].sCondition_ID = "CUSTOMER_ID";
                dvcArgu[3].sCondition_Value = cdvCustomerId.Text;

                dvcArgu[4].sCondition_ID = "SHIP_ORDER_ID";
                dvcArgu[4].sCondition_Value = txtShippingOrderNo.Text;
                /*
                dvcArgu[5].sCondition_ID = "FROM_DATE";
                dvcArgu[5].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));

                dvcArgu[6].sCondition_ID = "TO_DATE";
                dvcArgu[6].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";
                */

                dvcArgu[5].sCondition_ID = "FROM_DATE";
                dvcArgu[5].sCondition_Value = FromDt;

                dvcArgu[6].sCondition_ID = "TO_DATE";
                dvcArgu[6].sCondition_Value = ToDt;

                dvcArgu[7].sCondition_ID = "ERP_PACK_ORDER_ID";
                dvcArgu[7].sCondition_Value = txtERPPackingOrderNo.Text;

                dvcArgu[8].sCondition_ID = "DELIVERY_ID";
                dvcArgu[8].sCondition_Value = cdvVendorId.Text;

                dvcArgu[9].sCondition_ID = "MAT_DESC";
                dvcArgu[9].sCondition_Value = txtMatDesc.Text.Trim();

                dvcArgu[10].sCondition_ID = "ORG_LOT_ID";
                dvcArgu[10].sCondition_Value = txtOrgLotId.Text;

                dvcArgu[11].sCondition_ID = "PACK_LOT_ID";
                dvcArgu[11].sCondition_Value = txtPackLotId.Text;

                dvcArgu[12].sCondition_ID = "ERP_PACK_ORDER_LINE";
                dvcArgu[12].sCondition_Value = txtERPPackingOrderLine.Text;


                dvcArgu[13].sCondition_ID = "SHIP_ORDER_LINE";
                dvcArgu[13].sCondition_Value = txtShippingOrderLine.Text;




                if (cdvLotType.Text =="OPER")
                { 
                    if (TPDR.GetDataOne("", ref dt, "CSHP3002-002", dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt != null)
                            dt.Dispose();

                        GC.Collect();

                        MPCF.ClearList(spdShippingLotList);
                        return;
                    }
                }
                else
                {
                    if (TPDR.GetDataOne("", ref dt, "CSHP3002-001", dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt != null)
                            dt.Dispose();

                        GC.Collect();

                        MPCF.ClearList(spdShippingLotList);
                        return;
                    }
                }
                MPCF.ClearList(spdShippingLotList);

                if (iOutPutType == 2)
                {


                    DateTime dFromdateTime = DateTime.ParseExact(FromDt, "yyyyMMddHHmmss", null);
                    DateTime dTodateTime = DateTime.ParseExact(ToDt, "yyyyMMddHHmmss", null);


                    // CSV 파일로 바로 출력
                    //바탕화면 
                    string filePath = Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + "\\ShippingData_" + dSearchTime.ToString("yyyy-MM-dd_HHmmss") + "\\ShippingData_" + dFromdateTime.ToString("yyyy-MM-dd_HHmmss") + "~" + dTodateTime.ToString("yyyy-MM-dd_HHmmss") + ".csv";
                    //APP TEMP
                    //   string filePath = Environment.GetEnvironmentVariable("TEMP") + "\\" + FromDt + "~" + ToDt + "_" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".csv";
                    //C: temp
                    //   string filePath = Environment.GetEnvironmentVariable("windir") + "\\" + FromDt + "~" + ToDt + "_" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".csv";

     
                    FarPoint.Win.Spread.SheetView oSheet = spdShippingLotList.ActiveSheet;

                    clsCusExportFile CsvExport = new clsCusExportFile();


                    if (CsvExport.SaveDataTableToCsv(dt, filePath, oSheet, null))
                    {
                        CsvExport.OpenCsvInExcel(filePath);
                    }


                }
                else
                {

                    for (i = 0; i < dt.Rows.Count; i++)
                    {
                        spdShippingLotList_Sheet1.RowCount++;


                        spdShippingLotList_Sheet1.SetValue(i, (int)SHIPPING_LOT.CHK, false);
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.INSPECTION_LOT_ID].Value = dt.Rows[i]["INSPECTION_LOT_ID"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];


                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.UT_MIN].Value = dt.Rows[i]["UT_MIN"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.UT_MAX].Value = dt.Rows[i]["UT_MAX"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.UT_DEV].Value = dt.Rows[i]["UT_DEV"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.FLATENSS].Value = dt.Rows[i]["FLATENSS"];


                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.OPERATION_MAT_ID].Value = dt.Rows[i]["OPERATION_MAT_ID"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.OPERATION_MAT_DESC].Value = dt.Rows[i]["OPERATION_MAT_DESC"];

                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.QTY].Value = dt.Rows[i]["QTY"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.CONV_UNIT_QTY].Value = dt.Rows[i]["CONV_UNIT_QTY"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.CONV_STOCK_QTY].Value = dt.Rows[i]["CONV_QTY"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.CONV_UNIT].Value = dt.Rows[i]["CONV_UNIT"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.CUSTOMER_ID].Value = dt.Rows[i]["CUSTOMER_ID"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.CUSTOMER_NAME].Value = dt.Rows[i]["CUSTOMER_NAME"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.DELIVERY_ID].Value = dt.Rows[i]["DELIVERY_ID"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.DELIVERY_NAME].Value = dt.Rows[i]["DELIVERY_NAME"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_FLAG].Value = dt.Rows[i]["PACK_FLAG"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.IN_WH_DATE].Value = dt.Rows[i]["IN_WH_DATE"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_DATE].Value = dt.Rows[i]["PACK_DATE"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_LINE_NO].Value = dt.Rows[i]["PACK_LINE_NO"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_ORD_DATE].Value = dt.Rows[i]["PACK_ORD_DATE"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.ERP_PACK_ORDER_ID].Value = dt.Rows[i]["ERP_PACK_ORDER_ID"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.SHIP_FLAG].Value = dt.Rows[i]["SHIP_FLAG"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.SHIP_DATE].Value = dt.Rows[i]["SHIP_DATE"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.SHIP_ORDER_ID].Value = dt.Rows[i]["SHIP_ORDER_ID"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.SHIP_ORDER_SEQ].Value = dt.Rows[i]["SHIP_ORDER_SEQ"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.BOX_ID_1].Value = dt.Rows[i]["BOX_ID_1"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.BOX_ID_2].Value = dt.Rows[i]["BOX_ID_2"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACKING_INSTRUCTIONS].Value = dt.Rows[i]["PACKING_INSTRUCTIONS"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.USER_ID].Value = dt.Rows[i]["USER_Id"];
                        spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.USER_NAME].Value = dt.Rows[i]["USER_NAME"];

                    }
                }


                if (cdvDept.Text == CSGC.CP_AREA_CTM)
                {
                    spdShippingLotList_Sheet1.Columns[(int)SHIPPING_LOT.UT_MIN].Visible = true;
                    spdShippingLotList_Sheet1.Columns[(int)SHIPPING_LOT.UT_MAX].Visible = true;
                    spdShippingLotList_Sheet1.Columns[(int)SHIPPING_LOT.UT_DEV].Visible = true;
                    spdShippingLotList_Sheet1.Columns[(int)SHIPPING_LOT.FLATENSS].Visible = true;
                }
                else
                {
                    spdShippingLotList_Sheet1.Columns[(int)SHIPPING_LOT.UT_MIN].Visible = false;
                    spdShippingLotList_Sheet1.Columns[(int)SHIPPING_LOT.UT_MAX].Visible = false;
                    spdShippingLotList_Sheet1.Columns[(int)SHIPPING_LOT.UT_DEV].Visible = false;
                    spdShippingLotList_Sheet1.Columns[(int)SHIPPING_LOT.FLATENSS].Visible = false;
                }

                //MPCF.FitColumnHeader(spdShippingLotList);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        /// <summary>
        /// HM성적서정보의 ATTRIBUTE02 값(성적서 타입) 조회
        /// 2025-10-23(BOK)
        /// </summary>
        private void ViewHMReport(string sPackLot)
        {
            TRSNode in_node = new TRSNode("VIEW_SHIPPING_LOT_IN ");
            TRSNode out_node = new TRSNode("VIEW_SHIPPING_LOT_OUT");

            try
            {

                

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                DateTime dSearchTime = DateTime.Now;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;
                

                dvcArgu[1].sCondition_ID = "PACK_LOT_ID";
                dvcArgu[1].sCondition_Value = sPackLot;   

                if (TPDR.GetDataOne("", ref dt, "CSHP3002-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdShippingLotList);
                    return;
                }
                
                MPCF.ClearList(spdShippingLotList);



                if (dt.Rows.Count > 1)
                {
                    //
                }


                return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        #endregion

        #region " Event Definition"
        private void frmViewShippingLot_Load(object sender, EventArgs e)
        {
            try
            {
                //20230724 주문지시에서 팝업으로 조회되도록 수정
                if (g_Popup_yn == "Y")
                {
                    cdvDept.Text = g_Dept;
                    txtERPPackingOrderNo.Text = g_ERPPackingOrderNo;
                    txtERPPackingOrderLine.Text = g_ERPPackingOrderLine;

                    dtpFromWorkDate.Value = new System.DateTime(2004, 12, 02, 0, 0, 0, 0);
                    dtpToWorkDate.Value = DateTime.Now;

                    ViewShipLotCount('1');
                    //ViewShipLot();
                }
                else
                {
                    chkMeshDeleteFlag.Checked = false;
                    dtpToWorkDate.Value = DateTime.Now;
                    dtpFromWorkDate.Value = DateTime.Now.AddDays(-7);
                    //   dtpFromWorkDate.Format = DateTimePickerFormat.Custom;
                    //    dtpFromWorkDate.CustomFormat = " ";
                }






            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
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

        private void cdvVendorId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopVendorList popup = new frmPopVendorList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvVendorId.Text = popup.g_VendorId;
                    this.cdvVendorId.DisplayText = popup.g_VendorDesc;
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
                cdvMatId.Text = "";
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

                ViewShipLotCount('1');
                //ViewShipLot();
            }
            catch(Exception ex)
            { 
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvCustomerId_ButtonPress(object sender, EventArgs e)
        {
            //고객사 팝업으로 변경
            try
            {
                frmPopCustomerList popup = new frmPopCustomerList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvCustomerId.Text = popup.g_CustomerId;
                    this.cdvCustomerId.DisplayText = popup.g_CustomerDesc;
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

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdShippingLotList, "ShippingLot");  //spread 객체, 기본 파일명
              
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvLabelSize_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvLabelSize.Init();
                MPCF.InitListView(cdvLabelSize.GetListView);
                cdvLabelSize.Columns.Add("Size", 50, HorizontalAlignment.Left);
                cdvLabelSize.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvLabelSize.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvLabelSize.SelectedSubItemIndex = 2;
                cdvLabelSize.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewLabelGCMList(cdvLabelSize.GetListView, cdvDept.Text, CSGC.CP_LABEL_TYPE_SHIP) == false)
                {
                    return;
                }

                cdvLabelSize.InsertEmptyRow(0, 1);
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
                if (MPCF.Trim(cdvLabelSize.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLableSize.Text + "]");
                    cdvLabelSize.Focus();
                    return;
                }

                if (MPCF.Trim(cdvLotType.Text) == "OPER")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(" LOT기준을 출하LOT으로 변경하여 조회바랍니다.(Change Lot Type Ship Lot)" + " [" + cdvLotType.Text + "]");
                    cdvLabelSize.Focus();
                    return;
                }

                bool label_flag = false;
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");

                MPCR.SetInMsg(in_node);
                in_node.AddChar("MESH_DELETE_FLAG", chkMeshDeleteFlag.Checked == true ? 'Y' : 'N');

                for (int i = 0; i < spdShippingLotList_Sheet1.RowCount; i++)
                {
                    if (spdShippingLotList.ActiveSheet.Cells[i, (int)SHIPPING_LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        label_list = in_node.AddNode("PACK_LOT_LIST");
                        label_list.AddString("PACK_LOT_ID", spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_LOT_ID].Text);
                        label_list.AddString("ORG_LOT_ID", spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.ORG_LOT_ID].Text);

                        label_flag = true;
                    }
                }

                if (label_flag == true)
                {
                    file_name = cdvLabelSize.Text;

                    if (ViewPrintLabel(file_name, in_node))
                    {

                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdShippingLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (spdShippingLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdShippingLotList, e.Row, e.Column, true, true, false);
                    }
                }
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdShippingLotList, e.Row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatId.DisplayText == "")
                cdvMatId.Text = "";
        }

        private void cdvCustomerId_TextBoxTextChanged(object sender, EventArgs e)
        {

            if (cdvCustomerId.DisplayText == "")
                cdvCustomerId.Text = "";
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

        private void cdvVendorId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvVendorId.DisplayText == "")
                cdvVendorId.Text = "";
        }

        private void cdvLotType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvLotType.Init();
                MPCF.InitListView(cdvLotType.GetListView);
                cdvLotType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvLotType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                //cdvCar.SelectedSubItemIndex = 0;
                //cdvCar.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvLotType.GetListView, '1', "C_LOT_TYPE") == false)
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnHmReport_Click(object sender, EventArgs e)
        {
            try
            {
                // 2025-10-23(BOK)
                // 품질팀 요청사항 HM출하성적서 등록시 성적서 타입중 스펙이 나오는 타입 선택등록시
                // 출하현황에서 출력할때 저장된 스펙타입에 따라 출력 하도록 추가수정
                // 스펙타입 : fnPrintShipReport("CQCM2101-011", "pip520pc");   
                // 일반타입 : fnPrintShipReportHM("CQCM2006-005", "pip520pa");

                // 1. 선택한 포장 PACK_LOT_ID(CPAKLOTSTS) 를 HM 성적서 테이블(CQCMRPTHMM)에서 PACK_LOT_ID 조건으로 ATTRIBUTE02 조회

                // 2. if (result == "HM_03") { fnPrintShipReport("CQCM2101-011", "pip520pc"); }
                //    else { fnPrintShipReportHM("CQCM2006-005", "pip520pa"); }

                if (spdShippingLotList.ActiveSheet.RowCount == 0)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return;
                }
                else
                {

                    for (int i = 0; i < spdShippingLotList_Sheet1.RowCount; i++)
                    {

                        if (spdShippingLotList.ActiveSheet.Cells[i, (int)SHIPPING_LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                        {

                            ViewHMReport(spdShippingLotList_Sheet1.Cells[i, (int)SHIPPING_LOT.PACK_LOT_ID].Value.ToString());
                        }


                    }
                }

                

                //일단 HM만 되도록. 다른데는 제외
                //성적서 바인딩확인
                fnPrintShipReportHM("CQCM2006-005", "pip520pa");
                /*
                if (CheckCondition("PRINT") == false)
                    return;

                if (ViewPrintLabel(cdvLabelSize.Text))
                {
                }
                */
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        #endregion

        private void btnCsvDirect_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewShipLotCount(2);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}
