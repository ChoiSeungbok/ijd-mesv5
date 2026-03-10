using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Security.Cryptography;
using System.Text;
using System.Web;
using System.Windows.Forms;
using CUS_COM;
using System.Net;

using Miracom.CliFrx;

namespace MESClient
{
    public partial class frmLogin : Miracom.MESCore.frmLogInCore
    {
        public frmLogin()
        {
            InitializeComponent();
        }
        #region " Constant Definition "


        private const string IDK1_FACTORY = "IJDK1";
        private const string IDK1_SITE_ID = "IDK1";
        private const string IDK1_ADDRESS = "197.200.11.43";
        private const string IDV1_FACTORY = "IJDV1";
        private const string IDV1_SITE_ID = "IDV1";
        private const string IDV1_ADDRESS = "10.201.81.31";

        #endregion

        
        private void frmLogin_Load(object sender, System.EventArgs e)
        {

            MPGV.gsHelpURL = "http://localhost/MESHelp/";
            MPGV.gsDefaultHelpURL = "Manual_1";
            MPGV.gsDownloadFileList = "DownloadFile.xml";
            MPGV.gsUpgradeFile = "MESplusUpgradeFtp.exe";
            MPGV.gsClientVersion = "MES_V5.3.260310_01";

            SetFactory();
            txtUserID.Text = MPGV.gsUserID;

            if (chkSavePwd.Checked == true)
            {
                Pssword_Dncrypt();
            }
        }


        #region "Factory Change"
        private void SetFactory()
        {
            if (MPGV.gsFactory == IDV1_FACTORY)
            {
                rdoIJDV1.Checked = true;
            }
            else if (MPGV.gsFactory == IDK1_FACTORY)
            {
                rdoIJDK1.Checked = true;
            }
            if(MPCF.GetRegSetting(Application.ProductName, "Settings", "SavePassword", "N")  == "N")
            {
                chkSavePwd.Checked = false;
            }
            else
            {
                chkSavePwd.Checked = true;
            }
            //2비활겅화 1 활성화 
            if (MPCF.GetRegSetting(Application.ProductName, "Option", "ReloadScreens", "2") == "2")
            {
                ChkReloadFun.Checked = false;
            }
            else
            {
                ChkReloadFun.Checked = true;
            }

        }

        //헌국/베트남 선택기능 추가.syw
        private void rdoIJDK1_CheckedChanged(object sender, EventArgs e)
        {
            
            MPCF.SaveRegSetting(Application.ProductName, "Option", "SiteID", IDK1_SITE_ID);
            MPCF.SaveRegSetting(Application.ProductName, "Option", "RemoteAddress", IDK1_ADDRESS);
            MPCF.SaveRegSetting(Application.ProductName, "Settings", "Factory", IDK1_FACTORY);
            MPCF.SaveRegSetting(Application.ProductName, "Option", "StationMode" + "0", MPGV.gsStationMode);
            MPCF.SaveRegSetting(Application.ProductName, "Option", "StationMode" + "0", MPGV.gsStationMode);
            txtSiteID.Text = IDK1_SITE_ID;
            txtFactory.Text = IDK1_FACTORY;
            MPGV.gsSiteID = IDK1_SITE_ID;
            MPGV.gsRemoteAddress = IDK1_ADDRESS;
            
        }

        private void rdoIJDV1_CheckedChanged(object sender, EventArgs e)
        {

            
            MPCF.SaveRegSetting(Application.ProductName, "Option", "SiteID", IDV1_SITE_ID);
            MPCF.SaveRegSetting(Application.ProductName, "Option", "RemoteAddress", IDV1_ADDRESS);
            MPCF.SaveRegSetting(Application.ProductName, "Settings", "Factory", IDV1_FACTORY);
            MPCF.SaveRegSetting(Application.ProductName, "Option", "StationMode" + "0", MPGV.gsStationMode);
            txtSiteID.Text = IDV1_SITE_ID;
            txtFactory.Text = IDV1_FACTORY;
            MPGV.gsSiteID = IDV1_SITE_ID;
            MPGV.gsRemoteAddress = IDV1_ADDRESS;
            
        }
        #endregion

        #region " Password 암호화 저장 & 복호화 "

        //패스워드 저장기능 추가_ITGC 비번변경일90일권고떔시..패스워드 분실 문의 너무 많이옴.syw
        private void Pssword_Encrypt()
        {


            //암호화
            if(txtUserID.Text.Trim() == "")
            {
                txtPassword.Text = "";
                return;
            }

            string sEncrypt;
            CUS_COM.ClsCusCodeWord passwordIn = new CUS_COM.ClsCusCodeWord();

            sEncrypt = passwordIn.Des_Encrypt(txtPassword.Text);


            if (txtSiteID.Text.Trim() == "")
            {
                txtSiteID.Text = MPCF.GetRegSetting(Application.ProductName, "Settings", "SiteID", "");
            }
            if (txtFactory.Text.Trim() == "")
            {
                txtFactory.Text = MPCF.GetRegSetting(Application.ProductName, "Settings", "Factory", "");
            }

            MPCF.SaveRegSetting(Application.ProductName, "Settings", txtFactory.Text.Trim() + "_" + txtUserID.Text.Trim(), sEncrypt);

        }
        private void Pssword_Dncrypt()
        {


            //복호화

            string sPassword ="";
            CUS_COM.ClsCusCodeWord passwordOut = new CUS_COM.ClsCusCodeWord();



            if (txtSiteID.Text.Trim() == "")
            {
                txtSiteID.Text = MPCF.GetRegSetting(Application.ProductName, "Settings", "SiteID", "");
            }
            if (txtFactory.Text.Trim() == "")
            {
                txtFactory.Text = MPCF.GetRegSetting(Application.ProductName, "Settings", "Factory", "");
            }


            sPassword = MPCF.GetRegSetting(Application.ProductName, "Settings", txtFactory.Text.Trim() + "_" + txtUserID.Text.Trim(), "");

            if(sPassword != "")
            {
                txtPassword.Text = passwordOut.Des_Dncrypt(sPassword);
            }

        }

        private void txtUserID_TextChanged(object sender, EventArgs e)
        {
            if(chkSavePwd.Checked == true)
            {
                Pssword_Dncrypt();
            }
        }

        private void chkSavePwd_CheckedChanged(object sender, EventArgs e)
        {
            if (chkSavePwd.Checked == true)
            {
                MPCF.SaveRegSetting(Application.ProductName, "Settings", "SavePassword", "Y");
                
            }
            else
            {
                MPCF.SaveRegSetting(Application.ProductName, "Settings", "SavePassword", "N");
            }
        }

        private void ChkReloadFun_CheckedChanged(object sender, EventArgs e)
        {
            if(ChkReloadFun.Checked == true)
            {
                MPCF.SaveRegSetting(Application.ProductName, "Option", "ReloadScreens", "1");
            }
            else
            {
                MPCF.SaveRegSetting(Application.ProductName, "Option", "ReloadScreens", "2");
            }
        }

        #endregion

        private void btnOption_Click(object sender, EventArgs e)
        {

        }
    }
}