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
using FarPoint.Win.Spread.CellType;
using FarPoint.Win.Spread;

namespace CUS_INV
{
    public partial class frmTranRegistArrivalLot : CUS_COM.frmTranForm01
    {
        public frmTranRegistArrivalLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum PO
        {
            DLV_NO,                // 0 : 구매 입고 넘버
            DLV_SEQ,               // 1 : 구매 입고 순번
            PO_NO,                 // 2 : PO NO
            PO_SEQ,                // 3 : PO SEQ
            BL_NO,                 // 4 : BL NO
            BL_SEQ,                // 5 : BL SEQ
            MAT_DESC,              // 13 : 제품명
            MAT_ID,                // 11 : 제품
            UNIT,                  // 10 : 단위
            QTY,                   // 6 : PO 수량
            DLV_IN_QTY,            // 7 : 입하 확정 수량
            CONFIRM_QTY,           // 8 : 입고 수량
            LOSS_QTY,              // 9 : 불량 수량
            MAT_VER,               // 12 : 버전
            VENDOR_ID,             // 14 : 협력사
            VENDOR_SITE_ID,        // 15 : 업체 SITE ID
            VENDOR_DESC,           // 16 : 업체명
            INSPECTION_FLAG,       // 17 : 검사 여부
            CONSIGNMENT_FLAG,      // 18 : 위탁 여부
            MAT_CMF_9,             // 19 : 금형 여부
            MATERIAL_TYPE,         // 20 : 제품 타입
            MAT_TYPE,               // 21 : 제품 타입 
            DELETE_FLAG            // 22 : DELETE   
        }

        private enum ARRIVALLOT
        {
            CHK,                       // 1 : CHECK
            DLV_LOT_ID,                // 2 : 입하 LOT ID
            QTY,                       // 3 : 수량
            UNIT,                      // 4 : 단위
            DLV_LOT_STATUS,            // 5 : 입하 LOT 상태
            MAT_ID,                    // 6 : 제품
            MAT_VER,                   // 7 : 버전
            MAT_DESC,                  // 8 : 제품명
            DLV_TIME,                  // 9 : 입하일
            VENDOR_LOT_ID,             // 10 : 업체 LOT ID
            INSP_ID,                   // 11 : 수입 검사 ID
            INSP_RESULT_FLAG           // 12 : 수입검사 결과
        }

        private enum LABEL
        {
            CHK,                     // 1 : CHECK
            LABEL_ID,                // 2 : 라벨 ID
            SEQ,                     // 3 : 순번
            QTY,                     // 4 : 수량
            UNIT,                    // 5 : 단위
            MAT_ID,                  // 6 : 제품
            MAT_VER,                 // 7 : 버전
            MAT_DESC,                // 8 : 제품명
            DLV_TIME,                // 9 : 입하일
            DLV_LOT_ID               //10 : 입하 LOT ID
        }


        #endregion

        #region " Variable Definition "
        string dlvNo;
        string dlvSeq;
        string matId;
        string matVer;
        string matType;
        string moldFlag;
        string sArrivalLotID;
        string sDlvLotID;
        double dQty;
        #endregion


