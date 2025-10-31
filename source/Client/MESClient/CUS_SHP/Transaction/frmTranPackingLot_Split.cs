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
    public partial class frmTranPackingLot_Split : CUS_COM.frmTranForm01
    {
        public frmTranPackingLot_Split()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum PACK_ORDER
        {
            PACK_ORDER_ID,         // 1 : 포장 지시 번호
            LINE_NO,               // 2 : 포장 라인 번호           
            MAT_DESC ,             // 3 : 제품            
            PACK_ORD_DATE,         // 4 : 포장지시일자
            QTY,                   // 5 : 포장수량
            REG_QTY,               // 6 : 등록 수량
            PACKED_QTY,            // 7 : 포장된 수량
            REMAIN_QTY,            // 8 : 잔량
            UNIT,                  // 9 : 단위          
            ERP_PACK_ORDER_ID,     // 10 : ERP 포장 지시 번호
            CUSTOMER_NAME,         // 11 : 고객사명
            DELIVERY_NAME,         // 12 : 최종 납품처명
            CUSTOMER_ID,           // 13 : 고객사
            CUSTOMER_SITE_ID,      // 14 : 고객사 SITE ID            
            DELIVERY_ID,           // 15 : 납품처 ID            
            PACKING_INSTRUCTIONS,  // 16 : 용기
            DRAWING_FLAG,          // 17 : 도면유무
            MAT_ID,                // 18 : 제품명
            MAT_VER,               // 19 : 버전
            OPER,                  // 20: 창고
            OPER_DESC,             // 21 : 창고명                        
            ORDER_TYPE,            // 22 : 주문유형
            REQUEST_DATE,          // 23 : 출하요청일 
            SCHEDULE_SHIP_DATE,    // 24 : 출하예정일
            PO_GUBUN,              // 25 : 발주구분
            LABEL_TYPE,            // 26 : 라벨 유형
            LABEL_MESH,            // 27 : 라벨 사이즈 
            LABEL_NAME,            // 28 : 라벨품명
            INCLUDE_INSPECTION,    // 29 : 검사 성적서 포함 여부
            PACK_ORD_STATUS,       // 30 : 포장상태
        }

        private enum LOT
        {
            CHK,                   // 1 : 공정 LOT ID
            LOT_ID,                // 2 : 공정 LOT ID
            MAT_DESC,              // 3 : 제품명
            QTY,                   // 4 : 수량
            PACKED_QTY,            // 5 : 포장된 수량
            REMAIN_QTY,            // 6 : 포장 등록 가능 수량
            UNIT,                  // 7 : 단위
            PACKING_INSTRUCTIONS,  // 8 : 용기
            DRAWING_FLAG,          // 9 : 도면유무
            MAT_ID,                // 10 : 제품
            MAT_VER,               // 11 : 버전
            OPER,                  // 12 : 창고
            OPER_DESC,             // 13 : 창고명
            LAST_COMMENT           // 14 : 창고명
        }

        private enum PACK_LOT
        {
            CHK,                     // 1 : CHECK
            ORG_LOT_ID,              // 2 : 공정 LOT ID
            PACK_LOT_ID,             // 3 : 포장 LOT ID
            SEQ,                     // 4 : 순번
            MAT_ID,                  // 5 : 제품
            MAT_VER,                 // 6 : 버전
            MAT_DESC,                // 7 : 제품명
            QTY,                     // 8 : 수량
            UNIT,                    // 9 : 단위
            CMF_1,                   // 10 : 코팅 퍼센트(GRT 전용)
            PACK_FLAG,               // 11 : 포장 여부
            PACK_ORDER_ID,           // 12 : 포장 지시 번호
            PACK_LINE_NO,            // 13 : 포장 라인 번호
            ERP_PACK_ORDER_ID,       // 14 : ERP 포장 지시 번호
            SHIP_FLAG,               // 15 : 출하 여부
            BOX_ID,                  // 16 : 박스 ID
            FINAL_BOX_ID             // 17 : 최종 박스 ID
        }


        #endregion

        #region " Variable Definition "
        string matId = "";
        string matVer = "";
        string oper = "";
        string packOrderId = "";
        string packLineNo = "";
        string file_name = "";
        string s_Qty = "";
        string lotId = "";
        double pack_remain_qty = 0;
        string drawingFlag = "";
        string packingInstructions = "";
      
        #endregion

        #region " Function Definition "
        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                chkMeshDeleteFlag.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblLableSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                cdvLabelSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                //btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[9];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvPackOper.Text;

                dvcArgu[3].sCondition_ID = "MAT_ID";
                dvcArgu[3].sCondition_Value = cdvMatID.Text;
                
                dvcArgu[4].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[4].sCondition_Value = txtPackingOrderNo.Text;

                dvcArgu[5].sCondition_ID = "CUSTOMER_ID";
                dvcArgu[5].sCondition_Value = cdvCustomerID.Text;

                dvcArgu[6].sCondition_ID = "FROM_DATE";
                dvcArgu[6].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));

                dvcArgu[7].sCondition_ID = "TO_DATE";
                dvcArgu[7].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";

                dvcArgu[8].sCondition_ID = "ERP_PACK_ORDER_ID";
                dvcArgu[8].sCondition_Value = txtErpPackingOrderNo.Text.Trim();

                if (TPDR.GetDataOne("", ref dt, "CSHP2001-001", dvcArgu, false, false, ref sSql) == false)
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
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.REMAIN_QTY].Value = Convert.ToDouble(dt.Rows[i]["QTY"]) - Convert.ToDouble(dt.Rows[i]["REG_QTY"]);
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
        //LOT LIST 조회 함수
        private void ViewLotList(string matId, string matVer, string oper)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;
                
                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = matId;

                dvcArgu[2].sCondition_ID = "MAT_VER";
                dvcArgu[2].sCondition_Value = matVer;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = oper;

                if (TPDR.GetDataOne("", ref dt, "CSHP2001-011", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLotList);
                    return;
                }

                MPCF.ClearList(spdLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Sheet1.RowCount++;

                    spdLotList_Sheet1.SetValue(i, (int)LOT.CHK, false);
                    spdLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.PACKED_QTY].Value = dt.Rows[i]["PACKED_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.REMAIN_QTY].Value = (MPCF.ToDbl(dt.Rows[i]["QTY"]) - MPCF.ToDbl(dt.Rows[i]["PACKED_QTY"])).ToString();
                    spdLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.LAST_COMMENT].Value = dt.Rows[i]["LAST_COMMENT"];  

                    spdLotList_Sheet1.Cells[i, (int)LOT.DRAWING_FLAG].Value = drawingFlag;
                    spdLotList_Sheet1.Cells[i, (int)LOT.PACKING_INSTRUCTIONS].Value = packingInstructions;                    

                    if (lotId == spdLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Value.ToString().Trim()
                           && matId == spdLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Value.ToString().Trim()
                           && oper == spdLotList_Sheet1.Cells[i, (int)LOT.OPER].Value.ToString().Trim())
                    {
                        EXTFUC.SetSelectSheet(spdLotList, i);

                        SetRemainQty(i);
                    }

                }
                MPCF.FitColumnHeader(spdLotList);

                
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
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
        private DataTable ValidPackingLot(string lotId)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORG_LOT_ID";
                dvcArgu[1].sCondition_Value = lotId;

                if (TPDR.GetDataOne("", ref dt, "CSHP2001-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();
                    GC.Collect();
                }

                return dt;
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }
        private void AddRowLot(int iRow, DataRow dr)
        {
            spdPackingLotList_Sheet1.SetValue(iRow, (int)PACK_LOT.CHK, false);
            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.ORG_LOT_ID].Value = dr["ORG_LOT_ID"];
            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.PACK_LOT_ID].Value = dr["PACK_LOT_ID"];
            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.SEQ].Value = dr["SEQ"];
            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.MAT_ID].Value = dr["MAT_ID"];
            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.MAT_VER].Value = dr["MAT_VER"];
            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.MAT_DESC].Value = dr["MAT_DESC"];
            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.QTY].Value = dr["QTY"];
            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.UNIT].Value = dr["UNIT"];
            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.CMF_1].Value = dr["CMF_1"]; //GRT 전용 COATING PERCENT
            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.PACK_FLAG].Value = dr["PACK_FLAG"];
            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.PACK_ORDER_ID].Value = dr["PACK_ORDER_ID"];
            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.PACK_LINE_NO].Value = dr["PACK_LINE_NO"];
            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.ERP_PACK_ORDER_ID].Value = dr["CMF_5"];
            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.SHIP_FLAG].Value = dr["SHIP_FLAG"];
            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.BOX_ID].Value = dr["BOX_ID_1"];
            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.FINAL_BOX_ID].Value = dr["BOX_ID_2"];
        }
        //PACKING LOT LIST 조회 함수
        private void ViewPackingLotList(string lotId, bool bClear)
        {
            try
            {
                int i = 0;
                double dSumQty = 0;               

                DataTable dt = ValidPackingLot(lotId);
                SheetView sv = spdPackingLotList_Sheet1;
                if (bClear)
                {

                    MPCF.ClearList(spdPackingLotList);
                    for (i = 0; i < dt.Rows.Count; i++)
                    {
                        sv.RowCount++;
                        AddRowLot(i, dt.Rows[i]);
                    }
                }

                for (i = 0; i < sv.RowCount; i++)
                {
                    dSumQty += MPCF.ToDbl(sv.Cells[i, (int)PACK_LOT.QTY].Text);
                }
                sv.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        //포장 정보 생성
        private bool CreatePackingLot()
        {
            TRSNode in_node = new TRSNode("create_packing_Lot_In");
            TRSNode out_node = new TRSNode("create_packing_Lot_Out");
            TRSNode label_in_node = new TRSNode("print_label_In");
            TRSNode lot_list;
            TRSNode label_list;
            bool send_flag = false;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("PACK_ORDER_ID", spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)PACK_ORDER.PACK_ORDER_ID].Text);
                in_node.AddInt("LINE_NO", MPCF.ToInt(spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)PACK_ORDER.LINE_NO].Text));
                in_node.AddString("AREA_ID", cdvDept.Text);

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Text) != "")
                        {
                            continue;
                        }

                        lot_list = in_node.AddNode("PACK_LOT_LIST");
                        lot_list.AddString("ORG_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Text);
                        lot_list.AddString("PACK_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text);
                        lot_list.AddDouble("QTY", MPCF.ToDbl(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.QTY].Text));
                        lot_list.AddString("COATING_PERCENT", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CMF_1].Text);

                        send_flag = true;
                    }
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_SHP", "CUS_SHP_Create_Pack_Lot", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);

                MPCR.SetInMsg(label_in_node);
                label_in_node.AddChar("MESH_DELETE_FLAG", chkMeshDeleteFlag.Checked == true ? 'Y' : 'N');

                for (int i = 0; i < out_node.GetList(0).Count; i++)
                {
                    label_list = label_in_node.AddNode("PACK_LOT_LIST");
                    label_list.AddString("PACK_LOT_ID", out_node.GetList(0)[i].GetString("PACK_LOT_ID"));
                    label_list.AddString("ORG_LOT_ID", out_node.GetList(0)[i].GetString("ORG_LOT_ID"));
                }

                file_name = cdvLabelSize.Text;

                ViewPrintLabel(file_name, label_in_node);

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

                if (MPCF.Trim(cdvPackOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblPackOper.Text + "]");
                    cdvPackOper.Focus();
                    return false;
                }

                switch (sType)
                {
                    case "REGIST":
                        if (spdOrderList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdLotList.ActiveSheet.RowCount == 0)
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

                        if (MPCF.Trim(this.cdvLabelSize.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLableSize.Text + "]");
                            cdvLabelSize.Focus();
                            return false;
                        }

                        break;

                    case "DELETE":
                        if (spdOrderList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdLotList.ActiveSheet.RowCount == 0)
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

                    case "ADD":
                        if (MPCF.Trim(this.txtPackingQty.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblPackingQty.Text + "]");
                            txtPackingQty.Focus();
                            return false;
                        }

                        if (MPCF.Trim(this.txtLotSize.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotSize.Text + "]");
                            txtLotSize.Focus();
                            return false;
                        }

                        if (spdLotList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (pack_remain_qty < MPCF.ToDbl(this.txtPackingQty.Text))
                        {
                            //CMN496 INFO - 포장 수량이 초과되었습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(496));
                            return false;
                        }

                        if(MPCF.ToDbl(txtPackingQty.Text) < MPCF.ToDbl(txtLotSize.Text))
                        {
                            //CMN126 ERROR -입력한 값이 한계값을 넘었습니다.다른 수를 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(126) + " [" + lblLotSize.Text + "]");
                            txtLotSize.Focus();
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
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdPackingLotList);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;

                        s_Qty = "";
                        this.txtPackingQty.Text = "";
                        this.txtLotSize.Text = "";
                        pack_remain_qty = 0;
                        drawingFlag = "";
                        packingInstructions = "";

                        break;

                    case "ALL":

                        MPCF.ClearList(spdOrderList);
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdPackingLotList);
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;

                        this.cdvDept.Text = "";
                        this.cdvPackOper.Text = "";
                        this.cdvMatID.Text = "";
                        this.cdvCustomerID.Text = "";
                        this.txtErpPackingOrderNo.Text = "";
                        s_Qty = "";
                        this.txtPackingQty.Text = "";
                        this.txtLotSize.Text = "";
                        pack_remain_qty = 0;
                        chkMeshDeleteFlag.Checked = false;
                        drawingFlag = "";
                        packingInstructions = "";
                        break;

                    case "ORDER_CLICK_CELL":
                        
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdPackingLotList);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;

                        s_Qty = "";
                        this.txtPackingQty.Text = "";
                        this.txtLotSize.Text = "";
                        pack_remain_qty = 0;
                        break;

                    case "LOT_CLICK_CELL":

                        s_Qty = "";
                        this.txtPackingQty.Text = "";
                        this.txtLotSize.Text = "";
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;
                        break;
                    case "LOT_LIST":
                        MPCF.ClearList(spdPackingLotList);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;

                        //s_Qty = "";
                        //this.txtPackingQty.Text = "";
                        //this.txtLotSize.Text = "";
                        //pack_remain_qty = 0;
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
                CSCF.ViewLabelList(sFileName, in_node);
                
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        private bool SetRemainQty(int iLotRow)
        {
            try
            {
                int iOrderRow = spdOrderList.ActiveSheet.ActiveRowIndex;

                pack_remain_qty = MPCF.ToDbl(spdOrderList.ActiveSheet.Cells[iOrderRow, (int)PACK_ORDER.QTY].Text) - MPCF.ToDbl(spdOrderList.ActiveSheet.Cells[iOrderRow, (int)PACK_ORDER.REG_QTY].Text);

                // 공정 LOT 수량 - 포장된 LOT 수량
                s_Qty = (MPCF.ToDbl(spdLotList.ActiveSheet.Cells[iLotRow, (int)LOT.QTY].Text) - MPCF.ToDbl(spdLotList.ActiveSheet.Cells[iLotRow, (int)LOT.PACKED_QTY].Text)).ToString();

                if (MPCF.Trim(s_Qty) != "")
                {
                    if (pack_remain_qty < MPCF.ToDbl(s_Qty))
                    {
                        this.txtPackingQty.Text = pack_remain_qty.ToString();
                    }
                    else
                    {
                        this.txtPackingQty.Text = s_Qty;
                    }
                }
                return true;
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        #endregion

        #region " Event Definition"
        private void frmTranPackingLot_Split_Load(object sender, EventArgs e)
        {
            try
            {
                if (string.Equals(cdvDept.Text, CSGC.CP_AREA_GRT))
                {
                    lblCoatingPercent.Visible = true;
                    txtCoatingPercent.Visible = true;
                    txtCoatingPercent.Text = "";
                    pnlGCM.Visible = true;
                    pnlGCM2.Visible = true;
                }
                else
                {
                    lblCoatingPercent.Visible = false;
                    txtCoatingPercent.Visible = false;
                    txtCoatingPercent.Text = "";
                    pnlGCM.Visible = false;
                    pnlGCM2.Visible = false;
                }

                this.dtpToWorkDate.Value = DateTime.Now;
                this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);              
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
        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (string.Equals(cdvDept.Text, CSGC.CP_AREA_GRT))
                {
                    lblCoatingPercent.Visible = true;
                    txtCoatingPercent.Visible = true;
                    txtCoatingPercent.Text = "";
                    pnlGCM.Visible = true;
                    pnlGCM2.Visible = true;
                }
                else
                {
                    lblCoatingPercent.Visible = false;
                    txtCoatingPercent.Visible = false;
                    txtCoatingPercent.Text = "";
                    pnlGCM.Visible = false;
                    pnlGCM2.Visible = false;
                }
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
        private void cdvPackOper_ButtonPress(object sender, EventArgs e)
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

                cdvPackOper.Init();
                MPCF.InitListView(cdvPackOper.GetListView);
                cdvPackOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvPackOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvPackOper.SelectedSubItemIndex = 0;
                cdvPackOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvPackOper.GetListView, '6', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }

                cdvPackOper.InsertEmptyRow(0, 1);
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
        private void btnAdd_Click(object sender, EventArgs e)
        {
            //  int i_total_Qty = 0;
            // int i_lot_Qty = 0;
            //  int i_create_qty = 0;
            double i_total_Qty = 0;
            double i_lot_Qty = 0;
            double i_create_qty = 0;

            int beforeRowCount = 0;
            int currentRowCount = 0;
            int i_activeRow = 0;
            int i_lot_count = 0;

            try
            {
                if (CheckCondition("ADD") == false)
                    return;

                i_activeRow = spdLotList.ActiveSheet.ActiveRowIndex;

                beforeRowCount = spdPackingLotList_Sheet1.RowCount;

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if(string.Equals(spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT.LOT_ID].Text, spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Text))
                    {
                        i_create_qty += MPCF.ToInt(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.QTY].Text);
                    }
                }
                //Integer 에서 Double로 바꿈 왜 Interger로 했었는지는 모름.. 지금까지 소수점 출하가 없기는 했음.. 
                // 소수점 케이스가 생거서 Double로 바꿈.(24.01.26)


                //i_total_Qty = MPCF.ToDbl(this.txtPackingQty.Text);
                //i_lot_Qty = MPCF.ToDbl(this.txtLotSize.Text);

                i_total_Qty = Math.Round(MPCF.ToDbl(this.txtPackingQty.Text),5);
                i_lot_Qty = Math.Round(MPCF.ToDbl(this.txtLotSize.Text),5);
                //소수점 5자리 절삭.(업겠지만 혹시라도 반올림 시켜버리면, 수량보다 초가하는 경우수떔시)

                //i_lot_count = MPCF.ToInt(Math.Truncate((i_total_Qty / MPCF.ToDbl(this.txtLotSize.Text) * 100000) /100000));
                i_lot_count = MPCF.ToInt(i_total_Qty / MPCF.ToDbl(this.txtLotSize.Text));

        


                if (i_lot_count * i_lot_Qty < i_total_Qty)
                {
                    i_lot_count++;
                }

                if (i_total_Qty <= 0)
                {
                    //CMN126 ERROR -입력한 값이 한계값을 넘었습니다.다른 수를 입력해 주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(126) + " [" + lblPackingQty.Text + "]");
                    txtPackingQty.Focus();
                    return;
                }

                for (int i = 0; i < i_lot_count; i++)
                {
                    spdPackingLotList_Sheet1.RowCount++;

                    currentRowCount = spdPackingLotList_Sheet1.RowCount - 1;
                    spdPackingLotList_Sheet1.SetValue(currentRowCount, (int)PACK_LOT.CHK, true);
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACK_LOT.ORG_LOT_ID].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT.LOT_ID].Text;
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACK_LOT.PACK_LOT_ID].Value = "";
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACK_LOT.SEQ].Value = spdPackingLotList_Sheet1.RowCount;
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACK_LOT.MAT_ID].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT.MAT_ID].Text;
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACK_LOT.MAT_VER].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT.MAT_VER].Text;
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACK_LOT.MAT_DESC].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT.MAT_DESC].Text;

                    if (spdPackingLotList_Sheet1.RowCount == i_lot_count + beforeRowCount)
                    {
                        spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACK_LOT.QTY].Value = i_total_Qty.ToString();
                    }
                    else
                    {
                        spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACK_LOT.QTY].Value = i_lot_Qty.ToString();
                        i_total_Qty -= i_lot_Qty;
                    }

                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACK_LOT.UNIT].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT.UNIT].Text;
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACK_LOT.CMF_1].Value = txtCoatingPercent.Text;
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACK_LOT.PACK_FLAG].Value = "N";
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACK_LOT.PACK_ORDER_ID].Value = "";
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACK_LOT.PACK_LINE_NO].Value = "";
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACK_LOT.BOX_ID].Value = "";
                    spdPackingLotList_Sheet1.Cells[currentRowCount, (int)PACK_LOT.FINAL_BOX_ID].Value = "";

                }                              

                txtCoatingPercent.Text = "";

                CheckCount();
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
                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if(MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text) != "")
                        {
                            continue;
                        }

                        spdPackingLotList_Sheet1.RemoveRows(i, 1);
                        i--;
                    }
                }

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SEQ].Value = i + 1;
                }

                MPCF.FitColumnHeader(spdPackingLotList);

                CheckCount();
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
                if (CheckCondition("REGIST") == false)
                    return;

                if (CreatePackingLot())
                {                   
                 
                    ClearList("ORDER_CLICK_CELL");

                    //포장 지시 조회
                    ViewPackingOrderList();

                    // 포장 가능 LOT 조회
                    ViewLotList(matId, matVer, oper);

                    // 포장 진행 LOT 조회
                    ViewPackingLotList(lotId, true);
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
                matId = spdOrderList.ActiveSheet.Cells[e.Row, (int)PACK_ORDER.MAT_ID].Text;
                matVer = spdOrderList.ActiveSheet.Cells[e.Row, (int)PACK_ORDER.MAT_VER].Text;
                oper = cdvPackOper.Text;
                drawingFlag = spdOrderList.ActiveSheet.Cells[e.Row, (int)PACK_ORDER.DRAWING_FLAG].Text;
                packingInstructions = spdOrderList.ActiveSheet.Cells[e.Row, (int)PACK_ORDER.PACKING_INSTRUCTIONS].Text;
                pack_remain_qty = MPCF.ToDbl(spdOrderList.ActiveSheet.Cells[e.Row, (int)PACK_ORDER.QTY].Text) - MPCF.ToDbl(spdOrderList.ActiveSheet.Cells[e.Row, (int)PACK_ORDER.REG_QTY].Text);

                // 포장 가능 LOT 조회
                ViewLotList(matId, matVer, oper);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true || e.ColumnFooter == true || e.Row < 0)
                {
                    return;
                }
                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    spdLotList.ActiveSheet.SetValue(i, (int)LOT.CHK, false);
                    spdLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }
                spdLotList.ActiveSheet.Cells[e.Row, (int)LOT.CHK].Value = true;
                spdLotList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                lotId = spdLotList.ActiveSheet.Cells[e.Row, (int)LOT.LOT_ID].Text;

                ClearList("LOT_CLICK_CELL");

                // 남은포장 수량 :공정 LOT 수량 - 포장된 LOT 수량
                SetRemainQty(e.Row);

                // 포장된 LOT ID 
                if (e.Column == (int)LOT.CHK)
                    ViewPackingLotList(lotId, false); // 포장된 LOT ID 
                else
                    ViewPackingLotList(lotId, true);
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
        private void btnPrint_Click(object sender, EventArgs e)
        {
            try
            {
                bool b_label_flag = false;
                bool check_flag = false;      
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");

                MPCR.SetInMsg(in_node);
                in_node.AddChar("MESH_DELETE_FLAG", chkMeshDeleteFlag.Checked == true ? 'Y' : 'N');

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        check_flag = true;

                        if (MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Text) == "")
                        {
                            continue;
                        }

                        label_list = in_node.AddNode("PACK_LOT_LIST");
                        label_list.AddString("PACK_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text);
                        label_list.AddString("ORG_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Text);
                        b_label_flag = true;
                    }
                }

                if(check_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return;
                }

                if(b_label_flag == false)
                {
                    //CMN506 ERROR - 출하 라벨은 주문 지시를 가지고 있어야 출력이 가능합니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(506));
                    return;
                }

                file_name = cdvLabelSize.Text;

                ViewPrintLabel(file_name, in_node);
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
        private void btnClearLotList_Click(object sender, EventArgs e)
        {

            try
            {
                ClearList("LOT_LIST");

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void txtLotId_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (spdPackingLotList.ActiveSheet.RowCount > 0)
                    {
                        if (spdPackingLotList.ActiveSheet.Cells[0, (int)PACK_LOT.PACK_LOT_ID].Text != "")
                        {
                            MPCF.ClearList(spdPackingLotList);
                        }
                    }

                    for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT.LOT_ID].Text == txtLotId.Text.Trim())
                        {
                            spdLotList.ActiveSheet.SetValue(i, (int)LOT.CHK, true);
                            spdLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 192, 255);
                            spdLotList.ShowRow(0, i, VerticalPosition.Nearest);

                            spdLotList.ActiveSheet.ActiveRowIndex = i;
                            spdLotList.ActiveSheet.ActiveColumnIndex = (int)LOT.CHK;

                            CellClickEventArgs evnt = new CellClickEventArgs(null, i, (int)LOT.CHK, 0, 0, MouseButtons.Left, false, false);
                            spdLotList_CellClick(spdLotList, evnt);
                        }
                        else
                        {
                            spdLotList.ActiveSheet.SetValue(i, (int)LOT.CHK, false);
                            spdLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                        }
                    }
                    txtLotSize.Focus();
                    txtLotId.Text = "";
                    //txtLotId.Focus();
                    //txtLotId.SelectAll();
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
        private void btnGCM_Click(object sender, EventArgs e)
        {
            try
            {

                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = "C_FEFA_SIZE";

                if (MPGV.gcLanguage == '2')
                {
                    popup.sTable_name_desc = "고객사 FEFA SIZE";
                    popup.sComment = "FEFA SIZE 라벨 출력우선순위는 납품처기준 SIZE ->고객사기준 SIZE ->ERP 주문등록시 입력한 SIZE 순서입니다.\r\n(우선순위로 데이터 있는경우 보여줌)";

                }
                else
                {
                    popup.sTable_name_desc = "CUSTOMER FEFA SIZE";
                    popup.sComment = "FEFA SIZE ORDER BY (DELIVERY SIZE -> CUSTOMER SIZE -> ERP ORDER INPUT SIZE)";

                }

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
        private void btnGCM2_Click(object sender, EventArgs e)
        {
            try
            {

                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = "C_FEFA_SIZE2";

                if (MPGV.gcLanguage == '2')
                {
                    popup.sTable_name_desc = "납품처 FEFA SIZE";
                    popup.sComment = "FEFA SIZE 라벨 출력우선순위는 납품처기준 SIZE ->고객사기준 SIZE ->ERP 주문등록시 입력한 SIZE 순서입니다.\r\n(우선순위로 데이터 있는경우 보여줌)";

                }
                else
                {
                    popup.sTable_name_desc = "DELIVERY FEFA SIZE";
                    popup.sComment = "FEFA SIZE ORDER BY (DELIVERY SIZE -> CUSTOMER SIZE -> ERP ORDER INPUT SIZE)";

                }


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
        private void btnGCM3_Click(object sender, EventArgs e)
        {
            try
            {

                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = "C_CUSTOMER_ITEM";

                if (MPGV.gcLanguage == '2')
                {
                    popup.sTable_name_desc = "고객사 ITEM";
                    popup.sComment = "고객사 ITEM 라벨 출력우선순위는 납품처기준 SIZE ->고객사기준 SIZE ->ERP 주문등록시 입력한 SIZE 순서입니다.\r\n(우선순위로 데이터 있는경우 보여줌)";

                }
                else
                {
                    popup.sTable_name_desc = "CUSTOMER FEFA SIZE";
                    popup.sComment = "CUSTOMER ITEM ORDER BY (DELIVERY SIZE -> CUSTOMER SIZE -> ERP ORDER INPUT SIZE)";

                }


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
        private void btnGCM4_Click(object sender, EventArgs e)
        {
            try
            {

                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = "C_DELIVERY_ITEM";

                if (MPGV.gcLanguage == '2')
                {
                    popup.sTable_name_desc = "납품처 ITEM";
                    popup.sComment = "고객사 ITEM 라벨 출력우선순위는 납품처기준 SIZE ->고객사기준 SIZE ->ERP 주문등록시 입력한 SIZE 순서입니다.\r\n(우선순위로 데이터 있는경우 보여줌)";

                }
                else
                {
                    popup.sTable_name_desc = "DELIVERY ITEM";
                    popup.sComment = "CUSTOMER ITEM ORDER BY (DELIVERY SIZE -> CUSTOMER SIZE -> ERP ORDER INPUT SIZE)";

                }


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
        #endregion


    }
}
