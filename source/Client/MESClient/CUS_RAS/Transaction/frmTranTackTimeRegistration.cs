using System;
using System.Data;
using System.Windows.Forms;
using FarPoint.Win.Spread;
using Excel = Microsoft.Office.Interop.Excel;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

namespace CUS_RAS
{
    public partial class frmTranTackTimeRegistration : CUS_COM.frmTranForm01
    {
        public frmTranTackTimeRegistration()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        //TackTime 정보
        private enum TACKTIME_INFO : int
        {
            CHECK,             // 1 : 선택
            AREA_DESC,         // 2 : 사업부 명
            AREA_BUTTON,       // 3 : 사업부 버튼
            AREA_CODE,         // 4 : 사업부 코드
            OPER_CODE,         // 5 : 공정 코드
            OPER_BUTTON,       // 6 : 공정 버튼    
            OPER_DESC,         // 7 : 공정명  
            RES_ID,            // 8 : 설비 ID     
            RES_ID_BUTTON,     // 9 : 설비 버튼
            RES_DESC,          // 10: 설비명 
            MAT_CODE,          // 11: 품목 코드     
            MAT_BUTTON,        // 12: 품목 버튼
            MAT_DESC,          // 13: 품목명
            MAT_VER,           // 14: 제품버전
            QTY,               // 15: 수량
            UNIT               // 16: 단위
        }

        //TackTime Excel정보
        private enum TACKTIME_EXCEL : int
        {
            NO,                // 0
            AREA_DESC,         // 1 : 사업부 명
            OPER_CODE,         // 2 : 공정 코드  
            OPER_DESC,         // 3 : 공정명  
            RES_ID,            // 4 : 설비 ID     
            RES_DESC,          // 5 : 설비명 
            MAT_CODE,          // 6 : 품목 코드     
            MAT_DESC,          // 7 : 품목명
            QTY,               // 8 : 수량
            UNIT               // 9 : 단위
        }

        private const int ROW = 2000;// 한번에 INSERT할 ROW개수

        #endregion

        #region " Variable Definition "

        string s_area_id = "";
        string s_oper = "";  
        string s_res_id = "";
        string s_mat_id = "";
        string s_mat_ver = "";
        string s_unit = "";

        int saved_row = 0;

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
                btnUploadExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;
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

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:                      
                        break;

                    case CSGC.CHECK.SAVE:
                        if (spdTackTime.ActiveSheet.RowCount <= 0)
                        {
                            //CMN465 INFO - 체크항목이 존재하지 않습니다. 확인해주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(465));
                            return false;
                        }
                        break;

                    case CSGC.CHECK.DELETE:
                        if (spdTackTime.ActiveSheet.RowCount <= 0)
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

        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":
                        saved_row = 0;
                        MPCF.ClearList(spdTackTime);
                        break;

                    case "SAVE":
                    case "DELETE":
                        MPCF.ClearList(spdTackTime);
                        break;

                    case "CLICK_OPER":
                        cdvResId.Text="";
                        cdvMatid.Text = "";
                        s_mat_ver = "";
                        s_unit = "";
                        break;

