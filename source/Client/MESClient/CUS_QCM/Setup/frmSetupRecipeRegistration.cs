using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
//using MExcel = Microsoft.Office.Interop.Excel;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

namespace CUS_QCM
{
    public partial class frmSetupRecipeRegistration : CUS_COM.frmTranForm05
    {
        public frmSetupRecipeRegistration()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        // 작업자 정보
        private enum RECIPE_INFO : int
        {
            CHECK,                // 선택
            MAT_ID,               //  품목
            MAT_BUTTON,     //  버튼
            MAT_DESC,         //  품목명
            OPER,                //  공정
            OPER_BUTTON,  // 버튼
            OPER_DESC,      //공정명
            RECIPE_NO,        //  레시피 NO
            GRADE,              //  Grade
            THICK,                //  외경 두께
            POL_YN              //  Pol 여부     
        }

        private enum LOT_LIST : int
        {
            LOT_ID,
            MAT_ID,
            MAT_DESC,
            OPER,
            OPER_DESC,
            RECIPE_NO,
            GRADE,
            THICK,
            POL_YN
        }

        private enum RECIPE_UNREG_LIST : int
        {
            MAT_ID,
            MAT_DESC,
            OPER,
            OPER_DESC
        }

        //Excel 작업자 정보
        private enum WORKER_EXCEL : int
        {
            WORKER_ID,              // 1 : 사번
            WORKER_DESC,            // 2 : 작업자 명
            AREA_DESC,              // 3 : 사업부명
            DEPT_CODE,              // 6 : 부서정보코드  
            DEPT_DESC               // 7 : 부서정보명            
        }

        #endregion

        #region " Variable Definition "

        int worker_row = 0;
   
        int check_cnt = 0; 

        #endregion

