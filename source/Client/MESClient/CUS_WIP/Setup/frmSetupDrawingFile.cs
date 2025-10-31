using System;
using System.Data;
using System.Windows.Forms;

using Miracom.MESCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using FarPoint.Win.Spread;
using Miracom.TRSCore;
using System.Drawing;
using CUS_COM;
using System.IO;
using static System.Net.WebRequestMethods;
using System.ComponentModel;
using Microsoft.VisualBasic;
using System.Net.Http;
using System.Xml.Linq;
using GrapeCity.Win.Spread.InputMan.CellType;
using System.Net;

namespace CUS_WIP
{
    public partial class frmSetupDrawingFile : CUS_COM.frmViewForm01
    {




        public frmSetupDrawingFile()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum MAT_LIST
        {
            CHK,                    // 1 : CHECK
            MAT_ID,                 // 2 : 자재코드
            MAT_DESC,               // 3 : 자재명
            MAT_TYPE,               // 4 : 자재종류
            UNIT,                   // 5 : 단위
            MAT_GRP_1,              // 6 : 사업부
            MAT_VER,          // 7 : 제품 VER
            FILE_BUTTON,
            SAVE_BUTTON,

            DRAWING_SPECIFICATION,
            DRAWING_AREA,
            DRAWING_LENGTH,
            DRAWING_CONVERSION_QUANTITY,
            DRAWING_YIELD,
            DRAWING_COMPANY_AND_DRAWING_NAME,
            DRAWING_COMMENT,
            DRAWING_DATE,
            DRAWING_FILE_NO,
            DRAWING_FILE_PATH,

        }

        #endregion

        #region " Variable Definition "

        public string sMat_id = "";
        public string sMat_Desc = "";
        public string sMat_ver = "";

        public string sArea_id = "";
        public string sArea_desc = "";

        public string sType_id = "";
        public string sType_desc = "";

        public string sUnit = string.Empty;

        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                Brwpdf.Visible = true;

        

                this.AllowDrop = true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //자재 리스트 조회 함수
        private void ViewMatList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "MAT_TYPE";
                dvcArgu[2].sCondition_Value = cdvMatType.Text;

                dvcArgu[3].sCondition_ID = "MAT_DESC";
                dvcArgu[3].sCondition_Value = txtMatDesc.Text;


