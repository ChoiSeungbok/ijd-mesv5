using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace RPTServer
{
    sealed class clsRPTMain
    {
        static void Main()
        {
            if (RSCF.GetCommandLine() == false)
            {
                MessageBox.Show("GetCommandLine() Failed.");
                Application.Exit();
                return;
            }

            LOG.AddLog("GetCommandLine Success");

            if (RSCF.GetServerEnv() == false)
            {
                MessageBox.Show("GetServerEnv() Failed.");
                Application.Exit();
                return;
            }

            DBCF.Init();
            if (DBCF.Connect() == false)
            {
                MessageBox.Show("DB Connect Failed.");
                Application.Exit();
                return;
            }

            if (DBGV.gbDBConnected == false)
            {
                MessageBox.Show("DB Connect Failed.");
                Application.Exit();
                return;
            }

            LOG.AddLog("DB Connect Success");

            RSGV.gsTitle = RSGV.gsServerName;

            Application.Run(new frmH101Svr());
        }
    }
}
