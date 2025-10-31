using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


using Miracom.MsgHandler;
using Miracom.CliFrx;
using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.DNMCore;
using System.IO;
using System.IO.Ports;


using xExcel = Microsoft.Office.Interop.Excel;
using FarPoint.Win.Spread;

namespace CUS_WIP
{
    public partial class frmWIPViewMesErpInventoryInquiry : CUS_COM.frmViewForm01
    {
        public frmWIPViewMesErpInventoryInquiry()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum INVEN_QTY
        {
            OPER, 
            MAT_ID, 
            MAT_DESC, 
            UNIT,
            INV_QTY, 
            ISS_QTY, 
            GRT_CLASS_QC_QTY,
            GRT_CLASS_OPER_QTY, 
            MES_QTY, 
            ERP_QTY,
            DIFF_QTY
        }




        private enum OPER_QTY
        {
            AREA_ID,
            OPER,
            OPER_DESC,
            MAT_ID,
            MAT_DESC,
            MES_QTY,
            ERP_QTY,
            MIN_QTY
        }


        private enum WO_QTY
        {
            AREA_ID,
            ORDER_ID,
            OPER_SEQ,
            OPER,
            OPER_DESC,
            MES_QTY,
            ERP_QTY,
            MIN_QTY
        }

        private enum LOT_QTY
        {
            OPER,
            LOT_ID,
            MAT_ID,
            MAT_DESC,
            UNIT,
            INV_QTY,
            ISS_QTY,
            GRT_CLASS_QC_QTY,
            GRT_CLASS_OPER_QTY,
            MES_QTY
        }



        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;             
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;

