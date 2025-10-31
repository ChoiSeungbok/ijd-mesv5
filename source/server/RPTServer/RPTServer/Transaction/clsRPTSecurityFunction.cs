using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.IO;
using System.Data;
using System.Data.OleDb;
using EPADM2Lib;
using EPTRAYUTILLib;

namespace RPTServer
{
    public partial class RPTServerTran
    {
        public static int RPT_MySingle_Information(RPT_MySingle_Information_In_Tag _In
                                                    , ref RPT_MySingle_Information_Out_Tag _Out)
        {
            bool bRet = false;

            try
            {
                // Begin Transaction
                //DBCF.BeginTransaction();

                bRet = RPT_MySingle_Information_Main(_In, ref _Out);                

                if (bRet == false || _Out.h_status_value == RSGC.MP_FAIL_C)
                {
                    //DBGV.OleTran.Rollback();
                }
                else
                {
                    //DBGV.OleTran.Commit();
                }
            }
            catch (Exception ex)
            {
#if _OLE
                DBGV.OleTran.Rollback();
#elif _ORACLE
                DBGV.OraTran.Rollback();
#elif _SQL
                DBGV.SqlTran.Rollback();
#endif
                _Out.h_status_value = RSGC.MP_FAIL_C;
                _Out.h_msg = ex.Message;
                return RSGC.MP_FAIL;
            }
            return RSGC.MP_SUCCESS;
        }

        public static bool RPT_MySingle_Information_Main(RPT_MySingle_Information_In_Tag _In
                                                   , ref RPT_MySingle_Information_Out_Tag _Out)
        {
            try
            {
                if (_In.h_proc_step == '1')
                {
                    Hashtable ht = GetFuncHashTable(_In.ConnData, _In.ip);
                    string sOutput = string.Empty;

                    foreach (DictionaryEntry item in ht)
                    {
                        sOutput += item.Key.ToString() + "=" + item.Value.ToString() + ";";
                    }
                    _Out.ConnData = sOutput;
                }
                else if (_In.h_proc_step == '2')
                {                    
                    string[] CondList = null;
                    string sQuery = string.Empty;
                    
                    CondList = _In.ConnData.ToString().Split('^');

                    sQuery = "UPDATE ZSAUTA05 "
                           + " SET F_OPT_11 = '" + Encode(CondList[0]) +  "'"
                           + ", D_MODIFY = '" + DateTime.Now.ToString("yyyyMMddHHmmss") + "'"
                           + ", I_MOD_USER = FN_DECODEUID('" + CondList[2] + "')"
                           + " WHERE I_SYSTEM = '" + CondList[1] + "'"
                           + " AND I_USER = FN_DECODEUID('" + CondList[2] + "')";

                    if (DBCF.DB_ExecuteNonQuery(sQuery) == false)
                    {                        
                        _Out.h_status_value = RSGC.MP_FAIL_C;                        
                        return false;
                    }
                }
                else if (_In.h_proc_step == '3')
                {
                    DataTable dt = null;
                    string[] CondList = null;
                    string sQuery = string.Empty;
                    
                    CondList = _In.ConnData.ToString().Split('^');

                    sQuery = "SELECT COUNT(*) FROM ZSAUTA05 WHERE I_USER = '" + CondList[0] + "'"                    
                        + " AND F_OPT_11 = '" + Encode(CondList[1]) + "'";


                    if (DBCF.DB_FillDataDT(ref sQuery, ref dt) == false)
                    {
                        _Out.h_status_value = RSGC.MP_FAIL_C;
                        return false;
                    }

                    if(dt != null && dt.Rows.Count > 0)
                    {
                        _Out.ConnData = dt.Rows[0][0].ToString();
                    }
                }
                else if (_In.h_proc_step == '4')
                {
                    DataTable dt = null;
                    string[] CondList = null;
                    string sQuery = string.Empty;

                    CondList = _In.ConnData.ToString().Split('^');
                                        
                    sQuery = "SELECT COUNT(*) FROM ZSAUTA05 WHERE I_USER = FN_DECODEUID('" + CondList[0] + "')"
                           + " AND F_OPT_11 = '" + Encode(CondList[1]) + "'";

                    if (DBCF.DB_FillDataDT(ref sQuery, ref dt) == false)
                    {
                        _Out.h_status_value = RSGC.MP_FAIL_C;
                        return false;
                    }

                    if (dt != null && dt.Rows.Count > 0)
                    {
                        _Out.ConnData = dt.Rows[0][0].ToString();
                    }
                }


                _Out.h_status_value = RSGC.MP_SUCCESS_C;
            }
            catch (Exception ex)
            {
                _Out.h_status_value = RSGC.MP_FAIL_C;
                _Out.h_msg = ex.Message;
                return false;
            }
            finally
            {
                //if (dt != null) { dt.Dispose(); dt = null; }
                //if (adoCommand != null) { adoCommand.Dispose(); adoCommand = null; }
            }

            return true;
        }

