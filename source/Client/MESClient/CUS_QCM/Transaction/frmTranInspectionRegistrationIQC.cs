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
using FarPoint.Win.Spread.Model;
using System.IO;


namespace CUS_QCM
{
    public partial class frmTranInspectionRegistrationIQC : CUS_COM.frmTranForm06
    {
        public frmTranInspectionRegistrationIQC()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Variable Definition "
        private const int DEFAULT_COL_COUNT = 16;
        private clsDerivedCharList cls_derived_char_list;

        private const int MAX_DATA_COUNT = 5000;

        DefaultSheetDataModel defModelData;

        bool b_allow_changed;

        #endregion

        #region " Constant Definition "
        private enum LOT_INFO
        {
            LOT_ID,                 // 1 : LOT ID
            MAT_ID,                 // 2 : 제품코드
            MAT_DESC,               // 3 : 제품명         
            CREATE_DATE,            // 4 : 생성일자   
            INSP_QTY,                       // 5 : 요청 수량
            UNIT_1                     // 단위

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
            DEF_UNIT_OVR_FLAG_COL,
            DEF_VALUE_COL,
            UNIT_TBL_COL,
            VALUE_TBL_COL,
            UNIT_SEQ_COL,
            UNIT_COL,
            VALUE_START_COL
        }

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


        private enum COLLECTION_DATA_ISP
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

                cdvInspectionType.Text = "IQC";
                cdvInspectionType.DisplayText = "IQC";

                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnJudge.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnReceive.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnHold.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSpec.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnGCM.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnColSetId.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblLastSpec.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                txtLastSpecTime.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                btnFileManager.Anchor = AnchorStyles.Top | AnchorStyles.Right;

                this.AllowDrop = true;

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

                    MPCF.FieldClear(pnlStsCond, txtLotID);
                    MPCF.ClearList(spdLotList);
                    MPCF.FieldClear(panJudgeResult);
                    MPCF.FieldClear(panFileRegistration);
                    MPCF.ClearList(spdFileRegistration);
                    MPCF.ClearList(spdLossInfo);

                    //  MPCF.FieldClear(pm.cdvColSetID);
                    MPCF.ClearList(spdDataCollection);

                    break;

                case "COL_SET_CHANGED":

                    MPCF.ClearList(spdDataCollection);
                    txtColSetVer.Text = "";
                    spdDataCollection.ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;

                    break;
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



                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                MPCF.ClearList(spdLotList);

                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", sLot_ID); //Lot ID (WIP LotID 혹은 DLV LotID )

                //in_node.AddString("AREA_ID", cdvDept.Text);
                //in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("INSP_TYPE", cdvInspectionType.Text);


                if (MPCR.CallService("CUS_QCM", "CUS_QCM_View_Lot_Info", in_node, ref out_node) == false)
                {
                    return;
                }

