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

//CWIP2032
namespace CUS_WIP
{
    public partial class frmTranOutsourcingIn : CUS_COM.frmViewForm01
    {

        string BeforProdQty;

        public frmTranOutsourcingIn()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum PO_INFO
        {
            PO_NO,                  // 1 : po 번호
            PO_SEQ,                 // 2 : po 번호
            PO_QTY,                 // 3 : po 수량
            PO_REMAIN_QTY,          // 4 : po 잔량
            ORDER_ID,               // 5 : 작업지시
            MAT_ID,                 // 6 : 제품코드
            MAT_DESC,               // 7 : 제품명
            UNIT,                   // 8 : 단위
            VENDOR,                 // 9 : 협력사코드
            VENDOR_DESC             // 10 : 협력사 
        }

        private enum LOT_INFO
        {
            CHK,                    // 1 : CHECK
            ORDER_ID,               // 2 : ORDER 
            LOT_ID,                 // 3 : LOT ID            
            MAT_ID,                 // 4 : 제품코드
            MAT_DESC,               // 5 : 제품명            
            PROD_QTY,               // 6 : 생산수량
            GOOD_QTY,               // 7 : 양품수량
            BAD_QTY,                // 7 : 불량수량
            INV_BUTTON,
            OPER,
            LAST_TRAN_CODE
        }

        private enum LOSS_INFO
        {
            LOSS_CODE,              // 1 : 불량코드
            LOSS_DESC,              // 2 : 불량명
            LOSS_QTY                // 3 : 불량수량
        }

        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnIn.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //PO정보 조회 함수
        private void ViewPOList()
        {
            try
            {
                MPCF.ClearList(spdLotList);

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[8];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "ORDER_ID";
                dvcArgu[2].sCondition_Value = cdvOrder.Text + "%";

                dvcArgu[3].sCondition_ID = "VENDOR_ID";
                dvcArgu[3].sCondition_Value = cdvVendor.Text;

                dvcArgu[4].sCondition_ID = "MAT_ID";
                dvcArgu[4].sCondition_Value = cdvMatid.Text;

                dvcArgu[5].sCondition_ID = "MAT_DESC";
                dvcArgu[5].sCondition_Value = "%" + cdvMatid.Text + "%";

                dvcArgu[6].sCondition_ID = "PO_NO";
                dvcArgu[6].sCondition_Value = txtPo.Text + "%";

                dvcArgu[7].sCondition_ID = "PO_SEQ";
                dvcArgu[7].sCondition_Value = txtPoSeq.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2032-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdPoInfo);
                    return;
                }

                MPCF.ClearList(spdPoInfo);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdPoInfo.ActiveSheet.RowCount++;

                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.PO_NO].Value = dt.Rows[i]["PO_NO"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.PO_SEQ].Value = dt.Rows[i]["PO_SEQ"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.PO_QTY].Value = dt.Rows[i]["PO_QTY"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.PO_REMAIN_QTY].Value = dt.Rows[i]["PO_REMAIN_QTY"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.VENDOR].Value = dt.Rows[i]["VENDOR_ID"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                }
                MPCF.FitColumnHeader(spdPoInfo);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewInLotList(string sOrder_id)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORDER_ID";
                dvcArgu[1].sCondition_Value = sOrder_id;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2032-002", dvcArgu, false, false, ref sSql) == false)
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

                    spdLotList.ActiveSheet.RowCount++;

