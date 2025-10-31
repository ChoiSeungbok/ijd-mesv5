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
    public partial class frmTranMoveConfirmInvLot : CUS_COM.frmTranForm01
    {
        public frmTranMoveConfirmInvLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum MOVE_LIST
        {
            MOVE_ORDER_ID,          // 1 : 이동지시 번호
            FROM_AREA_ID,           // 2 : FROM 사업부
            FROM_SUB_AREA_ID,       // 3 : FROM 사업장
            FROM_SUB_AREA_DESC,     // 4 : FROM 사업장명
            FROM_OPER,              // 5 : FROM 공정
            FROM_OPER_DESC,         // 6 : FROM 공정명
            TO_AREA_ID,             // 7 : TO 사업부
            TO_AREA_DESC,           // 8 : TO 사업부
            TO_SUB_AREA_ID,         // 9 : TO 사업장
            TO_SUB_AREA_DESC,       // 10 : TO 사업장
            TO_OPER,                // 11 : TO 공정
            TO_OPER_DESC,           // 12 : TO 공정
            MOVE_STATUS             // 13 : 상태
        }

        private enum MOVE_INFO
        {
            INV_LOT_ID,             // 1 : INV_LOT_ID
            MAT_ID,                 // 2 : 자재코드
            MAT_DESC,               // 3 : 자재명
            QTY                     // 4 : 총소요량
        }

        #endregion

        #region " Variable Definition "
        string sMoveID = "";
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

        //이동지시 list 조회 함수
        private void ViewMoveList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvFromOper.Text;

                dvcArgu[3].sCondition_ID = "MOVE_ID";
                dvcArgu[3].sCondition_Value = txtMoveOrder.Text;

                dvcArgu[4].sCondition_ID = "FROM_DATE";
                dvcArgu[4].sCondition_Value = dtpFromWorkDate.Text.Replace("-", "") + "000000";

                dvcArgu[5].sCondition_ID = "TO_DATE";
                dvcArgu[5].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";

                if (TPDR.GetDataOne("", ref dt, "CINV2015-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdMoveList);
                    return;
                }

                MPCF.ClearList(spdMoveList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMoveList_Sheet1.RowCount++;

                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.MOVE_ORDER_ID].Value = dt.Rows[i]["MOVE_ID"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.FROM_AREA_ID].Value = dt.Rows[i]["FROM_AREA_ID"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.FROM_SUB_AREA_ID].Value = dt.Rows[i]["FROM_SUB_AREA_ID"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.FROM_SUB_AREA_DESC].Value = dt.Rows[i]["FROM_SUB_AREA_DESC"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.FROM_OPER].Value = dt.Rows[i]["FROM_OPER"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.FROM_OPER_DESC].Value = dt.Rows[i]["FROM_OPER_DESC"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_AREA_ID].Value = dt.Rows[i]["TO_AREA_ID"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_AREA_DESC].Value = dt.Rows[i]["TO_AREA_DESC"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_SUB_AREA_ID].Value = dt.Rows[i]["TO_SUB_AREA_ID"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_SUB_AREA_DESC].Value = dt.Rows[i]["TO_SUB_AREA_DESC"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_OPER].Value = dt.Rows[i]["TO_OPER"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_OPER_DESC].Value = dt.Rows[i]["TO_OPER_DESC"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.MOVE_STATUS].Value = dt.Rows[i]["MOVE_STATUS"];
                }

                MPCF.FitColumnHeader(spdMoveList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //이동지시 lot 리스트 조회 함수
        private void ViewMoveLotList(string sMoveID)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MOVE_ID";
                dvcArgu[1].sCondition_Value = sMoveID;

                if (TPDR.GetDataOne("", ref dt, "CINV2016-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdMoveLotList);
                    return;
                }

                MPCF.ClearList(spdMoveLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMoveLotList_Sheet1.RowCount++;

                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.INV_LOT_ID].Value = dt.Rows[i]["INV_LOT_ID"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.QTY].Value = dt.Rows[i]["QTY"];
                }

                MPCF.FitColumnHeader(spdMoveLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //이동 처리 함수
        private bool MoveLot()
        {
            TRSNode in_node = new TRSNode("MoveLot_In");
            TRSNode out_node = new TRSNode("MoveLot_Out");
            double d_total_qty = 0;
            TRSNode Inv_Lot_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '3';

                in_node.AddString("MOVE_ID", sMoveID);

                for (int i = 0; i < spdMoveLotList_Sheet1.RowCount; i++)
                {
                    Inv_Lot_list = in_node.AddNode("INV_LOT_LIST");
                    Inv_Lot_list.AddString("INV_LOT_ID", spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.INV_LOT_ID].Text);
                    d_total_qty += MPCF.ToDbl(spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.QTY].Text);
                }

                in_node.AddDouble("QTY", d_total_qty);

                if (MPCR.CallService("CUS_INV", "CUS_INV_Move_Lot_Order", in_node, ref out_node) == false)
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

        //벨이데이션 함수
        private bool CheckCondition(CSGC.CHECK CHECK)
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

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        break;

                    case CSGC.CHECK.SAVE:
                        if (spdMoveList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdMoveLotList_Sheet1.RowCount == 0)
                        {
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
                    case "VIEW":

                        MPCF.ClearList(spdMoveList);
                        MPCF.ClearList(spdMoveLotList);

                        break;

                    case "ALL":

                        MPCF.ClearList(spdMoveList);
                        MPCF.ClearList(spdMoveLotList);
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);

                        this.cdvDept.Text = "";
                        this.cdvFromOper.Text = "";
                        this.txtMoveOrder.Text = "";
                        sMoveID = "";
                        break;

                    case "ORDER_CLICK_CELL":

                        MPCF.ClearList(spdMoveLotList);
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

        private void frmTranMoveConfirmInvLot_Load(object sender, EventArgs e)
        {
            try
            {
                this.dtpToWorkDate.Value = DateTime.Now;
                this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvFromOper_ButtonPress(object sender, EventArgs e)
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
                ClearList("ALL");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtMoveOrder_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    btnView.PerformClick();

                    txtMoveOrder.SelectAll();
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

                ClearList("VIEW");

                ViewMoveList();
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

                if (MoveLot())
                {
                    btnView_Click(null, null);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdMoveList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                    return;

                ClearList("ORDER_CLICK_CELL");

                for (int i = 0; i < spdMoveList.ActiveSheet.RowCount; i++)
                {
                    spdMoveList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdMoveList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                sMoveID = spdMoveList.ActiveSheet.Cells[e.Row, (int)MOVE_LIST.MOVE_ORDER_ID].Text;

                if (MPCF.Trim(sMoveID) != "")
                {
                    ViewMoveLotList(sMoveID);
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
