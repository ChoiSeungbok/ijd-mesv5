using System;
using System.Collections.Generic;
using System.Text;

namespace Admin.RPTCore
{
    public class AMGV
    {
        public static bool GetFieldInfo;

#region "Enum Definition"
        public enum DATATYPE
        {
            UNKNOWN_TYPE = 0,
            CHAR_TYPE = 1,
            VARCHAR_TYPE = 2,
            INTEGER_TYPE = 3,
            DECIMAL_TYPE = 4,
            NUMERIC_TYPE = 5,
            DOUBLE_TYPE = 6,
            TIMESTAMP_TYPE = 7,
            FLOAT_TYPE = 8
        }

        public enum DBTYPE
        {
            MSSQL = 0,
            ORACLE = 1,
            DB2 = 2,
            ODBC = 3,
            SCRIPT = 4
        }

        public enum DB_VIEW_TYPE
        {
            TABLE = 0,
            VIEW = 1
        }
#endregion
    }
}