        #region " Function Defintion "
        private void InitControl()
        {
            try
            {
                btnExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                btnUploadExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        //초기화
        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "EXCEL_DOWNLOAD":
                        break;

                    case "EXCEL_UPLOAD":
                        MPCF.ClearList(spdRecipe);

                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void ViewRecipeList()
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CQCM1003-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatID.Text;

                dvcArgu[3].sCondition_ID = "MAT_DESC";
                dvcArgu[3].sCondition_Value = txtMatDesc.Text;

                dvcArgu[4].sCondition_ID = "OPER";
                dvcArgu[4].sCondition_Value = cdvOper.Text;

                MPCF.ClearList(spdRecipe);

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdRecipe_Sheet1.RowCount++;

                    spdRecipe_Sheet1.Cells[i, (int)RECIPE_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdRecipe_Sheet1.Cells[i, (int)RECIPE_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdRecipe_Sheet1.Cells[i, (int)RECIPE_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdRecipe_Sheet1.Cells[i, (int)RECIPE_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdRecipe_Sheet1.Cells[i, (int)RECIPE_INFO.RECIPE_NO].Value = dt.Rows[i]["RECIPE_NO"];
                    spdRecipe_Sheet1.Cells[i, (int)RECIPE_INFO.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdRecipe_Sheet1.Cells[i, (int)RECIPE_INFO.THICK].Value = dt.Rows[i]["THICK"];
                    spdRecipe_Sheet1.Cells[i, (int)RECIPE_INFO.POL_YN].Value = dt.Rows[i]["POL_YN"];
                }
                //MPCF.FitColumnHeader(spdWorker);
                worker_row = spdRecipe_Sheet1.RowCount;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void ViewLotList()
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CQCM1003-002";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = cdvMatID.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;

                MPCF.ClearList(spdLotList);

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Sheet1.RowCount++;

                    spdLotList_Sheet1.Cells[i, (int)LOT_LIST.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_LIST.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_LIST.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_LIST.RECIPE_NO].Value = dt.Rows[i]["RECIPE_NO"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_LIST.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_LIST.THICK].Value = dt.Rows[i]["THICK"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_LIST.POL_YN].Value = dt.Rows[i]["POL_YN"];
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void ViewRecipeUnRegisteredList()
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CQCM1003-003";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;


                MPCF.ClearList(spdRecipeUnregList);

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    
                    spdRecipeUnregList_Sheet1.RowCount++;

                    spdRecipeUnregList_Sheet1.Cells[i, (int)RECIPE_UNREG_LIST.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdRecipeUnregList_Sheet1.Cells[i, (int)RECIPE_UNREG_LIST.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdRecipeUnregList_Sheet1.Cells[i, (int)RECIPE_UNREG_LIST.OPER].Value = dt.Rows[i]["OPER"];
                    spdRecipeUnregList_Sheet1.Cells[i, (int)RECIPE_UNREG_LIST.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];

                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private bool CheckCondition(string _check)
        {
            try
            {
                switch (_check)
                {
                    case "1":
                        if (MPCF.Trim(cdvDept.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }
                      
                        break;

                    case "2":
                        if (MPCF.Trim(cdvDept.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvMatID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMatID.Text + "]");
                            cdvMatID.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
                            return false;
                        }

                        break;

                    case "3":
                        if (spdLotList_Sheet1.RowCount == 0)
                        {
                            MPCF.ShowMsgBox("No Rows");
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
        private bool CheckRow(int row)
        {
            try
            { 
                if (spdRecipe_Sheet1.Cells[row, (int)RECIPE_INFO.MAT_ID].Text.Trim() == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                    spdRecipe.ActiveSheet.SetActiveCell(row, (int)RECIPE_INFO.MAT_ID);
                    return false;
                }
                if (spdRecipe_Sheet1.Cells[row, (int)RECIPE_INFO.OPER].Text.Trim() == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                    spdRecipe.ActiveSheet.SetActiveCell(row, (int)RECIPE_INFO.OPER);
                    return false;
                }   
                if (spdRecipe_Sheet1.Cells[row, (int)RECIPE_INFO.RECIPE_NO].Text.Trim() == "")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                    spdRecipe.ActiveSheet.SetActiveCell(row, (int)RECIPE_INFO.RECIPE_NO);
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
        private bool SaveRecipeInfo()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode data_list;

                MPCR.SetInMsg(in_node);
               
                in_node.ProcStep = '1';

                check_cnt = 0;

                for (int i = 0; i < spdRecipe_Sheet1.RowCount; i++)
                {
                    if (spdRecipe_Sheet1.Cells[i, (int)RECIPE_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (CheckRow(i))
                        {
                            data_list = in_node.AddNode("DATA_LIST");

                            data_list.AddString("AREA_ID",cdvDept.Text);
                            data_list.AddString("MAT_ID", spdRecipe_Sheet1.Cells[i, (int)RECIPE_INFO.MAT_ID].Text.Trim());
                            data_list.AddString("OPER", spdRecipe_Sheet1.Cells[i, (int)RECIPE_INFO.OPER].Text.Trim());
                            data_list.AddString("RECIPE_NO", spdRecipe_Sheet1.Cells[i, (int)RECIPE_INFO.RECIPE_NO].Text);
                            data_list.AddString("GRADE", spdRecipe_Sheet1.Cells[i, (int)RECIPE_INFO.GRADE].Text);
                            data_list.AddString("THICK", spdRecipe_Sheet1.Cells[i, (int)RECIPE_INFO.THICK].Text);
                            data_list.AddString("POL_YN", spdRecipe_Sheet1.Cells[i, (int)RECIPE_INFO.POL_YN].Text);

                            check_cnt++;
                        }
                        else
                        {
                            return false;
                        }
                    }  
                }

                if (check_cnt > 0)
                {
                    if (MPCR.CallService("CUS_QCM", "CUS_QCM_Recipe_Management", in_node, ref out_node) == false)
                    {
                        return false;
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
        // 작업자 목록 정보로 저장
        private bool SendRecipeInfo()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode data_list;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '3';

                check_cnt = 0;

                for (int i = 0; i < spdLotList_Sheet1.RowCount; i++)
                {

                    data_list = in_node.AddNode("DATA_LIST");

                    data_list.AddString("LOT_ID", spdLotList_Sheet1.Cells[i, (int)LOT_LIST.LOT_ID].Text.Trim());
                    data_list.AddString("MAT_ID", spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAT_ID].Text.Trim());
                    data_list.AddString("MAT_DESC", spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAT_DESC].Text.Trim());
                    data_list.AddString("OPER", spdLotList_Sheet1.Cells[i, (int)LOT_LIST.OPER].Text.Trim());
                    data_list.AddString("OPER_DESC", spdLotList_Sheet1.Cells[i, (int)LOT_LIST.OPER_DESC].Text.Trim());
                    data_list.AddString("RECIPE_NO", spdLotList_Sheet1.Cells[i, (int)LOT_LIST.RECIPE_NO].Text.Trim());
                    data_list.AddString("GRADE", spdLotList_Sheet1.Cells[i, (int)LOT_LIST.GRADE].Text.Trim());
                    data_list.AddString("THICK", spdLotList_Sheet1.Cells[i, (int)LOT_LIST.THICK].Text.Trim());
                    data_list.AddString("POL_YN", spdLotList_Sheet1.Cells[i, (int)LOT_LIST.POL_YN].Text.Trim());

                    check_cnt++;

                }

                if (check_cnt > 0)
                {
                    if (MPCR.CallService("CUS_QCM", "CUS_QCM_Recipe_Management", in_node, ref out_node) == false)
                    {
                        return false;
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
        // 선택된 작업자 삭제
        private bool DeleteRecipeList()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode data_list;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '2';

                check_cnt = 0; 

                for (int i = 0; i < spdRecipe_Sheet1.RowCount; i++)
                {
                    if (spdRecipe_Sheet1.Cells[i, (int)RECIPE_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        data_list = in_node.AddNode("DATA_LIST");

                        data_list.AddString("AREA_ID", cdvDept.Text);
                        data_list.AddString("MAT_ID", spdRecipe.ActiveSheet.Cells[i, (int)RECIPE_INFO.MAT_ID].Text.Trim());
                        data_list.AddString("OPER", spdRecipe.ActiveSheet.Cells[i, (int)RECIPE_INFO.OPER].Text.Trim());
                        check_cnt++;
                    }
                }

                if(check_cnt > 0)
                {
                    if (MPCR.CallService("CUS_QCM", "CUS_QCM_Recipe_Management", in_node, ref out_node) == false)
                    {
                        return false;
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
        //엑셀 다운로드
        private void DownloadExcel()
        {
            /*
            int i=0, j = 0, k=0;
            try
            {          
                for(i =0;i<spdWorker_Sheet1.ColumnCount;i++)
                {
                    if(i==(int)WORKER_INFO.CHECK||i==(int)WORKER_INFO.AREA_ID|| 
                        i==(int)WORKER_INFO.AREA_SELECT||i==(int)WORKER_INFO.DEPT_SELECT)
                    {
                        continue;
                    }
                    
                    spdTemplate.ActiveSheet.ColumnHeader.Cells[j, k].Value = spdWorker_Sheet1.GetColumnLabel(j, i);
                    spdTemplate.ActiveSheet.ColumnHeader.Cells[j, k].BackColor = Color.Yellow;
                    k++;
                }

                for(i = 0;i<spdWorker.ActiveSheet.RowCount;i++)
                {
                    j = i;
                    spdTemplate_Sheet1.Cells[j, (int)WORKER_EXCEL.WORKER_ID].Value = spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Value;
                    spdTemplate_Sheet1.Cells[j, (int)WORKER_EXCEL.WORKER_DESC].Value = spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_DESC].Value;
                    spdTemplate_Sheet1.Cells[j, (int)WORKER_EXCEL.AREA_DESC].Value = spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.AREA_DESC].Value;
                    spdTemplate_Sheet1.Cells[j, (int)WORKER_EXCEL.DEPT_CODE].Value = spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.DEPT_CODE].Value;
                    spdTemplate_Sheet1.Cells[j, (int)WORKER_EXCEL.DEPT_DESC].Value = spdWorker_Sheet1.Cells[i, (int)WORKER_INFO.DEPT_DESC].Value;
                }

                if (sfdFile.ShowDialog() == DialogResult.OK)
                {
                    spdTemplate.SaveExcelAndShow(sfdFile.FileName);
                }

            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            */


        }
        //엑셀 업로드
        private void UploadExcel()
        {
            /*
            MExcel.Application XApp = null;
            MExcel.Workbooks XBooks = null;
            MExcel.Workbook XBook = null;
            MExcel.Worksheet XSheet = null;
            MExcel.Sheets XSheets = null;

            OpenFileDialog ofdFile = new OpenFileDialog();

            try
            {
                ofdFile.Filter = "Excel Files(*.xls;*.xlsx)|*.xls;*.xlsx";
                ofdFile.DefaultExt = "xls,xlsx";

                if (ofdFile.ShowDialog() != DialogResult.OK)
                    return;

                XApp = new MExcel.Application();
                XApp.Interactive = false;
                XBooks = XApp.Workbooks;
                XBook = XBooks.Open(ofdFile.FileName);

                ((Excel.Worksheet)XBook.Sheets[1]).Select();

                XSheets = XBook.Worksheets;
                XSheet = XSheets.get_Item(1) as MExcel.Worksheet;

                //시트에서 사용된 셀범위
                MExcel.Range range = XSheet.UsedRange;

                //2차원 배열에 담기
                Object[,] data = range.Value;
                int row_count = range.Rows.Count;
                spdWorker_Sheet1.RowCount = row_count - 1;

                for (int i = 2; i <= row_count; i++)
                {
                    spdWorker_Sheet1.Cells[i - 2, (int)WORKER_INFO.CHECK].Value = true;
                    spdWorker_Sheet1.Cells[i - 2, (int)WORKER_INFO.WORKER_ID].Value = data[i, (int)WORKER_EXCEL.WORKER_ID+1];
                    spdWorker_Sheet1.Cells[i - 2, (int)WORKER_INFO.WORKER_DESC].Value = data[i, (int)WORKER_EXCEL.WORKER_DESC+1];
                    spdWorker_Sheet1.Cells[i - 2, (int)WORKER_INFO.AREA_DESC].Value = data[i, (int)WORKER_EXCEL.AREA_DESC+1];
                    spdWorker_Sheet1.Cells[i - 2, (int)WORKER_INFO.DEPT_CODE].Value = data[i, (int)WORKER_EXCEL.DEPT_CODE+1];
                    spdWorker_Sheet1.Cells[i - 2, (int)WORKER_INFO.DEPT_DESC].Value = data[i, (int)WORKER_EXCEL.DEPT_DESC+1];
                }

                XBook.Close(true);
                XApp.Quit();

                MPCF.ShowMsgBox(MPCF.GetMessage(52));
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            finally
            {
                ReleasExcelObject(XSheet);
                ReleasExcelObject(XBook);
                ReleasExcelObject(XApp);
            }
            */
        }
        private void ReleasExcelObject(object obj)
        {
            try
            {
                if (obj != null)
                {
                    System.Runtime.InteropServices.Marshal.ReleaseComObject(obj);
                    obj = null;
                }
            }
            catch (Exception ex)
            {
                obj = null;
                throw ex;
            }
            finally
            {
                GC.Collect();
            }
        }
        private bool viewOperList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';


            in_node.AddString("SQL", "SELECT OPER AS CODE, "
                                               + "               OPER_DESC AS NAME "
                                               + "         FROM MWIPOPRDEF "
                                               + "        WHERE AREA_ID = '" + cdvDept.Text + "' "
                                               + "          AND OPER_GRP_2 = 'OQC' "
                                               + "         AND SUB_AREA_ID = 'C_ISP' "
                                               + "        ORDER BY OPER");


            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCR.FillDataView(listView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);

            return true;
        }

        #endregion

        #region " Event Defintion "
        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (tabControl1.SelectedIndex == 0)
                {
                    if (CheckCondition("1") == false)
                    {
                        return;
                    }

                    ViewRecipeList();
                }
                else if (tabControl1.SelectedIndex == 1)
                {
                    // 라운드 Lot 재공 조회
                    if (CheckCondition("2") == false)
                    {
                        return;
                    }

                    ViewLotList();
                }
                else if (tabControl1.SelectedIndex == 2)
                {
                    ViewRecipeUnRegisteredList();
                }
               
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            int iRow = spdRecipe_Sheet1.RowCount;
            FarPoint.Win.Spread.CellType.TextCellType cellType = new FarPoint.Win.Spread.CellType.TextCellType();

            try
            {
                cellType.ReadOnly = false;
                spdRecipe_Sheet1.RowCount++;
                spdRecipe_Sheet1.SetValue(iRow, (int)RECIPE_INFO.CHECK, true);           

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        private void btnRowDel_Click(object sender, EventArgs e)
        {
            try
            {
                for (int i = spdRecipe.ActiveSheet.RowCount - 1; i >= worker_row; i--)
                {
                    if (spdRecipe.ActiveSheet.Cells[i, (int)RECIPE_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        spdRecipe.ActiveSheet.RemoveRows(i, 1);
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
                /*
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                {
                    return;
                }
                */

                //  저장
                if(SaveRecipeInfo())
                {
                    ViewRecipeList();

                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                /*
                if (CheckCondition(CSGC.CHECK.DELETE) == false)
                {
                    return;
                }
                */

                DialogResult dr = MessageBox.Show(MPCF.GetMessage(453), "Info", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);

                if (dr == DialogResult.OK)
                {
                    if (DeleteRecipeList())
                    {
                        ViewRecipeList();

                        MPCF.ShowMsgBox(MPCF.GetMessage(52));
                    }
                }    
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        private void spdWorker_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            if (e.Row < 0)
                return;



            if (e.Column == (int)RECIPE_INFO.MAT_BUTTON)
            {
                try
                {
                    // 제품 팝업으로 변경
                    frmPopMaterialList popup = new frmPopMaterialList();
                    popup.StartPosition = FormStartPosition.CenterParent;
                    popup.sArea_id = "";
                    popup.sArea_desc = "";


                    if (popup.ShowDialog() == DialogResult.OK)
                    {
                        spdRecipe_Sheet1.Cells[e.Row, (int)RECIPE_INFO.CHECK].Value = true;
                        spdRecipe_Sheet1.Cells[e.Row, e.Column - 1].Value = popup.sMat_id;
                        spdRecipe_Sheet1.Cells[e.Row, e.Column + 1].Value = popup.sMat_Desc;
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
            else if (e.Column == (int)RECIPE_INFO.OPER_BUTTON)
            {
                //Class Value
                cdvGridButton.Init();
                MPCF.InitListView(cdvGridButton.GetListView);
                cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);

                viewOperList(cdvGridButton.GetListView);
                
                //cdvGridButton.DropDownSize = 

                cdvGridButton.ShowPopupList(e.Row, e.Column - 1);
               // cdvGridButton.Size = new System.Drawing.Size(100, 100);
               // cdvGridButton.InsertEmptyRow(0, 1);

                

            }

        }
        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            
            try
            {
                if (spdRecipe.ActiveSheet.ActiveColumnIndex == (int)RECIPE_INFO.OPER_BUTTON)
                {
                    spdRecipe_Sheet1.SetValue(e.Row, (int)RECIPE_INFO.OPER, e.SelectedItem.SubItems[0].Text);
                    spdRecipe_Sheet1.SetValue(e.Row, (int)RECIPE_INFO.OPER_DESC, e.SelectedItem.SubItems[1].Text);
                }                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            
        }
        private void spdWorker_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            int iRow = -1;
            int iColumn = -1;

            try
            {
                if (!e.ColumnHeader)
                    return;

                iRow = e.Row;
                iColumn = e.Column;

                if (spdRecipe.ActiveSheet.ColumnHeader.Cells[iRow, iColumn].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdRecipe, iRow, iColumn, true, true, false);
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
                ClearList("EXCEL_DOWNLOAD");

                DownloadExcel();
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnUploadExcel_Click(object sender, EventArgs e)
        {
            try
            {
                ClearList("EXCEL_UPLOAD");
                UploadExcel();
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void frmSetupRecipeRegistration_Load(object sender, EventArgs e)
        {
            cdvDept.Text = CSGV.gs_area_ctm;


            
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
                /*
                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return;
                }*/

                viewOperList(cdvOper.GetListView);

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnSendRecipeInfoToEquipment_Click(object sender, EventArgs e)
        {

            if (CheckCondition("3") == false)
            {
                return;
            }


            DialogResult dr = MessageBox.Show(MPCF.GetMessage(528), "Info", MessageBoxButtons.OKCancel, MessageBoxIcon.Information);

            if (dr == DialogResult.OK)
            {
                if (SendRecipeInfo())
                {
                    ViewRecipeList();

                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                }
            }
        }
        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (tabControl1.SelectedIndex == 0)
            {
                btnProcess.Enabled = true;
                btnDelete.Enabled = true;
            }
            else
            {
                btnProcess.Enabled = false;
                btnDelete.Enabled = false;
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

        #endregion
    }
}