                if (TPDR.GetDataOne("", ref dt, "CCOM3008-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdmatList);
                    return;
                }

                MPCF.ClearList(spdmatList);
                FarPoint.Win.Spread.CellType.CheckBoxCellType checkBoxCellType = new FarPoint.Win.Spread.CellType.CheckBoxCellType();
                spdmatList_Sheet1.Columns.Get((int)MAT_LIST.CHK).CellType = checkBoxCellType;

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdmatList_Sheet1.RowCount++;

                    spdmatList_Sheet1.SetValue(i, (int)MAT_LIST.CHK, false);
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.MAT_TYPE].Value = dt.Rows[i]["MAT_TYPE"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.MAT_GRP_1].Value = dt.Rows[i]["MAT_GRP_1"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.MAT_VER].Value = dt.Rows[i]["MAT_VER"];

                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_AREA].Value = dt.Rows[i]["DRAWING_AREA"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_COMMENT].Value = dt.Rows[i]["DRAWING_COMMENT"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_COMPANY_AND_DRAWING_NAME].Value = dt.Rows[i]["DRAWING_COMPANY_AND_NAME"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_CONVERSION_QUANTITY].Value = dt.Rows[i]["DRAWING_CONVERSION_QUANTITY"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_DATE].Value = dt.Rows[i]["DRAWING_DATE"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_FILE_NO].Value = dt.Rows[i]["DRAWING_FILE_NO"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_LENGTH].Value = dt.Rows[i]["DRAWING_LENGTH"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_SPECIFICATION].Value = dt.Rows[i]["DRAWING_SPECIFICATION"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_YIELD].Value = dt.Rows[i]["DRAWING_YIELD"];


                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_AREA].Tag = dt.Rows[i]["DRAWING_AREA"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_COMMENT].Tag = dt.Rows[i]["DRAWING_COMMENT"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_COMPANY_AND_DRAWING_NAME].Tag = dt.Rows[i]["DRAWING_COMPANY_AND_NAME"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_CONVERSION_QUANTITY].Tag = dt.Rows[i]["DRAWING_CONVERSION_QUANTITY"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_DATE].Tag = dt.Rows[i]["DRAWING_DATE"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_FILE_NO].Tag = dt.Rows[i]["DRAWING_FILE_NO"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_LENGTH].Tag = dt.Rows[i]["DRAWING_LENGTH"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_SPECIFICATION].Tag = dt.Rows[i]["DRAWING_SPECIFICATION"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.DRAWING_YIELD].Tag = dt.Rows[i]["DRAWING_YIELD"];




                }

                MPCF.FitColumnHeader(spdmatList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmSetupDrawingFile_Load(object sender, EventArgs e)
        {

            try
            {
                cdvDept.Text = sArea_id;
                cdvDept.DisplayText = sArea_desc;

                cdvMatType.Text = sType_id;
                cdvMatType.DisplayText = sType_desc;
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

                cdvDept.InsertEmptyRow(0, 1);
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
                cdvMatType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvMatType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvMatType.SelectedSubItemIndex = 0;
                cdvMatType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvMatType.GetListView, '1', MPGC.MP_WIP_MATERIAL_TYPE) == false)
                {
                    return;
                }

                cdvMatType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //수정
        private void spdmatList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {



                SheetView sv = spdmatList.ActiveSheet;

                if (e.ColumnHeader)
                    return;
                //if (e.Column == (int)MAT_LIST.CHK)
                //   return;


                for (int i = 0; i < spdmatList.ActiveSheet.RowCount; i++)
                {
                    spdmatList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdmatList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);


                ViewImageFile(e.Row);


                for (int i = 0; i < sv.RowCount; i++)
                {
                    sv.Cells[i, (int)MAT_LIST.CHK].Value = false;
                }

                sv.Cells[e.Row, (int)MAT_LIST.CHK].Value = true;
                // this.Close();


                switch (e.Column)
                {


                    case (int)MAT_LIST.DRAWING_AREA:
                    case (int)MAT_LIST.DRAWING_COMMENT:
                    case (int)MAT_LIST.DRAWING_COMPANY_AND_DRAWING_NAME:
                    case (int)MAT_LIST.DRAWING_CONVERSION_QUANTITY:
                    case (int)MAT_LIST.DRAWING_DATE:
                    case (int)MAT_LIST.DRAWING_FILE_NO:
                    case (int)MAT_LIST.DRAWING_LENGTH:
                    case (int)MAT_LIST.DRAWING_SPECIFICATION:
                    case (int)MAT_LIST.DRAWING_YIELD:


                        break;
                    default:

                        break;
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
                //if (MPCF.Trim(cdvDept.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                //    cdvDept.Focus();
                //    return;
                //}

                ViewMatList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdmatList_CellDoubleClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                    return;

                switch (e.Column)
                {

                    case (int)MAT_LIST.CHK:

                        break;
                    default:

                        /*
                        sMat_id = spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.MAT_ID].Text;
                        sMat_Desc = spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.MAT_DESC].Text;
                        sMat_ver = spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.MAT_VER].Text;
                        sType_id = spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.MAT_TYPE].Text;
                        sUnit = spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.UNIT].Text;

                        this.DialogResult = DialogResult.OK;
                        this.Close();

                        */
                        break;
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void txtMatDesc_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                ViewMatList();
            }
        }

        private void spdmatList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            //if (e.Column == (int)MAT_LIST.CHK)
            //{
            //    SheetView sv = spdmatList.ActiveSheet;

            //    for (int i = 0; i < sv.RowCount; i++)
            //    {
            //        if (sv.GetValue(i, 0) != null && bool.Parse(sv.GetValue(i, 0).ToString()))
            //            sv.SetValue(i, 0, false); 
            //    }

            //    sv.SetValue(e.Row, 0, true);

            //    return;
            //}

         

            string fullPath;

            //Focused Row
            int iActiveRow = e.Row; //spdmatList.ActiveSheet.ActiveRowIndex;

            try
            {

                switch (e.Column)
                {
                    case (int)(int)MAT_LIST.CHK:
                        SheetView sv = spdmatList.ActiveSheet;

                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.GetValue(i, 0) != null && bool.Parse(sv.GetValue(i, 0).ToString()))
                                sv.SetValue(i, 0, false);
                        }

                        sv.SetValue(e.Row, 0, true);
                        break;

                    case (int)MAT_LIST.FILE_BUTTON:


                        if (spdmatList.ActiveSheet.ActiveRowIndex < 0)
                            return;


                        openFileDialog1.Reset();
                        openFileDialog1.Filter = "Images Files(*.pdf)|*.pdf";
                        openFileDialog1.DefaultExt = "pdf";

                        if (openFileDialog1.ShowDialog() == DialogResult.OK)
                        {

                            fullPath = openFileDialog1.FileName;

                            fnLocalFileView(iActiveRow, fullPath);


                            // fnRegistrationFile(iActiveRow, fullPath);

                        }

                        break;


                    case (int)MAT_LIST.SAVE_BUTTON:


                        fullPath = spdmatList.ActiveSheet.Cells[iActiveRow, (int)MAT_LIST.DRAWING_FILE_PATH].Text;

                        fnRegistrationFile(iActiveRow, fullPath);

                        /*
                        if (MPCF.Trim(fullPath) == "")
                        {
                            //CMN531 INFO -  저장 할 데이터가 없습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(531));
                        }
                        else
                        {
                            fnRegistrationFile(iActiveRow, fullPath);
                        }
                        */


                        break;
                    default:

                        break;
                }





            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

        }

        private async void ViewImageFile(int iRow)
        {
            try
            {
                //WebView
                if (txtMatId.Text == MPCF.Trim(spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.MAT_ID].Text))
                {
                    return;
                }


                string sfilePath = "";



                Brwpdf.Navigate("about:blank");


                if (MPCF.Trim(spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_FILE_PATH].Text) != "")
                {
                    sfilePath = spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_FILE_PATH].Text;

                    Brwpdf.Navigate(sfilePath);

                    txtMatId.Text = MPCF.Trim(spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.MAT_ID].Text);
                }
                else
                {
                    sfilePath = @"http://197.200.11.142/DIA_FILE_SERVER/DRAWING_FILE/" + MPCF.Trim(spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.MAT_ID].Text) + ".PDF";
                    //if (System.IO.File.Exists(sfilePath))



                    if (await FileExistsOnWeb(sfilePath))
                    {
                        Brwpdf.Navigate(sfilePath);

                        txtMatId.Text = MPCF.Trim(spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.MAT_ID].Text);
                    }
                    else
                    {
                        Brwpdf.DocumentText = "";  // 빈 HTML을 로드하여 빈 화면을 표시

                        txtMatId.Text = "";
                    }
                }
                














                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public static Image ByteArrayToImage(byte[] b)
        {



            TypeConverter tc = TypeDescriptor.GetConverter(typeof(Bitmap));
            ImageConverter imgcvt = new ImageConverter();

            Image img = (Image)imgcvt.ConvertFrom(b);
            return img;
        }


        private async System.Threading.Tasks.Task<bool> FileExistsOnWeb(string url)
        {
            try
            {
                using (HttpClient client = new HttpClient())
                {
                    // HTTP 요청을 보낸 후 파일이 있는지 확인
                    var response = await client.GetAsync(url);
                    return response.IsSuccessStatusCode; // 상태 코드 200 OK인 경우 true
                }
            }
            catch
            {
                return false; // 예외 발생 시 파일이 없는 것으로 간주
            }
        }

        private void ByteArrayToPdf(byte[] b)
        {
            byte[] bt_buffer;
            string sfilePath = "";
            /* if ((bt_buffer = out_node.GetBlob(MPGC.MP_BIN_DATA_1)) != null)
             {
             }
            */
            try
            {

                sfilePath = Environment.GetEnvironmentVariable("TEMP") + "\\" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".pdf";
                bt_buffer = b;//new byte[b.Length];
                FileStream fs = System.IO.File.Open(sfilePath, FileMode.Create);
                BinaryWriter writer = new BinaryWriter(fs);
                writer.Write(bt_buffer, 0, bt_buffer.Length);
                writer.Close();
                Brwpdf.Navigate(sfilePath);


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

        }

        private void fnLocalFileView(int iRow, string sfilepath)
        {

            string fullPath = sfilepath;
            FileInfo finfo = new FileInfo(fullPath);

            //3M 제한
            long lengthKByte = finfo.Length / 1024;
            if (lengthKByte >= 3072)
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(504));
                return;
            }

            spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_FILE_PATH].Text = fullPath;
            txtMatId.Text = "";
            ViewImageFile(iRow);
        }

        private void fnRegistrationFile(int iRow, string sfilepath)
        {

            if (spdmatList.ActiveSheet.ActiveRowIndex < 0)
                return;

            if (MPCF.Trim(spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_FILE_NO].Text) == "" && MPCF.Trim(sfilepath) == "")
            {

                //CMN531 INFO -  저장 할 데이터가 없습니다.
                MPCF.ShowMsgBox(MPCF.GetMessage(531));
                return;
            }

            string fullPath = "";
            FileInfo finfo;
            long lengthKByte;

            //Focused Row
            int iActiveRow = iRow; //spdmatList.ActiveSheet.ActiveRowIndex;


            string sFileNo = "";


            if (MPCF.Trim(spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_FILE_NO].Text) != "" && MPCF.Trim(sfilepath) != "")
            {
                //backupd을 하는경우는 파일번호 새로채번.
                if (MPCF.ShowMsgBox("기존도면파일에 덮어쓰기 하시겠습니까?(아니면 기존파일이력저장후 )", System.Windows.Forms.MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.Yes)
                {
                    sFileNo = MPCF.Trim(spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_FILE_NO].Text);
                }
            }
            else
            {
                sFileNo = MPCF.Trim(spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_FILE_NO].Text);
            }

            if (MPCF.Trim(sfilepath) == "")
            {


                //DB 저장
                TRSNode in_node = new TRSNode("Update_File_In");
                TRSNode out_node = new TRSNode("Update_File_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '5';




                in_node.AddString("FILE_NO", sFileNo);


                in_node.AddString("CMF_1", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_SPECIFICATION].Text);

                in_node.AddString("CMF_2", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_AREA].Text);

                in_node.AddString("CMF_3", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_LENGTH].Text);

                in_node.AddString("CMF_4", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_YIELD].Text);

                in_node.AddString("CMF_5", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_CONVERSION_QUANTITY].Text);

                in_node.AddString("CMF_6", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_COMPANY_AND_DRAWING_NAME].Text);

                in_node.AddString("CMF_7", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_COMMENT].Text);

                in_node.AddString("CMF_8", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_DATE].Text);

                //  in_node.AddString("CMF_9", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_FILE_NO].Text);

                if (MPCR.CallService("CUS_QCM", "CUS_QCM_File_Attach", in_node, ref out_node) == false)
                {
                    return;
                }

                //CMN052 INFO -작업을 성공적으로 수행하였습니다.
                MPCF.ShowMsgBox(MPCF.GetMessage(052));

            }
            else
            {


                finfo = new FileInfo(sfilepath);
                fullPath = sfilepath;

                //3M 제한
                lengthKByte = finfo.Length / 1024;
                if (lengthKByte >= 3072)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(504));
                    return;
                }



                //DB 저장
                TRSNode in_node = new TRSNode("Update_File_In");
                TRSNode out_node = new TRSNode("Update_File_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '4';

                string sFileType = Path.GetExtension(fullPath).Replace(".", "");





                in_node.AddString("FILE_NO", sFileNo);

                in_node.AddString("MAT_ID", MPCF.Trim(spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.MAT_ID].Text));

                in_node.AddString("IMAGE_CODE", "BLUE_PRINT");

                in_node.AddString("FILE_TYPE", sFileType);

                in_node.AddString("FILE_NAME", "DRWING_FILE");

                in_node.AddString("AREA_ID", cdvDept.Text);

                // in_node.AddString("SUB_AREA_ID", "C_CUT");  //절단작업장으로 고정.

                in_node.AddString("CMF_1", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_SPECIFICATION].Text);

                in_node.AddString("CMF_2", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_AREA].Text);

                in_node.AddString("CMF_3", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_LENGTH].Text);

                in_node.AddString("CMF_4", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_YIELD].Text);

                in_node.AddString("CMF_5", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_CONVERSION_QUANTITY].Text);

                in_node.AddString("CMF_6", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_COMPANY_AND_DRAWING_NAME].Text);

                in_node.AddString("CMF_7", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_COMMENT].Text);

                in_node.AddString("CMF_8", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_DATE].Text);

                //  in_node.AddString("CMF_9", spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_FILE_NO].Text);





                //string s_File_no = "";

                BinaryReader br;
                byte[] file_buffer;
                if (finfo.Exists == true)
                {
                    br = new BinaryReader(finfo.OpenRead());
                    file_buffer = br.ReadBytes((int)finfo.Length);
                    in_node.AddBlob(MPGC.MP_BIN_DATA_1, file_buffer);
                    in_node.AddInt("IMAGE_SIZE", finfo.Length);
                    br.Close();
                }

                if (MPCR.CallService("CUS_QCM", "CUS_QCM_File_Attach", in_node, ref out_node) == false)
                {
                    return;
                }

                spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_FILE_NO].Text = out_node.GetString("FILE_NO");

                spdmatList.ActiveSheet.Cells[iRow, (int)MAT_LIST.DRAWING_FILE_PATH].Text = "";


                //FTP 저장(한국에서 등록한 도면 베트남에서도 사용해야되서...도면이미지들 FTP로 올려놓음.(관리는 한국MES에서만 하지만, 검사화면에서 도면 보여주는거는한국 베트남 같이..)
                string FileName = "";
                string FilePath = "";

                string gFileServer_Ip = "";
                string gFileServer_PORT = "";
                string gFileServer_Dir = "";
                string gFileServer_ID = "";
                string gFileServer_PW = "";


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
                    ListViewItem ItmFound = lisTmp.FindItemWithText("FILE_SERVER");
                    if (ItmFound == null)
                    {
                        MPCF.ShowMsgBox("FTP 서버 정보 조회 실패");
                        return;
                    }

                    gFileServer_Ip = ItmFound.SubItems[1].Text;
                    gFileServer_PORT = ItmFound.SubItems[2].Text;
                    gFileServer_Dir = ItmFound.SubItems[3].Text + "/DRAWING_FILE";
                    gFileServer_ID = ItmFound.SubItems[4].Text;
                    gFileServer_PW = ItmFound.SubItems[5].Text;
                }



                PTSFTPClient ptsftp = new PTSFTPClient();
                ptsftp.FtpServerIP = gFileServer_Ip.ToString();
                ptsftp.FtpUserID = @gFileServer_ID.ToString();
                ptsftp.FtpPassword = gFileServer_PW;
                ptsftp.FtpPath = gFileServer_Dir;

                OpenFileDialog dlgOpen = new OpenFileDialog();
                dlgOpen.RestoreDirectory = true;
                dlgOpen.InitialDirectory = "C:\\";

                FileName = spdmatList.ActiveSheet.Cells[spdmatList.ActiveSheet.ActiveRowIndex, (int)MAT_LIST.MAT_ID].Text + ".pdf";
                FilePath = fullPath;




                if (FileSystem.Dir(FilePath) != "" && FileSystem.FileLen(FilePath) > 0)
                {
                    if (ptsftp.UpLoadFile(FilePath, FileName) == true)
                    {
                        //CMN052 INFO -작업을 성공적으로 수행하였습니다.
                        MPCF.ShowMsgBox(MPCF.GetMessage(052));
                    }

                }
                else
                {
                    MPCF.ShowMsgBox("FTP File 전송 오류가 발생 하였습니다. MES 담당자에게 연락 바랍니다.");
                    return;
                }

            }
            //파일 리스트 조회
            // ViewInspectionFile(txtInspID.Text);

            // spdFileRegistration.ActiveSheet.ActiveRowIndex = iActiveRow;
            // fnFileSelectionChagned();



        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdmatList, "LotMaterialList");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {

        }





        private void frmSetupDrawingFile_DragDrop(object sender, DragEventArgs e)
        {

            if (spdmatList.ActiveSheet.ActiveRowIndex < 0)
            {
                return;
            }

            // 드롭된 파일의 경로 배열을 가져옴
            string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);

            // 첫 번째 파일 경로 가져오기 (여러 파일을 드롭할 경우 첫 번째만 사용)
            if (files.Length > 0)
            {
                string spdfPath = files[0];



                fnLocalFileView(spdmatList.ActiveSheet.ActiveRowIndex, spdfPath);
                // fnRegistrationFile(spdmatList.ActiveSheet.ActiveRowIndex, spdfPath);






            }
        }

        private void frmSetupDrawingFile_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Copy;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }
        }

        #endregion



    }
}
