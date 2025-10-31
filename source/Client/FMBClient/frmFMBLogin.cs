using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using Miracom.CliFrx;

namespace FMBClient
{
    public partial class frmFMBLogin : Miracom.FMBCore.frmFMBLoginCore
    {
        public frmFMBLogin()
        {
            InitializeComponent();
        }

        private void frmFMBLogin_Load(object sender, System.EventArgs e)
        {
            MPGV.gsDownloadFileList = "DownloadFile_FMB.xml";
            MPGV.gsUpgradeFile = "MESplusUpgradeFtp.exe";
            MPGV.gsServerName = "MESServer";

            MPGV.gsClientVersion = "FMB_V5.3.7";
        }
    }
}