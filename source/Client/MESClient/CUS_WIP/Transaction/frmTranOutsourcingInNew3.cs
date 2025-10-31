using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using FarPoint.Win.Spread.Model;


using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using System.Runtime.InteropServices.WindowsRuntime;

//CWIP2032
namespace CUS_WIP
{
    public partial class frmTranOutsourcingInNew3 : CUS_COM.frmViewForm01
    {

        //      int BeforLotRownum = -1;
        //      DefaultSheetDataModel defModelDataLoss;
       

        public frmTranOutsourcingInNew3()
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
            VENDOR_DESC,            // 10 : 협력사 
            LOTS                    // 11 : 입고된 LOT목록 
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
            OPER,
            LAST_TRAN_CODE,
            LOT_TYPE,
            LOSS_CODE
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
                chkAutoPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                pnlGCM.Anchor = AnchorStyles.Top | AnchorStyles.Left;
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
                resetvalue();

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[10];
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


                dvcArgu[7].sCondition_ID = "OPER";
                dvcArgu[7].sCondition_Value = cdvOper.Text + "%";

                dvcArgu[8].sCondition_ID = "WORK_PLACE";
                dvcArgu[8].sCondition_Value = cdvWorkPlace.Text + "%";


                dvcArgu[9].sCondition_ID = "PO_SEQ";
                dvcArgu[9].sCondition_Value = txtPoSeq.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2039-001", dvcArgu, false, false, ref sSql) == false)
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
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.LOTS].Value = dt.Rows[i]["LOTS"];
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
                resetvalue();
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



