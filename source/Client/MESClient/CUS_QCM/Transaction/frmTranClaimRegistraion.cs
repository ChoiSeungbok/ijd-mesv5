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
using Microsoft.VisualBasic;
using System.Xml.Linq;
using FarPoint.Win.Spread;
using System.Collections;
using DevExpress.Utils.CommonDialogs;
using System.IO;
using static System.Net.WebRequestMethods;
using FarPoint.Win.Spread.Model;
using System.Diagnostics;

namespace CUS_QCM
{
    public partial class frmTranClaimRegistraion : CUS_COM.frmViewForm01
    {

        #region " Constant Definition "
        private enum LOSS_INFO
        {
            LOSS_CODE,
            LOSS_DESC,
            LOSS_QTY,
            MAIN_YN
        }

        #endregion


        #region " Variable Definition "
        public frmTranClaimRegistraion()
        {
            InitializeComponent();

            InitControl();
        }


        string gFileServer_Ip;
        string gFileServer_PORT;
        string gFileServer_Dir;
        string gFileServer_ID;
        string gFileServer_PW;
        public string gReportNo = "";
        private void InitControl()
        {
            try
            {


                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;

                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;






                string sGcmName = "C_FILE_SERVER";
                ListView lisTmp = new ListView();
                lisTmp.Columns.Add("CODE");
                lisTmp.Columns.Add("IP");
                lisTmp.Columns.Add("PORT");
                lisTmp.Columns.Add("DIRECTORY");
                lisTmp.Columns.Add("ID");
                lisTmp.Columns.Add("PW");

                if (BASLIST.ViewGCMDataList(lisTmp, '1', sGcmName) == true)
                {
                    ListViewItem ItmFound = lisTmp.FindItemWithText(MPGV.gsFactory);

                    gFileServer_Ip = ItmFound.SubItems[1].Text;
                    gFileServer_PORT = ItmFound.SubItems[2].Text;
                    gFileServer_Dir = "MESplusV5/upgrade/PDA"; //다른곳에서도 FTP 쓸일있을수 있어서..싸인 이미지는 여기 고정  //ItmFound.SubItems[3].Text;
                    gFileServer_ID = ItmFound.SubItems[4].Text;
                    gFileServer_PW = ItmFound.SubItems[5].Text;
                }




            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "
        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                string LossOper = "";
                switch (cdvDept.Text)
                {
                    case CSGC.CP_AREA_CTM:
                        LossOper = "CW-RMA";
                        break;
                    case CSGC.CP_AREA_PDC:
                        LossOper = "PW-RMA";
                        break;
                    case CSGC.CP_AREA_GRT:
                        LossOper = "GW-RMA";
                        break;

                    case CSGC.CP_AREA_HM:
                        LossOper = "HW-RMA";
                        break;

                }
                cdvGrade.Text = "";
                cdvGrade2.Text = "";
                cdvMatid.Text = "";
                txtMatdesc.Text = "";

                ViewInspectionLossInfo(txtReportNo.Text, LossOper);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {

        }

        private void frmTranClaimRegistraion_Load(object sender, EventArgs e)
        {

            dtClosureDate.Value = DateTime.Now;
            dtEventDate.Value = DateTime.Now;
            dtReceiveddate.Value = DateTime.Now;
            dtReceiveddate2.Value = DateTime.Now;
            dtShareDate.Value = DateTime.Now;




            if (gReportNo != "")
            {
                txtReportNo.Text = gReportNo;

                ViewSearchData();
            }
            else
            {

                /*
                cdvClaimStatus.Text = "Q";
                cdvClaimStatus.DisplayText = "대기";
                */

                dtEventDate.Value = DateTime.Now;

                dtClosureDate.Format = DateTimePickerFormat.Custom;
                dtClosureDate.CustomFormat = " ";

                dtReceiveddate.Format = DateTimePickerFormat.Custom;
                dtReceiveddate.CustomFormat = " ";

                dtReceiveddate2.Format = DateTimePickerFormat.Custom;
                dtReceiveddate2.CustomFormat = " ";

                dtShareDate.Format = DateTimePickerFormat.Custom;
                dtShareDate.CustomFormat = " ";

            }

        }


        private void btnSave_Click_1(object sender, EventArgs e)
        {
            ReportSaveInfo();
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

                //특정 사업부인 경우 Tag에 저장된 사업부를 제외하고 보이지 않기 위해
                if (MPCF.Trim(cdvDept.Tag) != "")
                {
                    for (int i = cdvDept.GetListView.Items.Count; i > 0; i--)
                    {
                        if (cdvDept.GetListView.Items[i - 1].SubItems[0].Text != cdvDept.Tag.ToString())
                        {
                            cdvDept.GetListView.Items[i - 1].Remove();
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvCustName_ButtonPress(object sender, EventArgs e)
        {
            //고객사 팝업으로 변경
            try
            {
                frmPopCustomerList popup = new frmPopCustomerList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvCustName.Text = popup.g_CustomerId;
                    this.cdvCustName.DisplayText = popup.g_CustomerDesc;
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

        private void cdvMatid_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMatid.Text = popup.sMat_id;
                    this.txtMatdesc.Text = popup.sMat_Desc;
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
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvAdjusted_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvAdjusted.Init();
                MPCF.InitListView(cdvAdjusted.GetListView);
                cdvAdjusted.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvAdjusted.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvAdjusted.SelectedSubItemIndex = 0;
                cdvAdjusted.DisplaySubItemIndex = 0;

                if (BASLIST.ViewGCMDataList(cdvAdjusted.GetListView, '1', "YESNO") == false)
                {
                    return;
                }




            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvClamCount_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvClamCount.Init();
                MPCF.InitListView(cdvClamCount.GetListView);
                cdvClamCount.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvClamCount.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvClamCount.SelectedSubItemIndex = 0;
                cdvClamCount.DisplaySubItemIndex = 0;

                if (BASLIST.ViewGCMDataList(cdvClamCount.GetListView, '1', "YESNO") == false)
                {
                    return;
                }
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
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool ViewGCMDataList_Grade(Control Form_control, char c_step, string table_name, string Area)
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

        private void dtEventDate_ValueChanged(object sender, EventArgs e)
        {
            dtEventDate.CustomFormat = "yyyy-MM-dd";
        }

        private void dtReceiveddate2_ValueChanged(object sender, EventArgs e)
        {
            dtReceiveddate2.CustomFormat = "yyyy-MM-dd";
        }

        private void dtShareDate_ValueChanged(object sender, EventArgs e)
        {
            dtShareDate.CustomFormat = "yyyy-MM-dd";
        }

        private void dtReceiveddate_ValueChanged(object sender, EventArgs e)
        {
            dtReceiveddate.CustomFormat = "yyyy-MM-dd";
        }

        private void dtClosureDate_ValueChanged(object sender, EventArgs e)
        {
            dtClosureDate.CustomFormat = "yyyy-MM-dd";
        }
        private void dtEventDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtEventDate.CustomFormat = " ";
                    break;
            }
        }

        private void dtReceiveddate2_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtReceiveddate2.CustomFormat = " ";
                    break;
            }
        }

        private void dtShareDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtShareDate.CustomFormat = " ";
                    break;
            }
        }

        private void dtReceiveddate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtReceiveddate.CustomFormat = " ";
                    break;
            }
        }

