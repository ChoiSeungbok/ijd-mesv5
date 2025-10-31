using CUS_COM;
using Microsoft.VisualBasic.Logging;
using Miracom.CliFrx;
using Miracom.DNMCore;
using Miracom.MESCore;
using Miracom.TRSCore;
using System;
using System.Data;
using System.Windows.Forms;

namespace CUS_QCM
{
    public partial class frmPopSampleRndInspectionLotList : CUS_COM.frmTranForm06
    {
        public frmPopSampleRndInspectionLotList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT_INFO
        {
            CHK,
            INSP_REQ_TIME,
            CREATE_CODE,
            CREATE_BTN,

            LOT_ID,
            QTY,
            ORDER_ID,
            MAT_ID,
            MAT_BTN,
            MAT_DESC,
            FlOW,
            FLOW_BTN,
            FLOW_DESC,
            GRADE,
            SIZES,
            INSP_STATUS,
            JUDGE,
            COMMENT,
            INSP_ID,
            INSP_OPER,
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
        public string sSearchMatId = "";

        #endregion

        #region " Function Definition "
        private void InitControl()
        {
            try
            {
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnNew.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                chkDirLot.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                chkDirLot.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                if (cdvDept.Text == "CTM")
                {
                    cdvOper.Text = "OC90030";
                    cdvOper.DisplayText = "CTM 연구소 수입검사";
                    chkDirLot.Checked = false;
                }
                else if (cdvDept.Text == "GRT")
                {
                    cdvOper.Text = "OG05260";
                    cdvOper.DisplayText = "SAMPLE  검사";
                    chkDirLot.Checked = true;
                }
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
        //LOT ID 조회 함수
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


                if (TPDR.GetDataOne("", ref dt, "CQCM3001-012", dvcArgu, false, false, ref sSql) == false)
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
                    spdLotList_Sheet1.SetValue(i, (int)LOT_INFO.CHK, false);
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.FlOW].Value = dt.Rows[i]["FLOW"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.FLOW_DESC].Value = dt.Rows[i]["FLOW_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.SIZES].Value = dt.Rows[i]["SIZES"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.COMMENT].Value = dt.Rows[i]["INSP_COMMENT"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.INSP_ID].Value = dt.Rows[i]["INSP_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.INSP_REQ_TIME].Value = dt.Rows[i]["INSP_REQ_TIME"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.INSP_STATUS].Value = dt.Rows[i]["INSP_STATUS"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.JUDGE].Value = dt.Rows[i]["JUDGE"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.INSP_OPER].Value = dt.Rows[i]["INSP_OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.INSP_OPER_DESC].Value = dt.Rows[i]["INSP_OPER_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.DLV_LOT_STATUS].Value = dt.Rows[i]["DLV_LOT_STATUS"];





                }

                // MPCF.FitColumnHeader(spdLotList);


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private bool SaveOrder(char sStep, int iRow)
        {
            try
            {

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                string sflow = "";


                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;


                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_ID].Text;


                dvcArgu[2].sCondition_ID = "FLOW";


                //플로우 강제로 고정.
                if (cdvDept.Text == "CTM")
                {
                    dvcArgu[2].sCondition_Value = "FC940";
                    sflow = "FC940";
                }
                else if (cdvDept.Text == "GRT")
                {
                    dvcArgu[2].sCondition_Value = "FG919";
                    sflow = "FG919";
                }



                if (TPDR.GetDataOne("", ref dt, "CQCM3001-011", dvcArgu, false, false, ref sSql) == true)
                {
                    if (dt != null)
                        dt.Dispose();
                    spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.FlOW].Text = sflow;
                }
                else
                {   //플로우 없으면 넣기
                    if (Attach_Flow_ToMaterial(sflow))
                    {
                        spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.FlOW].Text = sflow;
                    }
                }



                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = sStep;

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("ORDER_ID", spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.ORDER_ID].Text);


