using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using com.miracom.transceiverx;
using com.miracom.transceiverx.session;
using com.miracom.transceiverx.message;

namespace RPTServer
{
    public partial class frmH101Svr : Form
    {
        public frmH101Svr()
        {
            InitializeComponent();

            _SetWorkCountDelegate = new SetWorkCountDelegate(IncreaseWorkCount);
            _SetWorkProcessDelegate = new SetWorkProcessDelegate(SetWorkProcess);
            _SetMessageDelegate = new SetMessageDelegate(WriteMessage);
            _SetProcessTimeDelegate = new SetProcessTimeDelegate(SetProcessTime);
            _SetViewIDDelegate = new SetViewIDDelegate(WriteViewID);
        }

        #region " Constant Definition "



        #endregion


        #region " Variable Definition "

        private h101stub h101 = null;
        private int iPrevFormHeight = 0;
        private int iOrigFormWidth = 0;
        private int iOrigFormHeight = 0;

        #endregion


        #region " Properties "

        public h101stub h101Stub
        {
            get
            {
                try
                {
                    return h101;
                }
                catch (Exception)
                {
                    return null;
                }
                finally
                {

                }
            }
        }

        #endregion


        #region " Function Definition "

        delegate void SetWorkCountDelegate();
        delegate void SetWorkProcessDelegate(int proc_step);
        delegate void SetMessageDelegate(string sMsg);
        delegate void SetProcessTimeDelegate(TimeSpan tSpan);
        delegate void SetViewIDDelegate(string sMsg);

        private SetWorkCountDelegate _SetWorkCountDelegate;
        private SetWorkProcessDelegate _SetWorkProcessDelegate;
        private SetMessageDelegate _SetMessageDelegate;
        private SetProcessTimeDelegate _SetProcessTimeDelegate;
        private SetViewIDDelegate _SetViewIDDelegate;

        private bool InitH101()
        {
            string sSessionID = string.Empty;
            string sH101ConnectionString = string.Empty;
            //string sChannel = string.Empty;
            int iSesstionMode;

            try
            {
                h101 = new h101stub();

                sSessionID = RSGV.gsServerName + "_" + RSGV.gsProcessNo;
                sH101ConnectionString = RSGV.gsRemoteAddress + ":10101";

                if (RSGV.gsSessionMode == "INNER")
                    iSesstionMode = Session_Fields.SESSION_INNER_STATION_MODE;
                else if (RSGV.gsSessionMode == "INTER")
                    iSesstionMode = Session_Fields.SESSION_INTER_STATION_MODE;
                else
                    iSesstionMode = Session_Fields.SESSION_INNER_STATION_MODE;

                if (h101.init(sSessionID, iSesstionMode, sH101ConnectionString, 10104) == false)
                {
                    MessageBox.Show(h101stub.StatusMessage);
                    return false;
                }

                RSGV.gsChannel = "/" + RSGV.gsSiteID + "/" + RSGV.gsProcessName;

                h101.registerDispatcher("RPTBAS", new clsRPTBASCallback(this));
                h101.tune(RSGV.gsChannel, false, false);
            }
            catch (Exception ex)
            {
                MessageBox.Show("H101 Connection Failed. " + ex.Message);
                return false;
            }

            return true;
        }

