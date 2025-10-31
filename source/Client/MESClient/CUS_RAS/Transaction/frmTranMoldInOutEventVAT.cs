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

//CRAS2008
namespace CUS_RAS
{
    public partial class frmTranMoldInOutEventVAT : CUS_COM.frmTranForm05
    {
        public frmTranMoldInOutEventVAT()
        {
            InitializeComponent();
            InitControl();
        }

        #region " Constant Definition "

        private enum MOLD_INFO : int
        {
            AREA_ID,
            AREA_DESC,
            PRESS_TYPE,
            HOGI,
            RES_ID,
            MOLD_TYPE,
            MOLD_TYPE_CODE,
            TOOL_ID,
            TOOL_ID_BTN,
            USE_COUNT,
            USE_COUNT_BTN,
            DAY_COUNT,
            INPUT_BTN,
            OUTPUT_BTN,
            COMMENT,
            COMMENT_BTN,
        }

        #endregion

        #region " Variable Definition "

        public string g_Popup_yn = "N";


        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnPopup.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                chkAutoRefresh.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                numRefreshSec.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                lblSec.Anchor = AnchorStyles.Top | AnchorStyles.Left;
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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int iCount = 0;
                FarPoint.Win.Spread.FpSpread sSpead = new FarPoint.Win.Spread.FpSpread();

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text + "%";

