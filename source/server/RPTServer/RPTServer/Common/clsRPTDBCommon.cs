using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Windows.Forms;

#if _OLE
using System.Data.OleDb;
#elif _ORACLE 
using Oracle.DataAccess.Client;
#elif _SQL

using System.Data.SqlClient;
#endif

namespace RPTServer
{
    /// <summary>
    /// Database Global Variable
    /// </summary>
    public sealed class DBGV
    {
        //Default 30초
        public static int giQueryCommandTimeout = 30;
        public static string gsDBError = string.Empty;
        public static string gsDBType = string.Empty;

#if _OLE
        public static OleDbConnection OleDBConn = null;
        public static OleDbCommand OleCmd = null;
        public static OleDbTransaction OleTran = null;

#elif _ORACLE
        public static OracleConnection OraDBConn = null;
        public static OracleCommand OraCmd = null;
        public static OracleTransaction OraTran = null;

#elif _SQL
        public static SqlConnection SqlDBConn = null;
        public static SqlCommand SqlCmd = null;
        public static SqlTransaction SqlTran = null;
#endif
        public static bool gbDBConnected = false;
        public static string gsDBConnectionString = string.Empty;

    }

    /// <summary>
    /// Database Global Constant
    /// </summary>
    public sealed class DBGC
    {
        public const string DB_TYPE_MSSQL = "MSSQL";
        public const string DB_TYPE_ORACLE = "ORACLE";

        public const int DB_EOF_CHANNEL          = 3113;
        public const int DB_DISCONNECT           = 3114;
        public const int DB_FAIL_PACKET_WRITE    = 12571;
        public const int DB_NOT_LOGGED_ON        = 1012;
        public const int DB_LOST_CONTACT         = 3135;
        public const int DB_NO_LISTENER          = 12541;
        public const int DB_LISTENER_FAILED      = 12500;
        public const int DB_MUST_ROLL_BACK       = 25402;
    }

    public sealed class DBCF
    {
        public static void Init()
        {
#if _OLE
            if (OleDBConn != null) { OleDBConn.Dispose(); OleDBConn = null; }
            if (OleCmd != null) { OleCmd.Dispose(); OleCmd = null; }
            if (OleTran != null) { OleTran.Dispose(); OleTran = null; }
#elif _ORACLE
            if (DBGV.OraDBConn != null) { DBGV.OraDBConn.Dispose(); DBGV.OraDBConn = null; }
            if (DBGV.OraCmd != null) { DBGV.OraCmd.Dispose(); DBGV.OraCmd = null; }
            if (DBGV.OraTran != null) { DBGV.OraTran.Dispose(); DBGV.OraTran = null; }
#elif _SQL
            if (SqlDBConn != null) { SqlDBConn.Dispose(); SqlDBConn = null; }
            if (SqlCmd != null) { SqlCmd.Dispose(); SqlCmd = null; }
            if (SqlTran != null) { SqlTran.Dispose(); SqlTran = null; }
#endif
            DBGV.gbDBConnected = false;
            DBGV.gsDBConnectionString = string.Empty;
            DBGV.gsDBError = string.Empty;
        }

        /// <summary>
        /// DB Connect
        /// </summary>
        /// <returns></returns>
        public static bool Connect()
        {
            try
            {
                DBGV.gbDBConnected = false;

                LOG.AddLog("DB Open Start ");

                if (string.IsNullOrEmpty(DBGV.gsDBType))
                {
                    MessageBox.Show("DBType : " + DBGV.gsDBType);
                    return false;
                }

                if (DBGV.gsDBType == DBGC.DB_TYPE_MSSQL || DBGV.gsDBType == DBGC.DB_TYPE_ORACLE)
                {
                    DBGV.gsDBConnectionString = RSGV.gsRPTDBConnectionString;
                }
                else
                {
                    MessageBox.Show("DBType : " + DBGV.gsDBType);
                    return false;
                }

                if (string.IsNullOrEmpty(RSGV.gsRPTDBConnectionString))
                {
                    MessageBox.Show("RPTDBConnectionString : " + DBGV.gsDBConnectionString);
                    return false;
                }
#if _OLE
                DBGV.OleDBConn = new OleDbConnection(DBGV.gsDBConnectionString);
                DBGV.OleDBConn.Open();
                if (DBGV.OleDBConn.State != ConnectionState.Open)
                {
                    SetDBErrors("Connection Status is not Open");
                    return false;
                }
#elif _ORACLE
                if (DBGV.OraDBConn != null)
                    DBGV.OraDBConn.Dispose();

                DBGV.OraDBConn = new OracleConnection(DBGV.gsDBConnectionString);
                DBGV.OraDBConn.Open();
                if (DBGV.OraDBConn.State != ConnectionState.Open)
                {
                    SetDBErrors("Connection Status is not Open");
                    return false;
                }
#elif _SQL
                DBGV.SqlDBConn = new SqlConnection(DBGV.gsDBConnectionString);
                DBGV.SqlDBConn.Open();
                if (DBGV.SqlDBConn.State != ConnectionState.Open)
                {
                    SetDBErrors("Connection Status is not Open");
                    return false;
                }
#endif

                DBGV.gbDBConnected = true;

                LOG.AddLog("DB Open End: " + DBGV.gsDBConnectionString);
            }
            catch (Exception ex)
            {
                //Add by J.S. 2015.11.19 서버에 메시지 생성을 막는다.
                //MessageBox.Show(ex.Message);
                SetDBErrors(ex.Message);
                return false;
            }

            return true;
        }

