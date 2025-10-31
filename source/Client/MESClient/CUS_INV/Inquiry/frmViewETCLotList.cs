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

namespace CUS_INV
{
    public partial class frmViewETCLotList : CUS_COM.frmViewForm01
    {
        public frmViewETCLotList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT
        {
            CHK,                // 1 : CHK
            LOT_ID,             // 2 : LOT ID
            SEQ,                // 1 : 시퀀스
            LOT_TYPE,           // 2 : 타입(WIP, INV)
            QTY,                // 3 : 수량
            UNIT,               // 4 : 단위
            COMMENT,            // 5 : 비고
            ETC_TYPE,           // 6 : 타입(IN, OUT)
            ETC_DATE,           // 7 : 기타출고일
            MAT_ID,             // 8 : 제품
            MAT_VER,            // 9 : 버전
            MAT_DESC,           // 10 : 제품명
            AREA_ID,            // 11 : 사업부
            SUB_AREA_ID,        // 12 : 작업장
            OPER,               // 13 : 창고
            OPER_DESC,          // 14 : 창고명
            SRC_ID,             // 15 : ERP 소스 ID
            SRC_NAME,           // 16 : ERP 소스명
            VENDOR_ID,          // 17 : 업체
            VENDOR_DESC,        // 18 : 업체명
            VENDOR_SITE_ID,     // 19 : 업체 SITE ID
            VENDOR_LOT_ID,      // 20 : 업체 LOT ID
            PROCESS_TYPE,       // 21 : 처리내용 
            INPUT_ORDER_ID,     // 22 : 투입된 작지
            INPUT_LOT_ID,       // 23 : 투입된 LOT
            CREATE_USER,        // 24 : 생성자
            CREATE_TIME,        // 25 : 생성시간
            UPDATE_USER,        // 26 : 수정자
            UPDATE_TIME         // 27 : 수정시간
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
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnCsvDirect.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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
                        cdvETCType.Text = "";
                        dtpFromWorkDate.Value = DateTime.Now;
                        //dtpFromWorkDate.Format = DateTimePickerFormat.Custom;
                        //dtpFromWorkDate.CustomFormat = " ";
                        cdvMatType.Text = "";
                        cdvMatID.Text = "";
                        txtMatDesc.Text = "";

                        MPCF.ClearList(spdETCLotList);
                        break;

                    case "VIEW":

                        MPCF.ClearList(spdETCLotList);
                        break;

                    case "CLICK_DEPT":

                        cdvOper.Text = "";
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
                    case "SAVE":
                        if (spdETCLotList.ActiveSheet.RowCount == 0)
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


        private void ViewInspectionDataCountCheck(int iOutPutType)
        {
            try
            {
                DataTable dt = null;
                string sSql = "";
                int i = 0;


                DateTime dSearchTime = DateTime.Now;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[9];

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;

                dvcArgu[3].sCondition_ID = "ETC_TYPE";
                dvcArgu[3].sCondition_Value = cdvETCType.Text;

                dvcArgu[4].sCondition_ID = "FROM_DATE";
                dvcArgu[4].sCondition_Value = string.IsNullOrEmpty(dtpFromWorkDate.Text.Trim()) ? "19000101" : dtpFromWorkDate.Text.Replace("-", "");

                dvcArgu[5].sCondition_ID = "TO_DATE";
                dvcArgu[5].sCondition_Value = dtpToWorkDate.Text.Replace("-", "");

                dvcArgu[6].sCondition_ID = "MAT_TYPE";
                dvcArgu[6].sCondition_Value = cdvMatType.Text;

                dvcArgu[7].sCondition_ID = "MAT_ID";
                dvcArgu[7].sCondition_Value = cdvMatID.Text;

                dvcArgu[8].sCondition_ID = "MAT_DESC";
                dvcArgu[8].sCondition_Value = txtMatDesc.Text;

                if (TPDR.GetDataOne("", ref dt, "CINV3010-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdETCLotList);
                    return;
                }

                MPCF.ClearList(spdETCLotList);


                if (dt.Rows.Count > 1)
                {

                    //조회 데이터가 50000건이상입니다. CSV파일로 바로출력됩니다.진행하시겠습니까 ?(50000건단위로 분할출력됩니다.)
                    if (MPCF.ShowMsgBox(MPCF.GetMessage(600), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                    {
                        return;
                    }
                    {



                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            //무조건 CSV파일로
                            ViewETCLotList(2, dt.Rows[i]["ETC_DATE_BEFORE"].ToString(), dt.Rows[i]["ETC_DATE_AFTER"].ToString(), dSearchTime);
                        }
                    }


                }
                else
                {
                    if (iOutPutType == 2)
                    {
                        ViewETCLotList(2, dt.Rows[i]["ETC_DATE_BEFORE"].ToString(), dt.Rows[0]["ETC_DATE_AFTER"].ToString(), dSearchTime);
                    }
                    else
                    {
                        ViewETCLotList(1, dt.Rows[i]["ETC_DATE_BEFORE"].ToString(), dt.Rows[0]["ETC_DATE_AFTER"].ToString(), dSearchTime);
                    }
                }


                return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }





        // 기타 입출고 현황 리스트 조회
        public bool ViewETCLotList(int iOutPutType, string FromDt, string ToDt, DateTime dSearchTime)
        {
            try
            {
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[9];

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;

                dvcArgu[3].sCondition_ID = "ETC_TYPE";
                dvcArgu[3].sCondition_Value = cdvETCType.Text;

                dvcArgu[4].sCondition_ID = "FROM_DATE";
                dvcArgu[4].sCondition_Value = FromDt;

                dvcArgu[5].sCondition_ID = "TO_DATE";
                dvcArgu[5].sCondition_Value = ToDt;

                dvcArgu[6].sCondition_ID = "MAT_TYPE";
                dvcArgu[6].sCondition_Value = cdvMatType.Text;

                dvcArgu[7].sCondition_ID = "MAT_ID";
                dvcArgu[7].sCondition_Value = cdvMatID.Text;

                dvcArgu[8].sCondition_ID = "MAT_DESC";
                dvcArgu[8].sCondition_Value = txtMatDesc.Text;

                if (TPDR.GetDataOne("", ref dt, "CINV3010-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdETCLotList);
                    return false;
                }

                MPCF.ClearList(spdETCLotList);


                if (iOutPutType == 2)
                {


            


                    // CSV 파일로 바로 출력
                    //바탕화면 
                    string filePath = Environment.GetFolderPath(Environment.SpecialFolder.Desktop) + "\\ETC_In_Out_" + dSearchTime.ToString("yyyy-MM-dd_HHmmss") + "\\ETC_In_Out_" + FromDt + "~" + ToDt + ".csv";
                    //APP TEMP
                    //   string filePath = Environment.GetEnvironmentVariable("TEMP") + "\\" + FromDt + "~" + ToDt + "_" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".csv";
                    //C: temp
                    //   string filePath = Environment.GetEnvironmentVariable("windir") + "\\" + FromDt + "~" + ToDt + "_" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".csv";


                    FarPoint.Win.Spread.SheetView oSheet = spdETCLotList.ActiveSheet;

                    clsCusExportFile CsvExport = new clsCusExportFile();

                    string[] columnNames = new string[dt.Columns.Count];


                    for (int iCol = 0; iCol < dt.Columns.Count; iCol++)
                    {

                        if (oSheet.ColumnCount - 1 >= iCol)
                        {
                            //앞에 체크박스 값 빼고 
                            columnNames[iCol] = oSheet.ColumnHeader.Cells[0, iCol+1].Text.Replace(",", ".");
                        }
                    }

                    if (CsvExport.SaveDataTableToCsv(dt, filePath, null, columnNames))
                    {
                        CsvExport.OpenCsvInExcel(filePath);
                    }


                }
                else
                {


                    for (i = 0; i < dt.Rows.Count; i++)
                    {
                        spdETCLotList_Sheet1.RowCount++;

                        spdETCLotList_Sheet1.SetValue(i, (int)LOT.CHK, false);
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.SEQ].Value = dt.Rows[i]["SEQ"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.QTY].Value = dt.Rows[i]["QTY"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.ETC_TYPE].Value = dt.Rows[i]["ETC_TYPE"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.ETC_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["ETC_DATE"].ToString().Replace("-",""), DATE_TIME_FORMAT.DATE);
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_ID"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.OPER].Value = dt.Rows[i]["OPER"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.SRC_ID].Value = dt.Rows[i]["TRAN_SRC_ID"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.SRC_NAME].Value = dt.Rows[i]["TRAN_SRC_NAME"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.VENDOR_ID].Value = dt.Rows[i]["VENDOR_ID"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.VENDOR_SITE_ID].Value = dt.Rows[i]["VENDOR_SITE_ID"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];

                        spdETCLotList_Sheet1.Cells[i, (int)LOT.PROCESS_TYPE].Value = dt.Rows[i]["PROCESS_TYPE"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.INPUT_ORDER_ID].Value = dt.Rows[i]["INPUT_ORDER_ID"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.INPUT_LOT_ID].Value = dt.Rows[i]["INPUT_LOT_ID"];

                        spdETCLotList_Sheet1.Cells[i, (int)LOT.COMMENT].Value = dt.Rows[i]["ETC_COMMENT"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.CREATE_USER].Value = dt.Rows[i]["CREATE_USER_ID"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.CREATE_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.UPDATE_USER].Value = dt.Rows[i]["UPDATE_USER_ID"];
                        spdETCLotList_Sheet1.Cells[i, (int)LOT.UPDATE_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["UPDATE_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    }

                    MPCF.FitColumnHeader(spdETCLotList);
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //기타 입출고 주석 정보 변경
        private bool ChangeETCComment()
        {
            TRSNode in_node = new TRSNode("change_Etc_Comment_In");
            TRSNode out_node = new TRSNode("change_Etc_Comment_Out");
            TRSNode lot_list;
            bool send_flag = false;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                for (int i = 0; i < spdETCLotList_Sheet1.RowCount; i++)
                {
                    if (spdETCLotList_Sheet1.Cells[i, (int)LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        lot_list = in_node.AddNode("LOT_LIST");
                        lot_list.AddString("LOT_ID", spdETCLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text);
                        lot_list.AddInt("SEQ", MPCF.ToInt(spdETCLotList_Sheet1.Cells[i, (int)LOT.SEQ].Text));
                        lot_list.AddString("COMMENT", spdETCLotList_Sheet1.Cells[i, (int)LOT.COMMENT].Text);
                        send_flag = true;
                    }
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_INV", "CUS_INV_Change_Etc_Comment", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);

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
        private void frmViewETCLotList_Load(object sender, EventArgs e)
        {
            try
            {
                dtpToWorkDate.Value = DateTime.Now;
                dtpFromWorkDate.Value = DateTime.Now.AddDays(-7);
                //dtpFromWorkDate.Format = DateTimePickerFormat.Custom;
                //dtpFromWorkDate.CustomFormat = " ";
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

                //ViewETCLotList();
                ViewInspectionDataCountCheck(1);
            }
            catch (Exception ex)
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

        private void spdETCLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (spdETCLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdETCLotList, e.Row, e.Column, true, true, false);
                    }
                }
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    SheetView sv = spdETCLotList.ActiveSheet;

                    for (int i = 0; i < sv.RowCount; i++)
                    {
                        sv.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                        sv.Cells[i, (int)LOT.COMMENT].BackColor = Color.Lime;
                    }
                    sv.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);
                    sv.Cells[e.Row, (int)LOT.COMMENT].BackColor = Color.Lime;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("SAVE") == false)
                    return;

                if (ChangeETCComment())
                {
                    ClearList("VIEW");
                    //ViewETCLotList();
                    ViewInspectionDataCountCheck(1);
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
                EXTFUC.SaveExcel(spdETCLotList, "ETCLotList");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
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

        private void cdvMatID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvMatType.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMatType.Text + "]");
                    cdvMatType.Focus();
                    return;
                }

                // 제품 팝업으로 변경
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                popup.sType_id = cdvMatType.Text;
                popup.sType_desc = cdvMatType.DisplayText;

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

        private void cdvETCType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvETCType.Init();
                MPCF.InitListView(cdvETCType.GetListView);
                cdvETCType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvETCType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvETCType.SelectedSubItemIndex = 0;
                cdvETCType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvETCType.GetListView, '1', CSGC.CP_GCM_ETC_TYPE) == false)
                {
                    return;
                }

                cdvETCType.InsertEmptyRow(0, 1);
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

        private void cdvMatID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatID.DisplayText == "")
                cdvMatID.Text = "";
        }

        private void spdETCLotList_EditModeStarting(object sender, EditModeStartingEventArgs e)
        {
            if (spdETCLotList_Sheet1.ActiveColumnIndex != 0)
                spdETCLotList_Sheet1.Cells[spdETCLotList_Sheet1.ActiveRowIndex, (int)LOT.CHK].Value = true;
        }

        #endregion

        private void dtpFromWorkDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromWorkDate.CustomFormat = "yyyy-MM-dd";
        }

        private void btnCsvDirect_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("VIEW") == false)
                    return;

                ClearList("VIEW");

                //ViewETCLotList();
                ViewInspectionDataCountCheck(2);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}
