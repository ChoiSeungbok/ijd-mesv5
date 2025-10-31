using System;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Net;
using System.Collections.Generic;
using System.Text.RegularExpressions;
using Miracom.TRSCore;
using Miracom.MESCore;
using Miracom.CliFrx;
using System.Text;
using FarPoint.Excel;
using System.Linq;
using System.Drawing;


//using static System.Windows.Forms.VisualStyles.VisualStyleElement;



//20250218 김태연씨 요청 LOT별로 파일관리할수 있게 해달라고해서. 197.200.11.142 서버 파일관리용도로활용(예초에 ROUND 디펙트 이미 관리용도로 용량 10TB)
//하는김에 LOT별,품목별,사업부별 파일관리 할수있게 개발 사용할지는.......
namespace CUS_COM
{
    public partial class frmPopFtpUpDown : frmViewForm01
    {

        public string ftpServer = "FTP://197.200.11.142:10024" + "/USER"; // FTP 서버 주소
        public string ftpServer2 = "FTP://197.200.11.142:10024" + "/TEAM"; // FTP 서버 주소
        public string ftpServer3 = "FTP://197.200.11.142:10024" + "/LOT"; // FTP 서버 주소
        public string ftpServer4 = "FTP://197.200.11.142:10024" + "/ITEM"; // FTP 서버 주소_Load
        public string ftpUser = "";
        public string ftpPassword = "";
        private ProgressBar progressBar;



        public string g_Area_Id = string.Empty;
        public string g_LotId = string.Empty;
        public string g_Mat_id = string.Empty;
        public string g_Mat_Desc = string.Empty;
        public string g_PopYn = string.Empty;
        public string g_SearchType = "A";



        public frmPopFtpUpDown()
        {
            InitializeComponent();
            InitControl();
            //  EnsureFtpDirectoriesExist();
            // LoadFtpDirectories();
            InitializeProgressBar();
        }
        

        private void InitControl()
        {
            
            btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;

            directoryTreeView.AfterSelect += DirectoryTreeView_AfterSelect;
            directoryTreeView.DrawMode = TreeViewDrawMode.OwnerDrawText;
            directoryTreeView.DrawNode += DirectoryTreeView_DrawNode;


            fileListView.OwnerDraw = true;
            fileListView.Columns.Add("FILE NAME ", 300);
            fileListView.Columns.Add("SIZE", 100, System.Windows.Forms.HorizontalAlignment.Right);
            fileListView.Columns.Add("TYPE", 150);
            fileListView.DrawItem += FileListView_DrawItem;
            fileListView.DrawSubItem += FileListView_DrawSubItem;
            fileListView.DrawColumnHeader += FileListView_DrawColumnHeader;
            fileListView.ItemActivate += FileListView_ItemActivate;
            fileListView.DragEnter += FileListView_DragEnter;
            fileListView.DragDrop += FileListView_DragDrop;
            fileListView.ItemSelectionChanged += FileListView_ItemSelectionChanged;
            InitializeContextMenu();



        }


        private void InitializeProgressBar()
        {
            progressBar = new ProgressBar
            {
                Dock = DockStyle.Bottom,
                Minimum = 0,
                Maximum = 100,
                Step = 1,
                Visible = false
            };
            Controls.Add(progressBar);
        }

        private void RefreshUI()
        {
            /* if (directoryTreeView.SelectedNode != null)
             {
                  LoadFtpFiles(directoryTreeView.SelectedNode.Tag.ToString());

             }
            */
            if (fileListView.Tag != null)
            {
                // LoadFtpFiles(directoryTreeView.SelectedNode.Tag.ToString());

                LoadFtpFiles(fileListView.Tag.ToString());

            }


        }


        private void InitializeContextMenu()
        {


            string MenuName_1 = MPCF.FindLanguage("File Upload", 2);
            string MenuName_2 = MPCF.FindLanguage("Directory Upload", 2);
            string MenuName_3 = MPCF.FindLanguage("File Download", 2);
            string MenuName_4 = MPCF.FindLanguage("File Delete", 2);
            string MenuName_5 = MPCF.FindLanguage("New Directory", 2);


            contextMenu = new ContextMenuStrip();
            contextMenu.Items.Add(MenuName_1, null, UploadFilesSync);
            contextMenu.Items.Add(MenuName_2, null, UploadFolderSync);
            // contextMenu.Items.Add("파일 다운로드", null, DownloadFiles);
            contextMenu.Items.Add(MenuName_3, null, DownloadFilesSync);
            //contextMenu.Items.Add("파일 다운로드", null, (sender, e) => Task.Run(() => DownloadFiles(sender, e)));
            contextMenu.Items.Add(MenuName_4, null, DeleteFilesSync);
            contextMenu.Items.Add(MenuName_5, null, CreateNewFolder);
            fileListView.ContextMenuStrip = contextMenu;
        }


