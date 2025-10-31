using FarPoint.Win.Spread;
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

namespace CUS_COM
{
    public partial class frmPopVendorList : frmViewForm01
    {
        public frmPopVendorList()
        {
            InitializeComponent();

            btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            btnSelect.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
        }

        private void frmPopVendorList_Load(object sender, EventArgs e)
        {
            txtVendorDesc.Text = g_VendorDesc;
        }

        #region " Constant Definition "
        private enum VENDOR_LIST
        {
            CHECK,              // 1 : 체크박스
            VENDOR_ID,          // 2 : 업체ID
            VENDOR_SITE_ID,     // 3 : 업체SITE ID
            VENDOR_DESC,        // 4 : 업체명
        }
        #endregion

        #region " Variable Definition "
        public string g_VendorId = string.Empty;
        public string g_VendorSiteId = string.Empty;
        public string g_VendorDesc = string.Empty;

        #endregion

        #region " Grid/Button Event Definition "
        private void spdVendor_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                SheetView svVendor = spdVendor.ActiveSheet;

                if (e.ColumnHeader)
                    return;

                for (int i = 0; i < svVendor.RowCount; i++)
                {
                    svVendor.SetValue(i, (int)VENDOR_LIST.CHECK, false);
                }

                svVendor.SetValue(e.Row, (int)VENDOR_LIST.CHECK, true);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdVendor_CellDoubleClick(object sender, CellClickEventArgs e)
        {
            try
            {
                SheetView svVendor = spdVendor.ActiveSheet;

                if (e.ColumnHeader)
                    return;

                g_VendorId = svVendor.GetValue(e.Row, (int)VENDOR_LIST.VENDOR_ID).ToString();
                g_VendorSiteId = svVendor.GetValue(e.Row, (int)VENDOR_LIST.VENDOR_SITE_ID).ToString();
                g_VendorDesc = svVendor.GetValue(e.Row, (int)VENDOR_LIST.VENDOR_DESC).ToString();
                this.DialogResult = DialogResult.OK;
                this.Close();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtVendorDesc_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                MPCF.ClearList(spdVendor);

                ViewVendorList();
            }
        }

        private void txtVendorID_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                MPCF.ClearList(spdVendor);

                ViewVendorList();
            }
        }

        private void txtVendorSiteID_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                MPCF.ClearList(spdVendor);

                ViewVendorList();
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                MPCF.ClearList(spdVendor);

                ViewVendorList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                SheetView svVendor = spdVendor.ActiveSheet;
                int iSelect = 0;

                for (int i = 0; i < svVendor.RowCount; i++)
                {
                    if (Convert.ToBoolean(svVendor.Cells[i, (int)VENDOR_LIST.CHECK].Value))
                    {
                        iSelect++;
                        g_VendorId = svVendor.GetValue(i, (int)VENDOR_LIST.VENDOR_ID).ToString();
                        g_VendorSiteId = svVendor.GetValue(i, (int)VENDOR_LIST.VENDOR_SITE_ID).ToString();
                        g_VendorDesc = svVendor.GetValue(i, (int)VENDOR_LIST.VENDOR_DESC).ToString();
                        break;
                    }
                }

                if (iSelect <= 0)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    spdVendor.Focus();
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

        #endregion

        #region " Function Definition "
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
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

        private void ViewVendorList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                SheetView svOrder = spdVendor.ActiveSheet;
                DataTable dt = null;
                string sViewId = "CCOM3004-001";
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "P_FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "P_VENDOR_DESC";
                dvcArgu[1].sCondition_Value = txtVendorDesc.Text;

                dvcArgu[2].sCondition_ID = "P_VENDOR_ID";
                dvcArgu[2].sCondition_Value = txtVendorID.Text;

                dvcArgu[3].sCondition_ID = "P_VENDOR_SITE_ID";
                dvcArgu[3].sCondition_Value = txtVendorSiteID.Text;

                if (TPDR.GetDataOne("", ref dt, sViewId, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    svOrder.RowCount++;

                    svOrder.Cells[i, (int)VENDOR_LIST.CHECK].Value = false;
                    svOrder.Cells[i, (int)VENDOR_LIST.VENDOR_ID].Value = dt.Rows[i]["VENDOR_ID"];
                    svOrder.Cells[i, (int)VENDOR_LIST.VENDOR_SITE_ID].Value = dt.Rows[i]["VENDOR_SITE_ID"];
                    svOrder.Cells[i, (int)VENDOR_LIST.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                }

                MPCF.FitColumnHeader(spdVendor);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion
    }
}
