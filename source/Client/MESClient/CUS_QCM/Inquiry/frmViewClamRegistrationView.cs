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
    public partial class frmViewClamRegistrationView : CUS_COM.frmViewForm01
    {
        public frmViewClamRegistrationView()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum CLAIM_LIST
        {
            REPORT_NO,//	REPORT NO
            CMF_02,//	사업부
            CUST_NAME,//	CUSTOMER NAME
            EVENT_DATE,//	EVENT DATE
            RECEIVED_DATE_1,//	통보서 접수일자
            RECEIVED_DATE_2,//	샘플 접수일자
            GRADE,//	제품 품목
            CMF_01,//	제품 품목 II 
            MAT_ID,//	품목코드
            MAT_DESC,//	품명
            CLOSURE_DATE,//	종결일자
            SHARE_DATE,//	분석보고 송부일
            SAL_GROUP,//	담당 법인
            SAL_USER,//	법인 담당자
            CLAIM_STATUS,//	진행상태
            CLAIM_LEVEL,//	불만 등급
            CLAIM_COUNT_FLAG,//	불만건수 카운트여부
            CLAIM_ADJUSTED_FLAG,//	체감 불만율 반영여부
            COST_QTY_01,//	총 비용
            COST_MONTH,//	품질비용 발생월
            COMMENT_01,//	고객사 사용 조건
            COMMENT_02,//	진행 세부 사항
            COMMENT_03,//	불량 내용
            FILE_NO_01,//	고객불만통보서 파일번호
            FILE_NO_02,//	분석 보고서 파일번호


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
        // 주문 지시 정보 조회
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



                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[15];
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

                dvcArgu[9].sCondition_ID = "CLAIM_STATUS";
                dvcArgu[9].sCondition_Value = "%" + cdvClaimStatus.Text + "%";

                dvcArgu[10].sCondition_ID = "CLAIM_LEVEL";
                dvcArgu[10].sCondition_Value = "%" + cdvClameLevel.Text + "%";

                dvcArgu[11].sCondition_ID = "GRADE";
                dvcArgu[11].sCondition_Value = "%" + cdvGrade.Text + "%";

                dvcArgu[12].sCondition_ID = "CMF_01";
                dvcArgu[12].sCondition_Value = "%" + cdvGrade2.Text + "%";

                dvcArgu[13].sCondition_ID = "MAT_ID";
                dvcArgu[13].sCondition_Value = "%" + cdvMatId.Text + "%";

                dvcArgu[14].sCondition_ID = "MAT_DESC";
                dvcArgu[14].sCondition_Value = "%" + txtMatDesc.Text + "%";

                sViewID = "CQCM3016-002";

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdClaimList);
                    return;
                }

                MPCF.ClearList(spdClaimList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdClaimList_Sheet1.RowCount++;

                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.REPORT_NO].Value = dt.Rows[i]["REPORT_NO"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.CMF_02].Value = dt.Rows[i]["CMF_02"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.CUST_NAME].Value = dt.Rows[i]["CUST_NAME"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.EVENT_DATE].Value = dt.Rows[i]["EVENT_DATE"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.RECEIVED_DATE_1].Value = dt.Rows[i]["RECEIVED_DATE_1"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.RECEIVED_DATE_2].Value = dt.Rows[i]["RECEIVED_DATE_2"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.CMF_01].Value = dt.Rows[i]["CMF_01"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.CLOSURE_DATE].Value = dt.Rows[i]["CLOSURE_DATE"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.SHARE_DATE].Value = dt.Rows[i]["SHARE_DATE"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.SAL_GROUP].Value = dt.Rows[i]["SAL_GROUP"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.SAL_USER].Value = dt.Rows[i]["SAL_USER"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.CLAIM_STATUS].Value = dt.Rows[i]["CLAIM_STATUS"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.CLAIM_LEVEL].Value = dt.Rows[i]["CLAIM_LEVEL"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.CLAIM_COUNT_FLAG].Value = dt.Rows[i]["CLAIM_COUNT_FLAG"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.CLAIM_ADJUSTED_FLAG].Value = dt.Rows[i]["CLAIM_ADJUSTED_FLAG"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.COST_QTY_01].Value = dt.Rows[i]["COST_QTY_01"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.COST_MONTH].Value = dt.Rows[i]["COST_MONTH"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.COMMENT_01].Value = dt.Rows[i]["COMMENT_01"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.COMMENT_02].Value = dt.Rows[i]["COMMENT_02"];
                    spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.COMMENT_03].Value = dt.Rows[i]["COMMENT_03"];



                    if (dt.Rows[i]["FILE_NO_01"].ToString().Trim() != "")
                    {
                        spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.FILE_NO_01].CellType = buttonCellType1;
                        spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.FILE_NO_01].Tag = dt.Rows[i]["FILE_NO_01"];

                    }
                    else
                    {
                        spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.FILE_NO_01].CellType = buttonCellType2;
                    }

                    if (dt.Rows[i]["FILE_NO_02"].ToString().Trim() != "")
                    {
                        spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.FILE_NO_02].CellType = buttonCellType1;
                        spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.FILE_NO_02].Tag = dt.Rows[i]["FILE_NO_02"];
                    }
                    else
                    {
                        spdClaimList_Sheet1.Cells[i, (int)CLAIM_LIST.FILE_NO_02].CellType = buttonCellType2;
                    }

                }
                MPCF.FitColumnHeader(spdClaimList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        //초기화 함수
        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":

                        MPCF.ClearList(spdClaimList);
                        break;

                    case "ALL":

                        MPCF.ClearList(spdClaimList);
                        dtpToEventDate.Value = DateTime.Now;
                        dtpFromEventDate.Value = dtpToEventDate.Value.AddDays(-30);

                        dtpToEventDate.Text = "";
                        dtpFromEventDate.Text = "";

                        cdvDept.Text = "";
                        cdvMatId.Text = "";
                        cdvCustomerId.Text = "";
                        cdvClaimStatus.Text = "";
                        txtMatDesc.Text = "";
                        cdvGrade.Text = "";
                        cdvClameLevel.Text = "";
                        cdvGrade2.Text = "";
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

        #region " Event Definition "
        private void frmViewClamRegistrationView_Load(object sender, EventArgs e)
        {
            try
            {
                //cdvClaimStatus.Text = CSGC.CP_PACK_STATUS_WAIT;
                //cdvClaimStatus.DisplayText = CSGC.CP_PACK_STATUS_WAIT_DESC;

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
                cdvMatId.Text = "";

                MPCF.ClearList(spdClaimList);

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
                    if (spdClaimList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdClaimList, e.Row, e.Column, true, true, false);
                    }
                }
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdClaimList, e.Row);
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
                cdvClaimStatus.Init();
                MPCF.InitListView(cdvClaimStatus.GetListView);
                cdvClaimStatus.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvClaimStatus.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvClaimStatus.SelectedSubItemIndex = 0;
                cdvClaimStatus.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvClaimStatus.GetListView, '1', CSGC.CP_GCM_SHIP_STATUS) == false)
                {
                    return;
                }

                cdvClaimStatus.InsertEmptyRow(0, 1);
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
                EXTFUC.SaveExcel(spdClaimList, "PackOrderList");

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
        private void cdvCustomerId_TextBoxTextChanged(object sender, EventArgs e)
        {

            if (cdvCustomerId.DisplayText == "")
                cdvCustomerId.Text = "";
        }
        private void cdvOrderStatus_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvClaimStatus.DisplayText == "")
                cdvClaimStatus.Text = "";
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
                cdvClaimStatus.Init();
                MPCF.InitListView(cdvClaimStatus.GetListView);
                cdvClaimStatus.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvClaimStatus.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                //cdvCar.SelectedSubItemIndex = 0;
                //cdvCar.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvClaimStatus.GetListView, '1', "C_CLAIM_STATUS") == false)
                {
                    return;
                }
                cdvClaimStatus.AddEmptyRow(1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvClameLevel_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvClameLevel.Init();
                MPCF.InitListView(cdvClameLevel.GetListView);
                cdvClameLevel.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvClameLevel.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                //cdvCar.SelectedSubItemIndex = 0;
                //cdvCar.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvClameLevel.GetListView, '1', "C_CLAIM_LEVEL") == false)
                {
                    return;
                }

                cdvClameLevel.AddEmptyRow(1);
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
        private void spdClaimList_CellDoubleClick(object sender, CellClickEventArgs e)
        {
            try
            {


                if (spdClaimList_Sheet1.ActiveColumnIndex != (int)CLAIM_LIST.FILE_NO_01 && spdClaimList_Sheet1.ActiveColumnIndex != (int)CLAIM_LIST.FILE_NO_02)
                {
                    frmTranClaimRegistraion popup = new frmTranClaimRegistraion();
                    popup.StartPosition = FormStartPosition.CenterParent;
                    popup.gReportNo = spdClaimList_Sheet1.Cells[spdClaimList_Sheet1.ActiveRowIndex, (int)CLAIM_LIST.REPORT_NO].Text;

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

                frmTranClaimRegistraion popup = new frmTranClaimRegistraion();
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
        private void spdClaimList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {

            try
            {

                string image_file = string.Empty;
                string sClaimNo = spdClaimList_Sheet1.Cells[e.Row, (int)CLAIM_LIST.REPORT_NO].Text;
                string sFileNo1 = "";
                string sFileNo2 = "";


                switch (e.Column)
                {
                    case (int)CLAIM_LIST.FILE_NO_01:
                    case (int)CLAIM_LIST.FILE_NO_02:


                        //int iActiveRow = spdFileRegistration.ActiveSheet.ActiveRowIndex;

                        SaveFileDialog dialog = new SaveFileDialog();
                        dialog.Title = "파일 위치 지정";
                        //Environment.GetFolderPath(Environment.SpecialFolder.Startup).ToString() 
                        //Environment.GetFolderPath(Environment.SpecialFolder.CommonPictures).ToString() 

                        if (e.Column == (int)CLAIM_LIST.FILE_NO_01)
                        {

                            if (spdClaimList_Sheet1.Cells[e.Row, e.Column].Tag != null)
                            {
                                //dialog.FileName = Environment.GetFolderPath(Environment.SpecialFolder.Startup).ToString() + "\\" + sClaimNo + "_고객불만통보서" + ".pdf";
                                dialog.FileName = "불만번호_" + sClaimNo + "_고객불만통보서" + ".pdf";
                                dialog.Filter = "PDF (*.PDF) | *.PDF | 모든 파일 (*.*) | *.*";

                                if (dialog.ShowDialog() == DialogResult.OK)
                                {

                                    sFileNo1 = spdClaimList_Sheet1.Cells[e.Row, (int)CLAIM_LIST.FILE_NO_01].Tag.ToString();

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

                            if (spdClaimList_Sheet1.Cells[e.Row, e.Column].Tag != null)
                            {
                                dialog.FileName = Environment.GetFolderPath(Environment.SpecialFolder.Startup).ToString() + "\\" + sClaimNo + "_분석보고서" + ".pdf";

                                dialog.FileName = "불만번호_" + sClaimNo + "_분석보고서" + ".pdf";
                                dialog.Filter = "PDF (*.PDF) | *.PDF | 모든 파일 (*.*) | *.*";

                                if (dialog.ShowDialog() == DialogResult.OK)
                                {


                                    sFileNo2 = spdClaimList_Sheet1.Cells[e.Row, (int)CLAIM_LIST.FILE_NO_02].Tag.ToString();

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
        #endregion
    }
}
