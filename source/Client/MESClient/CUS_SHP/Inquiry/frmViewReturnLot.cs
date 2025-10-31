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
using FarPoint.Win.Spread;

namespace CUS_SHP
{
    public partial class frmViewReturnLot : CUS_COM.frmViewForm01
    {
        public frmViewReturnLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "
        private enum RET_LOT
        {
            RET_ORDER_ID,            // 1 : 반품 지시 번호
            LOT_ID,                  // 2 : LOT ID
            RET_LOT_ID,              // 3 : 반품 LOT ID
            MAT_ID,                  // 4 : 제품
            MAT_VER,                 // 5 : 버전
            MAT_DESC,                // 6 : 제품명
            QTY,                     // 7 : 수량
            UNIT,                    // 8 : 단위
            RET_DATE,                // 9 : 반품 일자
            RET_LINE_NO,             // 10 : 반품 라인 번호
            AREA_ID,                 // 11 : 사업부
            CUSTOMER_ID,             // 12 : 고객사 ID
            CUSTOMER_NAME,           // 13 : 고객사명
            PACK_DATE,               // 14 : 포장 일자
            PACK_ORDER_ID,           // 15 : 포장 지시 번호
            PACK_LINE_NO,            // 16 : 포장 라인 번호
            ERP_PACK_ORDER_ID,       // 17 : ERP 포장 지시 번호
            SHIP_DATE,               // 18 : 출자 일자
            SHIP_ORDER_ID,           // 19 : 출하 지시 번호
            SHIP_ORDER_SEQ,           // 20 : 출하 지시 순번
            COMMENT,
            COMMENT_BTN,
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
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;


