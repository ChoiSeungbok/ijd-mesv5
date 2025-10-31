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
using FarPoint.Win.Spread.Model;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

using System.Threading;
using System.Collections;
using System.IO;


//Message 세팅
//캡션 세팅frmTranInspectionRegistrationGRIT_SMP
//Vaildation 체크

namespace CUS_QCM
{
    public partial class frmTranInspectionRegistrationGRIT_SMP : CUS_COM.frmTranForm06
    {
        public frmTranInspectionRegistrationGRIT_SMP()
        {
            InitializeComponent();

            InitControl();
        }

        //string gFileServer_Ip;
        //string gFileServer_PORT;
        //string gFileServer_Dir;
        //string gFileServer_ID;
        //string gFileServer_PW;

        bool b_allow_changed;

        DefaultSheetDataModel defModelPSD;
        DefaultSheetDataModel defModel;
        DefaultSheetDataModel defModelBTI;
        DefaultSheetDataModel defModelHLT;

        DataTable dtSTSampleWT;
        DataTable dtSTFactor;

        bool bDoubleSize;




        private clsDerivedCharList cls_derived_char_list;

        private enum LOT_INFO
        {
            LOT_ID,                 // 1 : LOT ID
            MAT_ID,                 // 2 : 제품코드
            MAT_DESC,               // 3 : 제품명       
            FLOW,                      //4 : Flow코드  
            CREATE_DATE,            // 5 : 생성일자   
            INSP_QTY,                       // 6 : 요청수량
            UNIT_1                      // 단위
            
        }

        private enum COLLECTION_DATA
        {
            CHAR_COL,
            CHAR_DESC_COL,
            CHAR_SEQ,
            LOWER_SPEC_LIMIT,
            TARGET_VALUE,
            UPPER_SPEC_LIMIT,
            SPEC_COL,
            OPT_INPUT_COL,
            VALUE_TYPE_COL,
            VALUE_COUNT_COL,
            DEF_UNIT_FLAG_COL,
            DEF_UNIT_OVR_FLAG_COL,
            DEF_VALUE_COL,
            UNIT_TBL_COL,
            VALUE_TBL_COL,
            UNIT_SEQ_COL,
            UNIT_COL,
            VALUE_START_COL
        }

        private enum COLLECTION_DATA_PDC
        {
            INSP_SEQ,    // INSP_SEQ
            SIEVE_CODE,   //체 코드
            SIEVE_VALUE,  // 체 값
            NOT_SIEVE_1,   //빈체
            EXIST_SIEVE_1, //찬체
            DIFF_SIEVE_1,  //차이
            TI_VALUE_1   // (%)
        }

        private enum COLLECTION_DATA_BI
        {
            INSP_SEQ,    // INSP_SEQ
            SIEVE_CODE,   //체 코드
            SIEVE_VALUE,  // 체 값
            NOT_SIEVE_1,   //빈체 1
            EXIST_SIEVE_1, //찬체 1
            DIFF_SIEVE_1,  //차이 1
            TI_VALUE_1,   // (%) 1
            NOT_SIEVE_2,   //빈체 2
            EXIST_SIEVE_2, //찬체 2
            DIFF_SIEVE_2,  //차이 2
            TI_VALUE_2,   // (%) 2
            AVG_SIEVE,    //AVG
            TI_CHANGE    //TI 환산

        }

        private enum COLLECTION_DATA_BTI
        {
            INSP_SEQ,    // INSP_SEQ
            SIEVE_CODE,   //체 코드
            SIEVE_VALUE,  // 체 값
            NOT_SIEVE_1,   //빈체 1
            EXIST_SIEVE_1, //찬체 1
            DIFF_SIEVE_1,  //차이 1
            TI_VALUE_1,   // (%) 1
            NOT_SIEVE_2,   //빈체 2
            EXIST_SIEVE_2, //찬체 2
            DIFF_SIEVE_2,  //차이 2
            TI_VALUE_2,   // (%) 2
            AVG_SIEVE,    //AVG
            TI_CHANGE    //TI 환산

        }

        private enum COLLECTION_DATA_ASPECT
        {
            INSP_SEQ,    // INSP_SEQ
            QC_NAME,    // 명칭
            SPEC_VAL,
            VAL_1,          //MEAN
            VAL_2,          //D10
            VAL_3,          //D25
            VAL_4,          //D50
            VAL_5,          //D75
            VAL_6,          //D90
        }

        private enum COLLECTION_DATA_HLT
        {
            INSP_SEQ,
            SIEVE_VALUE_1,
            NOT_SIEVE_1,
            EXIST_SIEVE_1,
            DIFF_SIEVE_1,
            TOTAL_SIEVE_1,
            AVG_SIEVE_1,
            F_VALUE_1,
            SIEVE_VALUE_2,
            NOT_SIEVE_2,
            EXIST_SIEVE_2,
            DIFF_SIEVE_2,
            TOTAL_SIEVE_2,
            AVG_SIEVE_2,
            F_VALUE_2
        }

        /*
        private enum FILEUPLOAD
        {
            CHK,                   // 1 : 선택 
            FILE_NO,               // 2 : 파일번호 
            FILE_TYPE,             // 3 : 파일타입 
            FILE_TYPE_DESC,        // 4 : 파일타입 
            FILE_NAME,             // 5 : 파일명 
            FILE_PATH,             // 6 : 경로   
            UPLOAD_DATE,           // 7 : 업로드시간 
            FILE_OPEN,             // 8 : 파일열기
            FILE_DOWN             // 9 : 파일다운       
        }*/

        private enum FILEUPLOAD
        {
            FILE_NO,               // 1 : 파일번호 
            TITLE,                   // 2 파일타이틀
            NAME,                  //  3. 이미지 SEQ 이름
            REGIST,                 // 4. 파일 등록
            DELETE

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

        //private const int VALUE_START_COL = 13;
        private const int DEFAULT_COL_COUNT = 17;
        //private clsDerivedCharList cls_derived_char_list;


        private const int MAX_DATA_COUNT = 5000;


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

                }
                */

                //cdvColSetID.Text = "PDC";
                //cdvColSetID.DisplayText = "PDC";

                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnJudge.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnReceive.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnHold.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSpec.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnGCM2.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                //Grit WT, NORMAR TIME 기준정보
                GetSampleWT();

                //Grit Factor 값
                GetFactor();

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

                    MPCF.FieldClear(panLotInfo,txtLotID);
                    MPCF.ClearList(spdLotList);
                    MPCF.FieldClear(panJudgeResult);
                    MPCF.ClearList(spdFileRegistration);
                    MPCF.ClearList(spdLossInfo);

                    //MPCF.FieldClear(panDataCollection);
                    MPCF.ClearList(spdDataCollectionPSD);

                    break;

                case "COL_SET_CHANGED":

                    MPCF.ClearList(spdDataCollection);
                    txtColSetVer.Text = "";
                    spdDataCollection.ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;

                    break;
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
                    return false;
                }

                cdvReworkOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

            return true; */

            
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

            //처음 LOT 생성 부분





