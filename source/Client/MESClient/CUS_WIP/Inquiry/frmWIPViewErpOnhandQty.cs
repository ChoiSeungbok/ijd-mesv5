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
using CUS_COM;
using Miracom.DNMCore;
using Miracom.MESCore;
using Miracom.TRSCore;

namespace CUS_WIP
{
    public partial class frmWIPViewErpOnhandQty : CUS_COM.frmViewForm01
    {
        public frmWIPViewErpOnhandQty()
        {
            InitializeComponent();
        }

        #region " Variable Definition "
        public string res_id = string.Empty;
        public string res_no = string.Empty;
        public char loss_yn = 'A'; // ALL

        #endregion

        #region " Function Definition "
        private enum OnHand
        {
            AREA_ID,            // 1 : AREA_ID
            MAT_ID,             // 2 : 품목코드
            MAT_DESC,           // 3 : 품명
            PRIMARY_UOM_CODE,   // 4 : UOM
            AMT,                // 5 : 단가
            AV_QTY,             // 6 : 평균출고량
            TOTAL_QTY,          // 7 : TORAL QTY            
            TOTAL_AMOUNG,       // 8 : TOTAL AMOUNT
            INACTIVE,           // 9 : inactive
            STOCK,              // 10: Stock
            SURPLUS,            // 11:Surplus
            EXCESS,             // 12:Excess
            PERIOD_NAME,        // 13:PERIOD_NAME 
            NORM_AMT,           // 14:표준원가

        }

        #endregion

