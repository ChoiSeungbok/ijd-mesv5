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

namespace CUS_SHP
{
    public partial class frmTranMoveReturnLot : CUS_COM.frmTranForm01
    {
        public frmTranMoveReturnLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT
        {
            CHK,                 // 1 : CHECK
            ORG_LOT_ID,          // 2 : 공정 LOT ID
            LOT_ID,              // 3 : 반품 LOT ID
            QTY,                 // 4 : 수량
            UNIT,                // 5 : 단위
            MAT_ID,              // 6 : 제품
            MAT_VER,             // 7 : 버전
            MAT_DESC,            // 8 : 제품명
            OPER,                // 9 : 창고
            OPER_DESC            // 10 : 창고명
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
        //반품 창고 LOT LIST 조회 함수
        private void ViewLotList()
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
                dvcArgu[1].sCondition_Value = cdvReturnOper.Text;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatID.Text;

                if (TPDR.GetDataOne("", ref dt, "CSHP2009-001", dvcArgu, false, false, ref sSql) == false)
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

                    spdLotList_Sheet1.SetValue(i, (int)LOT.CHK, false);
                    spdLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                }
                MPCF.FitColumnHeader(spdLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        // LOT ID 입력 후 데이터 추가
        private void InputLotData()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i_Row = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvReturnOper.Text;

                dvcArgu[2].sCondition_ID = "LOT_ID";
                dvcArgu[2].sCondition_Value = txtLotID.Text;

                if (TPDR.GetDataOne("", ref dt, "CSHP2009-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    txtLotID.SelectAll();

                    return;
                }

                for (int i = 0; i < spdLotList_Sheet1.RowCount; i++)
                {
                    // FROM 그리드에 데이터 제거
                    if (string.Equals(spdLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text, dt.Rows[0]["LOT_ID"]))
                    {
                        spdLotList_Sheet1.RemoveRows(i, 1);
                        break;
                    }
                }

                // TO 그리드에 데이터 삽입
                i_Row = spdMoveLotList_Sheet1.RowCount++;

                spdMoveLotList_Sheet1.SetValue(i_Row, (int)LOT.CHK, true);
                spdMoveLotList_Sheet1.Cells[i_Row, (int)LOT.ORG_LOT_ID].Value = dt.Rows[0]["ORG_LOT_ID"];
                spdMoveLotList_Sheet1.Cells[i_Row, (int)LOT.LOT_ID].Value = dt.Rows[0]["LOT_ID"];
                spdMoveLotList_Sheet1.Cells[i_Row, (int)LOT.QTY].Value = dt.Rows[0]["QTY"];
                spdMoveLotList_Sheet1.Cells[i_Row, (int)LOT.UNIT].Value = dt.Rows[0]["UNIT"];
                spdMoveLotList_Sheet1.Cells[i_Row, (int)LOT.MAT_ID].Value = dt.Rows[0]["MAT_ID"];
                spdMoveLotList_Sheet1.Cells[i_Row, (int)LOT.MAT_VER].Value = dt.Rows[0]["MAT_VER"];
                spdMoveLotList_Sheet1.Cells[i_Row, (int)LOT.MAT_DESC].Value = dt.Rows[0]["MAT_DESC"];
                spdMoveLotList_Sheet1.Cells[i_Row, (int)LOT.OPER].Value = dt.Rows[0]["OPER"];
                spdMoveLotList_Sheet1.Cells[i_Row, (int)LOT.OPER_DESC].Value = dt.Rows[0]["OPER_DESC"];
                MPCF.FitColumnHeader(spdMoveLotList);

                txtLotID.SelectAll();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        //반품 LOT LIST 이동
        private bool MoveLotList()
        {
            TRSNode in_node = new TRSNode("move_Lot_In");
            TRSNode out_node = new TRSNode("move_Lot_Out");
            TRSNode lot_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("TO_OPER", cdvToOper.Text);

                //ORG LOT ID로 정렬하여 서버로 전송
                //ORG LOT ID가 같은녀석들은 MERGE하여 이동
                spdMoveLotList_Sheet1.SortRows((int)LOT.ORG_LOT_ID, true, false);

                for (int i = 0; i < spdMoveLotList_Sheet1.RowCount; i++)
                {
                    if (spdMoveLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        lot_list = in_node.AddNode("MOVE_LOT_LIST");
                        lot_list.AddString("ORG_LOT_ID", spdMoveLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text);
                        lot_list.AddString("LOT_ID", spdMoveLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text);
                    }
                }

                if (MPCR.CallService("CUS_SHP", "CUS_SHP_Move_Return_Lot", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);
 
                ViewPrintLabel(in_node);

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
                
                switch (sType)
                {
                    case "VIEW":
                        if (MPCF.Trim(cdvReturnOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblReturnOper.Text + "]");
                            cdvReturnOper.Focus();
                            return false;
                        }

                        break;

                    case "MOVE":
                        if (spdMoveLotList_Sheet1.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (MPCF.Trim(cdvToOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToOper.Text + "]");
                            cdvToOper.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvLabelName.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLableSize.Text + "]");
                            cdvLabelName.Focus();
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

                        if (spdLotList_Sheet1.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (MPCF.Trim(cdvReturnOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblReturnOper.Text + "]");
                            cdvReturnOper.Focus();
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
                        MPCF.ClearList(spdMoveLotList);

                        this.txtLotID.Text = "";
                        this.cdvToWorkPlace.Text = "";
                        this.cdvToOper.Text = "";
                        break;

                    case "ALL":

                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdMoveLotList);

                        this.cdvDept.Text = "";
                        this.cdvReturnOper.Text = "";
                        this.cdvMatID.Text = "";
                        this.txtLotID.Text = "";
                        this.cdvToWorkPlace.Text = "";
                        this.cdvToOper.Text = "";
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        public bool ViewPrintLabel(TRSNode in_node)
        {
            string sFileName = "";
            try
            {
                sFileName = cdvLabelName.Text;
                CSCF.ViewLabelList(sFileName, in_node,'R');

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        #endregion

        #region " Event Definition"
        private void frmTranMoveReturnLot_Load(object sender, EventArgs e)
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
                string sLotID = "";
                bool addFlag = true;
                int iRow = 0;

                for (int i = spdLotList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        addFlag = true;

                        sLotID = spdLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text;

                        for (int k = 0; k < spdMoveLotList_Sheet1.RowCount; k++)
                        {
                            if (string.Equals(spdMoveLotList_Sheet1.Cells[k, (int)LOT.LOT_ID].Text, sLotID))
                            {
                                addFlag = false;
                                continue;
                            }
                        }

                        if (addFlag == true)
                        {
                            iRow = spdMoveLotList_Sheet1.RowCount++;

                            spdMoveLotList_Sheet1.SetValue(iRow, (int)LOT.CHK, true);
                            spdMoveLotList_Sheet1.Cells[iRow, (int)LOT.ORG_LOT_ID].Value = spdLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text;
                            spdMoveLotList_Sheet1.Cells[iRow, (int)LOT.LOT_ID].Value = spdLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text;
                            spdMoveLotList_Sheet1.Cells[iRow, (int)LOT.QTY].Value = spdLotList_Sheet1.Cells[i, (int)LOT.QTY].Text;
                            spdMoveLotList_Sheet1.Cells[iRow, (int)LOT.UNIT].Value = spdLotList_Sheet1.Cells[i, (int)LOT.UNIT].Text;
                            spdMoveLotList_Sheet1.Cells[iRow, (int)LOT.MAT_ID].Value = spdLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Text;
                            spdMoveLotList_Sheet1.Cells[iRow, (int)LOT.MAT_VER].Value = spdLotList_Sheet1.Cells[i, (int)LOT.MAT_VER].Text;
                            spdMoveLotList_Sheet1.Cells[iRow, (int)LOT.MAT_DESC].Value = spdLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Text;
                            spdMoveLotList_Sheet1.Cells[iRow, (int)LOT.OPER].Value = spdLotList_Sheet1.Cells[i, (int)LOT.OPER].Text;
                            spdMoveLotList_Sheet1.Cells[iRow, (int)LOT.OPER_DESC].Value = spdLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Text;
                        }

                        spdLotList_Sheet1.RemoveRows(i, 1);
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
                string sLotID = "";
                bool addFlag = true;
                int iRow = 0;

                for (int i = spdMoveLotList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdMoveLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        addFlag = true;

                        sLotID = spdMoveLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text;

                        for (int k = 0; k < spdLotList_Sheet1.RowCount; k++)
                        {
                            if (string.Equals(spdLotList_Sheet1.Cells[k, (int)LOT.LOT_ID].Text, sLotID))
                            {
                                addFlag = false;
                                continue;
                            }
                        }

                        if (addFlag == true)
                        {
                            iRow = spdLotList_Sheet1.RowCount++;

                            spdLotList_Sheet1.SetValue(iRow, (int)LOT.CHK, false);
                            spdLotList_Sheet1.Cells[iRow, (int)LOT.ORG_LOT_ID].Value = spdMoveLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text;
                            spdLotList_Sheet1.Cells[iRow, (int)LOT.LOT_ID].Value = spdMoveLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text;
                            spdLotList_Sheet1.Cells[iRow, (int)LOT.QTY].Value = spdMoveLotList_Sheet1.Cells[i, (int)LOT.QTY].Text;
                            spdLotList_Sheet1.Cells[iRow, (int)LOT.UNIT].Value = spdMoveLotList_Sheet1.Cells[i, (int)LOT.UNIT].Text;
                            spdLotList_Sheet1.Cells[iRow, (int)LOT.MAT_ID].Value = spdMoveLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Text;
                            spdLotList_Sheet1.Cells[iRow, (int)LOT.MAT_VER].Value = spdMoveLotList_Sheet1.Cells[i, (int)LOT.MAT_VER].Text;
                            spdLotList_Sheet1.Cells[iRow, (int)LOT.MAT_DESC].Value = spdMoveLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Text;
                            spdLotList_Sheet1.Cells[iRow, (int)LOT.OPER].Value = spdMoveLotList_Sheet1.Cells[i, (int)LOT.OPER].Text;
                            spdLotList_Sheet1.Cells[iRow, (int)LOT.OPER_DESC].Value = spdMoveLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Text;
                        }

                        spdMoveLotList_Sheet1.RemoveRows(i, 1);
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

                if (MoveLotList())
                {
                    btnView_Click(null, null);
                }
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
                    if (CheckCondition("INPUT") == false)
                        return;

                    InputLotData();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvReturnOper_ButtonPress(object sender, EventArgs e)
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

                cdvReturnOper.Init();
                MPCF.InitListView(cdvReturnOper.GetListView);
                cdvReturnOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvReturnOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvReturnOper.SelectedSubItemIndex = 0;
                cdvReturnOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvReturnOper.GetListView, 'B', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }

                cdvReturnOper.InsertEmptyRow(0, 1);
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
        private void cdvToWorkPlace_ButtonPress(object sender, EventArgs e)
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

                cdvToWorkPlace.Init();
                MPCF.InitListView(cdvToWorkPlace.GetListView);
                cdvToWorkPlace.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToWorkPlace.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToWorkPlace.SelectedSubItemIndex = 0;
                cdvToWorkPlace.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList_AREA(cdvToWorkPlace.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, cdvDept.Text) == false)
                {
                    return;
                }

                cdvToWorkPlace.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvToOper_ButtonPress(object sender, EventArgs e)
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

                if (MPCF.Trim(cdvToWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToWorkPlace.Text + "]");
                    cdvToWorkPlace.Focus();
                    return;
                }

                cdvToOper.Init();
                MPCF.InitListView(cdvToOper.GetListView);
                cdvToOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToOper.SelectedSubItemIndex = 0;
                cdvToOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvToOper.GetListView, 'D', cdvDept.Text, cdvToWorkPlace.Text, "", "", 'Y') == false)
                {
                    return;
                }

                cdvToOper.InsertEmptyRow(0, 1);
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
                if (e.ColumnHeader == true)
                {
                    if (spdLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdLotList, e.Row, e.Column, true, true, false);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdMoveLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (spdMoveLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdMoveLotList, e.Row, e.Column, true, true, false);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvLabelName_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvLabelName.Init();
                MPCF.InitListView(cdvLabelName.GetListView);
                cdvLabelName.Columns.Add("Size", 50, HorizontalAlignment.Left);
                cdvLabelName.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvLabelName.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvLabelName.SelectedSubItemIndex = 2;
                cdvLabelName.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewLabelGCMList(cdvLabelName.GetListView, cdvDept.Text, CSGC.CP_LABEL_TYPE_OPER) == false)
                {
                    return;
                }

                cdvLabelName.InsertEmptyRow(0, 1);
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
