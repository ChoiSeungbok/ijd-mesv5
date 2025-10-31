using System;
using System.IO;
using System.Data;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using System.Collections;
using Microsoft.Win32;
using ICSharpCode.SharpZipLib.Zip;
using ICSharpCode.SharpZipLib.Zip.Compression;
using ICSharpCode.SharpZipLib.Zip.Compression.Streams;

using Miracom.CliFrx;
using Miracom.MESCore;
using Miracom.MsgHandler;
using Miracom.TRSCore;


namespace MESplusUpgradeMsg
{
    public class frmUpgrade : Form
    {
        
        #region "Windows Form generate code "
        public frmUpgrade()
        {
            
            
            
            InitializeComponent();
        }
        
        protected override void Dispose(bool Disposing)
        {
            if (Disposing)
            {
                if (components != null)
                {
                    components.Dispose();
                }
            }
            base.Dispose(Disposing);
        }
        
        private System.ComponentModel.Container components = null;
        public ToolTip ToolTip1;



        internal Label lblMessage;
        public ProgressBar panProgress;
        [System.Diagnostics.DebuggerStepThrough()]private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            base.Activated += new System.EventHandler(frmUpgrade_Activated);
            base.Closing += new System.ComponentModel.CancelEventHandler(frmUpgrade_Closing);
            base.Load += new System.EventHandler(frmUpgrade_Load);
            System.Resources.ResourceManager resources = new System.Resources.ResourceManager(typeof(frmUpgrade));
            this.ToolTip1 = new System.Windows.Forms.ToolTip(this.components);
            this.lblMessage = new System.Windows.Forms.Label();
            this.panProgress = new System.Windows.Forms.ProgressBar();
            this.SuspendLayout();
            //
            //lblMessage
            //
            this.lblMessage.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblMessage.ForeColor = System.Drawing.Color.Blue;
            this.lblMessage.Location = new System.Drawing.Point(72, 36);
            this.lblMessage.Name = "lblMessage";
            this.lblMessage.Size = new System.Drawing.Size(313, 37);
            this.lblMessage.TabIndex = 2;
            this.lblMessage.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            //
            //panProgress
            //
            this.panProgress.AccessibleName = "panProgress";
            this.panProgress.Location = new System.Drawing.Point(12, 12);
            this.panProgress.Name = "panProgress";
            this.panProgress.Size = new System.Drawing.Size(436, 12);
            this.panProgress.Step = 1;
            this.panProgress.TabIndex = 3;
            //
            //frmUpgrade
            //
            this.AutoScaleBaseSize = new System.Drawing.Size(6, 14);
            this.BackColor = System.Drawing.SystemColors.Control;
            this.ClientSize = new System.Drawing.Size(461, 89);
            this.Controls.Add(this.panProgress);
            this.Controls.Add(this.lblMessage);
            this.Cursor = System.Windows.Forms.Cursors.Default;
            this.Icon = (System.Drawing.Icon) resources.GetObject("$this.Icon");
            this.Location = new System.Drawing.Point(3, 15);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "frmUpgrade";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "MESplus Client Upgrade Manager";
            this.ResumeLayout(false);
            
        }
        #endregion
        
        private string[] argv;
        private bool NormalExit;
        private int DownFileListCount;
        private bool UpgradeFlag;
        
        
        #region "Function Definition"
        
