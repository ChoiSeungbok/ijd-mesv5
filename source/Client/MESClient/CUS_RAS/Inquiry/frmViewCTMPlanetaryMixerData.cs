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

//CRAS3014 
namespace CUS_RAS
{
    public partial class frmViewCTMPlanetaryMixerData : CUS_COM.frmViewForm03
    {
        public frmViewCTMPlanetaryMixerData()
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
            SV_TEMP,
            PV_TEMP,
            LOT_ID, 
            MAT_ID, 
            MAT_DESC,
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

                if (TPDR.GetDataOne("", ref dt, "CRAS3014-000", dvcArgu, false, false, ref sSql) == false)
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

                if (TPDR.GetDataOne("", ref dt, "CRAS3014-003", dvcArgu, false, false, ref sSql) == false)
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

        private void ViewPlanetaryMixerData()
        {
            int i = 0;
            string sSql = "";
            string sViewID = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                DataTable dt = null;

                if (rdoDate.Checked)
                    sViewID = "CRAS3014-001";
                else
                    sViewID = "CRAS3014-002";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text + "%";

                dvcArgu[2].sCondition_ID = "RES_ID";
                dvcArgu[2].sCondition_Value = cdvResId.Text + "%";

                dvcArgu[3].sCondition_ID = "LOT_ID";
                dvcArgu[3].sCondition_Value = txtLotID.Text;

                dvcArgu[4].sCondition_ID = "FROM_DATE";
                dvcArgu[4].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text.Replace("-", ""));

                dvcArgu[5].sCondition_ID = "TO_DATE";
                dvcArgu[5].sCondition_Value = dtpToDate.Text.Replace("-", "") + "235959";

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    MPCF.ClearList(spdPlanetaryMixer);

                    return;
                }
                 
                MPCF.ClearList(spdPlanetaryMixer);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdPlanetaryMixer.ActiveSheet.RowCount++;

