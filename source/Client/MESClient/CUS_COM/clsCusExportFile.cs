using System;
using Miracom.CliFrx;
using Miracom.DNMCore;
using System.Data;
using Miracom.TRSCore;
using Miracom.MESCore;
using FarPoint.Win.Spread;
using System.Diagnostics;
using System.IO;
using System.Text;

namespace CUS_COM
{
    public  class clsCusExportFile
    {
        // 20250211 년단위 데이터 뽑는게 계록 다운되어서.. CSV파일로 뽑을수 있게 추가.(몇십만건)

        public bool SaveDataTableToCsv(DataTable dt, string filePath, SheetView oSheet, string[] sHeaderNames)
        {
            StringBuilder sb = new StringBuilder();


            try
            {
                // 컬럼 헤더 추가
                // 시트상의 컬럼해더랑 DataTable이랑 위치 갯수 같아야함..다르면..틀어짐...
                // 값에 ","있으면 필드로 구분되서 강제로"."으로 바꿈.

                string[] columnNames = new string[dt.Columns.Count];
                for (int i = 0; i < dt.Columns.Count; i++)
                {
                    //    columnNames[i] = dt.Columns[i].ColumnName;

                    if (oSheet != null)
                    {
                        if (oSheet.ColumnCount - 1 >= i)
                        {
                            columnNames[i] = oSheet.ColumnHeader.Cells[0, i].Text.Replace(",", ".");
                        }
                    }
                    else if(sHeaderNames != null)
                    {
                        columnNames[i] = sHeaderNames[i];
                    }
                    else
                    {
                        columnNames[i] = dt.Columns[i].ColumnName.Replace(",", ".");
                    }


                }
                sb.AppendLine(string.Join(",", columnNames));

                // 데이터 추가
                foreach (DataRow row in dt.Rows)
                {
                    string[] fields = new string[dt.Columns.Count];
                    for (int i = 0; i < dt.Columns.Count; i++)
                    {
                        fields[i] = row[i].ToString().Replace(",", ".");
                    }
                    sb.AppendLine(string.Join(",", fields));
                }


                string directoryPath = Path.GetDirectoryName(filePath) ?? "";
                Directory.CreateDirectory(directoryPath);


                File.WriteAllText(filePath, sb.ToString(), Encoding.UTF8);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

        }



        public bool OpenCsvInExcel(string filePath)
        {
            try
            {

                //엑셀로 자동오픈
                ProcessStartInfo psi = new ProcessStartInfo
                {
                    FileName = "excel",
                    Arguments = $"\"{filePath}\"",
                    UseShellExecute = true
                };

                Process.Start(psi);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

    }


   

}
