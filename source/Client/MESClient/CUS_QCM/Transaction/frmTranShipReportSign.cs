using Microsoft.VisualBasic;
using Miracom.CliFrx;
using Miracom.MESCore;
using System;
using System.Windows.Forms;

namespace CUS_QCM
{
    public partial class frmTranShipReportSign : CUS_COM.frmViewForm01
    {
        public frmTranShipReportSign()
        {
            InitializeComponent();

            InitControl();
        }

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
            try
            {


                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblprecautions.Anchor = AnchorStyles.Top | AnchorStyles.Left;

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
                    gFileServer_Dir = "MESplusV5/upgrade/PDA"; //.싸인 이미지는 여기 고정  //ItmFound.SubItems[3].Text;
                    gFileServer_ID = ItmFound.SubItems[4].Text;
                    gFileServer_PW = ItmFound.SubItems[5].Text;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
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
                FilePath = cdvFile.Text;

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

        #endregion

        #region " Event Definition "

        private void cdvFile_ButtonPress(object sender, EventArgs e)
        {
            ofdFile.Reset();
            ofdFile.Filter = "JPEG File(*.jpg)|*.jpg";
            ofdFile.DefaultExt = "jpg";
            ofdFile.FileName = cdvFile.Text;

            if (ofdFile.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {

                cdvFile.Text = ofdFile.FileName;
                picSign.ImageLocation = ofdFile.FileName;

            }
        }


        private void btnSave_Click(object sender, EventArgs e)
        {
            Save_File();
        }
        #endregion
    }
}
