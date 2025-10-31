using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Miracom.CliFrx;
using CUS_COM;
using Miracom.DNMCore;
using Miracom.MESCore;
using Miracom.TRSCore;

namespace CUS_WIP
{
    public partial class frmWIPViewPressYieldStatus : CUS_COM.frmViewForm01
    {

        #region " Variable Definition "
        public string res_id = string.Empty;
        public string res_no = string.Empty;
        public char loss_yn = 'A'; // ALL

        #endregion

        public frmWIPViewPressYieldStatus()
        {
            InitializeComponent();
        }



        private void View_Press()
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[10];
                DataTable dt = null;
                string text = "";
                text = ((!chkQcSearch.Checked) ? "CWIP3016-005" : "CWIP3016-001");
                string sSql = "";
                int num = 0;
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "AREA_ID";
                array[1].sCondition_Value = CSGV.gs_area_ctm;
                array[2].sCondition_ID = "LOTID";
                array[2].sCondition_Value = MPCF.Trim(txtLotID.Text);
                array[3].sCondition_ID = "MATID";
                array[3].sCondition_Value = MPCF.Trim(cdvMatID.Text);
                array[4].sCondition_ID = "FROMDATE";
                array[4].sCondition_Value = dtpFromDate.Value.ToString("yyyyMMdd");
                array[5].sCondition_ID = "TODATE";
                array[5].sCondition_Value = dtpToDate.Value.ToString("yyyyMMdd");
                array[6].sCondition_ID = "MATDESC";
                array[6].sCondition_Value = MPCF.Trim(txtMat.Text);
                array[7].sCondition_ID = "RESID";
                array[7].sCondition_Value = cdvResID.Text;
                array[8].sCondition_ID = "CAR";
                array[8].sCondition_Value = cdvCar.Text;
                array[9].sCondition_ID = "LOSSYN";
                array[9].sCondition_Value = loss_yn;
                if (!TPDR.GetDataOne("", ref dt, text, array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdYieldList);
                    return;
                }
                spdYieldList_sheet1.ColumnCount = 29;
                MPCF.ClearList(spdYieldList);
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdYieldList_sheet1.RowCount++;
                    spdYieldList_sheet1.Cells[num, 0].Value = dt.Rows[num]["RES_ID"];
                    spdYieldList_sheet1.Cells[num, 1].Value = dt.Rows[num]["RES_NO"];
                    spdYieldList_sheet1.Cells[num, 2].Value = dt.Rows[num]["CAR"];
                    spdYieldList_sheet1.Cells[num, 3].Value = dt.Rows[num]["ORDER_ID"];
                    spdYieldList_sheet1.Cells[num, 4].Value = dt.Rows[num]["LOT_ID"];
                    spdYieldList_sheet1.Cells[num, 5].Value = dt.Rows[num]["MAT_ID"];
                    spdYieldList_sheet1.Cells[num, 6].Value = dt.Rows[num]["MAT_DESC"];
                    spdYieldList_sheet1.Cells[num, 7].Value = dt.Rows[num]["WORK_DATE"];
                    spdYieldList_sheet1.Cells[num, 8].Value = dt.Rows[num]["LOSS_YN"];
                    spdYieldList_sheet1.Cells[num, 9].Value = dt.Rows[num]["PR_LOSS_NAME"];
                    spdYieldList_sheet1.Cells[num, 10].Value = dt.Rows[num]["CELL_WEIGHT"];
                    spdYieldList_sheet1.Cells[num, 11].Value = dt.Rows[num]["CELL_HEIGHT"];
                    spdYieldList_sheet1.Cells[num, 12].Value = dt.Rows[num]["PROFILE_ID"];
                    spdYieldList_sheet1.Cells[num, 13].Value = dt.Rows[num]["SET_VOLTAGE"];
                    spdYieldList_sheet1.Cells[num, 14].Value = dt.Rows[num]["SET_POWER_1"];
                    spdYieldList_sheet1.Cells[num, 15].Value = dt.Rows[num]["SET_POWER_2"];
                    spdYieldList_sheet1.Cells[num, 16].Value = dt.Rows[num]["SET_POWER_3"];
                    spdYieldList_sheet1.Cells[num, 17].Value = dt.Rows[num]["TRAN_COMMENT"];
                    spdYieldList_sheet1.Cells[num, 18].Value = dt.Rows[num]["LP_ISP_RST_DESC"];
                    spdYieldList_sheet1.Cells[num, 19].Value = dt.Rows[num]["RD_ISP_RST_DESC"];
                    spdYieldList_sheet1.Cells[num, 20].Value = dt.Rows[num]["LP_ISP_RST"];
                    spdYieldList_sheet1.Cells[num, 21].Value = dt.Rows[num]["RD_ISP_RST"];
                    spdYieldList_sheet1.Cells[num, 22].Value = dt.Rows[num]["MAT_ID"];
                    spdYieldList_sheet1.Cells[num, 23].Value = dt.Rows[num]["LP_LOSS_NAME"];
                    spdYieldList_sheet1.Cells[num, 24].Value = dt.Rows[num]["RD_LOSS_NAME"];
                    spdYieldList_sheet1.Cells[num, 25].Value = dt.Rows[num]["LP_RWK_COUNT"];
                    spdYieldList_sheet1.Cells[num, 26].Value = dt.Rows[num]["RD_RWK_COUNT"];
                }
                MPCF.FitColumnHeader(spdYieldList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void View_BOM()
        {
            try
            {
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[10];
                DataTable dt = null;
                string viewID = "CWIP3016-003";
                string sSql = "";
                string text = "";
                int num = 0;
                int num2 = 0;
                int num3 = 0;
                StringBuilder stringBuilder = new StringBuilder();
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "AREA_ID";
                array[1].sCondition_Value = CSGV.gs_area_ctm;
                array[2].sCondition_ID = "LOTID";
                array[2].sCondition_Value = MPCF.Trim(txtLotID.Text);
                array[3].sCondition_ID = "MATID";
                array[3].sCondition_Value = MPCF.Trim(cdvMatID.Text);
                array[4].sCondition_ID = "FROMDATE";
                array[4].sCondition_Value = dtpFromDate.Value.ToString("yyyyMMdd");
                array[5].sCondition_ID = "TODATE";
                array[5].sCondition_Value = dtpToDate.Value.ToString("yyyyMMdd");
                array[6].sCondition_ID = "MATDESC";
                array[6].sCondition_Value = MPCF.Trim(txtMat.Text);
                array[7].sCondition_ID = "RESID";
                array[7].sCondition_Value = cdvResID.Text;
                array[8].sCondition_ID = "CAR";
                array[8].sCondition_Value = cdvCar.Text;
                array[9].sCondition_ID = "LOSSYN";
                array[9].sCondition_Value = loss_yn;
                if (!TPDR.GetDataOne("", ref dt, viewID, array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdYieldList);
                    return;
                }
                spdYieldList_sheet1.ColumnCount = 29;
                num3 = spdYieldList_sheet1.ColumnCount;
                for (num = 0; num < dt.Rows.Count; num++)
                {
                    spdYieldList_sheet1.ColumnCount++;
                    spdYieldList_sheet1.ColumnHeader.Cells.Get(0, spdYieldList_sheet1.ColumnCount - 1).Value = dt.Rows[num]["MAT_DESC"];
                    spdYieldList_sheet1.Columns[spdYieldList_sheet1.ColumnCount - 1].Width = 200f;
                    spdYieldList_sheet1.ColumnCount++;
                    spdYieldList_sheet1.ColumnHeader.Cells.Get(0, spdYieldList_sheet1.ColumnCount - 1).Value = dt.Rows[num]["MAT_DESC"];
                    spdYieldList_sheet1.Columns[spdYieldList_sheet1.ColumnCount - 1].Width = 200f;
                    spdYieldList_sheet1.ColumnHeader.Cells.Get(0, spdYieldList_sheet1.ColumnCount - 2).ColumnSpan = 2;
                    text = text + " ,MAX(CASE WHEN TB.MAT_DESC ='" + dt.Rows[num]["MAT_DESC"].ToString() + "' THEN TB.INV_LOT_ID ELSE '' END) AS BOM" + num + "\r\n";
                    text = text + " ,MAX(CASE WHEN TB.MAT_DESC ='" + dt.Rows[num]["MAT_DESC"].ToString() + "' THEN TB.INV_INPUT_DATE ELSE null END) AS BOM_TIME" + num + "\r\n";
                }
                TPDR.DirectViewCond[] array2 = new TPDR.DirectViewCond[11];
                DataTable dt2 = null;
                viewID = "CWIP3016-004";
                sSql = "";
                num = 0;
                num2 = 0;
                array2[0].sCondition_ID = "FACTORY";
                array2[0].sCondition_Value = MPGV.gsFactory;
                array2[1].sCondition_ID = "AREA_ID";
                array2[1].sCondition_Value = CSGV.gs_area_ctm;
                array2[2].sCondition_ID = "LOTID";
                array2[2].sCondition_Value = MPCF.Trim(txtLotID.Text);
                array2[3].sCondition_ID = "MATID";
                array2[3].sCondition_Value = MPCF.Trim(cdvMatID.Text);
                array2[4].sCondition_ID = "FROMDATE";
                array2[4].sCondition_Value = dtpFromDate.Value.ToString("yyyyMMdd");
                array2[5].sCondition_ID = "TODATE";
                array2[5].sCondition_Value = dtpToDate.Value.ToString("yyyyMMdd");
                array2[6].sCondition_ID = "MATDESC";
                array2[6].sCondition_Value = MPCF.Trim(txtMat.Text);
                array2[7].sCondition_ID = "RESID";
                array2[7].sCondition_Value = cdvResID.Text;
                array2[8].sCondition_ID = "CAR";
                array2[8].sCondition_Value = cdvCar.Text;
                array2[9].sCondition_ID = "LOSSYN";
                array2[9].sCondition_Value = loss_yn;
                array2[10].sCondition_ID = "QUERY";
                array2[10].sCondition_Type = "TEXT";
                array2[10].sCondition_Value = text;
                if (!TPDR.GetDataOne("", ref dt2, viewID, array2, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt2?.Dispose();
                    GC.Collect();
                    MPCF.ClearList(spdYieldList);
                    return;
                }
                MPCF.ClearList(spdYieldList);
                for (num = 0; num < dt2.Rows.Count; num++)
                {
                    spdYieldList_sheet1.RowCount++;
                    spdYieldList_sheet1.Cells[num, 0].Value = dt2.Rows[num]["RES_ID"];
                    spdYieldList_sheet1.Cells[num, 1].Value = dt2.Rows[num]["RES_NO"];
                    spdYieldList_sheet1.Cells[num, 2].Value = dt2.Rows[num]["CAR"];
                    spdYieldList_sheet1.Cells[num, 3].Value = dt2.Rows[num]["ORDER_ID"];
                    spdYieldList_sheet1.Cells[num, 4].Value = dt2.Rows[num]["LOT_ID"];
                    spdYieldList_sheet1.Cells[num, 5].Value = dt2.Rows[num]["MAT_ID"];
                    spdYieldList_sheet1.Cells[num, 6].Value = dt2.Rows[num]["MAT_DESC"];
                    spdYieldList_sheet1.Cells[num, 7].Value = dt2.Rows[num]["WORK_DATE"];
                    spdYieldList_sheet1.Cells[num, 8].Value = dt2.Rows[num]["LOSS_YN"];
                    spdYieldList_sheet1.Cells[num, 9].Value = dt2.Rows[num]["PR_LOSS_NAME"];
                    spdYieldList_sheet1.Cells[num, 10].Value = dt2.Rows[num]["CELL_WEIGHT"];
                    spdYieldList_sheet1.Cells[num, 11].Value = dt2.Rows[num]["CELL_HEIGHT"];
                    spdYieldList_sheet1.Cells[num, 12].Value = dt2.Rows[num]["PROFILE_ID"];
                    spdYieldList_sheet1.Cells[num, 13].Value = dt2.Rows[num]["SET_VOLTAGE"];
                    spdYieldList_sheet1.Cells[num, 14].Value = dt2.Rows[num]["SET_POWER_1"];
                    spdYieldList_sheet1.Cells[num, 15].Value = dt2.Rows[num]["SET_POWER_2"];
                    spdYieldList_sheet1.Cells[num, 16].Value = dt2.Rows[num]["SET_POWER_3"];
                    spdYieldList_sheet1.Cells[num, 17].Value = dt2.Rows[num]["TRAN_COMMENT"];
                    spdYieldList_sheet1.Cells[num, 18].Value = dt2.Rows[num]["LP_ISP_RST_DESC"];
                    spdYieldList_sheet1.Cells[num, 19].Value = dt2.Rows[num]["RD_ISP_RST_DESC"];
                    spdYieldList_sheet1.Cells[num, 20].Value = dt2.Rows[num]["LP_ISP_RST"];
                    spdYieldList_sheet1.Cells[num, 21].Value = dt2.Rows[num]["RD_ISP_RST"];
                    spdYieldList_sheet1.Cells[num, 22].Value = dt2.Rows[num]["MAT_ID"];
                    spdYieldList_sheet1.Cells[num, 23].Value = dt2.Rows[num]["LP_LOSS_NAME"];
                    spdYieldList_sheet1.Cells[num, 24].Value = dt2.Rows[num]["RD_LOSS_NAME"];
                    spdYieldList_sheet1.Cells[num, 25].Value = dt2.Rows[num]["LP_RWK_COUNT"];
                    spdYieldList_sheet1.Cells[num, 26].Value = dt2.Rows[num]["RD_RWK_COUNT"];
                    spdYieldList_sheet1.Cells[num, 27].Value = dt2.Rows[num]["UP_LOT_ID_1"];
                    spdYieldList_sheet1.Cells[num, 28].Value = dt2.Rows[num]["UP_LOT_ID_2"];
                    for (num2 = num3; num2 < spdYieldList_sheet1.ColumnCount; num2++)
                    {
                        spdYieldList_sheet1.Cells[num, num2].Value = dt2.Rows[num][num2 - 1];
                        if (spdYieldList_sheet1.ColumnHeader.Cells.Get(0, num2).ColumnSpan == 2)
                        {
                            spdYieldList_sheet1.Cells[num, num2].BackColor = Color.WhiteSmoke;
                        }
                        else
                        {
                            spdYieldList_sheet1.Cells[num, num2].BackColor = Color.FloralWhite;
                        }
                    }
                }
                MPCF.FitColumnHeader(spdYieldList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool PressJudgeNgchange(string sLotId, string sBadCode, char cNextOperFlag)
        {
            try
            {
                if (spdYieldList_sheet1.Cells[spdYieldList_sheet1.ActiveRowIndex, 8].Text != "N")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(594));
                    return false;
                }
                if (cNextOperFlag == 'Y')
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(599));
                    return false;
                }
                if (spdYieldList_sheet1.Cells[spdYieldList_sheet1.ActiveRowIndex, 7].Text.Substring(0, 7) != DateTime.Now.ToString("yyyy-MM"))
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(593));
                    return false;
                }
                if (MPCF.ShowMsgBox(spdYieldList_sheet1.Cells[spdYieldList_sheet1.ActiveRowIndex, 4].Text + MPCF.GetMessage(595), MessageBoxButtons.YesNo, 2) != DialogResult.Yes)
                {
                    return false;
                }
                TPDR.DirectViewCond[] array = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                array[0].sCondition_ID = "FACTORY";
                array[0].sCondition_Value = MPGV.gsFactory;
                array[1].sCondition_ID = "LOT_ID";
                array[1].sCondition_Value = sLotId;
                array[2].sCondition_ID = "BAD_CODE";
                array[2].sCondition_Value = sBadCode;
                if (!TPDR.GetDataOne("", ref dt, "CWIP3016-006", array, bIcon: false, bBGColor: false, ref sSql))
                {
                    dt?.Dispose();
                    GC.Collect();
                    return false;
                }
                MPCF.ShowMsgBox(MPCF.GetMessage(52));
                View_Press();
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void frmWIPViewPressYieldStatus_Load(object sender, EventArgs e)
        {
            try
            {
                dtpFromDate.Value = DateTime.Now.AddDays(-7.0);
                dtpToDate.Value = DateTime.Now;
                cboxProdFlag.Items.Add("ALL");
                cboxProdFlag.Items.Add("Y");
                cboxProdFlag.Items.Add("N");
                cboxProdFlag.SelectedIndex = 0;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvResID_ButtonPress(object sender, EventArgs e)
        {
            string gs_area_ctm = CSGV.gs_area_ctm;
            try
            {
                cdvResID.Init();
                MPCF.InitListView(cdvResID.GetListView);
                cdvResID.Columns.Add("Key_1", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvResID.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvResID.Columns.Add("Count", 0, System.Windows.Forms.HorizontalAlignment.Left);
                cdvResID.SelectedSubItemIndex = 0;
                cdvResID.DisplaySubItemIndex = 1;
                if (COM_LIST.ViewResourceListByGroup(cdvResID.GetListView, "E002", gs_area_ctm))
                {
                    cdvResID.InsertEmptyRow(0, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            if (chkBomSearch.Checked)
            {
                View_BOM();
            }
            else
            {
                View_Press();
            }
        }

        private void cdvCar_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvCar.Init();
                MPCF.InitListView(cdvCar.GetListView);
                cdvCar.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvCar.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                if (BASLIST.ViewGCMDataList(cdvCar.GetListView, '1', "C_CAR"))
                {
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cboxLossYN_SelectedIndexChanged(object sender, EventArgs e)
        {
            loss_yn = cboxProdFlag.Text[0];
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                string empty = string.Empty;
                empty = "Press Yield Status";
                EXTFUC.SaveExcel(spdYieldList, empty);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvMatID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList frmPopMaterialList = new frmPopMaterialList();
                frmPopMaterialList.StartPosition = FormStartPosition.CenterParent;
                frmPopMaterialList.sArea_id = CSGV.gs_area_ctm;
                frmPopMaterialList.sArea_desc = CSGV.gs_area_ctm;
                if (frmPopMaterialList.ShowDialog() == DialogResult.OK)
                {
                    cdvMatID.Text = frmPopMaterialList.sMat_id;
                    frmPopMaterialList = null;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdYieldList_MouseUp(object sender, MouseEventArgs e)
        {
            if (spdYieldList_sheet1.RowCount == 0 || !e.Button.Equals(MouseButtons.Right) || !e.Button.Equals(MouseButtons.Right))
            {
                return;
            }
            ContextMenuStrip contextMenuStrip = new ContextMenuStrip();
            string text = MPCF.FindLanguage("Ok->NG Change", 2);
            ToolStripMenuItem toolStripMenuItem = new ToolStripMenuItem(text);
            TRSNode tRSNode = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            string sLotId = "";
            sLotId = spdYieldList.ActiveSheet.Cells[spdYieldList_sheet1.ActiveRowIndex, 4].Text;
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = '1';
            StringBuilder stringBuilder = new StringBuilder();
            stringBuilder.Append("SELECT * FROM ");
            stringBuilder.Append("(SELECT TO_CHAR(COUNT(*)) AS LOSS_CODE, ' ' AS LOSS_DESC, '0' AS SEQ FROM MWIPLOTHIS WHERE LOT_ID ='" + sLotId + "' AND HIST_DEL_FLAG <>'Y' UNION ALL  ");
            stringBuilder.Append(" SELECT A.KEY_2 AS LOSS_CODE, ");
            stringBuilder.Append("          C.DATA_1 AS LOSS_DESC, ");
            stringBuilder.Append("           replace(A.DATA_1,' ','999') AS SEQ");
            stringBuilder.Append("     FROM MGCMTBLDAT A , MGCMTBLDAT C ");
            stringBuilder.Append(" WHERE A.FACTORY = C.FACTORY ");
            stringBuilder.Append("                                 AND A.KEY_2 = C.KEY_1 ");
            stringBuilder.Append("                                 AND C.TABLE_NAME = 'LOSS_CODE' ");
            stringBuilder.Append("     AND A.FACTORY = '" + MPGV.gsFactory + "'");
            stringBuilder.Append("     AND A.TABLE_NAME = 'C_OPER_LOSS' ");
            stringBuilder.AppendLine("     AND A.KEY_1 = 'OC03160' )");
            stringBuilder.Append(" ORDER BY TO_NUMBER(SEQ)");
            tRSNode.AddString("SQL", stringBuilder.ToString());
            if (!MPCR.CallService("BAS", "BAS_SQL_Query", tRSNode, ref out_node))
            {
                return;
            }
            if (out_node.GetList("ROWS").Count > 0)
            {
                char cNextOperFlag = 'N';
                if (out_node.GetList("ROWS")[0].GetList("COLS")[0].GetString("DATA") != "1")
                {
                    cNextOperFlag = 'Y';
                }
                for (int i = 1; i < out_node.GetList("ROWS").Count; i++)
                {
                    int currentIndex = i;
                    ToolStripMenuItem toolStripMenuItem2 = new ToolStripMenuItem($"Option {currentIndex}");
                    toolStripMenuItem2.Tag = out_node.GetList("ROWS")[currentIndex].GetList("COLS")[0].GetString("DATA");
                    toolStripMenuItem2.Text = out_node.GetList("ROWS")[currentIndex].GetList("COLS")[1].GetString("DATA");
                    toolStripMenuItem2.Click += delegate
                    {
                        PressJudgeNgchange(sLotId, out_node.GetList("ROWS")[currentIndex].GetList("COLS")[0].GetString("DATA"), cNextOperFlag);
                    };
                    toolStripMenuItem.DropDownItems.Add(toolStripMenuItem2);
                }
            }
            ToolStripMenuItem toolStripMenuItem3 = new ToolStripMenuItem(spdYieldList.ActiveSheet.Cells[spdYieldList_sheet1.ActiveRowIndex, 4].Text);
            toolStripMenuItem3.TextAlign = ContentAlignment.MiddleCenter;
            toolStripMenuItem3.Font = new Font("Segoe UI", 13f);
            toolStripMenuItem3.ForeColor = Color.DarkRed;
            contextMenuStrip.Items.Add(toolStripMenuItem3);
            contextMenuStrip.Items.Add(toolStripMenuItem);
            contextMenuStrip.Items.Add(new ToolStripSeparator());
            string text2 = MPCF.FindLanguage("Comment Change", 2);
            ToolStripMenuItem toolStripMenuItem4 = new ToolStripMenuItem(text2);
            contextMenuStrip.Items.Add(toolStripMenuItem4);
            toolStripMenuItem4.Click += delegate
            {
                ShowCommentPopup(spdYieldList, e.Location);
            };
            contextMenuStrip.Show(spdYieldList, e.Location);
        }

        private void ShowCommentPopup(Control parent, Point location)
        {
            string text = MPCF.FindLanguage("No input needed (CELL_ID auto)", 2);
            ToolStripDropDown dropDown = new ToolStripDropDown();
            dropDown.AutoClose = true;
            Panel panel = new Panel();
            panel.Size = new Size(220, 110);
            Label label = new Label();
            label.AutoSize = false;
            label.Size = new Size(200, 30);
            label.Location = new Point(10, 5);
            label.Text = text;
            label.TextAlign = ContentAlignment.MiddleLeft;
            label.AutoEllipsis = true;
            label.Font = new Font("Segoe UI", 9f);
            label.ForeColor = Color.DarkRed;
            TextBox txtComment = new TextBox();
            txtComment.Size = new Size(200, 20);
            txtComment.Location = new Point(10, 40);
            Button button = new Button();
            button.Text = "Save";
            button.Size = new Size(200, 25);
            button.Location = new Point(10, 70);
            panel.Controls.Add(label);
            panel.Controls.Add(txtComment);
            panel.Controls.Add(button);
            ToolStripControlHost toolStripControlHost = new ToolStripControlHost(panel);
            toolStripControlHost.Margin = Padding.Empty;
            toolStripControlHost.Padding = Padding.Empty;
            toolStripControlHost.AutoSize = false;
            toolStripControlHost.Size = panel.Size;
            dropDown.Items.Add(toolStripControlHost);
            button.Click += delegate
            {
                string comment = txtComment.Text;
                dropDown.Close();
                commentChange(comment);
            };
            dropDown.Show(parent, location);
            txtComment.Focus();
        }

        public void commentChange(string comment)
        {
            TRSNode tRSNode = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");
            string text = spdYieldList.ActiveSheet.Cells[spdYieldList_sheet1.ActiveRowIndex, 4].Text;
            MPCR.SetInMsg(tRSNode);
            tRSNode.ProcStep = '1';
            StringBuilder stringBuilder = new StringBuilder();
            if (comment.Length == 0)
            {
                if (MPCF.ShowMsgBox(MPCF.GetMessage(613), MessageBoxButtons.YesNo, 2) != DialogResult.Yes)
                {
                    return;
                }
                comment = " ";
            }
            stringBuilder.Append("SELECT F_CTM_PRESS_COMMENT_CHANGE('" + text + "', '" + comment + "') FROM DUAL ");
            tRSNode.AddString("SQL", stringBuilder.ToString());
            if (MPCR.CallService("BAS", "BAS_SQL_Query", tRSNode, ref out_node) && out_node.GetList("ROWS").Count > 0)
            {
                spdYieldList.ActiveSheet.Cells[spdYieldList_sheet1.ActiveRowIndex, 17].Text = out_node.GetList("ROWS")[0].GetList("COLS")[0].GetString("DATA");
            }
        }

        public static DataTable ConvertRow2Col(DataTable Source, DataColumn StardardColumn, Type DataType)
        {
            DataTable dataTable = new DataTable();
            DataColumn column = new DataColumn(Source.Columns[0].ColumnName, Type.GetType("System.String"));
            dataTable.Columns.Add(column);
            DataColumn column2 = null;
            foreach (DataRow row in Source.Rows)
            {
                if (!(StardardColumn.DataType == Type.GetType("System.DateTime")))
                {
                    column2 = new DataColumn(row[2].ToString(), Type.GetType("System.String"));
                }
                if (!dataTable.Columns.Contains(row[2].ToString()))
                {
                    dataTable.Columns.Add(column2);
                }
            }
            dataTable.PrimaryKey = new DataColumn[1] { dataTable.Columns[0] };
            foreach (DataRow row2 in Source.Rows)
            {
                DataRow dataRow3 = dataTable.NewRow();
                dataRow3[0] = new DataColumn(row2[0].ToString(), Type.GetType("System.String"));
                if (dataTable.Rows.Find(row2[0].ToString()) == null)
                {
                    dataTable.Rows.Add(dataRow3);
                }
            }
            for (int i = 0; i < dataTable.Columns.Count; i++)
            {
                for (int j = 0; j < Source.Rows.Count; j++)
                {
                    DataRow dataRow4 = dataTable.Rows.Find(Source.Rows[j][0]);
                    if (dataTable.Columns[i].ColumnName.ToString() == Source.Rows[j][2].ToString())
                    {
                        dataRow4 = dataTable.Rows.Find(Source.Rows[j][0]);
                        dataRow4[i] = Source.Rows[j][1];
                    }
                }
            }
            dataTable.AcceptChanges();
            return dataTable;
        }




    }
}
