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
    public partial class frmViewPackingLot : CUS_COM.frmViewForm01
    {
        public frmViewPackingLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT
        {
            CHK,                     // 1 : CHK
            ORG_LOT_ID,              // 2 : 공정 LOT ID
            PACK_LOT_ID,             // 3 : 포장 LOT ID     
            INSPECTION_LOT_ID,       // 4 : 검사 LOT ID               
            MAT_ID,                  // 5 : 제품
            MAT_VER,                 // 6 : 버전
            MAT_DESC,                // 7 : 제품명
            OPERATION_MAT_ID,        // 육면적때문에 추가(생산 품목코드)
            OPERATION_MAT_DESC,      // 육면적때문에 추가(생산 품명)
            QTY,                     // 8 : 수량
            UNIT,                    // 9 : 단위
            AREA_ID,                 // 10 : 사업부
            CUSTOMER_ID,             // 11 : 고객사 
            CUSTOMER_SITE_ID,        // 12 : 고객사 Site ID
            CUSTOMER_NAME,           // 13 : 고객사명
            DELIVERY_NAME,           // 14 : 납품처명
            REPORT_NO,               // 15 : 성적서 번호
            PACK_FLAG,               // 16 : 포장 여부
            PACK_LOT_CREATE_DATE,    // 17 : 포장 등록일자
            PACK_DATE,               // 18 : 포장 확정일자
            PACK_ORDER_ID,           // 19 : 포장 지시 번호
            PACK_LINE_NO,            // 20 : 포장 지시 라인 번호
            PACK_ORD_DATE,           // 21 : 포장 지시 일자
            PACKING_INSTRUCTIONS,    
            ERP_PACK_ORDER_ID,       // 22 : ERP 포장 지시 번호
            SHIP_FLAG,               // 23 : 출하 상태
            SHIP_DATE,               // 24 : 출하 일자
            SHIP_ORDER_ID,           // 25 : 출하 지시 번호
            SHIP_ORDER_SEQ,          // 26 : 출하 지시 순번
            BOX_ID_1,                // 27 : 중 박스 ID
            BOX_ID_2,                // 28 : 대 박스 ID
            CREATE_USER,
            USER_DESC
        }

        #endregion

        #region " Variable Definition "
        string file_name = "";
        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                chkMeshDeleteFlag.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblLableSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                cdvLabelSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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
                        MPCF.ClearList(spdLotList);
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
                        if (MPCF.Trim(cdvDept.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
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

        // 포장 LOT 정보 조회
        private void ViewLot()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[12];
                DataTable dt = null;
                string sSql = "";
                string sMatDesc = "";
                string sMatDesc2 = "";
                string sSqlText = "";
                string sExcludeWord = "";
                StringBuilder sb = new StringBuilder();
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;
                
                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatId.Text;

                dvcArgu[3].sCondition_ID = "CUSTOMER_ID";
                dvcArgu[3].sCondition_Value = cdvCustomerId.Text;

                dvcArgu[4].sCondition_ID = "PACK_ORDER_ID";
                dvcArgu[4].sCondition_Value = txtPackingOrderNo.Text;

                dvcArgu[5].sCondition_ID = "FROM_DATE";
                dvcArgu[5].sCondition_Value = string.Format("{0}000000", string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", ""));

                dvcArgu[6].sCondition_ID = "TO_DATE";
                dvcArgu[6].sCondition_Value = dtpToWorkDate.Text.Replace("-", "") + "235959";

                dvcArgu[7].sCondition_ID = "ORG_LOT_ID";
                dvcArgu[7].sCondition_Value = txtOrgLotId.Text;

                dvcArgu[8].sCondition_ID = "PACK_LOT_ID";
                dvcArgu[8].sCondition_Value = txtPackLotId.Text;

                dvcArgu[9].sCondition_ID = "ERP_PACK_LOT_ID";
                dvcArgu[9].sCondition_Value = txtERPPackingOrderNo.Text.Trim();

                //CSHP2001-005, LOT.SHIP_FLAG
                dvcArgu[10].sCondition_ID = "SHIP_FLAG";
                dvcArgu[10].sCondition_Value = cboxShipFlag.Text.Trim();

                //if (cboxShipFlag.Text.Trim() != "")
                //{
                //    sSqlText = sSqlText + "AND LOT.SHIP_FLAG = '" + cboxShipFlag.Text.Trim() + "'";
                //}

                //제품명 & 제품코드
                sMatDesc = txtMatDesc.Text;
                sMatDesc2 = txtMatDesc2.Text;

                if (sMatDesc != "" || sMatDesc2 != "")
                {
                    sb.Append("AND (");

                    if (!string.IsNullOrEmpty(sMatDesc))
                    {
                        sb.Append($"MAT.MAT_DESC LIKE '%' || '{sMatDesc}' || '%'");
                    }

                    if (!string.IsNullOrEmpty(sMatDesc2))
                    {
                        if (sb.Length > 6) // 첫 번째 조건이 추가된 경우
                        {
                            sb.Append(" OR ");
                        }
                        sb.Append($"MAT.MAT_DESC LIKE '%' || '{sMatDesc2}' || '%'");
                    }
                    sb.Append(")");

                    sSqlText = sSqlText + sb.ToString();       // 결과 문자열 
                }


                // 제외문자
                sExcludeWord = MPCF.Trim(txtExcludeWord.Text);
                string[] split_data = sExcludeWord.Split(new string[] { string.Format("{0}", "-") }, StringSplitOptions.RemoveEmptyEntries);
                for (int k = 0; k < split_data.Count(); k++)
                {
                    sSqlText = sSqlText + " AND MAT.MAT_DESC NOT LIKE '%' || '" + split_data[k] + "' || '%'";
                }
                dvcArgu[11].sCondition_ID = "SQL_TEXT";
                dvcArgu[11].sCondition_Type = "TEXT";

                if (sSqlText == "")
                {
                    dvcArgu[11].sCondition_Value = "AND 1=1";
                }
                else
                {
                    dvcArgu[11].sCondition_Value = sSqlText;
                }

                

                if (TPDR.GetDataOne("", ref dt, "CSHP2001-005", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLotList);
                    return;
                }

                MPCF.ClearList(spdLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Sheet1.RowCount++;

                    spdLotList_Sheet1.SetValue(i, (int)LOT.CHK, false);
                    spdLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Value = dt.Rows[i]["ORG_LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.PACK_LOT_ID].Value = dt.Rows[i]["PACK_LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.INSPECTION_LOT_ID].Value = dt.Rows[i]["CMF_2"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.CUSTOMER_ID].Value = dt.Rows[i]["CUSTOMER_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.CUSTOMER_SITE_ID].Value = dt.Rows[i]["CUSTOMER_SITE_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.CUSTOMER_NAME].Value = dt.Rows[i]["CUSTOMER_NAME"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.DELIVERY_NAME].Value = dt.Rows[i]["DELIVERY_NAME"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.REPORT_NO].Value = dt.Rows[i]["REPORT_NO"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.PACK_FLAG].Value = dt.Rows[i]["PACK_FLAG"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.PACK_LOT_CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PACK_LOT_CREATE_DATE"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdLotList_Sheet1.Cells[i, (int)LOT.PACK_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PACK_DATE"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdLotList_Sheet1.Cells[i, (int)LOT.PACK_ORDER_ID].Value = dt.Rows[i]["PACK_ORDER_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.PACK_LINE_NO].Value = dt.Rows[i]["PACK_LINE_NO"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.PACK_ORD_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PACK_ORD_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdLotList_Sheet1.Cells[i, (int)LOT.PACKING_INSTRUCTIONS].Value = dt.Rows[i]["PACKING_INSTRUCTIONS"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.ERP_PACK_ORDER_ID].Value = dt.Rows[i]["CMF_5"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.SHIP_FLAG].Value = dt.Rows[i]["SHIP_FLAG"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.SHIP_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["SHIP_DATE"].ToString(), DATE_TIME_FORMAT.DATETIME); ;
                    spdLotList_Sheet1.Cells[i, (int)LOT.SHIP_ORDER_ID].Value = dt.Rows[i]["SHIP_ORDER_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.SHIP_ORDER_SEQ].Value = dt.Rows[i]["SHIP_ORDER_SEQ"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.BOX_ID_1].Value = dt.Rows[i]["BOX_ID_1"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.BOX_ID_2].Value = dt.Rows[i]["BOX_ID_2"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.CREATE_USER].Value = dt.Rows[i]["CREATE_USER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.USER_DESC].Value = dt.Rows[i]["USER_DESC"];


                    //HM은 성적서 필수라서 색깔 빨간색 표기
                    if (spdLotList_Sheet1.Cells[i, (int)LOT.AREA_ID].Text == "HM" && spdLotList_Sheet1.Cells[i, (int)LOT.REPORT_NO].Text =="")
                    {
                            spdLotList_Sheet1.Rows[i].BackColor = Color.OrangeRed;
                    }

                }
                MPCF.FitColumnHeader(spdLotList);
                

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public bool ViewPrintLabel(string sFileName, TRSNode in_node)
        {
            try
            {
                CSCF.ViewLabelList(sFileName, in_node);

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
        private void dtpFromWorkDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";
        }
        private void frmViewPackingLot_Load(object sender, EventArgs e)
        {
            try
            {
                chkMeshDeleteFlag.Checked = false;
                dtpToWorkDate.Value = DateTime.Now;
                //dtpFromWorkDate.Value = DateTime.Now;
                //dtpFromWorkDate.CustomFormat = " ";
                dtpFromWorkDate.Value = DateTime.Now.AddDays(-7);
                dtpFromWorkDate.Format = DateTimePickerFormat.Custom;
                           

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
                cdvMatId.Text = "";
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

                ClearData("VIEW");
                ViewLot();
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvCustomerId_ButtonPress(object sender, EventArgs e)
        {
            //고객사 팝업으로 변경
            try
            {
                frmPopCustomerList popup = new frmPopCustomerList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvCustomerId.Text = popup.g_CustomerId;
                    this.cdvCustomerId.DisplayText = popup.g_CustomerDesc;
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

        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (spdLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdLotList, e.Row, e.Column, true, true, false);
                    }
                }
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                { 
                 //   EXTFUC.SetSelectRowColor(spdLotList, e.Row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvLabelSize_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvLabelSize.Init();
                MPCF.InitListView(cdvLabelSize.GetListView);
                cdvLabelSize.Columns.Add("Size", 50, HorizontalAlignment.Left);
                cdvLabelSize.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvLabelSize.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvLabelSize.SelectedSubItemIndex = 2;
                cdvLabelSize.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewLabelGCMList(cdvLabelSize.GetListView, cdvDept.Text, CSGC.CP_LABEL_TYPE_SHIP) == false)
                {
                    return;
                }

                cdvLabelSize.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvLabelSize.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLableSize.Text + "]");
                    cdvLabelSize.Focus();
                    return;
                }

                bool label_flag = false;
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");

                MPCR.SetInMsg(in_node);
                in_node.AddChar("MESH_DELETE_FLAG", chkMeshDeleteFlag.Checked == true ? 'Y' : 'N');

                for (int i = 0; i < spdLotList_Sheet1.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        label_list = in_node.AddNode("PACK_LOT_LIST");
                        label_list.AddString("PACK_LOT_ID", spdLotList_Sheet1.Cells[i, (int)LOT.PACK_LOT_ID].Text);
                        label_list.AddString("ORG_LOT_ID", spdLotList_Sheet1.Cells[i, (int)LOT.ORG_LOT_ID].Text);

                        label_flag = true;
                    }
                }
                
                if(label_flag == true)
                {
                    file_name = cdvLabelSize.Text;

                    if (ViewPrintLabel(file_name, in_node))
                    {

                    }
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
                EXTFUC.SaveExcel(spdLotList, "PackLotList");
               
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if(cdvMatId.DisplayText == "")
                cdvMatId.Text = "";
        }

        private void cdvCustomerId_TextBoxTextChanged(object sender, EventArgs e)
        {

            if (cdvCustomerId.DisplayText == "")
                cdvCustomerId.Text = "";
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

        private void txtERPPackingOrderNo_KeyPress(object sender, KeyPressEventArgs e)
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

        private void txtPackingOrderNo_KeyPress(object sender, KeyPressEventArgs e)
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

        private void txtOrgLotId_KeyPress(object sender, KeyPressEventArgs e)
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

        private void txtPackLotId_KeyPress(object sender, KeyPressEventArgs e)
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

        #endregion


    }
}
