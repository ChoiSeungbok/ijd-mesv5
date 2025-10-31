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

namespace CUS_WIP
{
    public partial class frmWIPViewStock : CUS_COM.frmViewForm01
    {
        public frmWIPViewStock()
        {
            InitializeComponent();

            InitControl();
        }


        #region " Constant Definition "

        private enum LOT_MAIN
        {
            OPER,
            OPER_DESC,
            MAT_ID,
            MAT_DESC,
            PROD_QTY,
            MAT_UNIT,
            UNIT_QTY,
            CONV_QTY,
            CONV_UNIT,
            CREATE_CODE,
            CREATE_NAME
        }

        private enum LOT_DTL
        {
            CREATE_TIME,
            OPER_IN_TIME,
            OPER,
            OPER_DESC,
            LOT_ID,
            CREATE_NAME,
            MAT_ID,
            MAT_DESC,
            LAST_COMMENT,
            WORK_TYPE_DESC,
            ORDER_ID,
            ORDER_STATUS,
            START_RES_DESC,
            INPUT_STATUS,
            GROUP_ID,
            INV_FLAG,
            INSP_RESULT_DESC,
            PROD_QTY,
            MAT_UNIT,
            UNIT_QTY,
            CONV_QTY,
            CONV_UNIT,
            CREATE_CODE,
            CUSTOMER_NAME,
            DELIVERY_NAME,
            LABEL_NAME
        }

        #endregion

        #region " Variable Definition "


        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 초기화
        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":
                        MPCF.ClearList(spdStockMainList);
                        MPCF.ClearList(spdStockDetailList);
                        break;
                    case "CLICK_CELL":
                        MPCF.ClearList(spdStockDetailList);
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //벨리데이션 체크
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        if (MPCF.Trim(cdvDept.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
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


        private void ViewStockMainList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[9];
                DataTable dt = null;
                string sSql = "";
                string sViewID = "";


                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text.Trim();

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text.Trim();

                dvcArgu[3].sCondition_ID = "MAT_TYPE";
                dvcArgu[3].sCondition_Value = cdvMatType.Text.Trim();

                dvcArgu[4].sCondition_ID = "MAT_ID";
                dvcArgu[4].sCondition_Value = cdvMatId.Text.Trim();

                dvcArgu[5].sCondition_ID = "MAT_DESC";
                dvcArgu[5].sCondition_Value = txtMatDesc.Text.Trim();

                dvcArgu[6].sCondition_ID = "LOT_ID";
                dvcArgu[6].sCondition_Value = txtLotID.Text.Trim();

                dvcArgu[7].sCondition_ID = "EOH_DATE";
                dvcArgu[7].sCondition_Value = dtpWorkDate.Text.Replace("-", "");

                dvcArgu[8].sCondition_ID = "CREATE_CODE";
                dvcArgu[8].sCondition_Value = cdvOrderType.Text.Trim();

                if (rdoNow.Checked)
                {
                    sViewID = "CWIP3019-001-01";
                }
                else if (rdoPrev.Checked)
                {
                    sViewID = "CWIP3019-001-02";
                }
                else
                {
                    sViewID = "CWIP3019-001-03";
                }


                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdStockMainList);
                    return;
                }

