using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Miracom.CliFrx;
using Miracom.MESCore;
using Miracom.TRSCore;
using CUS_COM;
using Miracom.DNMCore;

namespace CUS_WIP
{
    public partial class frmTranErpInterface : CUS_COM.frmTranForm05
    {
        public frmTranErpInterface()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum COMP
        {
            CHK,
            IF_SEQ,
            ORDER_ID,
            LOT_ID, 
            TRAN_TYPE_ID,
            TRAN_TYPE, 
            TRAN_TIME, 
            MAT_ID, 
            ERP_MAT_ID, 
            QTY, 
            MES_OPER, 
            AREA_ID,
            OUT_MSG
        }

        private enum MOVE
        {
            CHK,
            IF_SEQ,
            ORDER_ID,
            LOT_ID,
            TRAN_TYPE_ID,
            TRAN_TYPE,
            TRAN_TIME,
            FROM_OPER_SEQ, 
            FROM_OPER, 
            FROM_STEP_TYPE, 
            FROM_STEP,
            TO_OPER_SEQ,
            TO_OPER,
            TO_STEP_TYPE,
            TO_STEP,
            QTY,
            OVER_FLAG,
            MES_OPER,
            OUT_MSG
        }

        private enum ISSU
        {
            CHK,
            IF_SEQ,
            ORDER_ID,
            LOT_ID,
            TRAN_TYPE_ID,
            TRAN_TYPE,
            TRAN_TIME,
            AREA_ID, 
            OPER_SEQ, 
            OPER, 
            INV_OPER,
            MAT_ID, 
            QTY,
            OUT_MSG
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
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
      
        private void ViewCompTableData()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                int i = 0;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "LOT_ID";
                dvcArgu[2].sCondition_Value = txtLotID.Text;

                dvcArgu[3].sCondition_ID = "ORDER_ID";
                dvcArgu[3].sCondition_Value = txtOrder.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP9005-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    MPCF.ClearList(spdCompList);

                    return;
                }

