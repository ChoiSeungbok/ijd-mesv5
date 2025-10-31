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
//CRAS0001
namespace CUS_RAS
{
    public partial class frmPopToolList : CUS_COM.frmViewForm03
    {
        public frmPopToolList()
        {
            InitializeComponent();
            InitControl();
        }

        #region " Constant Definition "

        private enum MOLD_INFO : int
        {
            CHK,
            MOLD_NO,
            MOLD_DESC,
            MOLD_MODEL,
            MOLD_TYPE,
            AREA_ID,
            OPER,
            RECV_DATE,
            VENDOR,
            VENDOR_LOT_ID,
            DLV_NO,
            PO_NO,
            PO_SEQ,
            RES_ID,
            CAR,
            TOP_BASE,
            MAX_USE_COUNT,
            USE_COUNT,
            ALARM_COUNT,
            REMARK
        }

        #endregion

        #region " Variable Definition "

        public string sArea_id = "";
        public string sArea_desc = "";
        public string g_Tool_id = "";
        public string g_Tool_desc = "";
        public string g_Tool_count = "";
        public string g_Area_id = "";

        public string g_Popup_yn = "N";

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSelect.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //공정 조회
        public bool ViewToolOper(Control control, string sArea_id)
        {
            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea_id;

                if (TPDR.GetDataOne("", ref dt, "CRAS0001-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return false;

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["OPER"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["OPER_DESC"].ToString());
                        }
                        ((ListView)control).Items.Add(itmX);
                    }
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        // 툴 조회
        private void ViewToolStatus()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;

                dvcArgu[3].sCondition_ID = "TOOL_GRP";
                dvcArgu[3].sCondition_Value = cdvModel.Text + "%";

                dvcArgu[4].sCondition_ID = "TOOL_TYPE";
                dvcArgu[4].sCondition_Value = cdvToolType.Text + "%";

                dvcArgu[5].sCondition_ID = "TOOL_ID";
                dvcArgu[5].sCondition_Value = txtToolId.Text + "%";
                
                if (TPDR.GetDataOne("", ref dt, "CRAS0001-001", dvcArgu, false, false, ref sSql) == false)
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

                    spdToolList.ActiveSheet.SetValue(i, (int)MOLD_INFO.CHK, false);
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_NO].Value = dt.Rows[i]["TOOL_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_MODEL].Value = dt.Rows[i]["MOLD_MODEL"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_TYPE].Value = dt.Rows[i]["MOLD_TYPE"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.AREA_ID].Value = dt.Rows[i]["AREA_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.OPER].Value = dt.Rows[i]["OPER_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.RECV_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["RECV_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.VENDOR].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.DLV_NO].Value = dt.Rows[i]["DLV_NO"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.PO_NO].Value = dt.Rows[i]["PO_NO"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.PO_SEQ].Value = dt.Rows[i]["PO_SEQ"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.RES_ID].Value = dt.Rows[i]["RES_DESC"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CAR].Value = dt.Rows[i]["CAR"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.TOP_BASE].Value = dt.Rows[i]["PAN"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MAX_USE_COUNT].Value = dt.Rows[i]["MAX_USE_COUNT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.USE_COUNT].Value = dt.Rows[i]["USE_COUNT"];
                    spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.ALARM_COUNT].Value = dt.Rows[i]["ALAM_COUNT"];
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
                    /*
                        if (MPCF.Trim(cdvDept.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
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

        private void frmPopToolList_Load(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Text = sArea_id;
                cdvDept.DisplayText = sArea_desc;


                if (g_Popup_yn == "Y") 
                {
                    btnView.PerformClick();
                }


                /*
                if (MPCF.Trim(cdvDept.Text) != "")
                {
                    btnView.PerformClick();
                }
                */
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

                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (ViewToolOper(cdvOper.GetListView, cdvDept.Text) == false)
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

        private void spdToolList_CellDoubleClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                    return;

                g_Tool_id = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.MOLD_NO].Text;
                g_Tool_desc = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.MOLD_DESC].Text;
                g_Tool_count = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.USE_COUNT].Text;
                g_Area_id = spdToolList.ActiveSheet.Cells[e.Row, (int)MOLD_INFO.AREA_ID].Text;

                this.DialogResult = DialogResult.OK;
                this.Close();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }           
        }

        private void spdToolList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                    return;

                for (int i = 0; i < spdToolList.ActiveSheet.RowCount; i++)
                {
                    spdToolList.ActiveSheet.SetValue(i, (int)MOLD_INFO.CHK, false);
                }

                spdToolList.ActiveSheet.SetValue(e.Row, (int)MOLD_INFO.CHK, true);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnSelect_Click(object sender, EventArgs e)
        {
            int iSelect = 0;

            try
            {
                for (int i = 0; i < spdToolList.ActiveSheet.RowCount; i++)
                {
                    if (spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iSelect++;

                        g_Tool_id = spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_NO].Text;
                        g_Tool_desc = spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.MOLD_DESC].Text;
                        g_Tool_count = spdToolList.ActiveSheet.Cells[i, (int)MOLD_INFO.USE_COUNT].Text;

                        break;
                    }
                }

                if (iSelect <= 0)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return;
                }

                if (iSelect > 0)
                {
                    this.DialogResult = DialogResult.OK;
                    this.Close();
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
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewToolStatus();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        #endregion


    }
}
