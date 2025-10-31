using CUS_COM;
using CUS_QCM;
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
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CUS_WIP
{
    public partial class frmWIPViewLotEdc : CUS_COM.frmViewForm02
    {

        

        public frmWIPViewLotEdc()
        {
            InitializeComponent();

            InitControl();
        }

        #region Constant
        private enum INSPECTION_LIST
        {
            OPER_DESC,
            LOT_ID,
            MAT_GRADE,
            START_TIME,
            END_TIME,
            MAT_ID,
            MAT_DESC,
            UNIT,
            IN_QTY,
            OUT_QTY,
            LOSS_QTY
        }


        #endregion

        #region Variable

        private const int DEFAULT_COL_COUNT = 17;

        private const int MAX_DATA_COUNT = 5000;

        private int sheet_st_column_count = 0;



        #endregion

        #region Function

        /// <summary>
        /// 검사현황 조회
        /// </summary>
        /// <returns></returns>
        private bool ViewDataList()
        {

            //INSP관련 정보 혹시 나중에 다시 쓸수도 있어서...일단 컬럼 만들고 히든만 시켜놓음 //쿼리에스는 속도떄문에 뺴둠.
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[8];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                string sSqlLot = "AND A.LOT_ID IN(";
                string sSqlLot2 = "AND 1=1";
                int iSqlLotCount = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "FROM_DATE";
                dvcArgu[2].sCondition_Value = dtpFromDate.Text.Replace("-", "");

                dvcArgu[3].sCondition_ID = "TO_DATE";
                dvcArgu[3].sCondition_Value = dtpToDate.Text.Replace("-", "");

                dvcArgu[4].sCondition_ID = "INSP_STATUS";
                dvcArgu[4].sCondition_Value = "";

                dvcArgu[5].sCondition_ID = "OPER";
                dvcArgu[5].sCondition_Value = cdvSearchOper.Text + "%";





                //dvcArgu[6].sCondition_ID = "LOT_ID";
                // dvcArgu[6].sCondition_Value = txtLotID.Text + "%";

                dvcArgu[6].sCondition_ID = "SQL_LOT_ID";
                // dvcArgu[6].sCondition_Value = txtLotID.Text + "%";

                sSqlLot = sSqlLot + "'" + txtLotID.Text + "',";

                for (int iRow = 0; iRow < spdSearchLotList.ActiveSheet.RowCount; iRow++)
                {
                    if (spdSearchLotList_Sheet1.Cells[iRow, 1].Text.Replace(" ", "").Length != 0)
                    {
                        sSqlLot = sSqlLot + "'" + spdSearchLotList_Sheet1.Cells[iRow, 1].Value + "',";
                        iSqlLotCount = iSqlLotCount + 1;
                    }
                }

                sSqlLot = sSqlLot + "'')";

                if (iSqlLotCount > 0)
                {
                    dvcArgu[6].sCondition_Value = sSqlLot;
                }
                else
                {
                    dvcArgu[6].sCondition_Value = sSqlLot2;
                }
                dvcArgu[6].sCondition_Type = "TEXT";




                dvcArgu[7].sCondition_ID = "MAT_ID";
                dvcArgu[7].sCondition_Value = "%" + cdvMat.Text + "%";






                // 기존화면에 개선하려다 화면 따로 빼서 다이렉트 쿼리 번호 번호가 화면이랑 안맞음...죄송
                if (TPDR.GetDataOne("", ref dt, "CWIP3024-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInspectionList);
                   // lblTotalCount.Text = "0";
                    return true;
                }

                MPCF.ClearList(spdInspectionList);

               // lblTotalCount.Text = string.Format("{0:#,###}", dt.Rows.Count);

                foreach (DataRow xRow in dt.Rows)
                {
                    i = spdInspectionList_Sheet1.RowCount++;


                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.OPER_DESC].Value = xRow["OPER_DESC"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.LOT_ID].Value = xRow["LOT_ID"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_GRADE].Value = xRow["MAT_GRADE"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.START_TIME].Value = MPCF.MakeDateFormat(xRow["START_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.END_TIME].Value = MPCF.MakeDateFormat(xRow["END_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_ID].Value = xRow["MAT_ID"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_DESC].Value = xRow["MAT_DESC"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.UNIT].Value = xRow["UNIT"];
                    //    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.QTY].Value = xRow["QTY"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.IN_QTY].Value = xRow["IN_QTY"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.OUT_QTY].Value = xRow["OUT_QTY"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.LOSS_QTY].Value = xRow["LOSS_QTY"];
                }

                MPCF.FitColumnHeader(spdInspectionList);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }




        private bool ViewDataList2()
        {

            //INSP관련 정보 혹시 나중에 다시 쓸수도 있어서...일단 컬럼 만들고 히든만 시켜놓음 //쿼리에스는 속도떄문에 뺴둠.
            try
            {


                //--------------------------------------------------------------------------------------
                //검사항목들 HEADER조회
                //--------------------------------------------------------------------------------------
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[8];
                DataTable dt = null;

                //DataTable header_dt;
                int iStColumnCount = 0;
                string sStLotId = "";
                string sStUnitSeq = "";
                int sQcColumn = 0;
                string sSql = "";
                int i = 0;
                string sSqlLot = "AND A.LOT_ID IN(";
                string sSqlLot2 = "AND 1=1";
                int iSqlLotCount = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "FROM_DATE";
                dvcArgu[2].sCondition_Value = dtpFromDate.Text.Replace("-", "");

                dvcArgu[3].sCondition_ID = "TO_DATE";
                dvcArgu[3].sCondition_Value = dtpToDate.Text.Replace("-", "");

                dvcArgu[4].sCondition_ID = "INSP_STATUS";
                dvcArgu[4].sCondition_Value = "";

                dvcArgu[5].sCondition_ID = "OPER";
                dvcArgu[5].sCondition_Value = cdvSearchOper.Text + "%";

                //dvcArgu[6].sCondition_ID = "LOT_ID";
               // dvcArgu[6].sCondition_Value = txtLotID.Text + "%";

                dvcArgu[6].sCondition_ID = "SQL_LOT_ID";
                // dvcArgu[6].sCondition_Value = txtLotID.Text + "%";

                sSqlLot = sSqlLot + "'" + txtLotID.Text + "',";

                for (int iRow = 0; iRow < spdSearchLotList.ActiveSheet.RowCount; iRow++)
                {
                    if (spdSearchLotList_Sheet1.Cells[iRow, 1].Text.Replace(" ", "").Length != 0)
                    {
                        sSqlLot = sSqlLot + "'" + spdSearchLotList_Sheet1.Cells[iRow, 1].Value + "',";
                        iSqlLotCount = iSqlLotCount + 1;
                    }
                }

                sSqlLot = sSqlLot + "'')";

                if(iSqlLotCount >0)
                {
                    dvcArgu[6].sCondition_Value = sSqlLot;
                }
                else
                {
                    dvcArgu[6].sCondition_Value = sSqlLot2;
                }
                dvcArgu[6].sCondition_Type = "TEXT";



                dvcArgu[7].sCondition_ID = "MAT_ID";
                dvcArgu[7].sCondition_Value = "%" + cdvMat.Text + "%";



                if (TPDR.GetDataOne("", ref dt, "CWIP3024-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInspectionList);
                  //  lblTotalCount.Text = "0";
                    return true;
                }

                MPCF.ClearList(spdInspectionList);
                spdInspectionList_Sheet1.ColumnCount = sheet_st_column_count;

                DataTable header_dt = new DataTable();

                header_dt.Columns.Add("CHAR_DESC", typeof(string));
              //  header_dt.Columns.Add("CHAR_ID", typeof(string));
                header_dt.Columns.Add("COL_NUM", typeof(int));
                DataColumn[] dtkey = new DataColumn[1];
                dtkey[0] = header_dt.Columns["CHAR_DESC"];
                header_dt.PrimaryKey = dtkey;



                spdInspectionList_Sheet1.ColumnCount++;
                spdInspectionList_Sheet1.ColumnHeader.Cells.Get(0, spdInspectionList_Sheet1.ColumnCount - 1).Value = "UNIT_SEQ";
                spdInspectionList_Sheet1.Columns[spdInspectionList_Sheet1.ColumnCount - 1].Width = 100;

                for (i = 0; i < dt.Rows.Count; i++)
                {




                    FarPoint.Win.Spread.CellType.NumberCellType numberCellType1 = new FarPoint.Win.Spread.CellType.NumberCellType();
                    numberCellType1.DecimalPlaces = 3;

                    iStColumnCount = spdInspectionList_Sheet1.ColumnCount;

                    if(dt.Rows[i]["COUNT"].ToString() != "")
                    {
                        for (int iCol = 1; iCol <= Int32.Parse(dt.Rows[i]["COUNT"].ToString()); iCol++)
                        {
                            spdInspectionList_Sheet1.ColumnCount++;
                            spdInspectionList_Sheet1.ColumnHeader.Cells.Get(0, iStColumnCount + iCol - 1).Value = dt.Rows[i]["CHAR_DESC"] + "_" + iCol.ToString();

                            spdInspectionList_Sheet1.Columns[iStColumnCount + iCol - 1].Width = 100;
                            spdInspectionList_Sheet1.Columns.Get(iStColumnCount + iCol - 1).CellType = numberCellType1;
  


                            // header_dt.Rows.Add(dt.Rows[i]["CHAR_DESC"] + "_" + iCol.ToString(), dt.Rows[i]["CHAR_ID"] + "_" + iCol.ToString(), spdInspectionList_Sheet1.ColumnCount);
                            header_dt.Rows.Add(dt.Rows[i]["CHAR_DESC"] + "_" + iCol.ToString(), spdInspectionList_Sheet1.ColumnCount-1);
                        }
                    };
                }

                //--------------------------------------------------------------------------------------
                //검사정보 조회
                //--------------------------------------------------------------------------------------

                // 기존화면에 개선하려다 화면 따로 빼서 다이렉트 쿼리 번호 번호가 화면이랑 안맞음...죄송
                if (TPDR.GetDataOne("", ref dt, "CWIP3024-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInspectionList);
                  //  lblTotalCount.Text = "0";
                    return true;
                }

                MPCF.ClearList(spdInspectionList);



                foreach (DataRow xRow in dt.Rows)
                {

                    if (sStLotId == xRow["LOT_ID"].ToString() && sStUnitSeq == xRow["UNIT_SEQ"].ToString())
                    {


                        for (int iCol = 1; iCol <= 25; iCol++)
                        {
                            if (xRow["CHAR_DESC"].ToString() != "" && xRow["VALUE_" + iCol.ToString()].ToString() != " ")
                            {

                                DataRow Dr = header_dt.Rows.Find(xRow["CHAR_DESC"].ToString() + "_" + iCol.ToString());
                                int selRow = header_dt.Rows.IndexOf(Dr);
                                sQcColumn = Int32.Parse(header_dt.Rows[selRow][1].ToString());
                                spdInspectionList_Sheet1.Cells[i, sQcColumn].Value = xRow["VALUE_" + iCol.ToString()];



                            }
                        }

                    }
                    else
                    {
                        i = spdInspectionList_Sheet1.RowCount++;
                        sStLotId = xRow["LOT_ID"].ToString();
                        sStUnitSeq = xRow["UNIT_SEQ"].ToString();
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.OPER_DESC].Value = xRow["OPER_DESC"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.LOT_ID].Value = xRow["LOT_ID"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_GRADE].Value = xRow["MAT_GRADE"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.START_TIME].Value = MPCF.MakeDateFormat(xRow["START_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.END_TIME].Value = MPCF.MakeDateFormat(xRow["END_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_ID].Value = xRow["MAT_ID"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_DESC].Value = xRow["MAT_DESC"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.UNIT].Value = xRow["UNIT"];
                        //    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.QTY].Value = xRow["QTY"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.IN_QTY].Value = xRow["IN_QTY"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.OUT_QTY].Value = xRow["OUT_QTY"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.LOSS_QTY].Value = xRow["LOSS_QTY"];
                        spdInspectionList_Sheet1.Cells[i, 14].Value = xRow["UNIT_SEQ"];

                        for (int iCol = 1; iCol <= 25; iCol++)
                        {
                            if (xRow["CHAR_DESC"].ToString() != "" && xRow["VALUE_" + iCol.ToString()].ToString() != " ")
                            {
           
                                DataRow Dr = header_dt.Rows.Find(xRow["CHAR_DESC"].ToString() + "_" + iCol.ToString());
                                int selRow = header_dt.Rows.IndexOf(Dr);
                                sQcColumn = Int32.Parse(header_dt.Rows[selRow][1].ToString());
                                spdInspectionList_Sheet1.Cells[i, sQcColumn].Value = xRow["VALUE_" + iCol.ToString()];
                            }
                        }

                    }
                    
                }

               // lblTotalCount.Text = string.Format("{0:#,###}", spdInspectionList_Sheet1.Rows.Count);

                MPCF.FitColumnHeader(spdInspectionList);
                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }





        private bool ViewDataList3()
        {

            //INSP관련 정보 혹시 나중에 다시 쓸수도 있어서...일단 컬럼 만들고 히든만 시켜놓음 //쿼리에스는 속도떄문에 뺴둠.
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[8];
                DataTable dt = null;
                string sAddColName = "";
                string sSql = "";
                int i = 0;
                string sSqlLot = "AND A.LOT_ID IN(";
                string sSqlLot2 = "AND 1=1";
                int iSqlLotCount = 0;


                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "FROM_DATE";
                dvcArgu[2].sCondition_Value = dtpFromDate.Text.Replace("-", "");

                dvcArgu[3].sCondition_ID = "TO_DATE";
                dvcArgu[3].sCondition_Value = dtpToDate.Text.Replace("-", "");

                dvcArgu[4].sCondition_ID = "INSP_STATUS";
                dvcArgu[4].sCondition_Value = "";

                dvcArgu[5].sCondition_ID = "OPER";
                dvcArgu[5].sCondition_Value = cdvSearchOper.Text + "%";

                dvcArgu[6].sCondition_ID = "SQL_LOT_ID";
                // dvcArgu[6].sCondition_Value = txtLotID.Text + "%";

                sSqlLot = sSqlLot + "'" + txtLotID.Text + "',";

                for (int iRow = 0; iRow < spdSearchLotList.ActiveSheet.RowCount; iRow++)
                {
                    if (spdSearchLotList_Sheet1.Cells[iRow, 1].Text.Replace(" ", "").Length != 0)
                    {
                        sSqlLot = sSqlLot + "'" + spdSearchLotList_Sheet1.Cells[iRow, 1].Value + "',";
                        iSqlLotCount = iSqlLotCount + 1;
                    }
                }

                sSqlLot = sSqlLot + "'')";

                if (iSqlLotCount > 0)
                {
                    dvcArgu[6].sCondition_Value = sSqlLot;
                }
                else
                {
                    dvcArgu[6].sCondition_Value = sSqlLot2;
                }
                dvcArgu[6].sCondition_Type = "TEXT";


                dvcArgu[7].sCondition_ID = "MAT_ID";
                dvcArgu[7].sCondition_Value = "%"+ cdvMat.Text + "%";

                

                // 기존화면에 개선하려다 화면 따로 빼서 다이렉트 쿼리 번호 번호가 화면이랑 안맞음...죄송
                if (TPDR.GetDataOne("", ref dt, "CWIP3024-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInspectionList);
                 //   lblTotalCount.Text = "0";
                    return true;
                }

                MPCF.ClearList(spdInspectionList);
                spdInspectionList_Sheet1.ColumnCount = sheet_st_column_count;


                //예매해서 COUNT뻄
                //lblTotalCount.Text = string.Format("{0:#,###}", dt.Rows.Count);
                //lblTotalCount.Text = "";


                spdInspectionList_Sheet1.ColumnCount = spdInspectionList_Sheet1.ColumnCount + 32;
                FarPoint.Win.Spread.CellType.NumberCellType numberCellType1 = new FarPoint.Win.Spread.CellType.NumberCellType();
                numberCellType1.DecimalPlaces = 3;
                for (i=0; i<= 31; i++)
                {

                    switch (i)
                    {
                        case 0:

                            if (MPGV.gcLanguage == '2')
                            {
                                sAddColName = "항목코드";
                            }
                            else
                            {
                                sAddColName = "Inspection Code";
                            }
                            break;
                        case 1:
                            sAddColName = "UNIT SEQ";
                            break;
                        case 2:
                            if (MPGV.gcLanguage == '2')
                            {
                                sAddColName = "항목명";
                            }
                            else
                            {
                                sAddColName = "Inspection Desc";
                            }
                            sAddColName = "항목명(Inspection Desc)";
                            break;
                        case 3:
                            sAddColName = "UNIT DESC";
                            break;
                        case 4:
                            if (MPGV.gcLanguage == '2')
                            {
                                sAddColName = "기준";
                            }
                            else
                            {
                                sAddColName = "Target Value";
                            }
                            break;
                        case 5:
                            if (MPGV.gcLanguage == '2')
                            {
                                sAddColName = "상한";
                            }
                            else
                            {
                                sAddColName = "Upper";
                            }
                            break;
                        case 6:
                            if (MPGV.gcLanguage == '2')
                            {
                                sAddColName = "하한";
                            }
                            else
                            {
                                sAddColName = "Lower";
                            }
                            break;
                        default :
                            sAddColName = "Value" +   MPCF.ToDecimal(i-6);
                            break;

                    }
   

                    switch (i)
                    {
                        case 0:
                        case 1:
                        case 2:
                            break;
                        default:
                            spdInspectionList_Sheet1.Columns.Get(sheet_st_column_count + i).CellType = numberCellType1;
                            break;
                    }
                    spdInspectionList_Sheet1.Columns[sheet_st_column_count + i].Width = 100;
                    spdInspectionList_Sheet1.ColumnHeader.Cells.Get(0, sheet_st_column_count + i).Value = sAddColName;



                }

               // spdInspectionList_Sheet1.OperationMode = FarPoint.Win.Spread.OperationMode.SingleSelect;


                foreach (DataRow xRow in dt.Rows)
                {
                    i = spdInspectionList_Sheet1.RowCount++;

                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.OPER_DESC].Value = xRow["OPER_DESC"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.LOT_ID].Value = xRow["LOT_ID"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_GRADE].Value = xRow["MAT_GRADE"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.START_TIME].Value = MPCF.MakeDateFormat(xRow["START_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.END_TIME].Value = MPCF.MakeDateFormat(xRow["END_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_ID].Value = xRow["MAT_ID"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_DESC].Value = xRow["MAT_DESC"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.UNIT].Value = xRow["UNIT"];
                    //    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.QTY].Value = xRow["QTY"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.IN_QTY].Value = xRow["IN_QTY"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.OUT_QTY].Value = xRow["OUT_QTY"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.LOSS_QTY].Value = xRow["LOSS_QTY"];

                    for (int iCol = 11; iCol <= 42; iCol++)
                    {
                        spdInspectionList_Sheet1.Cells[i, iCol].Value = xRow[iCol];
                    }



                }

                MPCF.FitColumnHeader(spdInspectionList);

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }






        private void InitControl()
        {
            try
            {
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnExcel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnReset.Anchor = AnchorStyles.Top | AnchorStyles.Right;


                cdvSearchType.Text = "NON";
                cdvSearchType.DisplayText = "공정 데이터 제외(Not Input Data)";





                sheet_st_column_count = spdInspectionList_Sheet1.ColumnCount;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        /// <summary>
        /// 검사 데이터 조회
        /// </summary>
        /// <param name="inspId">검사ID</param>
        /// <returns></returns>


        private bool viewInspStatusList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';


            in_node.AddString("SQL", "SELECT KEY_1 AS CODE, "
                                                + "   DATA_1 AS VALUE "
                                              + " FROM MGCMTBLDAT "
                                            + " WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                            + "  AND TABLE_NAME = '" + CSGC.CP_GCM_INSP_STATUS + "' "
                                            + "  AND KEY_1 != 'C' "
                                            + " ORDER BY DATA_3");


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

        private void ClearList(string sType)
        {

            /*
            switch (sType)
            {
                case
                "COL_SET_CHANGED":

                    MPCF.ClearList(spdDataCollection);
                    txtColSetVer.Text = "";
                    spdDataCollection.ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;

                    break;
            }
            */

        }





        #endregion

        #region Event


        private void cdvInspectionType_ButtonPress(object sender, EventArgs e)
        {
            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(cdvInspectionType.GetListView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            in_node.AddString("SQL", "SELECT KEY_1 AS CODE, "
                                                  + "         DATA_1 AS VALUE "
                                                  + "   FROM MGCMTBLDAT   "
                                                  + "  WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                                  + "  AND TABLE_NAME = 'C_INSP_TYPE' "
                                                  + "  AND KEY_1 != 'IQC' "
                                                  + "  ORDER BY DATA_2 ");

            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return;
                }

                MPCR.FillDataView(cdvInspectionType.GetListView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);

        }



        private void btnView_Click(object sender, EventArgs e)
        {

            if (MPCF.Trim(cdvDept.Text) == "")
            {
                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                cdvDept.Focus();
                return;
            }




            switch (cdvSearchType.Text)
            {
                case "NON":
                    ViewDataList();
                    break;
                case "COL":
                    if (MPCF.Trim(cdvSearchOper.Text) == "")
                    {
                        //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblnspOper.Text + "]");
                        cdvDept.Focus();
                        return;
                    }
                    ViewDataList2();
                    break;
                case "ROW":
                    if (MPCF.Trim(cdvSearchOper.Text) == "")
                    {
                        //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblnspOper.Text + "]");
                        cdvDept.Focus();
                        return;
                    }
                    ViewDataList3();
                    break;
                default:
                     break;
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

        private bool viewOperList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            /*
            in_node.AddString("SQL", "SELECT OPER AS CODE, "
                                                + "               OPER_DESC AS NAME "
                                                + "         FROM MWIPOPRDEF "
                                                + "        WHERE AREA_ID = '" + cdvDept.Text + "' "
                                                + "          AND SUB_AREA_ID = '" + cdvWorkPlace.Text + "' "
                                                + "          AND OPER_GRP_2 <> 'NONE' "
                                                + "         AND OPER_GRP_2 > ' ' "
                                                + "        ORDER BY OPER"); */


            in_node.AddString("SQL", "SELECT OPER AS CODE, "
                                               + "               OPER_DESC AS NAME "
                                               + "         FROM MWIPOPRDEF "
                                               + "        WHERE AREA_ID = '" + cdvDept.Text + "' "
                                               + "          AND OPER_GRP_1 = 'NO_STORE' "
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

        private void cdpInspOper_ButtonPress(object sender, EventArgs e)
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

                viewOperList(cdvSearchOper.GetListView);

                cdvSearchOper.InsertEmptyRow(0, 1);
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
                spdInspectionList_Sheet1.SheetName = "Sheet1";
                excelSp.Sheets.Add(spdInspectionList_Sheet1);

                //병합된 칼럼 색깔이 안나와서
             /*  for (int i = 0; i < excelSp.Sheets[1].ColumnCount; i++)
                {
                    excelSp.Sheets[1].ColumnHeader.Columns[i].BackColor = Color.FromArgb(14, 86, 155);
                } */

                EXTFUC.SaveExcel(excelSp, "InspectionList");
                
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            cdvOper.Text = "";
            txtLotID.Text = "";

        }

        private void btnClose_Click(object sender, EventArgs e)
        {

        }

        private void cdvSearchType_ButtonPressed(object sender, Miracom.UI.MCCodeViewButtonPressed_EventArgs e)
        {

        }

        private void cdvSearchType_ButtonPress(object sender, EventArgs e)
        {
            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(cdvSearchType.GetListView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            in_node.AddString("SQL", "SELECT 'NON' AS CODE,'측정값제외(Not QC Data)' AS VALUE FROM DUAL UNION ALL "
                                   + "SELECT 'COL' AS CODE,'세로정렬(Data Cols Align)' AS VALUE FROM DUAL UNION ALL "
                                   + "SELECT 'ROW' AS CODE,'가로정렬(Data Rows Align)' AS VALUE FROM DUAL ");

            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return;
                }

                MPCR.FillDataView(cdvSearchType.GetListView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);
        }

        private void cdvMat_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {

        }

        private void lblMat_Click(object sender, EventArgs e)
        {

        }

        private void cdvMat_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;

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

        private void cdvMat_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMat.DisplayText == "")
                cdvMat.Text = "";
        }



        private void btnLotListHidden_MouseMove(object sender, MouseEventArgs e)
        {

            // 현업요청땜시 만들기는 했는데 별로 실용성이 그냥 클릭으로 바꿈20210913 별로 실용성이
            /*
            if (e.Button == MouseButtons.Left)
            {

                if (ix < Convert.ToInt32(e.Location.X))
                {
                    if(tableLayoutPanel1.ColumnStyles[0].Width < 220 && tableLayoutPanel1.ColumnStyles[0].Width >= 0)
                    {
                        tableLayoutPanel1.ColumnStyles[0].Width = tableLayoutPanel1.ColumnStyles[0].Width + 4;//tableLayoutPanel1.ColumnStyles[0].Width + (ix - Convert.ToInt32(e.Location.X));
                    }
                }
                else
                {
                    if (tableLayoutPanel1.ColumnStyles[0].Width > 0)
                    {
                        tableLayoutPanel1.ColumnStyles[0].Width = tableLayoutPanel1.ColumnStyles[0].Width - 4;//tableLayoutPanel1.ColumnStyles[0].Width - (ix + Convert.ToInt32(e.Location.X));
                    }
                }
            }

            ix = Convert.ToInt32(e.Location.X);

            */
        }

        private void btnLotListHidden_MouseClick(object sender, MouseEventArgs e)
        {
            if (tableLayoutPanel1.ColumnStyles[0].Width == 0)
            {
                tableLayoutPanel1.ColumnStyles[0].Width = 220;
            }
            else
            {
                tableLayoutPanel1.ColumnStyles[0].Width = 0;

            }
        }

        private void spdSearchLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column ==1)
                    {
                        CSCF.CheckSpreadCell(spdSearchLotList, 0, 0, true, true);
                    }
                }
                spdSearchLotList.ActiveSheet.Cells[spdSearchLotList.ActiveSheet.RowCount - 1, 0].Value = false;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdSearchLotList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {

        }

        private void spdSearchLotList_Change(object sender, ChangeEventArgs e)
        {
            if (e.Column == 1 && e.Row == spdSearchLotList_Sheet1.RowCount-1)
            { 
                if (spdSearchLotList_Sheet1.Cells[e.Row, 1].ToString() != "")
                {
                    SheetView sv = spdSearchLotList.ActiveSheet;
                    sv.RowCount++;
                }
            }


        }

        private void spdSearchLotList_KeyDown(object sender, KeyEventArgs e)
        {
            try
            {
                SheetView sv = spdSearchLotList.ActiveSheet;

                if (e.Control && e.KeyCode == Keys.V)
                {                    
                    int iActiveRow = sv.ActiveRowIndex;

                    if (iActiveRow < 0)
                        return;

                    //줄바꿈을 자르고 마지막은 빈값이므로 포함안시킴
                    string[] rowSeparators = new string[] { "\r\n" };
                    string sClipboard = Clipboard.GetText();
                    string[] sList = sClipboard.Split(rowSeparators, StringSplitOptions.None);

                    for (int i = 0; i < sList.Length - 1; i++)
                    {
                        if (sv.RowCount > 1000)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(510));//최대 검색개수 1000개를 초과했습니다.
                            return;
                        }
                        else
                        {
                            //이제 열로 구분된 값을 다시 잘라서 각 ROW에 넣어준다.
                            string[] columnSeparators = new string[] { "\t" };
                            string[] sColumnList = sList[i].Split(columnSeparators, StringSplitOptions.None);

                            //체크박스 선택
                            sv.Cells[iActiveRow, 0].Value = true;
                            sv.Cells[iActiveRow, 1].Value = sColumnList[0];

                            iActiveRow++;
                            if ((sv.RowCount - 1) < iActiveRow)
                                sv.RowCount++;
                        }
                    }
                   
                    //sv.RemoveRows(iActiveRow, (sv.RowCount - iActiveRow - 1) == 0 ? 1 : (sv.RowCount - iActiveRow - 1));

                   // if (sv.RowCount - iActiveRow - 1 != 0)
                   // {
                   //     sv.RowCount++;
                   // }


                }                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

            e.Handled = true;
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            MPCF.ClearList(spdInspectionList);
            MPCF.ClearList(spdSearchLotList);
            spdSearchLotList.ActiveSheet.RowCount++;
        }

        #endregion

    }
}