                if (sStep != '2')
                {
                    //
                    in_node.AddString("OPER", cdvOper.Text);
                    in_node.AddString("COMMENT", spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.COMMENT].Text);
                    in_node.AddString("FLOW", spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.FlOW].Text);
                    in_node.AddString("MAT_ID", spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.MAT_ID].Text);
                    in_node.AddDouble("ORD_QTY", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.QTY].Text));
                    in_node.AddString("FROM_DATE", DateTime.Now.ToString("yyyyMMdd") + "000000");
                    in_node.AddString("TO_DATE", DateTime.Now.ToString("yyyyMMdd") + "000000");
                    in_node.AddString("CREATE_CODE", spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.CREATE_CODE].Text);
                    if (cdvDept.Text == "GRT")
                    {
                        in_node.AddString("INSP_SAMPLE_GRADE", spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.GRADE].Text.Trim());
                        in_node.AddString("INSP_SAMPLE_SIZE", spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.SIZES].Text.Trim());
                    }
                    else
                    {
                        in_node.AddString("INSP_SAMPLE_GRADE", "");
                        in_node.AddString("INSP_SAMPLE_SIZE", "");
                    }
                    in_node.AddChar("LOT_CREATE_FLAG", 'Y');

                    if (chkDirLot.Checked == true)
                    {




                        if (spdLotList_Sheet1.Cells[iRow, (int)LOT_INFO.LOT_ID].Text.Trim().Length == 0)
                        {
                            // CMN479 INFO -수기입력방식인경우 LotID를 지정해주셔야 합니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(479));
                            return false;

                        }
                        in_node.AddChar("LOT_INPUT_FLAG", 'Y');
                        in_node.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.LOT_ID].Text);

                    }
                    else
                    {
                        in_node.AddChar("LOT_INPUT_FLAG", 'N');
                    }

                }

                if (MPCR.CallService("CUS_ORD", "CUS_ORD_Create_Test_Order", in_node, ref out_node) == false)
                {
                    return false;
                }
                else
                {
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.ORDER_ID, out_node.GetString("ORDER_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.LOT_ID, out_node.GetString("LOT_ID"));
                }


                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        private bool Attach_Flow_ToMaterial(string sAttachFlow)
        {


            TRSNode in_node = new TRSNode("ATTACH_FLOW_TOMATERIAL_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            in_node.AddString("MAT_ID", MPCF.Trim(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.MAT_ID].Text));
            in_node.AddInt("MAT_VER", 1);
            in_node.AddString("FLOW", MPCF.Trim(sAttachFlow));


            if (MPCR.CallService("WIP", "WIP_Attach_Flow_ToMaterial", in_node, ref out_node) == false)
            {
                return false;
            }
            else
            {
                spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.FlOW].Text = sAttachFlow;
            }


            return true;
        }
        private bool MatFlowCheck()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";


                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;


                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = txtMatID.Text;


                dvcArgu[2].sCondition_ID = "FLOW";



                //플로우 강제로 고정.
                if (cdvDept.Text == "CTM")
                {
                    dvcArgu[2].sCondition_Value = "FC940";
                }
                else if (cdvDept.Text == "GRT")
                {
                    dvcArgu[2].sCondition_Value = "FG919";
                }




                if (TPDR.GetDataOne("", ref dt, "CQCM3001-011", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLotList);
                    return false;
                }
                else
                {
                    return true;
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        // 서버개발 라이센스 지금 없어서 걍 DB FUnction으로 Update침(f_iqc_pass)
        private void SaveIQcPass(string sInspStatus, string sInspResult)
        {
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

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                //  cdvOper.Text = "";

                if (cdvDept.Text == "CTM")
                {
                    cdvOper.Text = "OC90030";
                    cdvOper.DisplayText = "CTM 연구소 수입검사";
                    chkDirLot.Checked = false;
                }
                else if (cdvDept.Text == "GRT")
                {
                    cdvOper.Text = "OG05260";
                    cdvOper.DisplayText = "SAMPLE  검사";
                    chkDirLot.Checked = true;
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
        #endregion

        #region " Event Definition "
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
        private void cdvStatus_ButtonPress(object sender, EventArgs e)
        {
            viewInspStatusList(cdvStatus.GetListView);
            cdvStatus.InsertEmptyRow(0, 1);
        }
        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewLotList();
                btnSave.Enabled = false;
                chkDirLot.Visible = false;

                this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.CREATE_CODE).Locked = true;
                this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.LOT_ID).Locked = true;
                this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.QTY).Locked = true;
                this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.MAT_ID).Locked = true;
                this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.MAT_DESC).Locked = true;
                this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.GRADE).Locked = true;
                this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.SIZES).Locked = true;
                this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.COMMENT).Locked = true;



                this.spdLotList_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.CREATE_CODE).BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
                this.spdLotList_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.LOT_ID).BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
                this.spdLotList_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.QTY).BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
                this.spdLotList_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.MAT_ID).BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
                this.spdLotList_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.MAT_DESC).BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
                this.spdLotList_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.GRADE).BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
                this.spdLotList_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.SIZES).BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));
                this.spdLotList_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.COMMENT).BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(13)))), ((int)(((byte)(86)))), ((int)(((byte)(155)))));


                if (cdvDept.Text == "GRT")
                {
                    // this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.MAT_ID).Visible = false;
                    // this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.MAT_BTN).Visible = false;
                    // this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.MAT_DESC).Visible = false;
                    this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.GRADE).Visible = true;
                    this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.SIZES).Visible = true;
                }
                else
                {
                    // this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.MAT_ID).Visible = true;
                    //  this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.MAT_BTN).Visible = true;
                    //  this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.MAT_DESC).Visible = true;
                    this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.GRADE).Visible = false;
                    this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.SIZES).Visible = false;
                }

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
        private void frmPopSampleRndInspectionLotList_Load(object sender, EventArgs e)
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


            if (cdvDept.Text == "CTM")
            {
                cdvOper.Text = "OC90030";
                cdvOper.DisplayText = "CTM 연구소 수입검사";
                chkDirLot.Checked = false;
            }
            else if (cdvDept.Text == "GRT")
            {
                cdvOper.Text = "OG05260";
                cdvOper.DisplayText = "SAMPLE  검사";
                chkDirLot.Checked = true;
            }

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
        private void btnIqcPass_Click(object sender, EventArgs e)
        {

        }
        private void spdLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {



            if (spdLotList.ActiveSheet.ActiveRowIndex < 0)
                return;


            if (e.Column == (int)LOT_INFO.MAT_BTN)
            {


                if (cdvDept.Text != "GRT")
                {
                    if (MPCF.Trim(cdvDept.Text) == "")
                    {
                        //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + "Department" + "]");
                        return;
                    }

                    frmPopMaterialList popup = new frmPopMaterialList();
                    popup.StartPosition = FormStartPosition.CenterParent;
                    popup.sArea_id = cdvDept.Text;
                    popup.sArea_desc = cdvDept.DisplayText;

                    if (popup.ShowDialog() == DialogResult.OK)
                    {

                        spdLotList.ActiveSheet.SetValue(spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.MAT_ID, popup.sMat_id);
                        spdLotList.ActiveSheet.SetValue(spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.MAT_DESC, popup.sMat_Desc);

                        popup = null;






                    }
                    else
                    {
                        return;
                    }
                }
                else
                {



                    TRSNode in_node = new TRSNode("SQL_IN");
                    TRSNode out_node = new TRSNode("SQL_OUT");

                    cdvGridButton1.Init();
                    MPCF.InitListView(cdvGridButton1.GetListView);
                    cdvGridButton1.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridButton1.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '1';

                    in_node.AddString("SQL", "SELECT A.MAT_ID AS CODE,  "
                                                         + "          A.MAT_DESC AS VALUE "
                                                         + "         FROM MWIPMATDEF A "
                                                         + "       WHERE A.FACTORY = '" + MPGV.gsFactory + "' "
                                                         + "          AND A.MAT_ID IN( 'AG00000-00000','AG00000-00001')"
                                                         + "       ORDER BY A.MAT_ID");


                    do
                    {
                        if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                        {
                            return;
                        }

                        MPCR.FillDataView(cdvGridButton1.GetListView, out_node);

                        in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));




                    }
                    while (out_node.GetInt("NEXT_ROW") > 0);

                    cdvGridButton1.ShowPopupList(e.Row, e.Column);
                }




            }

            else if (e.Column == (int)LOT_INFO.CREATE_BTN)
            {

                cdvGridButton1.Init();
                MPCF.InitListView(cdvGridButton1.GetListView);
                cdvGridButton1.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvGridButton1.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                if (BASLIST.ViewGCMDataList(cdvGridButton1.GetListView, '1', MPGC.MP_WIP_CREATE_CODE) == false)
                    return;

                //양산품은 뺀다.
                for (int i = cdvGridButton1.GetListView.Items.Count; i > 0; i--)
                {
                    if (cdvGridButton1.GetListView.Items[i - 1].SubItems[0].Text == "PROD")
                    {
                        cdvGridButton1.GetListView.Items[i - 1].Remove();
                    }
                }

                cdvGridButton1.ShowPopupList(e.Row, e.Column);
                cdvGridButton1.AddEmptyRow(1);
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
        private void cdvMatType_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {

        }
        private void pnlStsCond_Paint(object sender, PaintEventArgs e)
        {

        }
        private void lblStatus_Click(object sender, EventArgs e)
        {

        }
        private void btnNew_Click(object sender, EventArgs e)
        {
            //  MPCF.ClearList(spdLotList);
            spdLotList.ActiveSheet.Rows.Add(spdLotList.ActiveSheet.RowCount, 1);

            btnSave.Enabled = true;
            chkDirLot.Visible = true;


            this.spdLotList_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.CREATE_CODE).BackColor = System.Drawing.Color.Red;
            this.spdLotList_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.LOT_ID).BackColor = System.Drawing.Color.Red;
            this.spdLotList_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.QTY).BackColor = System.Drawing.Color.Red;
            this.spdLotList_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.MAT_ID).BackColor = System.Drawing.Color.Red;
            this.spdLotList_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.MAT_DESC).BackColor = System.Drawing.Color.Red;
            this.spdLotList_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.GRADE).BackColor = System.Drawing.Color.Red;
            this.spdLotList_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.SIZES).BackColor = System.Drawing.Color.Red;
            this.spdLotList_Sheet1.ColumnHeader.Cells.Get(0, (int)LOT_INFO.COMMENT).BackColor = System.Drawing.Color.Red;



            this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.CREATE_CODE).Locked = false;

            this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.QTY).Locked = false;
            this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.MAT_ID).Locked = false;
            this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.MAT_DESC).Locked = false;
            this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.GRADE).Locked = false;
            this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.SIZES).Locked = false;
            this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.COMMENT).Locked = false;


            if (chkDirLot.Checked == true)
            {
                this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.LOT_ID).Locked = false;
            }
            else
            {
                this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.LOT_ID).Locked = true;
            }


            spdLotList_Sheet1.SetValue(spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.CHK, true);
            if (cdvDept.Text == "GRT")
            {


                spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.CREATE_CODE].Text = "TEST";
                //GRT SAMPLE 검사는 품목코드가없음 AG00000-00000 이걸로 고정. 시킴
                spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.MAT_ID].Text = "AG00000-00000";
                spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.MAT_DESC].Text = "GRT SAMPLE(일반)";
                // this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.MAT_ID).Visible = false;
                // this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.MAT_BTN).Visible = false;
                // this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.MAT_DESC).Visible = false;
                this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.GRADE).Visible = true;
                this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.SIZES).Visible = true;

            }
            else
            {
                // this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.MAT_ID).Visible = true;
                //this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.MAT_BTN).Visible = true;
                // this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.MAT_DESC).Visible = true;
                this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.GRADE).Visible = false;
                this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.SIZES).Visible = false;
            }


        }
        private void cdvGridButton1_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            try
            {

                if (sSearchMatId == "Y")
                {
                    sSearchMatId = "N";
                    txtMatID.Text = e.SelectedItem.SubItems[0].Text;
                    txtMatDesc.Text = e.SelectedItem.SubItems[1].Text;

                }
                else
                {
                    if (spdLotList.ActiveSheet.ActiveColumnIndex == (int)LOT_INFO.FLOW_BTN)
                    {
                        spdLotList_Sheet1.SetValue(e.Row, (int)LOT_INFO.FlOW, e.SelectedItem.SubItems[0].Text);
                        spdLotList_Sheet1.SetValue(e.Row, (int)LOT_INFO.FLOW_DESC, e.SelectedItem.SubItems[1].Text);
                    }

                    if (spdLotList.ActiveSheet.ActiveColumnIndex == (int)LOT_INFO.CREATE_BTN)
                    {
                        spdLotList_Sheet1.SetValue(e.Row, (int)LOT_INFO.CREATE_CODE, e.SelectedItem.SubItems[0].Text);
                    }

                    if (spdLotList.ActiveSheet.ActiveColumnIndex == (int)LOT_INFO.MAT_BTN)
                    {
                        spdLotList_Sheet1.SetValue(e.Row, (int)LOT_INFO.MAT_ID, e.SelectedItem.SubItems[0].Text);
                        spdLotList_Sheet1.SetValue(e.Row, (int)LOT_INFO.MAT_DESC, e.SelectedItem.SubItems[1].Text);
                    }

                    spdLotList.ActiveSheet.SetValue(spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.CHK, true);
                }



            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnSave_Click(object sender, EventArgs e)
        {

            if (chkDirLot.Checked == true)
            {

                //20230215 수기입력시에는 일단 경고 메세지를 날려줌.
                //미래에 채번되않은 LOT을 미리 채번을 한경우 시스템에 오류를 발생시킬수 있음을 경고 처리. 
                //CMN571 INFO -수기로 입력한 LOT은 나중에 시스템에 전체적인 오류를 발생시킬수도 있습니다. 주의가 필요합니다.(진행하시겠습니까 ? Yes / No)
                if (MPCF.ShowMsgBox(MPCF.GetMessage(571), MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.No)
                {
                    return;

                }
            }

            for (int j = 0; j < spdLotList.ActiveSheet.RowCount; j++)
            {
                if (spdLotList.ActiveSheet.Cells[j, (int)LOT_INFO.CHK].Text != "")
                {
                    if (spdLotList.ActiveSheet.Cells[j, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE" && spdLotList.ActiveSheet.Cells[j, (int)LOT_INFO.ORDER_ID].Text.Trim() == "")
                    {
                        if (SaveOrder('1', j) == false)
                        {
                            break;
                        }
                    }
                }


            }

            ViewLotList();
        }
        private void btnDelete_Click(object sender, EventArgs e)
        {

        }
        private void chkDirLot_CheckedChanged(object sender, EventArgs e)
        {

            if (spdLotList.ActiveSheet.RowCount > 0 && btnSave.Enabled == true)
            {
                spdLotList.ActiveSheet.SetValue(0, (int)LOT_INFO.LOT_ID, "");
                if (chkDirLot.Checked == true)
                {
                    this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.LOT_ID).Locked = false;
                }
                else
                {
                    this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.LOT_ID).Locked = true;
                }
            }
            else
            {
                this.spdLotList_Sheet1.Columns.Get((int)LOT_INFO.LOT_ID).Locked = true;
            }


        }
        private void btnDelete_Click_1(object sender, EventArgs e)
        {
            try
            {

                if (spdLotList.ActiveSheet.RowCount == 0)
                {
                    return;

                }


                //저장중삭제만 그냥 줄만 삭제.
                if (spdLotList.ActiveSheet.RowCount > 0 && btnSave.Enabled == true && spdLotList.ActiveSheet.Cells[spdLotList_Sheet1.ActiveRowIndex, (int)LOT_INFO.ORDER_ID].Text.Trim() == "")
                {

                    spdLotList.ActiveSheet.Rows.Remove(spdLotList_Sheet1.ActiveRowIndex, 1);
                    // spdLotList_Sheet1.RowCount = 0;
                    return;

                }


                //CMN453 INFO - 정말 삭제하시겠습니까?
                if (MPCF.ShowMsgBox(MPCF.GetMessage(453), MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.No)
                {
                    return;

                }

                if (spdLotList.ActiveSheet.Cells[spdLotList_Sheet1.ActiveRowIndex, (int)LOT_INFO.JUDGE].Text.Trim() != "")
                {
                    MPCF.ShowMsgBox("판정이전의 LOT만 삭제할수 있습니다. 판정먼저 리턴바랍니다.");
                    return;

                }




                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';



                in_node.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[spdLotList_Sheet1.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Delete_Lot_History", in_node, ref out_node) == false)
                {
                    return;
                }
                else
                {

                    TRSNode in_node_2 = new TRSNode("TRAN_IN");
                    TRSNode out_node_2 = new TRSNode("TRAN_OUT");

                    MPCR.SetInMsg(in_node_2);

                    in_node_2.ProcStep = '2';

                    in_node_2.AddString("AREA_ID", cdvDept.Text);
                    in_node_2.AddString("ORDER_ID", spdLotList.ActiveSheet.Cells[spdLotList_Sheet1.ActiveRowIndex, (int)LOT_INFO.ORDER_ID].Text);


                    if (MPCR.CallService("CUS_ORD", "CUS_ORD_Create_Test_Order", in_node_2, ref out_node_2) == false)
                        return;
                    else
                        MPCR.ShowSuccessMsg(out_node_2);

                }



                ViewLotList();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        private void btnMatid_Click(object sender, EventArgs e)
        {


            if (cdvDept.Text != "GRT")
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + "Department" + "]");
                    return;
                }

                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {

                    txtMatID.Text = popup.sMat_id;
                    txtMatDesc.Text = popup.sMat_Desc;

                    popup = null;






                }
                else
                {
                    return;
                }
            }
            else
            {

                TRSNode in_node = new TRSNode("SQL_IN");
                TRSNode out_node = new TRSNode("SQL_OUT");

                cdvGridButton1.Init();
                MPCF.InitListView(cdvGridButton1.GetListView);
                cdvGridButton1.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvGridButton1.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                in_node.AddString("SQL", "SELECT A.MAT_ID AS CODE,  "
                                                     + "          A.MAT_DESC AS VALUE "
                                                     + "         FROM MWIPMATDEF A "
                                                     + "       WHERE A.FACTORY = '" + MPGV.gsFactory + "' "
                                                     + "          AND A.MAT_ID IN( 'AG00000-00000','AG00000-00001')"
                                                     + "       ORDER BY A.MAT_ID");


                do
                {
                    if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                    {
                        return;
                    }

                    MPCR.FillDataView(cdvGridButton1.GetListView, out_node);

                    in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
                    sSearchMatId = "Y";



                }
                while (out_node.GetInt("NEXT_ROW") > 0);

                cdvGridButton1.ShowPopupList(1, 1);

            }



        }
        #endregion
    }
}
