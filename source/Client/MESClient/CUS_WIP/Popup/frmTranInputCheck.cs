using System;
using System.Data;
using System.Drawing;
using System.Collections.Generic;
using System.Windows.Forms;
using FarPoint.Win.Spread;

using CUS_COM;
using Miracom.CliFrx;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.DNMCore;
using FarPoint.Excel;

namespace CUS_WIP
{
    public partial class frmTranInputCheck : frmViewForm01
    {
        public frmTranInputCheck()
        {
            InitializeComponent();

            InitControl();
        }

        #region Constant

        // 작업자 정보
        private enum INPUTDATA : int
        {
            ORDER_ID,
            MAT_ID,  
            MAT_DESC, 
            ORDER_BOM, 
            LDM_BOM,    
            ISS_BOM      
        }

        #endregion

        #region Variable



        public string C_ORDER_ID = "";
        public string C_OPER = "";
        public string C_LOT_ID = "";
        public string C_PROD_QTY = "";
        #endregion

        #region Function
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

        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                SheetView sv = spdMaterialData.ActiveSheet;

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:



                        break;

                    case CSGC.CHECK.SAVE:



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


        private void ViewBomData()
        {
            try
            {

                grpLotPressInfo.Text =  "W/O: " + C_ORDER_ID + " , LOT LIST: " + C_LOT_ID + "End Qty: " + C_PROD_QTY;


                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;


         

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;


                dvcArgu[1].sCondition_ID = "ORDER_ID";
                dvcArgu[1].sCondition_Value = C_ORDER_ID;


                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = C_OPER;


                dvcArgu[3].sCondition_ID = "PROD_QTY";
                dvcArgu[3].sCondition_Value = Convert.ToDouble(C_PROD_QTY);
               // dvcArgu[3].sCondition_Type = "Double";

                dvcArgu[4].sCondition_ID = "LOT_ID_QUERY";
                dvcArgu[4].sCondition_Value = C_LOT_ID;
                dvcArgu[4].sCondition_Type = "TEXT";

                if (TPDR.GetDataOne("", ref dt, "CWIP0001-007", dvcArgu, false, false, ref sSql) == false)
                {
                    MPCF.ClearList(spdMaterialData);
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }



                for (i = 0; i < dt.Rows.Count; i++)
                {


                    spdMaterialData_Sheet1.RowCount++;


                    spdMaterialData_Sheet1.Cells[i, (int)INPUTDATA.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdMaterialData_Sheet1.Cells[i, (int)INPUTDATA.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMaterialData_Sheet1.Cells[i, (int)INPUTDATA.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMaterialData_Sheet1.Cells[i, (int)INPUTDATA.ORDER_BOM].Value = dt.Rows[i]["ORDER_BOM"];
                    spdMaterialData_Sheet1.Cells[i, (int)INPUTDATA.LDM_BOM].Value = dt.Rows[i]["LDM_BOM"];
                    spdMaterialData_Sheet1.Cells[i, (int)INPUTDATA.ISS_BOM].Value = dt.Rows[i]["ISS_BOM"];


                    if (spdMaterialData_Sheet1.Cells[i, (int)INPUTDATA.LDM_BOM].Text.Trim() == "0")  //
                    {
                        spdMaterialData_Sheet1.Rows[i].ForeColor = Color.Black;
                    }
                    else
                    {
                        spdMaterialData_Sheet1.Rows[i].ForeColor = Color.Red;
                    }
                }
                MPCF.FitColumnHeader(spdMaterialData);



                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        private bool ViewLotPressList()
        {
            return true;
        }

      

        #endregion


        #region Grid / Button Event

        private void frmTranInputCheck_Load(object sender, EventArgs e)
        {
            ViewBomData();
        }


        private void btnYes_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;

        }

        private void btnNo_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void spdPressData_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {

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

                ViewLotPressList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        #endregion


    }
}
