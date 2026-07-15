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
using System.IO;        //추가
using System.Xml.Linq;
using FarPoint.Excel.EntityClassLibrary.DrawingEx;
using FarPoint.Excel.EntityClassLibrary.SpreadsheetML;
using System.Diagnostics;
using FarPoint.Win.Spread.CellType;
using Miracom.UI;

namespace CUS_WIP
{
    public partial class frmWIPViewOperLotList : CUS_COM.frmViewForm01
    {


        #region " Constant Definition "

        private enum LOT_INFO
        {
            CHK,
            OPER,
            LOT_ID,
            MAT_TYPE,
            MAT_TYPE_DESC,
            MAT_ID,
            MAT_DESC,
            PROD_QTY,
            UNIT,
            COMMENT,
            WORK_TYPE,
            AREA_ID,
            SUB_AREA_ID,
            ORDER_ID,
            ORDER_STATUS,
            START_RES_ID,
            START_RES_DESC,
            INPUT_STATUS,
            GROUP_ID,
            OPER_IN_TIME,
            CREATE_TIME,
            INV_FLAG,
            INSP_RESULT_DESC,
            CREATE_CODE_DESC,
            ACTUAL_MAT_ID,
            ACTUAL_MAT_DESC
        }

        private enum WLOT_INFO
        {
            CHK,
            OPER,
            LOT_ID,
            MAT_TYPE,
            MAT_TYPE_DESC,
            MAT_ID,
            MAT_DESC,
            PROD_QTY,
            PROD_UNIT,
            COMMENT,
            CONV_PROD_QTY,
            CONV_UNIT,
            CONV_UNIT_QTY,
            CUSTOMER_NAME,
            DELIVERY_NAME,
            LABEL_NAME,
            AREA_ID,
            SUB_AREA_ID,
            ORDER_ID,
            ORDER_STATUS,
            OPER_IN_TIME,
            CREATE_TIME,
            INSP_RESULT_DESC,
            CREATE_CODE_DESC,
            PACKING_INSTRUCTIONS,
            OPER_CODE,
            OPER_GRP_1,
            INV_FLAG,
            ACTUAL_MAT_ID,
            ACTUAL_MAT_DESC
        }

        private enum ALL_LOT_INFO
        {
            CHK,
            LOT_ID,
            OPER,
            OPER_DESC,
            LOT_PROCESS_BTN,
            LOT_MAT_MOVE_BTN,
            LOT_MAT_CHANGE_BTN,
            LOT_MERGE_BTN,
            LOT_SPLITE_BTN,
            LOT_RETURN_BTN,
            LOT_HOLD_YN,
            LOT_HOLD_BTN,
            LOT_ID_CHANGE_TXT,
            LOT_ID_CHANGE_BTN,
            ORDER_ID,
            OPER_IN_TIME,
            MAT_TYPE,
            MAT_TYPE_DESC,
            MAT_ID,
            MAT_DESC,
            PROD_QTY,
            UNIT,
            CONV_PROD_QTY,
            CONV_UNIT,
            CONV_UNIT_QTY,
            CONV_FLAG,
            OUTSOURCEING_ORDER,
            RECV_DATE,
            VENDOR_ID,
            VENDOR_DESC,
            VENDOR_SITE_ID,
            VENDOR_LOT_ID,
            VENDOR_LOT_BTN,
            FIXED_COMMENT,
            FIXED_COMMENT_BTN,
            LAST_COMMENT,
            LAST_COMMENT_BTN,
            START_RES_ID,
            START_RES_DESC,
            WORK_TYPE,
            WORK_TYPE_DESC,
            AREA_ID,
            AREA_DESC,
            SUB_AREA_ID,
            SUB_AREA_DESC,
            ORDER_STATUS,
            INPUT_STATUS,
            GROUP_ID,
            CREATE_TIME,
            INSP_RESULT_DESC,
            REL_LEVEL,
            REL_DESC,
            LDM_DESC,
            LDM_DESC_BTN,
            INV_FLAG,
            PACK_DATE,
            ORG_LOT_ID,
            CUSTOMER_NAME,
            DELIVERY_NAME,
            PACK_ORDER_ID,
            PACK_LINE_NO,
            ERP_PACK_ORDER_ID,
            LABEL_NAME,
            PACKING_INSTRUCTIONS,
            SHIP_FLAG,
            SHIP_DATE,
            SHIP_ORDER_ID,
            SHIP_ORDER_SEQ,
            RET_DATE,
            RET_ORDER_ID,
            RET_LINE_NO,
            ACTUAL_MAT_ID,
            ACTUAL_MAT_DESC,
            OPER_GRP_1,
            CREATE_CODE,
            CREATE_CODE_DESC,
            TABLE_NAME,
            ERP_OPER,
            WIP_INV
        }

        #endregion

        public frmWIPViewOperLotList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Variable Definition "
        int iTabIndex = 0;
        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                lblLabel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                cdvLabel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");

                txtPath.Text = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);

                spdLotList.ActiveSheet.ColumnHeader.Cells[0, 0].Value = null;
                spdwLotList.ActiveSheet.ColumnHeader.Cells[0, 0].Value = null;

                tabselect();

