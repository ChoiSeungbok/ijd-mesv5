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
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using Miracom.CliFrx;
using Miracom.DNMCore;
using System.Threading;
using Microsoft.VisualBasic;
using System.IO;

namespace CUS_BAS
{
    public partial class frmSetUploadAttach : CUS_COM.frmViewForm01
    {
        #region
        public frmSetUploadAttach()
        {
            InitializeComponent();
            InitControl();
        }

        #endregion

        #region " Constant Definition "
        private enum FILEUPLOAD
        {
            CHK,                   // 1 : 선택 
            FILE_NO,               // 2 : 파일번호 
            FILE_TYPE,             // 3 : 파일타입 
            FILE_TYPE_DESC,        // 4 : 파일타입 
            FILE_NAME,             // 5 : 파일명 
            FILE_PATH,             // 6 : FROM 경로 
            TO_FILE_PATH,          // 7 : TO 경로  
            UPLOAD_DATE,           // 8 : 업로드시간 
            FILE_OPEN,             // 9 : 파일열기
            FILE_DOWN,             // 10 : 파일다운       
            AREA_ID,               // 11 : 사업부
            SUB_AREA_ID,           // 12 : 사업장 
            OPER,                  // 13 : 공정
            RES_ID,                // 14 : 설비
            TOOL_ID,               // 15 : 금형
            MAT_ID,                // 16 : 제품
            INSP_ID                // 17 :검사번호     
        }

        #endregion

        #region " Variable Definition "
        string gFileServer_Ip;
        string gFileServer_PORT;
        string gFileServer_Dir;
        string gFileServer_ID;
        string gFileServer_PW;
        #endregion

        #region " Function Definition "
        private void InitControl()
        {
            btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;

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
                gFileServer_Dir = ItmFound.SubItems[3].Text;
                gFileServer_ID = ItmFound.SubItems[4].Text;
                gFileServer_PW = ItmFound.SubItems[5].Text;
            }
        }

        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                if (MPCF.Trim(cdvFileType.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFileType.Text + "]");
                    cdvDept.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return false;
                }
                
