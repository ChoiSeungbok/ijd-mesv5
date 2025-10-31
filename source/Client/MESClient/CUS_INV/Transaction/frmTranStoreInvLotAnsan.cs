using System;
using System.Data;
using System.Drawing;
using System.Windows.Forms;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using FarPoint.Win.Spread;

namespace CUS_INV
{
    public partial class frmTranStoreInvLotAnsan : CUS_COM.frmTranForm01
    {
        public frmTranStoreInvLotAnsan()
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
            VENDOR_SITE_ID,        // 16 : 협력사 SITE ID
            VENDOR_DESC,           // 17 : 업체명
            INSPECTION_FLAG,       // 18 : 검사 여부
            CONSIGNMENT_FLAG       // 19 : 위탁 여부
        }

        private enum ARRIVALLOT
        {
            DLV_LOT_ID,                // 1 : 입하 LOT ID
            QTY,                       // 2 : 수량
            UNIT,                      // 3 : 단위
            DLV_LOT_STATUS,            // 4 : 입하 LOT 상태
            MAT_ID,                    // 5 : 제품
            MAT_VER,                   // 6 : 버전
            MAT_DESC,                  // 7 : 제품명
            DLV_TIME,                  // 8 : 입하일
            VENDOR_LOT_ID,             // 9 : 업체 LOT ID
            INSP_ID,                   // 10 : 수입 검사 ID
            INSP_RESULT_FLAG,          // 11 : 수입검사 결과
            SELECT,                    // 12 : 선택여부
            COMMENT                    // 13: COMMENT
        }

        private enum LABEL
        {
            LABEL_ID,                // 1 : 라벨 ID
            SEQ,                     // 2 : 순번
            QTY,                     // 3 : 수량
            UNIT,                    // 4 : 단위
            MAT_ID,                  // 5 : 제품
            MAT_VER,                 // 6 : 버전
            MAT_DESC,                // 7 : 제품명
            DLV_TIME,                // 8 : 입하일
            DLV_LOT_ID               // 9 : 입하 LOT ID
        }


        #endregion

        #region " Variable Definition "
        string dlvNo;
        string dlvSeq;
        string matId;
        string matVer;
        string sArrivalLotID;
        string consignmentFlag;
        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnStore.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnCancel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;

                ViewHidden();
                InspStatusdefault();
                LotStatusdefault();

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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[10];
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

                dvcArgu[4].sCondition_ID = "DELETE_FLAG";
                dvcArgu[4].sCondition_Value = cdvDeleteFlag.Text;

