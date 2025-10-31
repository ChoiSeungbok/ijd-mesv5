using System;
using Miracom.CliFrx;
using Miracom.DNMCore;
using System.Data;
using Miracom.TRSCore;
using Miracom.MESCore;
using System.Security.Cryptography;
using System.IO;
using System.Text;

//20221222 비밀번호 정책 변경후(대소문자특수문자등..및 3개월 변경) ,비번분실및 문의가 많아서, 대응방안으로 비번 저장 기능 개발
//암호화 해서 패스워드 레지스트리에 저장.

namespace CUS_COM
{
    public  class ClsCusCodeWord
    {
      
        private string Key_String = "iljindia";

        #region String을 byte로 단순 변환
        /// <summary>
        /// String을 byte[]로 단순 변환
        /// </summary>
        /// <param name="value"></param>
        /// <returns></returns>

        private byte[] stringToByte(string value)
        {
            Byte[] buffer = new byte[value.Length];

            for (int i = 0; i < value.Length; i++)
            {
                buffer[i] = Convert.ToByte(value.Substring(i, 1));
            }
            return buffer;
        }
        #endregion

        #region 실제로 복호화하는 함수
        // Decrypt the byte array.
        /// <summary>
        /// 복호화 주요 함수
        /// </summary>
        /// <param name="CypherText">해독할 값</param>
        /// <param name="key">키 값</param>
        /// <returns></returns>
        /// 


        private string Encrypt(string toDecrypt)
        {

            try
            {

                // 암호화 알고리즘중 RC2 암호화를 하려면 RC를
                // DES알고리즘을 사용하려면 DESCryptoServiceProvider 객체를 선언한다.
                //RC2 rc2 = new RC2CryptoServiceProvider();
                DESCryptoServiceProvider rc2 = new DESCryptoServiceProvider();

                // 대칭키 배치
                rc2.Key = Encoding.Default.GetBytes(Key_String);
                rc2.IV = Encoding.Default.GetBytes(Key_String);

                // 암호화는 스트림(바이트 배열)을
                // 대칭키에 의존하여 암호화 하기때문에 먼저 메모리 스트림을 생성한다.
                MemoryStream ms = new MemoryStream();

                //만들어진 메모리 스트림을 이용해서 암호화 스트림 생성 
                CryptoStream cryStream =
                                  new CryptoStream(ms, rc2.CreateEncryptor(), CryptoStreamMode.Write);

                // 데이터를 바이트 배열로 변경
                byte[] data = Encoding.UTF8.GetBytes(toDecrypt.ToCharArray());

                // 암호화 스트림에 데이터 씀
                cryStream.Write(data, 0, data.Length);
                cryStream.FlushFinalBlock();

                // 암호화 완료 (string으로 컨버팅해서 반환)
                return Convert.ToBase64String(ms.ToArray());


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return null;
            }
   
        }



        private string Decrypt(string toDecrypt)
        {
            try
            {

                // 암호화 알고리즘중 RC2 암호화를 하려면 RC를
                // DES알고리즘을 사용하려면 DESCryptoServiceProvider 객체를 선언한다.
                //RC2 rc2 = new RC2CryptoServiceProvider();
                DESCryptoServiceProvider rc2 = new DESCryptoServiceProvider();

                // 대칭키 배치
                rc2.Key = Encoding.Default.GetBytes(Key_String);
                rc2.IV = Encoding.Default.GetBytes(Key_String);

                // 암호화는 스트림(바이트 배열)을
                // 대칭키에 의존하여 암호화 하기때문에 먼저 메모리 스트림을 생성한다.
                MemoryStream ms = new MemoryStream();

                //만들어진 메모리 스트림을 이용해서 암호화 스트림 생성 
                CryptoStream cryStream =
                                  new CryptoStream(ms, rc2.CreateDecryptor(), CryptoStreamMode.Write);

                //데이터를 바이트배열로 변경한다.
                byte[] data = Convert.FromBase64String(toDecrypt);

                //변경된 바이트배열을 암호화 한다.
                cryStream.Write(data, 0, data.Length);
                cryStream.FlushFinalBlock();

                //암호화 한 데이터를 스트링으로 변환해서 리턴
                return Encoding.UTF8.GetString(ms.GetBuffer());
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return null;
            }
        }

        #endregion


        #region 암호화 호출함수
        /// <summary>
        /// 실제 암호화 할 때 호출하는 함수
        /// </summary>
        /// <param name="inputvalue"></param>
        /// <returns></returns>
        public string Des_Encrypt(string inputvalue)
        {
            string output;

            output =  Encrypt(inputvalue);

            return output;
        }
        #endregion

        #region 복호화 호출 함수 
        /// <summary>
        /// 복호화를 위한 호출 함수
        /// </summary>
        /// <param name="inputvalue"></param>
        /// <returns></returns>
        public string Des_Dncrypt(string inputvalue)
            {
            string output ="";

            if(inputvalue == "")
            {
                return output;
            }

            output = Decrypt(inputvalue);

            return output;
        }
        #endregion

    }




}
