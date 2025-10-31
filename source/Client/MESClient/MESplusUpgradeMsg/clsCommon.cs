using System;
using System.Data;
using System.Drawing;
using System.Diagnostics;
using System.Windows.Forms;
using System.Collections;

namespace MESplusUpgradeMsg
{
    sealed class clsCommon
    {
        public static string[][] DownFileList = new string[5][];
        public static string ExecuteFile;
        
        // GetFileList()
        //       - Function Description
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       -
        //
        public static bool GetFileList(string ListFile)
        {
            
            System.IO.FileStream fs;
            System.IO.StreamReader xmlReader;
            
            System.Data.DataSet adoDataSet = new System.Data.DataSet();
            System.Data.DataRow adoDataRow;
            
            System.Data.DataColumn[] adoDataColumn;
            int i;
            
            try
            {
                // Open XML File
                fs = new System.IO.FileStream(ListFile, System.IO.FileMode.Open, System.IO.FileAccess.Read, System.IO.FileShare.ReadWrite);
                
                // Set xmlReader
                xmlReader = new System.IO.StreamReader(fs);
                
                // Read DataSet
                adoDataSet.ReadXml(xmlReader);
                
                // Set PrimaryKey
                adoDataColumn = new System.Data.DataColumn[1];
                adoDataColumn[0] = adoDataSet.Tables[1].Columns[0];
                adoDataSet.Tables[1].PrimaryKey = adoDataColumn;
                
                // Get Options
                ExecuteFile = adoDataSet.Tables[0].Rows[0].ItemArray[0].ToString();

                DownFileList[0] = new string[adoDataSet.Tables[1].Rows.Count];
                DownFileList[1] = new string[adoDataSet.Tables[1].Rows.Count];
                DownFileList[2] = new string[adoDataSet.Tables[1].Rows.Count];
                DownFileList[3] = new string[adoDataSet.Tables[1].Rows.Count];
                DownFileList[4] = new string[adoDataSet.Tables[1].Rows.Count];
                
                for (i = 0; i < adoDataSet.Tables[1].Rows.Count; i++)
                {
                    adoDataRow = adoDataSet.Tables[1].Rows[i];
                    DownFileList[0][i] = adoDataRow.ItemArray[0].ToString();
                    DownFileList[1][i] = adoDataRow.ItemArray[1].ToString();
                    DownFileList[2][i] = adoDataRow.ItemArray[2].ToString();
                    DownFileList[3][i] = adoDataRow.ItemArray[3].ToString();
                    DownFileList[4][i] = adoDataRow.ItemArray[4].ToString();
                }
                
                // Close XML File
                fs.Close();
                
            }
            catch (Exception)
            {
                MessageBox.Show("Fail to read XML File.");
                return false;
            }
            
            return true;
            
        }
        
    }
}
