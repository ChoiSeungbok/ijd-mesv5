using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

using Miracom.CliFrx;
using Miracom.TRSCore;
using Miracom.MESCore;

using System.Net;
using System.Threading;
using System.IO;

namespace Miracom.MESCore.Controls
{
    public partial class udcAttachFile : UserControl
    {
        public udcAttachFile()
        {
            InitializeComponent();

            Init();
        }

        #region " Constant Definition "

        private const int COL_TRANS_TYPE = 0;
        private const int COL_FILE_NAME = 1;
        private const int COL_DOWN_BUTTON = 2;
        private const int COL_FILE_PATH = 3;

        #endregion

        #region " Variable Definition "

        private bool fileUploadCompleted = true;

        private string m_attah_path;
        private string m_attach_user;
        private string m_attach_pwd;

        private string m_lot_id;
        private string m_doc_id;

        private bool m_ignore_db = false;

        public bool TransType_ReadOnly
        {
            get
            {
                return !cdvTransType.VisibleButton;
            }
            set
            {
                if (value == true)
                {
                    lblType.Visible = false;
                    cdvTransType.Visible = false;
                    cdvTransType.VisibleButton = false;
                }
                else
                {
                    lblType.Visible = true;
                    cdvTransType.Visible = true;
                    cdvTransType.VisibleButton = true;
                }
            }
        }

        public string TransType
        {
            get
            {
                return MPCF.Trim(cdvTransType.Text);
            }
            set
            {
                cdvTransType.Text = value;
            }
        }
        
        public bool AttachType_ReadOnly
        {
            get
            {
                return !cdvAttachType.VisibleButton;
            }
            set
            {
                if (value == true)
                {
                    lblDocType.Visible = false;
                    cdvAttachType.Visible = false;
                    txtAttachD.Visible = false;
                    cdvAttachType.VisibleButton = false;
                }
                else
                {
                    lblDocType.Visible = true;
                    cdvAttachType.Visible = true;
                    txtAttachD.Visible = true;
                    cdvAttachType.VisibleButton = true;
                }
            }
        }

        public string AttachType
        {
            get
            {
                return MPCF.Trim(cdvAttachType.Text);
            }
            set
            {
                cdvAttachType.Text = value;
            }
        }

        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string LotID
        {
            get
            {
                if (AttachType == "LOT")
                {
                    if (m_lot_id == null) m_lot_id = "";
                    return m_lot_id;
                }
                else
                {
                    return "";
                }
            }
            set
            {
                spdFileAttachList_Sheet1.RowCount = 0;
                if (AttachType == "LOT")
                {
                    m_lot_id = value;
                    txtAttachD.Text = m_lot_id;
                }
            }
        }

