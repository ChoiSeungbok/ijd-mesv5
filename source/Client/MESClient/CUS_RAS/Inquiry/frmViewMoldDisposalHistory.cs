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
//CRAS3007
namespace CUS_RAS
{
    public partial class frmViewMoldDisposalHistory : CUS_COM.frmViewForm03
    {
        public frmViewMoldDisposalHistory()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum MOLD_INFO : int
        {
            MOLD_NO,
            MAT_ID,
            MOLD_DESC,
            MOLD_MODEL,
            MOLD_TYPE,
            AREA_ID,
            OPER,
            RECV_DATE,
            SCRAP_DATE,
            VENDOR,
            VENDOR_LOT_ID,
            DLV_NO,
            PO_NO,
            PO_SEQ,
            MAX_USE_COUNT,
            USE_COUNT,
            REQ_NO,
            ETC_OUT,
            REQ_USER,
            CONFIRM_USER,
            REMARK
        }


        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 툴 이력 조회
        private void ViewToolDisposalHis()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[8];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "TOOL_GRP";
                dvcArgu[2].sCondition_Value = cdvModel.Text + "%";

                dvcArgu[3].sCondition_ID = "TOOL_TYPE";
                dvcArgu[3].sCondition_Value = cdvToolType.Text + "%";

                dvcArgu[4].sCondition_ID = "TOOL_ID";
                dvcArgu[4].sCondition_Value = txtToolId.Text + "%";

                dvcArgu[5].sCondition_ID = "REQUEST_NO";
                dvcArgu[5].sCondition_Value = txtRequestNo.Text + "%";

                dvcArgu[6].sCondition_ID = "FROM_DATE";
                dvcArgu[6].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text.Replace("-", ""));

                dvcArgu[7].sCondition_ID = "TO_DATE";
                dvcArgu[7].sCondition_Value = dtpToDate.Text.Replace("-", "") + "235959";


                if (TPDR.GetDataOne("", ref dt, "CRAS3007-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    MPCF.ClearList(spdToolList);

                    return;
                }

                MPCF.ClearList(spdToolList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdToolList.ActiveSheet.RowCount++;

                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_NO].Value = dt.Rows[i]["TOOL_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_MODEL].Value = dt.Rows[i]["MOLD_MODEL"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_TYPE].Value = dt.Rows[i]["MOLD_TYPE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.AREA_ID].Value = dt.Rows[i]["AREA_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.OPER].Value = dt.Rows[i]["OPER_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.RECV_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["RECV_DATE"].ToString(), DATE_TIME_FORMAT.DATE);               
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.SCRAP_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["SCRAP_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.VENDOR].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.DLV_NO].Value = dt.Rows[i]["DLV_NO"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.PO_NO].Value = dt.Rows[i]["PO_NO"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.PO_SEQ].Value = dt.Rows[i]["PO_SEQ"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MAX_USE_COUNT].Value = dt.Rows[i]["MAX_USE_COUNT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.USE_COUNT].Value = dt.Rows[i]["USE_COUNT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.REQ_NO].Value = dt.Rows[i]["REQ_NO"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.ETC_OUT].Value = dt.Rows[i]["ETC_OUT"];                    
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.REQ_USER].Value = dt.Rows[i]["REQ_USER_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CONFIRM_USER].Value = dt.Rows[i]["CONFIRM_USER_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.REMARK].Value = dt.Rows[i]["TOOL_COMMENT"];
                }

                MPCF.FitColumnHeader(spdToolList);

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

        private void ClearData()
        {
            try
            {
                MPCF.ClearList(spdToolList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        #endregion

        #region " Event Definition "

        private void frmViewMoldDisposalHistory_Load(object sender, EventArgs e)
        {
            try
            {

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvModel_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvModel.Init();
                MPCF.InitListView(cdvModel.GetListView);
                cdvModel.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvModel.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvModel.SelectedSubItemIndex = 0;
                cdvModel.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvModel.GetListView, '1', MPGC.MP_RAS_TOOL_GRP) == false)
                {
                    return;
                }

                cdvModel.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToolType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvToolType.Init();
                MPCF.InitListView(cdvToolType.GetListView);
                cdvToolType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToolType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToolType.SelectedSubItemIndex = 0;
                cdvToolType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvToolType.GetListView, '1', CSGC.CP_GCM_MOLD_TYPE) == false)
                {
                    return;
                }

                cdvToolType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtToolId_KeyPress(object sender, KeyPressEventArgs e)
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

        private void txtRequestNo_KeyPress(object sender, KeyPressEventArgs e)
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

        private void btnExcel_Click(object sender, EventArgs e)
        {
            string sFileName = "";

            try
            {
                sFileName = "MoldDisposalHistory";

                EXTFUC.SaveExcel(spdToolList, sFileName);
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
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewToolDisposalHis();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        #endregion

    }
}