                    spdPlanetaryMixer.ActiveSheet.Cells[i, (int)RAS_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    spdPlanetaryMixer.ActiveSheet.Cells[i, (int)RAS_INFO.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                    spdPlanetaryMixer.ActiveSheet.Cells[i, (int)RAS_INFO.WORK_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdPlanetaryMixer.ActiveSheet.Cells[i, (int)RAS_INFO.WORK_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdPlanetaryMixer.ActiveSheet.Cells[i, (int)RAS_INFO.SV_TEMP].Value = dt.Rows[i]["SV_TEMP"];
                    spdPlanetaryMixer.ActiveSheet.Cells[i, (int)RAS_INFO.PV_TEMP].Value = dt.Rows[i]["PV_TEMP"];
                    spdPlanetaryMixer.ActiveSheet.Cells[i, (int)RAS_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdPlanetaryMixer.ActiveSheet.Cells[i, (int)RAS_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdPlanetaryMixer.ActiveSheet.Cells[i, (int)RAS_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdPlanetaryMixer.ActiveSheet.Cells[i, (int)RAS_INFO.RES_STATUS].Value = dt.Rows[i]["RES_STATUS"];
                }
 
                MPCF.FitColumnHeader(spdPlanetaryMixer);

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
                MPCF.ClearList(spdPlanetaryMixer);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmViewCTMPlanetaryMixerData_Load(object sender, EventArgs e)
        {
            try
            {


                FarPoint.Win.Spread.SheetView oSheet = spdPlanetaryMixer.ActiveSheet;

                if (g_PopYn =="Y") 
                {
                    cdvDept.Text = g_Dept;
                    cdvDept.DisplayText = g_DeptDisplay;
                    cdvOper.Text = g_Oper;
                    cdvOper.DisplayText = g_OperDisplay;
                    cdvResId.Text = g_ResId;
                    cdvResId.DisplayText = g_ResDisplay;
                    txtLotID.Text =  g_LotId;




                    if (g_searchType == "LOT")
                    {
                        rdoLot.Checked = true;
                        txtLotID.Enabled = true;
                        btnChngeLotTime.Enabled = true;
                        dtpFromDate.Enabled = false;
                        dtpToDate.Enabled = false;


                        oSheet.Columns[(int)RAS_INFO.LOT_ID].Visible = true;
                        oSheet.Columns[(int)RAS_INFO.MAT_ID].Visible = true;
                        oSheet.Columns[(int)RAS_INFO.MAT_DESC].Visible = true;

                    }
                    else
                    {

                        rdoLot.Checked = false;
                        txtLotID.Text = "";
                        txtLotID.Enabled = false;
                        btnChngeLotTime.Enabled = false;
                        dtpFromDate.Enabled = true;
                        dtpToDate.Enabled = true;
                        

                        oSheet.Columns[(int)RAS_INFO.LOT_ID].Visible = false;
                        oSheet.Columns[(int)RAS_INFO.MAT_ID].Visible = false;
                        oSheet.Columns[(int)RAS_INFO.MAT_DESC].Visible = false;
                    }


                    if (g_SearchYn =="Y") {
                        ViewPlanetaryMixerData();
                    }
                }
                else {
                    cdvDept.Text = CSGV.gs_area_ctm;
                    cdvDept.DisplayText = CSGV.gs_area_ctm;

                    txtLotID.Enabled = false;
                    btnChngeLotTime.Enabled = false;

                    if (MPGV.gsUserGroup.Contains("ADMIN"))
                        spdPlanetaryMixer.ActiveSheet.Columns[(int)RAS_INFO.RES_STATUS].Visible = true;
                    else
                        spdPlanetaryMixer.ActiveSheet.Columns[(int)RAS_INFO.RES_STATUS].Visible = false;
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
                MPCF.ClearList(spdPlanetaryMixer);
                cdvResId.Text = "";
                txtLotID.Text = "";
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
                MPCF.ClearList(spdPlanetaryMixer);
                txtLotID.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void rdoDate_CheckedChanged(object sender, EventArgs e)
        {
            try
            {
                if (rdoDate.Checked == true)
                {
                    rdoLot.Checked = false;
                    txtLotID.Text = "";
                    txtLotID.Enabled = false;
                    btnChngeLotTime.Enabled = false;
                    dtpFromDate.Enabled = true;
                    dtpToDate.Enabled = true;

                    spdPlanetaryMixer.ActiveSheet.Columns[(int)RAS_INFO.LOT_ID].Visible = false;
                    spdPlanetaryMixer.ActiveSheet.Columns[(int)RAS_INFO.MAT_ID].Visible = false;
                    spdPlanetaryMixer.ActiveSheet.Columns[(int)RAS_INFO.MAT_DESC].Visible = false;
                }
                else
                {
                    rdoLot.Checked = true;                    
                    txtLotID.Enabled = true;
                    btnChngeLotTime.Enabled = true;
                    dtpFromDate.Enabled = false;
                    dtpToDate.Enabled = false;

                    spdPlanetaryMixer.ActiveSheet.Columns[(int)RAS_INFO.LOT_ID].Visible = true;
                    spdPlanetaryMixer.ActiveSheet.Columns[(int)RAS_INFO.MAT_ID].Visible = true;
                    spdPlanetaryMixer.ActiveSheet.Columns[(int)RAS_INFO.MAT_DESC].Visible = true;
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
                    if (rdoLot.Checked == true)
                    {
                        btnView.PerformClick();
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnChngeLotTime_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(txtLotID.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotID.Text + "]");
                    txtLotID.Focus();
                    return;
                }

                frmPopUpdateResourceWorkTime popup = new frmPopUpdateResourceWorkTime();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sLot_ID = txtLotID.Text;
                popup.sOper = cdvOper.Text;
                popup.sOper_desc = cdvOper.DisplayText;
                popup.sRes_ID = cdvResId.Text;
                popup.sRes_desc = cdvResId.DisplayText;

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

        private void btnExcel_Click(object sender, EventArgs e)
        {
            string sFileName = "";

            try
            {
                sFileName = cdvResId.Text + "_Data";

                EXTFUC.SaveExcel(spdPlanetaryMixer, sFileName);
                
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

                ViewPlanetaryMixerData();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion


    }
}
