using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Data.OleDb;


namespace RPTServer
{
    public partial class RPTServerTran
    {
        private const int MAX_DATATABLE_ROW_COUNT = 10000;

        public static int RPT_SQL_Query_DataTable_Result(RPT_SQL_Query_In_Tag _In
                                                    , ref RPT_SQL_Query_DataTable_Result_Out_Tag _Out)
        {
            bool bRet = false;

            try
            {
                // Begin Transaction
                if (DBCF.BeginTransaction() == false)
                {
                    _Out.h_status_value = RSGC.MP_FAIL_C;
                    _Out.h_msg = DBGV.gsDBError;
                    return RSGC.MP_FAIL;
                }

                bRet = RPT_SQL_Query_DataTable_Result_Main(_In, ref _Out);

                if (bRet == false || _Out.h_status_value == RSGC.MP_FAIL_C)
                {
#if _OLE
                    DBGV.OleTran.Rollback();
#elif _ORACLE
                    DBGV.OraTran.Rollback();
#elif _SQL
                    DBGV.SqlTran.Rollback();
#endif
                }
                else
                {
#if _OLE
                    DBGV.OleTran.Commit();
#elif _ORACLE
                    DBGV.OraTran.Commit();
#elif _SQL
                    DBGV.SqlTran.Commit();
#endif
                }
            }
            catch (Exception ex)
            {
                //Modify by J.S. 2015.11.19 Exception안에서 Rollback시 다시 Exception이 발생하여
                //서버가 멈춤, DB가 재접속되게 설정
                //DBGV.OleTran.Rollback();
                DBGV.gbDBConnected = false;

                _Out.h_status_value = RSGC.MP_FAIL_C;
                _Out.h_msg = ex.Message;
                return RSGC.MP_FAIL;
            }
            return RSGC.MP_SUCCESS;
        }

