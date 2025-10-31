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
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CUS_QCM
{
    public partial class frmViewInspectionListMult : CUS_COM.frmViewForm02
    {

        

        public frmViewInspectionListMult()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "
        private enum INSPECTION_LIST
        {
            INSP_ID,
            INSP_TYPE,
            LOT_ID,
            MAT_GRADE,
            MAT_SIZE,
            REQUEST_TIME,
            JUDGE_TIME,
            INSP_STATUS,
            INSP_JUDGE,
            MAT_ID,
            MAT_DESC,
            UNIT,
            QTY,
            VENDOR_LOT_ID
        }

        private enum COLLECTION_DATA
        {
            CHAR_COL,
            CHAR_DESC_COL,
            CHAR_SEQ,
            LOWER_SPEC_LIMIT,
            TARGET_VALUE,
            UPPER_SPEC_LIMIT,
            SPEC_COL,
            OPT_INPUT_COL,
            VALUE_TYPE_COL,
            VALUE_COUNT_COL,
            DEF_UNIT_FLAG_COL,
            DEF_UNIT_OVR_FLAG_COL,
            DEF_VALUE_COL,
            UNIT_TBL_COL,
            VALUE_TBL_COL,
            UNIT_SEQ_COL,
            UNIT_COL,
            VALUE_START_COL
        }

        #endregion

        #region " Variable Definition"
        private const int DEFAULT_COL_COUNT = 17;
        private const int MAX_DATA_COUNT = 5000;
        private int sheet_st_column_count = 0;
        #endregion

        #region " Function Definition"
        private bool ViewInspectionList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[10];
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
                dvcArgu[4].sCondition_Value = cdvStatus.Text + "%";

                dvcArgu[5].sCondition_ID = "INSP_OPER";
                dvcArgu[5].sCondition_Value = cdvInspOper.Text + "%";





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




                dvcArgu[8].sCondition_ID = "DATE_TYPE";
                dvcArgu[8].sCondition_Value = cdvDate.Text;


                dvcArgu[9].sCondition_ID = "MAT_TYPE";
                dvcArgu[9].sCondition_Value = "%" + cdvMatType.Text + "%";



                // 기존화면에 개선하려다 화면 따로 빼서 다이렉트 쿼리 번호 번호가 화면이랑 안맞음...
                if (TPDR.GetDataOne("", ref dt, "CQCM3001-008", dvcArgu, false, false, ref sSql) == false)
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
                    


                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.INSP_ID].Value = xRow["INSP_ID"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.INSP_TYPE].Value = xRow["INSP_TYPE"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.LOT_ID].Value = xRow["LOT_ID"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_GRADE].Value = xRow["MAT_GRADE"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_SIZE].Value = xRow["MAT_SIZE"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.REQUEST_TIME].Value = MPCF.MakeDateFormat(xRow["INSP_REQ_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.JUDGE_TIME].Value = MPCF.MakeDateFormat(xRow["INSP_JUDGE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.INSP_STATUS].Value = xRow["INSP_STATUS"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.INSP_JUDGE].Value = xRow["INSP_JUDGE"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_ID].Value = xRow["MAT_ID"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_DESC].Value = xRow["MAT_DESC"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.UNIT].Value = xRow["UNIT"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.QTY].Value = xRow["QTY"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.VENDOR_LOT_ID].Value = xRow["VENDOR_LOT_ID"];
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
        private bool ViewInspectionList2()
        {
            try
            {


                //--------------------------------------------------------------------------------------
                //검사항목들 HEADER조회
                //--------------------------------------------------------------------------------------
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[10];
                DataTable dt = null;

                //DataTable header_dt;
                int iStColumnCount = 0;
                string sStInspId = "";
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
                dvcArgu[4].sCondition_Value = cdvStatus.Text + "%";

                dvcArgu[5].sCondition_ID = "INSP_OPER";
                dvcArgu[5].sCondition_Value = cdvInspOper.Text + "%";

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



                dvcArgu[8].sCondition_ID = "DATE_TYPE";
                dvcArgu[8].sCondition_Value = cdvDate.Text;


                dvcArgu[9].sCondition_ID = "MAT_TYPE";
                dvcArgu[9].sCondition_Value = "%" + cdvMatType.Text + "%";


                // 기존화면에 개선하려다 화면 따로 빼서 다이렉트 쿼리 번호 번호가 화면이랑 안맞음...
                if (TPDR.GetDataOne("", ref dt, "CQCM3001-005", dvcArgu, false, false, ref sSql) == false)
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



                // 기존화면에 개선하려다 화면 따로 빼서 다이렉트 쿼리 번호 번호가 화면이랑 안맞음...
                if (TPDR.GetDataOne("", ref dt, "CQCM3001-006", dvcArgu, false, false, ref sSql) == false)
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

                    if (sStInspId == xRow["INSP_ID"].ToString()  && sStLotId == xRow["LOT_ID"].ToString() && sStUnitSeq == xRow["UNIT_SEQ"].ToString())
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
                        sStInspId = xRow["INSP_ID"].ToString();
                        sStLotId = xRow["LOT_ID"].ToString();
                        sStUnitSeq = xRow["UNIT_SEQ"].ToString();

                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.INSP_ID].Value = xRow["INSP_ID"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.INSP_TYPE].Value = xRow["INSP_TYPE"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.LOT_ID].Value = xRow["LOT_ID"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_GRADE].Value = xRow["MAT_GRADE"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_SIZE].Value = xRow["MAT_SIZE"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.REQUEST_TIME].Value = MPCF.MakeDateFormat(xRow["INSP_REQ_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.JUDGE_TIME].Value = MPCF.MakeDateFormat(xRow["INSP_JUDGE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.INSP_STATUS].Value = xRow["INSP_STATUS"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.INSP_JUDGE].Value = xRow["INSP_JUDGE"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_ID].Value = xRow["MAT_ID"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_DESC].Value = xRow["MAT_DESC"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.UNIT].Value = xRow["UNIT"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.QTY].Value = xRow["QTY"];
                        spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.VENDOR_LOT_ID].Value = xRow["VENDOR_LOT_ID"];
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
        private bool ViewInspectionList3()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[10];
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
                dvcArgu[4].sCondition_Value = cdvStatus.Text + "%";

                dvcArgu[5].sCondition_ID = "INSP_OPER";
                dvcArgu[5].sCondition_Value = cdvInspOper.Text + "%";

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


                dvcArgu[8].sCondition_ID = "DATE_TYPE";
                dvcArgu[8].sCondition_Value = cdvDate.Text;




                dvcArgu[9].sCondition_ID = "MAT_TYPE";
                dvcArgu[9].sCondition_Value = "%" + cdvMatType.Text + "%";


                // 기존화면에 개선하려다 화면 따로 빼서 다이렉트 쿼리 번호 번호가 화면이랑 안맞음...
                if (TPDR.GetDataOne("", ref dt, "CQCM3001-007", dvcArgu, false, false, ref sSql) == false)
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

                //13번이후 추가컬럼
                spdInspectionList_Sheet1.ColumnCount = spdInspectionList_Sheet1.ColumnCount + 32;
                FarPoint.Win.Spread.CellType.NumberCellType numberCellType1 = new FarPoint.Win.Spread.CellType.NumberCellType();
                numberCellType1.DecimalPlaces = 3;
                for (i=14; i<= 45; i++)
                {
                    //어쩌다보니 귀찮...HEADER명 하드코딩..^^;;혹 수정하시는 분께 
                    switch (i)
                    {
                        case 14:

                            if (MPGV.gcLanguage == '2')
                            {
                                sAddColName = "항목코드";
                            }
                            else
                            {
                                sAddColName = "Inspection Code";
                            }
                            break;
                        case 15:
                            sAddColName = "UNIT SEQ";
                            break;
                        case 16:
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
                        case 17:
                            sAddColName = "UNIT DESC";
                            break;
                        case 18:
                            if (MPGV.gcLanguage == '2')
                            {
                                sAddColName = "기준";
                            }
                            else
                            {
                                sAddColName = "Target Value";
                            }
                            break;
                        case 19:
                            if (MPGV.gcLanguage == '2')
                            {
                                sAddColName = "상한";
                            }
                            else
                            {
                                sAddColName = "Upper";
                            }
                            break;
                        case 20:
                            if (MPGV.gcLanguage == '2')
                            {
                                sAddColName = "하한";
                            }
                            else
                            {
                                sAddColName = "Lower";
                            }
                            break;
                        case 21:
                            sAddColName = "Value01";
                            break;
                        case 22:
                            sAddColName = "Value02";
                            break;
                        case 23:
                            sAddColName = "Value03";
                            break;
                        case 24:
                            sAddColName = "Value04";
                            break;
                        case 25:
                            sAddColName = "Value05";
                            break;
                        case 26:
                            sAddColName = "Value06";
                            break;
                        case 27:
                            sAddColName = "Value07";
                            break;
                        case 28:
                            sAddColName = "Value08";
                            break;
                        case 29:
                            sAddColName = "Value09";
                            break;

                        case 30:
                            sAddColName = "Value10";
                            break;

                        case 31:
                            sAddColName = "Value11";
                            break;

                        case 32:
                            sAddColName = "Value12";
                            break;

                        case 33:
                            sAddColName = "Value13";
                            break;

                        case 34:
                            sAddColName = "Value14";
                            break;

                        case 35:
                            sAddColName = "Value15";
                            break;

                        case 36:
                            sAddColName = "Value16";
                            break;

                        case 37:
                            sAddColName = "Value17";
                            break;

                        case 38:
                            sAddColName = "Value18";
                            break;

                        case 39:
                            sAddColName = "Value19";
                            break;

                        case 40:
                            sAddColName = "Value20";
                            break;

                        case 41:
                            sAddColName = "Value21";
                            break;

                        case 42:
                            sAddColName = "Value22";
                            break;

                        case 43:
                            sAddColName = "Value23";
                            break;
                        case 44:
                            sAddColName = "Value24";
                            break;
                        case 45:
                            sAddColName = "Value25";
                            break;

                    }

                    switch (i)
                    {
                        case 14:
                        case 16:
                        case 17:
                            break;
                        default:
                            spdInspectionList_Sheet1.Columns.Get(i).CellType = numberCellType1;
                            break;
                    }
                    spdInspectionList_Sheet1.Columns[i].Width = 100;
                    spdInspectionList_Sheet1.ColumnHeader.Cells.Get(0, i).Value = sAddColName;


                }

               // spdInspectionList_Sheet1.OperationMode = FarPoint.Win.Spread.OperationMode.SingleSelect;


                foreach (DataRow xRow in dt.Rows)
                {
                    i = spdInspectionList_Sheet1.RowCount++;
                    

                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.INSP_ID].Value = xRow["INSP_ID"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.INSP_TYPE].Value = xRow["INSP_TYPE"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.LOT_ID].Value = xRow["LOT_ID"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_GRADE].Value = xRow["MAT_GRADE"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_SIZE].Value = xRow["MAT_SIZE"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.REQUEST_TIME].Value = MPCF.MakeDateFormat(xRow["INSP_REQ_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.JUDGE_TIME].Value = MPCF.MakeDateFormat(xRow["INSP_JUDGE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.INSP_STATUS].Value = xRow["INSP_STATUS"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.INSP_JUDGE].Value = xRow["INSP_JUDGE"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_ID].Value = xRow["MAT_ID"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.MAT_DESC].Value = xRow["MAT_DESC"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.UNIT].Value = xRow["UNIT"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.QTY].Value = xRow["QTY"];
                    spdInspectionList_Sheet1.Cells[i, (int)INSPECTION_LIST.VENDOR_LOT_ID].Value = xRow["VENDOR_LOT_ID"];

                    for (int iCol = 14; iCol <= 45; iCol++)
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
                btnFileManager.Anchor = AnchorStyles.Top | AnchorStyles.Right;


                cdvSearchType.Text = "NON";
                cdvSearchType.DisplayText = "측정값제외(Not QC Data)";
                cdvStatus.Text = "S";
                cdvStatus.DisplayText = "완료";

                cdvDate.Text = "REQ";
                cdvDate.DisplayText = "요청일자(Request Date)";



                sheet_st_column_count = spdInspectionList_Sheet1.ColumnCount;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
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

        #endregion

        #region " Event Definition"

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

            if (MPCF.Trim(cdvInspOper.Text) == "")
            {
                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblnspOper.Text + "]");
                cdvDept.Focus();
                return;
            }


            switch (cdvSearchType.Text)
            {
                case "NON":
                    ViewInspectionList();
                    break;
                case "COL":
                    ViewInspectionList2();
                    break;
                case "ROW":
                    ViewInspectionList3();
                    break;
                default:
                    break;
            }


        }
        private void cdvStatus_ButtonPress(object sender, EventArgs e)
        {
            viewInspStatusList(cdvStatus.GetListView);
            cdvStatus.InsertEmptyRow(0, 1);
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
                                               + "          AND OPER_GRP_2 <> 'NONE' "
                                               + "         AND OPER_GRP_2 > ' ' "
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

                viewOperList(cdvInspOper.GetListView);

                cdvInspOper.InsertEmptyRow(0, 1);
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
                    if (e.Column == 1)
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
            if (e.Column == 1 && e.Row == spdSearchLotList_Sheet1.RowCount - 1)
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
        private void cdvDate_ButtonPress(object sender, EventArgs e)
        {
            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(cdvDate.GetListView);




            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            in_node.AddString("SQL", "SELECT 'REQ' AS CODE,'요청일자(Request Date)' AS VALUE FROM DUAL UNION ALL "
                                   + "SELECT 'DEC' AS CODE,'판정일자(Decision Date)' AS VALUE FROM DUAL");


            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return;
                }

                MPCR.FillDataView(cdvDate.GetListView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);
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
        private void btnFileManager_Click(object sender, EventArgs e)
        {
            if (spdInspectionList.ActiveSheet.RowCount != 0)
            {



                frmPopFtpUpDown popup = new frmPopFtpUpDown();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.g_PopYn = "Y";
                popup.g_LotId = spdInspectionList.ActiveSheet.Cells[spdInspectionList.ActiveSheet.ActiveRowIndex, (int)INSPECTION_LIST.LOT_ID].Text;
                popup.g_Mat_id = spdInspectionList.ActiveSheet.Cells[spdInspectionList.ActiveSheet.ActiveRowIndex, (int)INSPECTION_LIST.MAT_ID].Text;
                popup.g_Mat_Desc = spdInspectionList.ActiveSheet.Cells[spdInspectionList.ActiveSheet.ActiveRowIndex, (int)INSPECTION_LIST.MAT_DESC].Text;
                popup.g_Area_Id = cdvDept.Text;
                popup.g_SearchType = "B";





                if (popup.ShowDialog() == DialogResult.OK)
                {

                    popup = null;
                }
                else
                {
                    return;
                }


            }
        }
        #endregion


    }
}
