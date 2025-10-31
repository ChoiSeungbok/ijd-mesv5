using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using FarPoint.Win.Spread;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

namespace CUS_QCM
{
    public partial class frmTranOtherCompanySpec : CUS_COM.frmTranForm05
    {
        public frmTranOtherCompanySpec()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum DELIVERY : int
        {
            DELIVERY_ID,        // 1 . 납품처 ID
            DELIVERY_NAME       // 2 . 납품처 명
        }

        private enum SPEC : int
        {
            CHECK,
            DELIVERY_ID,
            GRADE,
            GRADE_BTN,
            INSP_TYPE,
            INSP_TYPE_BTN,
            INSP_TYPE_DESC,
            CHAR_ID,
            CHAR_ID_BTN,
            CHAR_DESC,
            VALUE_TYPE,
            TARGET_VALUE,
            LOW_SPEC_LIMIT,
            UPPER_SPEC_LIMIT
        }

        #endregion

        #region " Variable Definition "

        int selected_row = -1;
        int saved_row = 0;

        string s_area_id = "";
        char spec_flag = 'Y';

        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnDel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        break;

                    case CSGC.CHECK.ADD:
                        if (selected_row < 0)
                        {
                            //CMN423 ERROR - 선택된 아이템이 없습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(423));
                            return false;
                        }
                        break;

                    case CSGC.CHECK.SAVE:
                        if (selected_row < 0)
                        {
                            //CMN423 ERROR - 선택된 아이템이 없습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(423));
                            return false;
                        }
                        else if (spdSpecList_Sheet1.RowCount <= 0)
                        {
                            //CMN465 INFO - 체크항목이 존재하지 않습니다. 확인해주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(465));
                            return false;
                        }
                        break;