        /// <summary>
        /// DB Disconnect
        /// </summary>
        /// <returns></returns>
        public static bool Disconnect()
        {
            try
            {
#if _OLE
                DBGV.OleDBConn.Close();
#elif _ORACLE
                DBGV.OraDBConn.Close();
#elif _SQL
                DBGV.SqlDBConn.Close();
#endif

                DBCF.Init();
            }
            catch (Exception ex)
            {
                //MessageBox.Show(ex.Message);
                SetDBErrors(ex.Message);
                return false;
            }
            return false;
        }

        public static bool BeginTransaction()
        {
            try
            {
#if _OLE
                if (DBGV.OleDBConn.State != ConnectionState.Open)
                {
                    if (Connect() == false) return false;
                }
                if (DBGV.gsDBType == DBGC.DB_TYPE_MSSQL)
                {
                    DBGV.OleTran = DBGV.OleDBConn.BeginTransaction(IsolationLevel.ReadUncommitted);
                }
                else
                {
                    DBGV.OleTran = DBGV.OleDBConn.BeginTransaction();
                }
#elif _ORACLE
                if (DBGV.OraDBConn.State != ConnectionState.Open)
                {
                    if (Connect() == false) return false;
                }

                DBGV.OraTran = DBGV.OraDBConn.BeginTransaction();
#elif _SQL
                if (DBGV.SqlDBConn.State != ConnectionState.Open)
                {
                    if (Connect() == false) return false;
                }
               
                DBGV.SqlTran = DBGV.SqlDBConn.BeginTransaction();
#endif

            }
            catch (Exception ex)
            {
                //Delete by J.S. 2015.11.19 서버에 웬 메시지 박스
                //MessageBox.Show(ex.Message);
                SetDBErrors(ex.Message);
                return false;
            }
            return true;
        }

        public static bool Commit()
        {
            try
            {
#if _OLE
                DBGV.OleTran.Commit();
#elif _ORACLE
                DBGV.OraTran.Commit();
#elif _SQL
                DBGV.SqlTran.Commit();
#endif
            }
            catch (Exception ex)
            {
                //MessageBox.Show(ex.Message);
                SetDBErrors(ex.Message);
                return false;
            }
            return false;
        }

        public static bool SetDBErrors(string sMsg)
        {
            try
            {
                DBGV.gsDBError = sMsg;
            }
            catch (Exception)
            {
                return false;
            }

            return true;
        }