                    spdLotList.ActiveSheet.SetValue(i, (int)LOT_INFO.CHK, false);
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Value = dt.Rows[i]["QTY_1"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.GOOD_QTY].Value = dt.Rows[i]["GOOD_QTY"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.BAD_QTY].Value = dt.Rows[i]["LOSS_QTY"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LAST_TRAN_CODE].Value = dt.Rows[i]["LAST_TRAN_CODE"];

                }

                MPCF.FitColumnHeader(spdLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewLossList(string sLotID)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                dvcArgu[2].sCondition_ID = "LOT_ID";
                dvcArgu[2].sCondition_Value = sLotID;

                if (TPDR.GetDataOne("", ref dt, "CWIP2032-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLossList);
                    return;
                }

                MPCF.ClearList(spdLossList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLossList_Sheet1.RowCount++;

                    spdLossList_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_CODE].Value = dt.Rows[i]["LOSS_CODE"];
                    spdLossList_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_DESC].Value = dt.Rows[i]["LOSS_DESC"];
                    spdLossList_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_QTY].Value = dt.Rows[i]["LOSS_QTY"];

                }
                MPCF.FitColumnHeader(spdLossList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //불량정보 등록 함수
        private bool SaveLossData()
        {
            try
            {
                TRSNode in_node = new TRSNode("loss_Code_In");
                TRSNode out_node = new TRSNode("loss_Code_Out");
                TRSNode loss_list;

                double d_loss_qty = 0;
                double d_prod_qty = 0;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text);
                //in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("CUASE_OPER", cdvCauseOper.Text);

                for (int i = 0; i < spdLossList.ActiveSheet.RowCount; i++)
                {
                    if (MPCF.ToDbl(spdLossList.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_QTY].Text) != 0)
                    {
                        loss_list = in_node.AddNode("LOSS_TBL");
                        loss_list.AddString("CODE", spdLossList.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_CODE].Text);
                        loss_list.AddDouble("VALUE", spdLossList.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_QTY].Text);
                        loss_list.AddChar("QTY_FLAG", '1');

                        d_loss_qty += MPCF.ToDbl(spdLossList.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_QTY].Value);
                    }
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Update_Lot_Loss", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                d_prod_qty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.PROD_QTY].Value);

                spdLotList.ActiveSheet.SetValue(spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.BAD_QTY, d_loss_qty);
                spdLotList.ActiveSheet.SetValue(spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.GOOD_QTY, d_prod_qty - d_loss_qty);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //작업지시 lot 생성
        private string fnCreateLot(string sOrder_ID)
        {
            string s_returen = "";

            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '5';

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("ORDER_ID", sOrder_ID);
                in_node.AddDouble("QTY_1", MPCF.ToDbl(txtProdQty.Text));

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Outsourcing_Process", in_node, ref out_node) == false)
                    return s_returen;

                s_returen = out_node.GetString("LOT_ID");

                return s_returen;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return s_returen;
            }
        }

        private bool fnDeleteLot(string sOrder_id, string sLot_id)
        {
            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '6';

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("ORDER_ID", sOrder_id);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("LOT_ID", sLot_id);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Outsourcing_Process", in_node, ref out_node) == false)
                    return false;

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }


        private string fnAdaptLot(string sOrder_ID, string sLot_id, double iQty)
        {
            string s_returen = "";

            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '8';

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("ORDER_ID", sOrder_ID);
                in_node.AddString("LOT_ID", sLot_id);
                in_node.AddDouble("QTY_1", iQty);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Outsourcing_Process", in_node, ref out_node) == false)
                    return s_returen;

                s_returen = out_node.GetString("LOT_ID");

                return s_returen;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);

                spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.PROD_QTY].Text = BeforProdQty;
                return s_returen;
            }
        }



        private bool SaveProcess(string sOrder_id)
        {
            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                TRSNode Lot_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '4';

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("ORDER_ID", sOrder_id);

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        Lot_list = in_node.AddNode("LOT_TBL");
                        Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                        Lot_list.AddString("ORDER_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.ORDER_ID].Text);
                        //Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text));
                        Lot_list.AddDouble("SUM_QTY", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text));
                        Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.GOOD_QTY].Text));
                        Lot_list.AddDouble("LOSS_QTY", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.BAD_QTY].Text));
                    }
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Outsourcing_Process", in_node, ref out_node) == false)
                    return false;
                else
                {
                    MPCR.ShowSuccessMsg(out_node);

                    //20220310 굳이 무조건 나올 이유 없음..제거
                    //ViewPrintLabel(out_node);
                    if (chkAutoPrint.Checked == true)
                    {
                        ViewPrintLabel(out_node);
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

        // 라벨 프린트
        public bool ViewPrintLabel(TRSNode out_node)
        {
            try
            {
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                string file_name = "";








                MPCR.SetInMsg(in_node);

                in_node.AddString("", "");


                for (int i = 0; i < out_node.GetList("LOT_LIST").Count; i++)
                {
                    label_list = in_node.AddNode("LOT_LIST");
                    label_list.AddString("LOT_ID", out_node.GetList("LOT_LIST")[i].GetString("LOT_ID"));
                }

                switch (cdvDept.Text)
                {
                    case "HM":
                    case "HV":
                        file_name = "t_card";
                        CSCF.ViewLabelList(file_name, in_node, '6');
                        break;
                    default:
                        file_name = "mtl100p";
                        CSCF.ViewLabelList(file_name, in_node, 'T');
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


        public bool ViewPrintLabel2()
        {
            try
            {

                if (spdLotList.ActiveSheet.RowCount == 0)
                {
                    return false;
                }

                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");



                string file_name = "";



                //string file_name = "t_card";

                MPCR.SetInMsg(in_node);

                in_node.AddString("", "");




                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    label_list = in_node.AddNode("LOT_LIST");
                    // label_list.AddString("LOT_ID", out_node.GetList("LOT_LIST")[i].GetString("LOT_ID"));

                    label_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);

                }



                switch (cdvDept.Text)
                {
                    case "HM":
                    case "HV":
                        file_name = "t_card";
                        CSCF.ViewLabelList(file_name, in_node, '6');
                        break;
                    default:
                        file_name = "mtl100p";
                        CSCF.ViewLabelList(file_name, in_node, 'T');
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




        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            int iLotCount = 0;

            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        break;

                    case CSGC.CHECK.SAVE:

                        if (MPCF.Trim(cdvCauseOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblCauseOper.Text + "]");
                            cdvCauseOper.Focus();
                            return false;
                        }

                        if (spdLotList.ActiveSheet.RowCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305));
                            return false;
                        }

                        break;

                    case CSGC.CHECK.ADD:

                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
                            return false;
                        }

                        if (MPCF.ToDbl(txtProdQty.Text) == 0)
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblProdQty.Text + "]");
                            txtProdQty.Focus();
                            return false;
                        }

                        break;

                    case CSGC.CHECK.DELETE:

                        for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                        {
                            if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                            {

                                /*
                                if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LAST_TRAN_CODE].Text != MPGC.MP_TRAN_CODE_CREATE)
                                {
                                    //CMN522 ERROR - 삭제 할 수 없는 LOT입니다. 해당 공정에서 생성된 LOT만 삭제 할 수 있습니다.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(522) + " [" + spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text + "]");
                                    return false;
                                }
                                */

                                iLotCount++;
                            }
                        }

                        if (iLotCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305));
                            return false;
                        }

                        break;

                    case CSGC.CHECK.END:

                        for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                        {
                            if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                                iLotCount++;
                        }

                        if (iLotCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305));
                            return false;
                        }

                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
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

        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "ALL":

                        cdvOrder.Text = "";
                        txtPo.Text = "";
                        cdvMatid.Text = "";
                        txtMatdesc.Text = "";
                        cdvVendor.Text = "";
                        txtProdQty.Text = "0";

                        MPCF.ClearList(spdPoInfo);
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdLossList);

                        break;

                    case "SAVE":

                        txtProdQty.Text = "0";

                        MPCF.ClearList(spdPoInfo);
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdLossList);

                        spdLossList.ActiveSheet.ColumnFooter.Cells[0, (int)LOSS_INFO.LOSS_QTY].Value = 0;

                        break;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmTranOutsourcingIn_Load(object sender, EventArgs e)
        {
            try
            {

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

        private void cdvWorkPlace_ButtonPress(object sender, EventArgs e)
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

                cdvWorkPlace.Init();
                MPCF.InitListView(cdvWorkPlace.GetListView);
                cdvWorkPlace.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWorkPlace.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWorkPlace.SelectedSubItemIndex = 0;
                cdvWorkPlace.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList_AREA(cdvWorkPlace.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, cdvDept.Text) == false)
                {
                    return;
                }

                cdvWorkPlace.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOper_ButtonPress(object sender, EventArgs e)
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

                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, 'E', cdvDept.Text, cdvWorkPlace.Text) == false)
                {
                    return;
                }

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        private void cdvOrder_ButtonPress(object sender, EventArgs e)
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

                CUS_COM.Popup.frmPopWorkOrderList popup = new CUS_COM.Popup.frmPopWorkOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_AreaCode = cdvDept.Text;
                popup.g_AreaDesc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvOrder.Text = popup.g_WorkOrder;
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

        private void cdvOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) != "")
                {
                    cdvCauseOper.Text = cdvOper.Text;
                    cdvCauseOper.DisplayText = cdvOper.DisplayText;

                    ViewLossList("");
                }
                else
                {
                    cdvCauseOper.Text = "";
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatid_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvMatid.Text = popup.sMat_id;
                    txtMatdesc.Text = popup.sMat_Desc;
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

        private void cdvVendor_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopVendorList popup = new frmPopVendorList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvVendor.Text = popup.g_VendorId;
                    this.cdvVendor.DisplayText = popup.g_VendorDesc;
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

        private void txtMatdesc_KeyPress(object sender, KeyPressEventArgs e)
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

        private void txtPo_KeyPress(object sender, KeyPressEventArgs e)
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

        private void spdPoInfo_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            string sOrder_id = "";

            try
            {
                if (e.ColumnHeader)
                    return;

                for (int i = 0; i < spdPoInfo.ActiveSheet.RowCount; i++)
                {
                    spdPoInfo.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }
                spdPoInfo.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                sOrder_id = spdPoInfo.ActiveSheet.Cells[e.Row, (int)PO_INFO.ORDER_ID].Text;

                if (MPCF.Trim(sOrder_id) != "")
                {
                    ViewInLotList(sOrder_id);
                    ViewLossList("");
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            string sLotID = "";

            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)LOT_INFO.CHK)
                    {
                        CSCF.CheckSpreadCell(spdLotList, 0, 0, true, true);
                    }
                }
                else
                {
                    sLotID = spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.LOT_ID].Text;

                    ViewLossList(sLotID);
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            string sOrder_id = "";

            try
            {
                if (MPCF.Trim(cdvOrder.Text) == "")
                    sOrder_id = spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Text;
                else
                    sOrder_id = cdvOrder.Text;

                if (e.Column == (int)LOT_INFO.INV_BUTTON)
                {
                    frmTranInputLotMaterials popup = new frmTranInputLotMaterials();
                    popup.StartPosition = FormStartPosition.CenterParent;
                    popup.sArea_id = cdvDept.Text;
                    popup.sArea_desc = cdvDept.DisplayText;
                    popup.sSub_area_id = cdvWorkPlace.Text;
                    popup.sSub_area_desc = cdvWorkPlace.DisplayText;
                    popup.sOper_id = cdvOper.Text;
                    popup.sOper_desc = cdvOper.DisplayText;
                    popup.sOrder_id = sOrder_id;
                    popup.sLot_id = spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text;
                    popup.sLot_Qty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.PROD_QTY].Text);
                    popup.bOsp_YN = true;

                    if (popup.ShowDialog() == DialogResult.OK)
                    {
                        popup = null;
                    }
                    else
                        return;
                }
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
                string sLot_id = "";
                string sOrder_id = "";
                int iRow = 0;

                try
                {
                    if (CheckCondition(CSGC.CHECK.ADD) == false)
                        return;

                    sOrder_id = spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Text;
                    sLot_id = fnCreateLot(sOrder_id);

                    if (sLot_id == "")
                    {
                        return;
                    }

                    iRow = spdLotList.ActiveSheet.RowCount;
                    spdLotList.ActiveSheet.RowCount++;
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CHK, true);
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.ORDER_ID, sOrder_id);
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.LOT_ID, sLot_id);
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_ID, spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.MAT_ID].Text);
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_DESC, spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.MAT_DESC].Text);
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.PROD_QTY, MPCF.ToDbl(txtProdQty.Text));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.GOOD_QTY, MPCF.ToDbl(txtProdQty.Text));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.BAD_QTY, 0);
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.OPER, cdvOper.Text);
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.LAST_TRAN_CODE, MPGC.MP_TRAN_CODE_CREATE);

                    txtProdQty.Text = "";

                }
                catch (Exception ex)
                {
                    MPCF.ShowMsgBox(ex.Message);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            string sOrder_id = "";
            string sLot_id = "";

            try
            {
                if (CheckCondition(CSGC.CHECK.DELETE) == false)
                    return;

                sOrder_id = spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Text;

                for (int i = spdLotList.ActiveSheet.RowCount; i > 0; i--)
                {
                    if (spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        sLot_id = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.LOT_ID].Text;

                        if (fnDeleteLot(sOrder_id, sLot_id) == true)
                        {
                            spdLotList.ActiveSheet.RemoveRows(i - 1, 1);
                        }
                        else
                        {
                            break;
                        }
                    }
                }

                ViewLossList("");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnLossSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SaveLossData())
                {

                }
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
                ClearData("ALL");
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

                ViewPOList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnIn_Click(object sender, EventArgs e)
        {
            try
            {
                string sOrder = "";

                try
                {
                    if (CheckCondition(CSGC.CHECK.END) == false)
                        return;

                    sOrder = spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Text;

                    if (SaveProcess(sOrder))
                    {
                        ClearData("END");
                        ViewPOList();
                    }
                }
                catch (Exception ex)
                {
                    MPCF.ShowMsgBox(ex.Message);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        private void btnPrint_Click(object sender, EventArgs e)
        {
            ViewPrintLabel2();
        }

        private void btnAdapt_Click(object sender, EventArgs e)
        {
            string sOrder_ID;
            string sLot_id;
            double iQty;

            for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
            {
                if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                {
                    sOrder_ID = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.ORDER_ID].Text;
                    sLot_id = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text;
                    iQty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text);

                    fnAdaptLot(sOrder_ID, sLot_id, iQty);
                }
            }


            ViewInLotList(spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Text);
            ViewLossList("");


        }

        private void spdLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            string sOrder_ID;
            string sLot_id;
            double iQty;

            switch (e.Column)
            {
                case (int)LOT_INFO.PROD_QTY:

                    if (MPCF.ShowMsgBox(MPCF.GetMessage(553), MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.Yes)
                    {
                        sOrder_ID = spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.ORDER_ID].Text;
                        sLot_id = spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text;
                        iQty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.PROD_QTY].Text);

                        fnAdaptLot(sOrder_ID, sLot_id, iQty);
                    }
                    else
                    {
                        spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.PROD_QTY].Text = BeforProdQty;
                    }
                    ViewInLotList(spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Text);
                    ViewLossList("");

                    break;

            }

        }

        private void spdLotList_KeyDown(object sender, KeyEventArgs e)
        {
            BeforProdQty = spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.PROD_QTY].Text;
        }

        private void txtPoSeq_KeyPress(object sender, KeyPressEventArgs e)
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


        #endregion


    }
}
