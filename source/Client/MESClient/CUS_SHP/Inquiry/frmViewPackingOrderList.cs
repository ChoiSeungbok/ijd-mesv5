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
using Miracom.MESCore.Controls;
using System.Diagnostics;
using System.IO;
using xExcel = Microsoft.Office.Interop.Excel;
using Microsoft.Office.Interop.Excel;
//using Microsoft.Office.Interop.Excel;
//using Microsoft.Office.Interop.Excel;

namespace CUS_SHP
{
    public partial class frmViewPackingOrderList : CUS_COM.frmViewForm01
    {
        public frmViewPackingOrderList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "
        private enum PACK_ITEM
        {
            CHK,                    // 1 : CHK
            ITEM,                   // 2 : 항목
            ITEM_DESC               // 3 : 항목명
        }

        private enum PACK_ORDER
        {
            CHK,                   // 1 : CHK
            PACK_ORDER_ID,         // 2 : 포장 지시 번호
            LINE_NO,               // 3 : 포장 라인 번호
            ERP_PACK_ORDER_ID,     // 4 : ERP 포장 지시 번호
            MAT_ID,                // 5 : 제품
            MAT_VER,               // 6 : 버전
            MAT_DESC,              // 7 : 제품명
            PACK_ORD_DATE,         // 8 : 포장지시일자
            QTY,                   // 9 : 포장수량
            REG_QTY,               // 10 : 등록 수량
            PACKED_QTY,            // 11 : 포장된 수량
            REMAIN_QTY,            // 12 : 남은 수량
            STOCK_QTY,             // 13 : 재고 수량
            UNIT,                  // 14 : 단위
            CONV_UNIT_QTY,         // 15 : 제품 단위 수량           
            CONV_STOCK_QTY,        // 16 : 환산 재고 수량           
            CONV_UNIT,             // 17 : 환산 단위
            PACK_ORD_STATUS,       // 18 : 포장상태
            CUSTOMER_ID,           // 19 : 고객사
            CUSTOMER_SITE_ID,      // 20 : 고객사 SITE ID
            CUSTOMER_NAME,         // 21 : 고객사명
            DELIVERY_ID,           // 22 : 납품처 ID
            DELIVERY_NAME,         // 23 : 최종 납품처명
            PACKING_INSTRUCTIONS,  // 24 : 용기
            CTM_STOCK_QTY,         // 25 : CTM CW-RUD-QC 창고 재고
            OPER,                  // 26 : 창고
            OPER_DESC,             // 27 : 창고명
            DRAWING_FLAG,          // 28 : 도면유무
            ORDER_TYPE,            // 29 : 주문유형
            REQUEST_DATE,          // 30 : 출하요청일 
            SCHEDULE_SHIP_DATE,    // 31 : 예상납기일
            BARE_INPUT_DATE,       // 32 : 베어인계일
            EXPECT_SHIP_DATE,      // 33 : 출하예정일
            PO_GUBUN,              // 34: 발주구분
            LABEL_TYPE,            // 35 : 라벨 유형
            LABEL_MESH,            // 36 : 라벨 사이즈 
            LABEL_NAME,            // 37 : 라벨품명
            INCLUDE_INSPECTION,    // 38 : 검사 성적서 포함 여부
            PACK_COMMENT,          // 39 : 비고
            TREE_MONTH,            // 40 : 3개월평균(스펠링틀린건......^^;)
            SIX_MONTH,             // 41 : 비고
            PART_NO,               // 42 : PART_NO(PDC 전용)
            DRAW_NO,               // 43 : DRAW_NO(PDC 전용)
            DOC_NO,                // 44 : DOC_NO(PDC 전용)
            DOC_LINE_NO,            // 45 : DOC_LINE_NO(PDC 전용)
            SHIPPED_HISTROY,            // 46 : 출하이력
            SHIPPED_HISTROY_BTN           // 47 : 출하이력버튼
        }

        #endregion

        #region " Variable Definition "
        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;

                lblExShop.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblExShopInput.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblExShopNoInput.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblExShopNow.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblExShopOver.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblExShDate.Anchor = AnchorStyles.Top | AnchorStyles.Right;

                dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");

                if (MPCF.GetRegSetting(System.Windows.Forms.Application.ProductName, this.Name, "CUSTOMER_LAYOUT_YN") == "Y")
                {
                    chkLayout.Checked = true;
                }
                else
                {
                    chkLayout.Checked = false;
                }

                SetSheetConvertColumn("N");
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
        private void SetSheetConvertColumn(string flag)
        {
            if (flag == "Y")
            {
                spdOrderList_Sheet1.Columns[(int)PACK_ORDER.CONV_STOCK_QTY].Visible = true;
                spdOrderList_Sheet1.Columns[(int)PACK_ORDER.CONV_UNIT].Visible = true;
                spdOrderList_Sheet1.Columns[(int)PACK_ORDER.CONV_UNIT_QTY].Visible = true;
                spdOrderList_Sheet1.Columns[(int)PACK_ORDER.LABEL_TYPE].Visible = false;
            }
            else
            {
                spdOrderList_Sheet1.Columns[(int)PACK_ORDER.CONV_STOCK_QTY].Visible = false;
                spdOrderList_Sheet1.Columns[(int)PACK_ORDER.CONV_UNIT].Visible = false;
                spdOrderList_Sheet1.Columns[(int)PACK_ORDER.CONV_UNIT_QTY].Visible = false;
                spdOrderList_Sheet1.Columns[(int)PACK_ORDER.LABEL_TYPE].Visible = true;
            }
        }
        // 주문 지시 정보 조회
        private void ViewOrderList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[17];
                System.Data.DataTable dt = null;
                string sSql = "";
                string sViewID = "";
                List<string> ItemList1 = new List<string>();
                List<string> ItemList2 = new List<string>();

                string sMatDesc = "";
                string sMatDesc2 = "";
                string sSqlText = "";
                string sExcludeWord = "";
                StringBuilder sb = new StringBuilder();

                string sGradeList_1 = "";
                string sGradeList_2 = "";
                string sGradeList_3 = "";
                string sGradeList_4 = "";
                // string sheaders[];
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatId.Text;

                dvcArgu[3].sCondition_ID = "CUSTOMER_ID";
                dvcArgu[3].sCondition_Value = cdvCustomerId.Text;

                dvcArgu[4].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[4].sCondition_Value = txtPackingOrderNo.Text;

                dvcArgu[5].sCondition_ID = "PACK_ORD_STATUS";
                dvcArgu[5].sCondition_Value = cdvOrderStatus.Text;

