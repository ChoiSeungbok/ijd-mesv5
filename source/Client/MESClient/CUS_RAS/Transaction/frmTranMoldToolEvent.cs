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

namespace CUS_RAS
{
    public partial class frmTranMoldToolEvent : CUS_COM.frmTranForm05
    {
        public frmTranMoldToolEvent()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        #endregion

        #region " Variable Definition "

        string tool_id = "";
        string tool_type = "";
        string tool_event_id = "";

        #endregion

        #region " Function Defintion "

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

        //벨리데이션 체크
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        if (MPCF.Trim(cdvDept.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvToolType.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToolType.Text + "]");
                            cdvToolType.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvToolId.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToolId.Text + "]");
                            cdvToolId.Focus();
                            return false;
                        }

                        break;

                    case CSGC.CHECK.SAVE:
                        if (tool_id == "")
                        {
                            return false;
                        }


                        if (MPCF.Trim(cdvToolEvent.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToolEvent.Text + "]");
                            cdvToolEvent.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvToolEvent.Text)==CSGC.CP_TOOL_EVENT_RES_INPUT && MPCF.Trim(cdvResId.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblResId.Text + "]");
                            cdvResId.Focus();
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

        // 데이터 초기화
        private void ClearInfo()
        {
            try
            {
                tool_type = "";

                txtResId.Text = "";
                txtModel.Text = "";
                txtToolType.Text = "";
                txtToolTypeDesc.Text = "";
                txtUseCount.Text = "";
                txtLastToolEvent.Text = "";
                txtLastTranTime.Text = "";
                txtLimitLifespan.Text = "";
                txtAlarmCount.Text = "";
                txtCar.Text = "";
                txtTopBase.Text = "";

                ClearEventInfo();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 이벤트 정보 초기화
        private void ClearEventInfo()
        {
            try
            {
                cdvToolEvent.Text = "";
                txtComment.Text = "";

                InitEnable();
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //비활성화 초기화
        private void InitEnable()
        {
            try
            {
                if (cdvToolEvent.Text!= CSGC.CP_TOOL_EVENT_RES_INPUT)
                {
                    cdvResId.Enabled = false;
                    cdvResId.Text = "";
                }

                cdvCar.Enabled = false;
                cdvCar.Text = "";

                cdvTopBase.Enabled = false;
                cdvTopBase.Text = "";
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //현재 툴 조회
        private void ViewToolInfo(string toolId)
        {
            string sView_Id = "";
            tool_type = cdvToolType.Text.Trim();

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                sView_Id = "CRAS2005-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "TOOL_ID";
                dvcArgu[1].sCondition_Value = toolId;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                if (dt.Rows.Count > 0)
                {
                    txtToolStatus.Text = dt.Rows[0]["TOOL_STATUS"].ToString();
                    txtResId.Text = dt.Rows[0]["RES_DESC"].ToString();
                    txtUseCount.Text = dt.Rows[0]["TOOL_STS_4"].ToString();
                    txtLimitLifespan.Text = dt.Rows[0]["TOOL_STS_3"].ToString();
                    txtCar.Text = dt.Rows[0]["CAR_DESC"].ToString();

                    txtModel.Text = dt.Rows[0]["MODEL_DESC"].ToString();
                    txtLastToolEvent.Text = dt.Rows[0]["TOOL_EVENT_DESC"].ToString();
                    txtAlarmCount.Text = dt.Rows[0]["TOOL_STS_5"].ToString();
                    txtTopBase.Text = dt.Rows[0]["PAN_DESC"].ToString();

                    txtToolType.Text = dt.Rows[0]["TOOL_TYPE"].ToString();
                    txtOper.Text = dt.Rows[0]["OPER"].ToString();
                    txtToolTypeDesc.Text = dt.Rows[0]["TOOL_TYPE_DESC"].ToString();
                    txtLastTranTime.Text = MPCF.MakeDateFormat(dt.Rows[0]["LAST_TRAN_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);

                }
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //툴 상세 조회
        private void ViewDetailToolInfo(String toolId)
        {
            string sViewID = "";

            try
            {
                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                sViewID = "CRAS2005-002";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "TOOL_ID";
                dvcArgu[1].sCondition_Value = toolId;

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return;

                int i = 0;

                if(dt.Rows.Count > 0)
                {
                    cdvDept.Text = dt.Rows[i]["AREA_ID"].ToString();
                    cdvDept.DisplayText = dt.Rows[i]["AREA_DESC"].ToString();
                    cdvToolType.Text = dt.Rows[i]["TOOL_TYPE"].ToString();
                    cdvToolType.DisplayText = dt.Rows[i]["TOOL_TYPE_DESC"].ToString();
                }
            }            
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //툴 이벤트 조회
        private void ViewToolEvent(string toolId, string toolType, string toolEventId)
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";

                sView_Id = "CRAS2005-003";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "TOOL_ID";
                dvcArgu[1].sCondition_Value = toolId;

                dvcArgu[2].sCondition_ID = "TOOL_TYPE";
                dvcArgu[2].sCondition_Value = toolType;

                dvcArgu[3].sCondition_ID = "TOOL_EVENT_ID";
                dvcArgu[3].sCondition_Value = toolEventId;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }
                int i = 0;

                if (dt.Rows.Count > 0)
                {
                    cdvToolEvent.Text = dt.Rows[i]["TOOL_EVENT_ID"].ToString();
                    cdvToolEvent.DisplayText = dt.Rows[i]["TOOL_EVENT_DESC"].ToString();
                    cdvResId.Text = dt.Rows[i]["RES_ID"].ToString();
                    cdvResId.DisplayText = dt.Rows[i]["RES_DESC"].ToString();
                    cdvCar.Text = dt.Rows[i]["CAR"].ToString();
                    cdvCar.DisplayText = dt.Rows[i]["CAR_DESC"].ToString();
                    cdvTopBase.Text = dt.Rows[i]["PAN"].ToString();
                    cdvTopBase.DisplayText = dt.Rows[i]["PAN_DESC"].ToString();
                    txtComment.Text = dt.Rows[i]["TRAN_COMMENT"].ToString();                    
                }

                if (toolEventId == CSGC.CP_TOOL_EVENT_RES_INPUT)
                {
                    cdvResId.Enabled = true;
                }

                if (CheckPress(MPCF.Trim(cdvResId.Text)))
                {
                    cdvCar.Enabled = true;
                    cdvTopBase.Enabled = true;
                }

            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //툴 조회
        private bool ViewToolList(Control control, string sArea, string sSubArea, string sToolType)
        {
            ListViewItem itmX = null;
            int iToolIcon;
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CRAS2005-005";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = sSubArea;

                dvcArgu[3].sCondition_ID = "TOOL_TYPE";
                dvcArgu[3].sCondition_Value = sToolType;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                if (dt == null)
                    return false;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                 foreach (DataRow row in dt.Rows)
                {
                    iToolIcon = (int)SMALLICON_INDEX.IDX_TOOL;

                    if (control is ListView)
                    {
                        if (MPCF.Trim(dt.Rows[i]["DELETE_FLAG"].ToString()) == "S")
                        {
                            iToolIcon = (int)SMALLICON_INDEX.IDX_TOOL_SCRAP;
                        }
                        else if (MPCF.Trim(dt.Rows[i]["DELETE_FLAG"].ToString()) == "R")
                        {
                            iToolIcon = (int)SMALLICON_INDEX.IDX_TOOL_RETURN;
                        }
     
                        itmX = new ListViewItem(MPCF.Trim(row["TOOL_ID"].ToString()), iToolIcon);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add((MPCF.Trim(row["TOOL_DESC"].ToString())));
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

        //툴 이벤트 저장
        private bool SaveToolEvent()
        {
            TRSNode in_node = new TRSNode("Tran_In");
            TRSNode out_node = new TRSNode("Tran_Out");
            TRSNode sts_list;

            try
            {
                tool_event_id = cdvToolEvent.Text;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                in_node.AddString("TOOL_ID", tool_id);
                in_node.AddString("TOOL_EVENT_ID", tool_event_id);
                in_node.AddString("RES_ID", cdvResId.Text);
                in_node.AddString("TRAN_COMMENT", txtComment.Text);

                sts_list = in_node.AddNode("STS_LIST");
                sts_list.AddString("TOOL_STS", cdvCar.Text);

                sts_list = in_node.AddNode("STS_LIST");
                sts_list.AddString("TOOL_STS", cdvTopBase.Text);

                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Mold_Tool_Event", in_node, ref out_node) == false)
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

        //설비 종류 조회
        private bool CheckPress(string sResId)
        {
            string sView_Id = "";
            string sResType = " ";
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                sView_Id = "CRAS2005-004";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "RES_ID";
                dvcArgu[1].sCondition_Value = sResId;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }
                int i = 0;

                if (dt.Rows.Count > 0)
                {
                    sResType = dt.Rows[i]["RES_GRP_1"].ToString();
                   
                }

                if (sResType==CSGC.CP_RESOURCE_GROUP_PRESS)
                {
                    return true;
                }

                return false;
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        #endregion\

        #region " Event Definition"
        private void cdvToolType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvToolType.Init();
                MPCF.InitListView(cdvToolType.GetListView);
                cdvToolType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToolType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToolType.SelectedSubItemIndex = 0;
                cdvToolType.DisplaySubItemIndex = 1;

                if (RASLIST.ViewToolTypeList(cdvToolType.GetListView,'1',' ',' ', null) ==false)
                {
                    return;
                }

                cdvToolType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToolId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                if (MPCF.Trim(cdvToolType.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToolType.Text + "]");
                    cdvToolType.Focus();
                    return;
                }

                cdvToolId.Init();
                MPCF.InitListView(cdvToolId.GetListView);
                cdvToolId.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToolId.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToolId.SelectedSubItemIndex = 0;
                cdvToolId.DisplaySubItemIndex = 1;

                if (ViewToolList(cdvToolId.GetListView,cdvDept.Text, cdvWorkPlace.Text, cdvToolType.Text) == false)
                {
                    return;
                }
                cdvToolId.InsertEmptyRow(0, 1);              
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToolEvent_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvToolType.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToolType.Text + "]");
                    cdvToolType.Focus();
                    return;
                }

                cdvToolEvent.Init();
                MPCF.InitListView(cdvToolEvent.GetListView);
                cdvToolEvent.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToolEvent.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToolEvent.SelectedSubItemIndex = 0;
                cdvToolEvent.DisplaySubItemIndex = 1;

                //툴 이벤트 호출                
                if (RASLIST.ViewToolEventList(cdvToolEvent.GetListView, '1', cdvToolType.Text, 'N', null)==false)
                {
                    return;
                }

                cdvToolEvent.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvResId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return;
                }

                cdvResId.Init();
                MPCF.InitListView(cdvResId.GetListView);
                cdvResId.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvResId.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvResId.SelectedSubItemIndex = 0;
                cdvResId.DisplaySubItemIndex = 1;

                //장비 호출      
                if (COM_LIST.ViewResourceList(cdvResId.GetListView, '3', txtOper.Text, cdvWorkPlace.Text) == false)
                    return;

                cdvResId.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvCar_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvCar.Init();
                MPCF.InitListView(cdvCar.GetListView);
                cdvCar.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvCar.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvCar.SelectedSubItemIndex = 0;
                cdvCar.DisplaySubItemIndex = 1;

                //카 호출
                if (BASLIST.ViewGCMDataList(cdvCar.GetListView, '1', CSGC.CP_GCM_CAR) == false)
                {
                    return;
                }

                cdvCar.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ClearInfo();

                tool_id = MPCF.Trim(cdvToolId.Text);
                ViewToolInfo(tool_id);
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

                if (SaveToolEvent())
                {
                    ClearInfo();
                    ViewToolInfo(tool_id);

                    tool_type = txtToolType.Text;
                    ViewToolEvent(tool_id, tool_type, tool_event_id);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //장비가 프레스인 경우 카, 상/하판 정보를 입력 가능
        //다른 장비일 경우 비활성화.
        private void cdvResId_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            string res_id = "";

            try
            {
                res_id = MPCF.Trim(cdvResId.Text);

                if (CheckPress(res_id))
                {
                    cdvCar.Enabled = true;
                    cdvTopBase.Enabled = true;
                }
                else
                {
                    InitEnable();
                }
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvTopBase_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvTopBase.Init();
                MPCF.InitListView(cdvTopBase.GetListView);
                cdvTopBase.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvTopBase.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvTopBase.SelectedSubItemIndex = 0;
                cdvTopBase.DisplaySubItemIndex = 1;

                //상 하판 호출
                if (BASLIST.ViewGCMDataList(cdvTopBase.GetListView, '1', CSGC.CP_GCM_PAN) == false)
                {
                    return;
                }

                cdvTopBase.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //툴 장착시 장비 선택 활성화, 해제시 비활성화
        private void cdvToolEvent_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                tool_event_id = cdvToolEvent.Text;

                InitEnable();

                //툴 장착
                if (tool_event_id == CSGC.CP_TOOL_EVENT_RES_INPUT)
                {
                    cdvResId.Enabled = true;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToolType_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvToolId.Text = "";
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkPlace_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                cdvWorkPlace.Init();
                MPCF.InitListView(cdvWorkPlace.GetListView);
                cdvWorkPlace.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWorkPlace.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWorkPlace.SelectedSubItemIndex = 0;
                cdvWorkPlace.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList_AREA(cdvWorkPlace.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, cdvDept.Text) == false)
                {
                    return;
                }

                //특정 사업장인 경우 Tag에 저장된 사업부를 제외하고 보이지 않기 위해
                if (MPCF.Trim(cdvWorkPlace.Tag) != "")
                {
                    for (int i = cdvWorkPlace.GetListView.Items.Count; i > 0; i--)
                    {
                        if (cdvWorkPlace.GetListView.Items[i - 1].SubItems[0].Text != cdvWorkPlace.Tag.ToString())
                        {
                            cdvWorkPlace.GetListView.Items[i - 1].Remove();
                        }
                    }
                }

                cdvWorkPlace.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkPlace_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvToolId.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvWorkPlace.Text = "";
                cdvToolType.Text = "";
                cdvToolId.Text = "";
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion
    }
}
