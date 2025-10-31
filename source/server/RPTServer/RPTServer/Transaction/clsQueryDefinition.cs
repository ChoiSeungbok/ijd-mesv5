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
        public static int RPT_Query_Definition_Setup(RPT_Query_Definition_Setup_In_Tag _In
                                                    , ref Cmn_Out_Tag _Out)
        {
            bool bRet = false;

            try
            {
                // Begin Transaction
                DBCF.BeginTransaction();

                bRet = RPT_Query_Definition_Setup_Main(_In, ref _Out);

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
#if _OLE
                DBGV.OleTran.Rollback();
#elif _ORACLE
                DBGV.OraTran.Rollback();
#elif _SQL
                DBGV.SqlTran.Rollback();
#endif
                _Out.h_status_value = RSGC.MP_FAIL_C;
                _Out.h_msg = ex.Message;
                return RSGC.MP_FAIL;
            }
            return RSGC.MP_SUCCESS;
        }

        public static bool RPT_Query_Definition_Setup_Main(RPT_Query_Definition_Setup_In_Tag _In
                                                    , ref Cmn_Out_Tag _Out)
        {
            string sQueryStatement = string.Empty;
            string sQueryStatement_his = string.Empty;

            string sMode = string.Empty;
            DataTable dt = null;

            try
            {
                //LOG.AddLog(_In.sql);
                if (string.IsNullOrEmpty(RSCF.Trim(_In.sql_id)))
                {
                    _Out.h_field_msg = "sql_id = Empty";
                    return false;
                }

                if (string.IsNullOrEmpty(RSCF.Trim(_In.sql_desc))) _In.sql_desc = " ";
                if (string.IsNullOrEmpty(RSCF.Trim(_In.sql_type_flag.ToString()))) _In.sql_type_flag = ' ';
                if (string.IsNullOrEmpty(RSCF.Trim(_In.sql_group))) _In.sql_group = " ";
                if (string.IsNullOrEmpty(RSCF.Trim(_In.sql_text))) _In.sql_text = " ";
                if (string.IsNullOrEmpty(RSCF.Trim(_In.resv_field_1))) _In.resv_field_1 = " ";
                if (string.IsNullOrEmpty(RSCF.Trim(_In.resv_field_2))) _In.resv_field_2 = " ";
                if (string.IsNullOrEmpty(RSCF.Trim(_In.resv_field_3))) _In.resv_field_3 = " ";
                if (string.IsNullOrEmpty(RSCF.Trim(_In.resv_field_4))) _In.resv_field_4 = " ";
                if (string.IsNullOrEmpty(RSCF.Trim(_In.resv_field_5))) _In.resv_field_5 = " ";
                if (string.IsNullOrEmpty(RSCF.Trim(_In.create_user_id))) _In.create_user_id = " ";
                if (string.IsNullOrEmpty(RSCF.Trim(_In.create_time))) _In.create_time = " ";
                if (string.IsNullOrEmpty(RSCF.Trim(_In.update_user_id))) _In.update_user_id = " ";
                if (string.IsNullOrEmpty(RSCF.Trim(_In.update_time))) _In.update_time = " ";

                if (_In.h_proc_step == '1')
                {
                    #region " SELECT Check "
                    sQueryStatement = string.Empty;
                    sQueryStatement = "SELECT * FROM CBASSQLDEF WHERE SQL_ID = '" + _In.sql_id + "'";

                    if (DBCF.DB_FillDataDT(ref sQueryStatement, ref dt) == false)
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
                        return false;
                    }
                    #endregion

                    if (dt == null || dt.Rows.Count <= 0)
                    {
                        sMode = "INSERT";

                        #region " INSERT Query "
                        sQueryStatement = string.Empty;
                        sQueryStatement += "INSERT INTO CBASSQLDEF ";
                        sQueryStatement += "    (SQL_ID, SQL_DESC, SQL_TYPE_FLAG, SQL_GROUP, SQL_TEXT ";
                        sQueryStatement += "    , RESV_FIELD_1, RESV_FIELD_2, RESV_FIELD_3, RESV_FIELD_4, RESV_FIELD_5 ";
                        sQueryStatement += "    , CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME) ";
                        sQueryStatement += "VALUES ";
                        sQueryStatement += "    ( ";
                        sQueryStatement += "'" + _In.sql_id + "'";
                        sQueryStatement += ", '" + _In.sql_desc.Replace("'", "''") + "'";
                        sQueryStatement += ", '" + _In.sql_type_flag.ToString() + "'";
                        sQueryStatement += ", '" + _In.sql_group.Replace("'", "''") + "'";
                        sQueryStatement += ", '" + _In.sql_text.Replace("'", "''") + "'";
                        sQueryStatement += ", '" + _In.resv_field_1.Replace("'", "''") + "'";
                        sQueryStatement += ", '" + _In.resv_field_2.Replace("'", "''") + "'";
                        sQueryStatement += ", '" + _In.resv_field_3.Replace("'", "''") + "'";
                        sQueryStatement += ", '" + _In.resv_field_4.Replace("'", "''") + "'";
                        sQueryStatement += ", '" + _In.resv_field_5.Replace("'", "''") + "'";
                        sQueryStatement += ", '" + _In.h_user_id + "'";
                        sQueryStatement += ", TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS') ";
                        sQueryStatement += ", '" + _In.h_user_id + "'";
                        sQueryStatement += ", TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS') ";
                        sQueryStatement += "    ) ";
                        #endregion
                    }
                    else
                    {
                        sMode = "UPDATE";

                        #region " UPDATE Query "
                        sQueryStatement = string.Empty;
                        sQueryStatement += "UPDATE CBASSQLDEF SET ";
                        sQueryStatement += "    SQL_DESC = '" + _In.sql_desc.Replace("'", "''") + "'";
                        sQueryStatement += "    , SQL_TYPE_FLAG = '" + _In.sql_type_flag.ToString() + "'";
                        sQueryStatement += "    , SQL_GROUP = '" + _In.sql_group.Replace("'", "''") + "'";
                        sQueryStatement += "    , SQL_TEXT = '" + _In.sql_text.Replace("'", "''") + "'";
                        sQueryStatement += "    , RESV_FIELD_1 = '" + _In.resv_field_1.Replace("'", "''") + "'";
                        sQueryStatement += "    , RESV_FIELD_2 = '" + _In.resv_field_2.Replace("'", "''") + "'";
                        sQueryStatement += "    , RESV_FIELD_3 = '" + _In.resv_field_3.Replace("'", "''") + "'";
                        sQueryStatement += "    , RESV_FIELD_4 = '" + _In.resv_field_4.Replace("'", "''") + "'";
                        sQueryStatement += "    , RESV_FIELD_5 = '" + _In.resv_field_5.Replace("'", "''") + "'";
                        sQueryStatement += "    , UPDATE_USER_ID = '" + _In.h_user_id + "'";
                        sQueryStatement += "    , UPDATE_TIME = TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS') ";
                        sQueryStatement += "WHERE SQL_ID = '" + _In.sql_id + "'";
                        #endregion
                    }

                    if (DBCF.DB_ExecuteNonQuery(sQueryStatement) == false)
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
                        return false;
                    }
                }
                else if (_In.h_proc_step == '2')
                {
                    sMode = "DELETE";
                    
                    sQueryStatement = string.Empty;
                    sQueryStatement = "DELETE FROM CBASSQLDEF WHERE SQL_ID = '" + _In.sql_id + "'";

                    if (DBCF.DB_ExecuteNonQuery(sQueryStatement) == false)
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
                        return false;
                    }
                }

                //History Insert

                #region " History Insert "
                sQueryStatement = string.Empty;
                sQueryStatement += "INSERT INTO CBASSQLHIS ";
                sQueryStatement += "    (TRAN_TIME, SQL_ID, SQL_DESC, SQL_TYPE_FLAG, SQL_GROUP, SQL_TEXT ";
                sQueryStatement += "    , RESV_FIELD_1, RESV_FIELD_2, RESV_FIELD_3, RESV_FIELD_4, RESV_FIELD_5 ";
                sQueryStatement += "    , CREATE_USER_ID, CREATE_TIME, UPDATE_USER_ID, UPDATE_TIME) ";
                sQueryStatement += "VALUES ";
                sQueryStatement += "    ( ";
                sQueryStatement += "TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS') ";
                sQueryStatement += ", '" + _In.sql_id + "'";
                sQueryStatement += ", '" + _In.sql_desc.Replace("'", "''") + "'";
                sQueryStatement += ", '" + _In.sql_type_flag.ToString() + "'";
                sQueryStatement += ", '" + _In.sql_group.Replace("'", "''") + "'";
                sQueryStatement += ", '" + _In.sql_text.Replace("'", "''") + "'";
                sQueryStatement += ", '" + _In.resv_field_1.Replace("'", "''") + "'";
                sQueryStatement += ", '" + _In.resv_field_2.Replace("'", "''") + "'";
                sQueryStatement += ", '" + _In.resv_field_3.Replace("'", "''") + "'";
                sQueryStatement += ", '" + _In.resv_field_4.Replace("'", "''") + "'";
                //sQueryStatement += ", '" + _In.resv_field_5.Replace("'", "''") + "'";
                sQueryStatement += ", '" + sMode + "'";
                sQueryStatement += ", '" + _In.h_user_id + "'";
                sQueryStatement += ", TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS') ";
                sQueryStatement += ", '" + _In.h_user_id + "'";
                sQueryStatement += ", TO_CHAR(SYSDATE, 'YYYYMMDDHH24MISS') ";
                sQueryStatement += "    ) ";

                if (DBCF.DB_ExecuteNonQuery(sQueryStatement) == false)
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
                    return false;
                }
                #endregion

                _Out.h_status_value = RSGC.MP_SUCCESS_C;

            }
            catch (Exception ex)
            {
                _Out.h_status_value = RSGC.MP_FAIL_C;
                _Out.h_msg = ex.Message;
                return false;
            }
            finally
            {
                if (dt != null) { dt.Dispose(); dt = null; }
            }

            return true;
        }
    }
}
