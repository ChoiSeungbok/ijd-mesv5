//-----------------------------------------------------------------------------
//
//   System      : MES
//   File Name   : frmRASSetupResourceMFORelation.cs
//   Description : Resource group & resource - MFO Relation setup
//
//   MES Version : 4.2.0.0
//
//   Function List
//       - ClearData() : Intialize Form Field
//       - CheckCondition : Check the Conditions before Transaction
//
//   Detail Description
//       -
//
//   History
//       - **** Do Not Modify in Site!!! ****
//       - 2007-08-28 : Created by Aiden
//
//
//   Copyright(C) 1998-2007 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using Miracom.MsgHandler;
using Miracom.MESCore;
using Miracom.CliFrx;
using Miracom.TRSCore;
namespace Miracom.RASCore
{
    public partial class frmRASSetupResourceMFORelation : Miracom.MESCore.SetupForm02
    {
        public frmRASSetupResourceMFORelation()
        {
            InitializeComponent();
        }

#region " Constant Definition "
#endregion

#region " Variable Definition "
#endregion

#region " Function Definition "

        // SelectClear()
        //       - Clear Selected Items
        // Return Value
        //       -
        // Arguments
        //       - ByVal list As ListView : ListView
        //
        private void SelectClear(ListView list)
        {
            int i;
            for (i = 0; i <= list.Items.Count - 1; i++)
            {
                list.Items[i].Selected = false;
            }
        }

        // CheckCondition()
        //       - Check the conditions before transaction
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal FuncName As String : Function Name
        //
        private bool CheckCondition(string FuncName)
        {

            if (tabRelation.SelectedTab == tbpMFO && tvMFO.SelectedItem != Miracom.MESCore.Controls.TreeSelectedItem.Oper)
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(109));
                tvMFO.Focus();
                return false;
            }

