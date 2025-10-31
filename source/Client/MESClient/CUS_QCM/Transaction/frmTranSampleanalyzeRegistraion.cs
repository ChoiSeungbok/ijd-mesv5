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
using FarPoint.Win.Spread.CellType;
using Miracom.UI.Controls.MCCodeView;
using Miracom.UI;

namespace CUS_QCM
{
    public partial class frmTranSampleanalyzeRegistraion : CUS_COM.frmViewForm01
    {
        public frmTranSampleanalyzeRegistraion()
        {
            InitializeComponent();

            InitControl();
        }
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
        string gFileServer_Ip;
        string gFileServer_PORT;
        string gFileServer_Dir;
        string gFileServer_ID;
        string gFileServer_PW;
        public string gReportNo = "";
        #endregion

        private void InitControl()
        {
            try
            {
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                string table_name = "C_FILE_SERVER";
                ListView listView = new ListView();
                listView.Columns.Add("CODE");
                listView.Columns.Add("IP");
                listView.Columns.Add("PORT");
                listView.Columns.Add("DIRECTORY");
                listView.Columns.Add("ID");
                listView.Columns.Add("PW");
                if (BASLIST.ViewGCMDataList(listView, '1', table_name))
                {
                    ListViewItem listViewItem = listView.FindItemWithText(MPGV.gsFactory);
                    gFileServer_Ip = listViewItem.SubItems[1].Text;
                    gFileServer_PORT = listViewItem.SubItems[2].Text;
                    gFileServer_Dir = "MESplusV5/upgrade/PDA";
                    gFileServer_ID = listViewItem.SubItems[4].Text;
                    gFileServer_PW = listViewItem.SubItems[5].Text;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewSearchData()
        {
            TRSNode tRSNode = new TRSNode("VIEW_SHIPPING_LOT_IN ");
            TRSNode tRSNode2 = new TRSNode("VIEW_SHIPPING_LOT_OUT");
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int index = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "REPORT_NO";
                array[1].sCondition_Value = txtReportNo.Text;
                if (!TPDR.GetDataOne("", ref dt, "CQCM3017-003", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    return;
                }
                cdvCustName.Text = dt.Rows[index]["CUST_NO"].ToString();
                cdvCustName.DisplayText = dt.Rows[index]["CUST_NAME"].ToString();
                dtEventDate.Text = MPCF.MakeDateFormat(dt.Rows[index]["EVENT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                dtReceiveddate.Text = MPCF.MakeDateFormat(dt.Rows[index]["RECEIVED_DATE_1"].ToString(), DATE_TIME_FORMAT.DATE);
                dtReceiveddate2.Text = MPCF.MakeDateFormat(dt.Rows[index]["RECEIVED_DATE_2"].ToString(), DATE_TIME_FORMAT.DATE);
                cdvGrade.Text = dt.Rows[index]["GRADE"].ToString();
                dtClosureDate.Text = MPCF.MakeDateFormat(dt.Rows[index]["CLOSURE_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                dtShareDate.Text = MPCF.MakeDateFormat(dt.Rows[index]["SHARE_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                cdvSalGroup.Text = dt.Rows[index]["SAL_GROUP"].ToString();
                cdvSalGroup.DisplayText = dt.Rows[index]["SAL_GROUP_DESC"].ToString();
                txtSalUser.Text = dt.Rows[index]["SAL_USER"].ToString();
                cdvAnalyzeStatus.Text = dt.Rows[index]["ANALYZE_STATUS"].ToString();
                cdvAnalyzeStatus.DisplayText = dt.Rows[index]["ANALYZE_STATUS_DESC"].ToString();
                txtFileNo1.Text = dt.Rows[index]["FILE_NO_01"].ToString();
                txtFileNo2.Text = dt.Rows[index]["FILE_NO_02"].ToString();
                txtComment1.Text = dt.Rows[index]["COMMENT_01"].ToString();
                txtComment2.Text = dt.Rows[index]["COMMENT_02"].ToString();
                cdvGrade2.Text = dt.Rows[index]["CMF_01"].ToString();
                cdvDept.Text = dt.Rows[index]["CMF_02"].ToString();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool ReportSaveInfo()
        {
            TRSNode tRSNode = new TRSNode("Report_In");
            TRSNode out_node = new TRSNode("Report_Out");
            try
            {
                MPCR.SetInMsg(tRSNode);
                if (txtReportNo.Text.Trim().ToString() == "")
                {
                    tRSNode.ProcStep = '1';
                }
                else
                {
                    tRSNode.ProcStep = '2';
                    tRSNode.AddString("REPORT_NO", txtReportNo.Text);
                }
                tRSNode.AddString("CUST_NO", cdvCustName.Text);
                tRSNode.AddString("CUST_NAME", cdvCustName.DisplayText);
                tRSNode.AddString("EVENT_DATE", dtEventDate.Text.Replace("-", ""));
                tRSNode.AddString("RECEIVED_DATE_1", dtReceiveddate.Text.Replace("-", ""));
                tRSNode.AddString("RECEIVED_DATE_2", dtReceiveddate2.Text.Replace("-", ""));
                tRSNode.AddString("GRADE", cdvGrade.Text);
                tRSNode.AddString("CLOSURE_DATE", dtClosureDate.Text.Replace("-", ""));
                tRSNode.AddString("SHARE_DATE", dtShareDate.Text.Replace("-", ""));
                tRSNode.AddString("SAL_GROUP", cdvSalGroup.Text);
                tRSNode.AddString("SAL_USER", txtSalUser.Text);
                if (cdvAnalyzeStatus.Text == "")
                {
                    tRSNode.AddString("ANALYZE_STATUS", "Q");
                }
                else
                {
                    tRSNode.AddString("ANALYZE_STATUS", cdvAnalyzeStatus.Text);
                }
                tRSNode.AddString("FILE_NO_01", txtFileNo1.Text);
                tRSNode.AddString("FILE_NO_02", txtFileNo2.Text);
                tRSNode.AddString("COMMENT_01", txtComment1.Text);
                tRSNode.AddString("COMMENT_02", txtComment2.Text);
                tRSNode.AddString("CMF_01", cdvGrade2.Text);
                tRSNode.AddString("CMF_02", cdvDept.Text);
                if (!MPCR.CallService("CUS_QCM", "CUS_QCM_Update_CUS_QCM_Sample_Analysis", tRSNode, ref out_node))
                {
                    return false;
                }
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
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "FILE_NO";
                array[1].sCondition_Value = sFileNo;
                if (!TPDR.GetDataOne("", ref dt, "CQCM2001-005", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    return;
                }
                byte[] array2 = (byte[])dt.Rows[0]["IMAGE_DATA"];
                FileStream output = System.IO.File.Open(sfilePath, FileMode.Create);
                BinaryWriter binaryWriter = new BinaryWriter(output);
                binaryWriter.Write(array2, 0, array2.Length);
                binaryWriter.Close();
                MPCF.ShowMsgBox(MPCF.GetMessage(576));
                Process.Start(new ProcessStartInfo(sfilePath)
                {
                    UseShellExecute = true
                });
                if (MPCF.ShowMsgBox(MPCF.GetMessage(597), MessageBoxButtons.YesNo, 2) == DialogResult.Yes)
                {
                    Process.Start(new ProcessStartInfo(sfilePath)
                    {
                        UseShellExecute = true
                    });
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ResetControls(Control parent)
        {
            foreach (Control control in parent.Controls)
            {
                if (control is TextBox textBox)
                {
                    textBox.Text = string.Empty;
                }
                else if (control is ComboBox comboBox)
                {
                    comboBox.SelectedIndex = -1;
                }
                else if (control is DateTimePicker dateTimePicker)
                {
                    if (dateTimePicker.Name == "dtEventDate")
                    {
                        dateTimePicker.Value = DateTime.Now;
                        continue;
                    }
                    dateTimePicker.Format = DateTimePickerFormat.Custom;
                    dateTimePicker.CustomFormat = " ";
                }
                else if (control.Controls.Count > 0)
                {
                    ResetControls(control);
                }
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvGrade.Text = "";
                cdvGrade2.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
        }

        private void btnProcess_Click(object sender, EventArgs e)
        {
        }

        private void frmTranSampleanalyzeRegistraion_Load(object sender, EventArgs e)
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
                return;
            }
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

        private void cdvFile_ButtonPress(object sender, EventArgs e)
        {
            ofdFile.Reset();
            ofdFile.Filter = "JPEG File(*.jpg)|*.jpg";
            ofdFile.DefaultExt = "jpg";
            ofdFile.FileName = cdvFilePath2.Text;
            if (ofdFile.ShowDialog() == DialogResult.OK)
            {
                cdvFilePath2.Text = ofdFile.FileName;
            }
        }

        private void panel6_Paint(object sender, PaintEventArgs e)
        {
        }

        private void label1_Click(object sender, EventArgs e)
        {
        }

        private void splitContainer2_Panel1_Paint(object sender, PaintEventArgs e)
        {
        }

        private void ultraGroupBox1_Click(object sender, EventArgs e)
        {
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

        private void cdvCustName_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopCustomerList frmPopCustomerList = new frmPopCustomerList();
                frmPopCustomerList.StartPosition = FormStartPosition.CenterParent;
                if (frmPopCustomerList.ShowDialog() == DialogResult.OK)
                {
                    cdvCustName.Text = frmPopCustomerList.g_CustomerId;
                    cdvCustName.DisplayText = frmPopCustomerList.g_CustomerDesc;
                    frmPopCustomerList = null;
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
                if (BASLIST.ViewGCMDataList(cdvSalGroup.GetListView, '1', "C_SAL_GROUP"))
                {
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
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }
                cdvGrade.Init();
                MPCF.InitListView(cdvGrade.GetListView);
                cdvGrade.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvGrade.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                if (ViewGCMDataList_Grade(cdvGrade.GetListView, '1', "C_AREA_MAT_GROUP_1", cdvDept.Text))
                {
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
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }
                cdvGrade2.Init();
                MPCF.InitListView(cdvGrade2.GetListView);
                cdvGrade2.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvGrade2.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                if (ViewGCMDataList_Grade(cdvGrade2.GetListView, '1', "C_AREA_MAT_GROUP_2", cdvDept.Text))
                {
                }
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
                if (BASLIST.ViewGCMDataList(cdvAnalyzeStatus.GetListView, '1', "C_CLAIM_STATUS"))
                {
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool ViewGCMDataList_Grade(Control Form_control, char c_step, string table_name, string Area)
        {
            int num = -1;
            string[] array = null;
            List<string> list = new List<string>();
            TRSNode tRSNode = new TRSNode("VIEW_DATA_LIST_IN");
            ArrayList arrayList = new ArrayList();
            num = 14;
            if (Form_control is ListView)
            {
                MPCF.InitListView((ListView)Form_control);
            }
            else if (!(Form_control is TreeView))
            {
                MPCF.ClearList(Form_control, ComboBoxSpaceAddFlag: true);
            }
            if (Form_control is MCCodeDropList)
            {
                ((MCCodeDropList)Form_control).GCMTableName = table_name;
            }
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = c_step;
            tRSNode.AddString("TABLE_NAME", table_name);
            tRSNode.AddString("NEXT_KEY_1", "");
            tRSNode.AddString("NEXT_KEY_2", "");
            do
            {
                TRSNode out_node = new TRSNode("VIEW_DATA_LIST_OUT");
                if (!MPCR.CallService("BAS", "BAS_View_Data_List", tRSNode, ref out_node, b_ignore_message: false))
                {
                    return false;
                }
                arrayList.Add(out_node);
                tRSNode.SetString("NEXT_KEY_1", out_node.GetString("NEXT_KEY_1"));
                tRSNode.SetString("NEXT_KEY_2", out_node.GetString("NEXT_KEY_2"));
            }
            while (tRSNode.GetString("NEXT_KEY_1") != "" || tRSNode.GetString("NEXT_KEY_2") != "");
            int i;
            foreach (object item in arrayList)
            {
                TRSNode out_node = null;
                out_node = (TRSNode)item;
                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    if (!(out_node.GetList(0)[i].GetString("KEY_1") == MPCF.Trim(Area)))
                    {
                        continue;
                    }
                    if (Form_control is ListView)
                    {
                        ListViewItem listViewItem = new ListViewItem(out_node.GetList(0)[i].GetString("KEY_2"), num);
                        if (((ListView)Form_control).Columns.Count > 1)
                        {
                            for (int j = 0; j <= ((ListView)Form_control).Columns.Count - 1; j++)
                            {
                                if (j == 0)
                                {
                                    listViewItem.SubItems.Add(out_node.GetList(0)[i].GetString("KEY_2"));
                                }
                            }
                        }
                        ((ListView)Form_control).Items.Add(listViewItem);
                    }
                    else if (Form_control is FpSpread)
                    {
                        SheetView activeSheet = ((FpSpread)Form_control).ActiveSheet;
                        if (activeSheet.Columns.Count == 2)
                        {
                            int rowCount = activeSheet.RowCount;
                            activeSheet.RowCount++;
                            int num2 = 0;
                            activeSheet.Cells[rowCount, num2].Value = out_node.GetList(0)[i].GetString("KEY_2");
                            num2++;
                            activeSheet.Cells[rowCount, num2].Value = out_node.GetList(0)[i].GetString("KEY_1");
                            num2++;
                        }
                        else
                        {
                            list.Add(out_node.GetList(0)[i].GetString("KEY_1"));
                        }
                    }
                }
            }
            if (Form_control is FpSpread && ((FpSpread)Form_control).ActiveSheet.Columns.Count == 3)
            {
                return true;
            }
            array = new string[list.Count + 1];
            for (i = 0; i < list.Count; i++)
            {
                array[i] = list[i];
            }
            array[i] = "";
            ComboBoxCellType comboBoxCellType = new ComboBoxCellType();
            comboBoxCellType.Items = array;
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
            Keys keyCode = e.KeyCode;
            Keys keys = keyCode;
            if (keys == Keys.Delete)
            {
                dtEventDate.CustomFormat = " ";
            }
        }

        private void dtReceiveddate2_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            Keys keyCode = e.KeyCode;
            Keys keys = keyCode;
            if (keys == Keys.Delete)
            {
                dtReceiveddate2.CustomFormat = " ";
            }
        }

        private void dtShareDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            Keys keyCode = e.KeyCode;
            Keys keys = keyCode;
            if (keys == Keys.Delete)
            {
                dtShareDate.CustomFormat = " ";
            }
        }

        private void dtReceiveddate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            Keys keyCode = e.KeyCode;
            Keys keys = keyCode;
            if (keys == Keys.Delete)
            {
                dtReceiveddate.CustomFormat = " ";
            }
        }

        private void dtClosureDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            Keys keyCode = e.KeyCode;
            Keys keys = keyCode;
            if (keys == Keys.Delete)
            {
                dtClosureDate.CustomFormat = " ";
            }
        }

        private void cdvFilePath1_ButtonPress(object sender, EventArgs e)
        {
            string text = "";
            string sOutFileNo = "";
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
                text = openFileDialog1.FileName;
                cdvFilePath1.Text = text;
                fnRegistrationFile(txtFileNo1.Text, "CLAIM_FILE", "CLAIM_FILE_01", text, ref sOutFileNo);
            }
            if (sOutFileNo.Trim().Length > 0)
            {
                txtFileNo1.Text = sOutFileNo;
            }
        }

        private void cdvFilePath2_ButtonPress(object sender, EventArgs e)
        {
            string text = "";
            string sOutFileNo = "";
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
                text = openFileDialog1.FileName;
                cdvFilePath2.Text = text;
                fnRegistrationFile(txtFileNo2.Text, "CLAIM_FILE", "CLAIM_FILE_01", text, ref sOutFileNo);
            }
            if (sOutFileNo.Trim().Length > 0)
            {
                txtFileNo2.Text = sOutFileNo;
            }
        }

        private void fnRegistrationFile(string sFileNo, string Image_code, string Image_Name, string sfullPath, ref string sOutFileNo)
        {
            try
            {
                FileInfo fileInfo = new FileInfo(sfullPath);
                TRSNode tRSNode = new TRSNode("Update_File_In");
                TRSNode out_node = new TRSNode("Update_File_Out");
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '4';
                string value = Path.GetExtension(sfullPath).Replace(".", "");
                tRSNode.AddString("FILE_NO", sFileNo);
                tRSNode.AddString("IMAGE_CODE", Image_code);
                tRSNode.AddString("FILE_TYPE", value);
                tRSNode.AddString("FILE_NAME", Image_Name);
                tRSNode.AddString("AREA_ID", cdvDept.Text);
                tRSNode.AddString("CMF_1", txtReportNo.Text);
                if (fileInfo.Exists)
                {
                    BinaryReader binaryReader = new BinaryReader(fileInfo.OpenRead());
                    byte[] value2 = binaryReader.ReadBytes((int)fileInfo.Length);
                    tRSNode.AddBlob("__BIN_DATA_1", value2);
                    tRSNode.AddInt("IMAGE_SIZE", fileInfo.Length);
                    binaryReader.Close();
                }
                if (MPCR.CallService("CUS_QCM", "CUS_QCM_File_Attach", tRSNode, ref out_node))
                {
                    sOutFileNo = out_node.GetString("FILE_NO");
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnFileDown1_Click(object sender, EventArgs e)
        {
            string empty = string.Empty;
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Title = "파일 위치 지정";
            saveFileDialog.FileName = "불만번호_" + txtReportNo.Text + "_고객불만통보서.pdf";
            saveFileDialog.Filter = "PDF (*.PDF) | *.PDF | 모든 파일 (*.*) | *.*";
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                ByteArrayToPdf(txtFileNo1.Text, saveFileDialog.FileName);
            }
        }

        private void btnFileDown2_Click(object sender, EventArgs e)
        {
            string empty = string.Empty;
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Title = "파일 위치 지정";
            saveFileDialog.FileName = "불만번호_" + txtReportNo.Text + "_분석보고서.pdf";
            saveFileDialog.Filter = "PDF (*.PDF) | *.PDF | 모든 파일 (*.*) | *.*";
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                ByteArrayToPdf(txtFileNo2.Text, saveFileDialog.FileName);
            }
        }

        private void btnNew_Click(object sender, EventArgs e)
        {
            ResetControls(this);
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            if (MPCF.ShowMsgBox(MPCF.GetMessage(453), MessageBoxButtons.YesNo, 1) != DialogResult.No)
            {
                cdvAnalyzeStatus.Text = "D";
                ReportSaveInfo();
            }
        }

        private void btnFileManager_Click(object sender, EventArgs e)
        {
            if (txtReportNo.Text.Trim().Length != 0)
            {
                frmPopFtpUpDown frmPopFtpUpDown = new frmPopFtpUpDown();
                frmPopFtpUpDown.StartPosition = FormStartPosition.CenterParent;
                frmPopFtpUpDown.g_PopYn = "Y";
                frmPopFtpUpDown.g_LotId = txtReportNo.Text;
                frmPopFtpUpDown.g_Area_Id = cdvDept.Text;
                frmPopFtpUpDown.g_SearchType = "B";
                if (frmPopFtpUpDown.ShowDialog() == DialogResult.OK)
                {
                    frmPopFtpUpDown = null;
                }
            }
            else
            {
                MPCF.ShowMsgBox("접수번호생성후 저장 가능합니다.저장을 먼저해주세요.");
            }
        }
    }
}
