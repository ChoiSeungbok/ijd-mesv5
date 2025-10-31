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
using FarPoint.Win.Spread;
using System.IO;
using FarPoint.Excel.EntityClassLibrary.DrawingVML;
using FarPoint.Excel;

namespace CUS_QCM
{
    public partial class frmViewInspectionDataIcp : CUS_COM.frmViewForm01
    {
        public frmViewInspectionDataIcp()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "
        private enum LOT_INFO
        {
            CHK
            , INSP_ID
            , COL_SET_ID
            , INSP_REQ_TIME
            , INSP_JUDGE_TIME
            , INSP_STATUS
            , LOT_ID
            , DETAIL
            , IMG
            , GRADE
            , SIZES
            , QTY
            , INSP_JUDGE_DESC
            , INSP_OPER
            , INSP_OPER_DESC
            , MAT_ID
            , MAT_DESC
            , VAL_SEQ
            , NI_VAL
            , FE_VAL
            , CU_VAL
            , CR_VAL
            , TI_VAL
            , MN_VAL
            , CO_VAL
            , CA_VAL
            , MG_VAL
            , ZN_VAL
            , MO_VAL
            , PB_VAL
            , AL_VAL
            , SI_VAL
            , B_VAL
            , NA_VAL
            , TOTAL
            , NI_VAL_2
            , FE_VAL_2
            , CU_VAL_2
            , CR_VAL_2
            , TI_VAL_2
            , MN_VAL_2
            , CO_VAL_2
            , CA_VAL_2
            , MG_VAL_2
            , ZN_VAL_2
            , MO_VAL_2
            , PB_VAL_2
            , AL_VAL_2
            , SI_VAL_2
            , B_VAL_2
            , NA_VAL_2
            , TOTAL_2

        }

        //내가외 ICP SEQ를 4번부터 시작했었는지 모르겠음....-_-;; 일단 업질러진 물이니.. 그냥 함
        private enum ICP_SEQ
        {
            NULL_1,
            NULL_2,
            NULL_3,
            Ni,
            Fe,
            Cu,
            Cr,
            Ti,
            Mn,
            Co,
            Ca,
            Mg,
            Zn,
            Mo,
            Pb,
            Al,
            Si,
            B,
            Na
        }

        #endregion

