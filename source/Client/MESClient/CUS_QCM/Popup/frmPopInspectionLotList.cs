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
using static CUS_COM.CSGC;
using System.Runtime.Remoting.Metadata.W3cXsd2001;
using System.Xml.Linq;

namespace CUS_QCM
{
    public partial class frmPopInspectionLotList : CUS_COM.frmTranForm06
    {
        public frmPopInspectionLotList()
        {
            InitializeComponent();

            InitControl();
        }


        #region " Constant Definition "
        private enum LOT_INFO
        {
            INSP_REQ_TIME,
            LOT_ID,
            QTY,
            ORDER_ID,
            MAT_ID,
            MAT_DESC,
            GRADE,
            SIZE,
            VENDOR_LOT_ID,
            INSP_ID,
            INSP_STATUS,
            INSP_OPER,
            JUDGE,
            PASS_BUTTON,
            FAIL_BUTTON,
            SPECIAL_BUTTON,
            RETRUN_BUTTON,
            INSP_OPER_DESC,
            DLV_LOT_STATUS,
        }
        #endregion

        #region " Variable Definition "
        public string sArea_id = "";
        public string sArea_desc = "";
        public string sSub_area_id = "";
        public string sSub_area_desc = "";
        public string sOper_id = "";
        public string sOper_desc = "";
        public string sLot_id = "";
        public string sMatType = "";
        public string sMatType_desc = "";
        public string sMatId = "";
        public string sMat_Desc = "";
        #endregion


        #region " Function Definition "
        private void InitControl()
        {
            try
            {
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        //20220407 제거
                        /*
                        if (MPCF.Trim(cdvDept.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
                            return false;
                        }
                        */

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
        private bool viewOperList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            in_node.AddString("SQL", "SELECT OPER AS CODE, "
                                               + "               OPER_DESC AS NAME "
                                               + "         FROM MWIPOPRDEF "
                                               + "        WHERE AREA_ID = '" + cdvDept.Text + "' "
                                               + "          AND OPER_GRP_2 <> 'NONE' "
                                               + "         AND OPER_GRP_2 > ' ' "
                                               + "        ORDER BY OPER");

            /*
            if (MPCF.Trim(cdvWorkPlace.Text) == "")
            {
                //IQC
                in_node.AddString("SQL", "SELECT OPER AS CODE, "
                                               + "               OPER_DESC AS NAME "
                                               + "         FROM MWIPOPRDEF "
                                               + "        WHERE AREA_ID = '" + cdvDept.Text + "' "
                                               + "          AND OPER_GRP_2 = 'IQC' "
                                               + "        ORDER BY OPER");
            }
            else
            {
                in_node.AddString("SQL", "SELECT CODE, "
                                                   + "              NAME "
                                                   + "         FROM "
                                                   + "        (SELECT OPER AS CODE, "
                                                   + "                OPER_DESC AS NAME "
                                                   + "           FROM MWIPOPRDEF "
                                                   + "         WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                                   + "            AND AREA_ID = '" + cdvDept.Text + "' "
                                                   + "            AND OPER_GRP_1 = 'INSP' "
                                                   + "            AND OPER_GRP_2 = 'IQC' "
                                                   + "  UNION ALL  "
                                                   + "     SELECT OPER AS CODE, "
                                                   + "               OPER_DESC AS NAME "
                                                   + "             FROM MWIPOPRDEF "
                                                   + "            WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                                   + "              AND AREA_ID = '" + cdvDept.Text + "' "
                                                   + "              AND SUB_AREA_ID = '" + cdvWorkPlace.Text + "' "
                                                   + "              AND OPER_GRP_2 <> 'NONE' "
                                                   + "             AND OPER_GRP_2 > ' ') "
                                                   + "      ORDER BY CODE");
            }
            */



            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCR.FillDataView(listView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);

            return true;
        }
        private bool viewInspStatusList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';


            in_node.AddString("SQL", "SELECT KEY_1 AS CODE, "
                                                + "   DATA_1 AS VALUE "
                                              + " FROM MGCMTBLDAT "
                                            + " WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                            + "  AND TABLE_NAME = '" + CSGC.CP_GCM_INSP_STATUS + "' "
                                            + "  AND KEY_1 != 'C' "
                                            + " ORDER BY DATA_3");


            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCR.FillDataView(listView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);



            return true;
        }
        private void ViewLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[10];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                dvcArgu[2].sCondition_ID = "FROM_DATE";
                dvcArgu[2].sCondition_Value = dtpFromDate.Text.Replace("-", "") + "000000";