        private void InitControl()
        {
            try
            {
                btnDlvLotPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnLotPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnArrive.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnCancelArrival.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnConfirm.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnCancelConfirm.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool SendMessage(string sUserGroup, string sUsserId, string sLotId, string sMatDesc)
        {
            TRSNode tRSNode = new TRSNode("Publish_Message_In");
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("SEND_COMPUTER_ID", MPGV.gsComputerName);
                tRSNode.AddString("SEND_USER_ID", MPGV.gsUserID, encrypt_flag: true);
                tRSNode.AddString("SEND_USER_GROUP", MPGV.gsUserGroup);
                tRSNode.AddString("TO_FACTORY", MPCF.Trim(MPGV.gsFactory));
                tRSNode.AddString("TO_USER_GROUP", MPCF.Trim(sUserGroup));
                tRSNode.AddString("TO_USER_ID", MPCF.Trim(sUsserId), encrypt_flag: true);
                tRSNode.AddString("MESSAGE", "LOT ID : " + sLotId + " / ITEM : " + sMatDesc + " / QC Result:무검사(No Inspection)  / 검사완료 입고가능합니다.(Inspection Complete,Store Inv Please)");
                string text = "/" + MPGV.gsSiteID;
                text += "/UTL";
                text = text + "/" + MPCF.Trim(MPGV.gsFactory);
                text = text + "/" + MPCF.Trim(sUserGroup);
                text = text + "/" + MPCF.Trim(sUsserId);
                if (!MPCR.CallService("UTL", "UTL_Publish_Message", tRSNode, text))
                {
                    return false;
                }
            }
            catch (Exception)
            {
                return false;
            }
            return true;
        }

        private bool messageUserCheck(string sLotid, string sMatDesc)
        {
            TRSNode tRSNode = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = '1';
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.Append("SELECT B.SEC_GRP_ID, A.KEY_1 FROM MGCMTBLDAT A LEFT JOIN MSECUSRDEF B ON A.FACTORY = B.FACTORY AND A.KEY_1 = B.USER_ID WHERE TABLE_NAME ='C_INSP_IQC_MESSAGE' ");
            tRSNode.AddString("SQL", stringBuilder.ToString());
            if (!MPCR.CallService("BAS", "BAS_SQL_Query", tRSNode, ref out_node))
            {
                return false;
            }
            for (int i = 0; i < out_node.GetList("ROWS").Count; i++)
            {
                if (!SendMessage(out_node.GetList("ROWS")[i].GetList("COLS")[0].GetString("DATA"), out_node.GetList("ROWS")[i].GetList("COLS")[1].GetString("DATA"), sLotid, sMatDesc))
                {
                }
            }
            return true;
        }

        private void ViewPOList()
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "AREA_ID";
                array[1].sCondition_Value = cdvDept.Text;
                array[2].sCondition_ID = "VENDOR_ID";
                array[2].sCondition_Value = cdvVendorID.Text;
                array[3].sCondition_ID = "MAT_ID";
                array[3].sCondition_Value = cdvMatID.Text;
                array[4].sCondition_ID = "FROM_DATE";
                array[4].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));
                array[5].sCondition_ID = "TO_DATE";
                array[5].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";
                array[6].sCondition_ID = "PO_NO";
                array[6].sCondition_Value = txtPONo.Text;
                if (!TPDR.GetDataOne("", ref dt, "CINV2001-001", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdPOList);
                    return;
                }
                MPCF.ClearList(spdPOList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdPOList_Sheet1.RowCount++;
                    spdPOList_Sheet1.Cells[num, 0].Value = dt.Rows[num]["DLV_NO"];
                    spdPOList_Sheet1.Cells[num, 1].Value = dt.Rows[num]["DLV_SEQ"];
                    spdPOList_Sheet1.Cells[num, 2].Value = dt.Rows[num]["PO_NO"];
                    spdPOList_Sheet1.Cells[num, 3].Value = dt.Rows[num]["PO_SEQ"];
                    spdPOList_Sheet1.Cells[num, 4].Value = dt.Rows[num]["BL_NO"];
                    spdPOList_Sheet1.Cells[num, 5].Value = dt.Rows[num]["BL_SEQ"];
                    spdPOList_Sheet1.Cells[num, 9].Value = dt.Rows[num]["DLV_QTY"];
                    spdPOList_Sheet1.Cells[num, 10].Value = dt.Rows[num]["DLV_IN_QTY"];
                    spdPOList_Sheet1.Cells[num, 11].Value = dt.Rows[num]["CONFIRM_QTY"];
                    spdPOList_Sheet1.Cells[num, 12].Value = dt.Rows[num]["LOSS_QTY"];
                    spdPOList_Sheet1.Cells[num, 8].Value = dt.Rows[num]["UNIT_1"];
                    spdPOList_Sheet1.Cells[num, 7].Value = dt.Rows[num]["MAT_ID"];
                    spdPOList_Sheet1.Cells[num, 13].Value = dt.Rows[num]["MAT_VER"];
                    spdPOList_Sheet1.Cells[num, 6].Value = dt.Rows[num]["MAT_DESC"];
                    spdPOList_Sheet1.Cells[num, 14].Value = dt.Rows[num]["VENDOR_ID"];
                    spdPOList_Sheet1.Cells[num, 15].Value = dt.Rows[num]["VENDOR_SITE_ID"];
                    spdPOList_Sheet1.Cells[num, 16].Value = dt.Rows[num]["VENDOR_DESC"];
                    spdPOList_Sheet1.Cells[num, 17].Value = dt.Rows[num]["INSPECTION_FLAG"];
                    spdPOList_Sheet1.Cells[num, 18].Value = dt.Rows[num]["CONSIGNMENT_FLAG"];
                    spdPOList_Sheet1.Cells[num, 19].Value = dt.Rows[num]["MAT_CMF_9"];
                    spdPOList_Sheet1.Cells[num, 21].Value = dt.Rows[num]["MAT_TYPE"];
                    spdPOList_Sheet1.Cells[num, 22].Value = dt.Rows[num]["ERP_OPEN_YN"];
                }
                MPCF.FitColumnHeader(spdPOList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewArrivalLotList(string dlvNo, string dlvSeq, string matId, string matVer)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "DLV_NO";
                array[1].sCondition_Value = dlvNo;
                array[2].sCondition_ID = "DLV_SEQ";
                array[2].sCondition_Value = dlvSeq;
                array[3].sCondition_ID = "MAT_ID";
                array[3].sCondition_Value = matId;
                array[4].sCondition_ID = "MAT_VER";
                array[4].sCondition_Value = matVer;
                if (!TPDR.GetDataOne("", ref dt, "CINV2001-002", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdArrivalLotList);
                    return;
                }
                MPCF.ClearList(spdArrivalLotList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdArrivalLotList_Sheet1.RowCount++;
                    spdArrivalLotList_Sheet1.SetValue(num, 0, false);
                    spdArrivalLotList_Sheet1.Cells[num, 1].Value = dt.Rows[num]["DLV_LOT_ID"];
                    spdArrivalLotList_Sheet1.Cells[num, 2].Value = dt.Rows[num]["QTY"];
                    spdArrivalLotList_Sheet1.Cells[num, 3].Value = dt.Rows[num]["UNIT"];
                    spdArrivalLotList_Sheet1.Cells[num, 4].Value = dt.Rows[num]["DLV_LOT_STATUS"];
                    spdArrivalLotList_Sheet1.Cells[num, 5].Value = dt.Rows[num]["MAT_ID"];
                    spdArrivalLotList_Sheet1.Cells[num, 6].Value = dt.Rows[num]["MAT_VER"];
                    spdArrivalLotList_Sheet1.Cells[num, 7].Value = dt.Rows[num]["MAT_DESC"];
                    spdArrivalLotList_Sheet1.Cells[num, 8].Value = MPCF.MakeDateFormat(dt.Rows[num]["DLV_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdArrivalLotList_Sheet1.Cells[num, 9].Value = dt.Rows[num]["VENDOR_LOT_ID"];
                    spdArrivalLotList_Sheet1.Cells[num, 10].Value = dt.Rows[num]["INSP_ID"];
                    spdArrivalLotList_Sheet1.Cells[num, 11].Value = dt.Rows[num]["INSP_RESULT_FLAG"];
                }
                MPCF.FitColumnHeader(spdArrivalLotList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void CheckCount()
        {
            int num = 0;
            double num2 = 0.0;
            try
            {
                for (int i = 0; i < spdLabelList_Sheet1.RowCount; i++)
                {
                    if (spdLabelList_Sheet1.Cells[i, 0].Value.ToString().ToUpper() == "TRUE")
                    {
                        num++;
                        num2 += MPCF.ToDbl(spdLabelList_Sheet1.Cells[i, 3].Text);
                    }
                }
                spdLabelList_Sheet1.ColumnFooter.Cells[0, 0].Value = num;
                spdLabelList_Sheet1.ColumnFooter.Cells[0, 3].Value = num2;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewLabelList(string arrivalLotID)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                double num2 = 0.0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "DLV_LOT_ID";
                array[1].sCondition_Value = arrivalLotID;
                if (!TPDR.GetDataOne("", ref dt, "CINV2001-003", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdLabelList);
                    return;
                }
                MPCF.ClearList(spdLabelList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdLabelList_Sheet1.RowCount++;
                    spdLabelList_Sheet1.SetValue(num, 0, false);
                    spdLabelList_Sheet1.Cells[num, 1].Value = dt.Rows[num]["LABEL_ID"];
                    spdLabelList_Sheet1.Cells[num, 2].Value = dt.Rows[num]["SEQ"];
                    spdLabelList_Sheet1.Cells[num, 3].Value = dt.Rows[num]["QTY"];
                    spdLabelList_Sheet1.Cells[num, 4].Value = dt.Rows[num]["UNIT"];
                    spdLabelList_Sheet1.Cells[num, 5].Value = dt.Rows[num]["MAT_ID"];
                    spdLabelList_Sheet1.Cells[num, 6].Value = dt.Rows[num]["MAT_VER"];
                    spdLabelList_Sheet1.Cells[num, 7].Value = dt.Rows[num]["MAT_DESC"];
                    spdLabelList_Sheet1.Cells[num, 8].Value = MPCF.MakeDateFormat(dt.Rows[num]["DLV_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdLabelList_Sheet1.Cells[num, 9].Value = dt.Rows[num]["DLV_LOT_ID"];
                }
                MPCF.FitColumnHeader(spdLabelList);
                for (num = 0; num < spdLabelList_Sheet1.RowCount; num++)
                {
                    num2 += MPCF.ToDbl(spdLabelList.ActiveSheet.Cells[num, 3].Text);
                }
                spdLabelList.ActiveSheet.ColumnFooter.Cells[0, 3].Value = num2;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CreateArrivalLot()
        {
            TRSNode tRSNode = new TRSNode("create_Arrival_Lot_In");
            TRSNode out_node = new TRSNode("create_Arrival_Lot_Out");
            if (MPCF.ToDbl(txtQty.Text) == 0.0)
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblQty.Text + "]");
                txtQty.Focus();
                return false;
            }
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("MAT_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, 7].Text);
                tRSNode.AddInt("MAT_VER", MPCF.ToInt(spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, 13].Text));
                tRSNode.AddDouble("QTY", MPCF.ToDbl(txtQty.Text));
                tRSNode.AddDouble("QTY_2", 0.0);
                tRSNode.AddDouble("QTY_3", 0.0);
                tRSNode.AddString("DLV_NO", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, 0].Text);
                tRSNode.AddInt("DLV_SEQ", MPCF.ToInt(spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, 1].Text));
                tRSNode.AddString("DLV_TIME", MPCF.DestroyDateFormat(dtpArrivalDate.Text));
                tRSNode.AddString("VENDOR_LOT_ID", txtVendorLotNo.Text);
                tRSNode.AddString("VENDOR_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, 14].Text);
                tRSNode.AddString("VENDOR_SITE_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, 15].Text);
                tRSNode.AddString("DLV_LOT_ID", "");
                if (!MPCR.CallService("CUS_INV", "CUS_INV_Create_Dlv_Lot", tRSNode, ref out_node))
                {
                    return false;
                }
                sDlvLotID = MPCF.Trim(out_node.GetString("DLV_LOT_ID"));
                dQty = MPCF.ToDbl(txtQty.Text);
                if (chkLabelListSkip.Checked)
                {
                    if (!CreateLabel2())
                    {
                        return false;
                    }
                    MPCR.ShowSuccessMsg(out_node);
                }
                else
                {
                    MPCR.ShowSuccessMsg(out_node);
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool DeleteArrivalLot()
        {
            TRSNode tRSNode = new TRSNode("create_Arrival_Lot_In");
            TRSNode out_node = new TRSNode("create_Arrival_Lot_Out");
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("DLV_LOT_ID", spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, 1].Text);
                if (!MPCR.CallService("CUS_INV", "CUS_INV_Delete_Dlv_Lot", tRSNode, ref out_node))
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

        private bool CreateLabel()
        {
            TRSNode tRSNode = new TRSNode("create_Label_In");
            TRSNode out_node = new TRSNode("create_Label_Out");
            double num = 0.0;
            bool flag = false;
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("DLV_LOT_ID", spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, 1].Text);
                tRSNode.AddString("VENDOR_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, 14].Text);
                tRSNode.AddString("VENDOR_SITE_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, 15].Text);
                for (int i = 0; i < spdLabelList_Sheet1.RowCount; i++)
                {
                    if (spdLabelList_Sheet1.Cells[i, 0].Text.ToString().ToUpper() == "TRUE")
                    {
                        TRSNode tRSNode2 = tRSNode.AddNode("INV_LOT_LIST");
                        tRSNode2.AddString("LABEL_ID", spdLabelList_Sheet1.Cells[i, 1].Text);
                        tRSNode2.AddDouble("QTY", MPCF.ToDbl(spdLabelList_Sheet1.Cells[i, 3].Text));
                        tRSNode2.AddDouble("QTY_2", 0.0);
                        tRSNode2.AddDouble("QTY_3", 0.0);
                        num += MPCF.ToDbl(spdLabelList_Sheet1.Cells[i, 3].Text);
                        flag = true;
                    }
                }
                if (!flag)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }
                if (MPCF.ToDbl(spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, 2].Text) != num)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(202));
                    return false;
                }
                if (!MPCR.CallService("CUS_INV", "CUS_INV_Create_Dlv_Label", tRSNode, ref out_node))
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

        private bool CreateLabel2()
        {
            TRSNode tRSNode = new TRSNode("create_Label_In");
            TRSNode out_node = new TRSNode("create_Label_Out");
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("DLV_LOT_ID", sDlvLotID);
                tRSNode.AddString("VENDOR_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, 14].Text);
                tRSNode.AddString("VENDOR_SITE_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, 15].Text);
                TRSNode tRSNode2 = tRSNode.AddNode("INV_LOT_LIST");
                tRSNode2.AddString("LABEL_ID", sDlvLotID);
                tRSNode2.AddDouble("QTY", dQty);
                tRSNode2.AddDouble("QTY_2", 0.0);
                tRSNode2.AddDouble("QTY_3", 0.0);
                if (!MPCR.CallService("CUS_INV", "CUS_INV_Create_Dlv_Label", tRSNode, ref out_node))
                {
                    return false;
                }
                if (!ConfirmDlvLot2())
                {
                    return false;
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool ConfirmDlvLot2()
        {
            TRSNode tRSNode = new TRSNode("confirm_dlv_Lot_In");
            TRSNode out_node = new TRSNode("confirm_dlv_Lot_Out");
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("DLV_LOT_ID", sDlvLotID);
                if (!MPCR.CallService("CUS_INV", "CUS_INV_Confirm_Dlv_Lot", tRSNode, ref out_node))
                {
                    return false;
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool ConfirmDlvLot()
        {
            TRSNode tRSNode = new TRSNode("confirm_dlv_Lot_In");
            TRSNode out_node = new TRSNode("confirm_dlv_Lot_Out");
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("DLV_LOT_ID", spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, 1].Text);
                if (!MPCR.CallService("CUS_INV", "CUS_INV_Confirm_Dlv_Lot", tRSNode, ref out_node))
                {
                    return false;
                }
                string sLotid = spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, 1].Text;
                string sMatDesc = spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, 7].Text;
                if (spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, 17].Text == "N")
                {
                    messageUserCheck(sLotid, sMatDesc);
                }
                MPCR.ShowSuccessMsg(out_node);
                ViewPrintLabel(2);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool ConfirmCancelDlvLot()
        {
            TRSNode tRSNode = new TRSNode("confirm_cancel_dlv_Lot_In");
            TRSNode out_node = new TRSNode("confirm_cancel_dlv_Lot_Out");
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '2';
                tRSNode.AddString("DLV_LOT_ID", spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, 1].Text);
                if (!MPCR.CallService("CUS_INV", "CUS_INV_Confirm_Dlv_Lot", tRSNode, ref out_node))
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

        public bool ViewPrintLabel(int step)
        {
            try
            {
                TRSNode tRSNode = new TRSNode("print_label_In");
                string sFileName = "mtl100p";
                MPCR.SetInMsg(tRSNode);
                if (step == 1)
                {
                    for (int i = 0; i < spdLabelList_Sheet1.RowCount; i++)
                    {
                        if (spdLabelList_Sheet1.Cells[i, 0].Text.ToString().ToUpper() == "TRUE")
                        {
                            TRSNode tRSNode2 = tRSNode.AddNode("INV_LOT_LIST");
                            tRSNode2.AddString("DLV_LOT_ID", spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, 1].Text);
                            tRSNode2.AddString("INV_LOT_ID", spdLabelList_Sheet1.Cells[i, 1].Text);
                        }
                    }
                }
                else
                {
                    for (int j = 0; j < spdLabelList_Sheet1.RowCount; j++)
                    {
                        TRSNode tRSNode2 = tRSNode.AddNode("INV_LOT_LIST");
                        tRSNode2.AddString("DLV_LOT_ID", spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, 1].Text);
                        tRSNode2.AddString("INV_LOT_ID", spdLabelList_Sheet1.Cells[j, 1].Text);
                    }
                }
                CSCF.ViewLabelList(sFileName, tRSNode);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        public bool ViewPrintDlvLabel(string sLotId = "")
        {
            try
            {
                TRSNode tRSNode = new TRSNode("print_label_In");
                string sFileName = "mtl100pa";
                if (!string.IsNullOrEmpty(sLotId))
                {
                    TRSNode tRSNode2 = tRSNode.AddNode("INV_LOT_LIST");
                    tRSNode2.AddString("DLV_LOT_ID", sLotId);
                }
                else
                {
                    for (int i = 0; i < spdArrivalLotList_Sheet1.RowCount; i++)
                    {
                        if (spdArrivalLotList_Sheet1.Cells[i, 0].Text.ToString().ToUpper() == "TRUE")
                        {
                            TRSNode tRSNode2 = tRSNode.AddNode("INV_LOT_LIST");
                            tRSNode2.AddString("DLV_LOT_ID", spdArrivalLotList_Sheet1.Cells[i, 1].Text);
                        }
                    }
                }
                CSCF.ViewLabelList(sFileName, tRSNode);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool CheckCondition(string sType)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }
                switch (sType)
                {
                    case "SAVE":
                        if (spdPOList_Sheet1.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        if (spdArrivalLotList_Sheet1.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        if (spdLabelList_Sheet1.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        break;
                    case "CONFIRM":
                        if (spdArrivalLotList.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        break;
                    case "ARRIVE":
                        if (MPCF.Trim(txtQty.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblQty.Text + "]");
                            txtQty.Focus();
                            return false;
                        }
                        if (MPCF.Trim(txtVendorLotNo.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblVendorLotNo.Text + "]");
                            txtVendorLotNo.Focus();
                            return false;
                        }
                        if (spdPOList.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        break;
                    case "CANCEL_ARRIVAL":
                        if (spdArrivalLotList.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        break;
                    case "ADD":
                        if (MPCF.Trim(txtTotalQty.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblTotalQty.Text + "]");
                            txtTotalQty.Focus();
                            return false;
                        }
                        if (MPCF.Trim(txtLotSize.Text) == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotSize.Text + "]");
                            txtLotSize.Focus();
                            return false;
                        }
                        if (spdArrivalLotList.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        break;
                    case "PRINT_LOT":
                        if (spdLabelList_Sheet1.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        if (spdLabelList.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        break;
                    case "PRINT_DLV_LOT":
                        if (spdArrivalLotList_Sheet1.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        if (spdArrivalLotList.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
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

        private void InitEnable()
        {
            try
            {
                grpDlvInvLabelList.Enabled = true;
                btnAdd.Enabled = true;
                btnDel.Enabled = true;
                btnProcess.Enabled = true;
                btnConfirm.Enabled = true;
                btnCancelConfirm.Enabled = true;
                txtQty.ReadOnly = false;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":
                        MPCF.ClearList(spdPOList);
                        MPCF.ClearList(spdArrivalLotList);
                        MPCF.ClearList(spdLabelList);
                        spdLabelList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdLabelList.ActiveSheet.ColumnFooter.Cells[0, 3].Value = 0;
                        InitEnable();
                        txtQty.Text = "";
                        txtVendorLotNo.Text = "";
                        dtpArrivalDate.Value = DateTime.Now;
                        txtTotalQty.Text = "";
                        txtLotSize.Text = "";
                        break;
                    case "ALL":
                        MPCF.ClearList(spdPOList);
                        MPCF.ClearList(spdArrivalLotList);
                        MPCF.ClearList(spdLabelList);
                        spdLabelList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdLabelList.ActiveSheet.ColumnFooter.Cells[0, 3].Value = 0;
                        InitEnable();
                        cdvDept.Text = "";
                        cdvVendorID.Text = "";
                        cdvMatID.Text = "";
                        txtQty.Text = "";
                        txtVendorLotNo.Text = "";
                        dtpArrivalDate.Value = DateTime.Now;
                        dtpToWorkDate.Value = DateTime.Now;
                        dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7.0);
                        txtTotalQty.Text = "";
                        txtLotSize.Text = "";
                        txtPONo.Text = "";
                        break;
                    case "PO_CLICK_CELL":
                        MPCF.ClearList(spdArrivalLotList);
                        MPCF.ClearList(spdLabelList);
                        spdLabelList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdLabelList.ActiveSheet.ColumnFooter.Cells[0, 3].Value = 0;
                        txtQty.Text = "";
                        txtVendorLotNo.Text = "";
                        dtpArrivalDate.Value = DateTime.Now;
                        txtTotalQty.Text = "";
                        txtLotSize.Text = "";
                        break;
                    case "ARRIVAL_LOT_CLICK_CELL":
                        MPCF.ClearList(spdLabelList);
                        spdLabelList.ActiveSheet.ColumnFooter.Cells[0, 0].Value = 0;
                        spdLabelList.ActiveSheet.ColumnFooter.Cells[0, 3].Value = 0;
                        txtTotalQty.Text = "";
                        txtLotSize.Text = "";
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmTranRegistArrivalLot_Load(object sender, EventArgs e)
        {
            try
            {
                dtpArrivalDate.Value = DateTime.Now;
                dtpToWorkDate.Value = DateTime.Now;
                dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7.0);
                dtpFromWorkDate.Format = DateTimePickerFormat.Custom;
                dtpFromWorkDate.CustomFormat = " ";
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

        private void cdvVendorID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvVendorID.DisplayText == "")
            {
                cdvVendorID.Text = "";
            }
        }

        private void dtpFromWorkDate_ValueChanged(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";
        }

        private void dtpFromWorkDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            Keys keyCode = e.KeyCode;
            Keys keys = keyCode;
            if (keys == Keys.Delete)
            {
                dtpFromWorkDate.CustomFormat = " ";
            }
        }

        private void chkLabelListSkip_CheckedChanged(object sender, EventArgs e)
        {
            if (chkLabelListSkip.Checked)
            {
                btnAdd.Enabled = false;
                btnDel.Enabled = false;
                btnProcess.Enabled = false;
                btnConfirm.Enabled = false;
            }
            else
            {
                btnAdd.Enabled = true;
                btnDel.Enabled = true;
                btnProcess.Enabled = true;
                btnConfirm.Enabled = true;
            }
        }

        private void btnGCM_Click(object sender, EventArgs e)
        {
            try
            {
                frmPopGcmData frmPopGcmData = new frmPopGcmData();
                frmPopGcmData.StartPosition = FormStartPosition.CenterParent;
                frmPopGcmData.sTable_name = "C_INSP_IQC_MESSAGE";
                if (MPGV.gcLanguage == '2')
                {
                    frmPopGcmData.sTable_name_desc = "메세지 받을 유저등록(검사완료)";
                    frmPopGcmData.sComment = "수입검사 완료 메세지를 받을 유더를 등록하세요.(합격,특채만 전송)";
                }
                else
                {
                    frmPopGcmData.sTable_name_desc = "Register users (IQC Completed msg)";
                    frmPopGcmData.sComment = "Register users to receive IQC completion messages(Pass,special Send only)";
                }
                if (frmPopGcmData.ShowDialog() == DialogResult.OK)
                {
                    frmPopGcmData = null;
                }
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
                frmPopVendorList frmPopVendorList = new frmPopVendorList();
                frmPopVendorList.StartPosition = FormStartPosition.CenterParent;
                if (frmPopVendorList.ShowDialog() == DialogResult.OK)
                {
                    cdvVendorID.Text = frmPopVendorList.g_VendorId;
                    cdvVendorID.DisplayText = frmPopVendorList.g_VendorDesc;
                    frmPopVendorList = null;
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
                frmPopMaterialList frmPopMaterialList = new frmPopMaterialList();
                frmPopMaterialList.StartPosition = FormStartPosition.CenterParent;
                frmPopMaterialList.sArea_id = cdvDept.Text;
                frmPopMaterialList.sArea_desc = cdvDept.DisplayText;
                if (frmPopMaterialList.ShowDialog() == DialogResult.OK)
                {
                    cdvMatID.Text = frmPopMaterialList.sMat_id;
                    frmPopMaterialList = null;
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
                if (CheckCondition("VIEW"))
                {
                    ClearList("VIEW");
                    ViewPOList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnArrive_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("ARRIVE") && CreateArrivalLot())
                {
                    ViewPrintDlvLabel(sDlvLotID);
                    ViewArrivalLotList(dlvNo, dlvSeq, matId, matVer);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnCancelArrival_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("CANCEL_ARRIVAL") && DeleteArrivalLot())
                {
                    ClearList("ARRIVAL_LOT_CLICK_CELL");
                    ViewArrivalLotList(dlvNo, dlvSeq, matId, matVer);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            double num = 0.0;
            double num2 = 0.0;
            double num3 = 0.0;
            int num4 = 0;
            int num5 = 0;
            int num6 = 0;
            int num7 = 0;
            try
            {
                if (!CheckCondition("ADD"))
                {
                    return;
                }
                num6 = spdArrivalLotList.ActiveSheet.ActiveRowIndex;
                num4 = spdLabelList_Sheet1.RowCount;
                for (int i = 0; i < spdLabelList_Sheet1.RowCount; i++)
                {
                    num3 += (double)MPCF.ToInt(spdLabelList_Sheet1.Cells[i, 3].Text);
                }
                num = MPCF.ToDbl(txtTotalQty.Text) - num3;
                num2 = MPCF.ToDbl(txtLotSize.Text);
                num7 = (int)(num / MPCF.ToDbl(txtLotSize.Text));
                if ((double)num7 * MPCF.ToDbl(txtLotSize.Text) < num)
                {
                    num7++;
                }
                if (num <= 0.0)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(126) + " [" + lblTotalQty.Text + "]");
                    txtTotalQty.Focus();
                    return;
                }
                for (int j = 0; j < num7; j++)
                {
                    spdLabelList_Sheet1.RowCount++;
                    num5 = spdLabelList_Sheet1.RowCount - 1;
                    spdLabelList_Sheet1.SetValue(num5, 0, true);
                    spdLabelList_Sheet1.Cells[num5, 1].Value = "";
                    spdLabelList_Sheet1.Cells[num5, 2].Value = spdLabelList_Sheet1.RowCount;
                    if (spdLabelList_Sheet1.RowCount == num7 + num4)
                    {
                        spdLabelList_Sheet1.Cells[num5, 3].Value = num.ToString();
                    }
                    else
                    {
                        spdLabelList_Sheet1.Cells[num5, 3].Value = num2.ToString();
                        num -= num2;
                    }
                    spdLabelList_Sheet1.Cells[num5, 4].Value = spdArrivalLotList.ActiveSheet.Cells[num6, 3].Text;
                    spdLabelList_Sheet1.Cells[num5, 5].Value = spdArrivalLotList.ActiveSheet.Cells[num6, 5].Text;
                    spdLabelList_Sheet1.Cells[num5, 6].Value = spdArrivalLotList.ActiveSheet.Cells[num6, 6].Text;
                    spdLabelList_Sheet1.Cells[num5, 7].Value = spdArrivalLotList.ActiveSheet.Cells[num6, 7].Text;
                    spdLabelList_Sheet1.Cells[num5, 8].Value = spdArrivalLotList.ActiveSheet.Cells[num6, 8].Text;
                    spdLabelList_Sheet1.Cells[num5, 9].Value = spdArrivalLotList.ActiveSheet.Cells[num6, 1].Text;
                }
                MPCF.FitColumnHeader(spdLabelList);
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
                for (int i = 0; i < spdLabelList_Sheet1.RowCount; i++)
                {
                    if (spdLabelList_Sheet1.Cells[i, 0].Text.ToString().ToUpper() == "TRUE")
                    {
                        spdLabelList_Sheet1.RemoveRows(i, 1);
                        i--;
                    }
                }
                for (int j = 0; j < spdLabelList_Sheet1.RowCount; j++)
                {
                    spdLabelList_Sheet1.Cells[j, 2].Value = j + 1;
                }
                MPCF.FitColumnHeader(spdLabelList);
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
                if (CheckCondition("SAVE") && CreateLabel())
                {
                    ViewLabelList(sArrivalLotID);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnConfirm_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("CONFIRM") && ConfirmDlvLot())
                {
                    ViewPOList();
                    ViewArrivalLotList(dlvNo, dlvSeq, matId, matVer);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnCancelConfirm_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("CONFIRM") && ConfirmCancelDlvLot())
                {
                    ViewPOList();
                    ViewArrivalLotList(dlvNo, dlvSeq, matId, matVer);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnLotPrint_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("PRINT_LOT") && !ViewPrintLabel(1))
                {
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDlvLotPrint_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("PRINT_DLV_LOT") && !ViewPrintDlvLabel())
                {
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdPOList_CellClick(object sender, CellClickEventArgs e)
        {
            ClearList("PO_CLICK_CELL");
            try
            {
                if (e.Row < 0 || e.ColumnHeader)
                {
                    return;
                }
                for (int i = 0; i < spdPOList.ActiveSheet.RowCount; i++)
                {
                    spdPOList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }
                spdPOList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);
                string obj = spdPOList.ActiveSheet.Cells[e.Row, 9].Text;
                string obj2 = spdPOList.ActiveSheet.Cells[e.Row, 10].Text;
                string obj3 = spdPOList.ActiveSheet.Cells[e.Row, 12].Text;
                obj = (MPCF.ToDbl(obj) - MPCF.ToDbl(obj2) - MPCF.ToDbl(obj3)).ToString();
                if (MPCF.Trim(obj) != "")
                {
                    txtQty.Text = obj;
                }
                dlvNo = spdPOList.ActiveSheet.Cells[e.Row, 0].Text;
                dlvSeq = spdPOList.ActiveSheet.Cells[e.Row, 1].Text;
                matId = spdPOList.ActiveSheet.Cells[e.Row, 7].Text;
                matVer = spdPOList.ActiveSheet.Cells[e.Row, 13].Text;
                matType = spdPOList.ActiveSheet.Cells[e.Row, 21].Text;
                moldFlag = spdPOList.ActiveSheet.Cells[e.Row, 19].Text;
                if (string.Equals(moldFlag, "Y"))
                {
                    InitEnable();
                    txtQty.Text = "1";
                    txtQty.ReadOnly = true;
                }
                else
                {
                    InitEnable();
                }
                if (e.Column == 22)
                {
                    if (spdPOList.ActiveSheet.Cells[e.Row, 10].Text == "0.00000")
                    {
                    }
                    if (spdPOList.ActiveSheet.Cells[e.Row, 19].Text == "Y")
                    {
                        if (MPCF.ShowMsgBox("PO LINE OPEN? (Please process ERP separately)? \r\n  해당라인 OPEN 하시겠습니까?(ERP는 별도 확인 및 처리하셔야합니다.) ", MessageBoxButtons.YesNo, 2) == DialogResult.Yes)
                        {
                        }
                    }
                    else if (MPCF.ShowMsgBox("PO LINE DELETE? (Please process ERP separately)? \r\n  해당라인 삭제하시겠습니까?(ERP는 별도 확인 및 처리하셔야합니다.) ", MessageBoxButtons.YesNo, 2) == DialogResult.Yes)
                    {
                    }
                }
                else
                {
                    ViewArrivalLotList(dlvNo, dlvSeq, matId, matVer);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdArrivalLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (spdArrivalLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdArrivalLotList, e.Row, e.Column, b_checked: true, b_isColHeaderCheckBox: true);
                    }
                }
                else
                {
                    if (e.Row < 0)
                    {
                        return;
                    }
                    ClearList("ARRIVAL_LOT_CLICK_CELL");
                    if (!e.ColumnHeader)
                    {
                        for (int i = 0; i < spdArrivalLotList.ActiveSheet.RowCount; i++)
                        {
                            spdArrivalLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                        }
                        spdArrivalLotList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);
                        string str = spdArrivalLotList.ActiveSheet.Cells[e.Row, 2].Text;
                        if (MPCF.Trim(str) != "")
                        {
                            txtTotalQty.Text = str;
                            txtLotSize.Text = str;
                        }
                        sArrivalLotID = spdArrivalLotList.ActiveSheet.Cells[e.Row, 1].Text;
                        ViewLabelList(sArrivalLotID);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                if (spdLabelList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdLabelList, e.Row, e.Column, b_checked: true, b_isColHeaderCheckBox: true);
                }
                CheckCount();
            }
        }

        private void spdLabelList_ButtonClicked(object sender, EditorNotifyEventArgs e)
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

        private void spdLabelList_Change(object sender, ChangeEventArgs e)
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

        private void txtPONo_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == '\r' && CheckCondition("VIEW"))
                {
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
            {
                cdvMatID.Text = "";
            }
        }



    }
}
