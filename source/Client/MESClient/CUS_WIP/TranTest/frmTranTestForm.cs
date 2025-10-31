using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

using System.Net.NetworkInformation;

using FarPoint.Win.Spread;
using Microsoft.VisualBasic.Logging;

namespace CUS_WIP
{
    public partial class frmTranTestForm : CUS_COM.frmTranForm01
    {
        public frmTranTestForm()
        {
            InitializeComponent();
        }

        private void frmTranTestForm_Load(object sender, EventArgs e)
        {

        }




        private  void PingTest(string host,int i)
        {
            try
            {
                using (Ping ping = new Ping())
                {
                  //Console.WriteLine($"{host}에 대해 Ping 테스트를 시작합니다...");

                    // Ping 옵션 설정 (기본 TTL 및 프래그먼트 허용 여부)
                    PingOptions options = new PingOptions
                    {
                        Ttl = 128,
                        DontFragment = true
                    };

                    // 데이터를 보낼 바이트 배열 생성
                    string data = "Ping Test Data";
                    byte[] buffer = System.Text.Encoding.ASCII.GetBytes(data);

                    // Ping 시간 초과 설정 (단위: 밀리초)
                    int timeout = 1000;

                    // Ping 전송 및 결과 받기
                    PingReply reply = ping.Send(host, timeout, buffer, options);

                    // 결과 출력
                    if (reply.Status == IPStatus.Success)
                    {
                        //onsole.WriteLine($"Ping 성공: {reply.Address}");
                        //onsole.WriteLine($"응답 시간: {reply.RoundtripTime}ms");
                        //onsole.WriteLine($"TTL: {reply.Options.Ttl}");

                        spdPackingLotList_Sheet1.Cells[i, 11].Text = "N";
                        spdPackingLotList_Sheet1.Rows[i].ForeColor = Color.Red;
                    
                    }
                    else
                    {
                    
                        spdPackingLotList_Sheet1.Cells[i, 11].Text = "Y";
                        spdPackingLotList_Sheet1.Rows[i].ForeColor = Color.Green;

                        //                      Console.WriteLine($"Ping 실패: {reply.Status}");
                    }
                }
            }
            catch (Exception ex)
            {
                // Console.WriteLine($"오류 발생: {ex.Message}");
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }



        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            SearchData();

        }

        private void SearchData()
        {
            string sIpAdress = "";

            for (int i = 0; i < spdPackingLotList_Sheet1.RowCount; i++)
            {

                sIpAdress = spdPackingLotList_Sheet1.Cells[i, 6].Text.ToString().ToUpper();

                if (string.IsNullOrWhiteSpace(sIpAdress))
                {
                    //  Console.WriteLine("유효한 호스트를 입력하세요.");
                    // return;
                }
                else
                {
                    PingTest(sIpAdress, i);
                }



            }
        }

        private void numRefreshSec_ValueChanged(object sender, EventArgs e)
        {
            if (chkAutoRefresh.Checked == true)
            {
                tmrTimer.Interval = ((int)(numRefreshSec.Value)) * 1000;
                tmrTimer.Start();
            }
        }

        private void chkAutoRefresh_CheckedChanged(object sender, EventArgs e)
        {
            if (chkAutoRefresh.Checked == true)
            {
                tmrTimer.Interval = ((int)(numRefreshSec.Value)) * 1000;
                tmrTimer.Start();
            }
            else
            {
                tmrTimer.Stop();

            }
        }

        private void tmrTimer_Tick(object sender, EventArgs e)
        {
            SearchData();
        }
    }
}
