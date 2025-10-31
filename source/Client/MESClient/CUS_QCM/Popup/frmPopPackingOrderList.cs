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

namespace CUS_QCM.Popup
{
    public partial class frmPopPackingOrderList : CUS_COM.frmTranForm01
    {
        public frmPopPackingOrderList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Variable Definition "
        public string s_pack_order_id = "";   //주문번호
        public string s_pack_line_no = "";     //주문라인번호
        public string s_customer_desc = ""; //고객사명
        public string s_delivery_name = "";       //SHIP_END_NAME
        public string s_mat_id = "";             //품목코드
        public string s_mat_desc = "";        //품목명
        public string s_grade = "";
        public string s_types = "";
        #endregion

        #region " Constant Definition "
        private enum PACK_ORDER
        {
            PACK_ORDER_ID,         // 1 : 포장 지시 번호
            LINE_NO,               // 2 : 포장 라인 번호
            MAT_ID,                // 3 : 제품
            MAT_VER,               // 4 : 버전
            MAT_DESC,              // 5 : 제품명
            GRADE,                  // GRADE
            TYPES,                   // TYPES
            PACK_ORD_DATE,         // 6 : 포장지시일자
            QTY,                   // 7 : 포장수량
            PACKED_QTY,            // 8 : 포장된 수량
            UNIT,                  // 9 : 단위
            PACK_ORD_STATUS,       // 10 : 포장상태
            CUSTOMER_ID,           // 11 : 최종 고객사
            CUSTOMER_DESC,     //  최종 고객사명
            CUSTOMER_SITE_ID,      // 12 : 고객사 SITE ID
            DELIVERY_ID,        //납품처
            DELIVERY_NAME,  //납품처명
            OPER,                  // 13 : 창고
            OPER_DESC,             // 14 : 창고명
            DRAWING_FLAG,          // 15 : 도면유무
            LABEL_TYPE,            // 16 : 라벨 유형
            LABEL_MESH,            // 17 : 라벨 사이즈 
            LABEL_NAME             // 18 : 라벨품명
        }

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CheckCondition(string sType)
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

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":

                        MPCF.ClearList(spdOrderList);

                        break;

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //Packing Order LIST 조회 함수
        private void ViewPackingOrderList()
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

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvPackOper.Text;

                dvcArgu[3].sCondition_ID = "MAT_ID";
                dvcArgu[3].sCondition_Value = cdvMatID.Text;

                dvcArgu[4].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[4].sCondition_Value = txtPackingOrderNo.Text;

                dvcArgu[5].sCondition_ID = "CUSTOMER_ID";
                dvcArgu[5].sCondition_Value = cdvCustomerID.Text;

                dvcArgu[6].sCondition_ID = "FROM_DATE";
                dvcArgu[6].sCondition_Value = dtpFromWorkDate.Text.Replace("-", "");

                dvcArgu[7].sCondition_ID = "TO_DATE";
                dvcArgu[7].sCondition_Value = dtpToWorkDate.Text.Replace("-", "");

                if (TPDR.GetDataOne("", ref dt, "CSHP2001-001-P1", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdOrderList);
                    return;
                }

                MPCF.ClearList(spdOrderList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdOrderList_Sheet1.RowCount++;

                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LINE_NO].Value = dt.Rows[i]["LINE_NO"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.TYPES].Value = dt.Rows[i]["TYPES"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORD_DATE].Value = dt.Rows[i]["PACK_ORD_DATE"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.QTY].Value = dt.Rows[i]["QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACKED_QTY].Value = dt.Rows[i]["PACKED_QTY"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.PACK_ORD_STATUS].Value = dt.Rows[i]["PACK_ORD_STATUS"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CUSTOMER_ID].Value = dt.Rows[i]["CUSTOMER_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CUSTOMER_DESC].Value = dt.Rows[i]["CUSTOMER_DESC"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.CUSTOMER_SITE_ID].Value = dt.Rows[i]["CUSTOMER_SITE_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DELIVERY_ID].Value = dt.Rows[i]["DELIVERY_ID"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DELIVERY_NAME].Value = dt.Rows[i]["DELIVERY_NAME"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.OPER].Value = dt.Rows[i]["OPER"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.DRAWING_FLAG].Value = dt.Rows[i]["DRAWING_FLAG"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LABEL_TYPE].Value = dt.Rows[i]["LABEL_TYPE"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LABEL_MESH].Value = dt.Rows[i]["LABEL_MESH"];
                    spdOrderList_Sheet1.Cells[i, (int)PACK_ORDER.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                }
                MPCF.FitColumnHeader(spdOrderList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void cdvPackOper_ButtonPress(object sender, EventArgs e)
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

                cdvPackOper.Init();
                MPCF.InitListView(cdvPackOper.GetListView);
                cdvPackOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvPackOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvPackOper.SelectedSubItemIndex = 0;
                cdvPackOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvPackOper.GetListView, '6', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }

                cdvPackOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                // 제품 팝업으로 변경
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMatID.Text = popup.sMat_id;
                    popup = null;
                }
                else
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvCustomerID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvCustomerID.Init();
                MPCF.InitListView(cdvCustomerID.GetListView);
                cdvCustomerID.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvCustomerID.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvCustomerID.SelectedSubItemIndex = 0;
                cdvCustomerID.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvCustomerID.GetListView, '1', CSGC.CP_GCM_CUSTOMER) == false)
                {
                    return;
                }

                cdvCustomerID.InsertEmptyRow(0, 1);
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
                if (CheckCondition("VIEW") == false)
                    return;

                ClearList("VIEW");

                ViewPackingOrderList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnProcess_Click(object sender, EventArgs e)
        {
            if (spdOrderList.ActiveSheet.ActiveRowIndex < 0)
                return;


            try
            {
                int iRow = spdOrderList.ActiveSheet.ActiveRowIndex;

                s_pack_order_id = spdOrderList.ActiveSheet.Cells[iRow, (int)PACK_ORDER.PACK_ORDER_ID].Text;
                s_pack_line_no = spdOrderList.ActiveSheet.Cells[iRow, (int)PACK_ORDER.LINE_NO].Text;
                s_customer_desc = spdOrderList.ActiveSheet.Cells[iRow, (int)PACK_ORDER.CUSTOMER_DESC].Text;
                s_delivery_name = spdOrderList.ActiveSheet.Cells[iRow, (int)PACK_ORDER.DELIVERY_NAME].Text;
                s_mat_id = spdOrderList.ActiveSheet.Cells[iRow, (int)PACK_ORDER.MAT_ID].Text;
                s_mat_desc = spdOrderList.ActiveSheet.Cells[iRow, (int)PACK_ORDER.MAT_DESC].Text;
                s_grade = spdOrderList.ActiveSheet.Cells[iRow, (int)PACK_ORDER.GRADE].Text;
                s_types = spdOrderList.ActiveSheet.Cells[iRow, (int)PACK_ORDER.TYPES].Text;

                this.DialogResult = DialogResult.OK;

                this.Close();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmPopPackingOrderList_Load(object sender, EventArgs e)
        {
            this.dtpToWorkDate.Value = DateTime.Now;
            this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
        }

        private void cdvMatID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatID.DisplayText == "")
                cdvMatID.Text = "";
        }

        private void cdvCustomerID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvCustomerID.DisplayText == "")
                cdvCustomerID.Text = "";
        }

        #endregion
    }
}