        #region " Event Definition "
        private void frmWIPViewErpOnhandQty_Load(object sender, EventArgs e)
        {
            try
            {

                dtpStDate.Value = DateTime.Now;

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


                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }
 



                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[8];
                DataTable dt = null;
                String view_id = "";
                string sSql = "";
                int i = 0;
                

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORGANIZATION_CODE";
                dvcArgu[1].sCondition_Value = MPCF.Trim(cdvDept.Text);

                dvcArgu[2].sCondition_ID = "SUBINVENTORY_CODE";
                dvcArgu[2].sCondition_Value = MPCF.Trim(cdvWareHouse.Text);

                dvcArgu[3].sCondition_ID = "PERIOD_NAME";
                dvcArgu[3].sCondition_Value = MPCF.Trim(cdvUnitCostMonth.Text);

                dvcArgu[4].sCondition_ID = "ITEM_TYPE";
                dvcArgu[4].sCondition_Value = MPCF.Trim(cdvMatType.Text);

                dvcArgu[5].sCondition_ID = "ITEM_CODE";
                dvcArgu[5].sCondition_Value =  MPCF.Trim(cdvMat.Text);

                dvcArgu[6].sCondition_ID = "ITEM_NAME";
                dvcArgu[6].sCondition_Value = "%" + MPCF.Trim(txtMatDesc.Text) + "%";

                dvcArgu[7].sCondition_ID = "EOH_DATE";
                dvcArgu[7].sCondition_Value = dtpStDate.Text.Replace("-", "");

                /*
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = CSGV.gs_area_ctm;

                dvcArgu[2].sCondition_ID = "WHP";
                dvcArgu[2].sCondition_Value = MPCF.Trim(txtLotID.Text);

                dvcArgu[3].sCondition_ID = "MATID";
                dvcArgu[3].sCondition_Value = MPCF.Trim(cdvMatID.Text);

                dvcArgu[4].sCondition_ID = "FROMDATE";
                dvcArgu[4].sCondition_Value = dtpFromDate.Value.ToString("yyyyMMdd");

                dvcArgu[5].sCondition_ID = "TODATE";
                dvcArgu[5].sCondition_Value = dtpToDate.Value.ToString("yyyyMMdd");

                dvcArgu[6].sCondition_ID = "MATDESC";
                dvcArgu[6].sCondition_Value = MPCF.Trim(txtMat.Text);

                dvcArgu[7].sCondition_ID = "RESID";
                dvcArgu[7].sCondition_Value = cdvResID.Text;

                dvcArgu[8].sCondition_ID = "CAR";
                dvcArgu[8].sCondition_Value = cdvCar.Text;

                dvcArgu[9].sCondition_ID = "LOSSYN";
                dvcArgu[9].sCondition_Value = loss_yn; // char 형태라 에러발생시 string으로 해야할수도있음
                */


                if (chkLastUCM.Checked)
                {
                    if (rdoALL.Checked)
                    {
                        view_id = "CWIP4002-004";
                    }
                    else if (rdoOper.Checked)
                    {
                        view_id = "CWIP4002-005";
                    }
                    else if (rdoWh.Checked)
                    {
                        view_id = "CWIP4002-006";
                    }
                    else
                    {
                        return;
                    }

                }
                else
                {
                    if (rdoALL.Checked)
                    {
                        view_id = "CWIP4002-001";
                    }
                    else if (rdoOper.Checked)
                    {
                        view_id = "CWIP4002-002";
                    }
                    else if (rdoWh.Checked)
                    {
                        view_id = "CWIP4002-003";
                    }
                    else
                    {
                        return;
                    }

                }


                if (TPDR.GetDataOne("", ref dt, view_id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdOnHandList);
                    return;
                }

                MPCF.ClearList(spdOnHandList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdOnHandList_Sheet1.RowCount++;

                    spdOnHandList_Sheet1.Cells[i, (int)OnHand.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdOnHandList_Sheet1.Cells[i, (int)OnHand.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdOnHandList_Sheet1.Cells[i, (int)OnHand.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdOnHandList_Sheet1.Cells[i, (int)OnHand.PRIMARY_UOM_CODE].Value = dt.Rows[i]["PRIMARY_UOM_CODE"];
                    spdOnHandList_Sheet1.Cells[i, (int)OnHand.AMT].Value = dt.Rows[i]["AMT"];
                    spdOnHandList_Sheet1.Cells[i, (int)OnHand.AV_QTY].Value = dt.Rows[i]["AV_QTY"];
                    spdOnHandList_Sheet1.Cells[i, (int)OnHand.TOTAL_QTY].Value = dt.Rows[i]["TOTAL_QTY"];
                    spdOnHandList_Sheet1.Cells[i, (int)OnHand.TOTAL_AMOUNG].Value = dt.Rows[i]["TOTAL_AMOUNG"];
                    spdOnHandList_Sheet1.Cells[i, (int)OnHand.INACTIVE].Value = dt.Rows[i]["INACTIVE"];
                    spdOnHandList_Sheet1.Cells[i, (int)OnHand.STOCK].Value = dt.Rows[i]["STOCK"];
                    spdOnHandList_Sheet1.Cells[i, (int)OnHand.SURPLUS].Value = dt.Rows[i]["SURPLUS"];
                    spdOnHandList_Sheet1.Cells[i, (int)OnHand.EXCESS].Value = dt.Rows[i]["EXCESS"];
                    spdOnHandList_Sheet1.Cells[i, (int)OnHand.PERIOD_NAME].Value = dt.Rows[i]["PERIOD_NAME"];
                    spdOnHandList_Sheet1.Cells[i, (int)OnHand.NORM_AMT].Value = dt.Rows[i]["NORM_AMT"];

                }

                MPCF.FitColumnHeader(spdOnHandList);

                return;
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
                string sFileName = string.Empty;

                sFileName = "Press Yield Status";
                EXTFUC.SaveExcel(spdOnHandList, sFileName);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvMatID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                // 제품 팝업으로 변경
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = CSGV.gs_area_ctm;
                popup.sArea_desc = CSGV.gs_area_ctm;
                popup.sMat_id = cdvMat.Text;
                popup.sMat_Desc = txtMatDesc.Text;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMat.Text = popup.sMat_id;
                    this.txtMatDesc.Text = popup.sMat_Desc;
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

        private void cdvWareHouse_ButtonPress(object sender, EventArgs e)
        {
            cdvWareHouse.Init();
            MPCF.InitListView(cdvWareHouse.GetListView);
            cdvWareHouse.Columns.Add("Operation", 50, HorizontalAlignment.Left);
            cdvWareHouse.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvWareHouse.SelectedSubItemIndex = 0;
            cdvWareHouse.DisplaySubItemIndex = 1;

            if (COM_LIST.ViewOperationList(cdvWareHouse.GetListView, 'R', cdvDept.Text, "", "", "", 'Y') == false)
            {
                return;
            }
        }

        private void cdvUnitCostMonth_ButtonPress(object sender, EventArgs e)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(cdvUnitCostMonth.GetListView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';


            in_node.AddString("SQL", "SELECT DISTINCT TO_CHAR(TO_DATE(TO_CHAR(SYSDATE,'YYYYMMDD')+1,'YYYYMMDD') -LEVEL,'YYYY-MM') AS CODE "
                                   + "      ,TO_CHAR(TO_DATE(TO_CHAR(SYSDATE,'YYYYMMDD')+1,'YYYYMMDD') -LEVEL,'YYYY/MM') AS VALUE FROM DUAL"
                                   + "  CONNECT BY LEVEL <= (TO_DATE(TO_CHAR(SYSDATE,'YYYYMMDD')+1,'YYYYMMDD') - TO_DATE('20150101','YYYYMMDD')) ORDER BY 1 DESC");


            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return;
                }

                MPCR.FillDataView(cdvUnitCostMonth.GetListView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);


            cdvUnitCostMonth.InsertEmptyRow(0, 1);
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
                    cdvMat.Text = popup.sMat_id;
                    cdvMat.DisplayText = popup.sMat_Desc;
                    popup = null;
                }
                else
                    return;
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

        private void chkLastUCM_CheckedChanged(object sender, EventArgs e)
        {
            if (chkLastUCM.Checked == true)
            {
                cdvUnitCostMonth.Text = "";
                cdvUnitCostMonth.Enabled = false;

            }
            else
            {
                cdvUnitCostMonth.Enabled = true;
            }
        }

        private void dtpStDate_ValueChanged(object sender, EventArgs e)
        {
            dtpStDate.CustomFormat = "yyyy-MM-dd";
        }

        private void dtpStDate_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtpStDate.CustomFormat = " ";
                    break;
            }
        }

        #endregion
    }
}
