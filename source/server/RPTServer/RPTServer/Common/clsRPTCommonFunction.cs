using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;
using System.Collections;
using System.Drawing;
using System.Data;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO.Compression;
using System.Globalization;

namespace RPTServer
{
    public sealed class RSCF
    {
        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public static bool GetCommandLine()
        {

            try
            {
                string[] arguments = Environment.GetCommandLineArgs();
                RSGV.gsProcessNo = arguments[1];
                RSGV.gsEnvXmlFileName = arguments[2];
            }
            catch (Exception ex)
            {
                Debug.WriteLine(ex.Message);
                return false;
            }

            return true;

        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public static bool GetServerEnv()
        {
            System.IO.FileStream fs;
            System.IO.StreamReader xmlReader;

            System.Data.DataSet adoDataSet = new System.Data.DataSet();
            System.Data.DataRow adoDataRow;

            System.Data.DataColumn[] adoDataColumn;

            object key;

            try
            {
                // Open XML File
                fs = new System.IO.FileStream(RSGV.gsEnvXmlFileName, System.IO.FileMode.Open, System.IO.FileAccess.Read, System.IO.FileShare.ReadWrite);

                // Set xmlReader
                xmlReader = new System.IO.StreamReader(fs);

                // Read DataSet
                adoDataSet.ReadXml(xmlReader);

                // Set PrimaryKey
                adoDataColumn = new System.Data.DataColumn[1];
                adoDataColumn[0] = adoDataSet.Tables[0].Columns[0];
                adoDataSet.Tables[0].PrimaryKey = adoDataColumn;

                // Get DB Connection String
                key = "RPTDBConnectionString";
                adoDataRow = adoDataSet.Tables[0].Rows.Find(key);
                RSGV.gsRPTDBConnectionString = adoDataRow["OptionValue"] as string;

                // Get SiteID
                key = "RPTSiteID";
                adoDataRow = adoDataSet.Tables[0].Rows.Find(key);
                RSGV.gsSiteID = adoDataRow["OptionValue"] as string;

                // Get Log Directory
                key = "RPTLogDir";
                adoDataRow = adoDataSet.Tables[0].Rows.Find(key);
                RSGV.gsLogDir = adoDataRow["OptionValue"] as string;

                // Get Log Write Level
                key = "RPTLogWriteLevel";
                adoDataRow = adoDataSet.Tables[0].Rows.Find(key);
                RSGV.gsLogWriteLevel = adoDataRow["OptionValue"] as string;

                // Get Server Name
                key = "RPTServerName";
                adoDataRow = adoDataSet.Tables[0].Rows.Find(key);
                RSGV.gsServerName = adoDataRow["OptionValue"] as string;

                // Get Process Name
                key = "RPTProcessName";
                adoDataRow = adoDataSet.Tables[0].Rows.Find(key);
                RSGV.gsProcessName = adoDataRow["OptionValue"] as string;

                // Get DB Type
                key = "RPTDBType";
                adoDataRow = adoDataSet.Tables[0].Rows.Find(key);
                DBGV.gsDBType = adoDataRow["OptionValue"] as string;

                // Get Remote Address for H101
                key = "RPTRemoteAddress";
                adoDataRow = adoDataSet.Tables[0].Rows.Find(key);
                RSGV.gsRemoteAddress = adoDataRow["OptionValue"] as string;

                // Get Session Mode
                key = "RPTSessionMode";
                adoDataRow = adoDataSet.Tables[0].Rows.Find(key);
                RSGV.gsSessionMode = adoDataRow["OptionValue"] as string;

                // Get DB Type
                key = "QueryCommandTimeout";
                adoDataRow = adoDataSet.Tables[0].Rows.Find(key);
                DBGV.giQueryCommandTimeout = ToInt(adoDataRow["OptionValue"] as string);
                //Default 30초
                if (DBGV.giQueryCommandTimeout <= 30)
                {
                    DBGV.giQueryCommandTimeout = 30;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return false;
            }

            return true;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="str"></param>
        /// <returns></returns>
        public static int ToInt(string str)
        {
            int iRet = 0;

            try
            {
                if (string.IsNullOrEmpty(str))
                {
                    iRet = 0;
                }
                else
                {
                    if (string.IsNullOrEmpty(str.Trim()))
                    {
                        iRet = 0;
                    }
                    else
                    {
                        iRet = Convert.ToInt32(str);
                    }
                }

            }
            catch (Exception)
            {
                return iRet;
            }

            return iRet;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sValue"></param>
        /// <returns></returns>
        public static string Trim(string sValue)
        {
            string sRet = string.Empty;

            try
            {
                if (string.IsNullOrEmpty(sValue))
                {
                    sRet = string.Empty;
                }
                else
                {
                    if (string.IsNullOrEmpty(sValue.Trim()))
                    {
                        sRet = string.Empty;
                    }
                    else
                    {
                        sRet = sValue.Trim();
                    }
                }
            }
            catch (Exception)
            {
                return sRet;
            }

            return sRet;
        }

        /// <summary>
        /// object -> Binary로 변환
        /// </summary>
        /// <param name="obj"></param>
        /// <returns></returns>
        public static byte[] serializeToBinary(object obj)
        {
            BinaryFormatter binFormatter = null;
            MemoryStream memStm = null;
            try
            {
                binFormatter = new BinaryFormatter();
                memStm = new MemoryStream();
                binFormatter.Serialize(memStm, obj);
                return memStm.GetBuffer();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return null;
            }
            finally
            {
                binFormatter = null;
                if (memStm != null)
                {
                    memStm.Dispose();
                    memStm = null;
                }
            }
        }

        /// <summary>
        /// Binary -> object로 변환
        /// </summary>
        /// <param name="bytes"></param>
        /// <returns></returns>
        public static object deserializeFromBinary(byte[] _BinaryData)
        {
            BinaryFormatter binFormatter = null;
            MemoryStream memStm = null;
            try
            {
                binFormatter = new BinaryFormatter();
                memStm = new MemoryStream(_BinaryData);
                if (memStm.Length == 0)
                {
                    return null;
                }

                return binFormatter.Deserialize(memStm);
            }
            catch
            {
                return null;
            }
            finally
            {
                binFormatter = null;
                memStm = null;
            }
        }

        /// <summary>
        /// Binary Data 압축
        /// </summary>
        /// <param name="_Data"></param>
        /// <param name="_ByteZip"></param>
        public static void DataCompress(byte[] _BinaryData, ref byte[] _BinaryDataZip)
        {
            try
            {
                MemoryStream ms = null;
                GZipStream zipStream = null;
                byte[] buf = null;

                buf = new Byte[_BinaryData.Length];
                ms = new MemoryStream();
                buf = _BinaryData;

                // Use the newly created memory stream for the compressed data.
                zipStream = new GZipStream(ms, CompressionMode.Compress, true);
                zipStream.Write(buf, 0, buf.Length);
                zipStream.Close();

                _BinaryDataZip = ms.ToArray();

                ms.Close();
                zipStream.Dispose();
                ms.Dispose();
            }
            catch (Exception ex)
            {
                throw (ex);
            }
        }

        /// <summary>
        /// Data 압축 해제
        /// </summary>
        /// <param name="_Data"></param>
        /// <param name="_ByteZip"></param>
        public static void DataDecompress(byte[] _BinaryDataZip, ref byte[] _BinaryData, int _BinaryDataLength)
        {
            try
            {
                MemoryStream ms = null;
                GZipStream zipStream = null;

                // Use the newly created memory stream for the decompressed data.
                ms = new MemoryStream(_BinaryDataZip);
                zipStream = new GZipStream(ms, CompressionMode.Decompress);

                _BinaryData = new byte[_BinaryDataLength];
                zipStream.Read(_BinaryData, 0, _BinaryDataLength);

                zipStream.Close();
                ms.Close();
                zipStream.Dispose();
                ms.Dispose();
            }
            catch
            {
                return;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public static bool StartProcess()
        {
            try
            {
                //Set StartTime
                ///gCOM_StartTime = Now;
                RSGV.gdStartTime = DateTime.Now;

                // Set PROC Status
                RSGV.gfrmMain.SetWorkProcessEvent(0);
                RSGV.gfrmMain.SetWorkCountEvent();

                RSGV.gfrmMain.SetMessageEvent(RSGV.gsMsgTitle);

                // Set Process Start Log
                //gLog.LogWrite("START " + gCOM_Msg_Title, "I");
                LOG.AddLog("START : " + RSGV.gsMsgTitle);

                
            }
            catch (Exception)
            {
                throw;
            }

            return true;
        }

        /// <summary>
        /// 
        /// </summary>
        /// <returns></returns>
        public static bool EndProcess()
        {
            TimeSpan tsDiffTime;

            try
            {
                // Set EndTime
                RSGV.gdEndTime = DateTime.Now;

                // Duration Time
                tsDiffTime = RSGV.gdEndTime.Subtract(RSGV.gdStartTime);

                RSGV.gfrmMain.SetMessageEvent("REPLY_MESSAGE");

                // Set Process Start Log
                LOG.AddLog("END : " + RSGV.gsMsgTitle);

                // Set ProcTime
                RSGV.gfrmMain.SetProcessTimeEvent(tsDiffTime);
                // Set WAIT Status
                RSGV.gfrmMain.SetWorkProcessEvent(1);
            }
            catch (Exception)
            {
                throw;
            }

            return true;
        }        
    }
}
