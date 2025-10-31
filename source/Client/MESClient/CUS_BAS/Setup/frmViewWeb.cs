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

namespace CUS_BAS
{
    public partial class frmViewWeb : BaseForm01
    {
        public frmViewWeb()
        {
            InitializeComponent();

        }

        private void frmViewWeb_Load(object sender, EventArgs e)
        {


            try
            {

                clsViewWeb WebOpen = new clsViewWeb();

                WebOpen.fun_name_sSearch();



            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }


        }

        private void frmViewWeb_Shown(object sender, EventArgs e)
        {
            this.Close();
        }
    }   
}
