using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using FarPoint.Win.Spread;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

using System.Threading;
using System.IO;
using FarPoint.Win.Spread.Model;
using DevExpress.Utils.Layout;

namespace CUS_QCM
{
    public partial class frmTranInspectionRegistrationPDC : CUS_COM.frmTranForm06
    {
        public frmTranInspectionRegistrationPDC()
        {
            InitializeComponent();

            InitControl();
        }


        #region " Variable Definition "
        DefaultSheetDataModel defModelData;

        bool b_allow_changed;
        string s_lot_kind = "";

        private const int INPUT_COL_MIN_COUNT = 1;
        //private const int INPUT_COL_MAX_COUNT = 17;
        private const int INPUT_COL_MAX_COUNT = 18;
        //private const int VALUE_START_COL = 13;
        //private const int DEFAULT_COL_COUNT = 13;
        //private clsDerivedCharList cls_derived_char_list;


        private const int MAX_DATA_COUNT = 5000;

        #endregion

        #region " Constant Definition "
        private enum LOT_INFO
        {
            LOT_ID,                 // 1 : LOT ID
            MAT_ID,                 // 2 : 제품코드
            MAT_DESC,               // 3 : 제품명       
            FLOW,                      //4 : Flow코드  
            CREATE_DATE,            // 5 : 생성일자   
            INSP_QTY,                       // 6 : 요청수량
            UNIT_1

        }
        private enum COLLECTION_DATA
        {
            UNIT_SEQ,
            POQC033_VALUE_1,
            POQC033_VALUE_2,
            POQC033_VALUE_3,
            POQC033_VALUE_4,
            POQC006_VALUE_1,
            POQC006_VALUE_2,
            POQC006_VALUE_3,
            POQC006_VALUE_4,
            POQC052_VALUE_1,
            POQC029_VALUE_1,
            POQC029_VALUE_2,
            POQC029_VALUE_3,
            POQC029_VALUE_4,
            POQC030_VALUE_1,
            POQC030_VALUE_2,
            POQC030_VALUE_3,
            POQC030_VALUE_4,
            POQC053_VALUE_1,
            JUDGE_PASS,
            JUDGE_LOSS,
            JUDGE_REWORK,
            JUDGE_COMMENT
        }
        private enum FILEUPLOAD
        {
            FILE_NO,               // 1 : 파일번호 
            TITLE,                   // 2 파일타이틀
            NAME,                  //  3. 이미지 SEQ 이름
            REGIST                 // 4. 파일 등록

        }
        private enum LOSS_INFO
        {
            LOSS_CODE,
            LOSS_DESC,
            LOSS_QTY,
            MAIN_YN
        }
        private enum WORKER_INFO
        {
            WORKER_ID,                 // 1 : 이름
            WORKER_DESC,               // 2 : 사번
            WORK_TYPE         // 3: 타입
        }
        private enum SPLITE_LOT
        {
            TYPE,
            LOWER,
            UPPER,
            NEW_LOT_ID,
            QTY

        }
        #endregion

        #region " Function Definition "
        private void InitControl()
        {
            try
            {
                /*
                ListView lisTmp = new ListView();
                string sGcmName;

                lisTmp = new ListView();
                sGcmName = "C_FILE_SERVER";


                lisTmp.Columns.Add("CODE");
                lisTmp.Columns.Add("IP");
                lisTmp.Columns.Add("PORT");
                lisTmp.Columns.Add("DIRECTORY");
                lisTmp.Columns.Add("ID");
                lisTmp.Columns.Add("PW");

                if (BASLIST.ViewGCMDataList(lisTmp, '1', sGcmName) == true)
                {
                    ListViewItem ItmFound = lisTmp.FindItemWithText(MPGV.gsFactory);

                    gFileServer_Ip = ItmFound.SubItems[1].Text;
                    gFileServer_PORT = ItmFound.SubItems[2].Text;
                    gFileServer_Dir = ItmFound.SubItems[3].Text;
                    gFileServer_ID = ItmFound.SubItems[4].Text;
                    gFileServer_PW = ItmFound.SubItems[5].Text;

                }*/

                cdvInspectionType.Text = "OQC";
                cdvInspectionType.DisplayText = "OQC";

                // b_loaded = true;

                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnJudge.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnReceive.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnHold.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSpec.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnFileManager.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void ClearList(string sType)
        {
            switch (sType)
            {
                case "LOT_INFO":

                    //MPCF.FieldClear(panLotInfo,txtLotID);
                    //  txtLotID.Text = "";
                    MPCF.ClearList(spdLotList);
                    MPCF.FieldClear(panJudgeResult);
                    MPCF.FieldClear(panFileRegistration);
                    MPCF.ClearList(spdFileRegistration);
                    MPCF.ClearList(spdLossInfo);

                    //MPCF.FieldClear(panDataCollection);
                    MPCF.ClearList(spdDataCollection);

                    break;

                case "COL_SET_CHANGED":

                    //MPCF.ClearList(spdDataCollection);
                    //txtColSetVer.Text = "";
                    //spdDataCollection.ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;

                    break;
            }

        }
        private void initCombobox()
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            StringBuilder sb;

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            sb = new StringBuilder();

            sb.Append("SELECT * FROM ");
            sb.Append("(SELECT ' ' AS LOSS_CODE, ' ' AS LOSS_DESC, '0' AS SEQ FROM DUAL UNION ALL  ");
            sb.Append(" SELECT A.KEY_2 AS LOSS_CODE, ");
            sb.Append("          C.DATA_1 AS LOSS_DESC, ");
            sb.Append("           replace(A.DATA_1,' ','999') AS SEQ");
            sb.Append("     FROM MGCMTBLDAT A , MGCMTBLDAT C ");
            sb.Append(" WHERE A.FACTORY = C.FACTORY ");
            sb.Append("                                 AND A.KEY_2 = C.KEY_1 ");
            sb.Append("                                 AND C.TABLE_NAME = 'LOSS_CODE' ");
            sb.Append("     AND A.FACTORY = '" + MPGV.gsFactory + "'");
            sb.Append("     AND A.TABLE_NAME = 'C_OPER_LOSS' ");
            sb.AppendLine("     AND A.KEY_1 = '" + cdvInspOper.Text + "' )");
            sb.Append(" ORDER BY TO_NUMBER(SEQ)");
            in_node.AddString("SQL", sb.ToString());

            sb = new StringBuilder();
            in_node.AddString("SQL", sb.ToString());

            if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
            {
                return;
            }

            string[] sItemData;
            string[] sItems;

            if (out_node.GetList("ROWS").Count > 0)
            {
                sItemData = new string[out_node.GetList("ROWS").Count];
                sItems = new string[out_node.GetList("ROWS").Count];

                for (int i = 0; i < out_node.GetList("ROWS").Count; i++)
                {
                    sItems[i] = out_node.GetList("ROWS")[i].GetList("COLS")[0].GetString("DATA");
                    sItemData[i] = out_node.GetList("ROWS")[i].GetList("COLS")[1].GetString("DATA");
                }

                FarPoint.Win.Spread.CellType.ComboBoxCellType cb2 = new FarPoint.Win.Spread.CellType.ComboBoxCellType();//CellType 정의 
                cb2.ItemData = sItems;//ItemData 값 지정. 
                cb2.Items = sItemData; //Items 값 지정.. 
                cb2.EditorValue = FarPoint.Win.Spread.CellType.EditorValue.ItemData;

                spdDataCollection.ActiveSheet.Columns[(int)COLLECTION_DATA.JUDGE_LOSS].CellType = cb2; //CellType 지정. .

            }
        }
        private bool initReworkOperList(ListView listView)
        {
            /*
            try
            {
                string s_flow = spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.FLOW].Value.ToString();

                cdvReworkOper.Init();
                MPCF.InitListView(cdvReworkOper.GetListView);
                cdvReworkOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvReworkOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvReworkOper.SelectedSubItemIndex = 0;
                cdvReworkOper.DisplaySubItemIndex = 1;

                //C_MAT_OPER_LIST
                if (COM_LIST.ViewOperationList(cdvReworkOper.GetListView,'A',"","",s_flow)== false)
                {
                    return;
                }

                cdvReworkOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }*/

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            string s_flow = spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.FLOW].Value.ToString();

            in_node.AddString("SQL", "SELECT A.OPER AS CODE,  "
                                                 + "          B.OPER_DESC AS OPER_DESC "
                                                 + "         FROM MWIPFLWOPR A INNER JOIN MWIPOPRDEF B "
                                                 + "                                   ON A.FACTORY = B.FACTORY "
                                                 + "                                  AND A.OPER = B.OPER "
                                                 + "       WHERE A.FACTORY = '" + MPGV.gsFactory + "' "
                                                 + "          AND A.FLOW = '" + s_flow + "' "
                                                 + "          AND A.SEQ_NUM < (SELECT SEQ_NUM FROM MWIPFLWOPR "
                                                 + "                           WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                                 + "                             AND FLOW = '" + s_flow + "' "
                                                 + "                             AND OPER = '" + MPCF.Trim(cdvInspOper.Text) + "' "
                                                 + "                           ) "
                                                 + "       ORDER BY SEQ_NUM");


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
        private bool ViewColsetIdCheck(string sLotId)
        {

            //PDC는 검사항목이 어차피 공통이라서. 자동으로 등록될수있게해놓음..
            bool bResult = false;
            string sMatId = "";
            string sColSetId = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                System.Data.DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                dvcArgu[2].sCondition_ID = "LOT_ID";
                dvcArgu[2].sCondition_Value = sLotId;

                if (TPDR.GetDataOne("", ref dt, "CQCM2003-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }


                if (MPCF.ToInt(dt.Rows[0]["COL_COUNT"].ToString()) >= 2)
                {

                    sMatId = dt.Rows[0]["MAT_ID"].ToString();
                    sColSetId = dt.Rows[0]["DEL_COL_SET_ID"].ToString();

                    if (Delete_MFO_ColSet_List(sMatId, sColSetId) != false)
                    {

                        if (Update_MFO_ColSet_List(sMatId) != false)
                        {
                            //CMN052 INFO -작업을 성공적으로 수행하였습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(557));
                            bResult = true;
                        }
                    }

                }
                else
                {
                    sMatId = dt.Rows[0]["MAT_ID"].ToString();
                    sColSetId = dt.Rows[0]["COL_SET_ID"].ToString();

                    if (dt.Rows[0]["COL_SET_ID"].ToString() != "X")
                    {
                        if (dt.Rows[0]["COL_SET_ID"].ToString() == "POQ00001")
                        {
                            bResult = true;
                        }
                        else
                        {
                            //CMN555 INFO - 현재의 CollectionSet으로는 검사가 불가합니다. 등록 가능한 CollectionSet으로 변경하시겠습니까?
                            if (MPCF.ShowMsgBox(MPCF.GetMessage(555), MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.Yes)
                            {
                                if (Delete_MFO_ColSet_List(sMatId, sColSetId) != false)
                                {

                                    if (Update_MFO_ColSet_List(sMatId) != false)
                                    {
                                        //CMN052 INFO -작업을 성공적으로 수행하였습니다.
                                        MPCF.ShowMsgBox(MPCF.GetMessage(52));
                                        bResult = true;
                                    }
                                }
                            }

                        }
                    }
                    else
                    {
                        if (Update_MFO_ColSet_List(sMatId) != false)
                        {
                            //CMN556 INFO - 등록된  CollectionSet이 없어서 자동으로 가능한 CollectionSet 등록하였습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(556));
                            bResult = true;
                        }
                    }
                }



                return bResult;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        public void ViewLotInfo(string sLot_ID)
        {

            try
            {


                if (ViewColsetIdCheck(sLot_ID) == false)
                {
                    return;
                }


                b_allow_changed = false;

                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                MPCF.ClearList(spdLotList);

                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", sLot_ID); //Lot ID (WIP LotID 혹은 DLV LotID )

                in_node.AddString("AREA_ID", cdvDept.Text);
                // in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("INSP_TYPE", cdvInspectionType.Text);

                in_node.AddChar("PDC_YN", "Y");

                if (MPCR.CallService("CUS_QCM", "CUS_QCM_View_Lot_Info", in_node, ref out_node) == false)
                {
                    return;
                }


                spdLotList.ActiveSheet.RowCount++;
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.LOT_ID, out_node.GetString("LOT_ID"));
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.MAT_ID, out_node.GetString("MAT_ID"));
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.MAT_DESC, out_node.GetString("MAT_DESC"));
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.FLOW, out_node.GetString("FLOW"));
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.CREATE_DATE, out_node.GetString("CREATE_TIME"));
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.INSP_QTY, out_node.GetDouble("INSP_QTY"));
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.UNIT_1, out_node.GetString("UNIT_1"));