                dvcArgu[6].sCondition_ID = "FROM_DATE";
                dvcArgu[6].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));

                dvcArgu[7].sCondition_ID = "TO_DATE";
                dvcArgu[7].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";



                GetItemList(out ItemList1, out ItemList2);


                /*
                if (ItemList1.Count + ItemList2.Count == 0)
                {
                    sViewID = "CSHP3004-001";
                    dvcArgu[8].sCondition_ID = "ITEM_LIST1";
                    dvcArgu[8].sCondition_Value = "";

                    dvcArgu[9].sCondition_ID = "ITEM_LIST2";
                    dvcArgu[9].sCondition_Value = "";
                }
                else
                {
                    if (cdvDept.Text == "PDC" && cdvDept.Text == "PDV")
                    {
                        // sViewID = "CSHP3004-004";
                    }
                    else
                    {
                        sViewID = "CSHP3004-002";
                    }
                    dvcArgu[8].sCondition_ID = "ITEM_LIST1";
                    dvcArgu[8].sCondition_Value = string.Format("/{0}/", string.Join("/", ItemList1));

                    dvcArgu[9].sCondition_ID = "ITEM_LIST2";
                    dvcArgu[9].sCondition_Value = string.Format("/{0}/", string.Join("/", ItemList2));
                }
                */


                //20250415 이재일과장 요청 과거일자의 미출하 현황을 보고싶다고 요청함.(CSHP3004-007 추가)
                if (dtpDate.Text == DateTime.Now.ToString("yyyy-MM-dd"))
                {
                    sViewID = "CSHP3004-006";


                }
                else
                {

                    MPCF.ShowMsgBox(dtpDate.Text + " 일 과거시점의 현황조회 \n (" + dtpDate.Text + " Past Status Inquiry)");
                    sViewID = "CSHP3004-007";
                }

                dvcArgu[8].sCondition_ID = "ITEM_LIST1";
                dvcArgu[8].sCondition_Value = "";

                dvcArgu[9].sCondition_ID = "ITEM_LIST2";
                dvcArgu[9].sCondition_Value = "";



                dvcArgu[10].sCondition_ID = "MAT_DESC";
                dvcArgu[10].sCondition_Value = txtMatDesc.Text;

                //제품명 & 제품코드
                sMatDesc = txtMatDesc.Text;
                sMatDesc2 = txtMatDesc2.Text;   


                if (sMatDesc != "" || sMatDesc2 != "")
                {
                    sb.Append(" AND (");

                    if (!string.IsNullOrEmpty(sMatDesc))
                    {
                        sb.Append($"(MAT.MAT_DESC LIKE '%' || '{sMatDesc}' || '%')");
                    }

                    if (!string.IsNullOrEmpty(sMatDesc2))
                    {
                        if (sb.Length > 6) // 첫 번째 조건이 추가된 경우
                        {
                            sb.Append(" OR ");
                        }
                        sb.Append($"(MAT.MAT_DESC LIKE '%' || '{sMatDesc2}' || '%')");
                    }
                    sb.Append(")");

                    sSqlText = sSqlText + sb.ToString();       // 결과 문자열 
                }

                // 제외문자
                sExcludeWord = MPCF.Trim(txtExcludeWord.Text);
                string[] split_data = sExcludeWord.Split(new string[] { string.Format("{0}", "%") }, StringSplitOptions.RemoveEmptyEntries);
                for (int k = 0; k < split_data.Count(); k++)
                {
                    sSqlText = sSqlText + " AND MAT.MAT_DESC NOT LIKE '%' || '" + split_data[k] + "' || '%'";
                }

                dvcArgu[10].sCondition_ID = "SQL_TEXT2";
                dvcArgu[10].sCondition_Type = "TEXT";
                if (sSqlText == "")
                {
                    dvcArgu[10].sCondition_Value = "AND 1=1";
                }
                else
                {
                    dvcArgu[10].sCondition_Value = sSqlText;
                }　


                dvcArgu[11].sCondition_ID = "ERP_PACK_ORDER_ID";
                dvcArgu[11].sCondition_Value = txtERPPackingOrderNo.Text;

                dvcArgu[12].sCondition_ID = "NEGATIVE_FLAG";
                dvcArgu[12].sCondition_Value = chkNegativeQty.Checked == true ? 'Y' : 'N';　


                //211123 품목조회 클라이언트에서 쿼리 만들어서 보내는걸로 변경.(UNION aLL 더 추가할수 없어서쿼리가 길어져서)
                //211124 베트남 PDV 추가

                sSqlText = "";

                SheetView sv = spdItemList_Sheet1;

                for (int iRow = 0; iRow < sv.RowCount; iRow++)
                {
                    if (sv.Cells[iRow, (int)PACK_ITEM.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        switch (cdvDept.Text)
                        {
                            case "CTM":
                            case "CTV":
                                switch (sv.Cells[iRow, (int)PACK_ITEM.ITEM].Value.ToString().Length)
                                {

                                    case 2:
                                        sGradeList_1 = sGradeList_1 + ",'" + sv.Cells[iRow, (int)PACK_ITEM.ITEM].Value.ToString() + "'";
                                        break;
                                    case 4:
                                        sGradeList_2 = sGradeList_2 + ",'" + sv.Cells[iRow, (int)PACK_ITEM.ITEM].Value.ToString() + "'";
                                        break;
                                    case 5:
                                        sGradeList_3 = sGradeList_3 + ",'" + sv.Cells[iRow, (int)PACK_ITEM.ITEM].Value.ToString() + "'";
                                        break;
                                    case 7:
                                        sGradeList_4 = sGradeList_4 + ",'" + sv.Cells[iRow, (int)PACK_ITEM.ITEM].Value.ToString() + "'";
                                        break;


                                }
                                break;
                            case "GRT":
                                sGradeList_1 = sGradeList_1 + ",'" + sv.Cells[iRow, (int)PACK_ITEM.ITEM].Value.ToString() + "'";
                                break;
                            case "HM":
                                sGradeList_1 = sGradeList_1 + ",'" + sv.Cells[iRow, (int)PACK_ITEM.ITEM].Value.ToString() + "'";
                                break;
                            case "PDC":
                                sGradeList_1 = sGradeList_1 + ",'" + sv.Cells[iRow, (int)PACK_ITEM.ITEM].Value.ToString() + "'";
                                break;
                        }

                    }
                }

                // 최성수대리 요청건(내부거래 미표시 요청건)
                if (chkInsiderTrading.Checked == false)
                {
                    //납품처ID(50101), 납품처명(내부거래) 
                    sSqlText = sSqlText + " AND ORD.DELIVERY_ID NOT IN('50101') ";
                }


                switch (cdvDept.Text)
                {
                    case "CTM":
                    case "CTV":
                        if (sGradeList_1 != "" || sGradeList_2 != "" || sGradeList_3 != "" || sGradeList_4 != "")
                        {
                            if (sGradeList_1 == "")
                            {
                                sSqlText = " AND (1=2 ";
                            }
                            else
                            {
                                sSqlText = sSqlText + " AND (SUBSTR(ORD.MAT_ID,2,2) IN(''" + sGradeList_1 + ") ";
                            }


                            if (sGradeList_2 == "")
                            {
                                //sSqlText = " ";
                            }
                            else
                            {
                                sSqlText = sSqlText + " OR  SUBSTR(ORD.MAT_ID,2,4) IN(''" + sGradeList_2 + ") ";
                            }


                            if (sGradeList_3 == "")
                            {
                                // sSqlText = " ";
                            }
                            else
                            {
                                sSqlText = sSqlText + " OR  SUBSTR(ORD.MAT_ID,1,5) IN(''" + sGradeList_3 + ") ";
                            }


                            if (sGradeList_4 == "")
                            {
                                sSqlText = sSqlText + ") ";
                            }
                            else
                            {
                                sSqlText = sSqlText + " OR  SUBSTR(ORD.MAT_ID,1,7) IN(''" + sGradeList_4 + ") )";
                            }

                        }



                        break;

                    case "GRT":
                        if (sGradeList_1 == "")
                        {
                            sSqlText = sSqlText + " AND 1=1";
                        }
                        else
                        {
                            sSqlText = sSqlText + " AND  SUBSTR(ORD.MAT_ID,4,2) IN(''" + sGradeList_1 + ")";
                        }
                        break;
                    case "HM":
                        if (sGradeList_1 == "")
                        {
                            sSqlText = sSqlText + " AND 1=1";
                        }
                        else
                        {
                            sSqlText = sSqlText + " AND  SUBSTR(ORD.MAT_ID,2,4) IN(''" + sGradeList_1 + ")";
                        }
                        break;
                    case "PDC":
                        if (sGradeList_1 == "")
                        {
                            sSqlText = sSqlText + " AND 1=1";
                        }
                        else
                        {
                            sSqlText = sSqlText + " AND (CASE WHEN SUBSTR(ORD.MAT_ID,1,7) IN('AE90000','EE90000') THEN 'XXXXXX' ELSE SUBSTR(ORD.MAT_ID,1,7) END )  IN(''" + sGradeList_1 + ")";
                        }
                        break;

                }

                dvcArgu[13].sCondition_ID = "SQL_TEXT";
                dvcArgu[13].sCondition_Type = "TEXT";


                if (sSqlText == "")
                {
                    dvcArgu[13].sCondition_Value = "AND 1=1";
                }
                else
                {
                    dvcArgu[13].sCondition_Value = sSqlText;
                }


                dvcArgu[14].sCondition_ID = "CUSTOMER_NAME";
                dvcArgu[14].sCondition_Value = txtCustomerName.Text;


                dvcArgu[15].sCondition_ID = "DELIVERY_NAME";
                dvcArgu[15].sCondition_Value = txtDeliveryName.Text;


                dvcArgu[16].sCondition_ID = "EOH_DATE";
                dvcArgu[16].sCondition_Value = dtpDate.Text.Replace("-", "");



                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdOrderList);
                    return;
                }

                InitializeComponent2();


                MPCF.ClearList(spdOrderList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdOrderList_Sheet1.RowCount++;

                    if (chkLayout.Checked == false)
                    {
                        if (i == 0) SetSheetConvertColumn(dt.Rows[i]["CONV_FLAG"].ToString());
                    }


                    spdOrderList_Sheet1.SetValue(i, (int)PACK_ORDER.CHK, false);
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LINE_NO].Value = dt.Rows[i]["LINE_NO"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.ERP_PACK_ORDER_ID].Value = dt.Rows[i]["CMF_1"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORD_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PACK_ORD_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.QTY].Value = dt.Rows[i]["QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.REG_QTY].Value = dt.Rows[i]["REG_QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACKED_QTY].Value = dt.Rows[i]["PACKED_QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.REMAIN_QTY].Value = dt.Rows[i]["REMAIN_QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.STOCK_QTY].Value = dt.Rows[i]["STOCK_QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CONV_UNIT_QTY].Value = dt.Rows[i]["CONV_UNIT_QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CONV_STOCK_QTY].Value = dt.Rows[i]["CONV_STOCK_QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CONV_UNIT].Value = dt.Rows[i]["CONV_UNIT"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORD_STATUS].Value = dt.Rows[i]["PACK_ORD_STATUS"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CUSTOMER_ID].Value = dt.Rows[i]["CUSTOMER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CUSTOMER_SITE_ID].Value = dt.Rows[i]["CUSTOMER_SITE_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CUSTOMER_NAME].Value = dt.Rows[i]["CUSTOMER_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DELIVERY_ID].Value = dt.Rows[i]["DELIVERY_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DELIVERY_NAME].Value = dt.Rows[i]["DELIVERY_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACKING_INSTRUCTIONS].Value = dt.Rows[i]["PACKING_INSTRUCTIONS"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CTM_STOCK_QTY].Value = dt.Rows[i]["CTM_STOCK_QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.OPER].Value = dt.Rows[i]["OPER"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DRAWING_FLAG].Value = dt.Rows[i]["DRAWING_FLAG"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.ORDER_TYPE].Value = dt.Rows[i]["ORDER_TYPE"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.REQUEST_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["REQUEST_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.SCHEDULE_SHIP_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["SCHEDULE_SHIP_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.BARE_INPUT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CMF_2"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["EXPECT_SHIP_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PO_GUBUN].Value = dt.Rows[i]["PO_GUBUN"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LABEL_TYPE].Value = dt.Rows[i]["LABEL_TYPE"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LABEL_MESH].Value = dt.Rows[i]["LABEL_MESH"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.INCLUDE_INSPECTION].Value = dt.Rows[i]["INCLUDE_INSPECTION"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_COMMENT].Value = dt.Rows[i]["PACK_COMMENT"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.TREE_MONTH].Value = dt.Rows[i]["TREE_MONTH"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.SIX_MONTH].Value = dt.Rows[i]["SIX_MONTH"];

                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PART_NO].Value = dt.Rows[i]["PART_NO"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DRAW_NO].Value = dt.Rows[i]["DRAW_NO"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DOC_NO].Value = dt.Rows[i]["DOC_NO"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DOC_LINE_NO].Value = dt.Rows[i]["DOC_LINE_NO"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.SHIPPED_HISTROY].Text = dt.Rows[i]["SHIPPED_HISTROY"].ToString();


                    if (spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORD_STATUS].Text.Trim().ToUpper() == "WAIT")
                    {
                        spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Locked = false;
                    }
                    else
                    {
                        spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Locked = true;
                    };



                    if (spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Text.Trim() == "")  //
                    {
                        spdOrderList.ActiveSheet.Rows[i].ForeColor = Color.Red;
                    }
                    else if (spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Text.Replace("-", "") == DateTime.Now.ToString("yyyyMMdd")) //출하예정일이 현재일이면 파란색
                    {
                        spdOrderList_Sheet1.Rows.Get(i).ForeColor = Color.Blue; //System.Drawing.Color.FromArgb(((int)(((byte)(1)))), ((int)(((byte)(0)))), ((int)(((byte)(255)))));
                    }
                    else if (Convert.ToInt32(spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Text.Replace("-", "")) < Convert.ToInt32(DateTime.Now.ToString("yyyyMMdd"))) //출하예정일이 지났으면 녹색
                    {
                        spdOrderList_Sheet1.Rows.Get(i).ForeColor = Color.Green; //System.Drawing.Color.FromArgb(((int)(((byte)(29)))), ((int)(((byte)(219)))), ((int)(((byte)(22)))));
                    }
                    else
                    {

                    }



                };

                // MES 오픈이 아직 6개월이 안되어 6월이전까지는 6개월 평균일단 안보이도록 히든.....나중에는 수정할일 있을때 해당 부분 제거...(송용원)
                DateTime dHiddenDate = Convert.ToDateTime("2021-06-01");

                if (DateTime.Compare(dHiddenDate, DateTime.Now) > 0)
                {
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.SIX_MONTH).Visible = false;
                }
                else
                {
                }


                if (cdvDept.Text == "GRT") //베어 인계일은 GRT만 보이도록
                {
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.BARE_INPUT_DATE).Locked = false;
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.BARE_INPUT_DATE).Visible = true;
                }
                else
                {
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.BARE_INPUT_DATE).Locked = true;
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.BARE_INPUT_DATE).Visible = false;
                };


                if (cdvDept.Text == "PDC") //PDC만 보이도록
                {
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.PART_NO).Locked = false;
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DRAW_NO).Locked = false;
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DOC_NO).Locked = false;
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DOC_LINE_NO).Locked = false;

                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.PART_NO).Visible = true;
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DRAW_NO).Visible = true;
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DOC_NO).Visible = true;
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DOC_LINE_NO).Visible = true;
                }
                else
                {
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.PART_NO).Locked = true;
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DRAW_NO).Locked = true;
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DOC_NO).Locked = true;
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DOC_LINE_NO).Locked = true;

                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.PART_NO).Visible = false;
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DRAW_NO).Visible = false;
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DOC_NO).Visible = false;
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.DOC_LINE_NO).Visible = false;
                };


                SetSheetColor();

                MPCF.FitColumnHeader(spdOrderList);
                spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.SHIPPED_HISTROY).Width = 800;

                for (int iCol = 0; iCol < spdOrderList_Sheet1.ColumnCount; iCol++)
                {
                    spdOrderList_Sheet1.Columns.Get(iCol).Tag = spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, iCol).Text;
                }



                if (chkLayout.Checked == true)
                {

                    layoutchange(out string[] sheaders);



                    // for (int iHeader = 0; iHeader < sheaders.GetLength(0); iHeader++)


                    spdOrderList_Sheet1.AddColumns(1, sheaders.GetLength(0));


                    for (int iCol = 1; iCol < spdOrderList_Sheet1.ColumnCount; iCol++)
                    {
                        spdOrderList_Sheet1.Columns[iCol].Visible = false;
                    }


                    for (int iHeader = sheaders.GetLength(0) - 1; iHeader > -1; iHeader--)
                    {
                        for (int iCol = 1; iCol < spdOrderList_Sheet1.ColumnCount; iCol++)
                        {

                            if (spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, iCol).Text != "" && spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, iCol).Text == sheaders[iHeader].ToString())
                            {



                                spdOrderList_Sheet1.Columns[iCol].Visible = true;
                                spdOrderList_Sheet1.MoveColumn(iCol, 1, 1, true);


                                //   string sHeaderName = MPCF.FindLanguage(spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, iCol).Text, 0);
                                //   spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, iCol).Value = sHeaderName;
                            }
                        }

                    }




                    //   spdOrderList_Sheet1.Columns[0].Visible = true;
                    //   spdOrderList_Sheet1.Columns[1].Visible = true;
                    spdOrderList_Sheet1.RemoveColumns(sheaders.GetLength(0), spdOrderList_Sheet1.ColumnCount - sheaders.GetLength(0));
                    MPCF.SaveRegSetting(System.Windows.Forms.Application.ProductName, this.Name, "CUSTOMER_LAYOUT_YN", "Y");

                }
                else
                {
                    MPCF.SaveRegSetting(System.Windows.Forms.Application.ProductName, this.Name, "CUSTOMER_LAYOUT_YN", "N");
                }
                 
                for (int iCol = 0; iCol < spdOrderList_Sheet1.ColumnCount; iCol++)
                {

                    // spdOrderList_Sheet1.Columns.Get(iCol).Tag = spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, iCol).Text;
                    string sHeaderName = MPCF.FindLanguage(spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, iCol).Text, 0);
                    spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, iCol).Value = sHeaderName;


                }


                /*
                else
                {
                    for (int iCol = 0; iCol < spdOrderList_Sheet1.ColumnCount; iCol++)
                    {

                        spdOrderList_Sheet1.Columns.Get(iCol).Tag = spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, iCol).Text;
                        string sHeaderName = MPCF.FindLanguage(spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, iCol).Text, 0);
                        spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, iCol).Value = sHeaderName;


                    }
                }
                */


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void sheetHidden(string sSheachType)
        {

            if (chkLayout.Checked == true)
            {
                return;
            }

            try
            {

                for (int i = 0; i < spdOrderList_Sheet1.RowCount; i++)
                {

                    spdOrderList_Sheet1.Rows.Get(i).Visible = true;

                    switch (sSheachType)
                    {
                        case "ALL":
                            //spdOrderList_Sheet1.Rows.Get(i).Visible = true;

                            break;

                        case "RED":
                            if (spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Text.Trim() != "")  //
                            {
                                spdOrderList_Sheet1.Rows.Get(i).Visible = false;
                            }
                            break;
                        case "BLUE":
                            if (spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Text.Replace("-", "") != DateTime.Now.ToString("yyyyMMdd"))
                            {
                                spdOrderList_Sheet1.Rows.Get(i).Visible = false;
                            }
                            break;
                        case "GREEN":

                            if (spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Text.Trim() == "")
                            {
                                spdOrderList_Sheet1.Rows.Get(i).Visible = false;
                            }
                            else
                            {
                                if (Convert.ToInt32(spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Text.Replace("-", "")) >= Convert.ToInt32(DateTime.Now.ToString("yyyyMMdd")))
                                {
                                    spdOrderList_Sheet1.Rows.Get(i).Visible = false;
                                }

                            }
                            break;
                        case "BLACK":
                            if (spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Text.Trim() == "")
                            {
                                spdOrderList_Sheet1.Rows.Get(i).Visible = false;
                            }
                            else
                            {
                                if (Convert.ToInt32(spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Text.Replace("-", "")) <= Convert.ToInt32(DateTime.Now.ToString("yyyyMMdd")))
                                {
                                    spdOrderList_Sheet1.Rows.Get(i).Visible = false;
                                }

                            }
                            break;

                    }


                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
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

                        MPCF.ClearList(spdOrderList);
                        break;

                    case "ALL":

                        MPCF.ClearList(spdOrderList);
                        MPCF.ClearList(spdItemList);
                        this.dtpToWorkDate.Value = DateTime.Now;

                        cdvOrderStatus.Text = CSGC.CP_PACK_STATUS_WAIT;
                        cdvOrderStatus.DisplayText = CSGC.CP_PACK_STATUS_WAIT_DESC;
                        dtpToWorkDate.Value = DateTime.Now;
                        dtpFromWorkDate.Value = DateTime.Now;
                        dtpFromWorkDate.Format = DateTimePickerFormat.Custom;
                        dtpFromWorkDate.CustomFormat = " ";

                        this.cdvDept.Text = "";
                        this.cdvMatId.Text = "";
                        this.cdvCustomerId.Text = "";
                        this.txtPackingOrderNo.Text = "";
                        this.txtMatDesc.Text = "";
                        this.chkNegativeQty.Checked = false;
                        this.chkInsiderTrading.Checked = false;
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // item 정보 조회
        private void ViewItemList(string sDept)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                System.Data.DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sDept;

                if (TPDR.GetDataOne("", ref dt, "CSHP3004-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdItemList);
                    return;
                }

                MPCF.ClearList(spdItemList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdItemList_Sheet1.RowCount++;

                    spdItemList_Sheet1.SetValue(i, (int)PACK_ITEM.CHK, false);
                    spdItemList_Sheet1.Cells[i, (int)PACK_ITEM.ITEM].Value = dt.Rows[i]["ITEM"];
                    spdItemList_Sheet1.Cells[i, (int)PACK_ITEM.ITEM_DESC].Value = dt.Rows[i]["ITEM_DESC"];
                }
                MPCF.FitColumnHeader(spdItemList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void GetItemList(out List<string> chkItemList1, out List<string> chkItemList2)
        {
            chkItemList1 = new List<string>();
            chkItemList2 = new List<string>();

            SheetView sv = spdItemList_Sheet1;
            try
            {
                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)PACK_ITEM.CHK] == null ? false : sv.Cells[i, (int)PACK_ITEM.CHK].Value))
                    {
                        if (cdvDept.Text == "CTM" && sv.Cells[i, (int)PACK_ITEM.ITEM].Value.ToString().Length == 2)
                            chkItemList2.Add(sv.Cells[i, (int)PACK_ITEM.ITEM].Value.ToString());
                        else if (cdvDept.Text == "PDC" && sv.Cells[i, (int)PACK_ITEM.ITEM].Value.ToString() == "XXXXX")
                            chkItemList2.Add(sv.Cells[i, (int)PACK_ITEM.ITEM].Value.ToString());
                        else
                            chkItemList1.Add(sv.Cells[i, (int)PACK_ITEM.ITEM].Value.ToString());
                    }
                    else
                    {
                        if (cdvDept.Text == "CTM" && sv.Cells[i, (int)PACK_ITEM.ITEM].Value.ToString().Length == 2)
                            chkItemList2.Remove(sv.Cells[i, (int)PACK_ITEM.ITEM].Value.ToString());
                        else if (cdvDept.Text == "PDC" && sv.Cells[i, (int)PACK_ITEM.ITEM].Value.ToString() == "XXXXX")
                            chkItemList2.Remove(sv.Cells[i, (int)PACK_ITEM.ITEM].Value.ToString());
                        else
                            chkItemList1.Remove(sv.Cells[i, (int)PACK_ITEM.ITEM].Value.ToString());
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        private bool SavePackOrder()
        {
            TRSNode in_node = new TRSNode("packing_Lot_In");
            TRSNode out_node = new TRSNode("packing_Lot_Out");
            TRSNode pack_list;
            SheetView sv = spdOrderList_Sheet1;
            bool send_flag = false;
            try
            {
                if (MPCF.GetRegSetting(System.Windows.Forms.Application.ProductName, this.Name, "CUSTOMER_LAYOUT_YN") == "Y")
                {
                    MPCF.ShowMsgBox("User LayOut 으로 조회한 경우 저장이 불가합니다.(Unable to save when Search with (User LayOut)");
                }




                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (sv.Cells[i, (int)PACK_ORDER.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (sv.Cells[i, (int)PACK_ORDER.PACK_ORD_STATUS].Text.Trim().ToUpper() == "WAIT")
                        {
                            pack_list = in_node.AddNode("PACK_LIST");
                            pack_list.AddString("PACK_ORDER_ID", sv.Cells[i, (int)PACK_ORDER.PACK_ORDER_ID].Text);
                            pack_list.AddInt("LINE_NO", sv.Cells[i, (int)PACK_ORDER.LINE_NO].Text);
                            pack_list.AddString("EXPECT_SHIP_DATE", sv.Cells[i, (int)PACK_ORDER.EXPECT_SHIP_DATE].Text.Replace("-", ""));
                            pack_list.AddString("CMF_2", sv.Cells[i, (int)PACK_ORDER.BARE_INPUT_DATE].Text.Replace("-", ""));

                            pack_list.AddString("CMF_3", sv.Cells[i, (int)PACK_ORDER.PART_NO].Text);
                            pack_list.AddString("CMF_4", sv.Cells[i, (int)PACK_ORDER.DRAW_NO].Text);
                            pack_list.AddString("CMF_5", sv.Cells[i, (int)PACK_ORDER.DOC_NO].Text);
                            pack_list.AddString("CMF_6", sv.Cells[i, (int)PACK_ORDER.DOC_LINE_NO].Text);

                            pack_list.AddString("PACK_COMMENT", sv.Cells[i, (int)PACK_ORDER.PACK_COMMENT].Text);

                            send_flag = true;
                        }

                    }
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_SHP", "CUS_SHP_Update_Pack_Order", in_node, ref out_node) == false)
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void SetSheetColor()
        {
            try
            {

                for (int i = 0; i < spdOrderList_Sheet1.RowCount; i++)
                {
                    if (spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.SCHEDULE_SHIP_DATE].Value.ToString().Length <= 1)
                    {
                        spdOrderList_Sheet1.Rows.Get(i).LockBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(192)))));
                    }
                    else
                    {
                        spdOrderList_Sheet1.Rows.Get(i).LockBackColor = System.Drawing.Color.White;
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion

        #region " Event Definition "
        private void frmViewPackingOrderList_Load(object sender, EventArgs e)
        {
            try
            {
                cdvOrderStatus.Text = CSGC.CP_PACK_STATUS_WAIT;
                cdvOrderStatus.DisplayText = CSGC.CP_PACK_STATUS_WAIT_DESC;
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

                MPCF.ClearList(spdOrderList);

                ViewItemList(cdvDept.Text);
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

                ClearList("VIEW");
                ViewOrderList();
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

                //20230221 출력양에 따라 속도가 너무 느림, 그냥 화면에서 데이터 끌고오는것으로 변경함.(속도차이 1분이상 혹은 타임아웃에서-> 1~2초)
                fnPrintReport();
                /*

                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                bool label_flag = false;
                string file_name = "sal450q";

                MPCR.SetInMsg(in_node);

                for (int i = 0; i < spdOrderList_Sheet1.RowCount; i++)
                {
                    if (spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (Convert.ToDouble(spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.REMAIN_QTY].Value) > 0)
                        {
                            label_list = in_node.AddNode("ORDER_LIST");
                            label_list.AddString("PACK_ORDER_ID", spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORDER_ID].Text);
                            label_list.AddInt("LINE_NO", MPCF.ToInt(spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LINE_NO].Text));

                            label_flag = true;
                        }
                        else
                        {
                            spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CHK].Value = false;
                        }
                    }
                }

                if (label_flag == true)
                {
                    CSCF.ViewLabelList(file_name, in_node);
                }
                else
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return;
                }

                */
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void fnPrintReport()
        {
            try
            {
                System.Data.DataTable dt = null;
                DataRow dr;
                //  DataColumn dc;

                ;
                dt = new System.Data.DataTable("DataTable");
                dt.Columns.Add(new DataColumn("SECTION_GBN", typeof(string)));
                dt.Columns.Add(new DataColumn("SECTION_NAME", typeof(string)));
                dt.Columns.Add(new DataColumn("BOOKED_DATE", typeof(string)));
                dt.Columns.Add(new DataColumn("ORDER_NUMBER", typeof(string)));
                dt.Columns.Add(new DataColumn("LINE_NUMBER", typeof(int)));
                dt.Columns.Add(new DataColumn("LABEL_NAME", typeof(string)));
                dt.Columns.Add(new DataColumn("CUSTOMER_NAME", typeof(string)));
                dt.Columns.Add(new DataColumn("DRAWING_FLAG", typeof(string)));
                dt.Columns.Add(new DataColumn("ORDER_TYPE", typeof(string)));
                dt.Columns.Add(new DataColumn("REQUEST_DATE", typeof(string)));
                dt.Columns.Add(new DataColumn("SCHEDULE_SHIP_DATE", typeof(string)));
                dt.Columns.Add(new DataColumn("UNPACKED_QUANTITY", typeof(double)));
                dt.Columns.Add(new DataColumn("UNPACKED_ONHAND_QUANTITY", typeof(double)));
                dt.Columns.Add(new DataColumn("ORDER_DATE", typeof(string)));
                dt.Columns.Add(new DataColumn("ITEM_CODE", typeof(string)));
                dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                dt.Columns.Add(new DataColumn("END_SHIP_TO_NAME", typeof(string)));
                dt.Columns.Add(new DataColumn("PACKING_INSTRUCTIONS", typeof(string)));
                dt.Columns.Add(new DataColumn("FIXED_YN", typeof(string)));
                dt.Columns.Add(new DataColumn("USER_NAME", typeof(string)));
                dt.Columns.Add(new DataColumn("REMAIN_QTY", typeof(double)));






                for (int i = 0; i < spdOrderList_Sheet1.RowCount; i++)
                {
                    if (spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (Convert.ToDouble(spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.REMAIN_QTY].Value) > 0)
                        {

                            dr = dt.NewRow();

                            //  dr[0] = spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.REMAIN_QTY].Text;

                            dr[0] = ""; //"SECTION_GBN", typeof(string)));
                            dr[1] = ""; //"SECTION_NAME", typeof(string)));
                            dr[2] = spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORD_DATE].Text; //"BOOKED_DATE", typeof(string)));
                            dr[3] = spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORDER_ID].Text; //"ORDER_NUMBER", typeof(string)));
                            dr[4] = Convert.ToInt64(spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LINE_NO].Text); //"LINE_NUMBER", typeof(int)));
                            dr[5] = spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LABEL_NAME].Text; //"LABEL_NAME", typeof(string)));
                            dr[6] = spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CUSTOMER_NAME].Text; //"CUSTOMER_NAME", typeof(string)));
                            dr[7] = spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DRAWING_FLAG].Text; //"DRAWING_FLAG", typeof(string)));
                            dr[8] = spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.ORDER_TYPE].Text; //"ORDER_TYPE", typeof(string)));
                            dr[9] = spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.REQUEST_DATE].Text; //"REQUEST_DATE", typeof(string)));
                            dr[10] = spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.SCHEDULE_SHIP_DATE].Text; //"SCHEDULE_SHIP_DATE", typeof(string)));
                            dr[11] = Convert.ToDouble(spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.REMAIN_QTY].Value); //"UNPACKED_QUANTITY", typeof(double)));
                            dr[12] = Convert.ToDouble(spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.STOCK_QTY].Value); //"UNPACKED_ONHAND_QUANTITY", typeof(double)));
                            dr[13] = spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORD_DATE].Text; //"ORDER_DATE", typeof(string)));
                            dr[14] = spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.MAT_ID].Text; //"ITEM_CODE", typeof(string)));
                            dr[15] = spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.MAT_DESC].Text; //"ITEM_NAME", typeof(string)));
                            dr[16] = spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DELIVERY_NAME].Text; //"END_SHIP_TO_NAME", typeof(string)));
                            dr[17] = spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACKING_INSTRUCTIONS].Text; //"PACKING_INSTRUCTIONS", typeof(string)));
                            dr[18] = ""; //"FIXED_YN", typeof(string)));
                            dr[19] = MPGV.gsUserID; //"USER_NAME", typeof(string)));
                            dr[20] = 0; //"REMAIN_QTY", typeof(double)));



                            dt.Rows.Add(dr);


                        }
                        else
                        {
                            spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CHK].Value = false;
                        }
                    }
                }

                DevReport.PreviewXtraReport(dt, "sal450q");

                return;
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
                ClearList("ALL");
            }
            catch (Exception ex)
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
                    this.txtCustomerName.Text = popup.g_CustomerDesc;
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

        public static bool CheckSpreadCellship(FarPoint.Win.Spread.FpSpread spdData, int i_ColHeaderRow, int i_Col, bool b_checked, bool b_isColHeaderCheckBox, bool b_LockRowCheckException = false)
        {
            try
            {
                if (b_isColHeaderCheckBox)
                {
                    if (spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Locked = false;

                        if (spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Value == null ||
                        spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Value.Equals(" ") ||
                        spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Value.Equals(false))
                        {
                            spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Value = true;
                        }
                        else
                        {
                            spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Value = false;//!Convert.ToBoolean(spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Value);
                                                                                                        //   return true; 
                        }

                        for (int i = 0; i < spdData.ActiveSheet.RowCount; i++)
                        {
                            // 잠금 되어있는 스프로드 로우에 대해서 체크 제외 여부
                            if (b_LockRowCheckException == false)
                                spdData.ActiveSheet.Cells[i, i_Col].Value = spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Value;
                            else
                            {
                                if (spdData.ActiveSheet.Rows[i].Locked == false)
                                    spdData.ActiveSheet.Cells[i, i_Col].Value = spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Value;
                            }
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < spdData.ActiveSheet.RowCount; i++)
                    {
                        spdData.ActiveSheet.Cells[i, i_Col].Value = b_checked;
                    }
                }

                return true;
            }
            catch (System.Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void spdOrderList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (spdOrderList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CheckSpreadCellship(spdOrderList, e.Row, e.Column, true, true, false);
                    }
                }
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdOrderList, e.Row);
                }






            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        private void cdvOrderStatus_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOrderStatus.Init();
                MPCF.InitListView(cdvOrderStatus.GetListView);
                cdvOrderStatus.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvOrderStatus.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOrderStatus.SelectedSubItemIndex = 0;
                cdvOrderStatus.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvOrderStatus.GetListView, '1', CSGC.CP_GCM_SHIP_STATUS) == false)
                {
                    return;
                }

                cdvOrderStatus.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdItemList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            SheetView sv = spdItemList.ActiveSheet;

            try
            {
                if (e.ColumnHeader == true)
                {
                    if (sv.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdItemList, e.Row, e.Column, true, true, false);
                    }
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


               // SaveExcel2(spdOrderList, "PackOrderList");

                EXTFUC.SaveExcel(spdOrderList, "PackLotList");


            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private bool SaveExcel2(Control _ctrl, string filename, bool show_flag = true)
        {

            // 정렬로 위치 바뀐정보 정렬 다시하는거 도무지 모르겠음...그래서 바꿈..
            try
            {
                string sFileName = string.Empty;

                FpSpread excelSp = new FpSpread();
                FpSpread spread = _ctrl as FpSpread;
                SheetView sv = new SheetView();

                if (spread == null)
                    return false;

                if (show_flag == false) //파일 저장
                {
                    sFileName = EXTFUC.ShowFileOpenDialog(filename);
                }
                else  //파일 바로 오픈
                {
                    string path = Path.Combine(System.Windows.Forms.Application.StartupPath, "Temp");

                    if (!Directory.Exists(path))
                        Directory.CreateDirectory(path);

                    if (string.IsNullOrEmpty(filename))
                        filename = DateTime.Now.ToString("yyyyMMddHHmmss");
                    else
                        filename = string.Format("{0}_{1}", filename, DateTime.Now.ToString("yyyyMMddHHmmss"));

                    sFileName = Path.Combine(path, filename);
                    // 확장자 붙이기
                    if (!Path.GetExtension(sFileName).Include(".xlsx"))
                    {
                        sFileName = $"{sFileName}.xlsx";
                    }
                }


                for (int i = 0; i < spread.Sheets.Count; i++)
                {
                    sv = spread.Sheets[i];
                    sv.SheetName = string.Format("Sheet{0}", (i + 1));
                    sv.ColumnCount = spread.Sheets[i].ColumnCount;
                    sv.RowCount = spread.Sheets[i].RowCount;
                    sv.Protect = false;



                    excelSp.Sheets.Add(sv);

                }
                // File 명에 / 있으면 Error 발생해서 수정함
                sFileName = sFileName.Replace("/", "-");
                excelSp.SaveExcel(sFileName, FarPoint.Excel.ExcelSaveFlags.SaveCustomColumnHeaders | FarPoint.Excel.ExcelSaveFlags.UseOOXMLFormat);



                for (int i = 0; i < spread.Sheets.Count; i++)
                {
                    sv = spread.Sheets[i];
                    sv.Protect = true;
                }
                if (show_flag)
                {
                    // Process.Start(sFileName);



                    xExcel.Application XApp = null;
                    xExcel.Workbooks XBooks = null; ;
                    xExcel.Workbook XBook = null;
                    xExcel.Worksheet XSheet = null;
                    xExcel.Sheets XSheets = null;

                    XApp = new xExcel.Application();

                    XApp.Visible = true;

                    XBooks = XApp.Workbooks;
                    XBook = XApp.Workbooks.Open(sFileName.Replace("-", "/"));



                    spdOrderList.ActiveSheet.AddSelection(0, 0, spdOrderList.ActiveSheet.RowCount, spdOrderList.ActiveSheet.ColumnCount); ;
                    spdOrderList.ActiveSheet.ClipboardCopy();

                    XSheets = XBook.Worksheets;
                    XSheet = XSheets.get_Item(1) as xExcel.Worksheet;
                    XSheets.get_Item(1).select();

                    Excel.Range CR2 = (Excel.Range)XSheet.Cells[2, 1];

                    CR2.Select();
                    XSheet.Paste();

                    XSheet.Cells.Font.Color = 2;

                    /*
                        for (int iRow = 0; iRow < spdOrderList_Sheet1.RowCount; iRow++)
                        {
                   //     XSheet.get_Range(XSheet.Cells[iRow, iRow], XSheet.Cells[iRow, MPGC.EXCEL_MAX_COL]).Font.Color = -4165632;
                            //spdOrderList_Sheet1.Rows.Get(iRow).ForeColor;



                        }
                    */




                    // XSheet.Cells[1,1000].Font.Color = 1;

                    /*
                    Excel.Range CR3 = (Excel.Range)XSheet.Cells[1, 1];
                    CR3.Select();
                    XSheet.Range[1,1000].Activate();
                    XSheet.Cells.Font.Color = 1;
                    */
                }


                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
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
        private void cdvOrderStatus_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvOrderStatus.DisplayText == "")
                cdvOrderStatus.Text = "";
        }

        private void btnSave_Click(object sender, EventArgs e)
        {

            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SavePackOrder())
                {
                    ClearList("View");
                    ViewOrderList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdOrderList_EditModeStarting(object sender, EditModeStartingEventArgs e)
        {

            if (spdOrderList_Sheet1.ActiveColumnIndex != 0)
                spdOrderList_Sheet1.Cells[spdOrderList_Sheet1.ActiveRowIndex, (int)PACK_ORDER.CHK].Value = true;
        }

        private void txtMatDesc_KeyPress(object sender, KeyPressEventArgs e)
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

        private void txtPackingOrderNo_KeyPress(object sender, KeyPressEventArgs e)
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

        private void btnExclUnShip_Click(object sender, EventArgs e)
        {

            try
            {
                FpSpread excelSp = new FpSpread();
                bool sendFlag = false;

                if (spdOrderList.ActiveSheet.RowCount == 0)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return;
                }

                SheetView sv = spdOrderList.ActiveSheet;

                //DataTable dt =spdOrderList.ActiveSheet.GetDataView(true).ToTable();

                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (sv.Cells[i, (int)PACK_ORDER.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (Convert.ToDouble(sv.Cells[i, (int)PACK_ORDER.REMAIN_QTY].Value) <= 0)
                        {
                            sv.Rows[i].Visible = false;
                        }
                        else
                        {
                            sendFlag = true;
                        }
                    }
                    else
                    {
                        sv.Rows[i].Visible = false;
                    }
                }

                if (sendFlag)
                {
                    excelSp.Sheets.Add(sv);
                    EXTFUC.SaveExcel(excelSp, "PackOrderList(Unship)");
                }
                else
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    //return;
                }

                for (int i = 0; i < sv.RowCount; i++)
                {

                    if (sv.Cells[i, (int)PACK_ORDER.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (Convert.ToDouble(sv.Cells[i, (int)PACK_ORDER.REMAIN_QTY].Value) <= 0)
                        {
                            sv.Rows[i].Visible = true;
                        }
                    }
                    else
                    {
                        sv.Rows[i].Visible = true;
                    }
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

        private void lblExShop_Click(object sender, EventArgs e)
        {
            sheetHidden("ALL");
        }

        private void lblExShopNoInput_Click(object sender, EventArgs e)
        {
            sheetHidden("RED");
        }

        private void lblExShopNow_Click(object sender, EventArgs e)
        {
            sheetHidden("BLUE");
        }

        private void lblExShopOver_Click(object sender, EventArgs e)
        {
            sheetHidden("GREEN");
        }

        private void lblExShopInput_Click(object sender, EventArgs e)
        {
            sheetHidden("BLACK");
        }

        private void spdOrderList_CellDoubleClick(object sender, CellClickEventArgs e)
        {
            try
            {


                SheetView sv = spdOrderList.ActiveSheet;


                /*
                if (spdOrderList.ActiveSheet.RowFilter.Fil == true) {
                    spdOrderList.ActiveSheet.RowFilter.ColumnDefinitions.Clear();
                }
                */


                switch (e.Column)
                {
                    case (int)PACK_ORDER.CUSTOMER_ID:
                    case (int)PACK_ORDER.CUSTOMER_NAME:
                    case (int)PACK_ORDER.DELIVERY_ID:
                    case (int)PACK_ORDER.DELIVERY_NAME:
                        sv.AutoFilterColumn(e.Column, sv.Cells[sv.ActiveRowIndex, e.Column].Text, 1);
                        break;
                    case (int)PACK_ORDER.SHIPPED_HISTROY:
                        try
                        {
                            frmViewShippingLot popup = new frmViewShippingLot();
                            popup.StartPosition = FormStartPosition.CenterParent;

                            popup.cdvDept.Text = cdvDept.Text;
                            popup.cdvDept.DisplayText = cdvDept.DisplayText;
                            popup.g_Popup_yn = "Y";
                            popup.g_ERPPackingOrderNo = sv.Cells[sv.ActiveRowIndex, (int)PACK_ORDER.ERP_PACK_ORDER_ID].Text; ;
                            popup.g_ERPPackingOrderLine = sv.Cells[sv.ActiveRowIndex, (int)PACK_ORDER.LINE_NO].Text; ;
                            popup.g_Dept = cdvDept.Text;


                            if (popup.ShowDialog() == DialogResult.OK)
                            {
                                popup = null;
                            }
                            else
                                return;
                        }
                        catch (Exception ex)
                        {
                            MPCF.ShowMsgBox(ex.Message);
                        }
                        break;
                }


                /*
                if (e.Column == (int)PACK_ORDER.CUSTOMER_ID)
                {

                    sv.AutoFilterColumn((int)PACK_ORDER.CUSTOMER_NAME, sv.Cells[sv.ActiveRowIndex, (int)PACK_ORDER.CUSTOMER_NAME].Text, 1);
            
                    cdvCustomerId.Text = sv.Cells[sv.ActiveRowIndex, (int)PACK_ORDER.CUSTOMER_ID].Text;
                    txtCustomerName.Text = sv.Cells[sv.ActiveRowIndex, (int)PACK_ORDER.CUSTOMER_NAME].Text;
                    btnView.PerformClick();
               

                }

                if (e.Column == (int)PACK_ORDER.CUSTOMER_NAME)
                {
                    cdvCustomerId.Text = sv.Cells[sv.ActiveRowIndex, (int)PACK_ORDER.CUSTOMER_ID].Text;
                    txtCustomerName.Text = sv.Cells[sv.ActiveRowIndex, (int)PACK_ORDER.CUSTOMER_NAME].Text;
                    btnView.PerformClick();

                    sv.AutoFilterColumn((int)PACK_ORDER.CUSTOMER_NAME, sv.Cells[sv.ActiveRowIndex, (int)PACK_ORDER.CUSTOMER_NAME].Text, 1);
                }

                if (e.Column == (int)PACK_ORDER.DELIVERY_ID)
                {
                    txtDeliveryName.Text = sv.Cells[sv.ActiveRowIndex, (int)PACK_ORDER.DELIVERY_NAME].Text;
                    btnView.PerformClick();
                }

                if (e.Column == (int)PACK_ORDER.DELIVERY_NAME)
                {
                    txtDeliveryName.Text = sv.Cells[sv.ActiveRowIndex, (int)PACK_ORDER.DELIVERY_NAME].Text;
                    btnView.PerformClick();
                }
                */



            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtCustomerName_TextChanged(object sender, EventArgs e)
        {

        }

        private void txtCustomerName_KeyPress(object sender, KeyPressEventArgs e)
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

        private void cdvCustomerId_KeyPress(object sender, KeyPressEventArgs e)
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

        private void txtDeliveryName_KeyPress(object sender, KeyPressEventArgs e)
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

        private void spdOrderList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {

            try
            {
                SheetView sv = spdOrderList.ActiveSheet;


                switch (e.Column)
                {
                    case (int)PACK_ORDER.SHIPPED_HISTROY_BTN:
                        frmViewShippingLot popup = new frmViewShippingLot();
                        popup.StartPosition = FormStartPosition.CenterParent;

                        popup.cdvDept.Text = cdvDept.Text;
                        popup.cdvDept.DisplayText = cdvDept.DisplayText;
                        popup.g_Popup_yn = "Y";
                        popup.g_ERPPackingOrderNo = sv.Cells[sv.ActiveRowIndex, (int)PACK_ORDER.ERP_PACK_ORDER_ID].Text; ;
                        popup.g_ERPPackingOrderLine = sv.Cells[sv.ActiveRowIndex, (int)PACK_ORDER.LINE_NO].Text; ;
                        popup.g_Dept = cdvDept.Text;


                        if (popup.ShowDialog() == DialogResult.OK)
                        {
                            popup = null;
                        }
                        else
                            return;

                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }



        }

        private void InitializeComponent2()
        {
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer1 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer1 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer2 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer2 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer3 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer3 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer4 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer4 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer5 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer5 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer6 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer6 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer7 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer7 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer8 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer8 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer9 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer9 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer10 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer10 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer11 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer11 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer12 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer12 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer13 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer13 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer14 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer14 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer15 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer15 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer16 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer16 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer17 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer17 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer18 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer18 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer19 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer19 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer20 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer20 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer21 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer22 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer102 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer184 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer185 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer103 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer186 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer187 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer21 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer23 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer24 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer22 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer25 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer26 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer23 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer27 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer28 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer24 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer29 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer30 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer25 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer31 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer32 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer26 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer33 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer34 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer27 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer35 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer36 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer28 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer37 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer38 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer29 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer39 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer40 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer30 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer41 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer42 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer31 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer43 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer44 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer32 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer45 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer46 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer33 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer47 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer48 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer34 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer49 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer50 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer35 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer51 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer52 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer36 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer53 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer54 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer37 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer55 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer56 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer38 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer57 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer58 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer39 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer59 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer60 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer40 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer61 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer62 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer41 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer63 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer64 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer42 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer65 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer66 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer43 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer67 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer68 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer44 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer69 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer70 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer45 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer71 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer72 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer46 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer73 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer74 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer47 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer75 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer76 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer48 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer77 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer78 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer49 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer79 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer80 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer50 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer81 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer82 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer51 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer83 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer84 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer52 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer85 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer86 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer53 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer87 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer88 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer54 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer89 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer90 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer55 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer91 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer92 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer56 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer93 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer94 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer57 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer95 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer96 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer58 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer97 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer98 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer59 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer99 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer100 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer60 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer101 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer102 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer61 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer103 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer104 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer62 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer105 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer106 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer63 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer107 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer108 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer64 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer109 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer110 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer65 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer111 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer112 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer66 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer113 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer114 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer67 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer115 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer116 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer68 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer117 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer118 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer69 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer119 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer120 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer70 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer121 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer122 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer71 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer123 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer124 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer72 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer125 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer126 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer73 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer127 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer128 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer74 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer129 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer130 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer75 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer131 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer132 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer76 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer133 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer134 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer77 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer135 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer136 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer78 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer137 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer138 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer79 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer139 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer140 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer80 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer141 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer142 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer81 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer143 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer144 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer82 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer145 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer146 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer83 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer147 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer148 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.ColumnHeaderRenderer columnHeaderRenderer84 = new FarPoint.Win.Spread.CellType.ColumnHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer149 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            FarPoint.Win.Spread.CellType.RowHeaderRenderer rowHeaderRenderer150 = new FarPoint.Win.Spread.CellType.RowHeaderRenderer();
            Infragistics.Win.Appearance appearance9 = new Infragistics.Win.Appearance();
            Infragistics.Win.Appearance appearance3 = new Infragistics.Win.Appearance();
            Infragistics.Win.Appearance appearance4 = new Infragistics.Win.Appearance();
            FarPoint.Win.Spread.DefaultFocusIndicatorRenderer defaultFocusIndicatorRenderer2 = new FarPoint.Win.Spread.DefaultFocusIndicatorRenderer();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer4 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.NamedStyle namedStyle10 = new FarPoint.Win.Spread.NamedStyle("Style4");
            FarPoint.Win.Spread.CellType.FilterBarCellType filterBarCellType3 = new FarPoint.Win.Spread.CellType.FilterBarCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle11 = new FarPoint.Win.Spread.NamedStyle("Style5");
            FarPoint.Win.Spread.NamedStyle namedStyle12 = new FarPoint.Win.Spread.NamedStyle("DataAreaDefault");
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType4 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle13 = new FarPoint.Win.Spread.NamedStyle("Style1");
            FarPoint.Win.BevelBorder bevelBorder3 = new FarPoint.Win.BevelBorder(FarPoint.Win.BevelBorderType.Lowered);
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType5 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle14 = new FarPoint.Win.Spread.NamedStyle("FilterBarDefault");
            FarPoint.Win.Spread.CellType.FilterBarCellType filterBarCellType4 = new FarPoint.Win.Spread.CellType.FilterBarCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle15 = new FarPoint.Win.Spread.NamedStyle("HeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle16 = new FarPoint.Win.Spread.NamedStyle("Style3");
            FarPoint.Win.Spread.NamedStyle namedStyle17 = new FarPoint.Win.Spread.NamedStyle("RowHeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle18 = new FarPoint.Win.Spread.NamedStyle("Style2");
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType6 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.SpreadSkin spreadSkin2 = new FarPoint.Win.Spread.SpreadSkin();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer5 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.StatusBarSkin statusBarSkin2 = new FarPoint.Win.Spread.StatusBarSkin();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer6 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.CellType.NumberCellType numberCellType1 = new FarPoint.Win.Spread.CellType.NumberCellType();
            FarPoint.Win.Spread.CellType.NumberCellType numberCellType2 = new FarPoint.Win.Spread.CellType.NumberCellType();
            FarPoint.Win.Spread.CellType.NumberCellType numberCellType3 = new FarPoint.Win.Spread.CellType.NumberCellType();
            FarPoint.Win.Spread.CellType.NumberCellType numberCellType4 = new FarPoint.Win.Spread.CellType.NumberCellType();
            FarPoint.Win.Spread.CellType.CheckBoxCellType checkBoxCellType3 = new FarPoint.Win.Spread.CellType.CheckBoxCellType();
            FarPoint.Win.Spread.CellType.CheckBoxCellType checkBoxCellType4 = new FarPoint.Win.Spread.CellType.CheckBoxCellType();
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType7 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.CellType.NumberCellType numberCellType5 = new FarPoint.Win.Spread.CellType.NumberCellType();
            FarPoint.Win.Spread.CellType.NumberCellType numberCellType6 = new FarPoint.Win.Spread.CellType.NumberCellType();
            FarPoint.Win.Spread.CellType.NumberCellType numberCellType7 = new FarPoint.Win.Spread.CellType.NumberCellType();
            FarPoint.Win.Spread.CellType.NumberCellType numberCellType8 = new FarPoint.Win.Spread.CellType.NumberCellType();
            FarPoint.Win.Spread.CellType.NumberCellType numberCellType9 = new FarPoint.Win.Spread.CellType.NumberCellType();
            FarPoint.Win.Spread.CellType.NumberCellType numberCellType10 = new FarPoint.Win.Spread.CellType.NumberCellType();
            FarPoint.Win.Spread.CellType.NumberCellType numberCellType11 = new FarPoint.Win.Spread.CellType.NumberCellType();
            FarPoint.Win.Spread.CellType.NumberCellType numberCellType12 = new FarPoint.Win.Spread.CellType.NumberCellType();
            FarPoint.Win.Spread.CellType.DateTimeCellType dateTimeCellType1 = new FarPoint.Win.Spread.CellType.DateTimeCellType();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frmViewPackingOrderList_2));
            FarPoint.Win.Spread.CellType.DateTimeCellType dateTimeCellType2 = new FarPoint.Win.Spread.CellType.DateTimeCellType();
            FarPoint.Win.Spread.CellType.ButtonCellType buttonCellType1 = new FarPoint.Win.Spread.CellType.ButtonCellType();
            Infragistics.Win.Appearance appearance7 = new Infragistics.Win.Appearance();
            Infragistics.Win.Appearance appearance1 = new Infragistics.Win.Appearance();
            Infragistics.Win.Appearance appearance2 = new Infragistics.Win.Appearance();
            FarPoint.Win.Spread.DefaultFocusIndicatorRenderer defaultFocusIndicatorRenderer1 = new FarPoint.Win.Spread.DefaultFocusIndicatorRenderer();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer1 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.NamedStyle namedStyle1 = new FarPoint.Win.Spread.NamedStyle("Style4");
            FarPoint.Win.Spread.CellType.FilterBarCellType filterBarCellType1 = new FarPoint.Win.Spread.CellType.FilterBarCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle2 = new FarPoint.Win.Spread.NamedStyle("Style5");
            FarPoint.Win.Spread.NamedStyle namedStyle3 = new FarPoint.Win.Spread.NamedStyle("DataAreaDefault");
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType1 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle4 = new FarPoint.Win.Spread.NamedStyle("Style1");
            FarPoint.Win.BevelBorder bevelBorder1 = new FarPoint.Win.BevelBorder(FarPoint.Win.BevelBorderType.Lowered);
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType2 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle5 = new FarPoint.Win.Spread.NamedStyle("FilterBarDefault");
            FarPoint.Win.Spread.CellType.FilterBarCellType filterBarCellType2 = new FarPoint.Win.Spread.CellType.FilterBarCellType();
            FarPoint.Win.Spread.NamedStyle namedStyle6 = new FarPoint.Win.Spread.NamedStyle("HeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle7 = new FarPoint.Win.Spread.NamedStyle("Style3");
            FarPoint.Win.Spread.NamedStyle namedStyle8 = new FarPoint.Win.Spread.NamedStyle("RowHeaderDefault");
            FarPoint.Win.Spread.NamedStyle namedStyle9 = new FarPoint.Win.Spread.NamedStyle("Style2");
            FarPoint.Win.Spread.CellType.GeneralCellType generalCellType3 = new FarPoint.Win.Spread.CellType.GeneralCellType();
            FarPoint.Win.Spread.SpreadSkin spreadSkin1 = new FarPoint.Win.Spread.SpreadSkin();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer2 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.StatusBarSkin statusBarSkin1 = new FarPoint.Win.Spread.StatusBarSkin();
            FarPoint.Win.Spread.DefaultScrollBarRenderer defaultScrollBarRenderer3 = new FarPoint.Win.Spread.DefaultScrollBarRenderer();
            FarPoint.Win.Spread.CellType.CheckBoxCellType checkBoxCellType1 = new FarPoint.Win.Spread.CellType.CheckBoxCellType();
            FarPoint.Win.BevelBorder bevelBorder2 = new FarPoint.Win.BevelBorder(FarPoint.Win.BevelBorderType.Lowered);
            FarPoint.Win.Spread.CellType.CheckBoxCellType checkBoxCellType2 = new FarPoint.Win.Spread.CellType.CheckBoxCellType();
            Infragistics.Win.Appearance appearance6 = new Infragistics.Win.Appearance();
            Infragistics.Win.Appearance appearance8 = new Infragistics.Win.Appearance();
            Infragistics.Win.Appearance appearance5 = new Infragistics.Win.Appearance();



            // pnlTop
            // 
            this.pnlTop.Size = new System.Drawing.Size(1239, 0);
            // 
            // lblFormTitle
            // 
            this.lblFormTitle.Size = new System.Drawing.Size(1235, 0);
            this.lblFormTitle.Text = "ViewForm01";
            columnHeaderRenderer1.Name = "columnHeaderRenderer1";
            columnHeaderRenderer1.PictureZoomEffect = false;
            columnHeaderRenderer1.TextRotationAngle = 0D;
            columnHeaderRenderer1.ZoomFactor = 1F;
            rowHeaderRenderer1.Name = "rowHeaderRenderer1";
            rowHeaderRenderer1.PictureZoomEffect = false;
            rowHeaderRenderer1.TextRotationAngle = 0D;
            rowHeaderRenderer1.ZoomFactor = 1F;
            columnHeaderRenderer2.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer2.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer2.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer2.Name = "columnHeaderRenderer2";
            columnHeaderRenderer2.PictureZoomEffect = false;
            columnHeaderRenderer2.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer2.TextRotationAngle = 0D;
            columnHeaderRenderer2.ZoomFactor = 1F;
            rowHeaderRenderer2.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer2.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer2.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer2.Name = "rowHeaderRenderer2";
            rowHeaderRenderer2.PictureZoomEffect = false;
            rowHeaderRenderer2.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer2.TextRotationAngle = 0D;
            rowHeaderRenderer2.ZoomFactor = 1F;
            columnHeaderRenderer3.Name = "columnHeaderRenderer3";
            columnHeaderRenderer3.PictureZoomEffect = false;
            columnHeaderRenderer3.TextRotationAngle = 0D;
            columnHeaderRenderer3.ZoomFactor = 1F;
            rowHeaderRenderer3.Name = "rowHeaderRenderer3";
            rowHeaderRenderer3.PictureZoomEffect = false;
            rowHeaderRenderer3.TextRotationAngle = 0D;
            rowHeaderRenderer3.ZoomFactor = 1F;
            columnHeaderRenderer4.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer4.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer4.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer4.Name = "columnHeaderRenderer4";
            columnHeaderRenderer4.PictureZoomEffect = false;
            columnHeaderRenderer4.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer4.TextRotationAngle = 0D;
            columnHeaderRenderer4.ZoomFactor = 1F;
            rowHeaderRenderer4.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer4.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer4.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer4.Name = "rowHeaderRenderer4";
            rowHeaderRenderer4.PictureZoomEffect = false;
            rowHeaderRenderer4.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer4.TextRotationAngle = 0D;
            rowHeaderRenderer4.ZoomFactor = 1F;
            columnHeaderRenderer5.Name = "columnHeaderRenderer5";
            columnHeaderRenderer5.PictureZoomEffect = false;
            columnHeaderRenderer5.TextRotationAngle = 0D;
            columnHeaderRenderer5.ZoomFactor = 1F;
            rowHeaderRenderer5.Name = "rowHeaderRenderer5";
            rowHeaderRenderer5.PictureZoomEffect = false;
            rowHeaderRenderer5.TextRotationAngle = 0D;
            rowHeaderRenderer5.ZoomFactor = 1F;
            columnHeaderRenderer6.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer6.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer6.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer6.Name = "columnHeaderRenderer6";
            columnHeaderRenderer6.PictureZoomEffect = false;
            columnHeaderRenderer6.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer6.TextRotationAngle = 0D;
            columnHeaderRenderer6.ZoomFactor = 1F;
            rowHeaderRenderer6.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer6.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer6.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer6.Name = "rowHeaderRenderer6";
            rowHeaderRenderer6.PictureZoomEffect = false;
            rowHeaderRenderer6.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer6.TextRotationAngle = 0D;
            rowHeaderRenderer6.ZoomFactor = 1F;
            columnHeaderRenderer7.Name = "columnHeaderRenderer7";
            columnHeaderRenderer7.PictureZoomEffect = false;
            columnHeaderRenderer7.TextRotationAngle = 0D;
            columnHeaderRenderer7.ZoomFactor = 1F;
            rowHeaderRenderer7.Name = "rowHeaderRenderer7";
            rowHeaderRenderer7.PictureZoomEffect = false;
            rowHeaderRenderer7.TextRotationAngle = 0D;
            rowHeaderRenderer7.ZoomFactor = 1F;
            columnHeaderRenderer8.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer8.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer8.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer8.Name = "columnHeaderRenderer8";
            columnHeaderRenderer8.PictureZoomEffect = false;
            columnHeaderRenderer8.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer8.TextRotationAngle = 0D;
            columnHeaderRenderer8.ZoomFactor = 1F;
            rowHeaderRenderer8.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer8.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer8.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer8.Name = "rowHeaderRenderer8";
            rowHeaderRenderer8.PictureZoomEffect = false;
            rowHeaderRenderer8.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer8.TextRotationAngle = 0D;
            rowHeaderRenderer8.ZoomFactor = 1F;
            columnHeaderRenderer9.Name = "columnHeaderRenderer9";
            columnHeaderRenderer9.PictureZoomEffect = false;
            columnHeaderRenderer9.TextRotationAngle = 0D;
            columnHeaderRenderer9.ZoomFactor = 1F;
            rowHeaderRenderer9.Name = "rowHeaderRenderer9";
            rowHeaderRenderer9.PictureZoomEffect = false;
            rowHeaderRenderer9.TextRotationAngle = 0D;
            rowHeaderRenderer9.ZoomFactor = 1F;
            columnHeaderRenderer10.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer10.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer10.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer10.Name = "columnHeaderRenderer10";
            columnHeaderRenderer10.PictureZoomEffect = false;
            columnHeaderRenderer10.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer10.TextRotationAngle = 0D;
            columnHeaderRenderer10.ZoomFactor = 1F;
            rowHeaderRenderer10.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer10.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer10.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer10.Name = "rowHeaderRenderer10";
            rowHeaderRenderer10.PictureZoomEffect = false;
            rowHeaderRenderer10.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer10.TextRotationAngle = 0D;
            rowHeaderRenderer10.ZoomFactor = 1F;
            columnHeaderRenderer11.Name = "columnHeaderRenderer11";
            columnHeaderRenderer11.PictureZoomEffect = false;
            columnHeaderRenderer11.TextRotationAngle = 0D;
            columnHeaderRenderer11.ZoomFactor = 1F;
            rowHeaderRenderer11.Name = "rowHeaderRenderer11";
            rowHeaderRenderer11.PictureZoomEffect = false;
            rowHeaderRenderer11.TextRotationAngle = 0D;
            rowHeaderRenderer11.ZoomFactor = 1F;
            columnHeaderRenderer12.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer12.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer12.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer12.Name = "columnHeaderRenderer12";
            columnHeaderRenderer12.PictureZoomEffect = false;
            columnHeaderRenderer12.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer12.TextRotationAngle = 0D;
            columnHeaderRenderer12.ZoomFactor = 1F;
            rowHeaderRenderer12.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer12.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer12.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer12.Name = "rowHeaderRenderer12";
            rowHeaderRenderer12.PictureZoomEffect = false;
            rowHeaderRenderer12.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer12.TextRotationAngle = 0D;
            rowHeaderRenderer12.ZoomFactor = 1F;
            columnHeaderRenderer13.Name = "columnHeaderRenderer13";
            columnHeaderRenderer13.PictureZoomEffect = false;
            columnHeaderRenderer13.TextRotationAngle = 0D;
            columnHeaderRenderer13.ZoomFactor = 1F;
            rowHeaderRenderer13.Name = "rowHeaderRenderer13";
            rowHeaderRenderer13.PictureZoomEffect = false;
            rowHeaderRenderer13.TextRotationAngle = 0D;
            rowHeaderRenderer13.ZoomFactor = 1F;
            columnHeaderRenderer14.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer14.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer14.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer14.Name = "columnHeaderRenderer14";
            columnHeaderRenderer14.PictureZoomEffect = false;
            columnHeaderRenderer14.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer14.TextRotationAngle = 0D;
            columnHeaderRenderer14.ZoomFactor = 1F;
            rowHeaderRenderer14.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer14.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer14.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer14.Name = "rowHeaderRenderer14";
            rowHeaderRenderer14.PictureZoomEffect = false;
            rowHeaderRenderer14.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer14.TextRotationAngle = 0D;
            rowHeaderRenderer14.ZoomFactor = 1F;
            columnHeaderRenderer15.Name = "columnHeaderRenderer15";
            columnHeaderRenderer15.PictureZoomEffect = false;
            columnHeaderRenderer15.TextRotationAngle = 0D;
            columnHeaderRenderer15.ZoomFactor = 1F;
            rowHeaderRenderer15.Name = "rowHeaderRenderer15";
            rowHeaderRenderer15.PictureZoomEffect = false;
            rowHeaderRenderer15.TextRotationAngle = 0D;
            rowHeaderRenderer15.ZoomFactor = 1F;
            columnHeaderRenderer16.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer16.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer16.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer16.Name = "columnHeaderRenderer16";
            columnHeaderRenderer16.PictureZoomEffect = false;
            columnHeaderRenderer16.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer16.TextRotationAngle = 0D;
            columnHeaderRenderer16.ZoomFactor = 1F;
            rowHeaderRenderer16.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer16.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer16.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer16.Name = "rowHeaderRenderer16";
            rowHeaderRenderer16.PictureZoomEffect = false;
            rowHeaderRenderer16.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer16.TextRotationAngle = 0D;
            rowHeaderRenderer16.ZoomFactor = 1F;
            columnHeaderRenderer17.Name = "columnHeaderRenderer17";
            columnHeaderRenderer17.PictureZoomEffect = false;
            columnHeaderRenderer17.TextRotationAngle = 0D;
            columnHeaderRenderer17.ZoomFactor = 1F;
            rowHeaderRenderer17.Name = "rowHeaderRenderer17";
            rowHeaderRenderer17.PictureZoomEffect = false;
            rowHeaderRenderer17.TextRotationAngle = 0D;
            rowHeaderRenderer17.ZoomFactor = 1F;
            columnHeaderRenderer18.Name = "columnHeaderRenderer18";
            columnHeaderRenderer18.PictureZoomEffect = false;
            columnHeaderRenderer18.TextRotationAngle = 0D;
            columnHeaderRenderer18.ZoomFactor = 1F;
            rowHeaderRenderer18.Name = "rowHeaderRenderer18";
            rowHeaderRenderer18.PictureZoomEffect = false;
            rowHeaderRenderer18.TextRotationAngle = 0D;
            rowHeaderRenderer18.ZoomFactor = 1F;
            columnHeaderRenderer19.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer19.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer19.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer19.Name = "columnHeaderRenderer19";
            columnHeaderRenderer19.PictureZoomEffect = false;
            columnHeaderRenderer19.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer19.TextRotationAngle = 0D;
            columnHeaderRenderer19.ZoomFactor = 1F;
            rowHeaderRenderer19.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer19.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer19.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer19.Name = "rowHeaderRenderer19";
            rowHeaderRenderer19.PictureZoomEffect = false;
            rowHeaderRenderer19.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer19.TextRotationAngle = 0D;
            rowHeaderRenderer19.ZoomFactor = 1F;
            rowHeaderRenderer20.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer20.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer20.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer20.Name = "rowHeaderRenderer20";
            rowHeaderRenderer20.PictureZoomEffect = false;
            rowHeaderRenderer20.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer20.TextRotationAngle = 0D;
            rowHeaderRenderer20.ZoomFactor = 1F;
            columnHeaderRenderer20.Name = "columnHeaderRenderer20";
            columnHeaderRenderer20.PictureZoomEffect = false;
            columnHeaderRenderer20.TextRotationAngle = 0D;
            columnHeaderRenderer20.ZoomFactor = 1F;
            rowHeaderRenderer21.Name = "rowHeaderRenderer21";
            rowHeaderRenderer21.PictureZoomEffect = false;
            rowHeaderRenderer21.TextRotationAngle = 0D;
            rowHeaderRenderer21.ZoomFactor = 1F;
            rowHeaderRenderer22.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer22.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer22.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer22.Name = "rowHeaderRenderer22";
            rowHeaderRenderer22.PictureZoomEffect = false;
            rowHeaderRenderer22.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer22.TextRotationAngle = 0D;
            rowHeaderRenderer22.ZoomFactor = 1F;
            columnHeaderRenderer102.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer102.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer102.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer102.Name = "columnHeaderRenderer102";
            columnHeaderRenderer102.PictureZoomEffect = false;
            columnHeaderRenderer102.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer102.TextRotationAngle = 0D;
            columnHeaderRenderer102.ZoomFactor = 1F;
            rowHeaderRenderer184.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer184.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer184.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer184.Name = "rowHeaderRenderer184";
            rowHeaderRenderer184.PictureZoomEffect = false;
            rowHeaderRenderer184.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer184.TextRotationAngle = 0D;
            rowHeaderRenderer184.ZoomFactor = 1F;
            rowHeaderRenderer185.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer185.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer185.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer185.Name = "rowHeaderRenderer185";
            rowHeaderRenderer185.PictureZoomEffect = false;
            rowHeaderRenderer185.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer185.TextRotationAngle = 0D;
            rowHeaderRenderer185.ZoomFactor = 1F;
            columnHeaderRenderer103.Name = "columnHeaderRenderer103";
            columnHeaderRenderer103.PictureZoomEffect = false;
            columnHeaderRenderer103.TextRotationAngle = 0D;
            columnHeaderRenderer103.ZoomFactor = 1F;
            rowHeaderRenderer186.Name = "rowHeaderRenderer186";
            rowHeaderRenderer186.PictureZoomEffect = false;
            rowHeaderRenderer186.TextRotationAngle = 0D;
            rowHeaderRenderer186.ZoomFactor = 1F;
            rowHeaderRenderer187.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer187.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer187.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer187.Name = "rowHeaderRenderer187";
            rowHeaderRenderer187.PictureZoomEffect = false;
            rowHeaderRenderer187.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer187.TextRotationAngle = 0D;
            rowHeaderRenderer187.ZoomFactor = 1F;
            columnHeaderRenderer21.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer21.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer21.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer21.Name = "columnHeaderRenderer21";
            columnHeaderRenderer21.PictureZoomEffect = false;
            columnHeaderRenderer21.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer21.TextRotationAngle = 0D;
            columnHeaderRenderer21.ZoomFactor = 1F;
            rowHeaderRenderer23.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer23.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer23.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer23.Name = "rowHeaderRenderer23";
            rowHeaderRenderer23.PictureZoomEffect = false;
            rowHeaderRenderer23.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer23.TextRotationAngle = 0D;
            rowHeaderRenderer23.ZoomFactor = 1F;
            rowHeaderRenderer24.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer24.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer24.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer24.Name = "rowHeaderRenderer24";
            rowHeaderRenderer24.PictureZoomEffect = false;
            rowHeaderRenderer24.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer24.TextRotationAngle = 0D;
            rowHeaderRenderer24.ZoomFactor = 1F;
            columnHeaderRenderer22.Name = "columnHeaderRenderer22";
            columnHeaderRenderer22.PictureZoomEffect = false;
            columnHeaderRenderer22.TextRotationAngle = 0D;
            columnHeaderRenderer22.ZoomFactor = 1F;
            rowHeaderRenderer25.Name = "rowHeaderRenderer25";
            rowHeaderRenderer25.PictureZoomEffect = false;
            rowHeaderRenderer25.TextRotationAngle = 0D;
            rowHeaderRenderer25.ZoomFactor = 1F;
            rowHeaderRenderer26.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer26.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer26.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer26.Name = "rowHeaderRenderer26";
            rowHeaderRenderer26.PictureZoomEffect = false;
            rowHeaderRenderer26.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer26.TextRotationAngle = 0D;
            rowHeaderRenderer26.ZoomFactor = 1F;
            columnHeaderRenderer23.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer23.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer23.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer23.Name = "columnHeaderRenderer23";
            columnHeaderRenderer23.PictureZoomEffect = false;
            columnHeaderRenderer23.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer23.TextRotationAngle = 0D;
            columnHeaderRenderer23.ZoomFactor = 1F;
            rowHeaderRenderer27.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer27.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer27.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer27.Name = "rowHeaderRenderer27";
            rowHeaderRenderer27.PictureZoomEffect = false;
            rowHeaderRenderer27.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer27.TextRotationAngle = 0D;
            rowHeaderRenderer27.ZoomFactor = 1F;
            rowHeaderRenderer28.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer28.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer28.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer28.Name = "rowHeaderRenderer28";
            rowHeaderRenderer28.PictureZoomEffect = false;
            rowHeaderRenderer28.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer28.TextRotationAngle = 0D;
            rowHeaderRenderer28.ZoomFactor = 1F;
            columnHeaderRenderer24.Name = "columnHeaderRenderer24";
            columnHeaderRenderer24.PictureZoomEffect = false;
            columnHeaderRenderer24.TextRotationAngle = 0D;
            columnHeaderRenderer24.ZoomFactor = 1F;
            rowHeaderRenderer29.Name = "rowHeaderRenderer29";
            rowHeaderRenderer29.PictureZoomEffect = false;
            rowHeaderRenderer29.TextRotationAngle = 0D;
            rowHeaderRenderer29.ZoomFactor = 1F;
            rowHeaderRenderer30.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer30.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer30.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer30.Name = "rowHeaderRenderer30";
            rowHeaderRenderer30.PictureZoomEffect = false;
            rowHeaderRenderer30.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer30.TextRotationAngle = 0D;
            rowHeaderRenderer30.ZoomFactor = 1F;
            columnHeaderRenderer25.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer25.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer25.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer25.Name = "columnHeaderRenderer25";
            columnHeaderRenderer25.PictureZoomEffect = false;
            columnHeaderRenderer25.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer25.TextRotationAngle = 0D;
            columnHeaderRenderer25.ZoomFactor = 1F;
            rowHeaderRenderer31.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer31.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer31.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer31.Name = "rowHeaderRenderer31";
            rowHeaderRenderer31.PictureZoomEffect = false;
            rowHeaderRenderer31.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer31.TextRotationAngle = 0D;
            rowHeaderRenderer31.ZoomFactor = 1F;
            rowHeaderRenderer32.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer32.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer32.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer32.Name = "rowHeaderRenderer32";
            rowHeaderRenderer32.PictureZoomEffect = false;
            rowHeaderRenderer32.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer32.TextRotationAngle = 0D;
            rowHeaderRenderer32.ZoomFactor = 1F;
            columnHeaderRenderer26.Name = "columnHeaderRenderer26";
            columnHeaderRenderer26.PictureZoomEffect = false;
            columnHeaderRenderer26.TextRotationAngle = 0D;
            columnHeaderRenderer26.ZoomFactor = 1F;
            rowHeaderRenderer33.Name = "rowHeaderRenderer33";
            rowHeaderRenderer33.PictureZoomEffect = false;
            rowHeaderRenderer33.TextRotationAngle = 0D;
            rowHeaderRenderer33.ZoomFactor = 1F;
            rowHeaderRenderer34.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer34.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer34.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer34.Name = "rowHeaderRenderer34";
            rowHeaderRenderer34.PictureZoomEffect = false;
            rowHeaderRenderer34.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer34.TextRotationAngle = 0D;
            rowHeaderRenderer34.ZoomFactor = 1F;
            columnHeaderRenderer27.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer27.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer27.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer27.Name = "columnHeaderRenderer27";
            columnHeaderRenderer27.PictureZoomEffect = false;
            columnHeaderRenderer27.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer27.TextRotationAngle = 0D;
            columnHeaderRenderer27.ZoomFactor = 1F;
            rowHeaderRenderer35.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer35.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer35.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer35.Name = "rowHeaderRenderer35";
            rowHeaderRenderer35.PictureZoomEffect = false;
            rowHeaderRenderer35.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer35.TextRotationAngle = 0D;
            rowHeaderRenderer35.ZoomFactor = 1F;
            rowHeaderRenderer36.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer36.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer36.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer36.Name = "rowHeaderRenderer36";
            rowHeaderRenderer36.PictureZoomEffect = false;
            rowHeaderRenderer36.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer36.TextRotationAngle = 0D;
            rowHeaderRenderer36.ZoomFactor = 1F;
            columnHeaderRenderer28.Name = "columnHeaderRenderer28";
            columnHeaderRenderer28.PictureZoomEffect = false;
            columnHeaderRenderer28.TextRotationAngle = 0D;
            columnHeaderRenderer28.ZoomFactor = 1F;
            rowHeaderRenderer37.Name = "rowHeaderRenderer37";
            rowHeaderRenderer37.PictureZoomEffect = false;
            rowHeaderRenderer37.TextRotationAngle = 0D;
            rowHeaderRenderer37.ZoomFactor = 1F;
            rowHeaderRenderer38.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer38.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer38.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer38.Name = "rowHeaderRenderer38";
            rowHeaderRenderer38.PictureZoomEffect = false;
            rowHeaderRenderer38.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer38.TextRotationAngle = 0D;
            rowHeaderRenderer38.ZoomFactor = 1F;
            columnHeaderRenderer29.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer29.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer29.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer29.Name = "columnHeaderRenderer29";
            columnHeaderRenderer29.PictureZoomEffect = false;
            columnHeaderRenderer29.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer29.TextRotationAngle = 0D;
            columnHeaderRenderer29.ZoomFactor = 1F;
            rowHeaderRenderer39.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer39.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer39.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer39.Name = "rowHeaderRenderer39";
            rowHeaderRenderer39.PictureZoomEffect = false;
            rowHeaderRenderer39.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer39.TextRotationAngle = 0D;
            rowHeaderRenderer39.ZoomFactor = 1F;
            rowHeaderRenderer40.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer40.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer40.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer40.Name = "rowHeaderRenderer40";
            rowHeaderRenderer40.PictureZoomEffect = false;
            rowHeaderRenderer40.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer40.TextRotationAngle = 0D;
            rowHeaderRenderer40.ZoomFactor = 1F;
            columnHeaderRenderer30.Name = "columnHeaderRenderer30";
            columnHeaderRenderer30.PictureZoomEffect = false;
            columnHeaderRenderer30.TextRotationAngle = 0D;
            columnHeaderRenderer30.ZoomFactor = 1F;
            rowHeaderRenderer41.Name = "rowHeaderRenderer41";
            rowHeaderRenderer41.PictureZoomEffect = false;
            rowHeaderRenderer41.TextRotationAngle = 0D;
            rowHeaderRenderer41.ZoomFactor = 1F;
            rowHeaderRenderer42.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer42.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer42.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer42.Name = "rowHeaderRenderer42";
            rowHeaderRenderer42.PictureZoomEffect = false;
            rowHeaderRenderer42.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer42.TextRotationAngle = 0D;
            rowHeaderRenderer42.ZoomFactor = 1F;
            columnHeaderRenderer31.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer31.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer31.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer31.Name = "columnHeaderRenderer31";
            columnHeaderRenderer31.PictureZoomEffect = false;
            columnHeaderRenderer31.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer31.TextRotationAngle = 0D;
            columnHeaderRenderer31.ZoomFactor = 1F;
            rowHeaderRenderer43.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer43.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer43.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer43.Name = "rowHeaderRenderer43";
            rowHeaderRenderer43.PictureZoomEffect = false;
            rowHeaderRenderer43.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer43.TextRotationAngle = 0D;
            rowHeaderRenderer43.ZoomFactor = 1F;
            rowHeaderRenderer44.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer44.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer44.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer44.Name = "rowHeaderRenderer44";
            rowHeaderRenderer44.PictureZoomEffect = false;
            rowHeaderRenderer44.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer44.TextRotationAngle = 0D;
            rowHeaderRenderer44.ZoomFactor = 1F;
            columnHeaderRenderer32.Name = "columnHeaderRenderer32";
            columnHeaderRenderer32.PictureZoomEffect = false;
            columnHeaderRenderer32.TextRotationAngle = 0D;
            columnHeaderRenderer32.ZoomFactor = 1F;
            rowHeaderRenderer45.Name = "rowHeaderRenderer45";
            rowHeaderRenderer45.PictureZoomEffect = false;
            rowHeaderRenderer45.TextRotationAngle = 0D;
            rowHeaderRenderer45.ZoomFactor = 1F;
            rowHeaderRenderer46.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer46.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer46.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer46.Name = "rowHeaderRenderer46";
            rowHeaderRenderer46.PictureZoomEffect = false;
            rowHeaderRenderer46.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer46.TextRotationAngle = 0D;
            rowHeaderRenderer46.ZoomFactor = 1F;
            columnHeaderRenderer33.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer33.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer33.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer33.Name = "columnHeaderRenderer33";
            columnHeaderRenderer33.PictureZoomEffect = false;
            columnHeaderRenderer33.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer33.TextRotationAngle = 0D;
            columnHeaderRenderer33.ZoomFactor = 1F;
            rowHeaderRenderer47.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer47.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer47.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer47.Name = "rowHeaderRenderer47";
            rowHeaderRenderer47.PictureZoomEffect = false;
            rowHeaderRenderer47.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer47.TextRotationAngle = 0D;
            rowHeaderRenderer47.ZoomFactor = 1F;
            rowHeaderRenderer48.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer48.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer48.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer48.Name = "rowHeaderRenderer48";
            rowHeaderRenderer48.PictureZoomEffect = false;
            rowHeaderRenderer48.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer48.TextRotationAngle = 0D;
            rowHeaderRenderer48.ZoomFactor = 1F;
            columnHeaderRenderer34.Name = "columnHeaderRenderer34";
            columnHeaderRenderer34.PictureZoomEffect = false;
            columnHeaderRenderer34.TextRotationAngle = 0D;
            columnHeaderRenderer34.ZoomFactor = 1F;
            rowHeaderRenderer49.Name = "rowHeaderRenderer49";
            rowHeaderRenderer49.PictureZoomEffect = false;
            rowHeaderRenderer49.TextRotationAngle = 0D;
            rowHeaderRenderer49.ZoomFactor = 1F;
            rowHeaderRenderer50.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer50.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer50.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer50.Name = "rowHeaderRenderer50";
            rowHeaderRenderer50.PictureZoomEffect = false;
            rowHeaderRenderer50.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer50.TextRotationAngle = 0D;
            rowHeaderRenderer50.ZoomFactor = 1F;
            columnHeaderRenderer35.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer35.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer35.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer35.Name = "columnHeaderRenderer35";
            columnHeaderRenderer35.PictureZoomEffect = false;
            columnHeaderRenderer35.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer35.TextRotationAngle = 0D;
            columnHeaderRenderer35.ZoomFactor = 1F;
            rowHeaderRenderer51.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer51.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer51.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer51.Name = "rowHeaderRenderer51";
            rowHeaderRenderer51.PictureZoomEffect = false;
            rowHeaderRenderer51.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer51.TextRotationAngle = 0D;
            rowHeaderRenderer51.ZoomFactor = 1F;
            rowHeaderRenderer52.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer52.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer52.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer52.Name = "rowHeaderRenderer52";
            rowHeaderRenderer52.PictureZoomEffect = false;
            rowHeaderRenderer52.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer52.TextRotationAngle = 0D;
            rowHeaderRenderer52.ZoomFactor = 1F;
            columnHeaderRenderer36.Name = "columnHeaderRenderer36";
            columnHeaderRenderer36.PictureZoomEffect = false;
            columnHeaderRenderer36.TextRotationAngle = 0D;
            columnHeaderRenderer36.ZoomFactor = 1F;
            rowHeaderRenderer53.Name = "rowHeaderRenderer53";
            rowHeaderRenderer53.PictureZoomEffect = false;
            rowHeaderRenderer53.TextRotationAngle = 0D;
            rowHeaderRenderer53.ZoomFactor = 1F;
            rowHeaderRenderer54.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer54.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer54.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer54.Name = "rowHeaderRenderer54";
            rowHeaderRenderer54.PictureZoomEffect = false;
            rowHeaderRenderer54.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer54.TextRotationAngle = 0D;
            rowHeaderRenderer54.ZoomFactor = 1F;
            columnHeaderRenderer37.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer37.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer37.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer37.Name = "columnHeaderRenderer37";
            columnHeaderRenderer37.PictureZoomEffect = false;
            columnHeaderRenderer37.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer37.TextRotationAngle = 0D;
            columnHeaderRenderer37.ZoomFactor = 1F;
            rowHeaderRenderer55.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer55.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer55.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer55.Name = "rowHeaderRenderer55";
            rowHeaderRenderer55.PictureZoomEffect = false;
            rowHeaderRenderer55.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer55.TextRotationAngle = 0D;
            rowHeaderRenderer55.ZoomFactor = 1F;
            rowHeaderRenderer56.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer56.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer56.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer56.Name = "rowHeaderRenderer56";
            rowHeaderRenderer56.PictureZoomEffect = false;
            rowHeaderRenderer56.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer56.TextRotationAngle = 0D;
            rowHeaderRenderer56.ZoomFactor = 1F;
            columnHeaderRenderer38.Name = "columnHeaderRenderer38";
            columnHeaderRenderer38.PictureZoomEffect = false;
            columnHeaderRenderer38.TextRotationAngle = 0D;
            columnHeaderRenderer38.ZoomFactor = 1F;
            rowHeaderRenderer57.Name = "rowHeaderRenderer57";
            rowHeaderRenderer57.PictureZoomEffect = false;
            rowHeaderRenderer57.TextRotationAngle = 0D;
            rowHeaderRenderer57.ZoomFactor = 1F;
            rowHeaderRenderer58.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer58.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer58.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer58.Name = "rowHeaderRenderer58";
            rowHeaderRenderer58.PictureZoomEffect = false;
            rowHeaderRenderer58.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer58.TextRotationAngle = 0D;
            rowHeaderRenderer58.ZoomFactor = 1F;
            columnHeaderRenderer39.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer39.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer39.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer39.Name = "columnHeaderRenderer39";
            columnHeaderRenderer39.PictureZoomEffect = false;
            columnHeaderRenderer39.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer39.TextRotationAngle = 0D;
            columnHeaderRenderer39.ZoomFactor = 1F;
            rowHeaderRenderer59.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer59.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer59.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer59.Name = "rowHeaderRenderer59";
            rowHeaderRenderer59.PictureZoomEffect = false;
            rowHeaderRenderer59.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer59.TextRotationAngle = 0D;
            rowHeaderRenderer59.ZoomFactor = 1F;
            rowHeaderRenderer60.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer60.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer60.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer60.Name = "rowHeaderRenderer60";
            rowHeaderRenderer60.PictureZoomEffect = false;
            rowHeaderRenderer60.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer60.TextRotationAngle = 0D;
            rowHeaderRenderer60.ZoomFactor = 1F;
            columnHeaderRenderer40.Name = "columnHeaderRenderer40";
            columnHeaderRenderer40.PictureZoomEffect = false;
            columnHeaderRenderer40.TextRotationAngle = 0D;
            columnHeaderRenderer40.ZoomFactor = 1F;
            rowHeaderRenderer61.Name = "rowHeaderRenderer61";
            rowHeaderRenderer61.PictureZoomEffect = false;
            rowHeaderRenderer61.TextRotationAngle = 0D;
            rowHeaderRenderer61.ZoomFactor = 1F;
            rowHeaderRenderer62.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer62.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer62.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer62.Name = "rowHeaderRenderer62";
            rowHeaderRenderer62.PictureZoomEffect = false;
            rowHeaderRenderer62.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer62.TextRotationAngle = 0D;
            rowHeaderRenderer62.ZoomFactor = 1F;
            columnHeaderRenderer41.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer41.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer41.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer41.Name = "columnHeaderRenderer41";
            columnHeaderRenderer41.PictureZoomEffect = false;
            columnHeaderRenderer41.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer41.TextRotationAngle = 0D;
            columnHeaderRenderer41.ZoomFactor = 1F;
            rowHeaderRenderer63.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer63.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer63.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer63.Name = "rowHeaderRenderer63";
            rowHeaderRenderer63.PictureZoomEffect = false;
            rowHeaderRenderer63.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer63.TextRotationAngle = 0D;
            rowHeaderRenderer63.ZoomFactor = 1F;
            rowHeaderRenderer64.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer64.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer64.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer64.Name = "rowHeaderRenderer64";
            rowHeaderRenderer64.PictureZoomEffect = false;
            rowHeaderRenderer64.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer64.TextRotationAngle = 0D;
            rowHeaderRenderer64.ZoomFactor = 1F;
            columnHeaderRenderer42.Name = "columnHeaderRenderer42";
            columnHeaderRenderer42.PictureZoomEffect = false;
            columnHeaderRenderer42.TextRotationAngle = 0D;
            columnHeaderRenderer42.ZoomFactor = 1F;
            rowHeaderRenderer65.Name = "rowHeaderRenderer65";
            rowHeaderRenderer65.PictureZoomEffect = false;
            rowHeaderRenderer65.TextRotationAngle = 0D;
            rowHeaderRenderer65.ZoomFactor = 1F;
            rowHeaderRenderer66.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer66.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer66.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer66.Name = "rowHeaderRenderer66";
            rowHeaderRenderer66.PictureZoomEffect = false;
            rowHeaderRenderer66.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer66.TextRotationAngle = 0D;
            rowHeaderRenderer66.ZoomFactor = 1F;
            columnHeaderRenderer43.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer43.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer43.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer43.Name = "columnHeaderRenderer43";
            columnHeaderRenderer43.PictureZoomEffect = false;
            columnHeaderRenderer43.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer43.TextRotationAngle = 0D;
            columnHeaderRenderer43.ZoomFactor = 1F;
            rowHeaderRenderer67.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer67.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer67.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer67.Name = "rowHeaderRenderer67";
            rowHeaderRenderer67.PictureZoomEffect = false;
            rowHeaderRenderer67.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer67.TextRotationAngle = 0D;
            rowHeaderRenderer67.ZoomFactor = 1F;
            rowHeaderRenderer68.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer68.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer68.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer68.Name = "rowHeaderRenderer68";
            rowHeaderRenderer68.PictureZoomEffect = false;
            rowHeaderRenderer68.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer68.TextRotationAngle = 0D;
            rowHeaderRenderer68.ZoomFactor = 1F;
            columnHeaderRenderer44.Name = "columnHeaderRenderer44";
            columnHeaderRenderer44.PictureZoomEffect = false;
            columnHeaderRenderer44.TextRotationAngle = 0D;
            columnHeaderRenderer44.ZoomFactor = 1F;
            rowHeaderRenderer69.Name = "rowHeaderRenderer69";
            rowHeaderRenderer69.PictureZoomEffect = false;
            rowHeaderRenderer69.TextRotationAngle = 0D;
            rowHeaderRenderer69.ZoomFactor = 1F;
            rowHeaderRenderer70.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer70.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer70.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer70.Name = "rowHeaderRenderer70";
            rowHeaderRenderer70.PictureZoomEffect = false;
            rowHeaderRenderer70.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer70.TextRotationAngle = 0D;
            rowHeaderRenderer70.ZoomFactor = 1F;
            columnHeaderRenderer45.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer45.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer45.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer45.Name = "columnHeaderRenderer45";
            columnHeaderRenderer45.PictureZoomEffect = false;
            columnHeaderRenderer45.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer45.TextRotationAngle = 0D;
            columnHeaderRenderer45.ZoomFactor = 1F;
            rowHeaderRenderer71.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer71.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer71.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer71.Name = "rowHeaderRenderer71";
            rowHeaderRenderer71.PictureZoomEffect = false;
            rowHeaderRenderer71.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer71.TextRotationAngle = 0D;
            rowHeaderRenderer71.ZoomFactor = 1F;
            rowHeaderRenderer72.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer72.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer72.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer72.Name = "rowHeaderRenderer72";
            rowHeaderRenderer72.PictureZoomEffect = false;
            rowHeaderRenderer72.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer72.TextRotationAngle = 0D;
            rowHeaderRenderer72.ZoomFactor = 1F;
            columnHeaderRenderer46.Name = "columnHeaderRenderer46";
            columnHeaderRenderer46.PictureZoomEffect = false;
            columnHeaderRenderer46.TextRotationAngle = 0D;
            columnHeaderRenderer46.ZoomFactor = 1F;
            rowHeaderRenderer73.Name = "rowHeaderRenderer73";
            rowHeaderRenderer73.PictureZoomEffect = false;
            rowHeaderRenderer73.TextRotationAngle = 0D;
            rowHeaderRenderer73.ZoomFactor = 1F;
            rowHeaderRenderer74.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer74.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer74.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer74.Name = "rowHeaderRenderer74";
            rowHeaderRenderer74.PictureZoomEffect = false;
            rowHeaderRenderer74.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer74.TextRotationAngle = 0D;
            rowHeaderRenderer74.ZoomFactor = 1F;
            columnHeaderRenderer47.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer47.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer47.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer47.Name = "columnHeaderRenderer47";
            columnHeaderRenderer47.PictureZoomEffect = false;
            columnHeaderRenderer47.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer47.TextRotationAngle = 0D;
            columnHeaderRenderer47.ZoomFactor = 1F;
            rowHeaderRenderer75.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer75.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer75.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer75.Name = "rowHeaderRenderer75";
            rowHeaderRenderer75.PictureZoomEffect = false;
            rowHeaderRenderer75.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer75.TextRotationAngle = 0D;
            rowHeaderRenderer75.ZoomFactor = 1F;
            rowHeaderRenderer76.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer76.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer76.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer76.Name = "rowHeaderRenderer76";
            rowHeaderRenderer76.PictureZoomEffect = false;
            rowHeaderRenderer76.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer76.TextRotationAngle = 0D;
            rowHeaderRenderer76.ZoomFactor = 1F;
            columnHeaderRenderer48.Name = "columnHeaderRenderer48";
            columnHeaderRenderer48.PictureZoomEffect = false;
            columnHeaderRenderer48.TextRotationAngle = 0D;
            columnHeaderRenderer48.ZoomFactor = 1F;
            rowHeaderRenderer77.Name = "rowHeaderRenderer77";
            rowHeaderRenderer77.PictureZoomEffect = false;
            rowHeaderRenderer77.TextRotationAngle = 0D;
            rowHeaderRenderer77.ZoomFactor = 1F;
            rowHeaderRenderer78.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer78.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer78.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer78.Name = "rowHeaderRenderer78";
            rowHeaderRenderer78.PictureZoomEffect = false;
            rowHeaderRenderer78.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer78.TextRotationAngle = 0D;
            rowHeaderRenderer78.ZoomFactor = 1F;
            columnHeaderRenderer49.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer49.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer49.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer49.Name = "columnHeaderRenderer49";
            columnHeaderRenderer49.PictureZoomEffect = false;
            columnHeaderRenderer49.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer49.TextRotationAngle = 0D;
            columnHeaderRenderer49.ZoomFactor = 1F;
            rowHeaderRenderer79.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer79.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer79.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer79.Name = "rowHeaderRenderer79";
            rowHeaderRenderer79.PictureZoomEffect = false;
            rowHeaderRenderer79.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer79.TextRotationAngle = 0D;
            rowHeaderRenderer79.ZoomFactor = 1F;
            rowHeaderRenderer80.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer80.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer80.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer80.Name = "rowHeaderRenderer80";
            rowHeaderRenderer80.PictureZoomEffect = false;
            rowHeaderRenderer80.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer80.TextRotationAngle = 0D;
            rowHeaderRenderer80.ZoomFactor = 1F;
            columnHeaderRenderer50.Name = "columnHeaderRenderer50";
            columnHeaderRenderer50.PictureZoomEffect = false;
            columnHeaderRenderer50.TextRotationAngle = 0D;
            columnHeaderRenderer50.ZoomFactor = 1F;
            rowHeaderRenderer81.Name = "rowHeaderRenderer81";
            rowHeaderRenderer81.PictureZoomEffect = false;
            rowHeaderRenderer81.TextRotationAngle = 0D;
            rowHeaderRenderer81.ZoomFactor = 1F;
            rowHeaderRenderer82.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer82.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer82.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer82.Name = "rowHeaderRenderer82";
            rowHeaderRenderer82.PictureZoomEffect = false;
            rowHeaderRenderer82.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer82.TextRotationAngle = 0D;
            rowHeaderRenderer82.ZoomFactor = 1F;
            columnHeaderRenderer51.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer51.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer51.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer51.Name = "columnHeaderRenderer51";
            columnHeaderRenderer51.PictureZoomEffect = false;
            columnHeaderRenderer51.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer51.TextRotationAngle = 0D;
            columnHeaderRenderer51.ZoomFactor = 1F;
            rowHeaderRenderer83.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer83.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer83.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer83.Name = "rowHeaderRenderer83";
            rowHeaderRenderer83.PictureZoomEffect = false;
            rowHeaderRenderer83.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer83.TextRotationAngle = 0D;
            rowHeaderRenderer83.ZoomFactor = 1F;
            rowHeaderRenderer84.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer84.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer84.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer84.Name = "rowHeaderRenderer84";
            rowHeaderRenderer84.PictureZoomEffect = false;
            rowHeaderRenderer84.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer84.TextRotationAngle = 0D;
            rowHeaderRenderer84.ZoomFactor = 1F;
            columnHeaderRenderer52.Name = "columnHeaderRenderer52";
            columnHeaderRenderer52.PictureZoomEffect = false;
            columnHeaderRenderer52.TextRotationAngle = 0D;
            columnHeaderRenderer52.ZoomFactor = 1F;
            rowHeaderRenderer85.Name = "rowHeaderRenderer85";
            rowHeaderRenderer85.PictureZoomEffect = false;
            rowHeaderRenderer85.TextRotationAngle = 0D;
            rowHeaderRenderer85.ZoomFactor = 1F;
            rowHeaderRenderer86.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer86.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer86.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer86.Name = "rowHeaderRenderer86";
            rowHeaderRenderer86.PictureZoomEffect = false;
            rowHeaderRenderer86.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer86.TextRotationAngle = 0D;
            rowHeaderRenderer86.ZoomFactor = 1F;
            columnHeaderRenderer53.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer53.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer53.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer53.Name = "columnHeaderRenderer53";
            columnHeaderRenderer53.PictureZoomEffect = false;
            columnHeaderRenderer53.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer53.TextRotationAngle = 0D;
            columnHeaderRenderer53.ZoomFactor = 1F;
            rowHeaderRenderer87.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer87.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer87.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer87.Name = "rowHeaderRenderer87";
            rowHeaderRenderer87.PictureZoomEffect = false;
            rowHeaderRenderer87.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer87.TextRotationAngle = 0D;
            rowHeaderRenderer87.ZoomFactor = 1F;
            rowHeaderRenderer88.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer88.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer88.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer88.Name = "rowHeaderRenderer88";
            rowHeaderRenderer88.PictureZoomEffect = false;
            rowHeaderRenderer88.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer88.TextRotationAngle = 0D;
            rowHeaderRenderer88.ZoomFactor = 1F;
            columnHeaderRenderer54.Name = "columnHeaderRenderer54";
            columnHeaderRenderer54.PictureZoomEffect = false;
            columnHeaderRenderer54.TextRotationAngle = 0D;
            columnHeaderRenderer54.ZoomFactor = 1F;
            rowHeaderRenderer89.Name = "rowHeaderRenderer89";
            rowHeaderRenderer89.PictureZoomEffect = false;
            rowHeaderRenderer89.TextRotationAngle = 0D;
            rowHeaderRenderer89.ZoomFactor = 1F;
            rowHeaderRenderer90.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer90.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer90.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer90.Name = "rowHeaderRenderer90";
            rowHeaderRenderer90.PictureZoomEffect = false;
            rowHeaderRenderer90.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer90.TextRotationAngle = 0D;
            rowHeaderRenderer90.ZoomFactor = 1F;
            columnHeaderRenderer55.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer55.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer55.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer55.Name = "columnHeaderRenderer55";
            columnHeaderRenderer55.PictureZoomEffect = false;
            columnHeaderRenderer55.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer55.TextRotationAngle = 0D;
            columnHeaderRenderer55.ZoomFactor = 1F;
            rowHeaderRenderer91.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer91.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer91.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer91.Name = "rowHeaderRenderer91";
            rowHeaderRenderer91.PictureZoomEffect = false;
            rowHeaderRenderer91.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer91.TextRotationAngle = 0D;
            rowHeaderRenderer91.ZoomFactor = 1F;
            rowHeaderRenderer92.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer92.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer92.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer92.Name = "rowHeaderRenderer92";
            rowHeaderRenderer92.PictureZoomEffect = false;
            rowHeaderRenderer92.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer92.TextRotationAngle = 0D;
            rowHeaderRenderer92.ZoomFactor = 1F;
            columnHeaderRenderer56.Name = "columnHeaderRenderer56";
            columnHeaderRenderer56.PictureZoomEffect = false;
            columnHeaderRenderer56.TextRotationAngle = 0D;
            columnHeaderRenderer56.ZoomFactor = 1F;
            rowHeaderRenderer93.Name = "rowHeaderRenderer93";
            rowHeaderRenderer93.PictureZoomEffect = false;
            rowHeaderRenderer93.TextRotationAngle = 0D;
            rowHeaderRenderer93.ZoomFactor = 1F;
            rowHeaderRenderer94.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer94.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer94.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer94.Name = "rowHeaderRenderer94";
            rowHeaderRenderer94.PictureZoomEffect = false;
            rowHeaderRenderer94.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer94.TextRotationAngle = 0D;
            rowHeaderRenderer94.ZoomFactor = 1F;
            columnHeaderRenderer57.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer57.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer57.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer57.Name = "columnHeaderRenderer57";
            columnHeaderRenderer57.PictureZoomEffect = false;
            columnHeaderRenderer57.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer57.TextRotationAngle = 0D;
            columnHeaderRenderer57.ZoomFactor = 1F;
            rowHeaderRenderer95.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer95.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer95.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer95.Name = "rowHeaderRenderer95";
            rowHeaderRenderer95.PictureZoomEffect = false;
            rowHeaderRenderer95.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer95.TextRotationAngle = 0D;
            rowHeaderRenderer95.ZoomFactor = 1F;
            rowHeaderRenderer96.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer96.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer96.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer96.Name = "rowHeaderRenderer96";
            rowHeaderRenderer96.PictureZoomEffect = false;
            rowHeaderRenderer96.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer96.TextRotationAngle = 0D;
            rowHeaderRenderer96.ZoomFactor = 1F;
            columnHeaderRenderer58.Name = "columnHeaderRenderer58";
            columnHeaderRenderer58.PictureZoomEffect = false;
            columnHeaderRenderer58.TextRotationAngle = 0D;
            columnHeaderRenderer58.ZoomFactor = 1F;
            rowHeaderRenderer97.Name = "rowHeaderRenderer97";
            rowHeaderRenderer97.PictureZoomEffect = false;
            rowHeaderRenderer97.TextRotationAngle = 0D;
            rowHeaderRenderer97.ZoomFactor = 1F;
            rowHeaderRenderer98.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer98.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer98.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer98.Name = "rowHeaderRenderer98";
            rowHeaderRenderer98.PictureZoomEffect = false;
            rowHeaderRenderer98.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer98.TextRotationAngle = 0D;
            rowHeaderRenderer98.ZoomFactor = 1F;
            columnHeaderRenderer59.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer59.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer59.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer59.Name = "columnHeaderRenderer59";
            columnHeaderRenderer59.PictureZoomEffect = false;
            columnHeaderRenderer59.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer59.TextRotationAngle = 0D;
            columnHeaderRenderer59.ZoomFactor = 1F;
            rowHeaderRenderer99.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer99.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer99.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer99.Name = "rowHeaderRenderer99";
            rowHeaderRenderer99.PictureZoomEffect = false;
            rowHeaderRenderer99.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer99.TextRotationAngle = 0D;
            rowHeaderRenderer99.ZoomFactor = 1F;
            rowHeaderRenderer100.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer100.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer100.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer100.Name = "rowHeaderRenderer100";
            rowHeaderRenderer100.PictureZoomEffect = false;
            rowHeaderRenderer100.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer100.TextRotationAngle = 0D;
            rowHeaderRenderer100.ZoomFactor = 1F;
            columnHeaderRenderer60.Name = "columnHeaderRenderer60";
            columnHeaderRenderer60.PictureZoomEffect = false;
            columnHeaderRenderer60.TextRotationAngle = 0D;
            columnHeaderRenderer60.ZoomFactor = 1F;
            rowHeaderRenderer101.Name = "rowHeaderRenderer101";
            rowHeaderRenderer101.PictureZoomEffect = false;
            rowHeaderRenderer101.TextRotationAngle = 0D;
            rowHeaderRenderer101.ZoomFactor = 1F;
            rowHeaderRenderer102.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer102.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer102.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer102.Name = "rowHeaderRenderer102";
            rowHeaderRenderer102.PictureZoomEffect = false;
            rowHeaderRenderer102.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer102.TextRotationAngle = 0D;
            rowHeaderRenderer102.ZoomFactor = 1F;
            columnHeaderRenderer61.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer61.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer61.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer61.Name = "columnHeaderRenderer61";
            columnHeaderRenderer61.PictureZoomEffect = false;
            columnHeaderRenderer61.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer61.TextRotationAngle = 0D;
            columnHeaderRenderer61.ZoomFactor = 1F;
            rowHeaderRenderer103.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer103.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer103.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer103.Name = "rowHeaderRenderer103";
            rowHeaderRenderer103.PictureZoomEffect = false;
            rowHeaderRenderer103.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer103.TextRotationAngle = 0D;
            rowHeaderRenderer103.ZoomFactor = 1F;
            rowHeaderRenderer104.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer104.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer104.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer104.Name = "rowHeaderRenderer104";
            rowHeaderRenderer104.PictureZoomEffect = false;
            rowHeaderRenderer104.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer104.TextRotationAngle = 0D;
            rowHeaderRenderer104.ZoomFactor = 1F;
            columnHeaderRenderer62.Name = "columnHeaderRenderer62";
            columnHeaderRenderer62.PictureZoomEffect = false;
            columnHeaderRenderer62.TextRotationAngle = 0D;
            columnHeaderRenderer62.ZoomFactor = 1F;
            rowHeaderRenderer105.Name = "rowHeaderRenderer105";
            rowHeaderRenderer105.PictureZoomEffect = false;
            rowHeaderRenderer105.TextRotationAngle = 0D;
            rowHeaderRenderer105.ZoomFactor = 1F;
            rowHeaderRenderer106.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer106.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer106.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer106.Name = "rowHeaderRenderer106";
            rowHeaderRenderer106.PictureZoomEffect = false;
            rowHeaderRenderer106.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer106.TextRotationAngle = 0D;
            rowHeaderRenderer106.ZoomFactor = 1F;
            columnHeaderRenderer63.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer63.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer63.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer63.Name = "columnHeaderRenderer63";
            columnHeaderRenderer63.PictureZoomEffect = false;
            columnHeaderRenderer63.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer63.TextRotationAngle = 0D;
            columnHeaderRenderer63.ZoomFactor = 1F;
            rowHeaderRenderer107.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer107.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer107.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer107.Name = "rowHeaderRenderer107";
            rowHeaderRenderer107.PictureZoomEffect = false;
            rowHeaderRenderer107.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer107.TextRotationAngle = 0D;
            rowHeaderRenderer107.ZoomFactor = 1F;
            rowHeaderRenderer108.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer108.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer108.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer108.Name = "rowHeaderRenderer108";
            rowHeaderRenderer108.PictureZoomEffect = false;
            rowHeaderRenderer108.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer108.TextRotationAngle = 0D;
            rowHeaderRenderer108.ZoomFactor = 1F;
            columnHeaderRenderer64.Name = "columnHeaderRenderer64";
            columnHeaderRenderer64.PictureZoomEffect = false;
            columnHeaderRenderer64.TextRotationAngle = 0D;
            columnHeaderRenderer64.ZoomFactor = 1F;
            rowHeaderRenderer109.Name = "rowHeaderRenderer109";
            rowHeaderRenderer109.PictureZoomEffect = false;
            rowHeaderRenderer109.TextRotationAngle = 0D;
            rowHeaderRenderer109.ZoomFactor = 1F;
            rowHeaderRenderer110.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer110.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer110.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer110.Name = "rowHeaderRenderer110";
            rowHeaderRenderer110.PictureZoomEffect = false;
            rowHeaderRenderer110.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer110.TextRotationAngle = 0D;
            rowHeaderRenderer110.ZoomFactor = 1F;
            columnHeaderRenderer65.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer65.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer65.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer65.Name = "columnHeaderRenderer65";
            columnHeaderRenderer65.PictureZoomEffect = false;
            columnHeaderRenderer65.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer65.TextRotationAngle = 0D;
            columnHeaderRenderer65.ZoomFactor = 1F;
            rowHeaderRenderer111.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer111.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer111.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer111.Name = "rowHeaderRenderer111";
            rowHeaderRenderer111.PictureZoomEffect = false;
            rowHeaderRenderer111.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer111.TextRotationAngle = 0D;
            rowHeaderRenderer111.ZoomFactor = 1F;
            rowHeaderRenderer112.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer112.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer112.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer112.Name = "rowHeaderRenderer112";
            rowHeaderRenderer112.PictureZoomEffect = false;
            rowHeaderRenderer112.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer112.TextRotationAngle = 0D;
            rowHeaderRenderer112.ZoomFactor = 1F;
            columnHeaderRenderer66.Name = "columnHeaderRenderer66";
            columnHeaderRenderer66.PictureZoomEffect = false;
            columnHeaderRenderer66.TextRotationAngle = 0D;
            columnHeaderRenderer66.ZoomFactor = 1F;
            rowHeaderRenderer113.Name = "rowHeaderRenderer113";
            rowHeaderRenderer113.PictureZoomEffect = false;
            rowHeaderRenderer113.TextRotationAngle = 0D;
            rowHeaderRenderer113.ZoomFactor = 1F;
            rowHeaderRenderer114.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer114.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer114.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer114.Name = "rowHeaderRenderer114";
            rowHeaderRenderer114.PictureZoomEffect = false;
            rowHeaderRenderer114.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer114.TextRotationAngle = 0D;
            rowHeaderRenderer114.ZoomFactor = 1F;
            columnHeaderRenderer67.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer67.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer67.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer67.Name = "columnHeaderRenderer67";
            columnHeaderRenderer67.PictureZoomEffect = false;
            columnHeaderRenderer67.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer67.TextRotationAngle = 0D;
            columnHeaderRenderer67.ZoomFactor = 1F;
            rowHeaderRenderer115.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer115.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer115.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer115.Name = "rowHeaderRenderer115";
            rowHeaderRenderer115.PictureZoomEffect = false;
            rowHeaderRenderer115.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer115.TextRotationAngle = 0D;
            rowHeaderRenderer115.ZoomFactor = 1F;
            rowHeaderRenderer116.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer116.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer116.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer116.Name = "rowHeaderRenderer116";
            rowHeaderRenderer116.PictureZoomEffect = false;
            rowHeaderRenderer116.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer116.TextRotationAngle = 0D;
            rowHeaderRenderer116.ZoomFactor = 1F;
            columnHeaderRenderer68.Name = "columnHeaderRenderer68";
            columnHeaderRenderer68.PictureZoomEffect = false;
            columnHeaderRenderer68.TextRotationAngle = 0D;
            columnHeaderRenderer68.ZoomFactor = 1F;
            rowHeaderRenderer117.Name = "rowHeaderRenderer117";
            rowHeaderRenderer117.PictureZoomEffect = false;
            rowHeaderRenderer117.TextRotationAngle = 0D;
            rowHeaderRenderer117.ZoomFactor = 1F;
            rowHeaderRenderer118.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer118.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer118.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer118.Name = "rowHeaderRenderer118";
            rowHeaderRenderer118.PictureZoomEffect = false;
            rowHeaderRenderer118.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer118.TextRotationAngle = 0D;
            rowHeaderRenderer118.ZoomFactor = 1F;
            columnHeaderRenderer69.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer69.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer69.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer69.Name = "columnHeaderRenderer69";
            columnHeaderRenderer69.PictureZoomEffect = false;
            columnHeaderRenderer69.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer69.TextRotationAngle = 0D;
            columnHeaderRenderer69.ZoomFactor = 1F;
            rowHeaderRenderer119.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer119.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer119.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer119.Name = "rowHeaderRenderer119";
            rowHeaderRenderer119.PictureZoomEffect = false;
            rowHeaderRenderer119.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer119.TextRotationAngle = 0D;
            rowHeaderRenderer119.ZoomFactor = 1F;
            rowHeaderRenderer120.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer120.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer120.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer120.Name = "rowHeaderRenderer120";
            rowHeaderRenderer120.PictureZoomEffect = false;
            rowHeaderRenderer120.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer120.TextRotationAngle = 0D;
            rowHeaderRenderer120.ZoomFactor = 1F;
            columnHeaderRenderer70.Name = "columnHeaderRenderer70";
            columnHeaderRenderer70.PictureZoomEffect = false;
            columnHeaderRenderer70.TextRotationAngle = 0D;
            columnHeaderRenderer70.ZoomFactor = 1F;
            rowHeaderRenderer121.Name = "rowHeaderRenderer121";
            rowHeaderRenderer121.PictureZoomEffect = false;
            rowHeaderRenderer121.TextRotationAngle = 0D;
            rowHeaderRenderer121.ZoomFactor = 1F;
            rowHeaderRenderer122.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer122.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer122.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer122.Name = "rowHeaderRenderer122";
            rowHeaderRenderer122.PictureZoomEffect = false;
            rowHeaderRenderer122.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer122.TextRotationAngle = 0D;
            rowHeaderRenderer122.ZoomFactor = 1F;
            columnHeaderRenderer71.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer71.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer71.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer71.Name = "columnHeaderRenderer71";
            columnHeaderRenderer71.PictureZoomEffect = false;
            columnHeaderRenderer71.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer71.TextRotationAngle = 0D;
            columnHeaderRenderer71.ZoomFactor = 1F;
            rowHeaderRenderer123.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer123.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer123.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer123.Name = "rowHeaderRenderer123";
            rowHeaderRenderer123.PictureZoomEffect = false;
            rowHeaderRenderer123.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer123.TextRotationAngle = 0D;
            rowHeaderRenderer123.ZoomFactor = 1F;
            rowHeaderRenderer124.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer124.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer124.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer124.Name = "rowHeaderRenderer124";
            rowHeaderRenderer124.PictureZoomEffect = false;
            rowHeaderRenderer124.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer124.TextRotationAngle = 0D;
            rowHeaderRenderer124.ZoomFactor = 1F;
            columnHeaderRenderer72.Name = "columnHeaderRenderer72";
            columnHeaderRenderer72.PictureZoomEffect = false;
            columnHeaderRenderer72.TextRotationAngle = 0D;
            columnHeaderRenderer72.ZoomFactor = 1F;
            rowHeaderRenderer125.Name = "rowHeaderRenderer125";
            rowHeaderRenderer125.PictureZoomEffect = false;
            rowHeaderRenderer125.TextRotationAngle = 0D;
            rowHeaderRenderer125.ZoomFactor = 1F;
            rowHeaderRenderer126.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer126.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer126.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer126.Name = "rowHeaderRenderer126";
            rowHeaderRenderer126.PictureZoomEffect = false;
            rowHeaderRenderer126.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer126.TextRotationAngle = 0D;
            rowHeaderRenderer126.ZoomFactor = 1F;
            columnHeaderRenderer73.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer73.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer73.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer73.Name = "columnHeaderRenderer73";
            columnHeaderRenderer73.PictureZoomEffect = false;
            columnHeaderRenderer73.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer73.TextRotationAngle = 0D;
            columnHeaderRenderer73.ZoomFactor = 1F;
            rowHeaderRenderer127.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer127.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer127.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer127.Name = "rowHeaderRenderer127";
            rowHeaderRenderer127.PictureZoomEffect = false;
            rowHeaderRenderer127.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer127.TextRotationAngle = 0D;
            rowHeaderRenderer127.ZoomFactor = 1F;
            rowHeaderRenderer128.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer128.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer128.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer128.Name = "rowHeaderRenderer128";
            rowHeaderRenderer128.PictureZoomEffect = false;
            rowHeaderRenderer128.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer128.TextRotationAngle = 0D;
            rowHeaderRenderer128.ZoomFactor = 1F;
            columnHeaderRenderer74.Name = "columnHeaderRenderer74";
            columnHeaderRenderer74.PictureZoomEffect = false;
            columnHeaderRenderer74.TextRotationAngle = 0D;
            columnHeaderRenderer74.ZoomFactor = 1F;
            rowHeaderRenderer129.Name = "rowHeaderRenderer129";
            rowHeaderRenderer129.PictureZoomEffect = false;
            rowHeaderRenderer129.TextRotationAngle = 0D;
            rowHeaderRenderer129.ZoomFactor = 1F;
            rowHeaderRenderer130.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer130.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer130.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer130.Name = "rowHeaderRenderer130";
            rowHeaderRenderer130.PictureZoomEffect = false;
            rowHeaderRenderer130.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer130.TextRotationAngle = 0D;
            rowHeaderRenderer130.ZoomFactor = 1F;
            columnHeaderRenderer75.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer75.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer75.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer75.Name = "columnHeaderRenderer75";
            columnHeaderRenderer75.PictureZoomEffect = false;
            columnHeaderRenderer75.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer75.TextRotationAngle = 0D;
            columnHeaderRenderer75.ZoomFactor = 1F;
            rowHeaderRenderer131.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer131.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer131.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer131.Name = "rowHeaderRenderer131";
            rowHeaderRenderer131.PictureZoomEffect = false;
            rowHeaderRenderer131.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer131.TextRotationAngle = 0D;
            rowHeaderRenderer131.ZoomFactor = 1F;
            rowHeaderRenderer132.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer132.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer132.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer132.Name = "rowHeaderRenderer132";
            rowHeaderRenderer132.PictureZoomEffect = false;
            rowHeaderRenderer132.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer132.TextRotationAngle = 0D;
            rowHeaderRenderer132.ZoomFactor = 1F;
            columnHeaderRenderer76.Name = "columnHeaderRenderer76";
            columnHeaderRenderer76.PictureZoomEffect = false;
            columnHeaderRenderer76.TextRotationAngle = 0D;
            columnHeaderRenderer76.ZoomFactor = 1F;
            rowHeaderRenderer133.Name = "rowHeaderRenderer133";
            rowHeaderRenderer133.PictureZoomEffect = false;
            rowHeaderRenderer133.TextRotationAngle = 0D;
            rowHeaderRenderer133.ZoomFactor = 1F;
            rowHeaderRenderer134.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer134.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer134.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer134.Name = "rowHeaderRenderer134";
            rowHeaderRenderer134.PictureZoomEffect = false;
            rowHeaderRenderer134.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer134.TextRotationAngle = 0D;
            rowHeaderRenderer134.ZoomFactor = 1F;
            columnHeaderRenderer77.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer77.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer77.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer77.Name = "columnHeaderRenderer77";
            columnHeaderRenderer77.PictureZoomEffect = false;
            columnHeaderRenderer77.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer77.TextRotationAngle = 0D;
            columnHeaderRenderer77.ZoomFactor = 1F;
            rowHeaderRenderer135.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer135.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer135.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer135.Name = "rowHeaderRenderer135";
            rowHeaderRenderer135.PictureZoomEffect = false;
            rowHeaderRenderer135.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer135.TextRotationAngle = 0D;
            rowHeaderRenderer135.ZoomFactor = 1F;
            rowHeaderRenderer136.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer136.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer136.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer136.Name = "rowHeaderRenderer136";
            rowHeaderRenderer136.PictureZoomEffect = false;
            rowHeaderRenderer136.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer136.TextRotationAngle = 0D;
            rowHeaderRenderer136.ZoomFactor = 1F;
            columnHeaderRenderer78.Name = "columnHeaderRenderer78";
            columnHeaderRenderer78.PictureZoomEffect = false;
            columnHeaderRenderer78.TextRotationAngle = 0D;
            columnHeaderRenderer78.ZoomFactor = 1F;
            rowHeaderRenderer137.Name = "rowHeaderRenderer137";
            rowHeaderRenderer137.PictureZoomEffect = false;
            rowHeaderRenderer137.TextRotationAngle = 0D;
            rowHeaderRenderer137.ZoomFactor = 1F;
            rowHeaderRenderer138.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer138.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer138.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer138.Name = "rowHeaderRenderer138";
            rowHeaderRenderer138.PictureZoomEffect = false;
            rowHeaderRenderer138.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer138.TextRotationAngle = 0D;
            rowHeaderRenderer138.ZoomFactor = 1F;
            columnHeaderRenderer79.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer79.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer79.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer79.Name = "columnHeaderRenderer79";
            columnHeaderRenderer79.PictureZoomEffect = false;
            columnHeaderRenderer79.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer79.TextRotationAngle = 0D;
            columnHeaderRenderer79.ZoomFactor = 1F;
            rowHeaderRenderer139.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer139.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer139.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer139.Name = "rowHeaderRenderer139";
            rowHeaderRenderer139.PictureZoomEffect = false;
            rowHeaderRenderer139.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer139.TextRotationAngle = 0D;
            rowHeaderRenderer139.ZoomFactor = 1F;
            rowHeaderRenderer140.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer140.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer140.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer140.Name = "rowHeaderRenderer140";
            rowHeaderRenderer140.PictureZoomEffect = false;
            rowHeaderRenderer140.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer140.TextRotationAngle = 0D;
            rowHeaderRenderer140.ZoomFactor = 1F;
            columnHeaderRenderer80.Name = "columnHeaderRenderer80";
            columnHeaderRenderer80.PictureZoomEffect = false;
            columnHeaderRenderer80.TextRotationAngle = 0D;
            columnHeaderRenderer80.ZoomFactor = 1F;
            rowHeaderRenderer141.Name = "rowHeaderRenderer141";
            rowHeaderRenderer141.PictureZoomEffect = false;
            rowHeaderRenderer141.TextRotationAngle = 0D;
            rowHeaderRenderer141.ZoomFactor = 1F;
            rowHeaderRenderer142.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer142.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer142.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer142.Name = "rowHeaderRenderer142";
            rowHeaderRenderer142.PictureZoomEffect = false;
            rowHeaderRenderer142.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer142.TextRotationAngle = 0D;
            rowHeaderRenderer142.ZoomFactor = 1F;
            columnHeaderRenderer81.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer81.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer81.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer81.Name = "columnHeaderRenderer81";
            columnHeaderRenderer81.PictureZoomEffect = false;
            columnHeaderRenderer81.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer81.TextRotationAngle = 0D;
            columnHeaderRenderer81.ZoomFactor = 1F;
            rowHeaderRenderer143.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer143.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer143.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer143.Name = "rowHeaderRenderer143";
            rowHeaderRenderer143.PictureZoomEffect = false;
            rowHeaderRenderer143.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer143.TextRotationAngle = 0D;
            rowHeaderRenderer143.ZoomFactor = 1F;
            rowHeaderRenderer144.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer144.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer144.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer144.Name = "rowHeaderRenderer144";
            rowHeaderRenderer144.PictureZoomEffect = false;
            rowHeaderRenderer144.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer144.TextRotationAngle = 0D;
            rowHeaderRenderer144.ZoomFactor = 1F;
            columnHeaderRenderer82.Name = "columnHeaderRenderer82";
            columnHeaderRenderer82.PictureZoomEffect = false;
            columnHeaderRenderer82.TextRotationAngle = 0D;
            columnHeaderRenderer82.ZoomFactor = 1F;
            rowHeaderRenderer145.Name = "rowHeaderRenderer145";
            rowHeaderRenderer145.PictureZoomEffect = false;
            rowHeaderRenderer145.TextRotationAngle = 0D;
            rowHeaderRenderer145.ZoomFactor = 1F;
            rowHeaderRenderer146.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer146.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer146.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer146.Name = "rowHeaderRenderer146";
            rowHeaderRenderer146.PictureZoomEffect = false;
            rowHeaderRenderer146.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer146.TextRotationAngle = 0D;
            rowHeaderRenderer146.ZoomFactor = 1F;
            columnHeaderRenderer83.BackColor = System.Drawing.SystemColors.Control;
            columnHeaderRenderer83.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            columnHeaderRenderer83.ForeColor = System.Drawing.SystemColors.ControlText;
            columnHeaderRenderer83.Name = "columnHeaderRenderer83";
            columnHeaderRenderer83.PictureZoomEffect = false;
            columnHeaderRenderer83.RightToLeft = System.Windows.Forms.RightToLeft.No;
            columnHeaderRenderer83.TextRotationAngle = 0D;
            columnHeaderRenderer83.ZoomFactor = 1F;
            rowHeaderRenderer147.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer147.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer147.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer147.Name = "rowHeaderRenderer147";
            rowHeaderRenderer147.PictureZoomEffect = false;
            rowHeaderRenderer147.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer147.TextRotationAngle = 0D;
            rowHeaderRenderer147.ZoomFactor = 1F;
            rowHeaderRenderer148.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer148.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer148.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer148.Name = "rowHeaderRenderer148";
            rowHeaderRenderer148.PictureZoomEffect = false;
            rowHeaderRenderer148.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer148.TextRotationAngle = 0D;
            rowHeaderRenderer148.ZoomFactor = 1F;
            columnHeaderRenderer84.Name = "columnHeaderRenderer84";
            columnHeaderRenderer84.PictureZoomEffect = false;
            columnHeaderRenderer84.TextRotationAngle = 0D;
            columnHeaderRenderer84.ZoomFactor = 1F;
            rowHeaderRenderer149.Name = "rowHeaderRenderer149";
            rowHeaderRenderer149.PictureZoomEffect = false;
            rowHeaderRenderer149.TextRotationAngle = 0D;
            rowHeaderRenderer149.ZoomFactor = 1F;
            rowHeaderRenderer150.BackColor = System.Drawing.SystemColors.Control;
            rowHeaderRenderer150.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            rowHeaderRenderer150.ForeColor = System.Drawing.SystemColors.ControlText;
            rowHeaderRenderer150.Name = "rowHeaderRenderer150";
            rowHeaderRenderer150.PictureZoomEffect = false;
            rowHeaderRenderer150.RightToLeft = System.Windows.Forms.RightToLeft.No;
            rowHeaderRenderer150.TextRotationAngle = 0D;
            rowHeaderRenderer150.ZoomFactor = 1F;


            // 
            // spdOrderList
            // 
            this.spdOrderList.AccessibleDescription = "spdOrderList, Sheet1, Row 0, Column 0, ";
            this.spdOrderList.AllowColumnMove = true;
            this.spdOrderList.BackColor = System.Drawing.Color.Transparent;
            this.spdOrderList.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.spdOrderList.Dock = System.Windows.Forms.DockStyle.Fill;
            this.spdOrderList.FocusRenderer = defaultFocusIndicatorRenderer2;
            this.spdOrderList.HorizontalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdOrderList.HorizontalScrollBar.Name = "";
            this.spdOrderList.HorizontalScrollBar.Renderer = defaultScrollBarRenderer4;
            this.spdOrderList.HorizontalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            this.spdOrderList.Location = new System.Drawing.Point(1, 19);
            this.spdOrderList.Margin = new System.Windows.Forms.Padding(0, 0, 0, 5);
            this.spdOrderList.Name = "spdOrderList";
            namedStyle10.BackColor = System.Drawing.SystemColors.Control;
            filterBarCellType3.FormatString = "";
            namedStyle10.CellType = filterBarCellType3;
            namedStyle10.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle10.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle10.Locked = false;
            namedStyle10.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle10.NoteStyle = FarPoint.Win.Spread.NoteStyle.PopupNote;
            namedStyle10.Renderer = filterBarCellType3;
            namedStyle10.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle10.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle11.BackColor = System.Drawing.Color.Aqua;
            namedStyle11.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle11.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle11.Locked = false;
            namedStyle11.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle11.NoteStyle = FarPoint.Win.Spread.NoteStyle.PopupNote;
            namedStyle11.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle11.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle12.BackColor = System.Drawing.SystemColors.Window;
            namedStyle12.CellType = generalCellType4;
            namedStyle12.ForeColor = System.Drawing.SystemColors.WindowText;
            namedStyle12.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            namedStyle12.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle12.Renderer = generalCellType4;
            namedStyle12.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            namedStyle12.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle13.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            namedStyle13.Border = bevelBorder3;
            namedStyle13.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            namedStyle13.ForeColor = System.Drawing.Color.White;
            namedStyle13.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle13.Locked = false;
            namedStyle13.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle13.NoteStyle = FarPoint.Win.Spread.NoteStyle.PopupNote;
            namedStyle13.Renderer = generalCellType5;
            namedStyle13.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle13.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle14.BackColor = System.Drawing.SystemColors.Control;
            filterBarCellType4.FormatString = "";
            namedStyle14.CellType = filterBarCellType4;
            namedStyle14.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle14.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle14.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle14.Renderer = filterBarCellType4;
            namedStyle14.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle14.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle15.BackColor = System.Drawing.SystemColors.Control;
            namedStyle15.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle15.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle15.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle15.Renderer = columnHeaderRenderer84;
            namedStyle15.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle15.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle16.BackColor = System.Drawing.SystemColors.Control;
            namedStyle16.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            namedStyle16.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle16.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle16.Locked = false;
            namedStyle16.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle16.NoteStyle = FarPoint.Win.Spread.NoteStyle.PopupNote;
            namedStyle16.Renderer = rowHeaderRenderer150;
            namedStyle16.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle16.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle17.BackColor = System.Drawing.SystemColors.Control;
            namedStyle17.ForeColor = System.Drawing.SystemColors.ControlText;
            namedStyle17.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            namedStyle17.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle17.Renderer = rowHeaderRenderer149;
            namedStyle17.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            namedStyle17.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            namedStyle18.BackColor = System.Drawing.Color.White;
            namedStyle18.CellType = generalCellType6;
            namedStyle18.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            namedStyle18.ForeColor = System.Drawing.Color.Black;
            namedStyle18.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            namedStyle18.Locked = false;
            namedStyle18.NoteIndicatorColor = System.Drawing.Color.Red;
            namedStyle18.NoteStyle = FarPoint.Win.Spread.NoteStyle.PopupNote;
            namedStyle18.Renderer = generalCellType6;
            namedStyle18.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            namedStyle18.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            this.spdOrderList.NamedStyles.AddRange(new FarPoint.Win.Spread.NamedStyle[] {
            namedStyle10,
            namedStyle11,
            namedStyle12,
            namedStyle13,
            namedStyle14,
            namedStyle15,
            namedStyle16,
            namedStyle17,
            namedStyle18});
            this.spdOrderList.Sheets.AddRange(new FarPoint.Win.Spread.SheetView[] {
            this.spdOrderList_Sheet1});
            this.spdOrderList.Size = new System.Drawing.Size(917, 591);
            spreadSkin2.ColumnFooterDefaultStyle = namedStyle15;
            spreadSkin2.ColumnHeaderDefaultStyle = namedStyle13;
            spreadSkin2.CornerDefaultStyle = namedStyle17;
            spreadSkin2.DefaultStyle = namedStyle18;
            spreadSkin2.FilterBarDefaultStyle = namedStyle14;
            spreadSkin2.FilterBarHeaderDefaultStyle = namedStyle17;
            spreadSkin2.FocusRenderer = defaultFocusIndicatorRenderer2;
            spreadSkin2.Name = "AA";
            spreadSkin2.RowHeaderDefaultStyle = namedStyle16;
            spreadSkin2.ScrollBarRenderer = defaultScrollBarRenderer5;
            spreadSkin2.SelectionRenderer = new FarPoint.Win.Spread.DefaultSelectionRenderer();
            statusBarSkin2.BackColor = System.Drawing.SystemColors.Control;
            statusBarSkin2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F);
            statusBarSkin2.ForeColor = System.Drawing.SystemColors.ControlText;
            statusBarSkin2.Name = "Classic";
            statusBarSkin2.ZoomButtonHoverColor = System.Drawing.SystemColors.ButtonHighlight;
            statusBarSkin2.ZoomSliderColor = System.Drawing.SystemColors.ControlDarkDark;
            statusBarSkin2.ZoomSliderHoverColor = System.Drawing.SystemColors.ControlDark;
            statusBarSkin2.ZoomSliderTrackColor = System.Drawing.SystemColors.ControlDarkDark;
            spreadSkin2.StatusBarSkin = statusBarSkin2;
            this.spdOrderList.Skin = spreadSkin2;
            this.spdOrderList.TabIndex = 250;
            this.spdOrderList.TabStop = false;
            this.spdOrderList.VerticalScrollBar.Buttons = new FarPoint.Win.Spread.FpScrollBarButtonCollection("BackwardLineButton,ThumbTrack,ForwardLineButton");
            this.spdOrderList.VerticalScrollBar.Name = "";
            this.spdOrderList.VerticalScrollBar.Renderer = defaultScrollBarRenderer6;
            this.spdOrderList.VerticalScrollBarPolicy = FarPoint.Win.Spread.ScrollBarPolicy.AsNeeded;
            //  this.spdOrderList.EditModeStarting += new FarPoint.Win.Spread.EditModeStartingEventHandler(this.spdOrderList_EditModeStarting);
            //  this.spdOrderList.CellClick += new FarPoint.Win.Spread.CellClickEventHandler(this.spdOrderList_CellClick);
            //  this.spdOrderList.CellDoubleClick += new FarPoint.Win.Spread.CellClickEventHandler(this.spdOrderList_CellDoubleClick);
            //   this.spdOrderList.ButtonClicked += new FarPoint.Win.Spread.EditorNotifyEventHandler(this.spdOrderList_ButtonClicked);
            this.spdOrderList.SetViewportLeftColumn(0, 0, 9);
            // 
            // spdOrderList_Sheet1
            // 
            this.spdOrderList_Sheet1.Reset();
            this.spdOrderList_Sheet1.SheetName = "Sheet1";
            // Formulas and custom names must be loaded with R1C1 reference style
            this.spdOrderList_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.R1C1;
            this.spdOrderList_Sheet1.ColumnCount = 47;
            this.spdOrderList_Sheet1.RowCount = 1;
            this.spdOrderList_Sheet1.ActiveSkin = new FarPoint.Win.Spread.SheetSkin("CustomSkin1", System.Drawing.SystemColors.Control, System.Drawing.Color.Empty, System.Drawing.Color.Empty, System.Drawing.Color.LightGray, FarPoint.Win.Spread.GridLines.Both, System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155))))), System.Drawing.Color.Empty, System.Drawing.Color.White, System.Drawing.Color.Empty, System.Drawing.Color.Empty, System.Drawing.Color.Empty, System.Drawing.Color.Empty, System.Drawing.Color.Empty, false, false, false, false, false, true, false, true, "ColumnHeaderDefaultEnhanced", "ColumnHeaderDefaultEnhanced", "RowHeaderDefaultEnhanced", "DataAreaDefault", "CornerDefaultEnhanced");
            ((FarPoint.Win.Spread.CellFooter)(this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 8))).AggregationType = FarPoint.Win.Spread.Model.AggregationType.Sum;
            numberCellType1.DecimalPlaces = 5;
            this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 8).CellType = numberCellType1;
            this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 8).Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 8).Formula = "SUBTOTAL(9,Sheet1!C:C)";
            this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 8).Value = 0D;
            ((FarPoint.Win.Spread.CellFooter)(this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 9))).AggregationType = FarPoint.Win.Spread.Model.AggregationType.Sum;
            numberCellType2.DecimalPlaces = 5;
            numberCellType2.ShowSeparator = true;
            this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 9).CellType = numberCellType2;
            this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 9).Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 9).Formula = "SUBTOTAL(9,Sheet1!C:C)";
            this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 9).Value = 0D;
            ((FarPoint.Win.Spread.CellFooter)(this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 10))).AggregationType = FarPoint.Win.Spread.Model.AggregationType.Sum;
            numberCellType3.DecimalPlaces = 5;
            numberCellType3.ShowSeparator = true;
            this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 10).CellType = numberCellType3;
            this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 10).Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 10).Formula = "SUBTOTAL(9,Sheet1!C:C)";
            this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 10).Value = 0D;
            ((FarPoint.Win.Spread.CellFooter)(this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 11))).AggregationType = FarPoint.Win.Spread.Model.AggregationType.Sum;
            numberCellType4.DecimalPlaces = 5;
            numberCellType4.ShowSeparator = true;
            this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 11).CellType = numberCellType4;
            this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 11).Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 11).Formula = "SUBTOTAL(9,Sheet1!C:C)";
            this.spdOrderList_Sheet1.ColumnFooter.Cells.Get(0, 11).Value = 0D;
            this.spdOrderList_Sheet1.ColumnFooter.Columns.Default.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            this.spdOrderList_Sheet1.ColumnFooter.DefaultStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdOrderList_Sheet1.ColumnFooter.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdOrderList_Sheet1.ColumnFooter.DefaultStyle.Parent = "ColumnHeaderDefaultEnhanced";
            this.spdOrderList_Sheet1.ColumnFooter.DefaultStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdOrderList_Sheet1.ColumnFooter.DefaultStyle.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            this.spdOrderList_Sheet1.ColumnFooter.Rows.Default.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            this.spdOrderList_Sheet1.ColumnFooter.Visible = true;
            this.spdOrderList_Sheet1.ColumnFooterSheetCornerStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdOrderList_Sheet1.ColumnFooterSheetCornerStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdOrderList_Sheet1.ColumnFooterSheetCornerStyle.Parent = "CornerDefaultEnhanced";
            this.spdOrderList_Sheet1.ColumnFooterSheetCornerStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdOrderList_Sheet1.ColumnFooterSheetCornerStyle.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 0).CellType = checkBoxCellType3;
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 1).Value = "Pack Order ID";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 2).Value = "Line No";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 3).Value = "ERP Pack Order ID";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 4).Value = "Material ID";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 5).Value = "Material Version";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 6).Value = "Material Desc";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 7).Value = "Pack Order Date";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 8).Value = "Qty";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 9).Value = "Reg Qty";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 10).Value = "Packed Qty";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 11).Value = "Remain Qty";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 12).Value = "Stock Qty";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 13).Value = "Unit";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 14).Value = "Conv Unit Qty";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 15).Value = "Conv Stock Qty";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 16).Value = "Conv Unit";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 17).Value = "Order Status";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 18).Value = "Customer ID";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 19).Value = "Customer Site ID";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 20).Value = "Customer Name";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 21).Value = "Delivery ID";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 22).Value = "Delivery Name";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 23).Value = "Packing Instructions";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 24).Value = "CTM Stock Qty";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 25).Value = "Warehouse";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 26).Value = "Warehouse Desc";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 27).Value = "Drawing Flag";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 28).Value = "Order Type";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 29).Value = "Ship Req Date";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 30).Value = "Schedule Ship Date";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 31).Value = "Bare Input Date";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 32).Value = "Expect Ship Date";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 33).Value = "PO Gubun";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 34).Value = "Label Type";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 35).Value = "Label Mesh";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 36).Value = "Label Name";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 37).Value = "Include Inspection";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 38).Value = "Remark";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 39).Value = "3 Mon Avg";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 40).Value = "6 Mon AVG";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 41).Value = "PART NO";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 42).Value = "DRAW NO";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 43).Value = "DOC NO";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 44).Value = "DOC LINE NO";
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 45).ColumnSpan = 2;
            this.spdOrderList_Sheet1.ColumnHeader.Cells.Get(0, 45).Value = "Shipped History";
            this.spdOrderList_Sheet1.ColumnHeader.Columns.Default.VisualStyles = FarPoint.Win.VisualStyles.Off;
            this.spdOrderList_Sheet1.ColumnHeader.DefaultStyle.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            this.spdOrderList_Sheet1.ColumnHeader.DefaultStyle.ForeColor = System.Drawing.Color.White;
            this.spdOrderList_Sheet1.ColumnHeader.DefaultStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdOrderList_Sheet1.ColumnHeader.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdOrderList_Sheet1.ColumnHeader.DefaultStyle.Parent = "ColumnHeaderDefaultEnhanced";
            this.spdOrderList_Sheet1.ColumnHeader.DefaultStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdOrderList_Sheet1.ColumnHeader.DefaultStyle.VisualStyles = FarPoint.Win.VisualStyles.Off;
            this.spdOrderList_Sheet1.ColumnHeader.Rows.Default.VisualStyles = FarPoint.Win.VisualStyles.Off;
            this.spdOrderList_Sheet1.ColumnHeader.Rows.Get(0).Height = 25F;
            this.spdOrderList_Sheet1.Columns.Get(0).CellType = checkBoxCellType4;
            this.spdOrderList_Sheet1.Columns.Get(0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(0).Width = 30F;
            this.spdOrderList_Sheet1.Columns.Get(1).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(1).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(1).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(1).Label = "Pack Order ID";
            this.spdOrderList_Sheet1.Columns.Get(1).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(1).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(1).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(2).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(2).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(2).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdOrderList_Sheet1.Columns.Get(2).Label = "Line No";
            this.spdOrderList_Sheet1.Columns.Get(2).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(2).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(2).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(3).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(3).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(3).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(3).Label = "ERP Pack Order ID";
            this.spdOrderList_Sheet1.Columns.Get(3).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(3).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(3).Width = 203F;
            this.spdOrderList_Sheet1.Columns.Get(4).AllowAutoFilter = true;
            this.spdOrderList_Sheet1.Columns.Get(4).AllowAutoSort = true;
            generalCellType7.ReadOnly = true;
            this.spdOrderList_Sheet1.Columns.Get(4).CellType = generalCellType7;
            this.spdOrderList_Sheet1.Columns.Get(4).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(4).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(4).Label = "Material ID";
            this.spdOrderList_Sheet1.Columns.Get(4).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(4).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(4).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(5).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(5).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(5).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdOrderList_Sheet1.Columns.Get(5).Label = "Material Version";
            this.spdOrderList_Sheet1.Columns.Get(5).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(5).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(5).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(6).AllowAutoFilter = true;
            this.spdOrderList_Sheet1.Columns.Get(6).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(6).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(6).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(6).Label = "Material Desc";
            this.spdOrderList_Sheet1.Columns.Get(6).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(6).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(6).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(7).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(7).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(7).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(7).Label = "Pack Order Date";
            this.spdOrderList_Sheet1.Columns.Get(7).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(7).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(7).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(8).AllowAutoSort = true;
            numberCellType5.DecimalPlaces = 5;
            numberCellType5.ShowSeparator = true;
            this.spdOrderList_Sheet1.Columns.Get(8).CellType = numberCellType5;
            this.spdOrderList_Sheet1.Columns.Get(8).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(8).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdOrderList_Sheet1.Columns.Get(8).Label = "Qty";
            this.spdOrderList_Sheet1.Columns.Get(8).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(8).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(8).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(9).AllowAutoSort = true;
            numberCellType6.DecimalPlaces = 5;
            numberCellType6.ShowSeparator = true;
            this.spdOrderList_Sheet1.Columns.Get(9).CellType = numberCellType6;
            this.spdOrderList_Sheet1.Columns.Get(9).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(9).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdOrderList_Sheet1.Columns.Get(9).Label = "Reg Qty";
            this.spdOrderList_Sheet1.Columns.Get(9).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(9).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(9).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(10).AllowAutoSort = true;
            numberCellType7.DecimalPlaces = 5;
            numberCellType7.ShowSeparator = true;
            this.spdOrderList_Sheet1.Columns.Get(10).CellType = numberCellType7;
            this.spdOrderList_Sheet1.Columns.Get(10).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(10).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdOrderList_Sheet1.Columns.Get(10).Label = "Packed Qty";
            this.spdOrderList_Sheet1.Columns.Get(10).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(10).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(10).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(11).AllowAutoSort = true;
            numberCellType8.DecimalPlaces = 5;
            numberCellType8.ShowSeparator = true;
            this.spdOrderList_Sheet1.Columns.Get(11).CellType = numberCellType8;
            this.spdOrderList_Sheet1.Columns.Get(11).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(11).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdOrderList_Sheet1.Columns.Get(11).Label = "Remain Qty";
            this.spdOrderList_Sheet1.Columns.Get(11).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(11).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(11).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(12).AllowAutoSort = true;
            numberCellType9.DecimalPlaces = 5;
            numberCellType9.ShowSeparator = true;
            this.spdOrderList_Sheet1.Columns.Get(12).CellType = numberCellType9;
            this.spdOrderList_Sheet1.Columns.Get(12).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(12).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdOrderList_Sheet1.Columns.Get(12).Label = "Stock Qty";
            this.spdOrderList_Sheet1.Columns.Get(12).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(12).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(12).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(13).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(13).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(13).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(13).Label = "Unit";
            this.spdOrderList_Sheet1.Columns.Get(13).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(13).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(13).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(14).AllowAutoSort = true;
            numberCellType10.DecimalPlaces = 5;
            this.spdOrderList_Sheet1.Columns.Get(14).CellType = numberCellType10;
            this.spdOrderList_Sheet1.Columns.Get(14).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F);
            this.spdOrderList_Sheet1.Columns.Get(14).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdOrderList_Sheet1.Columns.Get(14).Label = "Conv Unit Qty";
            this.spdOrderList_Sheet1.Columns.Get(14).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(14).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(14).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(15).AllowAutoSort = true;
            numberCellType11.DecimalPlaces = 5;
            this.spdOrderList_Sheet1.Columns.Get(15).CellType = numberCellType11;
            this.spdOrderList_Sheet1.Columns.Get(15).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F);
            this.spdOrderList_Sheet1.Columns.Get(15).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdOrderList_Sheet1.Columns.Get(15).Label = "Conv Stock Qty";
            this.spdOrderList_Sheet1.Columns.Get(15).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(15).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(15).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(16).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(16).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F);
            this.spdOrderList_Sheet1.Columns.Get(16).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(16).Label = "Conv Unit";
            this.spdOrderList_Sheet1.Columns.Get(16).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(16).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(16).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(17).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(17).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(17).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(17).Label = "Order Status";
            this.spdOrderList_Sheet1.Columns.Get(17).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(17).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(17).Width = 183F;
            this.spdOrderList_Sheet1.Columns.Get(18).AllowAutoFilter = true;
            this.spdOrderList_Sheet1.Columns.Get(18).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(18).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(18).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(18).Label = "Customer ID";
            this.spdOrderList_Sheet1.Columns.Get(18).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(18).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(18).Width = 201F;
            this.spdOrderList_Sheet1.Columns.Get(19).AllowAutoFilter = true;
            this.spdOrderList_Sheet1.Columns.Get(19).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(19).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(19).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(19).Label = "Customer Site ID";
            this.spdOrderList_Sheet1.Columns.Get(19).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(19).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(19).Width = 211F;
            this.spdOrderList_Sheet1.Columns.Get(20).AllowAutoFilter = true;
            this.spdOrderList_Sheet1.Columns.Get(20).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(20).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(20).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(20).Label = "Customer Name";
            this.spdOrderList_Sheet1.Columns.Get(20).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(20).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(20).Width = 218F;
            this.spdOrderList_Sheet1.Columns.Get(21).AllowAutoFilter = true;
            this.spdOrderList_Sheet1.Columns.Get(21).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(21).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(21).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(21).Label = "Delivery ID";
            this.spdOrderList_Sheet1.Columns.Get(21).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(21).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(21).Width = 188F;
            this.spdOrderList_Sheet1.Columns.Get(22).AllowAutoFilter = true;
            this.spdOrderList_Sheet1.Columns.Get(22).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(22).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(22).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(22).Label = "Delivery Name";
            this.spdOrderList_Sheet1.Columns.Get(22).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(22).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(22).Width = 219F;
            this.spdOrderList_Sheet1.Columns.Get(23).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(23).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(23).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(23).Label = "Packing Instructions";
            this.spdOrderList_Sheet1.Columns.Get(23).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(23).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(23).Width = 170F;
            this.spdOrderList_Sheet1.Columns.Get(24).AllowAutoSort = true;
            numberCellType12.DecimalPlaces = 5;
            this.spdOrderList_Sheet1.Columns.Get(24).CellType = numberCellType12;
            this.spdOrderList_Sheet1.Columns.Get(24).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F);
            this.spdOrderList_Sheet1.Columns.Get(24).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Right;
            this.spdOrderList_Sheet1.Columns.Get(24).Label = "CTM Stock Qty";
            this.spdOrderList_Sheet1.Columns.Get(24).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(24).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(24).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(25).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(25).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(25).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(25).Label = "Warehouse";
            this.spdOrderList_Sheet1.Columns.Get(25).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(25).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(25).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(26).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(26).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(26).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(26).Label = "Warehouse Desc";
            this.spdOrderList_Sheet1.Columns.Get(26).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(26).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(26).Width = 179F;
            this.spdOrderList_Sheet1.Columns.Get(27).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(27).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(27).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(27).Label = "Drawing Flag";
            this.spdOrderList_Sheet1.Columns.Get(27).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(27).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(27).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(28).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(28).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(28).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(28).Label = "Order Type";
            this.spdOrderList_Sheet1.Columns.Get(28).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(28).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(28).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(29).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(29).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(29).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(29).Label = "Ship Req Date";
            this.spdOrderList_Sheet1.Columns.Get(29).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(29).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(29).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(30).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(30).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(30).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(30).Label = "Schedule Ship Date";
            this.spdOrderList_Sheet1.Columns.Get(30).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(30).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(30).Width = 192F;
            this.spdOrderList_Sheet1.Columns.Get(31).AllowAutoSort = true;
            dateTimeCellType1.Calendar = new System.Globalization.GregorianCalendar(System.Globalization.GregorianCalendarTypes.Localized);
            dateTimeCellType1.CalendarSurroundingDaysColor = System.Drawing.SystemColors.GrayText;
            dateTimeCellType1.DropDownButton = true;
            dateTimeCellType1.MaximumTime = System.TimeSpan.Parse("23:59:59.9999999");
            dateTimeCellType1.TimeDefault = new System.DateTime(2023, 10, 25, 9, 45, 40, 0);
            this.spdOrderList_Sheet1.Columns.Get(31).CellType = dateTimeCellType1;
            this.spdOrderList_Sheet1.Columns.Get(31).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(31).Label = "Bare Input Date";
            this.spdOrderList_Sheet1.Columns.Get(31).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(31).Width = 145F;
            this.spdOrderList_Sheet1.Columns.Get(32).AllowAutoSort = true;
            dateTimeCellType2.Calendar = new System.Globalization.GregorianCalendar(System.Globalization.GregorianCalendarTypes.Localized);
            dateTimeCellType2.CalendarSurroundingDaysColor = System.Drawing.SystemColors.GrayText;
            dateTimeCellType2.DropDownButton = true;
            dateTimeCellType2.MaximumTime = System.TimeSpan.Parse("23:59:59.9999999");
            dateTimeCellType2.TimeDefault = new System.DateTime(2023, 10, 25, 14, 40, 37, 0);
            this.spdOrderList_Sheet1.Columns.Get(32).CellType = dateTimeCellType2;
            this.spdOrderList_Sheet1.Columns.Get(32).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F);
            this.spdOrderList_Sheet1.Columns.Get(32).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(32).Label = "Expect Ship Date";
            this.spdOrderList_Sheet1.Columns.Get(32).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(32).Width = 208F;
            this.spdOrderList_Sheet1.Columns.Get(33).AllowAutoFilter = true;
            this.spdOrderList_Sheet1.Columns.Get(33).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(33).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(33).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(33).Label = "PO Gubun";
            this.spdOrderList_Sheet1.Columns.Get(33).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(33).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(33).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(34).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(34).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(34).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(34).Label = "Label Type";
            this.spdOrderList_Sheet1.Columns.Get(34).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(34).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(34).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(35).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(35).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(35).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(35).Label = "Label Mesh";
            this.spdOrderList_Sheet1.Columns.Get(35).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(35).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(35).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(36).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(36).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(36).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(36).Label = "Label Name";
            this.spdOrderList_Sheet1.Columns.Get(36).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(36).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(36).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(37).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(37).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.spdOrderList_Sheet1.Columns.Get(37).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(37).Label = "Include Inspection";
            this.spdOrderList_Sheet1.Columns.Get(37).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(37).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(37).Width = 179F;
            this.spdOrderList_Sheet1.Columns.Get(38).AllowAutoSort = true;
            this.spdOrderList_Sheet1.Columns.Get(38).Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F);
            this.spdOrderList_Sheet1.Columns.Get(38).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
            this.spdOrderList_Sheet1.Columns.Get(38).Label = "Remark";
            this.spdOrderList_Sheet1.Columns.Get(38).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
            this.spdOrderList_Sheet1.Columns.Get(38).Width = 141F;
            this.spdOrderList_Sheet1.Columns.Get(39).Label = "3 Mon Avg";
            this.spdOrderList_Sheet1.Columns.Get(39).Width = 93F;
            this.spdOrderList_Sheet1.Columns.Get(40).Label = "6 Mon AVG";
            this.spdOrderList_Sheet1.Columns.Get(40).Width = 124F;
            this.spdOrderList_Sheet1.Columns.Get(41).Label = "PART NO";
            this.spdOrderList_Sheet1.Columns.Get(41).Width = 97F;
            this.spdOrderList_Sheet1.Columns.Get(42).Label = "DRAW NO";
            this.spdOrderList_Sheet1.Columns.Get(42).Width = 88F;
            this.spdOrderList_Sheet1.Columns.Get(43).Label = "DOC NO";
            this.spdOrderList_Sheet1.Columns.Get(43).Width = 74F;
            this.spdOrderList_Sheet1.Columns.Get(44).Label = "DOC LINE NO";
            this.spdOrderList_Sheet1.Columns.Get(44).Width = 110F;
            this.spdOrderList_Sheet1.Columns.Get(45).Label = "Shipped History";
            this.spdOrderList_Sheet1.Columns.Get(45).Locked = true;
            this.spdOrderList_Sheet1.Columns.Get(45).Width = 600F;
            buttonCellType1.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
            buttonCellType1.Text = "...";
            this.spdOrderList_Sheet1.Columns.Get(46).CellType = buttonCellType1;
            this.spdOrderList_Sheet1.Columns.Get(46).Width = 26F;
            this.spdOrderList_Sheet1.EnhancedFilterSortingMode = FarPoint.Win.Spread.EnhancedFilterSortingMode.Text;
            this.spdOrderList_Sheet1.FilterBar.DefaultStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdOrderList_Sheet1.FilterBar.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdOrderList_Sheet1.FilterBar.DefaultStyle.Parent = "FilterBarDefaultEnhanced";
            this.spdOrderList_Sheet1.FilterBar.DefaultStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdOrderList_Sheet1.FilterBar.DefaultStyle.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            this.spdOrderList_Sheet1.FilterBarHeaderStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdOrderList_Sheet1.FilterBarHeaderStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdOrderList_Sheet1.FilterBarHeaderStyle.Parent = "RowHeaderDefaultEnhanced";
            this.spdOrderList_Sheet1.FilterBarHeaderStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdOrderList_Sheet1.FilterBarHeaderStyle.VisualStyles = FarPoint.Win.VisualStyles.Auto;
            this.spdOrderList_Sheet1.NullBackColor = System.Drawing.Color.White;
            this.spdOrderList_Sheet1.RowHeader.Columns.Default.Resizable = false;
            this.spdOrderList_Sheet1.RowHeader.Columns.Default.VisualStyles = FarPoint.Win.VisualStyles.Off;
            this.spdOrderList_Sheet1.RowHeader.DefaultStyle.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            this.spdOrderList_Sheet1.RowHeader.DefaultStyle.ForeColor = System.Drawing.Color.White;
            this.spdOrderList_Sheet1.RowHeader.DefaultStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdOrderList_Sheet1.RowHeader.DefaultStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdOrderList_Sheet1.RowHeader.DefaultStyle.Parent = "RowHeaderDefaultEnhanced";
            this.spdOrderList_Sheet1.RowHeader.DefaultStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdOrderList_Sheet1.RowHeader.DefaultStyle.VisualStyles = FarPoint.Win.VisualStyles.Off;
            this.spdOrderList_Sheet1.RowHeader.Rows.Default.VisualStyles = FarPoint.Win.VisualStyles.Off;
            this.spdOrderList_Sheet1.RowHeader.Visible = false;
            this.spdOrderList_Sheet1.Rows.Default.Height = 30F;
            this.spdOrderList_Sheet1.Rows.Get(0).LockBackColor = System.Drawing.Color.White;
            this.spdOrderList_Sheet1.SheetCornerStyle.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(14)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
            this.spdOrderList_Sheet1.SheetCornerStyle.ForeColor = System.Drawing.Color.White;
            this.spdOrderList_Sheet1.SheetCornerStyle.HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.General;
            this.spdOrderList_Sheet1.SheetCornerStyle.NoteIndicatorColor = System.Drawing.Color.Red;
            this.spdOrderList_Sheet1.SheetCornerStyle.Parent = "CornerDefaultEnhanced";
            this.spdOrderList_Sheet1.SheetCornerStyle.VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.General;
            this.spdOrderList_Sheet1.SheetCornerStyle.VisualStyles = FarPoint.Win.VisualStyles.Off;
            this.spdOrderList_Sheet1.ShowRowSelector = true;
            this.spdOrderList_Sheet1.ReferenceStyle = FarPoint.Win.Spread.Model.ReferenceStyle.A1;





        }

        private void btnlayoutSave_Click(object sender, EventArgs e)
        {
            string sHeader = "";

            if (spdOrderList_Sheet1.RowCount == 0)
            {
                return;
            }

            for (int iCol = 1; iCol < spdOrderList_Sheet1.ColumnCount; iCol++)
            {


                if (spdOrderList_Sheet1.Columns[iCol].Visible == true && spdOrderList_Sheet1.Columns[iCol].Width > 0)
                {

                    if (sHeader == "")
                    {
                        sHeader = spdOrderList_Sheet1.Columns[iCol].Tag.ToString();
                    }
                    else
                    {
                        sHeader = sHeader + ";" + spdOrderList_Sheet1.Columns[iCol].Tag.ToString();
                    }
                }

                //  spdOrderList_Sheet1.GetColumnFromTag(iCol, 1);
            }

            MPCF.SaveRegSetting(System.Windows.Forms.Application.ProductName, this.Name, "Header", sHeader);

            MPCF.ShowMsgBox("저장하였습니다.(Save Completed)");

        }

        private void layoutchange(out string[] Headers)
        {

            string sRegHeader = MPCF.GetRegSetting(System.Windows.Forms.Application.ProductName, this.Name, "Header");
            string[] sHeaderList = sRegHeader.Split(';');
            Headers = sHeaderList;


            /*
            foreach (var word in sHeaderList)
            {

          
                //System.Console.WriteLine($"<{word}>");
            }
            */

        }

        private void spdOrderList_ColumnDragMove(object sender, DragMoveEventArgs e)
        {
            if (e.Index == 1)
            {
                return;
            }
        }

        private void chkNowOnly_CheckedChanged(object sender, EventArgs e)
        {
            if (chkNowOnly.Checked == true)
            {
                dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                dtpDate.Enabled = false;
            }
            else
            {
                dtpDate.Enabled = true;
            }
        }
    }
    #endregion




}