                this.dtpToWorkDate.Value = DateTime.Now;
                this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //반품 Lot 정보 조회
        private bool ViewReturnLotList()
        {
            TRSNode in_node = new TRSNode("view_return_lot_list_In");
            TRSNode out_node = new TRSNode("view_return_lot_list_Out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("MAT_ID", cdvMatId.Text);
                in_node.AddString("CUSTOMER_ID", cdvCustomerID.Text);
                in_node.AddString("RET_ORDER_ID", txtReturnOrderNo.Text);
                in_node.AddString("FROM_DATE", string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", "")));
                in_node.AddString("TO_DATE", dtpToWorkDate.Text.Replace("-", "") + "235959");

                if (MPCR.CallService("CUS_SHP", "CUS_SHP_View_Return_Lot_List", in_node, ref out_node) == false)
                    return false;

                MPCF.ClearList(spdReturnLotList);

                for (int i = 0; i < out_node.GetList(0).Count; i++)
                {
                    spdReturnLotList_Sheet1.RowCount++;

                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.RET_ORDER_ID].Value = out_node.GetList(0)[i].GetString("RET_ORDER_ID");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.LOT_ID].Value = out_node.GetList(0)[i].GetString("LOT_ID");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.RET_LOT_ID].Value = out_node.GetList(0)[i].GetString("RET_LOT_ID");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.MAT_ID].Value = out_node.GetList(0)[i].GetString("MAT_ID");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.MAT_VER].Value = out_node.GetList(0)[i].GetInt("MAT_VER");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.MAT_DESC].Value = out_node.GetList(0)[i].GetString("MAT_DESC");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.QTY].Value = out_node.GetList(0)[i].GetDouble("QTY");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.UNIT].Value = out_node.GetList(0)[i].GetString("UNIT");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.RET_DATE].Value = MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("RET_DATE"), DATE_TIME_FORMAT.DATE);
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.RET_LINE_NO].Value = out_node.GetList(0)[i].GetInt("RET_LINE_NO");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.AREA_ID].Value = out_node.GetList(0)[i].GetString("AREA_ID");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.CUSTOMER_ID].Value = out_node.GetList(0)[i].GetString("CUSTOMER_ID");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.CUSTOMER_NAME].Value = out_node.GetList(0)[i].GetString("CUSTOMER_NAME");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.PACK_DATE].Value = MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("PACK_DATE"), DATE_TIME_FORMAT.DATE);
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.PACK_ORDER_ID].Value = out_node.GetList(0)[i].GetString("PACK_ORDER_ID");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.PACK_LINE_NO].Value = out_node.GetList(0)[i].GetInt("PACK_LINE_NO");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.ERP_PACK_ORDER_ID].Value = out_node.GetList(0)[i].GetString("CMF_1");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.SHIP_DATE].Value = MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("SHIP_DATE"), DATE_TIME_FORMAT.DATE);
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.SHIP_ORDER_ID].Value = out_node.GetList(0)[i].GetString("SHIP_ORDER_ID");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.SHIP_ORDER_SEQ].Value = out_node.GetList(0)[i].GetDouble("SHIP_ORDER_SEQ");
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.COMMENT].Value = out_node.GetList(0)[i].GetDouble("COMMENT");
                }

                MPCF.FitColumnHeader(spdReturnLotList);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }



        private bool ViewReturnLotList2()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                // int ichk = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatId.Text;

                dvcArgu[3].sCondition_ID = "CUSTOMER_ID";
                dvcArgu[3].sCondition_Value = cdvCustomerID.Text;

                dvcArgu[4].sCondition_ID = "RET_ORDER_ID";
                dvcArgu[4].sCondition_Value = txtReturnOrderNo.Text;

                dvcArgu[5].sCondition_ID = "FROM_DATE";
                dvcArgu[5].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));

                dvcArgu[6].sCondition_ID = "TO_DATE";
                dvcArgu[6].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";




                if (TPDR.GetDataOne("", ref dt, "CSHP3003-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdReturnLotList);
                    return false;
                }

                MPCF.ClearList(spdReturnLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdReturnLotList.ActiveSheet.RowCount++;


                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.RET_ORDER_ID].Value = dt.Rows[i]["RET_ORDER_ID"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.RET_LOT_ID].Value = dt.Rows[i]["RET_LOT_ID"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.RET_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["RET_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.RET_LINE_NO].Value = dt.Rows[i]["RET_LINE_NO"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.CUSTOMER_ID].Value = dt.Rows[i]["CUSTOMER_ID"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.CUSTOMER_NAME].Value = dt.Rows[i]["CUSTOMER_NAME"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.PACK_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PACK_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.PACK_LINE_NO].Value = dt.Rows[i]["PACK_LINE_NO"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.ERP_PACK_ORDER_ID].Value = dt.Rows[i]["ERP_PACK_ORDER_ID"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.SHIP_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["SHIP_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.SHIP_ORDER_ID].Value = dt.Rows[i]["SHIP_ORDER_ID"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.SHIP_ORDER_SEQ].Value = dt.Rows[i]["SHIP_ORDER_SEQ"];
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.COMMENT].Value = dt.Rows[i]["RET_COMMENT"]; ;
                    spdReturnLotList_Sheet1.Cells[i, (int)RET_LOT.COMMENT].Locked = false ;

                }
                this.spdReturnLotList_Sheet1.OperationMode = FarPoint.Win.Spread.OperationMode.Normal;



                MPCF.FitColumnHeader(spdReturnLotList_Sheet1);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //초기화 함수
        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "ALL":

                        cdvDept.Text = "";
                        cdvMatId.Text = "";
                        cdvCustomerID.Text = "";
                        txtReturnOrderNo.Text = "";
                        this.dtpToWorkDate.Value = DateTime.Now;
                        this.dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);

                        MPCF.ClearList(spdReturnLotList);
                        break;

                    case "VIEW":

                        MPCF.ClearList(spdReturnLotList);
                        break;

                    case "CLICK_DEPT":

                        cdvMatId.Text = "";
                        cdvCustomerID.Text = "";
                        txtReturnOrderNo.Text = "";

                        MPCF.ClearList(spdReturnLotList);
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //벨리데이션 체크
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

                if (MPCF.Trim(dtpFromWorkDate.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDate.Text + "]");
                    dtpFromWorkDate.Focus();
                    return false;
                }

                if (MPCF.Trim(dtpToWorkDate.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDate.Text + "]");
                    dtpToWorkDate.Focus();
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
        #endregion

        #region " Event Definition "
        private void frmViewReturnLot_Load(object sender, EventArgs e)
        {
            try
            {
                dtpToWorkDate.Value = DateTime.Now;
                dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-7);
                //  dtpFromWorkDate.Format = DateTimePickerFormat.Custom;
                //  dtpFromWorkDate.CustomFormat = " ";

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtReturnOrderNo_KeyPress(object sender, KeyPressEventArgs e)
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

        private void dtpFromWorkDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";
        }
        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                ClearList("ALL");
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

                if (ViewReturnLotList2())
                {
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMatId.Text = popup.sMat_id;
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
            //고객사 팝업으로 변경
            try
            {
                frmPopCustomerList popup = new frmPopCustomerList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvCustomerID.Text = popup.g_CustomerId;
                    this.cdvCustomerID.DisplayText = popup.g_CustomerDesc;
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

        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Init();
                MPCF.InitListView(cdvDept.GetListView);
                cdvDept.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvDept.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDept.SelectedSubItemIndex = 0;
                cdvDept.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDept.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                ClearList("CLICK_DEPT");
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
                EXTFUC.SaveExcel(spdReturnLotList, "PackReturnLot");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }


        private void cdvMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatId.DisplayText == "")
                cdvMatId.Text = "";
        }

        private void cdvCustomerID_TextBoxTextChanged(object sender, EventArgs e)
        {

            if (cdvCustomerID.DisplayText == "")
                cdvCustomerID.Text = "";
        }

        private void spdReturnLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                /*
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdReturnLotList, e.Row);
                }
                */
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void dtpFromWorkDate_ValueChanged(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";

        }
        private void dtpFromWorkDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtpFromWorkDate.CustomFormat = " ";
                    break;
            }

        }

        #endregion

        private void spdReturnLotList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            try
            {

                switch (e.Column)
                {
                    case (int)RET_LOT.COMMENT_BTN:
                        TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                        DataTable dt = null;
                        string sSql = "";
                        int i = 0;
                        // int ichk = 0;
                        string sTranComment = " ";


                        if((spdReturnLotList_Sheet1.Cells[spdReturnLotList_Sheet1.ActiveRowIndex, (int)RET_LOT.COMMENT].Text.Length) != 0)
                        {
                            sTranComment = spdReturnLotList_Sheet1.Cells[spdReturnLotList_Sheet1.ActiveRowIndex, (int)RET_LOT.COMMENT].Text;
                        }

                        dvcArgu[0].sCondition_ID = "FACTORY";
                        dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                        dvcArgu[1].sCondition_ID = "LOT_ID";
                        dvcArgu[1].sCondition_Value = spdReturnLotList_Sheet1.Cells[spdReturnLotList_Sheet1.ActiveRowIndex, (int)RET_LOT.LOT_ID].Text;

                        dvcArgu[2].sCondition_ID = "TRAN_COMMENT";
                        dvcArgu[2].sCondition_Value = sTranComment;


                        if (TPDR.GetDataOne("", ref dt, "CSHP3003-002", dvcArgu, false, false, ref sSql) == false)
                        {
                            if (dt != null)
                                dt.Dispose();

                            GC.Collect();

                            MPCF.ClearList(spdReturnLotList);
                            return;
                        }

                        break;
                }



            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

        }
    }
}
