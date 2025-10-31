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
    public partial class frmTranMoveShipment : CUS_COM.frmTranForm01
    {
        public frmTranMoveShipment()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT
        {
            CHK,                     // 1 : CHECK
            LOT_ID,                  // 2 : LOT ID
            QTY,                     // 3 : 수량
            UNIT,                    // 4 : 단위
            OPER,                    // 5 : 창고
            OPER_DESC,               // 6 : 창고명
            MAT_ID,                  // 7 : 제품
            MAT_DESC                 // 8 : 제품명
        }

        #endregion

        #region " Variable Definition "
        string s_from_oper_grp = "";
        string s_to_oper_grp = "";
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
                CSCF.ShowMsg(ex.Message);
            }
        }

        //LOT LIST 조회 함수
        private void ViewLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                string viewID = "";
                double dSumQty = 0;

                if (string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_INV) || string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_OPER) || string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_MOLD))
                {
                    viewID = "CINV2017-001";
                }
                else if (string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_PROD) || string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_RET))
                {
                    viewID = "CINV2017-002";
                }

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;
                
                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = cdvMatID.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvFromOper.Text;

                if (TPDR.GetDataOne("", ref dt, viewID, dvcArgu, false, false, ref sSql) == false)
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

                for (i = 0; i < spdFromLotList_Sheet1.RowCount; i++)
                {
                    dSumQty += MPCF.ToDbl(spdFromLotList.ActiveSheet.Cells[i, (int)LOT.QTY].Text);
                }

                spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = dSumQty;

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
                for (int i = 0; i < spdFromLotList_Sheet1.RowCount; i++)
                {
                    if (spdFromLotList_Sheet1.Cells[i, (int)LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdFromLotList_Sheet1.Cells[i, (int)LOT.QTY].Text);
                    }
                }

                spdFromLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.CHK].Value = iCount;
                spdFromLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.QTY].Value = dSumQty;

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
                for (int i = 0; i < spdToLotList_Sheet1.RowCount; i++)
                {
                    if (spdToLotList_Sheet1.Cells[i, (int)LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdToLotList_Sheet1.Cells[i, (int)LOT.QTY].Text);
                    }
                }

                spdToLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.CHK].Value = iCount;
                spdToLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.QTY].Value = dSumQty;

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
                string viewID = "";

                if (string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_INV) || string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_OPER))
                {
                    viewID = "CINV2017-003";
                }
                else if (string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_PROD) || string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_RET))
                {
                    viewID = "CINV2017-004";
                }

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;
                
                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = "";

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvFromOper.Text;

                dvcArgu[3].sCondition_ID = "LOT_ID";
                dvcArgu[3].sCondition_Value = txtLotID.Text;
                
                if (TPDR.GetDataOne("", ref dt, viewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    txtLotID.SelectAll();

                    return;
                }

                for (int i = 0; i < spdToLotList_Sheet1.RowCount; i++)
                {
                    // FROM 그리드에 데이터 제거
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

                txtLotID.SelectAll();

                CheckCount2();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //LOT 이동
        private bool MoveLot()
        {
            TRSNode in_node = new TRSNode("move_Lot_In");
            TRSNode out_node = new TRSNode("move_Lot_Out");
            TRSNode lot_list;
            bool send_flag = false;

            try
            {
                MPCR.SetInMsg(in_node);

                if (string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_INV) || string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_OPER))
                {
                    in_node.ProcStep = '1';
                }
                else if ((string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_PROD) || string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_RET))
                    && string.Equals(s_to_oper_grp, CSGC.CP_OPER_GRP_INV) || string.Equals(s_to_oper_grp, CSGC.CP_OPER_GRP_OPER))
                {
                    in_node.ProcStep = '2';
                }
                else if(string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_RET) && string.Equals(s_to_oper_grp, CSGC.CP_OPER_GRP_PROD))
                {
                    in_node.ProcStep = '3';
                }
                else 
                {
                    in_node.ProcStep = '1';
                }

                in_node.AddString("TO_OPER", cdvToOper.Text);

                for (int i = 0; i < spdToLotList_Sheet1.RowCount; i++)
                {
                    if (spdToLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        lot_list = in_node.AddNode("LOT_LIST");
                        lot_list.AddString("LOT_ID", spdToLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text);
                        send_flag = true;
                    }
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_INV", "CUS_INV_Move_Shipment", in_node, ref out_node) == false)
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

                        //20220421 동일창고 허용
                        /*
                        if (string.Equals(cdvFromOper.Text, cdvToOper.Text))
                        {
                            //CMN368 ERROR - 기존 공정과 이동 공정이 같습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(368) + " [" + lblToOper.Text + "]");
                            cdvToOper.Focus();
                            return false;
                        }
                        */

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
                        spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;
                        spdToLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdToLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;

                        this.cdvToOper.Text = "";
                        this.txtLotID.Text = "";
                        break;
                        
                    case "ALL":

                        MPCF.ClearList(spdFromLotList);
                        MPCF.ClearList(spdToLotList);
                        spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;
                        spdToLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdToLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;

                        this.cdvDept.Text = "";
                        this.cdvFromOper.Text = "";
                        this.cdvToOper.Text = "";
                        this.cdvMatID.Text = "";
                        this.txtLotID.Text = "";
                        s_from_oper_grp = "";
                        s_to_oper_grp = "";
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //Oper 체크 함수
        private void CheckOper(char c_from_to_flag, string sOper)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = sOper;

                if (TPDR.GetDataOne("", ref dt, "CWIP2010-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }
                
                if(c_from_to_flag == 'F')
                {
                    s_from_oper_grp = dt.Rows[0]["OPER_GRP_1"].ToString();
                }
                else
                {
                    s_to_oper_grp = dt.Rows[0]["OPER_GRP_1"].ToString();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "
        private void frmTranMoveShipment_Load(object sender, EventArgs e)
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

                MPCF.FitColumnHeader(spdToLotList);

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

                MPCF.FitColumnHeader(spdFromLotList);

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

                CheckCount();
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

                CheckCount2();
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

            if (COM_LIST.ViewOperationList(cdvFromOper.GetListView, 'O', cdvDept.Text, "", "", "", 'Y') == false)
            {
                return;
            }

            cdvFromOper.InsertEmptyRow(0, 1);

            ClearList("VIEW");
        }

        private void cdvToOper_ButtonPress(object sender, EventArgs e)
        {
            if (MPCF.Trim(cdvFromOper.Text) == "")
            {
                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFromOper.Text + "]");
                cdvFromOper.Focus();
                return;
            }

            cdvToOper.Init();
            MPCF.InitListView(cdvToOper.GetListView);
            cdvToOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
            cdvToOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvToOper.SelectedSubItemIndex = 0;
            cdvToOper.DisplaySubItemIndex = 1;

            if (COM_LIST.ViewOperationList(cdvToOper.GetListView, 'O', cdvDept.Text, "", "", "", 'Y') == false)
            {
                return;
            }

            /*
            //FROM(자재, 생산) -> TO(완제품)
            if (string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_INV) || string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_OPER) || string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_MOLD))
            {
                if (COM_LIST.ViewOperationList(cdvToOper.GetListView, '6', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }
            }
            //FROM(완제품) -> TO(자재, 생산, 자재과 반품)
            else if (string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_PROD))
            {
                if (COM_LIST.ViewOperationList(cdvToOper.GetListView, 'H', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }
            }
            //FROM(반품) -> TO(자재, 생산, 자재과 반품, 완제품)
            else if (string.Equals(s_from_oper_grp, CSGC.CP_OPER_GRP_RET))
            {
                if (COM_LIST.ViewOperationList(cdvToOper.GetListView, 'P', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }
            }
            */

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

        private void spdFromLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
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

        private void spdFromLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
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

        private void spdToLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
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

        private void spdToLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
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

        private void cdvFromOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                CheckOper('F', cdvFromOper.Text);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                CheckOper('T', cdvToOper.Text);
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
