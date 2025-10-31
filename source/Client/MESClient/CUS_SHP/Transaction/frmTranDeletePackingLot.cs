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
using FarPoint.Win.Spread;

namespace CUS_SHP
{
    public partial class frmTranDeletePackingLot : CUS_COM.frmTranForm01
    {
        public frmTranDeletePackingLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT
        {
            LOT_ID,                // 1 : 공정 LOT ID
            MAT_ID,                // 2 : 제품
            MAT_VER,               // 3 : 버전
            MAT_DESC,              // 4 : 제품명
            QTY,                   // 5 : 수량
            PACKED_QTY,            // 6 : 포장된 수량
            UNIT,                  // 7 : 단위
            OPER,                  // 8 : 창고
            OPER_DESC              // 9 : 창고명
        }

        private enum PACK_LOT
        {
            CHK,                     // 1 : CHECK
            ORG_LOT_ID,              // 2 : 공정 LOT ID
            PACK_LOT_ID,             // 3 : 포장 LOT ID
            SEQ,                     // 4 : 순번
            MAT_ID,                  // 5 : 제품
            MAT_VER,                 // 6 : 버전
            MAT_DESC,                // 7 : 제품명
            QTY,                     // 8 : 수량
            UNIT,                    // 9 : 단위
            CMF_1,                   // 10 : 코팅 퍼센트(GRT 전용)
            PACK_FLAG,               // 11 : 포장 여부
            PACK_ORDER_ID,           // 12 : 포장 지시 번호
            PACK_LINE_NO,            // 13 : 포장 라인 번호
            ERP_PACK_ORDER_ID,       // 14 : ERP 포장 지시 번호
            SHIP_FLAG,               // 15 : 출하 여부
            BOX_ID,                  // 16 : 박스 ID
            FINAL_BOX_ID             // 17 : 최종 박스 ID
        }


        #endregion

        #region " Variable Definition "
        string lotId = "";
        string matId = "";
        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                lblLabel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                cdvLabel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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

        //LOT LIST 조회 함수
        private void ViewLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = cdvMatID.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvPackOper.Text;

                dvcArgu[3].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[3].sCondition_Value = txtPackingOrderNo.Text;

                dvcArgu[4].sCondition_ID = "LOT_ID";
                dvcArgu[4].sCondition_Value = txtLotID.Text;