        public static bool DB_FillDataDT(ref string sSQL, ref DataTable adoDataTable)
        {
            int i=0;
#if _OLE
            OleDbCommand adoCommand = new OleDbCommand();
#elif _ORACLE
            OracleCommand adoCommand = new OracleCommand() { CommandType = CommandType.Text, BindByName = true };
            OracleDataAdapter adoAdapter = new OracleDataAdapter();
#elif _SQL
            SqlCommand adoCommand = new SqlCommand(); //{ CommandType = CommandType.Text, BindByName = true };
#endif
                
            try
            {
                adoDataTable = new DataTable();

#if _OLE
                adoCommand.CommandText = sSQL;
                adoCommand.Connection = DBGV.OleDBConn;
                adoCommand.Transaction = DBGV.OleTran;
                adoCommand.CommandTimeout = DBGV.giQueryCommandTimeout;
                if (RSGV.parameter_tbl != null)
                {
                    for (i = 0; i < RSGV.parameter_tbl.Length; i++)
                    {
                        adoCommand.CommandText = adoCommand.CommandText.Replace(RSGV.parameter_tbl[i].cond_id, RSGV.parameter_tbl[i].cond);
                    }
                }
                OleDbDataAdapter adoAdapter = new OleDbDataAdapter();
                adoAdapter.SelectCommand = adoCommand;
                adoAdapter.Fill(adoDataTable);
#elif _ORACLE
                adoCommand.CommandText = sSQL;
                adoCommand.Connection = DBGV.OraDBConn;
                //adoCommand.Transaction = DBGV.OraTran;
                adoCommand.CommandTimeout = DBGV.giQueryCommandTimeout;
                if (RSGV.parameter_tbl != null)
                {
                    for (i = 0; i < RSGV.parameter_tbl.Length; i++)
                    {
                        if (RSGV.parameter_tbl[i].cond_type == "STRING")
                        {
                            adoCommand.Parameters.Add(RSGV.parameter_tbl[i].cond_id, RSGV.parameter_tbl[i].cond);
                            sSQL = sSQL.Replace(":" + RSGV.parameter_tbl[i].cond_id, "'" + RSGV.parameter_tbl[i].cond + "'");
                        }
                        else if (RSGV.parameter_tbl[i].cond_type == "INT")
                        {
                            adoCommand.Parameters.Add(RSGV.parameter_tbl[i].cond_id, RSGV.parameter_tbl[i].cond_int);
                            sSQL = sSQL.Replace(":" + RSGV.parameter_tbl[i].cond_id, RSGV.parameter_tbl[i].cond_int.ToString());
                        }
                        else if (RSGV.parameter_tbl[i].cond_type == "DOUBLE")
                        {
                            adoCommand.Parameters.Add(RSGV.parameter_tbl[i].cond_id, RSGV.parameter_tbl[i].cond_dbl);
                            sSQL = sSQL.Replace(":" + RSGV.parameter_tbl[i].cond_id, RSGV.parameter_tbl[i].cond_dbl.ToString());
                        }
                        else if (RSGV.parameter_tbl[i].cond_type == "FLOAT")
                        {
                            adoCommand.Parameters.Add(RSGV.parameter_tbl[i].cond_id, RSGV.parameter_tbl[i].cond_float);
                            sSQL = sSQL.Replace(":" + RSGV.parameter_tbl[i].cond_id, RSGV.parameter_tbl[i].cond_float.ToString());
                        }
                        else
                        {
                            adoCommand.CommandText = adoCommand.CommandText.Replace(RSGV.parameter_tbl[i].cond_id, RSGV.parameter_tbl[i].cond);
                            sSQL = sSQL.Replace(RSGV.parameter_tbl[i].cond_id, RSGV.parameter_tbl[i].cond);
                        }
                    }
                }
                
                adoAdapter.SelectCommand = adoCommand;

                adoAdapter.Fill(adoDataTable);
#elif _SQL
                adoCommand.CommandText = sSQL;
                adoCommand.Connection = DBGV.SqlDBConn;
                adoCommand.Transaction = DBGV.SqlTran;
                adoCommand.CommandTimeout = DBGV.giQueryCommandTimeout;

                if (RSGV.parameter_tbl != null)
                {
                    for (i = 0; i < RSGV.parameter_tbl.Length; i++)
                    {
                        if (RSGV.parameter_tbl[i].cond_type == "STRING")
                            adoCommand.Parameters.Add(RSGV.parameter_tbl[i].cond_id, RSGV.parameter_tbl[i].cond);
                        else if (RSGV.parameter_tbl[i].cond_type == "INT")
                            adoCommand.Parameters.Add(RSGV.parameter_tbl[i].cond_id, RSGV.parameter_tbl[i].cond_int);
                        else if (RSGV.parameter_tbl[i].cond_type == "DOUBLE")
                            adoCommand.Parameters.Add(RSGV.parameter_tbl[i].cond_id, RSGV.parameter_tbl[i].cond_dbl);
                        else if (RSGV.parameter_tbl[i].cond_type == "FLOAT")
                            adoCommand.Parameters.Add(RSGV.parameter_tbl[i].cond_id, RSGV.parameter_tbl[i].cond_float);
                        else
                            adoCommand.CommandText = adoCommand.CommandText.Replace(RSGV.parameter_tbl[i].cond_id, RSGV.parameter_tbl[i].cond);
                    }
                }

                SqlDataAdapter adoAdapter = new SqlDataAdapter();
                adoAdapter.SelectCommand = adoCommand;

                adoAdapter.Fill(adoDataTable);
#endif

            }
            catch (Exception ex)
            {
                if (ex.GetType().ToString() == "System.Data.OleDb.OleDbException")
                {
                    SetDBErrors(((System.Data.OleDb.OleDbException)ex).Errors.ToString() + " : " + ex.Message);
                    LOG.AddLog(((System.Data.OleDb.OleDbException)ex).Errors.ToString() + " : " + ex.Message);
                }
                else if (ex is Oracle.DataAccess.Client.OracleException)
                {
                    if ((ex as Oracle.DataAccess.Client.OracleException).Number == DBGC.DB_LISTENER_FAILED ||
                        (ex as Oracle.DataAccess.Client.OracleException).Number == DBGC.DB_DISCONNECT ||
                        (ex as Oracle.DataAccess.Client.OracleException).Number == DBGC.DB_EOF_CHANNEL ||
                        (ex as Oracle.DataAccess.Client.OracleException).Number == DBGC.DB_FAIL_PACKET_WRITE ||
                        (ex as Oracle.DataAccess.Client.OracleException).Number == DBGC.DB_NOT_LOGGED_ON ||
                        (ex as Oracle.DataAccess.Client.OracleException).Number == DBGC.DB_LOST_CONTACT ||
                        (ex as Oracle.DataAccess.Client.OracleException).Number == DBGC.DB_NO_LISTENER ||
                        (ex as Oracle.DataAccess.Client.OracleException).Number == DBGC.DB_MUST_ROLL_BACK)
                    {
                        if ((ex as Oracle.DataAccess.Client.OracleException).Number == DBGC.DB_MUST_ROLL_BACK)
                        {
                            DBGV.OraTran.Rollback();
                            Disconnect();
                        }

                        try
                        {
                            Disconnect();
                            Connect();
                        }
                        catch
                        {
                            Init();
                            Connect();
                        }

                        try
                        {
                            DBGV.OraTran = DBGV.OraDBConn.BeginTransaction();
                            adoCommand.Connection = DBGV.OraDBConn;
                            adoCommand.Transaction = DBGV.OraTran;
                            adoAdapter.SelectCommand = adoCommand;
                            adoAdapter.Fill(adoDataTable);
                            return true;
                        }
                        catch (Exception ex1)
                        {
                            SetDBErrors(ex1.Message);
                            LOG.AddLog(ex1.Message);

                            return false;
                        }
                    }

                    SetDBErrors(ex.Message);
                    LOG.AddLog(ex.Message);
                }
                else
                {
                    SetDBErrors(ex.Message);
                    LOG.AddLog(ex.Message);
                }

                return false;
            }

            return true;

        }//public static bool DB_FillData(OleDbCommand adoCommand, ref DataTable adoDataTable)

