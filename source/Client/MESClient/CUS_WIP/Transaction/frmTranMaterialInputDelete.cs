using System;
using System.Data;
using System.Windows.Forms;

using Miracom.CliFrx;
using Miracom.MESCore;
using Miracom.DNMCore;
using Miracom.TRSCore;

using CUS_COM;
using System.Runtime.InteropServices;
using FarPoint.Win;

namespace CUS_WIP
{
    public partial class frmTranMaterialInputDelete : CUS_COM.frmTranForm02
    {
        public frmTranMaterialInputDelete()
        {
            InitializeComponent();

            InitControl();
        }

        #region "Constant  Definition"
        private enum MAT
        {
            CHK,
            INPUT_TIME,
            ORDER_ID,
            ORDER_QTY,
            LOT_ID,
            MAT_ID,
            MAT_DESC,
            OPER,
            OPER_DESC,
            OUT_OPER,
            OUT_OPER_DESC,
            INV_LOT_ID,
            HIST_SEQ,
            INV_MAT_ID,
            INV_MAT_DESC,
            INPUT_QTY,
            UNIT,
            VENDOR_ID,
            VENDOR_SITE_ID,
            VENDOR_NAMEAS,
            VENDOR_LOT_ID,
            PSD_UP_VALUE,           // 9 : '+'
            SS_VALUE,               //10 : SS
            OS_VALUE,               //11 : OS
            PSD_LO_VALUE,           //12 : '-' 
            TI_VALUE,               //13 : TI
            BI_VALUE,               //14 : BI
            TTI_VALUE,              //15 : TTI
            MA_VALUE,               //16 : MA
            HLT_VALUE,              //17 : HLT
            EILLPT_VALUE,           //18 : EILLPT  
        }

        #endregion

        #region "Fuction Definition"
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnInputReturn.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool View_Material_Status()
        {

            if (MPCF.Trim(cdvDept.Text) == "")
            {
                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                cdvDept.Focus();
                return false;
            }

            if (MPCF.Trim(cdvWorkPlace.Text) == "")
            {
                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                cdvWorkPlace.Focus();
                return false;
            }

            if (MPCF.Trim(cdvOper.Text) == "")
            {
                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                cdvOper.Focus();
                return false;
            }


            string sViewID = "";

            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[13];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {

                spdMaterialList_Sheet1.RowCount = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FR_TM";
                dvcArgu[1].sCondition_Value = string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text.Replace("-", "");

                dvcArgu[2].sCondition_ID = "TO_TM";
                dvcArgu[2].sCondition_Value = dtpToDate.Value.ToString("yyyyMMdd");

                dvcArgu[3].sCondition_ID = "AREA_ID";
                dvcArgu[3].sCondition_Value = cdvDept.Text;

                dvcArgu[4].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[4].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[5].sCondition_ID = "OPER";
                dvcArgu[5].sCondition_Value = cdvOper.Text;

                dvcArgu[6].sCondition_ID = "LOT_ID";
                dvcArgu[6].sCondition_Value = txtLotID.Text;

                dvcArgu[7].sCondition_ID = "MAT_ID";
                dvcArgu[7].sCondition_Value = cdvMat.Text;

                dvcArgu[8].sCondition_ID = "MAT_DESC";
                dvcArgu[8].sCondition_Value = txtMatDesc.Text;

                dvcArgu[9].sCondition_ID = "INV_LOT_ID";
                dvcArgu[9].sCondition_Value = txtInvLotID.Text;

                dvcArgu[10].sCondition_ID = "INV_MAT_ID";
                dvcArgu[10].sCondition_Value = cdvInvMat.Text;

                dvcArgu[11].sCondition_ID = "INV_MAT_DESC";
                dvcArgu[11].sCondition_Value = txtInvMatDesc.Text;

                dvcArgu[12].sCondition_ID = "ORDER_ID";
                dvcArgu[12].sCondition_Value = txtOrderId.Text;


                if (cdvDept.Text == CSGV.gs_area_grit)
                    sViewID = "CWIP3012-002";
                else
                    sViewID = "CWIP3012-001";

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                spdMaterialList_Sheet1.RowCount = dt.Rows.Count;

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.CHK].Value = false;
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.INPUT_TIME].Value = dt.Rows[i]["INPUT_TIME"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.ORDER_QTY].Value = dt.Rows[i]["ORDER_QTY"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.OPER].Value = dt.Rows[i]["OPER"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.OUT_OPER].Value = dt.Rows[i]["OUT_OPER"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.INV_LOT_ID].Value = dt.Rows[i]["INV_LOT_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.INV_MAT_ID].Value = dt.Rows[i]["INV_MAT_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.INV_MAT_DESC].Value = dt.Rows[i]["INV_MAT_DESC"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.INPUT_QTY].Value = dt.Rows[i]["INPUT_QTY"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.HIST_SEQ].Value = dt.Rows[i]["HIST_SEQ"];

