using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Miracom.UI;
using Miracom.CliFrx;
using CUS_COM.BaseForm;

using System.Diagnostics;

namespace CUS_COM.Controls
{
    public partial class udcFactoryChange : UserControl
    {
        public udcFactoryChange()
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

        private void udcFactoryChange_Load(object sender, EventArgs e)
        {

        }


        #region "Control Events"



        #endregion



        private void rdUvIJDK1_CheckedChanged(object sender, EventArgs e)
        {
            if (rdUvIJDK1.Checked)
            {
                if(MPGV.gsSiteID != IDK1_SITE_ID)
                {
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "BackGroundLogin", "Y");
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "SiteID", IDK1_SITE_ID);
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "RemoteAddress", IDK1_ADDRESS);
                    MPCF.SaveRegSetting(Application.ProductName, "Settings", "Factory", IDK1_FACTORY);
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "StationMode" + "0", MPGV.gsStationMode);
                    MPCF.SaveRegSetting(Application.ProductName, "Settings", "Password", MPGV.gsPassword);
                    MPGV.gsSiteID = IDK1_SITE_ID;
                    MPGV.gsRemoteAddress = IDK1_ADDRESS;

    
                    if (RunProcess(Application.ExecutablePath) == false)
                    {
                        return;
                    }

                    MPCF.SaveRegSetting(Application.ProductName, "Option", "BackGroundLogin", "Y");
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "SiteID", IDV1_SITE_ID);
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "RemoteAddress", IDV1_ADDRESS);
                    MPCF.SaveRegSetting(Application.ProductName, "Settings", "Factory", IDV1_FACTORY);
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "StationMode" + "0", MPGV.gsStationMode);
                    MPCF.SaveRegSetting(Application.ProductName, "Settings", "Password", MPGV.gsPassword);
                    MPGV.gsSiteID = IDV1_SITE_ID;
                    MPGV.gsRemoteAddress = IDV1_ADDRESS;
                }
            }

        }

        private void rdUvIJDV1_CheckedChanged(object sender, EventArgs e)
        {
            if (rdUvIJDV1.Checked)
            {
                if (MPGV.gsSiteID != IDV1_SITE_ID)
                {
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "BackGroundLogin", "Y");
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "SiteID", IDV1_SITE_ID);
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "RemoteAddress", IDV1_ADDRESS);
                    MPCF.SaveRegSetting(Application.ProductName, "Settings", "Factory", IDV1_FACTORY);
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "StationMode" + "0", MPGV.gsStationMode);
                    MPCF.SaveRegSetting(Application.ProductName, "Settings", "Password", MPGV.gsPassword);
                    MPGV.gsSiteID = IDV1_SITE_ID;
                    MPGV.gsRemoteAddress = IDV1_ADDRESS;
                    

                    if(RunProcess(Application.ExecutablePath) == false)
                    {
                        return;
                    }
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "BackGroundLogin", "Y");
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "SiteID", IDK1_SITE_ID);
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "RemoteAddress", IDK1_ADDRESS);
                    MPCF.SaveRegSetting(Application.ProductName, "Settings", "Factory", IDK1_FACTORY);
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "StationMode" + "0", MPGV.gsStationMode);
                    MPCF.SaveRegSetting(Application.ProductName, "Settings", "Password", MPGV.gsPassword);
                    MPGV.gsSiteID = IDK1_SITE_ID;
                    MPGV.gsRemoteAddress = IDK1_ADDRESS;


                }
            }
        }

        private bool RunProcess(String FileName)
        {
            Process p = new Process();

            p.StartInfo.FileName = FileName;

           // p.StartInfo.WindowStyle = ProcessWindowStyle.Normal;

            p.Start();
            p.WaitForExit(20000);

            if (p.HasExited == false)
            {
                if (p.Responding)
                {
                    p.CloseMainWindow();
                    return false;
                }
                else
                {
                    p.Kill();
                    return false;
                }
            }
               
            return true;
        }
    }
}
