using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

namespace CUS_WIP
{
    public partial class frmSetupWorkerRegistration : CUS_COM.frmTranForm01
    {
        #region " Constant Definition "
        #endregion

        #region " Variable Definition "
        #endregion

        #region " Function Defintion "
        #endregion

        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {

        }

        private void cdvWorkPlace_ButtonPress(object sender, EventArgs e)
        {

        }

        private void cdvWO_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvWO.Init();
                MPCF.InitListView(cdvWO.GetListView);
                cdvWO.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvWO.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWO.SelectedSubItemIndex = 0;

                //호출

                cdvWO.AddEmptyRow(1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void cdvOper_ButtonPress(object sender, EventArgs e)
        {

        }

        private void cdvRes_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvRes.Init();
                MPCF.InitListView(cdvRes.GetListView);
                cdvRes.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvRes.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvRes.SelectedSubItemIndex = 0;

                //호출

                cdvRes.AddEmptyRow(1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnRight_Click(object sender, EventArgs e)
        {

        }

        private void btnLeft_Click(object sender, EventArgs e)
        {

        }

        private void btnProcess_Click(object sender, EventArgs e)
        {

        }

    }
}
