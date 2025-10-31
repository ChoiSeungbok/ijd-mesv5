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

namespace CUS_WIP
{
    public partial class frmWIPViewOperLotList : CUS_COM.frmViewForm01
    {
        public frmWIPViewOperLotList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT_INFO
        {
            CHK,                    // 1 : CHK
            LOT_ID,                 // 2 : LOT ID
            MAT_TYPE,               // 3 : 제품타입
            MAT_TYPE_DESC,          // 4 : 제품 타입명
            MAT_ID,                 // 5 : 제품코드
            MAT_DESC,               // 6 : 제품명            
            PROD_QTY,               // 7 : 생산수량
            WORK_TYPE,              // 8 : 작업 타입
            AREA_ID,                // 9 : 사업부
            SUB_AREA_ID,            // 10 : 사업장
            ORDER_ID,               // 11 : 작업지시
            ORDER_STATUS,           // 12 : 작업지시 상태 
            INPUT_STATUS,           // 13 : 투입 여부
            GROUP_ID,               // 14 : 그룹 ID
            CREATE_TIME,            // 15 :  생성 시간
            COMMENT
        }

        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                lblLabel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                cdvLabel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewOperLotList()
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

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvOper.Text;

                dvcArgu[4].sCondition_ID = "ORDER_ID";
                dvcArgu[4].sCondition_Value = cdvOrder.Text + "%";

                dvcArgu[5].sCondition_ID = "MAT_TYPE";
                dvcArgu[5].sCondition_Value = cdvMatType.Text + "%";

                dvcArgu[6].sCondition_ID = "MAT_ID";
                dvcArgu[6].sCondition_Value = cdvMat.Text + "%";

                dvcArgu[7].sCondition_ID = "LOT_ID";
                dvcArgu[7].sCondition_Value = txtLotID.Text + "%";

                if (TPDR.GetDataOne("", ref dt, "CWIP3007-001", dvcArgu, false, false, ref sSql) == false)
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
                    spdLotList.ActiveSheet.RowCount++;

                    spdLotList.ActiveSheet.SetValue(i, (int)LOT_INFO.CHK, false);
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_TYPE].Value = dt.Rows[i]["MAT_TYPE"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_TYPE_DESC].Value = dt.Rows[i]["MAT_TYPE_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Value = dt.Rows[i]["PROD_QTY"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.WORK_TYPE].Value = dt.Rows[i]["WORK_TYPE"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.AREA_ID].Value = dt.Rows[i]["AREA_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.ORDER_STATUS].Value = dt.Rows[i]["ORDER_STATUS"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.INPUT_STATUS].Value = dt.Rows[i]["INPUT_STATUS"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.GROUP_ID].Value = dt.Rows[i]["GROUP_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CREATE_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.COMMENT].Value = dt.Rows[i]["LAST_COMMENT"];
                }
                MPCF.FitColumnHeader(spdLotList);