                MPCF.FitColumnHeader(spdLotList);



                s_lot_kind = out_node.GetString("LOT_KIND");
                txtMatID.Text = out_node.GetString("MAT_ID");
                txtMatDesc.Text = out_node.GetString("MAT_DESC");
                txtMatVer.Text = Convert.ToString(out_node.GetInt("MAT_VER"));
                txtInspID.Text = out_node.GetString("INSP_ID"); //검사 ID
                cdvInspOper.Text = out_node.GetString("INSP_OPER");
                cdvInspOper.DisplayText = out_node.GetString("INSP_OPER_DESC");

                cdvDept.Text = out_node.GetString("AREA_ID");
                cdvDept.DisplayText = out_node.GetString("AREA_DESC");
                // cdvWorkPlace.Text = out_node.GetString("SUB_AREA_ID");
                // cdvWorkPlace.DisplayText = out_node.GetString("SUB_AREA_DESC");

                txtInspectionStatus.Text = out_node.GetChar("INSP_STATUS").ToString();
                txtInspectionStatusDesc.Text = out_node.GetString("INSP_STATUS_DESC").ToString();
                cdvInspectionJudgeFlag.Text = out_node.GetChar("INSP_JUDGE_FLAG").ToString();
                cdvInspectionJudgeFlag.DisplayText = out_node.GetString("INSP_JUDGE_DESC");

                txtComment.Text = out_node.GetString("INSP_COMMENT");

                cdvColSetID.Text = out_node.GetString("COL_SET_ID");
                cdvColSetID.DisplayText = out_node.GetString("COL_SET_DESC");



                GetJudgeFlagByArea(cdvInspectionJudgeFlag.GetListView, cdvInspOper.Text, cdvInspectionType.Text);
                cdvInspectionJudgeFlag.InsertEmptyRow(0, 1);

                initCombobox(); //Loss Combobox
                initReworkOperList(cdvReworkOper.GetListView);

                //파일 리스트 조회
                ViewInspectionFile(txtInspID.Text);

                //Loss 정보 조회
                ViewInspectionLossInfo(txtInspID.Text);

                //검사자 대상 조회;
                ViewWorkerList();

                //SPEC 조회
                ViewInspSpec();

                //Data 조회
                SelectedItemChangedByColSet();

                ViewSpecLastEditTime(txtMatID.Text, cdvInspOper.Text);





                b_allow_changed = true;

                splitCount();

                return;
            }
            catch (Exception ex)
            {
                b_allow_changed = false;
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        private bool Update_MFO_ColSet_List(string sMatId)
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
                list_item.AddString("COL_SET_ID", "POQ00001");
                list_item.AddChar("DEFAULT_FLAG", 'N');
                list_item.AddChar("DISABLE_FLAG", 'N');


                if (MPCR.CallService("EDC", "EDC_Update_MFO_ColSet_List", in_node, ref out_node) == false)
                {
                    return false;
                }

                // MPCR.ShowSuccessMsg(out_node);

                cdvColSetID.Text = "POQ00001";
                cdvColSetID.DisplayText = "POQ00001";

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
        private void ViewWorkerList()
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
                dvcArgu[1].sCondition_Value = cdvInspOper.Text;

                dvcArgu[2].sCondition_ID = "GROUP_ID";
                dvcArgu[2].sCondition_Value = cdvWorkGroup.Text;


                if (TPDR.GetDataOne("", ref dt, "CQCM2001-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdWorkerList);
                    return;
                }

                MPCF.ClearList(spdWorkerList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdWorkerList_Sheet1.RowCount++;

                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Value = dt.Rows[i]["WORKER_ID"];
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Value = dt.Rows[i]["WORKER_DESC"];
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORK_TYPE].Value = dt.Rows[i]["WORK_TYPE"];

                }
                MPCF.FitColumnHeader(spdWorkerList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private bool GetJudgeFlagByArea(ListView listView, string insp_oper, string insp_type)
        {
            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            /*
            in_node.AddString("SQL", "SELECT KEY_3 AS CODE, "
                                                + "          DATA_1 AS VALUE "
                                                + "         FROM MGCMTBLDAT "
                                                + "       WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                                + "           AND TABLE_NAME = 'C_INSP_JUDGE_FLAG' "
                                                + "           AND KEY_1 = (SELECT AREA_ID "
                                                + "                          FROM MWIPOPRDEF "
                                                + "                         WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                                + "                           AND OPER = '" + insp_oper + "') "
                                                + "           AND KEY_2 = '" + insp_type + "' "
                                                + "        ORDER BY DATA_2"); */

            in_node.AddString("SQL", "SELECT KEY_2 AS CODE, "
                                               + "       DATA_1 AS VALUE "
                                               + "  FROM MGCMTBLDAT A "
                                               + "  WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                               + "   AND TABLE_NAME = 'C_INSP_JUDGE' "
                                               + "   AND KEY_1 = '" + insp_oper + "'"
                                               + " ORDER BY DATA_2");

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
        private void ViewInspectionFile(string inspID)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_ID";
                dvcArgu[1].sCondition_Value = inspID;

                // 검사 첨부파일 리스트 조회
                if (TPDR.GetDataOne("", ref dt, "CQCM2001-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdFileRegistration);
                    return;
                }

                MPCF.ClearList(spdFileRegistration);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdFileRegistration.ActiveSheet.RowCount++;



                    spdFileRegistration.ActiveSheet.Cells[i, (int)FILEUPLOAD.FILE_NO].Value = dt.Rows[i]["FILE_NO"];
                    spdFileRegistration.ActiveSheet.Cells[i, (int)FILEUPLOAD.TITLE].Value = dt.Rows[i]["TITLE"];
                    spdFileRegistration.ActiveSheet.Cells[i, (int)FILEUPLOAD.NAME].Value = dt.Rows[i]["NAME"];



                }
                MPCF.FitColumnHeader(spdFileRegistration);

                pictureBox1.Image = null;


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void ViewInspectionLossInfo(string inspID)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_ID";
                dvcArgu[1].sCondition_Value = inspID;

                dvcArgu[2].sCondition_ID = "COL_SET_ID";
                dvcArgu[2].sCondition_Value = cdvColSetID.Text;

                // 검사 첨부파일 리스트 조회
                if (TPDR.GetDataOne("", ref dt, "CQCM2003-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLossInfo);
                    return;
                }

                MPCF.ClearList(spdLossInfo);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLossInfo.ActiveSheet.RowCount++;

                    spdLossInfo.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_CODE].Value = dt.Rows[i]["LOSS_CODE"];
                    spdLossInfo.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_DESC].Value = dt.Rows[i]["LOSS_DESC"];
                    spdLossInfo.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_QTY].Value = dt.Rows[i]["LOSS_QTY"];

                }
                MPCF.FitColumnHeader(spdLossInfo);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        /*private void cdvMatID_ButtonPress(object sender, EventArgs e)
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
                    this.cdvMatID.Text = popup.sMat_id;
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
        }*/
        private void FindColSetVersion(string sColSetID, string sLotID, string sMatID, int iMatVer, string sOper)
        {
            try
            {

                TRSNode in_node = new TRSNode("FIND_COL_SET_VERSION_IN");
                TRSNode out_node = new TRSNode("FIND_COL_SET_VERSION_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                // in_node.AddString("LOT_ID", sLotID);
                in_node.AddString("MAT_ID", sMatID);
                in_node.AddInt("MAT_VER", iMatVer);
                in_node.AddString("OPER", sOper);
                in_node.AddString("EVENT_ID", "");
                in_node.AddString("COL_SET_ID", sColSetID);
                in_node.AddChar("LOT_OR_RES_FLAG", 'L');

                if (MPCR.CallService("EDC", "EDC_Find_Col_Set_Version", in_node, ref out_node, false) == false)
                {
                    return;
                }

                txtColSetVer.Text = out_node.GetInt("COL_SET_VERSION").ToString();


                if (ViewInspData() == false)
                {
                    ViewInputContainer();
                    //CSCF.ClearSpread(spdDataCollection, 0, (int)COLLECTION_DATA.VALUE_START_COL, "");
                }

            }
            catch
            {

            }
        }
        private bool ViewInspSpec()
        {
            int i;
            string SpecType = "1";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = txtMatID.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvInspOper.Text;


                if (rdoStSpec.Checked == true)
                {
                    SpecType = "1";
                }
                else
                {
                    SpecType = "2";
                }

                dvcArgu[3].sCondition_ID = "SPEC_TYPE";
                dvcArgu[3].sCondition_Value = SpecType;


                if (TPDR.GetDataOne("", ref dt, "CQCM2003-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }


                for (i = 0; i < dt.Rows.Count; i++)
                {

                    if (dt.Rows[i]["CHAR_ID"].ToString() == "POQC033")
                    {
                        //this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 1).Value = "외경(mm)";
                        if (MPGV.gsFactory == "IJDK1")
                        {
                            this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 1).Value = "외경(mm)";
                        }
                        else
                        {
                            this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 1).Value = "Diameter(mm)";
                        }



                        //spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 1].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 1].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 1].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 1].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        // spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 2].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 2].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 2].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 2].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        // spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 3].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 3].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 3].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 3].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        //spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 4].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 4].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 4].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 4].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();
                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "POQC006")
                    {
                        // this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 5).Value = "높이(mm)";

                        if (MPGV.gsFactory == "IJDK1")
                        {
                            this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 5).Value = "높이(mm)";
                        }
                        else
                        {
                            this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 5).Value = "Height(mm)";
                        }


                        //spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 5].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 5].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 5].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 5].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        // spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 6].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 6].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 6].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 6].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        //  spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 7].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 7].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 7].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 7].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        // spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 8].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 8].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 8].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 8].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();
                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "POQC052")
                    {
                        //this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 9).Value = "총두께(mm)";


                        if (MPGV.gsFactory == "IJDK1")
                        {
                            this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 9).Value = "총두께(mm)";
                        }
                        else
                        {
                            this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 9).Value = "Layer Thickness(mm)";
                        }


