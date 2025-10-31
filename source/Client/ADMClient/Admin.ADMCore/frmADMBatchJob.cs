using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Miracom.UI;
using Miracom.CliFrx;
using Miracom.MESCore;
using Miracom.TRSCore;
using Admin.COMCore;

//-----------------------------------------------------------------------------
//
//   System      : ADMIN
//   File Name   : frmADMBatchJob.vb
//   Description : ADMIN register batch process in system
//
//   ADMIN Version : 4.0.0
//
//   Function List
//       - CheckCondition() : Check valid date
//       - ViewExeList() : View all process for batch job
//       - ViewBatchList() : View all process registered as batch job in the system
//       - RegisterJob() : Register batch job

//
//   Detail Description
//       -
//
//    History
//    Seq   Date        Developer      Description
//    ---------------------------------------------------------------------------
//    1     2008/12/17  James Kwon     Create
//
//
//   Copyright(C) 1998-2005 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

namespace Admin.ADMCore
{
    public partial class frmADMBatchJob : Miracom.MESCore.SetupForm02
    {
        #region "Variable Definition"

        private bool bLoadFlag = false;
        private char sOSType = 'L';
        private string sCurDir;

        #endregion

        #region "Function Definition"

        // ViewBinaryName()
        //       - View All Binary Name for Batch Job
        // Return Value
        //       - boolean : True / False
        // Arguments
        //		- ByVal c_step As String					: 처리 Process Step
        //		- ByVal directory_name As String			: Directory name included binary image (Option)
        //
        private bool ViewFileName(char c_step, string directory_name)
        {
            ListViewItem itmX;
            int Image_idx;
            int i;

            TRSNode in_node = new TRSNode("VIEW_FILE_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_FILE_LIST_OUT");

            Image_idx = (int)SMALLICON_INDEX.IDX_CODE_DATA;

            lisDirectory.Items.Clear();
            lisBinary.Items.Clear();

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = c_step;
            in_node.AddString("DIRECTORY_NAME", directory_name);
            in_node.AddString("NEXT_FILE_NAME", "");

            if (MPCR.CallService("ADM", "ADM_View_Directory_List", in_node, ref out_node, false) == false)
            {
                return false;
            }

            sCurDir = out_node.GetString("CUR_DIRECTORY");
            txtDrive.Text = out_node.GetString("CUR_DIRECTORY");

            sOSType = out_node.GetChar("OS_TYPE");

            for (i = 0; i < out_node.GetList("DIR_LIST").Count; i++)
            {
                itmX = new ListViewItem(MPCF.Trim(out_node.GetList("DIR_LIST")[i].GetString("FILE_NAME")), Image_idx);

                lisDirectory.Items.Add(itmX);
            }

            for (i = 0; i < out_node.GetList("FILE_LIST").Count; i++)
            {
                itmX = new ListViewItem(MPCF.Trim(out_node.GetList("FILE_LIST")[i].GetString("FILE_NAME")), Image_idx);
                itmX.SubItems.Add(MPCF.Trim(out_node.GetList("FILE_LIST")[i].GetInt("FILE_SIZE").ToString()));

                lisBinary.Items.Add(itmX);
            }

            return true;
        }

