using CUS_COM;
using Miracom.CliFrx;
using Miracom.DNMCore;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CUS_WIP
{
    public partial class frmTranAddNotInputMaterial : frmTranForm06
    {




        public frmTranAddNotInputMaterial()
        {
            InitializeComponent();
            InitControl();
        }

        #region " Constant Definition "

        private enum LOT_INFO
        {
            ORDER_ID,
            ORD_STATUS,
            WORK_DATE,
            MAT_ID,
            MAT_DESC,
            UNIT,
            AREA_ID,
            SUB_AREA_ID,
            ORDER_QTY,
            LOT_ID,
            OPER_SEQ,
            ERP_OPER,
            ERP_OPER_DESC,
            OPER,
            OPER_DESC,
            LOT_QTY,
            ERP_MAT_COUNT,
            ISSUE_MAT_COUNT,
            INV_BUTTON
        }

        private enum BOM_INFO
        {
            ORDER_ID,
            LOT_ID,
            OPER_SEQ,
            ERP_OPER,
            OPER,
            OPER_DESC,
            ISSUE_DATE,
            INV_LOT_ID,
            MAT_ID,
            MAT_DESC,
            UNIT_USE_QTY,
            TOTAL_USE_QTY,
            ISSUE_QTY,
            UNIT,
            INV_OPER,
            INV_OPER_DESC
        }

        #endregion

        #region " Variable Definition "


        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool ViewLotList()
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[9];
            DataTable dt = null;
            string sSql = "";
            int i = 0;
            string s_view_id = "";

            try
            {
                //spdLotList_Sheet1.RowCount = 0;

                MPCF.ClearList(spdLotList);
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMat.Text;

                dvcArgu[3].sCondition_ID = "MAT_DESC";
                dvcArgu[3].sCondition_Value = txtMatDesc.Text;

                dvcArgu[4].sCondition_ID = "LOT_ID";
                dvcArgu[4].sCondition_Value = txtLotID.Text;

                dvcArgu[5].sCondition_ID = "FROM_DATE";
                dvcArgu[5].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text.Replace("-", ""));

                dvcArgu[6].sCondition_ID = "TO_DATE";
                dvcArgu[6].sCondition_Value = dtpToDate.Text.Replace("-", "") + "235959";

                dvcArgu[7].sCondition_ID = "ORDER_ID";
                dvcArgu[7].sCondition_Value = cdvOrder.Text;

                dvcArgu[8].sCondition_ID = "OPER";
                dvcArgu[8].sCondition_Value = cdvOper.Text;

                //if(chkNon.Checked == true)
                //    s_view_id = "CWIP2033-003";
                //else 
                s_view_id = "CWIP2033-001";

                if (TPDR.GetDataOne("", ref dt, s_view_id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Sheet1.RowCount++;
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.ORD_STATUS].Value = dt.Rows[i]["ORD_STATUS"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.WORK_DATE].Value = dt.Rows[i]["WORK_DATE"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.UNIT].Value = dt.Rows[i]["UNIT_1"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.AREA_ID].Tag = dt.Rows[i]["AREA_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.AREA_ID].Value = dt.Rows[i]["AREA_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.SUB_AREA_ID].Tag = dt.Rows[i]["SUB_AREA_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.ORDER_QTY].Value = dt.Rows[i]["ORD_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.OPER_SEQ].Value = dt.Rows[i]["OPER_SEQ"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.ERP_OPER].Value = dt.Rows[i]["ERP_OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.ERP_OPER_DESC].Value = dt.Rows[i]["ERP_OPER_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.ERP_MAT_COUNT].Value = dt.Rows[i]["ERP_MAT_COUNT"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.ISSUE_MAT_COUNT].Value = dt.Rows[i]["ISSUE_MAT_COUNT"];
                }

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private bool ViewBomInfo(string lotId, string oper)
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                MPCF.ClearList(spdBom);
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = lotId;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = oper;

                if (TPDR.GetDataOne("", ref dt, "CWIP2033-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdBom_Sheet1.RowCount++;
                    spdBom_Sheet1.Cells[i, (int)BOM_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdBom_Sheet1.Cells[i, (int)BOM_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdBom_Sheet1.Cells[i, (int)BOM_INFO.OPER_SEQ].Value = dt.Rows[i]["OPER_SEQ"];
                    spdBom_Sheet1.Cells[i, (int)BOM_INFO.ERP_OPER].Value = dt.Rows[i]["ERP_OPER"];
                    spdBom_Sheet1.Cells[i, (int)BOM_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdBom_Sheet1.Cells[i, (int)BOM_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdBom_Sheet1.Cells[i, (int)BOM_INFO.ISSUE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["TRAN_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdBom_Sheet1.Cells[i, (int)BOM_INFO.INV_LOT_ID].Value = dt.Rows[i]["INV_LOT_ID"];
                    spdBom_Sheet1.Cells[i, (int)BOM_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdBom_Sheet1.Cells[i, (int)BOM_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdBom_Sheet1.Cells[i, (int)BOM_INFO.UNIT_USE_QTY].Value = dt.Rows[i]["UNIT_QTY"];
                    spdBom_Sheet1.Cells[i, (int)BOM_INFO.TOTAL_USE_QTY].Value = dt.Rows[i]["TOTAL_QTY"];
                    spdBom_Sheet1.Cells[i, (int)BOM_INFO.ISSUE_QTY].Value = dt.Rows[i]["TRAN_QTY"];
                    spdBom_Sheet1.Cells[i, (int)BOM_INFO.UNIT].Value = dt.Rows[i]["UNIT_1"];
                    spdBom_Sheet1.Cells[i, (int)BOM_INFO.INV_OPER].Value = dt.Rows[i]["INV_OPER"];
                    spdBom_Sheet1.Cells[i, (int)BOM_INFO.INV_OPER_DESC].Value = dt.Rows[i]["INV_OPER_DESC"];
                }

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private bool SaveProcess()
        {
            try
            {

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //벨리데이션 체크 함수
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                FarPoint.Win.Spread.SheetView sv = spdLotList.ActiveSheet;
                //int iCheckCount = 0;
                string prevMatID = string.Empty;
                string prevOper = string.Empty;


                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:


                        break;

                    case CSGC.CHECK.ADD:

                        //for (int i = 0; i < sv.RowCount; i++)
                        //{
                        //    if (Convert.ToBoolean(sv.Cells[i, (int)LOT_INFO.CHK].Value) == true)
                        //    {
                        //        iCheckCount++;
                        //    }
                        //}

                        //if (iCheckCount == 0)
                        //{
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(465)); //CMN465 INFO - 체크항목이 존재하지 않습니다. 확인해주세요.
                        //    return false;
                        //}

                        //if (iCheckCount > 1)
                        //{
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(516)); //CMN516 INFO - 1개의 항목만 선택가능합니다.
                        //    return false;
                        //}

                        break;

                    case CSGC.CHECK.SAVE:

                        break;
                }

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private void ClearData()
        {
            try
            {
                MPCF.FieldClear(grpLotInfo);
                MPCF.ClearList(spdLotList);
                MPCF.ClearList(spdBom);

                //spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.CHK].Value = 0;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "
        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SaveProcess())
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
                ViewLotList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void btnClear_Click(object sender, EventArgs e)
        {
            ClearData();
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

                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, '1', cdvDept.Text, cdvWorkPlace.Text) == false)
                {
                    return;
                }

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOrder_ButtonPress(object sender, EventArgs e)
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

                CUS_COM.Popup.frmPopWorkOrderList popup = new CUS_COM.Popup.frmPopWorkOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_AreaCode = cdvDept.Text;
                popup.g_AreaDesc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvOrder.Text = popup.g_WorkOrder;
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

        private void cdvMat_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMat.Text = popup.sMat_id;
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

        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            string s_lot_id = "";
            string s_oper = "";

            try
            {
                if (e.ColumnHeader)
                    return;

                spdBom_Sheet1.RowCount = 0;

                s_lot_id = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.LOT_ID].Text;
                s_oper = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.OPER].Text;

                ViewBomInfo(s_lot_id, s_oper);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void spdLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                if (e.Column == (int)LOT_INFO.INV_BUTTON)
                {
                    frmTranInputLotMaterials popup = new frmTranInputLotMaterials();
                    popup.StartPosition = FormStartPosition.CenterParent;
                    popup.sArea_id = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.AREA_ID].Tag.ToString();
                    popup.sArea_desc = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.AREA_ID].Text;
                    popup.sSub_area_id = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.SUB_AREA_ID].Tag.ToString();
                    popup.sSub_area_desc = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.SUB_AREA_ID].Text;
                    popup.sOper_id = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.OPER].Text;
                    popup.sOper_desc = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.OPER_DESC].Text;
                    popup.sOrder_id = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.ORDER_ID].Text;
                    popup.sLot_id = spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.LOT_ID].Text;
                    popup.sLot_Qty = MPCF.ToDbl(spdLotList_Sheet1.Cells[e.Row, (int)LOT_INFO.LOT_QTY].Text);
                    popup.bAddNonInput = true;


                    if (popup.ShowDialog() == DialogResult.OK)
                    {
                        popup = null;
                    }
                    else
                        return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmTranAddNotInputMaterial_Load(object sender, EventArgs e)
        {
            dtpToDate.Value = DateTime.Now;
            dtpFromDate.Value = DateTime.Now.AddDays(-7);

            chkNon.Checked = false;





        }
        #endregion


    }
}
