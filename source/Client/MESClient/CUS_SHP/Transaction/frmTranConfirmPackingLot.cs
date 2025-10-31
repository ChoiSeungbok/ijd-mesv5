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
    public partial class frmTranConfirmPackingLot : CUS_COM.frmTranForm01
    {
        public frmTranConfirmPackingLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum PACK_ORDER
        {
            PACK_ORDER_ID,         // 1 : 포장 지시 번호
            LINE_NO,               // 2 : 포장 라인 번호        
            MAT_DESC,              // 3 : 제품명
            PACK_ORD_DATE,         // 4 : 포장지시일자
            QTY,                   // 5 : 포장수량
            REG_QTY,               // 6 : 등록 수량
            PACKED_QTY,            // 7 : 포장된 수량
            CUSTOMER_NAME,         // 8 : 고객사명
            DELIVERY_NAME,         // 9 : 최종 납품처명
            ERP_PACK_ORDER_ID,     // 10 : ERP 포장 지시 번호
            UNIT,                  // 11 : 단위
            PACK_ORD_STATUS,       // 12 : 포장상태            
            MAT_ID,                // 13 : 제품
            MAT_VER,               // 14 : 버전            
            CUSTOMER_ID,           // 15 : 고객사
            CUSTOMER_SITE_ID,      // 16 : 고객사 SITE ID           
            DELIVERY_ID,           // 17 : 납품처 ID            
            PACKING_INSTRUCTIONS,  // 18 : 용기
            OPER,                  // 19 : 창고
            OPER_DESC,             // 20 : 창고명
            DRAWING_FLAG,          // 21 : 도면유무
            ORDER_TYPE,            // 22 : 주문유형
            REQUEST_DATE,          // 23 : 출하요청일 
            SCHEDULE_SHIP_DATE,    // 24 : 출하예정일
            PO_GUBUN,              // 25 : 발주구분
            LABEL_TYPE,            // 26 : 라벨 유형
            LABEL_MESH,            // 27 : 라벨 사이즈 
            LABEL_NAME,            // 28 : 라벨품명
            INCLUDE_INSPECTION     // 29 : 검사 성적서 포함 여부
        }

        private enum PACK_LOT
        {
            CHK,                     // 1 : CHECK
            ORG_LOT_ID,              // 2 : 공정 LOT ID
            PACK_LOT_ID,             // 3 : 포장 LOT ID
            SEQ,                     // 4 : 순번
            MAT_DESC,                // 5 : 제품명
            QTY,                     // 6 : 수량           
            CMF_1,                   // 7 : 코팅 퍼센트(GRT 전용)
            PACKING_INSTRUCTIONS,    // 8 : 용기
            DRAWING_FLAG,            // 9 : 도면유무
            PACK_ORDER_ID,           // 10 : 포장 지시 번호
            PACK_LINE_NO,            // 11 : 포장 라인 번호
            EXPECT_SHIP_DATE,        // 12 : 출하예정일
            MAT_ID,                  // 13 : 제품
            MAT_VER,                 // 14 : 버전
            UNIT,                    // 15 : 단위
            ERP_PACK_ORDER_ID,       // 16 : ERP 포장 지시 번호            
            PACK_FLAG,               // 17 : 포장 여부
            SHIP_FLAG,               // 18 : 출하 여부
            PDA_CHK_FLAG,            // GRIT 전용 PDA로 LOT검증했는지여부
            BOX_ID,                  // 19: 박스 ID
            FINAL_BOX_ID,            // 20 : 최종 박스 ID
            CMF_2,                   // 21 : 검사 LOT ID 
        }


        #endregion

        #region " Variable Definition "
        string packOrderId = "";
        string packLineNo = "";
        string packingInstructions = "";
        string drawingFlag = "";
        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                lblLableSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                cdvLabelSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnCancel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //Packing Order LIST 조회 함수
        private void ViewPackingOrderList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[10];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                string sViewID = "CSHP2011-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatID.Text.Trim();

                dvcArgu[3].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[3].sCondition_Value = txtPackingOrderNo.Text.Trim();

                dvcArgu[4].sCondition_ID = "CUSTOMER_ID";
                dvcArgu[4].sCondition_Value = cdvCustomerID.Text.Trim();

                dvcArgu[5].sCondition_ID = "FROM_DATE";
                dvcArgu[5].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));

                dvcArgu[6].sCondition_ID = "TO_DATE";
                dvcArgu[6].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";



                dvcArgu[7].sCondition_ID = "PACK_FLAG";
                dvcArgu[7].sCondition_Value = string.IsNullOrEmpty(cdvPackFlag.Text) ? "WAIT" : (cdvPackFlag.Text.Trim() == "Y" ? "%" : "WAIT");



                dvcArgu[8].sCondition_ID = "ERP_PACK_ORDER_ID";
                dvcArgu[8].sCondition_Value = txtErpPackingOrderNo.Text.Trim();

                dvcArgu[9].sCondition_ID = "ORG_LOT_ID";
                dvcArgu[9].sCondition_Value = txtOrgLotId.Text.Trim();


                if (cdvPackFlag.Text.Trim() == "Y")
                    sViewID = "CSHP2001-007";

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
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORD_STATUS].Value = dt.Rows[i]["PACK_ORD_STATUS"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CUSTOMER_ID].Value = dt.Rows[i]["CUSTOMER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CUSTOMER_SITE_ID].Value = dt.Rows[i]["CUSTOMER_SITE_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CUSTOMER_NAME].Value = dt.Rows[i]["CUSTOMER_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DELIVERY_ID].Value = dt.Rows[i]["DELIVERY_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DELIVERY_NAME].Value = dt.Rows[i]["DELIVERY_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACKING_INSTRUCTIONS].Value = dt.Rows[i]["PACKING_INSTRUCTIONS"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.OPER].Value = dt.Rows[i]["OPER"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DRAWING_FLAG].Value = dt.Rows[i]["DRAWING_FLAG"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.ORDER_TYPE].Value = dt.Rows[i]["ORDER_TYPE"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.REQUEST_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["REQUEST_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.SCHEDULE_SHIP_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["SCHEDULE_SHIP_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PO_GUBUN].Value = dt.Rows[i]["PO_GUBUN"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LABEL_TYPE].Value = dt.Rows[i]["LABEL_TYPE"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LABEL_MESH].Value = dt.Rows[i]["LABEL_MESH"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.INCLUDE_INSPECTION].Value = dt.Rows[i]["INCLUDE_INSPECTION"];




                    if (packOrderId == spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORDER_ID].Value.ToString().Trim()
                           && packLineNo == spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LINE_NO].Value.ToString().Trim())
                    {
                        EXTFUC.SetSelectSheet(spdOrderList, i);
                    }

                }
                // MPCF.FitColumnHeader(spdOrderList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //PACKING LOT LIST 조회 함수
        private void ViewPackingLotList(string packOrderId, string packLineNo)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                double dSumQty = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[1].sCondition_Value = packOrderId;

                dvcArgu[2].sCondition_ID = "PACK_LINE_NO";
                dvcArgu[2].sCondition_Value = packLineNo;

                dvcArgu[3].sCondition_ID = "PACK_FLAG";
                dvcArgu[3].sCondition_Value = cdvPackFlag.Text;

                dvcArgu[4].sCondition_ID = "FROM_DATE";
                dvcArgu[4].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", "")); ;

                dvcArgu[5].sCondition_ID = "TO_DATE";
                dvcArgu[5].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";


                if (TPDR.GetDataOne("", ref dt, "CSHP2001-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdPackingLotList);
                    return;
                }

                MPCF.ClearList(spdPackingLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdPackingLotList_Sheet1.RowCount++;

                    spdPackingLotList_Sheet1.SetValue(i, (int)PACK_LOT.CHK, false);
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SEQ].Value = dt.Rows[i]["SEQ"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CMF_1].Value = dt.Rows[i]["CMF_1"]; //GRT 전용 COATING PERCENT
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_FLAG].Value = dt.Rows[i]["PACK_FLAG"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LINE_NO].Value = dt.Rows[i]["PACK_LINE_NO"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.EXPECT_SHIP_DATE].Value = dt.Rows[i]["EXPECT_SHIP_DATE"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ERP_PACK_ORDER_ID].Value = dt.Rows[i]["CMF_5"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_FLAG].Value = dt.Rows[i]["SHIP_FLAG"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Value = dt.Rows[i]["BOX_ID_1"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Value = dt.Rows[i]["BOX_ID_2"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CMF_2].Value = dt.Rows[i]["CMF_2"]; //검사 LOT ID
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PDA_CHK_FLAG].Value = dt.Rows[i]["PDA_CHK_FLAG"]; // GRIT 전용 PDA로 LOT검증했는지여부

                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACKING_INSTRUCTIONS].Value = packingInstructions;
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.DRAWING_FLAG].Value = drawingFlag;
                }
                //MPCF.FitColumnHeader(spdPackingLotList);

                for (i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (cdvDept.Text == CSGV.gs_area_grit)  //GRT만 PDA체크 안한경우 빨간색으로 표기
                    {
                        if (spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.PDA_CHK_FLAG].Text != "Y")
                        {
                            spdPackingLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 0, 0);
                        }
                        else
                        {
                            spdPackingLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                        }
                    }
                    else
                    {
                        spdPackingLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                    }



                    dSumQty += MPCF.ToDbl(spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.QTY].Text);
                }

                spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //포장 정보 확정 취소
        private bool CancelConfirmPackInfo()
        {
            TRSNode in_node = new TRSNode("cancel_confirm_Pack_Info_In");
            TRSNode out_node = new TRSNode("cancel_confirm_Pack_Info_Out");
            TRSNode label_in_node = new TRSNode("print_label_In");
            TRSNode lot_list;
            TRSNode label_list;
            bool send_flag = false;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("PACK_ORDER_ID", spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)PACK_ORDER.PACK_ORDER_ID].Text);
                in_node.AddInt("LINE_NO", MPCF.ToInt(spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)PACK_ORDER.LINE_NO].Text));

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        //확정되지 않은 LOT 체크
                        if (!string.Equals(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_FLAG].Text, "Y"))
                        {
                            continue;
                        }

                        //이미 출하된 LOT 체크
                        if (string.Equals(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_FLAG].Text, "Y"))
                        {
                            continue;
                        }

                        lot_list = in_node.AddNode("PACK_LOT_LIST");
                        lot_list.AddString("ORG_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Text);
                        lot_list.AddString("PACK_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text);
                        lot_list.AddString("CMF_2", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CMF_2].Text);

                        send_flag = true;
                    }
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }


                if (MPCF.ShowMsgBox(MPCF.GetMessage(54), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                {
                    in_node.AddChar("PACK_LOT_DEL", 'N');
                }
                else
                {
                    in_node.AddChar("PACK_LOT_DEL", 'Y');
                }

                if (MPCR.CallService("CUS_SHP", "CUS_SHP_Confirm_Pack_Order", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);

                MPCR.SetInMsg(label_in_node);

                for (int i = 0; i < out_node.GetList(0).Count; i++)
                {
                    label_list = label_in_node.AddNode("LOT_LIST");
                    label_list.AddString("LOT_ID", out_node.GetList(0)[i].GetString("LOT_ID"));
                }

                if (out_node.GetList(0).Count > 0)
                {
                    ViewPrintLabel(cdvLabelSize.Text, label_in_node);
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //포장 정보 확정
        private bool ConfirmPackingLot()
        {
            TRSNode in_node = new TRSNode("confirm_packing_Lot_In");
            TRSNode out_node = new TRSNode("confirm_packing_Lot_Out");
            TRSNode lot_list;
            bool send_flag = false;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("PACK_ORDER_ID", spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)PACK_ORDER.PACK_ORDER_ID].Text);
                in_node.AddInt("LINE_NO", MPCF.ToInt(spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)PACK_ORDER.LINE_NO].Text));

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (string.Equals(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_FLAG].Text, "Y"))
                        {
                            continue;
                        }

                        lot_list = in_node.AddNode("PACK_LOT_LIST");
                        lot_list.AddString("ORG_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Text);
                        lot_list.AddString("PACK_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text);

                        send_flag = true;
                    }
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_SHP", "CUS_SHP_Confirm_Pack_Order", in_node, ref out_node) == false)
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

                switch (sType)
                {
                    case "CONFIRM":
                        if (spdOrderList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdPackingLotList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        break;

                    case "CANCEL":
                        if (spdOrderList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdPackingLotList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (MPCF.Trim(cdvLabelSize.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLableSize.Text + "]");
                            cdvLabelSize.Focus();
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

                        MPCF.ClearList(spdOrderList);
                        MPCF.ClearList(spdPackingLotList);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;
                        packingInstructions = "";
                        drawingFlag = "";
                        break;

                    case "ALL":

                        MPCF.ClearList(spdOrderList);
                        MPCF.ClearList(spdPackingLotList);
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);

                        this.cdvDept.Text = "";
                        this.cdvMatID.Text = "";
                        this.cdvCustomerID.Text = "";
                        this.txtPackingOrderNo.Text = "";
                        this.cdvPackFlag.Text = "";
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;
                        packingInstructions = "";
                        drawingFlag = "";
                        break;

                    case "ORDER_CLICK_CELL":

                        MPCF.ClearList(spdPackingLotList);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;

                        break;
                }
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
                if (string.IsNullOrEmpty(sFileName))
                {
                    //라벨 파일 조회
                    TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                    DataTable dt = null;
                    string sSql = "";

                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                    dvcArgu[1].sCondition_ID = "KEY_1";
                    dvcArgu[1].sCondition_Value = cdvDept.Text;

                    if (TPDR.GetDataOne("", ref dt, "CSHP2001-010", dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt != null)
                            dt.Dispose();

                        GC.Collect();
                        return false;
                    }

                    sFileName = dt.Rows[0]["KEY_2"].ToString();
                }

                CSCF.ViewLabelList(sFileName, in_node, 'E');

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        #endregion

        #region " Event Definition"
        private void frmTranConfirmPackingLot_Load(object sender, EventArgs e)
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
        private void cdvMatID_ButtonPress(object sender, EventArgs e)
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
                    this.cdvMatID.Text = popup.sMat_id;
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
        private void cdvCustomerID_ButtonPress(object sender, EventArgs e)
        {
            //고객사 팝업으로 변경
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
        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("VIEW") == false)
                    return;

                ClearList("VIEW");

                ViewPackingOrderList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnCancel_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("CANCEL") == false)
                    return;

                if (CancelConfirmPackInfo())
                {
                    ClearList("VIEW");

                    // 주문지시 조회
                    ViewPackingOrderList();

                    // 포장 LOT 조회
                    ViewPackingLotList(packOrderId, packLineNo);
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
                if (CheckCondition("CONFIRM") == false)
                    return;

                if (ConfirmPackingLot())
                {
                    ClearList("VIEW");

                    // 주문지시 조회
                    ViewPackingOrderList();

                    // 포장 LOT 조회
                    ViewPackingLotList(packOrderId, packLineNo);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdOrderList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            ClearList("ORDER_CLICK_CELL");

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

                for (int i = 0; i < spdOrderList.ActiveSheet.RowCount; i++)
                {
                    spdOrderList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdOrderList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                packOrderId = spdOrderList.ActiveSheet.Cells[e.Row, (int)PACK_ORDER.PACK_ORDER_ID].Text;
                packLineNo = spdOrderList.ActiveSheet.Cells[e.Row, (int)PACK_ORDER.LINE_NO].Text;

                packingInstructions = spdOrderList.ActiveSheet.Cells[e.Row, (int)PACK_ORDER.PACKING_INSTRUCTIONS].Text;
                drawingFlag = spdOrderList.ActiveSheet.Cells[e.Row, (int)PACK_ORDER.DRAWING_FLAG].Text;

                // 포장 등록된 LOT 조회
                ViewPackingLotList(packOrderId, packLineNo);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdPackingLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdPackingLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdPackingLotList, e.Row, e.Column, true, true, false);
                }

                CheckCount();
            }
        }
        private void CheckCount()
        {
            double dSumQty = 0;
            int iCount = 0;

            try
            {
                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.QTY].Text);
                    }
                }

                spdPackingLotList_Sheet1.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = iCount;
                spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
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
        private void spdPackingLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            try
            {
                CheckCount();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdPackingLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                CheckCount();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvPackFlag_ButtonPress(object sender, EventArgs e)
        {
            //PACK FLAG 추가
            cdvPackFlag.Init();
            MPCF.InitListView(cdvPackFlag.GetListView);

            cdvPackFlag.Columns.Add("Flag", 30, HorizontalAlignment.Left);

            ListViewItem item = new ListViewItem("Y", 14);
            item.SubItems.Add("Y");
            cdvPackFlag.Items.Add(item);

            cdvPackFlag.InsertEmptyRow(0, 1);
        }
        private void cdvMatID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatID.DisplayText == "")
                cdvMatID.Text = "";
        }
        private void cdvCustomerID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvCustomerID.DisplayText == "")
                cdvCustomerID.Text = "";
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
        private void dtpFromWorkDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";
        }

        #endregion
    }
}