                    case CSGC.CHECK.DELETE:
                        if (selected_row < 0)
                        {
                            //CMN423 ERROR - 선택된 아이템이 없습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(423));
                            return false;
                        }
                        else if (spdSpecList_Sheet1.RowCount <= 0)
                        {
                            //CMN465 INFO - 체크항목이 존재하지 않습니다. 확인해주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(465));
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
        //클리어 함수
        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":
                        selected_row = -1;
                        saved_row = 0;
                        s_area_id = "";

                        MPCF.ClearList(spdDeliveryList);
                        MPCF.ClearList(spdSpecList);

                        break;

                    case "SAVE":
                        saved_row = 0;

                        break;

                    case "DELETE":
                        saved_row = 0;

                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        //GRADE조회
        private bool ViewGCMDataList_Grade(Control Form_control, char c_step, string table_name, string Area)
        {
            ListViewItem itmX;
            SheetView sheetX;
            int iRow;
            int iCol;
            int i;
            int j;
            int Image_idx = -1;
            string[] strData = null;
            List<string> sList = new List<string>();
            FarPoint.Win.Spread.CellType.ComboBoxCellType cboCellType;
            ArrayList a_list;

            TRSNode in_node = new TRSNode("VIEW_DATA_LIST_IN");
            TRSNode out_node;

            a_list = new ArrayList();
            Image_idx = (int)SMALLICON_INDEX.IDX_CODE_DATA;

            if (Form_control is ListView)
            {
                MPCF.InitListView((ListView)Form_control);
            }
            else if (!(Form_control is TreeView))
            {
                MPCF.ClearList(Form_control, true);
            }
            if (Form_control is Miracom.UI.Controls.MCCodeView.MCCodeDropList)
            {
                ((Miracom.UI.Controls.MCCodeView.MCCodeDropList)Form_control).GCMTableName = table_name;
            }

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = c_step;

            in_node.AddString("TABLE_NAME", table_name);
            in_node.AddString("NEXT_KEY_1", "");
            in_node.AddString("NEXT_KEY_2", "");

            do
            {
                out_node = new TRSNode("VIEW_DATA_LIST_OUT");

                if (MPCR.CallService("BAS", "BAS_View_Data_List", in_node, ref out_node, false) == false)
                {
                    return false;
                }

                a_list.Add(out_node);

                in_node.SetString("NEXT_KEY_1", out_node.GetString("NEXT_KEY_1"));
                in_node.SetString("NEXT_KEY_2", out_node.GetString("NEXT_KEY_2"));
            } while (in_node.GetString("NEXT_KEY_1") != "" || in_node.GetString("NEXT_KEY_2") != "");

            foreach (object obj in a_list)
            {
                out_node = null;
                out_node = (TRSNode)obj;

                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    if (out_node.GetList(0)[i].GetString("KEY_1") == MPCF.Trim(Area))
                    {
                        if (Form_control is ListView)
                        {
                            itmX = new ListViewItem(out_node.GetList(0)[i].GetString("KEY_2"), Image_idx);
                            if (((ListView)Form_control).Columns.Count > 1)
                            {
                                for (j = 0; j <= ((ListView)Form_control).Columns.Count - 1; j++)
                                {
                                    switch (j)
                                    {
                                        case 0:
                                            itmX.SubItems.Add(out_node.GetList(0)[i].GetString("KEY_1"));
                                            break;
                                    }
                                }
                            }
                            ((ListView)Form_control).Items.Add(itmX);
                        }
                        else if (Form_control is FpSpread)
                        {
                            sheetX = ((FpSpread)Form_control).ActiveSheet;

                            if (sheetX.Columns.Count == 2)
                            {

                                iRow = sheetX.RowCount;
                                sheetX.RowCount++;

                                iCol = 0;
                                sheetX.Cells[iRow, iCol].Value = out_node.GetList(0)[i].GetString("KEY_2");

                                iCol++;
                                sheetX.Cells[iRow, iCol].Value = out_node.GetList(0)[i].GetString("KEY_1");

                                iCol++;
                            }
                            else
                            {
                                sList.Add(out_node.GetList(0)[i].GetString("KEY_1"));
                            }

                        }

                    }
                }
            }


            if (Form_control is FpSpread)
            {

                if (((FpSpread)Form_control).ActiveSheet.Columns.Count == 3)
                {
                    return true;
                }
            }

            strData = new string[sList.Count + 1];
            for (i = 0; i < sList.Count; i++)
            {
                strData[i] = sList[i];
            }
            strData[i] = "";

            cboCellType = new FarPoint.Win.Spread.CellType.ComboBoxCellType();
            cboCellType.Items = strData;

            return true;
        }
        //검사코드 조회
        public bool ViewCharacterList(Control control, string sAreaId, string sGrade, string sInspType)
        {
            string sViewID = "";
            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                string sSql = "";

                sViewID = "CQCM2006-003";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sAreaId;

                dvcArgu[2].sCondition_ID = "INSP_TYPE";
                dvcArgu[2].sCondition_Value = sInspType;

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return false;

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["CHAR_ID"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["CHAR_DESC"].ToString());
                            itmX.SubItems.Add(row["VALUE_TYPE"].ToString());
                        }
                        ((ListView)control).Items.Add(itmX);
                    }
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        //고객처 조회
        private void ViewDeliveryList(char cSpecFlag)
        {
            string sView_id = "";
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                if (spec_flag == 'N')
                    sView_id = "CQCM2006-001";
                else
                    sView_id = "CQCM2006-004";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "DELIVERY_ID";
                dvcArgu[2].sCondition_Value = cdvDeliveryId.Text;

                if (TPDR.GetDataOne("", ref dt, sView_id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdDeliveryList_Sheet1.RowCount++;

                    spdDeliveryList_Sheet1.Cells[i, (int)DELIVERY.DELIVERY_ID].Value = dt.Rows[i]["DELIVERY_ID"];
                    spdDeliveryList_Sheet1.Cells[i, (int)DELIVERY.DELIVERY_NAME].Value = dt.Rows[i]["DELIVERY_NAME"];
                }

                MPCF.FitColumnHeader(spdDeliveryList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        //스펙리스트 조회
        private void ViewSpecList(string sAreaId, int selected_row)
        {
            string sView_id = "";
            string sDeliveryId;

            try
            {
                sDeliveryId = spdDeliveryList_Sheet1.Cells[selected_row, (int)DELIVERY.DELIVERY_ID].Text;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                sView_id = "CQCM2006-002";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sAreaId;

                dvcArgu[2].sCondition_ID = "DELIVERY_ID";
                dvcArgu[2].sCondition_Value = sDeliveryId;

                if (TPDR.GetDataOne("", ref dt, sView_id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    MPCF.ClearList(spdSpecList);
                    GC.Collect();

                    return;
                }

                MPCF.ClearList(spdSpecList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdSpecList_Sheet1.RowCount++;
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.DELIVERY_ID].Value = dt.Rows[i]["DELIVERY_ID"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.INSP_TYPE].Value = dt.Rows[i]["INSP_TYPE"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.INSP_TYPE_DESC].Value = dt.Rows[i]["INSP_TYPE_DESC"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.CHAR_ID].Value = dt.Rows[i]["CHAR_ID"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.CHAR_DESC].Value = dt.Rows[i]["CHAR_DESC"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.VALUE_TYPE].Value = dt.Rows[i]["VALUE_TYPE"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.TARGET_VALUE].Value = dt.Rows[i]["TARGET_VALUE"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.LOW_SPEC_LIMIT].Value = dt.Rows[i]["LOW_SPEC_LIMIT"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.UPPER_SPEC_LIMIT].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"];
                }

                saved_row = dt.Rows.Count;

                MPCF.FitColumnHeader(spdSpecList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        //SPEC 리스트 저장
        private bool SaveSpecList(int iRow)
        {
            SheetView sv = spdSpecList.ActiveSheet;
            int iCheckCount = 0;

            TRSNode in_node = new TRSNode("Ship_Report_Spec_Registration_By_Grade_In");
            TRSNode out_node = new TRSNode("Ship_Report_Spec_Registration_By_Grade_Out");
            TRSNode spec_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)SPEC.CHECK].Value))
                    {
                        //GRADE 검사
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)SPEC.GRADE].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            sv.SetActiveCell(i, (int)SPEC.GRADE);
                            return false;
                        }
                        //검사 타입 검사
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)SPEC.INSP_TYPE].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            sv.SetActiveCell(i, (int)SPEC.INSP_TYPE);
                            return false;
                        }
                        //검사 코드 검사
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)SPEC.CHAR_ID].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            sv.SetActiveCell(i, (int)SPEC.CHAR_ID);
                            return false;
                        }

                        spec_list = in_node.AddNode("DATA_LIST");
                        spec_list.AddString("DELIVERY_ID", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.DELIVERY_ID].Value);
                        spec_list.AddString("GRADE", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.GRADE].Value);
                        spec_list.AddString("INSP_TYPE", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.INSP_TYPE].Value);
                        spec_list.AddString("CHAR_ID", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.CHAR_ID].Value);
                        spec_list.AddString("TARGET_VALUE", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.TARGET_VALUE].Value);
                        spec_list.AddString("LOW_SPEC_LIMIT", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.LOW_SPEC_LIMIT].Value);
                        spec_list.AddString("UPPER_SPEC_LIMIT", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.UPPER_SPEC_LIMIT].Value);

                        iCheckCount++;
                    }
                }

                if (iCheckCount > 0)
                {
                    if (MPCR.CallService("CUS_QCM", "CUS_QCM_Ship_Report_Spec_Registration_By_Grade", in_node, ref out_node, false) == false)
                    {
                        return false;
                    }

                    MPCR.ShowSuccessMsg(out_node);
                }
                else
                {
                    //체크항목이 존재하지 않습니다. 확인해주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(465));
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
        //SPEC 리스트 삭제
        private bool DeleteSpecList(int iRow)
        {
            SheetView sv = spdSpecList.ActiveSheet;
            int iCheckCount = 0;

            TRSNode in_node = new TRSNode("Ship_Report_Spec_Registration_By_Grade_In");
            TRSNode out_node = new TRSNode("Ship_Report_Spec_Registration_By_Grade_Out");
            TRSNode spec_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';

                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)SPEC.CHECK].Value))
                    {
                        //GRADE 검사
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)SPEC.GRADE].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            sv.SetActiveCell(i, (int)SPEC.GRADE);
                            return false;
                        }
                        //검사 타입 검사
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)SPEC.INSP_TYPE].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            sv.SetActiveCell(i, (int)SPEC.INSP_TYPE);
                            return false;
                        }
                        //검사 코드 검사
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)SPEC.CHAR_ID].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            sv.SetActiveCell(i, (int)SPEC.CHAR_ID);
                            return false;
                        }

                        spec_list = in_node.AddNode("DATA_LIST");
                        spec_list.AddString("DELIVERY_ID", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.DELIVERY_ID].Value);
                        spec_list.AddString("GRADE", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.GRADE].Value);
                        spec_list.AddString("INSP_TYPE", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.INSP_TYPE].Value);
                        spec_list.AddString("CHAR_ID", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.CHAR_ID].Value);

                        iCheckCount++;
                    }
                }

                if (iCheckCount > 0)
                {
                    if (MPCR.CallService("CUS_QCM", "CUS_QCM_Ship_Report_Spec_Registration_By_Grade", in_node, ref out_node, false) == false)
                    {
                        return false;
                    }

                    MPCR.ShowSuccessMsg(out_node);
                }
                else
                {
                    //체크항목이 존재하지 않습니다. 확인해주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(465));
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

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ClearList("VIEW");

                s_area_id = cdvDept.Text;
                spec_flag = (btnYes.Checked ? 'Y' : 'N');

                ViewDeliveryList(spec_flag);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }
        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SaveSpecList(selected_row))
                {
                    ClearList("SAVE");
                    ViewSpecList(s_area_id, selected_row);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnDel_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.DELETE) == false)
                    return;

                DialogResult dr = MessageBox.Show(MPCF.GetMessage(453), "Info", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);

                if (dr == DialogResult.OK)
                {
                    if (DeleteSpecList(selected_row))
                    {
                        ClearList("DELETE");
                        ViewSpecList(s_area_id, selected_row);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdDeliveryList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.Row < 0)
                {
                    return;
                }

                for (int i = 0; i < spdDeliveryList.ActiveSheet.RowCount; i++)
                {
                    spdDeliveryList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                if (e.ColumnHeader)
                {
                    return;
                }
                selected_row = e.Row;

                spdDeliveryList.ActiveSheet.Rows[selected_row].BackColor = Color.FromArgb(255, 192, 255);

                ViewSpecList(s_area_id, selected_row);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvCustomerId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopDeliveryList popup = new frmPopDeliveryList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvDeliveryId.Text = popup.g_DeliveryId;
                    this.cdvDeliveryId.DisplayText = popup.g_DeliveryName;
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
        private void spdSpecList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            try
            {
                if (e.Row < saved_row)
                    return;

                if (e.Column == (int)SPEC.GRADE_BTN || e.Column == (int)SPEC.INSP_TYPE_BTN || e.Column == (int)SPEC.CHAR_ID_BTN)
                {
                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                    if (e.Column == (int)SPEC.GRADE_BTN)
                    {
                        if (ViewGCMDataList_Grade(cdvGridButton.GetListView, '1', CSGC.CP_GCM_MAT_GRADE, s_area_id) == false)
                        {
                            return;
                        }
                    }
                    else if (e.Column == (int)SPEC.INSP_TYPE_BTN)
                    {
                        // 검사 TYPE 조회
                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', CSGC.CP_GCM_INSP_TYPE) == false)
                        {
                            return;
                        }
                    }
                    else if (e.Column == (int)SPEC.CHAR_ID_BTN)
                    {
                        if (selected_row < 0)
                            return;

                        if (MPCF.Trim(spdSpecList_Sheet1.Cells[e.Row, (int)SPEC.INSP_TYPE].Value) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            spdSpecList_Sheet1.SetActiveCell(e.Row, (int)SPEC.INSP_TYPE);
                            return;
                        }

                        //검사항목 조회
                        if (ViewCharacterList(cdvGridButton.GetListView, s_area_id, MPCF.Trim(spdSpecList_Sheet1.Cells[e.Row, (int)SPEC.GRADE].Value), MPCF.Trim(spdSpecList_Sheet1.Cells[e.Row, (int)SPEC.INSP_TYPE].Value)) == false)
                            return;

                        spdSpecList_Sheet1.Cells[e.Row, (int)SPEC.CHAR_ID].Value = string.Empty;
                    }

                    cdvGridButton.ShowPopupList(e.Row, e.Column);
                    cdvGridButton.InsertEmptyRow(0, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            int iRow = 0;
            try
            {
                if (CheckCondition(CSGC.CHECK.ADD) == false)
                    return;

                iRow = spdSpecList_Sheet1.RowCount++;
                spdSpecList_Sheet1.Cells[iRow, (int)SPEC.CHECK].Value = true;
                spdSpecList_Sheet1.Cells[iRow, (int)SPEC.DELIVERY_ID].Value = spdDeliveryList_Sheet1.Cells[iRow, (int)DELIVERY.DELIVERY_ID].Value;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnRowDel_Click(object sender, EventArgs e)
        {
            int iRow = spdSpecList_Sheet1.RowCount - 1;

            try
            {
                if (iRow < saved_row)
                    return;

                if (spdSpecList.ActiveSheet.Cells[iRow, (int)SPEC.CHECK].Value.ToString().ToUpper() == "TRUE")
                {
                    spdSpecList_Sheet1.RemoveRows(iRow, 1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (spdSpecList.ActiveSheet.ActiveColumnIndex == (int)SPEC.GRADE_BTN)
                {
                    spdSpecList_Sheet1.SetValue(e.Row, (int)SPEC.GRADE, e.SelectedItem.SubItems[0].Text);
                }
                else if (spdSpecList.ActiveSheet.ActiveColumnIndex == (int)SPEC.INSP_TYPE_BTN)
                {
                    spdSpecList_Sheet1.SetValue(e.Row, (int)SPEC.INSP_TYPE, e.SelectedItem.SubItems[0].Text);
                    spdSpecList_Sheet1.SetValue(e.Row, (int)SPEC.INSP_TYPE_DESC, e.SelectedItem.SubItems[1].Text);
                }
                else if (spdSpecList.ActiveSheet.ActiveColumnIndex == (int)SPEC.CHAR_ID_BTN)
                {
                    spdSpecList_Sheet1.SetValue(e.Row, (int)SPEC.CHAR_ID, e.SelectedItem.SubItems[0].Text);
                    spdSpecList_Sheet1.SetValue(e.Row, (int)SPEC.CHAR_DESC, e.SelectedItem.SubItems[1].Text);
                    spdSpecList_Sheet1.SetValue(e.Row, (int)SPEC.VALUE_TYPE, e.SelectedItem.SubItems[2].Text);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdSpecList_CellClick(object sender, CellClickEventArgs e)
        {
            int iRow = -1;
            int iColumn = -1;

            try
            {
                if (!e.ColumnHeader)
                    return;

                iRow = e.Row;
                iColumn = e.Column;

                if (spdSpecList.ActiveSheet.ColumnHeader.Cells[iRow, iColumn].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdSpecList, iRow, iColumn, true, true, false);
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
                cdvDeliveryId.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion
    }
}