                dvcArgu[5].sCondition_ID = "FROM_DATE";
                dvcArgu[5].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));

                dvcArgu[6].sCondition_ID = "TO_DATE";
                dvcArgu[6].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";

                dvcArgu[7].sCondition_ID = "PO_NO";
                dvcArgu[7].sCondition_Value = txtPONo.Text;

                dvcArgu[8].sCondition_ID = "DLV_LOT_STATUS";
                dvcArgu[8].sCondition_Value = cdvLotStatus.Text;

                dvcArgu[9].sCondition_ID = "INSP_RESULT_FLAG";
                dvcArgu[9].sCondition_Value = cdvInspStatus.Text;



                if (TPDR.GetDataOne("", ref dt, "CINV2002-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdPOList);

                    txtPONo.SelectAll();
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
                }

                txtPONo.SelectAll();
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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "P_FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "P_DLV_NO";
                dvcArgu[1].sCondition_Value = dlvNo;

                dvcArgu[2].sCondition_ID = "P_DLV_SEQ";
                dvcArgu[2].sCondition_Value = dlvSeq;

                dvcArgu[3].sCondition_ID = "P_MAT_ID";
                dvcArgu[3].sCondition_Value = matId;

                dvcArgu[4].sCondition_ID = "P_MAT_VER";
                dvcArgu[4].sCondition_Value = matVer;



                dvcArgu[5].sCondition_ID = "DLV_LOT_STATUS";
                dvcArgu[5].sCondition_Value = cdvLotStatus.Text;

                dvcArgu[6].sCondition_ID = "INSP_RESULT_FLAG";
                dvcArgu[6].sCondition_Value = cdvInspStatus.Text;

                if (TPDR.GetDataOne("", ref dt, "CINV2002-002", dvcArgu, false, false, ref sSql) == false)
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
                    spdArrivalLotList_Sheet1.Cells[i, (int)ARRIVALLOT.COMMENT].Value = dt.Rows[i]["COMMENT_1"];
                }
                MPCF.FitColumnHeader(spdArrivalLotList);

                LabelListSearch();

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

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDeleteFlag_ButtonPress(object sender, EventArgs e)
        {
            //DELETE FLAG 추가
            cdvDeleteFlag.Init();
            MPCF.InitListView(cdvDeleteFlag.GetListView);

            cdvDeleteFlag.Columns.Add("Flag", 30, HorizontalAlignment.Left);

            ListViewItem item = new ListViewItem("Y", 14);
            item.SubItems.Add("Y");
            cdvDeleteFlag.Items.Add(item);

            cdvDeleteFlag.InsertEmptyRow(0, 1);
        }

        //입고 자재 LOT 생성
        private bool CreateInvLot()
        {
            TRSNode in_node = new TRSNode("create_Lot_In");
            TRSNode out_node = new TRSNode("create_Lot_Out");
            TRSNode inv_lot_list;
            bool send_flag = false;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("DLV_LOT_ID", spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, (int)ARRIVALLOT.DLV_LOT_ID].Text);
                in_node.AddString("TRAN_COMMENT", spdArrivalLotList.ActiveSheet.Cells[spdArrivalLotList.ActiveSheet.ActiveRowIndex, (int)ARRIVALLOT.COMMENT].Text);
                in_node.AddString("OPER", cdvWarehouse.Text);

                for (int i = 0; i < spdLabelList_Sheet1.RowCount; i++)
                {
                    inv_lot_list = in_node.AddNode("INV_LOT_LIST");
                    inv_lot_list.AddString("INV_LOT_ID", spdLabelList_Sheet1.Cells[i, (int)LABEL.LABEL_ID].Text);
                    inv_lot_list.AddDouble("QTY", MPCF.ToDbl(spdLabelList_Sheet1.Cells[i, (int)LABEL.QTY].Text));
                    inv_lot_list.AddDouble("QTY_2", 0);
                    inv_lot_list.AddDouble("QTY_3", 0);
                    send_flag = true;
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_INV", "CUS_INV_Create_Lot", in_node, ref out_node) == false)
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

        private bool DeleteInvLot()
        {
            TRSNode in_node = new TRSNode("delete_Lot_In");
            TRSNode out_node = new TRSNode("delete_Lot_Out");
            SheetView svArrive = spdArrivalLotList.ActiveSheet;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("DLV_LOT_ID", svArrive.Cells[svArrive.ActiveRowIndex, (int)ARRIVALLOT.DLV_LOT_ID].Text);
                
                if (MPCR.CallService("CUS_INV", "CUS_INV_Delete_Lot", in_node, ref out_node) == false)
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

        //입하 자재 LOT 삭제
        private bool ReturnArrivalLot()
        {
            TRSNode in_node = new TRSNode("create_Arrival_Lot_In");
            TRSNode out_node = new TRSNode("create_Arrival_Lot_Out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
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

        //벨리데이션 체크
        private bool CheckCondition(string sType)
        {
            try
            {
                SheetView svArriveLot = spdArrivalLotList.ActiveSheet;
                SheetView svLabel = spdLabelList.ActiveSheet;
                int iSelection = -1;

                for (int i = 0; i < svArriveLot.RowCount; i++)
                {
                    if(MPCF.Trim(svArriveLot.Cells[i, (int)ARRIVALLOT.SELECT].Value) == "Y")
                    {
                        iSelection = i;
                        break;
                    }
                }

                int iArriveRow = svArriveLot.ActiveRowIndex;
                
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }
                
                switch (sType)
                {
                    case "STORE":
                        if (MPCF.Trim(cdvWarehouse.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWarehouse.Text + "]");
                            cdvWarehouse.Focus();
                            return false;
                        }

                        if (iArriveRow < 0 || iSelection < 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox("DLV LOT" + MPCF.GetMessage(109));
                            return false;
                        }

                        if(svArriveLot.Cells[iArriveRow, (int)ARRIVALLOT.DLV_LOT_STATUS].Value.ToString() != "CONFIRM")
                        {
                            //CMN467 INFO - 입하LOT의 상태가 맞지 않습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(467));
                            return false;
                        }
                        
                        //LABEL검사
                        if (svLabel.RowCount <= 0)
                        {
                            //CMN466 INFO - 리스트가 존재하지 않습니다. 확인해주세요.
                            MPCF.ShowMsgBox("INV LOT LABEL " + MPCF.GetMessage(466));
                            return false;
                        }

                        break;

                    case "RETURN":

                        if (iArriveRow < 0 || iSelection < 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox("DLV LOT" + MPCF.GetMessage(109));
                            return false;
                        }

                        if (svArriveLot.Cells[iArriveRow, (int)ARRIVALLOT.DLV_LOT_STATUS].Value.ToString() != "CONFIRM")
                        {
                            //CMN467 INFO - 입하LOT의 상태가 맞지 않습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(467));
                            return false;
                        }

                        //LABEL검사
                        if (svLabel.RowCount <= 0)
                        {
                            //CMN466 INFO - 리스트가 존재하지 않습니다. 확인해주세요.
                            MPCF.ShowMsgBox("INV LOT LABEL " + MPCF.GetMessage(466));
                            return false;
                        }

                        break;

                    case "CANCEL":
                        if (iArriveRow < 0 || iSelection < 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox("DLV LOT" + MPCF.GetMessage(109));
                            return false;
                        }

                        if (svArriveLot.Cells[iArriveRow, (int)ARRIVALLOT.DLV_LOT_STATUS].Value.ToString() != "COMPLETED")
                        {
                            //CMN467 INFO - 입하LOT의 상태가 맞지 않습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(467));
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
                        this.cdvWarehouse.Text = "";
                        consignmentFlag = "";
                        MPCF.ClearList(spdPOList);
                        MPCF.ClearList(spdArrivalLotList);
                        MPCF.ClearList(spdLabelList);
                        break;
                        
                    case "ALL":

                        MPCF.ClearList(spdPOList);
                        MPCF.ClearList(spdArrivalLotList);
                        MPCF.ClearList(spdLabelList);

                        this.cdvDept.Text = "";
                        this.cdvVendorID.Text = "";
                        this.cdvMatID.Text = "";
                        this.txtPONo.Text = "";
                        this.cdvWarehouse.Text = "";
                        consignmentFlag = "";
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
                        
                        break;

                    case "PO_CLICK_CELL":
                        
                        MPCF.ClearList(spdArrivalLotList);
                        MPCF.ClearList(spdLabelList);
                        this.cdvWarehouse.Text = "";
                        break;

                    case "ARRIVAL_LOT_CLICK_CELL":
                        
                        MPCF.ClearList(spdLabelList);
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        private void ViewHidden()
        {
            spdPOList_Sheet1.Columns.Get((int)PO.BL_NO).Visible = false;
            spdPOList_Sheet1.Columns.Get((int)PO.BL_SEQ).Visible = false;
            spdPOList_Sheet1.Columns.Get((int)PO.MAT_VER).Visible = false;

            spdArrivalLotList_Sheet1.Columns.Get((int)ARRIVALLOT.MAT_VER).Visible = false;
            spdLabelList_Sheet1.Columns.Get((int)LABEL.MAT_VER).Visible = false;

        }

        private void LotStatusdefault()
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            dvcArgu[0].sCondition_ID = "FACTORY";
            dvcArgu[0].sCondition_Value = MPGV.gsFactory;

            dvcArgu[1].sCondition_ID = "TABLE_NAME";
            dvcArgu[1].sCondition_Value = "C_DLV_LOT_STATUS";

            dvcArgu[2].sCondition_ID = "KEY_1";
            dvcArgu[2].sCondition_Value = "CONFIRM";



            if (TPDR.GetDataOne("", ref dt, "BAS-02", dvcArgu, false, false, ref sSql) == false)
            {
                if (dt != null)
                    dt.Dispose();

                GC.Collect();

                return;
            }

            if (dt.Rows.Count != 0)
            {
                cdvLotStatus.Text = dt.Rows[i]["KEY_1"].ToString();
                cdvLotStatus.DisplayText = dt.Rows[i]["DATA_1"].ToString();
            }


        }


        private void InspStatusdefault()
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            dvcArgu[0].sCondition_ID = "FACTORY";
            dvcArgu[0].sCondition_Value = MPGV.gsFactory;

            dvcArgu[1].sCondition_ID = "TABLE_NAME";
            dvcArgu[1].sCondition_Value = "QCM_INSP_JUDGE_FLAG";

            dvcArgu[2].sCondition_ID = "KEY_1";
            dvcArgu[2].sCondition_Value = "P";



            if (TPDR.GetDataOne("", ref dt, "BAS-02", dvcArgu, false, false, ref sSql) == false)
            {
                if (dt != null)
                    dt.Dispose();

                GC.Collect();

                return;
            }
            if (dt.Rows.Count != 0)
            {
                cdvInspStatus.Text = dt.Rows[i]["KEY_1"].ToString();
                cdvInspStatus.DisplayText = dt.Rows[i]["DATA_1"].ToString();
            }

        }

        private void LotListSearch()
        {
            if (spdPOList.ActiveSheet.RowCount != 0)
            {
                dlvNo = spdPOList.ActiveSheet.Cells[0, (int)PO.DLV_NO].Text;
                dlvSeq = spdPOList.ActiveSheet.Cells[0, (int)PO.DLV_SEQ].Text;
                matId = spdPOList.ActiveSheet.Cells[0, (int)PO.MAT_ID].Text;
                matVer = spdPOList.ActiveSheet.Cells[0, (int)PO.MAT_VER].Text;
                consignmentFlag = spdPOList.ActiveSheet.Cells[0, (int)PO.CONSIGNMENT_FLAG].Text;

                for (int i = 0; i < spdPOList.ActiveSheet.RowCount; i++)
                {
                    spdPOList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdPOList.ActiveSheet.IsSelected(0,1);
                spdPOList.ActiveSheet.Rows[0].BackColor = Color.FromArgb(255, 192, 255);


                WareHouseInput();
                ViewArrivalLotList(dlvNo, dlvSeq, matId, matVer);
                
            }
 

        }

        private void LabelListSearch()
        {

            if (spdArrivalLotList.ActiveSheet.RowCount != 0)
            {
                for (int i = 0; i < spdArrivalLotList.ActiveSheet.RowCount; i++)
                {
                    spdArrivalLotList.ActiveSheet.Cells[i, (int)ARRIVALLOT.SELECT].Value = "N";
                    spdArrivalLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdArrivalLotList.ActiveSheet.IsSelected(0, 1);
                spdArrivalLotList.ActiveSheet.Cells[0, (int)ARRIVALLOT.SELECT].Value = "Y";
                spdArrivalLotList.ActiveSheet.Rows[0].BackColor = Color.FromArgb(255, 192, 255);

                sArrivalLotID = spdArrivalLotList.ActiveSheet.Cells[0, (int)ARRIVALLOT.DLV_LOT_ID].Text;
                ViewLabelList(sArrivalLotID);
            }

        }


        #endregion

        #region " Event Definition "
        private void frmTranStoreInvLotAnsan_Load(object sender, EventArgs e)
        {
            try
            {
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

        private void txtDlvNo_KeyPress(object sender, KeyPressEventArgs e)
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

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("VIEW") == false)
                    return;

                ClearList("VIEW");

                ViewPOList();

                LotListSearch();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnStore_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("STORE") == false)
                    return;

                if (CreateInvLot())
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
        
        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("RETURN") == false)
                    return;

                if (ReturnArrivalLot())
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

        private void btnCancel_Click(object sender, EventArgs e)
        {
            //20240909  일단 해당 버튼 기능 막음.
            /*

            try
            {
                if (CheckCondition("CANCEL") == false)
                    return;

                if (DeleteInvLot())
                {
                    ClearList("VIEW");
                    ViewPOList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            */
        }

        private void spdPOList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
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
                
                dlvNo = spdPOList.ActiveSheet.Cells[e.Row, (int)PO.DLV_NO].Text;
                dlvSeq = spdPOList.ActiveSheet.Cells[e.Row, (int)PO.DLV_SEQ].Text;
                matId = spdPOList.ActiveSheet.Cells[e.Row, (int)PO.MAT_ID].Text;
                matVer = spdPOList.ActiveSheet.Cells[e.Row, (int)PO.MAT_VER].Text;
                consignmentFlag = spdPOList.ActiveSheet.Cells[e.Row, (int)PO.CONSIGNMENT_FLAG].Text;

                WareHouseInput();


                ViewArrivalLotList(dlvNo, dlvSeq, matId, matVer);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }




        private void spdArrivalLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            ClearList("ARRIVAL_LOT_CLICK_CELL");

            try
            {
                SheetView svArrive = spdArrivalLotList.ActiveSheet;

                if (e.Row < 0)
                {
                    return;
                }

                if (e.ColumnHeader == true)
                {
                    return;
                }

                for (int i = 0; i < spdArrivalLotList.ActiveSheet.RowCount; i++)
                {
                    svArrive.Cells[e.Row, (int)ARRIVALLOT.SELECT].Value = "N";
                    svArrive.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                svArrive.Cells[e.Row, (int)ARRIVALLOT.SELECT].Value = "Y";
                svArrive.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);
                
                sArrivalLotID = svArrive.Cells[e.Row, (int)ARRIVALLOT.DLV_LOT_ID].Text;
                
                ViewLabelList(sArrivalLotID);

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

        #endregion

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


        private void WareHouseInput()
        {
            try
            {
                /*
                if (string.IsNullOrEmpty(consignmentFlag))
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox("PO Info" + MPCF.GetMessage(109));
                    return;
                }
                */

                TRSNode in_node = new TRSNode("VIEW_OPERATION_LIST_IN");
                TRSNode out_node;

                out_node = new TRSNode("VIEW_OPERATION_LIST_OUT");


                if (string.Equals(consignmentFlag, "Y"))
                {
                    in_node.ProcStep = 'U';
                    in_node.Factory = MPGV.gsFactory;;
                    in_node.AddString("AREA_ID", cdvDept.Text);
                    in_node.AddChar("INV_FLAG", 'Y');
                }
                //자재 창고 조회
                else
                {
                    in_node.ProcStep = 'C';
                    in_node.Factory = MPGV.gsFactory;
                    in_node.AddString("AREA_ID", cdvDept.Text);
                    in_node.AddChar("INV_FLAG", 'Y');
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Oper_List", in_node, ref out_node) == false)
                {
                    return ;
                }

                if (out_node.GetList(0).Count != 0)
                {
                    cdvWarehouse.Text = out_node.GetList(0)[0].GetString("OPER");
                    cdvWarehouse.DisplayText = out_node.GetList(0)[0].GetString("OPER_SHORT_DESC");
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

       


        private void cdvWarehouse_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if(string.IsNullOrEmpty(consignmentFlag))
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox("PO Info" + MPCF.GetMessage(109));
                    return;
                }

                cdvWarehouse.Init();
                MPCF.InitListView(cdvWarehouse.GetListView);
                cdvWarehouse.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWarehouse.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWarehouse.SelectedSubItemIndex = 0;
                cdvWarehouse.DisplaySubItemIndex = 1;

                //위탁 창고 조회
                if(string.Equals(consignmentFlag, "Y"))
                {
                    if (COM_LIST.ViewOperationList(cdvWarehouse.GetListView, 'U', cdvDept.Text, "", "", "", 'Y') == false)
                    {
                        return;
                    }
                }
                //자재 창고 조회
                else
                {
                    if (COM_LIST.ViewOperationList(cdvWarehouse.GetListView, 'C', cdvDept.Text, "", "", "", 'Y') == false)
                    {
                        return;
                    }
                }

                cdvWarehouse.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void lblVendorID_Click(object sender, EventArgs e)
        {

        }

        private void cdvVendorID_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {

        }

        private void cdvLotStatus_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvLotStatus.Init();
                MPCF.InitListView(cdvLotStatus.GetListView);
                cdvLotStatus.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvLotStatus.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                //cdvCar.SelectedSubItemIndex = 0;
                //cdvCar.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvLotStatus.GetListView, '1', "C_DLV_LOT_STATUS") == false)
                {
                    return;
                }
                cdvLotStatus.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvInspStatus_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvInspStatus.Init();
                MPCF.InitListView(cdvLotStatus.GetListView);
                cdvInspStatus.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvInspStatus.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                //cdvCar.SelectedSubItemIndex = 0;
                //cdvCar.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvInspStatus.GetListView, '1', "QCM_INSP_JUDGE_FLAG") == false)
                {
                    return;
                }
                cdvInspStatus.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}
