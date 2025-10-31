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

namespace CUS_QCM
{
    public partial class frmPopCollectionSetOper : CUS_COM.frmTranForm06
    {
        public frmPopCollectionSetOper()
        {
            InitializeComponent();

            InitControl();
        }


        #region " Constant Definition "
        private enum SPEC_INFO
        {
            CHK,
            OPER,
            OPER_DESC,
            MAT_ID,
            MAT_DESC,
            COL_SET_ID,
            SPEC_REL_ID,
            SPEC_REL_VER,
            SPEC_YN,
            CHAR_ID,
            CHAR_DESC,
            SEQ_NUM,
            LOWER_SPEC_LIMIT,
            TARGET_VALUE,
            UPPER_SPEC_LIMIT

        }
        #endregion

        #region " Variable Definition "
        public string sArea_id = "";
        public string sArea_desc = "";
        public string sOper_id = "";
        public string sOper_desc = "";

        public string sMat_id = "";
        public string sMat_desc = "";
        #endregion

        #region " Function Definition "
        private void InitControl()
        {
            try
            {
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnUpdate.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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
        private bool viewCollectionSetList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            /*
            in_node.AddString("SQL", "SELECT OPER AS CODE, "
                                               + "               OPER_DESC AS NAME "
                                               + "         FROM MWIPOPRDEF "
                                               + "        WHERE AREA_ID = '" + cdvDept.Text + "' "
                                               + "          AND OPER_GRP_2 <> 'NONE' "
                                               + "         AND OPER_GRP_2 > ' ' "
                                               + "        ORDER BY OPER");

*/

            in_node.AddString("SQL", "SELECT  A.COL_SET_ID AS CODE   , A.COL_SET_DESC AS NAME   "
                                     + " FROM  MEDCCOLDEF A "
                                     + "   order by 1,2 ");




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
        //LOT ID 조회 함수
        private void ViewLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatId.Text;

                dvcArgu[3].sCondition_ID = "COL_SET_ID";
                dvcArgu[3].sCondition_Value = cdvColSetId.Text;



                if (TPDR.GetDataOne("", ref dt, "CQCM1004-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdSpecList);
                    return;
                }

                MPCF.ClearList(spdSpecList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdSpecList_Sheet1.RowCount++;


                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.COL_SET_ID].Value = dt.Rows[i]["COL_SET_ID"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.SPEC_REL_ID].Value = dt.Rows[i]["SPEC_REL_ID"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.SPEC_REL_VER].Value = dt.Rows[i]["SPEC_REL_VER"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.SPEC_YN].Value = dt.Rows[i]["SPEC_YN"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.CHAR_ID].Value = dt.Rows[i]["CHAR_ID"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.CHAR_DESC].Value = dt.Rows[i]["CHAR_DESC"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.SEQ_NUM].Value = dt.Rows[i]["SEQ_NUM"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.LOWER_SPEC_LIMIT].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.TARGET_VALUE].Value = dt.Rows[i]["TARGET_VALUE"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.UPPER_SPEC_LIMIT].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"];

                }


                txtColSetPresent.Text = dt.Rows[0]["COL_SET_PRESENT"].ToString();
                txtColSetPreName.Text = dt.Rows[0]["COL_SET_PRE_NAME"].ToString();

                // MPCF.FitColumnHeader(spdSpecList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void ViewLotList2()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatId.Text;


                if (TPDR.GetDataOne("", ref dt, "CQCM1004-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdSpecList);
                    return;
                }

                MPCF.ClearList(spdSpecList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdSpecList_Sheet1.RowCount++;


                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.COL_SET_ID].Value = dt.Rows[i]["COL_SET_ID"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.SPEC_REL_ID].Value = dt.Rows[i]["SPEC_REL_ID"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.SPEC_REL_VER].Value = dt.Rows[i]["SPEC_REL_VER"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.SPEC_YN].Value = dt.Rows[i]["SPEC_YN"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.CHAR_ID].Value = dt.Rows[i]["CHAR_ID"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.CHAR_DESC].Value = dt.Rows[i]["CHAR_DESC"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.SEQ_NUM].Value = dt.Rows[i]["SEQ_NUM"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.LOWER_SPEC_LIMIT].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.TARGET_VALUE].Value = dt.Rows[i]["TARGET_VALUE"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC_INFO.UPPER_SPEC_LIMIT].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"];

                }

