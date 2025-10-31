using System;
using System.Data;
using System.Drawing;
using System.Windows.Forms;
using System.Collections;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using FarPoint.Win.Spread;

namespace CUS_INV
{
    public partial class frmTranStoreInvLotMult : CUS_COM.frmTranForm01
    {
        public frmTranStoreInvLotMult()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "



        private enum LABEL
        {
            CHK,                     // 1 :  CHK                  
            AREA_ID,                 // 2 :  사업부
            PO_NO,                   // 3 :  PO번호
            PO_SEQ,                  // 4 :  PO순번
            VENDOR_DESC,             // 5 :  고객사명
            DLV_LOT_ID,              // 6 :  입하 LOT ID
            VENDOR_LOT_ID,           // 7 :  고객사 LOT ID
            LABEL_ID,                // 8 :  라벨 ID
            SEQ,                     // 9 :  순번
            QTY,                     // 10 : 수량
            UNIT,                    // 11 : 단위
            MAT_ID,                  // 12 : 제품
            MAT_VER,                 // 13 : 버전
            MAT_DESC,                // 14 : 제품명
            DLV_TIME,                // 15 : 입하일
            INSP_RESULT_FLAG,        // 16 : 검사판정결과  
            DLV_LOT_STATUS,          // 17 : LOT상태  
            OPER,                   // 18 : 창고 
            OPER_DESC,               // 19 : 창고 
            OPER_BUTTON,             // 20 : 창고   
            ERROR_MSG,               // 21 : 에러확인  
            SAVE_FLAG,               // 22 : 저장여부  
            CONSIGNMENT_FLAG,        // 23 : 위탁여부  
            QC_LOSS_FLAG,            // 24 : QC LOSS FLAG
            COMMENT                  // 25 : COMMENT 
        }


        #endregion

        #region " Variable Definition "


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

