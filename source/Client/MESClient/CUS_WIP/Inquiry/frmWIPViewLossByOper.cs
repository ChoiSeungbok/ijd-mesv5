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
    public partial class frmWIPViewLossByOper : CUS_COM.frmTranForm02
    {
        public frmWIPViewLossByOper()
        {
            InitializeComponent();
        }


        #region " Function Definition "
        private enum MAT
        {
            LOSS_DATE,
            AREA_ID,
            ORDER_ID,
            CREATE_CODE,
            LOT_ID,
            OPER,
            OPER_DESC,
            MAT_ID,
            MAT_DESC,
            DAY_NIGHT,
            LOSS_CODE,
            LOSS_DESC,
            LOSS_QTY,
            TRAN_QTY
        }

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

                dvcArgu[6].sCondition_ID = "LOT_ID";
                dvcArgu[6].sCondition_Value = txtLotID.Text;

                dvcArgu[7].sCondition_ID = "MAT_ID";
                dvcArgu[7].sCondition_Value = cdvMat.Text;

                dvcArgu[8].sCondition_ID = "MAT_DESC";
                dvcArgu[8].sCondition_Value = txtMatDesc.Text;

                dvcArgu[9].sCondition_ID = "CREATE_CODE";
                dvcArgu[9].sCondition_Value = cdvOrderType.Text;


                if (TPDR.GetDataOne("", ref dt, "CWIP3017-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                spdMaterialList_Sheet1.RowCount = dt.Rows.Count;

                for (i = 0; i < dt.Rows.Count; i++)
                {


                    spdMaterialList_Sheet1.Cells[i, (int)MAT.LOSS_DATE].Value = dt.Rows[i]["LOSS_DATE"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.OPER].Value = dt.Rows[i]["OPER"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.DAY_NIGHT].Value = dt.Rows[i]["DAY_NIGHT"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.LOSS_CODE].Value = dt.Rows[i]["LOSS_CODE"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.LOSS_DESC].Value = dt.Rows[i]["LOSS_DESC"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.LOSS_QTY].Value = dt.Rows[i]["LOSS_QTY"];
                    spdMaterialList_Sheet1.Cells[i, (int)MAT.TRAN_QTY].Value = dt.Rows[i]["TRAN_QTY"];


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
        #endregion


        #region " Event Definition "
        private void spdMaterialList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {

        }

        private void btnView_Click(object sender, EventArgs e)
        {
            View_Material_Status();
        }

        

        private void frmWIPViewMaterialInputStatus_Load(object sender, EventArgs e)
        {
             dtpFromDate.Value = DateTime.Now.AddDays(-3);
          //  dtpFromDate.Value = DateTime.Now; 
            dtpFromDate.Format = DateTimePickerFormat.Custom;
            //dtpFromDate.CustomFormat = " ";
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

        #endregion
    }
}