        #region " Function Definition "
        private void frmViewInspectionDataIcp_Load(object sender, EventArgs e)
        {
            try
            {
                rdoJudge.Checked = true;

                this.dtpToJudgeDate.Value = DateTime.Now;
                // this.dtpFromJudgeDate.CustomFormat = " ";
                this.dtpFromJudgeDate.Value = dtpToJudgeDate.Value.AddDays(-10);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

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

        private void ViewInspectionDataList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[10];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                double dTotal = 0;
                double dTotal2 = 0;

                string strFromJudgeDate = "";
                string strToJudgeDate = "";
                string strFromInspReqTime = "";
                string strToInspReqTime = "";

                if (rdoJudge.Checked)
                {
                    strFromJudgeDate = string.IsNullOrEmpty(dtpFromJudgeDate.Text.Trim()) ? "19000101" : dtpFromJudgeDate.Text.Replace("-", "");
                    strToJudgeDate = dtpToJudgeDate.Text.Replace("-", "");

                    strFromInspReqTime = "19000101";
                    strToInspReqTime = "29990101";
                }
                else
                {
                    strFromJudgeDate = "";
                    strToJudgeDate = "29990101";

                    strFromInspReqTime = string.IsNullOrEmpty(dtpFromJudgeDate.Text.Trim()) ? "19000101" : dtpFromJudgeDate.Text.Replace("-", "");
                    strToInspReqTime = dtpToJudgeDate.Text.Replace("-", "");
                }


                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FROM_JUDGE_DATE";
                dvcArgu[1].sCondition_Value = strFromJudgeDate;

                dvcArgu[2].sCondition_ID = "TO_JUDGE_DATE";
                dvcArgu[2].sCondition_Value = strToJudgeDate;

                dvcArgu[3].sCondition_ID = "FROM_INSP_REQ_DATE";
                dvcArgu[3].sCondition_Value = strFromInspReqTime;

                dvcArgu[4].sCondition_ID = "TO_INSP_REQ_DATE";
                dvcArgu[4].sCondition_Value = strToInspReqTime;



                dvcArgu[5].sCondition_ID = "MAT_DESC";
                dvcArgu[5].sCondition_Value = "%" + txtMatDesc.Text + "%";

                dvcArgu[6].sCondition_ID = "LOT_ID";
                dvcArgu[6].sCondition_Value = txtLotID.Text + "%";

                dvcArgu[7].sCondition_ID = "INSP_STATUS";
                dvcArgu[7].sCondition_Value = cdvStatus.Text + "%";

                dvcArgu[8].sCondition_ID = "INSP_OPER";
                dvcArgu[8].sCondition_Value = cdvOper.Text + "%";

                dvcArgu[9].sCondition_ID = "INSP_TYPE";
                dvcArgu[9].sCondition_Value = cdvInspectionType.Text + "%";



                if (TPDR.GetDataOne("", ref dt, "CQCM3014-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInspectionData);
                    return;
                }

                MPCF.ClearList(spdInspectionData);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdInspectionData.ActiveSheet.RowCount++;

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value = false;
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_ID].Value = dt.Rows[i]["INSP_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.COL_SET_ID].Value = dt.Rows[i]["COL_SET_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_REQ_TIME].Value = dt.Rows[i]["INSP_REQ_TIME"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_JUDGE_TIME].Value = dt.Rows[i]["INSP_JUDGE_TIME"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_STATUS].Value = dt.Rows[i]["INSP_STATUS"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SIZES].Value = dt.Rows[i]["SIZES"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_JUDGE_DESC].Value = dt.Rows[i]["INSP_JUDGE_DESC"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_OPER].Value = dt.Rows[i]["INSP_OPER"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_OPER_DESC].Value = dt.Rows[i]["INSP_OPER_DESC"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.VAL_SEQ].Value = dt.Rows[i]["VAL_SEQ"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.NI_VAL].Value = dt.Rows[i]["NI_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.ZN_VAL].Value = dt.Rows[i]["ZN_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MO_VAL].Value = dt.Rows[i]["MO_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.PB_VAL].Value = dt.Rows[i]["PB_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.AL_VAL].Value = dt.Rows[i]["AL_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SI_VAL].Value = dt.Rows[i]["SI_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.B_VAL].Value = dt.Rows[i]["B_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.NA_VAL].Value = dt.Rows[i]["NA_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.FE_VAL].Value = dt.Rows[i]["FE_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CU_VAL].Value = dt.Rows[i]["CU_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CR_VAL].Value = dt.Rows[i]["CR_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.TI_VAL].Value = dt.Rows[i]["TI_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MN_VAL].Value = dt.Rows[i]["MN_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CO_VAL].Value = dt.Rows[i]["CO_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CA_VAL].Value = dt.Rows[i]["CA_VAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MG_VAL].Value = dt.Rows[i]["MG_VAL"];

                    dTotal = MPCF.ToDbl(dt.Rows[i]["NI_VAL"]) +
                                MPCF.ToDbl(dt.Rows[i]["ZN_VAL"]) +
                                MPCF.ToDbl(dt.Rows[i]["MO_VAL"]) +
                                MPCF.ToDbl(dt.Rows[i]["PB_VAL"]) +
                                MPCF.ToDbl(dt.Rows[i]["AL_VAL"]) +
                                MPCF.ToDbl(dt.Rows[i]["SI_VAL"]) +
                                MPCF.ToDbl(dt.Rows[i]["B_VAL"]) +
                                MPCF.ToDbl(dt.Rows[i]["NA_VAL"]) +
                                MPCF.ToDbl(dt.Rows[i]["FE_VAL"]) +
                                MPCF.ToDbl(dt.Rows[i]["CU_VAL"]) +
                                MPCF.ToDbl(dt.Rows[i]["CR_VAL"]) +
                                MPCF.ToDbl(dt.Rows[i]["TI_VAL"]) +
                                MPCF.ToDbl(dt.Rows[i]["MN_VAL"]) +
                                MPCF.ToDbl(dt.Rows[i]["CO_VAL"]) +
                                MPCF.ToDbl(dt.Rows[i]["CA_VAL"]) +
                                MPCF.ToDbl(dt.Rows[i]["MG_VAL"]);
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.TOTAL].Value = dTotal;

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.NI_VAL_2].Value = dt.Rows[i]["NI_VAL_2"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.ZN_VAL_2].Value = dt.Rows[i]["ZN_VAL_2"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MO_VAL_2].Value = dt.Rows[i]["MO_VAL_2"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.PB_VAL_2].Value = dt.Rows[i]["PB_VAL_2"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.AL_VAL_2].Value = dt.Rows[i]["AL_VAL_2"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SI_VAL_2].Value = dt.Rows[i]["SI_VAL_2"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.B_VAL_2].Value = dt.Rows[i]["B_VAL_2"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.NA_VAL_2].Value = dt.Rows[i]["NA_VAL_2"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.FE_VAL_2].Value = dt.Rows[i]["FE_VAL_2"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CU_VAL_2].Value = dt.Rows[i]["CU_VAL_2"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CR_VAL_2].Value = dt.Rows[i]["CR_VAL_2"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.TI_VAL_2].Value = dt.Rows[i]["TI_VAL_2"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MN_VAL_2].Value = dt.Rows[i]["MN_VAL_2"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CO_VAL_2].Value = dt.Rows[i]["CO_VAL_2"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CA_VAL_2].Value = dt.Rows[i]["CA_VAL_2"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MG_VAL_2].Value = dt.Rows[i]["MG_VAL_2"];


                    dTotal2 = MPCF.ToDbl(dt.Rows[i]["NI_VAL_2"]) +
                                MPCF.ToDbl(dt.Rows[i]["ZN_VAL_2"]) +
                                MPCF.ToDbl(dt.Rows[i]["MO_VAL_2"]) +
                                MPCF.ToDbl(dt.Rows[i]["PB_VAL_2"]) +
                                MPCF.ToDbl(dt.Rows[i]["AL_VAL_2"]) +
                                MPCF.ToDbl(dt.Rows[i]["SI_VAL_2"]) +
                                MPCF.ToDbl(dt.Rows[i]["B_VAL_2"]) +
                                MPCF.ToDbl(dt.Rows[i]["NA_VAL_2"]) +
                                MPCF.ToDbl(dt.Rows[i]["FE_VAL_2"]) +
                                MPCF.ToDbl(dt.Rows[i]["CU_VAL_2"]) +
                                MPCF.ToDbl(dt.Rows[i]["CR_VAL_2"]) +
                                MPCF.ToDbl(dt.Rows[i]["TI_VAL_2"]) +
                                MPCF.ToDbl(dt.Rows[i]["MN_VAL_2"]) +
                                MPCF.ToDbl(dt.Rows[i]["CO_VAL_2"]) +
                                MPCF.ToDbl(dt.Rows[i]["CA_VAL_2"]) +
                                MPCF.ToDbl(dt.Rows[i]["MG_VAL_2"]);
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.TOTAL_2].Value = dTotal2;



