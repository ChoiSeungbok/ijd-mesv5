using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Miracom.DNMCore;

namespace CUS_COM
{
    public partial class frmViewSqlSample : frmViewForm01
    {
        public frmViewSqlSample()
        {
            InitializeComponent();
        }

        private enum Lot
        {
            LOT_ID,
            OPER
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
            string sSql = "";
            DataTable dt = null;

            dvcArgu[0].sCondition_ID = "LOT_ID";
            dvcArgu[0].sCondition_Value = txtLotID.Text;

            dvcArgu[1].sCondition_ID = "OPER";
            dvcArgu[1].sCondition_Value = txtLotID.Text;

            if (TPDR.GetDataOne("", ref dt, "TEST-001", dvcArgu, false, false, ref sSql) == false)
            {
                if (dt != null)
                    dt.Dispose();

                GC.Collect();
            }

            fpSpread1_Sheet1.DataSource = dt;
        }

        private void btnView2_Click(object sender, EventArgs e)
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
            string sSql = "";
            DataTable dt = null;
            int i = 0;

            dvcArgu[0].sCondition_ID = "LOT_ID";
            dvcArgu[0].sCondition_Value = txtLotID.Text;

            dvcArgu[1].sCondition_ID = "OPER";
            dvcArgu[1].sCondition_Value = txtLotID.Text;

            if (TPDR.GetDataOne("", ref dt, "TEST-001", dvcArgu, false, false, ref sSql) == false)
            {
                if (dt != null)
                    dt.Dispose();

                GC.Collect();
            }

            fpSpread1_Sheet1.RowCount = 0;
            
            for(i = 0; i < dt.Rows.Count; i++)
            {
                fpSpread1_Sheet1.RowCount++;
                fpSpread1_Sheet1.Cells[i, 0].Value = dt.Rows[0]["FACTORY"].ToString();
                fpSpread1_Sheet1.Cells[i, (int)Lot.LOT_ID].Value = dt.Rows[0]["LOT_ID"].ToString();
                fpSpread1_Sheet1.Cells[i, 2].Value = dt.Rows[0]["LOT_DESC"].ToString();
                fpSpread1_Sheet1.Cells[i, 3].Value = dt.Rows[0]["FLOW"].ToString();
                fpSpread1_Sheet1.Cells[i, 4].Value = dt.Rows[0]["OPER"].ToString();
                fpSpread1_Sheet1.Cells[i, 5].Value = dt.Rows[0]["MAT_ID"].ToString();
            }
        }
    }
}
