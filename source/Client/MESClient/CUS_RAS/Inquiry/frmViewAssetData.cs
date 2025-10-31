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
using CUS_COM.Reports;
using FarPoint.Win.Spread;

namespace CUS_RAS
{
    public partial class frmViewAssetData : CUS_COM.frmViewForm01
    {
        public frmViewAssetData()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum ASS_INFO : int
        {
            CHK,
            BOOK_TYPE_CODE,
            ASSET_NUMBER,
            ASSET_NAME,
            ATTRIBUTE_CATEGORY_CODE,
            CATEGORY_CODE,
            CURRENT_UNITS,
            ORIGINAL_COST,
            DATE_PLACED_IN_SERVICE,
            OPERATING_UNIT_SEG,
            OPERATING_UNIT,
            DEPARTMENT_SEG,
            DEPARTMENTS,
            PRODUCT_FAMILY_SEG,
            PRODUCT_FAMILY,
            BUSINESS_UNIT,
            TAG_NUMBER,
            SERIAL_NUMBER,
            MANUFACTURER_NAME,
            MODEL_NUMBER,
            EMPLOYEE_NUMBER,
            EMPLOYEE_NAME,
            IN_USE_FLAG,
            PRORATE_DATE,
            LOCATION_ID,
            LOCATION_DESCRIPTION,
            DEPRN_METHOD_CODE,
            CMF_1,
            PLC,
            PURCHASING_DATE,
            CONFIRMATION_DATE,
            CONFIRMED_PLC
        }

        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnDel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnAdd.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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
                       // cDeleteFlag ="";
                        MPCF.ClearList(spdAssetList);
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
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        // 툴 이력 조회
        private void ViewToolHistory()
        {
            string sView_Id = "";
           

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CRAS3011-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

            
                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdAssetList_Sheet1.RowCount++;
             
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.CHK].Value = false;
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.BOOK_TYPE_CODE].Value = dt.Rows[i]["BOOK_TYPE_CODE"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.ASSET_NUMBER].Value = dt.Rows[i]["ASSET_NUMBER"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.ASSET_NAME].Value = dt.Rows[i]["ASSET_NAME"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.ATTRIBUTE_CATEGORY_CODE].Value = dt.Rows[i]["ATTRIBUTE_CATEGORY_CODE"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.CATEGORY_CODE].Value = dt.Rows[i]["CATEGORY_CODE"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.CURRENT_UNITS].Value = dt.Rows[i]["CURRENT_UNITS"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.ORIGINAL_COST].Value = dt.Rows[i]["ORIGINAL_COST"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.DATE_PLACED_IN_SERVICE].Value = dt.Rows[i]["DATE_PLACED_IN_SERVICE"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.OPERATING_UNIT_SEG].Value = dt.Rows[i]["OPERATING_UNIT_SEG"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.OPERATING_UNIT].Value = dt.Rows[i]["OPERATING_UNIT"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.DEPARTMENT_SEG].Value = dt.Rows[i]["DEPARTMENT_SEG"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.DEPARTMENTS].Value = dt.Rows[i]["DEPARTMENTS"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.PRODUCT_FAMILY_SEG].Value = dt.Rows[i]["PRODUCT_FAMILY_SEG"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.PRODUCT_FAMILY].Value = dt.Rows[i]["PRODUCT_FAMILY"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.BUSINESS_UNIT].Value = dt.Rows[i]["BUSINESS_UNIT"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.TAG_NUMBER].Value = dt.Rows[i]["TAG_NUMBER"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.SERIAL_NUMBER].Value = dt.Rows[i]["SERIAL_NUMBER"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.MANUFACTURER_NAME].Value = dt.Rows[i]["MANUFACTURER_NAME"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.MODEL_NUMBER].Value = dt.Rows[i]["MODEL_NUMBER"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.EMPLOYEE_NUMBER].Value = dt.Rows[i]["EMPLOYEE_NUMBER"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.EMPLOYEE_NAME].Value = dt.Rows[i]["EMPLOYEE_NAME"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.IN_USE_FLAG].Value = dt.Rows[i]["IN_USE_FLAG"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.PRORATE_DATE].Value = dt.Rows[i]["PRORATE_DATE"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.LOCATION_ID].Value = dt.Rows[i]["LOCATION_ID"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.LOCATION_DESCRIPTION].Value = dt.Rows[i]["LOCATION_DESCRIPTION"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.DEPRN_METHOD_CODE].Value = dt.Rows[i]["DEPRN_METHOD_CODE"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.PLC].Value = dt.Rows[i]["PLC"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.PURCHASING_DATE].Value = dt.Rows[i]["PURCHASING_DATE"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.CONFIRMATION_DATE].Value = dt.Rows[i]["CONFIRMATION_DATE"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.CONFIRMED_PLC].Value = dt.Rows[i]["CONFIRMED_PLC"];
                    spdAssetList_Sheet1.Cells[i, (int)ASS_INFO.CMF_1].Value = dt.Rows[i]["CMF_1"];


                }
              //  MPCF.FitColumnHeader(spdAssetList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }          
        }
        public static string Emptyval(string sInputVal)
        {
            if (sInputVal == "")
            {
                return " ";
            }
            else
            {
                return sInputVal;
            }
        }

        #endregion

        #region " Event Definition"

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                //MPCF.ExportToExcel(spdToolHisList, this.lblFormName.Text, "");
                EXTFUC.SaveExcel(spdAssetList, "ToolHistory");
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

                ViewToolHistory();
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void frmViewAssetData_Load(object sender, EventArgs e)
        {
            try
            {
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnPrint_Click(object sender, EventArgs e)
        {


            try
            {


                DataTable dt = new DataTable();


                dt.Columns.Add("CATEGORY_CODE", typeof(string));
                dt.Columns.Add("ASSET_NUMBER", typeof(string));
                dt.Columns.Add("ASSET_NAME", typeof(string));
                dt.Columns.Add("CMF_1", typeof(string));
                dt.Columns.Add("PLC", typeof(string));
                dt.Columns.Add("PURCHASING_DATE", typeof(string));
                dt.Columns.Add("CONFIRMATION_DATE", typeof(string));
                dt.Columns.Add("CONFIRMED_PLC", typeof(string));




                string sFileName;


                for (int iRow = 0; iRow < spdAssetList_Sheet1.RowCount; iRow++)
                {
                    if (Convert.ToBoolean(spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CHK].Value) == true)
                    {

                        dt.Rows.Add(
                            spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CATEGORY_CODE].Value,
                            spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.ASSET_NUMBER].Value,
                            spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.ASSET_NAME].Value,
                            spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CMF_1].Value,
                            spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.PLC].Value,
                            spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.PURCHASING_DATE].Value,
                            spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CONFIRMATION_DATE].Value,
                            spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CONFIRMED_PLC].Value
                            );


                    }
                }

                if (dt.Rows.Count != 0)
                {

                    sFileName = "cras3011_001";
                    DevReport.PreviewXtraReport(dt, sFileName);
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }




        }
        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                for (int iRow = 0; iRow < spdAssetList_Sheet1.RowCount; iRow++)
                {
                    if (Convert.ToBoolean(spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CHK].Value) == true)
                    {
                        //서버개발 귀찮..좀 급하게 개발해서...나중에 서버로 

                        string sSql = "";


                        if(spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.BOOK_TYPE_CODE].Text == "NEW")
                        {
                            sSql = "INSERT INTO CERPASTSTS " +
                                " (FACTORY,  " +
                                " BOOK_TYPE_CODE,  " +
                                " ASSET_NUMBER,  " +
                                " ASSET_NAME,  " +
                                " ATTRIBUTE_CATEGORY_CODE,  " +
                                " CATEGORY_CODE,  " +
                                " CURRENT_UNITS,  " +
                                " ORIGINAL_COST,  " +
                                " DATE_PLACED_IN_SERVICE,  " +
                                " OPERATING_UNIT_SEG,  " +
                                " OPERATING_UNIT,  " +
                                " DEPARTMENT_SEG,  " +
                                " DEPARTMENTS,  " +
                                " PRODUCT_FAMILY_SEG,  " +
                                " PRODUCT_FAMILY,  " +
                                " BUSINESS_UNIT,  " +
                                " TAG_NUMBER,  " +
                                " SERIAL_NUMBER,  " +
                                " MANUFACTURER_NAME,  " +
                                " MODEL_NUMBER,  " +
                                " EMPLOYEE_NUMBER,  " +
                                " EMPLOYEE_NAME,  " +
                                " IN_USE_FLAG,  " +
                                " PRORATE_DATE,  " +
                                " LOCATION_ID,  " +
                                " LOCATION_DESCRIPTION,  " +
                                " DEPRN_METHOD_CODE,  " +
                                " PLC,  " +
                                " PURCHASING_DATE,  " +
                                " CONFIRMATION_DATE,  " +
                                " CONFIRMED_PLC,  " +
                                " CMF_1  )" +
                                " VALUES ( " +
                             " '" + MPGV.gsFactory + "' " +
                             " ,'MES' " +
                             " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.ASSET_NUMBER].Value + "') "+
                             " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.ASSET_NAME].Value + "') " +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.ATTRIBUTE_CATEGORY_CODE].Value + "') " +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CATEGORY_CODE].Value + "') " +
                            " , F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CURRENT_UNITS].Value + "') " +
                            " , F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.ORIGINAL_COST].Value + "') " +
                            " , F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.DATE_PLACED_IN_SERVICE].Value + "') " +
                            " , F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CONFIRMED_PLC].Value + "') " +
                            " , F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.OPERATING_UNIT].Value + "') " +
                            " , F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.DEPARTMENT_SEG].Value + "') " +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.DEPARTMENTS].Value + "') " +
                            " , F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.PRODUCT_FAMILY_SEG].Value + "') " +
                            " , F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.PRODUCT_FAMILY].Value + "') " +
                            " , F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.BUSINESS_UNIT].Value + "') " +
                            " , F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.TAG_NUMBER].Value + "') " +
                            " , F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.SERIAL_NUMBER].Value + "' )" +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.MANUFACTURER_NAME].Value + "') " +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.MODEL_NUMBER].Value + "') " +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.EMPLOYEE_NUMBER].Value + "') " +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.EMPLOYEE_NAME].Value + "') " +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.IN_USE_FLAG].Value + "') " +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.PRORATE_DATE].Value + "') " +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.LOCATION_ID].Value + "') " +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.LOCATION_DESCRIPTION].Value + "') " +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.DEPRN_METHOD_CODE].Value + "') " +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.PLC].Value + "') " +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.PURCHASING_DATE].Value + "') " +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CONFIRMATION_DATE].Value + "') " +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CONFIRMED_PLC].Value + "') " +
                            " ,F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CMF_1].Value + "')) "; 




                        }
                        else
                        {
                            sSql = "UPDATE CERPASTSTS SET " +
                             " ATTRIBUTE_CATEGORY_CODE= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.ATTRIBUTE_CATEGORY_CODE].Value + "') " +
                             " ,CATEGORY_CODE= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CATEGORY_CODE].Value + "') " +
                             " ,CURRENT_UNITS= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CURRENT_UNITS].Value + "') " +
                             " ,ORIGINAL_COST= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.ORIGINAL_COST].Value + "') " +
                             " ,DATE_PLACED_IN_SERVICE= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.DATE_PLACED_IN_SERVICE].Value + "') " +
                             " ,OPERATING_UNIT_SEG= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CONFIRMED_PLC].Value + "') " +
                             " ,OPERATING_UNIT= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.OPERATING_UNIT].Value + "') " +
                             " ,DEPARTMENT_SEG= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.DEPARTMENT_SEG].Value + "') " +
                             " ,DEPARTMENTS= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.DEPARTMENTS].Value + "') " +
                             " ,PRODUCT_FAMILY_SEG= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.PRODUCT_FAMILY_SEG].Value + "') " +
                             " ,PRODUCT_FAMILY= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.PRODUCT_FAMILY].Value + "') " +
                             " ,BUSINESS_UNIT= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.BUSINESS_UNIT].Value + "') " +
                             " ,TAG_NUMBER= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.TAG_NUMBER].Value + "') " +
                             " ,SERIAL_NUMBER= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.SERIAL_NUMBER].Value + "') " +
                             " ,MANUFACTURER_NAME= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.MANUFACTURER_NAME].Value + "') " +
                             " ,MODEL_NUMBER= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.MODEL_NUMBER].Value + "') " +
                             " ,EMPLOYEE_NUMBER= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.EMPLOYEE_NUMBER].Value + "') " +
                             " ,EMPLOYEE_NAME= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.EMPLOYEE_NAME].Value + "') " +
                             " ,IN_USE_FLAG= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.IN_USE_FLAG].Value + "') " +
                             " ,PRORATE_DATE= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.PRORATE_DATE].Value + "') " +
                             " ,LOCATION_ID= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.LOCATION_ID].Value + "') " +
                             " ,LOCATION_DESCRIPTION= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.LOCATION_DESCRIPTION].Value + "') " +
                             " ,DEPRN_METHOD_CODE= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.DEPRN_METHOD_CODE].Value + "') " +
                             " ,PLC= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.PLC].Value + "') " +
                             " ,PURCHASING_DATE= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.PURCHASING_DATE].Value + "') " +
                             " ,CONFIRMATION_DATE= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CONFIRMATION_DATE].Value + "') " +
                             " ,CONFIRMED_PLC= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CONFIRMED_PLC].Value + "') " +
                             " ,CMF_1= F_NULL_VAL('" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CMF_1].Value + "') " +
                             " WHERE FACTORY ='" + MPGV.gsFactory + "' " +
                             " AND BOOK_TYPE_CODE ='" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.BOOK_TYPE_CODE].Value + "' " +
                             " AND ASSET_NUMBER ='" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.ASSET_NUMBER].Value + "' ";
                        }







                     


                        TRSNode in_node = new TRSNode("TRAN_IN");
                        TRSNode out_node = new TRSNode("TRAN_OUT");

                        MPCR.SetInMsg(in_node);

                        in_node.ProcStep = '1';
                        in_node.AddString("SQL", sSql);

                        if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                        {
                            spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CHK].Value = false;
                            spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CHK].BackColor = Color.WhiteSmoke;
                        }
                        else
                        {
                            MPCR.ShowSuccessMsg(out_node);
                        }


                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }


        }
        private void spdAssetList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {


                int i = 0;
                bool allChecked = false;

                SheetView svRes = spdAssetList.ActiveSheet;

                if (e.Row >= 0 && Convert.ToBoolean(svRes.Cells[e.Row, (int)ASS_INFO.CHK] == null ? false : svRes.Cells[e.Row, (int)ASS_INFO.CHK].Value))
                    svRes.Cells[e.Row, (int)ASS_INFO.CHK].Value = true;



                if (e.ColumnHeader == false)
                {
                    return;
                }

                if (e.Column != (int)ASS_INFO.CHK)
                {
                    return;
                }

                if (svRes.ColumnHeader.Cells[0, 0].Value == null || Convert.ToBoolean(svRes.ColumnHeader.Cells[0, 0].Value == null ? false : svRes.ColumnHeader.Cells[0, 0].Value) == false)
                {
                    allChecked = false;
                }
                else
                {
                    allChecked = true;
                }

                if (allChecked == true)
                {
                    for (i = 0; i < svRes.RowCount; i++)
                    {
                        svRes.Cells[i, 0].Value = false;
                    }

                    svRes.ColumnHeader.Cells[0, 0].Value = false;
                }
                else
                {
                    for (i = 0; i < svRes.RowCount; i++)
                    {
                        svRes.Cells[i, 0].Value = true;
                    }
                    svRes.ColumnHeader.Cells[0, 0].Value = true;
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdAssetList_EditModeStarting(object sender, EditModeStartingEventArgs e)
        {
            if (spdAssetList_Sheet1.ActiveColumnIndex != 0)
                spdAssetList_Sheet1.Cells[spdAssetList_Sheet1.ActiveRowIndex, (int)ASS_INFO.CHK].Value = true;
        }
        private void btnAdd_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.ADD) == false)
                    return;

                SheetView sv = spdAssetList_Sheet1;
                int iRow = sv.RowCount;

                sv.RowCount++;
                sv.Cells[iRow, (int)ASS_INFO.CHK].Value = true;
                sv.Cells[iRow, (int)ASS_INFO.BOOK_TYPE_CODE].Value = "NEW";
                sv.Cells[iRow, (int)ASS_INFO.ASSET_NUMBER].Value = " ";

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        private void btnDel_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.ShowMsgBox(MPCF.GetMessage(53), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                {
                    return;
                }

                    for (int iRow = 0; iRow < spdAssetList_Sheet1.RowCount; iRow++)
                {
                    if (Convert.ToBoolean(spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CHK].Value) == true)
                    {
                        
                        
                        //서버개발 귀찮..좀 급하게 개발해서...나중에 서버로 바꿔놓을것음..일단 죄송.
                        
                        string sSql = "";
                        if (spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.BOOK_TYPE_CODE].ToString() == "NEW")
                        {
                            spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CHK].Value = false;
                            spdAssetList_Sheet1.Rows[iRow].Visible = false;


                        }
                        else
                        {
                            sSql = "DELETE CERPASTSTS " +
                             " WHERE FACTORY ='" + MPGV.gsFactory + "' " +
                             " AND BOOK_TYPE_CODE ='" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.BOOK_TYPE_CODE].Value + "' " +
                             " AND ASSET_NUMBER ='" + spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.ASSET_NUMBER].Value + "' ";
                            

                            TRSNode in_node = new TRSNode("TRAN_IN");
                            TRSNode out_node = new TRSNode("TRAN_OUT");

                            MPCR.SetInMsg(in_node);

                            in_node.ProcStep = '1';
                            in_node.AddString("SQL", sSql);

                            if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                            {
                                spdAssetList_Sheet1.Cells[iRow, (int)ASS_INFO.CHK].Value = false;
                                spdAssetList_Sheet1.Rows[iRow].Visible = false;
                            }
                            else
                            {
                                MPCR.ShowSuccessMsg(out_node);
                            }

                        }












                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

        }

        #endregion
    }
}