                return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CheckCondition(CSGC.CHECK CHECK)
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

                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return false;
                }

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

        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "ALL":

                        cdvWorkPlace.Text = "";
                        cdvOper.Text = "";
                        cdvOrder.Text = "";
                        cdvMatType.Text = "";
                        cdvMat.Text = "";
                        cdvLabel.Text = "";
                        txtLotID.Text = "";

                        MPCF.ClearList(spdLotList);

                        break;

                    case "VIEW":

                        MPCF.ClearList(spdLotList);

                        break;

                    case "AREA":
                        
                        cdvWorkPlace.Text = "";
                        cdvOper.Text = "";
                        cdvOrder.Text = "";
                        cdvMatType.Text = "";
                        cdvMat.Text = "";
                        cdvLabel.Text = "";
                        txtLotID.Text = "";

                        MPCF.ClearList(spdLotList);

                        break;

                    case "SUB_AREA":

                        cdvOper.Text = "";
                        cdvOrder.Text = "";
                        cdvMatType.Text = "";
                        cdvMat.Text = "";
                        txtLotID.Text = "";

                        MPCF.ClearList(spdLotList);

                        break;

                    case "OPER":

                        cdvOrder.Text = "";
                        cdvMatType.Text = "";
                        cdvMat.Text = "";
                        txtLotID.Text = "";

                        MPCF.ClearList(spdLotList);

                        break;

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "
        
        private void frmWIPViewOperLotList_Load(object sender, EventArgs e)
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

                //특정 사업부인 경우 Tag에 저장된 사업부를 제외하고 보이지 않기 위해
                if (MPCF.Trim(cdvDept.Tag) != "")
                {
                    for (int i = cdvDept.GetListView.Items.Count; i > 0; i--)
                    {
                        if (cdvDept.GetListView.Items[i - 1].SubItems[0].Text != cdvDept.Tag.ToString())
                        {
                            cdvDept.GetListView.Items[i - 1].Remove();
                        }
                    }
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
                ClearData("AREA");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkPlace_ButtonPress(object sender, EventArgs e)
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

                cdvWorkPlace.Init();
                MPCF.InitListView(cdvWorkPlace.GetListView);
                cdvWorkPlace.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWorkPlace.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWorkPlace.SelectedSubItemIndex = 0;
                cdvWorkPlace.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList_AREA(cdvWorkPlace.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, cdvDept.Text) == false)
                {
                    return;
                }

                //특정 사업장인 경우 Tag에 저장된 사업부를 제외하고 보이지 않기 위해
                if (MPCF.Trim(cdvWorkPlace.Tag) != "")
                {
                    for (int i = cdvWorkPlace.GetListView.Items.Count; i > 0; i--)
                    {
                        if (cdvWorkPlace.GetListView.Items[i - 1].SubItems[0].Text != cdvWorkPlace.Tag.ToString())
                        {
                            cdvWorkPlace.GetListView.Items[i - 1].Remove();
                        }
                    }
                }

                cdvWorkPlace.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkPlace_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                ClearData("SUB_AREA");
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
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return;
                }

                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, 'I', cdvDept.Text, cdvWorkPlace.Text) == false)
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

        private void cdvOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                ClearData("OPER");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOrder_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }

                CUS_COM.Popup.frmPopWorkOrderList popup = new CUS_COM.Popup.frmPopWorkOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_AreaCode = cdvDept.Text;
                popup.g_AreaDesc = cdvDept.DisplayText;
                popup.g_SubAreaCode = cdvWorkPlace.Text;
                popup.g_SubAreaDesc = cdvWorkPlace.DisplayText;
                popup.g_OperCode = cdvOper.Text;
                popup.g_OperDesc = cdvOper.DisplayText;
                popup.g_WorkOrder = cdvOrder.Text;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvOrder.Text = popup.g_WorkOrder;
                    popup = null;
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvMatType.Init();
                MPCF.InitListView(cdvMatType.GetListView);
                cdvMatType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvMatType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvMatType.SelectedSubItemIndex = 0;
                cdvMatType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvMatType.GetListView, '1', MPGC.MP_WIP_MATERIAL_TYPE) == false)
                {
                    return;
                }

                cdvMatType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMat_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvMat.Text = popup.sMat_id;
                    cdvMat.DisplayText = popup.sMat_Desc;
                    popup = null;
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvLabel_ButtonPress(object sender, EventArgs e)
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

                cdvLabel.Init();
                MPCF.InitListView(cdvLabel.GetListView);
                cdvLabel.Columns.Add("Size", 50, HorizontalAlignment.Left);
                cdvLabel.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvLabel.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvLabel.SelectedSubItemIndex = 2;
                cdvLabel.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewLabelGCMList(cdvLabel.GetListView, cdvDept.Text, CSGC.CP_LABEL_TYPE_OPER) == false)
                {
                    return;
                }

                cdvLabel.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                btnView.PerformClick();
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

                ViewOperLotList();
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
                FpSpread excelSp = new FpSpread();
                SheetView sheet1 = new SheetView();
                SheetView sheet2 = new SheetView();

                string sFileName = EXTFUC.ShowFileOpenDialog(cdvOper.DisplayText);

                if (String.IsNullOrEmpty(sFileName))
                {
                    return;
                }

                sheet1 = spdLotList_Sheet1;
                sheet1.SheetName = cdvOper.DisplayText;
                sheet1.ColumnCount = spdLotList_Sheet1.ColumnCount;
                sheet1.RowCount = spdLotList_Sheet1.RowCount;
                sheet1.Protect = false;
                excelSp.Sheets.Add(sheet1);

                excelSp.SaveExcel(sFileName, FarPoint.Excel.ExcelSaveFlags.SaveCustomColumnHeaders);

                MPCF.ShowMsgBox(MPCF.GetMessage(52));  // CMN052 INFO - 작업을 성공적으로 수행하였습니다.

                sheet1.Protect = true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvLabel.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLabel.Text + "]");
                    cdvLabel.Focus();
                    return;
                }

                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                List<string> group_list = new List<string>();
                bool print_flag = false;

                MPCR.SetInMsg(in_node);

                for (int i = 0; i < spdLotList_Sheet1.RowCount; i++)
                {
                    if (spdLotList_Sheet1.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        label_list = in_node.AddNode("LOT_LIST");
                        label_list.AddString("LOT_ID", spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_ID].Text);

                        // GROUP ID가 존재한다면, GROUP_LIST, CELL_LIST 구성
                        // 선택되는 라벨 관계없이 in_node 구성
                        if (MPCF.Trim(spdLotList_Sheet1.Cells[i, (int)LOT_INFO.GROUP_ID].Text) != "")
                        {
                            if (group_list.Contains(spdLotList_Sheet1.Cells[i, (int)LOT_INFO.GROUP_ID].Text) == false)
                            {
                                group_list.Add(spdLotList_Sheet1.Cells[i, (int)LOT_INFO.GROUP_ID].Text);

                                label_list = in_node.AddNode("GROUP_LIST");
                                label_list.AddString("GROUP_ID", spdLotList_Sheet1.Cells[i, (int)LOT_INFO.GROUP_ID].Text);

                                label_list = in_node.AddNode("CELL_LIST");
                                label_list.AddString("GROUP_ID", spdLotList_Sheet1.Cells[i, (int)LOT_INFO.GROUP_ID].Text);
                            }
                        }

                        print_flag = true;
                    }
                }

                if(print_flag == true)
                {
                    CSCF.ViewLabelList(cdvLabel.Text, in_node);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    CSCF.CheckSpreadCell(spdLotList, 0, 0, true, true);
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
