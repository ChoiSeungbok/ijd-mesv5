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

namespace CUS_INV
{
    public partial class frmTranArrivalLotFromShip : CUS_COM.frmTranForm01
    {
        public frmTranArrivalLotFromShip()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum PO
        {
            DLV_NO,                // 1 : 구매 입고 넘버
            DLV_SEQ,               // 2 : 구매 입고 순번
            PO_NO,                 // 3 : PO NO
            PO_SEQ,                // 4 : PO SEQ
            BL_NO,                 // 5 : BL NO
            BL_SEQ,                // 6 : BL SEQ
            QTY,                   // 7 : PO 수량
            DLV_IN_QTY,            // 8 : 입하 확정 수량
            CONFIRM_QTY,           // 9 : 입고 수량
            LOSS_QTY,              // 10 : 불량 수량
            UNIT,                  // 11 : 단위
            MAT_ID,                // 12 : 제품
            MAT_VER,               // 13 : 버전
            MAT_DESC,              // 14 : 제품명
            VENDOR_ID,             // 15 : 협력사
            VENDOR_SITE_ID,        // 16 : 업체 SITE ID
            VENDOR_DESC,           // 17 : 업체명
            INSPECTION_FLAG,       // 18 : 검사 여부
            CONSIGNMENT_FLAG,      // 19 : 위탁 여부
            MAT_CMF_9,             // 20 : 금형 여부
            MAT_TYPE               // 21 : 제품 타입   
        }

        private enum LOT
        {
            CHK,                       // 1 : CHECK
            ORG_LOT_ID,                // 2 : 공정 LOT ID
            PACK_LOT_ID,               // 3 : 출하 LOT ID
            SHIP_DATE,                 // 4 : 출하 일자
            SHIP_ORDER_ID,
            QTY,                       // 5 : 수량
            UNIT,                      // 6 : 단위
            MAT_ID,                    // 7 : 제품
            MAT_DESC                   // 8 : 제품명
        }

        #endregion

        #region " Variable Definition "
        string matId;
        string matVer;
        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
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

        //PO LIST 조회 함수
        private void ViewPOList()
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

                dvcArgu[2].sCondition_ID = "VENDOR_ID";
                dvcArgu[2].sCondition_Value = cdvVendorID.Text;

                dvcArgu[3].sCondition_ID = "MAT_ID";
                dvcArgu[3].sCondition_Value = cdvMatID.Text;

