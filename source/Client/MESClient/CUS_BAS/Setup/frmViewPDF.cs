using FarPoint.Win.Spread;
using Miracom.CliFrx;
using Miracom.DNMCore;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Miracom.TRSCore;
using Miracom.MESCore;
using CUS_COM;
using AcroPDFLib;
using AxAcroPDFLib;


namespace CUS_BAS
{
    public partial class frmViewPDF : BaseForm01
    {
        public frmViewPDF()
        {
            InitializeComponent();

        }

        private void frmViewPDF_Load(object sender, EventArgs e)
        {


            try
            {


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }


        }

        private void frmViewPDF_Shown(object sender, EventArgs e)
        {
     
        }
    }   
}
