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
using FarPoint.Excel.EntityClassLibrary.SpreadsheetML;
using System.Drawing.Drawing2D;

namespace CUS_WIP
{
    public partial class frmWIPViewDaeWonItemList : CUS_COM.frmTranForm02
    {
        public frmWIPViewDaeWonItemList()
        {
            InitializeComponent();
        }

        private enum MAT
        {
            AREA_ID,
            MAT_ID,
            MAT_DESC,
            TOTAL_QTY,
            LOT_TOTAL_QTY
        }

        /// <summary>
        /// 투입자재 현황 조회
        /// </summary>
        /// <returns></returns>
        private bool View_Material_Status()
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            FarPoint.Win.Spread.SheetView oSheet;



            try
            {

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FR_DATE";
                dvcArgu[1].sCondition_Value = string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text.Replace("-", "") + "000000";

                dvcArgu[2].sCondition_ID = "TO_DATE";
                dvcArgu[2].sCondition_Value = dtpToDate.Text.Replace("-", "") + "235959";//dtpToDate.Value.ToString("yyyyMMdd");




                if (TPDR.GetDataOne("", ref dt, "CWIP4003-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }



                spdOutPutList_Sheet1.RowCount = 0;

                spdOutPutList_Sheet2.RowCount = 0;

                spdOutPutList_Sheet3.RowCount = 0;

                //  spdMaterialList_Sheet1.RowCount = dt.Rows.Count;

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    switch (dt.Rows[i]["LIST_TYPE"].ToString())
                    {
                        case "1":
                            oSheet = spdOutPutList_Sheet1;
                            break;

                        case "2":
                            oSheet = spdOutPutList_Sheet2;
                            break;

                        case "3":
                            oSheet = spdOutPutList_Sheet3;
                            break;
                        default:
                            oSheet = spdOutPutList_Sheet1;
                            break;
                    }

                    oSheet.RowCount++;




                    oSheet.Cells[oSheet.RowCount-1, (int)MAT.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    oSheet.Cells[oSheet.RowCount - 1, (int)MAT.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    oSheet.Cells[oSheet.RowCount - 1, (int)MAT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    oSheet.Cells[oSheet.RowCount - 1, (int)MAT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    oSheet.Cells[oSheet.RowCount - 1, (int)MAT.TOTAL_QTY].Value = dt.Rows[i]["TOTAL_QTY"];
                    oSheet.Cells[oSheet.RowCount - 1, (int)MAT.LOT_TOTAL_QTY].Value = dt.Rows[i]["LOT_TOTAL_COUNT"];
                    /*
                    if(dt.Rows[i]["LIST_TYPE"].ToString() != "3")
                    {
                        spdOutPutList_Sheet3.RowCount++;

                        spdOutPutList_Sheet3.Cells[oSheet.RowCount - 1, (int)MAT.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                        spdOutPutList_Sheet3.Cells[oSheet.RowCount - 1, (int)MAT.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                        spdOutPutList_Sheet3.Cells[oSheet.RowCount - 1, (int)MAT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                        spdOutPutList_Sheet3.Cells[oSheet.RowCount - 1, (int)MAT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    }
                    */


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

        private void spdMaterialList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {

        }

        private void btnView_Click(object sender, EventArgs e)
        {
            View_Material_Status();
        }



        private void frmWIPViewMaterialInputStatus_Load(object sender, EventArgs e)
        {
            //   dtpFromDate.Value = DateTime.Now.AddDays(-3);
            //  dtpFromDate.Value = DateTime.Now; 
            //   dtpFromDate.Format = DateTimePickerFormat.Custom;
            //dtpFromDate.CustomFormat = " ";
        }

        private void btnProcess_Click(object sender, EventArgs e)
        {

        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdOutPutList, "MaterialList");

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

    }
}