                MPCF.ClearList(spdStockMainList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdStockMainList_Sheet1.RowCount++;

                    spdStockMainList_Sheet1.Cells[i, (int)LOT_MAIN.OPER].Value = dt.Rows[i]["OPER"];
                    spdStockMainList_Sheet1.Cells[i, (int)LOT_MAIN.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdStockMainList_Sheet1.Cells[i, (int)LOT_MAIN.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdStockMainList_Sheet1.Cells[i, (int)LOT_MAIN.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdStockMainList_Sheet1.Cells[i, (int)LOT_MAIN.PROD_QTY].Value = dt.Rows[i]["PROD_QTY"];
                    spdStockMainList_Sheet1.Cells[i, (int)LOT_MAIN.MAT_UNIT].Value = dt.Rows[i]["MAT_UNIT"];
                    spdStockMainList_Sheet1.Cells[i, (int)LOT_MAIN.UNIT_QTY].Value = dt.Rows[i]["UNIT_QTY"];
                    spdStockMainList_Sheet1.Cells[i, (int)LOT_MAIN.CONV_UNIT].Value = dt.Rows[i]["CONV_UNIT"];
                    spdStockMainList_Sheet1.Cells[i, (int)LOT_MAIN.CONV_QTY].Value = dt.Rows[i]["CONV_QTY"];
                    spdStockMainList_Sheet1.Cells[i, (int)LOT_MAIN.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    spdStockMainList_Sheet1.Cells[i, (int)LOT_MAIN.CREATE_NAME].Value = dt.Rows[i]["CREATE_NAME"];

                }
                MPCF.FitColumnHeader(spdStockMainList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewStockDetailList(string s_mat_id, string s_oper, string s_order_type, string s_eoh_date)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                string sViewID = "";

                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = s_mat_id;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = s_oper;

                dvcArgu[3].sCondition_ID = "CREATE_CODE";
                dvcArgu[3].sCondition_Value = s_order_type;

                dvcArgu[4].sCondition_ID = "EOH_DATE";
                dvcArgu[4].sCondition_Value = s_eoh_date;

                if (rdoNow.Checked)
                {
                    sViewID = "CWIP3019-002-01";
                }
                else if (rdoPrev.Checked)
                {
                    sViewID = "CWIP3019-002-02";
                }
                else
                {
                    sViewID = "CWIP3019-002-03";
                }





                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdStockDetailList);
                    return;
                }

                MPCF.ClearList(spdStockDetailList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdStockDetailList_Sheet1.RowCount++;

                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.CREATE_TIME].Value = dt.Rows[i]["CREATE_TIME"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.OPER_IN_TIME].Value = dt.Rows[i]["OPER_IN_TIME"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.OPER].Value = dt.Rows[i]["OPER"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.CREATE_NAME].Value = dt.Rows[i]["CREATE_NAME"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.LAST_COMMENT].Value = dt.Rows[i]["LAST_COMMENT"];

                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.WORK_TYPE_DESC].Value = dt.Rows[i]["WORK_TYPE_DESC"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.ORDER_STATUS].Value = dt.Rows[i]["ORDER_STATUS"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.START_RES_DESC].Value = dt.Rows[i]["START_RES_DESC"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.INPUT_STATUS].Value = dt.Rows[i]["INPUT_STATUS"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.GROUP_ID].Value = dt.Rows[i]["GROUP_ID"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.INV_FLAG].Value = dt.Rows[i]["INV_FLAG"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.INSP_RESULT_DESC].Value = dt.Rows[i]["INSP_RESULT_DESC"];

                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.PROD_QTY].Value = dt.Rows[i]["PROD_QTY"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.MAT_UNIT].Value = dt.Rows[i]["MAT_UNIT"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.UNIT_QTY].Value = dt.Rows[i]["UNIT_QTY"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.CONV_QTY].Value = dt.Rows[i]["CONV_QTY"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.CONV_UNIT].Value = dt.Rows[i]["CONV_UNIT"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.CUSTOMER_NAME].Value = dt.Rows[i]["CUSTOMER_NAME"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.DELIVERY_NAME].Value = dt.Rows[i]["DELIVERY_NAME"];
                    spdStockDetailList_Sheet1.Cells[i, (int)LOT_DTL.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                }
                MPCF.FitColumnHeader(spdStockDetailList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion

        #region " Event Definition "

        private void frmWIPViewStock_Load(object sender, EventArgs e)
        {
            try
            {
                //조회 조건 최조 세팅
                //Create Code
                cdvOrderType.Text = "PROD";
                cdvOrderType.DisplayText = "Product Lot";

                //일자
                dtpWorkDate.Text = DateTime.Now.AddDays(-1).ToShortDateString();

                //라디오버튼 (현재 혹은 과거)
                rdoNow.Checked = true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOper_ButtonPress(object sender, EventArgs e)
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

                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, '2', cdvDept.Text) == false)
                {
                    return;
                }

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Init();
                MPCF.InitListView(cdvDept.GetListView);
                cdvDept.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvDept.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDept.SelectedSubItemIndex = 0;
                cdvDept.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDept.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvOper.Text = "";
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

                ClearData("VIEW");

                ViewStockMainList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdOrderList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {


                ClearData("CLICK_CELL");

                if (e.ColumnHeader || e.Row < 0)
                {
                    return;
                }


                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdStockMainList, e.Row);

                }

                string sMatID = spdStockMainList.ActiveSheet.Cells[e.Row, (int)LOT_MAIN.MAT_ID].Text;
                string sOper = spdStockMainList.ActiveSheet.Cells[e.Row, (int)LOT_MAIN.OPER].Text;
                string sOrderType = spdStockMainList.ActiveSheet.Cells[e.Row, (int)LOT_MAIN.CREATE_CODE].Text;

                string sEohDate = dtpWorkDate.Text.Replace("-", "");



                ViewStockDetailList(sMatID, sOper, sOrderType, sEohDate);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOper_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvOper.DisplayText == "")
                cdvOper.Text = "";
        }

        private void spdOrderDetailList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdStockDetailList, e.Row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                FpSpread excelSp = new FpSpread();
                spdStockMainList_Sheet1.SheetName = "Sheet1";
                excelSp.Sheets.Add(spdStockMainList_Sheet1);
                spdStockDetailList_Sheet1.SheetName = "Sheet2";
                excelSp.Sheets.Add(spdStockDetailList_Sheet1);

                EXTFUC.SaveExcel(excelSp, "ViewStock");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatId.DisplayText == "")
                cdvMatId.Text = "";
        }

        private void cdvMatId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMatId.Text = popup.sMat_id;
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

        private void cdvMatType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvMatType.Init();
                MPCF.InitListView(cdvMatType.GetListView);
                cdvMatType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvMatType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvMatType.SelectedSubItemIndex = 0;
                cdvMatType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvMatType.GetListView, '1', MPGC.MP_WIP_MATERIAL_TYPE) == false)
                {
                    return;
                }

                cdvMatType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void rdoNow_CheckedChanged(object sender, EventArgs e)
        {

            MPCF.ClearList(spdStockMainList);
            MPCF.ClearList(spdStockDetailList);
        }

        private void cdvOrderType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOrderType.Init();
                MPCF.InitListView(cdvOrderType.GetListView);
                cdvOrderType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOrderType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOrderType.SelectedSubItemIndex = 0;
                cdvOrderType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvOrderType.GetListView, '1', MPGC.MP_WIP_CREATE_CODE) == false)
                    return;

                cdvOrderType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void rdoPrev_CheckedChanged(object sender, EventArgs e)
        {
            if (rdoPrev.Checked)
            {
                dtpWorkDate.Enabled = true;
            }
            else if (rdoPrev2.Checked)
            {
                dtpWorkDate.Enabled = true;
            }
            else
            {
                dtpWorkDate.Enabled = false;
            }
        }

        private void rdoPrev2_CheckedChanged(object sender, EventArgs e)
        {
            if (rdoPrev.Checked)
            {
                dtpWorkDate.Enabled = true;
            }
            else if (rdoPrev2.Checked)
            {
                dtpWorkDate.Enabled = true;
            }
            else
            {
                dtpWorkDate.Enabled = false;
            }
        }

        #endregion
    }
}
