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
using Microsoft.Office.Interop.Excel;
using System.IO;
using DevExpress.XtraPrinting.Export.Pdf.Compression;
using DevExpress.XtraEditors.Repository;
using xExcel = Microsoft.Office.Interop.Excel;

namespace CUS_QCM
{
    public partial class frmTranInspectionDataCScanExcelUpload : CUS_COM.frmViewForm01
    {
        public frmTranInspectionDataCScanExcelUpload()
        {
            InitializeComponent();

            InitControl();
        }


        #region " Constant Definition "

        private enum LOT_INFO
        {
            NO,
            LOT_ID,
            FILE_NO
        }
        #endregion

        #region " Variable Definition "
        private void InitControl()
        {
            try
            {


                // btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;


                cdvDept.Text = CSGV.gs_area_ctm;
                cdvOper.Text = "";
                //cdvOper.DisplayText = "";


                btnManual.Anchor = AnchorStyles.Top | AnchorStyles.Left;


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion

        #region " Function Definition "

        private bool fnRegistrationFile(string sfilepath, string sLotId)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return false;
                }


                ///기존에 있는지 확인//
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                System.Data.DataTable dt = null;
                string sSql = "";
                string sFileNo = "";


                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = sLotId;


                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;


                dvcArgu[3].sCondition_ID = "FILE_NAME";
                dvcArgu[3].sCondition_Value = "CSCAN_IMG_1";


                if (TPDR.GetDataOne("", ref dt, "CQCM3018-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    //return false;
                }

                if (dt.Rows.Count != 0)
                {
                    sFileNo = dt.Rows[0]["FILE_NO"].ToString();
                }
                else
                {
                    sFileNo = "";
                }


                FileInfo _fileInfo;

                _fileInfo = new FileInfo(sfilepath);


                //DB 저장
                TRSNode in_node = new TRSNode("Update_File_In");
                TRSNode out_node = new TRSNode("Update_File_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '6';


                string sFileType = Path.GetExtension(sfilepath).Replace(".", "");

                in_node.AddString("FILE_NO", sFileNo);


                in_node.AddString("IMAGE_CODE", "CSCAN_IMG");

                in_node.AddString("FILE_TYPE", sFileType);

             //   in_node.AddString("FILE_NAME", "CSCAN_IMG_1");




                in_node.AddString("AREA_ID", cdvDept.Text);

                in_node.AddString("OPER", cdvOper.Text);

                in_node.AddString("LOT_ID", sLotId );


                if(cdvOper.Text == "OC04120")  //L/P검사라면
                {
                    in_node.AddString("FILE_NAME", "CSCAN_IMG_2");
                    in_node.AddString("CMF_1", "CSCAN_IMG_2");
                }
                else
                {
                    in_node.AddString("FILE_NAME", "CSCAN_IMG_1");
                    in_node.AddString("CMF_1", "CSCAN_IMG_1");
                }
    

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
                    return false;
                }


                spdInspectionData_Sheet1.AddRows(spdInspectionData_Sheet1.RowCount, 1);

                spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.RowCount - 1, 0].Text = spdInspectionData_Sheet1.RowCount.ToString();
                spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.RowCount - 1, 1].Text = sLotId;
                spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.RowCount - 1, 2].Text = out_node.GetString("FILE_NO");

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {

                switch (CHECK)
                {
                    case CSGC.CHECK.SAVE:
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

        private bool viewOperList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            in_node.AddString("SQL", "SELECT OPER AS CODE, "
                                                 + "               OPER_DESC AS NAME "
                                                 + "         FROM MWIPOPRDEF "
                                                 + "        WHERE AREA_ID = '" + CSGV.gs_area_ctm + "' "
                                                 + "          AND OPER_GRP_2 <> 'NONE' "
                                                 + "         AND OPER IN('OC04120','OC05060') "
                                                 + "        ORDER BY OPER");



            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCR.FillDataView(listView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);

            return true;
        }

        private void ViewImageFile(string _FileNo)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                System.Data.DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FILE_NO";
                dvcArgu[1].sCondition_Value = _FileNo;


                if (TPDR.GetDataOne("", ref dt, "CQCM2001-005", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                pictureBox1.Image = ByteArrayToImage((byte[])dt.Rows[0]["IMAGE_DATA"]);




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

        #endregion

        #region " Event Definition "

        private void btnSave_Click(object sender, EventArgs e)
        {

        }

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

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

                FpSpread excelSp = new FpSpread();
                SheetView sheet1 = new SheetView();

                string sFileName = EXTFUC.ShowFileOpenDialog("Inspection Data");

                if (String.IsNullOrEmpty(sFileName))
                {
                    return;
                }


                sheet1 = spdInspectionData_Sheet1;

                sheet1.SheetName = "Inspection Data";
                sheet1.ColumnCount = spdInspectionData_Sheet1.ColumnCount;
                sheet1.RowCount = spdInspectionData_Sheet1.RowCount;
                sheet1.Protect = false;
                excelSp.Sheets.Add(sheet1);

                excelSp.SaveExcel(sFileName, FarPoint.Excel.ExcelSaveFlags.SaveCustomColumnHeaders);

                MPCF.ShowMsgBox(MPCF.GetMessage(52));  // CMN052 INFO - 작업을 성공적으로 수행하였습니다.

                sheet1.Protect = true;




            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void btnOpenFile_Click(object sender, EventArgs e)
        {
            try
            {
                //ofdAttachFile

                ofdAttachFile.Filter = "Excel Files(*.xls;*.xlsx)|*.xls;*.xlsx";
                ofdAttachFile.DefaultExt = "xls,xlsx";

                if (ofdAttachFile.ShowDialog() == DialogResult.OK)
                {
                    MPCF.ClearList(spdInspectionData);

                    OpenExcelFile(ofdAttachFile.FileName);

                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void OpenExcelFile(string filename)
        {
            //이미지 저장방식이 보편적이지는 않는데... 현장 이미지 편집방식이 엑셀에 넣어서 일괄넣는쪽이 가장좋다고 했음..syw


            string excelFilePath = filename; // 엑셀 파일 경로
            string outputFolder = Path.GetTempPath();  // @"C:\Your\Output\Folder";          // 저장할 폴더 경로

            if (!Directory.Exists(outputFolder))
            {
                Directory.CreateDirectory(outputFolder);
            }



            Microsoft.Office.Interop.Excel.Application excelApp = new Microsoft.Office.Interop.Excel.Application();
            Workbook workbook = excelApp.Workbooks.Open(excelFilePath);

            try
            {
                foreach (Worksheet sheet in workbook.Sheets)
                {
                    //  Console.WriteLine($"Processing sheet: {sheet.Name}");
                    int imageIndex = 1;

                    foreach (Shape shape in sheet.Shapes)
                    {


                        if (shape.Type == Microsoft.Office.Core.MsoShapeType.msoPicture)
                        {
                            //string imagePath = Path.Combine(outputFolder, $"{sheet.Name}_Image_{imageIndex}.png");
                            //shape.Copy();

                            string imagePath = Path.Combine(outputFolder, $"{sheet.Name}_{shape.Name}.Jpeg");
                            shape.Copy();


                            if (Clipboard.ContainsImage())
                            {
                                var image = Clipboard.GetImage();


                                image.Save(imagePath, System.Drawing.Imaging.ImageFormat.Jpeg);
                                fnRegistrationFile(imagePath, shape.Name);

                                //  Console.WriteLine($"Saved image: {imagePath}");
                            }

                            imageIndex++;
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
            finally
            {
                workbook.Close(false);
                excelApp.Quit();
            }

        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            MPCF.ClearList(spdInspectionData);
        }

        private void spdInspectionData_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.Row < 0)
            {
                return;
            }
            if (spdInspectionData.ActiveSheet.Cells[e.Row, (int)LOT_INFO.FILE_NO].Text.Trim().ToString() != "")
            {
                ViewImageFile(spdInspectionData.ActiveSheet.Cells[e.Row, (int)LOT_INFO.FILE_NO].Text.Trim().ToString());
            }

        }

        private void btnManual_Click(object sender, EventArgs e)
        {
            string sCurrentPath = "";
            string sfilePath = "";
            string sreportName = "CScanExcelUploadManual";  //메뉴얼 파일명//해당화면은 실수 많이할거 같아서 메뉴얼 작성.
            string sFolderName = "\\Report\\";


            xExcel.Application XApp = null;
            xExcel.Workbooks XBooks = null;
            xExcel.Workbook XBook = null;

            string path = Path.Combine(System.Windows.Forms.Application.StartupPath, "Temp");


            try
            {

                sCurrentPath = $"{System.Windows.Forms.Application.StartupPath}{sFolderName}";

                //로컬에 폴더가 있는지 체크한다. 없으면 폴더 생성
                if (Directory.Exists(sCurrentPath) == false)
                {
                    Directory.CreateDirectory(sCurrentPath);
                }

                //최종 파일 경로
                sfilePath = $"{sCurrentPath}{sreportName}.Xlsx";



                if (EXTFUC.CheckFileVersion(sfilePath, sreportName) == false)
                {
                    return;
                }



                XApp = new xExcel.Application();

                // XApp.Visible = true;

                XBooks = XApp.Workbooks;
                XBook = XApp.Workbooks.Open(sfilePath);
                XApp.Visible = true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            finally
            {
                EXTFUC.ReleasExcelObject(XBook);
                EXTFUC.ReleasExcelObject(XApp);
            }
        }

        private void lblManual_Click(object sender, EventArgs e)
        {

        }

        private void cdvOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                viewOperList(cdvOper.GetListView);

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            spdInspectionData_Sheet1.RowCount = 0;
        }

        #endregion
    }
}