                MPCF.ClearList(spdCompList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdCompList.ActiveSheet.RowCount++;

                    spdCompList.ActiveSheet.SetValue(i, (int)COMP.CHK, false);
                    spdCompList.ActiveSheet.Cells[i, (int)COMP.IF_SEQ].Value = dt.Rows[i]["IF_SEQ"];
                    spdCompList.ActiveSheet.Cells[i, (int)COMP.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdCompList.ActiveSheet.Cells[i, (int)COMP.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdCompList.ActiveSheet.Cells[i, (int)COMP.TRAN_TYPE_ID].Value = dt.Rows[i]["TRAN_TYPE_ID"];
                    spdCompList.ActiveSheet.Cells[i, (int)COMP.TRAN_TYPE].Value = dt.Rows[i]["TRAN_TYPE"];
                    spdCompList.ActiveSheet.Cells[i, (int)COMP.TRAN_TIME].Value = dt.Rows[i]["TRAN_TIME"];
                    spdCompList.ActiveSheet.Cells[i, (int)COMP.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdCompList.ActiveSheet.Cells[i, (int)COMP.ERP_MAT_ID].Value = dt.Rows[i]["ERP_MAT_ID"];
                    spdCompList.ActiveSheet.Cells[i, (int)COMP.QTY].Value = dt.Rows[i]["QTY"];
                    spdCompList.ActiveSheet.Cells[i, (int)COMP.MES_OPER].Value = dt.Rows[i]["MES_OPER"];
                    spdCompList.ActiveSheet.Cells[i, (int)COMP.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdCompList.ActiveSheet.Cells[i, (int)COMP.OUT_MSG].Value = "";
                }

                //MPCF.FitColumnHeader(spdCompList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewMoveTableData()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                int i = 0;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "LOT_ID";
                dvcArgu[2].sCondition_Value = txtLotID.Text;

                dvcArgu[3].sCondition_ID = "ORDER_ID";
                dvcArgu[3].sCondition_Value = txtOrder.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP9005-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    MPCF.ClearList(spdMove);

                    return;
                }

                MPCF.ClearList(spdMove);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMove.ActiveSheet.RowCount++;

                    spdMove.ActiveSheet.SetValue(i, (int)MOVE.CHK, false);
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.IF_SEQ].Value = dt.Rows[i]["IF_SEQ"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.TRAN_TYPE_ID].Value = dt.Rows[i]["TRAN_TYPE_ID"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.TRAN_TYPE].Value = dt.Rows[i]["TRAN_TYPE"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.TRAN_TIME].Value = dt.Rows[i]["TRAN_TIME"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.FROM_OPER_SEQ].Value = dt.Rows[i]["FROM_OPER_SEQ"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.FROM_OPER].Value = dt.Rows[i]["FROM_OPER"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.FROM_STEP_TYPE].Value = dt.Rows[i]["FROM_STEP_TYPE"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.FROM_STEP].Value = dt.Rows[i]["FROM_STEP"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.TO_OPER_SEQ].Value = dt.Rows[i]["TO_OPER_SEQ"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.TO_OPER].Value = dt.Rows[i]["TO_OPER"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.TO_STEP_TYPE].Value = dt.Rows[i]["TO_STEP_TYPE"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.TO_STEP].Value = dt.Rows[i]["TO_STEP"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.QTY].Value = dt.Rows[i]["QTY"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.OVER_FLAG].Value = dt.Rows[i]["OVER_FLAG"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.MES_OPER].Value = dt.Rows[i]["MES_OPER"];
                    spdMove.ActiveSheet.Cells[i, (int)MOVE.OUT_MSG].Value = "";
                }

                //MPCF.FitColumnHeader(spdMove);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewIssuTableData()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                int i = 0;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "LOT_ID";
                dvcArgu[2].sCondition_Value = txtLotID.Text;

                dvcArgu[3].sCondition_ID = "ORDER_ID";
                dvcArgu[3].sCondition_Value = txtOrder.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP9005-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    MPCF.ClearList(spdIss);

                    return;
                }

                MPCF.ClearList(spdIss);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdIss.ActiveSheet.RowCount++;

