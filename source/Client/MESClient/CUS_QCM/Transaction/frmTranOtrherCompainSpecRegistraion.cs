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
using Miracom.UI.Controls.MCCodeView;
using FarPoint.Excel.EntityClassLibrary.DrawingEx;

namespace CUS_QCM
{
    public partial class frmTranOtrherCompainSpecRegistraion : CUS_COM.frmViewForm01
    {

        public frmTranOtrherCompainSpecRegistraion()
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
        public string sDeptCode = "";

        #endregion

        #region " Function  Definition "
        private void InitControl()
        {
            try
            {
                if (sDeptCode == "")
                {
                    cdvDept.Text = CSGC.CP_AREA_CTM;
                }
                else
                {
                    cdvDept.Text = sDeptCode;
                }
                DataListNameView();

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
        private void DataListNameView()
        {

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                int iData = 0;

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


                for (iData = 1; iData <= 30; iData++)
                {

                    var label = Controls.Find($"lblData{iData:00}", true).FirstOrDefault();
                    var cdv = Controls.Find($"cdvData{iData:00}", true).FirstOrDefault();
                    if (label is Label lbl)
                    {

                        if (dt.Rows[0][iData - 1].ToString().Trim() == "")
                        {
                            lbl.Visible = false;
                            cdv.Visible = false;
                            lbl.Text = "";
                        }
                        else
                        {
                            lbl.Visible = true;
                            cdv.Visible = true;
                            lbl.Text = dt.Rows[0][iData - 1].ToString();



                            switch (dt.Rows[1][iData - 1].ToString())
                            {
                                //N 기본텍스트
                                case "N":
                                case "":
                                    cdv.Tag = "N";
                                    if (cdv is MCCodeView comboBox)
                                    {
                                        comboBox.ButtonWidth = 1;
                                    }

                                    break;

                                //D 날짜
                                case "D":
                                    cdv.Tag = dt.Rows[1][iData - 1].ToString();
                                    if (cdv is MCCodeView comboBox2)
                                    {
                                        comboBox2.ButtonWidth = 30;
                                    }

                                    break;

                                //Y 버튼 
                                case "Y":
                                    cdv.Tag = dt.Rows[2][iData - 1].ToString();

                                    if (cdv is MCCodeView comboBox3)
                                    {
                                        comboBox3.ButtonWidth = 30;
                                    }

                                    break;

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
        private void ViewSearchData()
        {
            TRSNode in_node = new TRSNode("VIEW_DATA_IN ");
            TRSNode out_node = new TRSNode("VIEW_DATA_OUT");

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




                if (TPDR.GetDataOne("", ref dt, "CQCM3020-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                cdvCustName.Text = dt.Rows[i]["CUST_NO"].ToString();
                cdvCustName.DisplayText = dt.Rows[i]["CUST_NAME"].ToString();
                cdvReportType.DisplayText = dt.Rows[i]["REPORT_TYPE"].ToString();
                dtEventDate.Text = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_DATE"].ToString(), DATE_TIME_FORMAT.DATE); //dt.Rows[i]["EVENT_DATE"].ToString();
                cdvGrade.Text = dt.Rows[i]["GRADE"].ToString();
                cdvSalGroup.Text = dt.Rows[i]["SAL_GROUP"].ToString();
                cdvSalGroup.DisplayText = dt.Rows[i]["SAL_GROUP_DESC"].ToString();



                cdvData01.Text = dt.Rows[i]["DATA_01"].ToString();
                cdvData02.Text = dt.Rows[i]["DATA_02"].ToString();
                cdvData03.Text = dt.Rows[i]["DATA_03"].ToString();
                cdvData04.Text = dt.Rows[i]["DATA_04"].ToString();
                cdvData05.Text = dt.Rows[i]["DATA_05"].ToString();
                cdvData06.Text = dt.Rows[i]["DATA_06"].ToString();
                cdvData07.Text = dt.Rows[i]["DATA_07"].ToString();
                cdvData08.Text = dt.Rows[i]["DATA_08"].ToString();
                cdvData09.Text = dt.Rows[i]["DATA_09"].ToString();
                cdvData10.Text = dt.Rows[i]["DATA_10"].ToString();
                cdvData11.Text = dt.Rows[i]["DATA_11"].ToString();
                cdvData12.Text = dt.Rows[i]["DATA_12"].ToString();
                cdvData13.Text = dt.Rows[i]["DATA_13"].ToString();
                cdvData14.Text = dt.Rows[i]["DATA_14"].ToString();
                cdvData15.Text = dt.Rows[i]["DATA_15"].ToString();
                cdvData16.Text = dt.Rows[i]["DATA_16"].ToString();
                cdvData17.Text = dt.Rows[i]["DATA_17"].ToString();
                cdvData18.Text = dt.Rows[i]["DATA_18"].ToString();
                cdvData19.Text = dt.Rows[i]["DATA_19"].ToString();
                cdvData20.Text = dt.Rows[i]["DATA_20"].ToString();
                cdvData21.Text = dt.Rows[i]["DATA_21"].ToString();
                cdvData22.Text = dt.Rows[i]["DATA_22"].ToString();
                cdvData23.Text = dt.Rows[i]["DATA_23"].ToString();
                cdvData24.Text = dt.Rows[i]["DATA_24"].ToString();
                cdvData25.Text = dt.Rows[i]["DATA_25"].ToString();
                cdvData26.Text = dt.Rows[i]["DATA_26"].ToString();
                cdvData27.Text = dt.Rows[i]["DATA_27"].ToString();
                cdvData28.Text = dt.Rows[i]["DATA_28"].ToString();
                cdvData29.Text = dt.Rows[i]["DATA_29"].ToString();
                cdvData30.Text = dt.Rows[i]["DATA_30"].ToString();



                txtFileNo1.Text = dt.Rows[i]["FILE_NO_01"].ToString();
                txtFileNo2.Text = dt.Rows[i]["FILE_NO_02"].ToString();
                txtComment1.Text = dt.Rows[i]["COMMENT_01"].ToString();
                cdvGrade2.Text = dt.Rows[i]["CMF_01"].ToString();
                cdvDept.Text = dt.Rows[i]["CMF_02"].ToString();
                cdvGrade3.Text = dt.Rows[i]["CMF_03"].ToString();


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private bool ReportSaveInfo(char sUse_Yn)
        {


            TRSNode in_node = new TRSNode("Report_In");
            TRSNode out_node = new TRSNode("Report_Out");

            try
            {
                MPCR.SetInMsg(in_node);

                if (cdvReportType.Text.Trim() == "")
                {
                    MPCF.ShowMsgBox("관리유형은 필수입니다.");
                    cdvReportType.Focus();

                }
                if (cdvDept.Text.Trim() == "")
                {
                    MPCF.ShowMsgBox("사업부는 필수입니다.");
                    cdvDept.Focus();

                }



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

                in_node.AddString("REPORT_TYPE", cdvReportType.Text);


                in_node.AddString("CUST_NO", cdvCustName.Text);
                in_node.AddString("CUST_NAME", cdvCustName.DisplayText);
                in_node.AddString("SAL_GROUP", cdvSalGroup.Text);
                in_node.AddString("CREATE_DATE", dtEventDate.Text.Replace("-", ""));
                in_node.AddString("GRADE", cdvGrade.Text);



                in_node.AddString("DATA_01", cdvData01.Text);
                in_node.AddString("DATA_02", cdvData02.Text);
                in_node.AddString("DATA_03", cdvData03.Text);
                in_node.AddString("DATA_04", cdvData04.Text);
                in_node.AddString("DATA_05", cdvData05.Text);
                in_node.AddString("DATA_06", cdvData06.Text);
                in_node.AddString("DATA_07", cdvData07.Text);
                in_node.AddString("DATA_08", cdvData08.Text);
                in_node.AddString("DATA_09", cdvData09.Text);
                in_node.AddString("DATA_10", cdvData10.Text);
                in_node.AddString("DATA_11", cdvData11.Text);
                in_node.AddString("DATA_12", cdvData12.Text);
                in_node.AddString("DATA_13", cdvData13.Text);
                in_node.AddString("DATA_14", cdvData14.Text);
                in_node.AddString("DATA_15", cdvData15.Text);
                in_node.AddString("DATA_16", cdvData16.Text);
                in_node.AddString("DATA_17", cdvData17.Text);
                in_node.AddString("DATA_18", cdvData18.Text);
                in_node.AddString("DATA_19", cdvData19.Text);
                in_node.AddString("DATA_20", cdvData20.Text);
                in_node.AddString("DATA_21", cdvData21.Text);
                in_node.AddString("DATA_22", cdvData22.Text);
                in_node.AddString("DATA_23", cdvData23.Text);
                in_node.AddString("DATA_24", cdvData24.Text);
                in_node.AddString("DATA_25", cdvData25.Text);
                in_node.AddString("DATA_26", cdvData26.Text);
                in_node.AddString("DATA_27", cdvData27.Text);
                in_node.AddString("DATA_28", cdvData28.Text);
                in_node.AddString("DATA_29", cdvData29.Text);
                in_node.AddString("DATA_30", cdvData30.Text);


                in_node.AddString("FILE_NO_01", txtFileNo1.Text);
                in_node.AddString("FILE_NO_02", txtFileNo2.Text);
                in_node.AddString("COMMENT_01", txtComment1.Text);
                in_node.AddString("CMF_01", cdvGrade2.Text);
                in_node.AddString("CMF_02", cdvDept.Text);
                in_node.AddChar("USE_YN", sUse_Yn);







                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Update_CUS_QCM_Other_Company_Spec", in_node, ref out_node) == false)
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
        private void Save_File()
        {
            try
            {
                //FTP 저장
                string FileName = "";
                string FilePath = "";

                PTSFTPClient ptsftp = new PTSFTPClient();
                ptsftp.FtpServerIP = gFileServer_Ip.ToString();
                ptsftp.FtpUserID = @gFileServer_ID.ToString();
                ptsftp.FtpPassword = gFileServer_PW;
                ptsftp.FtpPath = gFileServer_Dir;

                OpenFileDialog dlgOpen = new OpenFileDialog();
                dlgOpen.RestoreDirectory = true;
                dlgOpen.InitialDirectory = "C:\\";

                FileName = "DIA_QC_SIGN.jpg";
                FilePath = cdvFilePath2.Text;

                if (FileSystem.Dir(FilePath) != "" && FileSystem.FileLen(FilePath) > 0)
                {
                    if (ptsftp.UpLoadFile(FilePath, FileName) == true)
                    {
                        //CMN052 INFO -작업을 성공적으로 수행하였습니다.
                        MPCF.ShowMsgBox(MPCF.GetMessage(557));
                    }

                }
                else
                {
                    MPCF.ShowMsgBox("FTP File 전송 오류가 발생 하였습니다. MES 담당자에게 연락 바랍니다.");
                    return;
                }

                return;
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
            string sDept = cdvDept.Text;


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
            cdvDept.Text = sDept;

        }

        #endregion

        #region " Event Definition "
        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {

                ResetControls(this);

                DataListNameView();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvWorkPlace_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
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

        }
        private void btnProcess_Click(object sender, EventArgs e)
        {

        }
        private void frmTranOtrherCompainSpecRegistraion_Load(object sender, EventArgs e)
        {


            dtEventDate.Value = DateTime.Now;




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


            }

        }
        private void cdvFile_ButtonPress(object sender, EventArgs e)
        {
            ofdFile.Reset();
            ofdFile.Filter = "JPEG File(*.jpg)|*.jpg";
            ofdFile.DefaultExt = "jpg";
            ofdFile.FileName = cdvFilePath2.Text;

            if (ofdFile.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {/*
                if (CheckCondition(CSGC.CHECK.ADD) == false)
                {
                    return;
                }
                */

                // string strTargetDetail = "";

                cdvFilePath2.Text = ofdFile.FileName;


            }
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
            ReportSaveInfo('Y');
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


                cdvCustName.Init();
                MPCF.InitListView(cdvReportType.GetListView);
                cdvCustName.Columns.Add("Type", 50, HorizontalAlignment.Left);
                cdvCustName.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvCustName.SelectedSubItemIndex = 0;
                cdvCustName.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvCustName.GetListView, '1', "C_COMPANY_NAME") == false)
                {
                    return;
                }
                cdvCustName.InsertEmptyRow(0, 1);
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
        private void dtEventDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtEventDate.CustomFormat = " ";
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
        private void btnFileDown1_Click(object sender, EventArgs e)
        {
            string image_file = string.Empty;

            //int iActiveRow = spdFileRegistration.ActiveSheet.ActiveRowIndex;

            SaveFileDialog dialog = new SaveFileDialog();
            dialog.Title = "파일 위치 지정";
            //Environment.GetFolderPath(Environment.SpecialFolder.Startup).ToString() 
            //Environment.GetFolderPath(Environment.SpecialFolder.CommonPictures).ToString() 
            // dialog.FileName = Environment.GetFolderPath(Environment.SpecialFolder.Startup).ToString() + "\\" + txtReportNo.Text + "_고객불만통보서" + ".pdf";
            dialog.FileName = "RegistrationNo_" + txtReportNo.Text + "_FILE01" + ".pdf";

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
            dialog.FileName = "RegistrationNo_" + txtReportNo.Text + "_FILE02" + ".pdf";
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


            ReportSaveInfo('N');

        }
        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }
        private void cdvData01_ButtonPress(object sender, EventArgs e)
        {
            try
            {

                if (sender is MCCodeView cCdvData)
                {

                    switch (cCdvData.Tag)
                    {
                        case "N":
                        case "":
                            break;
                        case "D":
                            break;
                        case "Y":

                            if (MPCF.Trim(cdvDept.Text) == "")
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                                cdvDept.Focus();
                                return;
                            }

                            cCdvData.Init();
                            MPCF.InitListView(cCdvData.GetListView);
                            cCdvData.Columns.Add("Type", 50, HorizontalAlignment.Left);
                            cCdvData.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                            //cdvCar.SelectedSubItemIndex = 0;
                            //cdvCar.DisplaySubItemIndex = 1;

                            if (BASLIST.ViewGCMDataList(cCdvData.GetListView, '1', cCdvData.Tag.ToString()) == false)
                            {
                                return;
                            }
                            break;

                    }
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvData_ButtonPress(object sender, EventArgs e)
        {
            try
            {

                if (sender is MCCodeView cCdvData)
                {

                    switch (cCdvData.Tag)
                    {
                        case "N":
                        case "":
                            break;
                        case "D":
                            break;

                        default:

                            if (MPCF.Trim(cdvDept.Text) == "")
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                                cdvDept.Focus();
                                return;
                            }

                            cCdvData.Init();
                            MPCF.InitListView(cCdvData.GetListView);
                            cCdvData.Columns.Add("Type", 50, HorizontalAlignment.Left);
                            cCdvData.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                            cCdvData.SelectedSubItemIndex = 0;
                            cCdvData.DisplaySubItemIndex = 0;

                            if (BASLIST.ViewGCMDataList(cCdvData.GetListView, '1', cCdvData.Tag.ToString()) == false)
                            {
                                return;
                            }
                            cCdvData.InsertEmptyRow(0, 1);

                            break;

                    }
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvReportType_ButtonPress(object sender, EventArgs e)
        {

            if (MPCF.Trim(cdvDept.Text) == "")
            {
                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                cdvDept.Focus();
                return;
            }

            cdvReportType.Init();
            MPCF.InitListView(cdvReportType.GetListView);
            cdvReportType.Columns.Add("Type", 50, HorizontalAlignment.Left);
            cdvReportType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvReportType.SelectedSubItemIndex = 0;
            cdvReportType.DisplaySubItemIndex = 1;

            if (BASLIST.ViewGCMDataList(cdvReportType.GetListView, '1', "C_COMPANY_SPEC_TYPE") == false)
            {
                return;
            }
            cdvReportType.InsertEmptyRow(0, 1);
        }
        private void cdvGrade3_ButtonPress(object sender, EventArgs e)
        {
            if (MPCF.Trim(cdvDept.Text) == "")
            {
                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                cdvDept.Focus();
                return;
            }

            cdvGrade3.Init();
            MPCF.InitListView(cdvReportType.GetListView);
            cdvGrade3.Columns.Add("Type", 50, HorizontalAlignment.Left);
            cdvGrade3.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvGrade3.SelectedSubItemIndex = 1;
            cdvGrade3.DisplaySubItemIndex = 1;

            if (BASLIST.ViewGCMDataList(cdvGrade3.GetListView, '1', "C_COMPANY_QC_GRADE") == false)
            {
                return;
            }
            cdvGrade3.InsertEmptyRow(0, 1);
        }
        private void cdvGcmList_ButtonPress(object sender, EventArgs e)
        {


            cdvGcmList.Init();
            MPCF.InitListView(cdvGcmList.GetListView);
            //  cdvReportType.Columns.Add("Type", 50, HorizontalAlignment.Left);
            //  cdvReportType.Columns.Add("Desc", 100, HorizontalAlignment.Left);

            cdvGcmList.Columns.Add("CODE", 50, HorizontalAlignment.Left);
            cdvGcmList.Columns.Add("VALUE", 100, HorizontalAlignment.Left);
            cdvGcmList.SelectedSubItemIndex = 0;
            cdvGcmList.DisplaySubItemIndex = 1;

            if (BASLIST.ViewGCMDataList(cdvGcmList.GetListView, '1', "C_COMPANY_GCM_LIST") == false)
            {
                return;
            }
            cdvGcmList.InsertEmptyRow(0, 1);
        }
        private void btnGcm_Click(object sender, EventArgs e)
        {
            try
            {

                //C_INSP_GRIT_SIZE
                //C_INSP_GRIT_HLT_TIME

                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = cdvGcmList.Text;

                popup.sTable_name_desc = cdvGcmList.DisplayText;
                popup.sComment = "..";




                if (popup.ShowDialog() == DialogResult.OK)
                {

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

        #endregion
    }
}
