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
    public partial class frmTranProductionLotConversion : CUS_COM.frmTranForm01
    {
        public frmTranProductionLotConversion()
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


                if (MPGV.gsFactory == "IJDK1")
                {
                    cdvDept.Text = "CTM";
                    cdvDept.DisplayText = "CTM";
                }
                else
                {
                    cdvDept.Text = "CTV";
                    cdvDept.DisplayText = "CTM";
                }
                
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


                if (MPGV.gsFactory == "IJDK1")
                {
                    cdvDept.Text = "CTM";
                    cdvDept.DisplayText = "CTM";
                }
                else
                {
                    cdvDept.Text = "CTV";
                    cdvDept.DisplayText = "CTM";
                }

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                double dSumQty = 0;
                
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;
                
                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = cdvMatID.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = "CW-L/P-H"; //해당 창고는 임의로 하드코딩

                if (TPDR.GetDataOne("", ref dt, "CINV2019-001", dvcArgu, false, false, ref sSql) == false)
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

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;
                
                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = "";

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = "CW-L/P-H"; //해당 창고는 임의로 하드코딩

                dvcArgu[3].sCondition_ID = "LOT_ID";
                dvcArgu[3].sCondition_Value = txtLotID.Text;
                
                if (TPDR.GetDataOne("", ref dt, "CINV2019-002", dvcArgu, false, false, ref sSql) == false)
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

                CheckCount();
                CheckCount2();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //LOT 이동
        private bool ConversionLot()
        {
            TRSNode in_node = new TRSNode("conversion_Lot_In");
            TRSNode out_node = new TRSNode("conversion_Lot_Out");
            TRSNode label_in_node = new TRSNode("print_label_In");
            TRSNode lot_list;
            TRSNode label_list;
            bool send_flag = false;

            try
            {
                MPCR.SetInMsg(label_in_node);
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                for (int i = 0; i < spdToLotList_Sheet1.RowCount; i++)
                {
                    if (spdToLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        lot_list = in_node.AddNode("LOT_LIST");
                        lot_list.AddString("LOT_ID", spdToLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text);

                        if(MPGV.gsFactory == "IJDK1")
                        {
                            //20220110 LOT채번 수정(VC ->CV)
                            lot_list.AddString("NEW_LOT_ID", "VC" + spdToLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text.Substring(1));

                            label_list = label_in_node.AddNode("LOT_LIST");
                            label_list.AddString("LOT_ID", "VC" + spdToLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text.Substring(1));
                            send_flag = true;

                        }
                        else
                        {
                            //20220110 LOT채번 수정(VC ->CV)
                            lot_list.AddString("NEW_LOT_ID", "CV" + spdToLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text.Substring(1));

                            label_list = label_in_node.AddNode("LOT_LIST");
                            label_list.AddString("LOT_ID", "CV" + spdToLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text.Substring(1));
                            send_flag = true;
                        }
                    }
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_INV", "CUS_INV_Production_Lot_Conversion", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);
                
                // 서비스 성공 후 라벨 출력 (NEW LOT ID로 출력)
                CSCF.ViewLabelList(cdvLabel.Text, label_in_node);

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

                //if (MPCF.Trim(cdvFromOper.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFromOper.Text + "]");
                //    cdvFromOper.Focus();
                //    return false;
                //}

                switch (sType)
                {
                    case "PROCESS":
                        if(spdToLotList_Sheet1.RowCount == 0)
                        {
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
                        
                        this.txtLotID.Text = "";
                        break;
                        
                    case "ALL":

                        MPCF.ClearList(spdFromLotList);
                        MPCF.ClearList(spdToLotList);
                        spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdFromLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;
                        spdToLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdToLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;

                     //   this.cdvDept.Text = "CTV";
                        this.cdvFromOper.Text = "";
                        this.cdvMatID.Text = "";
                        this.txtLotID.Text = "";
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
        private void frmTranProductionLotConversion_Load(object sender, EventArgs e)
        {
            try
            {
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
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                cdvLabel.Init();
                MPCF.InitListView(cdvLabel.GetListView);
                cdvLabel.Columns.Add("Size", 50, HorizontalAlignment.Left);
                cdvLabel.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvLabel.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvLabel.SelectedSubItemIndex = 2;
                cdvLabel.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewLabelGCMList(cdvLabel.GetListView, cdvDept.Text, CSGC.CP_LABEL_TYPE_OPER) == false)
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
                if (CheckCondition("PROCESS") == false)
                    return;

                if (ConversionLot())
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

        private void cdvMatID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatID.DisplayText == "")
                cdvMatID.Text = "";
        }

        #endregion



    }
}