        public static Hashtable GetFuncHashTable(string Userinfo, string UserIP)
        {
            Hashtable EPUserInfo = null;

            try
            {
                string[] EPTrayDataArray = Userinfo.Split(';');

                string encryptedData = EPTrayDataArray[0];
                string DESKey = EPTrayDataArray[1];
                string keyFolder = EPTrayDataArray[2];
                string UserID = string.Empty;


                //FileStream fs = new FileStream("C:\\SSO\\" + keyFolder + "\\mySingle_Key", FileMode.OpenOrCreate, FileAccess.Read);
                //StreamReader st = new StreamReader(fs, Encoding.ASCII);
                //string key = st.ReadToEnd();

                string key = "MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCfLkZ0LtMe+lY9yIaPMn2U/p+D4dlx4boLoUTg4qvK56am67vPwgSYTFUCFhaBDk1NHCVt0MCE515Qzcese+porpyDw9shjW6KQ1gFSJNwYFTFym44hUPx4VkLJ/eHNXVz5Eov74RV0sUYd8IBWV3T+Vx89/Dl9nomSPuIvgTZMQIDAQAB";

                SDIENCRYPTLib.EncryptClass SDI = new SDIENCRYPTLib.EncryptClass();
                EPTRAYUTILLib.UtilClass util = new EPTRAYUTILLib.UtilClass();
                string decryptedDataList = util.DecryptDataList(key, DESKey, encryptedData);

                //string decryptedDataList = util.DecryptDataList2(keyFolder, DESKey, encryptedData);                

                string[] decryptedDataListArray = decryptedDataList.Split(';');

                EPUserInfo = new Hashtable();

                for (int i = 0; i < decryptedDataListArray.Length; i++)
                {
                    string[] val = decryptedDataListArray[i].Split('=');

                    if (val[0].Length <= 0)
                        break;

                    if (val[0] == "EP_SOCIALID")
                    {
                        //**** 주민번호는 클라이언트로 전송 하지 않음****//
                        //UserID = SDI.getEncode(val[1], UserIP);    //암호화
                        //EPUserInfo.Add(val[0], UserID);                        

                        //UserID = SDI.getDecode(UserID, UserIP);  //복호화
                    }
                    else
                    {
                        EPUserInfo.Add(val[0], val[1]);
                    }
                }

                if (!InspectEPTrayData(EPUserInfo, UserIP))     //mySingle Login Time Check ( 8시간 경과시 "1" 리턴 )
                {
                    EPUserInfo.Add("TIMEOUT", "1");
                    //EPUserInfo = null;
                }
                else
                {
                    EPUserInfo.Add("TIMEOUT", "0");
                }

                return EPUserInfo;
            }
            catch (Exception ex)
            {
                throw ex; // Exception 처리 Logic 추가
            }
        }