                    if (cdvOper.Text.Contains("IQC"))
                    {
                        this.spdInspectionData_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.NI_VAL).Value = "ICP(Out Side)";
                        this.spdInspectionData_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.NI_VAL_2).Value = "ICP(In Side)";

                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.NI_VAL_2).Visible = true;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.ZN_VAL_2).Visible = true;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.MO_VAL_2).Visible = true;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.PB_VAL_2).Visible = true;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.AL_VAL_2).Visible = true;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.SI_VAL_2).Visible = true;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.B_VAL_2).Visible = true;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.NA_VAL_2).Visible = true;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.FE_VAL_2).Visible = true;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.CU_VAL_2).Visible = true;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.CR_VAL_2).Visible = true;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.TI_VAL_2).Visible = true;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.MN_VAL_2).Visible = true;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.CO_VAL_2).Visible = true;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.CA_VAL_2).Visible = true;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.MG_VAL_2).Visible = true;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.TOTAL_2).Visible = true;

                    }
                    else
                    {
                        this.spdInspectionData_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.NI_VAL).Value = "ICP";
                        this.spdInspectionData_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.NI_VAL_2).Value = " ";

                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.NI_VAL_2).Visible = false;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.ZN_VAL_2).Visible = false;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.MO_VAL_2).Visible = false;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.PB_VAL_2).Visible = false;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.AL_VAL_2).Visible = false;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.SI_VAL_2).Visible = false;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.B_VAL_2).Visible = false;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.NA_VAL_2).Visible = false;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.FE_VAL_2).Visible = false;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.CU_VAL_2).Visible = false;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.CR_VAL_2).Visible = false;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.TI_VAL_2).Visible = false;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.MN_VAL_2).Visible = false;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.CO_VAL_2).Visible = false;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.CA_VAL_2).Visible = false;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.MG_VAL_2).Visible = false;
                        spdInspectionData_Sheet1.Columns.Get((int)LOT_INFO.TOTAL_2).Visible = false;
                    }

                }
                //MPCF.FitColumnHeader(spdInspectionData);

                return;

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

        private bool Collect_Data_ISP(int iRow)
        {

            TRSNode in_node = new TRSNode("COLLECTION_DATA_ASPECT_IN");
            TRSNode out_node = new TRSNode("COLLECTION_DATA_ASPECT_OUT");


            string sLotID;

            try
            {

                TRSNode data_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '6';


                sLotID = spdInspectionData.ActiveSheet.GetValue(iRow, (int)LOT_INFO.LOT_ID).ToString();



                in_node.AddString("INSP_ID", MPCF.Trim(spdInspectionData.ActiveSheet.GetValue(iRow, (int)LOT_INFO.INSP_ID).ToString()));   //검사 ID
                in_node.AddString("LOT_ID", sLotID);  // LOT_ID
                in_node.AddString("COL_SET_ID", MPCF.Trim(spdInspectionData.ActiveSheet.GetValue(iRow, (int)LOT_INFO.COL_SET_ID).ToString()));
                in_node.AddInt("COL_SET_VER", 1);
                in_node.AddString("INSP_DTL_TYPE", "ICP");



                data_list = in_node.AddNode("DATA_LIST");

                data_list = in_node.AddNode("DATA_LIST");
                data_list.AddInt("INSP_SEQ", (int)ICP_SEQ.Ni);
                data_list.AddString("QC_NAME", "Ni");
                data_list.AddString("SPEC_VAL", " ");
                data_list.AddDouble("VAL_1", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.NI_VAL].Value);
                data_list.AddDouble("VAL_2", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.NI_VAL_2].Value);

                data_list = in_node.AddNode("DATA_LIST");
                data_list.AddInt("INSP_SEQ", (int)ICP_SEQ.Fe);
                data_list.AddString("QC_NAME", "Fe");
                data_list.AddString("SPEC_VAL", " ");
                data_list.AddDouble("VAL_1", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.FE_VAL].Value);
                data_list.AddDouble("VAL_2", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.FE_VAL_2].Value);


                data_list = in_node.AddNode("DATA_LIST");
                data_list.AddInt("INSP_SEQ", (int)ICP_SEQ.Cu);
                data_list.AddString("QC_NAME", "Cu");
                data_list.AddString("SPEC_VAL", " ");
                data_list.AddDouble("VAL_1", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.CU_VAL].Value);
                data_list.AddDouble("VAL_2", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.CU_VAL_2].Value);



                data_list = in_node.AddNode("DATA_LIST");
                data_list.AddInt("INSP_SEQ", (int)ICP_SEQ.Cr);
                data_list.AddString("QC_NAME", "Cr");
                data_list.AddString("SPEC_VAL", " ");
                data_list.AddDouble("VAL_1", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.CR_VAL].Value);
                data_list.AddDouble("VAL_2", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.CR_VAL_2].Value);


                data_list = in_node.AddNode("DATA_LIST");
                data_list.AddInt("INSP_SEQ", (int)ICP_SEQ.Ti);
                data_list.AddString("QC_NAME", "Ti");
                data_list.AddString("SPEC_VAL", " ");
                data_list.AddDouble("VAL_1", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.TI_VAL].Value);
                data_list.AddDouble("VAL_2", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.TI_VAL_2].Value);

                data_list = in_node.AddNode("DATA_LIST");
                data_list.AddInt("INSP_SEQ", (int)ICP_SEQ.Mn);
                data_list.AddString("QC_NAME", "Mn");
                data_list.AddString("SPEC_VAL", " ");
                data_list.AddDouble("VAL_1", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.MN_VAL].Value);
                data_list.AddDouble("VAL_2", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.MN_VAL_2].Value);

                data_list = in_node.AddNode("DATA_LIST");
                data_list.AddInt("INSP_SEQ", (int)ICP_SEQ.Co);
                data_list.AddString("QC_NAME", "Co");
                data_list.AddString("SPEC_VAL", " ");
                data_list.AddDouble("VAL_1", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.CO_VAL].Value);
                data_list.AddDouble("VAL_2", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.CO_VAL_2].Value);

                data_list = in_node.AddNode("DATA_LIST");
                data_list.AddInt("INSP_SEQ", (int)ICP_SEQ.Ca);
                data_list.AddString("QC_NAME", "Ca");
                data_list.AddString("SPEC_VAL", " ");
                data_list.AddDouble("VAL_1", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.CA_VAL].Value);
                data_list.AddDouble("VAL_2", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.CA_VAL_2].Value);

                data_list = in_node.AddNode("DATA_LIST");
                data_list.AddInt("INSP_SEQ", (int)ICP_SEQ.Mg);
                data_list.AddString("QC_NAME", "Mg");
                data_list.AddString("SPEC_VAL", " ");
                data_list.AddDouble("VAL_1", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.MG_VAL].Value);
                data_list.AddDouble("VAL_2", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.MG_VAL_2].Value);

                data_list = in_node.AddNode("DATA_LIST");
                data_list.AddInt("INSP_SEQ", (int)ICP_SEQ.Zn);
                data_list.AddString("QC_NAME", "Zn");
                data_list.AddString("SPEC_VAL", " ");
                data_list.AddDouble("VAL_1", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.ZN_VAL].Value);
                data_list.AddDouble("VAL_2", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.ZN_VAL_2].Value);

                data_list = in_node.AddNode("DATA_LIST");
                data_list.AddInt("INSP_SEQ", (int)ICP_SEQ.Mo);
                data_list.AddString("QC_NAME", "Mo");
                data_list.AddString("SPEC_VAL", " ");
                data_list.AddDouble("VAL_1", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.MO_VAL].Value);
                data_list.AddDouble("VAL_2", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.MO_VAL_2].Value);


                data_list = in_node.AddNode("DATA_LIST");
                data_list.AddInt("INSP_SEQ", (int)ICP_SEQ.Pb);
                data_list.AddString("QC_NAME", "Pb");
                data_list.AddString("SPEC_VAL", " ");
                data_list.AddDouble("VAL_1", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.PB_VAL].Value);
                data_list.AddDouble("VAL_2", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.PB_VAL_2].Value);




                data_list = in_node.AddNode("DATA_LIST");
                data_list.AddInt("INSP_SEQ", (int)ICP_SEQ.Al);
                data_list.AddString("QC_NAME", "Al");
                data_list.AddString("SPEC_VAL", " ");
                data_list.AddDouble("VAL_1", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.AL_VAL].Value);
                data_list.AddDouble("VAL_2", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.AL_VAL_2].Value);

                data_list = in_node.AddNode("DATA_LIST");
                data_list.AddInt("INSP_SEQ", (int)ICP_SEQ.Si);
                data_list.AddString("QC_NAME", "Si");
                data_list.AddString("SPEC_VAL", " ");
                data_list.AddDouble("VAL_1", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.SI_VAL].Value);
                data_list.AddDouble("VAL_2", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.SI_VAL_2].Value);

                data_list = in_node.AddNode("DATA_LIST");
                data_list.AddInt("INSP_SEQ", (int)ICP_SEQ.B);
                data_list.AddString("QC_NAME", "B");
                data_list.AddString("SPEC_VAL", " ");
                data_list.AddDouble("VAL_1", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.B_VAL].Value);
                data_list.AddDouble("VAL_2", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.B_VAL_2].Value);

                data_list = in_node.AddNode("DATA_LIST");
                data_list.AddInt("INSP_SEQ", (int)ICP_SEQ.Na);
                data_list.AddString("QC_NAME", "Na");
                data_list.AddString("SPEC_VAL", " ");
                data_list.AddDouble("VAL_1", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.NA_VAL].Value);
                data_list.AddDouble("VAL_2", spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.NA_VAL_2].Value);




                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Collect_Inspection_Data_Grit", in_node, ref out_node, false) == false)
                {
                    return false;
                }
                else
                {
                    //  MPCR.ShowSuccessMsg(out_node);
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

        #region " Event Definition"

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewInspectionDataList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdInspectionData, "InspectionData(ICP)");
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }
        private void cdvMat_ButtonPress(object sender, EventArgs e)
        {
            /*
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvMat.Text = popup.sMat_id;
                    cdvMat.DisplayText = popup.sMat_Desc;
                    popup = null;
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            } 
            */
        }
        private void cdvMat_TextBoxTextChanged(object sender, EventArgs e)
        {
            // if (cdvMat.DisplayText == "")
            //    cdvMat.Text = "";
        }
        private void cdvStatus_ButtonPress(object sender, EventArgs e)
        {
            viewInspStatusList(cdvStatus.GetListView);
            cdvStatus.InsertEmptyRow(0, 1);
        }
        private void dtpFromJudgeDate_ValueChanged(object sender, EventArgs e)
        {
            dtpFromJudgeDate.CustomFormat = "yyyy-MM-dd";
        }
        private void dtpFromJudgeDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtpFromJudgeDate.CustomFormat = " ";
                    break;
            }
        }
        private void dtpFromJudgeDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromJudgeDate.CustomFormat = "yyyy-MM-dd";
        }
        private void cdvOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
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
        private void cdvInspectionType_ButtonPress(object sender, EventArgs e)
        {
            cdvInspectionType.Init();
            MPCF.InitListView(cdvInspectionType.GetListView);
            cdvInspectionType.Columns.Add("InspType", 50, System.Windows.Forms.HorizontalAlignment.Left);
            cdvInspectionType.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
            cdvInspectionType.SelectedSubItemIndex = 0;
            cdvInspectionType.DisplaySubItemIndex = 1;


            if (BASLIST.ViewGCMDataList(cdvInspectionType.GetListView, '1', CSGC.CP_GCM_INSP_TYPE, -1, null, "", true, -1, -1, null, null) == false)
            {
                return;
            }

            cdvInspectionType.InsertEmptyRow(0, 1);
        }
        private void txtMatDesc_KeyPress(object sender, KeyPressEventArgs e)
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
        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
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
        private void spdInspectionData_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            if (e.Column == (int)LOT_INFO.DETAIL || e.Column == (int)LOT_INFO.IMG)
            {
                try
                {
                    if (cdvDept.Text == CSGV.gs_area_grit)
                    {
                        frmTranInspectionRegistrationGRIT popup = new frmTranInspectionRegistrationGRIT();
                        popup.StartPosition = FormStartPosition.CenterParent;

                        popup.g_Dept = CSGV.gs_area_grit;
                        //popup.g_DeptDisplay = CSGV.gs_area_grit;
                        popup.g_Oper = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.INSP_OPER].Text;
                        popup.g_OperDisplay = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.INSP_OPER_DESC].Text;
                        popup.g_LotId = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text;
                        popup.g_PopYn = "Y";


                        if (e.Column == (int)LOT_INFO.DETAIL)
                        {
                            popup.g_SelectedTab = 0;
                        }
                        else
                        {
                            popup.g_SelectedTab = 8;
                        }



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
                catch (Exception ex)
                {
                    MPCF.ShowMsgBox(ex.Message);
                }
            }
        }
        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Init();
                MPCF.InitListView(cdvDept.GetListView);
                cdvDept.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvDept.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvDept.SelectedSubItemIndex = 0;
                cdvDept.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDept.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                {
                    return;
                }
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
                int iSaveCount = 0;


                for (int iRow = 0; iRow < spdInspectionData.ActiveSheet.RowCount; iRow++)
                {
                    if (Convert.ToBoolean(spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.CHK] == null ? false : spdInspectionData.ActiveSheet.Cells[iRow, (int)LOT_INFO.CHK].Value))
                    {

                        if (Collect_Data_ISP(iRow))
                        {
                            spdInspectionData_Sheet1.Cells[iRow, (int)LOT_INFO.CHK].Value = false;
                            spdInspectionData_Sheet1.Rows[iRow].ForeColor = Color.Black;
                            iSaveCount++;
                        }
                        else
                        {
                            spdInspectionData_Sheet1.Rows[iRow].ForeColor = Color.Red;
                            //CMN102 ERROR - 알수 없는 오류가 발생했습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(102));
                            return;

                        }
                    }
                }

                if (iSaveCount > 0)
                {
                    //CMN052 INFO - 작업을 성공적으로 수행하였습니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(52));


                }
                else
                {
                    //CMN423 ERROR - 선택된 아이템이 없습니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(423));
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdInspectionData_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)LOT_INFO.CHK)
                    {


                        CSCF.CheckSpreadCell(spdInspectionData, 0, 0, true, true);
                    }
                }
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdInspectionData, e.Row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdInspectionData_EditChange(object sender, EditorNotifyEventArgs e)
        {
            if (MPCF.Trim(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.CHK].Text) == "")
            {
                //CMN157 ERROR - Collection Set 정보가 올바르지 않습니다.
                MPCF.ShowMsgBox(MPCF.GetMessage(157));

                if (spdInspectionData_Sheet1.ActiveColumnIndex != 0)
                    spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.CHK].Value = false;
            }

            if (spdInspectionData_Sheet1.ActiveColumnIndex != 0)
                spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.CHK].Value = true;



            spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.TOTAL].Text =
                (MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.NI_VAL].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.ZN_VAL].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.MO_VAL].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.PB_VAL].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.AL_VAL].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.SI_VAL].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.B_VAL].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.NA_VAL].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.FE_VAL].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.CU_VAL].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.CR_VAL].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.TI_VAL].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.MN_VAL].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.CO_VAL].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.CA_VAL].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.MG_VAL].Text)).ToString();


            spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.TOTAL_2].Text =
                (MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.NI_VAL_2].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.ZN_VAL_2].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.MO_VAL_2].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.PB_VAL_2].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.AL_VAL_2].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.SI_VAL_2].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.B_VAL_2].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.NA_VAL_2].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.FE_VAL_2].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.CU_VAL_2].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.CR_VAL_2].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.TI_VAL_2].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.MN_VAL_2].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.CO_VAL_2].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.CA_VAL_2].Text) +
                MPCF.ToDbl(spdInspectionData_Sheet1.Cells[spdInspectionData_Sheet1.ActiveRowIndex, (int)LOT_INFO.MG_VAL_2].Text)).ToString();



        }
        private void frmViewInspectionDataIcp_KeyUp(object sender, KeyEventArgs e)
        {

        }
        private void frmViewInspectionDataIcp_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.S && (Control.ModifierKeys == Keys.Control))
            {
                btnSave_Click(sender, e);
            }
        }

        #endregion
    }
}