                    case "UPLOAD":
                        MPCF.ClearList(spdTackTime);
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //TACKTIME조회
        private void ViewTackTime(string sAreaId, string sOper, string sResId, string sMatId)
        {
            string sViewId = "";
            try
            {
                TPDR.DirectViewCond[] dvcProdPlan = new TPDR.DirectViewCond[5];
                DataTable dt = new DataTable();
                string sSql = "";

                sViewId = "CRAS2003-001";

                dvcProdPlan[0].sCondition_ID = "FACTORY";
                dvcProdPlan[0].sCondition_Value = MPGV.gsFactory;

                dvcProdPlan[1].sCondition_ID = "AREA_ID";
                dvcProdPlan[1].sCondition_Value = s_area_id;

                dvcProdPlan[2].sCondition_ID = "OPER";
                dvcProdPlan[2].sCondition_Value = s_oper;

                dvcProdPlan[3].sCondition_ID = "RES_ID";
                dvcProdPlan[3].sCondition_Value = s_res_id;

                dvcProdPlan[4].sCondition_ID = "MAT_ID";
                dvcProdPlan[4].sCondition_Value = s_mat_id;

                if (TPDR.GetDataOne("", ref dt, sViewId, dvcProdPlan, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                saved_row = dt.Rows.Count;

                for (int i = 0; i < saved_row; i++)
                {
                    spdTackTime.ActiveSheet.RowCount++;
                    spdTackTime.ActiveSheet.Cells[i, (int)TACKTIME_INFO.CHECK].Value = true;
                    spdTackTime.ActiveSheet.Cells[i, (int)TACKTIME_INFO.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    spdTackTime.ActiveSheet.Cells[i, (int)TACKTIME_INFO.AREA_CODE].Value = dt.Rows[i]["AREA_ID"];                   
                    spdTackTime.ActiveSheet.Cells[i, (int)TACKTIME_INFO.OPER_CODE].Value = dt.Rows[i]["OPER"];
                    spdTackTime.ActiveSheet.Cells[i, (int)TACKTIME_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdTackTime.ActiveSheet.Cells[i, (int)TACKTIME_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    spdTackTime.ActiveSheet.Cells[i, (int)TACKTIME_INFO.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                    spdTackTime.ActiveSheet.Cells[i, (int)TACKTIME_INFO.MAT_CODE].Value = dt.Rows[i]["MAT_ID"];
                    spdTackTime.ActiveSheet.Cells[i, (int)TACKTIME_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdTackTime.ActiveSheet.Cells[i, (int)TACKTIME_INFO.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdTackTime.ActiveSheet.Cells[i, (int)TACKTIME_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdTackTime.ActiveSheet.Cells[i, (int)TACKTIME_INFO.UNIT].Value = dt.Rows[i]["UNIT"];
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //TACKTIME 저장
        private bool SaveTackTime()
        {
            int totalRow = 0;
            int totalCheckCount = 0;
            int iStart = 0, iEnd = 0;
            int q = 0, r = 0;

            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode tacktime_list;
                int iCheckCount = 0;
 
                SheetView sv = spdTackTime.ActiveSheet;

                iCheckCount = 0;
                totalRow = sv.RowCount;
                q = totalRow / ROW; 
                r = totalRow % ROW; 

                for(int k=0;k<=q;k++)
                {
                    in_node.Init();

                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '1';

                    iStart = iEnd;
                    iEnd = iStart+(k==q?r:ROW);
                  
                    for (int i = iStart; i < iEnd; i++)
                    {                    
                        if (sv.Cells[i, (int)TACKTIME_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                        {
                            //사업부 검사
                            if (MPCF.Trim(sv.Cells[i, (int)TACKTIME_INFO.AREA_DESC].Value) == "")
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                sv.SetActiveCell(i, (int)TACKTIME_INFO.AREA_DESC);
                                return false;
                            }

                            //공정 검사
                            if (MPCF.Trim(sv.Cells[i, (int)TACKTIME_INFO.OPER_CODE].Value) == "")
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                sv.SetActiveCell(i, (int)TACKTIME_INFO.OPER_CODE);
                                return false;
                            }

                            //설비 검사
                            if (MPCF.Trim(sv.Cells[i, (int)TACKTIME_INFO.RES_ID].Value) == "")
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                sv.SetActiveCell(i, (int)TACKTIME_INFO.RES_ID);
                                return false;
                            }

                            //품목검사
                            if (MPCF.Trim(sv.Cells[i, (int)TACKTIME_INFO.MAT_CODE].Value) == "")
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                sv.SetActiveCell(i, (int)TACKTIME_INFO.MAT_CODE);
                                return false;
                            }

                            tacktime_list = in_node.AddNode("DATA_LIST");

                            tacktime_list.AddString("OPER", MPCF.Trim(sv.Cells[i, (int)TACKTIME_INFO.OPER_CODE].Value));
                            tacktime_list.AddString("RES_ID", MPCF.Trim(sv.Cells[i, (int)TACKTIME_INFO.RES_ID].Value));
                            tacktime_list.AddString("MAT_ID", MPCF.Trim(sv.Cells[i, (int)TACKTIME_INFO.MAT_CODE].Value));
                            tacktime_list.AddInt("MAT_VER", MPCF.Trim(sv.Cells[i, (int)TACKTIME_INFO.MAT_VER].Value));
                            tacktime_list.AddDouble("QTY", MPCF.ToDbl(sv.Cells[i, (int)TACKTIME_INFO.QTY].Text));
                            tacktime_list.AddString("UNIT", MPCF.Trim(sv.Cells[i, (int)TACKTIME_INFO.UNIT].Value));

                            iCheckCount++;
                            totalCheckCount++;
                        }
                    }

                    if (iCheckCount > 0)
                    {
                        if (MPCR.CallService("CUS_RAS", "CUS_RAS_Tacktime_Registration", in_node, ref out_node) == false)
                        {
                            return false;
                        }
                    }

                }     
                              
                if(totalCheckCount==0)
                {
                    //체크항목이 존재하지 않습니다. 확인해주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(465));
                    return false;
                }
                return true;
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //TACKTIME 삭제
        private bool DeleteTackTime()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode tacktime_list;
                SheetView sv = spdTackTime.ActiveSheet;
                int iCheckCount = 0;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '2';

                iCheckCount = 0;

                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (sv.Cells[i, 0].Text.ToString().ToUpper() == "TRUE")
                    {
                        //사업부 검사
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)TACKTIME_INFO.AREA_DESC].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            sv.SetActiveCell(i, (int)TACKTIME_INFO.AREA_DESC);
                            return false;
                        }

                        //공정 검사
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)TACKTIME_INFO.OPER_CODE].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            sv.SetActiveCell(i, (int)TACKTIME_INFO.OPER_CODE);
                            return false;
                        }

                        //설비 검사
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)TACKTIME_INFO.RES_ID].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            sv.SetActiveCell(i, (int)TACKTIME_INFO.RES_ID);
                            return false;
                        }

                        //품목검사
                        if (string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, (int)TACKTIME_INFO.MAT_CODE].Value)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108));
                            sv.SetActiveCell(i, (int)TACKTIME_INFO.MAT_CODE);
                            return false;
                        }