                dvcArgu[3].sCondition_ID = "TO_DATE";
                dvcArgu[3].sCondition_Value = dtpToDate.Text.Replace("-", "") + "000000";

                dvcArgu[4].sCondition_ID = "INSP_STATUS";
                dvcArgu[4].sCondition_Value = cdvStatus.Text + "%";

                dvcArgu[5].sCondition_ID = "MAT_ID";
                dvcArgu[5].sCondition_Value = txtMatID.Text + "%";

                dvcArgu[6].sCondition_ID = "MAT_DESC";
                dvcArgu[6].sCondition_Value = "%" + txtMatDesc.Text + "%";


                dvcArgu[7].sCondition_ID = "AREA_ID";
                dvcArgu[7].sCondition_Value = "%" + cdvDept.Text + "%";

                dvcArgu[8].sCondition_ID = "MAT_TYPE";
                dvcArgu[8].sCondition_Value = "%" + cdvMatType.Text + "%";


                dvcArgu[9].sCondition_ID = "LOT_ID";
                dvcArgu[9].sCondition_Value = "%" + txtLotId.Text + "%";


                if (TPDR.GetDataOne("", ref dt, "CQCM3001-003", dvcArgu, false, false, ref sSql) == false)
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
                    spdLotList_Sheet1.RowCount++;

                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.INSP_ID].Value = dt.Rows[i]["INSP_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.INSP_REQ_TIME].Value = dt.Rows[i]["INSP_REQ_TIME"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.INSP_STATUS].Value = dt.Rows[i]["INSP_STATUS"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.JUDGE].Value = dt.Rows[i]["JUDGE"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.INSP_OPER].Value = dt.Rows[i]["INSP_OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.INSP_OPER_DESC].Value = dt.Rows[i]["INSP_OPER_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.DLV_LOT_STATUS].Value = dt.Rows[i]["DLV_LOT_STATUS"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.SIZE].Value = dt.Rows[i]["SIZES"];

                }

                // MPCF.FitColumnHeader(spdLotList);

