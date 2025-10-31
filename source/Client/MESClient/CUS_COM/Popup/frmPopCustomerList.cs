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
    public partial class frmPopCustomerList : frmViewForm01
    {
        public frmPopCustomerList()
        {
            InitializeComponent();

            btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            btnSelect.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
        }

        private void frmPopCustomerList_Load(object sender, EventArgs e)
        {
            txtCustomerDesc.Text = g_CustomerDesc;
        }

        #region " Constant Definition "
        private enum CUSTOMER_LIST
        {
            CHECK,                // 1 : 체크박스
            CUSTOMER_ID,          // 2 : 고객사ID
            CUSTOMER_SITE_ID,     // 3 : 고객사 SITE ID
            CUSTOMER_DESC,        // 4 : 고객사명
        }
        #endregion

        #region " Variable Definition "
        public string g_CustomerId = string.Empty;
        public string g_CustomerSiteId = string.Empty;
        public string g_CustomerDesc = string.Empty;

        #endregion

        #region " Grid/Button Event Definition "
        private void spdCustomer_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                SheetView svCustomer = spdCustomer.ActiveSheet;

                if (e.ColumnHeader)
                    return;

                for (int i = 0; i < svCustomer.RowCount; i++)
                {
                    svCustomer.SetValue(i, (int)CUSTOMER_LIST.CHECK, false);
                }

                svCustomer.SetValue(e.Row, (int)CUSTOMER_LIST.CHECK, true);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdCustomer_CellDoubleClick(object sender, CellClickEventArgs e)
        {
            try
            {
                SheetView svCustomer = spdCustomer.ActiveSheet;

                if (e.ColumnHeader)
                    return;

                g_CustomerId = svCustomer.GetValue(e.Row, (int)CUSTOMER_LIST.CUSTOMER_ID).ToString();
                g_CustomerSiteId = svCustomer.GetValue(e.Row, (int)CUSTOMER_LIST.CUSTOMER_SITE_ID).ToString();
                g_CustomerDesc = svCustomer.GetValue(e.Row, (int)CUSTOMER_LIST.CUSTOMER_DESC).ToString();
                this.DialogResult = DialogResult.OK;
                this.Close();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtCustomerID_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                MPCF.ClearList(spdCustomer);

                ViewCustomerList();
            }
        }

        private void txtCustomerSiteID_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                MPCF.ClearList(spdCustomer);

                ViewCustomerList();
            }
        }

        private void txtCustomerDesc_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                MPCF.ClearList(spdCustomer);

                ViewCustomerList();
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                MPCF.ClearList(spdCustomer);

                ViewCustomerList();
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
                SheetView svCustomer = spdCustomer.ActiveSheet;
                int iSelect = 0;

                for (int i = 0; i < svCustomer.RowCount; i++)
                {
                    if (Convert.ToBoolean(svCustomer.Cells[i, (int)CUSTOMER_LIST.CHECK].Value))
                    {
                        iSelect++;
                        g_CustomerId = svCustomer.GetValue(i, (int)CUSTOMER_LIST.CUSTOMER_ID).ToString();
                        g_CustomerSiteId = svCustomer.GetValue(i, (int)CUSTOMER_LIST.CUSTOMER_SITE_ID).ToString();
                        g_CustomerDesc = svCustomer.GetValue(i, (int)CUSTOMER_LIST.CUSTOMER_DESC).ToString();
                        break;
                    }
                }

                if (iSelect <= 0)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    spdCustomer.Focus();
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

        private void ViewCustomerList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                SheetView svCustomer = spdCustomer.ActiveSheet;
                DataTable dt = null;
                string sViewId = "CCOM3005-001";
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "CUSTOMER_DESC";
                dvcArgu[1].sCondition_Value = txtCustomerDesc.Text;

                dvcArgu[2].sCondition_ID = "CUSTOMER_ID";
                dvcArgu[2].sCondition_Value = txtCustomerID.Text;

                dvcArgu[3].sCondition_ID = "CUSTOMER_SITE_ID";
                dvcArgu[3].sCondition_Value = txtCustomerSiteID.Text;

                if (TPDR.GetDataOne("", ref dt, sViewId, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    svCustomer.RowCount++;

                    svCustomer.Cells[i, (int)CUSTOMER_LIST.CHECK].Value = false;
                    svCustomer.Cells[i, (int)CUSTOMER_LIST.CUSTOMER_ID].Value = dt.Rows[i]["CUSTOMER_ID"];
                    svCustomer.Cells[i, (int)CUSTOMER_LIST.CUSTOMER_SITE_ID].Value = dt.Rows[i]["CUSTOMER_SITE_ID"];
                    svCustomer.Cells[i, (int)CUSTOMER_LIST.CUSTOMER_DESC].Value = dt.Rows[i]["CUSTOMER_DESC"];
                }

                MPCF.FitColumnHeader(spdCustomer);

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