        public static bool RPT_SQL_Query_DataTable_Result_Main(RPT_SQL_Query_In_Tag _In
                                                    , ref RPT_SQL_Query_DataTable_Result_Out_Tag _Out)
        {
            string sQueryStatement = string.Empty;

            DataTable adoDataTable = null;
            DataTable dt = null;

            bool b_SelectQuery = true;

            int i_data_cnt = 0;
            int i_row_cnt = 0;

            string s_Pre = string.Empty; ;

            try
            {
                LOG.AddLog(_In.sql);

                _Out.h_status_value = RSGC.MP_FAIL_C;
                _Out.col_count = 0;
                _Out.row_count = 0;
                _Out._size_data_tbl = 0;

                sQueryStatement =  RSCF.Trim(_In.sql);

                if (string.IsNullOrEmpty(sQueryStatement))
                {
                    _Out.h_status_value = RSGC.MP_FAIL_C;
                    _Out.h_msg = "QueryStatement = Empty";
                    return false;
                }

                s_Pre = sQueryStatement.Substring(0, 6).ToUpper();
                
                if (s_Pre == "UPDATE" || s_Pre == "INSERT" || s_Pre == "DELETE")
                {
                    b_SelectQuery = false;
                }

                if (b_SelectQuery == false)
                {
                    if (DBCF.DB_ExecuteNonQuery(_In.sql) == false)
                    {
                        _Out.h_db_err_msg = DBGV.gsDBError;
                        if (sQueryStatement.Length > 50)
                        {
                            _Out.h_field_msg = "SQL = " + sQueryStatement.Substring(0, 50);
                        }
                        else
                        {
                            _Out.h_field_msg = "SQL = " + sQueryStatement;
                        }
                        _Out.h_msg = DBGV.gsDBError;
                        return false;
                    }
                }
                else
                {
                    dt = new DataTable();
                    int i = 0;

                    if (DBCF.DB_FillDataDT(ref _In.sql, ref dt) == false)
                    {
                        _Out.h_db_err_msg = DBGV.gsDBError;
                        if (sQueryStatement.Length > 50)
                        {
                            _Out.h_field_msg = "SQL = " + sQueryStatement.Substring(0, 50);
                        }
                        else
                        {
                            _Out.h_field_msg = "SQL = " + sQueryStatement;
                        }
                        _Out.h_msg = DBGV.gsDBError;
                        return false;
                    }

                    //if (DB_GlobalVariable.gErrors.SqlCode == SQL_CODE.SQL_SUCCESS)
                    ////&& dt.Rows.Count > 0)
                    //{
                        byte[] BinaryData = null;
                        byte[] BinaryDataZip = null;
                        int i_max_data_cnt = RSCF.ToInt(_In.data_1);

                        // 기본 1만건이지만 Client에서 data_1에 MaxCount를 올려 주면
                        // data_1의 숫자를 Max Count로 한다.
                        if (i_max_data_cnt <= 0)
                        {
                            i_max_data_cnt = MAX_DATATABLE_ROW_COUNT;
                        }

                        if (dt.Rows.Count > i_max_data_cnt || _In.next_row > 0)
                        {
                            // Select된 데이터가 max count를 넘어가면
                            // 새로운 데이터 테이블에 Max count만큼 데이터를 넣어 내려보낸다.
                            adoDataTable = new DataTable();

                            i_row_cnt = dt.Rows.Count;
                            i_row_cnt = i_row_cnt - _In.next_row;

                            i_data_cnt = _In.next_row;

                            if (i_row_cnt > i_max_data_cnt)
                            {
                                _Out.next_row = _In.next_row + i_max_data_cnt;
                                i_row_cnt = i_max_data_cnt;
                            }

                            foreach (DataColumn dc in dt.Columns)
                            {
                                adoDataTable.Columns.Add(dc.ColumnName, dc.DataType);
                            }
                            for (i = 0; i < i_row_cnt; i++)
                            {
                                adoDataTable.Rows.Add(dt.Rows[i_data_cnt].ItemArray);
                                i_data_cnt++;
                            }

                            dt.Dispose();
                            dt = null;

                            _Out.col_count = adoDataTable.Columns.Count;
                            _Out.row_count = adoDataTable.Rows.Count;

                            //DataTable을 Binary로 변환
                            BinaryData = RSCF.serializeToBinary(adoDataTable);
                            if (BinaryData == null)
                            {
                                _Out.h_db_err_msg = DBGV.gsDBError;
                                if (sQueryStatement.Length > 50)
                                {
                                    _Out.h_field_msg = "SQL = " + sQueryStatement.Substring(0, 50);
                                }
                                else
                                {
                                    _Out.h_field_msg = "SQL = " + sQueryStatement;
                                }
                                _Out.h_msg = DBGV.gsDBError;
                                return false;
                            }

                            //압축 해제 후 GZipStream에서 데이터를 읽기 위해 압축되기 전의 Binary Data길이를 저장                        
                            _Out.binary_length = BinaryData.Length;

                            //Binary로 변환된 DataTable을 압축
                            RSCF.DataCompress(BinaryData, ref BinaryDataZip);

                            _Out.data_tbl = new RPT_SQL_Query_DataTable_Result_Out_Tag_data_tbl[BinaryDataZip.Length];

                            i_data_cnt = 0;
                            foreach (int iData in BinaryDataZip)
                            {
                                _Out.data_tbl[i_data_cnt] = new RPT_SQL_Query_DataTable_Result_Out_Tag_data_tbl();
                                _Out.data_tbl[i_data_cnt].data = iData;

                                i_data_cnt++;
                            }
                            _Out.data_count = i_data_cnt;
                            _Out._size_data_tbl = i_data_cnt;
                        }
                        else
                        {
                            _Out.col_count = dt.Columns.Count;
                            _Out.row_count = dt.Rows.Count;

                            //DataTable을 Binary로 변환
                            BinaryData = RSCF.serializeToBinary(dt);
                            if (BinaryData == null)
                            {
                                _Out.h_db_err_msg = DBGV.gsDBError;
                                _Out.h_field_msg = "Row Count = " + dt.Rows.Count.ToString();
                                _Out.h_msg = DBGV.gsDBError;
                                return false;
                            }

                            //압축 해제 후 GZipStream에서 데이터를 읽기 위해 압축되기 전의 Binary Data길이를 저장                        
                            _Out.binary_length = BinaryData.Length;

                            //Binary로 변환된 DataTable을 압축
                            RSCF.DataCompress(BinaryData, ref BinaryDataZip);

                            _Out.data_tbl = new RPT_SQL_Query_DataTable_Result_Out_Tag_data_tbl[BinaryDataZip.Length];
                            
                            i_data_cnt = 0;
                            foreach (int iData in BinaryDataZip)
                            {
                                _Out.data_tbl[i_data_cnt] = new RPT_SQL_Query_DataTable_Result_Out_Tag_data_tbl();
                                _Out.data_tbl[i_data_cnt].data = iData;

                                i_data_cnt++;
                            }
                            _Out.data_count = i_data_cnt;
                            _Out._size_data_tbl = i_data_cnt;
                        }

                    //}//if (DB_GlobalVariable.gErrors.SqlCode == SQL_CODE.SQL_SUCCESS)

                }//if (b_SelectQuery == false)

                _Out.h_status_value = RSGC.MP_SUCCESS_C;

            }
            catch (Exception ex)
            {
                _Out.h_status_value = RSGC.MP_FAIL_C;
                _Out.h_msg = ex.Message;
                return false;
            }
            return true;
        }
        public static int RPT_View_Dynamic(RPT_SQL_Query_In_Tag _In
                                                    , ref RPT_SQL_Query_DataTable_Result_Out_Tag _Out)
        {
            bool bRet = false;

            try
            {
                // Begin Transaction
                if (DBCF.BeginTransaction() == false)
                {
                    _Out.h_status_value = RSGC.MP_FAIL_C;
                    _Out.h_msg = DBGV.gsDBError;
                    return RSGC.MP_FAIL;
                }

                bRet = RPT_View_Dynamic_Main(_In, ref _Out);

                if (bRet == false || _Out.h_status_value == RSGC.MP_FAIL_C)
                {
#if _OLE
                    DBGV.OleTran.Rollback();
#elif _ORACLE
                    DBGV.OraTran.Rollback();
#elif _SQL
                    DBGV.SqlTran.Rollback();
#endif
                }
                else
                {
#if _OLE
                    DBGV.OleTran.Commit();
#elif _ORACLE
                    DBGV.OraTran.Commit();
#elif _SQL
                    DBGV.SqlTran.Commit();
#endif
                }
            }
            catch (Exception ex)
            {
                //Modify by J.S. 2015.11.19 Exception안에서 Rollback시 다시 Exception이 발생하여
                //서버가 멈춤
                //DBGV.OleTran.Rollback();
                DBGV.gbDBConnected = false;
                
                _Out.h_status_value = RSGC.MP_FAIL_C;
                _Out.h_msg = ex.Message;
                return RSGC.MP_FAIL;
            }
            return RSGC.MP_SUCCESS;
        }

