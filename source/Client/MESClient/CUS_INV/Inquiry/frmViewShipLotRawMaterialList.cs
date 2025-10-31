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

namespace CUS_INV
{
    public partial class frmViewShipLotRawMaterialList : CUS_COM.frmViewForm01
    {
        public frmViewShipLotRawMaterialList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum INV_LOT : int
        {
            INV_LOT_ID,             // 1. 자재 LOT ID
            MAT_ID,                 // 2. 제품
            MAT_VER,                // 3. 제품버전
            MAT_DESC,               // 4. 제품명
            QTY,                    // 5. BOM 환산 수량
            UNIT,                   // 6. 단위
            VENDOR_DESC,            // 7. 업체명
            RECV_DATE,              // 8. 입고 일자
            PO_NO,                  // 9. PO 번호
            PO_SEQ                  // 10. PO 순번
        }

        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 초기화
        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //벨리데이션 체크
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        if (MPCF.Trim(txtLotID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotId.Text + "]");
                            txtLotID.Focus();
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

        // 출하 Lot 원자재 리스트 조회
        public void ViewShipLotRawMatList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = txtLotID.Text;
                
                if (TPDR.GetDataOne("", ref dt, "CINV3012-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdRawMatList);
                    return;
                }

                MPCF.ClearList(spdRawMatList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdRawMatList_Sheet1.RowCount++;

                    spdRawMatList_Sheet1.Cells[i, (int)INV_LOT.INV_LOT_ID].Value = dt.Rows[i]["INV_LOT_ID"];
                    spdRawMatList_Sheet1.Cells[i, (int)INV_LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdRawMatList_Sheet1.Cells[i, (int)INV_LOT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdRawMatList_Sheet1.Cells[i, (int)INV_LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdRawMatList_Sheet1.Cells[i, (int)INV_LOT.QTY].Value = dt.Rows[i]["BOM_QTY"];
                    spdRawMatList_Sheet1.Cells[i, (int)INV_LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdRawMatList_Sheet1.Cells[i, (int)INV_LOT.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdRawMatList_Sheet1.Cells[i, (int)INV_LOT.RECV_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["RECV_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdRawMatList_Sheet1.Cells[i, (int)INV_LOT.PO_NO].Value = dt.Rows[i]["PO_NO"];
                    spdRawMatList_Sheet1.Cells[i, (int)INV_LOT.PO_SEQ].Value = dt.Rows[i]["PO_SEQ"];
                }

                MPCF.FitColumnHeader(spdRawMatList);

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
            if (CheckCondition(CSGC.CHECK.VIEW) == false)
                return;

            ViewShipLotRawMatList();
        }

        private void txtInvLotID_KeyDown(object sender, KeyEventArgs e)
        {
            try
            {
                if (e.KeyCode == Keys.Enter)
                {
                    if (CheckCondition(CSGC.CHECK.VIEW) == false)
                        return;

                    ViewShipLotRawMatList();

                    txtLotID.SelectAll();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdRawMatList, "ShipLotRawMaterialList");
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void spdRawMatList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdRawMatList, e.Row);
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void frmViewShipLotRawMaterialList_Load(object sender, EventArgs e)
        {
            try
            {
                MPCF.FitColumnHeader(spdRawMatList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}
