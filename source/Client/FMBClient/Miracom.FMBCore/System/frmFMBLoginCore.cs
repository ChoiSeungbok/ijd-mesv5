using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using Miracom.CliFrx;

namespace Miracom.FMBCore
{
    public partial class frmFMBLoginCore : Miracom.MESCore.frmLogInCore
    {
        public frmFMBLoginCore()
        {
            InitializeComponent();
        }

        // ShowOptionWindow()
        //       - FMBClient LogIn Show
        // Return Value
        //       -
        // Arguments
        //        - ByVal bRestart As Boolean : Restart Flag
        //
        protected override void ShowOptionWindow(bool bRestart)
        {
            try
            {
                frmFMBOptionCore f = new frmFMBOptionCore(bRestart);
                if (f.ShowDialog() == DialogResult.Cancel)
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("ShowOptionWindow()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
        }

    }
}