                btnOutsourceing.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                cdvOutsourcing.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblOutSourcing.Anchor = AnchorStyles.Top | AnchorStyles.Right;  


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewOperLotList()
        {
            try
            {
                if (chkNowOnly.Checked)
                {
                    dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                    dtpDate.Enabled = false;
                }
                else
                {
                    dtpDate.Enabled = true;
                }
                if (!(dtpDate.Text == DateTime.Now.ToString("yyyy-MM-dd")))
                {
                    if (dtpDate.Text == DateTime.Now.AddDays(-1.0).ToString("yyyy-MM-dd") && int.Parse(DateTime.Now.Hour.ToString()) < 8)
                    {
                        MPCF.ShowMsgBox("전일 과거시점조회는 8시이후부터 조회가능 합니다. \n (You can inquire the previous day after 8 o'clock)");
                        dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                    }
                    else
                    {
                        MPCF.ShowMsgBox(dtpDate.Text + " 일 과거시점 재고조회 \n (" + dtpDate.Text + " Past Date Search)");
                    }
                }
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[14];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "AREA_ID";
                array[1].sCondition_Value = cdvDept.Text;
                array[2].sCondition_ID = "SUB_AREA_ID";
                array[2].sCondition_Value = cdvWorkPlace.Text + "%";
                array[3].sCondition_ID = "OPER";
                array[3].sCondition_Value = cdvOper.Text;
                array[4].sCondition_ID = "ORDER_ID";
                array[4].sCondition_Value = cdvOrder.Text + "%";
                array[5].sCondition_ID = "MAT_TYPE";
                array[5].sCondition_Value = cdvMatType.Text + "%";
                array[6].sCondition_ID = "MAT_ID";
                array[6].sCondition_Value = cdvMat.Text + "%";
                array[7].sCondition_ID = "LOT_ID";
                array[7].sCondition_Value = txtLotID.Text + "%";
                array[8].sCondition_ID = "INV_FLAG";
                array[8].sCondition_Value = cdvInvYN.Text + "%";

                //array[9].sCondition_ID = "MAT_DESC";
                //array[9].sCondition_Value = "%" + txtMatDesc.Text + "%";

                string sMatDesc = txtMatDesc.Text;
                string sMatDesc2 = txtMatDesc2.Text;
                string sSqlText = "";
                string sExcludeWord = "";
                StringBuilder sb = new StringBuilder();

                //제품명 & 제품코드
                if (sMatDesc != "" || sMatDesc2 != "")
                {
                    sb.Append(" AND (");

                    if (!string.IsNullOrEmpty(sMatDesc))
                    {
                        sb.Append($"(B.MAT_DESC LIKE '%' || '{sMatDesc}' || '%')");
                    }

                    if (!string.IsNullOrEmpty(sMatDesc2))
                    {
                        if (sb.Length > 6) // 첫 번째 조건이 추가된 경우
                        {
                            sb.Append(" OR ");
                        }
                        sb.Append($"(B.MAT_DESC LIKE '%' || '{sMatDesc2}' || '%')");
                    }
                    sb.Append(")");

                    sSqlText = sSqlText + sb.ToString();       // 결과 문자열 
                }

                // 제외문자
                sExcludeWord = MPCF.Trim(txtExcludeWord.Text);
                string[] split_data = sExcludeWord.Split(new string[] { string.Format("{0}", "%") }, StringSplitOptions.RemoveEmptyEntries);
                for (int k = 0; k < split_data.Count(); k++)
                {
                    sSqlText = sSqlText + " AND B.MAT_DESC NOT LIKE '%' || '" + split_data[k] + "' || '%'";
                }

                array[9].sCondition_ID = "SQL_TEXT";
                array[9].sCondition_Type = "TEXT";
                if (sSqlText == "")
                {
                    array[9].sCondition_Value = "AND 1=1";
                }
                else
                {
                    array[9].sCondition_Value = sSqlText;
                }
                 

                array[10].sCondition_ID = "CREATE_CODE";
                array[10].sCondition_Value = cdvOrderType.Text + "%";
                array[11].sCondition_ID = "EOH_DATE";
                array[11].sCondition_Value = dtpDate.Text.Replace("-", "");
                if (rdo08.Checked)
                {
                    array[12].sCondition_ID = "EOH_ST";
                    array[12].sCondition_Value = "08";
                }
                array[12].sCondition_ID = "EOH_ST";
                array[12].sCondition_Value = "00";
                array[13].sCondition_ID = "HOLD_FLAG";
                array[13].sCondition_Value = cdvHold.Text + "%";
                if (!TPDR.GetDataOne("", ref dt, "CWIP3007-001", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdLotList);
                    return;
                }
                MPCF.ClearList(spdLotList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdLotList.ActiveSheet.RowCount++;
                    spdLotList.ActiveSheet.SetValue(num, 0, false);
                    spdLotList.ActiveSheet.Cells[num, 1].Value = dt.Rows[num]["OPER_DESC"];
                    spdLotList.ActiveSheet.Cells[num, 19].Value = dt.Rows[num]["OPER_IN_TIME"];
                    spdLotList.ActiveSheet.Cells[num, 2].Value = dt.Rows[num]["LOT_ID"];
                    spdLotList.ActiveSheet.Cells[num, 3].Value = dt.Rows[num]["MAT_TYPE"];
                    spdLotList.ActiveSheet.Cells[num, 4].Value = dt.Rows[num]["MAT_TYPE_DESC"];
                    spdLotList.ActiveSheet.Cells[num, 5].Value = dt.Rows[num]["MAT_ID"];
                    spdLotList.ActiveSheet.Cells[num, 6].Value = dt.Rows[num]["MAT_DESC"];
                    spdLotList.ActiveSheet.Cells[num, 7].Value = dt.Rows[num]["PROD_QTY"];
                    spdLotList.ActiveSheet.Cells[num, 8].Value = dt.Rows[num]["UNIT"];
                    spdLotList.ActiveSheet.Cells[num, 10].Value = dt.Rows[num]["WORK_TYPE_DESC"];
                    spdLotList.ActiveSheet.Cells[num, 11].Value = dt.Rows[num]["AREA_DESC"];
                    spdLotList.ActiveSheet.Cells[num, 12].Value = dt.Rows[num]["SUB_AREA_DESC"];
                    spdLotList.ActiveSheet.Cells[num, 13].Value = dt.Rows[num]["ORDER_ID"];
                    spdLotList.ActiveSheet.Cells[num, 14].Value = dt.Rows[num]["ORDER_STATUS"];
                    spdLotList.ActiveSheet.Cells[num, 15].Value = dt.Rows[num]["START_RES_ID"];
                    spdLotList.ActiveSheet.Cells[num, 16].Value = dt.Rows[num]["START_RES_DESC"];
                    spdLotList.ActiveSheet.Cells[num, 17].Value = dt.Rows[num]["INPUT_STATUS"];
                    spdLotList.ActiveSheet.Cells[num, 18].Value = dt.Rows[num]["GROUP_ID"];
                    spdLotList.ActiveSheet.Cells[num, 20].Value = MPCF.MakeDateFormat(dt.Rows[num]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdLotList.ActiveSheet.Cells[num, 21].Value = dt.Rows[num]["INV_FLAG_DESC"];
                    spdLotList.ActiveSheet.Cells[num, 22].Value = dt.Rows[num]["INSP_RESULT_DESC"];
                    spdLotList.ActiveSheet.Cells[num, 23].Value = dt.Rows[num]["CREATE_CODE_DESC"];
                    spdLotList.ActiveSheet.Cells[num, 9].Value = dt.Rows[num]["LAST_COMMENT"];
                    spdLotList.ActiveSheet.Cells[num, 24].Value = dt.Rows[num]["ACTUAL_MAT_ID"];
                    spdLotList.ActiveSheet.Cells[num, 25].Value = dt.Rows[num]["ACTUAL_MAT_DESC"];
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void SetSheetConvertColumn(string flag)
        {
            if (flag == "Y")
            {
                spdwLotList_Sheet1.Columns[10].Visible = true;
                spdwLotList_Sheet1.Columns[11].Visible = true;
            }
            else
            {
                spdwLotList_Sheet1.Columns[10].Visible = false;
                spdwLotList_Sheet1.Columns[11].Visible = false;
            }
        }

        private void ViewWareHouseLotList()
        {
            try
            {
                if (chkNowOnly.Checked)
                {
                    dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                    dtpDate.Enabled = false;
                }
                else
                {
                    dtpDate.Enabled = true;
                }
                if (!(dtpDate.Text == DateTime.Now.ToString("yyyy-MM-dd")))
                {
                    if (dtpDate.Text == DateTime.Now.AddDays(-1.0).ToString("yyyy-MM-dd") && int.Parse(DateTime.Now.Hour.ToString()) < 8)
                    {
                        MPCF.ShowMsgBox("전일 과거시점조회는 8시이후부터 조회가능 합니다. \n (You can inquire the previous day after 8 o'clock)");
                        dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                    }
                    else
                    {
                        MPCF.ShowMsgBox(dtpDate.Text + " 일 과거시점 재고조회 \n (" + dtpDate.Text + " Past Date Search)");
                    }
                }
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[12];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                double num2 = 0.0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "AREA_ID";
                array[1].sCondition_Value = cdvDept.Text;
                array[2].sCondition_ID = "OPER";
                array[2].sCondition_Value = cdvOper.Text;
                array[3].sCondition_ID = "ORDER_ID";
                array[3].sCondition_Value = cdvOrder.Text + "%";
                array[4].sCondition_ID = "MAT_TYPE";
                array[4].sCondition_Value = cdvMatType.Text + "%";
                array[5].sCondition_ID = "MAT_ID";
                array[5].sCondition_Value = cdvMat.Text + "%";
                array[6].sCondition_ID = "LOT_ID";
                array[6].sCondition_Value = txtLotID.Text + "%";
                //array[7].sCondition_ID = "MAT_DESC";
                //array[7].sCondition_Value = "%" + txtMatDesc.Text + "%";

                string sMatDesc = txtMatDesc.Text;
                string sMatDesc2 = txtMatDesc2.Text;
                string sSqlText = "";
                string sExcludeWord = "";
                StringBuilder sb = new StringBuilder();

                //제품명 & 제품코드
                if (sMatDesc != "" || sMatDesc2 != "")
                {
                    sb.Append(" AND (");

                    if (!string.IsNullOrEmpty(sMatDesc))
                    {
                        sb.Append($"(B.MAT_DESC LIKE '%' || '{sMatDesc}' || '%')");
                    }

                    if (!string.IsNullOrEmpty(sMatDesc2))
                    {
                        if (sb.Length > 6) // 첫 번째 조건이 추가된 경우
                        {
                            sb.Append(" OR ");
                        }
                        sb.Append($"(B.MAT_DESC LIKE '%' || '{sMatDesc2}' || '%')");
                    }
                    sb.Append(")");

                    sSqlText = sSqlText + sb.ToString();       // 결과 문자열 
                }

                // 제외문자
                sExcludeWord = MPCF.Trim(txtExcludeWord.Text);
                string[] split_data = sExcludeWord.Split(new string[] { string.Format("{0}", "%") }, StringSplitOptions.RemoveEmptyEntries);
                for (int k = 0; k < split_data.Count(); k++)
                {
                    sSqlText = sSqlText + " AND B.MAT_DESC NOT LIKE '%' || '" + split_data[k] + "' || '%'";
                }

                array[7].sCondition_ID = "SQL_TEXT";
                array[7].sCondition_Type = "TEXT";
                if (sSqlText == "")
                {
                    array[7].sCondition_Value = "AND 1=1";
                }
                else
                {
                    array[7].sCondition_Value = sSqlText;
                }


                array[8].sCondition_ID = "CREATE_CODE";
                array[8].sCondition_Value = cdvOrderType.Text + "%";
                array[9].sCondition_ID = "EOH_DATE";
                array[9].sCondition_Value = dtpDate.Text.Replace("-", "");
                if (rdo08.Checked)
                {
                    array[10].sCondition_ID = "EOH_ST";
                    array[10].sCondition_Value = "08";
                }
                array[10].sCondition_ID = "EOH_ST";
                array[10].sCondition_Value = "00";
                array[11].sCondition_ID = "HOLD_FLAG";
                array[11].sCondition_Value = cdvHold.Text + "%";
                if (!TPDR.GetDataOne("", ref dt, "CWIP3007-002", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdwLotList);
                    return;
                }
                MPCF.ClearList(spdwLotList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdwLotList.ActiveSheet.RowCount++;
                    if (num == 0)
                    {
                        SetSheetConvertColumn(dt.Rows[num]["CONV_FLAG"].ToString());
                    }
                    spdwLotList.ActiveSheet.SetValue(num, 0, false);
                    spdwLotList.ActiveSheet.Cells[num, 1].Value = dt.Rows[num]["OPER_DESC"];
                    spdwLotList.ActiveSheet.Cells[num, 20].Value = dt.Rows[num]["OPER_IN_TIME"];
                    spdwLotList.ActiveSheet.Cells[num, 2].Value = dt.Rows[num]["LOT_ID"];
                    spdwLotList.ActiveSheet.Cells[num, 3].Value = dt.Rows[num]["MAT_TYPE"];
                    spdwLotList.ActiveSheet.Cells[num, 4].Value = dt.Rows[num]["MAT_TYPE_DESC"];
                    spdwLotList.ActiveSheet.Cells[num, 5].Value = dt.Rows[num]["MAT_ID"];
                    spdwLotList.ActiveSheet.Cells[num, 6].Value = dt.Rows[num]["MAT_DESC"];
                    spdwLotList.ActiveSheet.Cells[num, 7].Value = dt.Rows[num]["PROD_QTY"];
                    spdwLotList.ActiveSheet.Cells[num, 8].Value = dt.Rows[num]["UNIT_1"];
                    spdwLotList.ActiveSheet.Cells[num, 10].Value = dt.Rows[num]["CONV_PROD_QTY"];
                    spdwLotList.ActiveSheet.Cells[num, 11].Value = dt.Rows[num]["CONV_UNIT"];
                    spdwLotList.ActiveSheet.Cells[num, 12].Value = dt.Rows[num]["CONV_UNIT_QTY"];
                    spdwLotList.ActiveSheet.Cells[num, 13].Value = dt.Rows[num]["CUSTOMER_NAME"];
                    spdwLotList.ActiveSheet.Cells[num, 14].Value = dt.Rows[num]["DELIVERY_NAME"];
                    spdwLotList.ActiveSheet.Cells[num, 15].Value = dt.Rows[num]["LABEL_NAME"];
                    spdwLotList.ActiveSheet.Cells[num, 16].Value = dt.Rows[num]["AREA_DESC"];
                    spdwLotList.ActiveSheet.Cells[num, 17].Value = dt.Rows[num]["SUB_AREA_DESC"];
                    spdwLotList.ActiveSheet.Cells[num, 18].Value = dt.Rows[num]["ORDER_ID"];
                    spdwLotList.ActiveSheet.Cells[num, 19].Value = dt.Rows[num]["ORDER_STATUS"];
                    spdwLotList.ActiveSheet.Cells[num, 21].Value = MPCF.MakeDateFormat(dt.Rows[num]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdwLotList.ActiveSheet.Cells[num, 22].Value = dt.Rows[num]["INSP_RESULT_DESC"];
                    spdwLotList.ActiveSheet.Cells[num, 23].Value = dt.Rows[num]["CREATE_CODE_DESC"];
                    spdwLotList.ActiveSheet.Cells[num, 24].Value = dt.Rows[num]["PACKING_INSTRUCTIONS"];
                    spdwLotList.ActiveSheet.Cells[num, 9].Value = dt.Rows[num]["LAST_COMMENT"];
                    spdwLotList.ActiveSheet.Cells[num, 25].Value = dt.Rows[num]["OPER"];
                    spdwLotList.ActiveSheet.Cells[num, 26].Value = dt.Rows[num]["OPER_GRP_1"];
                    spdwLotList.ActiveSheet.Cells[num, 27].Value = dt.Rows[num]["INV_FLAG"];
                    spdwLotList.ActiveSheet.Cells[num, 28].Value = dt.Rows[num]["ACTUAL_MAT_ID"];
                    spdwLotList.ActiveSheet.Cells[num, 29].Value = dt.Rows[num]["ACTUAL_MAT_DESC"];
                    if (dt.Rows[num]["CONV_FLAG"].ToString() == "Y")
                    {
                        num2 += Convert.ToDouble((dt.Rows[num]["CONV_PROD_QTY"] == null) ? ((object)0) : dt.Rows[num]["CONV_PROD_QTY"]);
                    }
                }
                if (num2 > 0.0)
                {
                    spdwLotList_Sheet1.ColumnFooter.Cells[0, 10].Value = num2;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewAllLotList()
        {
            try
            {
                if (chkNowOnly.Checked)
                {
                    dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                    dtpDate.Enabled = false;
                }
                else
                {
                    dtpDate.Enabled = true;
                }
                if (!(dtpDate.Text == DateTime.Now.ToString("yyyy-MM-dd")))
                {
                    if (dtpDate.Text == DateTime.Now.AddDays(-1.0).ToString("yyyy-MM-dd") && int.Parse(DateTime.Now.Hour.ToString()) < 8)
                    {
                        MPCF.ShowMsgBox("전일 과거시점조회는 8시이후부터 조회가능 합니다. \n (You can inquire the previous day after 8 o'clock)");
                        dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                    }
                    else
                    {
                        MPCF.ShowMsgBox(dtpDate.Text + " 일 과거시점 재고조회 \n (" + dtpDate.Text + " Past Date Search)");
                    }
                }
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[14];
                DataTable dt = null;
                string sSql = "";
                int num = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "AREA_ID";
                array[1].sCondition_Value = cdvDept.Text;
                array[2].sCondition_ID = "SUB_AREA_ID";
                array[2].sCondition_Value = cdvWorkPlace.Text + "%";
                array[3].sCondition_ID = "OPER";
                array[3].sCondition_Value = cdvOper.Text;
                array[4].sCondition_ID = "ORDER_ID";
                array[4].sCondition_Value = cdvOrder.Text + "%";
                array[5].sCondition_ID = "MAT_TYPE";
                array[5].sCondition_Value = cdvMatType.Text + "%";
                array[6].sCondition_ID = "MAT_ID";
                array[6].sCondition_Value = cdvMat.Text + "%";
                array[7].sCondition_ID = "LOT_ID";
                array[7].sCondition_Value = txtLotID.Text + "%";
                array[8].sCondition_ID = "INV_FLAG";
                array[8].sCondition_Value = cdvInvYN.Text + "%";
                //array[9].sCondition_ID = "MAT_DESC";
                //array[9].sCondition_Value = "%" + txtMatDesc.Text + "%";

                string sMatDesc = txtMatDesc.Text;
                string sMatDesc2 = txtMatDesc2.Text;
                string sSqlText = "";
                string sExcludeWord = "";
                StringBuilder sb = new StringBuilder();

                //제품명 & 제품코드
                if (sMatDesc != "" || sMatDesc2 != "")
                {
                    sb.Append(" AND (");

                    if (!string.IsNullOrEmpty(sMatDesc))
                    {
                        sb.Append($"(B.MAT_DESC LIKE '%' || '{sMatDesc}' || '%')");
                    }

                    if (!string.IsNullOrEmpty(sMatDesc2))
                    {
                        if (sb.Length > 6) // 첫 번째 조건이 추가된 경우
                        {
                            sb.Append(" OR ");
                        }
                        sb.Append($"(B.MAT_DESC LIKE '%' || '{sMatDesc2}' || '%')");
                    }
                    sb.Append(")");

                    sSqlText = sSqlText + sb.ToString();       // 결과 문자열 
                }

                // 제외문자
                sExcludeWord = MPCF.Trim(txtExcludeWord.Text);
                string[] split_data = sExcludeWord.Split(new string[] { string.Format("{0}", "%") }, StringSplitOptions.RemoveEmptyEntries);
                for (int k = 0; k < split_data.Count(); k++)
                {
                    sSqlText = sSqlText + " AND B.MAT_DESC NOT LIKE '%' || '" + split_data[k] + "' || '%'";
                }

                array[9].sCondition_ID = "SQL_TEXT";
                array[9].sCondition_Type = "TEXT";
                if (sSqlText == "")
                {
                    array[9].sCondition_Value = "AND 1=1";
                }
                else
                {
                    array[9].sCondition_Value = sSqlText;
                }


                array[10].sCondition_ID = "CREATE_CODE";
                array[10].sCondition_Value = cdvOrderType.Text + "%";
                array[11].sCondition_ID = "EOH_DATE";
                array[11].sCondition_Value = dtpDate.Text.Replace("-", "");
                if (rdo08.Checked)
                {
                    array[12].sCondition_ID = "EOH_ST";
                    array[12].sCondition_Value = "08";
                }
                array[12].sCondition_ID = "EOH_ST";
                array[12].sCondition_Value = "00";
                array[13].sCondition_ID = "HOLD_FLAG";
                array[13].sCondition_Value = cdvHold.Text + "%";
                if (!TPDR.GetDataOne("", ref dt, "CWIP3007-005", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdAllLotList);
                    return;
                }
                MPCF.ClearList(spdAllLotList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdAllLotList.ActiveSheet.RowCount++;
                    spdAllLotList.ActiveSheet.Cells[num, 1].Value = dt.Rows[num]["LOT_ID"];
                    spdAllLotList.ActiveSheet.Cells[num, 2].Value = dt.Rows[num]["OPER"];
                    spdAllLotList.ActiveSheet.Cells[num, 3].Value = dt.Rows[num]["OPER_DESC"];
                    spdAllLotList.ActiveSheet.Cells[num, 10].Value = dt.Rows[num]["LOT_HOLD_YN"];
                    spdAllLotList.ActiveSheet.Cells[num, 14].Value = dt.Rows[num]["ORDER_ID"];
                    spdAllLotList.ActiveSheet.Cells[num, 15].Value = dt.Rows[num]["OPER_IN_TIME"];
                    spdAllLotList.ActiveSheet.Cells[num, 16].Value = dt.Rows[num]["MAT_TYPE"];
                    spdAllLotList.ActiveSheet.Cells[num, 17].Value = dt.Rows[num]["MAT_TYPE_DESC"];
                    spdAllLotList.ActiveSheet.Cells[num, 18].Value = dt.Rows[num]["MAT_ID"];
                    spdAllLotList.ActiveSheet.Cells[num, 19].Value = dt.Rows[num]["MAT_DESC"];
                    spdAllLotList.ActiveSheet.Cells[num, 20].Value = dt.Rows[num]["PROD_QTY"];
                    spdAllLotList.ActiveSheet.Cells[num, 21].Value = dt.Rows[num]["UNIT"];
                    spdAllLotList.ActiveSheet.Cells[num, 22].Value = dt.Rows[num]["CONV_PROD_QTY"];
                    spdAllLotList.ActiveSheet.Cells[num, 23].Value = dt.Rows[num]["CONV_UNIT"];
                    spdAllLotList.ActiveSheet.Cells[num, 24].Value = dt.Rows[num]["CONV_UNIT_QTY"];
                    spdAllLotList.ActiveSheet.Cells[num, 25].Value = dt.Rows[num]["CONV_FLAG"];
                    spdAllLotList.ActiveSheet.Cells[num, 26].Value = dt.Rows[num]["OUTSOURCEING_ORDER"];
                    spdAllLotList.ActiveSheet.Cells[num, 37].Value = dt.Rows[num]["START_RES_ID"];
                    spdAllLotList.ActiveSheet.Cells[num, 38].Value = dt.Rows[num]["START_RES_DESC"];
                    spdAllLotList.ActiveSheet.Cells[num, 39].Value = dt.Rows[num]["WORK_TYPE"];
                    spdAllLotList.ActiveSheet.Cells[num, 40].Value = dt.Rows[num]["WORK_TYPE_DESC"];
                    spdAllLotList.ActiveSheet.Cells[num, 41].Value = dt.Rows[num]["AREA_ID"];
                    spdAllLotList.ActiveSheet.Cells[num, 42].Value = dt.Rows[num]["AREA_DESC"];
                    spdAllLotList.ActiveSheet.Cells[num, 43].Value = dt.Rows[num]["SUB_AREA_ID"];
                    spdAllLotList.ActiveSheet.Cells[num, 44].Value = dt.Rows[num]["SUB_AREA_DESC"];
                    spdAllLotList.ActiveSheet.Cells[num, 45].Value = dt.Rows[num]["ORDER_STATUS"];
                    spdAllLotList.ActiveSheet.Cells[num, 46].Value = dt.Rows[num]["INPUT_STATUS"];
                    spdAllLotList.ActiveSheet.Cells[num, 47].Value = dt.Rows[num]["GROUP_ID"];
                    spdAllLotList.ActiveSheet.Cells[num, 48].Value = dt.Rows[num]["CREATE_TIME"];
                    spdAllLotList.ActiveSheet.Cells[num, 49].Value = dt.Rows[num]["INSP_RESULT_DESC"];
                    spdAllLotList.ActiveSheet.Cells[num, 50].Value = dt.Rows[num]["REL_LEVEL"];
                    spdAllLotList.ActiveSheet.Cells[num, 51].Value = dt.Rows[num]["REL_DESC"];
                    spdAllLotList.ActiveSheet.Cells[num, 52].Value = dt.Rows[num]["LDM_DESC"];
                    spdAllLotList.ActiveSheet.Cells[num, 35].Value = dt.Rows[num]["LAST_COMMENT"];
                    spdAllLotList.ActiveSheet.Cells[num, 54].Value = dt.Rows[num]["INV_FLAG"];
                    spdAllLotList.ActiveSheet.Cells[num, 56].Value = dt.Rows[num]["ORG_LOT_ID"];
                    spdAllLotList.ActiveSheet.Cells[num, 57].Value = dt.Rows[num]["CUSTOMER_NAME"];
                    spdAllLotList.ActiveSheet.Cells[num, 58].Value = dt.Rows[num]["DELIVERY_NAME"];
                    spdAllLotList.ActiveSheet.Cells[num, 59].Value = dt.Rows[num]["PACK_ORDER_ID"];
                    spdAllLotList.ActiveSheet.Cells[num, 60].Value = dt.Rows[num]["PACK_LINE_NO"];
                    spdAllLotList.ActiveSheet.Cells[num, 61].Value = dt.Rows[num]["ERP_PACK_ORDER_ID"];
                    spdAllLotList.ActiveSheet.Cells[num, 73].Value = dt.Rows[num]["OPER_GRP_1"];
                    spdAllLotList.ActiveSheet.Cells[num, 62].Value = dt.Rows[num]["LABEL_NAME"];
                    spdAllLotList.ActiveSheet.Cells[num, 63].Value = dt.Rows[num]["PACKING_INSTRUCTIONS"];
                    spdAllLotList.ActiveSheet.Cells[num, 74].Value = dt.Rows[num]["CREATE_CODE"];
                    spdAllLotList.ActiveSheet.Cells[num, 75].Value = dt.Rows[num]["CREATE_CODE_DESC"];
                    spdAllLotList.ActiveSheet.Cells[num, 76].Value = dt.Rows[num]["TABLE_NAME"];
                    spdAllLotList.ActiveSheet.Cells[num, 33].Value = dt.Rows[num]["FIXED_COMMENT"];
                    spdAllLotList.ActiveSheet.Cells[num, 55].Value = dt.Rows[num]["PACK_DATE"];
                    spdAllLotList.ActiveSheet.Cells[num, 65].Value = dt.Rows[num]["SHIP_DATE"];
                    spdAllLotList.ActiveSheet.Cells[num, 66].Value = dt.Rows[num]["SHIP_ORDER_ID"];
                    spdAllLotList.ActiveSheet.Cells[num, 67].Value = dt.Rows[num]["SHIP_ORDER_SEQ"];
                    spdAllLotList.ActiveSheet.Cells[num, 68].Value = dt.Rows[num]["RET_DATE"];
                    spdAllLotList.ActiveSheet.Cells[num, 69].Value = dt.Rows[num]["RET_ORDER_ID"];
                    spdAllLotList.ActiveSheet.Cells[num, 70].Value = dt.Rows[num]["RET_LINE_NO"];
                    spdAllLotList.ActiveSheet.Cells[num, 27].Value = dt.Rows[num]["RECV_DATE"];
                    spdAllLotList.ActiveSheet.Cells[num, 28].Value = dt.Rows[num]["VENDOR_ID"];
                    spdAllLotList.ActiveSheet.Cells[num, 29].Value = dt.Rows[num]["VENDOR_DESC"];
                    spdAllLotList.ActiveSheet.Cells[num, 30].Value = dt.Rows[num]["VENDOR_SITE_ID"];
                    spdAllLotList.ActiveSheet.Cells[num, 31].Value = dt.Rows[num]["VENDOR_LOT_ID"];
                    spdAllLotList.ActiveSheet.Cells[num, 77].Value = dt.Rows[num]["ERP_OPER"];
                    spdAllLotList.ActiveSheet.Cells[num, 78].Value = dt.Rows[num]["WIP_INV"];
                    spdAllLotList.ActiveSheet.Cells[num, 71].Value = dt.Rows[num]["ACTUAL_MAT_ID"];
                    spdAllLotList.ActiveSheet.Cells[num, 72].Value = dt.Rows[num]["ACTUAL_MAT_DESC"];
                }
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
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }
                if (CHECK != CSGC.CHECK.VIEW)
                {
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
                        cdvWorkPlace.Text = "";
                        cdvOper.Text = "";
                        cdvOrder.Text = "";
                        cdvMatType.Text = "";
                        cdvMat.Text = "";
                        cdvLabel.Text = "";
                        txtLotID.Text = "";
                        cdvInvYN.Text = "";
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdwLotList);
                        break;
                    case "VIEW":
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdwLotList);
                        break;
                    case "AREA":
                        cdvWorkPlace.Text = "";
                        cdvOper.Text = "";
                        cdvOrder.Text = "";
                        cdvMatType.Text = "";
                        cdvMat.Text = "";
                        cdvLabel.Text = "";
                        txtLotID.Text = "";
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdwLotList);
                        break;
                    case "SUB_AREA":
                        cdvOper.Text = "";
                        cdvOrder.Text = "";
                        cdvMatType.Text = "";
                        cdvMat.Text = "";
                        txtLotID.Text = "";
                        MPCF.ClearList(spdLotList);
                        break;
                    case "OPER":
                        cdvOrder.Text = "";
                        cdvMatType.Text = "";
                        cdvMat.Text = "";
                        txtLotID.Text = "";
                        cdvLabel.Text = "";
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdwLotList);
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool ViewPrintShipLabel(string sFileName, TRSNode in_node)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "KEY_1";
                array[1].sCondition_Value = cdvDept.Text;
                if (!TPDR.GetDataOne("", ref dt, "CSHP2001-010", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    return false;
                }
                sFileName = dt.Rows[0]["KEY_2"].ToString();
                if (dt.Rows[0]["DATA_2"].ToString() == "OPER")
                {
                    CSCF.ViewLabelList(sFileName, in_node);
                }
                else
                {
                    CSCF.ViewLabelList(sFileName, in_node, 'E');
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private DataTable GetOperInfo(string sOper)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "OPER";
                array[1].sCondition_Value = sOper;
                if (!TPDR.GetDataOne("", ref dt, "CWIP3007-003", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                }
                return dt;
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        private bool Update_Lot_Comment(int i)
        {
            TRSNode tRSNode = new TRSNode("Update_Lot_Commnet_In");
            TRSNode out_node = new TRSNode("Update_Lot_Commnet_Out");
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("LOT_ID", spdLotList_Sheet1.Cells[i, 2].Text);
                tRSNode.AddString("LOT_DESC", spdLotList_Sheet1.Cells[i, 9].Text);
                if (!MPCR.CallService("CUS_WIP", "CUS_WIP_Update_Lot_Comment", tRSNode, ref out_node))
                {
                    return false;
                }
                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private bool Update_W_Lot_Comment(int i)
        {
            TRSNode tRSNode = new TRSNode("Update_Lot_Commnet_In");
            TRSNode out_node = new TRSNode("Update_Lot_Commnet_Out");
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("LOT_ID", spdwLotList_Sheet1.Cells[i, 2].Text);
                tRSNode.AddString("LOT_DESC", spdwLotList_Sheet1.Cells[i, 9].Text);
                if (!MPCR.CallService("CUS_WIP", "CUS_WIP_Update_Lot_Comment", tRSNode, ref out_node))
                {
                    return false;
                }
                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private bool Update_ALL_Lot_TRAN_Comment(int i, char sProc)
        {
            TRSNode tRSNode = new TRSNode("Update_Lot_Commnet_In");
            TRSNode out_node = new TRSNode("Update_Lot_Commnet_Out");
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = sProc;
                tRSNode.AddString("LOT_ID", spdAllLotList_Sheet1.Cells[i, 1].Text);
                if (sProc == '1')
                {
                    tRSNode.AddString("LOT_DESC", spdAllLotList_Sheet1.Cells[i, 35].Text);
                }
                else
                {
                    tRSNode.AddString("COMMENT_1", spdAllLotList_Sheet1.Cells[i, 33].Text);
                }
                if (!MPCR.CallService("CUS_WIP", "CUS_WIP_Update_Lot_Comment", tRSNode, ref out_node))
                {
                    return false;
                }
                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private bool Update_Inv_data_update(int i, char sProc)
        {
            TRSNode tRSNode = new TRSNode("Update_Inv_data_In");
            TRSNode out_node = new TRSNode("Update_Inv_data__Out");
            if (spdAllLotList_Sheet1.Cells[i, 27].Text.Trim() == "")
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(570) + " [" + spdAllLotList_Sheet1.Cells[i, 1].Text + "]");
            }
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = sProc;
                tRSNode.AddString("INV_LOT_ID", spdAllLotList_Sheet1.Cells[i, 1].Text);
                if (sProc == '1')
                {
                    tRSNode.AddString("VENDOR_LOT_ID", spdAllLotList_Sheet1.Cells[i, 31].Text);
                }
                if (!MPCR.CallService("CUS_INV", "CUS_INV_Update_inv_data_update", tRSNode, ref out_node))
                {
                    return false;
                }
                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private void tabselect()
        {
            try
            {
                if (tbOperType.SelectedIndex == 0)
                {
                    lblWorkPlace.Visible = true;
                    cdvWorkPlace.Visible = true;
                    cdvWorkPlace.Enabled = true;
                    rdoAll.Visible = false;
                    rdoOperation.Visible = false;
                    rdoWareHouse.Visible = false;
                    btnPrint.Enabled = true;
                    btnSave.Enabled = true;
                    cdvLabel.Enabled = true;
                    cdvLabel.Text = "";
                    iTabIndex = 0;
                }
                else if (tbOperType.SelectedIndex == 1)
                {
                    lblWorkPlace.Visible = true;
                    cdvWorkPlace.Visible = true;
                    cdvWorkPlace.Enabled = false;
                    rdoAll.Visible = false;
                    rdoOperation.Visible = false;
                    rdoWareHouse.Visible = false;
                    btnPrint.Enabled = true;
                    btnSave.Enabled = true;
                    cdvLabel.Enabled = true;
                    cdvLabel.Text = "";
                    iTabIndex = 1;
                }
                else if (tbOperType.SelectedIndex == 2)
                {
                    lblWorkPlace.Visible = false;
                    cdvWorkPlace.Visible = false;
                    cdvWorkPlace.Enabled = false;
                    rdoAll.Visible = true;
                    rdoOperation.Visible = true;
                    rdoWareHouse.Visible = true;
                    btnPrint.Enabled = true;
                    btnSave.Enabled = true;
                    cdvLabel.Enabled = true;
                    cdvLabel.Text = "";
                    iTabIndex = 2;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void changeDecimalpoint()
        {
            NumberCellType numberCellType = new NumberCellType();
            if (chkfixDecPoint.Checked)
            {
                numberCellType.DecimalPlaces = MPCF.ToInt(cbdDecimalPlace.Text);
                numberCellType.FixedPoint = true;
                spdLotList_Sheet1.Columns.Get(7).CellType = numberCellType;
                spdwLotList_Sheet1.Columns.Get(7).CellType = numberCellType;
            }
            else
            {
                numberCellType.DecimalPlaces = MPCF.ToInt(cbdDecimalPlace.Text);
                numberCellType.FixedPoint = false;
                spdLotList_Sheet1.Columns.Get(7).CellType = numberCellType;
                spdwLotList_Sheet1.Columns.Get(7).CellType = numberCellType;
            }
        }

        private void LotLoadPopUp(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }
                frmWIPViewMaterialInputStatus frmWIPViewMaterialInputStatus2 = new frmWIPViewMaterialInputStatus();
                frmWIPViewMaterialInputStatus2.StartPosition = FormStartPosition.CenterParent;
                if (frmWIPViewMaterialInputStatus2.ShowDialog() == DialogResult.OK)
                {
                    frmWIPViewMaterialInputStatus2 = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool LotChange()
        {
            try
            {
                TRSNode tRSNode = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                int num = 0;
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '2';
                num = spdAllLotList.ActiveSheet.ActiveRowIndex;
                tRSNode.AddString("LOT_ID", spdAllLotList.ActiveSheet.Cells[num, 1].Text);
                tRSNode.AddString("CHILD_LOT_ID", spdAllLotList.ActiveSheet.Cells[num, 12].Text.Trim());
                tRSNode.AddString("CHILD_LOT_DESC", spdAllLotList.ActiveSheet.Cells[num, 12].Text.Trim());
                tRSNode.AddDouble("MOVE_QTY_1", MPCF.ToDbl(spdAllLotList.ActiveSheet.Cells[num, 20].Text));
                tRSNode.AddString("CHILD_LOT_DESC", spdAllLotList.ActiveSheet.Cells[num, 35].Text);
                tRSNode.AddDouble("PRE_QTY_1", MPCF.ToDbl(spdAllLotList.ActiveSheet.Cells[num, 20].Text));
                tRSNode.AddString("RESV_FIELD_3", spdAllLotList.ActiveSheet.Cells[num, 12].Text);
                if (!MPCR.CallService("CUS_WIP", "CUS_WIP_Split_Wip_Lot", tRSNode, ref out_node))
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
                ViewAllLotList();
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool LotINVChange()
        {
            try
            {
                TRSNode tRSNode = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                MPCR.SetInMsg(tRSNode);
                int activeRowIndex = spdAllLotList.ActiveSheet.ActiveRowIndex;
                tRSNode.ProcStep = '1';
                tRSNode.AddString("INV_LOT_ID", spdAllLotList.ActiveSheet.Cells[activeRowIndex, 1].Text);
                tRSNode.AddString("SPLIT_LOT_ID", spdAllLotList.ActiveSheet.Cells[activeRowIndex, 12].Text);
                tRSNode.AddDouble("SPLIT_QTY", MPCF.ToDbl(spdAllLotList.ActiveSheet.Cells[activeRowIndex, 20].Text));
                if (!MPCR.CallService("CUS_INV", "CUS_INV_Split_Lot", tRSNode, ref out_node))
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
                ViewAllLotList();
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool WipLotHold(string sLotId, string sComment)
        {
            TRSNode tRSNode = new TRSNode("HOLD_LOT_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("LOT_ID", MPCF.Trim(sLotId));
                tRSNode.AddString("HOLD_CODE", MPCF.Trim("INTERLOCK"));
                tRSNode.AddString("COMMENT", MPCF.Trim(sComment));
                if (!MPCR.CallService("CUS_WIP", "CUS_WIP_Hold_Lot", tRSNode, ref out_node))
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool InvLotHold(string sLotId, string sComment)
        {
            try
            {
                TRSNode tRSNode = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                TRSNode tRSNode2 = tRSNode.AddNode("INV_LOT_LIST");
                tRSNode2.AddString("INV_LOT_ID", MPCF.Trim(sLotId));
                tRSNode.AddString("HOLD_CODE", "H1");
                tRSNode.AddString("TRAN_COMMENT", MPCF.Trim(sComment));
                if (!MPCR.CallService("CUS_INV", "CUS_INV_Hold_Lot", tRSNode, ref out_node))
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool InvLotRelease(string sLotId, string sComment)
        {
            try
            {
                TRSNode tRSNode = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                TRSNode tRSNode2 = tRSNode.AddNode("INV_LOT_LIST");
                tRSNode2.AddString("INV_LOT_ID", MPCF.Trim(sLotId));
                tRSNode.AddString("RELEASE_CODE", "R1");
                tRSNode.AddString("TRAN_COMMENT", MPCF.Trim(sComment));
                if (!MPCR.CallService("CUS_INV", "CUS_INV_Release_Lot", tRSNode, ref out_node))
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool WipLotRelease(string sLotId, string sComment)
        {
            TRSNode tRSNode = new TRSNode("RELEASE_LOT_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");
            try
            {
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("LOT_ID", MPCF.Trim(sLotId));
                tRSNode.AddString("RELEASE_CODE", MPCF.Trim("OPERACTION"));
                tRSNode.AddString("COMMENT", MPCF.Trim(sComment));
                if (!MPCR.CallService("CUS_WIP", "CUS_WIP_Release_Lot", tRSNode, ref out_node))
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void LotSplitepop(string sLotId)
        {
            try
            {
                frmTranSplitLot frmTranSplitLot2 = new frmTranSplitLot();
                if (spdAllLotList_Sheet1.ActiveRowIndex >= 0)
                {
                    frmTranSplitLot2.txtLotID.Text = sLotId;
                }
                if (frmTranSplitLot2.ShowDialog() == DialogResult.OK)
                {
                    ViewAllLotList();
                    frmTranSplitLot2 = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void LotMergeepop(string sLotId)
        {
            try
            {
                frmTranMergeLot frmTranMergeLot2 = new frmTranMergeLot();
                if (spdAllLotList_Sheet1.ActiveRowIndex >= 0)
                {
                    frmTranMergeLot2.txtLotID.Text = sLotId;
                }
                if (frmTranMergeLot2.ShowDialog() == DialogResult.OK)
                {
                    ViewAllLotList();
                    frmTranMergeLot2 = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void LotReturnpop(string sLotId)
        {
            try
            {
                frmTranDeleteLotHistory_NEW frmTranDeleteLotHistory_NEW2 = new frmTranDeleteLotHistory_NEW();
                if (spdAllLotList_Sheet1.ActiveRowIndex >= 0)
                {
                    frmTranDeleteLotHistory_NEW2.g_LotId = sLotId;
                    frmTranDeleteLotHistory_NEW2.g_popYn = "Y";
                }
                if (frmTranDeleteLotHistory_NEW2.ShowDialog() == DialogResult.OK)
                {
                    ViewAllLotList();
                    frmTranDeleteLotHistory_NEW2 = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void LotUnloadpop(string sLotId)
        {
            try
            {
                frmWIPViewMaterialInputStatus frmWIPViewMaterialInputStatus2 = new frmWIPViewMaterialInputStatus();
                if (spdAllLotList_Sheet1.ActiveRowIndex >= 0)
                {
                    frmWIPViewMaterialInputStatus2.g_Inv_LotId = sLotId;
                    frmWIPViewMaterialInputStatus2.g_PopYn = "Y";
                    frmWIPViewMaterialInputStatus2.g_Dept = cdvDept.Text;
                    frmWIPViewMaterialInputStatus2.g_DeptDisplay = cdvDept.DisplayText;
                }
                if (frmWIPViewMaterialInputStatus2.ShowDialog() == DialogResult.OK)
                {
                    ViewAllLotList();
                    frmWIPViewMaterialInputStatus2 = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void LotProcesspop(string sLotId)
        {
            try
            {
                frmTranMultiProcessLot frmTranMultiProcessLot2 = new frmTranMultiProcessLot();
                if (spdAllLotList_Sheet1.ActiveRowIndex >= 0 && spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 76].Text == "MWIPLOTSTS" && spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 78].Text == "WIP")
                {
                    frmTranMultiProcessLot2.g_Lot_ID = sLotId;
                    frmTranMultiProcessLot2.g_PopYn = "Y";
                }
                if (frmTranMultiProcessLot2.ShowDialog() == DialogResult.OK)
                {
                    ViewAllLotList();
                    frmTranMultiProcessLot2 = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void LotMatChangepop(string sLotId)
        {
            try
            {
                frmTranChangeItem frmTranChangeItem2 = new frmTranChangeItem();
                if (spdAllLotList_Sheet1.ActiveRowIndex >= 0 && spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 76].Text == "MWIPLOTSTS" && spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 78].Text == "INV")
                {
                    frmTranChangeItem2.txtBeforeLotID.Text = sLotId;
                    frmTranChangeItem2.cdvBeforeMatId.Text = spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 18].Text;
                    frmTranChangeItem2.cdvBeforeMatId.DisplayText = spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 19].Text;
                    frmTranChangeItem2.cdvDept.DisplayText = cdvDept.Text;
                    frmTranChangeItem2.cdvOper.Text = spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 2].Text;
                }
                if (frmTranChangeItem2.ShowDialog() == DialogResult.OK)
                {
                    ViewAllLotList();
                    frmTranChangeItem2 = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void LotMatMovepop(string sLotId)
        {
            try
            {
                frmTranMoveOrderRegistration frmTranMoveOrderRegistration2 = new frmTranMoveOrderRegistration();
                if (frmTranMoveOrderRegistration2.ShowDialog() == DialogResult.OK)
                {
                    ViewAllLotList();
                    frmTranMoveOrderRegistration2 = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmWIPViewOperLotList_Load(object sender, EventArgs e)
        {
            try
            {
                iTabIndex = 0;
                cdvOrderType.Text = "PROD";
                cdvOrderType.DisplayText = "Product Lot";
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
                cdvDept.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvDept.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvDept.SelectedSubItemIndex = 0;
                cdvDept.DisplaySubItemIndex = 1;
                if (!BASLIST.ViewGCMDataList(cdvDept.GetListView, '1', "AREA") || !(MPCF.Trim(cdvDept.Tag) != ""))
                {
                    return;
                }
                for (int num = cdvDept.GetListView.Items.Count; num > 0; num--)
                {
                    if (cdvDept.GetListView.Items[num - 1].SubItems[0].Text != cdvDept.Tag.ToString())
                    {
                        cdvDept.GetListView.Items[num - 1].Remove();
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                ClearData("AREA");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkPlace_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }
                cdvWorkPlace.Init();
                MPCF.InitListView(cdvWorkPlace.GetListView);
                cdvWorkPlace.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvWorkPlace.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvWorkPlace.SelectedSubItemIndex = 0;
                cdvWorkPlace.DisplaySubItemIndex = 1;
                if (!BASLIST.ViewGCMDataList_AREA(cdvWorkPlace.GetListView, '1', "SUB_AREA", -1, null, "", bIgnoreError: true, -1, -1, null, cdvDept.Text))
                {
                    return;
                }
                if (MPCF.Trim(cdvWorkPlace.Tag) != "")
                {
                    for (int num = cdvWorkPlace.GetListView.Items.Count; num > 0; num--)
                    {
                        if (cdvWorkPlace.GetListView.Items[num - 1].SubItems[0].Text != cdvWorkPlace.Tag.ToString())
                        {
                            cdvWorkPlace.GetListView.Items[num - 1].Remove();
                        }
                    }
                }
                cdvWorkPlace.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkPlace_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                ClearData("SUB_AREA");
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
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                }
                else if (tbOperType.SelectedIndex == 0)
                {
                    if (MPCF.Trim(cdvWorkPlace.Text) == "")
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                        cdvWorkPlace.Focus();
                        return;
                    }
                    cdvOper.Init();
                    MPCF.InitListView(cdvOper.GetListView);
                    cdvOper.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                    cdvOper.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                    cdvOper.SelectedSubItemIndex = 0;
                    cdvOper.DisplaySubItemIndex = 1;
                    if (COM_LIST.ViewOperationList(cdvOper.GetListView, 'I', cdvDept.Text, cdvWorkPlace.Text))
                    {
                        cdvOper.InsertEmptyRow(0, 1);
                    }
                }
                else if (tbOperType.SelectedIndex == 1)
                {
                    cdvOper.Init();
                    MPCF.InitListView(cdvOper.GetListView);
                    cdvOper.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                    cdvOper.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                    cdvOper.SelectedSubItemIndex = 0;
                    cdvOper.DisplaySubItemIndex = 1;
                    if (COM_LIST.ViewOperationList(cdvOper.GetListView, 'R', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y'))
                    {
                        cdvOper.InsertEmptyRow(0, 1);
                    }
                }
                else
                {
                    if (tbOperType.SelectedIndex != 2)
                    {
                        return;
                    }
                    TRSNode tRSNode = new TRSNode("SQL_IN");
                    TRSNode out_node = new TRSNode("SQL_OUT");
                    MPCF.InitListView(cdvOper.GetListView);
                    MPCR.SetInMsg(tRSNode);
                    tRSNode.ProcStep = '1';
                    string text = "";
                    text = (rdoOperation.Checked ? " AND OPER_CMF_12 = 'WIP' " : ((!rdoWareHouse.Checked) ? "   " : " AND OPER_CMF_12 = 'INV' "));
                    tRSNode.AddString("SQL", "SELECT OPER AS CODE       ,OPER_DESC AS VALUE FROM MWIPOPRDEF  WHERE FACTORY ='" + MPGV.gsFactory + "' AND AREA_ID = '" + cdvDept.Text + "' " + text + " ORDER BY 1,2");
                    do
                    {
                        if (!MPCR.CallService("BAS", "BAS_SQL_Query", tRSNode, ref out_node))
                        {
                            return;
                        }
                        MPCR.FillDataView(cdvOper.GetListView, out_node);
                        tRSNode.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
                    }
                    while (out_node.GetInt("NEXT_ROW") > 0);
                    cdvOper.InsertEmptyRow(0, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOper_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                ClearData("OPER");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader && e.Column == 0)
                {
                    CSCF.CheckSpreadCell(spdLotList, 0, 0, b_checked: true, b_isColHeaderCheckBox: true);
                }
                if (!e.ColumnHeader && !e.ColumnFooter)
                {
                    EXTFUC.SetSelectRowColor(spdLotList, e.Row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdwLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader && e.Column == 0)
                {
                    CSCF.CheckSpreadCell(spdwLotList, 0, 0, b_checked: true, b_isColHeaderCheckBox: true);
                }
                if (!e.ColumnHeader && !e.ColumnFooter)
                {
                    EXTFUC.SetSelectRowColor(spdwLotList, e.Row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOrder_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }

                CUS_COM.Popup.frmPopWorkOrderList popup = new CUS_COM.Popup.frmPopWorkOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_AreaCode = cdvDept.Text;
                popup.g_AreaDesc = cdvDept.DisplayText;
                popup.g_SubAreaCode = cdvWorkPlace.Text;
                popup.g_SubAreaDesc = cdvWorkPlace.DisplayText;
                popup.g_OperCode = cdvOper.Text;
                popup.g_OperDesc = cdvOper.DisplayText;
                popup.g_WorkOrder = cdvOrder.Text;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvOrder.Text = popup.g_WorkOrder;
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


        private void cdvMatType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvMatType.Init();
                MPCF.InitListView(cdvMatType.GetListView);
                cdvMatType.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvMatType.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvMatType.SelectedSubItemIndex = 0;
                cdvMatType.DisplaySubItemIndex = 1;
                if (BASLIST.ViewGCMDataList(cdvMatType.GetListView, '1', "MATERIAL_TYPE"))
                {
                    cdvMatType.InsertEmptyRow(0, 1);
                }
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
                frmPopMaterialList frmPopMaterialList = new frmPopMaterialList();
                frmPopMaterialList.StartPosition = FormStartPosition.CenterParent;
                frmPopMaterialList.sArea_id = cdvDept.Text;
                frmPopMaterialList.sArea_desc = cdvDept.DisplayText;
                if (frmPopMaterialList.ShowDialog() == DialogResult.OK)
                {
                    cdvMat.Text = frmPopMaterialList.sMat_id;
                    txtMatDesc.Text = frmPopMaterialList.sMat_Desc;
                    frmPopMaterialList = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvInvYN_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvInvYN.Init();
                MPCF.InitListView(cdvInvYN.GetListView);
                cdvInvYN.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvInvYN.SelectedSubItemIndex = 0;
                if (BASLIST.ViewGCMDataList(cdvInvYN.GetListView, '1', "YESNO"))
                {
                    cdvInvYN.InsertEmptyRow(0, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvLabel_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }
                cdvLabel.Init();
                MPCF.InitListView(cdvLabel.GetListView);
                cdvLabel.Columns.Add("Size", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvLabel.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvLabel.Columns.Add("Code", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvLabel.SelectedSubItemIndex = 2;
                cdvLabel.DisplaySubItemIndex = 1;
                string sLabelType = "OPER";
                if (COM_LIST.ViewLabelGCMList(cdvLabel.GetListView, cdvDept.Text, sLabelType))
                {
                    cdvLabel.InsertEmptyRow(0, 1);
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
                if (e.KeyChar == '\r')
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void tbOperType_SelectedIndexChanged(object sender, EventArgs e)
        {
            tabselect();
        }

        private void spdwLotList_EditModeStarting(object sender, EditModeStartingEventArgs e)
        {
            if (spdwLotList_Sheet1.ActiveColumnIndex != 0)
            {
                spdwLotList_Sheet1.Cells[spdwLotList_Sheet1.ActiveRowIndex, 0].Value = true;
            }
        }

        private void spdAllLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader && spdAllLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdAllLotList, e.Row, e.Column, b_checked: true, b_isColHeaderCheckBox: true);
                }
                if (!e.ColumnHeader && !e.ColumnFooter)
                {
                    EXTFUC.SetSelectRowColor(spdAllLotList, e.Row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdAllLotList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            string text = "";
            string text2 = "";
            try
            {
                switch (e.Column)
                {
                    case 4:
                        if (spdAllLotList_Sheet1.ActiveRowIndex >= 0)
                        {
                            LotProcesspop(spdAllLotList_Sheet1.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 1].Text);
                        }
                        break;
                    case 6:
                        if (spdAllLotList_Sheet1.ActiveRowIndex >= 0)
                        {
                            LotMatChangepop(spdAllLotList_Sheet1.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 1].Text);
                        }
                        break;
                    case 5:
                        if (spdAllLotList_Sheet1.ActiveRowIndex >= 0)
                        {
                            LotMatMovepop(spdAllLotList_Sheet1.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 1].Text);
                        }
                        break;
                    case 7:
                        if (spdAllLotList_Sheet1.ActiveRowIndex >= 0)
                        {
                            LotMergeepop(spdAllLotList_Sheet1.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 1].Text);
                        }
                        break;
                    case 9:
                        if (spdAllLotList_Sheet1.ActiveRowIndex >= 0)
                        {
                            LotReturnpop(spdAllLotList_Sheet1.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 1].Text);
                        }
                        break;
                    case 8:
                        if (spdAllLotList_Sheet1.ActiveRowIndex >= 0)
                        {
                            LotSplitepop(spdAllLotList_Sheet1.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 1].Text);
                        }
                        break;
                    case 13:
                        if (MPCF.Trim(spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 12].Text).Length == 0 || MPCF.ShowMsgBox(MPCF.GetMessage(571), MessageBoxButtons.YesNo, 2) == DialogResult.No)
                        {
                            break;
                        }
                        if (spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 76].Text == "MWIPLOTSTS")
                        {
                            if (LotChange())
                            {
                            }
                        }
                        else if (LotINVChange())
                        {
                        }
                        break;
                    case 36:
                        Update_ALL_Lot_TRAN_Comment(spdAllLotList_Sheet1.ActiveRowIndex, '1');
                        break;
                    case 34:
                        Update_ALL_Lot_TRAN_Comment(spdAllLotList_Sheet1.ActiveRowIndex, '2');
                        break;
                    case 32:
                        Update_Inv_data_update(spdAllLotList_Sheet1.ActiveRowIndex, '1');
                        break;
                    case 53:
                        if (spdAllLotList_Sheet1.ActiveRowIndex >= 0)
                        {
                            LotUnloadpop(spdAllLotList_Sheet1.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 1].Text);
                        }
                        break;
                    case 11:
                        text = spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 1].Text;
                        text2 = spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 35].Text;
                        if (spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 76].Text == "MWIPLOTSTS")
                        {
                            if (spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 10].Text == "Y")
                            {
                                if (WipLotRelease(text, text2))
                                {
                                    spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 10].Text = "N";
                                }
                            }
                            else if (WipLotHold(text, text2))
                            {
                                spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 10].Text = "Y";
                            }
                        }
                        else if (spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 10].Text == "Y")
                        {
                            if (InvLotRelease(text, text2))
                            {
                                spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 10].Text = "N";
                            }
                        }
                        else if (InvLotHold(text, text2))
                        {
                            spdAllLotList.ActiveSheet.Cells[spdAllLotList_Sheet1.ActiveRowIndex, 10].Text = "Y";
                        }
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOrderType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOrderType.Init();
                MPCF.InitListView(cdvOrderType.GetListView);
                cdvOrderType.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOrderType.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOrderType.SelectedSubItemIndex = 0;
                cdvOrderType.DisplaySubItemIndex = 1;
                if (BASLIST.ViewGCMDataList(cdvOrderType.GetListView, '1', "CREATE_CODE"))
                {
                    cdvOrderType.InsertEmptyRow(0, 1);
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
                if (CheckCondition(CSGC.CHECK.VIEW))
                {
                    if (tbOperType.SelectedIndex == 0)
                    {
                        ViewOperLotList();
                    }
                    else if (tbOperType.SelectedIndex == 1)
                    {
                        ViewWareHouseLotList();
                    }
                    else if (tbOperType.SelectedIndex == 2)
                    {
                        ViewAllLotList();
                    }
                    tbOperType.SelectedIndex = iTabIndex;
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
                string empty = string.Empty;
                if (tbOperType.SelectedIndex == 0)
                {
                    empty = (string.IsNullOrEmpty(cdvOper.DisplayText) ? "Operation" : cdvOper.DisplayText);
                    EXTFUC.SaveExcel(spdLotList, empty);
                }
                else if (tbOperType.SelectedIndex == 1)
                {
                    empty = (string.IsNullOrEmpty(cdvOper.DisplayText) ? "Warehouse" : cdvOper.DisplayText);
                    EXTFUC.SaveExcel(spdwLotList, empty);
                }
                else if (tbOperType.SelectedIndex == 2)
                {
                    empty = (string.IsNullOrEmpty(cdvOper.DisplayText) ? "Warehouse" : cdvOper.DisplayText);
                    EXTFUC.SaveExcel2(spdAllLotList, empty);
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvLabel.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLabel.Text + "]");
                    cdvLabel.Focus();
                    return;
                }
                TRSNode tRSNode = new TRSNode("print_label_In");
                List<string> list = new List<string>();
                bool flag = false;
                MPCR.SetInMsg(tRSNode);
                if (tbOperType.SelectedIndex == 0)
                {
                    for (int i = 0; i < spdLotList_Sheet1.RowCount; i++)
                    {
                        if (spdLotList_Sheet1.Cells[i, 0].Value.ToString().ToUpper() == "TRUE")
                        {
                            TRSNode tRSNode2 = tRSNode.AddNode("LOT_LIST");
                            tRSNode2.AddString("LOT_ID", spdLotList_Sheet1.Cells[i, 2].Text);
                            if (MPCF.Trim(spdLotList_Sheet1.Cells[i, 18].Text) != "" && !list.Contains(spdLotList_Sheet1.Cells[i, 18].Text))
                            {
                                list.Add(spdLotList_Sheet1.Cells[i, 18].Text);
                                tRSNode2 = tRSNode.AddNode("GROUP_LIST");
                                tRSNode2.AddString("GROUP_ID", spdLotList_Sheet1.Cells[i, 18].Text);
                                tRSNode2 = tRSNode.AddNode("CELL_LIST");
                                tRSNode2.AddString("GROUP_ID", spdLotList_Sheet1.Cells[i, 18].Text);
                            }
                            flag = true;
                        }
                    }
                    if (flag)
                    {
                        if (cdvLabel.Text == "mtl100p")
                        {
                            CSCF.ViewLabelList(cdvLabel.Text, tRSNode, 'T');
                        }
                        else
                        {
                            CSCF.ViewLabelList(cdvLabel.Text, tRSNode);
                        }
                    }
                }
                else if (tbOperType.SelectedIndex == 1)
                {
                    for (int j = 0; j < spdwLotList_Sheet1.RowCount; j++)
                    {
                        if (spdwLotList_Sheet1.Cells[j, 0].Value.ToString().ToUpper() == "TRUE")
                        {
                            TRSNode tRSNode2 = tRSNode.AddNode("LOT_LIST");
                            tRSNode2.AddString("LOT_ID", spdwLotList_Sheet1.Cells[j, 2].Text);
                            flag = true;
                        }
                    }
                    if (flag)
                    {
                        ViewPrintShipLabel(cdvLabel.Text, tRSNode);
                    }
                }
                tbOperType.SelectedIndex = iTabIndex;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            int num = 0;
            if (tbOperType.SelectedIndex == 0)
            {
                if (spdLotList_Sheet1.RowCount > 0)
                {
                    for (int i = 0; i < spdLotList_Sheet1.RowCount; i++)
                    {
                        if (Convert.ToBoolean(spdLotList_Sheet1.Cells[i, 0].Value))
                        {
                            if (!Update_Lot_Comment(i))
                            {
                                return;
                            }
                            spdLotList_Sheet1.Cells[i, 0].Value = false;
                            num++;
                        }
                    }
                    if (num == 0)
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(133));
                        return;
                    }
                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                }
                tbOperType.SelectedIndex = iTabIndex;
                return;
            }
            if (spdwLotList_Sheet1.RowCount > 0)
            {
                for (int j = 0; j < spdwLotList_Sheet1.RowCount; j++)
                {
                    if (Convert.ToBoolean(spdwLotList_Sheet1.Cells[j, 0].Value))
                    {
                        if (!Update_W_Lot_Comment(j))
                        {
                            return;
                        }
                        spdwLotList_Sheet1.Cells[j, 0].Value = false;
                        num++;
                    }
                }
                if (num == 0)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(133));
                    return;
                }
                MPCF.ShowMsgBox(MPCF.GetMessage(52));
            }
            tbOperType.SelectedIndex = iTabIndex;
        }

        private void spdLotList_EditModeStarting(object sender, EditModeStartingEventArgs e)
        {
            if (spdLotList_Sheet1.ActiveColumnIndex != 0)
            {
                spdLotList_Sheet1.Cells[spdLotList_Sheet1.ActiveRowIndex, 0].Value = true;
            }
        }

        private void cdvMat_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMat.DisplayText == "")
            {
                cdvMat.Text = "";
            }
        }

        private void cdvInvYN_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvInvYN.DisplayText == "")
            {
                cdvInvYN.Text = "";
            }
        }

        private void cdvMatType_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatType.DisplayText == "")
            {
                cdvMatType.Text = "";
            }
        }

        private void cdvOrder_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvOrder.DisplayText == "")
            {
                cdvOrder.Text = "";
            }
        }

        private void cdvWorkPlace_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvWorkPlace.DisplayText == "")
            {
                cdvWorkPlace.Text = "";
            }
        }

        private void cdvOper_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvOper.DisplayText == "")
            {
                cdvOper.Text = "";
            }
        }

        private void txtMatDesc_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == '\r')
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdwLotList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            try
            {
                if (spdwLotList.ActiveSheet.Cells[e.Row, 26].Value.ToString() == "PROD" && spdwLotList.ActiveSheet.Cells[e.Row, 27].Value.ToString() == "Y")
                {
                    btnPrint.Enabled = true;
                    cdvLabel.Enabled = true;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void chkNowOnly_CheckedChanged(object sender, EventArgs e)
        {
            if (chkNowOnly.Checked)
            {
                dtpDate.Text = DateTime.Now.ToString("yyyy-MM-dd");
                dtpDate.Enabled = false;
                pnlOldDate.Visible = false;
            }
            else
            {
                dtpDate.Enabled = true;
                pnlOldDate.Visible = true;
            }
        }

        private void btntxt_Click(object sender, EventArgs e)
        {
            File.Delete(txtPath.Text + "/eBeam.txt");
            StreamWriter streamWriter = File.AppendText(txtPath.Text + "/eBeam.txt");
            for (int i = 0; i < spdLotList_Sheet1.RowCount; i++)
            {
                if (spdLotList_Sheet1.Cells[i, 0].Value.ToString().ToUpper() == "TRUE")
                {
                    streamWriter.WriteLine(MPCF.Trim(spdLotList_Sheet1.Cells[i, 2].Text));
                }
            }
            streamWriter.Close();
        }

        private void chkfixDecPoint_CheckedChanged(object sender, EventArgs e)
        {
            changeDecimalpoint();
        }

        private void cbdDecimalPlace_SelectedIndexChanged(object sender, EventArgs e)
        {
            changeDecimalpoint();
        }

        private void cdvHold_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvHold.Init();
                MPCF.InitListView(cdvHold.GetListView);
                cdvHold.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvHold.SelectedSubItemIndex = 0;
                if (BASLIST.ViewGCMDataList(cdvHold.GetListView, '1', "YESNO"))
                {
                    cdvHold.InsertEmptyRow(0, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvHold_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvHold.DisplayText == "")
            {
                cdvHold.Text = "";
            }
        }

        private void btnOutsourceing_Click(object sender, EventArgs e)
        {
            try
            {
                if (cdvOutsourcing.Text.Trim().Length == 0 && MPCF.ShowMsgBox(MPCF.GetMessage(578), MessageBoxButtons.YesNo, 2) == DialogResult.No)
                {
                    return;
                }
                for (int i = 0; i < spdAllLotList_Sheet1.RowCount; i++)
                {
                    if (spdAllLotList_Sheet1.Cells[i, 0].Value != null && spdAllLotList_Sheet1.Cells[i, 0].Value.ToString().ToUpper() == "TRUE")
                    {
                        string sTableTypes = spdAllLotList_Sheet1.Cells[i, 76].Value.ToString();
                        string sLotId = spdAllLotList_Sheet1.Cells[i, 1].Value.ToString();
                        string sOutsourcing = cdvOutsourcing.Text.Trim();
                        if (!OutSourcing_Update(sTableTypes, sLotId, sOutsourcing))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(546));
                            break;
                        }
                        spdAllLotList_Sheet1.Cells[i, 0].Value = false;
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool OutSourcing_Update(string sTableTypes, string sLotId, string sOutsourcing)
        {
            try
            {
                string text = "";
                text = ((!(sTableTypes.ToString() == "MWIPLOTSTS")) ? ("UPDATE MINVLOTSTS SET INV_CMF_10 = '" + sOutsourcing + "'WHERE FACTORY = '" + MPGV.gsFactory + "'  AND  INV_LOT_ID = '" + sLotId + "'") : ("UPDATE MWIPLOTSTS SET LOT_CMF_16 = '" + sOutsourcing + "' WHERE FACTORY = '" + MPGV.gsFactory + "' AND  LOT_ID = '" + sLotId + "'"));
                TRSNode tRSNode = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("SQL", text);
                if (!MPCR.CallService("BAS", "BAS_SQL_Query", tRSNode, ref out_node))
                {
                    return false;
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void cdvOutsourcing_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                CUS_COM.Popup.frmPopWorkOrderList frmPopWorkOrderList = new CUS_COM.Popup.frmPopWorkOrderList();
                frmPopWorkOrderList.StartPosition = FormStartPosition.CenterParent;
                frmPopWorkOrderList.g_AreaCode = cdvDept.Text;
                frmPopWorkOrderList.g_AreaDesc = cdvDept.DisplayText;
                if (frmPopWorkOrderList.ShowDialog() == DialogResult.OK)
                {
                    cdvOutsourcing.Text = frmPopWorkOrderList.g_WorkOrder;
                    frmPopWorkOrderList = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

    }
}