        private bool _01_FindingServer()
        {
            
            try
            {
                lblMessage.Text = "Connecting Message Bus";
                Application.DoEvents();
                ChangeProgress(1);

                MPGV.gsProgramID = Application.ProductName;
                MPIF.gInit = new clsInitialFunctionImp();

                MPGV.gsSiteID = argv[2];
                MPGV.gsRemoteAddress = argv[1];

                MPGV.gsRvService = "";
                MPGV.gsRvNetwork = "";
                MPGV.gsPassword = "";

                try
                {
                    MPGV.gsRvService = argv[4];
                    MPGV.gsRvNetwork = argv[5];
                }
                catch(Exception ex)
                {
                    System.Diagnostics.Debug.WriteLine(ex.Message);
                }
                
                MPGV.gsFactory = "SYSTEM";
                MPGV.gsUserID = "ADMIN";
                MPGV.giTimeOut = 120; //2분
                MPIF.gInit.setTTL(MPGV.giTimeOut);

                if (MPIF.gInit.InitMsgHandler() == false)
                {
                    MessageBox.Show("ERROR - Middleware connection");
                    return false;
                }
                
                try
                {
                    File.Delete(Application.StartupPath + "\\" + argv[3]);
                }
                catch (Exception)
                {
                }
                
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
            
            return true;
            
        }
        
        private bool _02_XmlFileDownload()
        {
            try
            {
                lblMessage.Text = "File List Downloading : " + argv[3];
                Application.DoEvents();
                ChangeProgress(2);

                TRSNode in_node = new TRSNode("UPGRADE_MSG_IN");
                TRSNode out_node = new TRSNode("UPGRADE_MSG_OUT");

                MPCR.SetInMsg(in_node);
                in_node.Factory = "SYSTEM";
                in_node.ProcStep = '1';

                in_node.AddString("FILE_NAME", argv[3]);

                if (MPCR.CallService("BAS", "BAS_Upgrade_Msg", in_node, ref out_node, DeliveryMode.RReply, true) == false)
                {
                    if (out_node.GetString("MSG").Trim() != "")
                    {
                        MessageBox.Show(out_node.GetString("MSG"));
                    }
                    return false;
                }

                //Save File
                //DownloadFile.xml은 upgrade프로그램 위치에 존재한다
                FileStream fs = File.Open(Application.StartupPath + "\\" + argv[3], FileMode.Create);
                BinaryWriter bw = new BinaryWriter(fs);
                byte[] buffer;
                DateTime dt_create_time;

                fs.Flush();
                buffer = out_node.GetBlob(MPGC.MP_BIN_DATA_2);
                bw.Write(buffer);

                bw.Close();
                fs.Close();

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
            
            return true;
            
        }
        
        private bool _03_XmlFileParse()
        {
            string sInitDownFile = "";
            bool bRet;
            
            try
            {
                lblMessage.Text = "XML File Parse";
                Application.DoEvents();
                ChangeProgress(3);
                
                sInitDownFile = Application.StartupPath + "\\" + argv[3];
                bRet = clsCommon.GetFileList(sInitDownFile);
                
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
            
            return bRet;
            
        }
        
        private bool _04_KillProcess()
        {
            
            System.Diagnostics.Process[] processArray;
            bool bContinue;
            int i;
            
            lblMessage.Text = "Process Kill";
            Application.DoEvents();
            ChangeProgress(4);
            
            try
            {
                RegistryKey rk = Registry.LocalMachine.OpenSubKey("SYSTEM\\CurrentControlSet\\Services\\PerfProc\\Performance", true);
                object dpc_value = rk.GetValue("Disable Performance Counters");
                
                if (dpc_value != null)
                {
                    if (Convert.ToInt32(dpc_value) > 0)
                    {
                        rk.SetValue("Disable Performance Counters", 0);
                    }
                }
            }
            catch (Exception)
            {
                // Vista 에서 위 레지스트리를 찾을수 없어 에러 발생하므로 그냥 패스시킴
                //MsgBox(ex.Message)
                //Return False
            }
            
            bContinue = true;
            
            while (bContinue)
            {
                try
                {
                    processArray = Process.GetProcessesByName(clsCommon.ExecuteFile.Substring(0, clsCommon.ExecuteFile.Length- 4));
                    for (i = 0; i <= processArray.Length - 1; i++)
                    {
                        processArray[i].Kill();
                    }
                    
                    bContinue = false;
                    
                }
                catch (Exception ex)
                {
                    // Vista에서 위 코드 수행중 에러발생
                    // 아래와 같이 중단, 재시도, 무시 버튼을 표시하고 사용자가 무시버튼 클릭하여 계속 진행 할 수 있도록 함.
                    DialogResult ret;
                
                    ret = MessageBox.Show(ex.Message, Application.ProductName, MessageBoxButtons.AbortRetryIgnore);
                    switch (ret)
                    {
                        case DialogResult.Abort:
                            return false;
                        case DialogResult.Ignore:
                            return true;
                    }
                }
            }
            
            return true;
            
        }
        
        private bool _05_UpgradeFileDownload()
        {
            int k;
            int i;
            string DownPath = "";
            string DownFile = "";
            
            FileVersionInfo UpgradeFileInfo;
            string UpgradeVersion = "";

            try
            {
                lblMessage.Text = "Start Download";
                Application.DoEvents();
                ChangeProgress(5);

                String ClientPath = getMainPath();

                DownFileListCount = clsCommon.DownFileList[1].GetLength(0);
                
                //새로운 파일을 해당위치에 받는다
                for (k = 0; k <= DownFileListCount - 1; k++)
                {
                    if (clsCommon.DownFileList[1][k] == "")
                    {
                        break;
                    }
                    
                    //DLL의 충돌을 피하기 위해서 MESClient의 하위에 _upgrade폴드를 만들고 여기서 upgrade프로그램이 기동된다.
                    //그럼으로 Application.StartupPath의 상위에 파일을 받아서 처리한다.
                    if (clsCommon.DownFileList[3][k].Trim() == ".")
                    {
                        DownPath = ClientPath;
                    }
                    else
                    {
                        if (clsCommon.DownFileList[3][k].Trim().Substring(clsCommon.DownFileList[3][k].Trim().Length - 1, 1) == "\\")
                        {
                            DownPath = ClientPath.Substring(0, ClientPath.Length - 1) + clsCommon.DownFileList[3][k].Substring(1);
                        }
                        else
                        {
                            DownPath = ClientPath.Substring(0, ClientPath.Length - 1) + clsCommon.DownFileList[3][k].Substring(1) + "\\";
                        }
                    }
                    
                    if (Directory.Exists(DownPath.Substring(0, DownPath.Length - 1)) == false)
                    {
                        Directory.CreateDirectory(DownPath);
                    }
                    
                    DownFile = clsCommon.DownFileList[1][k];
                    
                    //Update 하다가 남은 파일 삭제
                    try
                    {
                        File.Delete(DownPath + DownFile + ".new");
                    }
                    catch (Exception)
                    {
                    }

                    try
                    {
                        // 파일의 버전을 구한 후 Client Side File Version과 Server Side File Version을 비교 후 일치하지 
                        // 않으면 파일을 받는다.  2017.11.28 by Lee Hwanno
                        if (clsCommon.DownFileList[4][k] != "ZIP")
                        {
                            if (File.Exists(DownPath + DownFile) == false)
                            {
                                UpgradeVersion = "";
                            }
                            else
                            {
                                UpgradeFileInfo = System.Diagnostics.FileVersionInfo.GetVersionInfo(DownPath + DownFile);
                                UpgradeVersion = UpgradeFileInfo.FileVersion;
                            }
                        }
                        else
                        {
                            UpgradeVersion = "";
                        }

                        if (UpgradeVersion != clsCommon.DownFileList[2][k])
                        {
                            // 압축 풀기전 기존 파일의 속성이 읽기전용, 숨김, System으로 되었을때 속성을 변경한다.
                            // 2107.11.28 by Lee Hwanno
                            if (File.Exists(DownPath + DownFile))
                            {
                                if ((File.GetAttributes(DownPath + DownFile) & FileAttributes.ReadOnly) == FileAttributes.ReadOnly)
                                    File.SetAttributes(DownPath + DownFile, FileAttributes.Archive);
                                else if ((File.GetAttributes(DownPath + DownFile) & FileAttributes.Hidden) == FileAttributes.Hidden)
                                    File.SetAttributes(DownPath + DownFile, FileAttributes.Archive);
                                else if ((File.GetAttributes(DownPath + DownFile) & FileAttributes.System) == FileAttributes.System)
                                    File.SetAttributes(DownPath + DownFile, FileAttributes.Archive);
                            }

                            lblMessage.Text = "Downloading " + DownFile;
                            Application.DoEvents();

                            // 기존 파일을 .old로 복사한다.
                            if (File.Exists(DownPath + DownFile) == true)
                            {
                                try
                                {
                                    File.Delete(DownPath + DownFile + ".old");
                                    File.Copy(DownPath + DownFile, DownPath + DownFile + ".old");
                                    File.Delete(DownPath + DownFile);
                                }
                                catch (Exception)
                                {
                                }
                            }

                            lblMessage.Text = "Downloading " + DownFile;
                            Application.DoEvents();
                            ChangeProgress(6);

                            TRSNode in_node = new TRSNode("UPGRADE_MSG_IN");
                            TRSNode out_node = new TRSNode("UPGRADE_MSG_OUT");

                            MPCR.SetInMsg(in_node);
                            in_node.Factory = "SYSTEM";
                            in_node.ProcStep = '1';

                            in_node.AddString("FILE_NAME", DownFile);

                            if (MPCR.CallService("BAS", "BAS_Upgrade_Msg", in_node, ref out_node, DeliveryMode.RReply, true) == false)
                            {
                                if (out_node.GetString("MSG").Trim() != "")
                                {
                                    MessageBox.Show(out_node.GetString("MSG"));
                                }
                                return false;
                            }

                            //Save File
                            FileStream fs = File.Open(DownPath + DownFile, FileMode.Create);
                            BinaryWriter bw = new BinaryWriter(fs);
                            byte[] buffer;
                            DateTime dt_create_time;

                            fs.Flush();
                            buffer = out_node.GetBlob(MPGC.MP_BIN_DATA_2);
                            bw.Write(buffer);

                            bw.Close();
                            fs.Close();
                        }
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message);  
                        try
                        {
                            File.Copy(DownPath + DownFile + ".old", DownPath + DownFile);
                            File.Delete(DownPath + DownFile + ".old");
                        }
                        catch (Exception)
                        {
                        }
                        return false;
                    }  
                }
                
                for (k = 0; k <= DownFileListCount - 1; k++)
                {
                    for (i = 0; i <= 20; i++)
                    {
                        if (File.Exists(DownPath + clsCommon.DownFileList[1][k]) == false)
                        {
                            System.Threading.Thread.Sleep(50);
                            Application.DoEvents();
                        }
                        else
                        {
                            break;
                        }
                    }
                    
                    if (i > 20)
                    {
                        MessageBox.Show("Fail to Downloading File : " + clsCommon.DownFileList[1][k], "ERROR");
                        return false;
                    }
                }
                
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
            
            return true;
            
        }
        
        private bool _06_ProcessDownloadFile()
        {
            int k;
            string DownPath;
            string DownFile;

            lblMessage.Text = "Processing";
            Application.DoEvents();
            ChangeProgress(7);

            String ClientPath = getMainPath();

            try
            { 
                for (k = 0; k <= DownFileListCount - 1; k++)
                {
                    if (clsCommon.DownFileList[1][k] == "")
                    {
                        break;
                    }
                    
                    if (clsCommon.DownFileList[3][k].Trim() == ".")
                    {
                        DownPath = ClientPath;
                    }
                    else
                    {
                        if (clsCommon.DownFileList[3][k].Trim().Substring(clsCommon.DownFileList[3][k].Trim().Length - 1, 1) == "\\")
                        {
                            DownPath = ClientPath.Substring(0,ClientPath.Length-1) + clsCommon.DownFileList[3][k].Substring(1);
                        }
                        else
                        {
                            DownPath = ClientPath.Substring(0, ClientPath.Length - 1) + clsCommon.DownFileList[3][k].Substring(1) + "\\";
                        }
                    }
                    DownFile = clsCommon.DownFileList[1][k];
                    
                    //Zip 파일의 경우 압축을 해제한다
                    if (clsCommon.DownFileList[4][k] == "ZIP")
                    {
                        
                        lblMessage.Text = "Unzip " + DownFile;
                        Application.DoEvents();
                        
                        ZipInputStream s = new ZipInputStream(File.OpenRead(DownPath + DownFile));
                        
                        ZipEntry theEntry;
                        while (true)
                        {
                            theEntry = s.GetNextEntry();
                            if (theEntry == null)
                            {
                                break;
                            }
                            //Debug.WriteLine(theEntry.Name)
                            string directoryName = Path.GetDirectoryName(clsCommon.DownFileList[3][k]);
                            string fileName = Path.GetFileName(theEntry.Name);
                            
                            if (directoryName != "")
                            {
                                Directory.CreateDirectory(DownPath + directoryName);
                                directoryName = directoryName + "\\";
                            }
                            
                            if (!(fileName == string.Empty))
                            {
                                FileStream streamWrite = File.Create(DownPath + directoryName + fileName);
                                int size = 2048;
                                byte[] data = new byte[2049];
                                while (true)
                                {
                                    size = s.Read(data, 0, data.Length);
                                    if (size > 0)
                                    {
                                        streamWrite.Write(data, 0, size);
                                    }
                                    else
                                    {
                                        streamWrite.Flush();
                                        streamWrite.Close();
                                        break;
                                    }
                                }
                            }
                        }
                        
                        s.Close();
                        
                        lblMessage.Text = "Remove file " + DownFile;
                        Application.DoEvents();
                        
                        //Write Chche처리...
                        if (File.Exists(DownPath + DownFile) == true)
                        {
                            try
                            {
                                File.Copy(DownPath + DownFile, DownPath + DownFile + ".new");
                                File.Delete(DownPath + DownFile);
                                File.Delete(DownPath + DownFile + ".new");
                            }
                            catch (Exception)
                            {
                            }
                        }
                    }
                    
                    if (clsCommon.DownFileList[4][k] == "REG")
                    {
                        System.Diagnostics.Process.Start("regsvr32 /s " + DownPath + DownFile);
                    }
                }
                
                //Down 받을 File 목록 파일을 삭제한다
                try
                {
                    //DownloadFile.xml은 upgrade프로그램 위치에 존재한다
                    File.Delete(Application.StartupPath + "\\" + argv[3]);
                }
                catch (Exception)
                {
                }
                
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
            
            return true;
            
        }
        
        private bool _07_ExecuteFile()
        {
            
            try
            {
                ChangeProgress(8);

                String ClientPath = getMainPath();

                if (clsCommon.ExecuteFile != "")
                {
                    lblMessage.Text = "Execute " + clsCommon.ExecuteFile;
                    Application.DoEvents();

                    clsCommon.ExecuteFile = ClientPath + clsCommon.ExecuteFile;
                    System.Diagnostics.Process.Start(clsCommon.ExecuteFile);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }
            
            return true;
        }

        //Upgrade Program의 상위 Path를 가지고 온다
        private string getMainPath()
        {
            int k;
            String ClientPath = Application.StartupPath;
            for (k = ClientPath.Length - 1; k >= 0; k--)
            {
               if (ClientPath.Substring(k, 1) == "\\")
                {
                    break;
                }
            }
            ClientPath = ClientPath.Substring(0, k + 1);
            //임시
            //ClientPath = ClientPath + "temp" + "\\";

            return ClientPath;
        }
        
        #endregion
        
        private void frmUpgrade_Activated(System.Object eventSender, System.EventArgs eventArgs)
        {
            try
            {
                // Upgrade Activate 한번만 수행
                if (UpgradeFlag == true)
                {
                    return;
                }

                UpgradeFlag = true;
                NormalExit = false;

                this.Text += " (" + Application.ProductVersion + ")";

                if (_01_FindingServer() == false) return;
                if (_02_XmlFileDownload() == false) return;
                if (_03_XmlFileParse() == false) return;
                if (_04_KillProcess() == false) return;
                if (_05_UpgradeFileDownload() == false) return;
                if (_06_ProcessDownloadFile() == false) return;
                if (_07_ExecuteFile() == false) return;

                NormalExit = true;

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            finally
            {
                this.Close();
            }
        }
        
        private void frmUpgrade_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
        }
        
        private void frmUpgrade_Load(System.Object eventSender, System.EventArgs eventArgs)
        {
            if (GetCommandLine() == false)
            {
                MessageBox.Show("FAIL TO GET ARGUMENT. USAGE(MESPLUSUPGRADEMSG \"CONNECT STRING\" \"SITE ID\" \"FILE_LIST\")");
                this.Close();
                return;
            }
            
            //argv(1) Connect String
            if (argv[1] == "")
            {
                MessageBox.Show("PLEASE ENTER SYSTEM NAME. USAGE(MESPLUSUPGRADEMSG \"CONNECT STRING\" \"SITE ID\" \"FILE_LIST\")");
                this.Close();
                return;
            }
            
            //argv(2) SITE ID
            if (argv[2] == "")
            {
                MessageBox.Show("PLEASE ENTER CHANNEL. USAGE(MESPLUSUPGRADEMSG \"CONNECT STRING\" \"SITE ID\" \"FILE_LIST\")");
                this.Close();
                return;
            }
                        
            //argv(3) Download List File Name (ex)MESplus.xml
            if (argv[3] == "")
            {
                MessageBox.Show("PLEASE ENTER DOWNLOAD FILE LIST. USAGE(MESPLUSUPGRADEMSG \"CONNECT STRING\" \"SITE ID\" \"FILE_LIST\")");
                this.Close();
                return;
            }
            
            Cursor.Current = Cursors.WaitCursor;
            Application.DoEvents();

        }
        
        //
        // GetCommandLine()
        //       - Get CommandLine Arguments
        // Return Value
        //       - Boolean : True or False
        // Arguments
        private bool GetCommandLine()
        {
            try
            {
                argv = Environment.GetCommandLineArgs();

                if (argv.Length < 4)
                {
                    return false;
                }
            }
            catch (Exception)
            {
                Cursor.Current = Cursors.Default;
                MessageBox.Show("GET COMMAND LINE ERROR!");
                this.Close();
                return false;
            }
            
            return true;
        }
        
        private void ChangeProgress(int size)
        {
            if (size <= 8)
            {
                panProgress.Value = (int)(size / 8.0 * 100.0);
            }
            Application.DoEvents();            
        }


        [STAThread]
        static void Main()
        {
            try
            {
                Application.EnableVisualStyles();
                Application.Run(new frmUpgrade());

                MPIF.gInit.TermMsgHandler();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
