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

namespace CUS_QCM
{
    public partial class frmViewCustomerVocView : CUS_COM.frmViewForm01
    {
        public frmViewCustomerVocView()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum ANALYZE_LIST
        {
            REPORT_NO,//	REPORT NO
            CMF_02,//	사업부
            CUST_NAME,//	CUSTOMER NAME
            CREATE_DATE,//	CREATE DATE
            RECEIVED_DATE_1,//  접수일자
            RECEIVED_DATE_2,//	예상 개선일자 
            CLOSURE_DATE,//완료일자
            SAL_GROUP,//	담당 법인
            CMF_01,//	담당 부서
            VOC_STATUS,//	진행상태
            COMMENT_01,//	고객요청사항
            COMMENT_02,//	진행 세부 사항
            FILE_NO_01,//	VOC관련 첨부파일


        }
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

                // this.spdSampleList_Sheet1.Columns.Get(23).CellType = buttonCellType1;
                //  this.spdSampleList_Sheet1.Columns.Get(23).Label = "고객불만 통보서 파일번호";
                //  this.spdSampleList_Sheet1.Columns.Get(23).Width = 151F;



                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[11];
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

                dvcArgu[3].sCondition_ID = "FROM_CLOSED_DATE";
                dvcArgu[3].sCondition_Value = dtpToClosedDate.Text.Replace("-", "");

                dvcArgu[4].sCondition_ID = "TO_CLOSED_DATE";
                dvcArgu[4].sCondition_Value = dtpToClosedDate.Text.Replace("-", "");


                dvcArgu[5].sCondition_ID = "CMF_02";
                dvcArgu[5].sCondition_Value = cdvDept.Text;

                dvcArgu[6].sCondition_ID = "SAL_GROUP";
                dvcArgu[6].sCondition_Value = "%" + cdvSalGroup.Text + "%";

                dvcArgu[7].sCondition_ID = "CUST_NO";
                dvcArgu[7].sCondition_Value = "%" + cdvCustomerId.Text + "%";

                dvcArgu[8].sCondition_ID = "CUST_NAME";
                dvcArgu[8].sCondition_Value = "%" + cdvCustomerId.Text + "%";

                dvcArgu[9].sCondition_ID = "VOC_STATUS";
                dvcArgu[9].sCondition_Value = "%" + cdvAnalyzeStatus.Text + "%";



                dvcArgu[10].sCondition_ID = "CMF_01";
                dvcArgu[10].sCondition_Value = "%" + cdvTeam.Text + "%";



