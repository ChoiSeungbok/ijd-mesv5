using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using DevExpress.XtraReports.UI;

using Miracom.CliFrx;
using Miracom.DNMCore;

namespace CUS_COM.Reports
{
    public class DevReport
    {
        /// <summary>
        /// Report출력 step 1: 성적서   
        /// </summary>                
        public static void PreviewXtraReport(DataTable dt, string reportName, char c_step = ' ')
        {
            string currentPath = "";
            string sFolderName = "\\CUS_COM\\Reports\\";

            try
            {
                if (reportName == "") return;

                //성적서
                if(c_step == '1')
                {
                    sFolderName += "qc\\";
                }

                currentPath = Path.GetDirectoryName(Path.GetDirectoryName(Directory.GetCurrentDirectory())) + sFolderName;

                XtraReport report = XtraReport.FromFile(currentPath + reportName + ".repx", true);
                report.DataSource = dt;

                //report.DataMember = reportName;

                report.ShowPreview();

            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }          
        }
    }
}
