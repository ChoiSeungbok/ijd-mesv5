using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using Miracom.CliFrx;

namespace ADMINClient
{
    public partial class frmLogin : Miracom.MESCore.frmLogInCore
    {
        public frmLogin()
        {
            InitializeComponent();
        }

        private void frmLogin_Load(object sender, System.EventArgs e)
        {
            MPGV.gsHelpURL = "http://localhost/ADMINHelp/";
            MPGV.gsDefaultHelpURL = "Manual_1";
            MPGV.gsServerName = "ADMServer";
            MPGV.gsDownloadFileList = "DownloadFile_ADM.xml";
            MPGV.gsUpgradeFile = "MESplusUpgradeFtp.exe";

            MPGV.gsClientVersion = "ADM_V5.3.7";
        }

    }
}