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
    public partial class frmTranTransferResInfo : CUS_COM.frmTranForm01
    {
        public frmTranTransferResInfo()
        {
            InitializeComponent();
            InitControl();
        }

        #region " Constant Definition "

        private enum LOT_LIST
        {
            CHK,                    // 1 : 체크
            GROUP_ID,               // 2 : 그룹ID
            LOT_ID,                 // 3 : LOT ID
            MAPPING_SEQ             // 4 : MAPPING 순서
        }

        #endregion

        #region " Variable Definition "

        public string sArea_id = "";
        public string sArea_desc = "";
        public string sSub_area_id = "";
        public string sSub_area_desc = "";
        public string sOper_id = "";
        public string sOper_desc = "";
        public string sOrder_id = "";
        string sCupOper = "";
        string s_Cup_YN = "";
        string sImpOper = "";
        string s_Imp_YN = "";

        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public static bool ViewGCMListbyKey1(Control control, string sKey1)
        {
            string sViewID = "";

            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                sViewID = "CWIP2022-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "KEY_1";
                dvcArgu[1].sCondition_Value = sKey1;

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
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
                        itmX = new ListViewItem(row["KEY_2"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["DATA_1"].ToString());
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

        private void ViewLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = sImpOper;

                if (TPDR.GetDataOne("", ref dt, "CWIP2022-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLotList);
                    return;
                }

                MPCF.ClearList(spdLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList.ActiveSheet.RowCount++;

                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].Value = false;
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.GROUP_ID].Value = dt.Rows[i]["GROUP_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.MAPPING_SEQ].Value = dt.Rows[i]["MAPPING_SEQ"];
                }
                MPCF.FitColumnHeader(spdLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CheckOperOption(string sOper)
        {
            sCupOper = "";
            s_Cup_YN = "";
            sImpOper = "";
            s_Imp_YN = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2022-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }

                if (dt.Rows.Count > 0)
                {
                    sCupOper = dt.Rows[0]["CUP_OPER"].ToString();
                    s_Cup_YN = dt.Rows[0]["CUP_SEND_YN"].ToString();
                    sImpOper = dt.Rows[0]["INPECT_OPER"].ToString();
                    s_Imp_YN = dt.Rows[0]["INPECT_SEND_YN"].ToString();
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        // step 1 : standard lot 발번
        // step 2 : 설비 정보 전송
        private bool SendResInfo(char c_step)
        {
            try
            {
                TRSNode in_node = new TRSNode("Create_In");
                TRSNode out_node = new TRSNode("Create_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = c_step;

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("ORDER_ID", cdvOrder.Text);

                if (c_step == '1')
                {
                    in_node.AddString("RES_ID", cdvResource.Text);
                }
                else if (c_step == '2')
                {
                    in_node.AddChar("CUP_YN", s_Cup_YN);
                    in_node.AddString("CUP_LOT_ID", txtStandardLot.Text);
                    in_node.AddString("CUP_RECIPE_ID", cdvRecipe.Text);
                    in_node.AddString("CUP_RES_ID", cdvResource.Text);
                    in_node.AddChar("IMP_YN", s_Imp_YN);
                    in_node.AddString("IMP_LOT_ID", txtStandardLot.Text);
                    in_node.AddString("IMP_RECIPE_ID", cdvRecipe.Text);
                    in_node.AddString("IMP_RES_ID", cdvResource1.Text);
                    in_node.AddInt("LOT_QTY", MPCF.ToInt(txtCreateQty.Text));
                    in_node.AddString("AUTO_FLAG", cdvAuto.Text);
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Send_Resource_Info", in_node, ref out_node) == false)
                {
                    return false;
                }
                else
                {
                    if (c_step == '2')
                        MPCR.ShowSuccessMsg(out_node);
                }

                if (c_step == '1')
                {
                    txtStandardLot.Text = out_node.GetString("LOT_ID");
                    txtStandardLot1.Text = out_node.GetString("LOT_ID");
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //벨리데이션 체크
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvOrder.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOrder.Text + "]");
                    cdvOrder.Focus();
                    return false;
                }

                switch (CHECK)
                {

                    case CSGC.CHECK.NONE:

                        if (MPCF.Trim(cdvResource.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblResource.Text + "]");
                            cdvResource.Focus();
                            return false;
                        }

                        break;


                    case CSGC.CHECK.SAVE:

                        if (s_Cup_YN == "Y")
                        {
                            if (MPCF.Trim(cdvResource.Text) == "")
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblResource.Text + "]");
                                cdvResource.Focus();
                                return false;
                            }

                            if (MPCF.Trim(txtStandardLot.Text) == "")
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblStandardLot.Text + "]");
                                txtStandardLot.Focus();
                                return false;
                            }

                            if (MPCF.Trim(cdvRecipe.Text) == "")
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblRecipe.Text + "]");
                                cdvRecipe.Focus();
                                return false;
                            }
                        }

                        if (s_Cup_YN == "Y")
                        {
                            if (MPCF.Trim(cdvResource1.Text) == "")
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblResource1.Text + "]");
                                cdvResource1.Focus();
                                return false;
                            }

                            if (MPCF.Trim(txtStandardLot1.Text) == "")
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblStandardLot1.Text + "]");
                                txtStandardLot1.Focus();
                                return false;
                            }

                            if (MPCF.Trim(cdvRecipe1.Text) == "")
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblRecipe1.Text + "]");
                                cdvRecipe1.Focus();
                                return false;
                            }
                        }

                        if (MPCF.ToInt(txtCreateQty.Text) == 0 || MPCF.Trim(txtCreateQty.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblCreateQty.Text + "]");
                            txtCreateQty.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvAuto.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblAuto.Text + "]");
                            cdvAuto.Focus();
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

        //화면 클리어
        private void ClearData(CSGC.CHECK CHECK)
        {
            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.SAVE:

                        txtStandardLot.Text = "";
                        cdvResource.Text = "";
                        txtStandardLot1.Text = "";
                        cdvResource1.Text = "";
                        cdvRecipe.Text = "";
                        cdvRecipe1.Text = "";
                        txtCreateQty.Text = "0";
                        cdvAuto.Text = "";
                        MPCF.ClearList(spdLotList);

                        break;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmTranTransferResInfo_Load(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Text = sArea_id;
                cdvDept.DisplayText = sArea_desc;
                cdvWorkPlace.Text = sSub_area_id;
                cdvWorkPlace.DisplayText = sSub_area_desc;
                cdvOper.Text = sOper_id;
                cdvOper.DisplayText = sOper_desc;
                cdvOrder.Text = sOrder_id;

                if (MPCF.Trim(cdvOper.Text) != "")
                {
                    CheckOperOption(cdvOper.Text);
                }

                if (s_Cup_YN == "Y")
                {
                    grpCupInfo.Enabled = true;
                    spdLotList.Enabled = false;
                    btnViewLotList.Enabled = false;
                }
                else
                {
                    grpCupInfo.Enabled = false;
                    spdLotList.Enabled = true;
                    btnViewLotList.Enabled = true;
                }

                if (s_Imp_YN == "Y")
                {
                    grpImpInfo.Enabled = true;
                    
                }
                else
                {
                    grpImpInfo.Enabled = false;                    
                }

                txtCreateQty.Text = "0";
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

                cdvOrder.Init();
                MPCF.InitListView(cdvOrder.GetListView);
                cdvOrder.Columns.Add("Order", 50, HorizontalAlignment.Left);
                cdvOrder.Columns.Add("Start_date", 50, HorizontalAlignment.Left);
                cdvOrder.Columns.Add("End_date", 50, HorizontalAlignment.Left);
                cdvOrder.SelectedSubItemIndex = 0;

                if (COM_LIST.ViewResourceList(cdvResource.GetListView, '1', cdvOper.Text) == false)
                    return;

                cdvOrder.InsertEmptyRow(0, 1);
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
                cdvResource.Init();
                MPCF.InitListView(cdvResource.GetListView);
                cdvResource.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvResource.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvResource.SelectedSubItemIndex = 0;
                cdvResource.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewResourceList(cdvResource.GetListView, '1', sCupOper) == false)
                    return;

                cdvResource.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvResource1_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvResource1.Init();
                MPCF.InitListView(cdvResource1.GetListView);
                cdvResource1.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvResource1.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvResource1.SelectedSubItemIndex = 0;
                cdvResource1.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewResourceList(cdvResource1.GetListView, '1', sImpOper) == false)
                    return;

                cdvResource1.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvRecipe_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvRecipe.Init();
                MPCF.InitListView(cdvRecipe.GetListView);
                cdvRecipe.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvRecipe.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvRecipe.SelectedSubItemIndex = 0;
                cdvRecipe.DisplaySubItemIndex = 1;

                if (ViewGCMListbyKey1(cdvRecipe.GetListView, sCupOper) == false)
                {
                    return;
                }

                cdvRecipe.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvRecipe1_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvRecipe1.Init();
                MPCF.InitListView(cdvRecipe1.GetListView);
                cdvRecipe1.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvRecipe1.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvRecipe1.SelectedSubItemIndex = 0;
                cdvRecipe1.DisplaySubItemIndex = 1;

                if (ViewGCMListbyKey1(cdvRecipe1.GetListView, sImpOper) == false)
                {
                    return;
                }

                cdvRecipe1.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvAuto_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvAuto.Init();
                MPCF.InitListView(cdvAuto.GetListView);
                cdvAuto.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvAuto.SelectedSubItemIndex = 0;

                if (BASLIST.ViewGCMDataList(cdvAuto.GetListView, '1', MPGC.MP_GCM_YESNO) == false)
                {
                    return;
                }

                cdvAuto.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (i == e.Row)
                    {
                        continue;
                    }

                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].Value = false;
                }

                txtStandardLot1.Text = spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_LIST.LOT_ID].Text;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnGen_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.NONE) == false)
                    return;

                if (SendResInfo('1') == false)
                {
                    txtStandardLot.Text = "";
                    txtStandardLot1.Text = "";
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnViewLotList_Click(object sender, EventArgs e)
        {
            try
            {
                ViewLotList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SendResInfo('2'))
                {
                    ClearData(CSGC.CHECK.SAVE);
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion


    }
}
