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
using System.IO;
using System.Diagnostics;

namespace CUS_QCM
{
    public partial class frmTranCustomerVocRegistraion : CUS_COM.frmViewForm01
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
        public frmTranCustomerVocRegistraion()
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

        }

        private void btnView_Click(object sender, EventArgs e)
        {

        }

        private void frmTranCustomerVocRegistraion_Load(object sender, EventArgs e)
        {

            dtClosureDate.Value = DateTime.Now;
            dtEventDate.Value = DateTime.Now;
            dtReceiveddate.Value = DateTime.Now;
            dtReceiveddate2.Value = DateTime.Now;





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



            }

        }

        private void splitContainer2_Panel1_Paint(object sender, PaintEventArgs e)
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

        private void dtEventDate_ValueChanged(object sender, EventArgs e)
        {
            dtEventDate.CustomFormat = "yyyy-MM-dd";
        }

        private void dtReceiveddate2_ValueChanged(object sender, EventArgs e)
        {
            dtReceiveddate2.CustomFormat = "yyyy-MM-dd";
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

            if (sFileNo.Trim().Length > 0)
            {
                txtFileNo1.Text = sFileNo;
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

        private void btnNew_Click(object sender, EventArgs e)
        {
            ResetControls(this);
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


                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REPORT_NO";
                dvcArgu[1].sCondition_Value = txtReportNo.Text;




                if (TPDR.GetDataOne("", ref dt, "CQCM3019-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                cdvCustName.Text = dt.Rows[i]["CUST_NO"].ToString();
                cdvCustName.DisplayText = dt.Rows[i]["CUST_NAME"].ToString();
                dtEventDate.Text = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_DATE"].ToString(), DATE_TIME_FORMAT.DATE); //dt.Rows[i]["EVENT_DATE"].ToString();
                dtReceiveddate.Text = MPCF.MakeDateFormat(dt.Rows[i]["RECEIVED_DATE_1"].ToString(), DATE_TIME_FORMAT.DATE);//dt.Rows[i]["RECEIVED_DATE_1"].ToString();
                dtReceiveddate2.Text = MPCF.MakeDateFormat(dt.Rows[i]["RECEIVED_DATE_2"].ToString(), DATE_TIME_FORMAT.DATE);//dt.Rows[i]["RECEIVED_DATE_1"].ToString();

                dtClosureDate.Text = MPCF.MakeDateFormat(dt.Rows[i]["CLOSURE_DATE"].ToString(), DATE_TIME_FORMAT.DATE);//dt.Rows[i]["CLOSURE_DATE"].ToString();

                cdvSalGroup.Text = dt.Rows[i]["SAL_GROUP"].ToString();
                cdvSalGroup.DisplayText = dt.Rows[i]["SAL_GROUP_DESC"].ToString();
                txtSalUser.Text = dt.Rows[i]["SAL_USER"].ToString();
                cdvClaimStatus.Text = dt.Rows[i]["VOC_STATUS"].ToString();
                cdvClaimStatus.DisplayText = dt.Rows[i]["VOC_STATUS_DESC"].ToString();


                txtCostQty.Text = dt.Rows[i]["COST_QTY_01"].ToString();

                txtFileNo1.Text = dt.Rows[i]["FILE_NO_01"].ToString();

                txtComment1.Text = dt.Rows[i]["COMMENT_01"].ToString();
                txtComment2.Text = dt.Rows[i]["COMMENT_02"].ToString();

                cdvDept.Text = dt.Rows[i]["CMF_02"].ToString();


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
        private bool ReportSaveInfo()
        {


            TRSNode in_node = new TRSNode("Report_In");
            TRSNode out_node = new TRSNode("Report_Out");
            // TRSNode loss_list;


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
                in_node.AddString("CREATE_DATE", dtEventDate.Text.Replace("-", ""));
                in_node.AddString("RECEIVED_DATE_1", dtReceiveddate.Text.Replace("-", ""));
                in_node.AddString("RECEIVED_DATE_2", dtReceiveddate2.Text.Replace("-", ""));

                in_node.AddString("CLOSURE_DATE", dtClosureDate.Text.Replace("-", ""));

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


                in_node.AddInt("COST_QTY_01", MPCF.ToInt(txtCostQty.Text));

                in_node.AddString("FILE_NO_01", txtFileNo1.Text);

                in_node.AddString("COMMENT_01", txtComment1.Text);
                in_node.AddString("COMMENT_02", txtComment2.Text);


                in_node.AddString("CMF_02", cdvDept.Text);









                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Update_CUS_QCM_Customer_Voc", in_node, ref out_node) == false)
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

        #endregion

    }
}