                    spdIss.ActiveSheet.SetValue(i, (int)ISSU.CHK, false);
                    spdIss.ActiveSheet.Cells[i, (int)ISSU.IF_SEQ].Value = dt.Rows[i]["IF_SEQ"];
                    spdIss.ActiveSheet.Cells[i, (int)ISSU.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdIss.ActiveSheet.Cells[i, (int)ISSU.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdIss.ActiveSheet.Cells[i, (int)ISSU.TRAN_TYPE_ID].Value = dt.Rows[i]["TRAN_TYPE_ID"];
                    spdIss.ActiveSheet.Cells[i, (int)ISSU.TRAN_TYPE].Value = dt.Rows[i]["TRAN_TYPE"];
                    spdIss.ActiveSheet.Cells[i, (int)ISSU.TRAN_TIME].Value = dt.Rows[i]["TRAN_TIME"];
                    spdIss.ActiveSheet.Cells[i, (int)ISSU.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdIss.ActiveSheet.Cells[i, (int)ISSU.OPER_SEQ].Value = dt.Rows[i]["OPER_SEQ"];
                    spdIss.ActiveSheet.Cells[i, (int)ISSU.OPER].Value = dt.Rows[i]["OPER"];
                    spdIss.ActiveSheet.Cells[i, (int)ISSU.INV_OPER].Value = dt.Rows[i]["INV_OPER"];
                    spdIss.ActiveSheet.Cells[i, (int)ISSU.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdIss.ActiveSheet.Cells[i, (int)ISSU.QTY].Value = dt.Rows[i]["QTY"];
                    spdIss.ActiveSheet.Cells[i, (int)ISSU.OUT_MSG].Value = "";
                }

                //MPCF.FitColumnHeader(spdIss);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool TranInterface(char cStep)
        {
            FarPoint.Win.Spread.FpSpread Sspread = new FarPoint.Win.Spread.FpSpread();

            try
            {
                if (cStep == '1')
                    Sspread = spdCompList;
                else if (cStep == '2')
                    Sspread = spdMove;
                else if (cStep == '3')
                    Sspread = spdIss;

                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");

                for (int i = 0; i < Sspread.ActiveSheet.RowCount; i++)
                {
                    if (Sspread.Sheets[0].Cells[i, 0].Value.ToString().ToUpper() == "TRUE")
                    {
                        in_node.Init();
                        MPCR.SetInMsg(in_node);
                        in_node.ProcStep = cStep;

                        in_node.AddInt("IF_SEQ", MPCF.ToInt(Sspread.Sheets[0].Cells[i, 1].Value));
                        in_node.AddDouble("QTY", MPCF.ToDbl(Sspread.Sheets[0].Cells[i, (int)ISSU.QTY].Value));

                        if (MPCR.CallService("CUS_WIP", "CUS_WIP_Create_Erp_If_Data", in_node, ref out_node, true) == false)
                        {
                            if (cStep == '1')
                                spdCompList.ActiveSheet.Cells[i, (int)COMP.OUT_MSG].Value = MPCF.FindLanguage("NG", 0);
                            else if (cStep == '2')
                                spdMove.ActiveSheet.Cells[i, (int)MOVE.OUT_MSG].Value = MPCF.FindLanguage("NG", 0);
                            else if (cStep == '3')
                                spdIss.ActiveSheet.Cells[i, (int)ISSU.OUT_MSG].Value = MPCF.FindLanguage("NG", 0);
                        }
                        else
                        {
                            if (cStep == '1')
                                spdCompList.ActiveSheet.Cells[i, (int)COMP.OUT_MSG].Value = MPCF.FindLanguage("SUCCESS", 0);
                            else if (cStep == '2')
                                spdMove.ActiveSheet.Cells[i, (int)MOVE.OUT_MSG].Value = MPCF.FindLanguage("SUCCESS", 0);
                            else if (cStep == '3')
                                spdIss.ActiveSheet.Cells[i, (int)ISSU.OUT_MSG].Value = MPCF.FindLanguage("SUCCESS", 0);

                            Sspread.Sheets[0].Cells[i, 0].Value = false;
                        }
                    }

                    CSCF.SetPosition(Sspread, i, 0);
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        #endregion

        #region " Event Definition "

        private void frmTranErpInterface_Load(object sender, EventArgs e)
        {
            try
            {
                tabInfo.SelectedIndex = 0;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spd_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == 0)
                    {
                        if (tabInfo.SelectedIndex == 0)
                            CSCF.CheckSpreadCell(spdCompList, 0, 0, true, true);
                        else if (tabInfo.SelectedIndex == 1)
                            CSCF.CheckSpreadCell(spdMove, 0, 0, true, true);
                        else if (tabInfo.SelectedIndex == 2)
                            CSCF.CheckSpreadCell(spdIss, 0, 0, true, true);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cboPort_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cboPort.Text) != "")
                {
                    tabInfo.SelectedIndex = cboPort.SelectedIndex;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void tabInfo_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cboPort.Text) != "")
                {
                    cboPort.SelectedIndex = tabInfo.SelectedIndex;
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
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtOrder_KeyPress(object sender, KeyPressEventArgs e)
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

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (tabInfo.SelectedIndex == 0)
                    ViewCompTableData();
                else if (tabInfo.SelectedIndex == 1)
                    ViewMoveTableData();
                else if (tabInfo.SelectedIndex == 2)
                    ViewIssuTableData();
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
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }
                //if (MPCF.Trim(cboPort.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblPort.Text + "]");
                //    cboPort.Focus();
                //    return;
                //}

                if (tabInfo.SelectedIndex == 0)
                    TranInterface('1');
                else if (tabInfo.SelectedIndex == 1)
                    TranInterface('2');
                else if (tabInfo.SelectedIndex == 2)
                    TranInterface('3');                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        #endregion


    }
}