        public static bool RPT_View_Dynamic_Main(RPT_SQL_Query_In_Tag _In
                                                    , ref RPT_SQL_Query_DataTable_Result_Out_Tag _Out)
        {
            string sQueryStatement = string.Empty;

            string s_sql;
            bool bUserHeader = false;
            int i;
            //int iBGIndex;
            //int iFirstIndex;
            //float icolwidth;
            string s_column = "";
            //string s_replace = "";

            DataTable adoDataTable = null;
            DataTable dt = null;
            //MDNMSQLDEF FLAG조회
            DataTable dnmSqlDefDt = null;
            char iconFlag;
            char bgcolorFlag;

            //bool b_SelectQuery = true;

            int i_data_cnt = 0;
            int i_row_cnt = 0;

            string s_Pre = string.Empty;

            try
            {
                LOG.AddLog(_In.sql);

                _Out.h_status_value = RSGC.MP_FAIL_C;
                _Out.col_count = 0;
                _Out.row_count = 0;
                _Out._size_data_tbl = 0;

                sQueryStatement = RSCF.Trim(_In.sql);


                dt = new DataTable();
                i = 0;

                //MDNMSQLDEF FLAG조회-----------------------------------------------------------
                iconFlag = _In.icon_flag;
                bgcolorFlag = _In.bgcolor_flag;

                dnmSqlDefDt = new DataTable();
                s_sql = "";
                s_sql = "SELECT USE_ICON_FLAG, USE_BGCOLOR_FLAG FROM MDNMSQLDEF";
                s_sql = s_sql + " WHERE 1=1";
                s_sql = s_sql + " AND VIEW_ID = :VIEW_ID";

                RPT_SQL_Query_In_Tag_cond_tbl param = new RPT_SQL_Query_In_Tag_cond_tbl();
                param.cond_id = "VIEW_ID";
                param.cond_type = "STRING";
                param.cond = _In.view_id;

                List<RPT_SQL_Query_In_Tag_cond_tbl> param_list = new List<RPT_SQL_Query_In_Tag_cond_tbl>();
                param_list.Add(param);

                _Out.s_sql_data = s_sql;

                RSGV.parameter_tbl = param_list.ToArray();

                if (DBCF.DB_FillDataDT(ref s_sql, ref dnmSqlDefDt) == false)
                {
                    LOG.AddLog(s_sql);
                    _Out.h_db_err_msg = DBGV.gsDBError;
                    if (sQueryStatement.Length > 50)
                    {
                        _Out.h_field_msg = "DNM : SQL = " + sQueryStatement.Substring(0, 50);
                    }
                    else
                    {
                        _Out.h_field_msg = "DNM : SQL = " + sQueryStatement;
                    }
                    _Out.h_msg = DBGV.gsDBError;
                    return false;
                }
                if (dnmSqlDefDt.Rows.Count <= 0)
                {
                    _Out.h_msg = "DNM : Dynamic View ID : [" + _In.view_id + "] is not exist";
                    return false;
                }
                iconFlag = Convert.ToChar(dnmSqlDefDt.Rows[0].ItemArray[0]);
                bgcolorFlag = Convert.ToChar(dnmSqlDefDt.Rows[0].ItemArray[1]);


                //------------------------------------------------------------------------------------------------
                //Get Global Option
                s_sql = "SELECT VALUE_1 FROM MBASGLBDEF WHERE FACTORY= :FACTORY AND OPTION_NAME='UseUserHeaderForDirectView'";
                param = new RPT_SQL_Query_In_Tag_cond_tbl();
                param.cond_id = "FACTORY";
                param.cond_type = "STRING";
                param.cond = _In.h_factory;

                param_list.RemoveRange(0, param_list.Count);
                param_list = new List<RPT_SQL_Query_In_Tag_cond_tbl>();
                param_list.Add(param);
                RSGV.parameter_tbl = param_list.ToArray();

                _Out.s_sql_data = s_sql;

                if (DBCF.DB_FillDataDT(ref s_sql, ref dt) == false)
                {
                    LOG.AddLog(s_sql);
                    _Out.h_db_err_msg = DBGV.gsDBError;
                    if (sQueryStatement.Length > 50)
                    {
                        _Out.h_field_msg = "DNM : SQL = " + sQueryStatement.Substring(0, 50);
                    }
                    else
                    {
                        _Out.h_field_msg = "DNM : SQL = " + sQueryStatement;
                    }
                    _Out.h_msg = DBGV.gsDBError;
                    return false;
                }

                if (dt.Rows.Count > 0)
                {
                    if (dt.Rows[0].ItemArray[0].ToString() != "Y")
                    {
                        _In.user_id = "ADMIN";
                    }
                }
                else
                    _In.user_id = "ADMIN";
                //------------------------------------------------------------------------
                s_sql = "";
                s_sql = "SELECT COUNT(*) FROM MDNMDVWHDR WHERE VIEW_ID = :VIEW_ID";
                param = new RPT_SQL_Query_In_Tag_cond_tbl();
                param.cond_id = "VIEW_ID";
                param.cond_type = "STRING";
                param.cond = _In.view_id;

                param_list.RemoveRange(0, param_list.Count);
                param_list = new List<RPT_SQL_Query_In_Tag_cond_tbl>();
                param_list.Add(param);

                RSGV.parameter_tbl = param_list.ToArray();

                _Out.s_sql_data = s_sql;
                if (DBCF.DB_FillDataDT(ref s_sql, ref dt) == false)
                {
                    LOG.AddLog(s_sql);
                    _Out.h_db_err_msg = DBGV.gsDBError;
                    if (sQueryStatement.Length > 50)
                    {
                        _Out.h_field_msg = "DNM : SQL = " + sQueryStatement.Substring(0, 50);
                    }
                    else
                    {
                        _Out.h_field_msg = "DNM : SQL = " + sQueryStatement;
                    }
                    _Out.h_msg = DBGV.gsDBError;
                    return false;
                }

                if (dt.Rows[0].ItemArray[0].ToString() == "0")
                {
                    //s_sql = "SELECT SQL_1, SQL_2, SQL_3, SQL_4, SQL_5, SQL_6, SQL_7, SQL_8, SQL_9, SQL_10, SQL_TEXT FROM ";
                    s_sql = "SELECT SQL_TEXT FROM ";
                    s_sql = s_sql + "MDNMSQLDEF WHERE VIEW_ID = :VIEW_ID";

                    param = new RPT_SQL_Query_In_Tag_cond_tbl();
                    param.cond_id = "VIEW_ID";
                    param.cond_type = "STRING";
                    param.cond = _In.view_id;

                    param_list.RemoveRange(0, param_list.Count);
                    param_list = new List<RPT_SQL_Query_In_Tag_cond_tbl>();
                    param_list.Add(param);

                    RSGV.parameter_tbl = param_list.ToArray();

                    _Out.s_sql_data = s_sql;
                    if (DBCF.DB_FillDataDT(ref s_sql, ref dt) == false)
                    {
                        LOG.AddLog(s_sql);
                        _Out.h_db_err_msg = DBGV.gsDBError;
                        if (sQueryStatement.Length > 50)
                        {
                            _Out.h_field_msg = "DNM : SQL = " + sQueryStatement.Substring(0, 50);
                        }
                        else
                        {
                            _Out.h_field_msg = "DNM : SQL = " + sQueryStatement;
                        }
                        _Out.h_msg = DBGV.gsDBError;
                        return false;
                    }

                    s_sql = "";
                    //s_sql = s_sql + dt.Rows[0].ItemArray[0].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[1].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[2].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[3].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[4].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[5].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[6].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[7].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[8].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[9].ToString();

                    s_sql = dt.Rows[0]["SQL_TEXT"].ToString();
                    RSGV.parameter_tbl = _In.cond_tbl;

                }
                else
                {
                    //------------------------------------------------------------
                    s_sql = "";
                    s_sql = "SELECT W.VIEW_ID,W.COL_NAME, DECODE(W.DISPLAY_NAME,' ', W.COL_NAME, W.DISPLAY_NAME), W.COL_DESC, TO_CHAR(NVL(U.COL_SEQ,99999)), ";
                    //s_sql = s_sql + " V.SQL_1, V.SQL_2, V.SQL_3, V.SQL_4, V.SQL_5, V.SQL_6, V.SQL_7, V.SQL_8, V.SQL_9, V.SQL_10, V.SQL_TEXT ";
                    s_sql = s_sql + " V.SQL_TEXT ";
                    s_sql = s_sql + " FROM MDNMDVWHDR W, MDNMDVUHDR U, MDNMSQLDEF V ";
                    s_sql = s_sql + " WHERE 1=1 ";
                    s_sql = s_sql + " AND W.VIEW_ID=U.VIEW_ID(+) ";
                    s_sql = s_sql + " AND W.COL_NAME = U.COL_NAME(+) ";
                    s_sql = s_sql + " AND W.VIEW_ID=    :VIEW_ID";
                    s_sql = s_sql + " AND U.VIEW_ID(+)= :VIEW_ID";
                    s_sql = s_sql + " AND U.FACTORY(+)= :FACTORY";
                    s_sql = s_sql + " AND U.USER_ID(+)= :USER_ID";
                    s_sql = s_sql + " AND V.VIEW_ID=    :VIEW_ID";
                    s_sql = s_sql + " ORDER BY U.COL_SEQ ";

                    param = new RPT_SQL_Query_In_Tag_cond_tbl();
                    param.cond_id = "VIEW_ID";
                    param.cond_type = "STRING";
                    param.cond = _In.view_id;

                    param_list.RemoveRange(0, param_list.Count);
                    param_list = new List<RPT_SQL_Query_In_Tag_cond_tbl>();
                    param_list.Add(param);

                    param = new RPT_SQL_Query_In_Tag_cond_tbl();
                    param.cond_id = "FACTORY";
                    param.cond_type = "STRING";
                    param.cond = _In.h_factory;

                    param_list.Add(param);

                    param = new RPT_SQL_Query_In_Tag_cond_tbl();
                    param.cond_id = "USER_ID";
                    param.cond_type = "STRING";
                    param.cond = _In.user_id;

                    param_list.Add(param);

                    param = new RPT_SQL_Query_In_Tag_cond_tbl();
                    param.cond_id = "VIEW_ID";
                    param.cond_type = "STRING";
                    param.cond = _In.view_id;

                    param_list.Add(param);

                    RSGV.parameter_tbl = param_list.ToArray();

                    _Out.s_sql_data = s_sql;

                    if (DBCF.DB_FillDataDT(ref s_sql, ref dt) == false)
                    {
                        LOG.AddLog(s_sql);
                        _Out.h_db_err_msg = DBGV.gsDBError;
                        if (sQueryStatement.Length > 50)
                        {
                            _Out.h_field_msg = "DNM : SQL = " + sQueryStatement.Substring(0, 50);
                        }
                        else
                        {
                            _Out.h_field_msg = "DNM : SQL = " + sQueryStatement;
                        }
                        _Out.h_msg = DBGV.gsDBError;
                        return false;
                    }

                    if (dt.Rows[0].ItemArray[4].ToString() != "99999")
                        bUserHeader = true;
                    else
                        bUserHeader = false;
                    s_column = "SELECT";
                    for (i = 0; i < dt.Rows.Count; i++)
                    {
                        if (bUserHeader == true && dt.Rows[i].ItemArray[4].ToString() == "99999")
                            continue;

                        //if (i == 0 && iconFlag == 'N')
                        //    continue;

                        //if (i == 1 && bgcolorFlag == 'N')
                        //    continue;

                        s_column = s_column + " " + dt.Rows[i].ItemArray[1].ToString() + " ";
                        s_column = s_column + "\"" + dt.Rows[i].ItemArray[2].ToString() + "\",";
                    }

                    s_column = s_column.Substring(0, s_column.Length - 1);
                    s_column = s_column + " FROM ( ";


                    s_sql = "";
                    //s_sql = s_sql + dt.Rows[0].ItemArray[5].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[6].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[7].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[8].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[9].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[10].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[11].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[12].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[13].ToString();
                    //s_sql = s_sql + dt.Rows[0].ItemArray[14].ToString();

                    s_sql = dt.Rows[0]["SQL_TEXT"].ToString();

                    RSGV.parameter_tbl = _In.cond_tbl;

                    s_column = s_column + s_sql;
                    s_column = s_column + " )";

                    s_sql = s_column;

                    //------------------------------------------------------------
                }


                _Out.s_sql_data = s_sql;
                if (DBCF.DB_FillDataDT(ref s_sql, ref dt) == false)
                {
                    _Out.h_db_err_msg = DBGV.gsDBError;
                    if (sQueryStatement.Length > 50)
                    {
                        _Out.h_field_msg = "DNM : SQL = " + sQueryStatement.Substring(0, 50);
                    }
                    else
                    {
                        _Out.h_field_msg = "DNM : SQL = " + sQueryStatement;
                    }

                    _Out.h_msg = DBGV.gsDBError;
                    LOG.AddLog(s_sql);
                    return false;
                }

                _Out.s_sql_data = s_sql;

                //if (DB_GlobalVariable.gErrors.SqlCode == SQL_CODE.SQL_SUCCESS)
                ////&& dt.Rows.Count > 0)
                //{
                byte[] BinaryData = null;
                byte[] BinaryDataZip = null;
                int i_max_data_cnt = RSCF.ToInt(_In.data_1);

                // 기본 1만건이지만 Client에서 data_1에 MaxCount를 올려 주면
                // data_1의 숫자를 Max Count로 한다.
                if (i_max_data_cnt <= 0)
                {
                    i_max_data_cnt = MAX_DATATABLE_ROW_COUNT;
                }

                if (dt.Rows.Count > i_max_data_cnt || _In.next_row > 0)
                {
                    // Select된 데이터가 max count를 넘어가면
                    // 새로운 데이터 테이블에 Max count만큼 데이터를 넣어 내려보낸다.
                    adoDataTable = new DataTable();

                    i_row_cnt = dt.Rows.Count;
                    i_row_cnt = i_row_cnt - _In.next_row;

                    i_data_cnt = _In.next_row;

                    if (i_row_cnt > i_max_data_cnt)
                    {
                        _Out.next_row = _In.next_row + i_max_data_cnt;
                        i_row_cnt = i_max_data_cnt;
                    }

                    foreach (DataColumn dc in dt.Columns)
                    {
                        adoDataTable.Columns.Add(dc.ColumnName, dc.DataType);
                    }
                    for (i = 0; i < i_row_cnt; i++)
                    {
                        adoDataTable.Rows.Add(dt.Rows[i_data_cnt].ItemArray);
                        i_data_cnt++;
                    }

                    dt.Dispose();
                    dt = null;

                    _Out.col_count = adoDataTable.Columns.Count;
                    _Out.row_count = adoDataTable.Rows.Count;

                    //DataTable을 Binary로 변환
                    BinaryData = RSCF.serializeToBinary(adoDataTable);
                    if (BinaryData == null)
                    {
                        _Out.h_db_err_msg = DBGV.gsDBError;
                        if (sQueryStatement.Length > 50)
                        {
                            _Out.h_field_msg = "DNM : SQL = " + sQueryStatement.Substring(0, 50);
                        }
                        else
                        {
                            _Out.h_field_msg = "DNM : SQL = " + sQueryStatement;
                        }
                        _Out.h_msg = DBGV.gsDBError;
                        return false;
                    }

                    //압축 해제 후 GZipStream에서 데이터를 읽기 위해 압축되기 전의 Binary Data길이를 저장                        
                    _Out.binary_length = BinaryData.Length;

                    //Binary로 변환된 DataTable을 압축
                    RSCF.DataCompress(BinaryData, ref BinaryDataZip);

                    _Out.data_tbl = new RPT_SQL_Query_DataTable_Result_Out_Tag_data_tbl[BinaryDataZip.Length];

                    i_data_cnt = 0;
                    foreach (int iData in BinaryDataZip)
                    {
                        _Out.data_tbl[i_data_cnt] = new RPT_SQL_Query_DataTable_Result_Out_Tag_data_tbl();
                        _Out.data_tbl[i_data_cnt].data = iData;

                        i_data_cnt++;
                    }
                    _Out.data_count = i_data_cnt;
                    _Out._size_data_tbl = i_data_cnt;
                }
                else
                {
                    _Out.col_count = dt.Columns.Count;
                    _Out.row_count = dt.Rows.Count;

                    //DataTable을 Binary로 변환
                    BinaryData = RSCF.serializeToBinary(dt);
                    if (BinaryData == null)
                    {
                        _Out.h_db_err_msg = DBGV.gsDBError;
                        _Out.h_field_msg = "DNM : Row Count = " + dt.Rows.Count.ToString();
                        _Out.h_msg = DBGV.gsDBError;
                        return false;
                    }

                    //압축 해제 후 GZipStream에서 데이터를 읽기 위해 압축되기 전의 Binary Data길이를 저장                        
                    _Out.binary_length = BinaryData.Length;

                    //Binary로 변환된 DataTable을 압축
                    RSCF.DataCompress(BinaryData, ref BinaryDataZip);

                    _Out.data_tbl = new RPT_SQL_Query_DataTable_Result_Out_Tag_data_tbl[BinaryDataZip.Length];

                    i_data_cnt = 0;
                    foreach (int iData in BinaryDataZip)
                    {
                        _Out.data_tbl[i_data_cnt] = new RPT_SQL_Query_DataTable_Result_Out_Tag_data_tbl();
                        _Out.data_tbl[i_data_cnt].data = iData;

                        i_data_cnt++;
                    }
                    _Out.data_count = i_data_cnt;
                    _Out._size_data_tbl = i_data_cnt;
                }

                //}//if (DB_GlobalVariable.gErrors.SqlCode == SQL_CODE.SQL_SUCCESS)
                 
                _Out.h_status_value = RSGC.MP_SUCCESS_C;

                //Out에 icon, bgcolor 추가
                _Out.icon_flag = iconFlag;
                _Out.bgcolor_flag = bgcolorFlag;

            }
            catch (Exception ex)
            {
                _Out.h_status_value = RSGC.MP_FAIL_C;
                _Out.h_msg = ex.Message;
                return false;
            }
            return true;
        }
    }
}
