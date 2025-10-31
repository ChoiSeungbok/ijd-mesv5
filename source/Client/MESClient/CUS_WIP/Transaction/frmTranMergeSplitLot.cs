using CUS_COM;
using FarPoint.Win.Spread;
using Miracom.CliFrx;
using Miracom.DNMCore;
using Miracom.MESCore;
using Miracom.TRSCore;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CUS_WIP
{
    public partial class frmTranMergeSplitLot : frmViewForm03
    {
        public frmTranMergeSplitLot()
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
            UNIT,
            OPER,
            OPER_DESC,
            PROD_QTY,                // 5 : 생산수량
            CHANGE_QTY,
            COMMENT
        }

        private enum TRAN_LOT_INFO
        {
            CHK,                    // 1 : CHECK
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 제품코드
            MAT_DESC,               // 4 : 제품명            
            PROD_QTY,                // 5 : 생산수량
            CHANGE_QTY
        }

        #endregion

        #region " Variable Definition "

        private class SelectedLotInfo
        {
            public int RowIndex { get; set; }
            public string LotID { get; set; }
            public string MatID { get; set; }
            public string MatDesc { get; set; }
            public double Qty { get; set; }
        }

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


                cboTranType.Items.Add("MERGE");
                cboTranType.Items.Add("SPLIT");
                cboTranType.SelectedIndex = 0;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool ViewLotList()
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
            DataTable dt = null;
            string sSql = "";
            int i = 0;
            string s_view_id = "";
            int iRow = 0;

            try
            {
                spdLotList_Sheet1.RowCount = 0;
                MPCF.ClearList(spdLotList);
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;

                dvcArgu[3].sCondition_ID = "MAT_ID";
                dvcArgu[3].sCondition_Value = cdvMat.Text;

                dvcArgu[4].sCondition_ID = "MAT_DESC";
                dvcArgu[4].sCondition_Value = txtMatDesc.Text;

                dvcArgu[5].sCondition_ID = "LOT_ID";
                dvcArgu[5].sCondition_Value = txtLotID.Text;

                s_view_id = "CWIP2030-001";

                if (TPDR.GetDataOne("", ref dt, s_view_id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                iRow = spdLotList.ActiveSheet.RowCount;

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Sheet1.RowCount++;
                    spdLotList_Sheet1.SetValue(iRow + i, (int)LOT_INFO.CHK, false);
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.UNIT].Value = dt.Rows[i]["UNIT_1"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.PROD_QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.CHANGE_QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.COMMENT].Value = dt.Rows[i]["LAST_COMMENT"];
                }

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private bool SaveProcess()
        {
            int iRow = 0;

            SelectedLotInfo selectedLotInfo = null;

            try
            {
                SheetView sv = spdTranLotList.ActiveSheet;

                if (cboTranType.SelectedItem.Equals("MERGE"))
                {
                    TRSNode in_node = new TRSNode("Process_In");
                    TRSNode out_node = new TRSNode("Process_Out");
                    TRSNode Lot_list;

                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '1';

                    selectedLotInfo = new SelectedLotInfo();

                    // Merge 할때 수량이 가장 큰 LOT_ID로 합쳐준다. 
                    // 수량이 동일한 경우 먼저 선택된 순
                    for (int i = 0; i < sv.RowCount; i++)
                    {
                        if (Convert.ToBoolean(sv.Cells[i, (int)TRAN_LOT_INFO.CHK].Value) == true)
                        {
                            if (selectedLotInfo.Qty < MPCF.ToDbl(sv.Cells[i, (int)TRAN_LOT_INFO.PROD_QTY].Value))
                            {
                                selectedLotInfo.LotID = sv.Cells[i, (int)TRAN_LOT_INFO.LOT_ID].Text;
                                selectedLotInfo.MatID = sv.Cells[i, (int)TRAN_LOT_INFO.MAT_ID].Text;
                                selectedLotInfo.MatDesc = sv.Cells[i, (int)TRAN_LOT_INFO.MAT_DESC].Text;
                                selectedLotInfo.Qty = MPCF.ToDbl(sv.Cells[i, (int)TRAN_LOT_INFO.PROD_QTY].Value);
                            }
                        }
                    }

                    in_node.AddString("LOT_ID", selectedLotInfo.LotID);

                    for (int i = 0; i < sv.RowCount; i++)
                    {
                        if (Convert.ToBoolean(sv.Cells[i, (int)TRAN_LOT_INFO.CHK] == null ? false : sv.Cells[i, (int)TRAN_LOT_INFO.CHK].Value))
                        {
                            if (sv.Cells[i, (int)TRAN_LOT_INFO.LOT_ID].Text.Equals(selectedLotInfo.LotID))
                                continue;

                            Lot_list = in_node.AddNode("LOT_TBL");
                            Lot_list.AddString("LOT_ID", sv.Cells[i, (int)TRAN_LOT_INFO.LOT_ID].Text);
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
                        MPCF.ClearList(spdTranLotList);
                        ViewLotList();

                        PrintLabel(cdvLabel.Text);
                    }

                    MPCF.ClearList(spdTranLotList);
                }
                else
                {
                    TRSNode in_node = new TRSNode("Process_In");
                    TRSNode out_node = new TRSNode("Process_Out");
                    TRSNode Lot_list;

                    selectedLotInfo = new SelectedLotInfo();

                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '1';

                    for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        if (Convert.ToBoolean(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value) == true)
                        {
                            selectedLotInfo.RowIndex = i;
                            selectedLotInfo.LotID = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text;
                            selectedLotInfo.MatID = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Text;
                            selectedLotInfo.MatDesc = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_DESC].Text;
                            selectedLotInfo.Qty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Value);
                        }
                    }

                    in_node.AddString("LOT_ID", selectedLotInfo.LotID);

                    for (int i = 0; i < sv.RowCount; i++)
                    {
                        if (Convert.ToBoolean(sv.Cells[i, (int)TRAN_LOT_INFO.CHK] == null ? false : sv.Cells[i, (int)TRAN_LOT_INFO.CHK].Value))
                        {
                            Lot_list = in_node.AddNode("LOT_TBL");
                            Lot_list.AddString("LOT_ID", sv.Cells[i, (int)TRAN_LOT_INFO.LOT_ID].Text);
                            Lot_list.AddDouble("QTY_1", MPCF.ToDbl(sv.Cells[i, (int)TRAN_LOT_INFO.CHANGE_QTY].Text));
                        }
                    }
                    in_node.AddString("COMMENT", txtComment.Text);

                    if (MPCR.CallService("CUS_WIP", "CUS_WIP_Split_Wip_Lot", in_node, ref out_node) == false)
                        return false;
                    else
                        MPCR.ShowSuccessMsg(out_node);


                    if (out_node.GetList("LOT_TBL").Count > 0)
                    {
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdTranLotList);
                        ViewLotList();

                        //시작 처리된 lot id를 받아 화면에 보이게 해준다.
                        for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                        {
                            iRow = sv.RowCount;

                            spdLotList.ActiveSheet.RowCount++;
                            spdLotList.ActiveSheet.SetValue(iRow, (int)TRAN_LOT_INFO.CHK, false);
                            spdLotList.ActiveSheet.SetValue(iRow, (int)TRAN_LOT_INFO.LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                            spdLotList.ActiveSheet.SetValue(iRow, (int)TRAN_LOT_INFO.MAT_ID, out_node.GetList("LOT_TBL")[i].GetString("MAT_ID"));
                            spdLotList.ActiveSheet.SetValue(iRow, (int)TRAN_LOT_INFO.MAT_DESC, out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC"));
                            spdLotList.ActiveSheet.SetValue(iRow, (int)TRAN_LOT_INFO.PROD_QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                            spdLotList.ActiveSheet.SetValue(iRow, (int)TRAN_LOT_INFO.CHANGE_QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                        }

                        PrintLabel(cdvLabel.Text);
                    }
                }

                CalcFooterData();
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void CalcFooterData()
        {
            double totalProdQty = 0;
            double totalChangeQty = 0;
            int iCount = 0;

            try
            {
                for (int i = 0; i < spdTranLotList.ActiveSheet.RowCount; i++)
                {
                    iCount++;
                    totalProdQty += MPCF.ToDbl(spdTranLotList.ActiveSheet.Cells[i, (int)TRAN_LOT_INFO.PROD_QTY].Text);
                    totalChangeQty += MPCF.ToDbl(spdTranLotList.ActiveSheet.Cells[i, (int)TRAN_LOT_INFO.CHANGE_QTY].Text);
                }

                spdTranLotList.ActiveSheet.ColumnFooter.Cells[0, (int)TRAN_LOT_INFO.CHK].Value = iCount;
                spdTranLotList.ActiveSheet.ColumnFooter.Cells[0, (int)TRAN_LOT_INFO.PROD_QTY].Value = totalProdQty;
                spdTranLotList.ActiveSheet.ColumnFooter.Cells[0, (int)TRAN_LOT_INFO.CHANGE_QTY].Value = totalChangeQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void PrintLabel(string sPrintLabel)
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

        //벨리데이션 체크 함수
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                FarPoint.Win.Spread.SheetView sv = spdLotList.ActiveSheet;
                int iCheckCount = 0;
                string prevMatID = string.Empty;
                string prevOper = string.Empty;
            

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:


                        break;

                    case CSGC.CHECK.ADD:

                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (Convert.ToBoolean(sv.Cells[i, (int)LOT_INFO.CHK].Value) == true)
                            {
                                iCheckCount++;

                                for (int idx = 0; idx < spdTranLotList.ActiveSheet.RowCount; idx++)
                                {
                                    if (spdTranLotList_Sheet1.Cells[idx, (int)TRAN_LOT_INFO.LOT_ID].Value == sv.Cells[i, (int)LOT_INFO.LOT_ID].Value)
                                    {
                                        MPCF.ShowMsgBox(MPCF.GetMessage(109)); //CMN164 ERROR -이 Lot은 이미 존재 합니다. Lot을 확인 하세요.
                                        return false;
                                    }
                                }                                    
                            }
                        }

                        if (iCheckCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(465)); //CMN465 INFO - 체크항목이 존재하지 않습니다. 확인해주세요.
                            return false;
                        }

                        if (cboTranType.SelectedItem.Equals("MERGE"))
                        {
                            for (int i = 0; i < sv.RowCount; i++)
                            {
                                if (Convert.ToBoolean(sv.Cells[i, (int)LOT_INFO.CHK].Value) == true)
                                {
                                    if (i > 0)
                                    {
                                        if (!prevMatID.Equals(sv.Cells[i, (int)LOT_INFO.MAT_ID].Text))
                                        {
                                            MPCF.ShowMsgBox(MPCF.GetMessage(512)); //CMN512 INFO - 품목 또는 공정이 다르면 Lot을 병합 할 수 없습니다.
                                            return false;
                                        }

                                        if (!prevOper.Equals(sv.Cells[i, (int)LOT_INFO.OPER].Text))
                                        {
                                            MPCF.ShowMsgBox(MPCF.GetMessage(512)); //CMN512 INFO - 품목 또는 공정이 다르면 Lot을 병합 할 수 없습니다.
                                            return false;
                                        }
                                    }

                                    prevMatID = sv.Cells[i, (int)LOT_INFO.MAT_ID].Text;
                                    prevOper = sv.Cells[i, (int)LOT_INFO.OPER].Text;
                                }
                            }
                        }
                        else
                        {
                            if (iCheckCount > 1)
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(516)); //CMN516 INFO - 1개의 항목만 선택가능합니다.
                                return false;
                            }
                        }                        

                        break;

                    case CSGC.CHECK.DELETE:

                        for (int idx = 0; idx < spdTranLotList.ActiveSheet.RowCount; idx++)
                        {
                            if (Convert.ToBoolean(sv.Cells[idx, (int)TRAN_LOT_INFO.CHK].Value) == true)
                            {
                                iCheckCount++;                                
                            }
                        }

                        if (iCheckCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(465)); //CMN465 INFO - 체크항목이 존재하지 않습니다. 확인해주세요.
                            return false;
                        }
                        

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

        private void ClearData()
        {
            try
            {
                MPCF.FieldClear(grpLotInfo);
                MPCF.ClearList(spdLotList);
                MPCF.ClearList(spdTranLotList);
                txtSplitCount.Text = "0";
                spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.CHK].Value = 0;
                spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.PROD_QTY].Value = 0;
                spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.CHANGE_QTY].Value = 0;

                spdTranLotList.ActiveSheet.ColumnFooter.Cells[0, (int)TRAN_LOT_INFO.CHK].Value = 0;
                spdTranLotList.ActiveSheet.ColumnFooter.Cells[0, (int)TRAN_LOT_INFO.PROD_QTY].Value = 0;
                spdTranLotList.ActiveSheet.ColumnFooter.Cells[0, (int)TRAN_LOT_INFO.CHANGE_QTY].Value = 0;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "
        private void btnProcess_Click(object sender, EventArgs e)
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
                        PrintLabel(cdvLabel.Text);
                    }

                    ViewLotList();
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
                ViewLotList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cboTranType_SelectedValueChanged(object sender, EventArgs e)
        {
            if(((ComboBox)sender).SelectedItem.Equals("MERGE"))
            {
                txtSplitCount.Enabled = false;
            }
            else
            {
                txtSplitCount.Enabled = true;
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            int iSplitCount = 0;
            int iRow = 0;
            int xIndex = 0;
            double splitQty = 0;

            SelectedLotInfo splitLot = null;

            iRow = spdTranLotList.ActiveSheet.RowCount;
            try
            {
                cboTranType.Enabled = false;

                if (cboTranType.SelectedItem.Equals("MERGE"))
                {
                    for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        if (Convert.ToBoolean(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value) == true)
                        {
                            spdTranLotList_Sheet1.RowCount++;

                            spdTranLotList_Sheet1.SetValue(iRow + xIndex, (int)TRAN_LOT_INFO.CHK, true);
                            spdTranLotList_Sheet1.Cells[iRow + xIndex, (int)TRAN_LOT_INFO.LOT_ID].Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Value;
                            spdTranLotList_Sheet1.Cells[iRow + xIndex, (int)TRAN_LOT_INFO.MAT_ID].Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Value;
                            spdTranLotList_Sheet1.Cells[iRow + xIndex, (int)TRAN_LOT_INFO.MAT_DESC].Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_DESC].Value;
                            spdTranLotList_Sheet1.Cells[iRow + xIndex, (int)TRAN_LOT_INFO.PROD_QTY].Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Value;
                            spdTranLotList_Sheet1.Cells[iRow + xIndex, (int)TRAN_LOT_INFO.CHANGE_QTY].Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHANGE_QTY].Value;
                            spdTranLotList_Sheet1.Cells[iRow + xIndex, (int)TRAN_LOT_INFO.CHANGE_QTY].Locked = true;
                            xIndex++;
                        }
                    }

                    CalcFooterData();
                }
                else
                {
                    // Split 은 선택한 Lot 의 Max 수량 안에서만 쪼개진다.
                    splitLot = new SelectedLotInfo();

                    for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        if (Convert.ToBoolean(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value) == true)
                        {
                            splitLot.RowIndex = i;
                            splitLot.LotID = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text;
                            splitLot.MatID = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Text;
                            splitLot.MatDesc = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_DESC].Text;
                            splitLot.Qty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Value);
                        }
                    }

                    iSplitCount = MPCF.ToInt(txtSplitCount.Text);

                    splitQty = splitLot.Qty / iSplitCount;

                    // Split 할 수량대로 하단 리스트에 추가
                    if (iSplitCount > 0)
                    {
                        for (int i = 0; i < iSplitCount; i++)
                        {
                            spdTranLotList_Sheet1.RowCount++;

                            spdTranLotList_Sheet1.SetValue(iRow + i, (int)TRAN_LOT_INFO.CHK, true);
                            spdTranLotList_Sheet1.Cells[iRow + i, (int)TRAN_LOT_INFO.LOT_ID].Value = " ";
                            spdTranLotList_Sheet1.Cells[iRow + i, (int)TRAN_LOT_INFO.MAT_ID].Value = splitLot.MatID;
                            spdTranLotList_Sheet1.Cells[iRow + i, (int)TRAN_LOT_INFO.MAT_DESC].Value = splitLot.MatDesc;
                            spdTranLotList_Sheet1.Cells[iRow + i, (int)TRAN_LOT_INFO.PROD_QTY].Value = splitQty;
                            spdTranLotList_Sheet1.Cells[iRow + i, (int)TRAN_LOT_INFO.CHANGE_QTY].Value = splitQty;
                        }

                        CalcFooterData();
                    }
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
                for (int i = spdTranLotList.ActiveSheet.RowCount; i > 0; i--)
                {
                    if (Convert.ToBoolean(spdTranLotList.ActiveSheet.Cells[i -1, (int)TRAN_LOT_INFO.CHK].Value) == true)
                    {
                        spdTranLotList.ActiveSheet.RemoveRows(i - 1, 1);
                    }
                }

                if (spdTranLotList.ActiveSheet.RowCount == 0)
                {
                    cboTranType.Enabled = true;
                }

                CalcFooterData();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnTranClear_Click(object sender, EventArgs e)
        {
            try
            {
                spdTranLotList.ActiveSheet.RowCount = 0;
                cboTranType.Enabled = true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            ClearData();
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

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, 'P', cdvDept.Text, "", "", "", 'Y') == false)
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

        private void cdvMat_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMat.Text = popup.sMat_id;
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

        #endregion
    }
}
