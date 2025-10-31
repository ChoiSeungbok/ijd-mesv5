using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace RPTServer
{
    public sealed class RSGV
    {
        #region "Global Variables"

        public static string gsProcessNo = string.Empty;
        public static string gsRPTDBConnectionString = string.Empty;
        public static string gsSiteID = string.Empty;
        public static string gsLogDir = string.Empty;
        public static string gsLogWriteLevel = string.Empty;
        public static string gsServerName = string.Empty;
        public static string gsProcessName = string.Empty;        
        public static string gsEnvXmlFileName = string.Empty;
        public static string gsRemoteAddress = string.Empty;
        public static string gsChannel = string.Empty;
        public static string gsTitle = string.Empty;
        public static string gsStartTime = string.Empty;
        public static string gsEndTime = string.Empty;
        public static string gsMsgTitle = string.Empty;
        public static string gsSessionMode = string.Empty;
        public static string gsUseParameter = string.Empty;
        //public static string  = string.Empty;
        //public static string  = string.Empty;
        //public static string  = string.Empty;
        //public static string  = string.Empty;
        //public static string  = string.Empty;

        public static DateTime gdStartTime = DateTime.Now;
        public static DateTime gdEndTime = DateTime.Now;

        public static frmH101Svr gfrmMain = null;

        public static RPT_SQL_Query_In_Tag_cond_tbl[] parameter_tbl;


        #endregion
    }
}
