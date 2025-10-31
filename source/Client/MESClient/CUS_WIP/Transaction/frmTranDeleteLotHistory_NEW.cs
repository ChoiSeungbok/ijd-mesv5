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
using Microsoft.Office.Interop.Excel;
using System.Reflection.Emit;

namespace CUS_WIP
{
    public partial class frmTranDeleteLotHistory_NEW : frmViewForm01
    {
        public frmTranDeleteLotHistory_NEW()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "


        private enum LOTLIST_INFO
        {
            CHK,
            LOT_ID,                 //  : HISTORY SEQ 
            START_SEQ,              //  : 리턴시작 HIST_SEQ
            STOP_SEQ,               //  : 리턴종료 HIST_SEQ
            DELETABLE,              //  : 리턴가능한지 여부
            RESULT,                 //  : 처리후 결과
            REQUEST_OPERATION,      //  : 리턴후 공정.
            LAST_DELETE_OPERATION,  //  : 마지막 리턴삭제될 공정.
            LAST_DELETE_HIS_DATE,  //  : 마지막 리턴삭제될 히스토리 날짜 

        }


        private enum LOTHIS_INFO
        {
            CHK,
            SEQ,                    //  : HISTORY SEQ 
            TRAN_TIME,              //  : 트랜잭션 시간
            OPER,                   //  : 공정코드
            OPER_DESC,              //  : 공정명
            TRAN_CODE,              //  : 트랜젝션코드
            MAT_ID,                 //  : 제품코드
            MAT_DESC,               //  : 제품명            
            QTY_1,                  //  : 생산수량
            ORDER_ID,               //  : 작업지시
            START_TIME,             //  : 시작시간
            START_RES_DESC,         //  : 시작설비
            END_TIME,               //  : 완료시간
            END_RES_DESC,           //  : 완료설비
            LOT_ID,                 //  : LOT ID
            GROUP_ID,               //  : 그룹 ID
            FROM_TO_LOT_ID,         //  : FROM TO LOT ID
            OPER_TYPE,              //  : WIP인지 INV인지
            HIST_DEL_FLAG,          //  : 이력삭제여부
            QC_TYPE,  //  : 검사공정인지여부
            OLD_OPER_QC_TYPE  //  : 이전공정 검사공정인지여부
        }


        private enum JUDGE_LOTLIST_INFO
        {
            CHK,
            LOT_ID,
            RESULT,
            INSP_ID,
            JUDGE,
            SHIP_JUDGE
        }

        #endregion

        #region " Variable Definition "
        private ListView listView;
        private string sQCPermission;

        private string sReturnPermission;
        public string g_popYn ="N";
        public string g_LotId= "";

