using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Miracom.CliFrx;
using Miracom.MESCore;

namespace CUS_COM
{
    public partial class frmTranForm03 : CUS_COM.frmTranForm01
    {
        public frmTranForm03()
        {
            InitializeComponent();
            chkFavorite.Anchor = AnchorStyles.Top | AnchorStyles.Left;
        }
        
        private void Base_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvOrder.Text = "";
                cdvResource.Text = "";

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        
        private void cdvOrder_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }

                //cdvOrder.Init();
                //MPCF.InitListView(cdvOrder.GetListView);
                //cdvOrder.Columns.Add("Order", 50, HorizontalAlignment.Left);
                //cdvOrder.Columns.Add("Start_date", 50, HorizontalAlignment.Left);
                //cdvOrder.Columns.Add("End_date", 50, HorizontalAlignment.Left);
                //cdvOrder.SelectedSubItemIndex = 0;
                ////cdvOrder.DisplaySubItemIndex = 1;

                //if (COM_LIST.ViewOrderList(cdvOrder.GetListView, '1', cdvDept.Text, cdvWorkPlace.Text, cdvOper.Text) == false)
                //{
                //    return;
                //}

                //cdvOrder.InsertEmptyRow(0, 1);

                CUS_COM.Popup.frmPopWorkOrderList popup = new CUS_COM.Popup.frmPopWorkOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_AreaCode = cdvDept.Text;
                popup.g_AreaDesc = cdvDept.DisplayText;
                popup.g_SubAreaCode = cdvWorkPlace.Text;
                popup.g_SubAreaDesc = cdvWorkPlace.DisplayText;
                popup.g_OperCode = cdvOper.Text;
                popup.g_OperDesc = cdvOper.DisplayText;
                popup.g_WorkOrder = cdvOrder.Text;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvOrder.Text = popup.g_WorkOrder;
                    popup = null;
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvResource_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }

                cdvResource.Init();
                MPCF.InitListView(cdvResource.GetListView);
                cdvResource.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvResource.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvResource.SelectedSubItemIndex = 0;
                cdvResource.DisplaySubItemIndex = 1;

                //if (RASLIST.ViewResourceList(cdvResource.GetListView, '1', "", "", cdvDept.Text, cdvWorkPlace.Text, "", -1, "", cdvOper.Text, 'R', "", false, null, "") == false)
                //{
                //    return;
                //}

                if (COM_LIST.ViewResourceList(cdvResource.GetListView, '1', cdvOper.Text) == false)
                    return;

                cdvResource.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}
