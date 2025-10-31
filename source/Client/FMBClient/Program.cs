using System;
using System.Collections.Generic;
using System.Windows.Forms;
using Miracom.FMBCore;

using Miracom.CliFrx;
using Miracom.MESCore;
using Miracom.MsgHandler;

namespace FMBClient
{
    static class Program
    {
        /// <summary>
        /// 해당 응용 프로그램의 주 진입점입니다.
        /// </summary>
        [STAThread]
        static void Main()
        {
            try
            {
                Application.EnableVisualStyles();
                Application.AddMessageFilter(new MESClientMessageFilter());

                MPGV.gsProgramID = Application.ProductName;
                MPIF.gInit = new clsInitialFunctionImp();
                MPGV.gIBaseFormEvent = new clsFormEventFunctionImp();

                MPGV.gfrmMDI = new frmMDIMain();
                FMBFI.gIMdiForm = (intFMBMdiFormFunction)MPGV.gfrmMDI;
                MPGV.gIMdiForm = FMBFI.gIMdiForm;

                Application.Run(MPGV.gfrmMDI);

                MPIF.gInit.TermMsgHandler();

            }
            catch (Exception ex)
            {
                MPIF.gInit.TermMsgHandler();
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}