                txtColSetPresent.Text = dt.Rows[0]["COL_SET_PRESENT"].ToString();
                txtColSetPreName.Text = dt.Rows[0]["COL_SET_PRE_NAME"].ToString();

                cdvColSetId.Text = dt.Rows[0]["COL_SET_PRESENT"].ToString();
                cdvColSetId.DisplayText = dt.Rows[0]["COL_SET_PRE_NAME"].ToString();

                // MPCF.FitColumnHeader(spdSpecList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private bool UpdateSpec(char c_step, int iRow)
        {
            TRSNode in_node = new TRSNode("UPDATE_SPEC_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = c_step;

            in_node.AddChar("REL_LEVEL", '4'); // 4번고정 제품-공정 (나중에 설비데이터 혹 스펙있다고 하면 그떄 분기나눌예정)
            in_node.AddString("MAT_ID", spdSpecList_Sheet1.Cells[iRow, (int)SPEC_INFO.MAT_ID].Text);
            in_node.AddInt("MAT_VER", 1);  // 일진 다이아는 품목버전 안올릴거임.필요없음.
            in_node.AddString("FLOW", "");
            in_node.AddString("OPER", spdSpecList_Sheet1.Cells[iRow, (int)SPEC_INFO.OPER].Text);




            // Spec Rel Version Tab
            if (c_step == MPGC.MP_STEP_CREATE)
            {
                //in_node.AddString("SPEC_REL_ID", spdSpecList_Sheet1.Cells[iRow, (int)SPEC_INFO.SPEC_REL_ID].Text);
                in_node.AddInt("SPEC_REL_VER", MPCF.ToInt('1'));
            }
            else
            {
                in_node.AddString("SPEC_REL_ID", spdSpecList_Sheet1.Cells[iRow, (int)SPEC_INFO.SPEC_REL_ID].Text);
                in_node.AddInt("SPEC_REL_VER", MPCF.ToInt(spdSpecList_Sheet1.Cells[iRow, (int)SPEC_INFO.SPEC_REL_VER].Text));
            }

            string s_datetime = MPCF.ToStandardTime(System.DateTime.Now, MPGC.MP_CONVERT_DATETIME_FORMAT).Substring(0, 14);
            in_node.AddString("APPLY_START_TIME", "");
            in_node.AddString("APPLY_END_TIME", "");
            in_node.AddChar("APPROVAL_FLAG", "Y");
            in_node.AddChar("RELEASE_FLAG", "Y");

            UpdateSpecSetLimitInfo(in_node, iRow);

            UpdateSpecSetAttribute(in_node);

            UpdateSpecSetAttachFile(in_node);


            if (MPCR.CallService("SPM", "SPM_Update_Spec", in_node, ref out_node) == false)
            {
                return false;
            }

            // MPCR.ShowSuccessMsg(out_node);
            return true;
        }
        private void UpdateSpecSetLimitInfo(TRSNode in_node, int iRow)
        {
            TRSNode list_item;

            //if (lisAssignedChar3.SelectedItems.Count <= 0) return;

            try
            {
                list_item = in_node.AddNode("LIMIT_LIST");
                //list_item.AddString("CHAR_ID", MPCF.Trim(lisAssignedChar3.SelectedItems[0].Text));
                list_item.AddString("CHAR_ID", spdSpecList_Sheet1.Cells[iRow, (int)SPEC_INFO.CHAR_ID].Text);
                list_item.AddChar("NO_UPDATE_ATTACH_OPTION_FLAG", 'Y');
                list_item.AddChar("SPEC_REF_TYPE", 'M'); // 제조스펙사용
                list_item.AddChar("SPEC_TYPE", 'B'); // 스펙상하안값 모두


                list_item.AddInt("SPEC_OUT_COUNT", MPCF.ToInt("0"));  //나중에 추가할 예정 스펙아웃 허용수
                list_item.AddString("SPEC_OUT_ALARM", MPCF.Trim("")); //나중에 추가할 예정 스펙아웃 알람
                list_item.AddString("WARN_OUT_ALARM", MPCF.Trim(""));  //나중에 추가할 예정 경고 발생시 알람



                list_item.AddString("TARGET_VALUE", MPCF.Trim(spdSpecList_Sheet1.Cells[iRow, (int)SPEC_INFO.TARGET_VALUE].Text));
                list_item.AddString("UPPER_SPEC_LIMIT", MPCF.Trim(spdSpecList_Sheet1.Cells[iRow, (int)SPEC_INFO.UPPER_SPEC_LIMIT].Text));
                list_item.AddString("LOWER_SPEC_LIMIT", MPCF.Trim(spdSpecList_Sheet1.Cells[iRow, (int)SPEC_INFO.LOWER_SPEC_LIMIT].Text));
                list_item.AddString("UPPER_WARN_LIMIT", MPCF.Trim("")); //나중에 추가할 예정 경고 발생 상한값
                list_item.AddString("LOWER_WARN_LIMIT", MPCF.Trim("")); //나중에 추가할 예정 경고 발생 하한값

                /*
                list_item.AddChar("CUST_SPEC_TYPE", 'B');
                */

                list_item.AddInt("CUST_SPEC_OUT_COUNT", MPCF.ToInt("")); //사용안함
                list_item.AddString("CUST_SPEC_OUT_ALARM", MPCF.Trim("")); //사용안함
                list_item.AddString("CUST_WARN_OUT_ALARM", MPCF.Trim("")); //사용안함

                list_item.AddString("CUST_TARGET_VALUE", MPCF.Trim(""));
                list_item.AddString("CUST_UPPER_SPEC_LIMIT", MPCF.Trim(""));
                list_item.AddString("CUST_LOWER_SPEC_LIMIT", MPCF.Trim(""));
                list_item.AddString("CUST_UPPER_WARN_LIMIT", MPCF.Trim(""));
                list_item.AddString("CUST_LOWER_WARN_LIMIT", MPCF.Trim(""));


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private bool UpdateSpecCharacter(char c_step, int iRow)
        {
            TRSNode in_node = new TRSNode("UPDATE_SPEC_CHARACTER_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = c_step;
                in_node.AddString("SPEC_REL_ID", MPCF.Trim(spdSpecList_Sheet1.Cells[iRow, (int)SPEC_INFO.SPEC_REL_ID].Text));
                in_node.AddInt("SPEC_REL_VER", MPCF.ToInt(MPCF.Trim(spdSpecList_Sheet1.Cells[iRow, (int)SPEC_INFO.SPEC_REL_VER].Text)));
                in_node.AddString("CHAR_ID", MPCF.Trim(spdSpecList_Sheet1.Cells[iRow, (int)SPEC_INFO.CHAR_ID].Text));

                if (MPCR.CallService("SPM", "SPM_Update_Spec_Character", in_node, ref out_node) == false)
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
        private void UpdateSpecSetAttribute(TRSNode in_node)
        {
            return;

        }
        private void UpdateSpecSetAttachFile(TRSNode in_node)
        {
            return;
        }
        private bool Update_MFO_ColSet_List(string sMatId, string sColSetId)
        {


            TRSNode in_node = new TRSNode("UPDATE_MFO_COLSET_LIST_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");
            TRSNode list_item;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = MPGC.MP_STEP_UPDATE;//MPGC.MP_STEP_DELETE;
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

                //  cdvColSetID.Text = "POQ00001";
                //  cdvColSetID.DisplayText = "POQ00001";

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

        }
        private bool Delete_MFO_ColSet_List(string sMatId, string sColSetId)
        {


            TRSNode in_node = new TRSNode("UPDATE_MFO_COLSET_LIST_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");
            TRSNode list_item;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = MPGC.MP_STEP_DELETE;
                in_node.AddChar("OPT_LEVEL", '4');

                list_item = in_node.AddNode("COLSET_LIST");
                list_item.AddString("MAT_ID", MPCF.Trim(sMatId));
                list_item.AddInt("MAT_VER", 1);
                list_item.AddChar("COLLECTION_MODE", 'M');



                list_item.AddString("OPER", MPCF.Trim(cdvOper.Text));
                list_item.AddString("COL_SET_ID", MPCF.Trim(sColSetId));
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
        private void SPEC_CHK_UPDATE()
        {
            try
            {
                int iRow;

                for (iRow = 0; iRow < spdSpecList.ActiveSheet.RowCount; iRow++)
                {
                    if (spdSpecList_Sheet1.Cells[iRow, (int)SPEC_INFO.CHK].Value != null)
                    {
                        if (Convert.ToBoolean(spdSpecList_Sheet1.Cells[iRow, (int)SPEC_INFO.CHK].Value) == true)
                        {

                            if (spdSpecList_Sheet1.Cells[iRow, (int)SPEC_INFO.SPEC_REL_ID].Text == "")
                            {
                                //일단은 이렇게 그다음 다시 등록
                                MPCF.ShowMsgBox(MPCF.GetMessage(561));
                                UpdateSpec(MPGC.MP_STEP_CREATE, iRow);
                                ViewLotList();
                                return;
                            }
                            else
                            {

                                if (spdSpecList_Sheet1.Cells[iRow, (int)SPEC_INFO.SPEC_YN].Text != "Y")
                                {
                                    UpdateSpecCharacter(MPGC.MP_STEP_CREATE, iRow);
                                }
                                UpdateSpec(MPGC.MP_STEP_UPDATE, iRow);
                            }
                        }
                    }
                }
                MPCF.ShowMsgBox("변경이 완료되었습니다.");
                ViewLotList();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion

        #region " Event Definition "
        private void spdSpecList_EditModeOff(object sender, EventArgs e)
        {
            if (spdSpecList.ActiveSheet.ActiveColumnIndex != 0)
            {
                spdSpecList.ActiveSheet.SetValue(spdSpecList.ActiveSheet.ActiveRowIndex, 0, true);
            }
        }
        private void btnUpdate_Click(object sender, EventArgs e)
        {


            try
            {
                if (cdvColSetId.Text != txtColSetPresent.Text)
                {

                    if (MPCF.ShowMsgBox(MPCF.GetMessage(560), MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.Yes)
                    {

                        if (MPCF.Trim(txtColSetPresent.Text) != "")
                        {
                            if (Delete_MFO_ColSet_List(cdvMatId.Text, txtColSetPresent.Text) == false)
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(546));
                            }
                        }


                        if (Update_MFO_ColSet_List(cdvMatId.Text, cdvColSetId.Text) == false)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(546));
                        }

                    }

                }


                SPEC_CHK_UPDATE();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvMatId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                // 제품 팝업으로 변경
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMatId.Text = popup.sMat_id;
                    this.txtMatDesc.Text = popup.sMat_Desc;
                    popup = null;
                }
                else
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvColSetId_ButtonPress(object sender, EventArgs e)
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

                if (MPCF.Trim(cdvMatId.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMatId.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvDept.Focus();
                    return;
                }


                viewCollectionSetList(cdvColSetId.GetListView);

                cdvColSetId.InsertEmptyRow(0, 1);



            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            ViewLotList();




        }
        private void cdvColSetId_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (cdvColSetId.Text == txtColSetPresent.Text)
                {
                    return;
                }
                else
                {
                    ViewLotList();
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

                ViewLotList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnProcess_Click(object sender, EventArgs e)
        {

        }
        private void frmPopCollectionSetOper_Load(object sender, EventArgs e)
        {


            if (sArea_id != "")
            {
                cdvDept.Text = sArea_id;
                cdvDept.DisplayText = sArea_desc;
                cdvOper.Text = sOper_id;
                cdvOper.DisplayText = sOper_desc;

                cdvMatId.Text = sMat_id;
                txtMatDesc.Text = sMat_desc;

                cdvDept.ReadOnly = true;
                cdvOper.ReadOnly = true;
                cdvMatId.ReadOnly = true;
                txtMatDesc.ReadOnly = true;



                ViewLotList2();


            }


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
        #endregion
    }
}
