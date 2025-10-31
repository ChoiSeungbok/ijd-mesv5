using System;
using System.Text;
using System.Data;
using System.Data.OleDb;
using System.Windows.Forms;
using System.Collections.Generic;

using Miracom.CliFrx;

//-----------------------------------------------------------------------------
//
//   System      : DEV
//   File Name   : clsDBManager.vb
//   Description :
//
//   MES Version : 4.0.0
//
//   Function List
//       -
//
//   Detail Description
//       -
//
//   History
//       - **** Do Not Modify in Site!!! ****
//       -
//
//   Copyright(C) 1998-2007 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

namespace Admin.RPTCore
{
    public class clsDBManager
    {
        private OleDbConnection m_db_connection;
        private bool m_is_connect;
        private AMGV.DBTYPE m_db_type;
        private string m_user_id;
        private string m_db_name;
        private string m_data_source;
        private string m_table_owner = string.Empty;
        private AMGV.DB_VIEW_TYPE m_view_type;

        public void dispose()
        {
            try
            {
                if (m_db_connection != null)
                {
                    m_db_connection.Close();
                    m_db_connection = null;
                }
            }
            catch
            {
                m_db_connection = null;
            }
            finally
            {
                m_is_connect = false;
            }
        }

        public OleDbConnection get_db_connection()
        {
            return m_db_connection;
        }

        public bool get_is_connect()
        {
            return m_is_connect;
        }

        public AMGV.DBTYPE get_db_type()
        {
            return m_db_type;
        }

        public string get_data_source()
        {
            return m_data_source;
        }

        public string get_db_name()
        {
            return m_db_name;
        }

        public string get_user_id()
        {
            return m_user_id;
        }

        public string get_table_owner()
        {
            return m_table_owner;
        }

        public void set_db_view_type(AMGV.DB_VIEW_TYPE t)
        {
            m_view_type = t;
        }

