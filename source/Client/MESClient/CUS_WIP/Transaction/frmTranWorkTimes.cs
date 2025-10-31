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
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using Miracom.CliFrx;
using Miracom.DNMCore;
using System.Threading;

namespace CUS_WIP
{
    public partial class frmTranWorkTimes : CUS_COM.frmTranForm01
    {
        #region ""
        public frmTranWorkTimes()
        {
            InitializeComponent();
            InitControl();
        }
        #endregion

        #region " Constant Definition "



        #endregion


        #region " Variable Definition "



        #endregion

        #region " Function Definition "


        private void InitControl()
        {
            try
            {

          
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private bool CheckCondition(CSGC.CHECK CHECK)
        {

            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        break;
                    case CSGC.CHECK.START:

                        break;
                    case CSGC.CHECK.END:

                        break;
                    case CSGC.CHECK.ADD:

                        break;
                    case CSGC.CHECK.DELETE:

                        break;

                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

        }

        #endregion

    }
}
