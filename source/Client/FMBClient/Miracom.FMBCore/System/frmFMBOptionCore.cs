using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using Miracom.CliFrx;
using Miracom.MsgHandler;

namespace Miracom.FMBCore
{
    public partial class frmFMBOptionCore : Miracom.MESCore.frmOptionCore
    {
        public frmFMBOptionCore()
        {
            InitializeComponent();
        }

        public frmFMBOptionCore(bool bRestart)
        {
            InitializeComponent();
            b_restart_flag = bRestart;
        }

        #region " Constant Definition "

        #endregion

        #region " Variable Definition"
        private bool b_load_flag;

        #endregion

        private void frmOption_Activated(object sender, System.EventArgs e)
        {

            try
            {
                if (b_load_flag == false)
                {
                    if (MPGV.gsStyleName == "FLAT")
                    {
                        rbnFlat.Checked = true;
                    }
                    else if (MPGV.gsStyleName == "3D")
                    {
                        rbn3D.Checked = true;
                    }

                    if (modGlobalVariable.gbAllFactory == true)
                    {
                        rbnAllYes.Checked = true;
                    }
                    else
                    {
                        rbnAllNo.Checked = true;
                    }

                    FMBCF.GetTextboxStyle(this.Controls);

                    b_load_flag = true;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmOption_Activated()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        private void btnOK_Click(System.Object sender, System.EventArgs e)
        {
            try
            {
                if (rbnFlat.Checked == true)
                {
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "Style", "1");
                    MPGV.gsStyleName = "FLAT";
                }
                else
                {
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "Style", "2");
                    MPGV.gsStyleName = "3D";
                }

                if (rbnAutoRefreshYes.Checked == true)
                {
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "AutoRefresh", "1");
                    if (MPCF.ToInt(MPCF.ToInt(txtAutoRefreshTime.Text)) < 1)
                    {
                        txtAutoRefreshTime.Text = "1";
                    }
                    else if (MPCF.ToInt(MPCF.ToInt(txtAutoRefreshTime.Text)) > 600)
                    {
                        txtAutoRefreshTime.Text = "600";
                    }
                    else if (MPCF.CheckNumeric(txtAutoRefreshTime.Text) == false)
                    {
                        txtAutoRefreshTime.Text = "300";
                    }
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "AutoRefreshTime", txtAutoRefreshTime.Text);
                    MPGV.gbAutoRefresh = true;
                    MPGV.giAutoRefreshTime = MPCF.ToInt(txtAutoRefreshTime.Text);
                }
                else
                {
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "AutoRefresh", "2");
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "AutoRefreshTime", "0");
                    MPGV.gbAutoRefresh = false;
                    MPGV.giAutoRefreshTime = 0;
                }


                if (rbnAllYes.Checked == true)
                {
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "AllFactory", "1");
                    modGlobalVariable.gbAllFactory = true;
                }
                else
                {
                    MPCF.SaveRegSetting(Application.ProductName, "Option", "AllFactory", "2");
                    modGlobalVariable.gbAllFactory = false;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("btnOK_Click()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }    
    
    }
}