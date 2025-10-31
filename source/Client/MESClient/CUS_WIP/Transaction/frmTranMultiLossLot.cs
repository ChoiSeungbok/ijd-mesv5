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

namespace CUS_WIP
{
    public partial class frmTranMultiLossLot : CUS_COM.frmTranForm01
    {
        public frmTranMultiLossLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOSS_INFO
        {
            LOSS_CODE,              // 1 : 불량코드
            LOSS_DESC,              // 2 : 불량명
            LOSS_QTY                // 3 : 불량수량
        }

        private enum LOT_INFO
        {
            CHK,                    // 1 :
            LOT_ID,                 // 2 : 
            MAT_ID,                 // 3 : 
            MAT_DESC,               // 4 :          
            CREATE_DATE,            // 5 :
            QTY,                    // 6 : 
            RES_ID,                 // 7 : 
            RES_DESC,               // 8 :  
            COMMENT                 // 9 :
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
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewLossCodeList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2015-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLoss);
                    return;
                }

                MPCF.ClearList(spdLoss);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLoss_Sheet1.RowCount++;

                    spdLoss_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_CODE].Value = dt.Rows[i]["LOSS_CODE"];
                    spdLoss_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_DESC].Value = dt.Rows[i]["LOSS_DESC"];
                    spdLoss_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_QTY].Value = dt.Rows[i]["LOSS_QTY"];
                }

                MPCF.FitColumnHeader(spdLoss);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewLotInfo(string sLot_ID)
        {
            string sLotId = "";
            int iRow = 0;
            bool bContinueFlag = false;

            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                if (MPCF.Trim(sLot_ID) != "")
                {
                    in_node.ProcStep = '1';
                    in_node.AddString("LOT_ID", sLot_ID);
                }
                else
                    in_node.ProcStep = '3';

                in_node.AddString("OPER", cdvOper.Text);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_Info", in_node, ref out_node) == false)
                {
                    return;
                }
                for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                {
                    bContinueFlag = false;

                    //lot 정보가 이미 있는경우 넘어간다.
                    sLotId = out_node.GetList("LOT_TBL")[i].GetString("LOT_ID");
                    for (int k = 0; k < spdLotList.ActiveSheet.RowCount; k++)
                    {
                        if (sLotId == spdLotList.ActiveSheet.Cells[k, (int)LOT_INFO.LOT_ID].Text)
                        {
                            bContinueFlag = true;
                            continue;
                        }
                    }

                    if (out_node.GetString("OPER_OPTION_1") != "Y")
                    {
                        if (i == 0)
                        {
                            cdvDept.Text = out_node.GetList("LOT_TBL")[0].GetString("AREA_ID");
                            cdvDept.DisplayText = out_node.GetList("LOT_TBL")[0].GetString("AREA_DESC");
                            cdvWorkPlace.Text = out_node.GetList("LOT_TBL")[0].GetString("SUB_AREA_ID");
                            cdvWorkPlace.DisplayText = out_node.GetList("LOT_TBL")[0].GetString("SUB_AREA_DESC");
                            cdvOper.Text = out_node.GetList("LOT_TBL")[0].GetString("OPER");
                            cdvOper.DisplayText = out_node.GetList("LOT_TBL")[0].GetString("OPER_DESC");
                        }
                    }

                    if (bContinueFlag == true)
                        continue;

                    iRow = spdLotList.ActiveSheet.RowCount;

                    spdLotList.ActiveSheet.RowCount++;
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CHK, true);
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_ID, out_node.GetList("LOT_TBL")[i].GetString("MAT_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_DESC, out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CREATE_DATE, MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("CREATE_TIME"), DATE_TIME_FORMAT.DATE));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.RES_ID, out_node.GetList("LOT_TBL")[i].GetString("RES_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.RES_DESC, out_node.GetList("LOT_TBL")[i].GetString("RES_DESC"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.COMMENT, out_node.GetList("LOT_TBL")[i].GetString("COMMENT"));
                }

                MPCF.FitColumnHeader(spdLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private bool LossLot()
        {
            TRSNode in_node = new TRSNode("loss_Code_In");
            TRSNode out_node = new TRSNode("loss_Code_Out");
            TRSNode loss_list;
            TRSNode lot_list;

            double d_loss_qty = 0;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '3';
                in_node.AddString("CUASE_OPER", cdvCauseOper.Text);
                in_node.AddString("RES_ID", spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.RES_ID].Text);

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        lot_list = in_node.AddNode("LOT_TBL");
                        lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                    }
                }

                for (int i = 0; i < spdLoss_Sheet1.RowCount; i++)
                {
                    if (MPCF.ToDbl(spdLoss_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_QTY].Text) != 0)
                    {
                        loss_list = in_node.AddNode("LOSS_TBL");
                        loss_list.AddString("CODE", spdLoss_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_CODE].Text);
                        loss_list.AddDouble("VALUE", spdLoss_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_QTY].Text);

                        d_loss_qty += MPCF.ToDbl(spdLoss_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_QTY].Value);
                    }
                }

                in_node.AddDouble("OUT_QTY_1", d_loss_qty);
                in_node.AddString("COMMENT", txtComment.Text);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Update_Lot_Loss", in_node, ref out_node) == false)
                    return false;
                else 
                    MPCR.ShowSuccessMsg(out_node);

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
            int iCount = 0;

            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
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

                        if (MPCF.Trim(cdvCauseOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblCauseOper.Text + "]");
                            cdvCauseOper.Focus();
                            return false;
                        }

                        for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                        {
                            if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                            {
                                iCount++;
                            }
                        }

                        if (iCount == 0)
                        {
                            //CMN199 ERROR - 선택된 Lot이 없습니다. 먼저 Lot을 선택하여 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(199));
                            return false;
                        }

                        iCount = 0;

                        for (int k = 0; k < spdLoss.ActiveSheet.RowCount; k++)
                        {
                            if (MPCF.ToDbl(spdLoss.ActiveSheet.Cells[k, (int)LOSS_INFO.LOSS_QTY].Text) != 0)
                                iCount++;
                        }

                        if (iCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305));
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

        private void ClearList()
        {
            try
            {
                MPCF.ClearList(spdLotList);
                MPCF.ClearList(spdLoss);

                cdvCauseOper.Text = "";
                txtComment.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmTranMultiLossLot_Load(object sender, EventArgs e)
        {
            try
            {


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
                ViewLossCodeList();

                cdvCauseOper.Text = cdvOper.Text;
                cdvCauseOper.DisplayText = cdvOper.DisplayText;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOper_TextBoxTextChanged(object sender, EventArgs e)
        {
            try
            {
                ViewLossCodeList();

                cdvCauseOper.Text = cdvOper.Text;
                cdvCauseOper.DisplayText = cdvOper.DisplayText;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvCauseOper_ButtonPress(object sender, EventArgs e)
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

                cdvCauseOper.Init();
                MPCF.InitListView(cdvCauseOper.GetListView);
                cdvCauseOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvCauseOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvCauseOper.SelectedSubItemIndex = 0;
                cdvCauseOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvCauseOper.GetListView, '2', cdvDept.Text) == false)
                {
                    return;
                }

                cdvCauseOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtLotID_ButtonClick(object sender, Infragistics.Win.Misc.AlertButtonClickedEventArgs e)
        {
            try
            {
                txtLotID.sArea_id = cdvDept.Text;
                txtLotID.sArea_desc = cdvDept.DisplayText;
                txtLotID.sSub_Area_id = cdvWorkPlace.Text;
                txtLotID.sSub_Area_desc = cdvWorkPlace.DisplayText;
                txtLotID.sOper_id = cdvOper.Text;
                txtLotID.sOper_desc = cdvOper.DisplayText;
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
                    if (MPCF.Trim(txtLotID.Text) == "")
                        return;

                    ViewLotInfo(txtLotID.Text);
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
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewLotInfo(txtLotID.Text);
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
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (LossLot())
                {
                    ClearList();

                    ViewLossCodeList();                    
                    //ViewLotInfo("");                    
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
