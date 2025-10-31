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

//CRAS3009 
namespace CUS_RAS
{
    public partial class frmViewHmExtrusionResData : CUS_COM.frmViewForm03
    {
        public frmViewHmExtrusionResData()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum EDR_INFO : int
        {
            WORK_DATE, 
            LOT_ID,
            FLOW,
            FLOW_DESC,
            OPER,
            OPER_DESC,
            RES_ID,
            RES_DESC,
            MAT_ID,
            MAT_DESC,
            L_COUNT
        }

        private enum CIP_INFO : int
        {
            WORK_DATE,
            WORK_TIME,
            LOT_ID,
            FLOW,
            FLOW_DESC,
            OPER,
            OPER_DESC,
            RES_ID,
            RES_DESC,
            MAT_ID,
            MAT_DESC,
            OPERATION_PRESS,            //운전압력
            PRESS_HOLD_TIME_1,          //압력유지시간
            PRESS_HOLD_TIME_2,          //압력유지시간
            PRESS_OPERATION_FLAG,       //가압운전시작
            DISCHARGE_OPERATION_FLAG    //배출운전시작
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
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public static bool ViewResID(Control control, string sArea_ID, string sType)
        {
            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea_ID;

                dvcArgu[2].sCondition_ID = "GRP_TYPE";
                dvcArgu[2].sCondition_Value = sType;

                if (TPDR.GetDataOne("", ref dt, "CRAS3009-000", dvcArgu, false, false, ref sSql) == false)
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

        private void ViewMdEdr()
        {
            
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;
                
                dvcArgu[1].sCondition_ID = "RES_ID";
                dvcArgu[1].sCondition_Value = cdvResId.Text + "%";

                dvcArgu[2].sCondition_ID = "LOT_ID";
                dvcArgu[2].sCondition_Value = txtLotID.Text + "%";

                dvcArgu[3].sCondition_ID = "FROM_DATE";
                dvcArgu[3].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text.Replace("-", ""));

                dvcArgu[4].sCondition_ID = "TO_DATE";
                dvcArgu[4].sCondition_Value = dtpToDate.Text.Replace("-", "") + "235959";


                if (TPDR.GetDataOne("", ref dt, "CRAS3009-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    MPCF.ClearList(spdMdEdr);

                    return;
                }

                MPCF.ClearList(spdMdEdr);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMdEdr.ActiveSheet.RowCount++;

                    spdMdEdr.ActiveSheet.Cells[i, (int)EDR_INFO.WORK_DATE].Value = dt.Rows[i]["WORK_DATE"];
                    spdMdEdr.ActiveSheet.Cells[i, (int)EDR_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdMdEdr.ActiveSheet.Cells[i, (int)EDR_INFO.FLOW].Value = dt.Rows[i]["FLOW"];
                    spdMdEdr.ActiveSheet.Cells[i, (int)EDR_INFO.FLOW_DESC].Value = dt.Rows[i]["FLOW_DESC"];
                    spdMdEdr.ActiveSheet.Cells[i, (int)EDR_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdMdEdr.ActiveSheet.Cells[i, (int)EDR_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdMdEdr.ActiveSheet.Cells[i, (int)EDR_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    spdMdEdr.ActiveSheet.Cells[i, (int)EDR_INFO.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                    spdMdEdr.ActiveSheet.Cells[i, (int)EDR_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMdEdr.ActiveSheet.Cells[i, (int)EDR_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMdEdr.ActiveSheet.Cells[i, (int)EDR_INFO.L_COUNT].Value = dt.Rows[i]["L_COUNT"];
                }

                MPCF.FitColumnHeader(spdMdEdr);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }            
        }

        private void ViewDryCip()
        {

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "RES_ID";
                dvcArgu[1].sCondition_Value = cdvResId.Text + "%";

                dvcArgu[2].sCondition_ID = "LOT_ID";
                dvcArgu[2].sCondition_Value = txtLotID.Text + "%";

                dvcArgu[3].sCondition_ID = "FROM_DATE";
                dvcArgu[3].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromDate.Text.Trim()) ? "19000101" : dtpFromDate.Text.Replace("-", ""));

                dvcArgu[4].sCondition_ID = "TO_DATE";
                dvcArgu[4].sCondition_Value = dtpToDate.Text.Replace("-", "") + "235959";

                if (TPDR.GetDataOne("", ref dt, "CRAS3009-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    MPCF.ClearList(spdDryCip);

                    return;
                }

                MPCF.ClearList(spdDryCip);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdDryCip.ActiveSheet.RowCount++;

                    spdDryCip.ActiveSheet.Cells[i, (int)CIP_INFO.WORK_DATE].Value = dt.Rows[i]["WORK_DATE"];
                    spdDryCip.ActiveSheet.Cells[i, (int)CIP_INFO.WORK_TIME].Value = dt.Rows[i]["WORK_TIME"];
                    spdDryCip.ActiveSheet.Cells[i, (int)CIP_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdDryCip.ActiveSheet.Cells[i, (int)CIP_INFO.FLOW].Value = dt.Rows[i]["FLOW"];
                    spdDryCip.ActiveSheet.Cells[i, (int)CIP_INFO.FLOW_DESC].Value = dt.Rows[i]["FLOW_DESC"];
                    spdDryCip.ActiveSheet.Cells[i, (int)CIP_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdDryCip.ActiveSheet.Cells[i, (int)CIP_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdDryCip.ActiveSheet.Cells[i, (int)CIP_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    spdDryCip.ActiveSheet.Cells[i, (int)CIP_INFO.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                    spdDryCip.ActiveSheet.Cells[i, (int)CIP_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdDryCip.ActiveSheet.Cells[i, (int)CIP_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdDryCip.ActiveSheet.Cells[i, (int)CIP_INFO.OPERATION_PRESS].Value = dt.Rows[i]["OPERATION_PRESS"];
                    spdDryCip.ActiveSheet.Cells[i, (int)CIP_INFO.PRESS_HOLD_TIME_1].Value = dt.Rows[i]["PRESS_HOLD_TIME_1"];
                    spdDryCip.ActiveSheet.Cells[i, (int)CIP_INFO.PRESS_HOLD_TIME_2].Value = dt.Rows[i]["PRESS_HOLD_TIME_2"];
                    spdDryCip.ActiveSheet.Cells[i, (int)CIP_INFO.PRESS_OPERATION_FLAG].Value = dt.Rows[i]["PRESS_OPERATION_FLAG"];
                    spdDryCip.ActiveSheet.Cells[i, (int)CIP_INFO.DISCHARGE_OPERATION_FLAG].Value = dt.Rows[i]["DISCHARGE_OPERATION_FLAG"];
                }

                MPCF.FitColumnHeader(spdDryCip);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmViewHmExtrusionResData_Load(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Text = CSGV.gs_area_hm;
                cdvDept.DisplayText = CSGV.gs_area_hm;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvResId_ButtonPress(object sender, EventArgs e)
        {
            string sType = "";

            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                cdvResId.Init();
                MPCF.InitListView(cdvResId.GetListView);
                cdvResId.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvResId.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvResId.SelectedSubItemIndex = 0;
                cdvResId.DisplaySubItemIndex = 1;

                if (tbResType.SelectedIndex == 0)
                    sType = "1";
                else
                    sType = "2";

                if (ViewResID(cdvResId.GetListView, cdvDept.Text, sType) == false)
                {
                    return;
                }

                cdvResId.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            string sFileName = "";

            try
            {
                if (tbResType.SelectedIndex == 0)
                {
                    sFileName = "EDR_MD History";

                    EXTFUC.SaveExcel(spdMdEdr, sFileName); 
                }
                else
                {
                    sFileName = "Dry-CPY History";

                    EXTFUC.SaveExcel(spdMdEdr, sFileName);
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
                MPCF.ClearList(spdDryCip);
                MPCF.ClearList(spdMdEdr);
                cdvResId.Text = "";
                txtLotID.Text = "";
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
                if (tbResType.SelectedIndex == 0)
                {
                    ViewMdEdr();
                }
                else
                {
                    ViewDryCip();
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