                        tacktime_list = in_node.AddNode("DATA_LIST");

                        tacktime_list.AddString("OPER", MPCF.Trim(sv.Cells[i, (int)TACKTIME_INFO.OPER_CODE].Value));
                        tacktime_list.AddString("RES_ID", MPCF.Trim(sv.Cells[i, (int)TACKTIME_INFO.RES_ID].Value));
                        tacktime_list.AddString("MAT_ID", MPCF.Trim(sv.Cells[i, (int)TACKTIME_INFO.MAT_CODE].Value));

                        iCheckCount++;
                    }
                }

                if (iCheckCount > 0)
                {
                    if (MPCR.CallService("CUS_RAS", "CUS_RAS_Tacktime_Registration", in_node, ref out_node) == false)
                    {
                        return false;
                    }
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
       
        //엑셀정보 가져오기
        private void GetDataByExcel()
        {
            Excel.Application XApp = null;
            Excel.Workbooks XBooks = null;
            Excel.Workbook XBook = null;
            Excel.Worksheet XSheet = null;
            Excel.Sheets XSheets = null;

            OpenFileDialog ofdFile = new OpenFileDialog();
           
            try
            {
                ofdFile.Filter = "Excel Files(*.xls;*.xlsx)|*.xls;*.xlsx";
                ofdFile.DefaultExt = "xls,xlsx";

                if (ofdFile.ShowDialog() != DialogResult.OK)
                    return;

                XApp = new Excel.Application();
                XApp.Interactive = false;
                XBooks = XApp.Workbooks;
                XBook = XBooks.Open(ofdFile.FileName);

                ((Excel.Worksheet)XBook.Sheets[1]).Select();

                XSheets = XBook.Worksheets;
                XSheet = XSheets.get_Item(1) as Excel.Worksheet;

                //시트에서 사용된 셀범위
                Excel.Range range = XSheet.UsedRange;

                //2차원 배열에 담기
                Object[,] data = range.Value;
                int row_count = range.Rows.Count;
                spdTackTime_Sheet1.RowCount = row_count - 1;

                for(int i= 2;i<= row_count; i++)
                {
                    spdTackTime_Sheet1.Cells[i - 2, (int)TACKTIME_INFO.CHECK].Value = true;
                    spdTackTime_Sheet1.Cells[i - 2, (int)TACKTIME_INFO.AREA_DESC].Value = data[i, (int)TACKTIME_EXCEL.AREA_DESC];
                    spdTackTime_Sheet1.Cells[i - 2, (int)TACKTIME_INFO.OPER_CODE].Value = data[i, (int)TACKTIME_EXCEL.OPER_CODE];
                    spdTackTime_Sheet1.Cells[i - 2, (int)TACKTIME_INFO.OPER_DESC].Value = data[i, (int)TACKTIME_EXCEL.OPER_DESC];
                    spdTackTime_Sheet1.Cells[i - 2, (int)TACKTIME_INFO.RES_ID].Value = data[i, (int)TACKTIME_EXCEL.RES_ID];
                    spdTackTime_Sheet1.Cells[i - 2, (int)TACKTIME_INFO.RES_DESC].Value = data[i, (int)TACKTIME_EXCEL.RES_DESC];
                    spdTackTime_Sheet1.Cells[i - 2, (int)TACKTIME_INFO.MAT_CODE].Value = data[i, (int)TACKTIME_EXCEL.MAT_CODE];
                    spdTackTime_Sheet1.Cells[i - 2, (int)TACKTIME_INFO.MAT_DESC].Value = data[i, (int)TACKTIME_EXCEL.MAT_DESC];
                    spdTackTime_Sheet1.Cells[i - 2, (int)TACKTIME_INFO.QTY].Value = data[i, (int)TACKTIME_EXCEL.QTY];
                    spdTackTime_Sheet1.Cells[i - 2, (int)TACKTIME_INFO.UNIT].Value = data[i, (int)TACKTIME_EXCEL.UNIT];
                }

                XBook.Close(true);
                XApp.Quit();
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            finally
            {
                ReleasExcelObject(XSheet);
                ReleasExcelObject(XBook);
                ReleasExcelObject(XApp);           
            }
        }

        private void ReleasExcelObject(object obj)
        {
            try
            {
                if(obj!=null)
                {
                    System.Runtime.InteropServices.Marshal.ReleaseComObject(obj);
                    obj = null;
                }
            }
            catch(Exception ex)
            {
                obj = null;
                throw ex;
            }
            finally
            {
                GC.Collect();
            }
        }
        #endregion

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void cdvMatid_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.Width = 900;
                popup.Height = 500;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvMatid.Text = popup.sMat_id;
                    cdvMatid.DisplayText = popup.sMat_Desc;
                    s_mat_ver = popup.sMat_ver;
                    s_unit = "min/" + popup.sUnit.ToLower();
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

        private void cdvResId_ButtonPress(object sender, EventArgs e)
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

                cdvResId.Init();
                MPCF.InitListView(cdvResId.GetListView);
                cdvResId.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvResId.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvResId.SelectedSubItemIndex = 0;
                cdvResId.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewResourceList(cdvResId.GetListView, '1', cdvOper.Text) == false)
                    return;

                cdvResId.InsertEmptyRow(0, 1);
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                ClearList("CLICK_OPER");
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkPlace_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                ClearList("CLICK_OPER");
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
                ClearList("CLICK_OPER");
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

                ClearList("VIEW");

                s_area_id = cdvDept.Text;
                s_oper = cdvOper.Text;
                s_res_id = cdvResId.Text;
                s_mat_id = cdvMatid.Text;
                ViewTackTime(s_area_id,s_oper, s_res_id, s_mat_id);
             }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            SheetView sv = spdTackTime.ActiveSheet;
            int iRow = sv.RowCount;

            try
            {
                sv.RowCount++;
                sv.Cells[iRow, (int)TACKTIME_INFO.CHECK].Value = true;          
                sv.Cells[iRow, (int)TACKTIME_INFO.AREA_DESC].Value = cdvDept.DisplayText;
                sv.Cells[iRow, (int)TACKTIME_INFO.AREA_CODE].Value = cdvDept.Text;
                sv.Cells[iRow, (int)TACKTIME_INFO.OPER_CODE].Value = cdvOper.Text;
                sv.Cells[iRow, (int)TACKTIME_INFO.OPER_DESC].Value = cdvOper.DisplayText;
                sv.Cells[iRow, (int)TACKTIME_INFO.RES_ID].Value = cdvResId.Text;
                sv.Cells[iRow, (int)TACKTIME_INFO.RES_DESC].Value = cdvResId.DisplayText;
                sv.Cells[iRow, (int)TACKTIME_INFO.MAT_CODE].Value = cdvMatid.Text;
                sv.Cells[iRow, (int)TACKTIME_INFO.MAT_DESC].Value = cdvMatid.DisplayText;
                sv.Cells[iRow, (int)TACKTIME_INFO.MAT_VER].Value = s_mat_ver;
                sv.Cells[iRow, (int)TACKTIME_INFO.UNIT].Value = s_unit;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
           
        }

        private void btnRowDel_Click(object sender, EventArgs e)
        {
            SheetView sv = spdTackTime.ActiveSheet;

            try
            {
                for (int i = sv.RowCount - 1; i >= 0; i--)
                {
                    if (sv.Cells[i, 0].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (i < saved_row)
                        {
                            return;
                        }

                        sv.RemoveRows(i, 1);
                    }
                }
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

                if(SaveTackTime())
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(52));

                    ClearList("SAVE");
                    ViewTackTime(cdvDept.Text, cdvOper.Text, cdvResId.Text, cdvMatid.Text);
                }
            }
            catch(Exception ex)
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
                    if (DeleteTackTime())
                    {
                        ClearList("DELETE");
                        ViewTackTime(cdvDept.Text, cdvOper.Text, cdvResId.Text, cdvMatid.Text);

                        MPCF.ShowMsgBox(MPCF.GetMessage(52));
                    }
                }
        
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdTackTime_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            try
            {
                SheetView sv = spdTackTime.ActiveSheet;

                if (e.Row < saved_row)
                    return;

                if (e.Column == (int)TACKTIME_INFO.AREA_BUTTON || e.Column == (int)TACKTIME_INFO.OPER_BUTTON || e.Column == (int)TACKTIME_INFO.RES_ID_BUTTON)
                {
                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                    if (e.Column == (int)TACKTIME_INFO.AREA_BUTTON)
                    {
                        //사업부 조회
                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                            return;

                        sv.Cells[e.Row, (int)TACKTIME_INFO.OPER_CODE].Value = string.Empty;
                        sv.Cells[e.Row, (int)TACKTIME_INFO.OPER_DESC].Value = string.Empty;
                        sv.Cells[e.Row, (int)TACKTIME_INFO.RES_ID].Value = string.Empty;
                        sv.Cells[e.Row, (int)TACKTIME_INFO.RES_DESC].Value = string.Empty;
                        
                       
                    }
                    else if (e.Column == (int)TACKTIME_INFO.OPER_BUTTON)
                    {
                        //공정 조회
                        if (COM_LIST.ViewOperationList(cdvGridButton.GetListView, '2', MPCF.Trim(sv.Cells[e.Row, (int)TACKTIME_INFO.AREA_CODE].Value)) == false)
                        {
                            return;
                        }

                        sv.Cells[e.Row, (int)TACKTIME_INFO.RES_ID].Value = string.Empty;
                        sv.Cells[e.Row, (int)TACKTIME_INFO.RES_DESC].Value = string.Empty;
                    }
                    else if (e.Column == (int)TACKTIME_INFO.RES_ID_BUTTON)
                    {
                        //설비 조회
                        if (COM_LIST.ViewResourceList(cdvGridButton.GetListView, '1', MPCF.Trim(sv.Cells[e.Row, (int)TACKTIME_INFO.OPER_CODE].Value)) == false)
                        {
                            return;
                        }
                    }

                    sv.Cells[e.Row, (int)TACKTIME_INFO.MAT_CODE].Value = string.Empty;
                    sv.Cells[e.Row, (int)TACKTIME_INFO.MAT_DESC].Value = string.Empty;
                    sv.Cells[e.Row, (int)TACKTIME_INFO.UNIT].Value = string.Empty;

                    cdvGridButton.ShowPopupList(e.Row, e.Column);
                    cdvGridButton.InsertEmptyRow(0, 1);
                }             
                else if (e.Column == (int)TACKTIME_INFO.MAT_BUTTON)
                {
                    //품명 조회
                    frmPopMaterialList popup = new frmPopMaterialList();
                    popup.StartPosition = FormStartPosition.CenterParent;
                    popup.Width = 900;
                    popup.Height = 500;
                    popup.sArea_id = sv.Cells[e.Row, (int)TACKTIME_INFO.AREA_CODE].Value == null ? string.Empty : sv.Cells[e.Row, (int)TACKTIME_INFO.AREA_CODE].Value.ToString();
                    popup.sArea_desc = sv.Cells[e.Row, (int)TACKTIME_INFO.AREA_DESC].Value == null ? string.Empty : sv.Cells[e.Row, (int)TACKTIME_INFO.AREA_DESC].Value.ToString();

                    if (popup.ShowDialog() == DialogResult.OK)
                    {
                        sv.Cells[e.Row, (int)TACKTIME_INFO.MAT_CODE].Value = popup.sMat_id;
                        sv.Cells[e.Row, (int)TACKTIME_INFO.MAT_DESC].Value = popup.sMat_Desc;
                        sv.Cells[e.Row, (int)TACKTIME_INFO.MAT_VER].Value = popup.sMat_ver;
                        sv.Cells[e.Row, (int)TACKTIME_INFO.UNIT].Value = "min/"+popup.sUnit.ToLower();
                        popup = null;
                    }
                    else
                    {
                        return;
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            SheetView sv = spdTackTime.ActiveSheet;
            try
            {
                if (sv.ActiveColumnIndex == (int)TACKTIME_INFO.AREA_BUTTON)
                {                  
                    sv.SetValue(e.Row, (int)TACKTIME_INFO.AREA_DESC, e.SelectedItem.SubItems[0].Text);
                    sv.SetValue(e.Row, (int)TACKTIME_INFO.AREA_CODE, e.SelectedItem.SubItems[1].Text);
                }
                else if (sv.ActiveColumnIndex == (int)TACKTIME_INFO.OPER_BUTTON)
                {
                    sv.SetValue(e.Row, (int)TACKTIME_INFO.OPER_CODE, e.SelectedItem.SubItems[0].Text);
                    sv.SetValue(e.Row, (int)TACKTIME_INFO.OPER_DESC, e.SelectedItem.SubItems[1].Text);
                }
                else if (sv.ActiveColumnIndex == (int)TACKTIME_INFO.RES_ID_BUTTON)
                {
                    sv.SetValue(e.Row, (int)TACKTIME_INFO.RES_ID, e.SelectedItem.SubItems[0].Text);
                    sv.SetValue(e.Row, (int)TACKTIME_INFO.RES_DESC, e.SelectedItem.SubItems[1].Text);
                }
                else if (sv.ActiveColumnIndex == (int)TACKTIME_INFO.MAT_BUTTON)
                {
                    sv.SetValue(e.Row, (int)TACKTIME_INFO.MAT_CODE, e.SelectedItem.SubItems[0].Text);
                    sv.SetValue(e.Row, (int)TACKTIME_INFO.MAT_DESC, e.SelectedItem.SubItems[1].Text);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnUploadExcel_Click(object sender, EventArgs e)
        {
            try
            {
                ClearList("UPLOAD");

                GetDataByExcel();

                MPCF.ShowMsgBox(MPCF.GetMessage(52));
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdTackTime_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (spdTackTime.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdTackTime, e.Row, e.Column, true, true, false);
                    }
                }
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatid_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatid.DisplayText == "")
                cdvMatid.Text = "";
        }
    }
}
