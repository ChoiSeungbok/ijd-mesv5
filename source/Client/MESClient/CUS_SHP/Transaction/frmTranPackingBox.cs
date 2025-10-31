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

namespace CUS_SHP
{
    public partial class frmTranPackingBox : CUS_COM.frmTranForm01
    {
        public frmTranPackingBox()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum PACK_ORDER
        {
            PACK_ORDER_ID,         // 1 : 포장 지시 번호
            LINE_NO,               // 2 : 포장 라인 번호
            ERP_PACK_ORDER_ID,     // 3 : ERP 포장 지시 번호
            MAT_ID,                // 4 : 제품
            MAT_VER,               // 5 : 버전
            MAT_DESC,              // 6 : 제품명
            PACK_ORD_DATE,         // 7 : 포장지시일자
            QTY,                   // 8 : 포장수량
            REG_QTY,               // 9 : 등록 수량
            PACKED_QTY,            // 10 : 포장된 수량
            UNIT,                  // 11 : 단위
            PACK_ORD_STATUS,       // 12 : 포장상태
            CUSTOMER_ID,           // 13 : 고객사
            CUSTOMER_SITE_ID,      // 14 : 고객사 SITE ID
            CUSTOMER_NAME,         // 15 : 고객사명
            DELIVERY_ID,           // 16 : 납품처 ID
            DELIVERY_NAME,         // 17 : 최종 납품처명
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
            QTY,                     // 4 : 수량
            UNIT,                    // 5 : 단위
            BOX_ID,                  // 6 : 박스 ID
            FINAL_BOX_ID,            // 7 : 최종 박스 ID
            SHIP_FLAG                // 8 : 출하 여부
        }


        #endregion

        #region " Variable Definition "
        string packOrderId = "";
        string packLineNo = "";
        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                lblLableSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                cdvLabelSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatID.Text;

                dvcArgu[3].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[3].sCondition_Value = txtPackingOrderNo.Text;