                        //spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 9].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 9].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 9].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 9].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();
                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "POQC029")
                    {
                        //  this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 10).Value = "다이아층 챔퍼길이(mm)";

                        if (MPGV.gsFactory == "IJDK1")
                        {
                            this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 10).Value = "다이아층 챔퍼길이(mm)";
                        }
                        else
                        {
                            this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 10).Value = "Dia Chamfer(mm)";
                        }

                        // spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 10].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 10].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 10].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 10].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        //spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 11].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 11].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 11].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 11].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        // spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 12].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 12].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 12].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 12].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        //spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 13].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 13].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 13].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 13].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();
                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "POQC030")
                    {
                        // this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 14).Value = "초경층 챔퍼길이(mm)";

                        if (MPGV.gsFactory == "IJDK1")
                        {
                            this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 14).Value = "초경층 챔퍼길이(mm)";
                        }
                        else
                        {
                            this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 14).Value = "Carbide Chamfer(mm)";
                        }


                        //spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 14].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 14].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 14].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 14].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        // spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 15].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 15].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 15].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 15].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        //spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 16].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 16].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 16].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 16].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        // spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 17].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 17].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 17].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 17].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "POQC053")
                    {
                        //this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 18).Value = "리칭깊이(mm)";

                        if (MPGV.gsFactory == "IJDK1")
                        {
                            this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 18).Value = "리칭깊이(mm)";
                        }
                        else
                        {
                            this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 18).Value = "Leaching depth(mm)";
                        }


                        //spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 14].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 18].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 18].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 18].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();
                        /*
                        // spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 15].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 19].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 19].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 19].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        //spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 16].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 20].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 20].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 20].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        // spdDataCollection.ActiveSheet.ColumnHeader.Cells[1, 17].Value = dt.Rows[i]["CHAR_DESC"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 21].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 21].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 21].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();
                        */

                    }
                }
                // MPCF.FitColumnHeader(spdDataCollection);


                return true;
                //return bResult;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        private bool ViewInspData()
        {

            int i;
            int iPassQty = 0;
            int iLossQty = 0;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_ID";
                dvcArgu[1].sCondition_Value = txtInspID.Text;

                dvcArgu[2].sCondition_ID = "COL_SET_ID";
                dvcArgu[2].sCondition_Value = cdvColSetID.Text;





                if (TPDR.GetDataOne("", ref dt, "CQCM2003-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }


                MPCF.ClearList(spdDataCollection);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdDataCollection.ActiveSheet.RowCount++;

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value = dt.Rows[i]["UNIT_SEQ"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC033_VALUE_1].Value = dt.Rows[i]["POQC033_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC033_VALUE_2].Value = dt.Rows[i]["POQC033_VALUE_2"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC033_VALUE_3].Value = dt.Rows[i]["POQC033_VALUE_3"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC033_VALUE_4].Value = dt.Rows[i]["POQC033_VALUE_4"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC006_VALUE_1].Value = dt.Rows[i]["POQC006_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC006_VALUE_2].Value = dt.Rows[i]["POQC006_VALUE_2"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC006_VALUE_3].Value = dt.Rows[i]["POQC006_VALUE_3"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC006_VALUE_4].Value = dt.Rows[i]["POQC006_VALUE_4"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC052_VALUE_1].Value = dt.Rows[i]["POQC052_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC029_VALUE_1].Value = dt.Rows[i]["POQC029_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC029_VALUE_2].Value = dt.Rows[i]["POQC029_VALUE_2"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC029_VALUE_3].Value = dt.Rows[i]["POQC029_VALUE_3"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC029_VALUE_4].Value = dt.Rows[i]["POQC029_VALUE_4"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC030_VALUE_1].Value = dt.Rows[i]["POQC030_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC030_VALUE_2].Value = dt.Rows[i]["POQC030_VALUE_2"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC030_VALUE_3].Value = dt.Rows[i]["POQC030_VALUE_3"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC030_VALUE_4].Value = dt.Rows[i]["POQC030_VALUE_4"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC053_VALUE_1].Value = dt.Rows[i]["POQC053_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_PASS].Value = dt.Rows[i]["JUDGE_PASS"].ToString() == "Y" ? true : false;
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_LOSS].Value = dt.Rows[i]["JUDGE_LOSS"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_REWORK].Value = dt.Rows[i]["JUDGE_REWORK"].ToString() == "Y" ? true : false;
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_COMMENT].Value = dt.Rows[i]["JUDGE_COMMENT"];

                    //합격수량 카운트
                    if (dt.Rows[i]["JUDGE_PASS"].ToString() == "Y")
                    {
                        iPassQty = iPassQty + 1;
                    }

                    if (dt.Rows[i]["JUDGE_LOSS"].ToString().Trim() != "")
                    {
                        iLossQty = iLossQty + 1;
                    }


                }

                txtPassQty.Text = iPassQty.ToString();
                txtBadQty.Text = iLossQty.ToString();

                //속도저하로 임시주석
                ApplyColorBySpecOut();

                // 데이터 조회후 합격, 불량 수량 넣어줌.


                return true;
                //return bResult;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        private bool ViewInputContainer()
        {

            int i;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                DataTable dt = null;
                string sSql = "";
                string sViewID = "";

                //dvcArgu[0].sCondition_ID = "FACTORY";
                // dvcArgu[0].sCondition_Value =  MPGV.gsFactory;

                // dvcArgu[1].sCondition_ID = "INSP_ID";
                // dvcArgu[1].sCondition_Value = txtInspID.Text;

                dvcArgu[0].sCondition_ID = "LOT_ID";
                dvcArgu[0].sCondition_Value = txtLotID.Text;

                if (s_lot_kind == "W")
                {
                    sViewID = "CQCM2003-002";
                }
                else if (s_lot_kind == "I")
                {
                    sViewID = "CQCM2003-005";
                }


                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }


                MPCF.ClearList(spdDataCollection);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdDataCollection.ActiveSheet.RowCount++;

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value = dt.Rows[i]["UNIT_SEQ"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC033_VALUE_1].Value = dt.Rows[i]["POQC033_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC033_VALUE_2].Value = dt.Rows[i]["POQC033_VALUE_2"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC033_VALUE_3].Value = dt.Rows[i]["POQC033_VALUE_3"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC033_VALUE_4].Value = dt.Rows[i]["POQC033_VALUE_4"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC006_VALUE_1].Value = dt.Rows[i]["POQC006_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC006_VALUE_2].Value = dt.Rows[i]["POQC006_VALUE_2"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC006_VALUE_3].Value = dt.Rows[i]["POQC006_VALUE_3"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC006_VALUE_4].Value = dt.Rows[i]["POQC006_VALUE_4"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC052_VALUE_1].Value = dt.Rows[i]["POQC052_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC029_VALUE_1].Value = dt.Rows[i]["POQC029_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC029_VALUE_2].Value = dt.Rows[i]["POQC029_VALUE_2"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC029_VALUE_3].Value = dt.Rows[i]["POQC029_VALUE_3"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC029_VALUE_4].Value = dt.Rows[i]["POQC029_VALUE_4"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC030_VALUE_1].Value = dt.Rows[i]["POQC030_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC030_VALUE_2].Value = dt.Rows[i]["POQC030_VALUE_2"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC030_VALUE_3].Value = dt.Rows[i]["POQC030_VALUE_3"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC030_VALUE_4].Value = dt.Rows[i]["POQC030_VALUE_4"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC053_VALUE_1].Value = dt.Rows[i]["POQC053_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_PASS].Value = dt.Rows[i]["JUDGE_PASS"].ToString() == "Y" ? true : false;
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_LOSS].Value = dt.Rows[i]["JUDGE_LOSS"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_REWORK].Value = dt.Rows[i]["JUDGE_REWORK"].ToString() == "Y" ? true : false;
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_COMMENT].Value = dt.Rows[i]["JUDGE_COMMENT"];


                }
                // MPCF.FitColumnHeader(spdDataCollection);


                return true;
                //return bResult;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        private bool FindColSetVersion(char c_step, string ColSetID, ref int ColSetVersion, string LotID,
                                                     FpSpread spdData, bool bIgnoreError)
        {

            TRSNode in_node = new TRSNode("FIND_COL_SET_VERSION_IN");
            TRSNode out_node = new TRSNode("FIND_COL_SET_VERSION_OUT");

            MPCR.SetInMsg(in_node);

            in_node.ProcStep = c_step;
            in_node.AddString("COL_SET_ID", ColSetID);

            if (MPCR.CallService("EDC", "EDC_Find_Col_Set_Version", in_node, ref out_node, bIgnoreError))
            {
                return false;
            }

            ColSetVersion = out_node.GetInt("COL_SET_VERSION");

            if (spdData != null)
            {
                // if(fnViewAttachCharacterList())
            }

            return true;
        }

        private void SelectedItemChangedByColSet()
        {
            string sLotID;
            string sOper;
            string sMatID;
            int iMatVer;

            try
            {
                sOper = cdvInspOper.Text;
                sMatID = txtMatID.Text;
                iMatVer = Convert.ToInt32(txtMatVer.Text);
                sLotID = spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.LOT_ID].Value.ToString();

                //Clear
                MPCF.ClearList(spdDataCollection, true);

                if (MPCF.Trim(cdvColSetID.Text) != "")
                {
                    FindColSetVersion(cdvColSetID.Text, sLotID, sMatID, iMatVer, sOper);
                }
                else
                {
                    // ClearList("COL_SET_CHANGED");
                }

                // txtColSetVer.Text = "";  Col Set ID 버전
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                /*
                if (MPCF.Trim(cdvInspOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblInspOper.Text + "]");
                    cdvInspOper.Focus();
                    return false;
                }
                */

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
                        /*
                        if (MPCF.Trim(cdvWorkPlace.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                            cdvWorkPlace.Focus();
                            return false;
                        }*/

                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
                            return false;
                        }

                        /*
                        if (MPCF.Trim(cdvInspectionType.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblInspectionType.Text + "]");
                            cdvInspectionType.Focus();
                            return false;
                        }*/

                        break;


                    case CSGC.CHECK.SAVE:

                        if (spdDataCollection.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(107));
                            spdDataCollection.Select();
                            return false;
                        }
                        if (MPCF.Trim(cdvColSetID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblColSetID.Text + "]");
                            cdvInspectionType.Focus();
                            return false;
                        }

                        for (int i = 0; i < spdDataCollection.ActiveSheet.RowCount; i++)
                        {
                            /*
                            if (MPCF.Trim(spdDataCollection.ActiveSheet.GetValue(i, (int)COLLECTION_DATA.CHAR_COL)) == "")
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                spdDataCollection.ActiveSheet.SetActiveCell(i, (int)COLLECTION_DATA.CHAR_COL);
                                spdDataCollection.Select();
                                return false;
                            }*/

                            // unit_id check
                            /* if (MPCF.Trim(spdDataCollection.ActiveSheet.GetValue(i, (int)COLLECTION_DATA.OPT_INPUT_COL)) != "Y")
                             {
                                 for (int j = (int)COLLECTION_DATA.UNIT_COL; j <= (int)COLLECTION_DATA.UNIT_COL + MPCF.ToInt(spdDataCollection.ActiveSheet.GetValue(i, (int)COLLECTION_DATA.VALUE_COUNT_COL)); j++)
                                 {
                                     if (MPCF.Trim(spdDataCollection.ActiveSheet.GetTag(i, j)) != "NULL")
                                     {
                                         if (MPCF.Trim(spdDataCollection.ActiveSheet.GetValue(i, j)) == "" && spdDataCollection.ActiveSheet.Cells[i, j].Locked == false)
                                         {
                                             //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                             MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                             spdDataCollection.ActiveSheet.SetActiveCell(i, j);
                                             spdDataCollection.Select();
                                             return false;
                                         }
                                     }
                                 }
                             }*/

                            /*
                            if (MPCF.Trim(spdDataCollection.ActiveSheet.GetValue(i, (int)COLLECTION_DATA.VALUE_TYPE_COL)) == "N")
                            {
                                for (int j = (int)COLLECTION_DATA.VALUE_START_COL; j < (int)COLLECTION_DATA.VALUE_START_COL + MPCF.ToInt(spdDataCollection.ActiveSheet.GetValue(i, (int)COLLECTION_DATA.VALUE_COUNT_COL)); j++)
                                {
                                    if (MPCF.Trim(spdDataCollection.ActiveSheet.GetValue(i, j)) != "")
                                    {
                                        if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.GetValue(i, j)) == false)
                                        {
                                            //CMN116 ERROR - 이 필드는 숫자를 입력해야 하는 필드입니다.
                                            MPCF.ShowMsgBox(MPCF.GetMessage(116));
                                            spdDataCollection.ActiveSheet.SetActiveCell(i, j);
                                            spdDataCollection.Select();
                                            return false;
                                        }
                                    }
                                }
                            }
                            */





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
        private bool Collect_Inspection_Data()
        {

            TRSNode in_node = new TRSNode("COLLECT_LOT_DATA_IN");
            TRSNode out_node = new TRSNode("COLLECT_LOT_DATA_OUT");
            TRSNode data_list;

            int iRowCnt = 0;
            // int i_value_start = (int)COLLECTION_DATA.VALUE_START_COL;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '3'; //PDC 전용 저장 STEP
                in_node.AddString("LOT_ID", MPCF.Trim(txtLotID.Text));
                in_node.AddString("MAT_ID", MPCF.Trim(txtMatID.Text));
                in_node.AddInt("MAT_VER", MPCF.ToInt(txtMatVer.Text));

                in_node.AddString("COL_SET_ID", MPCF.Trim(cdvColSetID.Text));
                in_node.AddInt("COL_SET_VERSION", MPCF.Trim(txtColSetVer.Text));

                in_node.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));
                in_node.AddInt("INSP_SEQ", 1);



                iRowCnt = spdDataCollection.ActiveSheet.RowCount;

                //PDC의 경우 검사항목 코드를 고정시킴.
                //외경
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "POQC033");
                    data_list.AddInt("CHAR_SEQ", 1);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 4);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC033_VALUE_1].Text);
                    data_list.AddString("VALUE_2", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC033_VALUE_2].Text);
                    data_list.AddString("VALUE_3", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC033_VALUE_3].Text);
                    data_list.AddString("VALUE_4", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC033_VALUE_4].Text);

                }
                //높이
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "POQC006");
                    data_list.AddInt("CHAR_SEQ", 2);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 4);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC006_VALUE_1].Text);
                    data_list.AddString("VALUE_2", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC006_VALUE_2].Text);
                    data_list.AddString("VALUE_3", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC006_VALUE_3].Text);
                    data_list.AddString("VALUE_4", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC006_VALUE_4].Text);
                }
                //총두께
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "POQC052");
                    data_list.AddInt("CHAR_SEQ", 3);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 1);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC052_VALUE_1].Text);
                }
                //다이아총챔퍼길이
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "POQC029");
                    data_list.AddInt("CHAR_SEQ", 4);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 4);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC029_VALUE_1].Text);
                    data_list.AddString("VALUE_2", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC029_VALUE_2].Text);
                    data_list.AddString("VALUE_3", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC029_VALUE_3].Text);
                    data_list.AddString("VALUE_4", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC029_VALUE_4].Text);
                }
                //초경총챔퍼길이
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "POQC030");
                    data_list.AddInt("CHAR_SEQ", 5);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 4);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC030_VALUE_1].Text);
                    data_list.AddString("VALUE_2", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC030_VALUE_2].Text);
                    data_list.AddString("VALUE_3", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC030_VALUE_3].Text);
                    data_list.AddString("VALUE_4", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC030_VALUE_4].Text);
                }

                //      if (cdvColSetID.Text == "POQ00002" || cdvColSetID.Text == "POQ00001") //PDC[OQC] 완제품검사(POQ00002) 일떄만 등록
                //     {
                //리칭깊이
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "POQC053");
                    data_list.AddInt("CHAR_SEQ", 10);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 1);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC053_VALUE_1].Text);

                }
                //     }


                //합격여부
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "JUDGE_PASS");
                    data_list.AddInt("CHAR_SEQ", 6);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'A');
                    data_list.AddInt("VALUE_COUNT", 1);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_PASS].Value.ToString().ToUpper() == "TRUE" ? "Y" : "N");
                }
                //불량
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "JUDGE_LOSS");
                    data_list.AddInt("CHAR_SEQ", 7);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'A');
                    data_list.AddInt("VALUE_COUNT", 1);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_LOSS].Value.ToString());
                }
                //재가공
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "JUDGE_REWORK");
                    data_list.AddInt("CHAR_SEQ", 8);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'A');
                    data_list.AddInt("VALUE_COUNT", 1);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_REWORK].Value.ToString().ToUpper() == "TRUE" ? "Y" : "N");
                }
                //비고
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "JUDGE_COMMENT");
                    data_list.AddInt("CHAR_SEQ", 9);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'A');
                    data_list.AddInt("VALUE_COUNT", 1);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_COMMENT].Value.ToString());
                }

                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Collect_Inspection_Data", in_node, ref out_node, false) == false)
                {
                    return false;
                }
                else
                {
                    // MPCR.ShowSuccessMsg(out_node);
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }
        private bool Inspection_Judge()
        {

            TRSNode in_node = new TRSNode("INSPECTION_JUDGE_IN");
            TRSNode out_node = new TRSNode("INSPECTION_JUDGE_OUT");
            TRSNode worker_list;
            TRSNode splite_list;

            string sLotID;
            int iWrkRow = 0;
            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2'; //PDC 판정





                if (cdvOper.Text == "OP90040") //PDC(PDV) 리칭인경우만 LOT SPLITE 진행
                {
                    in_node.AddChar("SPLITE_FLAG", "Y");
                    // 분할LOT 등록
                    for (int ispt = 0; ispt < spdSplitLotList.ActiveSheet.RowCount; ispt++)
                    {

                        if (spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.TYPE].Text != "REWORK" && spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.TYPE].Text != "LOSS")
                        {
                            if (spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.QTY].Text != "0" && spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.QTY].Text != "")
                            {
                                splite_list = in_node.AddNode("SPLITE_LIST");
                                splite_list.AddString("SPLITE_LOT", spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.NEW_LOT_ID].Value);
                                splite_list.AddDouble("SPLITE_LOT_QTY", MPCF.ToDbl(spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.QTY].Text));
                            }

                        }
                    }
                }
                else
                {
                    in_node.AddChar("SPLITE_FLAG", "N");
                }



                //INSP_ID, LOT_ID, INSP_JUDGE_FLAG, REWORK_OPER, INSP_COMMENT
                sLotID = spdLotList.ActiveSheet.GetValue(0, (int)LOT_INFO.LOT_ID).ToString();

                in_node.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));   //검사 ID
                in_node.AddString("LOT_ID", sLotID);  // LOT_ID
                in_node.AddChar("INSP_JUDGE_FLAG", MPCF.Trim(cdvInspectionJudgeFlag.Text));  // 판정 Flag

                in_node.AddString("INSP_COMMENT", MPCF.Trim(txtComment.Text));                        //주석

                in_node.AddString("COL_SET_ID", MPCF.Trim(cdvColSetID.Text)); //Col Set ID
                in_node.AddInt("COL_SET_VERSION", MPCF.ToInt(txtColSetVer.Text)); //Col Set VERSION

                in_node.AddString("TO_FLOW", MPCF.Trim(spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.FLOW].Value.ToString()));
                in_node.AddString("TO_OPER", MPCF.Trim(cdvReworkOper.Text));



                // 작업자 등록
                for (iWrkRow = 0; iWrkRow < spdWorkerList.ActiveSheet.RowCount; iWrkRow++)
                {
                    worker_list = in_node.AddNode("WORKER_LIST");

                    worker_list.AddString("WORKER_ID", spdWorkerList.ActiveSheet.Cells[iWrkRow, (int)WORKER_INFO.WORKER_ID].Value);  // WORKER_ID
                    worker_list.AddString("WORKER_DESC", spdWorkerList.ActiveSheet.Cells[iWrkRow, (int)WORKER_INFO.WORKER_DESC].Value);  // WORKER_DESC
                    worker_list.AddString("WORK_TYPE", spdWorkerList.ActiveSheet.Cells[iWrkRow, (int)WORKER_INFO.WORK_TYPE].Value);  // WORK_TYPE
                }



                //PDC는 매뉴얼로 저장한 lot size별 각각의 판정(합격,재가공,Loss)을 통하여 개별 처리  

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
        private bool VaildationCheckJudge()
        {

            try
            {
                // double dLotQty = 0;
                //double dLossQtyByRow = 0;


                if (txtInspID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(478));
                    txtLotID.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvInspectionJudgeFlag.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblJudge.Text + "]");
                    cdvInspectionJudgeFlag.Focus();
                    return false;
                }

                //Loss info Check

                /*
                dLotQty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.INSP_QTY].Value);
                for (int i = 0; i < spdLossInfo.ActiveSheet.RowCount; i++)
                {
                    dLossQtyByRow = MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_QTY].Value);
                    if (dLossQtyByRow > 0)
                    {
                        if (dLotQty < dLossQtyByRow)
                        {
                            MPCF.ShowMsgBox("불량수량은 현재의 Lot수량을 초과할 수 없습니다.");
                            return false;
                        }
                    }
                    
                }
                */

                // todo 판정플래그,  재가공?시 ReworkOper  체크.


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }
        private void ApplyColorBySpecOut()
        {

            if (spdDataCollection.ActiveSheet.RowCount < 1)
            {
                return;
            }

            double dInputValue;
            double dSpecMaxValue;
            double dSpecMinValue;

            bool bInputValueDoubleParse;
            bool bSpecMaxDoubleParse;
            bool bSpecMinDoubleParse;


            //bool bSpecOut;


            try
            {

                for (int iCol = INPUT_COL_MIN_COUNT; iCol < INPUT_COL_MAX_COUNT; iCol++)
                {
                    bSpecMaxDoubleParse = Double.TryParse(spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, iCol].Text.Trim(), out dSpecMaxValue);
                    bSpecMinDoubleParse = Double.TryParse(spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, iCol].Text.Trim(), out dSpecMinValue);

                    for (int iRow = 0; iRow < spdDataCollection.ActiveSheet.RowCount; iRow++)
                    {
                        //bSpecOut = false;

                        bInputValueDoubleParse = Double.TryParse(spdDataCollection.ActiveSheet.Cells[iRow, iCol].Text.Trim(), out dInputValue);

                        if (bInputValueDoubleParse)
                        {
                            // 스펙 상한값이 있을 때
                            if (bSpecMaxDoubleParse)
                            {
                                if (dInputValue > dSpecMaxValue)
                                {
                                    // bSpecOut = true;
                                    // spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.Blue;
                                    spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.FromArgb(51, 102, 255);
                                    // Color.FromArgb(51, 102, 255);

                                    continue;
                                }
                            }

                            if (bSpecMinDoubleParse)
                            {
                                if (dInputValue < dSpecMinValue)
                                {
                                    spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.Red;
                                    continue;
                                    // bSpecOut = true;
                                }
                            }
                        }




                        /*
                        //입력값(검사 결과값)이 숫자일 때만
                        if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value) == true)
                        {
                            dInputValue = MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value);

                            if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, iCol].Value))
                            {
                                if (dInputValue > MPCF.ToDbl(spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, iCol].Value))
                                {
                                    bSpecOut = true;
                                }
                            }

                            if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, iCol].Value))
                            {
                                if (dInputValue < MPCF.ToDbl(spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, iCol].Value))
                                {
                                    bSpecOut = true;
                                }
                            }

                            if (bSpecOut)
                            {
                                spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.Red;
                            }
                        }
                        else
                        {
                            
                        }
                        */





                    }
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

        }
        private bool Update_Inspection_Status(char procstep)
        {

            TRSNode in_node = new TRSNode("UPDATE_INSPECTION_STATUS_IN");
            TRSNode out_node = new TRSNode("UPDATE_INSPECTION_STATUS_OUT");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = procstep;

                in_node.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));   //검사 ID

                //Step : 1 접수
                //Step : 2 보류

                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Update_Inspection_Status", in_node, ref out_node, false) == false)
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
        private bool viewOperList(ListView listView)
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
                                                + "          AND SUB_AREA_ID = '" + cdvWorkPlace.Text + "' "
                                                + "          AND OPER_GRP_2 <> 'NONE' "
                                                + "         AND OPER_GRP_2 > ' ' "
                                                + "        ORDER BY OPER"); */

            in_node.AddString("SQL", "SELECT OPER AS CODE, "
                                               + "               OPER_DESC AS NAME "
                                               + "         FROM MWIPOPRDEF "
                                               + "        WHERE AREA_ID = '" + cdvDept.Text + "' "
                                               + "          AND OPER_GRP_2 <> 'NONE' "
                                               + "         AND OPER_GRP_2 > ' ' "
                                               + "        ORDER BY OPER");



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
        private bool VaildationCheckHold()
        {

            try
            {

                if (txtInspID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(478));
                    txtLotID.Focus();
                    return false;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }
        private void fnRegistrationFile(FileInfo _fileInfo, string FileNo, string Image_code, string InspID)
        {
            //DB 저장
            TRSNode in_node = new TRSNode("Update_File_In");
            TRSNode out_node = new TRSNode("Update_File_Out");

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '2';

            in_node.AddString("FILE_NO", FileNo);
            in_node.AddString("IMAGE_CODE", Image_code);
            in_node.AddString("INSP_ID", InspID);

            //string s_File_no = "";

            BinaryReader br;
            byte[] file_buffer;
            if (_fileInfo.Exists == true)
            {
                br = new BinaryReader(_fileInfo.OpenRead());
                file_buffer = br.ReadBytes((int)_fileInfo.Length);
                in_node.AddBlob(MPGC.MP_BIN_DATA_1, file_buffer);
                in_node.AddInt("IMAGE_SIZE", _fileInfo.Length);
                br.Close();
            }

            if (MPCR.CallService("CUS_QCM", "CUS_QCM_File_Attach", in_node, ref out_node) == false)
            {
                return;
            }

            //s_File_no = out_node.GetString("FILE_NO");

        }
        private void fnFileSelectionChagned()
        {
            if (spdFileRegistration.ActiveSheet.ActiveRowIndex < 0)
                return;

            int iRow = spdFileRegistration.ActiveSheet.ActiveRowIndex;


            pictureBox1.Image = null;


            string s_FileNo = MPCF.Trim(spdFileRegistration.ActiveSheet.Cells[iRow, (int)FILEUPLOAD.FILE_NO].Value.ToString());

            if (s_FileNo == "")
                return;

            ViewImageFile(s_FileNo);
        }
        private void ViewImageFile(string _FileNo)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FILE_NO";
                dvcArgu[1].sCondition_Value = _FileNo;





                if (TPDR.GetDataOne("", ref dt, "CQCM2001-005", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }


                pictureBox1.Image = ByteArrayToImage((byte[])dt.Rows[0]["IMAGE_DATA"]);


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        public static Image ByteArrayToImage(byte[] b)
        {
            TypeConverter tc = TypeDescriptor.GetConverter(typeof(Bitmap));
            ImageConverter imgcvt = new ImageConverter();

            Image img = (Image)imgcvt.ConvertFrom(b);
            return img;
        }
        private void SpecPopUp()
        {
            try
            {

                if (cdvOper.Text == "")
                {

                    MPCF.ShowMsgBox("공정입력바랍니다.(Input Operation Please)");
                    return;
                }

                if (txtMatID.Text == "")
                {
                    MPCF.ShowMsgBox("품목입력바랍니다.(Input Material Please)");
                    return;
                }



                frmPopSpecList popup = new frmPopSpecList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                popup.sOper_id = cdvOper.Text;
                popup.sOper_desc = cdvOper.DisplayText;
                popup.sMat_id = txtMatID.Text;
                popup.sMat_desc = txtMatDesc.Text;



                if (popup.ShowDialog() == DialogResult.OK)
                {

                    popup = null;
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void splitCount()
        {
            double dinData = 0;
            double dLower = 0;
            double dUpper = 0;
            int iLotCount = 0;



            if (cdvOper.Text == "OP90040") //PDC(PDV) 리칭인경우만 LOT SPLITE 진행
            {

                spdSplitLotList.ActiveSheet.Columns.Get((int)SPLITE_LOT.NEW_LOT_ID).Width = 170;
                //splitContainer2.Panel2.Enabled = true;


                for (int ispt = 0; ispt < spdSplitLotList.ActiveSheet.RowCount; ispt++)
                {
                    if (txtLotID.Text != "")
                    {
                        if (spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.TYPE].Text != "REWORK" && spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.TYPE].Text != "LOSS")
                        {
                            //20230717 앞으로 진행될것은 L이 없이 들어올것이지만 현재는 _L이 붙어서 들어옴..그래서 강재로 _L인거는 숫자만 붙임.
                            if (spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.NEW_LOT_ID].Text.IndexOf("_L") != -1 || spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.NEW_LOT_ID].Text.IndexOf("_PL") != -1)
                            {
                                spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.NEW_LOT_ID].Text = txtLotID.Text + spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.TYPE].Text.Substring(1, 2);
                            }
                            else
                            {
                                spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.NEW_LOT_ID].Text = txtLotID.Text + spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.TYPE].Text;

                            }


                            spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.QTY].Text = "0";
                            //this.spdSplitLotList_Sheet1.Rows.Get(21).Height = 456F;
                            spdSplitLotList_Sheet1.Rows.Get(ispt).Height = 0;


                        }
                        else
                        {
                            spdSplitLotList_Sheet1.Rows.Get(ispt).Height = 16F;
                            spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.QTY].Text = "0";
                        }
                    }


                    for (int i = 0; i < spdDataCollection.ActiveSheet.RowCount; i++)
                    {



                        if (spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_PASS].Value.ToString().ToUpper() == "TRUE")
                        {

                            //MPCF.Todbl 쓰면 속도 많이 느려짐 ...Convert.ToDouble 로변경(20230717)
                            if (spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC053_VALUE_1].Text.Trim() != "")
                            {
                                dinData = Convert.ToDouble(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.POQC053_VALUE_1].Text);
                            }
                            else
                            {
                                dinData = 0;
                            }

                            if (spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.TYPE].Text != "REWORK" && spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.TYPE].Text != "LOSS")
                            {
                                dLower = Convert.ToDouble(spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.LOWER].Value);
                                dUpper = Convert.ToDouble(spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.UPPER].Value);
                            }



                            if (dinData >= dLower && dinData <= dUpper)
                            {
                                if (spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_REWORK].Value.ToString().ToUpper() != "TRUE" && spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_LOSS].Text.Trim() == "")
                                {
                                    iLotCount = MPCF.ToInt(spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.QTY].Text) + 1;

                                    spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.QTY].Text = iLotCount.ToString();

                                    spdSplitLotList_Sheet1.Rows.Get(ispt).Height = 16F;
                                }

                            }


                        }

                        if (spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_REWORK].Value.ToString().ToUpper() == "TRUE")
                        {
                            if (spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.TYPE].Text == "REWORK")
                            {
                                iLotCount = MPCF.ToInt(spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.QTY].Text) + 1;
                                spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.QTY].Text = iLotCount.ToString();
                            }
                        }

                        if (spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.JUDGE_LOSS].Text.Trim() != "")
                        {
                            if (spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.TYPE].Text == "LOSS")
                            {
                                iLotCount = MPCF.ToInt(spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.QTY].Text) + 1;
                                spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.QTY].Text = iLotCount.ToString();
                            }
                        }



                    }
                }
            }
            else
            {
                for (int ispt = 0; ispt < spdSplitLotList.ActiveSheet.RowCount; ispt++)
                {
                    spdSplitLotList.ActiveSheet.Cells[ispt, (int)SPLITE_LOT.QTY].Text = "0";
                    //this.spdSplitLotList_Sheet1.Rows.Get(21).Height = 456F;
                    spdSplitLotList_Sheet1.Rows.Get(ispt).Height = 0;
                }
            }



        }
        private void ViewSpecLastEditTime(string matid, string oper)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                //  int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = matid;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = oper;

                if (TPDR.GetDataOne("", ref dt, "CQCM0001-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLossInfo);
                    return;
                }

                txtLastSpecTime.Text = dt.Rows[0]["LAST_EDIT_TIME"].ToString();


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private bool DeleteLotHistiry(string sLotId)
        {
            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';



                in_node.AddString("LOT_ID", sLotId);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Delete_Lot_History", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);
                txtLotID.Text = sLotId;

                ViewLotInfo(sLotId);

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
        private void brnReturn_Click(object sender, EventArgs e)
        {
            if (spdLotList_Sheet1.RowCount == 0)
            {
                return;
            }

            //어느정도 안전성확인되서 권한제약 풀음.
            DeleteLotHistiry(spdLotList_Sheet1.Cells[spdLotList_Sheet1.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text);

            /*
            if (MPGV.gsUserGroup == "ADMIN_GROUP" || MPGV.gsUserGroup ==  "USER_ADMIN_GROUP") {
                DeleteLotHistiry(spdLotList_Sheet1.Cells[spdLotList_Sheet1.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text);
            }
            else {
                MPCF.ShowMsgBox("해당ID는 권한이 없습니다.(This ID is have no authority.)");
            }
            */

        }
        private void txtInspectionStatus_TextChanged(object sender, EventArgs e)
        {
            if (txtInspectionStatus.Text == "")
                return;


            if (txtInspectionStatus.Text == "R" || txtInspectionStatus.Text == "H")
            {

                if (txtInspectionStatus.Text == "R")
                {
                    btnHold.Enabled = true;

                }
                else if (txtInspectionStatus.Text == "H")
                {
                    btnHold.Enabled = false;
                }

                btnReceive.Enabled = false;
                cdvInspectionJudgeFlag.Enabled = true;
                txtComment.Enabled = true;

                if (tabControl1.SelectedIndex == 0)
                {
                    btnJudge.Enabled = true;
                }
                else
                {
                    btnJudge.Enabled = false;
                }

                btnProcess.Enabled = true;

                spdLossInfo.ActiveSheet.OperationMode = OperationMode.Normal;
                cdvColSetID.Enabled = true;
                spdDataCollection.ActiveSheet.OperationMode = OperationMode.Normal;
                spdFileRegistration.ActiveSheet.OperationMode = OperationMode.Normal;
            }
            else if (txtInspectionStatus.Text == "C" || txtInspectionStatus.Text == "S" || txtInspectionStatus.Text == "Q")
            {
                if (txtInspectionStatus.Text == "Q")
                {
                    btnReceive.Enabled = true;
                    btnProcess.Enabled = false;
                }
                else
                {
                    btnReceive.Enabled = false;
                    btnProcess.Enabled = true;
                }

                cdvInspectionJudgeFlag.Enabled = false;
                txtComment.Enabled = false;
                btnJudge.Enabled = false;

                btnHold.Enabled = false;

                spdLossInfo.ActiveSheet.OperationMode = OperationMode.ReadOnly;
                cdvColSetID.Enabled = false;
                spdDataCollection.ActiveSheet.OperationMode = OperationMode.ReadOnly;
                spdFileRegistration.ActiveSheet.OperationMode = OperationMode.ReadOnly;


                //    spdLossInfo.ActiveSheet.OperationMode = OperationMode.Normal;
                //    cdvColSetID.Enabled = false;
                //   spdDataCollection.ActiveSheet.OperationMode = OperationMode.Normal;
                //   spdFileRegistration.ActiveSheet.OperationMode = OperationMode.Normal;

            }
        }
        private void cdvInspectionJudgeFlag_ButtonPress(object sender, EventArgs e)
        {/*
            cdvInspectionJudgeFlag.Init();
            MPCF.InitListView(cdvInspectionJudgeFlag.GetListView);
            cdvInspectionJudgeFlag.Columns.Add("Judge", 50, HorizontalAlignment.Left);
            cdvInspectionJudgeFlag.Columns.Add("Desc", 50, HorizontalAlignment.Left);
            cdvInspectionJudgeFlag.SelectedSubItemIndex = 0;
            cdvInspectionJudgeFlag.DisplaySubItemIndex = 1;

            if (BASLIST.ViewGCMDataList(cdvInspectionJudgeFlag.GetListView, '1', CSGC.CP_GCM_INSP_JUDGE_FLAG, -1, null, "", true, -1, -1, null, null) == false)
            {
                return;
            }
            */
        }
        private void rdoStSpec_CheckedChanged(object sender, EventArgs e)
        {
            ViewInspSpec();
        }
        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (Collect_Inspection_Data() == false)
                {
                    return;
                }
                else
                {
                    //저장되었습니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(576));

                }

                //재조회
                SelectedItemChangedByColSet();
                //LOSS 정보 조회
                ViewInspectionLossInfo(txtInspID.Text);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvColSetID_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            SelectedItemChangedByColSet();
        }
        private void tpgInspCommon_Click(object sender, EventArgs e)
        {

        }
        private void cdvInspectionType_ButtonPress(object sender, EventArgs e)
        {
            /*
            cdvInspectionType.Init();
            MPCF.InitListView(cdvInspectionType.GetListView);
            cdvInspectionType.Columns.Add("InspType", 50, HorizontalAlignment.Left);
            cdvInspectionType.SelectedSubItemIndex = 0;
            cdvInspectionType.DisplaySubItemIndex = 0;
            

            if (BASLIST.ViewGCMDataList(cdvInspectionType.GetListView, '1', CSGC.CP_GCM_INSP_TYPE_NOT_IQC, -1, null, "", true, -1, -1, null, null) == false)
            {
                return;
            }
            */


        }
        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                string sLotId = "";

                if (e.KeyChar == (char)13)
                {
                    if (MPCF.Trim(txtLotID.Text) == "")
                        return;

                    txtLotID.Text = MPCF.Trim(txtLotID.Text).ToUpper();

                    if (CheckCondition(CSGC.CHECK.VIEW) == false)
                        return;

                    sLotId = txtLotID.Text;
                    ClearList("LOT_INFO");

                    ViewLotInfo(sLotId);

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void button1_Click(object sender, EventArgs e)
        {
            cdvInspectionType.Text = "";
        }
        private void cdvInspectionJudgeFlag_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            if (MPCF.Trim(cdvInspectionJudgeFlag.Text) == "")
                return;


        }
        private void rdoDualSpec_CheckedChanged(object sender, EventArgs e)
        {
            ViewInspSpec();
        }
        private void btnFileManager_Click(object sender, EventArgs e)
        {
            if (txtLotID.Text.Trim().Length != 0)
            {


                frmPopFtpUpDown popup = new frmPopFtpUpDown();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.g_PopYn = "Y";
                popup.g_LotId = txtLotID.Text;
                popup.g_Mat_id = txtMatID.Text;
                popup.g_Mat_Desc = txtMatDesc.Text;
                popup.g_Area_Id = cdvDept.Text;
                popup.g_SearchType = "B";

                if (popup.ShowDialog() == DialogResult.OK)
                {

                    popup = null;
                }
                else
                {
                    return;
                }


            }
        }
        private void btnJudge_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.ShowMsgBox(MPCF.GetMessage(503), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                {
                    return;
                }

                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (Collect_Inspection_Data() == false)
                {
                    return;
                }


                string sLotID;

                //Vaildation check
                if (VaildationCheckJudge() == false)
                {
                    return;
                }



                splitCount();



                if (Inspection_Judge() == false)
                {
                    return;
                }

                //재조회
                sLotID = spdLotList.ActiveSheet.GetValue(0, (int)LOT_INFO.LOT_ID).ToString();
                ViewLotInfo(sLotID);
                txtLotID.Focus();
                txtLotID.SelectAll();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdLossInfo_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {



        }
        private void spdDataCollection_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            // if (!b_loaded)
            //     return;


            int iRow = e.Row;
            int iCol = e.Column;

            // b_loaded = false;
            if (e.Column == (int)COLLECTION_DATA.JUDGE_PASS)
            {
                if (spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value.ToString().ToUpper() == "TRUE")
                {
                    spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.JUDGE_LOSS].Value = " ";
                    spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.JUDGE_REWORK].Value = false;
                }
                else if (spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value.ToString().ToUpper() == "FALSE")
                {
                    spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value = true;
                }
            }
            else if (e.Column == (int)COLLECTION_DATA.JUDGE_REWORK)
            {
                if (spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value.ToString().ToUpper() == "TRUE")
                {
                    //spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.JUDGE_LOSS].Value = " ";
                    spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.JUDGE_PASS].Value = false;
                }
                else if (spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value.ToString().ToUpper() == "FALSE")
                {
                    if (spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.JUDGE_LOSS].Value.ToString() == " ")
                    {
                        spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value = true;
                    }
                }
            }

            // b_loaded = true;
        }
        private void spdDataCollection_Change(object sender, ChangeEventArgs e)
        {

            if (e.Column == (int)COLLECTION_DATA.POQC053_VALUE_1)
            {
                if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[e.Row, e.Column].Value) != true)
                {
                    spdDataCollection.ActiveSheet.Cells[e.Row, e.Column].Text = "";
                }
            }

            //속도떔시 주석
            // if (!b_loaded)
            //     return;

            /*
            int iRow = e.Row;
            int iCol = e.Column;

            double dInputValue;

            bool bSpecOut;

            //  b_loaded = false;

            if (e.Column == (int)COLLECTION_DATA.JUDGE_LOSS)
            {
                if (spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value.ToString().Trim() != "")
                {
                    spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.JUDGE_PASS].Value = false;
                    //spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.JUDGE_REWORK].Value = false;
                }
            }
            else if (iCol >= INPUT_COL_MIN_COUNT && iCol <= INPUT_COL_MAX_COUNT)
            {
                bSpecOut = false;

                if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value) == true)
                {
                    dInputValue = MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value);
                    //UPPER SPEC
                    if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, iCol].Value) == true)
                    {
                        if (dInputValue > MPCF.ToDbl(spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, iCol].Value))
                        {
                            bSpecOut = true;
                        }
                    }

                    //LOWER SPEC
                    if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, iCol].Value) == true)
                    {
                        if (dInputValue < MPCF.ToDbl(spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, iCol].Value))
                        {
                            bSpecOut = true;
                        }
                    }

                    if (bSpecOut)
                    {
                        spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.Red;
                    }
                    else
                    {
                        spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.White;
                    }
                }
                else
                {
                    spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.White;
                }

            }
            */
            // b_loaded = true;

        }
        private void spdFileRegistration_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            fnFileSelectionChagned();
        }
        private void spdDataCollection_EditModeOff(object sender, EventArgs e)
        {

            int iActiveRow = spdDataCollection.ActiveSheet.ActiveRowIndex;
            int iActiveCol = spdDataCollection.ActiveSheet.ActiveColumnIndex;
            int iRowCount = spdDataCollection.ActiveSheet.RowCount;

            //컬럼 1,2,3, (4), 1,2,3,(4), (1) , 1,2,3,(4), 1,2,3,(4)

            if (iActiveCol == (int)COLLECTION_DATA.POQC033_VALUE_1 || iActiveCol == (int)COLLECTION_DATA.POQC033_VALUE_2 || iActiveCol == (int)COLLECTION_DATA.POQC033_VALUE_3 ||
                  iActiveCol == (int)COLLECTION_DATA.POQC006_VALUE_1 || iActiveCol == (int)COLLECTION_DATA.POQC006_VALUE_2 || iActiveCol == (int)COLLECTION_DATA.POQC006_VALUE_3 ||
                   iActiveCol == (int)COLLECTION_DATA.POQC029_VALUE_1 || iActiveCol == (int)COLLECTION_DATA.POQC029_VALUE_2 || iActiveCol == (int)COLLECTION_DATA.POQC029_VALUE_3 ||
                    iActiveCol == (int)COLLECTION_DATA.POQC030_VALUE_1 || iActiveCol == (int)COLLECTION_DATA.POQC030_VALUE_2 || iActiveCol == (int)COLLECTION_DATA.POQC030_VALUE_3
                  )
            {
                //오른쪽 한칸
                spdDataCollection.ActiveSheet.SetActiveCell(iActiveRow, iActiveCol + 1);
            }
            else
            {
                if (iActiveCol == (int)COLLECTION_DATA.POQC033_VALUE_4)
                {
                    // 같은 검사항목의 다음Row의  첫칸 이동
                    if (iRowCount >= iActiveRow + 1)
                    {
                        spdDataCollection.ActiveSheet.SetActiveCell(iActiveRow + 1, (int)COLLECTION_DATA.POQC033_VALUE_1);
                    }
                }
                else if (iActiveCol == (int)COLLECTION_DATA.POQC006_VALUE_4)
                {
                    // 같은 검사항목의 다음Row의  첫칸 이동
                    if (iRowCount >= iActiveRow + 1)
                    {
                        spdDataCollection.ActiveSheet.SetActiveCell(iActiveRow + 1, (int)COLLECTION_DATA.POQC006_VALUE_1);
                    }
                }
                else if (iActiveCol == (int)COLLECTION_DATA.POQC052_VALUE_1)
                {
                    // 같은 검사항목의 다음Row의  첫칸 이동
                    if (iRowCount >= iActiveRow + 1)
                    {
                        spdDataCollection.ActiveSheet.SetActiveCell(iActiveRow + 1, (int)COLLECTION_DATA.POQC052_VALUE_1);
                    }
                }
                else if (iActiveCol == (int)COLLECTION_DATA.POQC029_VALUE_4)
                {
                    // 같은 검사항목의 다음Row의  첫칸 이동
                    if (iRowCount >= iActiveRow + 1)
                    {
                        spdDataCollection.ActiveSheet.SetActiveCell(iActiveRow + 1, (int)COLLECTION_DATA.POQC029_VALUE_1);
                    }
                }
                else if (iActiveCol == (int)COLLECTION_DATA.POQC030_VALUE_4)
                {
                    // 같은 검사항목의 다음Row의  첫칸 이동
                    if (iRowCount >= iActiveRow + 1)
                    {
                        spdDataCollection.ActiveSheet.SetActiveCell(iActiveRow + 1, (int)COLLECTION_DATA.POQC030_VALUE_1);
                    }
                }
                else if (iActiveCol == (int)COLLECTION_DATA.POQC053_VALUE_1)
                {
                    // 같은 검사항목의 다음Row의  첫칸 이동
                    if (iRowCount >= iActiveRow + 1)
                    {
                        spdDataCollection.ActiveSheet.SetActiveCell(iActiveRow + 1, (int)COLLECTION_DATA.POQC053_VALUE_1);
                        // splitCount();
                    }
                }

            }

        }
        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tabControl1.SelectedIndex == 0)
            {
                if (txtInspectionStatus.Text == "R" || txtInspectionStatus.Text == "H")
                {
                    if (txtInspectionStatus.Text == "R")
                    {
                        btnHold.Enabled = true;
                    }
                    else if (txtInspectionStatus.Text == "H")
                    {
                        btnHold.Enabled = false;
                    }
                    btnJudge.Enabled = true;
                }
                else if (txtInspectionStatus.Text == "Q" || txtInspectionStatus.Text == "S" || txtInspectionStatus.Text == "C")
                {
                    btnJudge.Enabled = false;
                    btnHold.Enabled = false;
                }
                if (cdvOper.Text == "OP90040")
                {
                    splitCount();
                }
            }
            else
            {
                btnHold.Enabled = false;
                btnJudge.Enabled = false;
            }



        }
        private void cdvReworkOper_ButtonPress(object sender, EventArgs e)
        {

        }
        private void spdDataCollection_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.Row < 0)
                {
                    return;
                }

                if (e.ColumnHeader == true)
                {
                    return;
                }

                for (int i = 0; i < spdDataCollection.ActiveSheet.RowCount; i++)
                {
                    spdDataCollection.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdDataCollection.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);
            }
            catch
            {

            }
        }
        private void btnSpec_Click(object sender, EventArgs e)
        {
            SpecPopUp();

        }
        private void btnPop_Click(object sender, EventArgs e)
        {
            try
            {

                frmPopInspectionLotList popup = new frmPopInspectionLotList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                //popup.sSub_area_id = cdvWorkPlace.Text;
                // popup.sSub_area_desc = cdvWorkPlace.DisplayText;
                popup.sOper_id = cdvOper.Text;
                popup.sOper_desc = cdvOper.DisplayText;


                if (popup.ShowDialog() == DialogResult.OK)
                {
                    if (popup.sLot_id != "")
                    {
                        txtLotID.Text = popup.sLot_id;
                        cdvOper.Text = popup.sOper_id;
                        cdvOper.DisplayText = popup.sOper_desc;

                        if (MPCF.Trim(txtLotID.Text) != "")
                        {
                            ViewLotInfo(txtLotID.Text);
                        }
                    }

                    popup = null;
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnReceive_Click(object sender, EventArgs e)
        {
            string sLotID;
            try
            {
                if (Update_Inspection_Status('1') == false)
                    return;


                //재조회
                sLotID = spdLotList.ActiveSheet.GetValue(0, (int)LOT_INFO.LOT_ID).ToString();
                ViewLotInfo(sLotID);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        private void cdvWorkGroup_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvWorkGroup.Text) != "")
                {
                    ViewWorkerList();
                }
                else
                {
                    MPCF.ClearList(spdWorkerList);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvWorkGroup_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvWorkGroup.Init();
                MPCF.InitListView(cdvWorkGroup.GetListView);
                cdvWorkGroup.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWorkGroup.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWorkGroup.SelectedSubItemIndex = 0;
                cdvWorkGroup.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvWorkGroup.GetListView, '1', CSGC.CP_GCM_WORKER_GROUP) == false)
                {
                    return;
                }

                cdvWorkGroup.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void frmTranInspectionRegistrationPDC_Load(object sender, EventArgs e)
        {
            cdvWorkGroup.Text = "A";
            cdvDept.Text = CSGC.CP_AREA_PDC;

            defModelData = new DefaultSheetDataModel(0, spdDataCollection.ActiveSheet.Columns.Count);
            spdDataCollection.ActiveSheet.Models.Data = defModelData;
            this.defModelData.Changed += new SheetDataModelEventHandler(this.defModelData_Changed);

            // FarPoint.Win.Spread.InputMap inputmap;
            // inputmap = spdDataCollection.GetInputMap(FarPoint.Win.Spread.InputMapMode.WhenAncestorOfFocused);
            // inputmap.Put(new FarPoint.Win.Spread.Keystroke(Keys.Enter, Keys.None), FarPoint.Win.Spread.SpreadActions.MoveToNextColumn);



        }
        private void defModelData_Changed(object sender, FarPoint.Win.Spread.Model.SheetDataModelEventArgs e)
        {
            if (!b_allow_changed)
                return;


            int iRow = e.Row;
            int iCol = e.Column;

            double dInputValue;

            string s_spec_out_type;


            if (e.Column == (int)COLLECTION_DATA.JUDGE_LOSS)
            {

                if (spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value.ToString().Trim() != "")
                {
                    spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.JUDGE_PASS].Value = false;
                    //spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.JUDGE_REWORK].Value = false;
                }
            }
            else if (iCol >= INPUT_COL_MIN_COUNT && iCol <= INPUT_COL_MAX_COUNT)
            {
                //bSpecOut = false;

                s_spec_out_type = "3";

                if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value) == true)
                {
                    dInputValue = MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value);
                    //UPPER SPEC
                    if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, iCol].Value) == true)
                    {
                        if (dInputValue > MPCF.ToDbl(spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, iCol].Value))
                        {
                            s_spec_out_type = "1";
                        }
                    }

                    //LOWER SPEC
                    if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, iCol].Value) == true)
                    {
                        if (dInputValue < MPCF.ToDbl(spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, iCol].Value))
                        {
                            s_spec_out_type = "2";
                        }
                    }


                    if (s_spec_out_type == "1")
                    {
                        spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.FromArgb(51, 102, 255);
                    }
                    else if (s_spec_out_type == "2")
                    {
                        spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.Red;
                    }
                    else if (s_spec_out_type == "3")
                    {
                        spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.White;
                    }

                }
                else
                {
                    spdDataCollection.ActiveSheet.Cells[iRow, iCol].BackColor = Color.White;
                }

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

                /*
                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return;
                }*/

                viewOperList(cdvOper.GetListView);

                cdvOper.InsertEmptyRow(0, 1);
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
        private void btnHold_Click(object sender, EventArgs e)
        {
            try
            {
                string sLotID;

                //Vaildation check
                if (VaildationCheckHold() == false)
                {
                    return;
                }


                if (Update_Inspection_Status('2') == false)
                    return;


                //재조회
                sLotID = spdLotList.ActiveSheet.GetValue(0, (int)LOT_INFO.LOT_ID).ToString();
                ViewLotInfo(sLotID);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdFileRegistration_ButtonClicked_1(object sender, EditorNotifyEventArgs e)
        {
            if (e.Column == (int)FILEUPLOAD.REGIST)
            {

                //파일등록 벨리데이션

                if (txtInspID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(478));
                    txtLotID.Focus();
                    return;
                }

                if (spdFileRegistration.ActiveSheet.ActiveRowIndex < 0)
                    return;




                long lengthKByte;
                string fullPath = "";
                FileInfo finfo;

                //Focused Row
                int iActiveRow = spdFileRegistration.ActiveSheet.ActiveRowIndex;


                string sFileNo = MPCF.Trim(spdFileRegistration.ActiveSheet.Cells[iActiveRow, (int)FILEUPLOAD.FILE_NO].Value.ToString());
                string sImageCode = MPCF.Trim(spdFileRegistration.ActiveSheet.Cells[iActiveRow, (int)FILEUPLOAD.TITLE].Value.ToString());


                ofdFile.Reset();
                ofdFile.Filter = "Images Files(*.jpg; *.jpeg; *.bmp; *.png)|*.jpg;*.jpeg;*.bmp;*.png";
                ofdFile.DefaultExt = "jpg";

                if (ofdFile.ShowDialog() == DialogResult.OK)
                {

                    fullPath = ofdFile.FileName;
                    //pictureBox1.Image = Image.FromFile(openFileDialog1.FileName);

                    finfo = new FileInfo(fullPath);

                    lengthKByte = finfo.Length / 1024;
                    if (lengthKByte >= 2048)
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(504));
                        return;

                    }
                    fnRegistrationFile(finfo, sFileNo, sImageCode, txtInspID.Text);   // FileNo  , ImageCode(CMF_1)   // 검사에서 논리적인 Key ( File_No, CMF_1 )


                    //파일 리스트 조회
                    ViewInspectionFile(txtInspID.Text);

                    spdFileRegistration.ActiveSheet.ActiveRowIndex = iActiveRow;
                    fnFileSelectionChagned();

                }
            }
        }
        private void txtLastSpecTime_Click(object sender, EventArgs e)
        {
            SpecPopUp();
        }
        #endregion
    }

}
