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
    public partial class frmTranRegistArrivalLotAnsan : CUS_COM.frmTranForm01
    {
        public frmTranRegistArrivalLotAnsan()
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

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
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
            TRSNode node = new TRSNode("Publish_Message_In");
            string sPublishChannel;

            try
            {
                MPCR.SetInMsg(node);
                node.ProcStep = '1';
                node.AddString("SEND_COMPUTER_ID", MPGV.gsComputerName);
                node.AddString("SEND_USER_ID", MPGV.gsUserID, true);
                node.AddString("SEND_USER_GROUP", MPGV.gsUserGroup);

                node.AddString("TO_FACTORY", MPCF.Trim(MPGV.gsFactory));
                node.AddString("TO_USER_GROUP", MPCF.Trim(sUserGroup));
                node.AddString("TO_USER_ID", MPCF.Trim(sUsserId), true);
                node.AddString("MESSAGE", "LOT ID : " + sLotId + " / ITEM : " + sMatDesc + " / QC Result:무검사(No Inspection) " + " / 검사완료 입고가능합니다.(Inspection Complete,Store Inv Please)");

                sPublishChannel = "/" + MPGV.gsSiteID;
                sPublishChannel += "/UTL";



                sPublishChannel += "/" + MPCF.Trim(MPGV.gsFactory);
                sPublishChannel += "/" + MPCF.Trim(sUserGroup);
                sPublishChannel += "/" + MPCF.Trim(sUsserId);

                if (MPCR.CallService("UTL", "UTL_Publish_Message", node, sPublishChannel) == false)
                {
                    return false;
                }

            }
            catch (Exception)
            {
                // MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;

        }


        private bool messageUserCheck(string sLotid, string sMatDesc)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            StringBuilder sb;


            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            sb = new StringBuilder();

            sb.Append("SELECT B.SEC_GRP_ID, A.KEY_1 FROM MGCMTBLDAT A LEFT JOIN MSECUSRDEF B ON A.FACTORY = B.FACTORY AND A.KEY_1 = B.USER_ID WHERE TABLE_NAME ='C_INSP_IQC_MESSAGE' ");


            in_node.AddString("SQL", sb.ToString());

            if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
            {
                return false;
            }

            for (int iRow = 0; iRow < out_node.GetList("ROWS").Count; iRow++)
            {
                // out_node.GetList("ROWS")[0].GetList("COLS")[0].GetString("DATA")
                if (SendMessage(out_node.GetList("ROWS")[iRow].GetList("COLS")[0].GetString("DATA"), out_node.GetList("ROWS")[iRow].GetList("COLS")[1].GetString("DATA"), sLotid, sMatDesc) == false)
                {
                    //return false;
                }

            }

            return true;
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

               if (TPDR.GetDataOne("", ref dt, "CINV2001-001", dvcArgu, false, false, ref sSql) == false)
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
                    spdPOList_Sheet1.Cells[i, (int)PO.DELETE_FLAG].Value = dt.Rows[i]["ERP_OPEN_YN"];
                    
                }
                MPCF.FitColumnHeader(spdPOList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //입하 자재 LOT LIST 조회 함수
        private void ViewArrivalLotList(string dlvNo, string dlvSeq, string matId, string matVer)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "DLV_NO";
                dvcArgu[1].sCondition_Value = dlvNo;

                dvcArgu[2].sCondition_ID = "DLV_SEQ";
                dvcArgu[2].sCondition_Value = dlvSeq;

                dvcArgu[3].sCondition_ID = "MAT_ID";
                dvcArgu[3].sCondition_Value = matId;

                dvcArgu[4].sCondition_ID = "MAT_VER";
                dvcArgu[4].sCondition_Value = matVer;

                if (TPDR.GetDataOne("", ref dt, "CINV2001-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdArrivalLotList);
                    return;
                }

                MPCF.ClearList(spdArrivalLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdArrivalLotList_Sheet1.RowCount++;

                    spdArrivalLotList_Sheet1.SetValue(i, (int)ARRIVALLOT.CHK, false);
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.DLV_LOT_ID].Value = dt.Rows[i]["DLV_LOT_ID"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.DLV_LOT_STATUS].Value = dt.Rows[i]["DLV_LOT_STATUS"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.DLV_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["DLV_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.INSP_ID].Value = dt.Rows[i]["INSP_ID"];
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.INSP_RESULT_FLAG].Value = dt.Rows[i]["INSP_RESULT_FLAG"];
                }
                MPCF.FitColumnHeader(spdArrivalLotList);

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
                for (int i = 0; i < spdLabelList_Sheet1.RowCount; i++)
                {
                    if (spdLabelList_Sheet1.Cells[i, (int)LABEL.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdLabelList_Sheet1.Cells[i, (int)LABEL.QTY].Text);
                    }
                }

                spdLabelList_Sheet1.ColumnFooter.Cells[0, (int)LABEL.CHK].Value = iCount;
                spdLabelList_Sheet1.ColumnFooter.Cells[0, (int)LABEL.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //LABEL LIST 조회 함수
        private void ViewLabelList(string arrivalLotID)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                double dSumQty = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "DLV_LOT_ID";
                dvcArgu[1].sCondition_Value = arrivalLotID;

                if (TPDR.GetDataOne("", ref dt, "CINV2001-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLabelList);
                    return;
                }

                MPCF.ClearList(spdLabelList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLabelList_Sheet1.RowCount++;

                    spdLabelList_Sheet1.SetValue(i, (int)LABEL.CHK, false);
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.LABEL_ID].Value = dt.Rows[i]["LABEL_ID"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.SEQ].Value = dt.Rows[i]["SEQ"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.QTY].Value = dt.Rows[i]["QTY"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.DLV_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["DLV_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.DLV_LOT_ID].Value = dt.Rows[i]["DLV_LOT_ID"];
                }
                MPCF.FitColumnHeader(spdLabelList);

                for (i = 0; i < spdLabelList_Sheet1.RowCount; i++)
                {
                    dSumQty += MPCF.ToDbl(spdLabelList.ActiveSheet.Cells[i, (int)LABEL.QTY].Text);
                }

                spdLabelList.ActiveSheet.ColumnFooter.Cells[0, (int)LABEL.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //입하 자재 LOT 생성
        private bool CreateArrivalLot()
        {
            TRSNode in_node = new TRSNode("create_Arrival_Lot_In");
            TRSNode out_node = new TRSNode("create_Arrival_Lot_Out");
            
            if(MPCF.ToDbl(this.txtQty.Text) == 0)
            {
                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblQty.Text + "]");
                txtQty.Focus();
                return false;
            }


            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("MAT_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.MAT_ID].Text);
                in_node.AddInt("MAT_VER", MPCF.ToInt(spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.MAT_VER].Text));
                in_node.AddDouble("QTY", MPCF.ToDbl(this.txtQty.Text));
                in_node.AddDouble("QTY_2", 0);
                in_node.AddDouble("QTY_3", 0);
                in_node.AddString("DLV_NO", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.DLV_NO].Text);
                in_node.AddInt("DLV_SEQ", MPCF.ToInt(spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.DLV_SEQ].Text));
                in_node.AddString("DLV_TIME", MPCF.DestroyDateFormat(dtpArrivalDate.Text));
                in_node.AddString("VENDOR_LOT_ID", this.txtVendorLotNo.Text);
                in_node.AddString("VENDOR_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.VENDOR_ID].Text);
                in_node.AddString("VENDOR_SITE_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.VENDOR_SITE_ID].Text);
                in_node.AddString("DLV_LOT_ID", "");

                if (MPCR.CallService("CUS_INV", "CUS_INV_Create_Dlv_Lot", in_node, ref out_node) == false)
                    return false;


                sDlvLotID = MPCF.Trim(out_node.GetString("DLV_LOT_ID"));
                dQty = MPCF.ToDbl(this.txtQty.Text);


                if (chkLabelListSkip.Checked == true)
                {
                    if(CreateLabel2() == true)
                    {
                        MPCR.ShowSuccessMsg(out_node);
                    }
                    else
                    {
                        return false;
                    }
    

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

        //입하 자재 LOT 생성
        private bool DeleteArrivalLot()
        {
            TRSNode in_node = new TRSNode("create_Arrival_Lot_In");
            TRSNode out_node = new TRSNode("create_Arrival_Lot_Out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("DLV_LOT_ID", spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, (int)ARRIVALLOT.DLV_LOT_ID].Text);
                
                if (MPCR.CallService("CUS_INV", "CUS_INV_Delete_Dlv_Lot", in_node, ref out_node) == false)
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

        //입하 자재 라벨 생성
        private bool CreateLabel()
        {
            TRSNode in_node = new TRSNode("create_Label_In");
            TRSNode out_node = new TRSNode("create_Label_Out");
            TRSNode label_list;
            double d_total_label_qty = 0;
            bool send_flag = false;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("DLV_LOT_ID", spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, (int)ARRIVALLOT.DLV_LOT_ID].Text);
                in_node.AddString("VENDOR_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.VENDOR_ID].Text);
                in_node.AddString("VENDOR_SITE_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.VENDOR_SITE_ID].Text);

                for (int i = 0; i < spdLabelList_Sheet1.RowCount; i++)
                {
                    if (spdLabelList_Sheet1.Cells[i, (int)LABEL.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        label_list = in_node.AddNode("INV_LOT_LIST");
                        label_list.AddString("LABEL_ID", spdLabelList_Sheet1.Cells[i, (int)LABEL.LABEL_ID].Text);
                        label_list.AddDouble("QTY", MPCF.ToDbl(spdLabelList_Sheet1.Cells[i, (int)LABEL.QTY].Text));
                        label_list.AddDouble("QTY_2", 0);
                        label_list.AddDouble("QTY_3", 0);

                        d_total_label_qty += MPCF.ToDbl(spdLabelList_Sheet1.Cells[i, (int)LABEL.QTY].Text);

                        send_flag = true;
                    }
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCF.ToDbl(spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, (int)ARRIVALLOT.QTY].Text) != d_total_label_qty)
                {
                    //CMN202 ERROR - 입력수량이 현재의 수량과 일치하지 않습니다..
                    MPCF.ShowMsgBox(MPCF.GetMessage(202));
                    return false;
                }

                if (MPCR.CallService("CUS_INV", "CUS_INV_Create_Dlv_Label", in_node, ref out_node) == false)
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



        //입하 자재 라벨 생성
        private bool CreateLabel2()
        {
            TRSNode in_node = new TRSNode("create_Label_In");
            TRSNode out_node = new TRSNode("create_Label_Out");
            TRSNode label_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("DLV_LOT_ID", sDlvLotID);
                in_node.AddString("VENDOR_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.VENDOR_ID].Text);
                in_node.AddString("VENDOR_SITE_ID", spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.VENDOR_SITE_ID].Text);

                label_list = in_node.AddNode("INV_LOT_LIST");
                label_list.AddString("LABEL_ID", sDlvLotID);
                label_list.AddDouble("QTY", dQty);
                label_list.AddDouble("QTY_2", 0);
                label_list.AddDouble("QTY_3", 0);




                if (MPCR.CallService("CUS_INV", "CUS_INV_Create_Dlv_Label", in_node, ref out_node) == false)
                {
                    return false;
                }
                else
                {
                    if (ConfirmDlvLot2() == false)
                    {
                        return false;
                    }
                }


                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }




        //입하 자재 확정
        private bool ConfirmDlvLot2()
        {
            TRSNode in_node = new TRSNode("confirm_dlv_Lot_In");
            TRSNode out_node = new TRSNode("confirm_dlv_Lot_Out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("DLV_LOT_ID", sDlvLotID);

                if (MPCR.CallService("CUS_INV", "CUS_INV_Confirm_Dlv_Lot", in_node, ref out_node) == false)
                {
                    return false;
                }
                else
                {
                   // ViewPrintLabel(2);
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
            TRSNode in_node = new TRSNode("confirm_dlv_Lot_In");
            TRSNode out_node = new TRSNode("confirm_dlv_Lot_Out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("DLV_LOT_ID", spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, (int)ARRIVALLOT.DLV_LOT_ID].Text);

                if (MPCR.CallService("CUS_INV", "CUS_INV_Confirm_Dlv_Lot", in_node, ref out_node) == false)
                    return false;



                string sLotId = spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, (int)ARRIVALLOT.DLV_LOT_ID].Text;
                string sMAaDesc = spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, (int)ARRIVALLOT.MAT_DESC].Text;


                if(spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.INSPECTION_FLAG].Text == "N")
                {
                    messageUserCheck(sLotId, sMAaDesc);
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

        //입하 자재 확정 취소
        private bool ConfirmCancelDlvLot()
        {
            TRSNode in_node = new TRSNode("confirm_cancel_dlv_Lot_In");
            TRSNode out_node = new TRSNode("confirm_cancel_dlv_Lot_Out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("DLV_LOT_ID", spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, (int)ARRIVALLOT.DLV_LOT_ID].Text);
                
                if (MPCR.CallService("CUS_INV", "CUS_INV_Confirm_Dlv_Lot", in_node, ref out_node) == false)
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

        public bool ViewPrintLabel(int step)
        {
            try
            {
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                string file_name = "mtl100p";

                MPCR.SetInMsg(in_node);
                

                if(step == 1)
                {
                    for (int i = 0; i < spdLabelList_Sheet1.RowCount; i++)
                    {
                        if (spdLabelList_Sheet1.Cells[i, (int)LABEL.CHK].Text.ToString().ToUpper() == "TRUE")
                        {
                            label_list = in_node.AddNode("INV_LOT_LIST");
                            label_list.AddString("DLV_LOT_ID", spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, (int)ARRIVALLOT.DLV_LOT_ID].Text);
                            label_list.AddString("INV_LOT_ID", spdLabelList_Sheet1.Cells[i, (int)LABEL.LABEL_ID].Text);
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < spdLabelList_Sheet1.RowCount; i++)
                    {
                        label_list = in_node.AddNode("INV_LOT_LIST");
                        label_list.AddString("DLV_LOT_ID", spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, (int)ARRIVALLOT.DLV_LOT_ID].Text);
                        label_list.AddString("INV_LOT_ID", spdLabelList_Sheet1.Cells[i, (int)LABEL.LABEL_ID].Text);
                    }
                }
                

                CSCF.ViewLabelList(file_name, in_node);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //입하 라벨 발행
        public bool ViewPrintDlvLabel(string sLotId = "")
        {
            try
            {
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                string file_name = "mtl100pa";
                
                if(!string.IsNullOrEmpty(sLotId))
                {
                    label_list = in_node.AddNode("INV_LOT_LIST");
                    label_list.AddString("DLV_LOT_ID", sLotId);
                }
                else
                {
                    for (int i = 0; i < spdArrivalLotList_Sheet1.RowCount; i++)
                    {
                        if (spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.CHK].Text.ToString().ToUpper() == "TRUE")
                        {
                            label_list = in_node.AddNode("INV_LOT_LIST");
                            label_list.AddString("DLV_LOT_ID", spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.DLV_LOT_ID].Text);
                        }
                    }
                }

                CSCF.ViewLabelList(file_name, in_node);

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
                        if (spdPOList_Sheet1.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdArrivalLotList_Sheet1.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdLabelList_Sheet1.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        break;

                    case "CONFIRM":

                        if (spdArrivalLotList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        break;
                        
                    case "ARRIVE":
                        if (MPCF.Trim(this.txtQty.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblQty.Text + "]");
                            txtQty.Focus();
                            return false;
                        }

                        if (MPCF.Trim(this.txtVendorLotNo.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblVendorLotNo.Text + "]");
                            txtVendorLotNo.Focus();
                            return false;
                        }

                        if (spdPOList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        //if (MPCF.ToDbl(spdPOList.ActiveSheet.Cells[spdPOList.ActiveSheet.ActiveRowIndex, (int)PO.QTY].Text) < MPCF.ToDbl(this.txtQty.Text))
                        //{
                        //    //CMN126 ERROR -입력한 값이 한계값을 넘었습니다.다른 수를 입력해 주세요.
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(126) + " [" + lblQty.Text + "]");
                        //    txtQty.Focus();
                        //    return false;
                        //}
                        break;

                    case "CANCEL_ARRIVAL":
                        if (spdArrivalLotList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        
                        break;

                    case "ADD":
                        if (MPCF.Trim(this.txtTotalQty.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblTotalQty.Text + "]");
                            txtTotalQty.Focus();
                            return false;
                        }

                        if (MPCF.Trim(this.txtLotSize.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotSize.Text + "]");
                            txtLotSize.Focus();
                            return false;
                        }

                        if (spdArrivalLotList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        break;

                    case "PRINT_LOT":
                        
                        if (spdLabelList_Sheet1.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdLabelList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        break;

                    case "PRINT_DLV_LOT":

                        if (spdArrivalLotList_Sheet1.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdArrivalLotList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
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
        
        //활성화 초기화
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
            catch(Exception ex)
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

                        MPCF.ClearList(spdPOList);
                        MPCF.ClearList(spdArrivalLotList);
                        MPCF.ClearList(spdLabelList);
                        spdLabelList.ActiveSheet.ColumnFooter.Cells[0, (int)LABEL.CHK].Value = 0;
                        spdLabelList.ActiveSheet.ColumnFooter.Cells[0, (int)LABEL.QTY].Value = 0;

                        InitEnable();

                        this.txtQty.Text = "";
                        this.txtVendorLotNo.Text = "";
                        this.dtpArrivalDate.Value = DateTime.Now;
                        this.txtTotalQty.Text = "";
                        this.txtLotSize.Text = "";
                        break;
                        
                    case "ALL":

                        MPCF.ClearList(spdPOList);
                        MPCF.ClearList(spdArrivalLotList);
                        MPCF.ClearList(spdLabelList);
                        spdLabelList.ActiveSheet.ColumnFooter.Cells[0, (int)LABEL.CHK].Value = 0;
                        spdLabelList.ActiveSheet.ColumnFooter.Cells[0, (int)LABEL.QTY].Value = 0;

                        InitEnable();

                        this.cdvDept.Text = "";
                        this.cdvVendorID.Text = "";
                        this.cdvMatID.Text = "";
                        this.txtQty.Text = "";
                        this.txtVendorLotNo.Text = "";
                        this.dtpArrivalDate.Value = DateTime.Now;
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
                        this.txtTotalQty.Text = "";
                        this.txtLotSize.Text = "";
                        this.txtPONo.Text = "";
                        break;

                    case "PO_CLICK_CELL":
                        
                        MPCF.ClearList(spdArrivalLotList);
                        MPCF.ClearList(spdLabelList);
                        spdLabelList.ActiveSheet.ColumnFooter.Cells[0, (int)LABEL.CHK].Value = 0;
                        spdLabelList.ActiveSheet.ColumnFooter.Cells[0, (int)LABEL.QTY].Value = 0;

                        this.txtQty.Text = "";
                        this.txtVendorLotNo.Text = "";
                        dtpArrivalDate.Value = DateTime.Now;
                        this.txtTotalQty.Text = "";
                        this.txtLotSize.Text = "";
                        break;

                    case "ARRIVAL_LOT_CLICK_CELL":
                        
                        MPCF.ClearList(spdLabelList);
                        spdLabelList.ActiveSheet.ColumnFooter.Cells[0, (int)LABEL.CHK].Value = 0;
                        spdLabelList.ActiveSheet.ColumnFooter.Cells[0, (int)LABEL.QTY].Value = 0;

                        this.txtTotalQty.Text = "";
                        this.txtLotSize.Text = "";
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region "Event Definition "
        private void frmTranRegistArrivalLotAnsan_Load(object sender, EventArgs e)
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

        private void btnArrive_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("ARRIVE") == false)
                    return;

                if (CreateArrivalLot())
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
                if (CheckCondition("CANCEL_ARRIVAL") == false)
                    return;

                if (DeleteArrivalLot())
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
            double d_total_Qty = 0;
            double d_lot_Qty = 0;
            double d_create_qty = 0;
            int beforeRowCount = 0;
            int currentRowCount = 0;
            int i_activeRow = 0;
            int i_lot_count = 0;

            try
            {
                if (CheckCondition("ADD") == false)
                    return;

                i_activeRow = spdArrivalLotList.ActiveSheet.ActiveRowIndex;

                beforeRowCount = spdLabelList_Sheet1.RowCount;

                for (int i = 0; i < spdLabelList_Sheet1.RowCount; i++)
                {
                    d_create_qty += MPCF.ToInt(spdLabelList_Sheet1.Cells[i, (int)LABEL.QTY].Text);
                }

                d_total_Qty = MPCF.ToDbl(this.txtTotalQty.Text) - d_create_qty;
                d_lot_Qty = MPCF.ToDbl(this.txtLotSize.Text);
                i_lot_count = (int)(d_total_Qty / MPCF.ToDbl(this.txtLotSize.Text));
                
                if(i_lot_count * MPCF.ToDbl(this.txtLotSize.Text) < d_total_Qty)
                {
                    i_lot_count++;
                }

                if(d_total_Qty <= 0)
                {
                    //CMN126 ERROR -입력한 값이 한계값을 넘었습니다.다른 수를 입력해 주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(126) + " [" + lblTotalQty.Text + "]");
                    txtTotalQty.Focus();
                    return;
                }

                for (int i = 0; i < i_lot_count; i++)
                {
                    spdLabelList_Sheet1.RowCount++;

                    currentRowCount = spdLabelList_Sheet1.RowCount - 1;
                    spdLabelList_Sheet1.SetValue(currentRowCount, (int)LABEL.CHK, true);
                    spdLabelList_Sheet1.Cells[currentRowCount, (int)LABEL.LABEL_ID].Value = "";
                    spdLabelList_Sheet1.Cells[currentRowCount, (int)LABEL.SEQ].Value = spdLabelList_Sheet1.RowCount;

                    if (spdLabelList_Sheet1.RowCount == i_lot_count + beforeRowCount)
                    {
                        spdLabelList_Sheet1.Cells[currentRowCount, (int)LABEL.QTY].Value = d_total_Qty.ToString();
                    }
                    else
                    {
                        spdLabelList_Sheet1.Cells[currentRowCount, (int)LABEL.QTY].Value = d_lot_Qty.ToString();
                        d_total_Qty -= d_lot_Qty;
                    }
                    
                    spdLabelList_Sheet1.Cells[currentRowCount, (int)LABEL.UNIT].Value = spdArrivalLotList.ActiveSheet.Cells[i_activeRow, (int)ARRIVALLOT.UNIT].Text;
                    spdLabelList_Sheet1.Cells[currentRowCount, (int)LABEL.MAT_ID].Value = spdArrivalLotList.ActiveSheet.Cells[i_activeRow, (int)ARRIVALLOT.MAT_ID].Text;
                    spdLabelList_Sheet1.Cells[currentRowCount, (int)LABEL.MAT_VER].Value = spdArrivalLotList.ActiveSheet.Cells[i_activeRow, (int)ARRIVALLOT.MAT_VER].Text;
                    spdLabelList_Sheet1.Cells[currentRowCount, (int)LABEL.MAT_DESC].Value = spdArrivalLotList.ActiveSheet.Cells[i_activeRow, (int)ARRIVALLOT.MAT_DESC].Text;
                    spdLabelList_Sheet1.Cells[currentRowCount, (int)LABEL.DLV_TIME].Value = spdArrivalLotList.ActiveSheet.Cells[i_activeRow, (int)ARRIVALLOT.DLV_TIME].Text;
                    spdLabelList_Sheet1.Cells[currentRowCount, (int)LABEL.DLV_LOT_ID].Value = spdArrivalLotList.ActiveSheet.Cells[i_activeRow, (int)ARRIVALLOT.DLV_LOT_ID].Text;
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
                    if (spdLabelList_Sheet1.Cells[i, (int)LABEL.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        spdLabelList_Sheet1.RemoveRows(i, 1);
                        i--;
                    }
                }

                for (int i = 0; i < spdLabelList_Sheet1.RowCount; i++)
                {
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.SEQ].Value = i + 1;
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
                if (CheckCondition("SAVE") == false)
                    return;

                if (CreateLabel())
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
                if (CheckCondition("CONFIRM") == false)
                    return;

                if (ConfirmDlvLot())
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
                if (CheckCondition("CONFIRM") == false)
                    return;

                if (ConfirmCancelDlvLot())
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
                if (CheckCondition("PRINT_LOT") == false)
                    return;

                if (ViewPrintLabel(1))
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
                if (CheckCondition("PRINT_DLV_LOT") == false)
                    return;

                if (ViewPrintDlvLabel())
                {
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
                    this.txtQty.Text = sQty;
                }

                dlvNo = spdPOList.ActiveSheet.Cells[e.Row, (int)PO.DLV_NO].Text;
                dlvSeq = spdPOList.ActiveSheet.Cells[e.Row, (int)PO.DLV_SEQ].Text;
                matId = spdPOList.ActiveSheet.Cells[e.Row, (int)PO.MAT_ID].Text;
                matVer = spdPOList.ActiveSheet.Cells[e.Row, (int)PO.MAT_VER].Text;
                matType = spdPOList.ActiveSheet.Cells[e.Row, (int)PO.MAT_TYPE].Text;
                moldFlag = spdPOList.ActiveSheet.Cells[e.Row, (int)PO.MAT_CMF_9].Text;

                //금형일 경우
                if (string.Equals(moldFlag, "Y"))
                {
                    /*
                    grpDlvInvLabelList.Enabled = false;
                    btnAdd.Enabled = false;
                    btnDel.Enabled = false;
                    btnProcess.Enabled = false;
                    btnConfirm.Enabled = false;
                    btnCancelConfirm.Enabled = false;
                    */

                    InitEnable();
                    txtQty.Text = "1";
                    txtQty.ReadOnly = true;
                }
                else
                {
                    InitEnable();
                }


                if (e.Column == (int)PO.DELETE_FLAG)
                {
                    if (spdPOList.ActiveSheet.Cells[e.Row, (int)PO.DLV_IN_QTY].Text == "0.00000")
                    {

                    } 


                    if (spdPOList.ActiveSheet.Cells[e.Row, (int)PO.MAT_CMF_9].Text == "Y")
                    {
                        if (MPCF.ShowMsgBox("PO LINE OPEN? (Please process ERP separately)? \r\n  해당라인 OPEN 하시겠습니까?(ERP는 별도 확인 및 처리하셔야합니다.) ", MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                        {

                        }
                    }
                    else
                    {
                        if (MPCF.ShowMsgBox("PO LINE DELETE? (Please process ERP separately)? \r\n  해당라인 삭제하시겠습니까?(ERP는 별도 확인 및 처리하셔야합니다.) ", MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                        {

                        }
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
        
        private void spdArrivalLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (spdArrivalLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdArrivalLotList, e.Row, e.Column, true, true, false);
                    }
                }
                else
                {
                    if (e.Row < 0)
                    {
                        return;
                    }

                    string sQty;

                    ClearList("ARRIVAL_LOT_CLICK_CELL");

                    if (e.ColumnHeader == true)
                    {
                        return;
                    }

                    for (int i = 0; i < spdArrivalLotList.ActiveSheet.RowCount; i++)
                    {
                        spdArrivalLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                    }

                    spdArrivalLotList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                    sQty = spdArrivalLotList.ActiveSheet.Cells[e.Row, (int)ARRIVALLOT.QTY].Text;

                    if (MPCF.Trim(sQty) != "")
                    {
                        this.txtTotalQty.Text = sQty;
                        this.txtLotSize.Text = sQty;
                    }

                    sArrivalLotID = spdArrivalLotList.ActiveSheet.Cells[e.Row, (int)ARRIVALLOT.DLV_LOT_ID].Text;

                    ViewLabelList(sArrivalLotID);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLabelList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdLabelList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdLabelList, e.Row, e.Column, true, true, false);
                }

                CheckCount();
            }
        }

        private void spdLabelList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
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

        private void spdLabelList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
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

                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = "C_INSP_IQC_MESSAGE";

                if (MPGV.gcLanguage == '2')
                {
                    popup.sTable_name_desc = "메세지 받을 유저등록(검사완료)";
                    popup.sComment = "수입검사 완료 메세지를 받을 유더를 등록하세요.(합격,특채만 전송)";

                }
                else
                {
                    popup.sTable_name_desc = "Register users (IQC Completed msg)";
                    popup.sComment = "Register users to receive IQC completion messages(Pass,special Send only)";

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