        // ViewBatchJob()
        //       - View All Batch Job
        // Return Value
        //       - boolean : True / False
        // Arguments
        //		- ByVal c_step As String					: 처리 Process Step
        //
        private bool ViewBatchJob(char c_step)
        {
            ListViewItem itmX;
            int iDataCnt = 0;
            int i;
            int Image_idx;

            TRSNode in_node = new TRSNode("VIEW_BATCHJOB_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_BATCHJOB_LIST_OUT");

            Image_idx = (int)SMALLICON_INDEX.IDX_CODE_DATA;

            lisBatchJob.Items.Clear();

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = c_step;
            in_node.AddString("NEXT_JOB_NAME", "");

            if (MPCR.CallService("ADM", "ADM_View_Batchjob_List", in_node, ref out_node, false) == false)
            {
                return false;
            }

            for (i = 0; i < out_node.GetList(0).Count; i++)
            {
                if (sOSType == 'W')
                {
                    itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("COMMAND")), Image_idx);
                    itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("JOBNAME")));
                    itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("SCHEDULE")));
                    itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RUNUSER")));

                    lisBatchJob.Items.Add(itmX);
                }
                else
                {
                    itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("COMMAND")), Image_idx);
                    itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("MIN")) + " " + MPCF.Trim(out_node.GetList(0)[i].GetString("HOUR")) + " " + MPCF.Trim(out_node.GetList(0)[i].GetString("DAY")) + " " + MPCF.Trim(out_node.GetList(0)[i].GetString("MONTH")) + " " + MPCF.Trim(out_node.GetList(0)[i].GetString("WEEK")));
                    itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("MIN")));
                    itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("HOUR")));
                    itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("DAY")));
                    itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("MONTH")));
                    itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("WEEK")));

                    lisBatchJob.Items.Add(itmX);
                }
            }

            iDataCnt += out_node.GetList(0).Count;

            return true;
        }

        // Update_Batch_Job()
        //       - Update Batch Job Information
        // Return Value
        //       - boolean : True / False
        // Arguments
        //		- ByVal c_step As String					: 처리 Process Step
        //
        private bool Update_Batch_Job(char c_step)
        {
            TRSNode in_node = new TRSNode("UPDATE_BATCHJOB_IN");
            TRSNode out_node = new TRSNode("UPDATE_BATCHJOB_OUT");
            TRSNode job_item;

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = c_step;

            if (sOSType == 'W')
            {
                in_node.AddString("TASKNAME", MPCF.Trim(txtJobName.Text));
                in_node.AddString("RUNIMAGE", MPCF.Trim(txtBinary.Text));
                in_node.AddString("RUNUSER", MPCF.Trim(txtUser.Text));
                in_node.AddString("RUNPSW", MPCF.Trim(txtPassword.Text));

                in_node.AddString("MIN", MPCF.Trim(txtMin.Text));
                in_node.AddString("HOUR", MPCF.Trim(txtHour.Text));
                in_node.AddString("DAY", MPCF.Trim(txtDayMonth.Text));
                in_node.AddString("MONTH", MPCF.Trim(txtMonth.Text));
                in_node.AddString("WEEK", MPCF.Trim(txtDayWeek.Text));

                in_node.AddString("STARTTIME", dtpStart.Value.ToString("HH:mm"));
            }
            else
            {
                if (MPCF.Trim(txtMin.Text) == "")
                    txtMin.Text = "*";

                if (MPCF.Trim(txtHour.Text) == "")
                    txtHour.Text = "*";

                if (MPCF.Trim(txtDayMonth.Text) == "")
                    txtDayMonth.Text = "*";

                if (MPCF.Trim(txtMonth.Text) == "")
                    txtMonth.Text = "*";

                if (MPCF.Trim(txtDayWeek.Text) == "")
                    txtDayWeek.Text = "*";

                if (c_step == MPGC.MP_STEP_UPDATE || c_step == MPGC.MP_STEP_DELETE)
                {
                    lisBatchJob.Items.Remove(lisBatchJob.SelectedItems[0]);
                }

                for (int i = 0; i < lisBatchJob.Items.Count; i++)
                {
                    job_item = in_node.AddNode("JOB_LIST");

                    job_item.AddString("JOBNAME", lisBatchJob.Items[i].SubItems[1].Text + " " + lisBatchJob.Items[i].SubItems[0].Text);
                }

                if (c_step != MPGC.MP_STEP_DELETE)
                {
                    job_item = in_node.AddNode("JOB_LIST");

                    job_item.AddString("JOBNAME", MPCF.Trim(txtMin.Text) + " " + MPCF.Trim(txtHour.Text) + " " + MPCF.Trim(txtDayMonth.Text) + " " + MPCF.Trim(txtMonth.Text) + " " + MPCF.Trim(txtDayWeek.Text) + " " + MPCF.Trim(txtBinary.Text));
                }
            }

            if (MPCR.CallService("ADM", "ADM_Update_BatchJob", in_node, ref out_node, false) == false)
            {
                return false;
            }

            MPCR.ShowSuccessMsg(out_node);

            return true;
        }

        //
        // SetBatchJobList()
        //       - Set Column in Batch Job List
        // Return Value
        //       -
        // Arguments
        //		- char  OSType : Type of Server OS  ('W' - Windows,   'L' - Linux/Unix)
        //
        private void SetBatchJobList(char OSType)
        {
            lisBatchJob.Columns.Clear();

            if (OSType == 'W')
            {
                lisBatchJob.Columns.Add("COMMAND", 300);
                lisBatchJob.Columns.Add("JOBNAME", 70);
                lisBatchJob.Columns.Add("SCHEDULE", 300);
                lisBatchJob.Columns.Add("RUNUSER", 70);
            }
            else
            {
                lisBatchJob.Columns.Add("COMMAND", 300);
                lisBatchJob.Columns.Add("SCHEDULE", 300);
                lisBatchJob.Columns.Add("MIN", 1);
                lisBatchJob.Columns.Add("HOUR", 1);
                lisBatchJob.Columns.Add("DAY", 1);
                lisBatchJob.Columns.Add("MONTH", 1);
                lisBatchJob.Columns.Add("WEEK", 1);
            }

            return;
        }

        // CheckCondition()
        //       -   Check update factory condition
        // Return Value
        //       -
        // Arguments
        //       -
        private bool CheckCondition(string sFunc)
        {
            int i_min = 0;
            int i_hour = 0;
            int i_day = 0;
            int i_month = 0;
            int i_week = 0;

            if (MPCF.CheckValue(txtBinary, 1) == false)
            {
                return false;
            }

            switch (sFunc)
            {
                case "I":
                    if (txtJobName.Visible == true)
                    {
                        if (txtJobName.Text.Trim() == "")
                        {
                            txtJobName.Text = "";
                            MPCF.ShowMsgBox(MPCF.GetMessage(107));
                            txtJobName.Focus();
                            return false;
                        }
                    }

                    if (txtUser.Visible == true)
                    {
                        if (txtUser.Text.Trim() == "")
                        {
                            txtUser.Text = "";
                            MPCF.ShowMsgBox(MPCF.GetMessage(107));
                            txtUser.Focus();
                            return false;
                        }
                    }

                    if (txtPassword.Visible == true)
                    {
                        if (txtPassword.Text.Trim() == "")
                        {
                            txtPassword.Text = "";
                            MPCF.ShowMsgBox(MPCF.GetMessage(107));
                            txtPassword.Focus();
                            return false;
                        }
                    }

                    if (sOSType == 'W')
                    {
                        if (txtMin.Text.Trim() != "" && txtMin.Text.Trim() != "*")
                            i_min = 1;

                        if (txtHour.Text.Trim() != "" && txtHour.Text.Trim() != "*")
                            i_hour = 1;

                        if (txtDayMonth.Text.Trim() != "" && txtDayMonth.Text.Trim() != "*")
                            i_day = 1;

                        if (txtMonth.Text.Trim() != "" && txtMonth.Text.Trim() != "*")
                            i_month = 1;

                        if (txtDayWeek.Text.Trim() != "" && txtDayWeek.Text.Trim() != "*")
                            i_week = 1;

                        if (i_min + i_hour + i_day + i_month + i_week == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(107));
                            txtMin.Focus();
                            return false;
                        }

                        if (i_min + i_hour + i_day + i_month + i_week > 1)
                        {
                            txtMin.Text = "";
                            txtHour.Text = "";
                            txtDayMonth.Text = "";
                            txtMonth.Text = "";
                            txtDayWeek.Text = "";

                            MPCF.ShowMsgBox(MPCF.GetMessage(111));
                            txtMin.Focus();

                            return false;
                        }
                    }
                    else
                    {
                        if (txtMin.Text.Trim() == "" && txtHour.Text.Trim() == "" && txtDayMonth.Text.Trim() == "" && txtMonth.Text.Trim() == "" && txtDayWeek.Text.Trim() == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(107));
                            txtMin.Focus();
                            return false;
                        }
                    }

                    break;


                case "U":
                    if (txtJobName.Visible == true)
                    {
                        if (txtJobName.Text.Trim() == "")
                        {
                            txtJobName.Text = "";
                            MPCF.ShowMsgBox(MPCF.GetMessage(107));
                            txtJobName.Focus();
                            return false;
                        }
                    }

                    if (txtUser.Visible == true)
                    {
                        if (txtUser.Text.Trim() == "")
                        {
                            txtUser.Text = "";
                            MPCF.ShowMsgBox(MPCF.GetMessage(107));
                            txtUser.Focus();
                            return false;
                        }
                    }

                    if (txtPassword.Visible == true)
                    {
                        if (txtPassword.Text.Trim() == "")
                        {
                            txtPassword.Text = "";
                            MPCF.ShowMsgBox(MPCF.GetMessage(107));
                            txtPassword.Focus();
                            return false;
                        }
                    }

                    if (sOSType == 'W')
                    {
                        if (txtMin.Text.Trim() != "" && txtMin.Text.Trim() != "*")
                            i_min = 1;

                        if (txtHour.Text.Trim() != "" && txtHour.Text.Trim() != "*")
                            i_hour = 1;

                        if (txtDayMonth.Text.Trim() != "" && txtDayMonth.Text.Trim() != "*")
                            i_day = 1;

                        if (txtMonth.Text.Trim() != "" && txtMonth.Text.Trim() != "*")
                            i_month = 1;

                        if (txtDayWeek.Text.Trim() != "" && txtDayWeek.Text.Trim() != "*")
                            i_week = 1;

                        if (i_min + i_hour + i_day + i_month + i_week == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(107));
                            txtMin.Focus();
                            return false;
                        }

                        if (i_min + i_hour + i_day + i_month + i_week > 1)
                        {
                            txtMin.Text = "";
                            txtHour.Text = "";
                            txtDayMonth.Text = "";
                            txtMonth.Text = "";
                            txtDayWeek.Text = "";

                            MPCF.ShowMsgBox(MPCF.GetMessage(111));
                            txtMin.Focus();

                            return false;
                        }
                    }
                    else
                    {
                        if (txtMin.Text.Trim() == "" && txtHour.Text.Trim() == "" && txtDayMonth.Text.Trim() == "" && txtMonth.Text.Trim() == "" && txtDayWeek.Text.Trim() == "")
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(107));
                            txtMin.Focus();
                            return false;
                        }
                    }

                    break;

                case "D":

                    break;

            }

            return true;

        }

        #endregion

        public frmADMBatchJob()
        {
            InitializeComponent();
        }

        private void frmADMBatchJob_Load(object sender, EventArgs e)
        {
            try
            {
                MPCF.ToClientLanguage(this);

                MPCF.InitListView(lisBinary);
                MPCF.InitListView(lisBatchJob);
                MPCF.InitListView(lisDirectory);
                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmADMBatchJob_Activated(object sender, EventArgs e)
        {
            try
            {
                if (bLoadFlag == false)
                {
                    if (ViewFileName('1', "") == false)
                    {
                        return;
                    }
                    else
                    {
                        SetBatchJobList(sOSType);

                        if (sOSType == 'W')
                        {
                            grpBatchJob.Height = 359;

                            lblJobName.Visible = true;
                            txtJobName.Visible = true;
                            txtJobName.Text = "";
                            lblUser.Visible = true;
                            txtUser.Visible = true;
                            txtUser.Text = "";
                            lblPassword.Visible = true;
                            txtPassword.Visible = true;
                            txtPassword.Text = "";
                            lblStartTime.Visible = true;
                            dtpStart.Visible = true;
                        }
                        else
                        {
                            grpBatchJob.Height = 415;

                            lblJobName.Visible = false;
                            txtJobName.Visible = false;
                            txtJobName.Text = "";
                            lblUser.Visible = false;
                            txtUser.Visible = false;
                            txtUser.Text = "";
                            lblPassword.Visible = false;
                            txtPassword.Visible = false;
                            txtPassword.Text = "";
                            lblStartTime.Visible = false;
                            dtpStart.Visible = false;
                        }
                    }

                    if (ViewBatchJob('1') == false)
                        return;

                    bLoadFlag = true;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void lisBinary_Click(object sender, EventArgs e)
        {
            if (lisBinary.SelectedItems.Count > 0)
            {
                if(sOSType == 'W')
                    txtBinary.Text = txtDrive.Text + "\\" + lisBinary.SelectedItems[0].Text;
                else
                    txtBinary.Text = txtDrive.Text + "/" + lisBinary.SelectedItems[0].Text;
            }
        }

        private void lisBatchJob_Click(object sender, EventArgs e)
        {
            if (lisBatchJob.SelectedItems.Count > 0)
            {
                if (sOSType == 'W')
                {
                    txtBinary.Text = lisBatchJob.SelectedItems[0].Text;
                    txtJobName.Text = lisBatchJob.SelectedItems[0].SubItems[1].Text;
                    txtUser.Text = lisBatchJob.SelectedItems[0].SubItems[3].Text;
                    txtPassword.Text = "";
                }
                else
                {
                    txtBinary.Text = lisBatchJob.SelectedItems[0].Text;
                    txtMin.Text = lisBatchJob.SelectedItems[0].SubItems[2].Text;
                    txtHour.Text = lisBatchJob.SelectedItems[0].SubItems[3].Text;
                    txtDayMonth.Text = lisBatchJob.SelectedItems[0].SubItems[4].Text;
                    txtMonth.Text = lisBatchJob.SelectedItems[0].SubItems[5].Text;
                    txtDayWeek.Text = lisBatchJob.SelectedItems[0].SubItems[6].Text;
                }
            }
        }

        private void btnCreate_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(MPGC.MP_STEP_CREATE.ToString()) == true)
                {
                    if (Update_Batch_Job(MPGC.MP_STEP_CREATE) == false)
                    {
                        return;
                    }

                    MPCF.ShowMsgBox(MPCF.GetMessage(52));

                    ViewBatchJob('1');
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(MPGC.MP_STEP_CREATE.ToString()) == true)
                {
                    if (Update_Batch_Job(MPGC.MP_STEP_UPDATE) == false)
                    {
                        return;
                    }

                    MPCF.ShowMsgBox(MPCF.GetMessage(52));

                    ViewBatchJob('1');
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.ShowMsgBox(MPCF.GetMessage(54), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                {
                    return;
                }

                if (CheckCondition(MPGC.MP_STEP_DELETE.ToString()) == true)
                {
                    if (Update_Batch_Job(MPGC.MP_STEP_DELETE) == false)
                    {
                        return;
                    }
                    MPCF.ShowMsgBox(MPCF.GetMessage(52)); ;

                    ViewBatchJob('1');
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void lisDirectory_DoubleClick(object sender, EventArgs e)
        {
            string sDirectory = string.Empty;

            if (lisDirectory.Items.Count <= 0)
                return;

            if (lisDirectory.SelectedItems.Count <= 0)
                return;

            if (sOSType == 'W')
            {
                if (lisDirectory.SelectedItems[0].Text == "..")
                {
                    sDirectory = sCurDir + "\\..\\";
                }
                else
                {
                    sDirectory = sCurDir + "\\" + lisDirectory.SelectedItems[0].Text;
                }
            }
            else
            {
                if (lisDirectory.SelectedItems[0].Text == "..")
                {
                    sDirectory = sCurDir + "//..//";
                }
                else
                {
                    sDirectory = sCurDir + "//" + lisDirectory.SelectedItems[0].Text;
                }
            }

            if (ViewFileName('1', sDirectory) == false)
            {
                return;
            }
        }

        private void txtDrive_KeyPress(object sender, KeyPressEventArgs e)
        {
            string tmpDir;

            try
            {
                if (e.KeyChar != (char)13)
                    return;

                if (MPCF.Trim(txtDrive.Text) == "")
                    return;

                tmpDir = MPCF.Trim(txtDrive.Text);

                if (sOSType == 'W')
                {
                    if (tmpDir[tmpDir.Length - 1] != '\\')
                        tmpDir = tmpDir + "\\";
                }
                else
                {
                    if (tmpDir[tmpDir.Length - 1] != '/')
                        tmpDir = tmpDir + "//";
                }

                if (ViewFileName('1', tmpDir) == false)
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}