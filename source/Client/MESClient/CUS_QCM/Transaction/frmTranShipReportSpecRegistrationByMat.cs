using CUS_COM;
using FarPoint.Win.Spread;
using Miracom.CliFrx;
using Miracom.DNMCore;
using Miracom.MESCore;
using Miracom.TRSCore;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CUS_QCM
{
    public partial class frmTranShipReportSpecRegistrationByMat : CUS_COM.frmTranForm05
    {
        public frmTranShipReportSpecRegistrationByMat()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum MAT : int
        {
            MAT_ID,                 // 1 : 제품         
            MAT_DESC,               // 2 : 제품명
            MAT_VER,                // 3 : 버전
            INSP_TYPE               // 4 : 검사 종류
        }

        private enum SPEC : int
        {
            CHECK,
            DELIVERY_ID,
            DELIVERY_NAME,
            DELIVERY_BTN,
            INSP_TYPE,
            INSP_TYPE_BTN,
            INSP_TYPE_DESC,
            CHAR_ID,
            CHAR_ID_BTN,
            CHAR_DESC,
            VALUE_TYPE,
            TARGET_VALUE,
            LOW_SPEC_LIMIT,
            UPPER_SPEC_LIMIT,
            DISPLAY_SPEC
        }



        #endregion

        #region " Variable Definition "

        int selected_row = -1;
        int saved_row = 0;
        string mat_id = "";
        string insp_type = "";
        string insp_type_desc = "";
        int mat_ver = 1;

        public string s_pop_mat_id = "";
        public string s_pop_insp_type = "";
        public string s_pop_insp_type_desc = "";
        public string s_pop_arda_id = "";


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
                        if (MPCF.Trim(cdvInspectionType.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblInspectionType.Text + "]");
                            cdvInspectionType.Focus();
                            return false;
                        }
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
                        mat_id = "";
                        insp_type = "";
                        insp_type_desc = "";
                        saved_row = 0;

                        MPCF.ClearList(spdMatList);
                        MPCF.ClearList(spdSpecList);

                        break;

                    case "SAVE":
                        saved_row = 0;

                        MPCF.ClearList(spdSpecList);
                        break;

                    case "DELETE":
                        saved_row = 0;

                        MPCF.ClearList(spdSpecList);
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        /*
        //COL_SET_VERSION 찾기
        private int FindColSetVersion(string sColSetID)
        {
            int col_set_version = 0;
            try
            {
                TRSNode in_node = new TRSNode("FIND_COL_SET_VERSION_IN");
                TRSNode out_node = new TRSNode("FIND_COL_SET_VERSION_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("COL_SET_ID", sColSetID);

                if (MPCR.CallService("EDC", "EDC_Find_Col_Set_Version", in_node, ref out_node, false) == false)
                {
                    return col_set_version;
                }

                col_set_version = out_node.GetInt("COL_SET_VERSION");

                return col_set_version;
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return col_set_version;
            }
        }
        */

        private bool CheckCell(int iRow, int iColumn)
        {
            try
            {
                if (iColumn != 0)
                    return false;

                if (spdSpecList.ActiveSheet.ColumnHeader.Cells[iRow, iColumn].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdSpecList, iRow, iColumn, true, true, false);
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //검사코드 조회
        public bool ViewCharacterList(Control control, string sMatID, string sInspType)
        {
            string sViewID = "";
            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                string sSql = "";

                sViewID = "CQCM2005-003";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = sMatID;

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

        //품목 조회
        private void ViewMatList()
        {
            string sView_id = "";
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                sView_id = "CQCM2005-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "INSP_TYPE";
                dvcArgu[2].sCondition_Value = cdvInspectionType.Text;

                dvcArgu[3].sCondition_ID = "MAT_TYPE";
                dvcArgu[3].sCondition_Value = cdvMatType.Text;

                dvcArgu[4].sCondition_ID = "MAT_ID";
                dvcArgu[4].sCondition_Value = cdvMatId.Text;

                if (TPDR.GetDataOne("", ref dt, sView_id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMatList_Sheet1.RowCount++;

                    spdMatList_Sheet1.Cells[i, (int)MAT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMatList_Sheet1.Cells[i, (int)MAT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMatList_Sheet1.Cells[i, (int)MAT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdMatList_Sheet1.Cells[i, (int)MAT.INSP_TYPE].Value = dt.Rows[i]["INSP_TYPE"];
                }

                MPCF.FitColumnHeader(spdMatList);

                if(spdMatList_Sheet1.RowCount != 0)
                {
                    spdMatList.ActiveSheet.AddSelection(0, 0, 1, 1);
                    selected_row = 0;
                    mat_id = spdMatList_Sheet1.Cells[0, (int)MAT.MAT_ID].Text;
                    mat_ver = MPCF.ToInt(spdMatList_Sheet1.Cells[0, (int)MAT.MAT_VER].Text);
                    insp_type = spdMatList_Sheet1.Cells[0, (int)MAT.INSP_TYPE].Text;
                    ViewSpecList(mat_id, insp_type);
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewSpecList(string sMat_id, string sInsp_type)
        {
            string sView_id = "";
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                sView_id = "CQCM2005-002";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INSP_TYPE";
                dvcArgu[1].sCondition_Value = sInsp_type;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = sMat_id;

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
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.DELIVERY_NAME].Value = dt.Rows[i]["DELIVERY_NAME"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.INSP_TYPE].Value = dt.Rows[i]["INSP_TYPE"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.INSP_TYPE_DESC].Value = dt.Rows[i]["INSP_TYPE_DESC"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.CHAR_ID].Value = dt.Rows[i]["CHAR_ID"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.CHAR_DESC].Value = dt.Rows[i]["CHAR_DESC"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.VALUE_TYPE].Value = dt.Rows[i]["VALUE_TYPE"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.TARGET_VALUE].Value = dt.Rows[i]["TARGET_VALUE"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.LOW_SPEC_LIMIT].Value = dt.Rows[i]["LOW_SPEC_LIMIT"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.UPPER_SPEC_LIMIT].Value = dt.Rows[i]["UPPER_SPEC_LIMIT"];
                    spdSpecList_Sheet1.Cells[i, (int)SPEC.DISPLAY_SPEC].Value = dt.Rows[i]["DISPLAY_SPEC"];
                }

                saved_row = dt.Rows.Count;

                MPCF.FitColumnHeader(spdSpecList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //품목별 SPEC 리스트 저장
        private bool SaveSpecList(int iRow)
        {
            SheetView sv = spdSpecList.ActiveSheet;
            int iCheckCount = 0;

            TRSNode in_node = new TRSNode("Ship_Report_Spec_Registration_By_Mat_In");
            TRSNode out_node = new TRSNode("Ship_Report_Spec_Registration_By_Mat_Out");
            TRSNode spec_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                in_node.AddString("MAT_ID", spdMatList_Sheet1.Cells[iRow, (int)MAT.MAT_ID].Value);
                in_node.AddInt("MAT_VER", spdMatList_Sheet1.Cells[iRow, (int)MAT.MAT_VER].Value);

                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)SPEC.CHECK].Value))
                    {
                        //납품처 검사
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)SPEC.DELIVERY_ID].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            sv.SetActiveCell(i, (int)SPEC.DELIVERY_ID);
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
                        spec_list.AddString("INSP_TYPE", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.INSP_TYPE].Value);
                        spec_list.AddString("CHAR_ID", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.CHAR_ID].Value);
                        spec_list.AddString("TARGET_VALUE", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.TARGET_VALUE].Value);
                        spec_list.AddString("LOW_SPEC_LIMIT", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.LOW_SPEC_LIMIT].Value);
                        spec_list.AddString("UPPER_SPEC_LIMIT", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.UPPER_SPEC_LIMIT].Value);
                        spec_list.AddString("CMF_1", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.DISPLAY_SPEC].Value);
                        iCheckCount++;
                    }
                }

                if (iCheckCount > 0)
                {
                    if (MPCR.CallService("CUS_QCM", "CUS_QCM_Ship_Report_Spec_Registration_By_Mat", in_node, ref out_node, false) == false)
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

        //품목별 SPEC 리스트 삭제
        private bool DeleteSpecList(int iRow)
        {
            SheetView sv = spdSpecList.ActiveSheet;
            int iCheckCount = 0;

            TRSNode in_node = new TRSNode("Ship_Report_Spec_Registration_By_Mat_In");
            TRSNode out_node = new TRSNode("Ship_Report_Spec_Registration_By_Mat_Out");
            TRSNode spec_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("MAT_ID", spdMatList_Sheet1.Cells[iRow, (int)MAT.MAT_ID].Value);

                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)SPEC.CHECK].Value))
                    {
                        //납품처 검사
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)SPEC.DELIVERY_ID].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            sv.SetActiveCell(i, (int)SPEC.DELIVERY_ID);
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
                        spec_list.AddString("INSP_TYPE", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.INSP_TYPE].Value);
                        spec_list.AddString("CHAR_ID", spdSpecList.ActiveSheet.Cells[i, (int)SPEC.CHAR_ID].Value);

                        iCheckCount++;
                    }
                }

                if (iCheckCount > 0)
                {
                    if (MPCR.CallService("CUS_QCM", "CUS_QCM_Ship_Report_Spec_Registration_By_Mat", in_node, ref out_node, false) == false)
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
        private void cdvInspectionType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvInspectionType.Init();
                MPCF.InitListView(cdvInspectionType.GetListView);
                cdvInspectionType.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvInspectionType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvInspectionType.SelectedSubItemIndex = 0;
                cdvInspectionType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvInspectionType.GetListView, '1', CSGC.CP_GCM_INSP_TYPE) == false)
                {
                    return;
                }

                cdvInspectionType.InsertEmptyRow(0, 1);
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

        private void cdvMatId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                popup.sType_id = cdvMatType.Text;
                popup.sType_desc = cdvMatType.DisplayText;

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

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ClearList("VIEW");

                insp_type = cdvInspectionType.Text;
                insp_type_desc = cdvInspectionType.DisplayText;
                ViewMatList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdMatList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.Row < 0)
                {
                    return;
                }

                for (int i = 0; i < spdMatList.ActiveSheet.RowCount; i++)
                {
                    spdMatList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                if (e.ColumnHeader)
                {
                    return;
                }
                selected_row = e.Row;

                spdMatList.ActiveSheet.Rows[selected_row].BackColor = Color.FromArgb(255, 192, 255);

                mat_id = spdMatList_Sheet1.Cells[selected_row, (int)MAT.MAT_ID].Text;
                mat_ver = MPCF.ToInt(spdMatList_Sheet1.Cells[selected_row, (int)MAT.MAT_VER].Text);
                insp_type = spdMatList_Sheet1.Cells[selected_row, (int)MAT.INSP_TYPE].Text;

                ViewSpecList(mat_id, insp_type);
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
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SaveSpecList(selected_row))
                {
                    ClearList("SAVE");
                    ViewSpecList(mat_id, insp_type);
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
                spdSpecList_Sheet1.Cells[iRow, (int)SPEC.INSP_TYPE].Text = insp_type;
                spdSpecList_Sheet1.Cells[iRow, (int)SPEC.INSP_TYPE_DESC].Value = insp_type_desc;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //저장되지 않은 체크 항목 한개를 삭제
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

        private void spdSpecList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                if (e.Row < saved_row)
                    return;

                if (e.Column == (int)SPEC.DELIVERY_BTN)
                {
                    //납품처 조회
                    frmPopDeliveryList popup = new frmPopDeliveryList();
                    popup.StartPosition = FormStartPosition.CenterParent;

                    if (popup.ShowDialog() == DialogResult.OK)
                    {
                        //this.cdvVendorID.Text = popup.g_DeliveryId;
                        //this.cdvVendorID.DisplayText = popup.g_DeliveryName;
                        spdSpecList_Sheet1.SetValue(e.Row, (int)SPEC.DELIVERY_ID, popup.g_DeliveryId);
                        spdSpecList_Sheet1.SetValue(e.Row, (int)SPEC.DELIVERY_NAME, popup.g_DeliveryName);
                        popup = null;
                    }
                    else
                    {
                        return;
                    }
                }
                else if (e.Column == (int)SPEC.INSP_TYPE_BTN || e.Column == (int)SPEC.CHAR_ID_BTN)
                {
                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                    if (e.Column == (int)SPEC.INSP_TYPE_BTN)
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
                        if (ViewCharacterList(cdvGridButton.GetListView, mat_id, MPCF.Trim(spdSpecList_Sheet1.Cells[e.Row, (int)SPEC.INSP_TYPE].Value)) == false)
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

        private void btnDel_Click(object sender, EventArgs e)
        {
            if (CheckCondition(CSGC.CHECK.DELETE) == false)
                return;

            DialogResult dr = MessageBox.Show(MPCF.GetMessage(453), "Info", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);

            if (dr == DialogResult.OK)
            {
                if (DeleteSpecList(selected_row))
                {
                    ClearList("DELETE");
                    ViewSpecList(mat_id, insp_type);
                }
            }
        }

        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (spdSpecList.ActiveSheet.ActiveColumnIndex == (int)SPEC.INSP_TYPE_BTN)
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
            try
            {
                if (e.ColumnHeader)
                {
                    CheckCell(e.Row, e.Column);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmTranShipReportSpecRegistrationByMat_Load(object sender, EventArgs e)
        {


            try
            {
                cdvDept.Text = s_pop_arda_id;
                cdvInspectionType.Text = s_pop_insp_type;
                cdvInspectionType.DisplayText = s_pop_insp_type_desc;
                cdvMatId.Text = s_pop_mat_id;

                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ClearList("VIEW");

                insp_type = cdvInspectionType.Text;
                insp_type_desc = cdvInspectionType.DisplayText;
                ViewMatList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }


        }

        #endregion
    }
}