            try
            {

                if (MPCF.Trim(txtLotID.Text) == "")  //LOT ID 필수입력
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotID.Text + "]");
                    txtLotID.Focus();
                    return;
                }

                if (MPCF.Trim(txtSizes.Text) == "")  //사이즈 필수입력
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblSizes.Text + "]");
                    txtSizes.Focus();
                    return;
                }
                if (MPCF.Trim(txtGrade.Text) == "") //GRADE 필수입력
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblGrade.Text + "]");
                    txtGrade.Focus();
                    return;
                }


                txtMatID.Text = "ZGXXXXX-00001";
                txtMatDesc.Text = "GRT-QC-SAMPLE";
                txtMatVer.Text = "1";


                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                MPCF.ClearList(spdLotList);

                in_node.ProcStep = '4';
                in_node.AddString("INSP_TYPE", "PQC");
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("LOT_ID", sLot_ID); 
                in_node.AddString("MAT_ID", txtMatID.Text);
                in_node.AddInt("MAT_VER", MPCF.ToInt(txtMatVer.Text));
                in_node.AddString("AREA_ID", cdvDept.Text);           

                 if (MPCR.CallService("CUS_QCM", "CUS_QCM_Create_Inspection_Request", in_node, ref out_node) == false)
                 {
                     return;
                 }
                //TRS.add_string(out_node, "FACTORY", CQCMISPSTS.FACTORY, sizeof(CQCMISPSTS.FACTORY));

                spdLotList.ActiveSheet.RowCount++;
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.LOT_ID, txtLotID.Text);
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.MAT_ID, "ZGXXXXX-00001");
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.MAT_DESC, "GRT-QC-SAMPLE");
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.FLOW, "");   //플로우 필요없을듯....
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.CREATE_DATE, "");
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.INSP_QTY, 0);
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.UNIT_1, "CTS");


                MPCF.FitColumnHeader(spdLotList);


                txtInspID.Text = out_node.GetString("INSP_ID"); //검사 ID
                cdvInspOper.Text =cdvOper.Text;
                cdvInspOper.DisplayText = cdvOper.DisplayText;




                //LOT 생성전에 입력이 되도록 그래서 가져올 필요없음
                /* 
                 txtSizes.Text = out_node.GetString("SIZES");
                 txtGrade.Text = out_node.GetString("GRADE");
                 */

                //LOT 생성전에 입력을 할거라서 필요가 없음.
                /*
                 cdvDept.Text = out_node.GetString("AREA_ID");
                 cdvDept.DisplayText = out_node.GetString("AREA_DESC");
                 */

                //cdvWorkPlace.Text = out_node.GetString("SUB_AREA_ID");
                //cdvWorkPlace.DisplayText = out_node.GetString("SUB_AREA_DESC");





                txtInspectionStatus.Text = "";//out_node.GetChar("INSP_STATUS").ToString();
                 txtInspectionStatusDesc.Text = "";//out_node.GetString("INSP_STATUS_DESC");
                 cdvInspectionJudgeFlag.Text = ""; //out_node.GetChar("INSP_JUDGE_FLAG").ToString();
                cdvInspectionJudgeFlag.DisplayText = ""; //out_node.GetString("INSP_JUDGE_DESC");


                //재작업은 필요없음
                /*
                cdvReworkOper.Text = out_node.GetString("RWK_OPER");
                cdvReworkOper.DisplayText = out_node.GetString("RWK_OPER_DESC");
                */

                txtComment.Text = ""; //out_node.GetString("INSP_COMMENT");




                cdvColSetID.Text = "GOQ00001"; //out_node.GetString("COL_SET_ID");
                cdvColSetID.DisplayText = "GRT [OQC] 제품검사(GOQ00001)"; //out_node.GetString("COL_SET_DESC");

                bDoubleSize = false;
                //-----------------------------------------------
                // 여기를 조회 쿼리 따와야함

                /*
                cdvInspPSDCount.Text =  out_node.GetInt("INSP_COUNT_PSD").ToString();
                cdvInspBICount.Text = out_node.GetInt("INSP_COUNT_BI").ToString();
                cdvInspBTICount.Text = out_node.GetInt("INSP_COUNT_BTI").ToString();
                cdvInspHLTCount.Text = out_node.GetInt("INSP_COUNT_HLT").ToString();

                txtHLTSize1.Text = out_node.GetString("SIZE_1").ToString();
                txtHLTSize2.Text = out_node.GetString("SIZE_2").ToString();

                txtHLTResultSize1.Text = out_node.GetString("SIZE_1").ToString();
                txtHLTResultSize2.Text = out_node.GetString("SIZE_2").ToString();

                bDoubleSize = out_node.GetChar("DOUBLE_SIZE") == 'Y' ? true : false;

                GetJudgeFlagByArea(cdvInspectionJudgeFlag.GetListView,cdvInspOper.Text,cdvInspectionType.Text);
                cdvInspectionJudgeFlag.InsertEmptyRow(0, 1);
                */

                //---------------------------------------------------------


                //재작업은 필요없음
                /*
                initReworkOperList(cdvReworkOper.GetListView);
                */


                //파일 리스트 조회
                ViewInspectionFile(txtInspID.Text);



                
                //Loss 정보 조회(LOSS 입력 할일 없음)
                /*
                ViewInspectionLossInfo(txtInspID.Text, cdvInspOper.Text);
                */



                //검사자 대상 조회;
                ViewWorkerList();




                //////////  Data 조회 ///////
                //Col Set Version
                SelectedItemChangedByColSet();

                /***** (1) PSD ****/
                //(1) 저장시에는 ratio_sieve , diff_sum 추가해야함.
                ViewInspectionGritPSD(txtInspID.Text);

                /***** (2) BI *****/
                ViewInspectionGritBI(txtInspID.Text);

                /*****(3) BTI *****/
                ViewInspectionGritBTI(txtInspID.Text);

                /*****(4) HLT ******/
                ViewInspectionGritHTL(txtInspID.Text);

                /*****(5) Coating *****/
                ViewInspectionGritCoating(txtInspID.Text);

                /*****(6) Aspect Ratio *****/
                ViewInspectionGritAspect(txtInspID.Text);


                ViewSpecLastEditTime(txtMatID.Text, cdvInspOper.Text);

                //SelectedItemChangedByColSet();
                // 이안에 데이터 조회 모두

                b_allow_changed = true;
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
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
                    spdLossInfo.ActiveSheet.Cells[i, (int)LOSS_INFO.MAIN_YN].Value = dt.Rows[i]["MAIN_YN"].ToString() == "Y" ? true : false;

                }
                MPCF.FitColumnHeader(spdLossInfo);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //작업자 조회 함수
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

            /* in_node.AddString("SQL", "SELECT KEY_3 AS CODE, "
                                                 + "          DATA_1 AS VALUE "
                                                 + "         FROM MGCMTBLDAT "
                                                 + "       WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                                 + "           AND TABLE_NAME = 'C_INSP_JUDGE_FLAG' "
                                                 + "           AND KEY_1 = (SELECT AREA_ID "
                                                 + "                          FROM MWIPOPRDEF "
                                                 + "                         WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                                 + "                           AND OPER = '" + insp_oper + "') "
                                                 + "           AND KEY_2 = '" + insp_type +  "' "
                                                 + "        ORDER BY DATA_2" ); */

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


        private void GetSampleWT()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                dtSTSampleWT = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;



                // 검사 첨부파일 리스트 조회
                if (TPDR.GetDataOne("", ref dtSTSampleWT, "CQCM2004-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dtSTSampleWT != null)
                        dtSTSampleWT.Dispose();

                    GC.Collect();

                    return;
                }

               
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void GetFactor()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                dtSTFactor = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;



                // 검사 첨부파일 리스트 조회
                if (TPDR.GetDataOne("", ref dtSTFactor, "CQCM2004-007", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dtSTFactor != null)
                        dtSTFactor.Dispose();

                    GC.Collect();

                    return;
                }


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewInspectionGritPSD(string inspID)
        {
            

            try
            {
                b_allow_changed = false;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_ID";
                dvcArgu[1].sCondition_Value = inspID;

                dvcArgu[2].sCondition_ID = "INSP_COUNT";
                dvcArgu[2].sCondition_Value = MPCF.ToInt(cdvInspPSDCount.Text);

                // 검사 첨부파일 리스트 조회
                if (TPDR.GetDataOne("", ref dt, "CQCM2004-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdDataCollectionPSD);
                    return;
                }

                MPCF.ClearList(spdDataCollectionPSD);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdDataCollectionPSD.ActiveSheet.RowCount++;

                    spdDataCollectionPSD.ActiveSheet.Cells[i, (int)COLLECTION_DATA_PDC.INSP_SEQ].Value = dt.Rows[i]["INSP_SEQ"];
                    spdDataCollectionPSD.ActiveSheet.Cells[i, (int)COLLECTION_DATA_PDC.SIEVE_CODE].Value = dt.Rows[i]["SIEVE_CODE"];
                    spdDataCollectionPSD.ActiveSheet.Cells[i, (int)COLLECTION_DATA_PDC.SIEVE_VALUE].Value = dt.Rows[i]["SIEVE_VALUE"];
                    spdDataCollectionPSD.ActiveSheet.Cells[i, (int)COLLECTION_DATA_PDC.NOT_SIEVE_1].Value = dt.Rows[i]["NOT_SIEVE_1"];
                    spdDataCollectionPSD.ActiveSheet.Cells[i, (int)COLLECTION_DATA_PDC.EXIST_SIEVE_1].Value = dt.Rows[i]["EXIST_SIEVE_1"];
                    spdDataCollectionPSD.ActiveSheet.Cells[i, (int)COLLECTION_DATA_PDC.DIFF_SIEVE_1].Value = dt.Rows[i]["DIFF_SIEVE_1"];
                    spdDataCollectionPSD.ActiveSheet.Cells[i, (int)COLLECTION_DATA_PDC.TI_VALUE_1].Value = dt.Rows[i]["TI_VALUE_1"]; 

                }
                //MPCF.FitColumnHeader(spdDataCollection);

                b_allow_changed = true;
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewInspectionGritBI(string inspID)
        {
            try
            {
                b_allow_changed = false;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_ID";
                dvcArgu[1].sCondition_Value = inspID;

                dvcArgu[2].sCondition_ID = "INSP_COUNT";
                dvcArgu[2].sCondition_Value = MPCF.ToInt(cdvInspBICount.Text);

                // 검사 첨부파일 리스트 조회
                if (TPDR.GetDataOne("", ref dt, "CQCM2004-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdDataCollectionBI);
                    return;
                }

                MPCF.ClearList(spdDataCollectionBI);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdDataCollectionBI.ActiveSheet.RowCount++;

                   spdDataCollectionBI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BI.INSP_SEQ].Value = dt.Rows[i]["INSP_SEQ"];


                    spdDataCollectionBI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BI.SIEVE_CODE].Value = dt.Rows[i]["SIEVE_CODE"];
                    spdDataCollectionBI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BI.SIEVE_VALUE].Value = dt.Rows[i]["SIEVE_VALUE"];

                    spdDataCollectionBI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BI.NOT_SIEVE_1].Value = dt.Rows[i]["NOT_SIEVE_1"];
                    spdDataCollectionBI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BI.EXIST_SIEVE_1].Value = dt.Rows[i]["EXIST_SIEVE_1"];
                    spdDataCollectionBI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BI.DIFF_SIEVE_1].Value = dt.Rows[i]["DIFF_SIEVE_1"];
                    spdDataCollectionBI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BI.TI_VALUE_1].Value = dt.Rows[i]["TI_VALUE_1"];

                    spdDataCollectionBI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BI.NOT_SIEVE_2].Value = dt.Rows[i]["NOT_SIEVE_2"];
                    spdDataCollectionBI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BI.EXIST_SIEVE_2].Value = dt.Rows[i]["EXIST_SIEVE_2"];
                    spdDataCollectionBI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BI.DIFF_SIEVE_2].Value = dt.Rows[i]["DIFF_SIEVE_2"];
                    spdDataCollectionBI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BI.TI_VALUE_2].Value = dt.Rows[i]["TI_VALUE_2"];

                    spdDataCollectionBI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BI.AVG_SIEVE].Value = dt.Rows[i]["AVG_SIEVE"];
                    spdDataCollectionBI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BI.TI_CHANGE].Value = dt.Rows[i]["TI_CHANGE"];

                    if (i == 0)
                    {
                        txtBICount1.Text = dt.Rows[i]["COUNT_1"].ToString();
                        txtBICount2.Text = dt.Rows[i]["COUNT_2"].ToString();
                    }


                }
                //MPCF.FitColumnHeader(spdDataCollection);

                b_allow_changed = true;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewInspectionGritBTI(string inspID)
        {
            try
            {
                b_allow_changed = false;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_ID";
                dvcArgu[1].sCondition_Value = inspID;

                dvcArgu[2].sCondition_ID = "INSP_COUNT";
                dvcArgu[2].sCondition_Value = MPCF.ToInt(cdvInspBTICount.Text);

                // 검사 첨부파일 리스트 조회
                if (TPDR.GetDataOne("", ref dt, "CQCM2004-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdDataCollectionBTI);
                    return;
                }

                MPCF.ClearList(spdDataCollectionBTI);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdDataCollectionBTI.ActiveSheet.RowCount++;

                    spdDataCollectionBTI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BTI.INSP_SEQ].Value = dt.Rows[i]["INSP_SEQ"];


                    spdDataCollectionBTI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BTI.SIEVE_CODE].Value = dt.Rows[i]["SIEVE_CODE"];
                    spdDataCollectionBTI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BTI.SIEVE_VALUE].Value = dt.Rows[i]["SIEVE_VALUE"];

                    spdDataCollectionBTI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BTI.NOT_SIEVE_1].Value = dt.Rows[i]["NOT_SIEVE_1"];
                    spdDataCollectionBTI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BTI.EXIST_SIEVE_1].Value = dt.Rows[i]["EXIST_SIEVE_1"];
                    spdDataCollectionBTI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BTI.DIFF_SIEVE_1].Value = dt.Rows[i]["DIFF_SIEVE_1"];
                    spdDataCollectionBTI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BTI.TI_VALUE_1].Value = dt.Rows[i]["TI_VALUE_1"];

                    spdDataCollectionBTI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BTI.NOT_SIEVE_2].Value = dt.Rows[i]["NOT_SIEVE_2"];
                    spdDataCollectionBTI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BTI.EXIST_SIEVE_2].Value = dt.Rows[i]["EXIST_SIEVE_2"];
                    spdDataCollectionBTI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BTI.DIFF_SIEVE_2].Value = dt.Rows[i]["DIFF_SIEVE_2"];
                    spdDataCollectionBTI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BTI.TI_VALUE_2].Value = dt.Rows[i]["TI_VALUE_2"];

                    spdDataCollectionBTI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BTI.AVG_SIEVE].Value = dt.Rows[i]["AVG_SIEVE"];
                    spdDataCollectionBTI.ActiveSheet.Cells[i, (int)COLLECTION_DATA_BTI.TI_CHANGE].Value = dt.Rows[i]["TI_CHANGE"];

                    if (i == 0)
                    {
                        txtBTICount1.Text = dt.Rows[i]["COUNT_1"].ToString();
                        txtBTICount2.Text = dt.Rows[i]["COUNT_2"].ToString();
                    }

                }
                //MPCF.FitColumnHeader(spdDataCollection);

                b_allow_changed = true;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewInspectionGritAspect(string inspID)
        {
            try
            {
                b_allow_changed = false;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_ID";
                dvcArgu[1].sCondition_Value = inspID;


                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvInspOper.Text;

                dvcArgu[3].sCondition_ID = "MAT_ID";
                dvcArgu[3].sCondition_Value = txtMatID.Text;


                // 검사 첨부파일 리스트 조회
                if (TPDR.GetDataOne("", ref dt, "CQCM2004-008", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdDataCollectionAspect);
                    return;
                }

                MPCF.ClearList(spdDataCollectionAspect);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdDataCollectionAspect.ActiveSheet.RowCount++;

                    spdDataCollectionAspect.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ASPECT.INSP_SEQ].Value = dt.Rows[i]["INSP_SEQ"];
                    spdDataCollectionAspect.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ASPECT.QC_NAME].Value = dt.Rows[i]["QC_NAME"];
                    spdDataCollectionAspect.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ASPECT.SPEC_VAL].Value = dt.Rows[i]["SPEC_VAL"];
                    spdDataCollectionAspect.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ASPECT.VAL_1].Value = dt.Rows[i]["VAL_1"];
                    spdDataCollectionAspect.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ASPECT.VAL_2].Value = dt.Rows[i]["VAL_2"];
                    spdDataCollectionAspect.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ASPECT.VAL_3].Value = dt.Rows[i]["VAL_3"];
                    spdDataCollectionAspect.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ASPECT.VAL_4].Value = dt.Rows[i]["VAL_4"];
                    spdDataCollectionAspect.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ASPECT.VAL_5].Value = dt.Rows[i]["VAL_5"];
                    spdDataCollectionAspect.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ASPECT.VAL_6].Value = dt.Rows[i]["VAL_6"];
                    
                }

                b_allow_changed = true;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewInspectionGritHTL(string inspID)
        {
            try
            {
                b_allow_changed = false;


                

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_ID";
                dvcArgu[1].sCondition_Value = inspID;

                dvcArgu[2].sCondition_ID = "INSP_COUNT";
                dvcArgu[2].sCondition_Value = MPCF.ToInt(cdvInspHLTCount.Text);

                dvcArgu[3].sCondition_ID = "SIZE_1";
                dvcArgu[3].sCondition_Value = txtHLTSize1.Text;

                dvcArgu[4].sCondition_ID = "SIZE_2";
                dvcArgu[4].sCondition_Value = txtHLTSize2.Text == "" ? txtHLTSize1.Text : txtHLTSize2.Text;

                dvcArgu[5].sCondition_ID = "GRADE";
                dvcArgu[5].sCondition_Value = txtGrade.Text;

                // 검사 첨부파일 리스트 조회
                if (TPDR.GetDataOne("", ref dt, "CQCM2004-009", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdDataCollectionHLT);
                    return;
                }

                MPCF.ClearList(spdDataCollectionHLT);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdDataCollectionHLT.ActiveSheet.RowCount++;

                    spdDataCollectionHLT.ActiveSheet.Cells[i, (int)COLLECTION_DATA_HLT.INSP_SEQ].Value = dt.Rows[i]["INSP_SEQ"];

                    spdDataCollectionHLT.ActiveSheet.Cells[i, (int)COLLECTION_DATA_HLT.SIEVE_VALUE_1].Value = dt.Rows[i]["SIEVE_VALUE_1"];
                    spdDataCollectionHLT.ActiveSheet.Cells[i, (int)COLLECTION_DATA_HLT.NOT_SIEVE_1].Value = dt.Rows[i]["NOT_SIEVE_1"];
                    spdDataCollectionHLT.ActiveSheet.Cells[i, (int)COLLECTION_DATA_HLT.EXIST_SIEVE_1].Value = dt.Rows[i]["EXIST_SIEVE_1"];
                    spdDataCollectionHLT.ActiveSheet.Cells[i, (int)COLLECTION_DATA_HLT.DIFF_SIEVE_1].Value = dt.Rows[i]["DIFF_SIEVE_1"];
                    spdDataCollectionHLT.ActiveSheet.Cells[i, (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_1].Value = dt.Rows[i]["TOTAL_SIEVE_1"];
                    spdDataCollectionHLT.ActiveSheet.Cells[i, (int)COLLECTION_DATA_HLT.AVG_SIEVE_1].Value = dt.Rows[i]["AVG_SIEVE_1"];
                    spdDataCollectionHLT.ActiveSheet.Cells[i, (int)COLLECTION_DATA_HLT.F_VALUE_1].Value = dt.Rows[i]["F_VALUE_1"];

                    spdDataCollectionHLT.ActiveSheet.Cells[i, (int)COLLECTION_DATA_HLT.SIEVE_VALUE_2].Value = dt.Rows[i]["SIEVE_VALUE_2"];
                    spdDataCollectionHLT.ActiveSheet.Cells[i, (int)COLLECTION_DATA_HLT.NOT_SIEVE_2].Value = dt.Rows[i]["NOT_SIEVE_2"];
                    spdDataCollectionHLT.ActiveSheet.Cells[i, (int)COLLECTION_DATA_HLT.EXIST_SIEVE_2].Value = dt.Rows[i]["EXIST_SIEVE_2"];
                    spdDataCollectionHLT.ActiveSheet.Cells[i, (int)COLLECTION_DATA_HLT.DIFF_SIEVE_2].Value = dt.Rows[i]["DIFF_SIEVE_2"];
                    spdDataCollectionHLT.ActiveSheet.Cells[i, (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_2].Value = dt.Rows[i]["TOTAL_SIEVE_2"];
                    spdDataCollectionHLT.ActiveSheet.Cells[i, (int)COLLECTION_DATA_HLT.AVG_SIEVE_2].Value = dt.Rows[i]["AVG_SIEVE_2"];
                    spdDataCollectionHLT.ActiveSheet.Cells[i, (int)COLLECTION_DATA_HLT.F_VALUE_2].Value = dt.Rows[i]["F_VALUE_2"];


                    if (i == 0)
                    {
                        if (bDoubleSize)
                        {

                        }
                        txtHLTMeshTime1.Text =  dt.Rows[i]["SMASH_TIME_1"].ToString();
                        txtHLTMeshTime2.Text = dt.Rows[i]["SMASH_TIME_2"].ToString();
                        txtHLTCount1.Text =  dt.Rows[i]["COUNT_1"].ToString();
                        txtHLTCount2.Text = dt.Rows[i]["COUNT_2"].ToString();

                        txtHLTTiValue1.Text = dt.Rows[i]["TI_VALUE_1"].ToString();
                        txtHLTTiValue2.Text = dt.Rows[i]["TI_VALUE_2"].ToString();

                        txtHLTResult.Text = dt.Rows[i]["TI_RESULT"].ToString();

                    }

                }

                if (bDoubleSize)
                {
                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.NOT_SIEVE_2].Locked = false;
                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.EXIST_SIEVE_2].Locked = false;

                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.SIEVE_VALUE_2].BackColor = Color.White;
                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.NOT_SIEVE_2].BackColor = Color.Yellow;
                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.EXIST_SIEVE_2].BackColor = Color.Yellow;
                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.DIFF_SIEVE_2].BackColor = Color.White;
                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.TOTAL_SIEVE_2].BackColor = Color.White;
                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.AVG_SIEVE_2].BackColor = Color.White;
                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.F_VALUE_2].BackColor = Color.White;

                    txtHLTMeshTime2.ReadOnly = false;
                    txtHLTCount2.ReadOnly = false;
                }
                else
                {
                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.NOT_SIEVE_2].Locked = true;
                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.EXIST_SIEVE_2].Locked = true;

                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.SIEVE_VALUE_2].BackColor = Color.Gray;
                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.NOT_SIEVE_2].BackColor = Color.Gray;
                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.EXIST_SIEVE_2].BackColor = Color.Gray;
                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.DIFF_SIEVE_2].BackColor = Color.Gray;
                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.TOTAL_SIEVE_2].BackColor = Color.Gray;
                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.AVG_SIEVE_2].BackColor = Color.Gray;
                    spdDataCollectionHLT.ActiveSheet.Columns[(int)COLLECTION_DATA_HLT.F_VALUE_2].BackColor = Color.Gray;

                    txtHLTMeshTime2.ReadOnly = true;
                    txtHLTCount2.ReadOnly = true;
                }

                b_allow_changed = true;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewInspectionGritCoating(string inspID)
        {
            try
            {
                b_allow_changed = false;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_ID";
                dvcArgu[1].sCondition_Value = inspID;

                // dvcArgu[2].sCondition_ID = "INSP_COUNT";
                //dvcArgu[2].sCondition_Value = MPCF.ToInt(cdvInspPSDCount.Text);

                // 검사 첨부파일 리스트 조회
                if (TPDR.GetDataOne("", ref dt, "CQCM2004-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    initCoatingControl();
                    return;
                }

                initCoatingControl();

                txtMAValue1.Text = dt.Rows[0]["MA_VALUE_1"].ToString();
                txtMAResult.Text = dt.Rows[0]["MA_RESULT"].ToString();
                txtWTValue1.Text = dt.Rows[0]["WT_VALUE_1"].ToString();
                txtWTValue2.Text = dt.Rows[0]["WT_VALUE_2"].ToString();
                txtWTValue3.Text = dt.Rows[0]["WT_VALUE_3"].ToString();
                txtWTValue1Same.Text = dt.Rows[0]["WT_VALUE_1"].ToString();
                txtWTResult.Text = dt.Rows[0]["WT_RESULT"].ToString();

                txtBDValue1.Text = dt.Rows[0]["BD_VALUE_1"].ToString();
                txtBDResult.Text = dt.Rows[0]["BD_RESULT"].ToString();

                txtTDValue1.Text = dt.Rows[0]["TD_VALUE_1"].ToString();
                txtTDResult.Text = dt.Rows[0]["TD_RESULT"].ToString();

                txtPCSValue1.Text = dt.Rows[0]["PCS_VALUE_1"].ToString();
                txtPCSResult.Text = dt.Rows[0]["PCS_RESULT"].ToString();

                txtPSValue1.Text = dt.Rows[0]["PS_VALUE_1"].ToString();
                txtPSValue2.Text = dt.Rows[0]["PS_VALUE_2"].ToString();
                txtPSResult.Text = dt.Rows[0]["PS_RESULT"].ToString();

                txtCML.Text = dt.Rows[0]["CM_L"].ToString();
                txtCMA.Text = dt.Rows[0]["CM_A"].ToString();
                txtCMB.Text = dt.Rows[0]["CM_B"].ToString();

                txtGrainSize.Text = dt.Rows[0]["GRAIN_SIZE"].ToString();
                txtEllipticity.Text = dt.Rows[0]["ELIP_VALUE2"].ToString();
                txtRoughness.Text = dt.Rows[0]["ROUG_VALUE"].ToString();
                txtCirculrarity.Text = dt.Rows[0]["CIRCULRARITY"].ToString();
                txtConvexity.Text = dt.Rows[0]["CONVEXITY"].ToString();
                txtShapeFactor.Text = dt.Rows[0]["SHAPE_FACTOR"].ToString();
                txtSurfaceB.Text = dt.Rows[0]["SURFACE_B"].ToString();
                txtConOValue.Text = dt.Rows[0]["CON_O_VALUE"].ToString();

                txtRemarksCoating.Text = dt.Rows[0]["REMARKS"].ToString();



                b_allow_changed = true;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void initCoatingControl()
        {
            txtMAValue1.Text = "0";
            txtMACalValue.Text = "7.5";
            txtMAResult.Text = "0";

            txtWTValue1.Text = "0";
            txtWTValue2.Text = "0";
            txtWTValue3.Text = "0";
            txtWTValue1Same.Text = "0";
            txtWTCalValue.Text = "100";
            txtWTResult.Text = "0";

            txtBDValue1.Text = "0";
            txtBDCalValue.Text = "7.8";
            txtBDResult.Text = "0";

            txtTDCalValue.Text = "50";
            txtTDValue1.Text = "0";
            txtTDResult.Text = "0";

            txtPCSCalValue.Text = "40";
            txtPCSValue1.Text = "0";
            txtPCSResult.Text = "0";

            txtPSValue1.Text = "0";
            txtPSValue2.Text = "0";
            txtPSResult.Text = "0";

            txtCML.Text = "0";
            txtCMA.Text = "0";
            txtCMB.Text = "0";

            txtGrainSize.Text = "0";
            txtEllipticity.Text = "0";
            txtRoughness.Text = "0";
            txtCirculrarity.Text = "0";
            txtConvexity.Text = "0";
            txtShapeFactor.Text = "0";
            txtSurfaceB.Text = "0";
            txtConOValue.Text = "0";

            txtRemarksCoating.Text = "";


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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_ID";
                dvcArgu[1].sCondition_Value = inspID;


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

        private void tpgInspCommon_Click(object sender, EventArgs e)
        {

        }

        private void cdvInspectionType_ButtonPress(object sender, EventArgs e)
        {
            cdvInspectionType.Init();
            MPCF.InitListView(cdvInspectionType.GetListView);
            cdvInspectionType.Columns.Add("InspType", 50, HorizontalAlignment.Left);
            cdvInspectionType.SelectedSubItemIndex = 0;
            cdvInspectionType.DisplaySubItemIndex =0;
            

            if (BASLIST.ViewGCMDataList(cdvInspectionType.GetListView, '1', CSGC.CP_GCM_INSP_TYPE, -1, null, "", true, -1, -1, null, null) == false)
            {
                return;
            }


           
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

                cls_derived_char_list = new clsDerivedCharList();
                cls_derived_char_list.GetDerivedInfo(sColSetID, Convert.ToInt32(txtColSetVer.Text), sLotID, "", "", "");

                if (ViewCharacterList(spdDataCollection, '5', sColSetID, Convert.ToInt32(txtColSetVer.Text), 'Y', cls_derived_char_list, sLotID, sMatID, iMatVer, sOper) == false)
                {
                    return;
                }

                if (ViewInspData2() == false)
                {
                    CSCF.ClearSpread(spdDataCollection, 0, (int)COLLECTION_DATA.VALUE_START_COL, "");
                }

                /*
                if (ViewInspData() == false)
                {
                    ViewInputContainer();
                   
                }
                */
            }
            catch
            {

            }
        }

        private bool ViewInspData2()
        {


            int iValueCnt = 0;
            int iRow = 0;
            string s_value_name;

            try
            {

                TRSNode in_node = new TRSNode("view_lot_data_In");
                TRSNode out_node = new TRSNode("view_lot_data_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("INSP_ID", txtInspID.Text);
                in_node.AddString("COL_SET_ID", cdvColSetID.Text);
                in_node.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.LOT_ID].Value.ToString());

                if (MPCR.CallService("CUS_QCM", "CUS_QCM_View_Lot_Inspection_Data", in_node, ref out_node) == false)
                {
                    return false;
                }




                for (int i = 0; i < out_node.GetList(0).Count; i++)
                {
                    for (int j = 0; j < spdDataCollection.ActiveSheet.RowCount; j++)
                    {
                        if (spdDataCollection.ActiveSheet.Cells[j, (int)COLLECTION_DATA.CHAR_COL].Text == out_node.GetList(0)[i].GetString("CHAR_ID")   //dt.Rows[i]["CHAR_ID"].ToString()
                            && spdDataCollection.ActiveSheet.Cells[j, (int)COLLECTION_DATA.UNIT_SEQ_COL].Text == out_node.GetList(0)[i].GetInt("UNIT_SEQ").ToString())
                        {
                            iRow = j;
                            break;
                        }

                    }

                    //spdDataCollection.ActiveSheet.SetValue(iRow, (int)COLLECTION_DATA.UNIT_COL, out_node.GetList(0)[i].GetString("UNIT_ID"));

                    // iUnitCnt = MPCF.ToInt(dt.Rows[0]["UNIT_COUNT"].ToString());
                    iValueCnt = out_node.GetList(0)[i].GetInt("VALUE_COUNT");

                    if (iValueCnt > 25)
                    {
                        iValueCnt = 25;
                    }

                    for (int k = 1; k <= iValueCnt; k++)
                    {
                        s_value_name = "VALUE_" + k.ToString();
                        if (out_node.GetList(0)[i].GetChar("VALUE_TYPE") == 'N')
                        {
                            if (out_node.GetList(0)[i].GetString(s_value_name) != "")
                            {
                                spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_START_COL + (k - 1)].Value = MPCF.ToDbl(out_node.GetList(0)[i].GetString(s_value_name));
                            }
                        }
                        else
                        {
                            spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_START_COL + (k - 1)].Value = out_node.GetList(0)[i].GetString(s_value_name);
                        }

                    }
                }

                //Spec Out 확인
                ApplyColorBySpecOut();

                return true;
                //return bResult;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void ApplyColorBySpecOut()
        {
            if (spdDataCollection.ActiveSheet.RowCount < 1)
            {
                return;
            }

            try
            {
                for (int iRow = 0; iRow < spdDataCollection.ActiveSheet.RowCount; iRow++)
                {
                    for (int iCol = (int)COLLECTION_DATA.VALUE_START_COL; iCol < spdDataCollection.ActiveSheet.ColumnCount; iCol++)
                    {
                        bool bSpecOut = false;

                        //검사항목이 숫자타입 일 때만
                        if (spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_TYPE_COL].Value.ToString() == "N")
                        {
                            //입력값(검사 결과값)이 숫자일 때
                            if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value) == true)
                            {
                                if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.LOWER_SPEC_LIMIT].Value) == true)
                                {
                                    if (MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value) < MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.LOWER_SPEC_LIMIT].Value))
                                    {
                                        bSpecOut = true;
                                    }
                                }

                                if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.UPPER_SPEC_LIMIT].Value) == true)
                                {
                                    if (MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, iCol].Value) > MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.UPPER_SPEC_LIMIT].Value))
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
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

        }

        public bool ViewCharacterList(Control control, char ProcStep, string ColSetID, int ColSetVersion, char cIncludeUnitID, clsDerivedCharList cls_derived_char_list, string LotID, string sMatID, int iMatVer, string sOper)
        {

            int i;
            int j;
            int k;
            int m;
            int i_index;
            int iLastRow = 0;
            int iUnitCnt = 0;
            int iValueCnt = 0;
            int iUnitSeq = 0;
            int iMaxColumnCnt = 0;
            int iColCnt = 0;
            string sDefaultValue;
            string sUnitTbl;
            string sValueTbl;
            char cDefUnitFlag;
            char cDefUnitOvrFlag;
            FarPoint.Win.Spread.CellType.ComboBoxCellType UnitCellType = null;
            FarPoint.Win.Spread.CellType.ComboBoxCellType ValueCellType = null;


            TRSNode in_node = new TRSNode("VIEW_ATTACH_CHARACTER_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_ATTACH_CHARACTER_LIST_OUT");
            List<TRSNode> unit_list;

            try
            {
                spdDataCollection.SuspendLayout();
                spdDataCollection.ActiveSheet.RowCount = 0;
                spdDataCollection.ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;
                spdDataCollection.ResumeLayout();

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = ProcStep;
                in_node.AddChar("INCLUDE_UNIT_ID", cIncludeUnitID);
                in_node.AddString("COL_SET_ID", ColSetID);
                in_node.AddInt("COL_SET_VERSION", ColSetVersion);

                in_node.AddString("MAT_ID", sMatID);
                in_node.AddInt("MAT_VER", iMatVer);
                in_node.AddString("OPER", sOper);
                // in_node.AddString("LOT_ID", LotID);

                do
                {
                    if (MPCR.CallService("EDC", "EDC_View_Attach_Character_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    //컬럼의 max count 를 구해온다.
                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        iColCnt = 0;
                        iValueCnt = out_node.GetList(0)[i].GetInt("VALUE_COUNT");
                        if (iValueCnt > 0)
                        {
                            iColCnt = DEFAULT_COL_COUNT + iValueCnt;
                        }
                        else
                        {
                            iColCnt = DEFAULT_COL_COUNT;
                        }

                        if (iColCnt > iMaxColumnCnt)
                        {
                            iMaxColumnCnt = iColCnt;
                        }

                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        // Initialize
                        FarPoint.Win.Spread.SheetView with_1 = spdDataCollection.ActiveSheet;

                        iLastRow = with_1.RowCount - 1;
                        iUnitCnt = out_node.GetList(0)[i].GetInt("UNIT_COUNT");
                        iValueCnt = out_node.GetList(0)[i].GetInt("VALUE_COUNT");
                        UnitCellType = null;
                        ValueCellType = null;
                        with_1.Columns[MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Width = 50;

                        with_1.RowCount += iUnitCnt;
                        if (with_1.ColumnCount < DEFAULT_COL_COUNT + iValueCnt)
                        {
                            with_1.ColumnCount = DEFAULT_COL_COUNT + iValueCnt;
                        }

                        sDefaultValue = out_node.GetList(0)[i].GetString("DEF_VALUE");
                        sUnitTbl = out_node.GetList(0)[i].GetString("UNIT_TBL");
                        sValueTbl = out_node.GetList(0)[i].GetString("VALUE_TBL");
                        cDefUnitFlag = out_node.GetList(0)[i].GetChar("DEF_UNIT_FLAG");
                        cDefUnitOvrFlag = out_node.GetList(0)[i].GetChar("DEF_UNIT_OVR_FLAG");

                        iUnitSeq = 0;
                        for (j = iLastRow + 1; j < with_1.RowCount; j++)
                        {
                            iUnitSeq++;
                            with_1.SetValue(j, (int)COLLECTION_DATA.CHAR_COL, out_node.GetList(0)[i].GetString("CHAR_ID"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.CHAR_DESC_COL, out_node.GetList(0)[i].GetString("CHAR_DESC"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.CHAR_SEQ, out_node.GetList(0)[i].GetInt("SEQ_NUM"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.LOWER_SPEC_LIMIT, out_node.GetList(0)[i].GetString("LOWER_SPEC_LIMIT"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.TARGET_VALUE, out_node.GetList(0)[i].GetString("TARGET_VALUE"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.UPPER_SPEC_LIMIT, out_node.GetList(0)[i].GetString("UPPER_SPEC_LIMIT"));


                            with_1.SetValue(j, (int)COLLECTION_DATA.SPEC_COL, MPCF.GetSpecInfo(out_node.GetList(0)[i].GetString("UPPER_SPEC_LIMIT"),
                                                                                           out_node.GetList(0)[i].GetString("LOWER_SPEC_LIMIT"),
                                                                                           out_node.GetList(0)[i].GetString("TARGET_VALUE")));
                            with_1.SetValue(j, (int)COLLECTION_DATA.OPT_INPUT_COL, out_node.GetList(0)[i].GetChar("OPT_INPUT_FLAG"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.VALUE_TYPE_COL, out_node.GetList(0)[i].GetChar("VALUE_TYPE"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.VALUE_COUNT_COL, out_node.GetList(0)[i].GetInt("VALUE_COUNT"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.DEF_UNIT_OVR_FLAG_COL, out_node.GetList(0)[i].GetChar("DEF_UNIT_OVR_FLAG"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.DEF_VALUE_COL, out_node.GetList(0)[i].GetString("DEF_VALUE"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.UNIT_TBL_COL, out_node.GetList(0)[i].GetString("UNIT_TBL"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.VALUE_TBL_COL, out_node.GetList(0)[i].GetString("VALUE_TBL"));
                            with_1.SetValue(j, (int)COLLECTION_DATA.UNIT_SEQ_COL, iUnitSeq);
                        }

                        i_index = 0;

                        //VALUE_TYPE에 따라 컬럼의 셀 타입을 지정해준다.
                        for (j = (int)COLLECTION_DATA.VALUE_START_COL; j < (int)COLLECTION_DATA.VALUE_START_COL + iValueCnt; j++)
                        {
                            for (k = iLastRow + 1; k < with_1.RowCount; k++)
                            {
                                if (out_node.GetList(0)[i].GetChar("VALUE_TYPE") == 'N')
                                {
                                    MPCR.SetNumberCell(with_1.Cells[k, j]);
                                }
                                else
                                {
                                    MPCR.SetAsciiCell(with_1.Cells[k, j]);
                                }

                                if (cls_derived_char_list != null)
                                {
                                    if (out_node.GetList(0)[i].GetChar("DERIVED_PARAM_FLAG") == 'Y')
                                    {
                                        with_1.Cells[k, j].Locked = true;
                                        with_1.Cells[k, j].BackColor = System.Drawing.Color.Cyan;
                                        with_1.Rows[k].Tag = "AUTO";

                                        cls_derived_char_list.SetCharLocation(out_node.GetList(0)[i].GetString("CHAR_ID"), with_1, i_index, k, j);
                                    }
                                }
                            }

                            i_index += 1;
                        }

                        // ColSet의 케릭터에 셋팅한 유닛ID 정보에 맞게 셀의 상태를 바꿔준다.
                        unit_list = out_node.GetList(0)[i].GetList("UNIT_LIST");
                        //Unit ID Cell Lock

                        
                        if (unit_list.Count < 1)
                        {
                            if (cDefUnitFlag == 'C')
                            {
                                for (m = 0; m < iUnitCnt; m++)
                                {
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Locked = true;
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].BackColor = System.Drawing.Color.WhiteSmoke;
                                    with_1.SetValue(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), out_node.GetList(0)[i].GetString("UNIT"));
                                    if (out_node.GetList(0)[i].GetString("UNIT") == "")
                                    {
                                        with_1.SetValue(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), "*");
                                    }
                                    with_1.SetTag(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), "CHARACTER");
                                }

                            }
                            else if (cDefUnitFlag == 'E')
                            {
                                for (m = 0; m < iUnitCnt; m++)
                                {
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Locked = false;
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].BackColor = System.Drawing.Color.White;
                                    with_1.SetTag(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), "NULL");
                                }
                            }
                            else
                            {
                                for (m = 0; m < iUnitCnt; m++)
                                {
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Locked = false;
                                    with_1.Cells[iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].BackColor = System.Drawing.Color.White;
                                }
                            }
                        }
                        else
                        {
                            if (cDefUnitFlag == 'Y')
                            {
                                for (m = 0; m < unit_list.Count; m++)
                                {
                                    if (m > iUnitCnt - 1)
                                    {
                                        break;
                                    }

                                    // null_flag check
                                    if (unit_list[m].GetChar("NULL_FLAG") == 'Y')
                                    {
                                        with_1.SetTag(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), "NULL");
                                    }
                                    else
                                    {
                                        with_1.SetValue(iLastRow + 1 + m, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), unit_list[m].GetString("DEF_UNIT_ID"));
                                    }

                                    if (out_node.GetList(0)[i].GetChar("DEF_UNIT_OVR_FLAG") == 'Y')
                                    {
                                    }
                                    else
                                    {
                                        with_1.Cells[iLastRow + 1 + m, (int)COLLECTION_DATA.UNIT_COL].Locked = true;
                                        with_1.Cells[iLastRow + 1 + m, (int)COLLECTION_DATA.UNIT_COL].BackColor = System.Drawing.Color.WhiteSmoke;
                                    }
                                }
                            }

                            if ((cDefUnitFlag == 'Y' && cDefUnitOvrFlag == 'Y' && sUnitTbl != "") ||
                                (cDefUnitFlag == ' ' && sUnitTbl != ""))
                            {
                                for (j = iLastRow + 1; j <= with_1.RowCount - 1; j++)
                                {
                                    if (UnitCellType == null)
                                    {
                                        if (BASLIST.ViewGCMDataList(control, '1', sUnitTbl, -1, null, "", false, MPCF.ToInt(COLLECTION_DATA.UNIT_COL), j, null) == false)
                                        {
                                            return false;
                                        }
                                        else
                                        {
                                            UnitCellType = (FarPoint.Win.Spread.CellType.ComboBoxCellType)(with_1.Cells[j, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].CellType);
                                            with_1.Columns[MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].Width = 50;
                                        }
                                    }
                                    else
                                    {
                                        with_1.Cells[j, MPCF.ToInt(COLLECTION_DATA.UNIT_COL)].CellType = UnitCellType;
                                    }
                                }
                            }

                        }

                        //기본값 세팅 - > ColSet의 케릭터에 셋팅한 기본값을 넣어준다.                        
                        for (j = (int)COLLECTION_DATA.VALUE_START_COL; j <= iValueCnt + (int)COLLECTION_DATA.VALUE_START_COL - 1; j++)
                        {
                            for (k = iLastRow + 1; k <= with_1.RowCount - 1; k++)
                            {
                                if (sDefaultValue != "")
                                {
                                    with_1.SetValue(k, j, sDefaultValue);
                                }
                                if (sValueTbl != "")
                                {
                                    if (ValueCellType == null)
                                    {
                                        if (BASLIST.ViewGCMDataList(control, '1', sValueTbl, -1, null, "", false, j, k, null) == false)
                                        {
                                            return false;
                                        }
                                        else
                                        {
                                            ValueCellType = (FarPoint.Win.Spread.CellType.ComboBoxCellType)(with_1.Cells[k, j].CellType);
                                        }
                                    }
                                    else
                                    {
                                        with_1.Cells[k, j].CellType = ValueCellType;
                                    }
                                }
                            }
                        }

                        //value count 가 다른 char id의 max value count 보다 작을경우 해당 컬럼은 lock을 하고, 색을 바꿔준다.
                        with_1.ColumnCount = iMaxColumnCnt;
                        for (j = iValueCnt + (int)COLLECTION_DATA.VALUE_START_COL; j < with_1.ColumnCount; j++)
                        {
                            for (k = iLastRow + 1; k < with_1.RowCount; k++)
                            {
                                with_1.Cells[k, j].Locked = true;
                                //with_1.Cells[k, j].BackColor = System.Drawing.Color.WhiteSmoke;
                                with_1.Cells[k, j].LockBackColor = System.Drawing.Color.WhiteSmoke;
                            }
                        }
                    }

                    in_node.SetString("NEXT_CHAR_ID", out_node.GetString("NEXT_CHAR_ID"));
                } while (in_node.GetString("NEXT_CHAR_ID") != "");

                // 추가 컬럼헤더 span 및 seq 나타내기    
                FarPoint.Win.Spread.SheetView with_2 = spdDataCollection.ActiveSheet;
                int iColumnSeq = 0;

                if (with_2.ColumnCount > DEFAULT_COL_COUNT)
                {
                    with_2.ColumnHeader.Cells.Get(0, (int)COLLECTION_DATA.VALUE_START_COL).ColumnSpan = with_2.ColumnCount - DEFAULT_COL_COUNT;
                    for (i = (int)COLLECTION_DATA.VALUE_START_COL; i < with_2.ColumnCount; i++)
                    {
                        iColumnSeq++;
                        with_2.ColumnHeader.Cells.Get(1, i).Value = iColumnSeq;
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

        private bool ViewInspSpec()
        {
            int i;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
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

                    if (dt.Rows[i]["CHAR_ID"].ToString() == "POQC033")
                    {
                        // this.spdDataCollection_Sheet1.ColumnHeader.Cells.Get(1, 1).Value = "외경(mm)";
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 1].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 1].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 1].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 2].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 2].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 2].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 3].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 3].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 3].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 4].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 4].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 4].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();
                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "POQC006")
                    {
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 5].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 5].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 5].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 6].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 6].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 6].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 7].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 7].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 7].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 8].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 8].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 8].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();
                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "POQC052")
                    {
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 9].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 9].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 9].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();
                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "POQC029")
                    {
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 10].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 10].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 10].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 11].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 11].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 11].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 12].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 12].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 12].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 13].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 13].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 13].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();
                    }
                    else if (dt.Rows[i]["CHAR_ID"].ToString() == "POQC030")
                    { spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 14].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 14].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 14].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 15].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 15].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 15].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 16].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 16].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 16].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[2, 17].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[3, 17].Value = dt.Rows[i]["TARGET_VALUE"].ToString();
                        spdDataCollectionPSD.ActiveSheet.ColumnHeader.Cells[4, 17].Value = dt.Rows[i]["LOWER_SPEC_LIMIT"].ToString();

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

        private bool fnViewAttachCharacterList(Control control, char ProcStep, string ColSetID, int ColSetVersion, string LotID)
        {
            int i;

            int iLastRow = 0;
            int iUnitCnt = 0;

            int iValueCnt = 0;
            int iColCnt = 0;
            int iMaxColumnCnt = 0;

            TRSNode in_node = new TRSNode("VIEW_ATTACH_CHARACTER_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_ATTACH_CHARACTER_LIST_OUT");

            try
            {

                if(control is FpSpread)
                {
                    ((FpSpread)control).SuspendLayout();

                    ((FpSpread)control).ActiveSheet.RowCount = 0;
                    ((FpSpread)control).ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;

                    ((FpSpread)control).ResumeLayout();
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = ProcStep;

                in_node.AddString("COL_SET_ID", ColSetID);
                in_node.AddInt("COL_SET_VERSION", ColSetVersion);
                in_node.AddString("INSP_ID", txtInspID.Text);

                do
                {
                    if (MPCR.CallService("QCM", "CUS_QCM_View_Attach_Character_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    //spread max column count
                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (control is FpSpread)
                        {
                            iColCnt = 0;
                            iValueCnt = out_node.GetList(0)[i].GetInt("VALUE_COUNT");  //캐릭터별 검사 횟수
                            if (iValueCnt > 0)
                            {
                                iColCnt = DEFAULT_COL_COUNT + iValueCnt; 
                            }
                            else
                            {
                                iColCnt = DEFAULT_COL_COUNT;
                            }

                            if (iColCnt > iMaxColumnCnt)
                            {
                                iMaxColumnCnt = iColCnt;
                            }
                        }
                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (control is FpSpread)
                        {

                            FarPoint.Win.Spread.SheetView with_1 = ((FpSpread)control).ActiveSheet;

                            iLastRow = with_1.RowCount - 1;
                            iUnitCnt = out_node.GetList(0)[i].GetInt("UNIT_COUNT");










                        }
                    }





                    in_node.SetString("NEXT_CHAR_ID", out_node.GetString("NEXT_CHAR_ID"));
                } while (in_node.GetString("NEXT_CHAR_ID") != "");



            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }

        private void cdvColSetID_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            SelectedItemChangedByColSet();
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
                    ClearList("COL_SET_CHANGED");
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
            string sNodataChk = "N";
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
                        if (MPCF.Trim(cdvWorkPlace.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                            cdvWorkPlace.Focus();
                            return false;
                        }*/

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

                        /*if (spdDataCollectionPSD.ActiveSheet.RowCount == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(107));
                            spdDataCollectionPSD.Select();
                            return false;
                        }*/

                        if (MPCF.Trim(cdvColSetID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblColSetID.Text + "]");
                            cdvInspectionType.Focus();
                            return false;
                        }

                        for (int i = 0; i < spdDataCollectionPSD.ActiveSheet.RowCount; i++)
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


                            //20220920 한국 IT감사떄문에 추가한부분이라 한국에서만 체크되도록(입력된값없으면 알람창)

                            if (MPGV.gsFactory == "IJDK1")
                            {
                                for (int j = (int)COLLECTION_DATA.UNIT_COL; j <= (int)COLLECTION_DATA.UNIT_COL + MPCF.ToInt(spdDataCollection.ActiveSheet.GetValue(i, (int)COLLECTION_DATA.VALUE_COUNT_COL)); j++)
                                {
                                    if (MPCF.Trim(spdDataCollection.ActiveSheet.GetTag(i, j)) != "NULL")
                                    {
                                        if (MPCF.Trim(spdDataCollection.ActiveSheet.GetValue(i, j)) == "" && spdDataCollection.ActiveSheet.Cells[i, j].Locked == false)
                                        {

                                            sNodataChk = "Y";
                                            /*
                                                if (MPCF.ShowMsgBox(MPCF.GetMessage(564), MessageBoxButtons.YesNo, 1) != System.Windows.Forms.DialogResult.No)
                                                {
                                                    return false;
                                                }
                                                */
                                            //CMN564 INFO - 미입력된 검사데이터가 있습니다.
                                            // MPCF.ShowMsgBox(MPCF.GetMessage(564));

                                        }
                                    }
                                }

                            }

                        }

                        if (sNodataChk == "Y")
                        {
                            //CMN564 INFO - 미입력된 검사데이터가 있습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(564));
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

        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (MPCF.Trim(txtInspID.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(478));
                    cdvDept.Focus();
                    return;
                }


                if (tabControl1.SelectedTab.Name == "tpgInspCommon") // 공통화면 저장 
                {
                    
                    // 검사판정 정보, Loss 정보 저장
                    if (Collect_Inspection_Common_Data() == false)
                    {
                        return;
                    }


                }
                else if (tabControl1.SelectedTab.Name == "tpgPSD")
                {
                    // 검사판정 정보, Loss 정보 저장
                    if (Collect_Inspection_Common_Data() == false)
                    {
                        return;
                    }

                    if (Collect_Data_PSD() == false)
                    {
                        return;
                    }

                    //PSD 재조회
                    ViewInspectionGritPSD(txtInspID.Text);


                }
                else if (tabControl1.SelectedTab.Name == "tpgBI")
                {
                    // 검사판정 정보, Loss 정보 저장
                    if (Collect_Inspection_Common_Data() == false)
                    {
                        return;
                    }

                    if (Collect_Data_BI() == false)
                    {
                        return;
                    }

                    //BI 재조회
                    ViewInspectionGritBI(txtInspID.Text);

                }
                else if (tabControl1.SelectedTab.Name == "tpgBTI")
                {
                    // 검사판정 정보, Loss 정보 저장
                    if (Collect_Inspection_Common_Data() == false)
                    {
                        return;
                    }

                    if (Collect_Data_BTI() == false)
                    {
                        return;
                    }

                    //BTI 재조회
                    ViewInspectionGritBTI(txtInspID.Text);

                }
                else if (tabControl1.SelectedTab.Name == "tpgHLT")
                {
                    // 검사판정 정보, Loss 정보 저장
                    if (Collect_Inspection_Common_Data() == false)
                    {
                        return;
                    }

                    if (Collect_Data_HLT() == false)
                    {
                        return;
                    }

                    //HLT 재조회
                    ViewInspectionGritHTL(txtInspID.Text);


                }
                else if (tabControl1.SelectedTab.Name == "tpgCoating")
                {
                    // 검사판정 정보, Loss 정보 저장
                    if (Collect_Inspection_Common_Data() == false)
                    {
                        return;
                    }

                    if (Collect_Data_Coating() == false)
                    {
                        return;
                    }

                    //Coating 재조회
                    ViewInspectionGritCoating(txtInspID.Text);

                }
                else if (tabControl1.SelectedTab.Name == "tpgAspectRatio")
                {
                    // 검사판정 정보, Loss 정보 저장
                    if (Collect_Inspection_Common_Data() == false)
                    {
                        return;
                    }

                    if (Collect_Data_ASPECT() == false)
                    {
                        return;
                    }
                    //Aspect 재조회
                    ViewInspectionGritAspect(txtInspID.Text);
                }



                //재조회
                SelectedItemChangedByColSet();


                //LOSS 정보 조회
               // ViewInspectionLossInfo(txtInspID.Text);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool Collect_Inspection_Common_Data()
        {

            TRSNode in_node = new TRSNode("COLLECT_COMMON_DATA_IN");
            TRSNode out_node = new TRSNode("COLLECT_COMMON_DATA_OUT");
            TRSNode loss_list;
            int iRow = 0;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));

                if (cdvInspectionJudgeFlag.Text != "")
                {
                    in_node.AddChar("INSP_JUDGE_FLAG", MPCF.ToChar(cdvInspectionJudgeFlag.Text));
                }
                in_node.AddString("RWK_OPER", cdvReworkOper.Text);
                in_node.AddString("INSP_COMMENT", txtComment.Text);


                for (iRow = 0; iRow < spdLossInfo.ActiveSheet.RowCount; iRow++)
                {
                    if (MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[iRow, (int)LOSS_INFO.LOSS_QTY].Value) > 0)
                    {
                        loss_list = in_node.AddNode("LOSS_LIST");

                        loss_list.AddString("LOSS_CODE", spdLossInfo.ActiveSheet.Cells[iRow, (int)LOSS_INFO.LOSS_CODE].Value);  // LOSS_CODE
                        loss_list.AddDouble("LOSS_QTY", MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[iRow, (int)LOSS_INFO.LOSS_QTY].Value));
                        if (spdLossInfo.ActiveSheet.Cells[iRow, (int)LOSS_INFO.MAIN_YN].Value.ToString().ToUpper() == "TRUE")
                        {
                            loss_list.AddChar("MAIN_FLAG", 'Y');
                        }
                        else
                        {
                            loss_list.AddChar("MAIN_FLAG", 'N');
                        }
                    }
                }


                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Collect_Inspection_Data", in_node, ref out_node, false) == false)
                {
                    return false;
                }
                else
                {
                    //MPCR.ShowSuccessMsg(out_node);
                }

                //Loss 정보 조회(LOSS정보 필요없음)
               // ViewInspectionLossInfo(txtInspID.Text, cdvInspOper.Text);


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }
        private bool Collect_Data_PSD()
        {

            TRSNode in_node = new TRSNode("COLLECTION_DATA_PSD_IN");
            TRSNode out_node = new TRSNode("COLLECTION_DATA_PSD_OUT");
            TRSNode data_list;

            int iRow = 0;

            string sLotID;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1'; //PSD 저장

                sLotID = spdLotList.ActiveSheet.GetValue(0, (int)LOT_INFO.LOT_ID).ToString();

                in_node.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));   //검사 ID
                in_node.AddString("LOT_ID", sLotID);  // LOT_ID
                in_node.AddString("COL_SET_ID", cdvColSetID.Text);
                in_node.AddInt("COL_SET_VER", MPCF.ToInt(txtColSetVer.Text));

                in_node.AddString("INSP_DTL_TYPE", "PSD");
                in_node.AddInt("INSP_COUNT", MPCF.ToInt(cdvInspPSDCount.Text));

                for (iRow = 0; iRow < spdDataCollectionPSD.ActiveSheet.RowCount; iRow++)
                {
                    data_list = in_node.AddNode("DATA_LIST");

                    data_list.AddInt("INSP_SEQ", spdDataCollectionPSD.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_PDC.INSP_SEQ].Value);
                    data_list.AddString("SIEVE_CODE", spdDataCollectionPSD.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_PDC.SIEVE_CODE].Value);
                    data_list.AddDouble("SIEVE_VALUE", spdDataCollectionPSD.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_PDC.SIEVE_VALUE].Value);

                    data_list.AddDouble("NOT_SIEVE_1", spdDataCollectionPSD.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_PDC.NOT_SIEVE_1].Value);      //빈체
                    data_list.AddDouble("EXIST_SIEVE_1", spdDataCollectionPSD.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_PDC.EXIST_SIEVE_1].Value);  //찬체
                    data_list.AddDouble("DIFF_SIEVE_1", spdDataCollectionPSD.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_PDC.DIFF_SIEVE_1].Value);     //차이
                    data_list.AddDouble("TI_VALUE_1", spdDataCollectionPSD.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_PDC.TI_VALUE_1].Value);           //(%)

                    data_list.AddDouble("SUM_DIFF_SIEVE", spdDataCollectionPSD.ActiveSheet.ColumnFooter.Cells[0, (int)COLLECTION_DATA_PDC.DIFF_SIEVE_1].Value); // SUM DIFF SIEVE
                    data_list.AddDouble("RATIO_SIEVE", spdDataCollectionPSD.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_PDC.TI_VALUE_1].Value);                         // RATIO SIEVE

                }

                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Collect_Inspection_Data_Grit", in_node, ref out_node, false) == false)
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

        private bool Collect_Data_BI()
        {

            TRSNode in_node = new TRSNode("COLLECTION_DATA_BI_IN");
            TRSNode out_node = new TRSNode("COLLECTION_DATA_BI_OUT");
            TRSNode data_list;

            int iRow = 0;

            string sLotID;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2'; //BI 저장

                sLotID = spdLotList.ActiveSheet.GetValue(0, (int)LOT_INFO.LOT_ID).ToString();

                in_node.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));   //검사 ID
                in_node.AddString("LOT_ID", sLotID);  // LOT_ID
                in_node.AddString("COL_SET_ID", cdvColSetID.Text);
                in_node.AddInt("COL_SET_VER", MPCF.ToInt(txtColSetVer.Text));

                in_node.AddString("INSP_DTL_TYPE", "BI");
                in_node.AddInt("INSP_COUNT", MPCF.ToInt(cdvInspBICount.Text));

                for (iRow = 0; iRow < spdDataCollectionBI.ActiveSheet.RowCount; iRow++)
                {
                    data_list = in_node.AddNode("DATA_LIST");

                    data_list.AddInt("INSP_SEQ", spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.INSP_SEQ].Value);
                    data_list.AddString("SIEVE_CODE", spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.SIEVE_CODE].Value);
                    data_list.AddDouble("SIEVE_VALUE", spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.SIEVE_VALUE].Value);

                    data_list.AddDouble("NOT_SIEVE_1", spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.NOT_SIEVE_1].Value);      //1차 빈체
                    data_list.AddDouble("EXIST_SIEVE_1", spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.EXIST_SIEVE_1].Value);  //1차 찬체
                    data_list.AddDouble("DIFF_SIEVE_1", spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.DIFF_SIEVE_1].Value);     //1차 차이
                    data_list.AddDouble("TI_VALUE_1", spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.TI_VALUE_1].Value);           //1차 (%)

                    data_list.AddDouble("NOT_SIEVE_2", spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.NOT_SIEVE_2].Value);      //2차 빈체
                    data_list.AddDouble("EXIST_SIEVE_2", spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.EXIST_SIEVE_2].Value);  //2차 찬체
                    data_list.AddDouble("DIFF_SIEVE_2", spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.DIFF_SIEVE_2].Value);     //2차 차이
                    data_list.AddDouble("TI_VALUE_2", spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.TI_VALUE_2].Value);           //2차 (%)

                    data_list.AddDouble("AVG_SIEVE", spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.AVG_SIEVE].Value);
                    data_list.AddDouble("TI_CHANGE", spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.TI_CHANGE].Value);

                    data_list.AddDouble("COUNT_1", MPCF.ToDbl(txtBICount1.Text));
                    data_list.AddDouble("COUNT_2", MPCF.ToDbl(txtBICount2.Text));
                }

                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Collect_Inspection_Data_Grit", in_node, ref out_node, false) == false)
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

        private bool Collect_Data_BTI()
        {

            TRSNode in_node = new TRSNode("COLLECTION_DATA_BTI_IN");
            TRSNode out_node = new TRSNode("COLLECTION_DATA_BTI_OUT");
            TRSNode data_list;

            int iRow = 0;

            string sLotID;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '3'; //BTI 저장

                sLotID = spdLotList.ActiveSheet.GetValue(0, (int)LOT_INFO.LOT_ID).ToString();

                in_node.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));   //검사 ID
                in_node.AddString("LOT_ID", sLotID);  // LOT_ID
                in_node.AddString("COL_SET_ID", cdvColSetID.Text);
                in_node.AddInt("COL_SET_VER", MPCF.ToInt(txtColSetVer.Text));

                in_node.AddString("INSP_DTL_TYPE", "BTI");
                in_node.AddInt("INSP_COUNT", MPCF.ToInt(cdvInspBTICount.Text));

                for (iRow = 0; iRow < spdDataCollectionBTI.ActiveSheet.RowCount; iRow++)
                {
                    data_list = in_node.AddNode("DATA_LIST");

                    data_list.AddInt("INSP_SEQ", spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.INSP_SEQ].Value);
                    data_list.AddString("SIEVE_CODE", spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.SIEVE_CODE].Value);
                    data_list.AddDouble("SIEVE_VALUE", spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.SIEVE_VALUE].Value);

                    data_list.AddDouble("NOT_SIEVE_1", spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.NOT_SIEVE_1].Value);      //1차 빈체
                    data_list.AddDouble("EXIST_SIEVE_1", spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.EXIST_SIEVE_1].Value);  //1차 찬체
                    data_list.AddDouble("DIFF_SIEVE_1", spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.DIFF_SIEVE_1].Value);     //1차 차이
                    data_list.AddDouble("TI_VALUE_1", spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.TI_VALUE_1].Value);           //1차 (%)

                    data_list.AddDouble("NOT_SIEVE_2", spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.NOT_SIEVE_2].Value);      //2차 빈체
                    data_list.AddDouble("EXIST_SIEVE_2", spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.EXIST_SIEVE_2].Value);  //2차 찬체
                    data_list.AddDouble("DIFF_SIEVE_2", spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.DIFF_SIEVE_2].Value);     //2차 차이
                    data_list.AddDouble("TI_VALUE_2", spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.TI_VALUE_2].Value);           //2차 (%)

                    data_list.AddDouble("AVG_SIEVE", spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.AVG_SIEVE].Value);
                    data_list.AddDouble("TI_CHANGE", spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.TI_CHANGE].Value);

                    data_list.AddDouble("COUNT_1", MPCF.ToDbl(txtBTICount1.Text));
                    data_list.AddDouble("COUNT_2", MPCF.ToDbl(txtBTICount2.Text));

                }

                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Collect_Inspection_Data_Grit", in_node, ref out_node, false) == false)
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

        private bool Collect_Data_ASPECT()
        {

            TRSNode in_node = new TRSNode("COLLECTION_DATA_ASPECT_IN");
            TRSNode out_node = new TRSNode("COLLECTION_DATA_ASPECT_OUT");
            TRSNode data_list;

            int iRow = 0;

            string sLotID;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '6'; //BTI 저장

                sLotID = spdLotList.ActiveSheet.GetValue(0, (int)LOT_INFO.LOT_ID).ToString();

                in_node.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));   //검사 ID
                in_node.AddString("LOT_ID", sLotID);  // LOT_ID
                in_node.AddString("COL_SET_ID", cdvColSetID.Text);
                in_node.AddInt("COL_SET_VER", MPCF.ToInt(txtColSetVer.Text));

                in_node.AddString("INSP_DTL_TYPE", "ASPECT");

                for (iRow = 0; iRow < spdDataCollectionAspect.ActiveSheet.RowCount; iRow++)
                {
                    data_list = in_node.AddNode("DATA_LIST");

                    data_list.AddInt("INSP_SEQ", spdDataCollectionAspect.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ASPECT.INSP_SEQ].Value);
                    data_list.AddString("QC_NAME", spdDataCollectionAspect.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ASPECT.QC_NAME].Value);
                    data_list.AddDouble("SPEC_VAL", spdDataCollectionAspect.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ASPECT.SPEC_VAL].Value);
                    data_list.AddDouble("VAL_1", spdDataCollectionAspect.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ASPECT.VAL_1].Value);  //MEAN
                    data_list.AddDouble("VAL_2", spdDataCollectionAspect.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ASPECT.VAL_2].Value);  //D10
                    data_list.AddDouble("VAL_3", spdDataCollectionAspect.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ASPECT.VAL_3].Value);  //D25
                    data_list.AddDouble("VAL_4", spdDataCollectionAspect.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ASPECT.VAL_4].Value);  //D50
                    data_list.AddDouble("VAL_5", spdDataCollectionAspect.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ASPECT.VAL_5].Value);  //D75
                    data_list.AddDouble("VAL_6", spdDataCollectionAspect.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ASPECT.VAL_6].Value);  //D90
                }

                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Collect_Inspection_Data_Grit", in_node, ref out_node, false) == false)
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

        private bool Collect_Data_HLT()
        {

            TRSNode in_node = new TRSNode("COLLECTION_DATA_HLT_IN");
            TRSNode out_node = new TRSNode("COLLECTION_DATA_HLT_OUT");
            TRSNode data_list;

            int iRow = 0;

            string sLotID;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '4'; //HLT 저장

                sLotID = spdLotList.ActiveSheet.GetValue(0, (int)LOT_INFO.LOT_ID).ToString();

                in_node.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));   //검사 ID
                in_node.AddString("LOT_ID", sLotID);  // LOT_ID
                in_node.AddString("COL_SET_ID", cdvColSetID.Text);
                in_node.AddInt("COL_SET_VER", MPCF.ToInt(txtColSetVer.Text));

                in_node.AddString("INSP_DTL_TYPE", "HLT");
                in_node.AddInt("INSP_COUNT", MPCF.ToInt(cdvInspHLTCount.Text));

                if (bDoubleSize)
                {
                    in_node.AddChar("DOUBLE_SIZE_YN", 'Y');
                }
                else
                {
                    in_node.AddChar("DOUBLE_SIZE_YN", 'N');
                }
                   
                

                for (iRow = 0; iRow < spdDataCollectionHLT.ActiveSheet.RowCount; iRow++)
                {
                    data_list = in_node.AddNode("DATA_LIST");

                    data_list.AddInt("INSP_SEQ", spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.INSP_SEQ].Value);  //seq

                    data_list.AddString("SIZES_1", txtHLTSize1.Text);
                    data_list.AddDouble("SIEVE_VALUE_1", spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.SIEVE_VALUE_1].Value);
                    data_list.AddDouble("SMASH_TIME_1", MPCF.ToDbl(txtHLTMeshTime1.Text));
                    data_list.AddDouble("COUNT_1", MPCF.ToDbl(txtHLTCount1.Text));
                    data_list.AddDouble("NOT_SIEVE_1", spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.NOT_SIEVE_1].Value);      //좌측 빈체
                    data_list.AddDouble("EXIST_SIEVE_1", spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.EXIST_SIEVE_1].Value);  //좌측 찬체
                    data_list.AddDouble("DIFF_SIEVE_1", spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.DIFF_SIEVE_1].Value);     //좌측 차이
                    data_list.AddDouble("TOTAL_SIEVE_1", spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_1].Value);   //좌측  (%)
                    data_list.AddDouble("AVG_SIEVE_1", spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.AVG_SIEVE_1].Value);           //좌측 평균
                    data_list.AddDouble("F_VALUE_1", spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.F_VALUE_1].Value);           //좌측 FACTOR
                    data_list.AddDouble("TI_VALUE_1", MPCF.ToDbl(txtHLTTiValue1.Text));  //좌측 TI Value

                    //DoubleSize 일 때, 전달
                    if (bDoubleSize)
                    {
                        data_list.AddString("SIZES_2", txtHLTSize2.Text);
                        data_list.AddDouble("SIEVE_VALUE_2", spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.SIEVE_VALUE_2].Value);
                        data_list.AddDouble("SMASH_TIME_2", MPCF.ToDbl(txtHLTMeshTime2.Text));
                        data_list.AddDouble("COUNT_2", MPCF.ToDbl(txtHLTCount2.Text));
                        data_list.AddDouble("NOT_SIEVE_2", spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.NOT_SIEVE_2].Value);      //우측 빈체  (Double Size시)
                        data_list.AddDouble("EXIST_SIEVE_2", spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.EXIST_SIEVE_2].Value);  //우측 찬체  (Double Size시)
                        data_list.AddDouble("DIFF_SIEVE_2", spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.DIFF_SIEVE_2].Value);     //우측 차이  (Double Size시)
                        data_list.AddDouble("TOTAL_SIEVE_2", spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_2].Value);   //우측  (%) (Double Size시)
                        data_list.AddDouble("AVG_SIEVE_2", spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.AVG_SIEVE_2].Value);           //우측 평균 (Double Size시)
                        data_list.AddDouble("F_VALUE_2", spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.F_VALUE_2].Value);           //우측 FACTOR (Double Size시)
                        data_list.AddDouble("TI_VALUE_2", MPCF.ToDbl(txtHLTTiValue2.Text));  //좌측 TI Value
                    }

                    data_list.AddDouble("TI_RESULT",MPCF.ToDbl( txtHLTResult.Text));



                }

                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Collect_Inspection_Data_Grit", in_node, ref out_node, false) == false)
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

        private bool Collect_Data_Coating()
        {

            TRSNode in_node = new TRSNode("COLLECTION_DATA_COATING_IN");
            TRSNode out_node = new TRSNode("COLLECTION_DATA_COATING_OUT");


            string sLotID;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '5'; //Coating 저장

                sLotID = spdLotList.ActiveSheet.GetValue(0, (int)LOT_INFO.LOT_ID).ToString();

                in_node.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));   //검사 ID
                in_node.AddString("LOT_ID", sLotID);  // LOT_ID
                in_node.AddString("COL_SET_ID", cdvColSetID.Text);
                in_node.AddInt("COL_SET_VER", MPCF.ToInt(txtColSetVer.Text));

                in_node.AddString("INSP_DTL_TYPE", "COATING");
                in_node.AddInt("INSP_COUNT", 1);


                in_node.AddDouble("MA_VALUE_1", MPCF.ToDbl(txtMAValue1.Text));
                in_node.AddDouble("MA_RESULT", MPCF.ToDbl(txtMAResult.Text));

                in_node.AddDouble("WT_VALUE_1", MPCF.ToDbl(txtWTValue1.Text));
                in_node.AddDouble("WT_VALUE_2", MPCF.ToDbl(txtWTValue2.Text));
                in_node.AddDouble("WT_VALUE_3", MPCF.ToDbl(txtWTValue3.Text));
                in_node.AddDouble("WT_RESULT", MPCF.ToDbl(txtWTResult.Text));

                in_node.AddDouble("BD_VALUE_1", MPCF.ToDbl(txtBDValue1.Text));
                in_node.AddDouble("BD_RESULT", MPCF.ToDbl(txtBDResult.Text));

                in_node.AddDouble("TD_VALUE_1", MPCF.ToDbl(txtTDValue1.Text));
                in_node.AddDouble("TD_RESULT", MPCF.ToDbl(txtTDResult.Text));

                in_node.AddDouble("PCS_VALUE_1", MPCF.ToDbl(txtPCSValue1.Text));
                in_node.AddDouble("PCS_RESULT", MPCF.ToDbl(txtPCSResult.Text));

                in_node.AddDouble("PS_VALUE_1", MPCF.ToDbl(txtPSValue1.Text));
                in_node.AddDouble("PS_VALUE_2", MPCF.ToDbl(txtPSValue2.Text));
                in_node.AddDouble("PS_RESULT", MPCF.ToDbl(txtPSResult.Text));

                in_node.AddDouble("CM_L", MPCF.ToDbl(txtCML.Text));
                in_node.AddDouble("CM_A", MPCF.ToDbl(txtCMA.Text));
                in_node.AddDouble("CM_B", MPCF.ToDbl(txtCMB.Text));

                in_node.AddString("REMARKS", MPCF.Trim(txtRemarksCoating.Text));

                in_node.AddDouble("GRAIN_SIZE", MPCF.ToDbl(txtGrainSize.Text));
                in_node.AddDouble("ELIP_VALUE2", MPCF.ToDbl(txtEllipticity.Text));
                in_node.AddDouble("ROUG_VALUE", MPCF.ToDbl(txtRoughness.Text));
                in_node.AddDouble("CIRCULRARITY", MPCF.ToDbl(txtCirculrarity.Text));
                in_node.AddDouble("CONVEXITY", MPCF.ToDbl(txtConvexity.Text));
                in_node.AddDouble("SHAPE_FACTOR", MPCF.ToDbl(txtShapeFactor.Text));
                in_node.AddDouble("SURFACE_B", MPCF.ToDbl(txtSurfaceB.Text));
                in_node.AddDouble("CON_O_VALUE", MPCF.ToDbl(txtConOValue.Text));


                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Collect_Inspection_Data_Grit", in_node, ref out_node, false) == false)
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

        private bool Inspection_Judge()
        {

            TRSNode in_node = new TRSNode("INSPECTION_JUDGE_IN");
            TRSNode out_node = new TRSNode("INSPECTION_JUDGE_OUT");
            TRSNode loss_list;
            TRSNode worker_list;

            string sLotID;
            int iRow = 0;
            int iWrkRow = 0;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1'; //GRIT 제품검사  판정

                //INSP_ID, LOT_ID, INSP_JUDGE_FLAG, REWORK_OPER, INSP_COMMENT
                sLotID = spdLotList.ActiveSheet.GetValue(0, (int)LOT_INFO.LOT_ID).ToString();
                
                in_node.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));   //검사 ID
                in_node.AddString("COL_SET_ID", MPCF.Trim(cdvColSetID.Text)); //COL SET ID 
                in_node.AddInt("COL_SET_VERSION", MPCF.ToInt(txtColSetVer.Text));
                in_node.AddString("LOT_ID", sLotID);  // LOT_ID
                in_node.AddChar("INSP_JUDGE_FLAG", MPCF.Trim(cdvInspectionJudgeFlag.Text));  // 판정 Flag
                
                in_node.AddString("INSP_COMMENT",MPCF.Trim(txtComment.Text));                        //주석

                
                in_node.AddString("TO_FLOW", MPCF.Trim(spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.FLOW].Value.ToString()));
                in_node.AddString("TO_OPER", MPCF.Trim(cdvReworkOper.Text));
                
                for (iRow = 0; iRow < spdLossInfo.ActiveSheet.RowCount; iRow++)
                {
                    if (MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[iRow, (int)LOSS_INFO.LOSS_QTY].Value) > 0)
                    {
                        loss_list = in_node.AddNode("LOSS_LIST");

                        loss_list.AddString("LOSS_CODE", spdLossInfo.ActiveSheet.Cells[iRow, (int)LOSS_INFO.LOSS_CODE].Value);  // LOSS_CODE
                        loss_list.AddDouble("LOSS_QTY", MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[iRow, (int)LOSS_INFO.LOSS_QTY].Value));

                    }
                }

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
               // txtComment.Enabled = true;
                cdvReworkOper.Enabled = true;
                //btnJudge.Enabled = true;
                if (tabControl1.SelectedIndex == 0)
                {
                    btnJudge.Enabled = true;
                }
                else
                {
                    btnJudge.Enabled = false;
                }
                btnProcess.Enabled = true;
                cdvColSetID.Enabled = true;

               // spdLossInfo.ActiveSheet.OperationMode = OperationMode.Normal;
                spdDataCollectionPSD.ActiveSheet.OperationMode = OperationMode.Normal;
                spdDataCollectionBI.ActiveSheet.OperationMode = OperationMode.Normal;
                spdDataCollectionBTI.ActiveSheet.OperationMode = OperationMode.Normal;
                spdDataCollectionHLT.ActiveSheet.OperationMode = OperationMode.Normal;
                spdDataCollectionAspect.ActiveSheet.OperationMode = OperationMode.Normal;

                panHLTTop.Enabled = true;
                panCoating.Enabled = true;
                
            }
            else if (txtInspectionStatus.Text == "C" || txtInspectionStatus.Text == "S" || txtInspectionStatus.Text == "Q")
            {
                if (txtInspectionStatus.Text == "Q")
                {
                    btnReceive.Enabled = true;
                    btnProcess.Enabled = false;

                    spdDataCollectionPSD.ActiveSheet.OperationMode = OperationMode.ReadOnly;
                    spdDataCollectionBI.ActiveSheet.OperationMode = OperationMode.ReadOnly;
                    spdDataCollectionBTI.ActiveSheet.OperationMode = OperationMode.ReadOnly;
                    spdDataCollectionHLT.ActiveSheet.OperationMode = OperationMode.ReadOnly;
                    spdDataCollectionAspect.ActiveSheet.OperationMode = OperationMode.ReadOnly;
                    panHLTTop.Enabled = false;
                    panCoating.Enabled = false;
                }
                else
                {
                    btnProcess.Enabled = true;
                    btnReceive.Enabled = false;

                    spdDataCollectionPSD.ActiveSheet.OperationMode = OperationMode.Normal;
                    spdDataCollectionBI.ActiveSheet.OperationMode = OperationMode.Normal;
                    spdDataCollectionBTI.ActiveSheet.OperationMode = OperationMode.Normal;
                    spdDataCollectionHLT.ActiveSheet.OperationMode = OperationMode.Normal;
                    spdDataCollectionAspect.ActiveSheet.OperationMode = OperationMode.Normal;
                    panHLTTop.Enabled = true;
                    panCoating.Enabled = true;
                }
                cdvInspectionJudgeFlag.Enabled = false;
               // txtComment.Enabled = false ;
                cdvReworkOper.Enabled = false;
                btnJudge.Enabled = false;
                btnHold.Enabled = false;

                cdvColSetID.Enabled = false;

                //spdLossInfo.ActiveSheet.OperationMode = OperationMode.ReadOnly;  //Loss정보는 판정 이후에도 수정가능하게 수정




            }
        }

        private void cdvInspectionJudgeFlag_ButtonPress(object sender, EventArgs e)
        {
           /* cdvInspectionJudgeFlag.Init();
            MPCF.InitListView(cdvInspectionJudgeFlag.GetListView);
            cdvInspectionJudgeFlag.Columns.Add("Judge", 50, HorizontalAlignment.Left);
            cdvInspectionJudgeFlag.Columns.Add("Desc", 50, HorizontalAlignment.Left);
            cdvInspectionJudgeFlag.SelectedSubItemIndex = 0;
            cdvInspectionJudgeFlag.DisplaySubItemIndex = 1;

            if (BASLIST.ViewGCMDataList(cdvInspectionJudgeFlag.GetListView, '1', CSGC.CP_GCM_INSP_JUDGE_FLAG, -1, null, "", true, -1, -1, null, null) == false)
            {
                return;
            }*/
        }

        private void cdvInspectionJudgeFlag_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            if (MPCF.Trim(cdvInspectionJudgeFlag.Text) == "R")
            {
                cdvReworkOper.Init();
            }


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

                // 검사판정 정보, Loss 정보 저장
                if (Collect_Inspection_Common_Data() == false)
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
            int i_check_row = e.Row;
            int i_check_col = e.Column;

            bool b_check;

            if (e.Column == (int)LOSS_INFO.MAIN_YN)
            {

                if ((bool)spdLossInfo.ActiveSheet.Cells[i_check_row, i_check_col].Value)
                {
                    b_check = false;
                }
                else
                {
                    b_check = true;
                }

                if (!b_check)
                {
                    for (int i = 0; i < spdLossInfo.ActiveSheet.RowCount; i++)
                    {
                        if (i == i_check_row)
                            continue;

                        spdLossInfo.ActiveSheet.Cells[i, i_check_col].Value = b_check;

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
                    btnHold.Enabled = false;
                    btnJudge.Enabled = false;
                }
            }
            else
            {
                btnJudge.Enabled = false;
                btnHold.Enabled = false;
            }
        }

        private void cdvReworkOper_ButtonPress(object sender, EventArgs e)
        {
            if (MPCF.Trim(cdvInspectionJudgeFlag.Text) == "R")
            {
                initReworkOperList(cdvReworkOper.GetListView);

            }
            else
            {
                cdvReworkOper.Init();
                // cdvReworkOper.Text = " ";
                // cdvReworkOper.DisplayText = " ";
            }
        }

        private void cdvInspCount_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            if (txtInspID.Text != "")
                ViewInspectionGritPSD(txtInspID.Text);
        }

        private void cdvInspCount_ButtonPress(object sender, EventArgs e)
        {
            cdvInspPSDCount.Init();
            MPCF.InitListView(cdvInspPSDCount.GetListView);
            cdvInspPSDCount.Columns.Add("Count", 50, HorizontalAlignment.Left);
            cdvInspPSDCount.SelectedSubItemIndex = 0;
            cdvInspPSDCount.DisplaySubItemIndex = 0;


            if (BASLIST.ViewGCMDataList(cdvInspPSDCount.GetListView, '1', CSGC.CP_GCM_INSP_COUNT, -1, null, "", true, -1, -1, null, null) == false)
            {
                return;
            }
        }

        private void spdDataCollection_Change(object sender, ChangeEventArgs e)
        {
            double dNotSieve;
            double dExistSieve;
            double dDiffValue;

            int iRow = e.Row;

            //빈체
            if (e.Column == (int)COLLECTION_DATA_PDC.NOT_SIEVE_1 || e.Column == (int)COLLECTION_DATA_PDC.EXIST_SIEVE_1)
            {
                dNotSieve = MPCF.ToDbl(spdDataCollectionPSD.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_PDC.NOT_SIEVE_1].Value);
                dExistSieve = MPCF.ToDbl(spdDataCollectionPSD.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_PDC.EXIST_SIEVE_1].Value);

                if (dExistSieve > dNotSieve)
                    dDiffValue = dExistSieve - dNotSieve;
                else
                    dDiffValue = 0;

                spdDataCollectionPSD.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_PDC.DIFF_SIEVE_1].Value = dDiffValue;

                RecalculrationPercent();
            }

        }

        private void RecalculrationPercent()
        {
            double dDiffSum = 0;

            double dDiff = 0;

            for (int i = 0; i < spdDataCollectionPSD.ActiveSheet.RowCount; i++)
            {
                dDiffSum += MPCF.ToDbl(spdDataCollectionPSD.ActiveSheet.Cells[i, (int)COLLECTION_DATA_PDC.DIFF_SIEVE_1].Value);
            }

            if (dDiffSum != 0)
            {
                for (int i = 0; i < spdDataCollectionPSD.ActiveSheet.RowCount; i++)
                {

                    dDiff = MPCF.ToDbl(spdDataCollectionPSD.ActiveSheet.Cells[i, (int)COLLECTION_DATA_PDC.DIFF_SIEVE_1].Value);

                    spdDataCollectionPSD.ActiveSheet.Cells[i, (int)COLLECTION_DATA_PDC.TI_VALUE_1].Value = Math.Round((dDiff / dDiffSum) * 100, 1, MidpointRounding.AwayFromZero);

                }
            }
          

        }

        private void spdDataCollectionBI_Change(object sender, ChangeEventArgs e)
        {
            

        }

        private void frmTranInspectionRegistrationGRIT_SMP_Load(object sender, EventArgs e)
        {
            cdvWorkGroup.Text = "A";
            cdvDept.Text = CSGC.CP_AREA_GRT;

            defModelPSD = new DefaultSheetDataModel(0, spdDataCollectionPSD.ActiveSheet.Columns.Count);
            defModel = new DefaultSheetDataModel(0, spdDataCollectionBI.ActiveSheet.Columns.Count);
            defModelBTI = new DefaultSheetDataModel(0, spdDataCollectionBTI.ActiveSheet.Columns.Count);
            defModelHLT = new DefaultSheetDataModel(0, spdDataCollectionHLT.ActiveSheet.Columns.Count);

            spdDataCollectionPSD.ActiveSheet.Models.Data = defModelPSD;
            spdDataCollectionBI.ActiveSheet.Models.Data = defModel;
            spdDataCollectionBTI.ActiveSheet.Models.Data = defModelBTI;
            spdDataCollectionHLT.ActiveSheet.Models.Data = defModelHLT;

            this.defModelPSD.Changed += new SheetDataModelEventHandler(this.defModelPSD_Changed);
            this.defModel.Changed += new SheetDataModelEventHandler(this.defModel_Changed);
            this.defModelBTI.Changed += new SheetDataModelEventHandler(this.defModelBTI_Changed);
            this.defModelHLT.Changed += new SheetDataModelEventHandler(this.defModelHLT_Changed);


            FarPoint.Win.Spread.InputMap inputmap;
            inputmap = spdDataCollectionPSD.GetInputMap(FarPoint.Win.Spread.InputMapMode.WhenAncestorOfFocused);
            inputmap.Put(new FarPoint.Win.Spread.Keystroke(Keys.Enter, Keys.None), FarPoint.Win.Spread.SpreadActions.MoveToNextRow);


        }


        //defModelPSD_Changed
        private void defModelPSD_Changed(object sender, FarPoint.Win.Spread.Model.SheetDataModelEventArgs e)
        {
            if (!b_allow_changed)
                return;

            double dNotSieve;
            double dExistSieve;
            double dDiffValue;

            int iRow = e.Row;

            //빈체
            if (e.Column == (int)COLLECTION_DATA_PDC.NOT_SIEVE_1 || e.Column == (int)COLLECTION_DATA_PDC.EXIST_SIEVE_1)
            {
                dNotSieve = MPCF.ToDbl(spdDataCollectionPSD.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_PDC.NOT_SIEVE_1].Value);
                dExistSieve = MPCF.ToDbl(spdDataCollectionPSD.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_PDC.EXIST_SIEVE_1].Value);

                if (dExistSieve > dNotSieve)
                    dDiffValue = dExistSieve - dNotSieve;
                else
                    dDiffValue = 0;

                spdDataCollectionPSD.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_PDC.DIFF_SIEVE_1].Value = dDiffValue;

                RecalculrationPercent();
            }

        }
        private void defModel_Changed(object sender, FarPoint.Win.Spread.Model.SheetDataModelEventArgs e)
        {
            if (!b_allow_changed)
                return;


            double dNotSieve;
            double dExistSieve;
            double dDiffValue;
            double dDiffValueRow2;

            double dTi1;
            double dTi2;

            double dTiValue1;
            double dTiValue2;

            double dAvgValue;

            int iRow = e.Row;

            //빈체
            if (e.Column == (int)COLLECTION_DATA_BI.NOT_SIEVE_1 || e.Column == (int)COLLECTION_DATA_BI.EXIST_SIEVE_1)
            {
                //#1 변경시 
                dNotSieve = MPCF.ToDbl(spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.NOT_SIEVE_1].Value);
                dExistSieve = MPCF.ToDbl(spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.EXIST_SIEVE_1].Value);

                if (dExistSieve > dNotSieve)
                    dDiffValue = dExistSieve - dNotSieve;
                else
                    dDiffValue = 0;

                //차(g)
                //spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.DIFF_SIEVE_1].Value = dDiffValue;

                spdDataCollectionBI.ActiveSheet.SetValue(iRow, (int)COLLECTION_DATA_BI.DIFF_SIEVE_1, dDiffValue);


            }
            else if (e.Column == (int)COLLECTION_DATA_BI.NOT_SIEVE_2 || e.Column == (int)COLLECTION_DATA_BI.EXIST_SIEVE_2)
            {
                //#2 변경시 
                dNotSieve = MPCF.ToDbl(spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.NOT_SIEVE_2].Value);
                dExistSieve = MPCF.ToDbl(spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.EXIST_SIEVE_2].Value);

                if (dExistSieve > dNotSieve)
                    dDiffValue = dExistSieve - dNotSieve;
                else
                    dDiffValue = 0;

                //차(g)
                spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.DIFF_SIEVE_2].Value = dDiffValue;


            }
            else if (e.Column == (int)COLLECTION_DATA_BI.DIFF_SIEVE_1)
            {
                if (iRow == 0)
                {
                    //#1 차이
                    dDiffValue = MPCF.ToDbl(spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.DIFF_SIEVE_1].Value);
                    dTi1 = Math.Round((dDiffValue / 0.4) * 100, 1, MidpointRounding.AwayFromZero);

                    // TI  계산
                    spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.TI_VALUE_1].Value = dTi1;


                    //#2 TI 계산
                    dDiffValueRow2 = MPCF.ToDbl(spdDataCollectionBI.ActiveSheet.Cells[iRow + 1, (int)COLLECTION_DATA_BI.DIFF_SIEVE_1].Value);
                    dTi2 = Math.Round(dTi1 + ((dDiffValueRow2 / 0.4) * 100), 1, MidpointRounding.AwayFromZero);

                    spdDataCollectionBI.ActiveSheet.Cells[iRow + 1, (int)COLLECTION_DATA_BI.TI_VALUE_1].Value = dTi2;

                }
                else if (iRow == 1)
                {
                    //#1 TI
                    dTi1 = MPCF.ToDbl(spdDataCollectionBI.ActiveSheet.Cells[iRow - 1, (int)COLLECTION_DATA_BI.TI_VALUE_1].Value);

                    //#2 차이
                    dDiffValueRow2 = MPCF.ToDbl(spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.DIFF_SIEVE_1].Value);
                    dTi2 = Math.Round(dTi1 + ((dDiffValueRow2 / 0.4) * 100), 1, MidpointRounding.AwayFromZero);

                    spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.TI_VALUE_1].Value = dTi2;

                }
            }
            else if (e.Column == (int)COLLECTION_DATA_BI.DIFF_SIEVE_2)
            {
                if (iRow == 0)
                {
                    //#1 차이
                    dDiffValue = MPCF.ToDbl(spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.DIFF_SIEVE_2].Value);
                    dTi1 = Math.Round((dDiffValue / 0.4) * 100, 1, MidpointRounding.AwayFromZero);

                    // TI  계산
                    spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.TI_VALUE_2].Value = dTi1;


                    //#2 TI 계산
                    dDiffValueRow2 = MPCF.ToDbl(spdDataCollectionBI.ActiveSheet.Cells[iRow + 1, (int)COLLECTION_DATA_BI.DIFF_SIEVE_2].Value);
                    dTi2 = Math.Round(dTi1 + ((dDiffValueRow2 / 0.4) * 100), 1, MidpointRounding.AwayFromZero);

                    spdDataCollectionBI.ActiveSheet.Cells[iRow + 1, (int)COLLECTION_DATA_BI.TI_VALUE_2].Value = dTi2;

                }
                else if (iRow == 1)
                {
                    //#1 TI
                    dTi1 = MPCF.ToDbl(spdDataCollectionBI.ActiveSheet.Cells[iRow - 1, (int)COLLECTION_DATA_BI.TI_VALUE_2].Value);

                    //#2 차이
                    dDiffValueRow2 = MPCF.ToDbl(spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.DIFF_SIEVE_2].Value);
                    dTi2 = Math.Round(dTi1 + ((dDiffValueRow2 / 0.4) * 100), 1, MidpointRounding.AwayFromZero);

                    spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.TI_VALUE_2].Value = dTi2;

                }

            }
            else if (e.Column == (int)COLLECTION_DATA_BI.TI_VALUE_1 || e.Column == (int)COLLECTION_DATA_BI.TI_VALUE_2)
            {
                dTiValue1 = MPCF.ToDbl(spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.TI_VALUE_1].Value);
                dTiValue2 = MPCF.ToDbl(spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.TI_VALUE_2].Value);

                dAvgValue = Math.Round((dTiValue1 + dTiValue2) / 2, 1, MidpointRounding.AwayFromZero);

                //평균
                spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.AVG_SIEVE].Value = dAvgValue;
            }
            else if (e.Column == (int)COLLECTION_DATA_BI.AVG_SIEVE)
            {
                ////TI 환산식 계산
                dAvgValue = MPCF.ToDbl(spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.AVG_SIEVE].Value);

                spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.TI_CHANGE].Value = Math.Round(CalculationTI(dAvgValue, txtMatID.Text, txtMatVer.Text), 1, MidpointRounding.AwayFromZero);

            }
        }

        private double CalculationTI(double p_d_avg, string p_s_mat_id, string p_s_mat_ver)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            StringBuilder sb;

            double d_TI = p_d_avg;

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            sb = new StringBuilder();

            string d_avg = p_d_avg.ToString();
            string s_mat_id = p_s_mat_id;
            string s_mat_ver = p_s_mat_ver.ToString();

            // 2020.11.08 수정
            // F_GRIT_CALC_TI_CHANGE -> F_GRIT_CALC_TI_CHANGE2 로 변경
            // C_INSP_TI_CHANGE GCM 테이블에서 공식 작성시, AVG , A, B, C 만 써야 함. 오라클 함수 안에서 해당 문자열만 REPLACE 하고 있음
            sb.Append("SELECT F_GRIT_CALC_TI_CHANGE2('" + MPGV.gsFactory + "'," + d_avg + ", '" + s_mat_id + "'," + s_mat_ver + ") FROM DUAL ");


            in_node.AddString("SQL", sb.ToString());

            if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
            {
                return p_d_avg;
            }


            if (out_node.GetList("ROWS").Count > 0)
            {
                if (out_node.GetList("ROWS")[0].GetList("COLS").Count > 0)
                {
                    d_TI = MPCF.ToDbl(out_node.GetList("ROWS")[0].GetList("COLS")[0].GetString("DATA"));
                }
            }

            return d_TI;

        }

        private void defModelBTI_Changed(object sender, FarPoint.Win.Spread.Model.SheetDataModelEventArgs e)
        {
            if (!b_allow_changed)
                return;


            double dNotSieve;
            double dExistSieve;
            double dDiffValue;
            double dDiffValueRow2;

            double dTi1;
            double dTi2;

            double dTiValue1;
            double dTiValue2;

            double dAvgValue;

            int iRow = e.Row;

            //빈체
            if (e.Column == (int)COLLECTION_DATA_BTI.NOT_SIEVE_1 || e.Column == (int)COLLECTION_DATA_BTI.EXIST_SIEVE_1)
            {
                //#1 변경시 
                dNotSieve = MPCF.ToDbl(spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.NOT_SIEVE_1].Value);
                dExistSieve = MPCF.ToDbl(spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.EXIST_SIEVE_1].Value);

                if (dExistSieve > dNotSieve)
                    dDiffValue = dExistSieve - dNotSieve;
                else
                    dDiffValue = 0;

                //차(g)
                //spdDataCollectionBI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BI.DIFF_SIEVE_1].Value = dDiffValue;

                spdDataCollectionBTI.ActiveSheet.SetValue(iRow, (int)COLLECTION_DATA_BTI.DIFF_SIEVE_1, dDiffValue);


            }
            else if (e.Column == (int)COLLECTION_DATA_BTI.NOT_SIEVE_2 || e.Column == (int)COLLECTION_DATA_BTI.EXIST_SIEVE_2)
            {
                //#2 변경시 
                dNotSieve = MPCF.ToDbl(spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.NOT_SIEVE_2].Value);
                dExistSieve = MPCF.ToDbl(spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.EXIST_SIEVE_2].Value);

                if (dExistSieve > dNotSieve)
                    dDiffValue = dExistSieve - dNotSieve;
                else
                    dDiffValue = 0;

                //차(g)
                spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.DIFF_SIEVE_2].Value = dDiffValue;


            }
            else if (e.Column == (int)COLLECTION_DATA_BTI.DIFF_SIEVE_1)
            {
                if (iRow == 0)
                {
                    //#1 차이
                    dDiffValue = MPCF.ToDbl(spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.DIFF_SIEVE_1].Value);
                    dTi1 = Math.Round((dDiffValue / 0.4) * 100, 1, MidpointRounding.AwayFromZero);

                    // TI  계산
                    spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.TI_VALUE_1].Value = dTi1;


                    //#2 TI 계산
                    dDiffValueRow2 = MPCF.ToDbl(spdDataCollectionBTI.ActiveSheet.Cells[iRow + 1, (int)COLLECTION_DATA_BTI.DIFF_SIEVE_1].Value);
                    dTi2 = Math.Round(dTi1 + ((dDiffValueRow2 / 0.4) * 100), 1, MidpointRounding.AwayFromZero);

                    spdDataCollectionBTI.ActiveSheet.Cells[iRow + 1, (int)COLLECTION_DATA_BTI.TI_VALUE_1].Value = dTi2;

                }
                else if (iRow == 1)
                {
                    //#1 TI
                    dTi1 = MPCF.ToDbl(spdDataCollectionBTI.ActiveSheet.Cells[iRow - 1, (int)COLLECTION_DATA_BTI.TI_VALUE_1].Value);

                    //#2 차이
                    dDiffValueRow2 = MPCF.ToDbl(spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.DIFF_SIEVE_1].Value);
                    dTi2 = Math.Round(dTi1 + ((dDiffValueRow2 / 0.4) * 100), 1, MidpointRounding.AwayFromZero);

                    spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.TI_VALUE_1].Value = dTi2;

                }
            }
            else if (e.Column == (int)COLLECTION_DATA_BTI.DIFF_SIEVE_2)
            {
                if (iRow == 0)
                {
                    //#1 차이
                    dDiffValue = MPCF.ToDbl(spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.DIFF_SIEVE_2].Value);
                    dTi1 = Math.Round((dDiffValue / 0.4) * 100, 1, MidpointRounding.AwayFromZero);

                    // TI  계산
                    spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.TI_VALUE_2].Value = dTi1;


                    //#2 TI 계산
                    dDiffValueRow2 = MPCF.ToDbl(spdDataCollectionBTI.ActiveSheet.Cells[iRow + 1, (int)COLLECTION_DATA_BTI.DIFF_SIEVE_2].Value);
                    dTi2 = Math.Round(dTi1 + ((dDiffValueRow2 / 0.4) * 100), 1, MidpointRounding.AwayFromZero);

                    spdDataCollectionBTI.ActiveSheet.Cells[iRow + 1, (int)COLLECTION_DATA_BTI.TI_VALUE_2].Value = dTi2;

                }
                else if (iRow == 1)
                {
                    //#1 TI
                    dTi1 = MPCF.ToDbl(spdDataCollectionBTI.ActiveSheet.Cells[iRow - 1, (int)COLLECTION_DATA_BTI.TI_VALUE_2].Value);

                    //#2 차이
                    dDiffValueRow2 = MPCF.ToDbl(spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.DIFF_SIEVE_2].Value);
                    dTi2 = Math.Round(dTi1 + ((dDiffValueRow2 / 0.4) * 100), 1, MidpointRounding.AwayFromZero);

                    spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.TI_VALUE_2].Value = dTi2;

                }

            }
            else if (e.Column == (int)COLLECTION_DATA_BTI.TI_VALUE_1 || e.Column == (int)COLLECTION_DATA_BTI.TI_VALUE_2)
            {
                dTiValue1 = MPCF.ToDbl(spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.TI_VALUE_1].Value);
                dTiValue2 = MPCF.ToDbl(spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.TI_VALUE_2].Value);

                dAvgValue = Math.Round((dTiValue1 + dTiValue2) / 2, 1, MidpointRounding.AwayFromZero);

                //평균
                spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.AVG_SIEVE].Value = dAvgValue;
            }
            else if (e.Column == (int)COLLECTION_DATA_BTI.AVG_SIEVE)
            {
                ////TI 환산식 계산
                ////TI 환산식 계산
                dAvgValue = MPCF.ToDbl(spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.AVG_SIEVE].Value);

                CalculationTI(dAvgValue, txtMatID.Text, txtMatVer.Text);

                spdDataCollectionBTI.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_BTI.TI_CHANGE].Value = Math.Round(CalculationTI(dAvgValue, txtMatID.Text, txtMatVer.Text), 1, MidpointRounding.AwayFromZero);
            }
        }

        private void defModelHLT_Changed(object sender, FarPoint.Win.Spread.Model.SheetDataModelEventArgs e)
        {
            if (!b_allow_changed)
                return;

            int iRow = e.Row;

            double dNotSieve;
            double dExistSieve;

            double dDiffValue; // 차

            double dDiffValueRowSeq1;
            double dDiffValueRowSeq2;

            double dWTSample;
            double dValue;

            double dValue1;
            double dValue2;

            double dAvg;

            double dFactor;

            double dNextDefaultTime;
            double dNormalSecond;



            //빈체1, 찬체1 변경시
            if (e.Column == (int)COLLECTION_DATA_HLT.NOT_SIEVE_1 || e.Column == (int)COLLECTION_DATA_HLT.EXIST_SIEVE_1)
            {
                dNotSieve = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.NOT_SIEVE_1].Value);
                dExistSieve = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.EXIST_SIEVE_1].Value);

                if (dExistSieve > dNotSieve)
                    dDiffValue = dExistSieve - dNotSieve;
                else
                    dDiffValue = 0;

                spdDataCollectionHLT.ActiveSheet.SetValue(iRow, (int)COLLECTION_DATA_HLT.DIFF_SIEVE_1, dDiffValue);

            }
            else if (e.Column == (int)COLLECTION_DATA_HLT.NOT_SIEVE_2 || e.Column == (int)COLLECTION_DATA_HLT.EXIST_SIEVE_2)
            {

                dNotSieve = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.NOT_SIEVE_2].Value);
                dExistSieve = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.EXIST_SIEVE_2].Value);

                if (dExistSieve > dNotSieve)
                    dDiffValue = dExistSieve - dNotSieve;
                else
                    dDiffValue = 0;

                //차(g)
                spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.DIFF_SIEVE_2].Value = dDiffValue;

            }
            else if (e.Column == (int)COLLECTION_DATA_HLT.DIFF_SIEVE_1)
            {

                // 4 Row 고정

                //1, 2 줄 변경시
                if (iRow == 0 || iRow == 1)
                {
                    //1줄, 2줄 고정
                    dDiffValueRowSeq1 = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[0, (int)COLLECTION_DATA_HLT.DIFF_SIEVE_1].Value);
                    dDiffValueRowSeq2 = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[1, (int)COLLECTION_DATA_HLT.DIFF_SIEVE_1].Value);

                    //txtHLTSize1
                    //값 찾기
                    DataRow[] arrRows = null;
                    arrRows = dtSTSampleWT.Select("SIZE_CODE = '" + txtHLTSize1.Text + "' ");
                    dWTSample = MPCF.ToDbl(arrRows[0]["SAMPLE_WT"]);

                    if (dWTSample == 0)
                    {
                        MPCF.ShowMsgBox("값을 구하기위한 기준정보가 등록되어 있지 않습니다. ( GCM : C_INSP_GRIT_SIZE)");
                        return;
                    }
                    dValue = Math.Round(((dDiffValueRowSeq1 + dDiffValueRowSeq2) / dWTSample) * 100, 1, MidpointRounding.AwayFromZero);

                    //index 0,1 고정
                    spdDataCollectionHLT.ActiveSheet.Cells[0, (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_1].Value = dValue;
                    spdDataCollectionHLT.ActiveSheet.Cells[1, (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_1].Value = dValue;


                }// 3,4 번째 줄
                else if (iRow == 2 || iRow == 3)
                {
                    //3줄, 4줄 고정
                    dDiffValueRowSeq1 = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[2, (int)COLLECTION_DATA_HLT.DIFF_SIEVE_1].Value);
                    dDiffValueRowSeq2 = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[3, (int)COLLECTION_DATA_HLT.DIFF_SIEVE_1].Value);

                    //txtHLTSize1
                    //값 찾기
                    DataRow[] arrRow = null;
                    arrRow = dtSTSampleWT.Select("SIZE_CODE = '" + txtHLTSize1.Text + "' ");
                    dWTSample = MPCF.ToDbl(arrRow[0]["SAMPLE_WT"]);

                    if (dWTSample == 0)
                    {
                        MPCF.ShowMsgBox("값을 구하기위한 기준정보가 등록되어 있지 않습니다. ( GCM : C_INSP_GRIT_SIZE)");
                        return;
                    }
                    dValue = Math.Round(((dDiffValueRowSeq1 + dDiffValueRowSeq2) / dWTSample) * 100, 1, MidpointRounding.AwayFromZero);

                    //index 2,3 고정
                    spdDataCollectionHLT.ActiveSheet.Cells[2, (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_1].Value = dValue;
                    spdDataCollectionHLT.ActiveSheet.Cells[3, (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_1].Value = dValue;

                }
            }
            else if (e.Column == (int)COLLECTION_DATA_HLT.DIFF_SIEVE_2)
            {

                // 4 Row 고정

                //1, 2 줄 변경시
                if (iRow == 0 || iRow == 1)
                {
                    //1줄, 2줄 고정
                    dDiffValueRowSeq1 = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[0, (int)COLLECTION_DATA_HLT.DIFF_SIEVE_2].Value);
                    dDiffValueRowSeq2 = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[1, (int)COLLECTION_DATA_HLT.DIFF_SIEVE_2].Value);

                    //txtHLTSize1
                    //값 찾기
                    DataRow[] arrRows = null;
                    arrRows = dtSTSampleWT.Select("SIZE_CODE = '" + txtHLTSize2.Text + "' ");
                    dWTSample = MPCF.ToDbl(arrRows[0]["SAMPLE_WT"]);

                    if (dWTSample == 0)
                    {
                        MPCF.ShowMsgBox("값을 구하기위한 기준정보가 등록되어 있지 않습니다. ( GCM : C_INSP_GRIT_SIZE)");
                        return;
                    }
                    dValue = Math.Round(((dDiffValueRowSeq1 + dDiffValueRowSeq2) / dWTSample) * 100, 1, MidpointRounding.AwayFromZero);

                    //index 0,1 고정
                    spdDataCollectionHLT.ActiveSheet.Cells[0, (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_2].Value = dValue;
                    spdDataCollectionHLT.ActiveSheet.Cells[1, (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_2].Value = dValue;


                }// 3,4 번째 줄
                else if (iRow == 2 || iRow == 3)
                {
                    //3줄, 4줄 고정
                    dDiffValueRowSeq1 = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[2, (int)COLLECTION_DATA_HLT.DIFF_SIEVE_2].Value);
                    dDiffValueRowSeq2 = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[3, (int)COLLECTION_DATA_HLT.DIFF_SIEVE_2].Value);

                    //txtHLTSize1
                    //값 찾기
                    DataRow[] arrRow = null;
                    arrRow = dtSTSampleWT.Select("SIZE_CODE = '" + txtHLTSize2.Text + "' ");
                    dWTSample = MPCF.ToDbl(arrRow[0]["SAMPLE_WT"]);

                    if (dWTSample == 0)
                    {
                        MPCF.ShowMsgBox("값을 구하기위한 기준정보가 등록되어 있지 않습니다. ( GCM : C_INSP_GRIT_SIZE)");
                        return;
                    }
                    dValue = Math.Round(((dDiffValueRowSeq1 + dDiffValueRowSeq2) / dWTSample) * 100, 1, MidpointRounding.AwayFromZero);

                    //index 2,3 고정
                    spdDataCollectionHLT.ActiveSheet.Cells[2, (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_2].Value = dValue;
                    spdDataCollectionHLT.ActiveSheet.Cells[3, (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_2].Value = dValue;

                }
            }
            else if (e.Column == (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_1)
            {
                dValue1 = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[0, (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_1].Value);
                dValue2 = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[2, (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_1].Value);

                dAvg = Math.Round(((dValue1 + dValue2) / 2) , 1, MidpointRounding.AwayFromZero);

                spdDataCollectionHLT.ActiveSheet.Cells[0, (int)COLLECTION_DATA_HLT.AVG_SIEVE_1].Value = dAvg;
                spdDataCollectionHLT.ActiveSheet.Cells[1, (int)COLLECTION_DATA_HLT.AVG_SIEVE_1].Value = dAvg;
                spdDataCollectionHLT.ActiveSheet.Cells[2, (int)COLLECTION_DATA_HLT.AVG_SIEVE_1].Value = dAvg;
                spdDataCollectionHLT.ActiveSheet.Cells[3, (int)COLLECTION_DATA_HLT.AVG_SIEVE_1].Value = dAvg;

            }
            else if (e.Column == (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_2)
            {
                dValue1 = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[0, (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_2].Value);
                dValue2 = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[2, (int)COLLECTION_DATA_HLT.TOTAL_SIEVE_2].Value);

                dAvg = Math.Round(((dValue1 + dValue2) / 2) , 1, MidpointRounding.AwayFromZero);

                spdDataCollectionHLT.ActiveSheet.Cells[0, (int)COLLECTION_DATA_HLT.AVG_SIEVE_2].Value = dAvg;
                spdDataCollectionHLT.ActiveSheet.Cells[1, (int)COLLECTION_DATA_HLT.AVG_SIEVE_2].Value = dAvg;
                spdDataCollectionHLT.ActiveSheet.Cells[2, (int)COLLECTION_DATA_HLT.AVG_SIEVE_2].Value = dAvg;
                spdDataCollectionHLT.ActiveSheet.Cells[3, (int)COLLECTION_DATA_HLT.AVG_SIEVE_2].Value = dAvg;

            }
            else if (e.Column == (int)COLLECTION_DATA_HLT.AVG_SIEVE_1)
            {
                
                //Factor 가져오기
                dAvg = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.AVG_SIEVE_1].Value);

                DataRow[] arrRow = null;

                arrRow = dtSTFactor.Select(string.Format("FROM_AVG <= {0} AND TO_AVG >= {1}", dAvg, dAvg));

                if (arrRow.Length == 0)
                {
                    if (iRow == 0)
                    {
                        MPCF.ShowMsgBox("FACTOR 정보가 존재하지 않습니다.");
                    }

                    spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.F_VALUE_1].Value = 0;
                }
                else
                {
                    dFactor = MPCF.ToDbl(arrRow[0]["FACTOR"]);

                    spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.F_VALUE_1].Value = dFactor;

                }
                

            }
            else if (e.Column == (int)COLLECTION_DATA_HLT.AVG_SIEVE_2)
            {
                //Factor 가져오기
                dAvg = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.AVG_SIEVE_2].Value);



                DataRow[] arrRow = null;
                //arrRow = dtSTFactor.Select("FROM_AVG < " + sAvg + " AND TO_AVG >= " + sAvg);
                arrRow = dtSTFactor.Select(string.Format("FROM_AVG <= {0} AND TO_AVG >= {1}", dAvg, dAvg));
                if (arrRow.Length == 0)
                {
                    if (iRow == 0)
                    {
                        MPCF.ShowMsgBox("FACTOR 정보가 존재하지 않습니다.");
                    }
                    spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.F_VALUE_1].Value = 0;
                    return;
                }
                dFactor = MPCF.ToDbl(arrRow[0]["FACTOR"]);

                spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.F_VALUE_2].Value = dFactor;

            }
            else if (e.Column == (int)COLLECTION_DATA_HLT.F_VALUE_1)
            {
                if (iRow == 0)
                {
                    //Factor 변경시 다음차수의 Default Time과 , Normal Second를 이용하여 TI 값을 구한다.
                    dFactor = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.F_VALUE_1].Value);  // Factor 
                    dNextDefaultTime = MPCF.ToDbl(txtHLTMeshTime1.Text) * dFactor;

                    //값 찾기
                    DataRow[] arrRow = null;
                    arrRow = dtSTSampleWT.Select("SIZE_CODE = '" + txtHLTSize1.Text + "' ");
                    dNormalSecond = MPCF.ToDbl(arrRow[0]["NORMAL_SECOND"]);

                    txtHLTTiValue1.Text = Math.Round((dNextDefaultTime / dNormalSecond) * 100, 2, MidpointRounding.AwayFromZero).ToString();
                }

            }
            else if (e.Column == (int)COLLECTION_DATA_HLT.F_VALUE_2)
            {
                if (iRow == 0)
                {
                    //Factor 변경시 다음차수의 Default Time과 , Normal Second를 이용하여 TI 값을 구한다.
                    dFactor = MPCF.ToDbl(spdDataCollectionHLT.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_HLT.F_VALUE_2].Value);  // Factor 
                    dNextDefaultTime = MPCF.ToDbl(txtHLTMeshTime2.Text) * dFactor;

                    //값 찾기
                    DataRow[] arrRow = null;
                    arrRow = dtSTSampleWT.Select("SIZE_CODE = '" + txtHLTSize2.Text + "' ");
                    dNormalSecond = MPCF.ToDbl(arrRow[0]["NORMAL_SECOND"]);

                    txtHLTTiValue2.Text = Math.Round((dNextDefaultTime / dNormalSecond) * 100, 2, MidpointRounding.AwayFromZero).ToString();
                }
            }
        }

        
        

        private void txtMAValue1_KeyPress(object sender, KeyPressEventArgs e)
        {
            /* if (!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar) && (e.KeyChar != '.'))
             {
                 e.Handled = true;
             }
             if ((e.KeyChar == '.') && ((sender as TextBox).Text.IndexOf('.') > -1))
             {
                 e.Handled = true;
             }
             */

            TypingOnlyNumber(sender, e, true, true);


        }

        public static void TypingOnlyNumber(object sender, KeyPressEventArgs e, bool includePoint, bool includeMinus)
        {
            
            bool isValidInput = false;
            if (!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar))
            {
                if (includePoint == true) { if (e.KeyChar == '.') isValidInput = true; }
                if (includeMinus == true) { if (e.KeyChar == '-') isValidInput = true; }

                if (isValidInput == false) e.Handled = true;
            }

            if (includePoint == true)
            {
                if (e.KeyChar == '.' && (string.IsNullOrEmpty((sender as TextBox).Text.Trim()) || (sender as TextBox).Text.IndexOf('.') > -1)) e.Handled = true;
            }
            if (includeMinus == true)
            {
                if (e.KeyChar == '-' && (!string.IsNullOrEmpty((sender as TextBox).Text.Trim()) || (sender as TextBox).Text.IndexOf('-') > -1)) e.Handled = true;
            }
        }

        private void txtWTValue1_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtWTValue2_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtBDValue1_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtTDValue1_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtPCSValue1_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtPSValue1_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtPSValue2_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtCML_KeyPress(object sender, KeyPressEventArgs e)
        {
            
            TypingOnlyNumber(sender, e, true, true);
            
        }

        private void txtCMA_KeyPress(object sender, KeyPressEventArgs e)
        {
            
           // TypingOnlyNumber(sender, e, true, true);
        }

        private void txtCMB_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtGrainSize_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtEllipticity_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtRoughness_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtCirculrarity_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtConvexity_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtShapeFactor_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtSurfaceB_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtConOValue_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtMAValue1_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }


            txtMAResult.Text = Convert.ToString(Math.Round(MPCF.ToDbl(txtMACalValue.Text) * MPCF.ToDbl(txtMAValue1.Text), 0, MidpointRounding.AwayFromZero));
        }

        private void txtWTValue1_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }

            txtWTValue3.Text = (MPCF.ToDbl(txtWTValue1.Text) - MPCF.ToDbl(txtWTValue2.Text)).ToString();

            txtWTValue1Same.Text = txtWTValue1.Text;

            if (MPCF.ToDbl(txtWTValue1Same.Text) == 0)
            {
                txtWTResult.Text = "0";
            }
            else
            {
                txtWTResult.Text = Convert.ToString(Math.Round((MPCF.ToDbl(txtWTValue3.Text) / MPCF.ToDbl(txtWTValue1Same.Text)) * MPCF.ToDbl(txtWTCalValue.Text), 2, MidpointRounding.AwayFromZero));
            }
            
        }

        private void txtWTValue2_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }

            txtWTValue3.Text = (MPCF.ToDbl(txtWTValue1.Text) - MPCF.ToDbl(txtWTValue2.Text)).ToString();

            if (MPCF.ToDbl(txtWTValue1Same.Text) == 0)
            {
                txtWTResult.Text = "0";
            }
            else
            {
                txtWTResult.Text = Convert.ToString(Math.Round((MPCF.ToDbl(txtWTValue3.Text) / MPCF.ToDbl(txtWTValue1Same.Text)) * MPCF.ToDbl(txtWTCalValue.Text), 2, MidpointRounding.AwayFromZero));
            }
            
        }

        private void txtBDValue1_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }

            txtBDResult.Text = Convert.ToString(Math.Round(MPCF.ToDbl(txtBDValue1.Text) / MPCF.ToDbl(txtBDCalValue.Text), 2, MidpointRounding.AwayFromZero));
        }

        private void txtTDValue1_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }

            if (MPCF.ToDbl(txtTDValue1.Text) == 0)
            {
                txtTDResult.Text = "0";
            }
            else
            {
                txtTDResult.Text = Convert.ToString(Math.Round(MPCF.ToDbl(txtTDCalValue.Text) / MPCF.ToDbl(txtTDValue1.Text), 2, MidpointRounding.AwayFromZero));
            }
            
        }

        private void txtPCSValue1_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }

            if (MPCF.ToDbl(txtPCSValue1.Text) == 0)
            {
                txtPCSResult.Text = "0";
            }
            else
            {
                txtPCSResult.Text = Convert.ToString(Math.Round(MPCF.ToDbl(txtPCSCalValue.Text) / MPCF.ToDbl(txtPCSValue1.Text), 2, MidpointRounding.AwayFromZero));
            }
            
        }

        private void txtPSValue1_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }

            if (MPCF.ToDbl(txtPSValue2.Text) == 0)
            {
                txtPSResult.Text = "0";
            }
            else
            {
                txtPSResult.Text = Convert.ToString(Math.Round(MPCF.ToDbl(txtPSValue1.Text) / MPCF.ToDbl(txtPSValue2.Text), 2, MidpointRounding.AwayFromZero));
            }
           
        }

        private void txtPSValue2_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }

            if (MPCF.ToDbl(txtPSValue2.Text) == 0)
            {
                txtPSResult.Text = "0";
            }
            else
            {
                txtPSResult.Text = Convert.ToString(Math.Round(MPCF.ToDbl(txtPSValue1.Text) / MPCF.ToDbl(txtPSValue2.Text), 2, MidpointRounding.AwayFromZero));
            }
            
        }

        private void txtMAResult_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void txtWTValue3_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void txtWTValue1Same_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void txtBDResult_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void txtTDResult_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void txtPCSResult_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void txtCML_Validated(object sender, EventArgs e)
        {
            
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
            
        }

        private void txtCMA_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void txtCMB_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void txtGrainSize_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void txtEllipticity_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void txtRoughness_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void txtCirculrarity_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void txtConvexity_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void txtShapeFactor_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void txtSurfaceB_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void txtConOValue_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void cdvInspBICount_ButtonPress(object sender, EventArgs e)
        {
            cdvInspBICount.Init();
            MPCF.InitListView(cdvInspBICount.GetListView);
            cdvInspBICount.Columns.Add("Count", 50, HorizontalAlignment.Left);
            cdvInspBICount.SelectedSubItemIndex = 0;
            cdvInspBICount.DisplaySubItemIndex = 0;


            if (BASLIST.ViewGCMDataList(cdvInspBICount.GetListView, '1', CSGC.CP_GCM_INSP_COUNT, -1, null, "", true, -1, -1, null, null) == false)
            {
                return;
            }
        }

        private void cdvInspBICount_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            if (txtInspID.Text != "")
                ViewInspectionGritBI(txtInspID.Text);
        }

        private void cdvInspBTICount_ButtonPress(object sender, EventArgs e)
        {
            cdvInspBTICount.Init();
            MPCF.InitListView(cdvInspBTICount.GetListView);
            cdvInspBTICount.Columns.Add("Count", 50, HorizontalAlignment.Left);
            cdvInspBTICount.SelectedSubItemIndex = 0;
            cdvInspBTICount.DisplaySubItemIndex = 0;


            if (BASLIST.ViewGCMDataList(cdvInspBTICount.GetListView, '1', CSGC.CP_GCM_INSP_COUNT, -1, null, "", true, -1, -1, null, null) == false)
            {
                return;
            }
        }

        private void cdvInspBTICount_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            if (txtInspID.Text != "")
                ViewInspectionGritBTI(txtInspID.Text);
        }

        private void txtBICount1_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtBICount2_KeyPress(object sender, KeyPressEventArgs e)
        {
            TypingOnlyNumber(sender, e, true, true);
        }

        private void txtBICount1_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
            }
        }

        private void txtBICount2_Validated(object sender, EventArgs e)
        {
            if (((TextBox)sender).Text == "")
            {
                ((TextBox)sender).Text = "0";
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

        private bool Update_Inspection_Status(char procstep)
        {

            TRSNode in_node = new TRSNode("UPDATE_INSPECTION_STATUS_IN");
            TRSNode out_node = new TRSNode("UPDATE_INSPECTION_STATUS_OUT");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = procstep;

                in_node.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));   //검사 ID

                //step : 1  접수
                //step : 2  보류

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

        private void panel8_Paint(object sender, PaintEventArgs e)
        {

        }

        private void cdvInspHLTCount_ButtonPress(object sender, EventArgs e)
        {
            cdvInspHLTCount.Init();
            MPCF.InitListView(cdvInspHLTCount.GetListView);
            cdvInspHLTCount.Columns.Add("Count", 50, HorizontalAlignment.Left);
            cdvInspHLTCount.SelectedSubItemIndex = 0;
            cdvInspHLTCount.DisplaySubItemIndex = 0;


            if (BASLIST.ViewGCMDataList(cdvInspHLTCount.GetListView, '1', CSGC.CP_GCM_INSP_COUNT, -1, null, "", true, -1, -1, null, null) == false)
            {
                return;
            }
        }

        private void txtHLTTiValue1_TextChanged(object sender, EventArgs e)
        {
            //txtHLTResult
            if (txtHLTTiValue1.Text == "")
                return;

            if (MPCF.ToDbl(txtHLTTiValue2.Text) == 0 || txtHLTTiValue2.Text == "")
            {
                txtHLTResult.Text = txtHLTTiValue1.Text;
            }
            else
            {
                txtHLTResult.Text = Math.Round(((MPCF.ToDbl(txtHLTTiValue1.Text) + MPCF.ToDbl(txtHLTTiValue2.Text)) / 2) , 0, MidpointRounding.AwayFromZero).ToString();
            }

        }

        private void txtHLTTiValue2_TextChanged(object sender, EventArgs e)
        {
            if (txtHLTTiValue2.Text == "")
                return;


            if (MPCF.ToDbl(txtHLTTiValue2.Text) == 0 || txtHLTTiValue2.Text == "")
            {
                txtHLTResult.Text = txtHLTTiValue1.Text;
            }
            else
            {
                txtHLTResult.Text = Math.Round(((MPCF.ToDbl(txtHLTTiValue1.Text) + MPCF.ToDbl(txtHLTTiValue2.Text)) / 2) , 0, MidpointRounding.AwayFromZero).ToString();
            }
        }

        private void cdvInspHLTCount_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            if (txtInspID.Text != "")
                ViewInspectionGritHTL(txtInspID.Text);
        }

        private void btnCalcAspectRatio_Click(object sender, EventArgs e)
        {
            if (spdDataCollectionAspect.ActiveSheet.RowCount == 0)
                return;

            /*
            ASPECT RATIO 의
            MEAN(VAL_1) = ROUND(1 / (ELLIPTICITY의 MEAN값),3)  VAL_1
            D10(VAL_2) = ROUND(1 / (ELLIPTICITY의 D90값),3)  VAL_6
            D25(VAL_3) = ROUND(1 / (ELLIPTICITY의 D75값),3)  VAL_5
            D50(VAL_4) = ROUND(1 / (ELLIPTICITY의 D50값),3)  VAL_4
            D75(VAL_5) = ROUND(1 / (ELLIPTICITY의 D25값),3)  VAL_3
            D90(VAL_6) = ROUND(1 / (ELLIPTICITY의 D10값),3)  VAL_2
            */

            double dInput;
            
            dInput = MPCF.ToDbl(spdDataCollectionAspect.ActiveSheet.Cells[3, (int)COLLECTION_DATA_ASPECT.VAL_1].Value); //MEAN 값
            if(dInput != 0)
                spdDataCollectionAspect.ActiveSheet.Cells[0, (int)COLLECTION_DATA_ASPECT.VAL_1].Value = Math.Round((1 / dInput), 3, MidpointRounding.AwayFromZero);


            dInput = MPCF.ToDbl(spdDataCollectionAspect.ActiveSheet.Cells[3, (int)COLLECTION_DATA_ASPECT.VAL_6].Value); //MEAN 값
            if(dInput != 0)
                spdDataCollectionAspect.ActiveSheet.Cells[0, (int)COLLECTION_DATA_ASPECT.VAL_2].Value = Math.Round((1 / dInput), 3, MidpointRounding.AwayFromZero);


            dInput = MPCF.ToDbl(spdDataCollectionAspect.ActiveSheet.Cells[3, (int)COLLECTION_DATA_ASPECT.VAL_5].Value); //MEAN 값
            if (dInput != 0)
                spdDataCollectionAspect.ActiveSheet.Cells[0, (int)COLLECTION_DATA_ASPECT.VAL_3].Value = Math.Round((1 / dInput), 3, MidpointRounding.AwayFromZero);


            dInput = MPCF.ToDbl(spdDataCollectionAspect.ActiveSheet.Cells[3, (int)COLLECTION_DATA_ASPECT.VAL_4].Value); //MEAN 값
            if (dInput != 0)
                spdDataCollectionAspect.ActiveSheet.Cells[0, (int)COLLECTION_DATA_ASPECT.VAL_4].Value = Math.Round((1 / dInput), 3, MidpointRounding.AwayFromZero);

            dInput = MPCF.ToDbl(spdDataCollectionAspect.ActiveSheet.Cells[3, (int)COLLECTION_DATA_ASPECT.VAL_3].Value); //MEAN 값
            if (dInput != 0)
                spdDataCollectionAspect.ActiveSheet.Cells[0, (int)COLLECTION_DATA_ASPECT.VAL_5].Value = Math.Round((1 / dInput), 3, MidpointRounding.AwayFromZero);

            dInput = MPCF.ToDbl(spdDataCollectionAspect.ActiveSheet.Cells[3, (int)COLLECTION_DATA_ASPECT.VAL_2].Value); //MEAN 값
            if (dInput != 0)
                spdDataCollectionAspect.ActiveSheet.Cells[0, (int)COLLECTION_DATA_ASPECT.VAL_6].Value = Math.Round((1 / dInput), 3, MidpointRounding.AwayFromZero);



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

        private void btnPop_Click(object sender, EventArgs e)
        {
            try
            {

                frmPopInspectionLotList popup = new frmPopInspectionLotList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                //popup.sSub_area_id = cdvWorkPlace.Text;
                //popup.sSub_area_desc = cdvWorkPlace.DisplayText;
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

        private void spdFileRegistration_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            fnFileSelectionChagned();
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
            else if (e.Column == (int)FILEUPLOAD.DELETE)
            {
                if (spdFileRegistration.ActiveSheet.ActiveRowIndex < 0)
                    return;

                if (txtInspID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(478));
                    txtLotID.Focus();
                    return;
                }

                int iActiveRow = spdFileRegistration.ActiveSheet.ActiveRowIndex;


                string sFileNo = MPCF.Trim(spdFileRegistration.ActiveSheet.Cells[iActiveRow, (int)FILEUPLOAD.FILE_NO].Value.ToString());
                string sImageCode = MPCF.Trim(spdFileRegistration.ActiveSheet.Cells[iActiveRow, (int)FILEUPLOAD.TITLE].Value.ToString());

                if (MPCF.Trim(sFileNo) == "")
                {
                    return;
                }

                //파일테이블에 실제 파일 삭제가 아닌,  참조정보 공백으로 업데이트 ( INSP_ID, CMF_1 )
                fnDeleteFile(sFileNo);

                //파일 리스트 조회
                ViewInspectionFile(txtInspID.Text);

                spdFileRegistration.ActiveSheet.ActiveRowIndex = iActiveRow;
                fnFileSelectionChagned();

            }

        }

        private void fnDeleteFile(string FileNo)
        {
            //DB 저장
            TRSNode in_node = new TRSNode("Update_File_In");
            TRSNode out_node = new TRSNode("Update_File_Out");

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '3';

            in_node.AddString("FILE_NO", FileNo);



            if (MPCR.CallService("CUS_QCM", "CUS_QCM_File_Attach", in_node, ref out_node) == false)
            {
                return;
            }

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

        private void chkJudgeMaintain_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void txtCML_TextChanged(object sender, EventArgs e)
        {
          
        }

        private void spdLossInfo_CellClick(object sender, CellClickEventArgs e)
        {

        }

        private void btnSpec_Click(object sender, EventArgs e)
        {
            SpecPopUp();

        }
        private void txtLastSpecTime_Click(object sender, EventArgs e)
        {
            SpecPopUp();
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

        private void btnGCM2_Click(object sender, EventArgs e)
        {
            try
            {

                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = "C_INSP_TI_CHANGE";

                popup.sTable_name_desc = "TI 환산 계산식";
                popup.sComment = "A,B,C 항목의 입력된 기준으로 계산을 진행합니다.";




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
    }

}
