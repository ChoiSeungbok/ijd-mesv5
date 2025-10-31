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

namespace CUS_SHP
{
    public partial class frmViewPackingOrderList_2 : CUS_COM.frmViewForm01
    {
        public frmViewPackingOrderList_2()
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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[16];
                DataTable dt = null;
                string sSql = "";
                string sViewID = "";
                List<string> ItemList1 = new List<string>();
                List<string> ItemList2 = new List<string>();

                string sSqlText = "";
                string sGradeList_1 = "";
                string sGradeList_2 = "";
                string sGradeList_3 = "";
                string sGradeList_4 = "";
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

                sViewID = "CSHP3004-006";
                dvcArgu[8].sCondition_ID = "ITEM_LIST1";
                dvcArgu[8].sCondition_Value = "";

                dvcArgu[9].sCondition_ID = "ITEM_LIST2";
                dvcArgu[9].sCondition_Value = "";



                dvcArgu[10].sCondition_ID = "MAT_DESC";
                dvcArgu[10].sCondition_Value = txtMatDesc.Text;

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
                                sSqlText = sSqlText +  ") ";
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
                            sSqlText = sSqlText +  " AND 1=1";
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
                            sSqlText = sSqlText +  " AND  SUBSTR(ORD.MAT_ID,2,4) IN(''" + sGradeList_1 + ")";
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
                    dvcArgu[13].sCondition_Value ="AND 1=1";
                }
                else
                {
                    dvcArgu[13].sCondition_Value = sSqlText;
                }




                dvcArgu[14].sCondition_ID = "CUSTOMER_NAME";
                dvcArgu[14].sCondition_Value = txtCustomerName.Text;


                dvcArgu[15].sCondition_ID = "DELIVERY_NAME";
                dvcArgu[15].sCondition_Value = txtDeliveryName.Text;






                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
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

                    if (i == 0) SetSheetConvertColumn(dt.Rows[i]["CONV_FLAG"].ToString());

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
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.SHIPPED_HISTROY].Value = dt.Rows[i]["SHIPPED_HISTROY"];



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
                    spdOrderList_Sheet1.Columns.Get((int)PACK_ORDER.SIX_MONTH).Visible = true;
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

                return;
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
                DataTable dt = null;
                DataRow dr;
                //  DataColumn dc;

                ;
                dt = new DataTable("DataTable");
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
        private void sheetHidden(string sSheachType)
        {
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
                DataTable dt = null;
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
        private void frmViewPackingOrderList_2_Load(object sender, EventArgs e)
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
                    this.txtCustomerName.Text= popup.g_CustomerDesc;
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

        private void spdOrderList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (spdOrderList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdOrderList, e.Row, e.Column, true, true, false);
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
                EXTFUC.SaveExcel(spdOrderList, "PackOrderList");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
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
            try {

            
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
            SheetView sv = spdOrderList.ActiveSheet;

            if (e.Column == (int)PACK_ORDER.SHIPPED_HISTROY_BTN)
            {

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

            }
        }

        #endregion

    }





}