                switch (cdvFileType.Text)
                {
                    case "F001":
                        //설비(설비 필수)
                        if (MPCF.Trim(cdvResource.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblResource.Text + "]");
                            cdvResource.Focus();
                            return false;
                        }
                        break;

                    case "F002":
                        //금형(금형 필수)
                        if (MPCF.Trim(cdvMold.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMold.Text + "]");
                            cdvMold.Focus();
                            return false;
                        }

                        break;
                    case "F003":
                        //표준서(제품 필수)
                        if (MPCF.Trim(cdvMat.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMat.Text + "]");
                            cdvMat.Focus();
                            return false;
                        }

                        break;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.SAVE:

                        break;
                    case CSGC.CHECK.VIEW:

                        break;
                    case CSGC.CHECK.DELETE:

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

        //초기화 함수
        private void ClearList(CSGC.CHECK CHECK)
        {
            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        MPCF.ClearList(spdFileAttachList);
                        break;

                    case CSGC.CHECK.ALL:

                        this.cdvDept.Text = "";
                        this.cdvWorkPlace.Text = "";
                        this.cdvOper.Text = "";
                        MPCF.ClearList(spdFileAttachList);
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void View_FileList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[8];
                DataTable dt = null;
                string sSql = "";
                
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvOper.Text;

                dvcArgu[4].sCondition_ID = "RES_ID";
                dvcArgu[4].sCondition_Value = cdvResource.Text;

                dvcArgu[5].sCondition_ID = "TOOL_ID";
                dvcArgu[5].sCondition_Value = cdvMold.Text;

                dvcArgu[6].sCondition_ID = "MAT_ID";
                dvcArgu[6].sCondition_Value = cdvMat.Text;

                dvcArgu[7].sCondition_ID = "FILE_TYPE";
                dvcArgu[7].sCondition_Value = cdvFileType.Text;
                
                if (TPDR.GetDataOne("", ref dt, "CBAS1001-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdFileAttachList);
                    return;
                }

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    spdFileAttachList_Sheet1.RowCount++;

                    spdFileAttachList_Sheet1.SetValue(i, (int)FILEUPLOAD.CHK, false);
                    spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.FILE_NO].Value = dt.Rows[i]["FILE_NO"];
                    spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.FILE_TYPE].Value = dt.Rows[i]["FILE_TYPE"];
                    spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.FILE_TYPE_DESC].Value = dt.Rows[i]["FILE_TYPE_DESC"];
                    spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.FILE_NAME].Value = dt.Rows[i]["FILE_NAME"];
                    spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.FILE_PATH].Value = dt.Rows[i]["FILE_PATH"];
                    spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.TO_FILE_PATH].Value = dt.Rows[i]["TO_FILE_PATH"];
                    spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.UPLOAD_DATE].Value = dt.Rows[i]["UPDATE_TIME"];
                    spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_ID"];
                    spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.OPER].Value = dt.Rows[i]["OPER"];
                    spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.TOOL_ID].Value = dt.Rows[i]["TOOL_ID"];
                    spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.INSP_ID].Value = dt.Rows[i]["INSP_ID"];  
                }
                MPCF.FitColumnHeader(spdFileAttachList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

            return;
        }

        private void Create_File(int iRow)
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
                ptsftp.FtpPath = spdFileAttachList_Sheet1.Cells[iRow, (int)FILEUPLOAD.TO_FILE_PATH].Text;

                OpenFileDialog dlgOpen = new OpenFileDialog();
                dlgOpen.RestoreDirectory = true;
                dlgOpen.InitialDirectory = "C:\\";

                FileName = spdFileAttachList_Sheet1.Cells[iRow, (int)FILEUPLOAD.FILE_NAME].Text;
                FilePath = spdFileAttachList_Sheet1.Cells[iRow, (int)FILEUPLOAD.FILE_PATH].Text;

                //if (FileSystem.Dir(FilePath) != "" && FileSystem.FileLen(FilePath) > 0)
                //{
                //    ptsftp.UpLoadFile(FilePath, FileName);
                //}
                //else
                //{
                //    MPCF.ShowMsgBox("FTP File 전송 오류가 발생 하였습니다. MES 담당자에게 연락 바랍니다.");
                //    return;
                //}

                //DB 저장
                TRSNode in_node = new TRSNode("Update_File_In");
                TRSNode out_node = new TRSNode("Update_File_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("FILE_NO", spdFileAttachList_Sheet1.Cells[iRow, (int)FILEUPLOAD.FILE_NO].Value);
                in_node.AddString("FILE_TYPE", spdFileAttachList_Sheet1.Cells[iRow, (int)FILEUPLOAD.FILE_TYPE].Value);
                in_node.AddString("FILE_NAME", spdFileAttachList_Sheet1.Cells[iRow, (int)FILEUPLOAD.FILE_NAME].Value);
                in_node.AddString("FILE_PATH", spdFileAttachList_Sheet1.Cells[iRow, (int)FILEUPLOAD.FILE_PATH].Value);
                in_node.AddString("TO_FILE_PATH", spdFileAttachList_Sheet1.Cells[iRow, (int)FILEUPLOAD.TO_FILE_PATH].Value);
                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("RES_ID", cdvResource.Text);
                in_node.AddString("TOOL_ID", cdvMold.Text);
                in_node.AddString("MAT_ID", cdvMat.Text);
                in_node.AddInt("INSP_ID", "");

                FileInfo finfo;
                BinaryReader br;
                byte[] file_buffer;

                finfo = new FileInfo(FilePath);
                if (finfo.Exists == true)
                {
                    br = new BinaryReader(finfo.OpenRead());
                    file_buffer = br.ReadBytes((int)finfo.Length);
                    in_node.AddBlob(MPGC.MP_BIN_DATA_1, file_buffer);
                    in_node.AddInt("IMAGE_SIZE", finfo.Length);
                    br.Close();
                }

                if (MPCR.CallService("CUS_BAS", "CUS_BAS_update_Attach", in_node, ref out_node) == false)
                {
                    return;
                }

                spdFileAttachList_Sheet1.Cells[iRow, (int)FILEUPLOAD.CHK].Value = false;
                spdFileAttachList_Sheet1.Cells[iRow, (int)FILEUPLOAD.FILE_NO].Value = out_node.GetString("FILE_NO");

                MPCF.ShowMsgBox("파일 저장이 완료되었습니다");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            return;
        }

        //private FileStream SelectFileBuff(string filename)
        //{
        //    FileInfo fileInf = new FileInfo(filename);
            
        //    // The buffer size is set to 2kb
        //    int buffLength = 2048;
        //    byte[] buff = new byte[buffLength];
        //    //int contentLen;

        //    // Opens a file stream (System.IO.FileStream) to read the file to be uploaded
        //    FileStream fs = fileInf.OpenRead();

        //    try
        //    {
        //        // Read from the file stream 2kb at a time
        //        //contentLen = fs.Read(buff, 0, buffLength);

        //        // Close the file stream and the Request Stream
        //        //return fs;
        //    }
        //    catch (Exception ex)
        //    {
        //        return null;
        //    }
        //    return fs;
        //}

        private void Delete_File(int iRow)
        {
            try
            {
                TRSNode in_node = new TRSNode("Update_Spare_In");
                TRSNode out_node = new TRSNode("Update_Spare_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '3';
                in_node.AddString("FILE_NO", spdFileAttachList_Sheet1.Cells[iRow, (int)FILEUPLOAD.FILE_NO].Text);

                if (MPCR.CallService("CUS_BAS", "CUS_BAS_update_Attach", in_node, ref out_node) == false)
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            return;
        }

        private void Attach_Download()
        {
            PTSFTPClient ptsftp = new PTSFTPClient();
            SaveFileDialog dlgSave = new SaveFileDialog();
            string FileName = "";
            string FilePath = "";
            bool PlayNow = false;

            try
            {
                //ptsftp.FtpServerIP = gFileServer_Ip.ToString();
                //ptsftp.FtpUserID = @gFileServer_ID.ToString();
                //ptsftp.FtpPassword = gFileServer_PW;
                //ptsftp.FtpPath = spdFileAttachList_Sheet1.Cells[spdFileAttachList.ActiveSheet.ActiveRowIndex, (int)FILEUPLOAD.TO_FILE_PATH].Text;

                //FileName = spdFileAttachList_Sheet1.Cells[spdFileAttachList.ActiveSheet.ActiveRowIndex, (int)FILEUPLOAD.FILE_NAME].Text;

                //PlayNow = false;

                //dlgSave.RestoreDirectory = true;
                //dlgSave.InitialDirectory = "C:\\";
                //dlgSave.FileName = FileName;


                //if (FileName.Substring(FileName.Length - 3 - 1, 1) == ".")
                //{
                //    dlgSave.DefaultExt = FileName.Substring(FileName.Length - 3 - 1, 4);
                //    dlgSave.Filter = FileName.Substring(FileName.Length - 2 - 1, 3) + " files (*." + FileName.Substring(FileName.Length - 2 - 1, 3) + ")|*." + FileName.Substring(FileName.Length - 2 - 1, 3) + "|All files (*.*)|*.*";
                //}


                //if (dlgSave.ShowDialog() == DialogResult.OK)
                //{
                //    if (MPCF.Trim(dlgSave.FileName) != "")
                //    {

                //        FilePath = MPCF.Trim(dlgSave.FileName);
                //        //FTP로 File Download
                //        ptsftp.DownLoadFile(FilePath, FileName);
                //        if (MPCF.ShowMsgBox("파일을 바로 실행하시겠습니까?", System.Windows.Forms.MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.Yes)
                //        {
                //            PlayNow = true;
                //        }
                //    }
                //}

                //if (PlayNow == true)
                //{
                //    System.Diagnostics.Process.Start(FilePath);
                //}

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FILE_NO";
                dvcArgu[1].sCondition_Value = spdFileAttachList_Sheet1.Cells[spdFileAttachList.ActiveSheet.ActiveRowIndex, (int)FILEUPLOAD.FILE_NO].Text;

                if (TPDR.GetDataOne("", ref dt, "CBAS1001-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdFileAttachList);
                    return;
                }

                FileName = dt.Rows[0]["FILE_NAME"].ToString();

                byte[] buffer = ((byte[])dt.Rows[0]["IMAGE_DATA"]);

                dlgSave.RestoreDirectory = true;
                dlgSave.InitialDirectory = "C:\\";
                dlgSave.FileName = FileName;

                if (FileName.Substring(FileName.Length - 3 - 1, 1) == ".")
                {
                    dlgSave.DefaultExt = FileName.Substring(FileName.Length - 3 - 1, 4);
                    dlgSave.Filter = FileName.Substring(FileName.Length - 2 - 1, 3) + " files (*." + FileName.Substring(FileName.Length - 2 - 1, 3) + ")|*." + FileName.Substring(FileName.Length - 2 - 1, 3) + "|All files (*.*)|*.*";
                }

                if (dlgSave.ShowDialog() == DialogResult.OK)
                {
                    if (MPCF.Trim(dlgSave.FileName) != "")
                    {

                        FilePath = MPCF.Trim(dlgSave.FileName);

                        // 지정 경로에 파일 생성
                        Stream writeStream = new FileStream(FilePath, FileMode.Create);

                        writeStream.Write(buffer, 0, buffer.Length);
                        writeStream.Close();

                        if (MPCF.ShowMsgBox("파일을 바로 실행하시겠습니까?", System.Windows.Forms.MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.Yes)
                        {
                            PlayNow = true;
                        }

                        if (PlayNow == true)
                        {
                            System.Diagnostics.Process.Start(FilePath);
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

        private void Attach_View()
        {
            try
            {
                //PTSFTPClient ptsftp = new PTSFTPClient();
                //string FileName = "";
                //string FilePath = "";
                //bool PlayNow = false;

                //ptsftp.FtpServerIP = gFileServer_Ip.ToString();
                //ptsftp.FtpUserID = @gFileServer_ID.ToString();
                //ptsftp.FtpPassword = gFileServer_PW;
                //ptsftp.FtpPath = spdFileAttachList_Sheet1.Cells[spdFileAttachList.ActiveSheet.ActiveRowIndex, (int)FILEUPLOAD.TO_FILE_PATH].Text;

                //FileName = spdFileAttachList_Sheet1.Cells[spdFileAttachList.ActiveSheet.ActiveRowIndex, (int)FILEUPLOAD.FILE_NAME].Text;

                //PlayNow = true;

                //if (Directory.Exists(Application.StartupPath + "\\MES_Files") == false)
                //{
                //    Directory.CreateDirectory(Application.StartupPath + "\\MES_Files");
                //}

                //FilePath = Application.StartupPath + "\\MES_Files\\" + FileName;
                //ptsftp.DownLoadFile(FilePath, FileName);

                //if (PlayNow == true)
                //{
                //    System.Diagnostics.Process.Start(FilePath);
                //}
                
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FILE_NO";
                dvcArgu[1].sCondition_Value = spdFileAttachList_Sheet1.Cells[spdFileAttachList.ActiveSheet.ActiveRowIndex, (int)FILEUPLOAD.FILE_NO].Text;

                if (TPDR.GetDataOne("", ref dt, "CBAS1001-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdFileAttachList);
                    return;
                }
                    
                string file_name = dt.Rows[0]["FILE_NAME"].ToString();
                    
                byte[] buffer = ((byte[])dt.Rows[0]["IMAGE_DATA"]);
                    
                string FilePath = Application.StartupPath + "\\MES_Files\\" + file_name;
                    
                // 지정 경로에 파일 생성
                Stream writeStream = new FileStream(FilePath, FileMode.Create);
                    
                writeStream.Write(buffer, 0, buffer.Length);
                writeStream.Close();

                System.Diagnostics.Process.Start(FilePath);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        #endregion
        
        #region " Event Definition "
        private void cdvFile_ButtonPress(object sender, EventArgs e)
        {
            ofdFile.Reset();
            ofdFile.Filter = "PDF Files(*.PDF)|*.PDF";
            ofdFile.DefaultExt = "pdf";
            ofdFile.FileName = cdvFile.Text;

            if (ofdFile.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                if (CheckCondition(CSGC.CHECK.ADD) == false)
                {
                    return;
                }

                string strTargetDetail = "";

                switch (cdvFileType.Text)
                {
                    case "F001":
                        strTargetDetail = cdvFileType.Text + "/" + cdvOper.Text + "/" + cdvResource.Text;
                        break;

                    case "F002":
                        strTargetDetail = cdvFileType.Text + "/" + cdvMold.Text;
                        break;

                    case "F003":
                        strTargetDetail = cdvFileType.Text + "/" + cdvOper.Text + "/" + cdvMat.Text;
                        break;
                }

                int sRow;
                if (spdFileAttachList.ActiveSheet.ActiveRowIndex == -1)
                {
                    sRow = 0;
                }
                else
                {
                    sRow = spdFileAttachList.ActiveSheet.ActiveRowIndex;
                }

                spdFileAttachList.ActiveSheet.AddRows(sRow, 1);

                cdvFile.Text = cdvFile.Text;
                spdFileAttachList_Sheet1.SetValue(sRow, (int)FILEUPLOAD.CHK, true);
                spdFileAttachList_Sheet1.Cells[sRow, (int)FILEUPLOAD.FILE_TYPE].Value = MPCF.Trim(cdvFileType.Text);
                spdFileAttachList_Sheet1.Cells[sRow, (int)FILEUPLOAD.FILE_TYPE_DESC].Text = MPCF.Trim(cdvFileType.DisplayText);
                spdFileAttachList_Sheet1.Cells[sRow, (int)FILEUPLOAD.FILE_NAME].Value = MPCF.Trim(ofdFile.FileName.Substring(ofdFile.FileName.LastIndexOf("\\") + 1));
                spdFileAttachList_Sheet1.Cells[sRow, (int)FILEUPLOAD.FILE_PATH].Value = MPCF.Trim(ofdFile.FileName);
                spdFileAttachList_Sheet1.Cells[sRow, (int)FILEUPLOAD.TO_FILE_PATH].Value = gFileServer_Dir.ToString() + "/" + strTargetDetail;

                MPCF.FitColumnHeader(spdFileAttachList);
            }
        }

        private void cdvFileType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvFileType.Init();
                MPCF.InitListView(cdvFileType.GetListView);
                cdvFileType.Columns.Add("CODE", 50, HorizontalAlignment.Left);
                cdvFileType.Columns.Add("DATA", 100, HorizontalAlignment.Left);
                cdvFileType.SelectedSubItemIndex = 0;
                cdvFileType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvFileType.GetListView, '1', CSGC.CP_FILE_TYPE) == false)
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void cdvFileType_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                switch (cdvFileType.Text)
                {
                    case "F001":
                        cdvOper.Visible = true;
                        cdvResource.Visible = true;
                        cdvMold.Visible = false;
                        cdvMat.Visible = false;

                        lblOper.Visible = true;
                        lblResource.Visible = true;
                        lblMold.Visible = false;
                        lblMat.Visible = false;
                        
                        break;

                    case "F002":
                        cdvOper.Visible = false;
                        cdvResource.Visible = false;
                        cdvMold.Visible = true;
                        cdvMat.Visible = false;

                        lblOper.Visible = false;
                        lblResource.Visible = false;
                        lblMold.Visible = true;
                        lblMat.Visible = false;
                        
                        break;

                    case "F003":
                        cdvOper.Visible = true;
                        cdvResource.Visible = false;
                        cdvMold.Visible = false;
                        cdvMat.Visible = true;

                        lblOper.Visible = true;
                        lblResource.Visible = false;
                        lblMold.Visible = false;
                        lblMat.Visible = true;
                        
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
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
                cdvWorkPlace.Text = "";
                cdvOper.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMat_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMat.DisplayText == "")
                cdvMat.Text = "";
        }

        private void cdvWorkPlace_ButtonPress(object sender, EventArgs e)
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

                cdvWorkPlace.Init();
                MPCF.InitListView(cdvWorkPlace.GetListView);
                cdvWorkPlace.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWorkPlace.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWorkPlace.SelectedSubItemIndex = 0;
                cdvWorkPlace.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList_AREA(cdvWorkPlace.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, cdvDept.Text) == false)
                {
                    return;
                }

                cdvWorkPlace.InsertEmptyRow(0, 1);
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
                cdvOper.Text = "";
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
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return;
                }

                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, '1', cdvDept.Text, cdvWorkPlace.Text) == false)
                {
                    return;
                }

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvResource_ButtonPress(object sender, EventArgs e)
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

                cdvResource.Init();
                MPCF.InitListView(cdvResource.GetListView);
                cdvResource.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvResource.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvResource.SelectedSubItemIndex = 0;
                cdvResource.DisplaySubItemIndex = 1;

                if (RASLIST.ViewResourceList(cdvResource.GetListView, '1', "", "", cdvDept.Text, cdvWorkPlace.Text, "", -1, "", cdvOper.Text, 'R', "", false, null, "") == false)
                {
                    return;
                }

                cdvResource.InsertEmptyRow(0, 1);
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
                // 제품 팝업으로 변경
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMat.Text = popup.sMat_id;
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

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ClearList(CSGC.CHECK.VIEW);

                View_FileList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                {
                    return;
                }

                for (int i = 0; i < spdFileAttachList_Sheet1.RowCount; i++)
                {
                    if (spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (string.IsNullOrEmpty(spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.FILE_NO].Text))
                        {
                            Create_File(i);
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

        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                {
                    return;
                }

                //정말삭제하시겠습니까?
                if (MPCF.ShowMsgBox(MPCF.GetMessage(453), MessageBoxButtons.YesNo, 1) == DialogResult.No)
                {
                    return;
                }
                
                for (int i = 0; i < spdFileAttachList_Sheet1.RowCount; i++)
                {
                    if (spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (!string.IsNullOrEmpty(spdFileAttachList_Sheet1.Cells[i, (int)FILEUPLOAD.FILE_NO].Text))
                        {
                            Delete_File(i);
                        }
                        else
                        {
                            spdFileAttachList.ActiveSheet.RemoveRows(i, 1);
                        }
                    }
                }

                btnView_Click(null, null);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void spdFileAttachList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                if (e.Column == (int)FILEUPLOAD.FILE_OPEN)  //View
                {
                    Attach_View();
                }
                else if (e.Column == (int)FILEUPLOAD.FILE_DOWN) // Download
                {
                    Attach_Download();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        #endregion


    }
}