                dvcArgu[4].sCondition_ID = "FROM_DATE";
                dvcArgu[4].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));

                dvcArgu[5].sCondition_ID = "TO_DATE";
                dvcArgu[5].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";

                dvcArgu[6].sCondition_ID = "PO_NO";
                dvcArgu[6].sCondition_Value = txtPONo.Text;

                if (TPDR.GetDataOne("", ref dt, "CINV2018-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdPOList);
                    return;
                }

                MPCF.ClearList(spdPOList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdPOList_Sheet1.RowCount++;

                    spdPOList_Sheet1.Cells[i, (int)PO.DLV_NO].Value = dt.Rows[i]["DLV_NO"];
                    spdPOList_Sheet1.Cells[i, (int)PO.DLV_SEQ].Value = dt.Rows[i]["DLV_SEQ"];
                    spdPOList_Sheet1.Cells[i, (int)PO.PO_NO].Value = dt.Rows[i]["PO_NO"];
                    spdPOList_Sheet1.Cells[i, (int)PO.PO_SEQ].Value = dt.Rows[i]["PO_SEQ"];
                    spdPOList_Sheet1.Cells[i, (int)PO.BL_NO].Value = dt.Rows[i]["BL_NO"];
                    spdPOList_Sheet1.Cells[i, (int)PO.BL_SEQ].Value = dt.Rows[i]["BL_SEQ"];
                    spdPOList_Sheet1.Cells[i, (int)PO.QTY].Value = dt.Rows[i]["DLV_QTY"];
                    spdPOList_Sheet1.Cells[i, (int)PO.DLV_IN_QTY].Value = dt.Rows[i]["DLV_IN_QTY"];
                    spdPOList_Sheet1.Cells[i, (int)PO.CONFIRM_QTY].Value = dt.Rows[i]["CONFIRM_QTY"];
                    spdPOList_Sheet1.Cells[i, (int)PO.LOSS_QTY].Value = dt.Rows[i]["LOSS_QTY"];
                    spdPOList_Sheet1.Cells[i, (int)PO.UNIT].Value = dt.Rows[i]["UNIT_1"];
                    spdPOList_Sheet1.Cells[i, (int)PO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdPOList_Sheet1.Cells[i, (int)PO.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdPOList_Sheet1.Cells[i, (int)PO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdPOList_Sheet1.Cells[i, (int)PO.VENDOR_ID].Value = dt.Rows[i]["VENDOR_ID"];
                    spdPOList_Sheet1.Cells[i, (int)PO.VENDOR_SITE_ID].Value = dt.Rows[i]["VENDOR_SITE_ID"];
                    spdPOList_Sheet1.Cells[i, (int)PO.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdPOList_Sheet1.Cells[i, (int)PO.INSPECTION_FLAG].Value = dt.Rows[i]["INSPECTION_FLAG"];
                    spdPOList_Sheet1.Cells[i, (int)PO.CONSIGNMENT_FLAG].Value = dt.Rows[i]["CONSIGNMENT_FLAG"];
                    spdPOList_Sheet1.Cells[i, (int)PO.MAT_CMF_9].Value = dt.Rows[i]["MAT_CMF_9"];
                    spdPOList_Sheet1.Cells[i, (int)PO.MAT_TYPE].Value = dt.Rows[i]["MAT_TYPE"];
                }
                MPCF.FitColumnHeader(spdPOList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //Ship Lot LIST 조회 함수
        private void ViewShipLotList(string matId, string matVer)
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

                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = matId;

                dvcArgu[2].sCondition_ID = "MAT_VER";
                dvcArgu[2].sCondition_Value = matVer;

                dvcArgu[3].sCondition_ID = "SHIP_ORDER_ID";
                dvcArgu[3].sCondition_Value = cdvShipOrderId.Text;


                if (TPDR.GetDataOne("", ref dt, "CINV2018-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdFromLotList);
                    return;
                }

                MPCF.ClearList(spdFromLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdFromLotList_Sheet1.RowCount++;

                    spdFromLotList_Sheet1.SetValue(i, (int)LOT.CHK, false);
                    spdFromLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];
                    spdFromLotList_Sheet1.Cells[i, (int)LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                    spdFromLotList_Sheet1.Cells[i, (int)LOT.SHIP_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["SHIP_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdFromLotList_Sheet1.Cells[i, (int)LOT.SHIP_ORDER_ID].Value = dt.Rows[i]["SHIP_ORDER_ID"];
                    spdFromLotList_Sheet1.Cells[i, (int)LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdFromLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdFromLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdFromLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                }
                MPCF.FitColumnHeader(spdFromLotList);

                for (i = 0; i < spdFromLotList_Sheet1.RowCount; i++)
                {
                    dSumQty += MPCF.ToDbl(spdFromLotList.ActiveSheet.Cells[i, (int)LOT.QTY].Text);
                }

                spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //Scan Lot 조회 함수
        private void ScanLot(string matId, string matVer)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i_Row = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = matId;

                dvcArgu[2].sCondition_ID = "MAT_VER";
                dvcArgu[2].sCondition_Value = matVer;

                dvcArgu[3].sCondition_ID = "ORG_LOT_ID";
                dvcArgu[3].sCondition_Value = txtLotID.Text;

                if (TPDR.GetDataOne("", ref dt, "CINV2018-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    txtLotID.SelectAll();

                    return;
                }

                for (int i = 0; i < spdToLotList_Sheet1.RowCount; i++)
                {
                    // FROM 그리드에 데이터 제거
                    if (string.Equals(spdToLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text, dt.Rows[0]["ORG_LOT_ID"]))
                    {
                        spdToLotList_Sheet1.RemoveRows(i, 1);
                        break;
                    }
                }

                for (int i = 0; i < spdFromLotList_Sheet1.RowCount; i++)
                {
                    // FROM 그리드에 데이터 제거
                    if (string.Equals(spdFromLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text, dt.Rows[0]["ORG_LOT_ID"]))
                    {
                        spdFromLotList_Sheet1.RemoveRows(i, 1);
                        break;
                    }
                }

                // TO 그리드에 데이터 삽입
                i_Row = spdToLotList_Sheet1.RowCount++;

                spdToLotList_Sheet1.SetValue(i_Row, (int)LOT.CHK, true);
                spdToLotList_Sheet1.Cells[i_Row, (int)LOT.ORG_LOT_ID].Value = dt.Rows[0]["ORG_LOT_ID"];
                spdToLotList_Sheet1.Cells[i_Row, (int)LOT.PACK_LOT_ID].Value = dt.Rows[0]["PACK_LOT_ID"];
                spdToLotList_Sheet1.Cells[i_Row, (int)LOT.SHIP_DATE].Value = MPCF.MakeDateFormat(dt.Rows[0]["SHIP_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                spdToLotList_Sheet1.Cells[i_Row, (int)LOT.SHIP_ORDER_ID].Value = dt.Rows[0]["SHIP_ORDER_ID"];
                spdToLotList_Sheet1.Cells[i_Row, (int)LOT.QTY].Value = dt.Rows[0]["QTY"];
                spdToLotList_Sheet1.Cells[i_Row, (int)LOT.UNIT].Value = dt.Rows[0]["UNIT"];
                spdToLotList_Sheet1.Cells[i_Row, (int)LOT.MAT_ID].Value = dt.Rows[0]["MAT_ID"];
                spdToLotList_Sheet1.Cells[i_Row, (int)LOT.MAT_DESC].Value = dt.Rows[0]["MAT_DESC"];
                MPCF.FitColumnHeader(spdToLotList);

                txtLotID.SelectAll();

                CheckCount();
                CheckCount2();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void CheckCount()
        {
            int iCount = 0;
            double dSumQty = 0;

            try
            {
                for (int i = 0; i < spdFromLotList_Sheet1.RowCount; i++)
                {
                    if (spdFromLotList_Sheet1.Cells[i, (int)LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdFromLotList_Sheet1.Cells[i, (int)LOT.QTY].Text);
                    }
                }

                spdFromLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.CHK].Value = iCount;
                spdFromLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void CheckCount2()
        {
            int iCount = 0;
            double dSumQty = 0;

            try
            {
                for (int i = 0; i < spdToLotList_Sheet1.RowCount; i++)
                {
                    if (spdToLotList_Sheet1.Cells[i, (int)LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdToLotList_Sheet1.Cells[i, (int)LOT.QTY].Text);
                    }
                }

                spdToLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.CHK].Value = iCount;
                spdToLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
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
                    case "PROCESS":
                        if (spdPOList_Sheet1.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdToLotList_Sheet1.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (MPCF.Trim(this.txtVendorLotNo.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblVendorLotNo.Text + "]");
                            txtVendorLotNo.Focus();
                            return false;
                        }

                        break;

                    case "INPUT":
                        if (MPCF.Trim(txtLotID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [LOT ID]");
                            txtLotID.Focus();
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

                        MPCF.ClearList(spdPOList);
                        MPCF.ClearList(spdFromLotList);
                        MPCF.ClearList(spdToLotList);
                        spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;
                        spdToLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdToLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;

                        this.txtVendorLotNo.Text = "";
                        this.dtpArrivalDate.Value = DateTime.Now;
                        this.txtTotalQty.Text = "0";
                        this.txtLotID.Text = "";
                        this.cdvShipOrderId.Text = "";
                        break;

                    case "ALL":

                        MPCF.ClearList(spdPOList);
                        MPCF.ClearList(spdFromLotList);
                        MPCF.ClearList(spdToLotList);
                        spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;
                        spdToLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdToLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;

                        this.cdvDept.Text = "";
                        this.cdvVendorID.Text = "";
                        this.cdvMatID.Text = "";
                        this.txtVendorLotNo.Text = "";
                        this.dtpArrivalDate.Value = DateTime.Now;
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
                        this.txtPONo.Text = "";
                        this.txtTotalQty.Text = "0";
                        this.txtLotID.Text = "";
                        this.cdvShipOrderId.Text = "";
                        break;

                    case "PO_CLICK_CELL":

                        MPCF.ClearList(spdFromLotList);
                        MPCF.ClearList(spdToLotList);
                        spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;
                        spdToLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdToLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;

                        this.txtVendorLotNo.Text = "";
                        this.dtpArrivalDate.Value = DateTime.Now;
                        this.txtTotalQty.Text = "0";
                        this.txtLotID.Text = "";
                        this.cdvShipOrderId.Text = "";
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //입하 자재 라벨 생성
        private bool ProcessInvLot()
        {
            TRSNode in_node = new TRSNode("create_InvLot_In");
            TRSNode out_node = new TRSNode("create_InvLot_Out");
            TRSNode lot_list;
            double d_total_label_qty = 0;
            bool send_flag = false;

            string sDlvLotId = "";
            string sDlvLotout = "";


            try
            {
                //CMN526 INFO -  입고 작업을 진행하시겠습니까?
                if (MPCF.ShowMsgBox(MPCF.GetMessage(526), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                {
                    return false;
                }




                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("AREA_ID", cdvDept.Text);

                for (int i = 0; i < spdToLotList_Sheet1.RowCount; i++)
                {
                    if (spdToLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {

                        sDlvLotId = spdToLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text;


                        //이미있으면 입고LOT은 뒤에 (1)..(2) 이런식으로 들어가도록.
                        GegDlvLotChecks(spdToLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text, ref sDlvLotout,i);

                        if (sDlvLotout != "")
                        {
                            sDlvLotId = spdToLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text + "(" + sDlvLotout.ToString() + ")";
                            /*
                            if (MPCF.ShowMsgBox(sMsg01 + " " + sDlvLotout, MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                            {
                                return false;
                            }
                            else
                            {
                                sDlvLotId = spdToLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text + "(" + sDlvLotout.ToString() + ")";


                            }
                            */
                        }
                        else
                        {
                            sDlvLotId = spdToLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text;
                        }


                        lot_list = in_node.AddNode("INV_LOT_LIST");
                        lot_list.AddString("ORG_LOT_ID", spdToLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text);
                        lot_list.AddString("PACK_LOT_ID", spdToLotList_Sheet1.Cells[i, (int)LOT.PACK_LOT_ID].Text);
                        lot_list.AddDouble("QTY", MPCF.ToDbl(spdToLotList_Sheet1.Cells[i, (int)LOT.QTY].Text));
                        lot_list.AddDouble("QTY_2", 0);
                        lot_list.AddDouble("QTY_3", 0);
                        lot_list.AddString("MAT_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.MAT_ID].Text);
                        lot_list.AddInt("MAT_VER", MPCF.ToInt(spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.MAT_VER].Text));
                        lot_list.AddString("DLV_NO", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.DLV_NO].Text);
                        lot_list.AddInt("DLV_SEQ", MPCF.ToInt(spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.DLV_SEQ].Text));
                        //lot_list.AddString("DLV_LOT_ID", spdToLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text);
                        lot_list.AddString("DLV_LOT_ID", sDlvLotId);
                        lot_list.AddString("DLV_TIME", MPCF.DestroyDateFormat(dtpArrivalDate.Text));
                        lot_list.AddString("VENDOR_LOT_ID", this.txtVendorLotNo.Text);
                        lot_list.AddString("VENDOR_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.VENDOR_ID].Text);
                        lot_list.AddString("VENDOR_SITE_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.VENDOR_SITE_ID].Text);

                        d_total_label_qty += MPCF.ToDbl(spdToLotList_Sheet1.Cells[i, (int)LOT.QTY].Text);

                        send_flag = true;


                        spdToLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text = sDlvLotId;
                    }
                }

                in_node.AddDouble("TOTAL_QTY", d_total_label_qty);

                if (d_total_label_qty > MPCF.ToDbl(txtTotalQty.Text))
                {
                    //CMN189 ERROR - 데이타가 최대값을 초과했습니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(189));
                    return false;
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                
                if (MPCR.CallService("CUS_INV", "CUS_INV_Arrival_Lot_From_Ship", in_node, ref out_node) == false)
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




        private bool GegDlvLotCheck(string DLV_LOT)
        {
            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");



            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            in_node.AddString("SQL", "SELECT DLV_LOT_ID FROM MINVDLVLOT "
                                               + "   WHERE DLV_LOT_ID = '" + DLV_LOT + "'");

            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return false;
                }



                if (out_node.GetList("ROWS").Count > 0)
                {
                    return true;
                }

            } while (out_node.GetInt("NEXT_ROW") > 0);



            return false;
        }




        private void GegDlvLotChecks(string sDlvLotIn, ref string sDlvLotout,int iRowindex)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                int iCount = 0;
                sDlvLotout = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "DLV_LOT_ID";
                dvcArgu[1].sCondition_Value = sDlvLotIn;



                if (TPDR.GetDataOne("", ref dt, "CINV2018-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();


                    iCount = 0;
                }
                else
                {
                    iCount = dt.Rows.Count;
                }


                for (i = spdToLotList.ActiveSheet.RowCount - 1; i >= 0; i--)
                {


                    if (spdToLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text.Substring(0, sDlvLotIn.Length) == sDlvLotIn)
                    {
                        iCount = iCount + 1;
                        if (i > iRowindex)
                        {
                            iCount = iCount - 1;
                        }

                    }
             

                }

                if (iCount <= 1)
                {
                    sDlvLotout = "";
                }
                else
                {
                    sDlvLotout = (iCount).ToString();
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region "Event Definition "
        private void frmTranArrivalLotFromShip_Load(object sender, EventArgs e)
        {
            try
            {
                this.dtpArrivalDate.Value = DateTime.Now;
                this.dtpToWorkDate.Value = DateTime.Now;
                this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
                dtpFromWorkDate.Format = DateTimePickerFormat.Custom;
                dtpFromWorkDate.CustomFormat = " ";
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

        private void cdvVendorID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopVendorList popup = new frmPopVendorList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvVendorID.Text = popup.g_VendorId;
                    this.cdvVendorID.DisplayText = popup.g_VendorDesc;
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

                ViewPOList();
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
                if (CheckCondition("PROCESS") == false)
                    return;

                if (ProcessInvLot())
                {
                    btnView_Click(null, null);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdPOList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            string sQty;
            string sDlvInQty;
            string sLossQty;

            ClearList("PO_CLICK_CELL");

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

                for (int i = 0; i < spdPOList.ActiveSheet.RowCount; i++)
                {
                    spdPOList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdPOList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                sQty = spdPOList.ActiveSheet.Cells[e.Row, (int)PO.QTY].Text;
                sDlvInQty = spdPOList.ActiveSheet.Cells[e.Row, (int)PO.DLV_IN_QTY].Text;
                sLossQty = spdPOList.ActiveSheet.Cells[e.Row, (int)PO.LOSS_QTY].Text;

                sQty = (MPCF.ToDbl(sQty) - MPCF.ToDbl(sDlvInQty) - MPCF.ToDbl(sLossQty)).ToString();

                if (MPCF.Trim(sQty) != "")
                {
                    this.txtTotalQty.Text = sQty;
                }

                matId = spdPOList.ActiveSheet.Cells[e.Row, (int)PO.MAT_ID].Text;
                matVer = spdPOList.ActiveSheet.Cells[e.Row, (int)PO.MAT_VER].Text;

                ViewShipLotList(matId, matVer);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdFromLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdFromLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdFromLotList, e.Row, e.Column, true, true, false);
                }

                CheckCount();
            }
        }

        private void spdFromLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
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

        private void spdFromLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
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

        private void spdToLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdToLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdToLotList, e.Row, e.Column, true, true, false);
                }

                CheckCount2();
            }
        }

        private void spdToLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
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

        private void spdToLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
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

        private void txtPONo_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (CheckCondition("VIEW") == false)
                        return;

                    ClearList("VIEW");

                    ViewPOList();
                }
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

        private void cdvVendorID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvVendorID.DisplayText == "")
                cdvVendorID.Text = "";
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

        private void btnAdd_Click(object sender, EventArgs e)
        {
            try
            {
                int iRow = 0;

                for (int i = spdFromLotList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdFromLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (spdToLotList_Sheet1.RowCount + 1 > MPCF.ToDbl(txtTotalQty.Text))
                        {
                            //CMN189 ERROR - 데이타가 최대값을 초과했습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(189));

                            CheckCount();
                            CheckCount2();

                            return;
                        }

                        iRow = spdToLotList_Sheet1.RowCount++;

                        spdToLotList_Sheet1.SetValue(iRow, (int)LOT.CHK, true);
                        spdToLotList_Sheet1.Cells[iRow, (int)LOT.ORG_LOT_ID].Value = spdFromLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text;
                        spdToLotList_Sheet1.Cells[iRow, (int)LOT.PACK_LOT_ID].Value = spdFromLotList_Sheet1.Cells[i, (int)LOT.PACK_LOT_ID].Text;
                        spdToLotList_Sheet1.Cells[iRow, (int)LOT.SHIP_DATE].Value = spdFromLotList_Sheet1.Cells[i, (int)LOT.SHIP_DATE].Text;
                        spdToLotList_Sheet1.Cells[iRow, (int)LOT.SHIP_ORDER_ID].Value = spdFromLotList_Sheet1.Cells[i, (int)LOT.SHIP_ORDER_ID].Text;
                        spdToLotList_Sheet1.Cells[iRow, (int)LOT.QTY].Value = spdFromLotList_Sheet1.Cells[i, (int)LOT.QTY].Text;
                        spdToLotList_Sheet1.Cells[iRow, (int)LOT.UNIT].Value = spdFromLotList_Sheet1.Cells[i, (int)LOT.UNIT].Text;
                        spdToLotList_Sheet1.Cells[iRow, (int)LOT.MAT_ID].Value = spdFromLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Text;
                        spdToLotList_Sheet1.Cells[iRow, (int)LOT.MAT_DESC].Value = spdFromLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Text;

                        spdFromLotList_Sheet1.RemoveRows(i, 1);
                    }
                }

                MPCF.FitColumnHeader(spdToLotList);

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
                int iRow = 0;

                for (int i = spdToLotList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdToLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        iRow = spdFromLotList_Sheet1.RowCount++;

                        spdFromLotList_Sheet1.SetValue(iRow, (int)LOT.CHK, false);
                        spdFromLotList_Sheet1.Cells[iRow, (int)LOT.ORG_LOT_ID].Value = spdToLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text;
                        spdFromLotList_Sheet1.Cells[iRow, (int)LOT.PACK_LOT_ID].Value = spdToLotList_Sheet1.Cells[i, (int)LOT.PACK_LOT_ID].Text;
                        spdFromLotList_Sheet1.Cells[iRow, (int)LOT.SHIP_DATE].Value = spdToLotList_Sheet1.Cells[i, (int)LOT.SHIP_DATE].Text;
                        spdFromLotList_Sheet1.Cells[iRow, (int)LOT.SHIP_ORDER_ID].Value = spdToLotList_Sheet1.Cells[i, (int)LOT.SHIP_ORDER_ID].Text;
                        spdFromLotList_Sheet1.Cells[iRow, (int)LOT.QTY].Value = spdToLotList_Sheet1.Cells[i, (int)LOT.QTY].Text;
                        spdFromLotList_Sheet1.Cells[iRow, (int)LOT.UNIT].Value = spdToLotList_Sheet1.Cells[i, (int)LOT.UNIT].Text;
                        spdFromLotList_Sheet1.Cells[iRow, (int)LOT.MAT_ID].Value = spdToLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Text;
                        spdFromLotList_Sheet1.Cells[iRow, (int)LOT.MAT_DESC].Value = spdToLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Text;

                        spdToLotList_Sheet1.RemoveRows(i, 1);
                    }
                }

                MPCF.FitColumnHeader(spdFromLotList);

                CheckCount();
                CheckCount2();
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

                    ScanLot(matId, matVer);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            //20220804 추가
            try
            {
                if (CheckCondition("VIEW") == false)
                    return;

                ClearList("VIEW");

                ViewPOList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOutType_ButtonPress(object sender, EventArgs e)
        {

        }

        private void cdvShipOrderId_ButtonPress(object sender, EventArgs e)
        {

            try
            {
                TRSNode in_node = new TRSNode("SQL_IN");
                TRSNode out_node = new TRSNode("SQL_OUT");

                MPCF.InitListView(cdvShipOrderId.GetListView);

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                if (spdPOList.ActiveSheet.ActiveRowIndex < 0)
                {
                    return;
                }

                string sMatId = spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.MAT_ID].Text;
                string sMatVer = spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.MAT_VER].Text;


                in_node.AddString("SQL", "select SHP.SHIP_ORDER_ID AS CODE, 'ORDER: ' || SHP.SHIP_ORDER_ID || ' / DATE: ' || SUBSTR(MAX(SHP.SHIP_DATE), 1, 8) || ' / QTY: ' || SUM(SHP.QTY) || ' ' || SHP.UNIT AS VALUE "
                                          + " from ISHPLOTRCV SHP , MWIPMATDEF MAT, MWIPMATDEF MAT2 "
                                         + " WHERE SHP.FACTORY = MAT.FACTORY(+) AND SHP.MAT_ID = MAT.MAT_ID(+) "
                                               + " AND SHP.MAT_VER = MAT.MAT_VER(+) "
                                              + " AND MAT2.FACTORY = SHP.FACTORY "
                                               + " AND MAT2.MAT_ID = '" + sMatId + "'"
                                              + "  AND MAT2.MAT_VER = '" + sMatVer + "'"
                                               + " AND MAT2.MAT_CMF_11 = SHP.MAT_ID "
                                              + "  AND SHP.RECEIVE_FLAG <> 'Y' "
                                              + "  AND SHP.DELETE_FLAG <> 'Y' "
                                        + " GROUP BY SHP.SHIP_ORDER_ID,SHP.UNIT");

                do
                {
                    if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                    {
                        return;
                    }

                    MPCR.FillDataView(cdvShipOrderId.GetListView, out_node);

                    in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
                } while (out_node.GetInt("NEXT_ROW") > 0);


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        private void cdvShipOrderId_TextBoxTextChanged(object sender, EventArgs e)
        {/*
            try
            {
                if (spdPOList.ActiveSheet.ActiveRowIndex < 0)
                {
                    return;
                }

                string sMatId = spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.MAT_ID].Text;
                string sMatVer = spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.MAT_VER].Text;


                ViewShipLotList(sMatId, sMatVer);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            */
        }

        private void cdvShipOrderId_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (spdPOList.ActiveSheet.ActiveRowIndex < 0)
                {
                    return;
                }

                string sMatId = spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.MAT_ID].Text;
                string sMatVer = spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.MAT_VER].Text;


                ViewShipLotList(sMatId, sMatVer);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnGCM_Click(object sender, EventArgs e)
        {
            try
            {

                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = "C_INV_MAT_MATCHING";

                if (MPGV.gcLanguage == '2')
                {
                    popup.sTable_name_desc = "출하 및 입고 품목 매칭";
                    popup.sComment = "입고잡을 품목과 타공장에서 출하된품목을 서로 매칭합니다.";

                }
                else
                {
                    popup.sTable_name_desc = "ITEM MATCHING";
                    popup.sComment = "Items that receive purchases and\r\nMatch the items sent from other factories to each other.";
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

        private void btnLotsearch_Click(object sender, EventArgs e)
        {
            if (spdPOList.ActiveSheet.ActiveRowIndex < 0)
            {
                return;
            }


            if (txtPakShpLot.Text.Trim() != "")
            {
                try
                {




                    TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                    DataTable dt = null;
                    string sSql = "";

                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                    dvcArgu[1].sCondition_ID = "LOT_ID";
                    dvcArgu[1].sCondition_Value = txtPakShpLot.Text;


                    dvcArgu[2].sCondition_ID = "MAT_ID";
                    dvcArgu[2].sCondition_Value = spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.MAT_ID].Text;


                    if (TPDR.GetDataOne("", ref dt, "CINV2018-005", dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt != null)
                            dt.Dispose();

                        GC.Collect();

                        MPCF.ShowMsgBox("At another factory.No shipping history.(다른 공장에서 출하된 이력이없습니다.");

                        return;
                    }

                    MPCF.ShowMsgBox(dt.Rows[0]["MSG_DESC"].ToString());


                    return;
                }
                catch (Exception ex)
                {
                    MPCF.ShowMsgBox(ex.Message);
                }
            }
        }
    }
}