	    public bool db_connect(string data_source, string db_name, string user_id, string password, string table_owner,
                               AMGV.DBTYPE db_type, AMGV.DB_VIEW_TYPE db_view_type)
	    {
            string connection_string;

            if(MPCF.Trim(data_source) == "")
            {
                if(db_type != AMGV.DBTYPE.ORACLE)
                {
                    MPCF.ShowMsgBox("Please input Data Source.", "DB Connect Error", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                }
            }

            if(MPCF.Trim(db_name) == "")
            {
                MPCF.ShowMsgBox("Please input DB Name.", "DB Connect Error", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
            }

            if(MPCF.Trim(user_id) == "")
            {
                MPCF.ShowMsgBox("Please input User ID.", "DB Connect Error", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
            }

            if(MPCF.Trim(password) == "")
            {
                MPCF.ShowMsgBox("Please input Password.", "DB Connect Error", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
            }

            connection_string = string.Empty;
            m_user_id = user_id;
            m_db_type = db_type;
            m_data_source = data_source;
            m_db_name = db_name;
            m_view_type = db_view_type;
            if(table_owner.Trim() == "")
                m_table_owner = user_id;
            else
                m_table_owner = table_owner;

            try
            {
                if(db_type ==  AMGV.DBTYPE.MSSQL)
                {
                    connection_string = "Provider=SQLOLEDB.1" + 
                                        ";Data Source=" + MPCF.Trim(data_source) + 
                                        ";User ID=" + MPCF.Trim(user_id) + 
                                        ";Password=" + MPCF.Trim(password) + 
                                        ";Initial Catalog=" + MPCF.Trim(db_name) + 
                                        ";Packet Size=4096";
                }
                else if(db_type == AMGV.DBTYPE.ORACLE)
                {
                    connection_string = "Provider=OraOLEDB.Oracle.1" + 
                                        ";Password=" + MPCF.Trim(password) + 
                                        ";Persist Security Info=True" + 
                                        ";User ID=" + MPCF.Trim(user_id) + 
                                        ";Data Source=" + MPCF.Trim(db_name);
                }
                else if(db_type == AMGV.DBTYPE.DB2)
                {
                    connection_string = "Provider=IBMDADB2.1" + 
                                        ";Password=" + MPCF.Trim(password) + 
                                        ";User ID=" + MPCF.Trim(user_id) + 
                                        ";Data Source=" + MPCF.Trim(db_name) + 
                                        ";Location=" + MPCF.Trim(data_source) + 
                                        ";Persist Security Info=True";
                }

                m_db_connection = new OleDbConnection(connection_string);
                m_db_connection.Open();
                m_is_connect = true;
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message, "DB Connect Error", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                return false;
            }

            return true;
        }

        public bool db_disconnect()
        {
            try
            {
                m_db_connection.Close();
                m_is_connect = false;
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message, "DB Disconnect Error", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                return false;
            }

            return true;
        }

        public DataRow[] get_table_list()
        {
            DataTable schemaTable;
            DataRow[] schemaRow;

            schemaTable = null;

            if(m_view_type == AMGV.DB_VIEW_TYPE.TABLE)
            {
                if(m_db_type == AMGV.DBTYPE.ORACLE)
                    schemaTable = m_db_connection.GetOleDbSchemaTable(System.Data.OleDb.OleDbSchemaGuid.Tables, new Object[] {null, m_table_owner.Trim().ToUpper(), null, "TABLE"});
                else if(m_db_type == AMGV.DBTYPE.MSSQL)
                    schemaTable = m_db_connection.GetOleDbSchemaTable(System.Data.OleDb.OleDbSchemaGuid.Tables, new Object[] { null, null, null, "TABLE" });
                //else if(m_db_type == AMGV.DBTYPE.DB2)
                //    schemaTable = gOleDBConnection.GetOleDbSchemaTable(OleDb.OleDbSchemaGuid.Tables, new Object[] {null, null, null, "TABLE"});
                //else if(m_db_type == AMGV.DBTYPE.ODBC)
                //    schemaTable = gOleDBConnection.GetOleDbSchemaTable(OleDb.OleDbSchemaGuid.Tables, new Object[] {null, null, null, "TABLE"});
            } else if(m_view_type == AMGV.DB_VIEW_TYPE.VIEW)
            {
                if(m_db_type == AMGV.DBTYPE.ORACLE)
                    schemaTable = m_db_connection.GetOleDbSchemaTable(System.Data.OleDb.OleDbSchemaGuid.Views, new Object[] { null, m_table_owner.Trim().ToUpper(), null, "VIEW" });
                else if(m_db_type == AMGV.DBTYPE.MSSQL)
                    schemaTable = m_db_connection.GetOleDbSchemaTable(System.Data.OleDb.OleDbSchemaGuid.Views, new Object[] { null, null, null, "VIEW" });
                //else if(m_db_type == AMGV.DBTYPE.DB2)
                //    schemaTable = gOleDBConnection.GetOleDbSchemaTable(OleDb.OleDbSchemaGuid.Tables, new Object[] {null, null, null, "VIEW"});
                //else if(m_db_type == AMGV.DBTYPE.ODBC)
                //    schemaTable = gOleDBConnection.GetOleDbSchemaTable(OleDb.OleDbSchemaGuid.Tables, new Object[] {null, null, null, "VIEW"});
            }

            schemaRow = schemaTable.Select("", "TABLE_NAME ASC");

            if(schemaRow.Length == 0)
            {
                MPCF.ShowMsgBox("DB에 Table이 존재하지 않거나 DB Gen에서 인식할 수 없는 Table List입니다.", "GetAllTables()", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                return null;
            }

            return schemaRow;
        }

        public DataRow[] get_field_list(string tableName)
        {
            DataTable schemaTable;
            DataRow[] schemaRow;

            schemaTable = null;

            if(m_db_type == AMGV.DBTYPE.ORACLE)
                schemaTable = m_db_connection.GetOleDbSchemaTable(System.Data.OleDb.OleDbSchemaGuid.Columns, new Object[] { null, m_table_owner.Trim().ToUpper(), tableName.Trim(), null });
            else if (m_db_type == AMGV.DBTYPE.MSSQL)
                schemaTable = m_db_connection.GetOleDbSchemaTable(System.Data.OleDb.OleDbSchemaGuid.Columns, new Object[] { null, null, tableName.Trim(), null });
            //else if (m_db_type == AMGV.DBTYPE.DB2)
            //    schemaTable = m_db_connection.GetOleDbSchemaTable(System.Data.OleDb.OleDbSchemaGuid.Columns, new Object[] { null, null, tableName.Trim, null });
            //else if (m_db_type == AMGV.DBTYPE.ODBC)
            //    schemaTable = m_db_connection.GetOleDbSchemaTable(System.Data.OleDb.OleDbSchemaGuid.Columns, new Object[] { null, null, tableName.Trim, null });

            schemaRow = schemaTable.Select("", "ORDINAL_POSITION ASC");

            return schemaRow;
        }

        public DataRow[] get_PK_list(string tableName)
        {
            DataTable schemaPKTable;
            DataRow[] schemaPKRow;

            schemaPKTable = null;

            // 2005-09-22 오후 12:02:47, HS Kim
            if(m_db_type == AMGV.DBTYPE.ORACLE)
                schemaPKTable = m_db_connection.GetOleDbSchemaTable(System.Data.OleDb.OleDbSchemaGuid.Primary_Keys, new Object[] { null, m_table_owner.Trim().ToUpper(), tableName.Trim() });
            else if (m_db_type == AMGV.DBTYPE.MSSQL)
                schemaPKTable = m_db_connection.GetOleDbSchemaTable(System.Data.OleDb.OleDbSchemaGuid.Primary_Keys, new Object[] { null, null, tableName.Trim() });
            //else if (m_db_type == AMGV.DBTYPE.DB2)
            //    schemaPKTable = m_db_connection.GetOleDbSchemaTable(System.Data.OleDb.OleDbSchemaGuid.Primary_Keys, new Object[] { null, null, tableName.Trim });
            //else if (m_db_type == AMGV.DBTYPE.ODBC)
            //    schemaPKTable = m_db_connection.GetOleDbSchemaTable(System.Data.OleDb.OleDbSchemaGuid.Primary_Keys, new Object[] { null, null, tableName.Trim });

            schemaPKRow = schemaPKTable.Select("", "ORDINAL ASC");

            return schemaPKRow;
        }
    }
}