                sViewID = "CQCM3019-002";

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdVocList);
                    return;
                }

                MPCF.ClearList(spdVocList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdVocList_Sheet1.RowCount++;

                    spdVocList_Sheet1.Cells[i, (int)ANALYZE_LIST.REPORT_NO].Value = dt.Rows[i]["REPORT_NO"];
                    spdVocList_Sheet1.Cells[i, (int)ANALYZE_LIST.CMF_02].Value = dt.Rows[i]["CMF_02"];
                    spdVocList_Sheet1.Cells[i, (int)ANALYZE_LIST.CUST_NAME].Value = dt.Rows[i]["CUST_NAME"];
                    spdVocList_Sheet1.Cells[i, (int)ANALYZE_LIST.CREATE_DATE].Value = dt.Rows[i]["CREATE_DATE"];
                    spdVocList_Sheet1.Cells[i, (int)ANALYZE_LIST.RECEIVED_DATE_1].Value = dt.Rows[i]["RECEIVED_DATE_1"];
                    spdVocList_Sheet1.Cells[i, (int)ANALYZE_LIST.RECEIVED_DATE_2].Value = dt.Rows[i]["RECEIVED_DATE_2"];
                    spdVocList_Sheet1.Cells[i, (int)ANALYZE_LIST.CMF_01].Value = dt.Rows[i]["CMF_01"];
                    spdVocList_Sheet1.Cells[i, (int)ANALYZE_LIST.CLOSURE_DATE].Value = dt.Rows[i]["CLOSURE_DATE"];
                    spdVocList_Sheet1.Cells[i, (int)ANALYZE_LIST.SAL_GROUP].Value = dt.Rows[i]["SAL_GROUP"];
                    spdVocList_Sheet1.Cells[i, (int)ANALYZE_LIST.VOC_STATUS].Value = dt.Rows[i]["VOC_STATUS"];
                    spdVocList_Sheet1.Cells[i, (int)ANALYZE_LIST.COMMENT_01].Value = dt.Rows[i]["COMMENT_01"];
                    spdVocList_Sheet1.Cells[i, (int)ANALYZE_LIST.COMMENT_02].Value = dt.Rows[i]["COMMENT_02"];



                    if (dt.Rows[i]["FILE_NO_01"].ToString().Trim() != "")
                    {
                        spdVocList_Sheet1.Cells[i, (int)ANALYZE_LIST.FILE_NO_01].CellType = buttonCellType1;
                        spdVocList_Sheet1.Cells[i, (int)ANALYZE_LIST.FILE_NO_01].Tag = dt.Rows[i]["FILE_NO_01"];

                    }
                    else
                    {
                        spdVocList_Sheet1.Cells[i, (int)ANALYZE_LIST.FILE_NO_01].CellType = buttonCellType2;
                    }


                }
                MPCF.FitColumnHeader(spdVocList);

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

                        MPCF.ClearList(spdVocList);
                        break;

                    case "ALL":

                        MPCF.ClearList(spdVocList);
                        dtpToEventDate.Value = DateTime.Now;
                        dtpFromEventDate.Value = dtpToEventDate.Value.AddDays(-30);

                        dtpToEventDate.Text = "";
                        dtpFromEventDate.Text = "";

                        cdvDept.Text = "";
                        cdvCustomerId.Text = "";
                        cdvAnalyzeStatus.Text = "";
                        cdvTeam.Text = "";
                        txtCustName.Text = "";
                        cdvSalGroup.Text = "";

                        break;
                }
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
        #endregion

        #region " Event Definition "
        private void frmViewCustomerVocView_Load(object sender, EventArgs e)
        {
            try
            {
                //cdvAnalyzeStatus.Text = CSGC.CP_PACK_STATUS_WAIT;
                //cdvAnalyzeStatus.DisplayText = CSGC.CP_PACK_STATUS_WAIT_DESC;

                dtpToEventDate.Value = DateTime.Now;
                dtpFromEventDate.Value = DateTime.Now.AddDays(-30); ;

                dtpFromClosedDate.Format = DateTimePickerFormat.Custom;
                dtpFromClosedDate.CustomFormat = " ";

                dtpToClosedDate.Format = DateTimePickerFormat.Custom;
                dtpToClosedDate.CustomFormat = " ";



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

                MPCF.ClearList(spdVocList);

                // ViewItemList(cdvDept.Text);
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
                    this.txtCustName.Text = popup.g_CustomerDesc;
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
                    if (spdVocList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdVocList, e.Row, e.Column, true, true, false);
                    }
                }
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdVocList, e.Row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
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
        private void cdvAnalyzeStatus_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvAnalyzeStatus.Init();
                MPCF.InitListView(cdvAnalyzeStatus.GetListView);
                cdvAnalyzeStatus.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvAnalyzeStatus.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                //cdvCar.SelectedSubItemIndex = 0;
                //cdvCar.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvAnalyzeStatus.GetListView, '1', "C_CLAIM_STATUS") == false)
                {
                    return;
                }
                cdvAnalyzeStatus.AddEmptyRow(1);
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

                cdvTeam.Init();
                MPCF.InitListView(cdvTeam.GetListView);
                cdvTeam.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvTeam.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                //cdvCar.SelectedSubItemIndex = 0;
                //cdvCar.DisplaySubItemIndex = 1;
                /*
                if (BASLIST.ViewGCMDataList_AREA(cdvWorkPlace.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, cdvDept.Text) == false)
                {
                    return;
                }
                */

                if (ViewGCMDataList_Grade(cdvTeam.GetListView, '1', "C_AREA_MAT_GROUP_1", cdvDept.Text) == false)
                {
                    return;
                }


                cdvTeam.AddEmptyRow(1);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdSampleList_CellDoubleClick(object sender, CellClickEventArgs e)
        {
            try
            {


                if (spdVocList_Sheet1.ActiveColumnIndex != (int)ANALYZE_LIST.FILE_NO_01)
                {
                    frmTranCustomerVocRegistraion popup = new frmTranCustomerVocRegistraion();
                    popup.StartPosition = FormStartPosition.CenterParent;
                    popup.gReportNo = spdVocList_Sheet1.Cells[spdVocList_Sheet1.ActiveRowIndex, (int)ANALYZE_LIST.REPORT_NO].Text;

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

                frmTranCustomerVocRegistraion popup = new frmTranCustomerVocRegistraion();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.gReportNo = "";

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
        private void dtpFromClosedDate_ValueChanged(object sender, EventArgs e)
        {
            dtpFromClosedDate.CustomFormat = "yyyy-MM-dd";
        }
        private void dtpToClosedDate_ValueChanged(object sender, EventArgs e)
        {
            dtpToClosedDate.CustomFormat = "yyyy-MM-dd";
        }
        private void dtpToClosedDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            try
            {

                switch (e.KeyCode)
                {
                    case Keys.Delete:
                        dtpToClosedDate.CustomFormat = " ";
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void dtpFromClosedDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {

            try
            {

                switch (e.KeyCode)
                {
                    case Keys.Delete:
                        dtpFromClosedDate.CustomFormat = " ";
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdSampleList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {

            try
            {

                string image_file = string.Empty;
                string sClaimNo = spdVocList_Sheet1.Cells[e.Row, (int)ANALYZE_LIST.REPORT_NO].Text;
                string sFileNo1 = "";



                switch (e.Column)
                {
                    case (int)ANALYZE_LIST.FILE_NO_01:


                        //int iActiveRow = spdFileRegistration.ActiveSheet.ActiveRowIndex;

                        SaveFileDialog dialog = new SaveFileDialog();
                        dialog.Title = "파일 위치 지정";
                        //Environment.GetFolderPath(Environment.SpecialFolder.Startup).ToString() 
                        //Environment.GetFolderPath(Environment.SpecialFolder.CommonPictures).ToString() 

                        if (e.Column == (int)ANALYZE_LIST.FILE_NO_01)
                        {

                            if (spdVocList_Sheet1.Cells[e.Row, e.Column].Tag != null)
                            {
                                //dialog.FileName = Environment.GetFolderPath(Environment.SpecialFolder.Startup).ToString() + "\\" + sClaimNo + "_고객불만통보서" + ".pdf";
                                dialog.FileName = "VocNo_" + sClaimNo + "_File" + ".pdf";
                                dialog.Filter = "PDF (*.PDF) | *.PDF | 모든 파일 (*.*) | *.*";

                                if (dialog.ShowDialog() == DialogResult.OK)
                                {

                                    sFileNo1 = spdVocList_Sheet1.Cells[e.Row, (int)ANALYZE_LIST.FILE_NO_01].Tag.ToString();

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

                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
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
        private void pnlStsCond_Paint(object sender, PaintEventArgs e)
        {

        }
        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdVocList, "PackOrderList");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }
        private void cdvCustomerId_TextBoxTextChanged(object sender, EventArgs e)
        {

            if (cdvCustomerId.DisplayText == "")
                cdvCustomerId.Text = "";
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
        #endregion




    }
}