        #endregion
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnJudgeSearch.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblDeletable.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblDeleted.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblNotDeletable.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                PermissionSearch();
                judgeDescList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private bool ViewLotHistory(string sLotId, int iSelectRow)
        {
            int num = 0;
            string text = MPCF.ToStandardTime(DateTime.Now, "DATETIME").Substring(0, 6);
            try
            {
                for (int i = 0; i < spdSearchLotList.ActiveSheet.RowCount; i++)
                {
                    spdSearchLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }
                spdSearchLotList.ActiveSheet.Rows[iSelectRow].BackColor = Color.FromArgb(255, 192, 255);
                TRSNode tRSNode = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("LOT_ID", sLotId);
                if (chkIncDelFlag.Checked)
                {
                    tRSNode.AddChar("INCLUDE_HIST_DEL", 'Y');
                }
                if (!MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_History", tRSNode, ref out_node))
                {
                    MPCF.ClearList(spdLotList);
                    spdSearchLotDelete(iSelectRow);
                    return false;
                }
                MPCF.ClearList(spdLotList);
                for (int j = 0; j < out_node.GetList("LOT_TBL").Count; j++)
                {
                    num = spdLotList.ActiveSheet.RowCount;
                    spdLotList.ActiveSheet.RowCount++;
                    spdLotList.ActiveSheet.SetValue(num, 1, out_node.GetList("LOT_TBL")[j].GetInt("HIST_SEQ"));
                    spdLotList.ActiveSheet.SetValue(num, 2, MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[j].GetString("TRAN_TIME"), DATE_TIME_FORMAT.DATETIME));
                    spdLotList.ActiveSheet.SetValue(num, 3, out_node.GetList("LOT_TBL")[j].GetString("OPER"));
                    spdLotList.ActiveSheet.SetValue(num, 4, out_node.GetList("LOT_TBL")[j].GetString("OPER_DESC"));
                    spdLotList.ActiveSheet.SetValue(num, 5, out_node.GetList("LOT_TBL")[j].GetString("TRAN_CODE"));
                    spdLotList.ActiveSheet.SetValue(num, 6, out_node.GetList("LOT_TBL")[j].GetString("MAT_ID"));
                    spdLotList.ActiveSheet.SetValue(num, 7, out_node.GetList("LOT_TBL")[j].GetString("MAT_DESC"));
                    spdLotList.ActiveSheet.SetValue(num, 8, out_node.GetList("LOT_TBL")[j].GetDouble("QTY_1"));
                    spdLotList.ActiveSheet.SetValue(num, 9, out_node.GetList("LOT_TBL")[j].GetString("ORDER_ID"));
                    spdLotList.ActiveSheet.SetValue(num, 10, MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[j].GetString("START_TIME"), DATE_TIME_FORMAT.DATETIME));
                    spdLotList.ActiveSheet.SetValue(num, 11, out_node.GetList("LOT_TBL")[j].GetString("START_RES_DESC"));
                    spdLotList.ActiveSheet.SetValue(num, 12, MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[j].GetString("END_TIME"), DATE_TIME_FORMAT.DATETIME));
                    spdLotList.ActiveSheet.SetValue(num, 13, out_node.GetList("LOT_TBL")[j].GetString("END_RES_DESC"));
                    spdLotList.ActiveSheet.SetValue(num, 14, out_node.GetList("LOT_TBL")[j].GetString("LOT_ID"));
                    spdLotList.ActiveSheet.SetValue(num, 15, out_node.GetList("LOT_TBL")[j].GetString("LOT_CMF_1"));
                    spdLotList.ActiveSheet.SetValue(num, 16, out_node.GetList("LOT_TBL")[j].GetString("FROM_TO_LOT_ID"));
                    spdLotList.ActiveSheet.SetValue(num, 17, out_node.GetList("LOT_TBL")[j].GetString("OPER_TYPE"));
                    spdLotList.ActiveSheet.SetValue(num, 18, out_node.GetList("LOT_TBL")[j].GetChar("HIST_DEL_FLAG"));
                    spdLotList.ActiveSheet.SetValue(num, 19, out_node.GetList("LOT_TBL")[j].GetString("QC_TYPE"));
                    spdLotList.ActiveSheet.SetValue(num, 20, out_node.GetList("LOT_TBL")[j].GetString("OLD_OPER_QC_TYPE"));
                    if (out_node.GetList("LOT_TBL")[j].GetChar("HIST_DEL_FLAG") == 'Y')
                    {
                        spdLotList.ActiveSheet.Rows[num].BackColor = Color.Red;
                        spdLotList.ActiveSheet.Rows[num].ForeColor = Color.White;
                    }
                    else if (out_node.GetList("LOT_TBL")[j].GetString("OPER_TYPE").ToString() == "INV" && out_node.GetList("LOT_TBL")[j].GetString("TRAN_CODE").ToString() == "CV")
                    {
                        spdLotList.ActiveSheet.Rows[num].BackColor = Color.Gray;
                        spdLotList.ActiveSheet.Rows[num].ForeColor = Color.Yellow;
                    }
                    if (sQCPermission != "Y")
                    {
                        if (out_node.GetList("LOT_TBL")[j].GetString("QC_TYPE").ToString() != "NONE" && out_node.GetList("LOT_TBL")[j].GetString("TRAN_CODE").ToString() != "END")
                        {
                            spdLotList.ActiveSheet.Rows[num].BackColor = Color.Gray;
                            spdLotList.ActiveSheet.Rows[num].ForeColor = Color.Yellow;
                        }
                        else if (out_node.GetList("LOT_TBL")[j].GetString("OLD_OPER_QC_TYPE").ToString() != "NONE")
                        {
                            spdLotList.ActiveSheet.Rows[num].BackColor = Color.Gray;
                            spdLotList.ActiveSheet.Rows[num].ForeColor = Color.Yellow;
                        }
                        else if (out_node.GetList("LOT_TBL")[j].GetString("TRAN_TIME").Substring(0, 6) == text)
                        {
                            spdLotList.ActiveSheet.Rows[num].ForeColor = Color.Blue;
                        }
                        else
                        {
                            spdLotList.ActiveSheet.Rows[num].BackColor = Color.Gray;
                            spdLotList.ActiveSheet.Rows[num].ForeColor = Color.Yellow;
                        }
                    }
                    else if (out_node.GetList("LOT_TBL")[j].GetString("TRAN_TIME").Substring(0, 6) == text)
                    {
                        spdLotList.ActiveSheet.Rows[num].ForeColor = Color.Blue;
                    }
                    else
                    {
                        spdLotList.ActiveSheet.Rows[num].BackColor = Color.Gray;
                        spdLotList.ActiveSheet.Rows[num].ForeColor = Color.Yellow;
                    }
                    if (spdSearchLotList.ActiveSheet.Cells[iSelectRow, 3].Text.Trim().Length != 0 && MPCF.ToDbl(spdSearchLotList.ActiveSheet.Cells[iSelectRow, 3].Text) <= MPCF.ToDbl(spdLotList.ActiveSheet.Cells[num, 1].Text) && out_node.GetList("LOT_TBL")[j].GetChar("HIST_DEL_FLAG") != 'Y')
                    {
                        spdLotList.ActiveSheet.Cells[num, 0].Value = true;
                        spdLotList_Sheet1.Rows.Get(num).Font = new System.Drawing.Font("굴림", 9f, FontStyle.Bold | FontStyle.Italic | FontStyle.Strikeout, GraphicsUnit.Point, 129);
                    }
                }
                MPCF.FitColumnHeader(spdLotList);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool DeleteLotHistiry2(string sLotID, int iStopSeq, int iRow)
        {
            try
            {
                TRSNode tRSNode = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '3';
                tRSNode.AddString("LOT_ID", sLotID);
                tRSNode.AddInt("STOP_SEQ", iStopSeq);
                if (!MPCR.CallService("CUS_WIP", "CUS_WIP_Delete_Lot_History", tRSNode, ref out_node))
                {
                    spdSearchLotList.ActiveSheet.Cells[iRow, 5].Text = "FAIL";
                    return false;
                }
                spdSearchLotList.ActiveSheet.Cells[iRow, 5].Text = "SUCCESS";
                spdSearchLotList.ActiveSheet.Cells[iRow, 3].Text = "";
                spdSearchLotList.ActiveSheet.Cells[iRow, 2].Text = "";
                spdSearchLotList.ActiveSheet.Cells[iRow, 4].Text = "";
                spdSearchLotList.ActiveSheet.Cells[iRow, 6].Text = "";
                spdSearchLotList.ActiveSheet.Cells[iRow, 7].Text = "";
                spdSearchLotList.ActiveSheet.Cells[iRow, 8].Text = "";
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void ViewLotInfo(string sLotId, int iRow)
        {
            try
            {
                if (sLotId.Trim() == "")
                {
                    return;
                }
                TRSNode tRSNode = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                MPCR.SetInMsg(tRSNode);
                tRSNode.ProcStep = '1';
                tRSNode.AddString("LOT_ID", sLotId);
                if (!MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_Info", tRSNode, ref out_node))
                {
                    spdJudgeLot.ActiveSheet.SetValue(iRow, 0, false);
                    spdJudgeLot.ActiveSheet.SetValue(iRow, 2, "SEARCH ERROR");
                    return;
                }
                for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                {
                    spdJudgeLot.ActiveSheet.SetValue(iRow, 0, true);
                    spdJudgeLot.ActiveSheet.SetValue(iRow, 1, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                    spdJudgeLot.ActiveSheet.SetValue(iRow, 2, "");
                    spdJudgeLot.ActiveSheet.SetValue(iRow, 3, out_node.GetList("LOT_TBL")[i].GetString("LOT_CMF_10"));
                    spdJudgeLot.ActiveSheet.Cells[iRow, 4].Text = GetDescByJudge(out_node.GetList("LOT_TBL")[i].GetString("LOT_CMF_11"));
                    spdJudgeLot.ActiveSheet.Cells[iRow, 5].Text = GetDescByJudge(out_node.GetList("LOT_TBL")[i].GetString("LOT_CMF_19"));
                }
                MPCF.FitColumnHeader(spdJudgeLot);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private string GetDescByJudge(string sJudge)
        {
            foreach (ListViewItem item in listView.Items)
            {
                if (item.Text == sJudge)
                {
                    return item.SubItems[1].Text;
                }
            }
            return " ";
        }

        private void PermissionSearch()
        {
            TRSNode tRSNode = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = '1';
            tRSNode.AddString("SQL", "SELECT USER_CMF_9 AS QC_AC,USER_CMF_10 AS RETURN_AC FROM MSECUSRDEF   WHERE FACTORY = '" + MPGV.gsFactory + "'    AND USER_ID = '" + MPGV.gsUserID + "' ");
            if (MPCR.CallService("BAS", "BAS_SQL_Query", tRSNode, ref out_node))
            {
                if (out_node.GetList("ROWS")[0].GetList("COLS")[0].GetString("DATA").ToString() == "Y")
                {
                    sQCPermission = "Y";
                }
                else
                {
                    sQCPermission = "N";
                }
                if (out_node.GetList("ROWS")[0].GetList("COLS")[1].GetString("DATA").ToString() == "Y")
                {
                    sReturnPermission = "Y";
                }
                else
                {
                    sReturnPermission = "N";
                }
            }
        }

        private void judgeDescList()
        {
            listView = new ListView();
            listView.Bounds = new System.Drawing.Rectangle(10, 10, 400, 200);
            listView.View = View.Details;
            listView.FullRowSelect = true;
            listView.GridLines = true;
            listView.Columns.Add("CODE", 50, System.Windows.Forms.HorizontalAlignment.Left);
            listView.Columns.Add("NAME", 150, System.Windows.Forms.HorizontalAlignment.Left);
            TRSNode tRSNode = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            MPCF.InitListView(listView);
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = '1';
            tRSNode.AddString("SQL", "SELECT KEY_1 AS CODE,        DATA_1 AS VALUE   FROM MGCMTBLDAT A   WHERE FACTORY = '" + MPGV.gsFactory + "'    AND TABLE_NAME = 'C_INSP_JUDGE_LIST'  ORDER BY KEY_1");
            do
            {
                if (!MPCR.CallService("BAS", "BAS_SQL_Query", tRSNode, ref out_node))
                {
                    return;
                }
                MPCR.FillDataView(listView, out_node);
                tRSNode.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            }
            while (out_node.GetInt("NEXT_ROW") > 0);
            base.Controls.Add(listView);
            listView.Visible = false;
        }

        private bool UpdateLotJudge(string sLotID)
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[2];
                System.Data.DataTable dt = null;
                string sSql = "";
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "LOT_ID";
                array[1].sCondition_Value = sLotID;
                if (!TPDR.GetDataOne("", ref dt, "CWIP2045-001", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    return false;
                }
                return true;
            }
            catch (Exception)
            {
                return false;
            }
        }

        private bool LotOverlapCheck(string sLotid)
        {
            int foundRowIndex = -1;
            int foundColumnIndex = -1;
            spdSearchLotList.Search(0, sLotid, caseSensitive: false, exactMatch: false, alternateSearch: false, useWildcards: false, 0, 1, spdSearchLotList.ActiveSheet.RowCount, 1, ref foundRowIndex, ref foundColumnIndex);
            if (foundRowIndex == -1)
            {
                return true;
            }
            spdSearchLotList.ActiveSheet.ActiveRowIndex = foundRowIndex;
            spdSearchLotList.ActiveSheet.ActiveColumnIndex = foundColumnIndex;
            MPCF.ShowMsgBox(MPCF.GetMessage(111) + "  LOT_ID(" + sLotid + ")");
            return false;
        }

        private bool LotOverlapCheck2(string sLotid)
        {
            int foundRowIndex = -1;
            int foundColumnIndex = -1;
            spdJudgeLot.Search(0, sLotid, caseSensitive: false, exactMatch: false, alternateSearch: false, useWildcards: false, 0, 1, spdJudgeLot.ActiveSheet.RowCount, 1, ref foundRowIndex, ref foundColumnIndex);
            if (foundRowIndex == -1)
            {
                return true;
            }
            spdJudgeLot.ActiveSheet.ActiveRowIndex = foundRowIndex;
            spdJudgeLot.ActiveSheet.ActiveColumnIndex = foundColumnIndex;
            MPCF.ShowMsgBox(MPCF.GetMessage(111) + "  LOT_ID(" + sLotid + ")");
            return false;
        }

        private void selectRowDelete(int iRow, string sLotid)
        {
            if (spdSearchLotList_Sheet1.Cells[iRow, 0].Value.ToString().ToUpper() == "TRUE" && spdSearchLotList_Sheet1.Cells[iRow, 1].Text.Replace(" ", "").Length != 0 && spdSearchLotList_Sheet1.Cells[iRow, 2].Text.Replace(" ", "").Length != 0 && spdSearchLotList_Sheet1.Cells[iRow, 3].Text.Replace(" ", "").Length != 0 && DeleteLotHistiry2(spdSearchLotList_Sheet1.Cells[iRow, 1].Text, MPCF.ToInt(spdSearchLotList_Sheet1.Cells[iRow, 3].Text), iRow))
            {
                MPCF.ShowMsgBox("Retrn Coplete Success: " + sLotid);
            }
        }

        private void LotSearchData(string sLotId)
        {
            try
            {
                switch (tabControl1.SelectedIndex)
                {
                    case 0:
                        if (LotOverlapCheck(sLotId))
                        {
                            SheetView activeSheet = spdSearchLotList.ActiveSheet;
                            if (activeSheet.Cells[activeSheet.RowCount - 1, 1].Text != "")
                            {
                                activeSheet.RowCount++;
                            }
                            activeSheet.Cells[activeSheet.RowCount - 1, 1].Text = sLotId;
                            activeSheet.Cells[activeSheet.RowCount - 1, 0].Value = true;
                            activeSheet.ActiveRowIndex = activeSheet.RowCount - 1;
                            if (!ViewLotHistory(activeSheet.Cells[activeSheet.RowCount - 1, 1].Text, activeSheet.ActiveRowIndex))
                            {
                            }
                            activeSheet.RowCount++;
                        }
                        break;
                    case 1:
                        if (LotOverlapCheck2(sLotId))
                        {
                            SheetView activeSheet = spdJudgeLot.ActiveSheet;
                            if (activeSheet.Cells[activeSheet.RowCount - 1, 1].Text != "")
                            {
                                activeSheet.RowCount++;
                            }
                            activeSheet.Cells[activeSheet.RowCount - 1, 1].Text = sLotId;
                            activeSheet.Cells[activeSheet.RowCount - 1, 0].Value = true;
                            activeSheet.ActiveRowIndex = activeSheet.RowCount - 1;
                            ViewLotInfo(activeSheet.Cells[activeSheet.RowCount - 1, 1].Text, activeSheet.RowCount - 1);
                            activeSheet.RowCount++;
                        }
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmTranDeleteLotHistory_NEW_Load(object sender, EventArgs e)
        {
            try
            {
                MPCF.FitColumnHeader(spdLotList);
                if (MPGV.gcLanguage == '2')
                {
                    txtWaitComment.Text = "1. 공정 생산실적 리턴화면입니다.\r\n2. 자재투입, 포장, 출고 등 관련 이력이 있으면 리턴 불가합니다.\r\n3. 리턴 후 재처리는 최소 10분 후 진행해야 합니다 (ERP 인터페이스 시간).\r\n4. 검사 공정에서는 리턴이 불가능합니다.\r\n5. 당월 실적만 리턴 가능합니다.";
                }
                else
                {
                    txtWaitComment.Text = "1. This is the production performance return screen.\r\n2.Returns are not possible if there are related histories like material input, packaging, or shipments after completion.\r\n3.Wait at least 10 minutes before reprocessing (ERP interface time).\r\n4.Returns are not possible on the inspection screen.\r\n5.Only the current month's performance can be returned.";
                }
                if (g_popYn == "Y")
                {
                    txtLotID.Text = g_LotId;
                    LotSearchData(txtLotID.Text);
                    txtOrderId.Text = "";
                    txtLotID.Text = "";
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
                if (e.KeyChar == '\r')
                {
                    LotSearchData(txtLotID.Text);
                    txtOrderId.Text = "";
                    txtLotID.Text = "";
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
        }

        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                int num = 0;
                int num2 = 0;
                switch (tabControl1.SelectedIndex)
                {
                    case 0:
                        {
                            if (MPCF.ShowMsgBox(MPCF.GetMessage(614), MessageBoxButtons.YesNo, 2) == DialogResult.No)
                            {
                                break;
                            }
                            if (sReturnPermission != "Y")
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(617));
                                break;
                            }
                            for (int j = 0; j < spdSearchLotList.ActiveSheet.RowCount - 1; j++)
                            {
                                if (spdSearchLotList_Sheet1.Cells[j, 0].Value.ToString().ToUpper() == "TRUE" && spdSearchLotList_Sheet1.Cells[j, 1].Text.Replace(" ", "").Length != 0 && spdSearchLotList_Sheet1.Cells[j, 2].Text.Replace(" ", "").Length != 0 && spdSearchLotList_Sheet1.Cells[j, 3].Text.Replace(" ", "").Length != 0)
                                {
                                    if (DeleteLotHistiry2(spdSearchLotList_Sheet1.Cells[j, 1].Text, MPCF.ToInt(spdSearchLotList_Sheet1.Cells[j, 3].Text), j))
                                    {
                                        num2++;
                                    }
                                    else
                                    {
                                        num++;
                                    }
                                }
                            }
                            MPCF.ShowMsgBox("Retrn Coplete Success: " + num2 + " Fail: " + num);
                            break;
                        }
                    case 1:
                        {
                            if (sQCPermission != "Y")
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(616));
                                break;
                            }
                            for (int i = 0; i < spdJudgeLot.ActiveSheet.RowCount - 1; i++)
                            {
                                if (spdJudgeLot.ActiveSheet.Cells[i, 0].Value.ToString().ToUpper() == "TRUE" && spdJudgeLot.ActiveSheet.Cells[i, 1].Text.Replace(" ", "").Length != 0 && spdJudgeLot.ActiveSheet.Cells[i, 2].Text != "SEARCH ERROR")
                                {
                                    if (UpdateLotJudge(spdJudgeLot.ActiveSheet.Cells[i, 1].Text))
                                    {
                                        spdJudgeLot.ActiveSheet.Cells[i, 2].Text = "SUCESS";
                                        spdJudgeLot.ActiveSheet.Cells[i, 5].Text = GetDescByJudge("P");
                                        num2++;
                                    }
                                    else
                                    {
                                        spdJudgeLot.ActiveSheet.Cells[i, 3].Text = "FAIL";
                                        num++;
                                    }
                                }
                            }
                            MPCF.ShowMsgBox("Change Judged Success: " + num2 + " Fail: " + num);
                            break;
                        }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdSearchLotList_Change(object sender, ChangeEventArgs e)
        {
            SheetView activeSheet = spdSearchLotList.ActiveSheet;
            if (e.Column == 1 && activeSheet.Cells[e.Row, 1].Text != "" && ViewLotHistory(activeSheet.Cells[e.Row, 1].Text, activeSheet.ActiveRowIndex))
            {
                activeSheet.Cells[e.Row, 0].Value = true;
                if (e.Row == activeSheet.RowCount - 1)
                {
                    activeSheet.RowCount++;
                }
            }
        }

        private void spdSearchLotList_KeyDown(object sender, KeyEventArgs e)
        {
            try
            {
                SheetView activeSheet = spdSearchLotList.ActiveSheet;
                if (e.Control && e.KeyCode == Keys.V)
                {
                    int num = activeSheet.ActiveRowIndex;
                    if (num < 0)
                    {
                        return;
                    }
                    string[] separator = new string[1] { "\r\n" };
                    string text = Clipboard.GetText();
                    string[] array = text.Split(separator, StringSplitOptions.None);
                    for (int i = 0; i < array.Length - 1; i++)
                    {
                        if (activeSheet.RowCount > 1000)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(510));
                            return;
                        }
                        string[] separator2 = new string[1] { "\t" };
                        string[] array2 = array[i].Split(separator2, StringSplitOptions.None);
                        if (LotOverlapCheck(array2[0].ToString().Trim()))
                        {
                            activeSheet.Cells[num, 0].Value = true;
                            activeSheet.Cells[num, 1].Value = array2[0];
                            num++;
                            if (activeSheet.RowCount - 1 < num)
                            {
                                activeSheet.RowCount++;
                            }
                        }
                    }
                    if (!ViewLotHistory(spdSearchLotList.ActiveSheet.Cells[spdSearchLotList.ActiveSheet.ActiveRowIndex, 1].Text, spdSearchLotList.ActiveSheet.ActiveRowIndex))
                    {
                    }
                }
                if (activeSheet.Cells[activeSheet.RowCount - 1, 1].Text != "")
                {
                    activeSheet.RowCount++;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
            e.Handled = true;
        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {
        }

        private void spdSearchLotList_CellClick_1(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader && e.Column == 1)
                {
                    CSCF.CheckSpreadCell(spdSearchLotList, 0, 0, b_checked: true, b_isColHeaderCheckBox: true);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_CellClick(object sender, CellClickEventArgs e)
        {
        }

        private void spdLotList_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            int num = 0;
            string text = MPCF.ToStandardTime(DateTime.Now.AddDays(0.0), "DATETIME").Substring(0, 6);
            if (spdLotList.ActiveSheet.ActiveRowIndex < 0)
            {
                return;
            }
            if (spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, 18].Text == "Y")
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(583));
                return;
            }
            if (spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, 2].Text.Replace("-", "").Substring(0, 6) != text)
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(582));
                return;
            }
            if (spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, 17].Text == "INV" && spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, 5].Text == "CV")
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(586));
                return;
            }
            spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 2].Text = "";
            spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 3].Text = "";
            spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 0].Value = false;
            for (num = 0; num < spdLotList.ActiveSheet.Rows.Count; num++)
            {
                spdLotList_Sheet1.Rows.Get(num).Font = new System.Drawing.Font("굴림", 9f, FontStyle.Regular, GraphicsUnit.Point, 129);
                if (MPCF.ToInt(spdLotList.ActiveSheet.Cells[num, 1].Text) >= MPCF.ToInt(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, 1].Text))
                {
                    if (spdLotList.ActiveSheet.Cells[num, 18].Text == "Y")
                    {
                        spdLotList.ActiveSheet.Cells[num, 0].Value = false;
                    }
                    else if (spdLotList.ActiveSheet.Cells[num, 17].Text == "INV" && spdLotList.ActiveSheet.Cells[num, 5].Text == "CV")
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(596));
                        break;
                    }
                    if (sQCPermission != "Y")
                    {
                        if (spdLotList.ActiveSheet.Cells[num, 19].Text != "NONE" && spdLotList.ActiveSheet.Cells[num, 5].Text != "END")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(598));
                            break;
                        }
                        if (spdLotList.ActiveSheet.Cells[num, 20].Text != "NONE")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(598));
                            break;
                        }
                    }
                    spdLotList.ActiveSheet.Cells[num, 0].Value = true;
                    spdLotList_Sheet1.Rows.Get(num).Font = new System.Drawing.Font("굴림", 9f, FontStyle.Bold | FontStyle.Italic | FontStyle.Strikeout, GraphicsUnit.Point, 129);
                    if (spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 2].Text.Trim().Length == 0)
                    {
                        spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 2].Text = spdLotList.ActiveSheet.Cells[num, 1].Text;
                    }
                    else if (MPCF.ToDbl(spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 2].Text) <= MPCF.ToDbl(spdLotList.ActiveSheet.Cells[num, 1].Text))
                    {
                        spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 2].Text = spdLotList.ActiveSheet.Cells[num, 1].Text;
                    }
                    if (spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 3].Text.Trim().Length == 0)
                    {
                        spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 3].Text = spdLotList.ActiveSheet.Cells[num, 1].Text;
                        spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 7].Text = spdLotList.ActiveSheet.Cells[num, 4].Text;
                        spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 8].Text = spdLotList.ActiveSheet.Cells[num, 2].Text;
                        if (MPCF.ToDbl(spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 3].Text) != 1.0)
                        {
                            spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 6].Text = spdLotList.ActiveSheet.Cells[num + 1, 4].Text;
                        }
                        else
                        {
                            spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 6].Text = "LOT DELETE";
                        }
                    }
                    else if (MPCF.ToDbl(spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 3].Text) >= MPCF.ToDbl(spdLotList.ActiveSheet.Cells[num, 1].Text))
                    {
                        spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 3].Text = spdLotList.ActiveSheet.Cells[num, 1].Text;
                        spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 7].Text = spdLotList.ActiveSheet.Cells[num, 4].Text;
                        spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 8].Text = spdLotList.ActiveSheet.Cells[num, 2].Text;
                        if (MPCF.ToDbl(spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 3].Text) != 1.0)
                        {
                            spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 6].Text = spdLotList.ActiveSheet.Cells[num + 1, 4].Text;
                        }
                        else
                        {
                            spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 6].Text = "LOT DELETE";
                        }
                    }
                }
                else
                {
                    spdLotList.ActiveSheet.Cells[num, 0].Value = false;
                }
            }
            if (spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 3].Text != "")
            {
                spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 0].Value = true;
            }
            else
            {
                spdSearchLotList.ActiveSheet.Cells[spdSearchLotList_Sheet1.ActiveRowIndex, 0].Value = false;
            }
        }

        private void spdSearchLotList_Click(object sender, EventArgs e)
        {
            try
            {
                ContextMenu contextMenu = new ContextMenu();
                System.Windows.Forms.MenuItem menuItem = new System.Windows.Forms.MenuItem();
                System.Windows.Forms.MenuItem menuItem2 = new System.Windows.Forms.MenuItem();
            }
            catch (Exception)
            {
            }
        }

        private void spdSearchLotList_MouseUp(object sender, MouseEventArgs e)
        {
            SheetView sv = spdSearchLotList.ActiveSheet;
            if (e.Button.Equals(MouseButtons.Right))
            {
                ContextMenu contextMenu = new ContextMenu();
                System.Windows.Forms.MenuItem menuItem = new System.Windows.Forms.MenuItem();
                System.Windows.Forms.MenuItem menuItem2 = new System.Windows.Forms.MenuItem();
                menuItem.Text = "List에서 Lot 삭제 (Lot List Delete)";
                menuItem2.Text = "선택한 1개 Lot Return (Select 1 Lot Return)";
                menuItem.Click += delegate
                {
                    spdSearchLotDelete(sv.ActiveRowIndex);
                };
                menuItem2.Click += delegate
                {
                    selectRowDelete(sv.ActiveRowIndex, sv.Cells[sv.ActiveRowIndex, 1].Text);
                };
                contextMenu.MenuItems.Add(menuItem);
                contextMenu.MenuItems.Add(menuItem2);
                contextMenu.Show(spdSearchLotList, e.Location);
            }
        }

        private void spdSearchLotDelete(int iRow)
        {
            try
            {
                if (iRow == 0)
                {
                    spdSearchLotList.ActiveSheet.RowCount++;
                    return;
                }
                spdSearchLotList.ActiveSheet.RemoveRows(iRow, 1);
                if (spdSearchLotList.ActiveSheet.Cells[spdSearchLotList.ActiveSheet.ActiveRowIndex, 1].Text != "")
                {
                    spdSearchLotList.ActiveSheet.RowCount++;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdSearchLotDelete2(int iRow)
        {
            try
            {
                if (iRow == 0)
                {
                    spdJudgeLot.ActiveSheet.RowCount++;
                    return;
                }
                spdJudgeLot.ActiveSheet.RemoveRows(iRow, 1);
                if (spdJudgeLot.ActiveSheet.Cells[spdJudgeLot.ActiveSheet.ActiveRowIndex, 1].Text != "")
                {
                    spdJudgeLot.ActiveSheet.RowCount++;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdSearchLotList_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            try
            {
                string text = spdSearchLotList.ActiveSheet.Cells[spdSearchLotList.ActiveSheet.ActiveRowIndex, 1].Text;
                if (text.Trim() != "" && ViewLotHistory(text, spdSearchLotList.ActiveSheet.ActiveRowIndex))
                {
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                MPCF.ClearList(spdLotList);
                MPCF.ClearList(spdSearchLotList);
                MPCF.ClearList(spdJudgeLot);
                spdLotList.ActiveSheet.RowCount++;
                spdJudgeLot.ActiveSheet.RowCount++;
                spdSearchLotDelete(0);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdSearchLotList_EditChange(object sender, EditorNotifyEventArgs e)
        {
        }

        private void spdSearchLotList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            SheetView activeSheet = spdSearchLotList.ActiveSheet;
            if (e.Column == 0)
            {
                if (activeSheet.Cells[e.Row, 0].Value.ToString().ToUpper() != "TRUE")
                {
                    activeSheet.Cells[e.Row, 5].Text = "";
                    activeSheet.Cells[e.Row, 3].Text = "";
                    activeSheet.Cells[e.Row, 2].Text = "";
                    activeSheet.Cells[e.Row, 4].Text = "";
                    activeSheet.Cells[e.Row, 6].Text = "";
                    activeSheet.Cells[e.Row, 7].Text = "";
                    activeSheet.Cells[e.Row, 8].Text = "";
                }
                else if (activeSheet.Cells[e.Row, 2].Text == "" || activeSheet.Cells[e.Row, 3].Text == "")
                {
                    activeSheet.Cells[e.Row, 0].Value = false;
                }
                ViewLotHistory(spdSearchLotList.ActiveSheet.Cells[e.Row, 1].Text, e.Row);
            }
        }

        private void txtOrderId_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar != '\r')
                {
                    return;
                }
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[7];
               System.Data.DataTable  dt = null;
                string sSql = "";
                int num = 0;
                SheetView activeSheet = spdSearchLotList.ActiveSheet;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "AREA_ID";
                array[1].sCondition_Value = "";
                array[2].sCondition_ID = "SUB_AREA_ID";
                array[2].sCondition_Value = "";
                array[3].sCondition_ID = "OPER";
                array[3].sCondition_Value = "";
                array[4].sCondition_ID = "ORDER_ID";
                array[4].sCondition_Value = txtOrderId.Text;
                array[5].sCondition_ID = "RES_ID";
                array[5].sCondition_Value = "";
                array[6].sCondition_ID = "LOT_ID";
                array[6].sCondition_Value = "";
                if (!TPDR.GetDataOne("", ref dt, "CCOM3002-001", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    return;
                }
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    LotSearchData(dt.Rows[num]["LOT_ID"].ToString());
                }
                txtLotID.Text = "";
                txtOrderId.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdJudgeLot_KeyDown(object sender, KeyEventArgs e)
        {
            try
            {
                SheetView activeSheet = spdJudgeLot.ActiveSheet;
                if (e.Control && e.KeyCode == Keys.V)
                {
                    int num = activeSheet.ActiveRowIndex;
                    if (num < 0)
                    {
                        return;
                    }
                    string[] separator = new string[1] { "\r\n" };
                    string text = Clipboard.GetText();
                    string[] array = text.Split(separator, StringSplitOptions.None);
                    for (int i = 0; i < array.Length - 1; i++)
                    {
                        if (activeSheet.RowCount > 1000)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(510));
                            return;
                        }
                        string[] separator2 = new string[1] { "\t" };
                        string[] array2 = array[i].Split(separator2, StringSplitOptions.None);
                        if (LotOverlapCheck2(array2[0].ToString().Trim()))
                        {
                            activeSheet.Cells[num, 0].Value = true;
                            activeSheet.Cells[num, 1].Value = array2[0];
                            ViewLotInfo(array2[0], num);
                            num++;
                            if (activeSheet.RowCount - 1 < num)
                            {
                                activeSheet.RowCount++;
                            }
                        }
                    }
                }
                if (activeSheet.Cells[activeSheet.RowCount - 1, 1].Text != "")
                {
                    activeSheet.RowCount++;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
            e.Handled = true;
        }

        private void btnJudgeSearch_Click(object sender, EventArgs e)
        {
            try
            {
                for (int i = 0; i < spdJudgeLot.ActiveSheet.Rows.Count; i++)
                {
                    ViewLotInfo(spdJudgeLot.ActiveSheet.Cells[i, 1].Text, i);
                }
            }
            catch (Exception)
            {
            }
        }

        private void spdJudgeLot_EditModeOff(object sender, EventArgs e)
        {
            if (spdJudgeLot.ActiveSheet.ActiveColumnIndex == 1)
            {
                ViewLotInfo(spdJudgeLot.ActiveSheet.Cells[spdJudgeLot.ActiveSheet.ActiveRowIndex, 1].Text, spdJudgeLot.ActiveSheet.ActiveRowIndex);
                spdLotList.ActiveSheet.RowCount++;
            }
        }

        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (tabControl1.SelectedIndex)
            {
                case 0:
                    btnJudgeSearch.Visible = false;
                    break;
                case 1:
                    btnJudgeSearch.Visible = true;
                    break;
            }
        }









    }
}
