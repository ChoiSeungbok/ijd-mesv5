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
using Miracom.MESCore;
using Miracom.TRSCore;

namespace CUS_COM.Reports
{
    public class DevReport
    {
        /// <summary>
        /// Report출력 
        /// </summary>                
        public static void PreviewXtraReport(DataTable dt, string reportName)
        {
            string sCurrentPath = "";
            string sfilePath = "";
            string sFolderName = "\\Report\\";
            
            try
            {
                if (reportName == "")
                    return;

                sCurrentPath = $"{System.Windows.Forms.Application.StartupPath}{sFolderName}";

                //로컬에 폴더가 있는지 체크한다. 없으면 폴더 생성
                if (Directory.Exists(sCurrentPath) == false)
                {
                    Directory.CreateDirectory(sCurrentPath);
                }

                //최종 파일 경로
                sfilePath = $"{sCurrentPath}{reportName}.repx";

                if (CheckFileVersion(sfilePath, reportName) == true)
                {
                    XtraReport report = XtraReport.FromFile(sfilePath, true);
                    report.DataSource = dt;

                    report.ShowPrintMarginsWarning = false;
                    //report.DataMember = reportName;
                    report.ShowPreview();
                }
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }          
        }

        /// <summary>
        /// SubReport를 포함한 Report출력 
        /// </summary> 
        public static void PreviewXtraSubReport(DataTable dt, DataTable subDt, string reportName, string subReportName)
        {
            string sCurrentPath = "";
            string sfilePath = "";
            string sfileSubPath = "";
            string sFolderName = "\\Report\\";
            XtraReport subreport = null;

            try
            {
                if (reportName == "")
                    return;

                sCurrentPath = $"{System.Windows.Forms.Application.StartupPath}{sFolderName}";

                //로컬에 폴더가 있는지 체크한다. 없으면 폴더 생성
                if (Directory.Exists(sCurrentPath) == false)
                {
                    Directory.CreateDirectory(sCurrentPath);
                }

                //최종 파일 경로
                sfilePath = $"{sCurrentPath}{reportName}.repx";

                //서브report 파일
                sfileSubPath = $"{sCurrentPath}{subReportName}.repx";

                if(CheckFileVersion(sfileSubPath, subReportName) == true)
                {
                    subreport = XtraReport.FromFile(sfileSubPath, true);
                    subreport.DataSource = subDt;
                }
                if (CheckFileVersion(sfilePath, reportName) == true)
                {
                    XtraReport report = XtraReport.FromFile(sfilePath, true);

                    report.DataSource = dt;

                    XRSubreport sr = (XRSubreport)report.FindControl("subreport", true);
                    if(sr!=null)
                        sr.ReportSource = subreport;

                    report.ShowPreview();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private static bool CheckFileVersion(string filePath, string fileName)
        {
            string sCreateTime;

            long iFileSize;
            DateTime create_time;
            TRSNode in_node = new TRSNode("View_File_IN");
            TRSNode out_node = new TRSNode("View_File_OUT");

            try
            {
                FileInfo fi = new FileInfo(filePath);

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = 'D';
                in_node.AddString("FILE_NAME", $"{fileName}.repx");

                if (fi.Exists == false)
                {
                    in_node.AddString("CREATION_TIME", "19001231000000");
                    in_node.AddInt("FILE_SIZE", 0);
                }
                else
                {
                    create_time = fi.CreationTime;
                    sCreateTime = MPCF.ToStandardTime(create_time, MPGC.MP_CONVERT_DATETIME_FORMAT);
                    iFileSize = fi.Length;

                    in_node.AddString("CREATION_TIME", sCreateTime);
                    in_node.AddInt("FILE_SIZE", iFileSize);
                }

                if (MPCR.CallService("CUS_BAS", "CUS_BAS_Update_Reports_File", in_node, ref out_node) == false)
                {
                    return false;
                }

                if (out_node.GetChar("UPDATE_YN") == 'Y')
                    DownReport(out_node, filePath);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox($"ViewScreen() : {ex.Message}");
                return false;
            }
        }

        private static bool DownReport(TRSNode out_node, string filePath)
        {
            FileStream fs = null;
            BinaryWriter bw = null;

            try
            {
                string sPath = $"{filePath}";
                fs = File.Open($"{sPath}", FileMode.Create);
                bw = new BinaryWriter(fs);
                byte[] buffer;
                DateTime dt_create_time;

                fs.Flush();
                buffer = out_node.GetBlob(MPGC.MP_BIN_DATA_3);
                bw.Write(buffer);

                bw.Close();
                fs.Close();

                dt_create_time = MPCF.ToDate(out_node.GetString("D_CREATION_TIME"));
                File.SetCreationTime($"{sPath}", dt_create_time);

                //MPCR.ZipDecompress(sPath);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox($"UpdateRepx() : {ex.Message}");
                return false;
            }
            finally
            {
                if (bw != null)
                {
                    bw.Dispose();
                    bw = null;
                }

                if (fs != null)
                {
                    fs.Dispose();
                    fs = null;
                }
            }
        }
    }
}