                lblatt1.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public bool ViewOperList(Control control)
        {
            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "AREA_ID";
                dvcArgu[0].sCondition_Value = cdvDept.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP3020-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return false;

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["OPER"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        //if (((ListView)control).Columns.Count > 1)
                        //{
                        //    itmX.SubItems.Add(row["OPER"].ToString());
                        //}
                        ((ListView)control).Items.Add(itmX);
                    }
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void ViewInventoryList()
        {
            string sViewID = "";

            try
            {


                if (chkNowOnly.Checked == true)
                {
                    dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                    dtpDate.Enabled = false;
                }
                else
                {
                    dtpDate.Enabled = true;
                }




                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                if (chkDiffMat.Checked == true)
                {
                    sViewID = "CWIP3020-001";
                }
                else
                {
                    sViewID = "CWIP3020-002";
                }

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;
                
                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text + "%"; ;

                dvcArgu[3].sCondition_ID = "MAT_ID";
                dvcArgu[3].sCondition_Value = cdvMat.Text + "%";

                dvcArgu[4].sCondition_ID = "MAT_DESC";
                dvcArgu[4].sCondition_Value = "%" + txtMatDesc.Text + "%";


                dvcArgu[5].sCondition_ID = "EOH_DATE";
                dvcArgu[5].sCondition_Value = dtpDate.Text.Replace("-", "");


  


                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdStock);
                    return;
                }

                MPCF.ClearList(spdStock);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdStock.ActiveSheet.RowCount++;

                    spdStock.ActiveSheet.Cells[i, (int)INVEN_QTY.OPER].Value = dt.Rows[i]["OPER"];
                    spdStock.ActiveSheet.Cells[i, (int)INVEN_QTY.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdStock.ActiveSheet.Cells[i, (int)INVEN_QTY.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdStock.ActiveSheet.Cells[i, (int)INVEN_QTY.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdStock.ActiveSheet.Cells[i, (int)INVEN_QTY.INV_QTY].Value = dt.Rows[i]["INV_QTY"];
                    spdStock.ActiveSheet.Cells[i, (int)INVEN_QTY.ISS_QTY].Value = dt.Rows[i]["ISS_QTY"];
                    spdStock.ActiveSheet.Cells[i, (int)INVEN_QTY.GRT_CLASS_QC_QTY].Value = dt.Rows[i]["GRT_CLASS_QC_QTY"];
                    spdStock.ActiveSheet.Cells[i, (int)INVEN_QTY.GRT_CLASS_OPER_QTY].Value = dt.Rows[i]["CRT_CLASS_OPER_QTY"];
                    spdStock.ActiveSheet.Cells[i, (int)INVEN_QTY.MES_QTY].Value = dt.Rows[i]["MES_QTY"];
                    spdStock.ActiveSheet.Cells[i, (int)INVEN_QTY.ERP_QTY].Value = dt.Rows[i]["ERP_QTY"];
                    spdStock.ActiveSheet.Cells[i, (int)INVEN_QTY.DIFF_QTY].Value = dt.Rows[i]["DIFF_QTY"];
                }
                //MPCF.FitColumnHeader(spdStock);





                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }




        private void ViewOperationList()
        {
            string sViewID = "";

            try
            {


                if (chkNowOnly.Checked == true)
                {
                    dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                    dtpDate.Enabled = false;
                }
                else
                {
                    dtpDate.Enabled = true;
                }


                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                if (chkDiffMat.Checked == true)
                {
                    sViewID = "CWIP3020-004";
                }
                else
                {
                    sViewID = "CWIP3020-005";
                }

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "EOH_DATE";
                dvcArgu[2].sCondition_Value = dtpDate.Text.Replace("-", "");

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdOper);
                    return;
                }

                MPCF.ClearList(spdOper);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdOper.ActiveSheet.RowCount++;



                    spdOper.ActiveSheet.Cells[i, (int)OPER_QTY.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdOper.ActiveSheet.Cells[i, (int)OPER_QTY.OPER].Value = dt.Rows[i]["OPER"];
                    spdOper.ActiveSheet.Cells[i, (int)OPER_QTY.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdOper.ActiveSheet.Cells[i, (int)OPER_QTY.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdOper.ActiveSheet.Cells[i, (int)OPER_QTY.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdOper.ActiveSheet.Cells[i, (int)OPER_QTY.ERP_QTY].Value = dt.Rows[i]["ERP_QTY"];
                    spdOper.ActiveSheet.Cells[i, (int)OPER_QTY.MES_QTY].Value = dt.Rows[i]["MES_QTY"];
                    spdOper.ActiveSheet.Cells[i, (int)OPER_QTY.MIN_QTY].Value = dt.Rows[i]["MIN_QTY"];

                }
                //MPCF.FitColumnHeader(spdOper);

                return;


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }







        private void ViewWoList()
        {
            string sViewID = "";

            try
            {


                if (chkNowOnly.Checked == true)
                {
                    dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                    dtpDate.Enabled = false;
                }
                else
                {
                    dtpDate.Enabled = true;
                }


                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                if (chkDiffMat.Checked == true)
                {
                    sViewID = "CWIP3020-006";
                }
                else
                {
                    sViewID = "CWIP3020-007";
                }

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "EOH_DATE";
                dvcArgu[2].sCondition_Value = dtpDate.Text.Replace("-", "");

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdWo);
                    return;
                }

                MPCF.ClearList(spdWo);

                for (i = 0; i < dt.Rows.Count; i++)
                {

                    spdWo.ActiveSheet.RowCount++;

                    spdWo.ActiveSheet.Cells[i, (int)WO_QTY.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdWo.ActiveSheet.Cells[i, (int)WO_QTY.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdWo.ActiveSheet.Cells[i, (int)WO_QTY.OPER_SEQ].Value = dt.Rows[i]["OPER_SEQ"];
                    spdWo.ActiveSheet.Cells[i, (int)WO_QTY.OPER].Value = dt.Rows[i]["OPER"];
                    spdWo.ActiveSheet.Cells[i, (int)WO_QTY.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdWo.ActiveSheet.Cells[i, (int)WO_QTY.ERP_QTY].Value = dt.Rows[i]["ERP_QTY"];
                    spdWo.ActiveSheet.Cells[i, (int)WO_QTY.MES_QTY].Value = dt.Rows[i]["MES_QTY"];
                    spdWo.ActiveSheet.Cells[i, (int)WO_QTY.MIN_QTY].Value = dt.Rows[i]["MIN_QTY"];


                }
                //MPCF.FitColumnHeader(spdOper);

                return;


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }





        private void ViewLotList()
        {
            string sViewID = "";

            try
            {


                if (chkNowOnly.Checked == true)
                {
                    dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                    dtpDate.Enabled = false;
                }
                else
                {
                    dtpDate.Enabled = true;
                }




                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                DataTable dt = null;
                string sSql = "";
                int i = 0;


                sViewID = "CWIP3020-008";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text + "%"; ;

                dvcArgu[3].sCondition_ID = "MAT_ID";
                dvcArgu[3].sCondition_Value = cdvMat.Text + "%";

                dvcArgu[4].sCondition_ID = "MAT_DESC";
                dvcArgu[4].sCondition_Value = "%" + txtMatDesc.Text + "%";


                dvcArgu[5].sCondition_ID = "EOH_DATE";
                dvcArgu[5].sCondition_Value = dtpDate.Text.Replace("-", "");



                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLot);
                    return;
                }

                MPCF.ClearList(spdLot);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLot.ActiveSheet.RowCount++;

                    spdLot.ActiveSheet.Cells[i, (int)LOT_QTY.OPER].Value = dt.Rows[i]["OPER"];
                    spdLot.ActiveSheet.Cells[i, (int)LOT_QTY.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLot.ActiveSheet.Cells[i, (int)LOT_QTY.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLot.ActiveSheet.Cells[i, (int)LOT_QTY.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLot.ActiveSheet.Cells[i, (int)LOT_QTY.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdLot.ActiveSheet.Cells[i, (int)LOT_QTY.INV_QTY].Value = dt.Rows[i]["INV_QTY"];
                    spdLot.ActiveSheet.Cells[i, (int)LOT_QTY.ISS_QTY].Value = dt.Rows[i]["ISS_QTY"];
                    spdLot.ActiveSheet.Cells[i, (int)LOT_QTY.GRT_CLASS_QC_QTY].Value = dt.Rows[i]["GRT_CLASS_QC_QTY"];
                    spdLot.ActiveSheet.Cells[i, (int)LOT_QTY.GRT_CLASS_OPER_QTY].Value = dt.Rows[i]["CRT_CLASS_OPER_QTY"];
                    spdLot.ActiveSheet.Cells[i, (int)LOT_QTY.MES_QTY].Value = dt.Rows[i]["MES_QTY"];

                }
 



                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        //ViewVatSupplyList



        private void ViewVatSupplyList()
        {
            string sViewID = "";

            try
            {


                if (chkNowOnly.Checked == true)
                {
                    dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                    dtpDate.Enabled = false;
                }
                else
                {
                    dtpDate.Enabled = true;
                }


                // 1번Sheet

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int iRow = 0;
                int iCol = 0;

                sViewID = "CWIP3020-009";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "EOH_DATE";
                dvcArgu[1].sCondition_Value = dtpDate.Text.Replace("-", "");



                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdVatSupply01);
                    return;
                }


                spdVatSupply01.ActiveSheet.RowCount = 0;
                spdVatSupply01.ActiveSheet.ColumnCount = 0;
                MPCF.ClearList(spdVatSupply01);

                for (iCol = 0; iCol < dt.Columns.Count; iCol++)
                {
                    spdVatSupply01.ActiveSheet.ColumnCount ++;
                    spdVatSupply01.ActiveSheet.ColumnHeader.Cells.Get(0, iCol).Value = dt.Columns[iCol].ColumnName;

                   

                    for (iRow = 0; iRow < dt.Rows.Count; iRow++)
                    {
                        spdVatSupply01.ActiveSheet.RowCount++;

                        spdVatSupply01.ActiveSheet.Cells[iRow, iCol].Value = dt.Rows[iRow][iCol];

                    }

                }
                MPCF.FitColumnHeader(spdVatSupply01);
                spdVatSupply01.ActiveSheet.RowCount = iRow;


                // 2번Sheet


                sViewID = "CWIP3020-010";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "EOH_DATE";
                dvcArgu[1].sCondition_Value = dtpDate.Text.Replace("-", "");



                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdVatSupply02);
                    return;
                }


                spdVatSupply02.ActiveSheet.RowCount = 0;
                spdVatSupply02.ActiveSheet.ColumnCount = 0;
                MPCF.ClearList(spdVatSupply02);

                for (iCol = 0; iCol < dt.Columns.Count; iCol++)
                {
                    spdVatSupply02.ActiveSheet.ColumnCount++;
                    spdVatSupply02.ActiveSheet.ColumnHeader.Cells.Get(0, iCol).Value = dt.Columns[iCol].ColumnName;

                    for (iRow = 0; iRow < dt.Rows.Count; iRow++)
                    {
                        spdVatSupply02.ActiveSheet.RowCount++;

                        spdVatSupply02.ActiveSheet.Cells[iRow, iCol].Value = dt.Rows[iRow][iCol];

                    }

                }
                MPCF.FitColumnHeader(spdVatSupply02);
                spdVatSupply02.ActiveSheet.RowCount = iRow;




                // 3번Sheet


                sViewID = "CWIP3020-011";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "EOH_DATE";
                dvcArgu[1].sCondition_Value = dtpDate.Text.Replace("-", "");



                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdVatSupply03);
                    return;
                }

                spdVatSupply03.ActiveSheet.RowCount = 0;
                spdVatSupply03.ActiveSheet.ColumnCount = 0;
                MPCF.ClearList(spdVatSupply03);
       

                for (iCol = 0; iCol < dt.Columns.Count; iCol++)
                {
                    spdVatSupply03.ActiveSheet.ColumnCount++;
                    spdVatSupply03.ActiveSheet.ColumnHeader.Cells.Get(0, iCol).Value = dt.Columns[iCol].ColumnName;

                    for (iRow = 0; iRow < dt.Rows.Count; iRow++)
                    {
                        spdVatSupply03.ActiveSheet.RowCount++;

                        spdVatSupply03.ActiveSheet.Cells[iRow, iCol].Value = dt.Rows[iRow][iCol];

                    }

                }
                MPCF.FitColumnHeader(spdVatSupply03);
                spdVatSupply03.ActiveSheet.RowCount = iRow;


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }








        private void ViewVatNgList()
        {
            string sViewID = "";

            try
            {


                if (chkNowOnly.Checked == true)
                {
                    dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                    dtpDate.Enabled = false;
                }
                else
                {
                    dtpDate.Enabled = true;
                }


                // 1번Sheet

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int iRow = 0;
                int iCol = 0;

                sViewID = "CWIP3020-012";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "EOH_DATE";
                dvcArgu[1].sCondition_Value = cdvMonth.Text.Replace("-", "").Substring(0, 6);



                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdMesErpScrap);
                    return;
                }


                spdMesErpScrap.ActiveSheet.RowCount = 0;
                spdMesErpScrap.ActiveSheet.ColumnCount = 0;
                MPCF.ClearList(spdMesErpScrap);

                for (iCol = 0; iCol < dt.Columns.Count; iCol++)
                {
                    spdMesErpScrap.ActiveSheet.ColumnCount++;
                    spdMesErpScrap.ActiveSheet.ColumnHeader.Cells.Get(0, iCol).Value = dt.Columns[iCol].ColumnName;



                    for (iRow = 0; iRow < dt.Rows.Count; iRow++)
                    {
                        spdMesErpScrap.ActiveSheet.RowCount++;

                        spdMesErpScrap.ActiveSheet.Cells[iRow, iCol].Value = dt.Rows[iRow][iCol];

                    }

                }
                MPCF.FitColumnHeader(spdMesErpScrap);
                spdMesErpScrap.ActiveSheet.RowCount = iRow;


                // 2번Sheet


                sViewID = "CWIP3020-013";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "EOH_DATE";
                dvcArgu[1].sCondition_Value = cdvMonth.Text.Replace("-", "").Substring(0, 6);



                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdMesScrap);
                    return;
                }


                spdMesScrap.ActiveSheet.RowCount = 0;
                spdMesScrap.ActiveSheet.ColumnCount = 0;
                MPCF.ClearList(spdMesScrap);

                for (iCol = 0; iCol < dt.Columns.Count; iCol++)
                {
                    spdMesScrap.ActiveSheet.ColumnCount++;
                    spdMesScrap.ActiveSheet.ColumnHeader.Cells.Get(0, iCol).Value = dt.Columns[iCol].ColumnName;

                    for (iRow = 0; iRow < dt.Rows.Count; iRow++)
                    {
                        spdMesScrap.ActiveSheet.RowCount++;

                        spdMesScrap.ActiveSheet.Cells[iRow, iCol].Value = dt.Rows[iRow][iCol];

                    }

                }
                MPCF.FitColumnHeader(spdMesScrap);
                spdMesScrap.ActiveSheet.RowCount = iRow;




                // 3번Sheet


                sViewID = "CWIP3020-014";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "EOH_DATE";
                dvcArgu[1].sCondition_Value = cdvMonth.Text.Replace("-", "").Substring(0, 6);



                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdErpScrap);
                    return;
                }

