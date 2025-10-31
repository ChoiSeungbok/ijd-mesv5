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
using DevExpress.ReportServer.ServiceModel.DataContracts;
using System.Collections;
using System.IO;
using FarPoint.Win.Spread.CellType;
using System.Diagnostics;
using FarPoint.Excel.EntityClassLibrary.DrawingVML;

namespace CUS_QCM
{
    public partial class frmViewOtrherCompanySpecView : CUS_COM.frmViewForm01
    {
        public frmViewOtrherCompanySpecView()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum DATA_LIST
        {
            CREATE_DATE,
            REPORT_NO,
            CMF_02,  //사업부
            REPORT_TYPE,
            CUST_NAME,
            SAL_GROUP,
            GRADE,
            CMF_01, //상세품목1
            CMF_03,  //상세품목2(Grade)
            DATA_01,
            DATA_02,
            DATA_03,
            DATA_04,
            DATA_05,
            DATA_06,
            DATA_07,
            DATA_08,
            DATA_09,
            DATA_10,
            DATA_11,
            DATA_12,
            DATA_13,
            DATA_14,
            DATA_15,
            DATA_16,
            DATA_17,
            DATA_18,
            DATA_19,
            DATA_20,
            DATA_21,
            DATA_22,
            DATA_23,
            DATA_24,
            DATA_25,
            DATA_26,
            DATA_27,
            DATA_28,
            DATA_29,
            DATA_30,
            FILE_NO_01,//	고객불만통보서 파일번호
            FILE_NO_02,//	분석 보고서 파일번호
            COMMENT_01

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
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnNew.Anchor = AnchorStyles.Top | AnchorStyles.Right;





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
        private void ViewOrderList()
        {
            try
            {
                ButtonCellType buttonCellType1 = new ButtonCellType();  //파일있는거
                ButtonCellType buttonCellType2 = new ButtonCellType();  //파일없는거

                buttonCellType1.UseVisualStyleBackColor = false;
                buttonCellType1.ButtonColor = System.Drawing.Color.BlueViolet;  //System.Drawing.SystemColors.ButtonFace;
                buttonCellType1.TextColor = System.Drawing.Color.White;  //System.Drawing.SystemColors.ButtonFace;

                buttonCellType1.Text = "Download";
                buttonCellType2.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                buttonCellType2.Text = "No File";

                // this.spdClaimList_Sheet1.Columns.Get(23).CellType = buttonCellType1;
                //  this.spdClaimList_Sheet1.Columns.Get(23).Label = "고객불만 통보서 파일번호";
                //  this.spdClaimList_Sheet1.Columns.Get(23).Width = 151F;



                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[10];
                DataTable dt = null;
                string sSql = "";
                string sViewID = "";

                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FROM_DATE";
                dvcArgu[1].sCondition_Value = string.Format("{0}", string.IsNullOrEmpty(dtpFromEventDate.Text.Trim()) ? "19000101" : dtpFromEventDate.Text.Replace("-", ""));

                dvcArgu[2].sCondition_ID = "TO_DATE";
                dvcArgu[2].sCondition_Value = dtpToEventDate.Text.Replace("-", "");



                dvcArgu[3].sCondition_ID = "CMF_02";
                dvcArgu[3].sCondition_Value = cdvDept.Text;

                dvcArgu[4].sCondition_ID = "SAL_GROUP";
                dvcArgu[4].sCondition_Value = "%" + cdvSalGroup.Text + "%";

                dvcArgu[5].sCondition_ID = "CUST_NAME";
                dvcArgu[5].sCondition_Value = "%" + cdvCustomerId.Text + "%";


                dvcArgu[6].sCondition_ID = "REPORT_TYPE";
                dvcArgu[6].sCondition_Value = "%" + cdvReportType.Text + "%";



                dvcArgu[7].sCondition_ID = "GRADE";
                dvcArgu[7].sCondition_Value = "%" + cdvGrade.Text + "%";

                dvcArgu[8].sCondition_ID = "CMF_01";
                dvcArgu[8].sCondition_Value = "%" + cdvGrade2.Text + "%";

                dvcArgu[9].sCondition_ID = "CMF_03";
                dvcArgu[9].sCondition_Value = "%" + cdvGrade3.Text + "%";

                sViewID = "CQCM3020-001";

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdSpecList);
                    return;
                }

                MPCF.ClearList(spdSpecList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdSpecList_Sheet1.RowCount++;

                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.CREATE_DATE].Value = dt.Rows[i]["CREATE_DATE"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.REPORT_NO].Value = dt.Rows[i]["REPORT_NO"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.REPORT_TYPE].Value = dt.Rows[i]["REPORT_TYPE"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.CMF_02].Value = dt.Rows[i]["CMF_02"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.CUST_NAME].Value = dt.Rows[i]["CUST_NAME"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.SAL_GROUP].Value = dt.Rows[i]["SAL_GROUP"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.CMF_01].Value = dt.Rows[i]["CMF_01"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.CMF_03].Value = dt.Rows[i]["CMF_03"];



                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_01].Value = dt.Rows[i]["DATA_01"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_02].Value = dt.Rows[i]["DATA_02"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_03].Value = dt.Rows[i]["DATA_03"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_04].Value = dt.Rows[i]["DATA_04"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_05].Value = dt.Rows[i]["DATA_05"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_06].Value = dt.Rows[i]["DATA_06"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_07].Value = dt.Rows[i]["DATA_07"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_08].Value = dt.Rows[i]["DATA_08"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_09].Value = dt.Rows[i]["DATA_09"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_10].Value = dt.Rows[i]["DATA_10"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_11].Value = dt.Rows[i]["DATA_11"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_12].Value = dt.Rows[i]["DATA_12"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_13].Value = dt.Rows[i]["DATA_13"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_14].Value = dt.Rows[i]["DATA_14"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_15].Value = dt.Rows[i]["DATA_15"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_16].Value = dt.Rows[i]["DATA_16"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_17].Value = dt.Rows[i]["DATA_17"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_18].Value = dt.Rows[i]["DATA_18"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_19].Value = dt.Rows[i]["DATA_19"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_20].Value = dt.Rows[i]["DATA_20"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_21].Value = dt.Rows[i]["DATA_21"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_22].Value = dt.Rows[i]["DATA_22"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_23].Value = dt.Rows[i]["DATA_23"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_24].Value = dt.Rows[i]["DATA_24"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_25].Value = dt.Rows[i]["DATA_25"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_26].Value = dt.Rows[i]["DATA_26"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_27].Value = dt.Rows[i]["DATA_27"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_28].Value = dt.Rows[i]["DATA_28"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_29].Value = dt.Rows[i]["DATA_29"];
                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.DATA_30].Value = dt.Rows[i]["DATA_30"];