                if (TPDR.GetDataOne("", ref dt, "CWIP2039-002", dvcArgu, false, false, ref sSql) == false)
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

                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];



                }
                // spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.LOSS_CODE).Visible = false;
                MPCF.FitColumnHeader(spdLotList);
                //  spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, 0, spdLotList.ActiveSheet.ActiveRowIndex, spdLotList.ActiveSheet.ColumnCount - 1].BackColor = System.Drawing.Color.Pink;
                QtyCount();

                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.LOSS_CODE).Width = 150;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.LOSS_CODE).Locked = true;
                // LossCombobox();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void ViewInLotList2(string sOrder_id)
        {
            try
            {



                resetvalue();
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



                if (TPDR.GetDataOne("", ref dt, "CWIP2039-003", dvcArgu, false, false, ref sSql) == false)
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

                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];

                }


                //spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.LOSS_CODE).Visible = true;
                QtyCount();
                MPCF.FitColumnHeader(spdLotList);
                //   spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, 0, spdLotList.ActiveSheet.ActiveRowIndex, spdLotList.ActiveSheet.ColumnCount - 1].BackColor = System.Drawing.Color.Pink;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.LOSS_CODE).Width = 150;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.LOSS_CODE).Locked = false;
                LossCombobox();
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        //불량정보 등록 함수
        private bool SaveLossData(int iRow)
        {
            try
            {
                TRSNode in_node = new TRSNode("loss_Code_In");
                TRSNode out_node = new TRSNode("loss_Code_Out");
                TRSNode loss_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.LOT_ID].Text);
                //in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("CUASE_OPER", cdvOper.Text);

                loss_list = in_node.AddNode("LOSS_TBL");
                loss_list.AddString("CODE", spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.LOSS_CODE].Value.ToString());
                loss_list.AddDouble("VALUE", spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.BAD_QTY].Text);
                loss_list.AddChar("QTY_FLAG", '1');


                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Update_Lot_Loss", in_node, ref out_node) == false)
                    return false;
                else

                    return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }










        private bool SaveProcess()
        {
            try
            {
                int iChkCount = 0;

                //불량정보 먼저 저장
                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_CODE].Text.Trim() != "")
                        {
                            if (SaveLossData(i) == false)
                            {
                                return false;
                            }
                        }
                        iChkCount = iChkCount + 1;

                    }
                }

                if (iChkCount == 0)
                {
                    //CMN199 ERROR - 선택된 Lot이 없습니다. 먼저 Lot을 선택하여 주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(199));
                    return false;

                }



                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                TRSNode Lot_list;
                string sLotId = "";
                double dinputQty = 0;

                sLotId = spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text;

                dinputQty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.GOOD_QTY].Text) + MPCF.ToDbl(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.BAD_QTY].Text);

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '4';

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("ORDER_ID", spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Value);

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        Lot_list = in_node.AddNode("LOT_TBL");
                        Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                        Lot_list.AddString("ORDER_ID", spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Value);
                        Lot_list.AddDouble("SUM_QTY", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text));
                        Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.GOOD_QTY].Text));
                        Lot_list.AddDouble("LOSS_QTY", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.BAD_QTY].Text));
                    }
                }




                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Outsourcing_Process", in_node, ref out_node) == false)
                    return false;
                else
                {


                    if (rdoOper.Checked == true)
                    {
                        ViewInLotList2(spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Text);
                    }
                    else
                    {
                        ViewInLotList(spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Text);
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

                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
                            return false;
                        }

                        break;

                    case CSGC.CHECK.SAVE:


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
                        txtPoSeq.Text = "";
                        cdvMatid.Text = "";
                        txtMatdesc.Text = "";
                        cdvVendor.Text = "";

                        MPCF.ClearList(spdPoInfo);
                        MPCF.ClearList(spdLotList);


                        break;

                    case "SAVE":


                        MPCF.ClearList(spdPoInfo);
                        MPCF.ClearList(spdLotList);


                        break;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void QtyCount()
        {
            int iGoodQty = 0;
            int iBadQty = 0;

            txtGoodQty.Text = "";
            txtLossQty.Text = "";

            for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
            {
                iGoodQty = iGoodQty + Convert.ToInt32(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.GOOD_QTY].Text);
                iBadQty = iBadQty + Convert.ToInt32(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.BAD_QTY].Text);
            }

            txtGoodQty.Text = iGoodQty.ToString();
            txtLossQty.Text = iBadQty.ToString();

        }
        private void InputSpliteCountCount()
        {

            pnlInputSpliteCount.Visible = true;
            txtSpliteCount.Text = "1";
            txtSpliteCount.Enabled = true;
            txtSpliteCount.Focus();
            txtSpliteCount.Select();


        }

        private void fnCreateLot()
        {
            // string sErrorLot = "";
            int iChkCount = 0;

            try
            {

                if (txtSpliteCount.Text.Trim() == "")
                {
                    //CMN419 ERROR - LOT 분할 정보가 없습니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(419));
                }


                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        TRSNode in_node = new TRSNode("Process_In");
                        TRSNode out_node = new TRSNode("Process_Out");

                        MPCR.SetInMsg(in_node);
                        in_node.ProcStep = '0';

                        in_node.AddString("AREA_ID", cdvDept.Text);
                        in_node.AddString("OPER", cdvOper.Text);
                        in_node.AddString("ORDER_ID", spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Text);
                        in_node.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                        in_node.AddString("MAT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Text);
                        in_node.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text));
                        in_node.AddInt("SPLITE_COUNT", MPCF.ToInt(txtSpliteCount.Text));
                        in_node.AddDouble("SPLITE_QTY", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text) / MPCF.ToDbl(txtSpliteCount.Text));
                        in_node.AddString("BOM_INPUT_TYPE", CSGC.CP_MAT_INPUT_TYPE_BOM);


                        if (MPCR.CallService("CUS_WIP", "CUS_WIP_Outsourcing_Process", in_node, ref out_node) == false)
                        {
                            rdoWh.Checked = true;
                            ViewInLotList(spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Text);
                            return;
                        }
                        else
                        {
                            iChkCount = iChkCount + 1;
                        }

                    }

                }

                if (iChkCount > 0)
                {
                    rdoOper.Checked = true;

                    // ViewInLotList2(spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Text);
                }
                else
                {
                    //CMN199 ERROR - 선택된 Lot이 없습니다. 먼저 Lot을 선택하여 주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(199));

                }


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        private void LossCombobox()
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            StringBuilder sb;

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            sb = new StringBuilder();

            sb.Append("SELECT * FROM ");
            sb.Append("(SELECT ' ' AS LOSS_CODE, ' ' AS LOSS_DESC, '0' AS SEQ FROM DUAL UNION ALL  ");
            sb.Append(" SELECT A.KEY_2 AS LOSS_CODE, ");
            sb.Append("          C.DATA_1 AS LOSS_DESC, ");
            sb.Append("           replace(A.DATA_1,' ','999') AS SEQ");
            sb.Append("     FROM MGCMTBLDAT A , MGCMTBLDAT C ");
            sb.Append(" WHERE A.FACTORY = C.FACTORY ");
            sb.Append("                                 AND A.KEY_2 = C.KEY_1 ");
            sb.Append("                                 AND C.TABLE_NAME = 'LOSS_CODE' ");
            sb.Append("     AND A.FACTORY = '" + MPGV.gsFactory + "'");
            sb.Append("     AND A.TABLE_NAME = 'C_OPER_LOSS' ");
            sb.AppendLine("     AND A.KEY_1 = '" + cdvOper.Text + "' )");
            sb.Append(" ORDER BY TO_NUMBER(SEQ)");
            in_node.AddString("SQL", sb.ToString());

            sb = new StringBuilder();
            in_node.AddString("SQL", sb.ToString());

            if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
            {
                return;
            }

            string[] sItemData;
            string[] sItems;

            if (out_node.GetList("ROWS").Count > 0)
            {
                sItemData = new string[out_node.GetList("ROWS").Count];
                sItems = new string[out_node.GetList("ROWS").Count];

                for (int i = 0; i < out_node.GetList("ROWS").Count; i++)
                {
                    sItems[i] = out_node.GetList("ROWS")[i].GetList("COLS")[0].GetString("DATA");
                    sItemData[i] = out_node.GetList("ROWS")[i].GetList("COLS")[1].GetString("DATA");



                    spdBadData_Sheet1.ColumnCount = 0;

                    for (int r = 0; r < out_node.GetList("ROWS").Count; r++)
                    {
                        if (r != 0)
                        {
                            spdBadData_Sheet1.ColumnCount++;


                            spdBadData_Sheet1.ColumnHeader.Cells[0, r - 1].Text = out_node.GetList("ROWS")[r].GetList("COLS")[1].GetString("DATA");

                            spdBadData_Sheet1.ColumnFooter.Cells[0, r - 1].Text = out_node.GetList("ROWS")[r].GetList("COLS")[0].GetString("DATA");

                        }

                    }

                    // MPCF.FitColumnHeader(spdBadData);



                }

                FarPoint.Win.Spread.CellType.ComboBoxCellType cb2 = new FarPoint.Win.Spread.CellType.ComboBoxCellType();//CellType 정의 
                cb2.ItemData = sItems;//ItemData 값 지정. 
                cb2.Items = sItemData; //Items 값 지정.. 
                cb2.EditorValue = FarPoint.Win.Spread.CellType.EditorValue.ItemData;

                spdLotList.ActiveSheet.Columns[(int)LOT_INFO.LOSS_CODE].CellType = cb2; //CellType 지정. .

            }
        }
        private void resetvalue()
        {
            pnlInputSpliteCount.Visible = false;
            txtGoodQty.Text = "";
            txtLossQty.Text = "";
            MPCF.ClearList(spdLotList);


        }

        #endregion

        #region " Event Definition "

        private void frmTranOutsourcingInNew3_Load(object sender, EventArgs e)
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
                txtGoodQty.Text = "";
                txtLossQty.Text = "";
                MPCF.ClearList(spdPoInfo);
                MPCF.ClearList(spdLotList);
                /*
                if (MPCF.Trim(cdvOper.Text) != "")
                {
                    MPCF.ClearList(spdPoInfo);
                    MPCF.ClearList(spdLotList);
                }
                */
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
                    if (rdoOper.Checked == true)
                    {
                        ViewInLotList2(sOrder_id);
                    }
                    else
                    {
                        ViewInLotList(sOrder_id);
                    }

                }
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
                if (e.ColumnHeader)
                {

                    //일단 체크박스 안쓰기는 하는데 일단 나둠..나중에 쓸까봐..
                    if (e.Column == (int)LOT_INFO.CHK)
                    {
                        CSCF.CheckSpreadCell(spdLotList, 0, 0, true, true);
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {

            try
            {


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

        private void btnPrint_Click(object sender, EventArgs e)
        {
            ViewPrintLabel2();
        }

        private void spdLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            int iRow = e.Row;
            int iCol = e.Column;




            //  b_loaded = false;

            if (e.Column == (int)LOT_INFO.LOSS_CODE)
            {
                if (spdLotList.ActiveSheet.Cells[iRow, iCol].Value.ToString().Trim() != "")
                {
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.GOOD_QTY].Text = "0";
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.BAD_QTY].Text = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.PROD_QTY].Text;


                }
                else
                {
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.GOOD_QTY].Text = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.PROD_QTY].Text;
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.BAD_QTY].Text = "0";
                }
                QtyCount();

            }

        }


        private void spdLotList_KeyDown(object sender, KeyEventArgs e)
        {

        }

        private void spdLotList_SelectionChanged(object sender, FarPoint.Win.Spread.SelectionChangedEventArgs e)
        {

        }

        private void btnGCM_Click(object sender, EventArgs e)
        {
            try
            {

                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = "C_OSP_ADD_WORD";

                if (MPGV.gcLanguage == '2')
                {
                    popup.sTable_name_desc = "입고 LOT 생성조건";
                    popup.sComment = "투입 LOT을 기준으로 등록된 정보를 기준으로 뒤에 채번하여 생성합니다.";

                }
                else
                {
                    popup.sTable_name_desc = "OutSourcing LOT generation conditions";
                    popup.sComment = "Generates the registered information based on the input LOT.";

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

        private void txtbomLot_KeyPress(object sender, KeyPressEventArgs e)
        {

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

        private void btnLotCreate_Click(object sender, EventArgs e)
        {

            pnlInputSpliteCount.Visible = false;
            InputSpliteCountCount();
            /*
            if (MPCF.Trim(txtSpliteCount.Text) == "")
            {
                MPCF.ShowMsgBox("Input Splite Count(분할수량을 입력하세요.)");
                return;
            };

            fnCreateLot();
            */

        }

        private void btnLotEnd_Click(object sender, EventArgs e)
        {
            if (SaveProcess() == false)
            {
                return;
            }
        }

        private void rdoWh_CheckedChanged(object sender, EventArgs e)
        {
            if (rdoWh.Checked)
            {

                if (spdPoInfo.ActiveSheet.ActiveRowIndex > 0)
                {
                    ViewInLotList(spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Text);

                }

                btnLotCreate.Visible = true;
                btnLotEnd.Visible = false;
            }
            else
            {
                btnLotCreate.Visible = false;
                btnLotEnd.Visible = true;
            }

        }

        private void rdoOper_CheckedChanged(object sender, EventArgs e)
        {
            if (rdoOper.Checked)
            {
                if (spdPoInfo.ActiveSheet.ActiveRowIndex > 0)
                {
                    ViewInLotList2(spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Text);
                }
                btnLotCreate.Visible = false;
                btnLotEnd.Visible = true;
            }
            else
            {
                btnLotCreate.Visible = true;
                btnLotEnd.Visible = false;
            }
        }

        private void txtSpliteCount_TextChanged(object sender, EventArgs e)
        {
            int QtyChk = 0;

            bool isNum = int.TryParse(txtSpliteCount.Text, out QtyChk);

            if (!isNum)
            {
                MPCF.ShowMsgBox("is Not Number (숫자만 입력 가능합니다.)");
                txtSpliteCount.Text = "1";
            }

        }

        private void cdvWorkPlace_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            cdvOper.Text = "";
            txtGoodQty.Text = "";
            txtLossQty.Text = "";
            MPCF.ClearList(spdPoInfo);
            MPCF.ClearList(spdLotList);
        }

        private void btnSpliteCount_Click(object sender, EventArgs e)
        {
            if (MPCF.Trim(txtSpliteCount.Text) == "")
            {
                MPCF.ShowMsgBox("Input Splite Count(분할수량을 입력하세요.)");
                return;
            };

            fnCreateLot();
            pnlInputSpliteCount.Visible = false;
        }

        private void textBox1_Click(object sender, EventArgs e)
        {
            pnlInputSpliteCount.Visible = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            pnlInputSpliteCount.Visible = false;
        }


        #endregion
    }
}