            switch (MPCF.Trim(FuncName))
            {
                case "ATTACH_GROUP":

                    if (lisGroupList.SelectedItems.Count <= 0)
                    {
                        if (lisGroupList.Items.Count > 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            lisGroupList.Items[0].Selected = true;
                            lisGroupList.Focus();
                        }
                        return false;
                    }
                    break;
                case "DETACH_GROUP":

                    if (lisMFORel1.SelectedItems.Count <= 0)
                    {
                        if (lisMFORel1.Items.Count > 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            lisMFORel1.Items[0].Selected = true;
                            lisMFORel1.Focus();
                        }
                        return false;
                    }
                    break;
                case "ATTACH_RES":

                    if (lisResourceList.SelectedItems.Count <= 0)
                    {
                        if (lisResourceList.Items.Count > 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            lisResourceList.Items[0].Selected = true;
                            lisResourceList.Focus();
                        }
                        return false;
                    }
                    break;
                case "DETACH_RES":

                    if (lisMFORel2.SelectedItems.Count <= 0)
                    {
                        if (lisMFORel2.Items.Count > 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            lisMFORel2.Items[0].Selected = true;
                            lisMFORel2.Focus();
                        }
                        return false;
                    }
                    break;
                case "ATTACH_MFO":
                    if (udcMFOTreeList.SelectedItem != Miracom.MESCore.Controls.TreeSelectedItem.Oper)
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(109));
                        udcMFOTreeList.Focus();
                        return false;
                    }
                    break;
                case "DETACH_MFO":

                    if (lisMfo.SelectedItems.Count < 1)
                    {
                        if (lisMfo.Items.Count > 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            lisMfo.Items[0].Selected = true;
                            lisMfo.Focus();
                        }
                        return false;
                    }
                    break;
            }

            return true;
        }

        // UpdateResourceGroupRelation()
        //       - Create/Update/Delete Resource - Group Relation
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       - char c_step           : Process Step
        //       - string s_group       : Resource group id
        //       - string s_res         : Resource ID
        //
        private bool UpdateResourceMFORelation(char c_step, char c_rel_level, string s_group, string s_res)
        {
            return UpdateResourceMFORelation(c_step, c_rel_level, s_group, s_res, tvMFO.MatID, tvMFO.MatVersion, tvMFO.Flow, tvMFO.Oper);
        }
        private bool UpdateResourceMFORelation(char c_step, char c_rel_level, string s_group, string s_res,
            string s_mat_id, int i_mat_ver, string s_flow, string s_oper)
        {
            TRSNode in_node = new TRSNode("Update_Resource_MFO_Relation_In");
            TRSNode out_node = new TRSNode("Cmn_Out");
            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = c_step;

                in_node.AddString("MAT_ID", s_mat_id);
                in_node.AddInt("MAT_VER", i_mat_ver);
                in_node.AddString("FLOW", s_flow);
                in_node.AddString("OPER", s_oper);

                in_node.AddChar("REL_LEVEL", c_rel_level);

                in_node.AddString("RESG_ID", s_group);
                in_node.AddString("RES_ID", s_res);

                if (MPCR.CallService("RAS", "RAS_Update_Resource_MFO_Relation", in_node, ref out_node) == false)
                {
                    return false;
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        

        //
        // ViewSettingDataList()
        //       - Get setting data list
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       - 
        //
        private bool ViewSettingDataList()
        {
            TRSNode in_node = new TRSNode("Sql_In");
            TRSNode out_node = new TRSNode("Sql_Out");
           
            string s_rel_level;
            StringBuilder sb;

            MPCF.InitListView(tvMFO.GetListView);

            s_rel_level = tabOption.SelectedTab == tbpResource ? "R" : "G";

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';            
            in_node.AddInt("NEXT_ROW", 0);

            sb = new StringBuilder();

            switch (tvMFO.SelectLevel)
            {
                case Miracom.MESCore.Controls.MFOSelectLevel.MFO:
                    sb.Append("SELECT MAT_ID, MAT_VER, FLOW, OPER FROM MRASRESMFO ");
                    sb.Append("WHERE FACTORY = '" + MPGV.gsFactory + "' AND REL_LEVEL = '" + s_rel_level + "' ");
                    sb.Append("AND MAT_ID <> ' ' AND MAT_VER > 0 AND FLOW <> ' ' AND OPER <> ' ' ");
                    sb.Append("GROUP BY MAT_ID, MAT_VER, FLOW, OPER ");
                    sb.Append("ORDER BY MAT_ID ASC, MAT_VER DESC, FLOW ASC, OPER ASC");
                    break;

                case Miracom.MESCore.Controls.MFOSelectLevel.MO:
                    sb.Append("SELECT MAT_ID, MAT_VER, OPER FROM MRASRESMFO ");
                    sb.Append("WHERE FACTORY = '" + MPGV.gsFactory + "' AND REL_LEVEL = '" + s_rel_level + "' ");
                    sb.Append("AND MAT_ID <> ' ' AND MAT_VER > 0 AND FLOW = ' ' AND OPER <> ' ' ");
                    sb.Append("GROUP BY MAT_ID, MAT_VER, OPER ");
                    sb.Append("ORDER BY MAT_ID ASC, MAT_VER DESC, OPER ASC");
                    break;

                case Miracom.MESCore.Controls.MFOSelectLevel.FO:
                    sb.Append("SELECT FLOW, OPER FROM MRASRESMFO ");
                    sb.Append("WHERE FACTORY = '" + MPGV.gsFactory + "' AND REL_LEVEL = '" + s_rel_level + "' ");
                    sb.Append("AND MAT_ID = ' ' AND MAT_VER = 0 AND FLOW <> ' ' AND OPER <> ' ' ");
                    sb.Append("GROUP BY FLOW, OPER ");
                    sb.Append("ORDER BY FLOW ASC, OPER ASC");
                    break;

                case Miracom.MESCore.Controls.MFOSelectLevel.O:
                    sb.Append("SELECT OPER FROM MRASRESMFO ");
                    sb.Append("WHERE FACTORY = '" + MPGV.gsFactory + "' AND REL_LEVEL = '" + s_rel_level + "' ");
                    sb.Append("AND MAT_ID = ' ' AND MAT_VER = 0 AND FLOW = ' ' AND OPER <> ' ' ");
                    sb.Append("GROUP BY OPER ");
                    sb.Append("ORDER BY OPER ASC");
                    break;

            }

            in_node.AddString("SQL", sb.ToString());
            
            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCR.FillDataView(tvMFO.GetListView, out_node, false, (int)SMALLICON_INDEX.IDX_MODULE, false);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (in_node.GetInt("NEXT_ROW") > 0 );

            lblDataCount.Text = tvMFO.GetListView.Items.Count.ToString();

            return true;
        }

        public virtual Control GetFisrtFocusItem()
        {

            try
            {
                return this.tvMFO;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return null;
            }

        }

#endregion

        private void frmRASSetupResourceMFORelation_Load(object sender, EventArgs e)
        {
            MPCF.InitListView(lisGroupList);
            MPCF.InitListView(lisResourceList);
            MPCF.InitListView(lisMFORel1);
            MPCF.InitListView(lisMFORel2);

            pnlGrpMid_Resize(null, null);
            pnlResMid_Resize(null, null);

            lisGroupList.Focus();

            if (RASLIST.ViewResourceGroupList(lisGroupList, '1') == false) return;
            if (RASLIST.ViewResourceList(lisResourceList, false) == false) return;

            btnCreate.Visible = false;
            btnUpdate.Visible = false;
            btnDelete.Visible = false;

            tabOption.TabPages.Remove(tbpResourceMfo);
        }

        private void btnRefresh_Click(System.Object sender, System.EventArgs e)
        {
            if (tabRelation.SelectedTab == tbpMFO)
                tvMFO.RefreshSelectedList();
            else
                udcResourceTreeList.RefreshSelectedList();
        }

        private void btnNext_Click(System.Object sender, System.EventArgs e)
        {
            if (tabRelation.SelectedTab == tbpMFO)
                tvMFO.GetNext(txtFind.Text);
            else
                udcResourceTreeList.GetNext(txtFind.Text);
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            if (tabRelation.SelectedTab == tbpMFO)
                MPCF.ExportToExcel(tvMFO.GetListView, this.Text, "");
            else 
                MPCF.ExportToExcel(udcResourceTreeList.GetTreeView, this.Text, "");
        }

        private void txtFind_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (tabRelation.SelectedTab == tbpMFO)
            {
                if (e.KeyChar == 13 && MPCF.Trim(txtFind.Text) != "")
                {
                    btnNext_Click(null, null);
                }
            }
        }

        private void pnlResMid_Resize(object sender, EventArgs e)
        {
            MPCF.FieldAdjust(pnlResMid, pnlResMidLeft, pnlResMidRight, pnlResMidMid, 40);
        }

        private void pnlGrpMid_Resize(object sender, EventArgs e)
        {
            MPCF.FieldAdjust(pnlGrpMid, pnlGrpMidLeft, pnlGrpMidRight, pnlGrpMidMid, 40);
        }

        private void pnlResourceMfo_Resize(object sender, EventArgs e)
        {
            MPCF.FieldAdjust(pnlMfoMid, pnlMfoMidLeft, pnlMfoMidRight, pnlMfoMidMid, 40);
        }

        // 선택 Level의 말단 노드가 선택되었을 때
        private void tvMFO_LevelItemSelect(System.Object sender, System.Windows.Forms.TreeViewEventArgs e)
        {
            if (RASLIST.ViewResourceGroupList(lisMFORel1, '3', tvMFO.MatID, tvMFO.MatVersion, tvMFO.Flow, tvMFO.Oper) == false) return;
            if (RASLIST.ViewResourceList(lisMFORel2, '1', "", tvMFO.MatID, tvMFO.MatVersion, tvMFO.Flow, tvMFO.Oper, 'R', false) == false) return;
        }

        private void tvMFO_AfterGetTree(object sender, EventArgs e)
        {
            lblDataCount.Text = MPCF.Trim(tvMFO.GetTreeView.GetNodeCount(false));
        }

        private void tvMFO_AfterSelect(object sender, TreeViewEventArgs e)
        {
            lblDataCount.Text = MPCF.Trim(tvMFO.SelectedNode.GetNodeCount(false));
        }

        private void btnAdd_Click(System.Object sender, System.EventArgs e)
        {
            string s_group;
            ListViewItem itmX;
            string[] s_select = null;
            int i;
            int j;
            int i_idx = 0;

            s_select = new string[lisGroupList.SelectedItems.Count];
            SelectClear(lisMFORel1);

            if (CheckCondition("ATTACH_GROUP") == false) return;

            for (i = 0; i <= lisGroupList.SelectedItems.Count - 1; i++)
            {
                s_group = lisGroupList.SelectedItems[i].Text;
                if (MPCF.FindListItem(lisMFORel1, s_group, false) == false)
                {
                    if (UpdateResourceMFORelation(MPGC.MP_STEP_CREATE, 'G', s_group, "") == true)
                    {
                        s_select[i] = s_group;
                        itmX = lisMFORel1.Items.Add(s_group, (int)SMALLICON_INDEX.IDX_RESOURCE_GROUP);
                        itmX.SubItems.Add(lisGroupList.SelectedItems[i].SubItems[1].Text);
                        i_idx = lisGroupList.SelectedItems[i].Index;
                    }
                    else
                    {
                        for (j = 0; j <= s_select.Length - 1; j++)
                        {
                            MPCF.FindListItem(lisMFORel1, s_select[j], false);
                        }
                        SelectClear(lisGroupList);
                        return;
                    }
                }
                else
                {
                    s_select[i] = s_group;
                    i_idx = lisGroupList.SelectedItems[i].Index;
                }
            }

            SelectClear(lisGroupList);

            if (s_select.Length == 1)
            {
                if (i_idx < lisGroupList.Items.Count - 1)
                {
                    lisGroupList.Items[i_idx + 1].Selected = true;
                }
            }

            for (i = 0; i <= s_select.Length - 1; i++)
            {
                MPCF.FindListItem(lisMFORel1, s_select[i], false);
            }
        }

        private void btnDel_Click(System.Object sender, System.EventArgs e)
        {
            string s_group;
            int i_idx = 0;
            int i;
            int i_count;

            if (CheckCondition("DETACH_GROUP") == false) return;

            i_count = lisMFORel1.SelectedItems.Count;
            SelectClear(lisGroupList);

            for (i = lisMFORel1.SelectedItems.Count - 1; i >= 0; i--)
            {
                s_group = lisMFORel1.SelectedItems[i].Text;
                if (UpdateResourceMFORelation(MPGC.MP_STEP_DELETE, 'G', s_group, "") == true)
                {
                    i_idx = lisMFORel1.SelectedItems[i].Index;
                    lisMFORel1.Items.RemoveAt(i_idx);
                    MPCF.FindListItem(lisGroupList, s_group, false);
                }
            }
            if (i_count == 1)
            {
                if (i_idx < lisMFORel1.Items.Count)
                {
                    lisMFORel1.Items[i_idx].Selected = true;
                }
            }
        }

        private void btnAttach_Click(System.Object sender, System.EventArgs e)
        {
            string s_res;
            string[] s_select = null;
            ListViewItem itmX;
            int i;
            int j;
            int i_idx = 0;

            s_select = new string[lisResourceList.SelectedItems.Count];
            SelectClear(lisMFORel2);

            if (CheckCondition("ATTACH_RES") == false) return;

            for (i = 0; i <= lisResourceList.SelectedItems.Count - 1; i++)
            {
                s_res = lisResourceList.SelectedItems[i].Text;
                if (MPCF.FindListItem(lisMFORel2, s_res, false) == false)
                {
                    if (UpdateResourceMFORelation(MPGC.MP_STEP_CREATE, 'R', "", s_res) == true)
                    {
                        s_select[i] = s_res;
                        itmX = lisMFORel2.Items.Add(s_res, (int)SMALLICON_INDEX.IDX_RESOURCE);
                        itmX.SubItems.Add(lisResourceList.SelectedItems[i].SubItems[1].Text);
                        i_idx = lisResourceList.SelectedItems[i].Index;
                    }
                    else
                    {
                        for (j = 0; j <= s_select.Length - 1; j++)
                        {
                            MPCF.FindListItem(lisMFORel2, s_select[j], false);
                        }
                        SelectClear(lisResourceList);
                        return;
                    }
                }
                else
                {
                    s_select[i] = s_res;
                    i_idx = lisResourceList.SelectedItems[i].Index;
                }
            }

            SelectClear(lisResourceList);
            if (s_select.Length == 1)
            {
                if (i_idx < lisResourceList.Items.Count - 1)
                {
                    lisResourceList.Items[i_idx + 1].Selected = true;
                }
            }
            for (i = 0; i <= s_select.Length - 1; i++)
            {
                MPCF.FindListItem(lisMFORel2, s_select[i], false);
            }
        }

        private void btnDetach_Click(System.Object sender, System.EventArgs e)
        {
            string s_res;
            int i;
            int i_idx = 0;
            int i_count;

            if (CheckCondition("DETACH_RES") == false) return;

            i_count = lisMFORel2.SelectedItems.Count;
            SelectClear(lisResourceList);

            for (i = lisMFORel2.SelectedItems.Count - 1; i >= 0; i--)
            {
                s_res = lisMFORel2.SelectedItems[i].Text;
                if (UpdateResourceMFORelation(MPGC.MP_STEP_DELETE, 'R', "", s_res) == true)
                {
                    i_idx = lisMFORel2.SelectedItems[i].Index;
                    lisMFORel2.Items.RemoveAt(i_idx);
                    MPCF.FindListItem(lisResourceList, s_res, false);
                }
            }
            if (i_count == 1)
            {
                if (i_idx < lisMFORel2.Items.Count)
                {
                    lisMFORel2.Items[i_idx].Selected = true;
                }
            }
        }


        private void lisMFORel1_DragEnter(System.Object sender, System.Windows.Forms.DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.Text))
            {
                e.Effect = DragDropEffects.Copy;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }

        }

        private void lisMFORel1_DragDrop(System.Object sender, System.Windows.Forms.DragEventArgs e)
        {
            btnAdd_Click(null, null);
        }

        private void lisMFORel1_ItemDrag(object sender, System.Windows.Forms.ItemDragEventArgs e)
        {
            lisMFORel1.DoDragDrop(lisMFORel1.SelectedItems[0].Text, DragDropEffects.Move);
        }

        private void lisMFORel1_MouseDown(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            lisMFORel1.AllowDrop = false;
            lisGroupList.AllowDrop = true;
        }

        private void lisMFORel2_DragEnter(System.Object sender, System.Windows.Forms.DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.Text))
            {
                e.Effect = DragDropEffects.Copy;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }
        }

        private void lisMFORel2_DragDrop(System.Object sender, System.Windows.Forms.DragEventArgs e)
        {
            btnAttach_Click(null, null);
        }

        private void lisMFORel2_ItemDrag(object sender, System.Windows.Forms.ItemDragEventArgs e)
        {
            lisMFORel2.DoDragDrop(lisMFORel2.SelectedItems[0].Text, DragDropEffects.Move);
        }

        private void lisMFORel2_MouseDown(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            lisMFORel2.AllowDrop = false;
            lisResourceList.AllowDrop = true;
        }

        private void lisGroupList_ItemDrag(System.Object sender, System.Windows.Forms.ItemDragEventArgs e)
        {
            lisGroupList.DoDragDrop(lisGroupList.SelectedItems[0].Text, DragDropEffects.Copy);
        }

        private void lisGroupList_DragEnter(object sender, System.Windows.Forms.DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.Text))
            {
                e.Effect = DragDropEffects.Move;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }
        }

        private void lisGroupList_DragDrop(object sender, System.Windows.Forms.DragEventArgs e)
        {
            btnDel_Click(null, null);
        }

        private void lisGroupList_MouseDown(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            lisGroupList.AllowDrop = false;
            lisMFORel1.AllowDrop = true;
        }

        private void lisResourceList_DragEnter(object sender, System.Windows.Forms.DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.Text))
            {
                e.Effect = DragDropEffects.Move;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }
        }

        private void lisResourceList_DragDrop(object sender, System.Windows.Forms.DragEventArgs e)
        {
            btnDetach_Click(null, null);
        }

        private void lisResourceList_MouseDown(object sender, System.Windows.Forms.MouseEventArgs e)
        {
            lisResourceList.AllowDrop = false;
            lisMFORel2.AllowDrop = true;
        }

        private void lisResourceList_ItemDrag(System.Object sender, System.Windows.Forms.ItemDragEventArgs e)
        {
            lisResourceList.DoDragDrop(lisResourceList.SelectedItems[0].Text, DragDropEffects.Copy);
        }

        private void lisGroupList_Click(object sender, System.EventArgs e)
        {
            SelectClear(lisMFORel1);
        }

        private void lisMFORel1_Click(object sender, System.EventArgs e)
        {
            SelectClear(lisGroupList);
        }

        private void lisMFORel2_Click(object sender, System.EventArgs e)
        {
            SelectClear(lisResourceList);
        }

        private void lisResourceList_Click(object sender, System.EventArgs e)
        {
            SelectClear(lisMFORel2);
        }

        private void tabOption_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tvMFO.OnlySetDataList == true)
            {
                ViewSettingDataList();
            }
        }

        private void tvMFO_GetOnlySetData(object sender, EventArgs e)
        {
            ViewSettingDataList();
        }

        private void tvMFO_SetDataSelectedIndexChanged(object sender, EventArgs e)
        {
            if (tabOption.SelectedTab == tbpResource)
            {
                if (RASLIST.ViewResourceList(lisMFORel2, '1', "", tvMFO.MatID, tvMFO.MatVersion, tvMFO.Flow, tvMFO.Oper, 'R', false) == false) return;
            }
            else if (tabOption.SelectedTab == tbpResourceGroup)
            {
                if (RASLIST.ViewResourceGroupList(lisMFORel1, '3', tvMFO.MatID, tvMFO.MatVersion, tvMFO.Flow, tvMFO.Oper) == false) return;
            }
        }


        #region " MFO - Resource Relation "
        private bool ViewMFOListByResource()
        {
            TRSNode in_node = new TRSNode("VIEW_MFO_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_MFO_LIST_OUT");

            try
            {
                MPCF.ClearList(lisMfo);
                MPCR.SetInMsg(in_node);

                if (udcResourceTreeList.SelectLevel == MESCore.Controls.ResourceSelectLevel.R)
                    in_node.ProcStep = 'R';
                else
                    in_node.ProcStep = 'G';
                in_node.AddString("RES_ID", udcResourceTreeList.Resource);
                in_node.AddString("RESG_ID", udcResourceTreeList.ResourceGroup);

                if (MPCR.CallService("RAS", "RAS_View_Resource_List", in_node, ref out_node) == false)
                {
                    return false;
                }

                for (int i = 0; i < out_node.GetList("MFO_LIST").Count; i++)
                {
                    TRSNode item = out_node.GetList("MFO_LIST")[i];
                    ListViewItem lvi = new ListViewItem(item.GetString("MAT_ID"), (int)SMALLICON_INDEX.IDX_MATERIAL);
                    lvi.SubItems.Add(item.GetInt("MAT_VER").ToString());
                    lvi.SubItems.Add(item.GetString("FLOW"));
                    lvi.SubItems.Add(item.GetString("OPER"));

                    lisMfo.Items.Add(lvi);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }

        private void tabRelation_SelectedIndexChanged(object sender, EventArgs e)
        {
            tabOption.TabPages.Clear();
            tabOption.SuspendLayout();
            if (tabRelation.SelectedTab == tbpMFO)
            {
                tabOption.TabPages.Add(tbpResourceGroup);
                tabOption.TabPages.Add(tbpResource);
            }
            else
            {
                tabOption.TabPages.Add(tbpResourceMfo);
            }
            tabOption.ResumeLayout();
        }

        private void udcResourceTreeList_AfterGetTree(object sender, EventArgs e)
        {
            lblDataCount.Text = MPCF.Trim(udcResourceTreeList.GetTreeView.GetNodeCount(false));
        }

        private void udcResourceTreeList_AfterSelect(object sender, TreeViewEventArgs e)
        {
            lblDataCount.Text = MPCF.Trim(udcResourceTreeList.GetTreeView.SelectedNode.GetNodeCount(false));
        }
        #endregion

        private void udcResourceTreeList_LevelItemSelect(object sender, TreeViewEventArgs e)
        {
            ViewMFOListByResource();
        }

        private void btnMfoAttach_Click(object sender, EventArgs e)
        {
            if (CheckCondition("ATTACH_MFO") == false) return;

            lisMfo.SelectedItems.Clear();

            char c_rel_level = udcResourceTreeList.SelectLevel == MESCore.Controls.ResourceSelectLevel.R ? 'R' : 'G';
            if (UpdateResourceMFORelation(MPGC.MP_STEP_CREATE, c_rel_level, udcResourceTreeList.ResourceGroup, udcResourceTreeList.Resource,
                udcMFOTreeList.MatID, udcMFOTreeList.MatVersion, udcMFOTreeList.Flow, udcMFOTreeList.Oper) == false)
            {
                return;
            }

            ViewMFOListByResource();

            for (int i = 0; i < lisMfo.Items.Count; i++)
            {
                if (lisMfo.Items[i].SubItems[0].Text.Equals(udcMFOTreeList.MatID) &&
                    lisMfo.Items[i].SubItems[1].Text.Equals(udcMFOTreeList.MatVersion.ToString()) &&
                    lisMfo.Items[i].SubItems[2].Text.Equals(udcMFOTreeList.Flow) &&
                    lisMfo.Items[i].SubItems[3].Text.Equals(udcMFOTreeList.Oper))
                {
                    lisMfo.Focus();
                    lisMfo.Items[i].Selected = true;
                    lisMfo.Items[i].EnsureVisible();
                    break;
                }
            }
        }

        private void btnMfoDetach_Click(object sender, EventArgs e)
        {
            if (CheckCondition("DETACH_MFO") == false) return;

            char c_rel_level = udcResourceTreeList.SelectLevel == MESCore.Controls.ResourceSelectLevel.R ? 'R' : 'G';

            lisMfo.SuspendLayout();
            for (int i = lisMfo.SelectedItems.Count - 1; i >= 0 ; i--)
            {
                ListViewItem lvi = lisMfo.SelectedItems[i];
                if (UpdateResourceMFORelation(MPGC.MP_STEP_DELETE, c_rel_level, udcResourceTreeList.ResourceGroup, udcResourceTreeList.Resource,
                   lvi.SubItems[0].Text, MPCF.ToInt(lvi.SubItems[1].Text), lvi.SubItems[2].Text, lvi.SubItems[3].Text) == false)
                {
                    continue;
                }

                lisMfo.Items.Remove(lvi);
            }
            lisMfo.ResumeLayout();
        }
    }
}

