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
    public partial class frmViewKittingInvLotList : CUS_COM.frmViewForm01
    {
        public frmViewKittingInvLotList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT
        {
            CHK,                // 1 : CHK
            KITTING_ID,         // 2 : KITTING ID (INV_CMF_4)
            INV_LOT_ID,         // 1 : 자재 LOT ID
            INV_LOT_TYPE,       // 2 : 자재 LOT 타입
            MAT_ID,             // 3 : 제품
            MAT_VER,            // 4 : 버전
            MAT_DESC,           // 5 : 제품명
            QTY,                // 6 : 수량
            UNIT,               // 7 : 단위
            RECV_DATE,          // 8 : 입고일자
            ORDER_ID,           // 9 : 작업 지시 번호
            VENDOR_ID,          // 10 : 업체
            VENDOR_DESC,        // 11 : 업체명
            VENDOR_SITE_ID,     // 12 : 업체 SITE ID
            VENDOR_LOT_ID,      // 13 : 업체 LOT ID
            AREA_ID,            // 14 : 사업부
            SUB_AREA_ID,        // 15 : 작업장
            OPER,               // 16 : 창고
            OPER_DESC,          // 17 : 창고명
            LOAD_SUB_AREA_ID,   // 18 : 투입 작업장
            LOAD_OPER,          // 19 : 투입 공정
            LOAD_OPER_DESC,     // 20 : 투입 공정명
            HOLD_FLAG,          // 21 : 잠금여부
            INV_CMF_1,          // 22 : 금형 모델
            INV_CMF_2           // 23 : 금형 구분
        }

        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
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
                        cdvOper.Text = "";
                        txtInvLotID.Text = "";
                        txtKittingID.Text = "";

                        MPCF.ClearList(spdKittingList);
                        break;

                    case "VIEW":

                        MPCF.ClearList(spdKittingList);
                        break;

                    case "CLICK_DEPT":
                        
                        cdvOper.Text = "";

                        MPCF.ClearList(spdKittingList);
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

                switch (sType)
                {
                    case "PRINT":
                        if (spdKittingList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
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

        // Kitting LOT 리스트 조회
        public bool ViewKittingList()
        {
            try
            {
                DataTable dt = null;
                string sSql = "";
                string kittingID = "";
                int i = 0;

                if (string.IsNullOrEmpty(txtInvLotID.Text))
                {
                    TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                    
                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                    dvcArgu[1].sCondition_ID = "AREA_ID";
                    dvcArgu[1].sCondition_Value = cdvDept.Text;

                    dvcArgu[2].sCondition_ID = "OPER";
                    dvcArgu[2].sCondition_Value = cdvOper.Text;

                    dvcArgu[3].sCondition_ID = "INV_LOT_ID";
                    dvcArgu[3].sCondition_Value = txtInvLotID.Text;

                    dvcArgu[4].sCondition_ID = "KITTING_ID";
                    dvcArgu[4].sCondition_Value = txtKittingID.Text;

                    if (TPDR.GetDataOne("", ref dt, "CINV3009-001", dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt != null)
                            dt.Dispose();

                        GC.Collect();

                        MPCF.ClearList(spdKittingList);
                        return false;
                    }
                }
                else
                {
                    TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];

                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                    dvcArgu[1].sCondition_ID = "AREA_ID";
                    dvcArgu[1].sCondition_Value = cdvDept.Text;

                    dvcArgu[2].sCondition_ID = "INV_LOT_ID";
                    dvcArgu[2].sCondition_Value = txtInvLotID.Text;

                    if (TPDR.GetDataOne("", ref dt, "CINV3009-002", dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt != null)
                            dt.Dispose();

                        GC.Collect();

                        MPCF.ClearList(spdKittingList);
                        return false;
                    }
                }

                MPCF.ClearList(spdKittingList);

                FarPoint.Win.Spread.CellType.CheckBoxCellType checkBox = new FarPoint.Win.Spread.CellType.CheckBoxCellType();

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdKittingList_Sheet1.RowCount++;
                    
                    spdKittingList_Sheet1.SetValue(i, (int)LOT.CHK, false);
                    spdKittingList_Sheet1.Cells[i, (int)LOT.KITTING_ID].Value = dt.Rows[i]["INV_CMF_4"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Value = dt.Rows[i]["INV_LOT_ID"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.INV_LOT_TYPE].Value = dt.Rows[i]["INV_LOT_TYPE"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.RECV_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["RECV_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdKittingList_Sheet1.Cells[i, (int)LOT.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.VENDOR_ID].Value = dt.Rows[i]["VENDOR_ID"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.VENDOR_SITE_ID].Value = dt.Rows[i]["VENDOR_SITE_ID"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_ID"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.OPER].Value = dt.Rows[i]["OPER"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.LOAD_SUB_AREA_ID].Value = dt.Rows[i]["INV_CMF_8"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.LOAD_OPER].Value = dt.Rows[i]["INV_CMF_9"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.LOAD_OPER_DESC].Value = dt.Rows[i]["LOAD_OPER_DESC"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.HOLD_FLAG].Value = dt.Rows[i]["HOLD_FLAG"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.INV_CMF_1].Value = dt.Rows[i]["INV_CMF_1"];
                    spdKittingList_Sheet1.Cells[i, (int)LOT.INV_CMF_2].Value = dt.Rows[i]["INV_CMF_2"];

                    if (string.IsNullOrEmpty(kittingID) || !string.Equals(kittingID, dt.Rows[i]["INV_CMF_4"].ToString()))
                    {
                        kittingID = dt.Rows[i]["INV_CMF_4"].ToString();
                        spdKittingList_Sheet1.Cells[i, (int)LOT.CHK].CellType = checkBox;
                        spdKittingList_Sheet1.SetValue(i, (int)LOT.CHK, false);
                    }
                    else if (string.Equals(kittingID, dt.Rows[i]["INV_CMF_4"].ToString()))
                    {
                        spdKittingList_Sheet1.SetValue(i, (int)LOT.CHK, "");
                        spdKittingList_Sheet1.AddSpanCell(i-1, (int)LOT.CHK, i+1, 1);
                        spdKittingList_Sheet1.AddSpanCell(i-1, (int)LOT.KITTING_ID, i+1, 1);
                        
                    }
                }

                MPCF.FitColumnHeader(spdKittingList);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        #endregion

        #region Event
        private void frmViewKittingInvLotList_Load(object sender, EventArgs e)
        {
            try
            {
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

        private void cdvOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, '7', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }

                cdvOper.InsertEmptyRow(0, 1);
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

                ViewKittingList();
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
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

        private void spdKittingList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (spdKittingList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdKittingList, e.Row, e.Column, true, true, false);
                    }
                }
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdKittingList, e.Row);
                }
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
                if (CheckCondition("PRINT") == false)
                    return;

                TRSNode in_node = new TRSNode("print_label_Request_In");
                TRSNode out_node = new TRSNode("print_label_Request_Out");
                TRSNode kitting_List;
                string sFileName = "kittingLabel";

                MPCR.SetInMsg(in_node);

                for (int i = 0; i < spdKittingList_Sheet1.RowCount; i++)
                {
                    if (spdKittingList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        kitting_List = in_node.AddNode("KITTING_LIST");
                        kitting_List.AddString("KITTING_ID", spdKittingList_Sheet1.Cells[i, (int)LOT.KITTING_ID].Text);
                    }
                }

                //라벨 출력
                CSCF.ViewLabelList(sFileName, in_node, 'I');
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        private void txtInvLotID_KeyPress(object sender, KeyPressEventArgs e)
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

        private void txtKittingID_KeyPress(object sender, KeyPressEventArgs e)
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

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdKittingList, "KittingInvLotList");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }
    }
}
