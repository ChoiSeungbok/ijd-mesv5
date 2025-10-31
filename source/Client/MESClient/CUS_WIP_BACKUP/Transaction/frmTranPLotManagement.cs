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
    public partial class frmTranPLotManagement : CUS_COM.frmTranForm01
    {
        public frmTranPLotManagement()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT
        {
            CHK,                     // 1 : CHECK
            LOT_ID,              // 2 : 자재 LOT ID
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

        //이동 LOT LIST 조회 함수
        private void ViewLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;
                
                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = cdvMatID.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvFromOper.Text;

                dvcArgu[3].sCondition_ID = "AREA_ID";
                dvcArgu[3].sCondition_Value = cdvDept.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2019-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdFromLotList);
                    return;
                }

                MPCF.ClearList(spdFromLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdFromLotList_Sheet1.RowCount++;

                    spdFromLotList_Sheet1.SetValue(i, (int)LOT.CHK, false);
                    spdFromLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdFromLotList_Sheet1.Cells[i, (int)LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdFromLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdFromLotList_Sheet1.Cells[i, (int)LOT.OPER].Value = dt.Rows[i]["OPER"];
                    spdFromLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdFromLotList_Sheet1.Cells[i, (int)LOT. MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdFromLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                }
                MPCF.FitColumnHeader(spdFromLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 입력 LOT 정보 조회 후 데이터 추가
        private void InputLot()
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

                dvcArgu[3].sCondition_ID = "LOT_ID";
                dvcArgu[3].sCondition_Value = txtLotID.Text;
                
                if (TPDR.GetDataOne("", ref dt, "CWIP2019-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    
                    return;
                }

                for (int i = 0; i < spdToLotList_Sheet1.RowCount; i++)
                {
                    // TO 그리드에 데이터 제거
                    if (string.Equals(spdToLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text, dt.Rows[0]["LOT_ID"]))
                    {
                        spdToLotList_Sheet1.RemoveRows(i, 1);
                        break;
                    }
                }

                for (int i = 0; i < spdFromLotList_Sheet1.RowCount; i++)
                {
                    // FROM 그리드에 데이터 제거
                    if (string.Equals(spdFromLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text, dt.Rows[0]["LOT_ID"]))
                    {
                        spdFromLotList_Sheet1.RemoveRows(i, 1);
                        break;
                    }
                }
                
                // TO 그리드에 데이터 삽입
                i_Row = spdToLotList_Sheet1.RowCount++;

                spdToLotList_Sheet1.SetValue(i_Row, (int)LOT.CHK, true);
                spdToLotList_Sheet1.Cells[i_Row, (int)LOT.LOT_ID].Value = dt.Rows[0]["LOT_ID"];
                spdToLotList_Sheet1.Cells[i_Row, (int)LOT.QTY].Value = dt.Rows[0]["QTY"];
                spdToLotList_Sheet1.Cells[i_Row, (int)LOT.UNIT].Value = dt.Rows[0]["UNIT"];
                spdToLotList_Sheet1.Cells[i_Row, (int)LOT.OPER].Value = dt.Rows[0]["OPER"];
                spdToLotList_Sheet1.Cells[i_Row, (int)LOT.OPER_DESC].Value = dt.Rows[0]["OPER_DESC"];
                spdToLotList_Sheet1.Cells[i_Row, (int)LOT.MAT_ID].Value = dt.Rows[0]["MAT_ID"];
                spdToLotList_Sheet1.Cells[i_Row, (int)LOT.MAT_DESC].Value = dt.Rows[0]["MAT_DESC"];
                MPCF.FitColumnHeader(spdToLotList);

                this.txtLotID.Text = "";

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // P급 LOT 이동
        private bool MoveLot()
        {
            TRSNode in_node = new TRSNode("move_Lot_In");
            TRSNode out_node = new TRSNode("move_Lot_Out");
            TRSNode lot_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("TO_OPER", cdvToOper.Text);
                in_node.AddString("TRAN_COMMENT", txtComment.Text);

                for (int i = 0; i < spdToLotList_Sheet1.RowCount; i++)
                {
                    if (spdToLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        lot_list = in_node.AddNode("LOT_LIST");
                        lot_list.AddString("LOT_ID", spdToLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text);
                    }
                }
                
                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Regenerate_P_Lot", in_node, ref out_node) == false)
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
                        if(spdToLotList_Sheet1.RowCount == 0)
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
                        if (MPCF.Trim(txtLotID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotID.Text + "]");
                            txtLotID.Focus();
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

                        MPCF.ClearList(spdFromLotList);
                        MPCF.ClearList(spdToLotList);
                        
                        this.cdvToOper.Text = "";
                        this.txtLotID.Text = "";
                        this.txtComment.Text = "";
                        break;
                        
                    case "ALL":

                        MPCF.ClearList(spdFromLotList);
                        MPCF.ClearList(spdToLotList);

                        //this.cdvDept.Text = "";
                        //this.cdvWorkPlace.Text = "";
                        this.cdvFromOper.Text = "";
                        this.cdvToOper.Text = "";
                        this.cdvMatID.Text = "";
                        this.txtLotID.Text = "";
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

        #region Event
        private void frmTranPLotManagement_Load(object sender, EventArgs e)
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

                ViewLotList();
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

                for (int i = spdFromLotList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdFromLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        iRow = spdToLotList_Sheet1.RowCount++;

                        spdToLotList_Sheet1.SetValue(iRow, (int)LOT.CHK, true);
                        spdToLotList_Sheet1.Cells[iRow, (int)LOT.LOT_ID].Value = spdFromLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text;
                        spdToLotList_Sheet1.Cells[iRow, (int)LOT.QTY].Value = spdFromLotList_Sheet1.Cells[i, (int)LOT.QTY].Text;
                        spdToLotList_Sheet1.Cells[iRow, (int)LOT.UNIT].Value = spdFromLotList_Sheet1.Cells[i, (int)LOT.UNIT].Text;
                        spdToLotList_Sheet1.Cells[iRow, (int)LOT.OPER].Value = spdFromLotList_Sheet1.Cells[i, (int)LOT.OPER].Text;
                        spdToLotList_Sheet1.Cells[iRow, (int)LOT.OPER_DESC].Value = spdFromLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Text;
                        spdToLotList_Sheet1.Cells[iRow, (int)LOT.MAT_ID].Value = spdFromLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Text;
                        spdToLotList_Sheet1.Cells[iRow, (int)LOT.MAT_DESC].Value = spdFromLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Text;

                        spdFromLotList_Sheet1.RemoveRows(i, 1);
                    }
                }
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

                for (int i = spdToLotList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdToLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        iRow = spdFromLotList_Sheet1.RowCount++;

                        spdFromLotList_Sheet1.SetValue(iRow, (int)LOT.CHK, false);
                        spdFromLotList_Sheet1.Cells[iRow, (int)LOT.LOT_ID].Value = spdToLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text;
                        spdFromLotList_Sheet1.Cells[iRow, (int)LOT.QTY].Value = spdToLotList_Sheet1.Cells[i, (int)LOT.QTY].Text;
                        spdFromLotList_Sheet1.Cells[iRow, (int)LOT.UNIT].Value = spdToLotList_Sheet1.Cells[i, (int)LOT.UNIT].Text;
                        spdFromLotList_Sheet1.Cells[iRow, (int)LOT.OPER].Value = spdToLotList_Sheet1.Cells[i, (int)LOT.OPER].Text;
                        spdFromLotList_Sheet1.Cells[iRow, (int)LOT.OPER_DESC].Value = spdToLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Text;
                        spdFromLotList_Sheet1.Cells[iRow, (int)LOT.MAT_ID].Value = spdToLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Text;
                        spdFromLotList_Sheet1.Cells[iRow, (int)LOT.MAT_DESC].Value = spdToLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Text;

                        spdToLotList_Sheet1.RemoveRows(i, 1);
                    }
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
                if (CheckCondition("MOVE") == false)
                    return;

                if (MoveLot())
                {
                    ClearList("VIEW");
                    ViewLotList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdFromLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdFromLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdFromLotList, e.Row, e.Column, true, true, false);
                }
            }
        }

        private void spdToLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdToLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdToLotList, e.Row, e.Column, true, true, false);
                }
            }
        }

        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (CheckCondition("INPUT") == false)
                        return;

                    InputLot();
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

            if (COM_LIST.ViewOperationList(cdvFromOper.GetListView, 'J', cdvDept.Text, "", "", "", 'Y') == false)
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

            if (COM_LIST.ViewOperationList(cdvToOper.GetListView, '4', cdvDept.Text, "", "", "", 'Y') == false)
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
        #endregion
    }
}