                spdErpScrap.ActiveSheet.RowCount = 0;
                spdErpScrap.ActiveSheet.ColumnCount = 0;
                MPCF.ClearList(spdErpScrap);


                for (iCol = 0; iCol < dt.Columns.Count; iCol++)
                {
                    spdErpScrap.ActiveSheet.ColumnCount++;
                    spdErpScrap.ActiveSheet.ColumnHeader.Cells.Get(0, iCol).Value = dt.Columns[iCol].ColumnName;

                    for (iRow = 0; iRow < dt.Rows.Count; iRow++)
                    {
                        spdErpScrap.ActiveSheet.RowCount++;

                        spdErpScrap.ActiveSheet.Cells[iRow, iCol].Value = dt.Rows[iRow][iCol];

                    }

                }
                MPCF.FitColumnHeader(spdErpScrap);
                spdErpScrap.ActiveSheet.RowCount = iRow;


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }





        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {

                    if (TbSelectType.SelectedIndex != 4 && TbSelectType.SelectedIndex != 5)
                    {
                        //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                        cdvDept.Focus();
                        return false;
                    }
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

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

        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "ALL":

                        cdvOper.Text = "";
                        cdvMat.Text = "";
                        txtMatDesc.Text = "";
                        chkDiffMat.Checked = false;

                        MPCF.ClearList(spdStock);

                        MPCF.ClearList(spdOper);

                        MPCF.ClearList(spdWo);

                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }







        //20220519 Excel Report기능 추가.
        public  void VtSupplyExcelReport(string reportName)
        {


            string sCurrentPath = "";
            string sfilePath = "";
            string sfileName = "";
            string sFolderName = "\\Report\\";


            xExcel.Application XApp = null;
            xExcel.Workbooks XBooks = null;
            xExcel.Workbook XBook = null;
            xExcel.Worksheet XSheet = null;
            xExcel.Sheets XSheets = null;


            string path = Path.Combine(Application.StartupPath, "Temp");



            try
            {
                if (reportName == "")
                    return;

                sCurrentPath = $"{System.Windows.Forms.Application.StartupPath}{sFolderName}";

                //로컬에 폴더가 있는지 체크한다. 없으면 폴더 생성
                if (Directory.Exists(sCurrentPath) == false)
                {
                    Directory.CreateDirectory(sCurrentPath);
                }

                //최종 파일 경로
                sfilePath = $"{sCurrentPath}{reportName}.Xlsx";



                if (EXTFUC.CheckFileVersion(sfilePath, reportName) == false)
                {
                    return;
                }



                XApp = new xExcel.Application();

               // XApp.Visible = true;

                XBooks = XApp.Workbooks;
                XBook = XApp.Workbooks.Open(sfilePath);


                XSheets = XBook.Worksheets;
                XSheet = XSheets.get_Item(2) as xExcel.Worksheet;
                XSheets.get_Item(2).select();

                if (spdVatSupply01.ActiveSheet.ColumnCount != 0) { 

                    spdVatSupply01.ActiveSheet.AddSelection(0, 0, spdVatSupply01.ActiveSheet.RowCount, spdVatSupply01.ActiveSheet.ColumnCount); ;
                    spdVatSupply01.ActiveSheet.ClipboardCopy();

                    XSheet.Range["B3", "N30000"].ClearContents();

                    Excel.Range CR = (Excel.Range)XSheet.Cells[3, 1];

                    CR.Select();
                    XSheet.Paste();
                    //XSheet.PasteSpecial(CR, Type.Missing , Type.Missing, Type.Missing, Type.Missing, Type.Missing,true);
                    XSheet.Cells[1, 2] = "MES_" + DateTime.Now.ToString("yyyy-MM-dd");

                    //XSheet.Paste();
                }
                else
                {
                    XSheet.Range["B3", "Z30000"].ClearContents();
                    XSheet.Delete();
                }


                XSheet = XSheets.get_Item(3) as xExcel.Worksheet;
                XSheets.get_Item(3).select();

                if (spdVatSupply02.ActiveSheet.ColumnCount != 0)
                {

                    spdVatSupply02.ActiveSheet.AddSelection(0, 0, spdVatSupply02.ActiveSheet.RowCount, spdVatSupply02.ActiveSheet.ColumnCount); ;
                    spdVatSupply02.ActiveSheet.ClipboardCopy();

                    XSheet.Range["B3", "Z30000"].ClearContents();

                    Excel.Range CR2 = (Excel.Range)XSheet.Cells[3, 1];

                    CR2.Select();
                    XSheet.Paste();
                    //XSheet.PasteSpecial(CR2, Type.Missing, Type.Missing, Type.Missing, Type.Missing, Type.Missing, true);
                    XSheet.Cells[1, 2] = "ERP_WIP_WIP_" + DateTime.Now.ToString("yyyy-MM-dd");

                    //XSheet.Paste();
                }
                else
                {
                    XSheet.Range["B3", "Z30000"].ClearContents();
                    XSheet.Delete();
                }




                XSheet = XSheets.get_Item(4) as xExcel.Worksheet;
                XSheets.get_Item(4).select();

                if (spdVatSupply03.ActiveSheet.ColumnCount != 0)
                {

                    spdVatSupply03.ActiveSheet.AddSelection(0, 0, spdVatSupply03.ActiveSheet.RowCount, spdVatSupply03.ActiveSheet.ColumnCount); ;
                    spdVatSupply03.ActiveSheet.ClipboardCopy();

                    XSheet.Range["B3", "Z30000"].ClearContents();

                    Excel.Range CR3 = (Excel.Range)XSheet.Cells[3, 1];

                    CR3.Select();
                    XSheet.Paste();
                   // XSheet.PasteSpecial(CR3, Type.Missing, Type.Missing, Type.Missing, Type.Missing, Type.Missing, true);
                    XSheet.Cells[1, 2] = "ERP_WIP_INV_" + DateTime.Now.ToString("yyyy-MM-dd");

                    //XSheet.Paste();
                }
                else
                {
                    XSheet.Range["B3", "Z30000"].ClearContents();
                    XSheet.Delete();
                }

                //1번 시트 피벗테이블들 리프레쉬
                XSheet = XSheets.get_Item(1) as xExcel.Worksheet;
                XSheets.get_Item(1).select();

                Excel.PivotTables pivotTables =  (Excel.PivotTables)XSheet.PivotTables();

                if (pivotTables.Count > 0)
                {
                    foreach (Microsoft.Office.Interop.Excel.PivotTable table
                         in pivotTables)
                    {
                        table.RefreshTable();
                    }
                }
                XSheet.Cells[1, 2] = "TOTAL_SUMMARY_" + DateTime.Now.ToString("yyyy-MM-dd");
     

                sfileName = $"{Path.Combine(path, DateTime.Now.ToString("yyyyMMddHHmmss"))}.xlsx";

                XBook.SaveAs(sfileName);
                XApp.Visible = true;


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            finally
            {
                EXTFUC.ReleasExcelObject(XSheet);
                EXTFUC.ReleasExcelObject(XBook);
                EXTFUC.ReleasExcelObject(XApp);
            }

        }








        //202201104 NG Excel Report기능 추가.
        public void VtNGExcelReport(string reportName)
        {


            string sCurrentPath = "";
            string sfilePath = "";
            string sfileName = "";
            string sFolderName = "\\Report\\";


            xExcel.Application XApp = null;
            xExcel.Workbooks XBooks = null;
            xExcel.Workbook XBook = null;
            xExcel.Worksheet XSheet = null;
            xExcel.Sheets XSheets = null;


            string path = Path.Combine(Application.StartupPath, "Temp");



            try
            {
                if (reportName == "")
                    return;

                sCurrentPath = $"{System.Windows.Forms.Application.StartupPath}{sFolderName}";

                //로컬에 폴더가 있는지 체크한다. 없으면 폴더 생성
                if (Directory.Exists(sCurrentPath) == false)
                {
                    Directory.CreateDirectory(sCurrentPath);
                }

                //최종 파일 경로
                sfilePath = $"{sCurrentPath}{reportName}.Xlsx";



                if (EXTFUC.CheckFileVersion(sfilePath, reportName) == false)
                {
                    return;
                }



                XApp = new xExcel.Application();

                // XApp.Visible = true;

                XBooks = XApp.Workbooks;
                XBook = XApp.Workbooks.Open(sfilePath);


                XSheets = XBook.Worksheets;
                XSheet = XSheets.get_Item(2) as xExcel.Worksheet;
                XSheets.get_Item(2).select();

                if (spdMesErpScrap.ActiveSheet.ColumnCount != 0)
                {

                    spdMesErpScrap.ActiveSheet.AddSelection(0, 0, spdMesErpScrap.ActiveSheet.RowCount, spdMesErpScrap.ActiveSheet.ColumnCount); ;
                    spdMesErpScrap.ActiveSheet.ClipboardCopy();

                    XSheet.Range["B3", "G30000"].ClearContents();

                    Excel.Range CR = (Excel.Range)XSheet.Cells[3, 1];

                    CR.Select();
                    XSheet.Paste();
                    //XSheet.PasteSpecial(CR, Type.Missing , Type.Missing, Type.Missing, Type.Missing, Type.Missing,true);
                    //XSheet.Cells[1, 2] = "MES & ERP Difference_" + DateTime.Now.ToString("yyyy/MM");
                    XSheet.Cells[1, 2] = "";
                    XSheet.Cells[1, 1] = "";
                    XSheet.Cells[1, 2] = "MES & ERP Difference_" + cdvMonth.Text;
                    //XSheet.Paste();
                }
                else
                {
                    XSheet.Range["B3", "Z30000"].ClearContents();
                    XSheet.Delete();
                }


                XSheet = XSheets.get_Item(3) as xExcel.Worksheet;
                XSheets.get_Item(3).select();

                if (spdMesScrap.ActiveSheet.ColumnCount != 0)
                {

                    spdMesScrap.ActiveSheet.AddSelection(0, 0, spdMesScrap.ActiveSheet.RowCount, spdMesScrap.ActiveSheet.ColumnCount); ;
                    spdMesScrap.ActiveSheet.ClipboardCopy();

                    XSheet.Range["B3", "I30000"].ClearContents();

                    Excel.Range CR2 = (Excel.Range)XSheet.Cells[3, 1];

                    CR2.Select();
                    XSheet.Paste();
                    //XSheet.PasteSpecial(CR2, Type.Missing, Type.Missing, Type.Missing, Type.Missing, Type.Missing, true);
                    // XSheet.Cells[1, 2] = "MES_" + DateTime.Now.ToString("yyyy/MM");
                    XSheet.Cells[1, 2] = "";
                    XSheet.Cells[1, 1] = "";
                    XSheet.Cells[1, 2] = "MES_" + cdvMonth.Text;
                    //XSheet.Paste();
                }
                else
                {
                    XSheet.Range["B3", "Z30000"].ClearContents();
                    XSheet.Delete();
                }




                XSheet = XSheets.get_Item(4) as xExcel.Worksheet;
                XSheets.get_Item(4).select();

                if (spdErpScrap.ActiveSheet.ColumnCount != 0)
                {

                    spdErpScrap.ActiveSheet.AddSelection(0, 0, spdErpScrap.ActiveSheet.RowCount, spdErpScrap.ActiveSheet.ColumnCount); ;
                    spdErpScrap.ActiveSheet.ClipboardCopy();

                    XSheet.Range["B3", "I30000"].ClearContents();

                    Excel.Range CR3 = (Excel.Range)XSheet.Cells[3, 1];

                    CR3.Select();
                    XSheet.Paste();
                    // XSheet.PasteSpecial(CR3, Type.Missing, Type.Missing, Type.Missing, Type.Missing, Type.Missing, true);
                    // XSheet.Cells[1, 2] = "ERP_" + DateTime.Now.ToString("yyyy/MM");

                    XSheet.Cells[1, 2] = "";
                    XSheet.Cells[1, 1] = "";

                    XSheet.Cells[1, 2] = "ERP_" + cdvMonth.Text;
                    //XSheet.Paste();
                }
                else
                {
                    XSheet.Range["B3", "Z30000"].ClearContents();
                    XSheet.Delete();
                }

                //1번 시트 피벗테이블들 리프레쉬
                XSheet = XSheets.get_Item(1) as xExcel.Worksheet;
                XSheets.get_Item(1).select();

                Excel.PivotTables pivotTables = (Excel.PivotTables)XSheet.PivotTables();

                if (pivotTables.Count > 0)
                {
                    foreach (Microsoft.Office.Interop.Excel.PivotTable table
                         in pivotTables)
                    {
                        table.RefreshTable();
                    }
                }
                //XSheet.Cells[1, 2] = "TOTAL_SUMMARY_" + DateTime.Now.ToString("yyyy/MM");
                XSheet.Cells[1, 2] = "";
                XSheet.Cells[1, 1] = "";

                XSheet.Cells[1, 2] = "TOTAL_SUMMARY_" + cdvMonth.Text;

                sfileName = $"{Path.Combine(path, DateTime.Now.ToString("yyyyMMddHHmmss"))}.xlsx";

                XBook.SaveAs(sfileName);
                XApp.Visible = true;


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            finally
            {
                EXTFUC.ReleasExcelObject(XSheet);
                EXTFUC.ReleasExcelObject(XBook);
                EXTFUC.ReleasExcelObject(XApp);
            }

        }




        #endregion

        #region " Event Definition "

        private void frmWIPViewMesErpInventoryInquiry_Load(object sender, EventArgs e)
        {
            try
            {
                if (cdvDept.Text == CSGV.gs_area_grit)
                {
                    spdStock.ActiveSheet.Columns[(int)INVEN_QTY.GRT_CLASS_QC_QTY].Visible = true;
                    spdStock.ActiveSheet.Columns[(int)INVEN_QTY.GRT_CLASS_OPER_QTY].Visible = true;
                }
                else
                {
                    spdStock.ActiveSheet.Columns[(int)INVEN_QTY.GRT_CLASS_QC_QTY].Visible = false;
                    spdStock.ActiveSheet.Columns[(int)INVEN_QTY.GRT_CLASS_OPER_QTY].Visible = false;
                }
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
                    return;

                ////특정 사업부인 경우 Tag에 저장된 사업부를 제외하고 보이지 않기 위해
                //if (MPCF.Trim(cdvDept.Tag) != "")
                //{
                //    for (int i = cdvDept.GetListView.Items.Count; i > 0; i--)
                //    {
                //        if (cdvDept.GetListView.Items[i - 1].SubItems[0].Text != cdvDept.Tag.ToString())
                //        {
                //            cdvDept.GetListView.Items[i - 1].Remove();
                //        }
                //    }
                //}
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
                if (cdvDept.Text == CSGV.gs_area_grit)
                {
                    spdStock.ActiveSheet.Columns[(int)INVEN_QTY.GRT_CLASS_QC_QTY].Visible = true;
                    spdStock.ActiveSheet.Columns[(int)INVEN_QTY.GRT_CLASS_OPER_QTY].Visible = true;
                }
                else
                {
                    spdStock.ActiveSheet.Columns[(int)INVEN_QTY.GRT_CLASS_QC_QTY].Visible = false;
                    spdStock.ActiveSheet.Columns[(int)INVEN_QTY.GRT_CLASS_OPER_QTY].Visible = false;
                }
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
                cdvOper.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;

                if (ViewOperList(cdvOper.GetListView) == false)
                    return;

                cdvOper.AddEmptyRow(1);                
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
                    txtMatDesc.Text = popup.sMat_Desc;
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

        private void chkNowOnly_CheckedChanged(object sender, EventArgs e)
        {
            if (chkNowOnly.Checked == true)
            {
                dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                dtpDate.Enabled = false;

            }
            else
            {
                dtpDate.Enabled = true;

            }
        }
        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                ClearData("ALL");
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



                switch (TbSelectType.SelectedIndex)
                {
                    case 0:
                        sFileName = string.IsNullOrEmpty(cdvDept.DisplayText) ? "Department" : cdvDept.DisplayText;

                        EXTFUC.SaveExcel(spdStock, sFileName);
                        break;
                    case 1:
                        sFileName = string.IsNullOrEmpty(cdvDept.DisplayText) ? "Department" : cdvDept.DisplayText;

                        EXTFUC.SaveExcel(spdOper, sFileName);
                        break;
                    case 2:
                        sFileName = string.IsNullOrEmpty(cdvDept.DisplayText) ? "Department" : cdvDept.DisplayText;

                        EXTFUC.SaveExcel(spdWo, sFileName);
                        break;
                    case 3:
                        sFileName = string.IsNullOrEmpty(cdvDept.DisplayText) ? "Department" : cdvDept.DisplayText;

                        EXTFUC.SaveExcel(spdLot, sFileName);
                        break;
                    case 4:
                        sFileName = "ERP_MES_WiP_INV.REPORT_01";

                        VtSupplyExcelReport( sFileName);

                        break;
                    case 5:
                        sFileName = "ERP_MES_NG_REPORT_01";

                        VtNGExcelReport(sFileName);

                        break;

                }







            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                switch (TbSelectType.SelectedIndex)
                {
                    case 0:
                        ViewInventoryList();
                        break;
                    case 1:
                        ViewOperationList();
                        break;
                    case 2:
                        ViewWoList();
                        break;
                    case 3:
                        ViewLotList();
                        break;
                    case 4:
                        ViewVatSupplyList();
                        break;
                    case 5:
                        ViewVatNgList();
                        break;
                }



      
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void TbSelectType_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (TbSelectType.SelectedIndex)
            {
                case 0:
                    pnlStockSearch.Visible = true;
                    pnlStandardSearch.Visible = true;
                    pnlMonthSearch.Visible = false;
                    //ViewInventoryList();
                    break;
                case 1:
                    pnlStockSearch.Visible = false;
                    pnlStandardSearch.Visible = true;
                    pnlMonthSearch.Visible = false;
                    //ViewOperationList();
                    break;
                case 2:
                    pnlStockSearch.Visible = false;
                    pnlStandardSearch.Visible = true;
                    pnlMonthSearch.Visible = false;
                    //ViewWoList();
                    break;
                case 3:
                    pnlStockSearch.Visible = true;
                    pnlStandardSearch.Visible = true;
                    pnlMonthSearch.Visible = false;
                    //ViewWoList();
                    break;

                case 4:
                    pnlStockSearch.Visible = false;
                    pnlStandardSearch.Visible = true;
                    pnlMonthSearch.Visible = false;
                    //ViewWoList();
                    break;
                case 5:
                    pnlStockSearch.Visible = false;
                    pnlStandardSearch.Visible = false;
                    pnlMonthSearch.Visible = true;
                    //ViewWoList();
                    break;

            }

        }



        private void txtMatDesc_TextChanged(object sender, EventArgs e)
        {




        }

        private void lblMatDesc_Click(object sender, EventArgs e)
        {

        }

        private void pnlStockSearch_Paint(object sender, PaintEventArgs e)
        {

        }

        private void cdvMonth_ButtonPress(object sender, EventArgs e)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(cdvMonth.GetListView);

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

                MPCR.FillDataView(cdvMonth.GetListView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);


            cdvMonth.InsertEmptyRow(0, 1);
        }



        #endregion


    }
}