                spdLotList.ActiveSheet.RowCount++;
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.LOT_ID, out_node.GetString("LOT_ID"));
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.MAT_ID, out_node.GetString("MAT_ID"));
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.MAT_DESC, out_node.GetString("MAT_DESC"));
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
                cdvWorkPlace.Text = out_node.GetString("SUB_AREA_ID");
                cdvWorkPlace.DisplayText = out_node.GetString("SUB_AREA_DESC");

                txtVendorLotID.Text = out_node.GetString("VENDOR_LOT_ID");

                txtInspectionStatus.Text = out_node.GetChar("INSP_STATUS").ToString();
                txtInspectionStatusDesc.Text = out_node.GetString("INSP_STATUS_DESC").ToString();
                cdvInspectionJudgeFlag.Text = out_node.GetChar("INSP_JUDGE_FLAG").ToString();
                cdvInspectionJudgeFlag.DisplayText = out_node.GetString("INSP_JUDGE_DESC");
                //cdvReworkOper.Text = out_node.GetString("RWK_OPER");
                txtComment.Text = out_node.GetString("INSP_COMMENT");

                cdvColSetID.Text = out_node.GetString("COL_SET_ID");
                cdvColSetID.DisplayText = out_node.GetString("COL_SET_DESC");

                GetJudgeFlagByArea(cdvInspectionJudgeFlag.GetListView, cdvInspOper.Text, cdvInspectionType.Text);
                cdvInspectionJudgeFlag.InsertEmptyRow(0, 1);

                //파일 리스트 조회
                ViewInspectionFile(txtInspID.Text);

                //Loss 정보 조회
                ViewInspectionLossInfo(txtInspID.Text, cdvInspOper.Text);

                //검사자 대상 조회;
                ViewWorkerList();

                //불러온 ColSetID로 조회
                SelectedItemChangedByColSet();

                if (cdvDept.Text == CSGC.CP_AREA_GRT || cdvDept.Text == CSGC.CP_AREA_CTM)
                {
                    ViewInspectionGritISP(txtInspID.Text);
                }


                ViewSpecLastEditTime(txtMatID.Text, cdvInspOper.Text);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
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

                cls_derived_char_list = new clsDerivedCharList();
                cls_derived_char_list.GetDerivedInfo(sColSetID, Convert.ToInt32(txtColSetVer.Text), sLotID, "", "", "");

                if (ViewCharacterList(spdDataCollection, '5', sColSetID, Convert.ToInt32(txtColSetVer.Text), 'Y', cls_derived_char_list, sLotID, sMatID, iMatVer, sOper) == false)
                {
                    return;
                }

                if (ViewInspData() == false)
                {
                    CSCF.ClearSpread(spdDataCollection, 0, (int)COLLECTION_DATA.VALUE_START_COL, "");
                }

            }
            catch
            {

            }
        }
        private bool ViewInspData()
        {

            b_allow_changed = false;
            int iValueCnt = 0;
            int iRow = 0;
            string s_value_name;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_ID";
                dvcArgu[1].sCondition_Value = txtInspID.Text;



                if (TPDR.GetDataOne("", ref dt, "CQCM2001-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    for (int j = 0; j < spdDataCollection.ActiveSheet.RowCount; j++)
                    {
                        if (spdDataCollection.ActiveSheet.Cells[j, (int)COLLECTION_DATA.CHAR_COL].Text == dt.Rows[i]["CHAR_ID"].ToString()
                            && spdDataCollection.ActiveSheet.Cells[j, (int)COLLECTION_DATA.UNIT_SEQ_COL].Text == dt.Rows[i]["UNIT_SEQ"].ToString())
                        {
                            iRow = j;
                            break;
                        }

                    }

                    // spdDataCollection.ActiveSheet.SetValue(iRow, (int)COLLECTION_DATA.UNIT_COL, dt.Rows[i]["UNIT_ID"].ToString());

                    // iUnitCnt = MPCF.ToInt(dt.Rows[0]["UNIT_COUNT"].ToString());
                    iValueCnt = MPCF.ToInt(dt.Rows[i]["VALUE_COUNT"].ToString());

                    if (iValueCnt > 25)
                    {
                        iValueCnt = 25;
                    }

                    for (int k = 1; k <= iValueCnt; k++)
                    {
                        s_value_name = "VALUE_" + k.ToString();
                        if (dt.Rows[i]["VALUE_TYPE"].ToString() == "N")
                        {
                            if (dt.Rows[i][s_value_name].ToString() != "")
                            {
                                spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_START_COL + (k - 1)].Value = dt.Rows[i][s_value_name].ToString();
                                //spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_START_COL + (k - 1)].Value = MPCF.ToDbl(dt.Rows[i][s_value_name].ToString());
                            }
                        }
                        else
                        {
                            spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_START_COL + (k - 1)].Value = dt.Rows[i][s_value_name].ToString();
                        }

                        /*
                        if (out_node.GetList(0)[i].GetChar("DERIVED_PARAM_FLAG") == 'Y')
                        {
                            spdEDCList.ActiveSheet.Cells[iRow, (int)CHAR_COLUMN.VALUE_START_COL + (k - 1)].Locked = true;
                            spdEDCList.ActiveSheet.Cells[iRow, (int)CHAR_COLUMN.VALUE_START_COL + (k - 1)].BackColor = System.Drawing.Color.Cyan;
                            spdEDCList.ActiveSheet.Rows[iRow].Tag = "AUTO";

                            cls_derived_char_list.SetCharLocation(out_node.GetList(0)[i].GetString("CHAR_ID"), spdEDCList.ActiveSheet, k - 1, iRow, (int)CHAR_COLUMN.VALUE_START_COL + (k - 1));
                        }*/
                    }


                }

                //Spec Out 확인
                ApplyColorBySpecOut();

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
                //in_node.AddString("LOT_ID", LotID);
                //in_node.AddString("LOT_ID", "");



                spdDataCollection.ActiveSheet.Columns.Get((int)COLLECTION_DATA.CHAR_COL).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection.ActiveSheet.Columns.Get((int)COLLECTION_DATA.CHAR_DESC_COL).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection.ActiveSheet.Columns.Get((int)COLLECTION_DATA.CHAR_SEQ).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection.ActiveSheet.Columns.Get((int)COLLECTION_DATA.LOWER_SPEC_LIMIT).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection.ActiveSheet.Columns.Get((int)COLLECTION_DATA.TARGET_VALUE).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection.ActiveSheet.Columns.Get((int)COLLECTION_DATA.UPPER_SPEC_LIMIT).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection.ActiveSheet.Columns.Get((int)COLLECTION_DATA.SPEC_COL).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;

                spdDataCollection.ActiveSheet.Columns.Get((int)COLLECTION_DATA.OPT_INPUT_COL).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection.ActiveSheet.Columns.Get((int)COLLECTION_DATA.VALUE_TYPE_COL).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection.ActiveSheet.Columns.Get((int)COLLECTION_DATA.VALUE_COUNT_COL).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection.ActiveSheet.Columns.Get((int)COLLECTION_DATA.DEF_UNIT_OVR_FLAG_COL).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection.ActiveSheet.Columns.Get((int)COLLECTION_DATA.DEF_VALUE_COL).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection.ActiveSheet.Columns.Get((int)COLLECTION_DATA.UNIT_TBL_COL).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                spdDataCollection.ActiveSheet.Columns.Get((int)COLLECTION_DATA.VALUE_TBL_COL).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;




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


                            /*
                            if (j != 0)
                            {
                                if (with_1.Cells[j, (int)COLLECTION_DATA.CHAR_COL].Value != with_1.Cells[j - 1, (int)COLLECTION_DATA.CHAR_COL].Value)
                                {
                                    if (with_1.Cells[j - 1, (int)COLLECTION_DATA.CHAR_COL, j - 1, (int)COLLECTION_DATA.UNIT_SEQ_COL].BackColor == System.Drawing.Color.Gray)
                                    {
                                        with_1.Cells[j, (int)COLLECTION_DATA.CHAR_COL, j, (int)COLLECTION_DATA.UNIT_SEQ_COL].BackColor = System.Drawing.Color.WhiteSmoke;
                                    }
                                    else
                                    {
                                        with_1.Cells[j, (int)COLLECTION_DATA.CHAR_COL, j, (int)COLLECTION_DATA.UNIT_SEQ_COL].BackColor = System.Drawing.Color.Gray;
                                    }
                                }
                                else
                                {
                                    with_1.Cells[j, (int)COLLECTION_DATA.CHAR_COL, j, (int)COLLECTION_DATA.UNIT_SEQ_COL].BackColor = with_1.Cells[j - 1, (int)COLLECTION_DATA.CHAR_COL, j - 1, (int)COLLECTION_DATA.UNIT_SEQ_COL].BackColor;
                                }
                            }
                            */

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
        private bool fnDrawCollectionCharacter(FpSpread _fpSpread, string _colSetID, string _lotID, string _inspID)
        {
            try
            {


                if (MPCF.Trim(_colSetID) == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + "\r\n Inspection Set");
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

                if (control is FpSpread)
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
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
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
                b_allow_changed = false;

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

                b_allow_changed = true;
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
                        if (MPCF.Trim(txtInspID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(478));
                            cdvDept.Focus();
                            return false;
                        }
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
                            if (MPCF.Trim(spdDataCollection.ActiveSheet.GetValue(i, (int)COLLECTION_DATA.CHAR_COL)) == "")
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                spdDataCollection.ActiveSheet.SetActiveCell(i, (int)COLLECTION_DATA.CHAR_COL);
                                spdDataCollection.Select();
                                return false;
                            }

                            // unit_id check
                            /*if (MPCF.Trim(spdDataCollection.ActiveSheet.GetValue(i, (int)COLLECTION_DATA.OPT_INPUT_COL)) != "Y")
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
                in_node.AddString("INSP_COMMENT", txtComment.Text);


                for (iRow = 0; iRow < spdLossInfo.ActiveSheet.RowCount; iRow++)
                {
                    if (MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[iRow, (int)LOSS_INFO.LOSS_QTY].Value) > 0)
                    {
                        loss_list = in_node.AddNode("LOSS_LIST");

                        loss_list.AddString("LOSS_CODE", spdLossInfo.ActiveSheet.Cells[iRow, (int)LOSS_INFO.LOSS_CODE].Value);  // LOSS_CODE
                        loss_list.AddDouble("LOSS_QTY", MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[iRow, (int)LOSS_INFO.LOSS_QTY].Value));

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

                //Loss 정보 조회
                ViewInspectionLossInfo(txtInspID.Text, cdvInspOper.Text);


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

            if (CheckCondition(CSGC.CHECK.SAVE) == false)
                return false;

            TRSNode in_node = new TRSNode("COLLECT_LOT_DATA_IN");
            TRSNode out_node = new TRSNode("COLLECT_LOT_DATA_OUT");
            TRSNode data_list;
            TRSNode loss_list;

            int iRow = 0;
            int iLossRow = 0;
            int i_value_start = (int)COLLECTION_DATA.VALUE_START_COL;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", MPCF.Trim(spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.LOT_ID].Value));
                in_node.AddString("MAT_ID", MPCF.Trim(txtMatID.Text));
                in_node.AddInt("MAT_VER", MPCF.ToInt(txtMatVer.Text));

                in_node.AddString("COL_SET_ID", MPCF.Trim(cdvColSetID.Text));
                in_node.AddInt("COL_SET_VERSION", MPCF.ToInt(txtColSetVer.Text));

                in_node.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));
                in_node.AddInt("INSP_SEQ", 1);

                if (cdvInspectionJudgeFlag.Text != "")
                {
                    in_node.AddChar("INSP_JUDGE_FLAG", MPCF.ToChar(cdvInspectionJudgeFlag.Text));
                }
                in_node.AddString("INSP_COMMENT", txtComment.Text);

                for (iRow = 0; iRow < spdDataCollection.ActiveSheet.RowCount; iRow++)
                {
                    data_list = in_node.AddNode("DATA_LIST");

                    data_list.AddString("CHAR_ID", spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.CHAR_COL].Value);
                    data_list.AddInt("CHAR_SEQ", spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.CHAR_SEQ].Value);
                    data_list.AddInt("UNIT_SEQ", spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.UNIT_SEQ_COL].Value);
                    data_list.AddInt("VALUE_SEQ", 1);
                    data_list.AddString("UNIT_ID", spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.UNIT_COL].Value);
                    data_list.AddChar("VALUE_TYPE", spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_TYPE_COL].Value);
                    data_list.AddInt("VALUE_COUNT", spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_COUNT_COL].Value);


                    for (int iCol = 1; iCol - 1 + i_value_start < spdDataCollection.ActiveSheet.ColumnCount; iCol++)
                    {
                        if (iCol > 26)
                            break;

                        data_list.AddString("VALUE_" + iCol.ToString(), spdDataCollection.ActiveSheet.Cells[iRow, iCol - 1 + i_value_start].Value);
                    }
                }

                for (iLossRow = 0; iLossRow < spdLossInfo.ActiveSheet.RowCount; iLossRow++)
                {
                    if (MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[iLossRow, (int)LOSS_INFO.LOSS_QTY].Value) > 0)
                    {
                        loss_list = in_node.AddNode("LOSS_LIST");

                        loss_list.AddString("LOSS_CODE", spdLossInfo.ActiveSheet.Cells[iLossRow, (int)LOSS_INFO.LOSS_CODE].Value);  // LOSS_CODE
                        loss_list.AddDouble("LOSS_QTY", MPCF.ToDbl(spdLossInfo.ActiveSheet.Cells[iLossRow, (int)LOSS_INFO.LOSS_QTY].Value));

                    }
                }


                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Collect_Inspection_Data", in_node, ref out_node, false) == false)
                {
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
        private bool Inspection_Judge()
        {
            //Vaildation check
            if (VaildationCheckJudge() == false)
            {
                return false;
            }

            TRSNode in_node = new TRSNode("INSPECTION_JUDGE_IN");
            TRSNode out_node = new TRSNode("INSPECTION_JUDGE_OUT");
            TRSNode loss_list;
            TRSNode worker_list;

            int iRow = 0;
            int iWrkRow = 0;

            string sLotID;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                //INSP_ID, LOT_ID, INSP_JUDGE_FLAG, REWORK_OPER, INSP_COMMENT
                sLotID = spdLotList.ActiveSheet.GetValue(0, (int)LOT_INFO.LOT_ID).ToString();

                in_node.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));   //검사 ID
                in_node.AddString("COL_SET_ID", MPCF.Trim(cdvColSetID.Text)); //COL SET ID
                in_node.AddInt("COL_SET_VERSION", MPCF.ToInt(txtColSetVer.Text));
                in_node.AddString("LOT_ID", sLotID);  // LOT_ID
                in_node.AddChar("INSP_JUDGE_FLAG", MPCF.Trim(cdvInspectionJudgeFlag.Text));  // 검사요청 ID
                                                                                             // in_node.AddString("REWORK_OPER", MPCF.Trim(cdvReworkOper.Text));                   //재가공 공정
                in_node.AddString("INSP_COMMENT", MPCF.Trim(txtComment.Text));                        //주석


                // Loss 정보
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
        private bool Update_Inspection_Status(char procstep)
        {

            TRSNode in_node = new TRSNode("UPDATE_INSPECTION_STATUS_IN");
            TRSNode out_node = new TRSNode("UPDATE_INSPECTION_STATUS_OUT");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = procstep;

                in_node.AddString("INSP_ID", MPCF.Trim(txtInspID.Text));   //검사 ID

                //Step : 1  접수
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
        private bool FillCollectionData(TRSNode in_node)
        {
            int i;
            int j;
            int i_value_count;

            TRSNode char_item, unit_item, value_item;


            try
            {
                char_item = in_node.AddNode("CHAR_LIST");
                for (i = 0; i < spdDataCollection.ActiveSheet.RowCount; i++)
                {
                    if (MPCF.ToInt(spdDataCollection.ActiveSheet.GetValue(i, (int)COLLECTION_DATA.UNIT_SEQ_COL)) == 1)
                    {
                        if (i != 0)
                        {
                            char_item = in_node.AddNode("CHAR_LIST");
                        }
                        char_item.AddString("CHAR_ID", MPCF.Trim(spdDataCollection.ActiveSheet.GetValue(i, (int)COLLECTION_DATA.CHAR_COL)));
                    }
                    unit_item = char_item.AddNode("UNIT_LIST");
                    unit_item.AddString("UNIT_ID", MPCF.Trim(spdDataCollection.ActiveSheet.GetValue(i, (int)COLLECTION_DATA.UNIT_COL)));
                    unit_item.AddInt("UNIT_SEQ_NUM", MPCF.ToInt(spdDataCollection.ActiveSheet.GetValue(i, (int)COLLECTION_DATA.UNIT_SEQ_COL)));

                    i_value_count = MPCF.ToInt(spdDataCollection.ActiveSheet.GetValue(i, (int)COLLECTION_DATA.VALUE_COUNT_COL));
                    for (j = 0; j < i_value_count; j++)
                    {
                        value_item = unit_item.AddNode("VALUE_LIST");

                        if (MPCF.Trim(spdDataCollection.ActiveSheet.GetValue(i, (int)COLLECTION_DATA.VALUE_TYPE_COL)) == "N" &&
                            MPCF.CheckNumeric(spdDataCollection.ActiveSheet.GetValue(i, j + (int)COLLECTION_DATA.VALUE_START_COL)) == true)
                        {
                            value_item.AddString("VALUE", MPCF.ToDbl(spdDataCollection.ActiveSheet.GetValue(i, j + (int)COLLECTION_DATA.VALUE_START_COL)).ToString());
                        }
                        else
                        {
                            value_item.AddString("VALUE", MPCF.Trim(spdDataCollection.ActiveSheet.GetValue(i, j + (int)COLLECTION_DATA.VALUE_START_COL)));
                        }
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
        private void CancelNetDrice(string strTarget)
        {
            try
            {
                NetConnection.WNetCancelConnection2A(strTarget, 1, 0);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        private void Attach_View()
        {

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
                                                + "          AND OPER_GRP_2 = 'IQC' "
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
            //   string sMatId = "";

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
                    return false;
                }

                if (dt.Rows[0]["COL_SET_ID"].ToString() == "X")
                {

                    //CMN563 INFO - 등록된  CollectionSet이 없습니다. 등록 진행하시겠습니까?
                    if (MPCF.ShowMsgBox(MPCF.GetMessage(563), MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.Yes)
                    {

                        frmPopCollectionSetOper popup = new frmPopCollectionSetOper();
                        //    popup.StartPosition = frmPopCollectionSetOper.CenterParent;

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


                    bResult = false;

                }
                else
                {
                    bResult = true;
                }




                return bResult;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
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
        private bool Collect_Data_ISP()
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

                in_node.AddString("INSP_DTL_TYPE", "ICP");

                for (iRow = 0; iRow < spdDataCollectionISP.ActiveSheet.RowCount; iRow++)
                {
                    data_list = in_node.AddNode("DATA_LIST");

                    data_list.AddInt("INSP_SEQ", spdDataCollectionISP.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ISP.INSP_SEQ].Value);
                    data_list.AddString("QC_NAME", spdDataCollectionISP.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ISP.QC_NAME].Value);
                    data_list.AddString("SPEC_VAL", spdDataCollectionISP.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ISP.SPEC_VAL].Value);
                    data_list.AddDouble("VAL_1", spdDataCollectionISP.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ISP.VAL_1].Value);  //외부
                    data_list.AddDouble("VAL_2", spdDataCollectionISP.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ISP.VAL_2].Value);  //내부
                    data_list.AddDouble("VAL_3", spdDataCollectionISP.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ISP.VAL_3].Value);
                    data_list.AddDouble("VAL_4", spdDataCollectionISP.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ISP.VAL_4].Value);
                    data_list.AddDouble("VAL_5", spdDataCollectionISP.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ISP.VAL_5].Value);
                    data_list.AddDouble("VAL_6", spdDataCollectionISP.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA_ISP.VAL_6].Value);
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
        private void ViewInspectionGritISP(string inspID)
        {
            try
            {
                b_allow_changed = false;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_ID";
                dvcArgu[1].sCondition_Value = inspID;



                // 검사 첨부파일 리스트 조회
                if (TPDR.GetDataOne("", ref dt, "CQCM2004-011", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdDataCollectionISP);
                    return;
                }

                MPCF.ClearList(spdDataCollectionISP);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdDataCollectionISP.ActiveSheet.RowCount++;

                    spdDataCollectionISP.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ISP.INSP_SEQ].Value = dt.Rows[i]["INSP_SEQ"];
                    spdDataCollectionISP.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ISP.QC_NAME].Value = dt.Rows[i]["QC_NAME"];
                    spdDataCollectionISP.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ISP.SPEC_VAL].Value = dt.Rows[i]["SPEC_VAL"];
                    spdDataCollectionISP.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ISP.VAL_1].Value = dt.Rows[i]["VAL_1"];
                    spdDataCollectionISP.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ISP.VAL_2].Value = dt.Rows[i]["VAL_2"];
                    spdDataCollectionISP.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ISP.VAL_3].Value = dt.Rows[i]["VAL_3"];
                    spdDataCollectionISP.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ISP.VAL_4].Value = dt.Rows[i]["VAL_4"];
                    spdDataCollectionISP.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ISP.VAL_5].Value = dt.Rows[i]["VAL_5"];
                    spdDataCollectionISP.ActiveSheet.Cells[i, (int)COLLECTION_DATA_ISP.VAL_6].Value = dt.Rows[i]["VAL_6"];

                }

                b_allow_changed = true;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private bool SendMessage(string sUserGroup, string sUsserId)
        {
            TRSNode node = new TRSNode("Publish_Message_In");
            string sPublishChannel;

            try
            {
                MPCR.SetInMsg(node);
                node.ProcStep = '1';
                node.AddString("SEND_COMPUTER_ID", MPGV.gsComputerName);
                node.AddString("SEND_USER_ID", MPGV.gsUserID, true);
                node.AddString("SEND_USER_GROUP", MPGV.gsUserGroup);

                node.AddString("TO_FACTORY", MPCF.Trim(MPGV.gsFactory));
                node.AddString("TO_USER_GROUP", MPCF.Trim(sUserGroup));
                node.AddString("TO_USER_ID", MPCF.Trim(sUsserId), true);
                node.AddString("MESSAGE", "LOT ID : " + txtLotID.Text + " / ITEM : " + txtMatDesc.Text + " / QC Result:" + cdvInspectionJudgeFlag.DisplayText + " / 검사완료 입고가능합니다.(Inspection Complete,Store Inv Please)");

                sPublishChannel = "/" + MPGV.gsSiteID;
                sPublishChannel += "/UTL";



                sPublishChannel += "/" + MPCF.Trim(MPGV.gsFactory);
                sPublishChannel += "/" + MPCF.Trim(sUserGroup);
                sPublishChannel += "/" + MPCF.Trim(sUsserId);

                if (MPCR.CallService("UTL", "UTL_Publish_Message", node, sPublishChannel) == false)
                {
                    return false;
                }
            }
            catch (Exception)
            {
                return false;
            }

            return true;

        }
        private bool messageUserCheck()
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            StringBuilder sb;


            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            sb = new StringBuilder();

            sb.Append("SELECT B.SEC_GRP_ID, A.KEY_1 FROM MGCMTBLDAT A LEFT JOIN MSECUSRDEF B ON A.FACTORY = B.FACTORY AND A.KEY_1 = B.USER_ID WHERE TABLE_NAME ='C_INSP_IQC_MESSAGE' ");


            in_node.AddString("SQL", sb.ToString());

            if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
            {
                return false;
            }

            for (int iRow = 0; iRow < out_node.GetList("ROWS").Count; iRow++)
            {
                // out_node.GetList("ROWS")[0].GetList("COLS")[0].GetString("DATA")
                if (SendMessage(out_node.GetList("ROWS")[iRow].GetList("COLS")[0].GetString("DATA"), out_node.GetList("ROWS")[iRow].GetList("COLS")[1].GetString("DATA")) == false)
                {
                    //return false;
                }

            }

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

        #endregion

        #region " Event Definition "
        private void cdvInspectionType_ButtonPress(object sender, EventArgs e)
        {
            /*cdvInspectionType.Init();
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
                if (e.KeyChar == (char)13)
                {
                    if (MPCF.Trim(txtLotID.Text) == "")
                        return;

                    txtLotID.Text = MPCF.Trim(txtLotID.Text).ToUpper();

                    if (CheckCondition(CSGC.CHECK.VIEW) == false)
                        return;

                    ViewLotInfo(txtLotID.Text);
                    // ClearList("LOT_INFO");
                    txtLotID.Text = "";


                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvColSetID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                string sOper = "";
                string sMatID = "";
                int sMatVer = 0;


                if (txtInspID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(478));
                    txtLotID.Focus();
                    return;
                }

                sOper = cdvInspOper.Text;
                sMatID = txtMatID.Text;
                sMatVer = Convert.ToInt32(txtMatVer.Text);
                //sOper = spdLotList.ActiveSheet.Cells[0,(int)LOT_INFO.MAT_ID]

                //Initialize ListView
                cdvColSetID.Init();
                MPCF.InitListView(cdvColSetID.GetListView);
                cdvColSetID.Columns.Add("Collection Set", 50, HorizontalAlignment.Left);
                cdvColSetID.Columns.Add("Description", 100, HorizontalAlignment.Left);
                cdvColSetID.SelectedSubItemIndex = 0;
                // cdvColSetID.SelectedDescIndex = 1;


                if (EDCLIST.ViewMFOColSetList(cdvColSetID.GetListView, '2', null, "", '0', sMatID, sMatVer, null, sOper, 'M', ' ', 'N', -1, -1) == false)
                {
                    return;
                }

                cdvColSetID.InsertEmptyRow(0, 1);
                /* if (EDCLIST.ViewEDCColSetList(cdvColSetID.GetListView, '1', null, "", -1, -1, ' ', false) == false)
                 {
                     return;
                 }*/

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvColSetID_TextBoxTextChanged(object sender, EventArgs e)
        {

        }
        private void cdvColSetID_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            SelectedItemChangedByColSet();
        }
        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {

                if (cdvDept.Text == CSGC.CP_AREA_GRT || cdvDept.Text == CSGC.CP_AREA_CTM)
                {

                    if (Collect_Data_ISP() == false)
                    {
                        return;
                    }

                }


                if (Collect_Inspection_Data() == false)
                {
                    return;
                }




                //재조회
                SelectedItemChangedByColSet();

                if (cdvDept.Text == CSGC.CP_AREA_GRT || cdvDept.Text == CSGC.CP_AREA_CTM)
                {
                    ViewInspectionGritISP(txtInspID.Text);
                }

                /*
                if (tabControl1.SelectedTab.Name == "tpgInspCommon") // 공통화면 저장 
                {
                    if (MPCF.Trim(txtInspID.Text) == "")
                    {
                        //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(478));
                        cdvDept.Focus();
                        return;
                    }

                    // 검사판정 정보, Loss 정보 저장
                    if (Collect_Inspection_Common_Data() == false)
                    {
                        return;
                    }


                }
                else if (tabControl1.SelectedTab.Name == "tpgInspData")
                {
                 
                }
                */

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
                //txtComment.Enabled = true;
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
                spdLossInfo.ActiveSheet.OperationMode = OperationMode.Normal;
                spdDataCollection.ActiveSheet.OperationMode = OperationMode.Normal;
                //spdFileRegistration.ActiveSheet.OperationMode = OperationMode.Normal;

            }
            else if (txtInspectionStatus.Text == "Q" || txtInspectionStatus.Text == "C" || txtInspectionStatus.Text == "S")
            {
                if (txtInspectionStatus.Text == "Q")
                {
                    btnReceive.Enabled = true;
                    btnProcess.Enabled = false;
                    spdDataCollection.ActiveSheet.OperationMode = OperationMode.ReadOnly;
                }
                else
                {
                    btnReceive.Enabled = false;
                    btnProcess.Enabled = true;
                    spdDataCollection.ActiveSheet.OperationMode = OperationMode.Normal;
                }
                cdvInspectionJudgeFlag.Enabled = false;
                //cdvReworkOper.Enabled = false;
                //txtComment.Enabled = false;
                btnJudge.Enabled = false;
                //btnProcess.Enabled = false;
                btnHold.Enabled = false;

                spdLossInfo.ActiveSheet.OperationMode = OperationMode.ReadOnly;
                cdvColSetID.Enabled = false;
                //spdDataCollection.ActiveSheet.OperationMode = OperationMode.ReadOnly;
                //spdFileRegistration.ActiveSheet.OperationMode = OperationMode.ReadOnly;
            }
        }
        private void cdvInspectionJudgeFlag_ButtonPress(object sender, EventArgs e)
        {
            /*
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


                //데이터 재저장
                if (Collect_Inspection_Data() == false)
                {
                    return;
                }

                if (Inspection_Judge() == false)
                {
                    return;
                }


                //20231005 수입검사 완료되면 구매팀 담당자에게 메세지 가도록 수정.
                if (cdvOper.Text.Substring(2, 3).ToString() == "IQC")
                {
                    if (cdvInspectionJudgeFlag.Text == "P" || cdvInspectionJudgeFlag.Text == "S")
                    {
                        if (messageUserCheck() == false)
                        {
                            // return;
                        }
                    }
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
            /*
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
            */




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
        private void spdDataCollection_EditModeOff(object sender, EventArgs e)
        {

        }
        private void frmTranInspectionRegistrationIQC_Load(object sender, EventArgs e)
        {
            cdvWorkGroup.Text = "A";
            //FarPoint.Win.Spread.InputMap inputmap;
            //inputmap = spdDataCollection.GetInputMap(FarPoint.Win.Spread.InputMapMode.WhenAncestorOfFocused);
            //inputmap.Put(new FarPoint.Win.Spread.Keystroke(Keys.Enter, Keys.None), FarPoint.Win.Spread.SpreadActions.MoveToNextColumn);

            defModelData = new DefaultSheetDataModel(0, spdDataCollection.ActiveSheet.Columns.Count);
            spdDataCollection.ActiveSheet.Models.Data = defModelData;
            this.defModelData.Changed += new SheetDataModelEventHandler(this.defModelData_Changed);




            switch (cdvDept.Text)
            {
                case "CTM":
                case "CTV":

                    cdvOper.Text = "C-IQC";
                    cdvOper.DisplayText = "수입검사(Import Inspection)";

                    break;

                case "PDC":
                case "PDV":
                    cdvOper.Text = "P-IQC";
                    cdvOper.DisplayText = "수입검사(Import Inspection)";
                    break;
                case "GRT":

                    cdvOper.Text = "G-IQC";
                    cdvOper.DisplayText = "수입검사(Import Inspection)";
                    break;
                case "HM":
                    cdvOper.Text = "H-IQC";
                    cdvOper.DisplayText = "수입검사(Import Inspection)";

                    break;
            }

        }
        private void defModelData_Changed(object sender, FarPoint.Win.Spread.Model.SheetDataModelEventArgs e)
        {
            if (!b_allow_changed)
                return;

            if (spdDataCollection.ActiveSheet.RowCount < 1)
            {
                return;
            }

            try
            {

                int iRow;
                int iColumn;

                bool bSpecOut = false;

                iColumn = e.Column; // spdDataCollection.ActiveSheet.ActiveColumnIndex;
                iRow = e.Row; // spdDataCollection.ActiveSheet.ActiveRowIndex;

                if (spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.VALUE_TYPE_COL].Value.ToString() == "N")
                {
                    if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[iRow, iColumn].Value) == true)
                    {

                        if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.LOWER_SPEC_LIMIT].Value) == true)
                        {
                            if (MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, iColumn].Value) < MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.LOWER_SPEC_LIMIT].Value))
                            {
                                bSpecOut = true;
                            }
                        }

                        if (MPCF.CheckNumeric(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.UPPER_SPEC_LIMIT].Value) == true)
                        {
                            if (MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, iColumn].Value) > MPCF.ToDbl(spdDataCollection.ActiveSheet.Cells[iRow, (int)COLLECTION_DATA.UPPER_SPEC_LIMIT].Value))
                            {
                                bSpecOut = true;
                            }
                        }

                        if (bSpecOut)
                        {
                            spdDataCollection.ActiveSheet.Cells[iRow, iColumn].BackColor = Color.Red;

                        }
                        else
                        {
                            spdDataCollection.ActiveSheet.Cells[iRow, iColumn].BackColor = Color.White;
                        }


                    }
                    else
                    {
                        spdDataCollection.ActiveSheet.Cells[iRow, iColumn].BackColor = Color.White;
                    }
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
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
                //cdvOper.Text = "";

                switch (cdvDept.Text)
                {
                    case "CTM":
                    case "CTV":

                        cdvOper.Text = "C-IQC";
                        cdvOper.DisplayText = "수입검사(Import Inspection)";

                        break;

                    case "PDC":
                    case "PDV":
                        cdvOper.Text = "P-IQC";
                        cdvOper.DisplayText = "수입검사(Import Inspection)";
                        break;
                    case "GRT":

                        cdvOper.Text = "G-IQC";
                        cdvOper.DisplayText = "수입검사(Import Inspection)";
                        break;
                    case "HM":
                        cdvOper.Text = "H-IQC";
                        cdvOper.DisplayText = "수입검사(Import Inspection)";

                        break;
                }


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
                popup.sSub_area_id = cdvWorkPlace.Text;
                popup.sSub_area_desc = cdvWorkPlace.DisplayText;
                //20220901 품질측 요청으로 일단 수입검사는 디펄트값 원자재로 고정.



                switch (cdvDept.Text)
                {
                    case "CTM":
                    case "CTV":

                        popup.sOper_id = "C-IQC";
                        popup.sOper_desc = "수입검사(Import Inspection)";

                        break;

                    case "PDC":
                    case "PDV":
                        popup.sOper_id = "P-IQC";
                        popup.sOper_desc = "수입검사(Import Inspection)";
                        popup.sMatType = "RAW_MATERIAL";
                        popup.sMatType_desc = "원재료";
                        break;
                    case "GRT":

                        popup.sOper_id = "G-IQC";
                        popup.sOper_desc = "수입검사(Import Inspection)";
                        break;
                    case "HM":
                        popup.sOper_id = "H-IQC";
                        popup.sOper_desc = "수입검사(Import Inspection)";

                        break;
                }




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
        private void spdFileRegistration_ButtonClicked(object sender, EditorNotifyEventArgs e)
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


                openFileDialog1.Reset();
                openFileDialog1.Filter = "Images Files(*.jpg; *.jpeg; *.bmp; *.png)|*.jpg;*.jpeg;*.bmp;*.png";
                openFileDialog1.DefaultExt = "jpg";

                if (openFileDialog1.ShowDialog() == DialogResult.OK)
                {

                    fullPath = openFileDialog1.FileName;
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
        private void spdFileRegistration_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            fnFileSelectionChagned();
        }
        private void spdDataCollection_EditModeOff_1(object sender, EventArgs e)
        {
            int iActiveRow = spdDataCollection.ActiveSheet.ActiveRowIndex;
            int iActiveCol = spdDataCollection.ActiveSheet.ActiveColumnIndex;

            int iRowCount = spdDataCollection.ActiveSheet.RowCount;
            int iColCount = spdDataCollection.ActiveSheet.ColumnCount;

            try
            {
                //Enter시 오른쪽으로 포커스를 이동해준다. (마지막인경우 아래 행이 있으면 아래행의 Value_1 열로 )
                if (iActiveCol >= (int)COLLECTION_DATA.VALUE_START_COL)
                {

                    //마지막 컬럼 일때 또는 다음 열이 Lock상태일 떄
                    if (iActiveCol == iColCount - 1 || spdDataCollection.ActiveSheet.Cells[iActiveRow, iActiveCol + 1].Locked == true)
                    {
                        //아래행으로 이동

                        //현재가 마지막 행이 아닌 경우만
                        if (iActiveRow != iRowCount - 1)
                        {
                            spdDataCollection.ActiveSheet.SetActiveCell(iActiveRow + 1, (int)COLLECTION_DATA.VALUE_START_COL);
                        }
                    }
                    else
                    {
                        //오른쪽으로 한칸 이동
                        spdDataCollection.ActiveSheet.SetActiveCell(iActiveRow, iActiveCol + 1);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
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
        private void btnGCM_Click(object sender, EventArgs e)
        {

            try
            {

                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = "C_INSP_IQC_MES_FLAG";

                if (MPGV.gcLanguage == '2')
                {
                    popup.sTable_name_desc = "수입검사 필수 품목등록";
                    popup.sComment = "해당 리스트에 등록된 품목은 ERP PO정보 무관하게 수입검사 필수로 변경됩니다.(등록이후 P/O 부터 반영됩니다.)";

                }
                else
                {
                    popup.sTable_name_desc = "IQC Required Item Registration";
                    popup.sComment = "Items registered in the list will be changed to Import Inspection Required regardless of ERP PO information (after registration, P/O will be reflected)";

                }


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
        private void btnColSetId_Click(object sender, EventArgs e)
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



                frmPopCollectionSetOper popup = new frmPopCollectionSetOper();
                //    popup.StartPosition = frmPopCollectionSetOper.CenterParent;

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
        private void lblComment_Click(object sender, EventArgs e)
        {/*
            if (messageUserCheck() == false)
            {
                // return;
            }
            */
        }
        private void frmTranInspectionRegistrationIQC_DragDrop(object sender, DragEventArgs e)
        {
            // 드롭된 파일의 경로 배열을 가져옴
            string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);

            // 첫 번째 파일 경로 가져오기 (여러 파일을 드롭할 경우 첫 번째만 사용)
            if (files.Length > 0)
            {
                string imagePath = files[0];


                // MessageBox.Show("Image Path: " + imagePath);



                //파일등록 벨리데이션

                if (txtInspID.Text == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(478));
                    txtLotID.Focus();
                    return;
                }

                if (spdFileRegistration.ActiveSheet.ActiveRowIndex < 0)
                    return;



                FileInfo finfo;
                long lengthKByte;

                //Focused Row
                int iActiveRow = spdFileRegistration.ActiveSheet.ActiveRowIndex;


                string sFileNo = MPCF.Trim(spdFileRegistration.ActiveSheet.Cells[iActiveRow, (int)FILEUPLOAD.FILE_NO].Value.ToString());
                string sImageCode = MPCF.Trim(spdFileRegistration.ActiveSheet.Cells[iActiveRow, (int)FILEUPLOAD.TITLE].Value.ToString());



                //   imagePath = openFileDialog1.FileName;
                //pictureBox1.Image = Image.FromFile(openFileDialog1.FileName);

                finfo = new FileInfo(imagePath);



                lengthKByte = finfo.Length / 1024;
                if (lengthKByte >= 2048)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(504));
                    return;
                }

                fnRegistrationFile(finfo, sFileNo, sImageCode, txtInspID.Text);

                //파일 리스트 조회
                ViewInspectionFile(txtInspID.Text);

                spdFileRegistration.ActiveSheet.ActiveRowIndex = iActiveRow;
                fnFileSelectionChagned();
            }
        }
        private void frmTranInspectionRegistrationIQC_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Copy;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }
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

        #endregion
    }

}