                    spdMaterialList_Sheet1.Cells[i, (int)MAT.VENDOR_ID].Value = dt.Rows[i]["VENDOR_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.VENDOR_SITE_ID].Value = dt.Rows[i]["VENDOR_SITE_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.VENDOR_NAMEAS].Value = dt.Rows[i]["VENDOR_NAME"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];

                    if (cdvDept.Text == CSGV.gs_area_grit)
                    {
                        spdMaterialList_Sheet1.Cells[i, (int)MAT.PSD_UP_VALUE].Value = dt.Rows[i]["PSD_UP_VALUE"];
                        spdMaterialList_Sheet1.Cells[i, (int)MAT.SS_VALUE].Value = dt.Rows[i]["SS_VALUE"];
                        spdMaterialList_Sheet1.Cells[i, (int)MAT.OS_VALUE].Value = dt.Rows[i]["OS_VALUE"];
                        spdMaterialList_Sheet1.Cells[i, (int)MAT.PSD_LO_VALUE].Value = dt.Rows[i]["PSD_LO_VALUE"];
                        spdMaterialList_Sheet1.Cells[i, (int)MAT.TI_VALUE].Value = dt.Rows[i]["TI_VALUE"];
                        spdMaterialList_Sheet1.Cells[i, (int)MAT.BI_VALUE].Value = dt.Rows[i]["BI_VALUE"];
                        spdMaterialList_Sheet1.Cells[i, (int)MAT.TTI_VALUE].Value = dt.Rows[i]["TTI_VALUE"];
                        spdMaterialList_Sheet1.Cells[i, (int)MAT.MA_VALUE].Value = dt.Rows[i]["MA_VALUE"];
                        spdMaterialList_Sheet1.Cells[i, (int)MAT.HLT_VALUE].Value = dt.Rows[i]["HLT_VALUE"];
                        spdMaterialList_Sheet1.Cells[i, (int)MAT.EILLPT_VALUE].Value = dt.Rows[i]["EILLPT_VALUE"];
                    }
                }