                if (TPDR.GetDataOne("", ref dt, "CRAS2011-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    MPCF.ClearList(spdToolList1);
                    MPCF.ClearList(spdToolList2);
                    MPCF.ClearList(spdToolList3);
                    MPCF.ClearList(spdToolList4);

                    return;
                }

                MPCF.ClearList(spdToolList1);
                MPCF.ClearList(spdToolList2);
                MPCF.ClearList(spdToolList3);
                MPCF.ClearList(spdToolList4);

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    if (dt.Rows[i]["RES_LOCATION"].ToString() == "P1")
                        sSpead = spdToolList1;
                    else if (dt.Rows[i]["RES_LOCATION"].ToString() == "P2")
                        sSpead = spdToolList2;
                    else if (dt.Rows[i]["RES_LOCATION"].ToString() == "P3")
                        sSpead = spdToolList3;
                    else if (dt.Rows[i]["RES_LOCATION"].ToString() == "P4")
                        sSpead = spdToolList4;

                    iCount = sSpead.ActiveSheet.RowCount;
                    sSpead.ActiveSheet.RowCount++;

                    sSpead.ActiveSheet.Cells[iCount, (int)MOLD_INFO.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    sSpead.ActiveSheet.Cells[iCount, (int)MOLD_INFO.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    sSpead.ActiveSheet.Cells[iCount, (int)MOLD_INFO.PRESS_TYPE].Value = dt.Rows[i]["PRESS_TYPE"];
                    sSpead.ActiveSheet.Cells[iCount, (int)MOLD_INFO.HOGI].Value = dt.Rows[i]["HOGI"];
                    sSpead.ActiveSheet.Cells[iCount, (int)MOLD_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    sSpead.ActiveSheet.Cells[iCount, (int)MOLD_INFO.MOLD_TYPE].Value = dt.Rows[i]["MOLD_TYPE"];
                    sSpead.ActiveSheet.Cells[iCount, (int)MOLD_INFO.MOLD_TYPE_CODE].Value = dt.Rows[i]["MOLD_TYPE_CODE"];
                    sSpead.ActiveSheet.Cells[iCount, (int)MOLD_INFO.TOOL_ID].Value = dt.Rows[i]["TOOL_ID"];
                    sSpead.ActiveSheet.Cells[iCount, (int)MOLD_INFO.USE_COUNT].Value = MPCF.ToInt(dt.Rows[i]["USE_COUNT"].ToString());
                    sSpead.ActiveSheet.Cells[iCount, (int)MOLD_INFO.DAY_COUNT].Value = MPCF.ToInt(dt.Rows[i]["DAY_COUNT"].ToString());
                    sSpead.ActiveSheet.Cells[iCount, (int)MOLD_INFO.COMMENT].Value = dt.Rows[i]["TOOL_COMMENT"];
                }

                MPCF.FitColumnHeader(spdToolList1);
                MPCF.FitColumnHeader(spdToolList2);
                MPCF.FitColumnHeader(spdToolList3);
                MPCF.FitColumnHeader(spdToolList4);
                spdToolList1.ActiveSheet.Columns[(int)MOLD_INFO.COMMENT].Width = 200;
                spdToolList2.ActiveSheet.Columns[(int)MOLD_INFO.COMMENT].Width = 200;
                spdToolList3.ActiveSheet.Columns[(int)MOLD_INFO.COMMENT].Width = 200;
                spdToolList4.ActiveSheet.Columns[(int)MOLD_INFO.COMMENT].Width = 200;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool SaveToolInOut(char c_step, string sRes_id, string sTool_id, string sCar, string sTopBase, string sTool_comment, string sUse_Count)
        {
            string tool_event_id = "";

            try
            {
                TRSNode in_node = new TRSNode("Tran_In");
                TRSNode out_node = new TRSNode("Tran_Out");
                TRSNode sts_list, Tool_list;

                try
                {
                    if (c_step == '1')
                        tool_event_id = "RES_INPUT";
                    else if (c_step == '2')
                        tool_event_id = "RES_OUTPUT";

                    MPCR.SetInMsg(in_node);

                    if (c_step == '3')
                    {
                        in_node.ProcStep = '3';
                    }
                    else if (c_step == '4')
                    {
                        in_node.ProcStep = '2';
                    }
                    else
                    {
                        in_node.ProcStep = '1';
                    }




                    in_node.AddString("TOOL_ID", sTool_id);
                    in_node.AddString("TOOL_EVENT_ID", tool_event_id);
                    in_node.AddString("RES_ID", sRes_id);
                    in_node.AddString("TRAN_COMMENT", sTool_comment);

                    sts_list = in_node.AddNode("STS_LIST");
                    sts_list.AddString("TOOL_STS", sCar);

                    sts_list = in_node.AddNode("STS_LIST");
                    sts_list.AddString("TOOL_STS", sTopBase);
                    if (c_step == '4')
                    {
                        Tool_list = in_node.AddNode("TOOL_TBL");
                        Tool_list.AddString("TOOL_ID", sTool_id);
                        Tool_list.AddInt("USE_COUNT", MPCF.ToInt(sUse_Count));
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
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void SaveToolEvn(FarPoint.Win.Spread.FpSpread S_Spread, string sType, int i_RowIndwx)
        {
            FarPoint.Win.Spread.FpSpread Sspread = new FarPoint.Win.Spread.FpSpread();
            string sResID = "";
            string sToolID = "";
            string sCar = "";
            string sTopBase = "";
            string sToolComment = "";
            string sCount = "0";
            string sMoldType = "";

            try
            {
                Sspread = S_Spread;

                if (sType == "INPUT")
                {
                    frmPopToolList popup = new frmPopToolList();
                    popup.StartPosition = FormStartPosition.CenterParent;
                    popup.sArea_id = ""; // Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.AREA_ID].Text;
                    popup.sArea_desc = ""; // Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.AREA_DESC].Text;
                    popup.g_Popup_yn = "Y";

                    if (popup.ShowDialog() == DialogResult.OK)
                    {
                        Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.TOOL_ID].Value = popup.g_Tool_id;
                        Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.USE_COUNT].Value = MPCF.ToInt(popup.g_Tool_count);
                        Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.AREA_ID].Value = MPCF.ToInt(popup.g_Area_id);


                        popup = null;
                    }
                    else
                        return;

                    if (MPCF.Trim(Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.TOOL_ID].Text) != "")
                    {
                        //진짜 투입처리 할건지 물어본다.
                        //CMN540 INFO -  금형을 정말 장착 하시겠습니까?
                        if (MPCF.ShowMsgBox(MPCF.GetMessage(540), MessageBoxButtons.YesNo, 1) == DialogResult.No)
                        {
                            Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.TOOL_ID].Value = "";
                            Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.USE_COUNT].Value = 0;
                        }
                        else
                        {
                            sResID = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.RES_ID].Text;
                            sToolID = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.TOOL_ID].Text;

                            if (MPCF.ToInt(Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.MOLD_TYPE_CODE].Text) > 0)
                            {
                                sCar = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.MOLD_TYPE_CODE].Text;
                                sTopBase = "";
                            }
                            else
                            {
                                sCar = "";
                                sTopBase = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.MOLD_TYPE_CODE].Text;
                            }

                            sToolComment = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.COMMENT].Text;

                            sCount = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.USE_COUNT].Text;