        public static bool DB_ExecuteNonQuery(string strQuery)
        {
            try
            {
#if _OLE
                OleDbCommand adoCommand = new OleDbCommand();
                adoCommand.Connection = DBGV.OleDBConn;
                adoCommand.Transaction = DBGV.OleTran;
#elif _ORACLE
                OracleCommand adoCommand = new OracleCommand();
                adoCommand.Connection = DBGV.OraDBConn;
                adoCommand.Transaction = DBGV.OraTran;
#elif _SQL
                SqlCommand adoCommand = new SqlCommand();
                adoCommand.Connection = DBGV.SqlDBConn;
                adoCommand.Transaction = DBGV.SqlTran;
#endif

                adoCommand.CommandTimeout = DBGV.giQueryCommandTimeout;
                adoCommand.CommandText = strQuery;

                if (adoCommand.ExecuteNonQuery() < 1)
                {
                    SetDBErrors("SQL_NOT_FOUND");
                    return false;
                }

            }
            catch (Exception ex)
            {
                if (ex.GetType().ToString() == "System.Data.OleDb.OleDbException")
                {
#if _OLE
                    SetDBErrors(((OleDbException)ex).Errors.ToString() + " : " + ex.Message);
                    LOG.AddLog(((OleDbException)ex).Errors.ToString() + " : " + ex.Message);
#elif _ORACLE
                    SetDBErrors(((OracleException)ex).Errors.ToString() + " : " + ex.Message);
                    LOG.AddLog(((OracleException)ex).Errors.ToString() + " : " + ex.Message);
#elif _SQL
                    SetDBErrors(((SqlException)ex).Errors.ToString() + " : " + ex.Message);
                    LOG.AddLog(((SqlException)ex).Errors.ToString() + " : " + ex.Message);
#endif
                }
                else
                    SetDBErrors(ex.Message);

                return false;
            }

            return true;

        }//public static bool DB_ExecuteNonQuery(string strQuery)

    }
}