        private void LoadFtpFiles(string path)
        {
            fileListView.Items.Clear();

            string displayPath = path;
            if (displayPath.StartsWith(directoryTreeView.SelectedNode.Tag.ToString()))
            {
                displayPath = displayPath.Replace(directoryTreeView.SelectedNode.Tag.ToString(), directoryTreeView.SelectedNode.Text);
            }

            grpDirFileList.Text = "Dir Location : " + displayPath;

            // "..." (뒤로가기 버튼) 추가 (트리뷰 최상위보다 상위로 이동 불가)
            if (path != directoryTreeView.SelectedNode.Tag.ToString())
            {
                ListViewItem backItem = new ListViewItem(new string[] { "...", "", "Back" }) { Tag = GetParentPath(path) };
                fileListView.Items.Add(backItem);
            }

            try
            {
                FtpWebRequest request = (FtpWebRequest)WebRequest.Create(path);
                request.Method = WebRequestMethods.Ftp.ListDirectoryDetails;
                request.Credentials = new NetworkCredential(ftpUser, ftpPassword);

                using (FtpWebResponse response = (FtpWebResponse)request.GetResponse())
                using (StreamReader reader = new StreamReader(response.GetResponseStream()))
                {
                    while (!reader.EndOfStream)
                    {
                        string line = reader.ReadLine();
                        string name = ParseFtpFileName(line);
                        string type = line.ToLower().Contains("<dir>") || line.StartsWith("d") ? "Dir" : "File";
                        string size = "-";

                        if (type == "File")
                        {
                            long fileSize = ParseFtpFileSize(line);
                            if (fileSize > 0)
                            {
                                size = (fileSize / 1024) + " KB"; // KB 단위로 변환
                            }
                        }

                        ListViewItem item = new ListViewItem(new string[] { name, size, type }) { Tag = path + "/" + name };
                        fileListView.Items.Add(item);
                    }
                }

                fileListView.Tag = path;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private async Task LoadFtpDirectories()
        {
            directoryTreeView.Nodes.Clear();

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            string sFolderName = "Folder";

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            in_node.AddString("SQL", "SELECT 'FTP://' || DATA_1 || '/' || DATA_3 AS CODE,  "
                                     + "      KEY_1 AS VALUE ,   "
                                     + "      F_USER_NAME('" + MPGV.gsFactory + "',  '" + MPGV.gsUserID + "') AS USER_DESC, "
                                     + "       (SELECT DATA_1 FROM MGCMTBLDAT B WHERE TABLE_NAME ='C_WORK_TEAM' "
                                     + "         AND KEY_1 =(SELECT USER_CMF_4  FROM Msecusrdef C WHERE C.FACTORY = '"
                                     + MPGV.gsFactory + "' AND C.USER_ID ='" + MPGV.gsUserID + "')) AS USER_TEAM "
                                     + "  FROM MGCMTBLDAT A  "
                                     + "  WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                     + "   AND TABLE_NAME = 'C_FILE_SERVER' "
                                     + "   AND KEY_1 NOT IN ('IJDK1','IJDV1')  ");

            if (!MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node))
            {
                return;
            }

            sFolderName = MPCF.FindLanguage(sFolderName, 2);

            if (out_node.GetList("ROWS").Count > 0)
            {
                Dictionary<string, string> ftpRoots = new Dictionary<string, string>();

                for (int i = 0; i < out_node.GetList("ROWS").Count; i++)
                {
                    string sFtpAdress = "";
                    string sFtpName = "";

                    switch (out_node.GetList("ROWS")[i].GetList("COLS")[1].GetString("DATA"))
                    {


                        case "USER_FILE_SERVER":

                            if(g_SearchType == "A")
                            {
                                sFtpAdress = out_node.GetList("ROWS")[i].GetList("COLS")[0].GetString("DATA") + "//" + MPGV.gsUserID;
                                sFtpName = out_node.GetList("ROWS")[i].GetList("COLS")[2].GetString("DATA") + " " + sFolderName;
                                EnsureFtpDirectoriesExist(sFtpAdress);
                                ftpServer = sFtpAdress;
                            }

                            break;
                        case "TEAM_FILE_SERVER":
                            if (g_SearchType == "A")
                            {

                                sFtpAdress = out_node.GetList("ROWS")[i].GetList("COLS")[0].GetString("DATA") + "//" + out_node.GetList("ROWS")[i].GetList("COLS")[3].GetString("DATA");
                                sFtpName = out_node.GetList("ROWS")[i].GetList("COLS")[3].GetString("DATA") + " " + sFolderName;
                                EnsureFtpDirectoriesExist(sFtpAdress);
                                ftpServer2 = sFtpAdress;
                            }
                            break;
                        case "LOT_FILE_SERVER":

                            if (g_SearchType == "B")
                            {
                                //LOT폴더경로를 좀 그룹화하려고 했는데..부서마다 불규칙해서..일단 사업부 + LOT앞2 + LOT앞2 + LOT앞2
                                sFtpAdress = txtLotID.Text.Trim().Length != 0
                                ? out_node.GetList("ROWS")[i].GetList("COLS")[0].GetString("DATA") + "//" + g_Area_Id + "//" + txtLotID.Text.Substring(0, 2) + "//" + txtLotID.Text.Substring(2, 2) + "//" + txtLotID.Text.Substring(4, 2) + "//" + txtLotID.Text
                                : out_node.GetList("ROWS")[i].GetList("COLS")[0].GetString("DATA");
                                sFtpName = txtLotID.Text.Trim().Length != 0 ? txtLotID.Text + " " + sFolderName : "LOT" + " " + sFolderName;
                                EnsureFtpDirectoriesExist(sFtpAdress);
                                ftpServer3 = sFtpAdress;
                            }

                            break;
                        case "MAT_FILE_SERVER":
                            if (g_SearchType == "C")
                            {
                                //품목폴더 //사업부별로
                                sFtpAdress = cdvMatID.Text.Trim().Length != 0
                                ? out_node.GetList("ROWS")[i].GetList("COLS")[0].GetString("DATA") + "//" + g_Area_Id + "//" + cdvMatID.Text
                                : out_node.GetList("ROWS")[i].GetList("COLS")[0].GetString("DATA");
                                sFtpName = cdvMatID.Text.Trim().Length != 0 ? txtMatDesc.Text + " " + sFolderName : "ITEM" + " " + sFolderName;
                                ftpServer4 = sFtpAdress;
                                EnsureFtpDirectoriesExist(sFtpAdress);
                            }
                            break;
                    }

                    if (!string.IsNullOrEmpty(sFtpAdress) && !ftpRoots.ContainsKey(sFtpName))
                    {
                        ftpRoots.Add(sFtpName, sFtpAdress);
                    }
                }

                // 모든 FTP 서버의 하위 폴더를 비동기 처리
                List<Task> loadTasks = new List<Task>();

                foreach (var kvp in ftpRoots)
                {
                    TreeNode rootNode = new TreeNode(kvp.Key) { Tag = kvp.Value };
                    directoryTreeView.Nodes.Add(rootNode);
                    loadTasks.Add(Task.Run(() => LoadFtpSubDirectories(rootNode))); // 비동기 실행
                }

                await Task.WhenAll(loadTasks); // 모든 하위 폴더가 로드될 때까지 대기



                if (txtLotID.Text.Trim().Length != 0)
                {
                    UpdateSelectedNode(ftpServer3);
                }
                else if (cdvMatID.Text.Trim().Length != 0)
                {
                    UpdateSelectedNode(ftpServer4);
                }
                else
                {
                    UpdateSelectedNode(ftpServer);
                }

                if(g_SearchType == "A")
                {
                    pnlSeachData.Visible = false;
                }
                else
                {
                    pnlSeachData.Visible = true;
                }

            }
        }

        private async Task LoadFtpSubDirectoriesRecursively(TreeNode parentNode)
        {
            string path = parentNode.Tag.ToString();
            List<TreeNode> nodesToAdd = new List<TreeNode>();

            try
            {
                FtpWebRequest request = (FtpWebRequest)WebRequest.Create(path);
                request.Method = WebRequestMethods.Ftp.ListDirectoryDetails;
                request.Credentials = new NetworkCredential(ftpUser, ftpPassword);
                request.Timeout = 30000; // 30초 대기
                request.ReadWriteTimeout = 30000;
                request.UsePassive = true;
                request.KeepAlive = false;

                using (FtpWebResponse response = (FtpWebResponse)await request.GetResponseAsync())
                using (StreamReader reader = new StreamReader(response.GetResponseStream()))
                {
                    while (!reader.EndOfStream)
                    {
                        string line = reader.ReadLine();
                        if (IsFtpDirectory(line)) // 폴더인지 확인
                        {
                            string name = ParseFtpFileName(line);
                            string fullPath = path + "/" + name;
                            TreeNode node = new TreeNode(name) { Tag = fullPath };
                            nodesToAdd.Add(node);


                        }
                    }
                }

                // UI 갱신 최소화 (한 번만 Invoke 실행)
                if (nodesToAdd.Count > 0)
                {
                    directoryTreeView.Invoke((MethodInvoker)(() =>
                    {
                        foreach (var node in nodesToAdd)
                        {
                            parentNode.Nodes.Add(node);
                        }
                    }));
                }

                // 서버 부담 감소를 위해 지연 추가
                await Task.Delay(100);

                // 하위 폴더 재귀적으로 로드
                foreach (var node in nodesToAdd)
                {
                    await LoadFtpSubDirectoriesRecursively(node);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private bool IsFtpDirectory(string line)
        {
            //return line.ToLower().Contains("<dir>") || line.StartsWith("d");

            // 1️ Windows FTP 형식: "<DIR>" 포함 여부 확인
            if (line.ToLower().Contains("<dir>")) return true;

            // 2️ Linux FTP 형식: 권한이 "d"로 시작하는지 확인 (drwx------)
            if (Regex.IsMatch(line, @"^d")) return true;

            // 3️ 일반 파일인 경우
            return false;
        }


        private async void ReloadFtpDirectories(string previousSelectedPath)
        {
            await LoadFtpDirectories(); //  FTP 트리 다시 로드
            UpdateSelectedNode(previousSelectedPath); //  이전 선택 노드 복구
        }
        private void LoadFtpSubDirectories(TreeNode parentNode)
        {
            string path = parentNode.Tag.ToString();
            List<TreeNode> nodesToAdd = new List<TreeNode>();

            try
            {
                FtpWebRequest request = (FtpWebRequest)WebRequest.Create(path);
                request.Method = WebRequestMethods.Ftp.ListDirectoryDetails;
                request.Credentials = new NetworkCredential(ftpUser, ftpPassword);
                request.UsePassive = true;
                request.KeepAlive = false;
                request.Timeout = 30000; // 타임아웃 설정

                using (FtpWebResponse response = (FtpWebResponse)request.GetResponse())
                using (StreamReader reader = new StreamReader(response.GetResponseStream()))
                {
                    while (!reader.EndOfStream)
                    {
                        string line = reader.ReadLine();
                        if (IsFtpDirectory(line))
                        {
                            string name = ParseFtpFileName(line);
                            string fullPath = path + "/" + name;
                            TreeNode node = new TreeNode(name) { Tag = fullPath };
                            nodesToAdd.Add(node);
                        }
                    }
                }

                if (nodesToAdd.Count > 0)
                {
                    directoryTreeView.Invoke((MethodInvoker)(() =>
                    {
                        foreach (var node in nodesToAdd)
                        {
                            parentNode.Nodes.Add(node);
                        }
                    }));
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void UpdateDirectoryTreeView(string currentPath)
        {
            TreeNode targetNode = FindTreeNodeByPath(directoryTreeView.Nodes, currentPath);
            if (targetNode != null)
            {
                directoryTreeView.SelectedNode = targetNode;
                targetNode.Expand();
            }
        }
        private void UpdateSelectedNode(string previousSelectedPath)
        {
            if (string.IsNullOrEmpty(previousSelectedPath)) return;

            foreach (TreeNode node in directoryTreeView.Nodes)
            {
                TreeNode foundNode = FindTreeNodeByPath(node, previousSelectedPath);
                if (foundNode != null)
                {
                    directoryTreeView.SelectedNode = foundNode;
                    foundNode.Expand();
                    break;
                }
            }
        }

        private TreeNode FindTreeNodeByPath(TreeNode node, string path)
        {
            if (node.Tag.ToString() == path)
                return node;

            foreach (TreeNode child in node.Nodes)
            {
                TreeNode found = FindTreeNodeByPath(child, path);
                if (found != null)
                    return found;
            }
            return null;
        }

        private TreeNode FindTreeNodeByPath(TreeNodeCollection nodes, string path)
        {
            foreach (TreeNode node in nodes)
            {
                if (node.Tag.ToString() == path)
                    return node;

                TreeNode foundNode = FindTreeNodeByPath(node.Nodes, path);
                if (foundNode != null)
                    return foundNode;
            }
            return null;
        }




        private void DownloadFilesSync(object sender, EventArgs e)
        {
            _ = DownloadFiles(sender, e); // 경고 없이 실행 (비동기 메서드를 실행하되, 호출을 기다리지 않음)
        }

        private async Task DownloadFiles(object sender, EventArgs e)
        {
            if (fileListView.SelectedItems.Count == 0)
                return;

            using (FolderBrowserDialog folderDialog = new FolderBrowserDialog())
            {
                if (folderDialog.ShowDialog() == DialogResult.OK)
                {
                    progressBar.Visible = true;

                    foreach (ListViewItem item in fileListView.SelectedItems)
                    {
                        if (item.SubItems[2].Text == "Dir")
                        {
                            await CopyFtpFolderToLocal(item.Tag.ToString(), folderDialog.SelectedPath);
                        }
                        else
                        {
                            await DownloadFile(item.Tag.ToString(), folderDialog.SelectedPath);
                        }

                    }

                    progressBar.Visible = false;
                    //저장되었습니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(576));


                    RefreshUI();
                }
            }
        }

        private async Task DownloadFile(string remotePath, string localFolder)
        {
            //if (IsFtpDirectory(remotePath))

            if (IsFtpDirectory(remotePath))
            {

                if (localFolder.ToString().Trim() != "")
                {
                    await DownloadFolder(remotePath, localFolder);
                }
                else
                {

                    using (FolderBrowserDialog folderDialog = new FolderBrowserDialog())
                    {
                        if (folderDialog.ShowDialog() != DialogResult.OK) return;

                        await DownloadFolder(remotePath, localFolder);
                    }
                }



            }
            else
            {
                using (SaveFileDialog saveFileDialog = new SaveFileDialog())
                {

                    string localPath = "";

                    if (localFolder.ToString().Trim() != "")
                    {

                        //localPath = localFolder.ToString() + "\\" + Path.GetFileName(remotePath);
                        localPath = Path.Combine(localFolder.ToString(), Path.GetFileName(remotePath));
                    }
                    else
                    {
                        saveFileDialog.FileName = Path.GetFileName(remotePath);

                        if (saveFileDialog.ShowDialog() != DialogResult.OK) return;
                        localPath = saveFileDialog.FileName;
                    }



                    if (File.Exists(localPath))
                    {
                        if (MPCF.ShowMsgBox(MPCF.GetMessage(603), MessageBoxButtons.YesNo, 1) != DialogResult.Yes)
                        {
                            return;
                        }
                    }




                    try
                    {
                        FtpWebRequest request = (FtpWebRequest)WebRequest.Create(remotePath);
                        request.Method = WebRequestMethods.Ftp.DownloadFile;
                        request.Credentials = new NetworkCredential(ftpUser, ftpPassword);

                        using (FtpWebResponse response = (FtpWebResponse)await request.GetResponseAsync())
                        using (Stream responseStream = response.GetResponseStream())
                        using (FileStream fileStream = new FileStream(localPath, FileMode.Create))
                        {
                            await responseStream.CopyToAsync(fileStream);
                        }

                    }
                    catch (Exception ex)
                    {
                        //CMN546 INFO - 저장중 오류가 발생하였습니다. 관리자에게 문의바랍니다.
                        MPCF.ShowMsgBox(MPCF.GetMessage(546));
                        //return;
                    }
                }
            }
        }

        private async Task DownloadFolder(string remoteFolderPath, string localFolder)
        {
            string folderName = Path.GetFileName(remoteFolderPath);
            string localFolderPath = Path.Combine(localFolder, folderName);
            Directory.CreateDirectory(localFolderPath);

            List<string> fileList = GetFtpFileList(remoteFolderPath);
            foreach (string file in fileList)
            {
                string remoteFilePath = remoteFolderPath + "/" + file;
                await DownloadFile(remoteFilePath, localFolder);
            }
        }

        private async Task DownloadFolderRecursive(string ftpFolderPath, string localFolderPath)
        {
            List<string> files = new List<string>();
            List<string> directories = new List<string>();

            //  FTP에서 현재 폴더 내 파일 & 하위 폴더 목록 가져오기
            GetFtpFileAndFolderList(ftpFolderPath, ref files, ref directories);

            // 파일 다운로드
            foreach (string file in files)
            {
                string remoteFilePath = ftpFolderPath + "/" + file;
                string localFilePath = Path.Combine(localFolderPath, file);
                await DownloadFile(remoteFilePath, localFolderPath);
            }

            // 하위 폴더 재귀적으로 다운로드
            foreach (string directory in directories)
            {
                string remoteDirPath = ftpFolderPath + "/" + directory;
                string localDirPath = Path.Combine(localFolderPath, directory);
                Directory.CreateDirectory(localDirPath);
                await DownloadFolderRecursive(remoteDirPath, localDirPath);
            }
        }




        private void UploadFilesSync(object sender, EventArgs e)
        {
            _ = UploadFiles(); // 경고 없이 실행 (비동기 메서드를 실행하되, 호출을 기다리지 않음)
        }

        private void UploadFolderSync(object sender, EventArgs e)
        {
            _ = UploadFolder(); // 경고 없이 실행 (비동기 메서드를 실행하되, 호출을 기다리지 않음)
        }

        private async Task UploadFiles()
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog { Multiselect = true })
            {
                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    progressBar.Visible = true;
                    await UploadFilesToFtp(openFileDialog.FileNames);
                    progressBar.Visible = false;
                    RefreshUI();
                }
            }
        }

        private async Task UploadFolder()
        {
            using (FolderBrowserDialog folderDialog = new FolderBrowserDialog())
            {
                if (folderDialog.ShowDialog() == DialogResult.OK)
                {
                    progressBar.Visible = true;
                    await UploadFolderToFtp(folderDialog.SelectedPath);
                    progressBar.Visible = false;
                    RefreshUI();
                }
            }
        }

        private async Task UploadFilesToFtp(string[] paths)
        {
            foreach (string path in paths)
            {
                if (File.Exists(path))
                {
                    //  await UploadFile(path, directoryTreeView.SelectedNode.Tag.ToString());

                    await UploadFile(path, fileListView.Tag.ToString());

                }
            }
        }

        private async Task UploadFolderToFtp(string folderPath)
        {
            string folderName = Path.GetFileName(folderPath);
            //  string remoteFolderPath = directoryTreeView.SelectedNode.Tag.ToString() + "/" + folderName;
            string remoteFolderPath = fileListView.Tag.ToString() + "/" + folderName;



            try
            {
                //  먼저 원격에 폴더 생성
                FtpWebRequest request = (FtpWebRequest)WebRequest.Create(remoteFolderPath);
                request.Method = WebRequestMethods.Ftp.MakeDirectory;
                request.Credentials = new NetworkCredential(ftpUser, ftpPassword);
                await request.GetResponseAsync();
            }
            catch { } // 이미 존재하면 무시

            //   하위 폴더 및 파일 처리 
            await UploadFolderContents(folderPath, remoteFolderPath);
        }

        private async Task UploadFolderContents(string localPath, string remotePath)
        {
            foreach (string file in Directory.GetFiles(localPath))
            {
                string remoteFilePath = remotePath + "/" + Path.GetFileName(file);
                await UploadFile(file, remoteFilePath); // 개별 파일 업로드
            }

            foreach (string dir in Directory.GetDirectories(localPath))
            {
                string remoteDirPath = remotePath + "/" + Path.GetFileName(dir);

                try
                {
                    FtpWebRequest request = (FtpWebRequest)WebRequest.Create(remoteDirPath);
                    request.Method = WebRequestMethods.Ftp.MakeDirectory;
                    request.Credentials = new NetworkCredential(ftpUser, ftpPassword);
                    await request.GetResponseAsync();
                }
                catch { } // 이미 존재하면 무시

                // 돌면서 하위 폴더 내부도 업로드
                await UploadFolderContents(dir, remoteDirPath);
            }
        }

        private async Task UploadFile(string filePath, string remoteFilePath)
        {
            try
            {

                //  remoteFilePath = Uri.UnescapeDataString(remoteFilePath);

                remoteFilePath = remoteFilePath + "/" + Path.GetFileName(filePath);

                FtpWebRequest request = (FtpWebRequest)WebRequest.Create(remoteFilePath);
                request.Method = WebRequestMethods.Ftp.UploadFile;
                request.Credentials = new NetworkCredential(ftpUser, ftpPassword);

                using (FileStream fileStream = new FileStream(filePath, FileMode.Open, FileAccess.Read))
                using (Stream requestStream = request.GetRequestStream())
                {
                    await fileStream.CopyToAsync(requestStream);
                }
            }
            catch (Exception ex)
            {
                // CMN546 INFO -저장중 오류가 발생하였습니다. 관리자에게 문의바랍니다.
                //MPCF.ShowMsgBox(MPCF.GetMessage(602));

                MPCF.ShowMsgBox(ex.Message);
            }
        }





        private void DeleteFilesSync(object sender, EventArgs e)
        {
            _ = DeleteFiles(sender, e); 
        }

        private async Task DeleteFiles(object sender, EventArgs e)
        {
            if (fileListView.SelectedItems.Count == 0)
                return;






            //CMN453 INFO - 정말 삭제하시겠습니까?
            if (MPCF.ShowMsgBox(MPCF.GetMessage(453) + "(Total:" + fileListView.SelectedItems.Count + " File)", System.Windows.Forms.MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.Yes)
            {

                progressBar.Visible = true;

                foreach (ListViewItem item in fileListView.SelectedItems)
                {
                    if (item.SubItems[2].Text == "File")
                    {
                        await DeleteFile(item.Tag.ToString());
                    }
                    else
                    {
                        await DeleteFolderRecursive(item.Tag.ToString());
                    }
                    // await DeleteFolderRecursive(item.Tag.ToString(), item.SubItems[2].Text);


                }

                progressBar.Visible = false;
                RefreshUI();

            }
        }

        private async Task DeleteFolderRecursive(string remoteFolderPath)
        {
            List<string> files = GetFtpFileList(remoteFolderPath);
            foreach (string file in files)
            {
                string filePath = remoteFolderPath + "/" + file;
                await DeleteFile(filePath);
            }

            List<string> directories = GetFtpFolderList(remoteFolderPath);
            foreach (string dir in directories)
            {
                string dirPath = remoteFolderPath + "/" + dir;
                await DeleteFolderRecursive(dirPath);
            }

            await RemoveDirectory(remoteFolderPath);
        }

        private async Task DeleteFile(string remotePath)
        {
            try
            {
                FtpWebRequest request = (FtpWebRequest)WebRequest.Create(remotePath);
                request.Method = WebRequestMethods.Ftp.DeleteFile;
                request.Credentials = new NetworkCredential(ftpUser, ftpPassword);
                await request.GetResponseAsync();
            }
            catch (Exception ex)
            {
                //   MPCF.ShowMsgBox(ex.Message);
            }
        }

        private async Task RemoveDirectory(string remotePath)
        {
            try
            {
                FtpWebRequest request = (FtpWebRequest)WebRequest.Create(remotePath);
                request.Method = WebRequestMethods.Ftp.RemoveDirectory;
                request.Credentials = new NetworkCredential(ftpUser, ftpPassword);
                await request.GetResponseAsync();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        private async Task CopyFtpFolderToLocal(string ftpFolderPath, string localFolder)
        {
            // 로컬 폴더 생성 (존재하지 않으면 생성)
            string localFolderPath = Path.Combine(localFolder, Path.GetFileName(ftpFolderPath));
            Directory.CreateDirectory(localFolderPath);

            // 현재 FTP 폴더 내 파일 & 하위 폴더 목록 가져오기
            List<string> files = new List<string>();
            List<string> directories = new List<string>();

            GetFtpFileAndFolderList(ftpFolderPath, ref files, ref directories);

            //  파일 다운로드
            List<Task> downloadTasks = new List<Task>();
            foreach (string file in files)
            {
                string remoteFilePath = ftpFolderPath + "/" + file;
                downloadTasks.Add(DownloadFile(remoteFilePath, localFolderPath));
            }
            await Task.WhenAll(downloadTasks); // 모든 파일 다운로드 완료될 때까지 대기

            // 4하위 폴더도 돌면서 다운로드
            foreach (string directory in directories)
            {
                string remoteDirPath = ftpFolderPath + "/" + directory;
                await CopyFtpFolderToLocal(remoteDirPath, localFolderPath);
            }
        }
        private void CreateFtpDirectoryIfNotExists(string directoryPath)
        {
            try
            {

                if (DirectoryExists(directoryPath))
                {
                    //CMN601 INFO -동일디렉토리가 존재합니다
                    // MPCF.ShowMsgBox(MPCF.GetMessage(601));
                    return;
                }

                FtpWebRequest request = (FtpWebRequest)WebRequest.Create(directoryPath);
                request.Method = WebRequestMethods.Ftp.MakeDirectory;
                request.Credentials = new NetworkCredential(ftpUser, ftpPassword);
                request.UsePassive = true;
                request.KeepAlive = false;
                request.Timeout = 10000;

                using (FtpWebResponse response = (FtpWebResponse)request.GetResponse()) { }
            }
            catch (WebException ex)
            {
                //CMN602 INFO -FTP 디렉토리 생성 오류발생.지속적 발생시 관리자 문의바랍니다.
                MPCF.ShowMsgBox(MPCF.GetMessage(602));
            }
        }

        private async void CreateNewFolder(object sender, EventArgs e)
        {
            if (directoryTreeView.SelectedNode == null)
            {

                //CMN605 INFO - 먼저 디렉토리를 선택해주세요
                MPCF.ShowMsgBox(MPCF.GetMessage(605));
                return;
            }

            string currentPath = fileListView.Tag.ToString(); //directoryTreeView.SelectedNode.Tag.ToString();
            string newFolderName = "New Folder";

            // 같은 이름이 있으면 (New Folder) (1), (New Folder) (2) 형식으로 추가
            int count = 1;
            while (fileListView.Items.Cast<ListViewItem>().Any(item => item.Text.Equals(newFolderName)))
            {
                newFolderName = $"New Folder ({count++})";
            }

            string newFolderPath = currentPath + "/" + newFolderName;

            // FTP에 새 폴더 만들기
            bool success = await CreateFtpDirectory(newFolderPath);
            if (success)
            {
                ListViewItem item = new ListViewItem(newFolderName);
                item.SubItems.Add("-"); // 크기
                item.SubItems.Add("Dir"); // 유형
                item.Tag = newFolderPath;

                fileListView.Items.Add(item);
                item.BeginEdit(); // 사용자가 직접 폴더 이름을 수정할 수 있도록...
            }
        }
        private async Task<bool> CreateFtpDirectory(string directoryPath)
        {
            try
            {
                FtpWebRequest request = (FtpWebRequest)WebRequest.Create(directoryPath);
                request.Method = WebRequestMethods.Ftp.MakeDirectory;
                request.Credentials = new NetworkCredential(ftpUser, ftpPassword);
                request.UsePassive = true;
                request.KeepAlive = false;
                request.Timeout = 10000;

                using (FtpWebResponse response = (FtpWebResponse)await request.GetResponseAsync()) { }
                return true;
            }
            catch (WebException ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool RenameFtpDirectory(string oldPath, string newPath)
        {
            try
            {


                string previousSelectedPath = directoryTreeView.SelectedNode?.Tag.ToString();

                //  FTP 경로 디코딩 (한글, 특수 문자 처리)
                string decodedOldPath = Uri.UnescapeDataString(oldPath);
                string decodedNewPath = Uri.UnescapeDataString(newPath);

                //  부모 경로와 변경할 폴더명 분리
                string parentPath = Path.GetDirectoryName(decodedOldPath).Replace("\\", "/");
                string newFolderName = Path.GetFileName(decodedNewPath);

                if (string.IsNullOrEmpty(newFolderName))
                {

                    MPCF.ShowMsgBox(MPCF.GetMessage(606));
                    return false;
                }

                //  FTP RENAME 요청 (경로를 FTP에서 올바르게 인식하도록 수정)
                FtpWebRequest request = (FtpWebRequest)WebRequest.Create(decodedOldPath);
                request.Method = WebRequestMethods.Ftp.Rename;
                request.RenameTo = newFolderName; // "파일명"만 입력해야 함 (경로 포함 X)
                request.Credentials = new NetworkCredential(ftpUser, ftpPassword);
                request.UsePassive = true;
                request.UseBinary = true;
                request.KeepAlive = false;



                using (FtpWebResponse response = (FtpWebResponse)request.GetResponse()) { }

                ReloadFtpDirectories(previousSelectedPath);

                return true;
            }
            catch (WebException ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

        }



        private void EnsureFtpDirectoriesExist(string sFtpServer)
        {
            string[] directories = sFtpServer.Split('/');
            string currentPath = directories[0] + "//" + directories[2]; // FTP root path
            for (int i = 3; i < directories.Length; i++)
            {
                currentPath += "/" + directories[i];
                CreateFtpDirectoryIfNotExists(currentPath);
            }
        }

        private bool DirectoryExists(string directoryPath)
        {
            try
            {
                FtpWebRequest request = (FtpWebRequest)WebRequest.Create(directoryPath);
                request.Method = WebRequestMethods.Ftp.ListDirectory;
                request.Credentials = new NetworkCredential(ftpUser, ftpPassword);
                request.UsePassive = true;
                request.KeepAlive = false;
                request.Timeout = 10000;

                using (FtpWebResponse response = (FtpWebResponse)request.GetResponse()) { }
                return true; // 디렉토리가 존재함
            }
            catch (WebException ex)
            {
                if (ex.Response is FtpWebResponse response && response.StatusCode == FtpStatusCode.ActionNotTakenFileUnavailable)
                    return false; // 디렉토리가 존재하지 않음
            }
            return false; // 기타 오류 발생
        }



        private void GetFtpFileAndFolderList(string remoteFolderPath, ref List<string> files, ref List<string> directories)
        {
            try
            {
                FtpWebRequest request = (FtpWebRequest)WebRequest.Create(remoteFolderPath);
                request.Method = WebRequestMethods.Ftp.ListDirectoryDetails;
                request.Credentials = new NetworkCredential(ftpUser, ftpPassword);
                request.UsePassive = true;
                request.KeepAlive = false;
                request.Timeout = 30000;

                using (FtpWebResponse response = (FtpWebResponse)request.GetResponse())
                using (StreamReader reader = new StreamReader(response.GetResponseStream()))
                {
                    while (!reader.EndOfStream)
                    {
                        string line = reader.ReadLine();
                        string name = ParseFtpFileName(line);

                        if (IsFtpDirectory(line)) directories.Add(name); // 폴더면 directories 리스트에 추가
                        else files.Add(name); // 파일이면 files 리스트에 추가
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);

            }


        }

        private List<string> GetFtpFolderList(string remoteFolderPath)
        {
            List<string> folders = new List<string>();
            try
            {
                FtpWebRequest request = (FtpWebRequest)WebRequest.Create(remoteFolderPath);
                request.Method = WebRequestMethods.Ftp.ListDirectoryDetails;
                request.Credentials = new NetworkCredential(ftpUser, ftpPassword);

                using (FtpWebResponse response = (FtpWebResponse)request.GetResponse())
                using (StreamReader reader = new StreamReader(response.GetResponseStream()))
                {
                    while (!reader.EndOfStream)
                    {
                        string line = reader.ReadLine();
                        if (line.ToLower().Contains("<dir>") || Regex.IsMatch(line, "^d"))
                        {
                            folders.Add(ParseFtpFileName(line));
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            return folders;
        }

        private List<string> GetFtpFileList(string remoteFolderPath)
        {
            List<string> files = new List<string>();
            try
            {
                FtpWebRequest request = (FtpWebRequest)WebRequest.Create(remoteFolderPath);
                request.Method = WebRequestMethods.Ftp.ListDirectory;
                request.Credentials = new NetworkCredential(ftpUser, ftpPassword);

                using (FtpWebResponse response = (FtpWebResponse)request.GetResponse())
                using (StreamReader reader = new StreamReader(response.GetResponseStream()))
                {
                    while (!reader.EndOfStream)
                    {
                        files.Add(reader.ReadLine());
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            return files;
        }

        private string GetParentPath(string path)
        {
            if (string.IsNullOrEmpty(path) || path.LastIndexOf('/') <= "FTP://".Length)
            {
                return path; // 이미 최상위 폴더라면 그대로 반환
            }

            return path.Substring(0, path.LastIndexOf('/'));
        }

        private long ParseFtpFileSize(string line)
        {

            var match = Regex.Match(line, @"\s+(\d+)\s+\S+\s+\S+$"); // 마지막 숫자 부분 찾기
            if (match.Success)
            {
                return long.Parse(match.Groups[1].Value);
            }

            return 0; // 파일 크기 파싱 실패 시 0 반환
        }

        private string ParseFtpFileName(string line)
        {
            var match = System.Text.RegularExpressions.Regex.Match(
                  line,
                  @"(?:\d{2}-\d{2}-\d{2,4} +\d{2}:\d{2}[AP]M +<DIR> +|\d{2}-\d{2}-\d{2,4} +\d{2}:\d{2}[AP]M +[0-9]+ +)(.+)"
              );
            return match.Success ? match.Groups[1].Value.Trim() : line;
        }



        #region " Event Definition "

        private void FileListView_DrawColumnHeader(object sender, DrawListViewColumnHeaderEventArgs e)
        {
            e.DrawDefault = true; // 기본 스타일 유지
        }
        private void FileListView_DrawItem(object sender, DrawListViewItemEventArgs e)
        {
            e.DrawDefault = true; // 기본 스타일로 먼저 그리기
        }

        private void FileListView_DrawSubItem(object sender, DrawListViewSubItemEventArgs e)
        {
            Font regularFont = fileListView.Font;
            Font boldFont = new Font(fileListView.Font, FontStyle.Bold);

            if (e.Item.SubItems[2].Text == "Dir")  //  폴더라면
            {
                e.Graphics.DrawString(e.SubItem.Text, boldFont, Brushes.Black, e.Bounds, StringFormat.GenericDefault);
            }
            else //  파일이라면
            {
                e.Graphics.DrawString(e.SubItem.Text, regularFont, Brushes.Black, e.Bounds, StringFormat.GenericDefault);
            }
        }

        private void DirectoryTreeView_DrawNode(object sender, DrawTreeNodeEventArgs e)
        {
            if (e.Node == directoryTreeView.SelectedNode)
            {
                // 선택된 노드는 강조 색상 적용 (파란색)
                e.Graphics.FillRectangle(Brushes.LightBlue, e.Bounds);
                TextRenderer.DrawText(e.Graphics, e.Node.Text, directoryTreeView.Font, e.Bounds, Color.Black, TextFormatFlags.VerticalCenter);
            }
            else
            {
                // 선택되지 않은 노드는 기본 색상 적용
                e.DrawDefault = true;
            }
        }


        //2025-04-28 김태연씨 요청 이미지 파일 미리보기 만들어달라고함. syw
        private readonly string[] imgExts = { ".jpg", ".jpeg", ".png", ".bmp", ".gif", ".tif", ".tiff" };

        private async void FileListView_ItemSelectionChanged(object sender, ListViewItemSelectionChangedEventArgs e)
        {

            if (directoryTreeView.SelectedNode != null) directoryTreeView.Invalidate();
            /*
            if (directoryTreeView.SelectedNode != null)
            {
                // 트리뷰를 강제로 다시 그려서 선택된 노드 강조 유지
                directoryTreeView.Invalidate();


            }
            */
            if (!e.IsSelected) return;                      // 선택 해제 무시
            if (e.Item.SubItems[2].Text != "File") 
            {
                ClearPictureBox();
                return;  // 폴더/Back 무시
            }


            string ftpPath = e.Item.Tag.ToString();
            if (!imgExts.Contains(Path.GetExtension(ftpPath).ToLower()))
            {   // 이미지가 아니면 PictureBox 비우고 종료
                ClearPictureBox();
                return;
            }

            try
            {
                using (var img = await LoadImageFromFtpAsync(ftpPath))
                {

                    ClearPictureBox();
                    pictureBox1.Image = (Image)img.Clone(); 
                    pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;
                    splitContainer2.Panel2Collapsed = false;
                    ResizePanel2(0.5); 

                }
            }
            catch (Exception ex)
            {
                ClearPictureBox();
            }

        }

        private void ResizePanel2(double ratio = 0.4)   // ratio (0.0 ~ 1.0)
        {
            if (splitContainer2.Orientation == Orientation.Horizontal)
            {
                int panel2H = (int)(splitContainer2.Height * ratio);
                splitContainer2.SplitterDistance = splitContainer2.Height - panel2H;
            }
            else // Orientation.Vertical
            {
                int panel2W = (int)(splitContainer2.Width * ratio);
                splitContainer2.SplitterDistance = splitContainer2.Width - panel2W;
            }
        }

        private async Task<Image> LoadImageFromFtpAsync(string ftpPath)
        {
            FtpWebRequest req = (FtpWebRequest)WebRequest.Create(ftpPath);
            req.Method = WebRequestMethods.Ftp.DownloadFile;
            req.Credentials = new NetworkCredential(ftpUser, ftpPassword);
            req.UsePassive = true;
            req.KeepAlive = false;

            using (FtpWebResponse rsp = (FtpWebResponse)await req.GetResponseAsync())
            using (Stream ftpStream = rsp.GetResponseStream())
            {

                using (var ms = new MemoryStream())
                {
                    await ftpStream.CopyToAsync(ms);
                    ms.Position = 0;
                    return Image.FromStream(ms);  
                }
            }
        }

        // PictureBox 정리 헬퍼
        private void ClearPictureBox()
        {
            if (pictureBox1.Image != null)
            {
                pictureBox1.Image.Dispose();
                pictureBox1.Image = null;
                splitContainer2.Panel2Collapsed = true;
            }
        }


        private void DirectoryTreeView_AfterSelect(object sender, TreeViewEventArgs e)
        {
            LoadFtpFiles(e.Node.Tag.ToString());

            string DisplayPath = e.Node.Tag.ToString();


            if (DisplayPath.StartsWith(directoryTreeView.SelectedNode.Tag.ToString()))
            {
                DisplayPath = DisplayPath.Replace(directoryTreeView.SelectedNode.Tag.ToString(), directoryTreeView.SelectedNode.Text);
            }

            grpDirFileList.Text = "Dir Location: " + DisplayPath;


        }


        private void FileListView_ItemActivate(object sender, EventArgs e)
        {
            if (fileListView.SelectedItems.Count == 0)
                return;

            fileListView.Tag.ToString();

            ListViewItem selectedItem = fileListView.SelectedItems[0];
            string itemType = selectedItem.SubItems[2].Text;
            string selectedPath = selectedItem.Tag.ToString(); //fileListView.Tag.ToString(); // selectedItem.Tag.ToString();


            //  "..." 클릭 시 상위 폴더로 이동
            if (itemType == "Back")
            {
                //if (selectedPath != directoryTreeView.SelectedNode.Tag.ToString()) // 최상위 경로 제한

                if (selectedPath.ToString().Length >= directoryTreeView.SelectedNode.Tag.ToString().Length)
                {
                    LoadFtpFiles(selectedPath);
                    UpdateDirectoryTreeView(selectedPath);
                }
                return;
            }

            if (itemType == "Dir")
            {
                LoadFtpFiles(selectedPath);
                UpdateDirectoryTreeView(selectedPath);
            }
            else
            {
                _ = DownloadFile(selectedPath, "");
            }
        }

        private void FileListView_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Copy;
            }
        }

        private async void FileListView_DragDrop(object sender, DragEventArgs e)
        {
            string[] paths = (string[])e.Data.GetData(DataFormats.FileDrop);
            await UploadFilesToFtp(paths);

            RefreshUI();
        }

        private void btnView_Click(object sender, EventArgs e)
        {

        }

        private void cdvDirList_ButtonPress(object sender, EventArgs e)
        {

        }

        private void rdoUser_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void rdoTeam_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void rdoLot_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void rdoMatId_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void txtLotID_TextChanged(object sender, EventArgs e)
        {

        }

        private void lblMatID_Click(object sender, EventArgs e)
        {

        }

        private async void fileListView_ItemDrag(object sender, ItemDragEventArgs e)
        {
            if (fileListView.SelectedItems.Count == 0) return;

            List<string> downloadedFiles = new List<string>();

            //사용자 임시 폴더 (여기에 다운로드 후 Drag & Drop 실행)
            string tempFolder = Path.Combine(Path.GetTempPath(), "FTPTmpDownloads");
            Directory.CreateDirectory(tempFolder); // 폴더가 없으면 생성

            // Drag할 파일과 폴더 다운로드
            foreach (ListViewItem item in fileListView.SelectedItems)
            {
                string ftpPath = item.Tag.ToString(); // FTP 경로
                string itemType = item.SubItems[2].Text; // "File" 또는 "Dir"

                if (itemType == "File") //  파일 처리
                {
                    string localFilePath = Path.Combine(tempFolder, Path.GetFileName(ftpPath));

                    if (!File.Exists(localFilePath)) // 이미 다운로드된 파일은 다시 다운로드 안 함
                    {
                        await DownloadFile(ftpPath, tempFolder);
                    }

                    downloadedFiles.Add(localFilePath);
                }
                else if (itemType == "Dir") //  폴더 처리
                {
                    string localFolderPath = Path.Combine(tempFolder, Path.GetFileName(ftpPath));

                    if (!Directory.Exists(localFolderPath))
                    {
                        Directory.CreateDirectory(localFolderPath);
                        await DownloadFolderRecursive(ftpPath, localFolderPath);
                    }

                    downloadedFiles.Add(localFolderPath);
                }
            }

            // Drag 실행 전에 이전 이벤트 클리어
            Application.DoEvents();

            if (downloadedFiles.Count > 0)
            {
                DataObject data = new DataObject(DataFormats.FileDrop, downloadedFiles.ToArray());
                DoDragDrop(data, DragDropEffects.Copy);

                fileListView.SelectedItems.Clear();
            }
        }

        private async void frmPopFtpUpDown_DragDrop(object sender, DragEventArgs e)
        {



            if (!e.Data.GetDataPresent(DataFormats.FileDrop)) return;

            string[] ftpFilePaths = (string[])e.Data.GetData(DataFormats.FileDrop);

            using (FolderBrowserDialog folderDialog = new FolderBrowserDialog())
            {
                if (folderDialog.ShowDialog() != DialogResult.OK) return;

                string localDirectory = folderDialog.SelectedPath;

                progressBar.Visible = true;



                foreach (string ftpFilePath in ftpFilePaths)
                {
                    if (File.Exists(ftpFilePath)) //  이미 다운로드된 경우
                    {
                        string finalPath = Path.Combine(localDirectory, Path.GetFileName(ftpFilePath));
                        File.Copy(ftpFilePath, finalPath, true); // 덮어쓰기 허용
                    }
                    else // FTP 경로가 직접 전달된 경우 → 다운로드 수행
                    {
                        await DownloadFile(ftpFilePath, localDirectory);
                    }
                }

                progressBar.Visible = false;
                MPCF.ShowMsgBox(MPCF.GetMessage(576)); // "저장되었습니다."
            }
        }

        private void frmPopFtpUpDown_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Copy;
            }
        }

        private void frmPopFtpUpDown_Load(object sender, EventArgs e)
        {


            if (g_PopYn == "Y")
            {
                if (g_LotId.Trim().Length != 0)
                {

                    txtLotID.Text = g_LotId;
                }
                if (g_Mat_id.Trim().Length != 0)
                {

                    cdvMatID.Text = g_Mat_id;
                }
                if (g_Mat_Desc.Trim().Length != 0)
                {

                    txtMatDesc.Text = g_Mat_Desc;
                }

                if (g_Area_Id.Trim().Length == 0)
                {

                    g_Area_Id = MPGV.gsUserAreaID;
                }

            }


            _ = LoadFtpDirectories();
        }

        private void fileListView_AfterLabelEdit(object sender, LabelEditEventArgs e)
        {
            if (e.Label == null) return; // 사용자가 이름을 변경하지 않은 경우

            ListViewItem item = fileListView.Items[e.Item];

            // "..."(뒤로가기) 버튼이면 이름 변경 취소
            if (item.Text == "...")
            {
                e.CancelEdit = true;
                return;
            }

            string oldPath = item.Tag.ToString();

            //  FTP 경로를 직접 처리하여 부모 폴더 경로 가져오기
            int lastSlashIndex = oldPath.LastIndexOf('/');
            string parentPath = lastSlashIndex > 0 ? oldPath.Substring(0, lastSlashIndex) : oldPath;

            //  새로운 폴더 경로 생성
            string newPath = $"{parentPath}/{e.Label}";

            //  중복된 이름 확인
            if (fileListView.Items.Cast<ListViewItem>().Any(i => i.Text.Equals(e.Label)))
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(601)); // "동일한 디렉토리가 존재합니다."
                e.CancelEdit = true;
                return;
            }

            //  FTP에서 폴더 이름 변경
            bool success = RenameFtpDirectory(oldPath, newPath);
            if (success)
            {
                item.Tag = newPath;
                _ = LoadFtpDirectories();
            }
            else
            {
                e.CancelEdit = true;
            }
        }
        #endregion







    }
}