                            //설비에 투입처리
                            SaveToolInOut('1', sResID, sToolID, sCar, sTopBase, sToolComment, "");
                        }
                    }
                }
                else if (sType == "OUTPUT")
                {
                    if (MPCF.Trim(Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.TOOL_ID].Text) != "")
                    {
                        //진짜 삭제처리 할지 물어본다.
                        //CMN541 INFO -  금형을 정말 탈착 하시겠습니까?
                        if (MPCF.ShowMsgBox(MPCF.GetMessage(541), MessageBoxButtons.YesNo, 1) == DialogResult.No)
                        {
                            return;
                        }
                        else
                        {
                            //sResID = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.RES_ID].Text;
                            sToolID = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.TOOL_ID].Text;
                            sToolComment = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.COMMENT].Text;
                            //설비에서 툴을 뺀다.
                            if (SaveToolInOut('2', sResID, sToolID, sCar, sTopBase, sToolComment, ""))
                            {
                                Sspread.ActiveSheet.SetValue(i_RowIndwx, (int)MOLD_INFO.TOOL_ID, "");
                                Sspread.ActiveSheet.SetValue(i_RowIndwx, (int)MOLD_INFO.USE_COUNT, 0);
                            }
                        }
                    }
                }
                else if (sType == "COMMENT_UPDATE")
                {

                    /*
                    if (MPCF.Trim(Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.TOOL_ID].Text) != "")
                    {

                        //sResID = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.RES_ID].Text;
                        sToolID = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.TOOL_ID].Text;
                        sToolComment = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.COMMENT].Text;

                        //설비에서 툴을 뺀다.
                        if (SaveToolInOut('3', sResID, sToolID, sCar, sTopBase, sToolComment,""))
                        {

                        }

                    }
                    */



                    sResID = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.RES_ID].Text;
                    sToolID = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.TOOL_ID].Text;
                    sToolComment = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.COMMENT].Text;
                    sMoldType = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.MOLD_TYPE].Text;


                    // 설비에도 COMMENT 저장
                    if (UpdateDataList(MPGC.MP_STEP_UPDATE, sResID, sMoldType, sToolComment))
                    {
                        if (MPCF.Trim(Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.TOOL_ID].Text) != "")
                        {
                            //TOOL ID COMMENT 저장.
                            if (SaveToolInOut('4', sResID, sToolID, sCar, sTopBase, sToolComment, sToolComment))
                            {

                            }
                        }

                    }

                }
                else if (sType == "VIEW_LOT_ID")
                {
                    if (MPCF.Trim(Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.TOOL_ID].Text) != "")
                    {

                        frmViewMoldStatus popup = new frmViewMoldStatus();
                        popup.StartPosition = FormStartPosition.CenterParent;
                        popup.WindowState = FormWindowState.Maximized;
                        popup.g_Popup_yn = "Y";
                        popup.g_Tool_id = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.TOOL_ID].Text;

                        chkAutoRefresh.Checked = false;


                        if (popup.ShowDialog() == DialogResult.OK)
                        {
                            popup = null;
                        }



                    }

                }
                else if (sType == "USE_COUNT_UPDATE")
                {
                    if (MPCF.Trim(Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.TOOL_ID].Text) != "")
                    {

                        //sResID = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.RES_ID].Text;
                        sToolID = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.TOOL_ID].Text;
                        sToolComment = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.COMMENT].Text;
                        sCount = Sspread.ActiveSheet.Cells[i_RowIndwx, (int)MOLD_INFO.USE_COUNT].Text;
                        //설비에서 툴을 뺀다.
                        if (SaveToolInOut('4', sResID, sToolID, sCar, sTopBase, sToolComment, sCount))
                        {

                        }
                    }

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }




        private bool UpdateDataList(char ProcStep, string sResID, string sType, string sComment)
        {
            // int i = 0;
            TRSNode in_node = new TRSNode("UPDATE_DATA_LIST_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");
            TRSNode node;


            MPCR.SetInMsg(in_node);
            in_node.ProcStep = ProcStep;
            in_node.AddString("TABLE_NAME", "C_PRESS_RES_COMMENT");
            //in_node.AddString("TABLE_PASSWORD", MPCF.Trim(txtPwd.Text).ToUpper(), true);



            node = in_node.AddNode("DATA_LIST");

            node.AddString("KEY_1", sResID);
            node.AddString("KEY_2", sType);
            node.AddString("KEY_3", "");
            node.AddString("KEY_4", "");
            node.AddString("KEY_5", "");
            node.AddString("KEY_6", "");
            node.AddString("KEY_7", "");
            node.AddString("KEY_8", "");
            node.AddString("KEY_9", "");
            node.AddString("KEY_10", "");

            node.AddString("DATA_1", sComment);
            node.AddString("DATA_2", "");
            node.AddString("DATA_3", "");
            node.AddString("DATA_4", "");
            node.AddString("DATA_5", "");
            node.AddString("DATA_6", "");
            node.AddString("DATA_7", "");
            node.AddString("DATA_8", "");
            node.AddString("DATA_9", "");
            node.AddString("DATA_10", "");


            if (MPCR.CallService("BAS", "BAS_Update_Data_List", in_node, ref out_node) == false)
            {
                return false;
            }
            else
            {
                // MPCR.ShowSuccessMsg(out_node);
            }



            return true;
        }


        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

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
                MPCF.ClearList(spdToolList1);
                MPCF.ClearList(spdToolList2);
                MPCF.ClearList(spdToolList3);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmTranMoldInOutEventVAT_Load(object sender, EventArgs e)
        {
            try
            {

                if (g_Popup_yn == "Y")
                {

                    btnPopup.Visible = false;

                    columnHidden("Y");



                }
                else
                {
                    btnPopup.Visible = true;
                }
                ViewToolStatus();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        private void pnlStsCond3_Paint(object sender, PaintEventArgs e)
        {

        }

        private void numRefreshSec_ValueChanged(object sender, EventArgs e)
        {
            if (chkAutoRefresh.Checked == true)
            {
                tmrTimer.Interval = ((int)(numRefreshSec.Value)) * 1000;
                tmrTimer.Start();
            }
        }

        private void tmrTimer_Tick(object sender, EventArgs e)
        {
            ViewToolStatus();
        }

        private void chkAutoRefresh_CheckedChanged(object sender, EventArgs e)
        {
            if (chkAutoRefresh.Checked == true)
            {
                tmrTimer.Interval = ((int)(numRefreshSec.Value)) * 1000;
                tmrTimer.Start();
            }
            else
            {
                tmrTimer.Stop();

            }
        }



        private void frmTranMoldInOutEventVAT_KeyPress(object sender, KeyPressEventArgs e)

        {
            if (chkAutoRefresh.Checked == true)
            {
                tmrTimer.Stop();
                tmrTimer.Interval = ((int)(numRefreshSec.Value)) * 1000;
                tmrTimer.Start();
            }
        }

        private void btnPopup_Click(object sender, EventArgs e)
        {

            frmTranMoldInOutEventVAT popup = new frmTranMoldInOutEventVAT();
            popup.StartPosition = FormStartPosition.CenterParent;
            popup.WindowState = FormWindowState.Maximized;
            popup.g_Popup_yn = "Y";

            chkAutoRefresh.Checked = false;


            if (popup.ShowDialog() == DialogResult.OK)
            {

                popup = null;
                ViewToolStatus();
                chkAutoRefresh.Checked = true;
            }
            else
            {
                popup = null;
                ViewToolStatus();
                chkAutoRefresh.Checked = true;
            }


        }
        private void columnHidden(string shiddenYn)
        {

            if (shiddenYn == "Y")
            {

                spdToolList1.ActiveSheet.Columns[(int)MOLD_INFO.AREA_ID].Visible = false;
                spdToolList1.ActiveSheet.Columns[(int)MOLD_INFO.AREA_DESC].Visible = false;
                spdToolList1.ActiveSheet.Columns[(int)MOLD_INFO.PRESS_TYPE].Visible = false;
                spdToolList1.ActiveSheet.Columns[(int)MOLD_INFO.HOGI].Visible = false;
                spdToolList1.ActiveSheet.Columns[(int)MOLD_INFO.RES_ID].Visible = false;
                spdToolList1.ActiveSheet.Columns[(int)MOLD_INFO.MOLD_TYPE_CODE].Visible = false;

                spdToolList1.ActiveSheet.Columns[(int)MOLD_INFO.TOOL_ID_BTN].Visible = false;
                spdToolList1.ActiveSheet.Columns[(int)MOLD_INFO.USE_COUNT_BTN].Visible = false;
                spdToolList1.ActiveSheet.Columns[(int)MOLD_INFO.INPUT_BTN].Visible = false;
                spdToolList1.ActiveSheet.Columns[(int)MOLD_INFO.OUTPUT_BTN].Visible = false;
                spdToolList1.ActiveSheet.Columns[(int)MOLD_INFO.COMMENT_BTN].Visible = false;


                spdToolList2.ActiveSheet.Columns[(int)MOLD_INFO.AREA_ID].Visible = false;
                spdToolList2.ActiveSheet.Columns[(int)MOLD_INFO.AREA_DESC].Visible = false;
                spdToolList2.ActiveSheet.Columns[(int)MOLD_INFO.PRESS_TYPE].Visible = false;
                spdToolList2.ActiveSheet.Columns[(int)MOLD_INFO.HOGI].Visible = false;
                spdToolList2.ActiveSheet.Columns[(int)MOLD_INFO.RES_ID].Visible = false;
                spdToolList2.ActiveSheet.Columns[(int)MOLD_INFO.MOLD_TYPE_CODE].Visible = false;

                spdToolList2.ActiveSheet.Columns[(int)MOLD_INFO.TOOL_ID_BTN].Visible = false;
                spdToolList2.ActiveSheet.Columns[(int)MOLD_INFO.USE_COUNT_BTN].Visible = false;
                spdToolList2.ActiveSheet.Columns[(int)MOLD_INFO.INPUT_BTN].Visible = false;
                spdToolList2.ActiveSheet.Columns[(int)MOLD_INFO.OUTPUT_BTN].Visible = false;
                spdToolList2.ActiveSheet.Columns[(int)MOLD_INFO.COMMENT_BTN].Visible = false;


                spdToolList3.ActiveSheet.Columns[(int)MOLD_INFO.AREA_ID].Visible = false;
                spdToolList3.ActiveSheet.Columns[(int)MOLD_INFO.AREA_DESC].Visible = false;
                spdToolList3.ActiveSheet.Columns[(int)MOLD_INFO.PRESS_TYPE].Visible = false;
                spdToolList3.ActiveSheet.Columns[(int)MOLD_INFO.HOGI].Visible = false;
                spdToolList3.ActiveSheet.Columns[(int)MOLD_INFO.RES_ID].Visible = false;
                spdToolList3.ActiveSheet.Columns[(int)MOLD_INFO.MOLD_TYPE_CODE].Visible = false;

                spdToolList3.ActiveSheet.Columns[(int)MOLD_INFO.TOOL_ID_BTN].Visible = false;
                spdToolList3.ActiveSheet.Columns[(int)MOLD_INFO.USE_COUNT_BTN].Visible = false;
                spdToolList3.ActiveSheet.Columns[(int)MOLD_INFO.INPUT_BTN].Visible = false;
                spdToolList3.ActiveSheet.Columns[(int)MOLD_INFO.OUTPUT_BTN].Visible = false;
                spdToolList3.ActiveSheet.Columns[(int)MOLD_INFO.COMMENT_BTN].Visible = false;


                spdToolList4.ActiveSheet.Columns[(int)MOLD_INFO.AREA_ID].Visible = false;
                spdToolList4.ActiveSheet.Columns[(int)MOLD_INFO.AREA_DESC].Visible = false;
                spdToolList4.ActiveSheet.Columns[(int)MOLD_INFO.PRESS_TYPE].Visible = false;
                spdToolList4.ActiveSheet.Columns[(int)MOLD_INFO.HOGI].Visible = false;
                spdToolList4.ActiveSheet.Columns[(int)MOLD_INFO.RES_ID].Visible = false;
                spdToolList4.ActiveSheet.Columns[(int)MOLD_INFO.MOLD_TYPE_CODE].Visible = false;

                spdToolList4.ActiveSheet.Columns[(int)MOLD_INFO.TOOL_ID_BTN].Visible = false;
                spdToolList4.ActiveSheet.Columns[(int)MOLD_INFO.USE_COUNT_BTN].Visible = false;
                spdToolList4.ActiveSheet.Columns[(int)MOLD_INFO.INPUT_BTN].Visible = false;
                spdToolList4.ActiveSheet.Columns[(int)MOLD_INFO.OUTPUT_BTN].Visible = false;
                spdToolList4.ActiveSheet.Columns[(int)MOLD_INFO.COMMENT_BTN].Visible = false;

            }


        }

        private void spdToolList1_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                    return;

                if (e.Column == (int)MOLD_INFO.INPUT_BTN)
                {
                    if (MPCF.Trim(spdToolList1.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) != "")
                    {
                        //CMN542 INFO -  이미 금형이 장착되어 있습니다. 탈착 후 장착하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(542));
                        return;
                    }

                    SaveToolEvn(spdToolList1, "INPUT", e.Row);
                }
                else if (e.Column == (int)MOLD_INFO.OUTPUT_BTN)
                {
                    if (MPCF.Trim(spdToolList1.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) == "")
                    {
                        //CMN543 INFO -  이미 금형이 탈착되어 있습니다. 금형 장착 여부를 확인하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(543));
                        return;
                    }

                    SaveToolEvn(spdToolList1, "OUTPUT", e.Row);
                }
                else if (e.Column == (int)MOLD_INFO.COMMENT_BTN)
                {
                    if (MPCF.Trim(spdToolList1.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) == "")
                    {
                        //CMN543 INFO -  이미 금형이 탈착되어 있습니다. 금형 장착 여부를 확인하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(543));
                        return;
                    }

                    SaveToolEvn(spdToolList1, "COMMENT_UPDATE", e.Row);
                }
                else if (e.Column == (int)MOLD_INFO.TOOL_ID_BTN)
                {
                    if (MPCF.Trim(spdToolList1.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) == "")
                    {
                        //CMN543 INFO -  이미 금형이 탈착되어 있습니다. 금형 장착 여부를 확인하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(543));
                        return;
                    }
                    SaveToolEvn(spdToolList1, "VIEW_LOT_ID", e.Row);
                }
                else if (e.Column == (int)MOLD_INFO.USE_COUNT_BTN)
                {
                    if (MPCF.Trim(spdToolList1.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) == "")
                    {
                        //CMN543 INFO -  이미 금형이 탈착되어 있습니다. 금형 장착 여부를 확인하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(543));
                        return;
                    }

                    if (MPCF.ShowMsgBox(MPCF.GetMessage(565), MessageBoxButtons.YesNo, 1) == DialogResult.No)
                    {
                        return;
                    }


                    SaveToolEvn(spdToolList1, "USE_COUNT_UPDATE", e.Row);
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdToolList2_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                    return;

                if (e.Column == (int)MOLD_INFO.INPUT_BTN)
                {
                    if (MPCF.Trim(spdToolList2.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) != "")
                    {
                        //CMN542 INFO -  이미 금형이 장착되어 있습니다. 탈착 후 장착하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(542));
                        return;
                    }

                    SaveToolEvn(spdToolList2, "INPUT", e.Row);
                }
                else if (e.Column == (int)MOLD_INFO.OUTPUT_BTN)
                {
                    if (MPCF.Trim(spdToolList2.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) == "")
                    {
                        //CMN543 INFO -  이미 금형이 탈착되어 있습니다. 금형 장착 여부를 확인하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(543));
                        return;
                    }

                    SaveToolEvn(spdToolList2, "OUTPUT", e.Row);
                }
                else if (e.Column == (int)MOLD_INFO.COMMENT_BTN)
                {
                    if (MPCF.Trim(spdToolList2.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) == "")
                    {
                        //CMN543 INFO -  이미 금형이 탈착되어 있습니다. 금형 장착 여부를 확인하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(543));
                        return;
                    }

                    SaveToolEvn(spdToolList2, "COMMENT_UPDATE", e.Row);
                }
                else if (e.Column == (int)MOLD_INFO.TOOL_ID_BTN)
                {
                    if (MPCF.Trim(spdToolList2.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) == "")
                    {
                        //CMN543 INFO -  이미 금형이 탈착되어 있습니다. 금형 장착 여부를 확인하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(543));
                        return;
                    }
                    SaveToolEvn(spdToolList2, "VIEW_LOT_ID", e.Row);
                }
                else if (e.Column == (int)MOLD_INFO.USE_COUNT_BTN)
                {
                    if (MPCF.Trim(spdToolList2.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) == "")
                    {
                        //CMN543 INFO -  이미 금형이 탈착되어 있습니다. 금형 장착 여부를 확인하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(543));
                        return;
                    }

                    if (MPCF.ShowMsgBox(MPCF.GetMessage(565), MessageBoxButtons.YesNo, 1) == DialogResult.No)
                    {
                        return;
                    }


                    SaveToolEvn(spdToolList2, "USE_COUNT_UPDATE", e.Row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdToolList3_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                    return;

                if (e.Column == (int)MOLD_INFO.INPUT_BTN)
                {
                    if (MPCF.Trim(spdToolList3.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) != "")
                    {
                        //CMN542 INFO -  이미 금형이 장착되어 있습니다. 탈착 후 장착하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(542));
                        return;
                    }

                    SaveToolEvn(spdToolList3, "INPUT", e.Row);
                }
                else if (e.Column == (int)MOLD_INFO.OUTPUT_BTN)
                {
                    if (MPCF.Trim(spdToolList3.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) == "")
                    {
                        //CMN543 INFO -  이미 금형이 탈착되어 있습니다. 금형 장착 여부를 확인하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(543));
                        return;
                    }

                    SaveToolEvn(spdToolList3, "OUTPUT", e.Row);
                }
                else if (e.Column == (int)MOLD_INFO.COMMENT_BTN)
                {
                    if (MPCF.Trim(spdToolList3.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) == "")
                    {
                        //CMN543 INFO -  이미 금형이 탈착되어 있습니다. 금형 장착 여부를 확인하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(543));
                        return;
                    }

                    SaveToolEvn(spdToolList3, "COMMENT_UPDATE", e.Row);
                }
                else if (e.Column == (int)MOLD_INFO.TOOL_ID_BTN)
                {
                    if (MPCF.Trim(spdToolList3.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) == "")
                    {
                        //CMN543 INFO -  이미 금형이 탈착되어 있습니다. 금형 장착 여부를 확인하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(543));
                        return;
                    }
                    SaveToolEvn(spdToolList3, "VIEW_LOT_ID", e.Row);
                }
                else if (e.Column == (int)MOLD_INFO.USE_COUNT_BTN)
                {
                    if (MPCF.Trim(spdToolList3.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) == "")
                    {
                        //CMN543 INFO -  이미 금형이 탈착되어 있습니다. 금형 장착 여부를 확인하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(543));
                        return;
                    }

                    if (MPCF.ShowMsgBox(MPCF.GetMessage(565), MessageBoxButtons.YesNo, 1) == DialogResult.No)
                    {
                        return;
                    }


                    SaveToolEvn(spdToolList3, "USE_COUNT_UPDATE", e.Row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdToolList4_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                    return;

                if (e.Column == (int)MOLD_INFO.INPUT_BTN)
                {
                    if (MPCF.Trim(spdToolList4.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) != "")
                    {
                        //CMN542 INFO -  이미 금형이 장착되어 있습니다. 탈착 후 장착하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(542));
                        return;
                    }

                    SaveToolEvn(spdToolList4, "INPUT", e.Row);
                }
                else if (e.Column == (int)MOLD_INFO.OUTPUT_BTN)
                {
                    if (MPCF.Trim(spdToolList4.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) == "")
                    {
                        //CMN543 INFO -  이미 금형이 탈착되어 있습니다. 금형 장착 여부를 확인하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(543));
                        return;
                    }

                    SaveToolEvn(spdToolList4, "OUTPUT", e.Row);
                }
                else if (e.Column == (int)MOLD_INFO.COMMENT_BTN)
                {
                    if (MPCF.Trim(spdToolList4.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) == "")
                    {
                        //CMN543 INFO -  이미 금형이 탈착되어 있습니다. 금형 장착 여부를 확인하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(543));
                        return;
                    }

                    SaveToolEvn(spdToolList4, "COMMENT_UPDATE", e.Row);
                }
                else if (e.Column == (int)MOLD_INFO.TOOL_ID_BTN)
                {
                    if (MPCF.Trim(spdToolList4.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) == "")
                    {
                        //CMN543 INFO -  이미 금형이 탈착되어 있습니다. 금형 장착 여부를 확인하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(543));
                        return;
                    }
                    SaveToolEvn(spdToolList4, "VIEW_LOT_ID", e.Row);
                }
                else if (e.Column == (int)MOLD_INFO.USE_COUNT_BTN)
                {
                    if (MPCF.Trim(spdToolList4.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.TOOL_ID].Text) == "")
                    {
                        //CMN543 INFO -  이미 금형이 탈착되어 있습니다. 금형 장착 여부를 확인하세요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(543));
                        return;
                    }

                    if (MPCF.ShowMsgBox(MPCF.GetMessage(565), MessageBoxButtons.YesNo, 1) == DialogResult.No)
                    {
                        return;
                    }


                    SaveToolEvn(spdToolList4, "USE_COUNT_UPDATE", e.Row);
                }
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

        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }






        #endregion

    }
}
