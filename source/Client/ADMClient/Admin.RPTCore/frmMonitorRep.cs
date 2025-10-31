using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.OleDb;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Reflection.Emit;

using Miracom.CliFrx;

namespace Admin.RPTCore
{
    public partial class frmMonitorRep : BaseForm04
    {
#region "Variables"

        private bool m_load_flag = false;

        // DB
        private clsTableInfo m_table = null;
        private clsDBManager m_db_manager = null;
        private bool m_db_connect_routine = false;

#endregion

        public frmMonitorRep()
        {
            InitializeComponent();
        }

#region "Form Event"

        private void frmMonitorRep_Load(object sender, EventArgs e)
        {
            btnClose.Location = new System.Drawing.Point(628, 7);
        }

        private void frmMonitorRep_Activated(object sender, EventArgs e)
        {
            if (m_load_flag == false)
            {
                return;
            }

            tabColumns.SelectedIndex = 0;
            txtDBName.Focus();

            m_load_flag = true;
        }

        private void btnRefresh_Click(object sender, EventArgs e)
        {
            try
            {
                if (btnRefresh.Text == "Refresh")
                {
                    timeRefresh.Interval = MPCF.ToInt(txtRefreshTime.Text) * 1000;
                    timeRefresh.Enabled = true;
                    btnRefresh.Text = "Stop Refresh";
                }
                else
                {
                    timeRefresh.Enabled = false;
                    btnRefresh.Text = "Refresh";
                }
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnInit_Click(object sender, EventArgs e)
        {
            OleDbCommand adoCommand;
            string tmpTableName;
            string ProcName;
            int iRet, i;

            adoCommand = null;

            try
            {
                if (m_db_manager.get_is_connect() == false)
                    return;

                adoCommand = new OleDbCommand();
                adoCommand.Connection = m_db_manager.get_db_connection();

                for (i = 0; i < lisMonitor.Items.Count; i++)
                {
                    if (lisMonitor.Items[i].Checked == true)
                    {
                        ProcName = lisMonitor.Items[i].Text;

                        switch (ProcName)
                        {
                            case "ATRLoader":
                                tmpTableName = "MTMPATRHIS";
                                break;
                            case "CRRLoader":
                                tmpTableName = "MTMPATRHIS";
                                break;
                            case "RASLoader":
                                tmpTableName = "MTMPATRHIS";
                                break;
                            case "WIPLoader":
                                tmpTableName = "MTMPATRHIS";
                                break;
                            default :
                                tmpTableName = string.Empty;
                                break;
                        }

                        if (tmpTableName == string.Empty)
                            continue;

                        try
                        {
                            adoCommand.CommandText = "UPDATE " + tmpTableName + " SET PROCESS_FLAG = ' ' WHERE PROCESS_FLAG = 'Y'";
                            iRet = adoCommand.ExecuteNonQuery();
                        }
                        catch (Exception ex)
                        {
                            MPCF.ShowMsgBox("TABLE NAME : " + tmpTableName + ex.Message);
                            return;
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            GetAllProcInfo();
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            OleDbCommand adoCommand;
            object obj1 = null;
            string ProcName;
            int iRet, i;

            adoCommand = null;

            try
            {
                if (m_db_manager.get_is_connect() == false)
                    return;

                adoCommand = new OleDbCommand();
                adoCommand.Connection = m_db_manager.get_db_connection();

                for (i = 0; i < lisMonitor.Items.Count; i++)
                {
                    if (lisMonitor.Items[i].Checked == true)
                    {
                        ProcName = lisMonitor.Items[i].Text;

                        try
                        {
                            adoCommand.CommandText = "SELECT COUNT(*) FROM RPRCPRCSTP WHERE PROC_NAME = '" + ProcName + "'";
                            obj1 = adoCommand.ExecuteScalar();

                            iRet = int.Parse(obj1.ToString());
                            if (iRet <= 0)
                            {
                                adoCommand.CommandText = "INSERT INTO RPRCPRCSTP (PROC_NAME, STOP_FLAG) VALUES ('" + ProcName + "', 'Y')";
                            }
                            else
                            {
                                adoCommand.CommandText = "UPDATE RPRCPRCSTP SET STOP_FLAG = 'Y' WHERE PROC_NAME ='" + ProcName + "'";
                            }
                            iRet = adoCommand.ExecuteNonQuery();
                        }
                        catch (Exception ex)
                        {
                            MPCF.ShowMsgBox("Proc Name : " + ProcName + ex.Message);
                            return;
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnConnect_Click(object sender, EventArgs e)
        {
            string data_source;
            string db_name;
            string user_id;
            string password;
            AMGV.DBTYPE db_type = AMGV.DBTYPE.ORACLE;

            m_table = new clsTableInfo();

            try
            {
                if (MPCF.Trim(txtDBName.Text) == "")
                {
                    MPCF.ShowMsgBox("Please input DB Name.", "DB Connect Error", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                    return;
                }

                if (MPCF.Trim(txtUserID.Text) == "")
                {
                    MPCF.ShowMsgBox("Please input User ID.", "DB Connect Error", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                    return;
                }

                if (MPCF.Trim(txtPassword.Text) == "")
                {
                    MPCF.ShowMsgBox("Please input Password.", "DB Connect Error", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                    return;
                }

                data_source = MPCF.Trim(txtDataSource.Text);
                db_name = MPCF.Trim(txtDBName.Text);
                user_id = MPCF.Trim(txtUserID.Text);
                password = MPCF.Trim(txtPassword.Text);

                if (rdoTarMsSql.Checked == true)
                    db_type = AMGV.DBTYPE.MSSQL;
                else if (rdoTarOracle.Checked == true)
                    db_type = AMGV.DBTYPE.ORACLE;
                else if (rdoTarDB2.Checked == true)
                    db_type = AMGV.DBTYPE.DB2;

                m_db_manager = new clsDBManager();

                if (m_db_manager.db_connect(data_source, db_name, user_id, password, "", db_type, AMGV.DB_VIEW_TYPE.TABLE) == false)
                {
                    m_db_connect_routine = false;
                    m_db_manager.dispose();
                    MPCF.ShowMsgBox("Fail to connect DB." + " " +
                                        m_db_manager.get_data_source() + " " +
                                        m_db_manager.get_db_name() + " " +
                                        m_db_manager.get_user_id() + " " +
                                        m_db_manager.get_db_type());
                    return;
                }

                m_db_manager.set_db_view_type(AMGV.DB_VIEW_TYPE.TABLE);
                m_db_connect_routine = true;

                MPCF.ShowMsgBox("Success to connect database." + " " +
                                    m_db_manager.get_data_source() + " " +
                                    m_db_manager.get_db_name() + " " +
                                    m_db_manager.get_user_id() + " " +
                                    m_db_manager.get_db_type());

                tabColumns.TabIndex = 1;

                GetAllProcInfo();
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnDisconnect_Click(object sender, EventArgs e)
        {
            try
            {
                if (m_db_connect_routine == true)
                {
                    m_db_manager.db_disconnect();
                    m_db_connect_routine = false;
                }

                lisMonitor.Items.Clear();
                tabColumns.TabIndex = 0;
                txtDBName.Focus();

                MPCF.ShowMsgBox("Disconnet to database.");
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void tabColumns_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if (tabColumns.SelectedTab == pageConnect)
                {
                    this.txtRefreshTime.Visible = false;
                    this.btnRefresh.Visible = false;
                    this.btnStop.Visible = false;
                    this.btnView.Visible = false;
                    this.btnInit.Visible = false;
                    this.btnConnect.Visible = true;
                    this.btnDisconnect.Visible = true;
                }
                else
                {
                    this.txtRefreshTime.Visible = true;
                    this.btnRefresh.Visible = true;
                    this.btnStop.Visible = true;
                    this.btnView.Visible = true;
                    this.btnInit.Visible = true;
                    this.btnConnect.Visible = false;
                    this.btnDisconnect.Visible = false;
                }
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void timeRefresh_Tick(object sender, EventArgs e)
        {
            GetAllProcInfo();
        }
#endregion

#region "Procedure and Function"

        private bool GetAllProcInfo()
        {
            OleDbCommand adoCommand;
            StringBuilder strQuery = new StringBuilder();
            object obj1 = null;
            ListViewItem item1;
            int iRet;

            try
            {
                //Clear ListView Items
                lisMonitor.Items.Clear();

                tabColumns.SelectedIndex = 1;

                adoCommand = null;

                if (m_db_manager.get_is_connect() == false)
                    return false;

                adoCommand = new OleDbCommand();
                adoCommand.Connection = m_db_manager.get_db_connection();

                // Attribute
                item1 = new ListViewItem("ATRLoader");

                adoCommand.CommandText = "SELECT COUNT(*) FROM MTMPATRHIS";
                obj1 = adoCommand.ExecuteScalar();

                iRet = int.Parse(obj1.ToString());

                item1.SubItems.Add(iRet.ToString());
                lisMonitor.Items.Add(item1);

                // Carrier
                item1 = new ListViewItem("CRRLoader");

                adoCommand.CommandText = "SELECT COUNT(*) FROM MTMPCRRHIS";
                obj1 = adoCommand.ExecuteScalar();

                iRet = int.Parse(obj1.ToString());

                item1.SubItems.Add(iRet.ToString());
                lisMonitor.Items.Add(item1);

                // Resource
                item1 = new ListViewItem("RASLoader");

                adoCommand.CommandText = "SELECT COUNT(*) FROM MTMPRESHIS";
                obj1 = adoCommand.ExecuteScalar();

                iRet = int.Parse(obj1.ToString());

                item1.SubItems.Add(iRet.ToString());
                lisMonitor.Items.Add(item1);

                // WIP
                item1 = new ListViewItem("WIPLoader");

                adoCommand.CommandText = "SELECT COUNT(*) FROM MTMPLOTHIS";
                obj1 = adoCommand.ExecuteScalar();

                iRet = int.Parse(obj1.ToString());

                item1.SubItems.Add(iRet.ToString());
                lisMonitor.Items.Add(item1);


                adoCommand.Dispose();
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
#endregion

    }
}