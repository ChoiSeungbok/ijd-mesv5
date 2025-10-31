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

//CRAS3012
namespace CUS_RAS
{
    public partial class frmViewHMExtruderData : CUS_COM.frmViewForm03
    {
        public frmViewHMExtruderData()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum RAS_INFO : int
        {
            RES_ID, 
            RES_DESC, 
            WORK_DATE, 
            WORK_TIME,
            PV_PRESSURE,
            PV_TEMP,
            RES_STATUS
        }

        #endregion

        #region " Variable Definition "
            public string g_Dept = string.Empty;
            public string g_DeptDisplay = string.Empty;
            public string g_Oper = string.Empty;
            public string g_OperDisplay = string.Empty;
            public string g_ResId = string.Empty;
            public string g_ResDisplay = string.Empty;
            public string g_searchType = string.Empty;
            public string g_LotId = string.Empty;
            public string g_SearchYn = string.Empty;
            public string g_PopYn = "N";

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public static bool ViewOper(Control control, string sArea_ID)
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
                dvcArgu[1].sCondition_Value = sArea_ID;               

                if (TPDR.GetDataOne("", ref dt, "CRAS3012-000", dvcArgu, false, false, ref sSql) == false)
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

        public static bool ViewResID(Control control, string sOperID)
        {
            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = sOperID;
                
                if (TPDR.GetDataOne("", ref dt, "CRAS3012-002", dvcArgu, false, false, ref sSql) == false)
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
                        itmX = new ListViewItem(row["RES_ID"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["RES_DESC"].ToString());
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

        private void ViewExtruderData()
        {
            int i = 0;
            string sSql = "";


            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "RES_ID";
                dvcArgu[1].sCondition_Value = cdvResId.Text + "%";

                dvcArgu[2].sCondition_ID = "FROM_DATE";
                dvcArgu[2].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text.Replace("-", ""));

                dvcArgu[3].sCondition_ID = "TO_DATE";
                dvcArgu[3].sCondition_Value = dtpToDate.Text.Replace("-", "") + "235959";

                if (TPDR.GetDataOne("", ref dt, "CRAS3012-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    MPCF.ClearList(spdExtruder);

                    return;
                }
                 
                MPCF.ClearList(spdExtruder);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdExtruder.ActiveSheet.RowCount++;

                    spdExtruder.ActiveSheet.Cells[i, (int)RAS_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    spdExtruder.ActiveSheet.Cells[i, (int)RAS_INFO.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                    spdExtruder.ActiveSheet.Cells[i, (int)RAS_INFO.WORK_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdExtruder.ActiveSheet.Cells[i, (int)RAS_INFO.WORK_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdExtruder.ActiveSheet.Cells[i, (int)RAS_INFO.PV_PRESSURE].Value = dt.Rows[i]["PV_PRESSURE"];
                    spdExtruder.ActiveSheet.Cells[i, (int)RAS_INFO.PV_TEMP].Value = dt.Rows[i]["PV_TEMP"];
                    spdExtruder.ActiveSheet.Cells[i, (int)RAS_INFO.RES_STATUS].Value = dt.Rows[i]["RES_STATUS"];
                }
 
                MPCF.FitColumnHeader(spdExtruder);

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
                
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvResId.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblRes.Text + "]");
                            cdvResId.Focus();
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
                MPCF.ClearList(spdExtruder);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmViewHMExtruderData_Load(object sender, EventArgs e)
        {
            try
            {


                FarPoint.Win.Spread.SheetView oSheet = spdExtruder.ActiveSheet;

                if (g_PopYn == "Y")
                {
                    cdvDept.Text = g_Dept;
                    cdvDept.DisplayText = g_DeptDisplay;
                    cdvOper.Text = g_Oper;
                    cdvOper.DisplayText = g_OperDisplay;
                    cdvResId.Text = g_ResId;
                    cdvResId.DisplayText = g_ResDisplay;

                }
                else {
                    cdvDept.Text = CSGV.gs_area_hm;
                    cdvDept.DisplayText = CSGV.gs_area_hm;

                }

                if (MPGV.gsUserGroup.Contains("ADMIN"))
                    spdExtruder.ActiveSheet.Columns[(int)RAS_INFO.RES_STATUS].Visible = true;
                else
                    spdExtruder.ActiveSheet.Columns[(int)RAS_INFO.RES_STATUS].Visible = false;



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

                if (ViewOper(cdvOper.GetListView, cdvDept.Text) == false)
                {
                    return;
                }

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                MPCF.ClearList(spdExtruder);
                cdvResId.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvResId_ButtonPress(object sender, EventArgs e)
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

                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }

                cdvResId.Init();
                MPCF.InitListView(cdvResId.GetListView);
                cdvResId.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvResId.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvResId.SelectedSubItemIndex = 0;
                cdvResId.DisplaySubItemIndex = 1;


                if (ViewResID(cdvResId.GetListView, cdvOper.Text) == false)
                {
                    return;
                }

                cdvResId.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvResId_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                MPCF.ClearList(spdExtruder);
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
                sFileName = cdvResId.Text + "_Data";

                EXTFUC.SaveExcel(spdExtruder, sFileName);
                
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
                ClearData();
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

                ViewExtruderData();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion


    }
}