        private static bool InspectEPTrayData(Hashtable EPUserInfo, string clientIPAddress)
        {
            const string _EP_LOGINIP = "EP_LOGINIP";
            const string _EP_LOGINTIMEFORMIS = "EP_LOGINTIMEFORMIS";
            // EP 로그인 정보의 최대 허용 시간
            const int _DEADLINE = 8;

            try
            {
                if (EPUserInfo != null
                    && EPUserInfo.ContainsKey(_EP_LOGINIP)
                    && EPUserInfo.ContainsKey(_EP_LOGINTIMEFORMIS)
                    && EPUserInfo[_EP_LOGINTIMEFORMIS].ToString().Length == 14)
                {
                    // EP Login IP 검사
                    string EP_LOGINIP = EPUserInfo[_EP_LOGINIP].ToString();

                    if (!clientIPAddress.Equals(EP_LOGINIP))
                    {
                        //StringBuilder message = new StringBuilder();
                        //message.AppendLine("mySingle 접속 IP 주소가 다릅니다.");
                        //message.AppendFormat("mySingle 접속 IP 주소: {0}", EP_LOGINIP);
                        //throw new ApplicationException(message.ToString());
                        return false;
                    }

                    // EP Login Time 검사
                    string EP_LOGINTIMEFORMIS = EPUserInfo[_EP_LOGINTIMEFORMIS].ToString();

                    int year = Convert.ToInt16(EP_LOGINTIMEFORMIS.Substring(0, 4));
                    int month = Convert.ToInt16(EP_LOGINTIMEFORMIS.Substring(4, 2));
                    int day = Convert.ToInt16(EP_LOGINTIMEFORMIS.Substring(6, 2));
                    int hour = Convert.ToInt16(EP_LOGINTIMEFORMIS.Substring(8, 2));
                    int minute = Convert.ToInt16(EP_LOGINTIMEFORMIS.Substring(10, 2));
                    int second = Convert.ToInt16(EP_LOGINTIMEFORMIS.Substring(12, 2));

                    DateTime loginTime = new DateTime(year, month, day, hour, minute, second);
                    TimeSpan elapsedTime = DateTime.UtcNow - loginTime; //싱글은 Utc 시간기준 ???

                    if (elapsedTime.TotalHours > _DEADLINE)
                    {
                        //StringBuilder message = new StringBuilder();
                        //message.AppendLine("mySingle 접속 시간이 허용 범위를 초과했습니다.");
                        //message.AppendFormat("mySingle 접속 경과 시간: {0}", elapsedTime.TotalHours.ToString());
                        //throw new ApplicationException(message.ToString());
                        return false;
                    }

                    return true;
                }
                else
                {
                    //throw new ApplicationException("mySingle 인증 정보가 올바르지 않습니다.");
                    return false;
                }
            }

            catch (ApplicationException appEx)
            {
                throw appEx;
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }


        private static string Encode(string password)
        {
            string EncodePass = string.Empty;

            EncodePass = password;

            int i, j, m;
            char[] Ls_len = new char[3];
            char[] Ls_len1 = new char[2];
            char[] Ls_pass = new char[20];
            char[] Ls_passwd01 = new char[21];


            if (password == "INIT00")
            {
                return password;
            }

            int k = 1;
            int[] Li_random = new int[20];
            char[] Ls_origin = new char[20];


            //strncpy(Ls_passwd01,Ls_passwd,20);

            for (i = 0; i < password.Length; i++)
            {
                Ls_passwd01[i] = Convert.ToChar(password.Substring(i, 1));
            }

            for (m = 0; m < 20; m++)
            {
                Ls_pass[m] = Ls_passwd01[m];
            }

            i = password.Length;

            if (i < 10)
            {
                Ls_len[0] = '0';
                Ls_len[1] = Convert.ToChar(i.ToString());
            }
            else
            {
                Ls_len[0] = Convert.ToChar(i.ToString().Substring(0, 1));
                Ls_len[1] = Convert.ToChar(i.ToString().Substring(1, 1));
            }

            Ls_len[2] = '\0';

            Li_random[0] = 42;
            Li_random[1] = 108;
            Li_random[2] = 215;
            Li_random[3] = 236;
            Li_random[4] = 45;
            Li_random[5] = 170;
            Li_random[6] = 4;
            Li_random[7] = 34;
            Li_random[8] = 188;
            Li_random[9] = 240;
            Li_random[10] = 96;
            Li_random[11] = 96;
            Li_random[12] = 77;
            Li_random[13] = 253;
            Li_random[14] = 17;
            Li_random[15] = 237;
            Li_random[16] = 191;
            Li_random[17] = 213;
            Li_random[18] = 238;
            Li_random[19] = 82;

            for (j = 0; j < 20; j++)
            {
                Ls_origin[j] = (char)Li_random[j];
            }

            Ls_origin[10] = (char)((int)Ls_len[0] + 1);
            Ls_origin[1] = (char)((int)Ls_len[1] + 1);

            if (k <= i)
            {
                Ls_origin[8] = (char)((int)Ls_pass[0] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[5] = (char)((int)Ls_pass[1] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[12] = (char)((int)Ls_pass[2] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[6] = (char)((int)Ls_pass[3] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[4] = (char)((int)Ls_pass[4] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[18] = (char)((int)Ls_pass[5] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[0] = (char)((int)Ls_pass[6] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[13] = (char)((int)Ls_pass[7] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[19] = (char)((int)Ls_pass[8] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[2] = (char)((int)Ls_pass[9] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[17] = (char)((int)Ls_pass[10] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[9] = (char)((int)Ls_pass[11] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[11] = (char)((int)Ls_pass[12] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[3] = (char)((int)Ls_pass[13] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[14] = (char)((int)Ls_pass[14] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[16] = (char)((int)Ls_pass[15] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[7] = (char)((int)Ls_pass[16] + 3);
                k++;
            }
            if (k <= i)
            {
                Ls_origin[15] = (char)((int)Ls_pass[17] + 3);
            }

            EncodePass = string.Empty;

            for (i = 0; i < Ls_origin.Length; i++)
            {
                EncodePass = EncodePass + Ls_origin[i].ToString();
            }

            return EncodePass;
        }

        private static string Decode(string password)
        {

            int i, Li_len;
            int[] Li_asc = new int[20];
            char[] Lc_asc = new char[20];
            char[] Ls_passwd = new char[20];


            int k = 1;

            int itemp_1, itemp_2, itemp_3, itemp_4, itemp_5, itemp_6, itemp_7, itemp_8, itemp_9, itemp_10
               , itemp_11, itemp_12, itemp_13, itemp_14, itemp_15, itemp_16, itemp_17, itemp_18, itemp_19, itemp_20;

            char[] Ls_temp = new char[2];


            for (i = 0; i < 20; i++)
            {
                Lc_asc[i] = password[i];
            }

            itemp_1 = Lc_asc[0];
            itemp_2 = Lc_asc[1];
            itemp_3 = Lc_asc[2];
            itemp_4 = Lc_asc[3];
            itemp_5 = Lc_asc[4];
            itemp_6 = Lc_asc[5];
            itemp_7 = Lc_asc[6];
            itemp_8 = Lc_asc[7];
            itemp_9 = Lc_asc[8];
            itemp_10 = Lc_asc[9];
            itemp_11 = Lc_asc[10];
            itemp_12 = Lc_asc[11];
            itemp_13 = Lc_asc[12];
            itemp_14 = Lc_asc[13];
            itemp_15 = Lc_asc[14];
            itemp_16 = Lc_asc[15];
            itemp_17 = Lc_asc[16];
            itemp_18 = Lc_asc[17];
            itemp_19 = Lc_asc[18];
            itemp_20 = Lc_asc[19];


            Ls_temp[0] = Convert.ToChar(itemp_11 - 1);
            Ls_temp[1] = Convert.ToChar(itemp_2 - 1);
            Li_len = Convert.ToInt32(Ls_temp[0].ToString() + Ls_temp[1].ToString());

            if (k <= Li_len)
            {
                Ls_passwd[0] = Convert.ToChar(itemp_9 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[1] = Convert.ToChar(itemp_6 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[2] = Convert.ToChar(itemp_13 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[3] = Convert.ToChar(itemp_7 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[4] = Convert.ToChar(itemp_5 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[5] = Convert.ToChar(itemp_19 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[6] = Convert.ToChar(itemp_1 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[7] = Convert.ToChar(itemp_14 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[8] = Convert.ToChar(itemp_20 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[9] = Convert.ToChar(itemp_3 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[10] = Convert.ToChar(itemp_18 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[11] = Convert.ToChar(itemp_10 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[12] = Convert.ToChar(itemp_12 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[13] = Convert.ToChar(itemp_4 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[14] = Convert.ToChar(itemp_15 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[15] = Convert.ToChar(itemp_17 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[16] = Convert.ToChar(itemp_8 - 3);
                k++;
            }
            if (k <= Li_len)
            {
                Ls_passwd[17] = Convert.ToChar(itemp_16 - 3);
            }

            Ls_passwd[Li_len] = '\0';

            password = string.Empty;

            for (i = 0; i < Ls_passwd.Length; i++)
            {
                password = password + Ls_passwd[i];
            }

            password = password.Replace('\0', ' ').TrimEnd();

            return password;
        }


    }
}
