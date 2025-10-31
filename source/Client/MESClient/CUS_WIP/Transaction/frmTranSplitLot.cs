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
    public partial class frmTranSplitLot : CUS_COM.frmViewForm01
    {
        public frmTranSplitLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT_INFO
        {
            CHK,                    // 1 : CHECK
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 제품코드
            MAT_DESC,               // 4 : 제품명            
            PROD_QTY,               // 5 : 생산수량
            ADD_CHK,
            ADD_CHAR,
            ADD_BTN
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
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewLotInfo()
        {            
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", txtLotID.Text);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_Info", in_node, ref out_node) == false)
                {
                    return;
                }

                if(out_node.GetList("LOT_TBL").Count >0)
                {
                    txtAreaId.Text = out_node.GetList("LOT_TBL")[0].GetString("AREA_ID");
                    txtSubAreaId.Text= out_node.GetList("LOT_TBL")[0].GetString("SUB_AREA_DESC");
                    txtOper.Text = out_node.GetList("LOT_TBL")[0].GetString("OPER_DESC");
                    txtMatId.Text= out_node.GetList("LOT_TBL")[0].GetString("MAT_ID");
                    txtMatDesc.Text = out_node.GetList("LOT_TBL")[0].GetString("MAT_DESC");
                    txtUnit.Text = out_node.GetList("LOT_TBL")[0].GetString("UNIT_1");
                    txtLotType.Text = out_node.GetList("LOT_TBL")[0].GetString("LOT_TYPE");
                    txtLotStatus.Text = out_node.GetList("LOT_TBL")[0].GetString("LOT_STATUS");
                    txtQty.Text = out_node.GetList("LOT_TBL")[0].GetDouble("QTY_1").ToString();
                    txtChangeQty.Text = out_node.GetList("LOT_TBL")[0].GetDouble("QTY_1").ToString();
                }

                if (txtAreaId.Text == CSGV.gs_area_grit)
                {
                    spdLotList.ActiveSheet.Columns[(int)LOT_INFO.ADD_CHK].Visible = true;
                    spdLotList.ActiveSheet.Columns[(int)LOT_INFO.ADD_CHAR].Visible = true;
                    spdLotList.ActiveSheet.Columns[(int)LOT_INFO.ADD_BTN].Visible = true;
                }
                else
                {
                    spdLotList.ActiveSheet.Columns[(int)LOT_INFO.ADD_CHK].Visible = false;
                    spdLotList.ActiveSheet.Columns[(int)LOT_INFO.ADD_CHAR].Visible = false;
                    spdLotList.ActiveSheet.Columns[(int)LOT_INFO.ADD_BTN].Visible = false;
                }

                if (txtAreaId.Text == CSGV.gs_area_hm)
                {
                    txtConv.Visible = true;
                    lblConv.Visible = true;
                    btnConv.Visible = true;
                }
                else
                {
                    txtConv.Visible = false;
                    lblConv.Visible = false;
                    btnConv.Visible = false;
                }

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
            int iRow = 0;

            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                TRSNode Lot_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                in_node.AddString("LOT_ID", txtLotID.Text);

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        Lot_list = in_node.AddNode("LOT_TBL");
                        Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                        Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text));

                        //그릿의 문자 추가인 겨우
                        if (txtAreaId.Text == CSGV.gs_area_grit)
                        {
                            if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.ADD_CHK].Value.ToString().ToUpper() == "TRUE")
                            {
                                Lot_list.AddChar("ADD_CHAR_FLAG", 'Y');
                                Lot_list.AddString("ADD_LOT_CHAR", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.ADD_CHAR].Text);
                            }
                        }
                    }
                }
                in_node.AddString("COMMENT", txtComment.Text);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Split_Wip_Lot", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                MPCF.ClearList(spdLotList);

                //시작 처리된 lot id를 받아 화면에 보이게 해준다.
                for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                {
                    iRow = spdLotList.ActiveSheet.RowCount;

                    spdLotList.ActiveSheet.RowCount++;
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CHK, false);
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_ID, out_node.GetList("LOT_TBL")[i].GetString("MAT_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_DESC, out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.PROD_QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                }

                fnCalData();

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

            try
            {
                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;

                        dSumProd = dSumProd + MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text);
                    }
                }

                spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.CHK].Value = iCount;
                spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.PROD_QTY].Value = dSumProd;

                txtChangeQty.Text = (MPCF.ToDbl(txtQty.Text) - dSumProd).ToString();

                return;
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
                
                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    //if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    //{
                    Print_Lot_list = print_node.AddNode("LOT_LIST");
                    Print_Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                    //}
                }

                if(MPCF.ToDbl(txtChangeQty.Text) > 0)
                {
                    Print_Lot_list = print_node.AddNode("LOT_LIST");
                    Print_Lot_list.AddString("LOT_ID", txtLotID.Text);
                }

                CSCF.ViewLabelList(sPrintLabel, print_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        //벨리데이션 체크 함수
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                if (MPCF.Trim(txtLotID.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotID.Text + "]");
                    txtLotID.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                
                        break;

                    case CSGC.CHECK.SAVE:

                        if (chkLabel.Checked == true)
                        {
                            if (MPCF.Trim(cdvLabel.Text) == "")
                            {
                                //CMN519 INFO - 라벨종류를 선택하지 않았습니다. 라벨 종류를 선택하세요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(519) + " [" + chkLabel.Text + "]");
                                txtLotID.Focus();
                                return false;
                            }
                        }

                        //그릿의 문자 추가인 겨우 문자 추가가 비어있는 경우 
                        if (txtAreaId.Text == CSGV.gs_area_grit)
                        {
                            for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                            {
                                if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                                {                                   
                                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.ADD_CHK].Value.ToString().ToUpper() == "TRUE")
                                    {
                                        if (MPCF.Trim(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.ADD_CHAR].Text) == "")
                                        {
                                            //CMN544 INFO -  Lot뒤 문자 등록 여부  확인하세요.
                                            MPCF.ShowMsgBox(MPCF.GetMessage(544));
                                            return false;
                                        }
                                    }                                    
                                }
                            }
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



        private void ConvQty()
        {
            try
            {

                if(txtMatId.Text == "" || txtConv.Text == "")
                {
                    return;
                }


                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
   

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = txtMatId.Text;

                dvcArgu[2].sCondition_ID = "INPUT_QTY ";
                dvcArgu[2].sCondition_Value = txtConv.Text;

;

                if (TPDR.GetDataOne("", ref dt, "CSHP2010-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLotList);
                    return;
                }

                MPCF.ClearList(spdLotList);

                if(dt.Rows.Count == 0)
                {
                    return;
                }
                else
                {
                    txtConv.Text = "0";
                    txtSplitQty.Text = dt.Rows[0]["CONV_QTY"].ToString();
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void ClearData()
        {
            try
            {
                MPCF.FieldClear(grpLotInfo);
                MPCF.ClearList(spdLotList);
                txtLotID.Focus();
                txtLotID.SelectAll();
                txtSplitCount.Text = "0";
                txtSplitQty.Text = "0";
                spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.CHK].Value = 0;
                spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.PROD_QTY].Value = 0.00;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmTranSplitLot_Load(object sender, EventArgs e)
        {
            try
            {
                chkLabel.Checked = false;
                cdvLabel.Enabled = false;

                spdLotList.ActiveSheet.Columns[(int)LOT_INFO.ADD_CHK].Visible = false;
                spdLotList.ActiveSheet.Columns[(int)LOT_INFO.ADD_CHAR].Visible = false;
                spdLotList.ActiveSheet.Columns[(int)LOT_INFO.ADD_BTN].Visible = false;

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

        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)LOT_INFO.CHK)
                    {
                        CSCF.CheckSpreadCell(spdLotList, 0, 0, true, true);
                    }

                    fnCalData();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            try
            {
                if (e.Column == (int)LOT_INFO.PROD_QTY)
                {
                    fnCalData();
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
                if (e.Column == (int)LOT_INFO.CHK)
                {
                    fnCalData();
                }
                else if (e.Column == (int)LOT_INFO.ADD_CHK)
                {
                    if (spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.ADD_CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.ADD_CHAR].Text = "";
                        spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.ADD_BTN].Locked= false;
                    }
                    else
                    {
                        spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.ADD_CHAR].Text = "";
                        spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.ADD_BTN].Locked = true;
                    }
                }
                else if (e.Column == (int)LOT_INFO.ADD_BTN)
                {
                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("Desc", 0, HorizontalAlignment.Left);

                    if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', CSGC.CP_GCM_ADD_LOT_CHAR) == false)
                        return;

                    cdvGridButton.ShowPopupList(e.Row, e.Column);
                    cdvGridButton.AddEmptyRow(1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (spdLotList.ActiveSheet.ActiveColumnIndex == (int)LOT_INFO.ADD_BTN)
                {
                    spdLotList.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.ADD_CHAR, e.SelectedItem.SubItems[0].Text);
                    //spdLotList.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHK, true);                    
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            int iSplitCount = 0;
            int iRow = 0;
            double d_total_qty = 0;

            try
            {
                if (MPCF.ToInt(txtSplitCount.Text) != 0)
                {
                    iSplitCount = MPCF.ToInt(txtSplitCount.Text);
                    iRow = spdLotList.ActiveSheet.RowCount;

                    for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        d_total_qty = d_total_qty + MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text);
                    }

                    d_total_qty += (iSplitCount * MPCF.ToDbl(txtSplitQty.Text));

                    if(d_total_qty > MPCF.ToDbl(txtQty.Text))
                    {
                        //CMN126 ERROR -입력한 값이 한계값을 넘었습니다.다른 수를 입력해 주세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(126));
                        return;
                    }

                    for (int i = 0; i < iSplitCount; i++)
                    {
                        spdLotList_Sheet1.RowCount++;

                        spdLotList_Sheet1.SetValue(iRow + i, (int)LOT_INFO.CHK, true);
                        spdLotList_Sheet1.Cells[iRow + i, (int)LOT_INFO.LOT_ID].Value = " ";
                        spdLotList_Sheet1.Cells[iRow + i, (int)LOT_INFO.MAT_ID].Value = txtMatId.Text;
                        spdLotList_Sheet1.Cells[iRow + i, (int)LOT_INFO.MAT_DESC].Value = txtMatDesc.Text;
                        spdLotList_Sheet1.Cells[iRow + i, (int)LOT_INFO.PROD_QTY].Value = MPCF.ToDbl(txtSplitQty.Text);
                        spdLotList_Sheet1.SetValue(iRow + i, (int)LOT_INFO.ADD_CHK, false);
                        spdLotList_Sheet1.Cells[iRow + i, (int)LOT_INFO.ADD_CHAR].Value = " ";
                    }

                    fnCalData();
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
                ClearData();
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
                    MPCF.ClearList(spdLotList);
                    txtSplitQty.Text = "0";
                    txtSplitCount.Text = "0";
                    ViewLotInfo();
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

                    //ViewLotInfo();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void txtConv_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    ConvQty();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnConv_Click(object sender, EventArgs e)
        {
            ConvQty();
        }

        #endregion

    }
}