                dvcArgu[4].sCondition_ID = "FROM_DATE";
                dvcArgu[4].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));

                dvcArgu[5].sCondition_ID = "TO_DATE";
                dvcArgu[5].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";

                dvcArgu[6].sCondition_ID = "ERP_PACK_ORDER_ID";
                dvcArgu[6].sCondition_Value = txtERPPackOrderID.Text.Trim();

                if (TPDR.GetDataOne("", ref dt, "CSHP2002-001", dvcArgu, false, false, ref sSql) == false)
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
                //MPCF.FitColumnHeader(spdOrderList);

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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
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

                if (TPDR.GetDataOne("", ref dt, "CSHP2002-004", dvcArgu, false, false, ref sSql) == false)
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
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Value = dt.Rows[i]["BOX_ID_1"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Value = dt.Rows[i]["BOX_ID_2"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_FLAG].Value = dt.Rows[i]["SHIP_FLAG"];

                }
                //MPCF.FitColumnHeader(spdPackingLotList);

                for (i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
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

        private void CheckCount2()
        {
            double dSumQty = 0;
            int iCount = 0;

            try
            {
                for (int i = 0; i < spdBoxLotList_Sheet1.RowCount; i++)
                {
                    if (spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.QTY].Text);
                    }
                }

                spdBoxLotList_Sheet1.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = iCount;
                spdBoxLotList_Sheet1.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 포장 LOT 정보 조회 후 데이터 추가
        private void InputPackLot()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i_Row = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[1].sCondition_Value = spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)PACK_ORDER.PACK_ORDER_ID].Text;

                dvcArgu[2].sCondition_ID = "PACK_LINE_NO";
                dvcArgu[2].sCondition_Value = spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)PACK_ORDER.LINE_NO].Text;

                dvcArgu[3].sCondition_ID = "PACK_LOT_ID";
                dvcArgu[3].sCondition_Value = txtLotID.Text;

                if (TPDR.GetDataOne("", ref dt, "CSHP2002-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    txtLotID.SelectAll();

                    return;
                }

                if (string.Equals(dt.Rows[0]["SHIP_FLAG"], "Y"))
                {
                    //CMN459 ERROR - 해당 LOT은 이미 출하되었습니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(459) + " [" + lblLotID.Text + "]");
                    return;
                }

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    // FROM 그리드에 데이터 제거
                    if (string.Equals(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text, dt.Rows[0]["PACK_LOT_ID"]))
                    {
                        spdPackingLotList_Sheet1.RemoveRows(i, 1);
                        break;
                    }
                }

                // TO 그리드에 데이터 삽입
                i_Row = spdBoxLotList_Sheet1.RowCount++;

                spdBoxLotList_Sheet1.SetValue(i_Row, (int)PACK_LOT.CHK, true);
                spdBoxLotList_Sheet1.Cells[i_Row, (int)PACK_LOT.ORG_LOT_ID].Value = dt.Rows[0]["ORG_LOT_ID"];
                spdBoxLotList_Sheet1.Cells[i_Row, (int)PACK_LOT.PACK_LOT_ID].Value = dt.Rows[0]["PACK_LOT_ID"];
                spdBoxLotList_Sheet1.Cells[i_Row, (int)PACK_LOT.QTY].Value = dt.Rows[0]["QTY"];
                spdBoxLotList_Sheet1.Cells[i_Row, (int)PACK_LOT.UNIT].Value = dt.Rows[0]["UNIT"];
                spdBoxLotList_Sheet1.Cells[i_Row, (int)PACK_LOT.BOX_ID].Value = "";
                spdBoxLotList_Sheet1.Cells[i_Row, (int)PACK_LOT.FINAL_BOX_ID].Value = "";
                spdBoxLotList_Sheet1.Cells[i_Row, (int)PACK_LOT.SHIP_FLAG].Value = dt.Rows[0]["SHIP_FLAG"];
                //MPCF.FitColumnHeader(spdBoxLotList);

                txtLotID.SelectAll();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //BOX PACKING LOT LIST 조회 함수
        private void ViewBoxLotList(string packOrderId, string packLineNo)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
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

                dvcArgu[3].sCondition_ID = "BOX_ID_1";
                dvcArgu[3].sCondition_Value = txtBoxID.Text;

                if (TPDR.GetDataOne("", ref dt, "CSHP2002-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdBoxLotList);
                    txtBoxID.SelectAll();
                    return;
                }

                MPCF.ClearList(spdBoxLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdBoxLotList_Sheet1.RowCount++;

                    spdBoxLotList_Sheet1.SetValue(i, (int)PACK_LOT.CHK, true);
                    spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];
                    spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                    spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Value = dt.Rows[i]["BOX_ID_1"];
                    spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Value = dt.Rows[i]["BOX_ID_2"];
                    spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_FLAG].Value = dt.Rows[i]["SHIP_FLAG"];
                }

                MPCF.FitColumnHeader(spdBoxLotList);

                txtBoxID.SelectAll();

                for (i = 0; i < spdBoxLotList_Sheet1.RowCount; i++)
                {
                    dSumQty += MPCF.ToDbl(spdBoxLotList.ActiveSheet.Cells[i, (int)PACK_LOT.QTY].Text);
                }

                spdBoxLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = dSumQty;

                txtLotCount.Text = dt.Rows.Count.ToString();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        //포장 정보 생성 및 제거
        private bool SaveBox()
        {
            TRSNode in_node = new TRSNode("save_Box_In");
            TRSNode out_node = new TRSNode("save_Box_Out");
            TRSNode lot_list;
            bool send_flag = false;
            int lot_count = 0;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("PACK_ORDER_ID", spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)PACK_ORDER.PACK_ORDER_ID].Text);
                in_node.AddInt("LINE_NO", MPCF.ToInt(spdOrderList.ActiveSheet.Cells[spdOrderList.ActiveSheet.ActiveRowIndex, (int)PACK_ORDER.LINE_NO].Text));
                in_node.AddString("BOX_ID", txtBoxID.Text);
                in_node.AddString("AREA_ID", cdvDept.Text);

                spdBoxLotList.ActiveSheet.SortRows((int)PACK_LOT.QTY, false, false);

                for (int i = 0; i < spdBoxLotList_Sheet1.RowCount; i++)
                {
                    if (spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (string.Equals(spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_FLAG].Text, "Y"))
                        {
                            //CMN459 ERROR - 해당 LOT은 이미 출하되었습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(459));
                            return false;
                        }

                        lot_list = in_node.AddNode("PACK_LOT_LIST");
                        lot_list.AddString("ORG_LOT_ID", spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Text);
                        lot_list.AddString("PACK_LOT_ID", spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text);
                        lot_count++;
                        send_flag = true;
                    }
                }

                if (string.IsNullOrEmpty(txtBoxID.Text))
                {
                    in_node.AddInt("LOT_COUNT", MPCF.ToInt(txtLotCount.Text));
                }
                else
                {
                    in_node.AddInt("LOT_COUNT", lot_count);
                }

                if (send_flag == false && string.IsNullOrEmpty(txtBoxID.Text))
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_SHP", "CUS_SHP_Create_Pack_Box", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);

                if (out_node.GetChar("PRINT_FLAG") == 'Y')
                {
                    ViewPrintLabel(out_node);
                }
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
                    case "SAVE":
                        if (spdOrderList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        //박스 및 데이터가 비어있다면, 진행 X
                        if (string.IsNullOrEmpty(txtBoxID.Text) && spdBoxLotList_Sheet1.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        //박스 및 LOT COUNT가 비어 있다면, 진행 X
                        if (string.IsNullOrEmpty(txtBoxID.Text) && string.IsNullOrEmpty(txtLotCount.Text))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblBoxLotCount.Text + "]");
                            txtLotCount.Focus();
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

                    case "INPUT":
                        if (MPCF.Trim(txtLotID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotID.Text + "]");
                            txtLotID.Focus();
                            return false;
                        }

                        if (spdOrderList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        break;

                    case "BOX_INPUT":
                        if (MPCF.Trim(txtBoxID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblBoxID.Text + "]");
                            txtBoxID.Focus();
                            return false;
                        }

                        break;

                    case "PRINT":
                        if (MPCF.Trim(txtBoxID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblBoxID.Text + "]");
                            txtBoxID.Focus();
                            return false;
                        }

                        if (string.IsNullOrEmpty(txtBoxID.Text) && spdBoxLotList_Sheet1.RowCount == 0)
                        {
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
                        MPCF.ClearList(spdBoxLotList);

                        this.txtLotID.Text = "";
                        this.txtBoxID.Text = "";
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;
                        spdBoxLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdBoxLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;
                        break;

                    case "ALL":

                        MPCF.ClearList(spdOrderList);
                        MPCF.ClearList(spdPackingLotList);
                        MPCF.ClearList(spdBoxLotList);
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);

                        this.cdvWorkPlace.Text = "";
                        this.cdvMatID.Text = "";
                        this.txtPackingOrderNo.Text = "";
                        this.txtLotID.Text = "";
                        this.txtBoxID.Text = "";
                        this.txtLotCount.Text = "";
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;
                        spdBoxLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdBoxLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;
                        break;

                    case "ORDER_CLICK_CELL":

                        MPCF.ClearList(spdPackingLotList);
                        MPCF.ClearList(spdBoxLotList);

                        this.txtLotID.Text = "";
                        this.txtBoxID.Text = "";
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;
                        spdBoxLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdBoxLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public bool ViewPrintLabel(TRSNode in_node)
        {
            string sFileName = "";
            try
            {
                sFileName = cdvLabelSize.Text;

                CSCF.ViewLabelList(sFileName, in_node, 'B');

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
        private void frmTranPackingBox_Load(object sender, EventArgs e)
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
            try
            {
                string sLotId = "";
                bool addFlag = true;
                int iRow = 0;

                for (int i = spdPackingLotList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        addFlag = true;

                        sLotId = spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text;

                        for (int k = 0; k < spdBoxLotList_Sheet1.RowCount; k++)
                        {
                            if (string.Equals(spdBoxLotList_Sheet1.Cells[k, (int)PACK_LOT.PACK_LOT_ID].Text, sLotId))
                            {
                                addFlag = false;
                                continue;
                            }
                        }

                        if (MPCF.Trim(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Text) != "")
                        {
                            continue;
                        }

                        if (string.Equals(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_FLAG].Text, "Y"))
                        {
                            continue;
                        }

                        if (addFlag == true)
                        {
                            iRow = spdBoxLotList_Sheet1.RowCount++;

                            spdBoxLotList_Sheet1.SetValue(iRow, (int)PACK_LOT.CHK, true);
                            spdBoxLotList_Sheet1.Cells[iRow, (int)PACK_LOT.ORG_LOT_ID].Value = spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Text;
                            spdBoxLotList_Sheet1.Cells[iRow, (int)PACK_LOT.PACK_LOT_ID].Value = spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text;
                            spdBoxLotList_Sheet1.Cells[iRow, (int)PACK_LOT.QTY].Value = spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.QTY].Text;
                            spdBoxLotList_Sheet1.Cells[iRow, (int)PACK_LOT.UNIT].Value = spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.UNIT].Text;
                            spdBoxLotList_Sheet1.Cells[iRow, (int)PACK_LOT.BOX_ID].Value = spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Text;
                            spdBoxLotList_Sheet1.Cells[iRow, (int)PACK_LOT.FINAL_BOX_ID].Value = spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Text;
                            spdBoxLotList_Sheet1.Cells[iRow, (int)PACK_LOT.SHIP_FLAG].Value = spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_FLAG].Text;

                        }

                        spdPackingLotList_Sheet1.RemoveRows(i, 1);
                    }
                }

                spdBoxLotList.ActiveSheet.SortRows((int)PACK_LOT.QTY, false, false);

                MPCF.FitColumnHeader(spdBoxLotList);

                CheckCount();
                CheckCount2();
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
                string sLotId = "";
                bool addFlag = true;
                int iRow = 0;

                for (int i = spdBoxLotList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        addFlag = true;

                        sLotId = spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text;

                        for (int k = 0; k < spdPackingLotList_Sheet1.RowCount; k++)
                        {
                            if (string.Equals(spdPackingLotList_Sheet1.Cells[k, (int)PACK_LOT.PACK_LOT_ID].Text, sLotId))
                            {
                                addFlag = false;
                                continue;
                            }
                        }

                        if (string.Equals(spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_FLAG].Text, "Y"))
                        {
                            continue;
                        }

                        if (addFlag == true)
                        {
                            iRow = spdPackingLotList_Sheet1.RowCount++;

                            spdPackingLotList_Sheet1.SetValue(iRow, (int)PACK_LOT.CHK, true);
                            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.ORG_LOT_ID].Value = spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Text;
                            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.PACK_LOT_ID].Value = spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text;
                            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.QTY].Value = spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.QTY].Text;
                            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.UNIT].Value = spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.UNIT].Text;
                            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.BOX_ID].Value = "";
                            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.FINAL_BOX_ID].Value = "";
                            spdPackingLotList_Sheet1.Cells[iRow, (int)PACK_LOT.SHIP_FLAG].Value = spdBoxLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_FLAG].Text;

                        }

                        spdBoxLotList_Sheet1.RemoveRows(i, 1);
                    }
                }

                MPCF.FitColumnHeader(spdPackingLotList);

                CheckCount();
                CheckCount2();
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
                if (CheckCondition("SAVE") == false)
                    return;

                if (SaveBox())
                {
                    ClearList("ORDER_CLICK_CELL");

                    // 포장 진행 LOT 조회
                    ViewPackingLotList(packOrderId, packLineNo);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (CheckCondition("INPUT") == false)
                        return;

                    InputPackLot();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtBoxID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (CheckCondition("BOX_INPUT") == false)
                        return;

                    txtLotCount.Text = "1";

                    ViewBoxLotList(packOrderId, packLineNo);
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

                // 포장 진행 LOT 조회
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

        private void spdBoxLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdBoxLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdBoxLotList, e.Row, e.Column, true, true, false);
                }

                CheckCount2();
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
            if (CheckCondition("PRINT") == false)
                return;

            try
            {
                TRSNode box_list;
                TRSNode in_node = new TRSNode("print_label_In");
                MPCR.SetInMsg(in_node);
                box_list = in_node.AddNode("BOX_LIST");
                box_list.AddString("BOX_ID", MPCF.Trim(txtBoxID.Text));

                ViewPrintLabel(in_node);
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

        private void spdBoxLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            try
            {
                CheckCount2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdBoxLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                CheckCount2();
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