        private void SetLocation()
        {
            System.Drawing.Rectangle rcScreen;
            int iRowCount = 0;
            int iColCount = 0;
            int iPos = 0;
            int iLeft = 0;
            int iTop = 0;
            double d_result;

            try
            {
                rcScreen = SystemInformation.WorkingArea;
                d_result = rcScreen.Width / this.Width;
                iColCount = (int)Math.Floor(d_result);
                d_result = rcScreen.Height / this.Height;
                iRowCount = (int)Math.Floor(d_result);
                if (System.Convert.ToInt32(RSGV.gsProcessNo) == 0)
                {
                    iPos = 1;
                }
                else
                {
                    iPos = (System.Convert.ToInt32(RSGV.gsProcessNo) - 1) % (iRowCount * iColCount);
                }

                iLeft = (iPos % iColCount) * this.Width;
                d_result = iPos / iColCount;
                iTop = (int)Math.Floor(d_result) * this.Height;

                this.Location = new Point(iLeft, iTop);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
        }

        public void SetWorkProcess(int proc_step)
        {
            if (proc_step == 0)
            {
                lblProcessStatus.BackColor = System.Drawing.Color.FromArgb(255, 192, 192);
            }
            else if (proc_step == 1)
            {
                lblProcessStatus.BackColor = System.Drawing.Color.FromArgb(192, 255, 192);
            }
        }

        private void IncreaseWorkCount()
        {
            lblTranCount.Text = (RSCF.ToInt(lblTranCount.Text) + 1).ToString();
        }

        public void SetWorkCountEvent()
        {
            IAsyncResult r = BeginInvoke(_SetWorkCountDelegate);
            EndInvoke(r);
        }

        public void SetWorkProcessEvent(int proc_step)
        {
            IAsyncResult r = BeginInvoke(_SetWorkProcessDelegate, new object[] { proc_step });
            EndInvoke(r);
        }

        public void SetMessageEvent(string sMsg)
        {
            IAsyncResult r = BeginInvoke(_SetMessageDelegate, new object[] { sMsg });
            EndInvoke(r);
        }

        public void SetProcessTimeEvent(TimeSpan tSpan)
        {
            IAsyncResult r = BeginInvoke(_SetProcessTimeDelegate, new object[] { tSpan });
            EndInvoke(r);
        }

        public void SetViewIDEvent(string sMsg)
        {
            IAsyncResult r = BeginInvoke(_SetViewIDDelegate, new object[] { sMsg });
            EndInvoke(r);
        }

        private void WriteMessage(string sMsg)
        {
            string sNowTime = null;
            DateTime NowTime = DateTime.Now;

            sNowTime = NowTime.ToString("HH:mm:ss");

            sMsg = sMsg.ToUpper();
            if (btnShort.Visible == true)
            {
                if (txtMessage.Text.Length > 3000)
                {
                    txtMessage.Text = "[ " + sNowTime + " ] " + sMsg + "\r\n" + txtMessage.Text.Substring(0, 2500);
                }
                else
                {
                    txtMessage.Text = "[ " + sNowTime + " ] " + sMsg + "\r\n" + txtMessage.Text;
                }
            }
        }

        private void WriteViewID(string sMsg)
        {
            StringBuilder sbMsg = new StringBuilder();
            if (btnShort.Visible == true)
            {
                for (int i = 0; i < txtMessage.Lines.Length; i++)
                {
                    if (i == 0)
                        sbMsg.AppendLine(txtMessage.Lines[i] + " : " + sMsg);
                    else
                        sbMsg.AppendLine(txtMessage.Lines[i]);
                }

                txtMessage.Text = sbMsg.ToString();
            }
        }

        private void SetProcessTime(TimeSpan tSpan)
        {
            lblDiffTime.Text = tSpan.Seconds + "." + tSpan.Milliseconds.ToString("000#");
        }

        
        #endregion


        #region " Form Event Definition "

        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);

            try
            {
                RSGV.gfrmMain = this;

                if (InitH101() == false)
                {
                    MessageBox.Show("H101 Connect Failed.");
                    Application.Exit();
                    return;
                }

                RSGV.gsTitle = RSGV.gsServerName + " - " + RSGV.gsChannel + " " + RSGV.gsProcessNo;

                this.Text = RSGV.gsTitle;

                LOG.AddLog("H101 Connect Success");

                LOG.AddLog("RPTServer Start");

                lblDeviceName.Text = RSGV.gsTitle;

                txtMessage.Text = "Start Process ...";
                txtMessage.Text = "Server Running !!!" + "\r\n" + txtMessage.Text;

                SetLocation();
            }
            catch (Exception)
            {
                throw;
            }
        }

        protected override void OnClosing(CancelEventArgs e)
        {
            base.OnClosing(e);
            try
            {
                DBCF.Disconnect();

                LOG.AddLog("DB Disconnect Success");

                h101.untune(RSGV.gsChannel, false, false);
                h101.term();

                LOG.AddLog("H101 term Success");

                LOG.AddLog("RPTServer Close");
            }
            catch (Exception)
            {
                throw;
            }
        }

        #endregion


        #region " Event Definition "

        private void btnShort_Click(object sender, EventArgs e)
        {
            try
            {
                // Form Size
                System.Drawing.Size TempSize = default(System.Drawing.Size);

                iPrevFormHeight = this.Height;

                TempSize.Height = pnlTop.Height + pnlBottom.Height + 32;
                TempSize.Width = this.Width;

                this.MinimumSize = TempSize;
                this.MaximumSize = TempSize;

                // Form Size
                this.Height = TempSize.Height;

                // Enable/Disable Button
                btnShort.Visible = false;
                btnLong.Visible = true;

                // Unvisible
                pnlFill.Visible = false;

                pnlBottom.Visible = true;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
        }

        private void btnLong_Click(object sender, EventArgs e)
        {
            try
            {
                // Form Size
                System.Drawing.Size TempSize = default(System.Drawing.Size);
                TempSize.Height = iOrigFormHeight;
                TempSize.Width = iOrigFormWidth;
                this.MinimumSize = TempSize;
                TempSize.Height = 0;
                TempSize.Width = 0;
                this.MaximumSize = TempSize;

                // Form Size
                this.Height = iPrevFormHeight;

                // Enable/Disable Button
                btnShort.Visible = true;
                btnLong.Visible = false;

                // Unvisible
                pnlFill.Visible = true;

                pnlBottom.Visible = true;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                txtMessage.Text = "";
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            try
            {
                this.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
        }

        private void chkTop_CheckedChanged(object sender, EventArgs e)
        {
            try
            {
                this.TopMost = chkTop.Checked;
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                return;
            }
        }

        #endregion
    }
}