                //OC04091
                if (cdvOper.Text.Contains("IQC")) //수입검사
                {
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.PASS_BUTTON].Visible = true;
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.FAIL_BUTTON].Visible = true;
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.SPECIAL_BUTTON].Visible = true;
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.RETRUN_BUTTON].Visible = true;
                }
                else if (cdvOper.Text == "OC04091")  //C-SCAN검사
                {
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.PASS_BUTTON].Visible = true;
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.FAIL_BUTTON].Visible = false;
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.SPECIAL_BUTTON].Visible = false;
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.RETRUN_BUTTON].Visible = false;
                }
                else
                {
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.PASS_BUTTON].Visible = false;
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.FAIL_BUTTON].Visible = false;
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.SPECIAL_BUTTON].Visible = false;
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.RETRUN_BUTTON].Visible = false;
                }

                if (cdvOper.Text == "OG05260") //GRT 샘플검사일때만 GRADE/SIZE 보이게
                {
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.MAT_ID].Visible = false;
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.GRADE].Visible = true;
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.SIZE].Visible = true;
                }
                else
                {
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.MAT_ID].Visible = true;
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.GRADE].Visible = false;
                    spdLotList_Sheet1.Columns[(int)LOT_INFO.SIZE].Visible = false;
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void SaveIQcPass(string sInspStatus, string sInspResult)
        {        // 서버개발 라이센스 지금 없어서 걍 DB FUnction으로 Update침(f_iqc_pass)
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";



                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_ID";
                dvcArgu[1].sCondition_Value = spdLotList_Sheet1.Cells[spdLotList_Sheet1.ActiveRowIndex, (int)LOT_INFO.INSP_ID].Text;

                dvcArgu[2].sCondition_ID = "LOT_ID";
                dvcArgu[2].sCondition_Value = spdLotList_Sheet1.Cells[spdLotList_Sheet1.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text;

                dvcArgu[3].sCondition_ID = "USER_ID";
                dvcArgu[3].sCondition_Value = MPGV.gsUserID;

                dvcArgu[4].sCondition_ID = "COMMENT";
                dvcArgu[4].sCondition_Value = "Manual Non inspection";

                dvcArgu[5].sCondition_ID = "INSP_STATUS";
                dvcArgu[5].sCondition_Value = sInspStatus;

                dvcArgu[6].sCondition_ID = "INSP_RESULT_FLAG";
                dvcArgu[6].sCondition_Value = sInspResult;


                if (TPDR.GetDataOne("", ref dt, "CQCM3001-009", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }



                //CMN052 INFO - 작업을 성공적으로 수행하였습니다.
                MPCF.ShowMsgBox(MPCF.GetMessage(52));
                ViewLotList();
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private bool Inspection_Judge(string sLotID)
        {


            TRSNode in_node = new TRSNode("INSPECTION_JUDGE_IN");
            TRSNode out_node = new TRSNode("INSPECTION_JUDGE_OUT");


            string sColSetId = "";
            string sFlow = "";
            string sInspId = "";
            int sColSetVersion = 0;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                //INSP_ID, LOT_ID, INSP_JUDGE_FLAG, REWORK_OPER, INSP_COMMENT
                //  sLotID = spdLotList.ActiveSheet.GetValue(iRow, (int)LOT_INFO.LOT_ID).ToString();




                ViewColsetIdCheck(sLotID, ref sColSetId, ref sColSetVersion, ref sFlow, ref sInspId);
                if (sColSetId.Length == 0)
                {
                    return false;
                }


                in_node.AddString("INSP_ID", sInspId);   //검사 ID
                in_node.AddString("LOT_ID", sLotID);  // LOT_ID
                in_node.AddString("COL_SET_ID", sColSetId); //COL SET ID
                in_node.AddInt("COL_SET_VERSION", sColSetVersion);
                in_node.AddChar("INSP_JUDGE_FLAG", "P");
                in_node.AddString("TO_FLOW", sFlow);


                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Inspection_Judge", in_node, ref out_node, false) == false)
                {
                    return false;
                }
                else
                {
                    MPCR.ShowSuccessMsg(out_node);
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }
        private void ViewColsetIdCheck(string sLotId, ref string sColSetId, ref int sColSetVersion, ref string sFlow, ref string sInspId)
        {
            string sMatId = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                dvcArgu[2].sCondition_ID = "LOT_ID";
                dvcArgu[2].sCondition_Value = sLotId;

                if (TPDR.GetDataOne("", ref dt, "CQCM0001-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                if (dt.Rows[0]["COL_SET_ID"].ToString() == "X")
                {

                    //CMN563 INFO - 등록된  CollectionSet이 없습니다. 등록 진행하시겠습니까?
                    if (MPCF.ShowMsgBox(MPCF.GetMessage(563), MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.Yes)
                    {


                        //고정COL_SET_ID 있으면_자동등록으로 바꿈_20250318 syw
                        if (dt.Rows[0]["A_COL_SET_ID"].ToString().Trim() != "")
                        {


                            sMatId = dt.Rows[0]["MAT_ID"].ToString();
                            sColSetId = dt.Rows[0]["A_COL_SET_ID"].ToString().Trim();
                            sColSetVersion = 1;
                            sFlow = dt.Rows[0]["FLOW"].ToString().Trim();
                            sInspId = dt.Rows[0]["INSP_ID"].ToString().Trim();

                            if (Update_MFO_ColSet_List(sMatId, sColSetId) != false)
                            {
                                //CMN556 INFO - 등록된  CollectionSet이 없어서 자동으로 가능한 CollectionSet 등록하였습니다.
                                MPCF.ShowMsgBox(MPCF.GetMessage(556));
                            }
                            else
                            {
                                sColSetId = "";
                                sColSetVersion = 0;
                                sFlow = "";
                                sInspId = "";
                            }


                        }
                        else
                        {

                            frmPopCollectionSetOper popup = new frmPopCollectionSetOper();
                            //popup.StartPosition = frmPopCollectionSetOper.CenterParent;

                            popup.sArea_id = cdvDept.Text;
                            popup.sArea_desc = cdvDept.DisplayText;
                            popup.sOper_id = cdvOper.Text;
                            popup.sOper_desc = cdvOper.DisplayText;
                            popup.sMat_id = dt.Rows[0]["MAT_ID"].ToString();
                            popup.sMat_desc = dt.Rows[0]["MAT_DESC"].ToString();



                            if (popup.ShowDialog() == DialogResult.OK)
                            {
                                popup = null;
                            }
                            else
                            {

                            }
                        }



                    }



                }
                else
                {

                    sColSetId = dt.Rows[0]["COL_SET_ID"].ToString();
                    sColSetVersion = 1;
                    sFlow = dt.Rows[0]["FLOW"].ToString().Trim();
                    sInspId = dt.Rows[0]["INSP_ID"].ToString().Trim();

                }




                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        private bool Update_MFO_ColSet_List(string sMatId, string sColSetId)
        {

            TRSNode in_node = new TRSNode("UPDATE_MFO_COLSET_LIST_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");
            TRSNode list_item;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = MPGC.MP_STEP_UPDATE;
                in_node.AddChar("OPT_LEVEL", '4');

                list_item = in_node.AddNode("COLSET_LIST");
                list_item.AddString("MAT_ID", MPCF.Trim(sMatId));
                list_item.AddInt("MAT_VER", 1);
                list_item.AddChar("COLLECTION_MODE", 'M');



                list_item.AddString("OPER", MPCF.Trim(cdvOper.Text));
                //list_item.AddString("COL_SET_ID", MPCF.Trim(cdvColSetID.Text));
                list_item.AddString("COL_SET_ID", sColSetId);
                list_item.AddChar("DEFAULT_FLAG", 'N');
                list_item.AddChar("DISABLE_FLAG", 'N');


                if (MPCR.CallService("EDC", "EDC_Update_MFO_ColSet_List", in_node, ref out_node) == false)
                {
                    return false;
                }

                // MPCR.ShowSuccessMsg(out_node);


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
        private void cdvStatus_ButtonPress(object sender, EventArgs e)
        {
            viewInspStatusList(cdvStatus.GetListView);
            cdvStatus.InsertEmptyRow(0, 1);
        }
        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvOper.Text = "";
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
                cdvOper.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvOper_ButtonPress(object sender, EventArgs e)
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

                viewOperList(cdvOper.GetListView);

                cdvOper.InsertEmptyRow(0, 1);
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

                ViewLotList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnProcess_Click(object sender, EventArgs e)
        {
            if (spdLotList.ActiveSheet.ActiveRowIndex < 0)
                return;


            try
            {
                int iRow = spdLotList.ActiveSheet.ActiveRowIndex;

                sLot_id = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.LOT_ID].Text;
                sOper_id = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.INSP_OPER].Text;
                sOper_desc = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.INSP_OPER_DESC].Text;
                sMatId = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_ID].Text;
                sMat_Desc = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_DESC].Text;

                this.DialogResult = DialogResult.OK;

                this.Close();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void frmPopInspectionLotList_Load(object sender, EventArgs e)
        {

            cdvDept.Text = sArea_id;
            cdvDept.DisplayText = sArea_desc;
            //cdvWorkPlace.Text = sSub_area_id;
            // cdvWorkPlace.DisplayText = sSub_area_desc;
            cdvOper.Text = sOper_id;
            cdvOper.DisplayText = sOper_desc;
            cdvMatType.Text = sMatType;
            cdvMatType.DisplayText = sMatType;
            cdvMatType.DisplayText = sMatType_desc;
            this.dtpToDate.Value = DateTime.Now;
            this.dtpFromDate.Value = dtpToDate.Value.AddDays(-3);

        }
        private void spdLotList_DoubleClick(object sender, EventArgs e)
        {
            if (spdLotList.ActiveSheet.ActiveRowIndex < 0)
                return;


            try
            {
                int iRow = spdLotList.ActiveSheet.ActiveRowIndex;

                sLot_id = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.LOT_ID].Text;
                sOper_id = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.INSP_OPER].Text;
                sOper_desc = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.INSP_OPER_DESC].Text;
                sMatId = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_ID].Text;
                sMat_Desc = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_DESC].Text;

                this.DialogResult = DialogResult.OK;

                this.Close();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }



        }
        private void spdLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {


            string sInspStatus = "";
            string sInspResult = "";

            if (spdLotList.ActiveSheet.ActiveRowIndex < 0)
                return;
            if (e.Column == (int)LOT_INFO.PASS_BUTTON || e.Column == (int)LOT_INFO.FAIL_BUTTON || e.Column == (int)LOT_INFO.SPECIAL_BUTTON || e.Column == (int)LOT_INFO.RETRUN_BUTTON)
            {

                //수입검사랑,C-SCAN 검사공정만 판정할수 있음.
                if (spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.INSP_OPER].Text.Contains("IQC") == false && cdvOper.Text != "OC04091")
                {
                    //CMN559 INFO - 수입검사 LOT만 처리가능합니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(559));
                    return;

                }


                if (spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.INSP_OPER].Text.Contains("IQC"))
                {



                    switch (e.Column)
                    {
                        case (int)LOT_INFO.PASS_BUTTON:
                        case (int)LOT_INFO.FAIL_BUTTON:
                        case (int)LOT_INFO.SPECIAL_BUTTON:
                            if (spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.JUDGE].Text.Trim() != "")
                            {
                                //CMN567 INFO -판정을 변경하시겠습니까?
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(567), MessageBoxButtons.YesNo, 1) == System.Windows.Forms.DialogResult.No)
                                {
                                    return;
                                }
                            }
                            else
                            {
                                //CMN567 INFO -검사정보 등록없이 바로 판정하시겠습니까?
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(568), MessageBoxButtons.YesNo, 1) == System.Windows.Forms.DialogResult.No)
                                {
                                    return;
                                }
                            }
                            break;
                        case (int)LOT_INFO.RETRUN_BUTTON:
                            if (spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.JUDGE].Text.Trim() == "")
                            {
                                //판정안했으니 그냥 아무것도 안함.
                                return;
                            }
                            else
                            {
                                //CMN569 INFO -검사 판정을 취소하시겠습니까?
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(569), MessageBoxButtons.YesNo, 1) == System.Windows.Forms.DialogResult.No)
                                {
                                    return;
                                }
                            }
                            break;

                    }



                    if (spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.DLV_LOT_STATUS].Text == "COMPLETED")
                    {
                        //CMN367 ERROR -해당 입하 자재 LOT은 입고가 완료되었습니다.진행할 수 없습니다.
                        MPCF.ShowMsgBox(MPCF.GetMessage(367));
                        return;
                    }


                    if (e.Column == (int)LOT_INFO.PASS_BUTTON || e.Column == (int)LOT_INFO.FAIL_BUTTON || e.Column == (int)LOT_INFO.SPECIAL_BUTTON)
                    {

                    }

                    switch (e.Column)
                    {
                        case (int)LOT_INFO.PASS_BUTTON:
                            sInspStatus = "S";
                            sInspResult = "P";

                            break;
                        case (int)LOT_INFO.FAIL_BUTTON:
                            sInspStatus = "S";
                            sInspResult = "F";
                            break;
                        case (int)LOT_INFO.SPECIAL_BUTTON:
                            sInspStatus = "S";
                            sInspResult = "S";
                            break;
                        case (int)LOT_INFO.RETRUN_BUTTON:
                            sInspStatus = "R";
                            sInspResult = " ";
                            break;

                    }

                    SaveIQcPass(sInspStatus, sInspResult);

                }
                else if (cdvOper.Text == "OC04091")
                {
                    switch (e.Column)
                    {
                        case (int)LOT_INFO.PASS_BUTTON:
                            if (spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.JUDGE].Text.Trim() == "")
                            {
                                if (Inspection_Judge(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text) == true)
                                {  //베트남 전용 공정이기는 해서.. 그냥 영어로 밀어넣음. syw
                                    spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.INSP_STATUS].Text = "Done";
                                    spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.JUDGE].Text = "Pass";
                                }
                            }
                            break;
                    }



                }

            }

        }
        private void cdvMatType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvMatType.Init();
                MPCF.InitListView(cdvMatType.GetListView);
                cdvMatType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvMatType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvMatType.SelectedSubItemIndex = 0;
                cdvMatType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvMatType.GetListView, '1', MPGC.MP_WIP_MATERIAL_TYPE) == false)
                {
                    return;
                }

                cdvMatType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            MPCF.ClearList(spdLotList);
        }
        #endregion
    }
}
