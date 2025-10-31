using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace RPTServer
{
    public static class LOG
    {
        public static void AddLog(string Message)
        {
            StreamWriter sw = null;

            string LogDir = RSGV.gsLogDir;
            string strFullPath = GetFileName(LogDir);            
            string sTime = DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss");
            string sLog = string.Empty;

            try
            {
                if (!Directory.Exists(LogDir)) Directory.CreateDirectory(LogDir);

                sLog = "[" + RSGV.gsProcessNo + "]" + sTime + "\r\n";
                sLog += Message + "\r\n";

                sw = new StreamWriter(strFullPath, true);
                sw.AutoFlush = true;
                sw.WriteLine(sLog);
                sw.Close();
            }
            catch
            {
                /// Error 무시
            }
            finally
            {
                if (sw != null)
                {
                    sw.Dispose();
                }
            }
        }

        private static string GetFileName(string LogDir)
        {
            return string.Format(@"{0}\RPTServer{1}.txt", LogDir, DateTime.Now.ToString("yyyyMMdd"));
        }
    }
}
