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
    public partial class frmPopDeliveryList : frmViewForm01
    {
        public frmPopDeliveryList()
        {
            InitializeComponent();

            initControl();
        }

        private void frmPopDeliveryList_Load(object sender, EventArgs e)
        {
            txtDeliveryName.Text = g_DeliveryName;
        }

        #region " Constant Definition "

        private enum DELIVERY_LIST : int
        {
            CHECK,              // 1 : 체크박스
            DELIVERY_ID,        // 2 : 납품처 ID
            DELIVERY_NAME       // 3 : 납품처명
        }

        #endregion

        #region " Variable Definition "
        public string g_DeliveryId = string.Empty;
        public string g_DeliveryName = string.Empty;

        #endregion

        #region " Function Definition "

        private void initControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSelect.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch(Exception ex)
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

        private void ViewDeliveryList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                SheetView svOrder = spdDelivery.ActiveSheet;
                DataTable dt = null;
                string sViewId = "CCOM3006-001";
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "P_FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "P_DELIVERY_ID";
                dvcArgu[1].sCondition_Value = txtDeliveryID.Text;

                dvcArgu[2].sCondition_ID = "P_DELIVERY_NAME";
                dvcArgu[2].sCondition_Value = txtDeliveryName.Text;

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

                    svOrder.Cells[i, (int)DELIVERY_LIST.DELIVERY_ID].Value = dt.Rows[i]["DELIVERY_ID"];
                    svOrder.Cells[i, (int)DELIVERY_LIST.DELIVERY_NAME].Value = dt.Rows[i]["DELIVERY_NAME"];
                }

                MPCF.FitColumnHeader(spdDelivery);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                MPCF.ClearList(spdDelivery);

                ViewDeliveryList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdDelivery_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
           
        }

        private void spdDelivery_CellDoubleClick(object sender, CellClickEventArgs e)
        {
            try
            {
                SheetView svDelivery = spdDelivery.ActiveSheet;

                if (e.ColumnHeader)
                    return;

                g_DeliveryId = svDelivery.GetValue(e.Row, (int)DELIVERY_LIST.DELIVERY_ID).ToString();
                g_DeliveryName = svDelivery.GetValue(e.Row, (int)DELIVERY_LIST.DELIVERY_NAME).ToString();
                this.DialogResult = DialogResult.OK;
                this.Close();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnSelect_Click(object sender, EventArgs e)
        {
            try
            {
                SheetView svDelivery = spdDelivery.ActiveSheet;
                int iSelect = 0;

                for (int i = 0; i < svDelivery.RowCount; i++)
                {
                    if (Convert.ToBoolean(svDelivery.Cells[i, (int)DELIVERY_LIST.CHECK].Value))
                    {
                        iSelect++;
                        g_DeliveryId = svDelivery.GetValue(i, (int)DELIVERY_LIST.DELIVERY_ID).ToString();
                        g_DeliveryName = svDelivery.GetValue(i, (int)DELIVERY_LIST.DELIVERY_NAME).ToString();
                        break;
                    }
                }

                if (iSelect <= 0)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    spdDelivery.Focus();
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

        private void txtDeliveryID_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar==(char)Keys.Enter)
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                MPCF.ClearList(spdDelivery);

                ViewDeliveryList();
            }
        }

        private void txtDeliveryName_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)Keys.Enter)
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                MPCF.ClearList(spdDelivery);

                ViewDeliveryList();
            }
        }

        private void spdDelivery_CellClick(object sender, CellClickEventArgs e)
        {
            int selected_row = 0;

            try
            {
                SheetView svDelivery = spdDelivery.ActiveSheet;
                
                if (e.ColumnHeader)
                    return;

                selected_row = e.Row;
                for (int i = 0; i < svDelivery.RowCount; i++)
                {
                    if (i == selected_row)
                    {
                        svDelivery.SetValue(i, (int)DELIVERY_LIST.CHECK, true);
                    }
                    else
                    {
                        svDelivery.SetValue(i, (int)DELIVERY_LIST.CHECK, false);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}