        private void dtClosureDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtClosureDate.CustomFormat = " ";
                    break;
            }
        }

        private void btnFileDown1_Click(object sender, EventArgs e)
        {
            string image_file = string.Empty;

            //int iActiveRow = spdFileRegistration.ActiveSheet.ActiveRowIndex;

            SaveFileDialog dialog = new SaveFileDialog();
            dialog.Title = "파일 위치 지정";
            //Environment.GetFolderPath(Environment.SpecialFolder.Startup).ToString() 
            //Environment.GetFolderPath(Environment.SpecialFolder.CommonPictures).ToString() 
            // dialog.FileName = Environment.GetFolderPath(Environment.SpecialFolder.Startup).ToString() + "\\" + txtReportNo.Text + "_고객불만통보서" + ".pdf";
            dialog.FileName = "불만번호_" + txtReportNo.Text + "_고객불만통보서" + ".pdf";

            dialog.Filter = "PDF (*.PDF) | *.PDF | 모든 파일 (*.*) | *.*";

            if (dialog.ShowDialog() == DialogResult.OK)
            {



                ByteArrayToPdf(txtFileNo1.Text, dialog.FileName);
            }
            else
            {
                return;
            }
        }

        private void btnFileDown2_Click(object sender, EventArgs e)
        {
            string image_file = string.Empty;

            //int iActiveRow = spdFileRegistration.ActiveSheet.ActiveRowIndex;

            SaveFileDialog dialog = new SaveFileDialog();
            dialog.Title = "파일 위치 지정";
            //Environment.GetFolderPath(Environment.SpecialFolder.Startup).ToString() 
            //Environment.GetFolderPath(Environment.SpecialFolder.CommonPictures).ToString() 
            // dialog.FileName = Environment.GetFolderPath(Environment.SpecialFolder.Startup).ToString() + "\\" + txtReportNo.Text + "_분석보고서" + ".pdf";
            dialog.FileName = "불만번호_" + txtReportNo.Text + "_분석보고서" + ".pdf";
            dialog.Filter = "PDF (*.PDF) | *.PDF | 모든 파일 (*.*) | *.*";

            if (dialog.ShowDialog() == DialogResult.OK)
            {



                ByteArrayToPdf(txtFileNo2.Text, dialog.FileName);
            }
            else
            {
                return;
            }
        }

        private void btnNew_Click(object sender, EventArgs e)
        {
            ResetControls(this);
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {

            //정말삭제하시겠습니까?
            if (MPCF.ShowMsgBox(MPCF.GetMessage(453), MessageBoxButtons.YesNo, 1) == DialogResult.No)
            {
                return;
            }

            //삭제 플레그 D
            cdvClaimStatus.Text = "D";

            ReportSaveInfo();

        }

        #endregion

        #region " Function Definition "

        private void cdvFilePath1_ButtonPress(object sender, EventArgs e)
        {

            string sfullPath = "";
            string sFileNo = "";
            if (txtReportNo.Text == "")
            {
                MPCF.ShowMsgBox("접수번호생성후 저장 가능합니다.저장을 먼저해주세요.");
                return;
            }

            openFileDialog1.Reset();
            openFileDialog1.Filter = "Images Files(*.pdf)|*.pdf";
            openFileDialog1.DefaultExt = "pdf";

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {

                sfullPath = openFileDialog1.FileName;
                cdvFilePath1.Text = sfullPath;

                fnRegistrationFile(txtFileNo1.Text, "CLAIM_FILE", "CLAIM_FILE_01", sfullPath, ref sFileNo);

                // fnRegistrationFile(iActiveRow, fullPath);

            }

            if(sFileNo.Trim().Length > 0)
            {
                txtFileNo1.Text = sFileNo;
            }


        }

        private void cdvFilePath2_ButtonPress(object sender, EventArgs e)
        {
            string sfullPath = "";
            string sFileNo = "";
            if (txtReportNo.Text == "")
            {
                MPCF.ShowMsgBox("접수번호생성후 저장 가능합니다.저장을 먼저해주세요.");
                return;
            }

            openFileDialog1.Reset();
            openFileDialog1.Filter = "Images Files(*.pdf)|*.pdf";
            openFileDialog1.DefaultExt = "pdf";

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {

                sfullPath = openFileDialog1.FileName;
                cdvFilePath2.Text = sfullPath;

                fnRegistrationFile(txtFileNo2.Text, "CLAIM_FILE", "CLAIM_FILE_01", sfullPath, ref sFileNo);

                // fnRegistrationFile(iActiveRow, fullPath);

            }

            if (sFileNo.Trim().Length > 0)
            {
                txtFileNo2.Text = sFileNo;
            }

        }

        private void fnRegistrationFile(string sFileNo, string Image_code, string Image_Name, string sfullPath, ref string sOutFileNo)
        {

            try
            {

                FileInfo _fileInfo;

                _fileInfo = new FileInfo(sfullPath);

                //DB 저장
                TRSNode in_node = new TRSNode("Update_File_In");
                TRSNode out_node = new TRSNode("Update_File_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '4';

                string sFileType = Path.GetExtension(sfullPath).Replace(".", "");

                in_node.AddString("FILE_NO", sFileNo);


                in_node.AddString("IMAGE_CODE", Image_code);

                in_node.AddString("FILE_TYPE", sFileType);

                in_node.AddString("FILE_NAME", Image_Name);

                in_node.AddString("AREA_ID", cdvDept.Text);

                in_node.AddString("CMF_1", txtReportNo.Text);


                BinaryReader br;
                byte[] file_buffer;
                if (_fileInfo.Exists == true)
                {
                    br = new BinaryReader(_fileInfo.OpenRead());
                    file_buffer = br.ReadBytes((int)_fileInfo.Length);
                    in_node.AddBlob(MPGC.MP_BIN_DATA_1, file_buffer);
                    in_node.AddInt("IMAGE_SIZE", _fileInfo.Length);
                    br.Close();
                }

                if (MPCR.CallService("CUS_QCM", "CUS_QCM_File_Attach", in_node, ref out_node) == false)
                {
                    return;
                }

                sOutFileNo = out_node.GetString("FILE_NO");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }


        }

        private void ViewSearchData()
        {
            TRSNode in_node = new TRSNode("VIEW_SHIPPING_LOT_IN ");
            TRSNode out_node = new TRSNode("VIEW_SHIPPING_LOT_OUT");

            try
            {



                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                string LossOper = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REPORT_NO";
                dvcArgu[1].sCondition_Value = txtReportNo.Text;




                if (TPDR.GetDataOne("", ref dt, "CQCM3015-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();


                    MPCF.ClearList(spdLossInfo);
                    return;
                }

                cdvCustName.Text = dt.Rows[i]["CUST_NO"].ToString();
                cdvCustName.DisplayText = dt.Rows[i]["CUST_NAME"].ToString();
                dtEventDate.Text = MPCF.MakeDateFormat(dt.Rows[i]["EVENT_DATE"].ToString(), DATE_TIME_FORMAT.DATE); //dt.Rows[i]["EVENT_DATE"].ToString();
                dtReceiveddate.Text = MPCF.MakeDateFormat(dt.Rows[i]["RECEIVED_DATE_1"].ToString(), DATE_TIME_FORMAT.DATE);//dt.Rows[i]["RECEIVED_DATE_1"].ToString();
                dtReceiveddate2.Text = MPCF.MakeDateFormat(dt.Rows[i]["RECEIVED_DATE_2"].ToString(), DATE_TIME_FORMAT.DATE);//dt.Rows[i]["RECEIVED_DATE_1"].ToString();
                cdvGrade.Text = dt.Rows[i]["GRADE"].ToString();
                cdvMatid.Text = dt.Rows[i]["MAT_ID"].ToString();
                txtMatdesc.Text = dt.Rows[i]["MAT_DESC"].ToString();
                dtClosureDate.Text = MPCF.MakeDateFormat(dt.Rows[i]["CLOSURE_DATE"].ToString(), DATE_TIME_FORMAT.DATE);//dt.Rows[i]["CLOSURE_DATE"].ToString();
                dtShareDate.Text = MPCF.MakeDateFormat(dt.Rows[i]["SHARE_DATE"].ToString(), DATE_TIME_FORMAT.DATE);//dt.Rows[i]["SHARE_DATE"].ToString();
                cdvSalGroup.Text = dt.Rows[i]["SAL_GROUP"].ToString();
                cdvSalGroup.DisplayText = dt.Rows[i]["SAL_GROUP_DESC"].ToString();
                txtSalUser.Text = dt.Rows[i]["SAL_USER"].ToString();
                cdvClaimStatus.Text = dt.Rows[i]["CLAIM_STATUS"].ToString();
                cdvClaimStatus.DisplayText = dt.Rows[i]["CLAIM_STATUS_DESC"].ToString();

                cdvClameLevel.Text = dt.Rows[i]["CLAIM_LEVEL"].ToString();
                cdvClamCount.Text = dt.Rows[i]["CLAIM_COUNT_FLAG"].ToString();
                cdvAdjusted.Text = dt.Rows[i]["CLAIM_ADJUSTED_FLAG"].ToString();
                txtCostQty.Text = dt.Rows[i]["COST_QTY_01"].ToString();
                cdvCostMonth.Text = dt.Rows[i]["COST_MONTH"].ToString();
                txtFileNo1.Text = dt.Rows[i]["FILE_NO_01"].ToString();
                txtFileNo2.Text = dt.Rows[i]["FILE_NO_02"].ToString();
                txtComment1.Text = dt.Rows[i]["COMMENT_01"].ToString();
                txtComment2.Text = dt.Rows[i]["COMMENT_02"].ToString();
                txtComment3.Text = dt.Rows[i]["COMMENT_03"].ToString();
                cdvGrade2.Text = dt.Rows[i]["CMF_01"].ToString();
                cdvDept.Text = dt.Rows[i]["CMF_02"].ToString();


                switch (cdvDept.Text)
                {
                    case CSGC.CP_AREA_CTM:
                        LossOper = "CW-RMA";
                        break;
                    case CSGC.CP_AREA_PDC:
                        LossOper = "PW-RMA";
                        break;
                    case CSGC.CP_AREA_GRT:
                        LossOper = "GW-RMA";
                        break;

                    case CSGC.CP_AREA_HM:
                        LossOper = "HW-RMA";
                        break;

                }

                ViewInspectionLossInfo(txtReportNo.Text, LossOper);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool ReportSaveInfo()
        {

            TRSNode loss_list;

            TRSNode in_node = new TRSNode("Report_In");
            TRSNode out_node = new TRSNode("Report_Out");
            // TRSNode loss_list;

            int i = 0;
            string LossOper = "";
            // double d_loss_qty = 0;

            try
            {
                MPCR.SetInMsg(in_node);

                if (txtReportNo.Text.Trim().ToString() == "")
                {
                    //신규
                    in_node.ProcStep = '1';
                }
                else
                {
                    //수정
                    in_node.ProcStep = '2';
                    in_node.AddString("REPORT_NO", txtReportNo.Text);
                }




                in_node.AddString("CUST_NO", cdvCustName.Text);
                in_node.AddString("CUST_NAME", cdvCustName.DisplayText);
                in_node.AddString("EVENT_DATE", dtEventDate.Text.Replace("-", ""));
                in_node.AddString("RECEIVED_DATE_1", dtReceiveddate.Text.Replace("-", ""));
                in_node.AddString("RECEIVED_DATE_2", dtReceiveddate2.Text.Replace("-", ""));
                in_node.AddString("GRADE", cdvGrade.Text);
                in_node.AddString("MAT_ID", cdvMatid.Text);
                in_node.AddString("MAT_DESC", txtMatdesc.Text);
                in_node.AddString("CLOSURE_DATE", dtClosureDate.Text.Replace("-", ""));
                in_node.AddString("SHARE_DATE", dtShareDate.Text.Replace("-", ""));
                in_node.AddString("SAL_GROUP", cdvSalGroup.Text);
                in_node.AddString("SAL_USER", txtSalUser.Text);


                //상태값 입력없으면 대기상태
                if (cdvClaimStatus.Text == "")
                {
                    in_node.AddString("CLAIM_STATUS", "Q");
                }
                else
                {
                    in_node.AddString("CLAIM_STATUS", cdvClaimStatus.Text);
                }

                in_node.AddString("CLAIM_LEVEL", cdvClameLevel.Text);
                in_node.AddString("CLAIM_COUNT_FLAG", cdvClamCount.Text);
                in_node.AddString("CLAIM_ADJUSTED_FLAG", cdvAdjusted.Text);
                in_node.AddInt("COST_QTY_01", MPCF.ToInt(txtCostQty.Text));
                in_node.AddInt("COST_MONTH", MPCF.ToInt(cdvCostMonth.Text));
                in_node.AddString("FILE_NO_01", txtFileNo1.Text);
                in_node.AddString("FILE_NO_02", txtFileNo2.Text);
                in_node.AddString("COMMENT_01", txtComment1.Text);
                in_node.AddString("COMMENT_02", txtComment2.Text);
                in_node.AddString("COMMENT_03", txtComment3.Text);
                in_node.AddString("CMF_01", cdvGrade2.Text);
                in_node.AddString("CMF_02", cdvDept.Text);




                switch (cdvDept.Text)
                {
                    case CSGC.CP_AREA_CTM:
                        LossOper = "CW-RMA";
                        break;
                    case CSGC.CP_AREA_PDC:
                        LossOper = "PW-RMA";
                        break;
                    case CSGC.CP_AREA_GRT:
                        LossOper = "GW-RMA";
                        break;

                    case CSGC.CP_AREA_HM:
                        LossOper = "HW-RMA";
                        break;

                }

                for (i = 0; i < spdLossInfo_Sheet1.RowCount; i++)
                {
                    if (MPCF.ToDbl(spdLossInfo_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_QTY].Text) != 0)
                    {
                        loss_list = in_node.AddNode("LOSS_LIST");
                        loss_list.AddString("LOSS_CODE", spdLossInfo_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_CODE].Text);
                        loss_list.AddDouble("LOSS_QTY", spdLossInfo_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_QTY].Text);
                        loss_list.AddString("LOSS_OPER", LossOper);

                        if (spdLossInfo.ActiveSheet.Cells[i, (int)LOSS_INFO.MAIN_YN].Value.ToString().ToUpper() == "TRUE")
                        {
                            loss_list.AddChar("MAIN_FLAG", 'Y');
                        }
                        else
                        {
                            loss_list.AddChar("MAIN_FLAG", 'N');
                        }

                    }
                }



                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Update_CUS_QCM_Customer_Claim", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);

                if (out_node.GetString("REPORT_NO") != "")
                {
                    txtReportNo.Text = out_node.GetString("REPORT_NO");
                }


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




                //sfilePath = Environment.GetEnvironmentVariable("TEMP") + "\\" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".pdf";

                FileStream fs = System.IO.File.Open(sfilePath, FileMode.Create);
                BinaryWriter writer = new BinaryWriter(fs);
                writer.Write(bt_buffer, 0, bt_buffer.Length);
                writer.Close();


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

        private void ResetControls(Control parent)
        {
            foreach (Control control in parent.Controls)
            {
                if (control is TextBox textBox)
                {
                    textBox.Text = string.Empty; // 텍스트박스 초기화
                }
                else if (control is ComboBox comboBox)
                {
                    comboBox.SelectedIndex = -1; // 콤보박스 선택 초기화
                }
                else if (control is DateTimePicker DateTimePicker)
                {
                    if (DateTimePicker.Name == "dtEventDate")
                    {
                        DateTimePicker.Value = DateTime.Now;
                    }
                    else
                    {
                        DateTimePicker.Format = DateTimePickerFormat.Custom;
                        DateTimePicker.CustomFormat = " "; // Date 초기화

                    }
                }
                else if (control.Controls.Count > 0)
                {
                    // 자식 컨트롤이 있으면 재귀적으로 초기화
                    ResetControls(control);
                }
            }

            MPCF.ClearList(spdLossInfo);
        }


        private void ViewInspectionLossInfo(string inspID, string oper)
        {
            try
            {
                //  b_allow_changed = false;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_ID";
                dvcArgu[1].sCondition_Value = inspID;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = oper;

                // 검사 첨부파일 리스트 조회
                if (TPDR.GetDataOne("", ref dt, "CQCM3015-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLossInfo);
                    return;
                }

                MPCF.ClearList(spdLossInfo);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLossInfo.ActiveSheet.RowCount++;

                    spdLossInfo.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_CODE].Value = dt.Rows[i]["LOSS_CODE"];
                    spdLossInfo.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_DESC].Value = dt.Rows[i]["LOSS_DESC"];
                    //spdLossInfo.ActiveSheet.Cells[i, (int)LOSS_INFO.HM_INPUT_QTY].Value = dt.Rows[i]["HM_INPUT_QTY"];

                    spdLossInfo.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_QTY].Value = dt.Rows[i]["LOSS_QTY"];
                    spdLossInfo.ActiveSheet.Cells[i, (int)LOSS_INFO.MAIN_YN].Value = dt.Rows[i]["MAIN_YN"].ToString() == "Y" ? true : false;

                }
                MPCF.FitColumnHeader(spdLossInfo);
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion
    }
}
