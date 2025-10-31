using System;
using System.Data;
using System.Collections;
using System.Diagnostics;
using System.Windows.Forms;
using System.IO;
using System.Text;

using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.MESCore;
using Miracom.TRSCore;
using System.Drawing;

using System.Xml;
using System.Collections.Specialized;

namespace CUS_BAS
{
    public partial class frmBASSetupCaption : Miracom.MESCore.SetupForm02
    {
        public frmBASSetupCaption()
        {
            InitializeComponent();
        }

        public frmBASSetupCaption(string arg)
        {
            InitializeComponent();
            s_msg_group = arg;
        }

        #region "VariableDefinition"

        private bool b_load_flag;
        private bool b_export_stop = false;
        private string s_msg_group = "";

        public string sTestString = "";

        #endregion

        #region " Function Definition "
        // View_Message()
        //       - View message
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVla sMsgId                : 가?�올 메시지 ID
        private bool View_Message(char c_ProcStep, string sMsgId)
        {
            TRSNode in_node = new TRSNode("View_Caption_In");
            TRSNode out_node = new TRSNode("View_Caption_Out");

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = c_ProcStep;
            in_node.AddString("CAPTION_TYPE", cboMsgGrp.Text);
            in_node.AddString("CAPTION_KEY", MPCF.Trim(sMsgId));

            if (MPCR.CallService("CUS_BAS", "CUS_BAS_View_Caption", in_node, ref out_node) == false)
            {
                return false;
            }

            cboMsgGrp.Text = out_node.GetString("CAPTION_TYPE");
            txtMsgId.Text = out_node.GetString("CAPTION_KEY");
            txtMsg1.Text = out_node.GetString("CAPTION_MSG_1");
            txtMsg2.Text = out_node.GetString("CAPTION_MSG_2");
            txtMsg3.Text = out_node.GetString("CAPTION_MSG_3");
            txtCreateUser.Text = out_node.GetString("CREATE_USER_ID");
            txtCreateTime.Text = MPCF.MakeDateFormat(out_node.GetString("CREATE_TIME"));
            txtUpdateUser.Text = out_node.GetString("UPDATE_USER_ID");
            txtUpdateTime.Text = MPCF.MakeDateFormat(out_node.GetString("UPDATE_TIME"));

            return true;
        }




