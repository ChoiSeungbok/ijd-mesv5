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
//CRAS3006
namespace CUS_RAS
{
    public partial class frmViewMoldStatus : CUS_COM.frmViewForm03
    {




        public frmViewMoldStatus()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum MOLD_INFO : int
        {
            CHK,
            MOLD_NO,
            MAT_ID,
            MOLD_DESC,
            MOLD_MODEL,
            MOLD_TYPE,
            AREA_ID,
            OPER,
            RECV_DATE,
            VENDOR,
            VENDOR_LOT_ID,
            DLV_NO,
            PO_NO,
            PO_SEQ,
            RES_ID,
            CAR,
            TOP_BASE,
            MAX_USE_COUNT,
            USE_COUNT,
            ALARM_COUNT,
            REMARK
        }

        #endregion

        #region " Variable Definition "
            public string g_Popup_yn = "N";
            public string g_Tool_id = "";

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 툴 이력 조회
        private void ViewToolStatus()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = "%" + cdvDept.Text + "%";

                dvcArgu[2].sCondition_ID = "TOOL_GRP";
                dvcArgu[2].sCondition_Value = cdvModel.Text + "%";

                dvcArgu[3].sCondition_ID = "TOOL_TYPE";
                dvcArgu[3].sCondition_Value = cdvToolType.Text + "%";

                dvcArgu[4].sCondition_ID = "TOOL_ID";
                dvcArgu[4].sCondition_Value = txtToolId.Text + "%";

                dvcArgu[5].sCondition_ID = "OPER";
                dvcArgu[5].sCondition_Value = cdvOper.Text + "%";

                if (TPDR.GetDataOne("", ref dt, "CRAS3006-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    MPCF.ClearList(spdToolList);

                    return;
                }

                MPCF.ClearList(spdToolList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdToolList.ActiveSheet.RowCount++;

                    spdToolList.ActiveSheet.SetValue(i, (int)MOLD_INFO.CHK, false);
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_NO].Value = dt.Rows[i]["TOOL_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_MODEL].Value = dt.Rows[i]["MOLD_MODEL"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_TYPE].Value = dt.Rows[i]["MOLD_TYPE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.AREA_ID].Value = dt.Rows[i]["AREA_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.OPER].Value = dt.Rows[i]["OPER_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.RECV_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["RECV_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.VENDOR].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.DLV_NO].Value = dt.Rows[i]["DLV_NO"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.PO_NO].Value = dt.Rows[i]["PO_NO"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.PO_SEQ].Value = dt.Rows[i]["PO_SEQ"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.RES_ID].Value = dt.Rows[i]["RES_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CAR].Value = dt.Rows[i]["CAR"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.TOP_BASE].Value = dt.Rows[i]["PAN"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MAX_USE_COUNT].Value = dt.Rows[i]["MAX_USE_COUNT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.USE_COUNT].Value = dt.Rows[i]["USE_COUNT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.ALARM_COUNT].Value = dt.Rows[i]["ALAM_COUNT"];                    
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.REMARK].Value = dt.Rows[i]["TOOL_COMMENT"];
                }

                MPCF.FitColumnHeader(spdToolList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool SaveUseCount()
        {
            try
            {
                TRSNode in_node = new TRSNode("loss_Code_In");
                TRSNode out_node = new TRSNode("loss_Code_Out");
                TRSNode Tool_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';

                for (int i = 0; i < spdToolList.ActiveSheet.RowCount; i++)
                {
                    if (spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        Tool_list = in_node.AddNode("TOOL_TBL");
                        Tool_list.AddString("TOOL_ID", spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_NO].Text);
                        Tool_list.AddInt("USE_COUNT", MPCF.ToInt(spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.USE_COUNT].Text));
                    }
                }

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


        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            int iCount = 0;

            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        
                        break;

                    case CSGC.CHECK.SAVE:

                        for (int i = 0; i < spdToolList.ActiveSheet.RowCount; i++)
                        {
                            if (spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                            {
                                iCount++;
                            }
                        }

                        if (iCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305));
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

        private void ClearData()
        {
            try
            {
                MPCF.ClearList(spdToolList);                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "
        private void cdvOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {

        }

        private void cdvOper_ButtonPress(object sender, EventArgs e)
        {
            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(cdvOper.GetListView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';


            in_node.AddString("SQL", "SELECT OPER AS CODE, OPER_DESC AS VALUE FROM MWIPOPRDEF "
                                   + "WHERE FACTORY = '" + MPGV.gsFactory + "' AND OPER_GRP_1 IN('CONSIGNMENT','MOLD') AND AREA_ID ='" + cdvDept.Text + "'");


            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return;
                }

                MPCR.FillDataView(cdvOper.GetListView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);


            cdvOper.InsertEmptyRow(0, 1);
        }
        private void frmViewMoldStatus_Load(object sender, EventArgs e)
        {
            try
            {
                if(g_Popup_yn =="Y") {
                    txtToolId.Text = g_Tool_id;
                    cdvDept.ReadOnly = true;
                    cdvModel.ReadOnly = true;
                    cdvToolType.ReadOnly = true;

                    cdvDept.Text = "";
                    cdvModel.Text = "";
                    cdvToolType.Text = "";

                    ViewToolStatus();
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvModel_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvModel.Init();
                MPCF.InitListView(cdvModel.GetListView);
                cdvModel.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvModel.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvModel.SelectedSubItemIndex = 0;
                cdvModel.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvModel.GetListView, '1', MPGC.MP_RAS_TOOL_GRP) == false)
                {
                    return;
                }

                cdvModel.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

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

                if (BASLIST.ViewGCMDataList(cdvToolType.GetListView, '1', CSGC.CP_GCM_MOLD_TYPE) == false)
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

        private void txtToolId_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void spdToolList_EditChange(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                if (e.Column == (int)MOLD_INFO.USE_COUNT)
                {
                    spdToolList.ActiveSheet.SetValue(e.Row, (int)MOLD_INFO.CHK, true);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            string sFileName = "";

            try
            {
                sFileName = "MoldStatus";

                EXTFUC.SaveExcel(spdToolList, sFileName);
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

                ViewToolStatus();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SaveUseCount() == true)
                {
                    ViewToolStatus();
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
