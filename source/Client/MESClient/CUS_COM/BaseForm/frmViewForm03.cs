using Miracom.CliFrx;
using Miracom.MESCore;
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
using Miracom.DNMCore;

namespace CUS_COM
{
    public partial class frmViewForm03 : frmViewForm01
    {
        public frmViewForm03()
        {
            InitializeComponent();

        }

        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Init();
                MPCF.InitListView(cdvDept.GetListView);
                cdvDept.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvDept.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDept.SelectedSubItemIndex = 0;
                cdvDept.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDept.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                {
                    return;
                }

                //특정 사업부인 경우 Tag에 저장된 사업부를 제외하고 보이지 않기 위해
                if (MPCF.Trim(cdvDept.Tag) != "")
                {
                    for (int i = cdvDept.GetListView.Items.Count; i > 0; i--)
                    {
                        if (cdvDept.GetListView.Items[i - 1].SubItems[0].Text != cdvDept.Tag.ToString())
                        {
                            cdvDept.GetListView.Items[i - 1].Remove();
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

      

        private void frmViewForm03_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (!SaveRegistry.ContainsKey(cdvDept.Name))
                this.SaveRegistry.Add(cdvDept.Name, cdvDept.Text + ';' + cdvDept.DisplayText);            
        }




    }
}
