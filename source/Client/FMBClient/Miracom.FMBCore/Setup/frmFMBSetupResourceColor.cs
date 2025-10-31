using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.MESCore;
using Miracom.TRSCore;
namespace Miracom.FMBCore
{
    public partial class frmFMBSetupResourceColor : Form
    {
        public frmFMBSetupResourceColor()
        {
            InitializeComponent();
        }
        private string s_back_opt = "";
        private bool CheckCondition(char c_step)
        {
            if (MPCF.CheckValue(cdvFactory, 1) == false)
            {
                return false;
            }
            if (MPCF.CheckValue(cdvType, 1) == false)
            {
                return false;
            }

            if (MPCF.CheckValue(cdvStatus, 1) == false)
            {
                return false;
            }

            if (c_step != modGlobalConstant.MP_STEP_DELETE)
            { 
            }
            return true;
        }
        private bool Update_Event_Color(char c_step)
        {

            try
            {
                TRSNode in_node = new TRSNode("Update_Event_Color_In");
                TRSNode out_node = new TRSNode("Cmn_Out");
                
                MPCR.SetInMsg(in_node);
                in_node.Factory = cdvFactory.Text;
                in_node.ProcStep = c_step;
                
                in_node.AddString("RES_TYPE", cdvType.Text);
                in_node.AddString("EVENT_ID", cdvStatus.Text);
                if (utcBack.Color.IsKnownColor == true)
                {
                    in_node.AddInt("COLOR", (int)utcBack.Color.ToKnownColor());
                }
                else
                {
                    in_node.AddInt("COLOR", utcBack.Color.ToArgb());
                }

                if (MPCR.CallService("FMB", "FMB_Update_Event_Color", in_node, ref out_node) == false)
                {
                    return false;
                }
                MPCR.ShowSuccessMsg(out_node);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupGlobalOption.Update_Event_Color()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        private bool View_Environment()
        {

            try
            {
                TRSNode in_node = new TRSNode("View_Environment_In");
                TRSNode out_node = new TRSNode("View_Environment_Out");

                MPCR.SetInMsg(in_node);
                in_node.Factory = cdvFactory.Text;
                in_node.ProcStep = '1';

                if (MPCR.CallService("FMB", "FMB_View_Environment", in_node, ref out_node) == false)
                {
                    return false;
                }
                s_back_opt = out_node.GetString("BACK_OPT") ;
                if (s_back_opt  == "Event" && cdvType.Text != "PORT")
                {
                    cdvStatus.VisibleButton = true;
                    cdvStatus.ReadOnly = true;
                }
                else
                {
                    cdvStatus.VisibleButton = false;
                    cdvStatus.ReadOnly = false;
                }

                modListRoutine.ViewResourceColorList(lisResource, '1', cdvFactory.Text, cdvType.Text, s_back_opt);
                if (lisResource.Items.Count > 0)
                {
                    lisResource.Items[0].Selected = true;
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupGlobalOption.Update_Environment()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        private bool View_Resource_Color()
        {

            try
            {
                TRSNode in_node = new TRSNode("View_Resource_Color_In");
                TRSNode out_node = new TRSNode("View_Resource_Color_Out");

                MPCR.SetInMsg(in_node);
                in_node.Factory = cdvFactory.Text;
                in_node.ProcStep = '1';
                in_node.AddString("RES_TYPE", cdvType.Text);
                in_node.AddString("EVENT_ID", cdvStatus.Text);

                if (MPCR.CallService("FMB", "FMB_View_Event_Color", in_node, ref out_node, true) == false)
                {
                    return false;
                }

                if (out_node.GetInt("COLOR") < 0)
                {
                   utcBack.Color = System.Drawing.Color.FromArgb(out_node.GetInt("COLOR"));
                }
                else if (out_node.GetInt("COLOR") > 0)
                {
                    utcBack.Color = System.Drawing.Color.FromKnownColor((KnownColor)out_node.GetInt("COLOR"));
                }
                else
                {
                    utcBack.Color = SystemColors.Control;
                }
                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupGlobalOption.Update_Environment()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }
        private void frmFMBSetupResourceColor_Load(object sender, EventArgs e)
        {
            MPCR.CheckSecurityFormControl(this);
            FMBCF.GetTextboxStyle(this.Controls);
            MPCF.ToClientLanguage(this);
            FMBCF.CheckAllFactoryOption(cdvFactory);
            MPCF.InitListView(lisResource);
        }

        private void cdvType_ButtonPress(object sender, EventArgs e)
        {
            cdvType.Init();
            MPCF.InitListView(cdvType.GetListView);
            cdvType.Columns.Add("Sub RES Type", 150, HorizontalAlignment.Left);
            cdvType.Columns.Add("Desc", 200, HorizontalAlignment.Left);
            cdvType.SelectedSubItemIndex = 0;
            BASLIST.ViewGCMDataList(cdvType.GetListView, '2', "FMB_SUBRES_TYPE");
        }

        private void cdvType_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            cdvStatus.Text = "";
            utcBack.Color = SystemColors.Control;
            if (MPCF.Trim(cdvType.Text) != "")
            {
                View_Environment();                
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            if (MPCF.ShowMsgBox(MPCF.GetMessage(5), Application.ProductName, MessageBoxButtons.YesNo, 1) == DialogResult.No)
            {
                return;
            }
            if (CheckCondition(modGlobalConstant.MP_STEP_DELETE) == true)
            {
                if(Update_Event_Color(modGlobalConstant.MP_STEP_DELETE) == true)
                {
                    modListRoutine.ViewResourceColorList(lisResource, '1', cdvFactory.Text, cdvType.Text, s_back_opt);
                }
            }
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            if (CheckCondition(modGlobalConstant.MP_STEP_UPDATE) == true)
            {
                if (Update_Event_Color(modGlobalConstant.MP_STEP_UPDATE) == true)
                {
                    modListRoutine.ViewResourceColorList(lisResource, '1', cdvFactory.Text, cdvType.Text, s_back_opt);
                }
            }
        }

        private void btnCreate_Click(object sender, EventArgs e)
        {
            if (CheckCondition(modGlobalConstant.MP_STEP_CREATE) == true)
            {
                if (Update_Event_Color(modGlobalConstant.MP_STEP_CREATE) == true)
                {
                    modListRoutine.ViewResourceColorList(lisResource, '1', cdvFactory.Text, cdvType.Text, s_back_opt);
                }
            }
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void lisResource_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (lisResource.SelectedItems.Count > 0)
            {
                cdvStatus.Text = lisResource.SelectedItems[0].Text;
                utcBack.Color = lisResource.SelectedItems[0].BackColor;
            }
        }

        private void cdvFactory_ButtonPress(System.Object sender, System.EventArgs e)
        {

            try
            {
                cdvFactory.Init();
                cdvFactory.Columns.Add("Factory", 100, HorizontalAlignment.Left);
                cdvFactory.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvFactory.SelectedSubItemIndex = 0;
                cdvFactory.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
                WIPLIST.ViewFactoryList(cdvFactory.GetListView, '1', null);
                cdvFactory.AddEmptyRow(1);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBSetupGlobalOption.cdvFactory_ButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        private void cdvFactory_TextBoxTextChanged(object sender, EventArgs e)
        {
            cdvType.Text = "";
            MPCF.InitListView(lisResource);
            cdvStatus.Text = "";
            utcBack.Color = SystemColors.Control;
        }

        private void cdvType_TextBoxTextChanged(object sender, EventArgs e)
        {
            MPCF.InitListView(lisResource);
            cdvStatus.Text = "";
            utcBack.Color = SystemColors.Control;
        }

        private void cdvStatus_ButtonPress(object sender, EventArgs e)
        {
            cdvStatus.Init();
            cdvStatus.Columns.Add("Factory", 100, HorizontalAlignment.Left);
            cdvStatus.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvStatus.SelectedSubItemIndex = 0;
            cdvStatus.SmallImageList = FMBFI.gIMdiForm.GetSmallIconList();
            
            if (cdvType.Text == "RES" || cdvType.Text == "SUBRES")
            {
                RASLIST.ViewEventList(cdvStatus.GetListView, '1', "", null, "");
            }
            else if (cdvType.Text == "TOOL" )
            {
                RASLIST.ViewToolEventList(cdvStatus.GetListView, '2', "", ' ', null);
            }
            
        }

        private void cdvStatus_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            utcBack.Color = SystemColors.Control;
            if (MPCF.Trim(cdvType.Text) != "" && MPCF.Trim(cdvStatus.Text) != "")
            {
                View_Resource_Color();
            }
        }
    }
}