                dvcArgu[5].sCondition_ID = "FROM_DATE";
                dvcArgu[5].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));

                dvcArgu[6].sCondition_ID = "TO_DATE";
                dvcArgu[6].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";

                if (TPDR.GetDataOne("", ref dt, "CSHP2012-003", dvcArgu, false, false, ref sSql) == false)
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
                    spdLotList_Sheet1.RowCount++;

                    spdLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.PACKED_QTY].Value = dt.Rows[i]["PACKED_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];

                    if (lotId == spdLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Value.ToString().Trim()
                           && matId == spdLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Value.ToString().Trim())
                    {
                        EXTFUC.SetSelectSheet(spdLotList, i);
                    }
                }
                MPCF.FitColumnHeader(spdLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //PACKING LOT LIST 조회 함수
        private void ViewPackingLotList(string lotId)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                double dSumQty = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORG_LOT_ID";
                dvcArgu[1].sCondition_Value = lotId;

                dvcArgu[2].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[2].sCondition_Value = txtPackingOrderNo.Text;

                if (TPDR.GetDataOne("", ref dt, "CSHP2012-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdPackingLotList);
                    return;
                }

                MPCF.ClearList(spdPackingLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdPackingLotList_Sheet1.RowCount++;

                    spdPackingLotList_Sheet1.SetValue(i, (int)PACK_LOT.CHK, false);
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SEQ].Value = dt.Rows[i]["SEQ"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CMF_1].Value = dt.Rows[i]["CMF_1"]; //GRT 전용 COATING PERCENT
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_FLAG].Value = dt.Rows[i]["PACK_FLAG"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LINE_NO].Value = dt.Rows[i]["PACK_LINE_NO"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ERP_PACK_ORDER_ID].Value = dt.Rows[i]["CMF_5"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.SHIP_FLAG].Value = dt.Rows[i]["SHIP_FLAG"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.BOX_ID].Value = dt.Rows[i]["BOX_ID_1"];
                    spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.FINAL_BOX_ID].Value = dt.Rows[i]["BOX_ID_2"];
                }
                MPCF.FitColumnHeader(spdPackingLotList);

                for (i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    dSumQty += MPCF.ToDbl(spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.QTY].Text);
                }

                spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //포장 정보 삭제
        private bool DeletePackInfo()
        {
            TRSNode in_node = new TRSNode("delete_Pack_Info_In");
            TRSNode out_node = new TRSNode("delete_Pack_Info_Out");
            TRSNode label_in_node = new TRSNode("label_In");
            TRSNode lot_list;
            TRSNode label_list;
            List<string> group_list = new List<string>();
            bool send_flag = false;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';

                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        lot_list = in_node.AddNode("PACK_LOT_LIST");
                        lot_list.AddString("ORG_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Text);
                        lot_list.AddString("PACK_LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Text);

                        send_flag = true;

                        // 공정 LOT 라벨 출력 용도
                        if (group_list.Contains(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Text) == false)
                        {
                            group_list.Add(spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Text);

                            label_list = label_in_node.AddNode("LOT_LIST");
                            label_list.AddString("LOT_ID", spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Text);
                        }
                    }
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_SHP", "CUS_SHP_Delete_Pack_Lot", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);

                CSCF.ViewLabelList(cdvLabel.Text, label_in_node, 'E');

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

                if (MPCF.Trim(cdvPackOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblPackOper.Text + "]");
                    cdvPackOper.Focus();
                    return false;
                }

                switch (sType)
                {
                    case "DELETE":
                        if (spdLotList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdPackingLotList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (MPCF.Trim(cdvLabel.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLabel.Text + "]");
                            cdvLabel.Focus();
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

                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdPackingLotList);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;
                        break;

                    case "ALL":

                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdPackingLotList);
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);

                        this.cdvDept.Text = "";
                        this.cdvPackOper.Text = "";
                        this.cdvMatID.Text = "";
                        this.txtLotID.Text = "";
                        this.txtPackingOrderNo.Text = "";
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;
                        this.cdvLabel.Text = "";
                        break;

                    case "LOT_CLICK_CELL":

                        MPCF.ClearList(spdPackingLotList);
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = 0;
                        spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = 0;
                        break;
                }
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
                for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
                {
                    if (spdPackingLotList_Sheet1.Cells[i, (int)PACK_LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdPackingLotList.ActiveSheet.Cells[i, (int)PACK_LOT.QTY].Text);
                    }
                }

                spdPackingLotList_Sheet1.ColumnFooter.Cells[0, (int)PACK_LOT.CHK].Value = iCount;
                spdPackingLotList.ActiveSheet.ColumnFooter.Cells[0, (int)PACK_LOT.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion

        #region " Event Definition"
        private void frmTranDeletePackingLot_Load(object sender, EventArgs e)
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

        private void cdvPackOper_ButtonPress(object sender, EventArgs e)
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

                cdvPackOper.Init();
                MPCF.InitListView(cdvPackOper.GetListView);
                cdvPackOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvPackOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvPackOper.SelectedSubItemIndex = 0;
                cdvPackOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvPackOper.GetListView, '6', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }

                cdvPackOper.InsertEmptyRow(0, 1);
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

        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("DELETE") == false)
                    return;

                if (DeletePackInfo())
                {

                    ViewLotList();

                    // 포장 진행 LOT 조회
                    ViewPackingLotList(lotId);
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
                if (e.Row < 0)
                {
                    return;
                }

                if (e.ColumnHeader == true)
                {
                    return;
                }

                ClearList("LOT_CLICK_CELL");

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    spdLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdLotList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                lotId = spdLotList.ActiveSheet.Cells[e.Row, (int)LOT.LOT_ID].Text;
                matId = spdLotList.ActiveSheet.Cells[e.Row, (int)LOT.MAT_ID].Text;

                // 포장된 LOT ID 
                ViewPackingLotList(lotId);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdPackingLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdPackingLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdPackingLotList, e.Row, e.Column, true, true, false);
                }

                CheckCount();
            }
        }

        private void spdPackingLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
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

        private void spdPackingLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
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

        private void cdvMatID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatID.DisplayText == "")
                cdvMatID.Text = "";
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

        private void txtPackingOrderNo_KeyPress(object sender, KeyPressEventArgs e)
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

        private void dtpFromWorkDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";
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

                if (COM_LIST.ViewLabelGCMList(cdvLabel.GetListView, cdvDept.Text, CSGC.CP_LABEL_TYPE_SHIP) == false)
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

        #endregion


    }
}
