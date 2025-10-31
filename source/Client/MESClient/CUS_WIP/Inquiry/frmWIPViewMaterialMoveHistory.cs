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
    public partial class frmWIPViewMaterialMoveHistory : CUS_COM.frmViewForm03
    {
        public frmWIPViewMaterialMoveHistory()
        {
            InitializeComponent();
        }


        #region " Constant Definition "
        private enum MOVE_LIST
        {            
            MOVE_DATE,
            MOVE_TIME,
            MOVE_ID,
            LOT_ID,
            DEPT,
            FROM_OPER,
            FROM_OPER_DESC,
            TO_OPER,
            TO_OPER_DESC,
            MAT_ID,
            MAT_DESC,
            QTY,
            HM_EA_QTY,
            UNIT,
            REG_USER_NAME,
            CON_USER_NAME
        }

        #endregion

        #region " Function Definition "
        private bool ViewMoveHistory()
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[9];
            DataTable dt = null;
            string sSql = "";
            int i = 0;
            string s_view_id = "";

            try
            {
                spdMaterialMoveList_Sheet1.RowCount = 0;
                MPCF.ClearList(spdMaterialMoveList);
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "FROM_OPER";
                dvcArgu[2].sCondition_Value = cdvFromOper.Text;

                dvcArgu[3].sCondition_ID = "TO_OPER";
                dvcArgu[3].sCondition_Value = cdvToOper.Text;

                dvcArgu[4].sCondition_ID = "MAT_ID";
                dvcArgu[4].sCondition_Value = cdvMat.Text;

                dvcArgu[5].sCondition_ID = "MAT_DESC";
                dvcArgu[5].sCondition_Value = txtMatDesc.Text;

                dvcArgu[6].sCondition_ID = "FROM_DATE";
                dvcArgu[6].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text.Replace("-", ""));

                dvcArgu[7].sCondition_ID = "TO_DATE";
                dvcArgu[7].sCondition_Value = dtpToDate.Text.Replace("-", "");

                dvcArgu[8].sCondition_ID = "LOT_ID";
                dvcArgu[8].sCondition_Value = txtLotID.Text;

                s_view_id = "CWIP3011-001";

                if (TPDR.GetDataOne("", ref dt, s_view_id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMaterialMoveList_Sheet1.RowCount++;
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.MOVE_DATE].Value = dt.Rows[i]["MOVE_DATE"];
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.MOVE_TIME].Value = dt.Rows[i]["MOVE_TIME"];
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.MOVE_ID].Value = dt.Rows[i]["MOVE_ID"];
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.DEPT].Value = dt.Rows[i]["AREA_DESC"];
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.DEPT].Tag = dt.Rows[i]["AREA_ID"];                    
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.FROM_OPER].Value = dt.Rows[i]["FROM_OPER"];
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.FROM_OPER_DESC].Value = dt.Rows[i]["FROM_OPER_DESC"];
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_OPER].Value = dt.Rows[i]["TO_OPER"];
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_OPER_DESC].Value = dt.Rows[i]["TO_OPER_DESC"];
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.UNIT].Value = dt.Rows[i]["UNIT_1"];
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.QTY].Value = dt.Rows[i]["QTY"];
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.HM_EA_QTY].Value = dt.Rows[i]["HM_EA_QTY"];
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.REG_USER_NAME].Value = dt.Rows[i]["REG_USER_NAME"];
                    spdMaterialMoveList_Sheet1.Cells[i, (int)MOVE_LIST.CON_USER_NAME].Value = dt.Rows[i]["CON_USER_NAME"];
                }


                if(cdvDept.Text == CSGC.CP_AREA_HM)
                 {
                    spdMaterialMoveList_Sheet1.Columns.Get((int)MOVE_LIST.HM_EA_QTY).Visible = true;
                }
                else {
                    spdMaterialMoveList_Sheet1.Columns.Get((int)MOVE_LIST.HM_EA_QTY).Visible = false;
                }
                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }
        #endregion


        #region " Event Definition "
        private void btnView_Click(object sender, EventArgs e)
        {
            ViewMoveHistory();
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdMaterialMoveList , "MaterialMoveHistory");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void frmWIPViewMaterialMoveHistory_Load(object sender, EventArgs e)
        {
            dtpToDate.Value = DateTime.Now;
            dtpFromDate.Value = DateTime.Now.AddDays(-7);
            //dtpFromDate.Format = DateTimePickerFormat.Custom;
            //dtpFromDate.CustomFormat = " ";
        }

        private void cdvFromOper_ButtonPress(object sender, EventArgs e)
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

                cdvFromOper.Init();
                MPCF.InitListView(cdvFromOper.GetListView);
                cdvFromOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvFromOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvFromOper.SelectedSubItemIndex = 0;
                cdvFromOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvFromOper.GetListView, '7', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }

                cdvFromOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToOper_ButtonPress(object sender, EventArgs e)
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

                cdvToOper.Init();
                MPCF.InitListView(cdvToOper.GetListView);
                cdvToOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToOper.SelectedSubItemIndex = 0;
                cdvToOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvToOper.GetListView, '7', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }

                cdvToOper.InsertEmptyRow(0, 1);
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
        #endregion
    }
}
