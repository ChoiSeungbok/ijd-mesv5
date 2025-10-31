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
    public partial class frmTranMoveInvLot : CUS_COM.frmTranForm01
    {
        public frmTranMoveInvLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT
        {
            CHK,                     // 1 : CHECK
            INV_LOT_ID,              // 2 : 자재 LOT ID
            QTY,                     // 3 : 수량
            UNIT,                    // 4 : 단위
            OPER,                    // 5 : 창고
            OPER_DESC,               // 6 : 창고명
            MAT_ID,                  // 7 : 제품
            MAT_DESC                 // 8 : 제품명
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
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //이동 자재 LOT LIST 조회 함수
        private void ViewInvLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                double dSumQty = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;
                
                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = cdvMatID.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvFromOper.Text;

                dvcArgu[3].sCondition_ID = "AREA_ID";
                dvcArgu[3].sCondition_Value = cdvDept.Text;

                if (TPDR.GetDataOne("", ref dt, "CINV2003-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdFromInvLotList);
                    return;
                }

                MPCF.ClearList(spdFromInvLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdFromInvLotList_Sheet1.RowCount++;

                    spdFromInvLotList_Sheet1.SetValue(i, (int)LOT.CHK, false);
                    spdFromInvLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Value = dt.Rows[i]["INV_LOT_ID"];
                    spdFromInvLotList_Sheet1.Cells[i, (int)LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdFromInvLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdFromInvLotList_Sheet1.Cells[i, (int)LOT.OPER].Value = dt.Rows[i]["OPER"];
                    spdFromInvLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdFromInvLotList_Sheet1.Cells[i, (int)LOT. MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdFromInvLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                }
                MPCF.FitColumnHeader(spdFromInvLotList);

                for (i = 0; i < spdFromInvLotList_Sheet1.RowCount; i++)
                {
                    dSumQty += MPCF.ToDbl(spdFromInvLotList.ActiveSheet.Cells[i, (int)LOT.QTY].Text);
                }

                spdFromInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void CheckCount()
        {
            double dSumQty = 0;
            int iCount = 0;

            try
            {
                for (int i = 0; i < spdFromInvLotList_Sheet1.RowCount; i++)
                {
                    if (spdFromInvLotList_Sheet1.Cells[i, (int)LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdFromInvLotList_Sheet1.Cells[i, (int)LOT.QTY].Text);
                    }
                }

                spdFromInvLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.CHK].Value = iCount;
                spdFromInvLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void CheckCount2()
        {
            double dSumQty = 0;
            int iCount = 0;

            try
            {
                for (int i = 0; i < spdToInvLotList_Sheet1.RowCount; i++)
                {
                    if (spdToInvLotList_Sheet1.Cells[i, (int)LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdToInvLotList_Sheet1.Cells[i, (int)LOT.QTY].Text);
                    }
                }

                spdToInvLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.CHK].Value = iCount;
                spdToInvLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 입력 자재 LOT 정보 조회 후 데이터 추가
        private void InputInvLot()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i_Row = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;
                
                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = "";

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvFromOper.Text;

                dvcArgu[3].sCondition_ID = "INV_LOT_ID";
                dvcArgu[3].sCondition_Value = txtInvLotID.Text;
                
                if (TPDR.GetDataOne("", ref dt, "CINV2003-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    txtInvLotID.SelectAll();

                    return;
                }

                for (int i = 0; i < spdToInvLotList_Sheet1.RowCount; i++)
                {
                    // FROM 그리드에 데이터 제거
                    if (string.Equals(spdToInvLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Text, dt.Rows[0]["INV_LOT_ID"]))
                    {
                        spdToInvLotList_Sheet1.RemoveRows(i, 1);
                        break;
                    }
                }

                for (int i = 0; i < spdFromInvLotList_Sheet1.RowCount; i++)
                {
                    // FROM 그리드에 데이터 제거
                    if (string.Equals(spdFromInvLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Text, dt.Rows[0]["INV_LOT_ID"]))
                    {
                        spdFromInvLotList_Sheet1.RemoveRows(i, 1);
                        break;
                    }
                }
                
                // TO 그리드에 데이터 삽입
                i_Row = spdToInvLotList_Sheet1.RowCount++;

                spdToInvLotList_Sheet1.SetValue(i_Row, (int)LOT.CHK, true);
                spdToInvLotList_Sheet1.Cells[i_Row, (int)LOT.INV_LOT_ID].Value = dt.Rows[0]["INV_LOT_ID"];
                spdToInvLotList_Sheet1.Cells[i_Row, (int)LOT.QTY].Value = dt.Rows[0]["QTY"];
                spdToInvLotList_Sheet1.Cells[i_Row, (int)LOT.UNIT].Value = dt.Rows[0]["UNIT"];
                spdToInvLotList_Sheet1.Cells[i_Row, (int)LOT.OPER].Value = dt.Rows[0]["OPER"];
                spdToInvLotList_Sheet1.Cells[i_Row, (int)LOT.OPER_DESC].Value = dt.Rows[0]["OPER_DESC"];
                spdToInvLotList_Sheet1.Cells[i_Row, (int)LOT.MAT_ID].Value = dt.Rows[0]["MAT_ID"];
                spdToInvLotList_Sheet1.Cells[i_Row, (int)LOT.MAT_DESC].Value = dt.Rows[0]["MAT_DESC"];
                MPCF.FitColumnHeader(spdToInvLotList);

                txtInvLotID.SelectAll();

                CheckCount2();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //자재 LOT 이동
        private bool MoveInvLot()
        {
            TRSNode in_node = new TRSNode("move_InvLot_In");
            TRSNode out_node = new TRSNode("move_InvLot_Out");
            TRSNode Inv_Lot_list;
            bool send_flag = false;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("TO_OPER", cdvToOper.Text);
                in_node.AddString("TRAN_COMMENT", txtComment.Text);

                for (int i = 0; i < spdToInvLotList_Sheet1.RowCount; i++)
                {
                    if (spdToInvLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        Inv_Lot_list = in_node.AddNode("INV_LOT_LIST");
                        Inv_Lot_list.AddString("INV_LOT_ID", spdToInvLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Text);
                        send_flag = true;
                    }
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_INV", "CUS_INV_Move_Lot", in_node, ref out_node) == false)
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
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvFromOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFromOper.Text + "]");
                    cdvFromOper.Focus();
                    return false;
                }

                switch (sType)
                {
                    case "MOVE":
                        if(spdToInvLotList_Sheet1.RowCount == 0)
                        {
                            return false;
                        }

                        if (MPCF.Trim(cdvToOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToOper.Text + "]");
                            cdvToOper.Focus();
                            return false;
                        }

                        if (string.Equals(cdvFromOper.Text, cdvToOper.Text))
                        {
                            //CMN368 ERROR - 기존 공정과 이동 공정이 같습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(368) + " [" + lblToOper.Text + "]");
                            cdvToOper.Focus();
                            return false;
                        }

                        break;

                    case "INPUT":
                        if (MPCF.Trim(txtInvLotID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblInvLotID.Text + "]");
                            txtInvLotID.Focus();
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

                        MPCF.ClearList(spdFromInvLotList);
                        MPCF.ClearList(spdToInvLotList);
                        spdFromInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdFromInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;
                        spdToInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdToInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;

                        this.cdvToOper.Text = "";
                        this.txtInvLotID.Text = "";
                        this.txtComment.Text = "";
                        break;
                        
                    case "ALL":

                        MPCF.ClearList(spdFromInvLotList);
                        MPCF.ClearList(spdToInvLotList);
                        spdFromInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdFromInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;
                        spdToInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdToInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;

                        this.cdvDept.Text = "";
                        //this.cdvWorkPlace.Text = "";
                        this.cdvFromOper.Text = "";
                        this.cdvToOper.Text = "";
                        this.cdvMatID.Text = "";
                        this.txtInvLotID.Text = "";
                        this.txtComment.Text = "";
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
        private void frmTranMoveInvLot_Load(object sender, EventArgs e)
        {
            try
            {
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

        private void cdvMatID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                // 제품 팝업으로 변경
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                popup.sType_id = "RAW_MATERIAL";
                popup.sType_desc = "원재료";

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

                ViewInvLotList();
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
                int iRow = 0;

                for (int i = spdFromInvLotList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdFromInvLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        iRow = spdToInvLotList_Sheet1.RowCount++;

                        spdToInvLotList_Sheet1.SetValue(iRow, (int)LOT.CHK, true);
                        spdToInvLotList_Sheet1.Cells[iRow, (int)LOT.INV_LOT_ID].Value = spdFromInvLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Text;
                        spdToInvLotList_Sheet1.Cells[iRow, (int)LOT.QTY].Value = spdFromInvLotList_Sheet1.Cells[i, (int)LOT.QTY].Text;
                        spdToInvLotList_Sheet1.Cells[iRow, (int)LOT.UNIT].Value = spdFromInvLotList_Sheet1.Cells[i, (int)LOT.UNIT].Text;
                        spdToInvLotList_Sheet1.Cells[iRow, (int)LOT.OPER].Value = spdFromInvLotList_Sheet1.Cells[i, (int)LOT.OPER].Text;
                        spdToInvLotList_Sheet1.Cells[iRow, (int)LOT.OPER_DESC].Value = spdFromInvLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Text;
                        spdToInvLotList_Sheet1.Cells[iRow, (int)LOT.MAT_ID].Value = spdFromInvLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Text;
                        spdToInvLotList_Sheet1.Cells[iRow, (int)LOT.MAT_DESC].Value = spdFromInvLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Text;

                        spdFromInvLotList_Sheet1.RemoveRows(i, 1);
                    }
                }

                MPCF.FitColumnHeader(spdToInvLotList);

                CheckCount();
                CheckCount2();
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
                int iRow = 0;

                for (int i = spdToInvLotList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdToInvLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        iRow = spdFromInvLotList_Sheet1.RowCount++;

                        spdFromInvLotList_Sheet1.SetValue(iRow, (int)LOT.CHK, false);
                        spdFromInvLotList_Sheet1.Cells[iRow, (int)LOT.INV_LOT_ID].Value = spdToInvLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Text;
                        spdFromInvLotList_Sheet1.Cells[iRow, (int)LOT.QTY].Value = spdToInvLotList_Sheet1.Cells[i, (int)LOT.QTY].Text;
                        spdFromInvLotList_Sheet1.Cells[iRow, (int)LOT.UNIT].Value = spdToInvLotList_Sheet1.Cells[i, (int)LOT.UNIT].Text;
                        spdFromInvLotList_Sheet1.Cells[iRow, (int)LOT.OPER].Value = spdToInvLotList_Sheet1.Cells[i, (int)LOT.OPER].Text;
                        spdFromInvLotList_Sheet1.Cells[iRow, (int)LOT.OPER_DESC].Value = spdToInvLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Text;
                        spdFromInvLotList_Sheet1.Cells[iRow, (int)LOT.MAT_ID].Value = spdToInvLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Text;
                        spdFromInvLotList_Sheet1.Cells[iRow, (int)LOT.MAT_DESC].Value = spdToInvLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Text;

                        spdToInvLotList_Sheet1.RemoveRows(i, 1);
                    }
                }

                MPCF.FitColumnHeader(spdFromInvLotList);

                CheckCount();
                CheckCount2();
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
                if (CheckCondition("MOVE") == false)
                    return;

                if (MoveInvLot())
                {
                    ClearList("VIEW");
                    ViewInvLotList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdFromInvLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdFromInvLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdFromInvLotList, e.Row, e.Column, true, true, false);
                }

                CheckCount();
            }
        }

        private void spdToInvLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdToInvLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdToInvLotList, e.Row, e.Column, true, true, false);
                }

                CheckCount2();
            }
        }

        private void txtInvLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (CheckCondition("INPUT") == false)
                        return;

                    InputInvLot();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvFromOper_ButtonPress(object sender, EventArgs e)
        {
            cdvFromOper.Init();
            MPCF.InitListView(cdvFromOper.GetListView);
            cdvFromOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
            cdvFromOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvFromOper.SelectedSubItemIndex = 0;
            cdvFromOper.DisplaySubItemIndex = 1;

            if (COM_LIST.ViewOperationList(cdvFromOper.GetListView, '3', cdvDept.Text, "", "", "", 'Y') == false)
            {
                return;
            }

            cdvFromOper.InsertEmptyRow(0, 1);

            ClearList("VIEW");
        }

        private void cdvToOper_ButtonPress(object sender, EventArgs e)
        {
            cdvToOper.Init();
            MPCF.InitListView(cdvToOper.GetListView);
            cdvToOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
            cdvToOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvToOper.SelectedSubItemIndex = 0;
            cdvToOper.DisplaySubItemIndex = 1;

            if (COM_LIST.ViewOperationList(cdvToOper.GetListView, 'H', cdvDept.Text, "", "", "", 'Y') == false)
            {
                return;
            }

            cdvToOper.InsertEmptyRow(0, 1);
        }
        
        private void cdvDept_ButtonPress(object sender, EventArgs e)
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

        private void spdFromInvLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
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

        private void spdFromInvLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
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

        private void spdToInvLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                CheckCount2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdToInvLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            try
            {
                CheckCount2();
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

        #endregion
    }
}
