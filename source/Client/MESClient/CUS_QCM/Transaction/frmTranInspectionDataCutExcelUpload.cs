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
namespace CUS_QCM
{
    public partial class frmTranInspectionDataCutExcelUpload : CUS_COM.frmViewForm01
    {
        public frmTranInspectionDataCutExcelUpload()
        {
            InitializeComponent();

            InitControl();
        }


        #region " Constant Definition "
        private enum LOT_INFO
        {
            NO,
            LOT_ID,
            SAMPLE_SEQ,
            ANGLE1,
            ANGLE2,
            LENG1,
            LENG2,
            LENG3,
            UT,
            ALL_T,
            CIQC31,
        }
        #endregion

        #region " Variable Definition "

        private void InitControl()
        {
            try
            {
                // btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                pnlSaveList.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion



        #region " Function Definition "

        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                int iTry;

                switch (CHECK)
                {
                    case CSGC.CHECK.SAVE:

                        if (spdInspectionData.ActiveSheet.RowCount == 0)
                        {
                            //저장 할 데이터가 없습니다. 
                            MPCF.ShowMsgBox(MPCF.GetMessage(531));
                            spdInspectionData.Select();
                            return false;
                        }

                        for (int i = 0; i < spdInspectionData.ActiveSheet.RowCount; i++)
                        {
                            if (spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SAMPLE_SEQ].Text.Trim() == "")
                            {
                                //샘플번호는 반드시 입력되어어야 합니다.
                                MPCF.ShowMsgBox(MPCF.GetMessage(532));
                                return false;
                            }

                            if (!Int32.TryParse(spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SAMPLE_SEQ].Text, out iTry))
                            {
                                //샘플번호는 반드시 숫자만 입력할 수 있습니다.
                                MPCF.ShowMsgBox(MPCF.GetMessage(533));
                                return false;
                            }

                            if (iTry > 25)
                            {
                                // 샘플번호값은 25를 초과할 수 없습니다. ( 검사 횟수 최대값 : 25 )
                                MPCF.ShowMsgBox(MPCF.GetMessage(534));
                                return false;
                            }

                        }


                        for (int i = 0; i < spdInspectionData.ActiveSheet.RowCount; i++)
                        {
                            if (spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text.Trim() == "")
                            {
                                // LOT ID는 반드시 입력되어야 합니다.
                                return false;
                            }
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

        private bool CollectInspectionData()
        {

            try
            {
                TRSNode in_node = new TRSNode("COLLECT_LOT_DATA_IN");
                TRSNode out_node = new TRSNode("COLLECT_LOT_DATA_OUT");
                TRSNode data_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                DataTable dt = new DataTable();

                dt.Columns.Add("NO");
                dt.Columns.Add("LOT_ID");
                dt.Columns.Add("SAMPLE");
                dt.Columns.Add("ANGLE_1");
                dt.Columns.Add("ANGLE_2");
                dt.Columns.Add("LENGTH_1");
                dt.Columns.Add("LENGTH_2");
                dt.Columns.Add("LENGTH_3");
                dt.Columns.Add("UT");
                dt.Columns.Add("ALL_THICK");
                dt.Columns.Add("CIQC31");

                for (int i = 0; i < spdInspectionData.ActiveSheet.RowCount; i++)
                {

                    dt.Rows.Add(spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.NO].Text,
                                       spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text,
                                       spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SAMPLE_SEQ].Text,
                                       spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.ANGLE1].Text,
                                       spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.ANGLE2].Text,
                                       spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LENG1].Text,
                                       spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LENG2].Text,
                                       spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LENG3].Text,
                                       spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.UT].Text,
                                       spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.ALL_T].Text,
                                       spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CIQC31].Text
                        );
                }



                dt = dt.Select("", "LOT_ID ASC , SAMPLE ASC").CopyToDataTable<DataRow>();

                int i_input_count = 0;

                int i_start = 0;
                int i_end;

                string sNewLotID = "";
                string sOldLotID = "";

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    if (i == 0)
                    {
                        sNewLotID = dt.Rows[i]["LOT_ID"].ToString();
                    }

                    if (sNewLotID != dt.Rows[i]["LOT_ID"].ToString() || i == dt.Rows.Count - 1)
                    {
                        if (i == dt.Rows.Count - 1)
                        {
                            i_end = i + 1;
                        }
                        else
                        {
                            i_end = i;
                        }


                        sOldLotID = sNewLotID;
                        sNewLotID = dt.Rows[i]["LOT_ID"].ToString();

                        //20210915 syw 품질팀 요청에 의해 부분저장 가능하도록 각각했을경우 마지막걸로 들어가는 문제.전체데이터가. 현장 데이터 뽑는 PC들이 다름.
                        //syw 항목별로 체크해서 저장되도록
                        for (int icol = 3; icol < dt.Columns.Count; icol++)
                        {


                            data_list = in_node.AddNode("DATA_LIST");

                            data_list.AddString("LOT_ID", sOldLotID);

                            if (icol == 3)
                            {
                                if (chkAngle1.Checked == false)
                                {
                                    continue;
                                }

                                data_list.AddString("CHAR_ID", "ANGLE1");

                            }
                            else if (icol == 4)
                            {
                                if (chkAngle2.Checked == false)
                                {
                                    continue;
                                }

                                data_list.AddString("CHAR_ID", "ANGLE2");
                            }
                            else if (icol == 5)
                            {
                                if (chkLeng1.Checked == false)
                                {
                                    continue;
                                }
                                data_list.AddString("CHAR_ID", "LENG1");
                            }
                            else if (icol == 6)
                            {
                                if (chkLeng2.Checked == false)
                                {
                                    continue;
                                }
                                data_list.AddString("CHAR_ID", "LENG2");
                            }
                            else if (icol == 7)
                            {
                                if (chkLeng3.Checked == false)
                                {
                                    continue;
                                }
                                data_list.AddString("CHAR_ID", "LENG3");
                            }
                            else if (icol == 8)
                            {
                                if (chkGradeT.Checked == false)
                                {
                                    continue;
                                }
                                data_list.AddString("CHAR_ID", "GRADE-T");
                            }
                            else if (icol == 9)
                            {
                                if (chkAllT.Checked == false)
                                {
                                    continue;
                                }
                                data_list.AddString("CHAR_ID", "ALL-T");
                            }

                            else if (icol == 10)
                            {
                                if (chkCiqc31.Checked == false)
                                {
                                    continue;
                                }
                                data_list.AddString("CHAR_ID", "CIQC31");
                            }

                            for (int irow = i_start; irow < i_end; irow++)
                            {
                                data_list.AddString("VALUE_" + dt.Rows[irow]["SAMPLE"].ToString(), dt.Rows[irow][icol].ToString());

                                if (dt.Rows[irow][icol].ToString().Trim() != "")
                                {
                                    i_input_count++;
                                }
                            }

                            if (i_input_count == 0) // 해당 Lot의 특정검사항목코드의 검사데이터를 한건도 입력하지 않았으면,
                            {
                                data_list.SetChar("SKIP_YN", 'Y');
                            }

                            i_input_count = 0;

                        }

                        i_start = i_end;

                    }
                }

                if (MPCR.CallService("CUS_QCM", "CUS_QCM_Collect_Cut_Inspection_Upload", in_node, ref out_node, false) == false)
                {
                    return false;
                }
                else
                {
                    MPCR.ShowSuccessMsg(out_node);
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

        }

        private void initSpreadSheet()
        {
            spdInspectionData.ActiveSheet.Columns[0].Label = "No.";
            spdInspectionData.ActiveSheet.Columns[1].Label = "Lot ID";
            spdInspectionData.ActiveSheet.Columns[2].Label = "#샘플";

            //각도#1
            spdInspectionData.ActiveSheet.Columns[3].Label = "각도#1";
            spdInspectionData.ActiveSheet.Columns[3].Tag = "ANGLE1";

            //각도#2
            spdInspectionData.ActiveSheet.Columns[4].Label = "각도#2";
            spdInspectionData.ActiveSheet.Columns[4].Tag = "ANGLE2";

            //변길이#1
            spdInspectionData.ActiveSheet.Columns[5].Label = "변길이#1";
            spdInspectionData.ActiveSheet.Columns[5].Tag = "LENG1";

            //변길이#2
            spdInspectionData.ActiveSheet.Columns[6].Label = "변길이#2";
            spdInspectionData.ActiveSheet.Columns[6].Tag = "LENG2";

            //변길이#3
            spdInspectionData.ActiveSheet.Columns[7].Label = "변길이#3";
            spdInspectionData.ActiveSheet.Columns[7].Tag = "LENG3";

            //UT편차
            spdInspectionData.ActiveSheet.Columns[8].Label = "UT";
            spdInspectionData.ActiveSheet.Columns[8].Tag = "GRADE-T";

            //전체두께
            spdInspectionData.ActiveSheet.Columns[9].Label = "전체두께";
            spdInspectionData.ActiveSheet.Columns[9].Tag = "ALL-T";


            //전체두께
            spdInspectionData.ActiveSheet.Columns[10].Label = "절단데미지";
            spdInspectionData.ActiveSheet.Columns[10].Tag = "CIQC31";
        }

        private void OpenExcelFile(string filename)
        {
            //int i;
            int i_cnt_col;
            int i_cnt_row;

            try
            {

                // spdInspectionData.Sheets.Count = 0;



                if (spdInspectionData.ActiveSheet.OpenExcel(filename, 0) == false)
                {
                    return;
                }


                i_cnt_col = 11; // 컬럼 수
                i_cnt_row = 0;

                //Import한 row수
                while (MPCF.Trim(spdInspectionData.ActiveSheet.Cells[i_cnt_row, 0].Value) != "")
                {
                    i_cnt_row++;
                }

                //설비에서 Convert한  의미 없는 2행 제거
                spdInspectionData.ActiveSheet.Rows[0, 1].Remove();


                //업로드한 기준으로 스프레드 정리
                spdInspectionData.ActiveSheet.ColumnCount = i_cnt_col;
                spdInspectionData.ActiveSheet.RowCount = i_cnt_row - 2;

                initSpreadSheet();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
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

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {

            int iActiveRowCount = 0;

            for (int i = 0; i < spdInspectionData.ActiveSheet.RowCount; i++)
            {
                if (spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text.Trim() == "" || i == spdInspectionData.ActiveSheet.RowCount - 1)
                {
                    if (i == spdInspectionData.ActiveSheet.RowCount - 1)
                    {
                        iActiveRowCount = i + 1;
                    }
                    else
                    {
                        iActiveRowCount = i;
                    }

                    break;
                }
            }

            spdInspectionData.ActiveSheet.RowCount = iActiveRowCount;


            // ((DataTable)spdInspectionData_Sheet1.DataSource).AcceptChanges();



            if (CheckCondition(CSGC.CHECK.SAVE) == false)
                return;


            if (!CollectInspectionData())
            {
                return;
            }

            MPCF.ClearList(spdInspectionData);
            spdInspectionData.ActiveSheet.RowCount = 500;

        }

        private void button1_Click(object sender, EventArgs e)
        {
            DataTable dt = new DataTable();


            dt.Columns.Add("No");
            dt.Columns.Add("LOT_ID");
            dt.Columns.Add("SAMPLE");
            dt.Columns.Add("ANGLE_1");
            dt.Columns.Add("ANGLE_2");
            dt.Columns.Add("LENGTH_1");
            dt.Columns.Add("LENGTH_2");
            dt.Columns.Add("LENGTH_3");
            dt.Columns.Add("UT");
            dt.Columns.Add("ALL_THICK");
            dt.Columns.Add("CIQC31");  //절단데미지

            dt.Rows.Add(1, "C210113-0026", 1, "", "", "4.205", "3.811", "", "", "1.615");
            dt.Rows.Add(2, "C210113-0026", 2, "", "", "4.203", "3.807", "", "", "1.615");
            dt.Rows.Add(3, "C210113-0026", 3, "", "", "4.222", "3.820", "", "", "1.618");
            dt.Rows.Add(4, "C210113-0026", 4, "", "", "4.205", "3.808", "", "", "1.614");
            dt.Rows.Add(5, "C210113-0026", 5, "", "", "4.218", "3.828", "", "", "1.620");

            dt.Rows.Add(1, "C210113-0025", 1, "", "", "4.209", "3.805", "", "", "1.611");
            dt.Rows.Add(2, "C210113-0025", 2, "", "", "4.213", "3.804", "", "", "1.612");
            dt.Rows.Add(3, "C210113-0025", 3, "", "", "4.209", "3.796", "", "", "1.613");
            dt.Rows.Add(4, "C210113-0025", 4, "", "", "4.204", "3.111", "", "", "1.614");
            dt.Rows.Add(5, "C210113-0025", 5, "", "", "4.211", "3.222", "", "", "1.625");

            dt.Rows.Add(1, "C210113-0024", 1, "", "", "4.201", "3.813", "", "", "1.615");
            dt.Rows.Add(2, "C210113-0024", 2, "", "", "4.202", "3.804", "", "", "1.616");
            dt.Rows.Add(3, "C210113-0024", 3, "", "", "4.223", "3.825", "", "", "1.617");
            dt.Rows.Add(4, "C210113-0024", 4, "", "", "4.204", "3.806", "", "", "1.618");
            dt.Rows.Add(5, "C210113-0024", 5, "", "", "4.215", "3.827", "", "", "1.629");

            spdInspectionData_Sheet1.DataSource = dt;



        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {

                FpSpread excelSp = new FpSpread();
                SheetView sheet1 = new SheetView();

                string sFileName = EXTFUC.ShowFileOpenDialog("Inspection Data");

                if (String.IsNullOrEmpty(sFileName))
                {
                    return;
                }


                sheet1 = spdInspectionData_Sheet1;

                sheet1.SheetName = "Inspection Data";
                sheet1.ColumnCount = spdInspectionData_Sheet1.ColumnCount;
                sheet1.RowCount = spdInspectionData_Sheet1.RowCount;
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

        private void btnOpenFile_Click(object sender, EventArgs e)
        {
            try
            {
                //ofdAttachFile

                ofdAttachFile.Filter = "Excel Files(*.xls;*.xlsx)|*.xls;*.xlsx";
                ofdAttachFile.DefaultExt = "xls,xlsx";

                if (ofdAttachFile.ShowDialog() == DialogResult.OK)
                {
                    MPCF.ClearList(spdInspectionData);
                    /*
                      for (i = 0; i < ofdAttachFile.FileNames.Length; i++)
                    {
                        iRow = spdFileList.Sheets[0].RowCount;
                        spdFileList.Sheets[0].RowCount++;

                        spdFileList.Sheets[0].Cells[iRow, 0].Value = true;
                        spdFileList.Sheets[0].Cells[iRow, 1].Value = ofdAttachFile.FileNames[i];
                    }*/

                    OpenExcelFile(ofdAttachFile.FileName);


                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {

            CollectInspectionData();


        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            MPCF.ClearList(spdInspectionData);

            spdInspectionData.ActiveSheet.RowCount = 500;
        }

        private void chkAll_CheckedChanged(object sender, EventArgs e)
        {
            if (chkAll.Checked == true)
            {
                chkAngle1.Checked = true;
                chkAngle2.Checked = true;
                chkLeng1.Checked = true;
                chkLeng2.Checked = true;
                chkLeng3.Checked = true;
                chkAllT.Checked = true;
                chkGradeT.Checked = true;
                chkCiqc31.Checked = true;

                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.ANGLE1).Visible = true;
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.ANGLE2).Visible = true;
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.LENG1).Visible = true;
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.LENG2).Visible = true;
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.LENG3).Visible = true;
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.UT).Visible = true;
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.ALL_T).Visible = true;
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.CIQC31).Visible = true;



            }
            else
            {
                chkAngle1.Checked = false;
                chkAngle2.Checked = false;
                chkLeng1.Checked = false;
                chkLeng2.Checked = false;
                chkLeng3.Checked = false;
                chkAllT.Checked = false;
                chkGradeT.Checked = false;
                chkCiqc31.Checked = false;

                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.ANGLE1).Visible = false;
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.ANGLE2).Visible = false;
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.LENG1).Visible = false;
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.LENG2).Visible = false;
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.LENG3).Visible = false;
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.UT).Visible = false;
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.ALL_T).Visible = false;
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.CIQC31).Visible = false;
            }

        }

        private void chkAngle1_CheckedChanged(object sender, EventArgs e)
        {
            if (chkAngle1.Checked == true)
            {
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.ANGLE1).Visible = true;
            }
            else
            {
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.ANGLE1).Visible = false;
            }

        }

        private void chkAngle2_CheckedChanged(object sender, EventArgs e)
        {
            if (chkAngle2.Checked == true)
            {
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.ANGLE2).Visible = true;
            }
            else
            {
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.ANGLE2).Visible = false;
            }

        }

        private void chkLeng1_CheckedChanged(object sender, EventArgs e)
        {
            if (chkLeng1.Checked == true)
            {
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.LENG1).Visible = true;
            }
            else
            {
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.LENG1).Visible = false;
            }

        }

        private void chkLeng2_CheckedChanged(object sender, EventArgs e)
        {
            if (chkLeng2.Checked == true)
            {
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.LENG2).Visible = true;
            }
            else
            {
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.LENG2).Visible = false;
            }

        }

        private void chkLeng3_CheckedChanged(object sender, EventArgs e)
        {
            if (chkLeng3.Checked == true)
            {
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.LENG3).Visible = true;
            }
            else
            {
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.LENG3).Visible = false;
            }

        }

        private void chkAllT_CheckedChanged(object sender, EventArgs e)
        {
            if (chkAllT.Checked == true)
            {
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.ALL_T).Visible = true;
            }
            else
            {
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.ALL_T).Visible = false;
            }

        }

        private void chkGradeT_CheckedChanged(object sender, EventArgs e)
        {
            if (chkGradeT.Checked == true)
            {
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.UT).Visible = true;
            }
            else
            {
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.UT).Visible = false;
            }

        }

        private void chkCiqc31_CheckedChanged(object sender, EventArgs e)
        {
            if (chkCiqc31.Checked == true)
            {
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.CIQC31).Visible = true;
            }
            else
            {
                spdInspectionData.ActiveSheet.Columns.Get((int)LOT_INFO.CIQC31).Visible = false;
            }

        }

        #endregion
    }
}