                InspStatusdefault();
                LotStatusdefault();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        //LABEL LIST 조회 함수
        private void ViewLabelList()
        {
            try
            {


                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[13];
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

                dvcArgu[10].sCondition_ID = "VENDOR_DESC";
                dvcArgu[10].sCondition_Value = txtVendorDesc.Text;

                dvcArgu[11].sCondition_ID = "MAT_DESC";
                dvcArgu[11].sCondition_Value = txtMatDesc.Text;

                dvcArgu[12].sCondition_ID = "CONSIGNMENT_FLAG";
                dvcArgu[12].sCondition_Value = cdvPoType.Text;




                if (TPDR.GetDataOne("", ref dt, "CINV3013-001", dvcArgu, false, false, ref sSql) == false)
                {

                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLabelList);

                    txtPONo.SelectAll();
                    return;

                }

                MPCF.ClearList(spdLabelList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLabelList_Sheet1.RowCount++;

                    spdLabelList_Sheet1.SetValue(i, (int)LABEL.CHK, false);
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.PO_NO].Value = dt.Rows[i]["PO_NO"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.PO_SEQ].Value = dt.Rows[i]["PO_SEQ"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.DLV_LOT_ID].Value = dt.Rows[i]["DLV_LOT_ID"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.LABEL_ID].Value = dt.Rows[i]["LABEL_ID"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.SEQ].Value = dt.Rows[i]["SEQ"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.QTY].Value = dt.Rows[i]["QTY"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.DLV_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["DLV_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.INSP_RESULT_FLAG].Value = dt.Rows[i]["INSP_RESULT_FLAG"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.DLV_LOT_STATUS].Value = dt.Rows[i]["DLV_LOT_STATUS"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.ERROR_MSG].Value = "";
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.SAVE_FLAG].Value = "N";
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.QC_LOSS_FLAG].Value = dt.Rows[i]["QC_LOSS_FLAG"];
                    spdLabelList_Sheet1.Cells[i, (int)LABEL.COMMENT].Value = dt.Rows[i]["COMMENT_1"];


                    //입고 가능창고가 2개이상인경우 빈값으로 저장전에 선택하여 들어갈수 있도록.
                    if (dt.Rows[i]["OPER_COUNT"].ToString() == "0")
                    {
                        spdLabelList_Sheet1.Cells[i, (int)LABEL.OPER].Value = "";
                        spdLabelList_Sheet1.Cells[i, (int)LABEL.OPER_DESC].Value = "";
                    }
                    else
                    {
                        spdLabelList_Sheet1.Cells[i, (int)LABEL.OPER].Value = dt.Rows[i]["OPER"];
                        spdLabelList_Sheet1.Cells[i, (int)LABEL.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    }



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






        private void ViewLBL(ref DataTable lblDT, string sDlv_Lot, int iRow)
        {
            try
            {


                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                string sSql = "";
                DataTable dt = null;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "DLV_LOT_ID";
                dvcArgu[2].sCondition_Value = sDlv_Lot;





                if (TPDR.GetDataOne("", ref dt, "CINV3013-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    //lblDT = null;
                    return;
                }

                lblDT = dt;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }




        //입고 자재 LOT 생성
        private void CreateInvLot()
        {
            TRSNode in_node = new TRSNode("create_Lot_In");
            TRSNode out_node = new TRSNode("create_Lot_Out");
            TRSNode inv_lot_list;
            bool send_flag = false;

            DataTable dt = null;

            try
            {


                for (int iRow_1 = 0; iRow_1 < spdLabelList_Sheet1.RowCount; iRow_1++)
                {
                    if (spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        out_node = null;
                        in_node = null;
                        inv_lot_list = null;

                        in_node = new TRSNode("create_Lot_In");
                        out_node = new TRSNode("create_Lot_Out");


                        //라벨정보 가져오기(라벨정보 이거 필요없음...-_- 진지하게 없에는거 검토 예정,현업업무에 필요X, 베트남에도 물어보기는 해야함.)
                        //2023/09/07 일단 입하에서 자동으로 라벨 정보 저장되게 바꿔놓음.(있어도 그만 없어도 그만)
                        ViewLBL(ref dt, spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.DLV_LOT_ID].Text, iRow_1);
                        if (dt.Rows.Count == 0)
                        {
                            spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.ERROR_MSG].Text = "INV LOT LABEL " + MPCF.GetMessage(466); //"자제LOT 라벨정보가 없습니다.(IS NOT LABEL DATA)";
                            spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.SAVE_FLAG].Text = "E";
                            spdLabelList.ActiveSheet.Rows[iRow_1].ForeColor = Color.Red;
                        }
                        else
                        {

                            MPCR.SetInMsg(in_node);
                            in_node.ProcStep = '1';
                            in_node.AddString("DLV_LOT_ID", spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.DLV_LOT_ID].Text);
                            in_node.AddString("TRAN_COMMENT", spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.COMMENT].Text);
                            in_node.AddString("OPER", spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.OPER].Text);
                            send_flag = true;
                            //in_node.AddString("OPER", cdvWarehouse.Text);
                            //ViewLBL(ref dt, spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.DLV_LOT_ID].Text, iRow_1);
                            for (int iRow_2 = 0; iRow_2 < dt.Rows.Count; iRow_2++)
                            {

                                inv_lot_list = in_node.AddNode("INV_LOT_LIST");
                                inv_lot_list.AddString("INV_LOT_ID", dt.Rows[iRow_2]["LABEL_ID"]);
                                inv_lot_list.AddDouble("QTY", dt.Rows[iRow_2]["QTY"]);
                                inv_lot_list.AddDouble("QTY_2", 0);
                                inv_lot_list.AddDouble("QTY_3", 0);

                            }


                            if (MPCR.CallService("CUS_INV", "CUS_INV_Create_Lot", in_node, ref out_node) == false)
                            {

                                //CMN545 INFO- 저장중 오류가 발생하였습니다. 관리자에게 문의바랍니다.(Insert Data Error Please contact your administrator.)
                                spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.ERROR_MSG].Text = MPCF.GetMessage(546);
                                spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.SAVE_FLAG].Text = "E";
                                spdLabelList.ActiveSheet.Rows[iRow_1].ForeColor = Color.Red;
                                ;
                            }
                            else
                            {
                                spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.SAVE_FLAG].Text = "S";
                                spdLabelList.ActiveSheet.Rows[iRow_1].ForeColor = Color.Blue;
                                send_flag = true;
                            }


                        }


                    }
                }
                if (send_flag == true)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                }
                else
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(546));
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private bool DeleteInvLot()
        {
            TRSNode in_node = new TRSNode("delete_Lot_In");
            TRSNode out_node = new TRSNode("delete_Lot_Out");
            SheetView svArrive = spdLabelList.ActiveSheet;
            bool send_flag = false;


            try
            {

                for (int iRow_1 = 0; iRow_1 < spdLabelList_Sheet1.RowCount; iRow_1++)
                {
                    if (spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        // out_node = null;
                        // in_node = null;

                        //MPCR.SetInMsg(in_node);
                        in_node.ProcStep = '1';
                        in_node.AddString("DLV_LOT_ID", svArrive.Cells[iRow_1, (int)LABEL.DLV_LOT_ID].Text);



                        if (MPCR.CallService("CUS_INV", "CUS_INV_Delete_Lot", in_node, ref out_node) == false)
                        {

                            spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.ERROR_MSG].Text = MPCF.GetMessage(546);
                            spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.SAVE_FLAG].Text = "E";
                            spdLabelList.ActiveSheet.Rows[iRow_1].ForeColor = Color.Red;

                        }
                        else
                        {
                            spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.SAVE_FLAG].Text = "S";
                            spdLabelList.ActiveSheet.Rows[iRow_1].ForeColor = Color.Blue;
                            send_flag = true;
                        }




                    }
                }

                if (send_flag == true)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                }
                else
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(546));
                }

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
            SheetView svArrive = spdLabelList.ActiveSheet;
            bool send_flag = false;

            try
            {

                for (int iRow_1 = 0; iRow_1 < spdLabelList_Sheet1.RowCount; iRow_1++)
                {
                    if (spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        //  out_node = null;
                        //  in_node = null;

                        //  MPCR.SetInMsg(in_node);
                        in_node.ProcStep = '1';
                        in_node.AddString("DLV_LOT_ID", svArrive.Cells[iRow_1, (int)LABEL.DLV_LOT_ID].Text);

                        if (MPCR.CallService("CUS_INV", "CUS_INV_Delete_Dlv_Lot", in_node, ref out_node) == false)
                        {

                            spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.ERROR_MSG].Text = MPCF.GetMessage(546);
                            spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.SAVE_FLAG].Text = "E";
                            spdLabelList.ActiveSheet.Rows[iRow_1].ForeColor = Color.Red;

                        }
                        else
                        {
                            spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.SAVE_FLAG].Text = "S";
                            spdLabelList.ActiveSheet.Rows[iRow_1].ForeColor = Color.Blue;
                            send_flag = true;
                        }
                    }
                }

                if (send_flag == true)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                }
                else
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(546));
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

                SheetView svLabel = spdLabelList.ActiveSheet;
                int iSelectCount = 0;


                //int iLabeRow = svLabel.ActiveRowIndex;

                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvLotStatus.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotStatus.Text + "]");
                    cdvLotStatus.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvInspStatus.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblInspStatus.Text + "]");
                    cdvInspStatus.Focus();
                    return false;
                }





                switch (sType)
                {

                    case "STORE":


                        for (int iRow_1 = 0; iRow_1 < spdLabelList_Sheet1.RowCount; iRow_1++)
                        {
                            if (spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.CHK].Text.ToString().ToUpper() == "TRUE")
                            {
                                iSelectCount = iSelectCount + 1;

                                if (svLabel.Cells[iRow_1, (int)LABEL.OPER].Value.ToString() == "")
                                {
                                    MPCF.ShowMsgBox("입고창고정보가 없습니다. 입력이 필요합니다.(Please Input WareHouse) :  " + svLabel.Cells[iRow_1, (int)LABEL.DLV_LOT_ID].Value);
                                    return false;
                                }


                                if (svLabel.Cells[iRow_1, (int)LABEL.DLV_LOT_STATUS].Value.ToString() != "CONFIRM")
                                {
                                    //CMN467 INFO - 입하LOT의 상태가 맞지 않습니다.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(467) + "(" + svLabel.Cells[iRow_1, (int)LABEL.DLV_LOT_ID].Value + ")");
                                    return false;
                                }

                                //LABEL등록 했는지 확인
                                if (svLabel.Cells[iRow_1, (int)LABEL.LABEL_ID].Text.ToString().ToUpper() == "N")
                                {
                                    //CMN547 INFO-  자재 LOT LABEL이 등록이 되지 않았습니다. 등록후 처리 바랍니다.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(547) + "  (" + svLabel.Cells[iRow_1, (int)LABEL.DLV_LOT_ID].Value + ")");
                                    return false;
                                }


                                if (svLabel.Cells[iRow_1, (int)LABEL.SAVE_FLAG].Text.ToString().ToUpper() == "S")
                                {
                                    //CMN548 INFO-이미 저장된 정보입니다./ 재조회하여 처리바랍니다.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(548) + "(" + svLabel.Cells[iRow_1, (int)LABEL.DLV_LOT_ID].Value + ")");
                                    return false;
                                }


                            }

                        }


                        if (iSelectCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }




                        break;

                    case "RETURN":




                        for (int iRow_1 = 0; iRow_1 < spdLabelList_Sheet1.RowCount; iRow_1++)
                        {
                            if (spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.CHK].Text.ToString().ToUpper() == "TRUE")
                            {
                                iSelectCount = iSelectCount + 1;

                                if (svLabel.Cells[iRow_1, (int)LABEL.DLV_LOT_STATUS].Value.ToString() != "CONFIRM")
                                {
                                    //CMN467 INFO - 입하LOT의 상태가 맞지 않습니다.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(467) + "(" + svLabel.Cells[iRow_1, (int)LABEL.DLV_LOT_ID].Value + ")");
                                    return false;
                                }


                                if (svLabel.Cells[iRow_1, (int)LABEL.SAVE_FLAG].Text.ToString().ToUpper() == "S")
                                {
                                    //CMN548 INFO-이미 저장된 정보입니다./ 재조회하여 처리바랍니다.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(548) + "(" + svLabel.Cells[iRow_1, (int)LABEL.DLV_LOT_ID].Value + ")");
                                    return false;
                                }

                                /*
                                //LABEL등록 했는지 확인
                                if (svLabel.Cells[iRow_1, (int)LABEL.LABEL_ID].Text.ToString().ToUpper() == "N")
                                {
                                    //CMN547 INFO-  자재 LOT LABEL이 등록이 되지 않았습니다. 등록후 처리 바랍니다.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(547) + "  (" + svLabel.Cells[iRow_1, (int)LABEL.DLV_LOT_ID].Value + ")");
                                }
                                */
                            }

                        }


                        if (iSelectCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        break;

                    case "CANCEL":


                        for (int iRow_1 = 0; iRow_1 < spdLabelList_Sheet1.RowCount; iRow_1++)
                        {
                            if (spdLabelList.ActiveSheet.Cells[iRow_1, (int)LABEL.CHK].Text.ToString().ToUpper() == "TRUE")
                            {
                                iSelectCount = iSelectCount + 1;

                                if (svLabel.Cells[iRow_1, (int)LABEL.DLV_LOT_STATUS].Value.ToString() != "COMPLETED")
                                {
                                    //CMN467 INFO - 입하LOT의 상태가 맞지 않습니다.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(467) + "(" + svLabel.Cells[iRow_1, (int)LABEL.DLV_LOT_ID].Value + ")");
                                    return false;
                                }


                                if (svLabel.Cells[iRow_1, (int)LABEL.SAVE_FLAG].Text.ToString().ToUpper() == "S")
                                {
                                    //CMN548 INFO-이미 저장된 정보입니다./ 재조회하여 처리바랍니다.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(548) + "(" + svLabel.Cells[iRow_1, (int)LABEL.DLV_LOT_ID].Value + ")");
                                    return false;
                                }

                                /*
                                //LABEL등록 했는지 확인
                                if (svLabel.Cells[iRow_1, (int)LABEL.LABEL_ID].Text.ToString().ToUpper() == "N")
                                {
                                    //CMN547 INFO-  자재 LOT LABEL이 등록이 되지 않았습니다. 등록후 처리 바랍니다.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(547) + "  (" + svLabel.Cells[iRow_1, (int)LABEL.DLV_LOT_ID].Value + ")");
                                }
                                */
                            }

                        }


                        if (iSelectCount == 0)
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

        //초기화 함수
        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
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





        #endregion

        #region " Event Definition "
        private void frmTranStoreInvLotMult_Load(object sender, EventArgs e)
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
                MPCF.ClearList(spdLabelList);
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
                this.txtVendorDesc.Text = popup.g_VendorDesc;

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
                    this.txtMatDesc.Text = popup.sMat_Desc;
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

                ViewLabelList();


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


                CreateInvLot();


                //ClearList("VIEW");
                //ViewLabelList();




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
                    ViewLabelList();
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
                                ViewLabelList();
                            }
                        }
                        catch (Exception ex)
                        {
                            MPCF.ShowMsgBox(ex.Message);
                        }
              */

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

        private void cdvPoType_ButtonPress(object sender, EventArgs e)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(cdvPoType.GetListView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';


            in_node.AddString("SQL", "SELECT ' ' AS CODE , '일반(Standard)' AS VALUE FROM DUAL UNION ALL "
                                   + "SELECT 'Y' AS CODE , '위탁(Consignment)' AS VALUE FROM DUAL");


            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return;
                }

                MPCR.FillDataView(cdvPoType.GetListView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);


            cdvPoType.InsertEmptyRow(0, 1);
        }

        private void spdLabelList_CellClick(object sender, CellClickEventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void pnlMID_Paint(object sender, PaintEventArgs e)
        {

        }

        private void cdvPoType_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            MPCF.ClearList(spdLabelList);
        }

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            MPCF.ClearList(spdLabelList);
        }

        private void cdvInspStatus_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            MPCF.ClearList(spdLabelList);
        }

        private void cdvLotStatus_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            MPCF.ClearList(spdLabelList);
        }

        private void cdvDeleteFlag_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            MPCF.ClearList(spdLabelList);
        }

        private void spdLabelList_CellClick_1(object sender, CellClickEventArgs e)
        {
            SheetView sv = spdLabelList.ActiveSheet;

            try
            {
                if (e.ColumnHeader == true)
                {
                    if (sv.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdLabelList, e.Row, e.Column, true, true, false);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLabelList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            try
            {
                SheetView sv = spdLabelList_Sheet1;

                if (e.Column == (int)LABEL.OPER_BUTTON)
                {

                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("Desc", 100, HorizontalAlignment.Left);


                    //위탁 창고 조회
                    if (sv.Cells[e.Row, (int)LABEL.SAVE_FLAG].Text.ToString().ToUpper() == "Y")
                    {
                        if (COM_LIST.ViewOperationList(cdvGridButton.GetListView, 'U', cdvDept.Text, "", "", "", 'Y') == false)
                        {
                            return;
                        }
                    }
                    //자재 창고 조회
                    else
                    {
                        if (COM_LIST.ViewOperationList(cdvGridButton.GetListView, 'C', cdvDept.Text, "", "", "", 'Y') == false)
                        {
                            return;
                        }
                    }

                    cdvGridButton.ShowPopupList(e.Row, e.Column);


                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            SheetView sv = spdLabelList_Sheet1;
            try
            {
                if (sv.ActiveColumnIndex == (int)LABEL.OPER_BUTTON)
                {
                    sv.SetValue(e.Row, (int)LABEL.OPER, e.SelectedItem.SubItems[0].Text);
                    sv.SetValue(e.Row, (int)LABEL.OPER_DESC, e.SelectedItem.SubItems[1].Text);
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }







    }
}