        //
        // Update_Message()
        //       - Change message information
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVla c_step                : Create/Update/Delete 구분??
        //
        private bool Update_Message(char c_step)
        {
            ListViewItem itm;

            int idx;
            string sType = "";

            TRSNode in_node = new TRSNode("UPDATE_MESSAGE_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");

            try
            {
                if (cboMsgGrp.Text == "Message")
                {
                    sType = cboMsgGrp.Text;
                }
                else
                {
                    sType = "Captions";
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = c_step;
                in_node.AddString("CAPTION_TYPE", cboMsgGrp.Text);
                in_node.AddString("CAPTION_KEY", MPCF.Trim(txtMsgId.Text));
                in_node.AddString("CAPTION_MSG_1", MPCF.Trim(txtMsg1.Text));
                in_node.AddString("CAPTION_MSG_2", MPCF.Trim(txtMsg2.Text));
                in_node.AddString("CAPTION_MSG_3", MPCF.Trim(txtMsg3.Text));
                in_node.AddString("CAPTION_CMF_10", sType);

                if (MPCR.CallService("CUS_BAS", "CUS_BAS_Update_Caption", in_node, ref out_node) == false)
                {
                    return false;
                } 

                MPCR.ShowSuccessMsg(out_node);

                if (MPGV.gbListAutoRefresh == false)
                {
                    if (c_step == MPGC.MP_STEP_CREATE)
                    {
                        itm = lisMsgList.Items.Add(MPCF.Trim(txtMsgId.Text), (int)SMALLICON_INDEX.IDX_MESSAGE);
                        if (MPGV.gcLanguage == '1')
                        {
                            itm.SubItems.Add(MPCF.Trim(txtMsg1.Text));
                        }
                        else if (MPGV.gcLanguage == '2')
                        {
                            itm.SubItems.Add(MPCF.Trim(txtMsg2.Text));
                        }
                        else if (MPGV.gcLanguage == '3')
                        {
                            itm.SubItems.Add(MPCF.Trim(txtMsg3.Text));
                        }
                        itm.Selected = true;
                        lisMsgList.Sorting = SortOrder.Ascending;
                        lisMsgList.Sort();
                        itm.EnsureVisible();
                    }
                    else if (c_step == MPGC.MP_STEP_UPDATE)
                    {
                        if (MPCF.FindListItem(lisMsgList, MPCF.Trim(txtMsgId.Text), false) == true)
                        {
                            if (MPGV.gcLanguage == '1')
                            {
                                lisMsgList.SelectedItems[0].SubItems[1].Text = MPCF.Trim(txtMsg1.Text);
                            }
                            else if (MPGV.gcLanguage == '2')
                            {
                                lisMsgList.SelectedItems[0].SubItems[1].Text = MPCF.Trim(txtMsg2.Text);
                            }
                            else if (MPGV.gcLanguage == '3')
                            {
                                lisMsgList.SelectedItems[0].SubItems[1].Text = MPCF.Trim(txtMsg3.Text);
                            }
                        }
                    }
                    else if (c_step == MPGC.MP_STEP_DELETE)
                    {
                        idx = MPCF.FindListItemIndex(lisMsgList, MPCF.Trim(txtMsgId.Text), false);
                        if (idx != -1)
                        {
                            lisMsgList.Items[idx].Remove();
                        }
                    }
                    lblDataCount.Text = MPCF.Trim(lisMsgList.Items.Count);
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

            return true;
        }

        //
        // Update_Caption_List()
        //       - Xml Data Insert
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       - ByVal ProcStep As String ("I" - Insert)
        //
        private bool Update_Caption_List(char ProcStep)
        {
            XmlDocument xmlDoc = new XmlDocument();

            TRSNode in_node = new TRSNode("Update_Caption_List_in");
            TRSNode out_node = new TRSNode("Update_Caption_List_Out");
            TRSNode list_item;

            try
            {
                SetImportEnables(false);
                
                txtImport.Text = "";
                txtImport.AppendText("Start Import\r\n");

                xmlDoc.Load(txtImportFile.Text);
                string sType = xmlDoc.FirstChild.NextSibling.Name;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = ProcStep;
                in_node.AddString("CAPTION_CMF_10", sType);

                if (sType == "Message")
                {
                    XmlNodeList xmlTextList = xmlDoc.FirstChild.NextSibling.ChildNodes;
                    //string type = sType.ToUpper();

                    foreach (XmlNode xmlText in xmlTextList)
                    {
                        if (xmlText.Attributes != null)
                        {
                            string Key = MPCF.Trim(xmlText.Attributes["Key"].Value);
                            string Lnag_1 = MPCF.Trim(xmlText.ChildNodes[0].InnerText);
                            string Lnag_2 = MPCF.Trim(xmlText.ChildNodes[1].InnerText);
                            string Lnag_3 = MPCF.Trim(xmlText.ChildNodes[2].InnerText);

                            list_item = in_node.AddNode("LIST");
                            list_item.AddString("CAPTION_TYPE", sType);
                            list_item.AddString("CAPTION_KEY", Key);
                            list_item.AddString("CAPTION_MSG_1", Lnag_1);
                            list_item.AddString("CAPTION_MSG_2", Lnag_2);
                            list_item.AddString("CAPTION_MSG_3", Lnag_3);
                        }
                    }
                }
                else if (sType == "Captions")
                {
                    XmlNodeList xmlCategoryList = xmlDoc.FirstChild.NextSibling.ChildNodes;

                    foreach (XmlNode xmlCategory in xmlCategoryList)
                    {
                        string type = xmlCategory.Name;
                        XmlNodeList xmlTextList = xmlCategory.SelectNodes("Text");

                        foreach (XmlNode xmlText in xmlTextList)
                        {
                            if (xmlText.Attributes != null)
                            {
                                string Key = MPCF.Trim(xmlText.Attributes["Key"].Value);
                                string Lnag_1 = MPCF.Trim(xmlText.ChildNodes[0].InnerText);
                                string Lnag_2 = MPCF.Trim(xmlText.ChildNodes[1].InnerText);
                                string Lnag_3 = MPCF.Trim(xmlText.ChildNodes[2].InnerText);

                                list_item = in_node.AddNode("LIST");
                                list_item.AddString("CAPTION_TYPE", type);
                                list_item.AddString("CAPTION_KEY", Key);
                                list_item.AddString("CAPTION_MSG_1", Lnag_1);
                                list_item.AddString("CAPTION_MSG_2", Lnag_2);
                                list_item.AddString("CAPTION_MSG_3", Lnag_3);
                            }
                        }
                    }
                }

                if (MPCR.CallService("CUS_BAS", "CUS_BAS_Update_Caption_List", in_node, ref out_node) == false)
                {
                    txtImport.AppendText(out_node.Msg + "\r\n");
                    txtImport.AppendText(out_node.DBErrMsg + "\r\n");
                    SetImportEnables(true);
                    return false;
                }

                txtImport.AppendText("Import Complete...\r\n");

                SetImportEnables(true);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                SetImportEnables(true);
                return false;
            }

            return true;
        }

        // CheckCondition()
        //       - check Create/Update/Delete condition
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal FuncName As String      : Function Name
        //       - Optional ByVal ProcStep As String        : Create/Update/Delete 구분??
        //
        private bool CheckCondition(string FuncName, char ProcStep)
        {

            switch (MPCF.Trim(FuncName))
            {
                case "Update_Message":

                    switch (MPCF.ToChar(MPCF.Trim(ProcStep)))
                    {
                        case MPGC.MP_STEP_CREATE:
                            if (MPCF.CheckValue(cboMsgGrp, 1) == false)
                            {
                                return false;
                            }
                            if (MPCF.CheckValue(txtMsgId, 1) == false)
                            {
                                return false;
                            }
                            if (MPCF.CheckValue(txtMsg1, 1) == false)
                            {
                                return false;
                            }
                            break;

                        case MPGC.MP_STEP_UPDATE:

                            if (MPCF.CheckValue(cboMsgGrp, 1) == false)
                            {
                                return false;
                            }
                            if (MPCF.CheckValue(txtMsgId, 1) == false)
                            {
                                return false;
                            }
                            if (MPCF.CheckValue(txtMsg1, 1) == false)
                            {
                                return false;
                            }
                            break;
                        case MPGC.MP_STEP_DELETE:

                            if (MPCF.CheckValue(txtMsgId, 1) == false)
                            {
                                return false;
                            }
                            break;
                    }
                    break;
            }

            return true;

        }

        public virtual Control GetFisrtFocusItem()
        {

            try
            {
                return this.cboMsgGrp;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return null;
            }

        }


        public static bool ViewCaptionList(char cProcStep, Control control, string sCaptionType)
        {
            return ViewCaptionList(cProcStep, control, sCaptionType, "");
        }

        public static bool ViewCaptionList(Control control, string sCaptionType)
        {
            return ViewCaptionList('1', control, sCaptionType, "");
        }

        public static bool ViewCaptionList(char cProcStep, Control control, string sCaptionType, string sSearchKey)
        {
            try
            {
                int i;
                ListViewItem itmX;
                ArrayList a_list;

                TRSNode in_node = new TRSNode("In_node");
                TRSNode out_node;

                a_list = new ArrayList();

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = cProcStep;
                in_node.AddString("CAPTION_TYPE", sCaptionType);
                in_node.AddString("SEARCH_KEY", MPCF.Trim(sSearchKey));

                in_node.AddString("NEXT_CAPTION_KEY", " ");

                do
                {
                    out_node = new TRSNode("VIEW_CAPTION_OUT");

                    if (MPCR.CallService("CUS_BAS", "CUS_BAS_View_Caption_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    a_list.Add(out_node);

                    in_node.SetString("NEXT_CAPTION_KEY", out_node.GetString("NEXT_CAPTION_KEY"));
                } while (in_node.GetString("NEXT_CAPTION_KEY") != "");

                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (control is ListView)
                        {
                            itmX = new ListViewItem(out_node.GetList(0)[i].GetString("CAPTION_KEY"), (int)SMALLICON_INDEX.IDX_MESSAGE);


                            if (((ListView)control).Columns.Count > 1)
                            {
                                if (MPGV.gcLanguage == '1')
                                    itmX.SubItems.Add(out_node.GetList(0)[i].GetString("CAPTION_MSG_1"));
                                else if (MPGV.gcLanguage == '2')
                                    itmX.SubItems.Add(out_node.GetList(0)[i].GetString("CAPTION_MSG_2"));
                                else if (MPGV.gcLanguage == '3')
                                    itmX.SubItems.Add(out_node.GetList(0)[i].GetString("CAPTION_MSG_3"));

                            }
                            ((ListView)control).Items.Add(itmX);
                        }
                        else if (control is ComboBox)
                        {
                            ((ComboBox)control).Items.Add(out_node.GetList(0)[i].GetString("CAPTION_KEY"));
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }

        #endregion

        private void frmCOMSetupCaption_Activated(object sender, System.EventArgs e)
        {
            if (b_load_flag == false)
            {

                MPCF.InitListView(lisMsgList);

                if (BASLIST.ViewGCMDataList(cboMsgGrp, '1', "@CAPTION_TYPE_LIST") == true)
                {
                    if (cboMsgGrp.Items.Count > 0)
                    {
                        int j = 0;
                        int i = 0;
                        if (s_msg_group != "")
                        {
                            for (i = 0; i < cboMsgGrp.Items.Count; i++)
                            {
                                if (cboMsgGrp.Items[i].ToString() == s_msg_group)
                                {
                                    j = i;
                                    break;
                                }
                            }
                        }

                        cboMsgGrp.SelectedIndex = j;
                    }
                }

                b_load_flag = true;
            }
        }

        private void btnNext_Click(System.Object sender, System.EventArgs e)
        {
            MPCF.FindListItemNextPartial(lisMsgList, txtFind.Text, true, false);
        }

        private void txtFind_TextChanged(System.Object sender, System.EventArgs e)
        {
            MPCF.FindListItemPartial(lisMsgList, txtFind.Text, 0, true, false);
        }

        private void lisMsgList_SelectedIndexChanged(System.Object sender, System.EventArgs e)
        {
            if (lisMsgList.SelectedItems.Count > 0)
            {
                View_Message('1', MPCF.Trim(lisMsgList.SelectedItems[0].Text));
            }
        }

        private void btnRefresh_Click(System.Object sender, System.EventArgs e)
        {

            try
            {
                lblDataCount.Text = "";
                if (ViewCaptionList(lisMsgList, cboMsgGrp.Text) == true)
                {
                    lblDataCount.Text = MPCF.Trim(lisMsgList.Items.Count);
                    if (lisMsgList.Items.Count > 0)
                    {
                        MPCF.FindListItem(lisMsgList, txtMsgId.Text, false);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        private void btnCreate_Click(System.Object sender, System.EventArgs e)
        {

            try
            {
                if (CheckCondition("Update_Message", MPGC.MP_STEP_CREATE) == true)
                {
                    if (Update_Message(MPGC.MP_STEP_CREATE) == false)
                    {
                        return;
                    }
                    if (MPGV.gbListAutoRefresh == true)
                    {
                        btnRefresh.PerformClick();
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        private void btnUpdate_Click(System.Object sender, System.EventArgs e)
        {

            try
            {
                if (CheckCondition("Update_Message", MPGC.MP_STEP_UPDATE) == true)
                {
                    if (Update_Message(MPGC.MP_STEP_UPDATE) == false)
                    {
                        return;
                    }
                    if (MPGV.gbListAutoRefresh == true)
                    {
                        btnRefresh.PerformClick();
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        private void btnDelete_Click(System.Object sender, System.EventArgs e)
        {

            try
            {
                if (MPCF.ShowMsgBox(MPCF.GetMessage(54), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                {
                    return;
                }
                if (CheckCondition("Update_Message", MPGC.MP_STEP_DELETE) == true)
                {
                    if (Update_Message(MPGC.MP_STEP_DELETE) == false)
                    {
                        return;
                    }
                    MPCF.FieldClear(this.pnlRight);
                    if (MPGV.gbListAutoRefresh == true)
                    {
                        btnRefresh.PerformClick();
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        private void txtMsgId_KeyPress(System.Object sender, System.Windows.Forms.KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)58)
            {
                e.Handled = true;
            }
        }

        private void cboMsgGrp_KeyPress(object sender, System.Windows.Forms.KeyPressEventArgs e)
        {
            e.Handled = true;
        }

        private void cboMsgGrp_TextChanged(object sender, System.EventArgs e)
        {

            if (cboMsgGrp.Text == "")
            {
                return;
            }
            lblDataCount.Text = "";
            if (ViewCaptionList(lisMsgList, cboMsgGrp.Text) == true)
            {
                lblDataCount.Text = MPCF.Trim(lisMsgList.Items.Count);
                if (lisMsgList.Items.Count > 0)
                {
                    if (MPCF.FindListItem(lisMsgList, txtMsgId.Text, false) == true)
                    {
                        lisMsgList_SelectedIndexChanged(lisMsgList, e);
                    }
                    else
                    {
                        lisMsgList.Items[0].Selected = true;
                    }

                    lisMsgList.Focus();
                }
            }

        }

        private void btnExcel_Click(System.Object sender, System.EventArgs e)
        {
            string sCond;

            sCond = "Message Group : " + cboMsgGrp.Text;
            MPCF.ExportToExcel(lisMsgList, this.Text, sCond);
        }

        private void btnImportFile_Click(object sender, EventArgs e)
        {
            openFileDialog.Filter = "XML | *.xml";
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txtImportFile.Text = openFileDialog.FileName;
            }
        }

        private void btnExportFile_Click(object sender, EventArgs e)
        {
            saveFileDialog.Filter = "XML | *.xml";
            saveFileDialog.InitialDirectory = Application.StartupPath;
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                txtExportFile.Text = saveFileDialog.FileName;

                txtExport.Text = "";
            }
        }

        private void btnInsertExportStop_Click_1(object sender, EventArgs e)
        {
            b_export_stop = true;
        }

        private void btnExport_Click(object sender, EventArgs e)
        {
            XmlDocument NewXmlDoc = new XmlDocument();

            TRSNode in_node;
            TRSNode out_node;

            string sType = "";
            string sPreCationType = "";

            try
            {
                b_export_stop = false;

                if (txtExportFile.Text == "")
                {
                    if (rboCaption.Checked)
                        txtExportFile.Text = $"{Application.StartupPath}\\MESCaption.xml";
                    else if (rboMessage.Checked)
                        txtExportFile.Text = $"{Application.StartupPath}\\MESMessage.xml";
                }

                // Export�߿�Disable
                SetExportEnables(false);

                txtExport.Text = "";
                txtExport.AppendText("Start Export\r\n");

                // Init progressBar
                progressBarExport.Value = 0;
                txtExport.Focus();

                if (rboMessage.Checked == true)
                {
                    sType = "Message";
                    
                }
                else if (rboCaption.Checked == true)
                {
                    sType = "Captions";
                }

                XmlDocument doc = new XmlDocument();
                XmlDeclaration dec = doc.CreateXmlDeclaration("1.0", "utf-8", "");
                XmlElement ele = doc.CreateElement(sType);
                XmlElement gubun = null;

                doc.AppendChild(dec);
                doc.AppendChild(ele);

                in_node = new TRSNode("View_Caption_List_in");
                out_node = new TRSNode("View_Caption_List_On");
                MPCR.SetInMsg(in_node);
                in_node.AddString("CAPTION_CMF_10", sType);
                in_node.AddString("NEXT_CAPTION_KEY", "");

                if (rboCaption.Checked == true)
                {
                    in_node.ProcStep = '2';
                }
                else if (rboMessage.Checked == true)
                {
                    in_node.ProcStep = '3';
                }

                do
                {
                    if (b_export_stop)
                    {
                        SetExportEnables(true);
                        txtExport.Focus();
                        txtExport.AppendText("<User Stop>..." + "\r\n");
                        return;
                    }

                    if (MPCR.CallService("CUS_BAS", "CUS_BAS_View_Caption_List", in_node, ref out_node) == false)
                    {
                        txtExport.AppendText(out_node.Msg + "\r\n");
                        txtExport.AppendText(out_node.DBErrMsg + "\r\n");
                        SetExportEnables(true);
                        return;
                    }

                    if (rboCaption.Checked == true)
                    {
                        gubun = doc.CreateElement(out_node.GetList(0)[0].GetString("CAPTION_TYPE"));
                        ele.AppendChild(gubun);
                        sPreCationType = out_node.GetList(0)[0].GetString("CAPTION_TYPE");
                    }

                    for (int i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        XmlElement txt = doc.CreateElement("Text");
                        XmlElement Lang_1 = doc.CreateElement("L");
                        XmlElement Lang_2 = doc.CreateElement("L");
                        XmlElement Lang_3 = doc.CreateElement("L");

                        if (rboCaption.Checked == true)
                        {
                            if (sPreCationType != out_node.GetList(0)[i].GetString("CAPTION_TYPE"))
                            {
                                gubun = doc.CreateElement(out_node.GetList(0)[i].GetString("CAPTION_TYPE"));
                                ele.AppendChild(gubun);
                                sPreCationType = out_node.GetList(0)[i].GetString("CAPTION_TYPE");
                            }

                            gubun.AppendChild(txt);
                        }
                        else
                        {
                            ele.AppendChild(txt);
                        }
                        
                        txt.AppendChild(Lang_1);
                        txt.AppendChild(Lang_2);
                        txt.AppendChild(Lang_3);

                        txt.SetAttribute("Key", out_node.GetList(0)[i].GetString("CAPTION_KEY"));

                        if (out_node.GetList(0)[i].GetString("CAPTION_MSG_1") != "")
                        {
                            Lang_1.InnerText = out_node.GetList(0)[i].GetString("CAPTION_MSG_1");
                        }
                        else
                        {
                            Lang_1.InnerText = " ";
                        }

                        if (out_node.GetList(0)[i].GetString("CAPTION_MSG_2") != "")
                        {
                            Lang_2.InnerText = out_node.GetList(0)[i].GetString("CAPTION_MSG_2");
                        }
                        else
                        {
                            Lang_2.InnerText = " ";
                        }

                        if (out_node.GetList(0)[i].GetString("CAPTION_MSG_3") != "")
                        {
                            Lang_3.InnerText = out_node.GetList(0)[i].GetString("CAPTION_MSG_3");
                        }
                        else
                        {
                            Lang_3.InnerText = " ";
                        }
                    }

                    in_node.SetString("NEXT_CAPTION_KEY", out_node.GetString("NEXT_CAPTION_KEY"));
                } while (in_node.GetString("NEXT_CAPTION_KEY") != "");

                doc.Save(txtExportFile.Text);

                txtExport.AppendText("Export Complete...\r\n");

                SetExportEnables(true);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                SetExportEnables(true);
            }
        }

        private void btnUpload_Click(object sender, EventArgs e)
        {
            XmlDocument NewXmlDoc = new XmlDocument();

            TRSNode in_node;
            TRSNode out_node;

            string sType = "";
            string sPreCationType = "";
            string s_base_path = "";
            string sPath = "";

            try
            {
                b_export_stop = false;
                
                // Export�߿�Disable
                SetUploadEnables(false);

                s_base_path = Application.StartupPath + "\\";

                txtExport.Text = "";
                txtExport.AppendText("Start Upload\r\n");

                // Init progressBar
                progressBarExport.Value = 0;
                txtExport.Focus();

                if (rboMessage.Checked == true)
                {
                    sType = "Message";
                    txtExportFile.Text = "MESMessage.xml";

                }
                else if (rboCaption.Checked == true)
                {
                    sType = "Captions";
                    txtExportFile.Text = "MESCaption.xml";
                }

                XmlDocument doc = new XmlDocument();
                XmlDeclaration dec = doc.CreateXmlDeclaration("1.0", "utf-8", "");
                XmlElement ele = doc.CreateElement(sType);
                XmlElement gubun = null;

                doc.AppendChild(dec);
                doc.AppendChild(ele);

                in_node = new TRSNode("View_Caption_List_in");
                out_node = new TRSNode("View_Caption_List_On");
                MPCR.SetInMsg(in_node);
                in_node.AddString("CAPTION_CMF_10", sType);
                in_node.AddString("NEXT_CAPTION_KEY", "");

                if (rboCaption.Checked == true)
                {
                    in_node.ProcStep = '2';
                }
                else if (rboMessage.Checked == true)
                {
                    in_node.ProcStep = '3';
                }

                do
                {
                    if (b_export_stop)
                    {
                        SetUploadEnables(true);
                        txtExport.Focus();
                        txtExport.AppendText("<User Stop>..." + "\r\n");
                        return;
                    }

                    if (MPCR.CallService("CUS_BAS", "CUS_BAS_View_Caption_List", in_node, ref out_node) == false)
                    {
                        txtExport.AppendText(out_node.Msg + "\r\n");
                        txtExport.AppendText(out_node.DBErrMsg + "\r\n");
                        SetUploadEnables(true);
                        return;
                    }

                    if (rboCaption.Checked == true)
                    {
                        gubun = doc.CreateElement(out_node.GetList(0)[0].GetString("CAPTION_TYPE"));
                        ele.AppendChild(gubun);
                        sPreCationType = out_node.GetList(0)[0].GetString("CAPTION_TYPE");
                    }

                    for (int i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        XmlElement txt = doc.CreateElement("Text");
                        XmlElement Lang_1 = doc.CreateElement("L");
                        XmlElement Lang_2 = doc.CreateElement("L");
                        XmlElement Lang_3 = doc.CreateElement("L");

                        if (rboCaption.Checked == true)
                        {
                            if (sPreCationType != out_node.GetList(0)[i].GetString("CAPTION_TYPE"))
                            {
                                gubun = doc.CreateElement(out_node.GetList(0)[i].GetString("CAPTION_TYPE"));
                                ele.AppendChild(gubun);
                                sPreCationType = out_node.GetList(0)[i].GetString("CAPTION_TYPE");
                            }

                            gubun.AppendChild(txt);
                        }
                        else
                        {
                            ele.AppendChild(txt);
                        }

                        txt.AppendChild(Lang_1);
                        txt.AppendChild(Lang_2);
                        txt.AppendChild(Lang_3);

                        txt.SetAttribute("Key", out_node.GetList(0)[i].GetString("CAPTION_KEY"));

                        if (out_node.GetList(0)[i].GetString("CAPTION_MSG_1") != "")
                        {
                            Lang_1.InnerText = out_node.GetList(0)[i].GetString("CAPTION_MSG_1");
                        }
                        else
                        {
                            Lang_1.InnerText = " ";
                        }

                        if (out_node.GetList(0)[i].GetString("CAPTION_MSG_2") != "")
                        {
                            Lang_2.InnerText = out_node.GetList(0)[i].GetString("CAPTION_MSG_2");
                        }
                        else
                        {
                            Lang_2.InnerText = " ";
                        }

                        if (out_node.GetList(0)[i].GetString("CAPTION_MSG_3") != "")
                        {
                            Lang_3.InnerText = out_node.GetList(0)[i].GetString("CAPTION_MSG_3");
                        }
                        else
                        {
                            Lang_3.InnerText = " ";
                        }
                    }

                    in_node.SetString("NEXT_CAPTION_KEY", out_node.GetString("NEXT_CAPTION_KEY"));
                } while (in_node.GetString("NEXT_CAPTION_KEY") != "");

                sPath = s_base_path + txtExportFile.Text;
                doc.Save(sPath);

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = 'F';
                in_node.AddString("FILE_NAME", txtExportFile.Text);
                // Add xml file
                {
                    FileInfo finfo;
                    BinaryReader br;
                    byte[] file_buffer;

                    finfo = new FileInfo(sPath);
                    if (finfo.Exists == true)
                    {
                        br = new BinaryReader(finfo.OpenRead());
                        file_buffer = br.ReadBytes((int)finfo.Length);
                        in_node.AddBlob(MPGC.MP_BIN_DATA_1, file_buffer);
                        br.Close();
                    }
                }

                if (MPCR.CallService("CUS_BAS", "CUS_BAS_Update_Caption", in_node, ref out_node) == false)
                {
                    return;
                }                                 

                txtExport.AppendText("Upload Complete...\r\n");

                SetUploadEnables(true);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                SetUploadEnables(true);
            }
        }

        private void SetExportEnables(bool value)
        {
            MPCR.ChangeControlEnabled(this, btnExport, value);
            MPCR.ChangeControlEnabled(this, btnExportFile, value);
            MPCR.ChangeControlEnabled(this, btnCreate, value);
            MPCR.ChangeControlEnabled(this, btnUpdate, value);
            MPCR.ChangeControlEnabled(this, btnDelete, value);            
        }

        private void SetImportEnables(bool value)
        {
            MPCR.ChangeControlEnabled(this, btnImport, value);
            MPCR.ChangeControlEnabled(this, btnImportFile, value);
            MPCR.ChangeControlEnabled(this, btnCreate, value);
            MPCR.ChangeControlEnabled(this, btnUpdate, value);
            MPCR.ChangeControlEnabled(this, btnDelete, value);            
        }

        private void SetUploadEnables(bool value)
        {
            MPCR.ChangeControlEnabled(this, btnUpload, value);
            MPCR.ChangeControlEnabled(this, btnExportFile, value);
            MPCR.ChangeControlEnabled(this, btnCreate, value);
            MPCR.ChangeControlEnabled(this, btnUpdate, value);
            MPCR.ChangeControlEnabled(this, btnDelete, value);
        }

        private void btnImport_Click(object sender, EventArgs e)
        {
            if (txtImportFile.Text != "")
            {
                Update_Caption_List('I');
            }
        }

        private void txtSearchKey_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                if (ViewCaptionList('4', lisMsgList, cboMsgGrp.Text, txtSearchKey.Text) == true)
                {
                }
            }
        }

        private void btnLocalUpload_Click(object sender, EventArgs e)
        {
            MPCF.LoadMessageResource(MPGC.MP_MESSAGE_FILE);
            MPCF.LoadCaptionResource(MPGC.MP_CAPTION_FILE);
            MPGV.gIMdiForm.MenuRefresh();

            for(int i = 0; i < MPGV.gfrmMDI.MdiChildren.Length; i++)
            {
                MPCF.ToClientLanguage(MPGV.gfrmMDI.MdiChildren[i]);
            }
        }
    }
}


