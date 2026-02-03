using CUS_COM;
using FarPoint.Win.Chart;
using FarPoint.Win.Spread;
using FarPoint.Win.Spread.Model;
using Miracom.CliFrx;
using Miracom.DNMCore;
using Miracom.MESCore;
using Miracom.TRSCore;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CUS_QCM
{
    public partial class frmTranInspectionRegistrationDaewonTech : CUS_COM.frmTranForm06
    {
        public frmTranInspectionRegistrationDaewonTech()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "
        private enum LOT_INFO
        {
            LOT_ID,                 // 1 : LOT ID
            MAT_ID,                 // 2 : 제품코드
            MAT_DESC,               // 3 : 제품명       
            FLOW,                      //4 : Flow코드  
            CREATE_DATE,            // 5 : 생성일자   
            INSP_QTY,                       // 6 : 생산수량
            UNIT_1

        }
        private enum COLLECTION_DATA
        {
            UNIT_SEQ,
            CIQC12_VALUE_1, //외경#1 
            CIQC12_VALUE_2, //외경#1

            CIQC13_VALUE_1, //외경#2
            CIQC13_VALUE_2, //외경#2

            CIQC05_VALUE_1, //내경
            CIQC05_VALUE_2, //내경

            CIQC06_VALUE_1,  //높이#1
            CIQC06_VALUE_2,  //높이#2
            CIQC06_VALUE_3,  //높이#3
            CIQC06_VALUE_4,  //높이#4    

            CIQC07_VALUE_1,  //단높이#1
            CIQC07_VALUE_2,  //단높이#2
            CIQC07_VALUE_3,  //단높이#3
            CIQC07_VALUE_4,  //단높이#4

            CIQC08_VALUE_1,  //두께#1
            CIQC08_VALUE_2,  //두께#2
            CIQC08_VALUE_3,  //두께#3
            CIQC08_VALUE_4,  //두께#4
            CIQC08_VALUE_5,  //두께#5

            CIQC14_VALUE_1, //중량

            CIQC09_VALUE_1, //밀도

            CIQC04_VALUE_1, //경도
            CIQC04_VALUE_2, //경도

            CIQC11_VALUE_1, //압축강도
            CIQC11_VALUE_2, //압축강도

            CIQC072_VALUE_1, //진밀도
            CIQC072_VALUE_2  //진밀도


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
        #endregion

        #region " Variable Definition "
        DefaultSheetDataModel defModel;

        bool b_allow_changed;

        string sDawonCollectionSet = "";

        private const int INPUT_COL_MIN_COUNT = 1;
        private const int INPUT_COL_MAX_COUNT = 28;
        //private const int VALUE_START_COL = 13;
        //private const int DEFAULT_COL_COUNT = 13;
        //private clsDerivedCharList cls_derived_char_list;

        private const int MAX_DATA_COUNT = 5000;

        #endregion

        #region " Function Definition "
        private void InitControl()
        {
            try
            {
                /*ListView lisTmp = new ListView();
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

                }
                */


                // b_loaded = true;

                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnJudge.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnReceive.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnHold.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSpec.Anchor = AnchorStyles.Top | AnchorStyles.Right;


                if (string.Equals(cdvDept.Text, CSGC.CP_AREA_CTM))
                {
                    sDawonCollectionSet = "CPQ90001";
                }
                else if (string.Equals(cdvDept.Text, CSGC.CP_AREA_GRT))
                {
                    sDawonCollectionSet = "GPQ90001";
                }
                else if (string.Equals(cdvDept.Text, CSGC.CP_AREA_PDC))
                {
                    sDawonCollectionSet = "PPQ90001";
                }
                else
                {
                    sDawonCollectionSet = "CPQ90001";
                }
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

                    MPCF.FieldClear(panLotInfo, txtLotID);
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
        private bool initReworkOperList(ListView listView)
        {

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
        public void ViewLotInfo(string sLot_ID)
        {

            try
            {

                if (ViewColsetIdCheck(sLot_ID) == false)
                {
                    return;
                }



                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                MPCF.ClearList(spdLotList);

                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", sLot_ID); //Lot ID (WIP LotID 혹은 DLV LotID )

                in_node.AddString("AREA_ID", cdvDept.Text);
                //in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
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




                txtMatID.Text = out_node.GetString("MAT_ID");
                txtMatDesc.Text = out_node.GetString("MAT_DESC");
                txtMatVer.Text = Convert.ToString(out_node.GetInt("MAT_VER"));
                txtInspID.Text = out_node.GetString("INSP_ID"); //검사 ID
                cdvInspOper.Text = out_node.GetString("INSP_OPER");
                cdvInspOper.DisplayText = out_node.GetString("INSP_OPER_DESC");

                cdvDept.Text = out_node.GetString("AREA_ID");
                cdvDept.DisplayText = out_node.GetString("AREA_DESC");
                // cdvWorkPlace.Text = out_node.GetString("SUB_AREA_ID");
                //cdvWorkPlace.DisplayText = out_node.GetString("SUB_AREA_DESC");

                txtInspectionStatus.Text = out_node.GetChar("INSP_STATUS").ToString();
                txtInspectionStatusDesc.Text = out_node.GetString("INSP_STATUS_DESC").ToString();
                cdvInspectionJudgeFlag.Text = out_node.GetChar("INSP_JUDGE_FLAG").ToString();
                cdvInspectionJudgeFlag.DisplayText = out_node.GetString("INSP_JUDGE_DESC");

                txtComment.Text = out_node.GetString("INSP_COMMENT");

                cdvColSetID.Text = out_node.GetString("COL_SET_ID");
                cdvColSetID.DisplayText = out_node.GetString("COL_SET_DESC");

                GetJudgeFlagByArea(cdvInspectionJudgeFlag.GetListView, cdvInspOper.Text, cdvInspectionType.Text);
                cdvInspectionJudgeFlag.InsertEmptyRow(0, 1);

                // initCombobox(); //Loss Combobox
                initReworkOperList(cdvReworkOper.GetListView);

                //파일 리스트 조회
                ViewInspectionFile(txtInspID.Text);

                //Loss 정보 조회
                ViewInspectionLossInfo(txtInspID.Text, cdvInspOper.Text);

                //검사자 대상 조회;
                ViewWorkerList();

                //SPEC 조회
                ViewInspSpec();

                //Data 조회
                SelectedItemChangedByColSet();

                ViewSpecLastEditTime(txtMatID.Text, cdvInspOper.Text);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
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

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = txtMatID.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvInspOper.Text;


                if (TPDR.GetDataOne("", ref dt, "CQCM2003-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }


                for (i = 0; i < dt.Rows.Count; i++)
                {

                    if (dt.Rows[i]["CHAR_ID"].ToString() == "CIQC12")
                    {
                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 1).Value = "외경#1";

                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 1].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 1].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 1].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 2).Value = "외경#1";
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 2].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 2].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 2].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "CIQC13")
                    {
                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 3).Value = "외경#2";

                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 3].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 3].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 3].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 4).Value = "외경#2";
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 4].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 4].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 4].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "CIQC05")
                    {
                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 5).Value = "내경";

                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 5].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 5].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 5].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 6).Value = "내경";
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 6].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 6].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 6].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "CIQC06")
                    {
                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 7).Value = "높이";

                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 7].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 7].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 7].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 8).Value = "높이";
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 8].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 8].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 8].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 9).Value = "높이";
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 9].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 9].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 9].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 10).Value = "높이";
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 10].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 10].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 10].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "CIQC07")
                    {
                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 11).Value = "단높이";

                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 11].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 11].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 11].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 12).Value = "단높이";
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 12].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 12].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 12].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 13).Value = "단높이";
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 13].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 13].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 13].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 14).Value = "단높이";
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 14].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 14].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 14].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "CIQC08")
                    {
                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 15).Value = "두께";

                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 15].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 15].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 15].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 16).Value = "두께";
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 16].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 16].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 16].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 17).Value = "두께";
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 17].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 17].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 17].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 18).Value = "두께";
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 18].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 18].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 18].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 19).Value = "두께";
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 19].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 19].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 19].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "CIQC14")
                    {
                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 20).Value = "중량";

                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 20].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 20].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 20].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();


                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "CIQC09")
                    {
                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 21).Value = "밀도";

                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 21].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 21].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 21].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();


                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "CIQC04")
                    {
                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 22).Value = "경도";

                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 22].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 22].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 22].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 23).Value = "경도";
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 23].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 23].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 23].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "CIQC11")
                    {
                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 24).Value = "압축강도";

                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 24].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 24].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 24].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 25).Value = "압축강도";
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 25].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 25].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 25].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "CIQC072")
                    {
                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 26).Value = "진밀도";

                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 26].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 26].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 26].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 27).Value = "진밀도";
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[2, 27].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[3, 27].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollection.ActiveSheet.ColumnHeader.Cells[4, 27].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

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

            try
            {
                b_allow_changed = false;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_ID";
                dvcArgu[1].sCondition_Value = txtInspID.Text;


                if (TPDR.GetDataOne("", ref dt, "CQCM2007-001", dvcArgu, false, false, ref sSql) == false)
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


                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC12_VALUE_1].Value = dt.Rows[i]["CIQC12_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC12_VALUE_2].Value = dt.Rows[i]["CIQC12_VALUE_2"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC13_VALUE_1].Value = dt.Rows[i]["CIQC13_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC13_VALUE_2].Value = dt.Rows[i]["CIQC13_VALUE_2"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC05_VALUE_1].Value = dt.Rows[i]["CIQC05_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC05_VALUE_2].Value = dt.Rows[i]["CIQC05_VALUE_2"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC06_VALUE_1].Value = dt.Rows[i]["CIQC06_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC06_VALUE_2].Value = dt.Rows[i]["CIQC06_VALUE_2"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC06_VALUE_3].Value = dt.Rows[i]["CIQC06_VALUE_3"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC06_VALUE_4].Value = dt.Rows[i]["CIQC06_VALUE_4"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC07_VALUE_1].Value = dt.Rows[i]["CIQC07_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC07_VALUE_2].Value = dt.Rows[i]["CIQC07_VALUE_2"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC07_VALUE_3].Value = dt.Rows[i]["CIQC07_VALUE_3"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC07_VALUE_4].Value = dt.Rows[i]["CIQC07_VALUE_4"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC08_VALUE_1].Value = dt.Rows[i]["CIQC08_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC08_VALUE_2].Value = dt.Rows[i]["CIQC08_VALUE_2"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC08_VALUE_3].Value = dt.Rows[i]["CIQC08_VALUE_3"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC08_VALUE_4].Value = dt.Rows[i]["CIQC08_VALUE_4"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC08_VALUE_5].Value = dt.Rows[i]["CIQC08_VALUE_5"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC14_VALUE_1].Value = dt.Rows[i]["CIQC14_VALUE_1"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC09_VALUE_1].Value = dt.Rows[i]["CIQC09_VALUE_1"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC04_VALUE_1].Value = dt.Rows[i]["CIQC04_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC04_VALUE_2].Value = dt.Rows[i]["CIQC04_VALUE_2"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC11_VALUE_1].Value = dt.Rows[i]["CIQC11_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC11_VALUE_2].Value = dt.Rows[i]["CIQC11_VALUE_2"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC072_VALUE_1].Value = dt.Rows[i]["CIQC072_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC072_VALUE_2].Value = dt.Rows[i]["CIQC072_VALUE_2"];

                }

                //속도저하로 임시주석
                //ApplyColorBySpecOut();
                b_allow_changed = true;
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
                b_allow_changed = false;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                DataTable dt = null;
                string sSql = "";

                //dvcArgu[0].sCondition_ID = "FACTORY";
                // dvcArgu[0].sCondition_Value =  MPGV.gsFactory;

                // dvcArgu[1].sCondition_ID = "INSP_ID";
                // dvcArgu[1].sCondition_Value = txtInspID.Text;

                dvcArgu[0].sCondition_ID = "LOT_ID";
                dvcArgu[0].sCondition_Value = txtLotID.Text;


                if (TPDR.GetDataOne("", ref dt, "CQCM2007-002", dvcArgu, false, false, ref sSql) == false)
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
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC12_VALUE_1].Value = dt.Rows[i]["CIQC12_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC12_VALUE_2].Value = dt.Rows[i]["CIQC12_VALUE_2"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC13_VALUE_1].Value = dt.Rows[i]["CIQC13_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC13_VALUE_2].Value = dt.Rows[i]["CIQC13_VALUE_2"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC05_VALUE_1].Value = dt.Rows[i]["CIQC05_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC05_VALUE_2].Value = dt.Rows[i]["CIQC05_VALUE_2"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC06_VALUE_1].Value = dt.Rows[i]["CIQC06_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC06_VALUE_2].Value = dt.Rows[i]["CIQC06_VALUE_2"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC06_VALUE_3].Value = dt.Rows[i]["CIQC06_VALUE_3"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC06_VALUE_4].Value = dt.Rows[i]["CIQC06_VALUE_4"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC07_VALUE_1].Value = dt.Rows[i]["CIQC07_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC07_VALUE_2].Value = dt.Rows[i]["CIQC07_VALUE_2"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC07_VALUE_3].Value = dt.Rows[i]["CIQC07_VALUE_3"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC07_VALUE_4].Value = dt.Rows[i]["CIQC07_VALUE_4"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC08_VALUE_1].Value = dt.Rows[i]["CIQC08_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC08_VALUE_2].Value = dt.Rows[i]["CIQC08_VALUE_2"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC08_VALUE_3].Value = dt.Rows[i]["CIQC08_VALUE_3"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC08_VALUE_4].Value = dt.Rows[i]["CIQC08_VALUE_4"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC08_VALUE_5].Value = dt.Rows[i]["CIQC08_VALUE_5"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC14_VALUE_1].Value = dt.Rows[i]["CIQC14_VALUE_1"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC09_VALUE_1].Value = dt.Rows[i]["CIQC09_VALUE_1"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC04_VALUE_1].Value = dt.Rows[i]["CIQC04_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC04_VALUE_2].Value = dt.Rows[i]["CIQC04_VALUE_2"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC11_VALUE_1].Value = dt.Rows[i]["CIQC11_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC11_VALUE_2].Value = dt.Rows[i]["CIQC11_VALUE_2"];

                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC072_VALUE_1].Value = dt.Rows[i]["CIQC072_VALUE_1"];
                    spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC072_VALUE_2].Value = dt.Rows[i]["CIQC072_VALUE_2"];


                }
                // MPCF.FitColumnHeader(spdDataCollection);

                b_allow_changed = true;

                return true;
                //return bResult;

            }
            catch (Exception ex)
            {
                b_allow_changed = true;
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
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
        private bool Inspection_Judge()
        {

            TRSNode in_node = new TRSNode("INSPECTION_JUDGE_IN");
            TRSNode out_node = new TRSNode("INSPECTION_JUDGE_OUT");
            TRSNode worker_list;

            string sLotID;
            int iWrkRow = 0;
            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1'; //대원검사 판정

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
                //double dLotQty = 0;
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
        private bool Collect_Inspection_Data()
        {

            TRSNode in_node = new TRSNode("COLLECT_LOT_DATA_IN");
            TRSNode out_node = new TRSNode("COLLECT_LOT_DATA_OUT");
            TRSNode data_list;
            TRSNode loss_list;

            int iLossRow = 0;
            int iRowCnt = 0;
            // int i_value_start = (int)COLLECTION_DATA.VALUE_START_COL;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", MPCF.Trim(txtLotID.Text));
                in_node.AddString("MAT_ID", MPCF.Trim(txtMatID.Text));
                in_node.AddInt("MAT_VER", MPCF.ToInt(txtMatVer.Text));

                in_node.AddString("COL_SET_ID", MPCF.Trim(cdvColSetID.Text));
                in_node.AddInt("COL_SET_VERSION", MPCF.Trim(txtColSetVer.Text));

                in_node.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));
                in_node.AddInt("INSP_SEQ", 1);



                iRowCnt = spdDataCollection.ActiveSheet.RowCount;

                //대원검사의 경우 검사항목 코드를 고정시킴.
                //외경#1
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "CIQC12");
                    data_list.AddInt("CHAR_SEQ", 1);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 2);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC12_VALUE_1].Text);
                    data_list.AddString("VALUE_2", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC12_VALUE_2].Text);


                }
                //외경#2
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "CIQC13");
                    data_list.AddInt("CHAR_SEQ", 2);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 2);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC13_VALUE_1].Text);
                    data_list.AddString("VALUE_2", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC13_VALUE_2].Text);

                }
                //내경
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "CIQC05");
                    data_list.AddInt("CHAR_SEQ", 3);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 2);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC05_VALUE_1].Value.ToString());
                    data_list.AddString("VALUE_2", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC05_VALUE_2].Value.ToString());
                }
                //높이
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "CIQC06");
                    data_list.AddInt("CHAR_SEQ", 4);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 1);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC06_VALUE_1].Text);
                    data_list.AddString("VALUE_2", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC06_VALUE_2].Text);
                    data_list.AddString("VALUE_3", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC06_VALUE_3].Text);
                    data_list.AddString("VALUE_4", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC06_VALUE_4].Text);

                }
                //단높이
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "CIQC07");
                    data_list.AddInt("CHAR_SEQ", 5);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 2);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC07_VALUE_1].Text);
                    data_list.AddString("VALUE_2", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC07_VALUE_2].Text);
                    data_list.AddString("VALUE_3", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC07_VALUE_3].Text);
                    data_list.AddString("VALUE_4", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC07_VALUE_4].Text); 

                }

                //두께
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "CIQC08");
                    data_list.AddInt("CHAR_SEQ", 6);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 2);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC08_VALUE_1].Text);
                    data_list.AddString("VALUE_2", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC08_VALUE_2].Text);
                    data_list.AddString("VALUE_3", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC08_VALUE_3].Text);
                    data_list.AddString("VALUE_4", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC08_VALUE_4].Text);
                    data_list.AddString("VALUE_5", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC08_VALUE_5].Text);

                }

                //중량
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "CIQC14");
                    data_list.AddInt("CHAR_SEQ", 7);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 1);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC14_VALUE_1].Text);


                }

                //밀도
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "CIQC09");
                    data_list.AddInt("CHAR_SEQ", 8);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 1);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC09_VALUE_1].Text);

                }

                //경도
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "CIQC04");
                    data_list.AddInt("CHAR_SEQ", 9);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 2);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC04_VALUE_1].Text);
                    data_list.AddString("VALUE_2", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC04_VALUE_2].Text);

                }

                //압축강도
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "CIQC11");
                    data_list.AddInt("CHAR_SEQ", 10);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 2);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC11_VALUE_1].Text);
                    data_list.AddString("VALUE_2", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC11_VALUE_2].Text);

                }

                //진밀도
                for (int i = 0; i < iRowCnt; i++)
                {
                    data_list = in_node.AddNode("DATA_LIST");
                    data_list.AddString("CHAR_ID", "CIQC072");
                    data_list.AddInt("CHAR_SEQ", 11);
                    data_list.AddInt("UNIT_SEQ", MPCF.ToInt(spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.UNIT_SEQ].Value));
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", " ");
                    data_list.AddChar("VALUE_TYPE", 'N');
                    data_list.AddInt("VALUE_COUNT", 2);
                    data_list.AddString("VALUE_1", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC072_VALUE_1].Text);
                    data_list.AddString("VALUE_2", spdDataCollection.ActiveSheet.Cells[i, (int)COLLECTION_DATA.CIQC072_VALUE_2].Text);

                }


                for (iLossRow = 0; iLossRow < spdLossInfo.ActiveSheet.RowCount; iLossRow++)
                {
                    if (MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[iLossRow, (int)LOSS_INFO.LOSS_QTY].Value) > 0)
                    {
                        loss_list = in_node.AddNode("LOSS_LIST");

                        loss_list.AddString("LOSS_CODE", spdLossInfo.ActiveSheet.Cells[iLossRow, (int)LOSS_INFO.LOSS_CODE].Value);  // LOSS_CODE
                        loss_list.AddDouble("LOSS_QTY", MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[iLossRow, (int)LOSS_INFO.LOSS_QTY].Value));
                        loss_list.AddChar("MAIN_FLAG", 'N');
                    }
                }


                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Collect_Inspection_Data", in_node, ref out_node, false) == false)
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
        private void ViewSpecLastEditTime(string matid, string oper)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                //int i = 0;

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
        private bool ViewColsetIdCheck(string sLotId)
        {
            bool bResult = false;
            string sMatId = "";
            string sColSetId = "";

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
                        if (dt.Rows[0]["COL_SET_ID"].ToString() == sDawonCollectionSet)
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
                list_item.AddString("COL_SET_ID", sDawonCollectionSet);
                list_item.AddChar("DEFAULT_FLAG", 'N');
                list_item.AddChar("DISABLE_FLAG", 'N');


                if (MPCR.CallService("EDC", "EDC_Update_MFO_ColSet_List", in_node, ref out_node) == false)
                {
                    return false;
                }

                // MPCR.ShowSuccessMsg(out_node);

                cdvColSetID.Text = sDawonCollectionSet;
                cdvColSetID.DisplayText = sDawonCollectionSet;

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

        #endregion

        #region " Event Definition "
        private void tpgInspCommon_Click(object sender, EventArgs e)
        {

        }
        private void cdvInspectionType_ButtonPress(object sender, EventArgs e)
        {


        }
        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (MPCF.Trim(txtLotID.Text) == "")
                        return;

                    txtLotID.Text = MPCF.Trim(txtLotID.Text).ToUpper();

                    if (CheckCondition(CSGC.CHECK.VIEW) == false)
                        return;


                    ClearList("LOT_INFO");

                    ViewLotInfo(txtLotID.Text);

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
        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvOper.Text = "";

                if (string.Equals(cdvDept.Text, CSGC.CP_AREA_CTM))
                {
                    sDawonCollectionSet = "CPQ90001";
                }
                else if (string.Equals(cdvDept.Text, CSGC.CP_AREA_GRT))
                {
                    sDawonCollectionSet = "GPQ90001";
                }
                else if (string.Equals(cdvDept.Text, CSGC.CP_AREA_PDC))
                {
                    sDawonCollectionSet = "PPQ90001";
                }
                else
                {
                    sDawonCollectionSet = "CPQ90001";
                }
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
        private void btnPop_Click(object sender, EventArgs e)
        {
            try
            {

                frmPopInspectionLotList popup = new frmPopInspectionLotList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                // popup.sSub_area_id = cdvWorkPlace.Text;
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
        private void spdFileRegistration_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            fnFileSelectionChagned();
        }
        private void spdDataCollection_EditModeOff(object sender, EventArgs e)
        {

            /* int iActiveRow = spdDataCollection.ActiveSheet.ActiveRowIndex;
             int iActiveCol = spdDataCollection.ActiveSheet.ActiveColumnIndex;
             int iRowCount = spdDataCollection.ActiveSheet.RowCount;

             if (iActiveRow < 0)
                 return;



             //컬럼 1,2,3, (4), 1,2,3,(4), (1) , 1,2,3,(4), 1,2,3,(4)

             if ( 1==1)
             {
                 //오른쪽 한칸
                 spdDataCollection.ActiveSheet.SetActiveCell(iActiveRow, iActiveCol + 1);
             } */

        }
        private void ViewInspectionLossInfo(string inspID, string oper)
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

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = oper;

                // 검사 첨부파일 리스트 조회
                if (TPDR.GetDataOne("", ref dt, "CQCM2001-003", dvcArgu, false, false, ref sSql) == false)
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
                    //spdLossInfo.ActiveSheet.Cells[i, (int)LOSS_INFO.MAIN_YN].Value = dt.Rows[i]["MAIN_YN"].ToString() == "Y" ? true : false;

                }
                MPCF.FitColumnHeader(spdLossInfo);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnSpec_Click(object sender, EventArgs e)
        {
            SpecPopUp();

        }
        private void txtLastSpecTime_Click(object sender, EventArgs e)
        {
            SpecPopUp();
        }
        private void cdvColSetID_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            SelectedItemChangedByColSet();
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

                //재조회
                SelectedItemChangedByColSet();
                //LOSS 정보 조회
                ViewInspectionLossInfo(txtInspID.Text, cdvInspOper.Text);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
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
                }
                else
                {
                    btnReceive.Enabled = false;
                }

                cdvInspectionJudgeFlag.Enabled = false;
                txtComment.Enabled = false;
                btnJudge.Enabled = false;
                btnProcess.Enabled = false;
                btnHold.Enabled = false;

                spdLossInfo.ActiveSheet.OperationMode = OperationMode.ReadOnly;
                cdvColSetID.Enabled = false;
                spdDataCollection.ActiveSheet.OperationMode = OperationMode.ReadOnly;
                spdFileRegistration.ActiveSheet.OperationMode = OperationMode.ReadOnly;
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
        private void cdvInspectionJudgeFlag_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            if (MPCF.Trim(cdvInspectionJudgeFlag.Text) == "")
                return;


        }
        private void btnJudge_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.ShowMsgBox(MPCF.GetMessage(503), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                {
                    return;
                }

                string sLotID;

                //Vaildation check
                if (VaildationCheckJudge() == false)
                {
                    return;
                }


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



        }
        private void spdDataCollection_Change(object sender, ChangeEventArgs e)
        {

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
        private void frmTranInspectionRegistrationDaewonTech_Load(object sender, EventArgs e)
        {
            cdvWorkGroup.Text = "A";
            rdoDencityNotUse.Checked = true;
            //cdvDept.Text = CSGC.CP_AREA_PDC;


            defModel = new DefaultSheetDataModel(0, spdDataCollection.ActiveSheet.Columns.Count);
            spdDataCollection.ActiveSheet.Models.Data = defModel;
            this.defModel.Changed += new SheetDataModelEventHandler(this.defModel_Changed);



            FarPoint.Win.Spread.InputMap inputmap;
            inputmap = spdDataCollection.GetInputMap(FarPoint.Win.Spread.InputMapMode.WhenAncestorOfFocused);
            inputmap.Put(new FarPoint.Win.Spread.Keystroke(Keys.Enter, Keys.None), FarPoint.Win.Spread.SpreadActions.MoveToNextRow);



        }
        private void defModel_Changed(object sender, FarPoint.Win.Spread.Model.SheetDataModelEventArgs e)
        {
            if (!b_allow_changed)
                return;



            int iRow = e.Row;
            int iCol = e.Column;

            double dInputValue;

            bool bSpecOut;

            //  b_loaded = false;

            if (iCol >= INPUT_COL_MIN_COUNT && iCol <= INPUT_COL_MAX_COUNT)
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

            double od1_min;
            double od1_max;
            double od1_avg;

            double od2_min;
            double od2_max;
            double od2_avg;

            double id_min;
            double id_max;
            double id_avg;

            double height1;
            double height2;
            double height3;
            double height4;
            double height_avg;

            double thick1;
            double thick2;
            double thick3;
            double thick4;
            double thick5;
            double thick_avg;

            double step_height1;
            double step_height2;
            double step_height3;
            double step_height4;

            double step_height_avg;

            double weight;

            double dencity;

            double dpie = 3.141592;

            try
            {
                if (!rdoDencityNotUse.Checked)
                {
                    //밀도 계산
                    //M12, M11 , M11(내경), M11(내경_NEW)
                    if (e.Column == (int)COLLECTION_DATA.CIQC12_VALUE_1 || e.Column == (int)COLLECTION_DATA.CIQC12_VALUE_2 ||
                       e.Column == (int)COLLECTION_DATA.CIQC06_VALUE_1 || e.Column == (int)COLLECTION_DATA.CIQC06_VALUE_2 || e.Column == (int)COLLECTION_DATA.CIQC06_VALUE_3 || e.Column == (int)COLLECTION_DATA.CIQC06_VALUE_4 ||
                       e.Column == (int)COLLECTION_DATA.CIQC07_VALUE_1 || e.Column == (int)COLLECTION_DATA.CIQC07_VALUE_2 || e.Column == (int)COLLECTION_DATA.CIQC07_VALUE_3 || e.Column == (int)COLLECTION_DATA.CIQC07_VALUE_4 ||
                       e.Column == (int)COLLECTION_DATA.CIQC13_VALUE_1 || e.Column == (int)COLLECTION_DATA.CIQC13_VALUE_2 ||
                       e.Column == (int)COLLECTION_DATA.CIQC05_VALUE_1 || e.Column == (int)COLLECTION_DATA.CIQC05_VALUE_2 ||
                       e.Column == (int)COLLECTION_DATA.CIQC08_VALUE_1 || e.Column == (int)COLLECTION_DATA.CIQC08_VALUE_2 || e.Column == (int)COLLECTION_DATA.CIQC08_VALUE_3 || e.Column == (int)COLLECTION_DATA.CIQC08_VALUE_4 || e.Column == (int)COLLECTION_DATA.CIQC08_VALUE_5 ||
                       e.Column == (int)COLLECTION_DATA.CIQC14_VALUE_1
                       )
                    {

                        //M12
                        if (rdoDencityCalc01.Checked)
                        {

                            if (Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC12_VALUE_1].Text, out od1_min) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC12_VALUE_2].Text, out od1_max) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC13_VALUE_1].Text, out od2_min) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC13_VALUE_2].Text, out od2_max) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC06_VALUE_1].Text, out height1) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC06_VALUE_2].Text, out height2) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC06_VALUE_3].Text, out height3) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC06_VALUE_4].Text, out height4) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC07_VALUE_1].Text, out step_height1) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC07_VALUE_2].Text, out step_height2) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC07_VALUE_3].Text, out step_height3) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC07_VALUE_4].Text, out step_height4) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC05_VALUE_1].Text, out id_min) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC05_VALUE_2].Text, out id_max) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC14_VALUE_1].Text, out weight)

                                )
                            {
                                od1_avg = (od1_min + od1_max) / 2;  //외경1_평균
                                od2_avg = (od2_min + od2_max) / 2;  //외경2_평균
                                id_avg = (id_min + id_max) / 2;     //내경_평균
                                height_avg = (height1 + height2 + height3 + height4) / 4;   // 높이_평균
                                step_height_avg = (step_height1 + step_height2 + step_height3 + step_height4) / 4; // 단높이_평균
                                 
                                dencity = weight / (((od1_avg / 2) * (od1_avg / 2) * dpie * (height_avg - step_height_avg - step_height_avg)) + ((od2_avg / 2) * (od2_avg / 2) * dpie * step_height_avg * 2) - ((id_avg / 2) * (id_avg / 2) * dpie * height_avg) / 1000);

                                spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC09_VALUE_1].Value = Math.Round(dencity, 3, MidpointRounding.AwayFromZero);

                            }

                        }
                        //M11
                        else if (rdoDencityCalc02.Checked)
                        {
                            if (Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC12_VALUE_1].Text, out od1_min) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC12_VALUE_2].Text, out od1_max) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC08_VALUE_1].Text, out thick1) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC08_VALUE_2].Text, out thick2) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC08_VALUE_3].Text, out thick3) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC08_VALUE_4].Text, out thick4) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC08_VALUE_5].Text, out thick5) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC14_VALUE_1].Text, out weight)
                               )
                            {
                                od1_avg = (od1_min + od1_max) / 2;
                                thick_avg = (thick1 + thick2 + thick3 + thick4 + thick5) / 5;

                                dencity = weight / (((od1_avg / 2) * (od1_avg / 2) * dpie * thick_avg) / 1000);

                                spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC09_VALUE_1].Value = Math.Round(dencity, 3, MidpointRounding.AwayFromZero);

                            }
                        }
                        //M11(내경)
                        else if (rdoDencityCalc03.Checked)
                        {
                            if (Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC12_VALUE_1].Text, out od1_min) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC12_VALUE_2].Text, out od1_max) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC08_VALUE_1].Text, out thick1) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC08_VALUE_2].Text, out thick2) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC08_VALUE_3].Text, out thick3) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC08_VALUE_4].Text, out thick4) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC08_VALUE_5].Text, out thick5) &&



                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC05_VALUE_1].Text, out id_min) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC05_VALUE_2].Text, out id_max) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC14_VALUE_1].Text, out weight)
                              )
                            {
                                od1_avg = (od1_min + od1_max) / 2;
                                id_avg = (id_min + id_max) / 2;
                                thick_avg = (thick1 + thick2 + thick3 + thick4 + thick5) / 5;  //두께 평균

                                dencity = weight / ((((od1_avg / 2) * (od1_avg / 2) * dpie * thick_avg) - ((id_avg / 2) * (id_avg / 2) * dpie * thick_avg)) / 1000);

                                spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC09_VALUE_1].Value = Math.Round(dencity, 3, MidpointRounding.AwayFromZero);

                            }
                        }
                        //M11(내경_NEW)
                        else if (rdoDencityCalc04.Checked)
                        {
                            if (Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC12_VALUE_1].Text, out od1_min) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC12_VALUE_2].Text, out od1_max) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC13_VALUE_1].Text, out od2_min) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC13_VALUE_2].Text, out od2_max) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC07_VALUE_1].Text, out step_height1) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC07_VALUE_2].Text, out step_height2) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC07_VALUE_3].Text, out step_height3) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC07_VALUE_4].Text, out step_height4) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC08_VALUE_1].Text, out thick1) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC08_VALUE_2].Text, out thick2) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC08_VALUE_3].Text, out thick3) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC08_VALUE_4].Text, out thick4) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC08_VALUE_5].Text, out thick5) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC05_VALUE_1].Text, out id_min) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC05_VALUE_2].Text, out id_max) &&
                                Double.TryParse(spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC14_VALUE_1].Text, out weight)
                              )
                            {
                                od1_avg = (od1_min + od1_max) / 2; // 외경1_평균
                                od2_avg = (od2_min + od2_max) / 2; // 외경2_평균
                                id_avg = (id_min + id_max) / 2;    // 내경_평균
                                thick_avg = (thick1 + thick2 + thick3 + thick4 + thick5) / 5;                      //두께 평균
                                step_height_avg = (step_height1 + step_height2 + step_height3 + step_height4) / 4; //단높이_평균

                                dencity = weight / (((od2_avg / 2) * (od2_avg / 2) * dpie * step_height_avg) + ((od1_avg / 2) * (od1_avg / 2) * dpie * (thick_avg - step_height_avg) - ((id_avg / 2) * (id_avg / 2) * dpie * thick_avg)) * 1000);

                                spdDataCollection.ActiveSheet.Cells[e.Row, (int)COLLECTION_DATA.CIQC09_VALUE_1].Value = Math.Round(dencity, 3, MidpointRounding.AwayFromZero);

                            }
                        }

                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
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

        #endregion
    }

}
