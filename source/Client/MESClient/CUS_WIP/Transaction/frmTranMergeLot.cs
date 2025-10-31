using System;
using System.Windows.Forms;
using System.Data;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using FarPoint.Win.Spread;

namespace CUS_WIP
{
    public partial class frmTranMergeLot : frmViewForm01
    {


        public DataTable dtLotList = new DataTable();


        


        public frmTranMergeLot()
        {
            InitializeComponent();
            InitControl();
        }

        #region " Constant Definition "

        private enum LOT_INFO
        {
            CHK,                    // 1 : CHECK
            LOT_ID,                 // 2 : LOT ID
            LOT_STATUS,             // 3 : LOT 상태
            MAT_ID,                 // 4 : 제품코드
            MAT_DESC,               // 5 : 제품명            
            OPER_DESC,              // 6 : 공정            
            PROD_QTY                // 7 : 생산수량
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
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewLotInfo(string sLotID)
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", sLotID);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_Info", in_node, ref out_node) == false)
                {
                    return;
                }

                if (out_node.GetList("LOT_TBL").Count > 0)
                {
                    txtAreaId.Text = out_node.GetList("LOT_TBL")[0].GetString("AREA_ID");
                    txtSubAreaId.Text = out_node.GetList("LOT_TBL")[0].GetString("SUB_AREA_DESC");
                    txtOperCode.Text = out_node.GetList("LOT_TBL")[0].GetString("OPER");
                    txtOperDesc.Text = out_node.GetList("LOT_TBL")[0].GetString("OPER_DESC");
                    txtMatId.Text = out_node.GetList("LOT_TBL")[0].GetString("MAT_ID");
                    txtMatDesc.Text = out_node.GetList("LOT_TBL")[0].GetString("MAT_DESC");
                    txtUnit.Text = out_node.GetList("LOT_TBL")[0].GetString("UNIT_1");
                    txtLotType.Text = out_node.GetList("LOT_TBL")[0].GetString("LOT_TYPE");
                    txtLotStatus.Text = out_node.GetList("LOT_TBL")[0].GetString("LOT_STATUS");
                    txtQty.Text = out_node.GetList("LOT_TBL")[0].GetDouble("QTY_1").ToString();
                    txtChangeQty.Text = out_node.GetList("LOT_TBL")[0].GetDouble("QTY_1").ToString(); 
                    txtComment.Text = out_node.GetList("LOT_TBL")[0].GetString("COMMENT").ToString(); 
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void ValidLotInfo(string sLotID)
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", sLotID);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_Info", in_node, ref out_node) == false)
                {
                    return;
                }
                if (out_node.GetList("LOT_TBL").Count > 0)
                {

                    if (this.txtLotStatus.Text != out_node.GetList("LOT_TBL")[0].GetString("LOT_STATUS"))
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(513)); //CMN513 INFO -LOT 상태가 다르면 Lot을 병합 할 수 없습니다.
                       txtMergeLot.SelectAll();
                        return;
                    }

                    if (txtMatId.Text != out_node.GetList("LOT_TBL")[0].GetString("MAT_ID"))
                   {
                        MPCF.ShowMsgBox(MPCF.GetMessage(512)); //CMN512 INFO - 품목 또는 공정이 다르면 Lot을 병합 할 수 없습니다.
                        txtMergeLot.SelectAll();
                        return;
                    }
                    if (txtOperCode.Text != out_node.GetList("LOT_TBL")[0].GetString("OPER"))
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(512));//CMN512 INFO - 품목 또는 공정이 다르면 Lot을 병합 할 수 없습니다.
                        txtMergeLot.SelectAll();
                        return;
                    }
                    int idxRow = spdLotList.ActiveSheet.RowCount;

                    for (int i = 0; i < out_node.ListCount; i++)
                    {
                        idxRow = spdLotList.ActiveSheet.RowCount++;

                        spdLotList.ActiveSheet.SetValue(idxRow, (int)LOT_INFO.CHK, true);
                        spdLotList.ActiveSheet.Cells[idxRow, (int)LOT_INFO.LOT_ID].Value = out_node.GetList("LOT_TBL")[0].GetString("LOT_ID");
                        spdLotList.ActiveSheet.Cells[idxRow, (int)LOT_INFO.LOT_STATUS].Value = out_node.GetList("LOT_TBL")[0].GetString("LOT_STATUS");
                        spdLotList.ActiveSheet.Cells[idxRow, (int)LOT_INFO.MAT_ID].Value = out_node.GetList("LOT_TBL")[0].GetString("MAT_ID");
                        spdLotList.ActiveSheet.Cells[idxRow, (int)LOT_INFO.MAT_DESC].Value = out_node.GetList("LOT_TBL")[0].GetString("MAT_DESC");
                        spdLotList.ActiveSheet.Cells[idxRow, (int)LOT_INFO.OPER_DESC].Value = out_node.GetList("LOT_TBL")[0].GetString("OPER_DESC");
                        spdLotList.ActiveSheet.Cells[idxRow, (int)LOT_INFO.PROD_QTY].Value = out_node.GetList("LOT_TBL")[0].GetDouble("QTY_1");
                    }
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
        
        private bool SaveProcess()
        {
            try
            {
                SheetView sv = spdLotList.ActiveSheet;

                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                TRSNode Lot_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                in_node.AddString("LOT_ID", txtLotID.Text);

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)LOT_INFO.CHK] == null ? false : sv.Cells[i, (int)LOT_INFO.CHK].Value))
                    {
                        Lot_list = in_node.AddNode("LOT_TBL");
                        Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                        // Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text));
                    }
                }
                in_node.AddString("COMMENT", txtComment.Text);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Merge_Wip_Lot", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                if (MPCF.Trim(out_node.GetString("LOT_ID")) != "")
                {
                    MPCF.ClearList(spdLotList);
                    MPCF.FieldClear(grpLotInfo);
                    txtLotID.Text = out_node.GetString("LOT_ID");
                    ViewLotInfo(txtLotID.Text);
                    PrintLable(cdvLabel.Text);
                }

                MPCF.ClearList(spdLotList);

               // fnCalData();

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void fnCalData()
        {
            double dSumProd = 0;
            int iCount = 0;
            SheetView sv = spdLotList.ActiveSheet;

            try
            {
                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)LOT_INFO.CHK] == null ? false : sv.Cells[i, (int)LOT_INFO.CHK].Value))
                    {
                        iCount++;

                        dSumProd = dSumProd + MPCF.ToDbl(sv.Cells[i, (int)LOT_INFO.PROD_QTY].Text);
                    }
                }

                sv.ColumnFooter.Cells[0, (int)LOT_INFO.CHK].Value = iCount;
                sv.ColumnFooter.Cells[0, (int)LOT_INFO.PROD_QTY].Value = dSumProd;

                txtChangeQty.Text = (MPCF.ToDbl(txtQty.Text) + dSumProd).ToString();
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void PrintLable(string sPrintLabel)
        {
            try
            {
                TRSNode print_node = new TRSNode("Print_In");
                TRSNode Print_Lot_list;
                MPCR.SetInMsg(print_node);

                Print_Lot_list = print_node.AddNode("LOT_LIST");
                Print_Lot_list.AddString("LOT_ID", txtLotID.Text);

                CSCF.ViewLabelList(sPrintLabel, print_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
               
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                SheetView sv = spdLotList.ActiveSheet;
                int iCheckCount= 0;

                if (MPCF.Trim(txtLotID.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotID.Text + "]");
                    txtLotID.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.ADD:

                        if (MPCF.Trim(txtLotID.Text) == MPCF.Trim(txtMergeLot.Text))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(514)); //CMN514 INFO -모LOT과 같은 LOT은 병합 할 수 없습니다.
                            return false;
                        }
                        for (int i = 0; i < sv.RowCount; i++)
                        {                           
                            if (sv.Cells[i, (int)LOT_INFO.LOT_ID].Value.ToString() == txtMergeLot.Text)
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(164)); //CMN164 ERROR -이 Lot은 이미 존재 합니다. Lot을 확인 하세요.
                                return false;
                            }
                        }
                        break;
                    case CSGC.CHECK.SAVE:
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (Convert.ToBoolean(sv.Cells[i, (int)LOT_INFO.CHK] == null ? false : sv.Cells[i, (int)LOT_INFO.CHK].Value))
                            {
                                iCheckCount++;
                            }
                        }
                        if (iCheckCount == 0)
                        {                           
                            MPCF.ShowMsgBox(MPCF.GetMessage(465)); //체크항목이 존재하지 않습니다. 확인해주세요.
                            return false;
                        }
                        break;
                }
                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private void ClearData(CSGC.CHECK CHECK)
        {
            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.ALL:
                        MPCF.FieldClear(grpLotInfo);
                        MPCF.ClearList(spdLotList);
                        txtMergeLot.Text = "";
                        txtComment.Text = "";
                        txtLotID.Focus();
                        txtLotID.SelectAll();
                        chkLabel.Checked = false;
                        cdvLabel.Text = "";
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.CHK].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.PROD_QTY].Value = 0.00;
                        break;
                    case CSGC.CHECK.ADD:
                        txtMergeLot.Focus();
                        txtMergeLot.SelectAll();
                        txtComment.Text = "";
                        break;
                    case CSGC.CHECK.VIEW:
                        MPCF.ClearList(spdLotList);
                        txtMergeLot.Text = "";
                        txtComment.Text = "";
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.CHK].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.PROD_QTY].Value = 0.00;
                        break;
                    case CSGC.CHECK.SAVE:
                        txtLotID.Focus();
                        txtLotID.SelectAll();
                        txtMergeLot.Text = "";
                        txtComment.Text = "";
                        MPCF.ClearList(spdLotList);
                        chkLabel.Checked = false;
                        cdvLabel.Text = "";
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.CHK].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.PROD_QTY].Value = 0.00;
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

        private void frmTranMergeLot_Load(object sender, EventArgs e)
        {
            try
            {
                chkLabel.Checked = false;
                cdvLabel.Enabled = false;



                if(MPCF.Trim(txtLotID.Text) != "")
                {
                    ViewLotInfo(txtLotID.Text);
                }


                if(dtLotList.Rows.Count != 0)
                {
                    for (int i = 0; dtLotList.Rows.Count >i ; i++)
                    {
                        ValidLotInfo(dtLotList.Rows[i][0].ToString());
                    }
                }


                /*

                if (sArrLotList.Li != 0)
                {

                    for(int i = 0; Merge_Lot_List.Items.Count == i; i++)
                    {
                        ValidLotInfo(Merge_Lot_List.Items[i].Text);
                    }

                }
                */





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
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtMergeLot_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (CheckCondition(CSGC.CHECK.ADD) == false)
                        return;

                    ValidLotInfo(txtMergeLot.Text);
                    fnCalData();

                    ClearData(CSGC.CHECK.ADD);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                for (int i = spdLotList.ActiveSheet.RowCount; i > 0; i--)
                {
                    if (spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        spdLotList.ActiveSheet.RemoveRows(i - 1, 1);
                    }
                }

                fnCalData();
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
                ClearData(CSGC.CHECK.ALL);
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

                if (MPCF.Trim(txtLotID.Text) != "")
                {
                    ClearData(CSGC.CHECK.VIEW);

                    ViewLotInfo(txtLotID.Text);                    
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SaveProcess())
                {
                    if (chkLabel.Checked == true)
                    {
                        //프린트 공정인 경우 프린트 한다.
                        PrintLable(cdvLabel.Text);
                    }

                    ViewLotInfo(txtLotID.Text);

                    ClearData(CSGC.CHECK.SAVE);
                   
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvLabel_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvLabel.Init();
                MPCF.InitListView(cdvLabel.GetListView);
                cdvLabel.Columns.Add("Size", 50, HorizontalAlignment.Left);
                cdvLabel.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvLabel.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvLabel.SelectedSubItemIndex = 2;
                cdvLabel.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewLabelGCMList(cdvLabel.GetListView, txtAreaId.Text, CSGC.CP_LABEL_TYPE_OPER) == false)
                {
                    return;
                }

                cdvLabel.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        
        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            SheetView sv = spdLotList.ActiveSheet;

            try
            {
                if (e.ColumnHeader == true)
                {
                    if (sv.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdLotList, e.Row, e.Column, true, true, false);
                    }
                }
                fnCalData();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void chkLabel_CheckedChanged(object sender, EventArgs e)
        {
            try
            {
                if (chkLabel.Checked == true)
                {
                    cdvLabel.Enabled = true;
                }
                else
                {
                    cdvLabel.Enabled = false;
                }

                cdvLabel.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
              

        private void spdLotList_Change(object sender, ChangeEventArgs e)
        {
            try
            {
                fnCalData();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdLotList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            try
            {
                fnCalData();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion


    }

}