                    spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.COMMENT_01].Value = dt.Rows[i]["COMMENT_01"];



                    if (dt.Rows[i]["FILE_NO_01"].ToString().Trim() != "")
                    {
                        spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.FILE_NO_01].CellType = buttonCellType1;
                        spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.FILE_NO_01].Tag = dt.Rows[i]["FILE_NO_01"];

                    }
                    else
                    {
                        spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.FILE_NO_01].CellType = buttonCellType2;
                    }

                    if (dt.Rows[i]["FILE_NO_02"].ToString().Trim() != "")
                    {
                        spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.FILE_NO_02].CellType = buttonCellType1;
                        spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.FILE_NO_02].Tag = dt.Rows[i]["FILE_NO_02"];
                    }
                    else
                    {
                        spdSpecList_Sheet1.Cells[i, (int)DATA_LIST.FILE_NO_02].CellType = buttonCellType2;
                    }

                }
                MPCF.FitColumnHeader(spdSpecList);



                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":

                        MPCF.ClearList(spdSpecList);
                        break;

                    case "ALL":

                        MPCF.ClearList(spdSpecList);
                        dtpToEventDate.Value = DateTime.Now;
                        dtpFromEventDate.Value = dtpToEventDate.Value.AddDays(-30);

                        dtpToEventDate.Text = "";
                        dtpFromEventDate.Text = "";

                        cdvDept.Text = "";

                        cdvCustomerId.Text = "";
                        cdvReportType.Text = "";

                        cdvGrade.Text = "";

                        cdvGrade2.Text = "";

                        cdvSalGroup.Text = "";

                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion

        #region " Event Definition "
        private void frmViewOtrherCompanySpecView_Load(object sender, EventArgs e)
        {
            try
            {
                //cdvClaimStatus.Text = CSGC.CP_PACK_STATUS_WAIT;
                //cdvClaimStatus.DisplayText = CSGC.CP_PACK_STATUS_WAIT_DESC;

                dtpToEventDate.Value = DateTime.Now;
                dtpFromEventDate.Value = DateTime.Now.AddDays(-30); ;






            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
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

                MPCF.ClearList(spdSpecList);

                DataListNameView();


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

                ClearList("VIEW");
                ViewOrderList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                ClearList("ALL");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvCustomerId_ButtonPress(object sender, EventArgs e)
        {
            //고객사 팝업으로 변경
            try
            {
                frmPopCustomerList popup = new frmPopCustomerList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvCustomerId.Text = popup.g_CustomerId;
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
        private void spdOrderList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (spdSpecList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdSpecList, e.Row, e.Column, true, true, false);
                    }
                }
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdSpecList, e.Row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }
        private void cdvOrderStatus_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvReportType.Init();
                MPCF.InitListView(cdvReportType.GetListView);
                cdvReportType.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvReportType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvReportType.SelectedSubItemIndex = 0;
                cdvReportType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvReportType.GetListView, '1', CSGC.CP_GCM_SHIP_STATUS) == false)
                {
                    return;
                }

                cdvReportType.InsertEmptyRow(0, 1);
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
                EXTFUC.SaveExcel(spdSpecList, "PackOrderList");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }
        private void cdvMatId_TextBoxTextChanged(object sender, EventArgs e)
        {

        }
        private void cdvCustomerId_TextBoxTextChanged(object sender, EventArgs e)
        {

            if (cdvCustomerId.DisplayText == "")
                cdvCustomerId.Text = "";
        }
        private void cdvOrderStatus_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvReportType.DisplayText == "")
                cdvReportType.Text = "";
        }
        private void txtMatDesc_KeyPress(object sender, KeyPressEventArgs e)
        {

            try
            {
                if (e.KeyChar == (char)13)
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void txtPackingOrderNo_KeyPress(object sender, KeyPressEventArgs e)
        {

            try
            {
                if (e.KeyChar == (char)13)
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void dtpFromWorkDate_ValueChanged(object sender, EventArgs e)
        {
            dtpFromEventDate.CustomFormat = "yyyy-MM-dd";

        }
        private void dtpFromWorkDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtpFromEventDate.CustomFormat = " ";
                    break;
            }

        }
        private void cdvCustomerId_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {

        }
        private void cdvSalGroup_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvSalGroup.Init();
                MPCF.InitListView(cdvSalGroup.GetListView);
                cdvSalGroup.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvSalGroup.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                //cdvCar.SelectedSubItemIndex = 0;
                //cdvCar.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvSalGroup.GetListView, '1', "C_SAL_GROUP") == false)
                {
                    return;
                }

                cdvSalGroup.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvClaimStatus_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvReportType.Init();
                MPCF.InitListView(cdvReportType.GetListView);
                cdvReportType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvReportType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                //cdvCar.SelectedSubItemIndex = 0;
                //cdvCar.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvReportType.GetListView, '1', "C_CLAIM_STATUS") == false)
                {
                    return;
                }
                cdvReportType.AddEmptyRow(1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvGrade_ButtonPress(object sender, EventArgs e)
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

                cdvGrade.Init();
                MPCF.InitListView(cdvGrade.GetListView);
                cdvGrade.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvGrade.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                //cdvCar.SelectedSubItemIndex = 0;
                //cdvCar.DisplaySubItemIndex = 1;
                /*
                if (BASLIST.ViewGCMDataList_AREA(cdvWorkPlace.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, cdvDept.Text) == false)
                {
                    return;
                }
                */

                if (ViewGCMDataList_Grade(cdvGrade.GetListView, '1', "C_AREA_MAT_GROUP_1", cdvDept.Text) == false)
                {
                    return;
                }


                cdvGrade.AddEmptyRow(1);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvGrade2_ButtonPress(object sender, EventArgs e)
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

                cdvGrade2.Init();
                MPCF.InitListView(cdvGrade2.GetListView);
                cdvGrade2.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvGrade2.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                //cdvCar.SelectedSubItemIndex = 0;
                //cdvCar.DisplaySubItemIndex = 1;



                if (ViewGCMDataList_Grade(cdvGrade2.GetListView, '1', "C_AREA_MAT_GROUP_2", cdvDept.Text) == false)
                {
                    return;
                }

                cdvGrade2.AddEmptyRow(1);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private bool ViewGCMDataList_Grade(Control Form_control, char c_step, string table_name, string Area)
        {

            try
            {
                ListViewItem itmX;
                SheetView sheetX;
                int iRow;
                int iCol;
                int i;
                int j;
                int Image_idx = -1;
                string[] strData = null;
                List<string> sList = new List<string>();
                FarPoint.Win.Spread.CellType.ComboBoxCellType cboCellType;
                ArrayList a_list;

                TRSNode in_node = new TRSNode("VIEW_DATA_LIST_IN");
                TRSNode out_node;

                a_list = new ArrayList();
                Image_idx = (int)SMALLICON_INDEX.IDX_CODE_DATA;

                if (Form_control is ListView)
                {
                    MPCF.InitListView((ListView)Form_control);
                }
                else if (!(Form_control is TreeView))
                {
                    MPCF.ClearList(Form_control, true);
                }
                if (Form_control is Miracom.UI.Controls.MCCodeView.MCCodeDropList)
                {
                    ((Miracom.UI.Controls.MCCodeView.MCCodeDropList)Form_control).GCMTableName = table_name;
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = c_step;

                in_node.AddString("TABLE_NAME", table_name);
                in_node.AddString("NEXT_KEY_1", "");
                in_node.AddString("NEXT_KEY_2", "");

                do
                {
                    out_node = new TRSNode("VIEW_DATA_LIST_OUT");

                    if (MPCR.CallService("BAS", "BAS_View_Data_List", in_node, ref out_node, false) == false)
                    {
                        return false;
                    }

                    a_list.Add(out_node);

                    in_node.SetString("NEXT_KEY_1", out_node.GetString("NEXT_KEY_1"));
                    in_node.SetString("NEXT_KEY_2", out_node.GetString("NEXT_KEY_2"));
                } while (in_node.GetString("NEXT_KEY_1") != "" || in_node.GetString("NEXT_KEY_2") != "");

                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (out_node.GetList(0)[i].GetString("KEY_1") == MPCF.Trim(Area))
                        {
                            if (Form_control is ListView)
                            {

                                itmX = new ListViewItem(out_node.GetList(0)[i].GetString("KEY_2"), Image_idx);
                                if (((ListView)Form_control).Columns.Count > 1)
                                {
                                    for (j = 0; j <= ((ListView)Form_control).Columns.Count - 1; j++)
                                    {
                                        switch (j)
                                        {
                                            case 0:
                                                itmX.SubItems.Add(out_node.GetList(0)[i].GetString("KEY_2"));
                                                break;
                                        }
                                    }
                                }
                                ((ListView)Form_control).Items.Add(itmX);
                            }
                            else if (Form_control is FpSpread)
                            {
                                sheetX = ((FpSpread)Form_control).ActiveSheet;

                                if (sheetX.Columns.Count == 2)
                                {

                                    iRow = sheetX.RowCount;
                                    sheetX.RowCount++;

                                    iCol = 0;
                                    sheetX.Cells[iRow, iCol].Value = out_node.GetList(0)[i].GetString("KEY_2");

                                    iCol++;
                                    sheetX.Cells[iRow, iCol].Value = out_node.GetList(0)[i].GetString("KEY_1");

                                    iCol++;
                                }
                                else
                                {
                                    sList.Add(out_node.GetList(0)[i].GetString("KEY_1"));
                                }

                            }

                        }
                    }
                }


                if (Form_control is FpSpread)
                {

                    if (((FpSpread)Form_control).ActiveSheet.Columns.Count == 3)
                    {
                        return true;
                    }
                }

                strData = new string[sList.Count + 1];
                for (i = 0; i < sList.Count; i++)
                {
                    strData[i] = sList[i];
                }
                strData[i] = "";

                cboCellType = new FarPoint.Win.Spread.CellType.ComboBoxCellType();
                cboCellType.Items = strData;

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        private void spdClaimList_CellDoubleClick(object sender, CellClickEventArgs e)
        {
            try
            {


                if (spdSpecList_Sheet1.ActiveColumnIndex != (int)DATA_LIST.FILE_NO_01 && spdSpecList_Sheet1.ActiveColumnIndex != (int)DATA_LIST.FILE_NO_02)
                {
                    frmTranOtrherCompainSpecRegistraion popup = new frmTranOtrherCompainSpecRegistraion();
                    popup.StartPosition = FormStartPosition.CenterParent;
                    popup.gReportNo = spdSpecList_Sheet1.Cells[spdSpecList_Sheet1.ActiveRowIndex, (int)DATA_LIST.REPORT_NO].Text;
                    popup.sDeptCode = cdvDept.Text;

                    if (popup.ShowDialog() == DialogResult.OK)
                    {

                        popup = null;
                        ViewOrderList();
                    }
                    else
                    {
                        ViewOrderList();
                        return;
                    }

                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnNew_Click(object sender, EventArgs e)
        {
            try
            {
                frmTranOtrherCompainSpecRegistraion popup = new frmTranOtrherCompainSpecRegistraion();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.gReportNo = "";
                popup.sDeptCode = cdvDept.Text;

                if (popup.ShowDialog() == DialogResult.OK)
                {
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
        private void spdClaimList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {

            try
            {

                string image_file = string.Empty;
                string sReportNo = spdSpecList_Sheet1.Cells[e.Row, (int)DATA_LIST.REPORT_NO].Text;
                string sFileNo1 = "";
                string sFileNo2 = "";


                switch (e.Column)
                {
                    case (int)DATA_LIST.FILE_NO_01:
                    case (int)DATA_LIST.FILE_NO_02:


                        //int iActiveRow = spdFileRegistration.ActiveSheet.ActiveRowIndex;

                        SaveFileDialog dialog = new SaveFileDialog();
                        dialog.Title = "파일 위치 지정";
                        //Environment.GetFolderPath(Environment.SpecialFolder.Startup).ToString() 
                        //Environment.GetFolderPath(Environment.SpecialFolder.CommonPictures).ToString() 

                        if (e.Column == (int)DATA_LIST.FILE_NO_01)
                        {

                            if (spdSpecList_Sheet1.Cells[e.Row, e.Column].Tag != null)
                            {
                                //dialog.FileName = Environment.GetFolderPath(Environment.SpecialFolder.Startup).ToString() + "\\" + sClaimNo + "_고객불만통보서" + ".pdf";
                                dialog.FileName = "RegistrationNo_" + sReportNo + "_FILE01" + ".pdf";
                                dialog.Filter = "PDF (*.PDF) | *.PDF | 모든 파일 (*.*) | *.*";

                                if (dialog.ShowDialog() == DialogResult.OK)
                                {

                                    sFileNo1 = spdSpecList_Sheet1.Cells[e.Row, (int)DATA_LIST.FILE_NO_01].Tag.ToString();

                                    ByteArrayToPdf(sFileNo1, dialog.FileName);
                                }
                                else
                                {
                                    return;
                                }
                            }
                            else
                            {
                                return;
                            }

                        }
                        else
                        {

                            if (spdSpecList_Sheet1.Cells[e.Row, e.Column].Tag != null)
                            {
                                // dialog.FileName = Environment.GetFolderPath(Environment.SpecialFolder.Startup).ToString() + "\\" + sReportNo + "_분석보고서" + ".pdf";

                                dialog.FileName = "RegistrationNo_" + sReportNo + "_FILE02" + ".pdf";
                                dialog.Filter = "PDF (*.PDF) | *.PDF | 모든 파일 (*.*) | *.*";

                                if (dialog.ShowDialog() == DialogResult.OK)
                                {


                                    sFileNo2 = spdSpecList_Sheet1.Cells[e.Row, (int)DATA_LIST.FILE_NO_02].Tag.ToString();

                                    ByteArrayToPdf(sFileNo2, dialog.FileName);
                                }
                                else
                                {
                                    return;
                                }
                            }
                            else
                            {
                                return;
                            }


                        }

                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }
        private void DataListNameView()
        {

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                int iCol = 0;
                int iRow = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "KEY_1";
                dvcArgu[1].sCondition_Value = cdvDept.Text;


                if (TPDR.GetDataOne("", ref dt, "CQCM3020-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }


                for (iCol = (int)DATA_LIST.DATA_01; iCol <= (int)DATA_LIST.DATA_30; iCol++)
                {


                    spdSpecList_Sheet1.ColumnHeader.Cells.Get(0, iCol).Value = dt.Rows[0][iRow];
                    spdSpecList_Sheet1.ColumnHeader.Cells.Get(0, iCol).Tag = dt.Rows[1][iRow];

                    if (spdSpecList_Sheet1.ColumnHeader.Cells.Get(0, iCol).Text.Trim() == "")
                    {
                        spdSpecList_Sheet1.Columns[iCol].Visible = false;
                    }
                    else
                    {
                        spdSpecList_Sheet1.Columns[iCol].Visible = true;
                    }
                    iRow++;
                }
                MPCF.FitColumnHeader(spdSpecList);



            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

        }
        private void ByteArrayToPdf(string sFileNo, string sfilePath)
        {
            byte[] bt_buffer;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FILE_NO";
                dvcArgu[1].sCondition_Value = sFileNo;


                if (TPDR.GetDataOne("", ref dt, "CQCM2001-005", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                bt_buffer = (byte[])dt.Rows[0]["IMAGE_DATA"];

                FileStream fs = System.IO.File.Open(sfilePath, FileMode.Create);
                BinaryWriter writer = new BinaryWriter(fs);
                writer.Write(bt_buffer, 0, bt_buffer.Length);
                writer.Close();

                //저장되었습니다.
                MPCF.ShowMsgBox(MPCF.GetMessage(576));
                Process.Start(new ProcessStartInfo(sfilePath) { UseShellExecute = true });
                if (MPCF.ShowMsgBox(MPCF.GetMessage(597), MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.Yes)
                {
                    Process.Start(new ProcessStartInfo(sfilePath) { UseShellExecute = true });
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

        }
        private void btnDelete_Click(object sender, EventArgs e)
        {

        }

        #endregion

    }
}
