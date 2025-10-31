using System;
using System.Windows.Forms;
using System.Data;
using Miracom.CliFrx;
using Miracom.MESCore;
using CUS_COM;
using Miracom.DNMCore;
using System.Collections;
using Miracom.TRSCore;

namespace CUS_WIP
{
    public partial class frmWIPSetupClassifyMasterData : CUS_COM.frmViewForm01
    {
        public frmWIPSetupClassifyMasterData()
        {
            InitializeComponent();
            InitControl();
        }

        #region " Constant Definition "

        private enum CLASS_INFO
        {
            CHK,
            MAT_GROUP,
            MAT_GROUP_SELECT,
            CLASS_TYPE,
            CLASS_TYPE_DESC,
            CLASS_TYPE_SELECT,
            CLASS_VALUE,
            CLASS_VALUE_DESC,
            CLASS_VALUE_SELECT,            
            INPUT_MAT_ID,
            INPUT_MAT_SELECT,
            INPUT_MAT_DESC,            
            OUTPUT_MAT_ID,
            OUTPUT_MAT_SELECT,
            OUTPUT_MAT_DESC
        }

        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnUpdate.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public bool ViewClassValue(Control control, string sMatGrp , string sClassType)
        {
            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_GROUP";
                dvcArgu[1].sCondition_Value = sMatGrp;

                if (sClassType.Contains(CSGC.CP_CLASS_CUP) == true)
                    sClassType = CSGC.CP_CLASS_CUP;

                dvcArgu[2].sCondition_ID = "CLASS_TYPE";
                dvcArgu[2].sCondition_Value = sClassType;

                if (TPDR.GetDataOne("", ref dt, "CWIP1004-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return false;

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["KEY_1"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["DATA_3"].ToString());
                        }
                        ((ListView)control).Items.Add(itmX);
                    }
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void ViewClassInfo()
        {
            int i = 0;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_GROUP";
                dvcArgu[1].sCondition_Value = cdvMatGrp.Text;

                dvcArgu[2].sCondition_ID = "CLASS_TYPE";                
                dvcArgu[2].sCondition_Value = cdvClassType.Text + "%";

                dvcArgu[3].sCondition_ID = "CLASS_VALUE";                
                dvcArgu[3].sCondition_Value = cdvClass.Text + "%";

                dvcArgu[4].sCondition_ID = "INPUT_MAT_ID";
                dvcArgu[4].sCondition_Value = cdvInputMatID.Text + "%";                

                if (TPDR.GetDataOne("", ref dt, "CWIP1004-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdMasterData);
                    return;
                }

                MPCF.ClearList(spdMasterData);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMasterData_Sheet1.RowCount++;

                    spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.CHK].Value = false;
                    spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.MAT_GROUP].Value = dt.Rows[i]["MAT_GROUP"];
                    spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.CLASS_TYPE].Value = dt.Rows[i]["CLASS_TYPE"];
                    spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.CLASS_TYPE_DESC].Value = dt.Rows[i]["CLASS_TYPE_DESC"];
                    spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.CLASS_VALUE].Value = dt.Rows[i]["CLASS_VALUE"];
                    spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.CLASS_VALUE_DESC].Value = dt.Rows[i]["CLASS_VALUE_DESC"];
                    spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.INPUT_MAT_ID].Value = dt.Rows[i]["INPUT_MAT_ID"];
                    spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.INPUT_MAT_DESC].Value = dt.Rows[i]["INPUT_MAT_DESC"];                    
                    spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.OUTPUT_MAT_ID].Value = dt.Rows[i]["OUTPUT_MAT_ID"];
                    spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.OUTPUT_MAT_DESC].Value = dt.Rows[i]["OUTPUT_MAT_DESC"];                    
                }

                MPCF.FitColumnHeader(spdMasterData);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool SaveClass(char sStep)
        {
            try
            {
                TRSNode in_node = new TRSNode("Delete_Classify_Master_Data_In");
                TRSNode out_node = new TRSNode("Delete_Classify_Master_Data_Out");
                TRSNode lot_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;

                for (int i = 0; i < spdMasterData_Sheet1.Rows.Count; i++)
                {
                    if (spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        lot_list = in_node.AddNode("CLASS_LIST");
                        lot_list.AddString("MAT_GROUP", MPCF.Trim(spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.MAT_GROUP].Text));
                        lot_list.AddString("CLASS_TYPE", MPCF.Trim(spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.CLASS_TYPE].Text));
                        lot_list.AddString("CLASS_VALUE", MPCF.Trim(spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.CLASS_VALUE].Text));
                        lot_list.AddString("INPUT_MAT_ID", MPCF.Trim(spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.INPUT_MAT_ID].Text));
                        lot_list.AddString("OUTPUT_MAT_ID", MPCF.Trim(spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.OUTPUT_MAT_ID].Text));
                    }
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Update_Classify_Master_Data_List", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            int iCount = 0;

            try
            {
                if (MPCF.Trim(cdvMatGrp.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMatGrp.Text + "]");
                    cdvMatGrp.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        break;

                    case CSGC.CHECK.SAVE:

                        for (int i = 0; i < spdMasterData.ActiveSheet.RowCount; i++)
                        {
                            if (spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                            {
                                if (MPCF.Trim(spdMasterData.ActiveSheet.Cells[i, (int)CLASS_INFO.MAT_GROUP].Text) == "")
                                {
                                    MPCF.ShowMsgBox("(" + lblMatGrp.Text + ")\r\n" + MPCF.GetMessage(108));
                                    return false;
                                }
                                if (MPCF.Trim(spdMasterData.ActiveSheet.Cells[i, (int)CLASS_INFO.CLASS_TYPE].Text) == "")
                                {
                                    MPCF.ShowMsgBox("(" + lblClassType.Text + ")\r\n" + MPCF.GetMessage(108));
                                    return false;
                                }
                                if (MPCF.Trim(spdMasterData.ActiveSheet.Cells[i, (int)CLASS_INFO.CLASS_VALUE].Text) == "")
                                {
                                    MPCF.ShowMsgBox("(" + lblClass.Text + ")\r\n" + MPCF.GetMessage(108));
                                    return false;
                                }
                                if (MPCF.Trim(spdMasterData.ActiveSheet.Cells[i, (int)CLASS_INFO.INPUT_MAT_ID].Text) == "")
                                {
                                    MPCF.ShowMsgBox("(" + lblInputMatID.Text + ")\r\n" + MPCF.GetMessage(108));
                                    return false;
                                }

                                iCount++;
                            }
                        }

                        if (iCount == 0)
                        {
                            //CMN133 ERROR - 최소한 1개 이상의 아이템을 선택해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(133));
                            return false;
                        }

                        break;

                    case CSGC.CHECK.DELETE:

                        //CMN453 INFO - 정말 삭제하시겠습니까?
                        if (MPCF.ShowMsgBox(MPCF.GetMessage(453), MessageBoxButtons.YesNo, 1) == DialogResult.No)
                        {
                            return false;
                        }

                        for (int i = 0; i < spdMasterData.ActiveSheet.RowCount; i++)
                        {
                            if (spdMasterData_Sheet1.Cells[i, (int)CLASS_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                            {
                                if (MPCF.Trim(spdMasterData.ActiveSheet.Cells[i, (int)CLASS_INFO.MAT_GROUP].Text) == "")
                                {
                                    MPCF.ShowMsgBox("(" + lblMatGrp.Text + ")\r\n" + MPCF.GetMessage(108));
                                    return false;
                                }
                                if (MPCF.Trim(spdMasterData.ActiveSheet.Cells[i, (int)CLASS_INFO.CLASS_TYPE].Text) == "")
                                {
                                    MPCF.ShowMsgBox("(" + lblClassType.Text + ")\r\n" + MPCF.GetMessage(108));
                                    return false;
                                }
                                if (MPCF.Trim(spdMasterData.ActiveSheet.Cells[i, (int)CLASS_INFO.CLASS_VALUE].Text) == "")
                                {
                                    MPCF.ShowMsgBox("(" + lblClass.Text + ")\r\n" + MPCF.GetMessage(108));
                                    return false;
                                }
                                if (MPCF.Trim(spdMasterData.ActiveSheet.Cells[i, (int)CLASS_INFO.INPUT_MAT_ID].Text) == "")
                                {
                                    MPCF.ShowMsgBox("(" + lblInputMatID.Text + ")\r\n" + MPCF.GetMessage(108));
                                    return false;
                                }

                                iCount++;
                            }
                        }

                        if (iCount == 0)
                        {
                            //CMN133 ERROR - 최소한 1개 이상의 아이템을 선택해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(133));
                            return false;
                        }

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

        #region " Event Definition "

        private void frmWIPSetupClassifyMasterData_Load(object sender, EventArgs e)
        {
            try
            {
                MPCF.ClearList(spdMasterData);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatGrp_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvMatGrp.Init();
                MPCF.InitListView(cdvMatGrp.GetListView);
                cdvMatGrp.Columns.Add("Mat Group", 50, HorizontalAlignment.Left);
                cdvMatGrp.Columns.Add("Description", 0, HorizontalAlignment.Left);
                cdvMatGrp.SelectedSubItemIndex = 0;

                if (BASLIST.ViewGCMDataList(cdvMatGrp.GetListView, '1', "C_GRIT_MAT_TYPE") == false)
                {
                    cdvMatGrp.IsPopup = false;
                    return;
                }

                for (int i = cdvMatGrp.GetListView.Items.Count; i > 0; i--)
                {
                    if (cdvMatGrp.GetListView.Items[i - 1].SubItems[0].Text == "NONE")
                    {
                        cdvMatGrp.GetListView.Items[i - 1].Remove();
                    }
                }

                cdvMatGrp.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvClassType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvMatGrp.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMatGrp.Text + "]");
                    cdvMatGrp.Focus();
                    return;
                }

                cdvClassType.Init();
                MPCF.InitListView(cdvClassType.GetListView);
                cdvClassType.Columns.Add("Class Type", 100, HorizontalAlignment.Left);
                cdvClassType.Columns.Add("Description", 100, HorizontalAlignment.Left);
                cdvClassType.SelectedSubItemIndex = 0;

                if (BASLIST.ViewGCMDataList(cdvClassType.GetListView, '1', "C_GRIT_CLASS_TYPE") == false)
                {
                    return;
                }

                for (int i = cdvClassType.GetListView.Items.Count; i > 0; i--)
                {
                    if (cdvClassType.GetListView.Items[i - 1].SubItems[0].Text == "NONE")
                    {
                        cdvClassType.GetListView.Items[i - 1].Remove();
                    }
                }

                cdvClassType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvClass_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvMatGrp.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMatGrp.Text + "]");
                    cdvMatGrp.Focus();
                    return;
                }

                if (MPCF.Trim(cdvClassType.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblClassType.Text + "]");
                    cdvClassType.Focus();
                    return;
                }

                cdvClass.Init();
                MPCF.InitListView(cdvClass.GetListView);
                cdvClass.Columns.Add("Class Value", 50, HorizontalAlignment.Left);
                cdvClass.Columns.Add("Description", 50, HorizontalAlignment.Left);
                cdvClass.SelectedSubItemIndex = 0;

                if (ViewClassValue(cdvClass.GetListView, cdvMatGrp.Text, cdvClassType.Text) == false)
                    return;

                cdvClass.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvInputMatID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvMatGrp.Text) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMatGrp.Text + "]");
                    cdvInputMatID.Focus();
                    return;
                }

                // 제품 팝업으로 변경
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = CSGV.gs_area_grit;
                popup.sArea_desc = CSGV.gs_area_grit;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvInputMatID.Text = popup.sMat_id;
                    popup = null;
                }
                else
                {
                    return;
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdMasterData_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)CLASS_INFO.CHK)
                    {
                        CSCF.CheckSpreadCell(spdMasterData, 0, 0, true, true);
                    }
                }                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdMasterData_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                if (e.Column == (int)CLASS_INFO.MAT_GROUP_SELECT)
                {
                    //Mat group
                    cdvGridBtn.Init();
                    MPCF.InitListView(cdvGridBtn.GetListView);
                    cdvGridBtn.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridBtn.Columns.Add("Code", 0, HorizontalAlignment.Left);

                    if (BASLIST.ViewGCMDataList(cdvGridBtn.GetListView, '1', "C_GRIT_MAT_TYPE") == false)
                    {
                        return;
                    }

                    for (int i = cdvGridBtn.GetListView.Items.Count; i > 0; i--)
                    {
                        if (cdvGridBtn.GetListView.Items[i - 1].SubItems[0].Text == "NONE")
                        {
                            cdvGridBtn.GetListView.Items[i - 1].Remove();
                        }
                    }

                    cdvGridBtn.ShowPopupList(e.Row, e.Column);
                    cdvGridBtn.InsertEmptyRow(0, 1);
                }
                else if (e.Column == (int)CLASS_INFO.CLASS_TYPE_SELECT)
                {
                    if (MPCF.Trim(spdMasterData.ActiveSheet.Cells[e.Row,(int)CLASS_INFO.MAT_GROUP].Text) == "")
                    {
                        //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMatGrp.Text + "]");
                        spdMasterData.ActiveSheet.SetActiveCell(e.Row, (int)CLASS_INFO.MAT_GROUP_SELECT);
                        return;
                    }

                    //Class Type
                    cdvGridBtn.Init();
                    MPCF.InitListView(cdvGridBtn.GetListView);
                    cdvGridBtn.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridBtn.Columns.Add("Code", 50, HorizontalAlignment.Left);

                    if (BASLIST.ViewGCMDataList(cdvGridBtn.GetListView, '1', "C_GRIT_CLASS_TYPE") == false)
                    {
                        return;
                    }

                    for (int i = cdvGridBtn.GetListView.Items.Count; i > 0; i--)
                    {
                        if (cdvGridBtn.GetListView.Items[i - 1].SubItems[0].Text == "NONE")
                        {
                            cdvGridBtn.GetListView.Items[i - 1].Remove();
                        }
                    }

                    cdvGridBtn.ShowPopupList(e.Row, e.Column);
                    cdvGridBtn.InsertEmptyRow(0, 1);
                }
                else if (e.Column == (int)CLASS_INFO.CLASS_VALUE_SELECT)
                {
                    if (MPCF.Trim(spdMasterData.ActiveSheet.Cells[e.Row, (int)CLASS_INFO.MAT_GROUP].Text) == "")
                    {
                        //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMatGrp.Text + "]");
                        spdMasterData.ActiveSheet.SetActiveCell(e.Row, (int)CLASS_INFO.MAT_GROUP_SELECT);
                        return;
                    }

                    if (MPCF.Trim(spdMasterData.ActiveSheet.Cells[e.Row, (int)CLASS_INFO.CLASS_TYPE].Text) == "")
                    {
                        //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblClassType.Text + "]");
                        spdMasterData.ActiveSheet.SetActiveCell(e.Row, (int)CLASS_INFO.CLASS_TYPE_SELECT);
                        return;
                    }

                    //Class Value
                    cdvGridBtn.Init();
                    MPCF.InitListView(cdvGridBtn.GetListView);
                    cdvGridBtn.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridBtn.Columns.Add("Code", 50, HorizontalAlignment.Left);

                    if (ViewClassValue(cdvGridBtn.GetListView, spdMasterData.ActiveSheet.Cells[e.Row, (int)CLASS_INFO.MAT_GROUP].Text, 
                                                               spdMasterData.ActiveSheet.Cells[e.Row, (int)CLASS_INFO.CLASS_TYPE].Text) == false)
                        return;

                    cdvGridBtn.ShowPopupList(e.Row, e.Column);
                    cdvGridBtn.InsertEmptyRow(0, 1);
                }
                else if (e.Column == (int)CLASS_INFO.INPUT_MAT_SELECT)
                {               
                    frmPopMaterialList popup = new frmPopMaterialList();
                    popup.StartPosition = FormStartPosition.CenterParent;
                    popup.sArea_id = CSGV.gs_area_grit;
                    popup.sArea_desc = CSGV.gs_area_grit;

                    if (popup.ShowDialog() == DialogResult.OK)
                    {
                        spdMasterData_Sheet1.SetValue(e.Row, (int)CLASS_INFO.CHK, true);
                        spdMasterData_Sheet1.Cells[e.Row, (int)CLASS_INFO.INPUT_MAT_ID].Value = popup.sMat_id;
                        spdMasterData_Sheet1.Cells[e.Row, (int)CLASS_INFO.INPUT_MAT_DESC].Value = popup.sMat_Desc;
                        popup = null;
                    }
                    else                        
                        return;                        
                }
                else if (e.Column == (int)CLASS_INFO.OUTPUT_MAT_SELECT)
                {     
                    // 제품 팝업으로 변경
                    frmPopMaterialList popup = new frmPopMaterialList();
                    popup.StartPosition = FormStartPosition.CenterParent;
                    popup.sArea_id = CSGV.gs_area_grit;
                    popup.sArea_desc = CSGV.gs_area_grit;

                    if (popup.ShowDialog() == DialogResult.OK)
                    {
                        spdMasterData_Sheet1.SetValue(e.Row, (int)CLASS_INFO.CHK, true);
                        spdMasterData_Sheet1.Cells[e.Row, (int)CLASS_INFO.OUTPUT_MAT_ID].Value = popup.sMat_id;
                        spdMasterData_Sheet1.Cells[e.Row, (int)CLASS_INFO.OUTPUT_MAT_DESC].Value = popup.sMat_Desc;                            
                        popup = null;
                    }
                    else
                        return;          
                }                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvGridBtn_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (spdMasterData.ActiveSheet.ActiveColumnIndex == (int)CLASS_INFO.MAT_GROUP_SELECT)
                {
                    spdMasterData.ActiveSheet.SetValue(e.Row, (int)CLASS_INFO.MAT_GROUP, e.SelectedItem.SubItems[0].Text);
                    spdMasterData.ActiveSheet.SetValue(e.Row, (int)CLASS_INFO.CHK, true);
                }
                if (spdMasterData.ActiveSheet.ActiveColumnIndex == (int)CLASS_INFO.CLASS_TYPE_SELECT)
                {
                    spdMasterData.ActiveSheet.SetValue(e.Row, (int)CLASS_INFO.CLASS_TYPE, e.SelectedItem.SubItems[0].Text);
                    spdMasterData.ActiveSheet.SetValue(e.Row, (int)CLASS_INFO.CLASS_TYPE_DESC, e.SelectedItem.SubItems[1].Text);
                    spdMasterData.ActiveSheet.SetValue(e.Row, (int)CLASS_INFO.CHK, true);
                }
                if (spdMasterData.ActiveSheet.ActiveColumnIndex == (int)CLASS_INFO.CLASS_VALUE_SELECT)
                {
                    spdMasterData.ActiveSheet.SetValue(e.Row, (int)CLASS_INFO.CLASS_VALUE, e.SelectedItem.SubItems[0].Text);
                    spdMasterData.ActiveSheet.SetValue(e.Row, (int)CLASS_INFO.CLASS_VALUE_DESC, e.SelectedItem.SubItems[1].Text);
                    spdMasterData.ActiveSheet.SetValue(e.Row, (int)CLASS_INFO.CHK, true);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            try
            {
                spdMasterData.ActiveSheet.AddRows(0, 1);
                spdMasterData_Sheet1.SetValue(0, (int)CLASS_INFO.CHK, false);

                if (MPCF.Trim(cdvMatGrp.Text) != "")
                {
                    spdMasterData_Sheet1.Cells[0, (int)CLASS_INFO.MAT_GROUP].Value = cdvMatGrp.Text;
                }

                if (MPCF.Trim(cdvClassType.Text) != "")
                {
                    spdMasterData_Sheet1.Cells[0, (int)CLASS_INFO.CLASS_TYPE].Value = cdvClassType.Text;
                    spdMasterData_Sheet1.Cells[0, (int)CLASS_INFO.CLASS_TYPE_DESC].Value = cdvClassType.DisplayText;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnRowDel_Click(object sender, EventArgs e)
        {
            try
            {
                if (spdMasterData_Sheet1.RowCount == 0)
                {
                    //192 ERROR - 삭제할 데이터가 없습니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(192));
                    return;
                }

                for (int i = spdMasterData.ActiveSheet.RowCount - 1; i >= 0; i--)
                {
                    if (spdMasterData.ActiveSheet.Cells[i, (int)CLASS_INFO.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        spdMasterData.ActiveSheet.RemoveRows(i, 1);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                string sFileName = string.Empty;

                sFileName = cdvMatGrp.DisplayText;
                EXTFUC.SaveExcel(spdMasterData, sFileName);                
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewClassInfo();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.DELETE) == false)
                    return;

                if (SaveClass('D') == true)
                {
                    ViewClassInfo();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SaveClass('U') == true)
                {
                    ViewClassInfo();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        #endregion
    }
}