        [Browsable(false), DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        public string AttachID
        {
            get
            {
                if (AttachType != "LOT")
                {
                    if (m_doc_id == null) m_doc_id = "";
                    return m_doc_id;
                }
                else
                {
                    return "";
                }
            }
            set
            {
                spdFileAttachList_Sheet1.RowCount = 0;
                if (AttachType != "LOT")
                {
                    m_doc_id = value;
                    txtAttachD.Text = m_doc_id;
                }
            }
        }

        #endregion

        #region " Function Definition "

        //파일 업데이트 경로를 가져온다.
        private bool Get_Attach_Path(char ProcStep, string trans_type)
        {
            TRSNode in_node = new TRSNode("BAS_View_Data_In");
            TRSNode out_node = new TRSNode("BAS_View_Data_Out");
            //TRSNode path_node;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = ProcStep;

                in_node.AddString("TABLE_NAME", MPGC.MP_GCM_ATTACH_PATH);
                switch (trans_type)
                {
                    case "FTP":
                        in_node.AddString("KEY_1", "FTP");    /* file attach => FTP */
                        break;
                    case "FILE_COPY":
                        in_node.AddString("KEY_1", "FILE_COPY");   /* file attach => 네트워크 드라이브 */
                        break;
                    case "NETWORK":
                        in_node.AddString("KEY_1", "NETWORK");   /* file attach => 네트워크 드라이브 */
                        break;
                }

                if (MPCR.CallService("BAS", "BAS_View_Data", in_node, ref out_node) == false)
                {
                    return false;
                }

                m_attah_path = MPCF.Trim(out_node.GetString("DATA_1"));
                m_attach_user = MPCF.Trim(out_node.GetString("DATA_2"));
                m_attach_pwd = MPCF.Trim(out_node.GetString("DATA_3"));

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        public string Make_file_Path(string trans_type, string file_name)
        {
            string target_path;

            switch (trans_type)
            {
                case "FTP":
                    target_path =  m_attah_path + "/" + AttachID + "_" + file_name;
                    break;
                default:
                    target_path = "";
                    break;
            }

            return target_path;
        }

        protected bool Update_File_List()
        {
            TRSNode in_node = new TRSNode("BAS_View_Data_In");
            TRSNode out_node = new TRSNode("BAS_View_Data_Out");
            TRSNode list_item;
            FarPoint.Win.Spread.SheetView sheet;
            int i;

            try
            {
                sheet = spdFileAttachList_Sheet1;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("ATTACH_TYPE", AttachType);
                in_node.AddString("ATTACH_ID", AttachID);

                for (i = 0; i < sheet.RowCount; i++)
                {
                    list_item = in_node.AddNode("FILE_LIST");

                    list_item.AddString("FILE_NAME", sheet.GetText(i, COL_FILE_NAME));
                    list_item.AddString("FILE_PATH", sheet.GetText(i, COL_FILE_PATH));
                    list_item.AddString("TRANS_TYPE", sheet.GetText(i, COL_TRANS_TYPE));
                }

                if (MPCR.CallService("BAS", "BAS_Update_Attach_File", in_node, ref out_node) == false)
                {
                    return false;
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //
        public bool Upload_File(string trans_type, string file_name, string src_file, string file_path)
        {
            try
            {
                // 파일을 공유폴더로 업로드(Copy)한다.
                switch (trans_type)
                {
                    case "FTP":
                        if (Upload_By_FTP(src_file, "ftp://" + file_path) == false) return false;
                        break;
                    //case "FILE_COPY":
                    //    if (Upload_By_Copy() == false) return false;
                    //    break;
                    //case "NETWORK":
                    //    if (Upload_By_Copy(true) == false) return false;
                    //    break;
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

        }

        public bool Download_File(string trans_type, string file_name, string file_path, string local_path)
        {
            try
            {
                switch (trans_type)
                {
                    case "FTP":
                        Download_By_FTP("ftp://" + file_path, local_path);
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
            return true;
        }

        public bool Delete_File(string trans_type, string file_path)
        {
            try
            {
                switch (trans_type)
                {
                    case "FTP":
                        if (Delete_By_FTP("ftp://" + file_path) == false) return false;
                        break;
                    //case "FILE_COPY":
                    //    if (Upload_By_Copy() == false) return false;
                    //    break;
                    //case "NETWORK":
                    //    if (Upload_By_Copy(true) == false) return false;
                    //    break;
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //
        private bool Upload_By_FTP(string sorce_file, string ftp_path)
        {
            try
            {
                /* Class 생성하여 사용 (clsAttachFTPClient) */
                AttachFTPClient ftp = new AttachFTPClient();

                ftp.FtpServerIP = m_attah_path;
                ftp.FtpUserID = m_attach_user;
                ftp.FtpPassword = m_attach_pwd;

                ftp.Upload(sorce_file, ftp_path);
            }
            catch (WebException ex)
            {
                MessageBox.Show(ex.Message.ToString());
            }

            return true;
        }

        private void Download_By_FTP(string ftp_path, string local_path)
        {
            try
            {
                /* Class 생성하여 사용 (clsAttachFTPClient) */
                AttachFTPClient ftp = new AttachFTPClient();

                ftp.FtpServerIP = m_attah_path;
                ftp.FtpUserID = m_attach_user;
                ftp.FtpPassword = m_attach_pwd;

                ftp.DownLoad(ftp_path, local_path);

            }
            catch (WebException ex)
            {
                MessageBox.Show(ex.Message.ToString());
            }

            MessageBox.Show("파일 Download가 완료되었습니다");

            return;
        }

        private bool Delete_By_FTP(string ftp_path)
        {
            try
            {
                /* Class 생성하여 사용 (clsAttachFTPClient) */
                AttachFTPClient ftp = new AttachFTPClient();

                ftp.FtpServerIP = m_attah_path;
                ftp.FtpUserID = m_attach_user;
                ftp.FtpPassword = m_attach_pwd;

                ftp.DeleteFile(ftp_path);
            }
            catch (WebException ex)
            {
                MessageBox.Show(ex.Message.ToString());
            }

            return true;
        }

        //
        public bool View_File_List(char ProcStep)
        {
            return View_File_List(ProcStep, AttachType, AttachID);
        }
        public bool View_File_List(char ProcStep, string attach_type, string attach_id)
        {
            TRSNode in_node = new TRSNode("FILE_ATTACH_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");
            TRSNode list_item;
            FarPoint.Win.Spread.SheetView sheet;
            int i;

            try
            {
                sheet = spdFileAttachList_Sheet1;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = ProcStep;
                in_node.AddString("ATTACH_TYPE", attach_type);
                in_node.AddString("ATTACH_ID", attach_id);

                if (MPCR.CallService("BAS", "BAS_View_Attach_File_List", in_node, ref out_node) == false)
                {
                    return false;
                }

                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    list_item = out_node.GetList(0)[i];
                    sheet.RowCount = i + 1;

                    sheet.Cells[i, COL_TRANS_TYPE].Value = list_item.GetString("TRANS_TYPE");
                    sheet.Cells[i, COL_FILE_NAME].Value = list_item.GetString("FILE_NAME");
                    sheet.Cells[i, COL_FILE_PATH].Value = list_item.GetString("FILE_PATH");
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void Open_File(int iRow)
        {
            string file_path;
            string trans_type;
            FarPoint.Win.Spread.SheetView sheet;

            try
            {
                sheet = spdFileAttachList_Sheet1;
                trans_type = MPCF.Trim(sheet.GetText(iRow, COL_TRANS_TYPE));
                file_path = MPCF.Trim(sheet.GetText(iRow, COL_FILE_PATH));

                if (Get_Attach_Path('1', trans_type) == false)
                {
                    MPCF.ShowMsgBox("File Upload Attach Path(FTP) 정보가 존재하지 않습니다.");
                    return;
                }

                switch (trans_type)
                {
                    case "FTP":
                        AttachFTPClient ftp = new AttachFTPClient();

                        ftp.FtpServerIP = m_attah_path;
                        ftp.FtpUserID = m_attach_user;
                        ftp.FtpPassword = m_attach_pwd;

                        ftp.Open("ftp://" + file_path, "");

                        //System.Diagnostics.Process.Start("ftp://" + file_path);
                        //Download_By_FTP(0);
                        break;
                }
            }
            catch (WebException ex)
            {
                MessageBox.Show(ex.Message.ToString());
            }

            return;

        }

        private void Init()
        {
            TransType_ReadOnly = true;
            TransType = "FTP";

            AttachType_ReadOnly = true;
            AttachType = "LOT";
            AttachID = "";



            spdFileAttachList_Sheet1.RowCount = 0;
        }

        public void Clear()
        {
            AttachID = "";
            spdFileAttachList_Sheet1.RowCount = 0;
        }

        #endregion

        #region " Control Events "

        private System.EventHandler AddButtonPressEvent;
        public event System.EventHandler AddButtonPress
        {
            add
            {
                AddButtonPressEvent = (System.EventHandler)System.Delegate.Combine(AddButtonPressEvent, value);
            }
            remove
            {
                AddButtonPressEvent = (System.EventHandler)System.Delegate.Remove(AddButtonPressEvent, value);
            }
        }
        private System.EventHandler AddButtonPressEventAfter;
        public event System.EventHandler AddButtonPressAfter
        {
            add
            {
                AddButtonPressEventAfter = (System.EventHandler)System.Delegate.Combine(AddButtonPressEventAfter, value);
            }
            remove
            {
                AddButtonPressEventAfter = (System.EventHandler)System.Delegate.Remove(AddButtonPressEventAfter, value);
            }
        }
        private System.EventHandler DelButtonPressEvent;
        public event System.EventHandler DelButtonPress
        {
            add
            {
                DelButtonPressEvent = (System.EventHandler)System.Delegate.Combine(DelButtonPressEvent, value);
            }
            remove
            {
                DelButtonPressEvent = (System.EventHandler)System.Delegate.Remove(DelButtonPressEvent, value);
            }
        }
        private System.EventHandler DelButtonPressEventAfter;
        public event System.EventHandler DelButtonPressAfter
        {
            add
            {
                DelButtonPressEventAfter = (System.EventHandler)System.Delegate.Combine(DelButtonPressEventAfter, value);
            }
            remove
            {
                DelButtonPressEventAfter = (System.EventHandler)System.Delegate.Remove(DelButtonPressEventAfter, value);
            }
        }
        #endregion

        private void AddFile()
        {
            string file_name, file_path;
            int iRow, n;
            FarPoint.Win.Spread.SheetView sheet;

            try
            {
                sheet = spdFileAttachList.ActiveSheet;

                if (!this.fileUploadCompleted) { return; }

                openFileDialog.FileName = "";
                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    if (Get_Attach_Path('1', TransType) == false)
                    {
                        MPCF.ShowMsgBox("File Upload Attach Path(FTP) 정보가 존재하지 않습니다.");
                        return;
                    }

                    foreach (string file in openFileDialog.FileNames)
                    {
                        file_name = MPCF.Trim(file.Substring(file.LastIndexOf("\\") + 1));
                        file_path = Make_file_Path(TransType, file_name);

                        for (n = 0; n < sheet.RowCount; n++)
                        {
                            if (sheet.GetText(n, COL_FILE_PATH).Equals(file_path) == true)
                            {
                                if (MPCF.ShowMsgBox(file_name + " 파일이 이미 존재합니다. 계속 진행하시겠습니까?", MessageBoxButtons.YesNo, 0) == DialogResult.Yes)
                                {
                                    if (Upload_File(TransType, file_name, file, file_path) == false)
                                    {
                                        return;
                                    }
                                    //
                                    iRow = n;

                                    sheet.Cells[iRow, COL_TRANS_TYPE].Value = MPCF.Trim(cdvTransType.Text);
                                    sheet.Cells[iRow, COL_FILE_NAME].Value = MPCF.Trim(file_name);
                                    sheet.Cells[iRow, COL_FILE_PATH].Value = MPCF.Trim(file_path);
                                    break;
                                }
                                return;
                            }
                        }
                        if (n == sheet.RowCount)
                        {
                            if (Upload_File(TransType, file_name, file, file_path) == false)
                            {
                                return;
                            }
                            iRow = sheet.RowCount;

                            sheet.RowCount++;

                            sheet.Cells[iRow, COL_TRANS_TYPE].Value = MPCF.Trim(cdvTransType.Text);
                            sheet.Cells[iRow, COL_FILE_NAME].Value = MPCF.Trim(file_name);
                            sheet.Cells[iRow, COL_FILE_PATH].Value = MPCF.Trim(file_path);
                        }
                    }//End of For

                    //Upload DB
                    Update_File_List();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //
        private void btnAdd_Click(object sender, EventArgs e)
        {
            bool check = true;
            try
            {
                if (AddButtonPressEvent != null)
                    AddButtonPressEvent(this, e);

                if (MPCF.Trim(txtAttachD.Text) == "")
                {
                    switch (MPCF.Trim(cdvAttachType.Text))
                    {
                        case "LOT":
                            MPCF.ShowMsgBox(MPCF.GetMessage(154));
                            check = false;
                            break;
                    }
                }

                if (check)
                {
                    AddFile();
                }

                if (AddButtonPressEventAfter != null)
                    AddButtonPressEventAfter(this, e);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //리스트에서 파일 제거
        private void btnDel_Click(object sender, EventArgs e)
        {
            int iRow;
            string trans_type, file_path;

            try
            {
                if (DelButtonPressEvent != null)
                    DelButtonPressEvent(this, e);

                if (spdFileAttachList.ActiveSheet.RowCount > 0)
                {
                    iRow = spdFileAttachList.ActiveSheet.ActiveRowIndex;
                    trans_type = spdFileAttachList_Sheet1.GetText(iRow, COL_TRANS_TYPE);
                    file_path = spdFileAttachList_Sheet1.GetText(iRow, COL_FILE_PATH);

                    if (Get_Attach_Path('1', trans_type) == false)
                    {
                        MPCF.ShowMsgBox("File Remote Path(FTP) 정보가 존재하지 않습니다.");
                        return;
                    }

                    if (MPCF.ShowMsgBox(MPCF.GetMessage(53), MessageBoxButtons.YesNo, 2) == DialogResult.No)
                    {
                        return;
                    }

                    if (Delete_File(trans_type, "ftp://" + file_path) == false)
                    {
                        return;
                    }

                    //Upload DB
                    Update_File_List();
                }
                
                if (DelButtonPressEventAfter != null)
                    DelButtonPressEventAfter(this, e);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdFileAttachList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            FarPoint.Win.Spread.SheetView sheet;
            string trans_type, file_name, file_path, local_path;
            int iRow;

            try
            {
                if (e.Column == COL_DOWN_BUTTON)
                {
                    iRow = e.Row;

                    sheet = spdFileAttachList_Sheet1;
                    trans_type = MPCF.Trim(sheet.GetText(iRow, COL_TRANS_TYPE));
                    file_path = MPCF.Trim(sheet.GetText(iRow, COL_FILE_PATH));
                    file_name = MPCF.Trim(sheet.GetText(iRow, COL_FILE_NAME));

                    if (Get_Attach_Path('1', trans_type) == false)
                    {
                        MPCF.ShowMsgBox("File Remote Path(FTP) 정보가 존재하지 않습니다.");
                        return;
                    }

                    //다운로드 경로
                    folderBrowserDialog.SelectedPath = "C\\" + file_name;
                    if (folderBrowserDialog.ShowDialog() == DialogResult.OK)
                    {
                        local_path = MPCF.Trim(folderBrowserDialog.SelectedPath) + "\\" + file_name;

                        Download_File(trans_type, file_name, file_path, local_path);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdFileAttachList_CellDoubleClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            //if (e.RowHeader == false && e.Column == COL_FILE_NAME)
            //{
            //    View_File(e.Row);
            //}
        }

        private void cdvTransType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvTransType.Init();
                MPCF.InitListView(cdvTransType.GetListView);
                cdvTransType.Columns.Add("Initial ID", 50, HorizontalAlignment.Left);
                cdvTransType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvTransType.SelectedSubItemIndex = 0;

                if (BASLIST.ViewGCMDataList(cdvTransType.GetListView, '1', MPGC.MP_GCM_ATTACH_TYPE) == false)
                {
                    return;
                }
                cdvTransType.InsertEmptyRow(1, 0);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvAttachType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvAttachType.Init();
                MPCF.InitListView(cdvAttachType.GetListView);
                cdvAttachType.Columns.Add("ID", 50, HorizontalAlignment.Left);
                cdvAttachType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvAttachType.SelectedSubItemIndex = 0;

                if (BASLIST.ViewGCMDataList(cdvAttachType.GetListView, '1', "FILE_ATTACH_ID") == false)
                {
                    return;
                }
                cdvAttachType.InsertEmptyRow(1, 0);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        //// 파일을 업로드한다. (파일카피: 네트워크 폴더, 네트워크 드라이브 등 이용할 때)
        //private bool Upload_By_Copy()
        //{
        //    return Upload_By_Copy(false);
        //}
        //private bool Upload_By_Copy(bool bNetworkCopy)
        //{
        //    try
        //    {
        //        string strTarget = MPCF.Trim(m_attah_path);
        //        string strUSR = MPCF.Trim(m_attach_user);
        //        string strPWD = MPCF.Trim(m_attach_pwd);

        //        if (string.IsNullOrEmpty(strTarget)) // || string.IsNullOrEmpty(strUSR)
        //        {
        //            MessageBox.Show("공유정보가 부족합니다.");
        //            return false;
        //        }

        //        //에러나는 부분임
        //        if (bNetworkCopy)
        //        {
        //            // 먼저 네트웍 드라이브가 연결된 것이 있으면 해제한다.
        //            //try
        //            //{
        //            //    NetConnection.WNetCancelConnection2A(strTarget, 1, 0);
        //            //}
        //            //catch (Exception exer2)
        //            //{
        //            //    MessageBox.Show(exer2.Message.ToString());
        //            //    return false;
        //            //}

        //            //// 네트워크 드라이브 연결
        //            //NetConnection.ConnectNetDrive(strTarget, strUSR, strPWD);
        //        }

        //        // 리스트 순환하면서 데이터 업로드
        //        for (int i = 0; i < spdFileAttachList.ActiveSheet.RowCount; i++)
        //        {
        //            string sourcePath = MPCF.Trim(spdFileAttachList.ActiveSheet.GetValue(i, COL_FILE_PATH));
        //            string targetPath = strTarget;
        //            string sFILE_NAME = MPCF.Trim(spdFileAttachList.ActiveSheet.GetValue(i, COL_FILE_NAME));

        //            string sourceFile = sourcePath; //System.IO.Path.Combine(sourcePath, dataGridView1.Rows[dataGridView1.Rows.Count - 1].Cells["FILENM"].Value.ToString().Trim());
        //            string destFile = System.IO.Path.Combine(targetPath, sFILE_NAME);
        //            string prevFile = MPCF.Trim(spdFileAttachList.ActiveSheet.GetValue(i, COL_SERVER_PATH));

        //            if (MPCF.ToChar(spdFileAttachList_Sheet1.Cells[i, COL_STEP].Value) == MPGC.MP_STEP_DELETE)
        //            {
        //                if (System.IO.File.Exists(@prevFile))
        //                {
        //                    System.IO.File.Delete(@prevFile);
        //                }
        //            }
        //            else if (MPCF.ToChar(spdFileAttachList_Sheet1.Cells[i, COL_STEP].Value) == MPGC.MP_STEP_CREATE ||
        //                MPCF.ToChar(spdFileAttachList_Sheet1.Cells[i, COL_STEP].Value) == MPGC.MP_STEP_UPDATE)
        //            {
        //                spdFileAttachList_Sheet1.Cells[i, COL_SERVER_PATH].Value = destFile;

        //                if (!System.IO.Directory.Exists(@targetPath))
        //                {
        //                    System.IO.Directory.CreateDirectory(@targetPath);
        //                }
        //                System.IO.File.Copy(sourceFile, destFile, true);
        //                spdFileAttachList_Sheet1.Cells[i, COL_SERVER_PATH].Value = destFile;
        //            }

        //            Thread.Sleep(500);
        //        }

        //        // 네트웍 드라이브 해제
        //        try
        //        {
        //            //NetConnection.WNetCancelConnection2A(strTarget, 1, 0);
        //        }
        //        catch (Exception exer2)
        //        {
        //            MessageBox.Show(exer2.Message.ToString());
        //            return false;
        //        }

        //    }
        //    catch (WebException ex)
        //    {
        //        MessageBox.Show(ex.Message.ToString());
        //    }

        //    return true;
        //}

    }
}
