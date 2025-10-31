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
using Miracom.DNMCore;
using Miracom.TRSCore;

using CUS_COM;

namespace CUS_WIP
{
    public partial class frmWIPViewMaterialInputStatus : CUS_COM.frmTranForm02
    {




        public frmWIPViewMaterialInputStatus()
        {
            InitializeComponent();
        }
        #region " Constant Definition "
        private enum MAT
        {
            SEL,
            INV_LOT_ID,
            INPUT_QTY,
            INPUT_METHOD,
            DEPT,
            WORKPLACE,
            OPER,
            WORK_ORDER,
            INPUT_TIME,
            PROD_LOT_ID,
            MAT_ID,
            MAT_DESC,
            LOT_TYPE,
            RTN_WAREHOUSE
        }
        #endregion

        #region " Variable Definition "

        public string g_Dept = string.Empty;
        public string g_DeptDisplay = string.Empty;
        public string g_Oper = string.Empty;
        public string g_OperDisplay = string.Empty;
        public string g_LotId = string.Empty;
        public string g_Inv_LotId = string.Empty;
        public string g_OrderId = string.Empty;
        public string g_InputMethod = string.Empty;
        public string g_PopYn = "N";

        #endregion



        #region " Function Definition "
        private bool View_Material_Status()
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[10];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                spdMaterialList_Sheet1.RowCount = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value =   MPGV.gsFactory;

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

                dvcArgu[6].sCondition_ID = "REL_LEVEL";
                dvcArgu[6].sCondition_Value = cdvInputMethod.Text;

                dvcArgu[7].sCondition_ID = "INV_LOT_ID";
                dvcArgu[7].sCondition_Value = txtInvLotId.Text;

                dvcArgu[8].sCondition_ID = "LOT_ID";
                dvcArgu[8].sCondition_Value = txtLotID.Text;

                dvcArgu[9].sCondition_ID = "ORDER_ID";
                dvcArgu[9].sCondition_Value = txtOrderId.Text;



                if (TPDR.GetDataOne("", ref dt, "CWIP3008-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                spdMaterialList_Sheet1.RowCount = dt.Rows.Count;

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.SEL].Value = false;
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.INV_LOT_ID].Value = dt.Rows[i]["INV_LOT_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.INPUT_QTY].Value = dt.Rows[i]["QTY"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.INPUT_METHOD].Value = dt.Rows[i]["REL_LEVEL_DESC"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.INPUT_METHOD].Tag = dt.Rows[i]["REL_LEVEL"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.DEPT].Value = dt.Rows[i]["AREA_DESC"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.WORKPLACE].Value = dt.Rows[i]["SUB_AREA_DESC"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.OPER].Value = dt.Rows[i]["INPUT_OPER_DESC"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.OPER].Tag = dt.Rows[i]["INPUT_OPER"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.WORK_ORDER].Value = dt.Rows[i]["ORDER_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.INPUT_TIME].Value = dt.Rows[i]["TRAN_TIME"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.PROD_LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.RTN_WAREHOUSE].Value = dt.Rows[i]["RTN_WAREHOUSE"];
                }

                MPCF.FitColumnHeader(spdMaterialList);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        /// <summary>
        /// 자재 투입 해제
        /// </summary>
        /// <returns></returns>
        private bool Unload_Material()
        {
            TRSNode in_node = new TRSNode("Unload_Material_In");
            TRSNode out_node = new TRSNode("Unload_Material_Out");

            int i = 0;
            int iCnt = 0;

            try
            {
                for (i = 0; i < spdMaterialList_Sheet1.RowCount; i++)
                {
                    if (Convert.ToBoolean(spdMaterialList_Sheet1.Cells[i, (int)MAT.SEL].Value))
                    {
                        in_node.Init();
                        MPCR.SetInMsg(in_node);
                        in_node.ProcStep = '1';

                        in_node.AddChar("REL_LEVEL", spdMaterialList_Sheet1.Cells[i, (int)MAT.INPUT_METHOD].Tag);
                        in_node.AddString("INV_LOT_ID", spdMaterialList_Sheet1.Cells[i, (int)MAT.INV_LOT_ID].Value);
                        in_node.AddString("OPER", spdMaterialList_Sheet1.Cells[i, (int)MAT.OPER].Tag);
                        in_node.AddString("ORDER_ID", spdMaterialList_Sheet1.Cells[i, (int)MAT.WORK_ORDER].Value);
                        in_node.AddString("RES_ID", "");
                        in_node.AddString("LOT_ID", spdMaterialList_Sheet1.Cells[i, (int)MAT.PROD_LOT_ID].Value);
                        in_node.AddString("LOT_TYPE", spdMaterialList_Sheet1.Cells[i, (int)MAT.LOT_TYPE].Value);

                        if (MPCR.CallService("CUS_WIP", "CUS_WIP_Input_Material_Lot", in_node, ref out_node) == false)
                        {
                            return false;
                        }

                        iCnt++;
                    }
                }

                if(iCnt == 0)
                {
                    // CMN423 ERROR - 선택된 아이템이 없습니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(423));
                    return false;
                }

                if (iCnt > 0)
                {
                    MPCR.ShowSuccessMsg(out_node);
                    View_Material_Status();
                }

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }
        #endregion


        #region " Event Definition "
        private void cdvInputMethod_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvInputMethod.Init();
                MPCF.InitListView(cdvInputMethod.GetListView);
                cdvInputMethod.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvInputMethod.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                if (BASLIST.ViewGCMDataList(cdvInputMethod.GetListView, '1', "C_LOAD_LEVEL") == false)
                {
                    return;
                }
            }
            catch(Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void spdMaterialList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)MAT.SEL)
                    {
                        CSCF.CheckSpreadCell(spdMaterialList, 0, 0, true, true);
                    }
                }
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    //EXTFUC.SetSelectRowColor(spdMaterialList, e.Row);
                    if (spdMaterialList.ActiveSheet.Cells[e.Row, (int)MAT.SEL].Value.ToString().ToUpper() == "TRUE")
                    {
                        spdMaterialList.ActiveSheet.SetValue(e.Row, (int)MAT.SEL, false);
                    }
                    else
                    {
                        spdMaterialList.ActiveSheet.SetValue(e.Row, (int)MAT.SEL, true);
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
            // 20.12.21 minjae.go
            // dtpFromDate.Value = DateTime.Now.AddDays(-7);
            //dtpFromDate.Value = DateTime.Now; 
            //dtpFromDate.Format = DateTimePickerFormat.Custom;
            //dtpFromDate.CustomFormat = " ";
            dtpFromDate.Value = DateTime.Now.AddDays(-7);


            if(g_PopYn == "Y")
            {
                cdvDept.Text = g_Dept;
                cdvDept.DisplayText = g_DeptDisplay;
                txtInvLotId.Text = g_Inv_LotId; 
             //   txtOrderId.Text = g_OrderId;
                dtpFromDate.Value = DateTime.Now;
                dtpFromDate.Format = DateTimePickerFormat.Custom;
                dtpFromDate.CustomFormat = " ";

                View_Material_Status();
            }





    }

    private void btnProcess_Click(object sender, EventArgs e)
        {
            if(spdMaterialList_Sheet1.RowCount == 0)
            {
                // CMN154 ERROR - 데이타가 없습니다. LOT 정보를 확인해주십시오.
                MPCF.ShowMsgBox(MPCF.GetMessage(154));
                return;
            }

            // 자재 투입 해제
            Unload_Material();
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

        private void dtpFromDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromDate.CustomFormat = "yyyy-MM-dd";
        }

        #endregion
    }
}