                //MPCF.FitColumnHeader(spdMaterialList);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private bool InputReturn()
        {
            TRSNode in_node = new TRSNode("input_In");
            TRSNode out_node = new TRSNode("input_Out");
            TRSNode input_list;
            string sFirstSaveYn = "Y";

            try
            {
                MPCR.SetInMsg(in_node);

                //자재투입취소
                in_node.ProcStep = '6';


                for (int i = 0; i < spdMaterialList.ActiveSheet.RowCount; i++)
                {
                    if (spdMaterialList.ActiveSheet.Cells[i, (int)MAT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (sFirstSaveYn == "Y")
                        {
                            in_node.AddString("AREA_ID", cdvDept.Text);
                            in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                            in_node.AddString("OPER", cdvOper.Text);
                            in_node.AddString("ORDER_ID", spdMaterialList.ActiveSheet.Cells[i, (int)MAT.ORDER_ID].Text);

                            sFirstSaveYn = "N";
                        }
                        else
                        {
                            if (in_node.GetString("ORDER_ID").ToString() != spdMaterialList.ActiveSheet.Cells[i, (int)MAT.ORDER_ID].Text)
                            {
                                MPCF.ShowMsgBox("동일한 작업지시끼리만 처리가능합니다.(Only the same W/O is possible.)");
                                return false;
                            }

                        }

                        input_list = in_node.AddNode("LIST_TBL");
                        input_list.AddString("OPER_LOT_ID", spdMaterialList.ActiveSheet.Cells[i, (int)MAT.LOT_ID].Text);
                        input_list.AddString("LOT_ID", spdMaterialList.ActiveSheet.Cells[i, (int)MAT.INV_LOT_ID].Text);
                        input_list.AddString("MAT_ID", spdMaterialList.ActiveSheet.Cells[i, (int)MAT.INV_MAT_ID].Text);
                        input_list.AddDouble("QTY", spdMaterialList.ActiveSheet.Cells[i, (int)MAT.INPUT_QTY].Text);
                        input_list.AddInt("HIST_SEQ", MPCF.ToInt(spdMaterialList.ActiveSheet.Cells[i, (int)MAT.HIST_SEQ].Text));
                        input_list.AddString("OUT_OPER", spdMaterialList.ActiveSheet.Cells[i, (int)MAT.OUT_OPER].Text);




                    }



                }


                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Input_Material_Lot", in_node, ref out_node) == false)
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

        #endregion

        #region "event Definition"
        private void spdMaterialList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)MAT.CHK)
                    {
                        CSCF.CheckSpreadCell(spdMaterialList, 0, 0, true, true);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            View_Material_Status();
        }

        private void frmWIPViewMaterialInputStatus_Load(object sender, EventArgs e)
        {
            try
            {
                dtpFromDate.Value = DateTime.Now.AddDays(-3);
                dtpFromDate.Format = DateTimePickerFormat.Custom;

                if (cdvDept.Text == CSGV.gs_area_grit)
                {
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.PSD_UP_VALUE].Visible = true;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.SS_VALUE].Visible = true;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.OS_VALUE].Visible = true;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.TI_VALUE].Visible = true;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.BI_VALUE].Visible = true;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.TTI_VALUE].Visible = true;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.MA_VALUE].Visible = true;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.HLT_VALUE].Visible = true;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.EILLPT_VALUE].Visible = true;
                }
                else
                {
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.PSD_UP_VALUE].Visible = false;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.SS_VALUE].Visible = false;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.OS_VALUE].Visible = false;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.TI_VALUE].Visible = false;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.BI_VALUE].Visible = false;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.TTI_VALUE].Visible = false;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.MA_VALUE].Visible = false;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.HLT_VALUE].Visible = false;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.EILLPT_VALUE].Visible = false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnProcess_Click(object sender, EventArgs e)
        {

        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdMaterialList, "InputMaterialList");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void dtpFromDate_ValueChanged(object sender, EventArgs e)
        {
            dtpFromDate.CustomFormat = "yyyy-MM-dd";
        }

        private void dtpFromDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtpFromDate.CustomFormat = " ";
                    break;
            }
        }

        //그릿 사업부인 경우 물성치 컬럼이 보이도록 함.
        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (cdvDept.Text == CSGV.gs_area_grit)
                {
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.PSD_UP_VALUE].Visible = true;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.SS_VALUE].Visible = true;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.OS_VALUE].Visible = true;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.TI_VALUE].Visible = true;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.BI_VALUE].Visible = true;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.TTI_VALUE].Visible = true;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.MA_VALUE].Visible = true;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.HLT_VALUE].Visible = true;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.EILLPT_VALUE].Visible = true;
                }
                else
                {
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.PSD_UP_VALUE].Visible = false;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.SS_VALUE].Visible = false;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.OS_VALUE].Visible = false;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.TI_VALUE].Visible = false;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.BI_VALUE].Visible = false;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.TTI_VALUE].Visible = false;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.MA_VALUE].Visible = false;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.HLT_VALUE].Visible = false;
                    spdMaterialList.ActiveSheet.Columns[(int)MAT.EILLPT_VALUE].Visible = false;
                }

                MPCF.ClearList(spdMaterialList);
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

        private void cdvInvMat_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvInvMat.Text = popup.sMat_id;
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

        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                btnView_Click(null, null);
            }
        }

        private void txtInvLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                btnView_Click(null, null);
            }
        }

        private void txtMatDesc_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                btnView_Click(null, null);
            }
        }

        private void txtInvMatDesc_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                btnView_Click(null, null);
            }
        }

        private void btnInputReturn_Click(object sender, EventArgs e)
        {
            if (InputReturn() == true)
            {

                return;
            }

        }

        #endregion
    }
}
