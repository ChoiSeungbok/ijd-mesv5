using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.OleDb;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using Miracom.CliFrx;

namespace Admin.RPTCore
{
    public partial class frmDBReplicator : BaseForm01
    {
#region "Variables"


        //Source DB
        private clsTableInfo m_table = null;
        //private intGenerator m_generator = null;
        private bool m_load_flag = false;
        private clsDBManager m_src_db_manager = null;
        private bool m_src_db_connect_routine = false;
        private AMGV.DBTYPE m_src_db_type = AMGV.DBTYPE.ORACLE;

        //Target DB
        private clsDBManager m_tar_db_manager = null;
        private bool m_tar_db_connect_routine = false;
        //private AMGV.DBTYPE m_tar_db_type = AMGV.DBTYPE.ORACLE;

        //SqlStatement
        private StringBuilder sbSQL1 = new StringBuilder();
        private StringBuilder sbSQL2 = new StringBuilder();
        private StringBuilder sbSQL3 = new StringBuilder();
        private StringBuilder sbSQL4 = new StringBuilder();
        private StringBuilder sbSQL5 = new StringBuilder();

#endregion

        public frmDBReplicator()
        {
            InitializeComponent();
        }

#region "Form Event"

        private void frmDBReplicator_Load(object sender, EventArgs e)
        {
        }

        private void frmDBReplicator_Activated(object sender, EventArgs e)
        {
            if(m_load_flag == false)
            {
                return;
            }

            tabColumns.SelectedIndex = 0;
            txtSrcDBName.Focus();

            m_load_flag = true;
        }

        private void btnConnect_Click(object sender, EventArgs e)
        {
            string data_source = string.Empty;
            string db_name = string.Empty;
            string user_id = string.Empty;
            string password = string.Empty;
            string table_owner = string.Empty;
            OleDbCommand srcCommand;
            OleDbCommand tarCommand;
            object obj1 = null;
            int iRet;


            AMGV.DBTYPE db_type = AMGV.DBTYPE.ORACLE;

            if (txtSrcDBName.Text.Trim() == "")
            {
                MPCF.ShowMsgBox("Input Source Database Information (DB Name)", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                txtSrcDBName.Focus();
                return;
            }

            if (txtSrcUserID.Text.Trim() == "")
            {
                MPCF.ShowMsgBox("Input Source Database Information (User)", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                txtSrcUserID.Focus();
                return;
            }

            if (txtSrcPassword.Text.Trim() == "")
            {
                MPCF.ShowMsgBox("Input Source Database Information (DB Name, User and Password)", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                txtSrcPassword.Focus();
                return;
            }

            if (txtSchema.Text.Trim() == "")
            {
                MPCF.ShowMsgBox("Input Source Database Information (Table Owner)", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                txtSchema.Focus();
                return;
            }

            if (txtTarDBName.Text.Trim() == "")
            {
                MPCF.ShowMsgBox("Input Target Database Information (DB Name)", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                txtTarDBName.Focus();
                return;
            }

            if (txtTarUserID.Text.Trim() == "")
            {
                MPCF.ShowMsgBox("Input Target Database Information (User)", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                txtTarUserID.Focus();
                return;
            }

            if (txtTarPassword.Text.Trim() == "")
            {
                MPCF.ShowMsgBox("Input Target Database Information (Password)", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                txtTarPassword.Focus();
                return;
            }

            if (txtDBLink.Text.Trim() == "" && txtSrcDBName.Text.ToUpper().Trim() != txtTarDBName.Text.ToUpper().Trim())
            {
                MPCF.ShowMsgBox("Input Database Link Name", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                txtDBLink.Focus();
                return;
            }

            data_source = MPCF.Trim(txtSrcDataSource.Text);
            db_name = MPCF.Trim(txtSrcDBName.Text);
            user_id = MPCF.Trim(txtSrcUserID.Text);
            password = MPCF.Trim(txtSrcPassword.Text);
            if(txtSchema.Text.Trim() != txtSrcUserID.Text.Trim())
                table_owner = MPCF.Trim(txtSchema.Text);

            if(rdoSrcMsSql.Checked == true)
            {
                db_type = AMGV.DBTYPE.MSSQL;
            } else if(rdoSrcOracle.Checked == true)
            {
                db_type = AMGV.DBTYPE.ORACLE;
            } else if(rdoSrcDB2.Checked == true)
            {
                db_type = AMGV.DBTYPE.DB2;
            }

            m_src_db_manager = new clsDBManager();
            m_table = new clsTableInfo();

            if (m_src_db_manager.db_connect(data_source, db_name, user_id, password, table_owner, db_type, AMGV.DB_VIEW_TYPE.TABLE) == false)
            {
                m_src_db_connect_routine = false;
                m_src_db_manager.dispose();
                MPCF.ShowMsgBox("Fail to connet Source DB." + " " + 
                                m_src_db_manager.get_data_source()  + " " + 
                                m_src_db_manager.get_db_name() + " " + 
                                m_src_db_manager.get_user_id() + " " + 
                                m_src_db_manager.get_db_type());
                return;
            }

            m_src_db_manager.set_db_view_type(AMGV.DB_VIEW_TYPE.TABLE);
            m_src_db_connect_routine = true;

            if (txtLogTablespace.Text.ToUpper().Trim() != "")
            {
                srcCommand = new OleDbCommand();
                srcCommand.Connection = m_src_db_manager.get_db_connection();

                srcCommand.CommandText = "SELECT COUNT(*) FROM user_tablespaces WHERE tablespace_name = '" + txtLogTablespace.Text.ToUpper().Trim() + "'";
                obj1 = srcCommand.ExecuteScalar();
                iRet = int.Parse(obj1.ToString());
                if (iRet <= 0)
                {
                    MPCF.ShowMsgBox("Invalid LogTablespace Name,"); 
                    return;
                }
            }

            data_source = MPCF.Trim(txtTarDataSource.Text);
            db_name = MPCF.Trim(txtTarDBName.Text);
            user_id = MPCF.Trim(txtTarUserID.Text);
            password = MPCF.Trim(txtTarPassword.Text);

            if(rdoTarMsSql.Checked == true)
                db_type = AMGV.DBTYPE.MSSQL;
            else if(rdoTarOracle.Checked == true)
                db_type = AMGV.DBTYPE.ORACLE;
            else if(rdoTarDB2.Checked == true)
                db_type = AMGV.DBTYPE.DB2;

            m_tar_db_manager = new clsDBManager();

            if (m_tar_db_manager.db_connect(data_source, db_name, user_id, password, "", db_type, AMGV.DB_VIEW_TYPE.TABLE) == false)
            {
                m_src_db_manager.db_disconnect();
                m_src_db_connect_routine = false;
                m_src_db_manager.dispose();
                m_tar_db_connect_routine = false;
                m_tar_db_manager.dispose();
                MPCF.ShowMsgBox("Fail to connect Target DB." + " " + 
                                    m_tar_db_manager.get_data_source()  + " " +
                                    m_tar_db_manager.get_db_name() + " " +
                                    m_tar_db_manager.get_user_id() + " " +
                                    m_tar_db_manager.get_db_type());
                return;
            }

            m_tar_db_manager.set_db_view_type(AMGV.DB_VIEW_TYPE.TABLE);
            m_tar_db_connect_routine = true;

            if (txtViewTablespace.Text.ToUpper().Trim() != "")
            {
                tarCommand = new OleDbCommand();
                tarCommand.Connection = m_tar_db_manager.get_db_connection();

                tarCommand.CommandText = "SELECT COUNT(*) FROM user_tablespaces WHERE tablespace_name = '" + txtViewTablespace.Text.ToUpper().Trim() + "'";
                obj1 = tarCommand.ExecuteScalar();
                iRet = int.Parse(obj1.ToString());
                if (iRet <= 0)
                {
                    MPCF.ShowMsgBox("Invalid Materialised View Tablespace Name,");
                    return;
                }
            }

            if (txtRepTblTablespace.Text.ToUpper().Trim() != "")
            {
                tarCommand = new OleDbCommand();
                tarCommand.Connection = m_tar_db_manager.get_db_connection();

                tarCommand.CommandText = "SELECT COUNT(*) FROM user_tablespaces WHERE tablespace_name = '" + txtRepTblTablespace.Text.ToUpper().Trim() + "'";
                obj1 = tarCommand.ExecuteScalar();
                iRet = int.Parse(obj1.ToString());
                if (iRet <= 0)
                {
                    MPCF.ShowMsgBox("Invalid Materialised View Tablespace Name,");
                    return;
                }
            }

            if (txtRepIdxTablespace.Text.ToUpper().Trim() != "")
            {
                tarCommand = new OleDbCommand();
                tarCommand.Connection = m_tar_db_manager.get_db_connection();

                tarCommand.CommandText = "SELECT COUNT(*) FROM user_tablespaces WHERE tablespace_name = '" + txtRepIdxTablespace.Text.ToUpper().Trim() + "'";
                obj1 = tarCommand.ExecuteScalar();
                iRet = int.Parse(obj1.ToString());
                if (iRet <= 0)
                {
                    MPCF.ShowMsgBox("Invalid Materialised View Tablespace Name,");
                    return;
                }
            }

            if (MPCF.Trim(txtDBLink.Text) != "")
            {
                try
                {
                    tarCommand = new OleDbCommand();
                    tarCommand.Connection = m_tar_db_manager.get_db_connection();

                    tarCommand.CommandText = "SELECT COUNT(*) FROM USER_DB_LINKS WHERE DB_LINK LIKE \'" + MPCF.Trim(txtDBLink.Text).ToUpper() + "%\'";
                    obj1 = tarCommand.ExecuteScalar();
                    iRet = int.Parse(obj1.ToString());
                    if (iRet <= 0)
                    {
                        MPCF.ShowMsgBox("Invalid Database Link,");
                        return;
                    }
                }
                catch (Exception ex)
                {
                    MPCF.ShowMsgBox("Invalid Database Link,");
                    return;
                }
            }

            MPCF.ShowMsgBox("Success to connect database." + " " +
                                m_src_db_manager.get_data_source() + " " +
                                m_src_db_manager.get_db_name() + " " +
                                m_src_db_manager.get_user_id() + " " +
                                m_src_db_manager.get_db_type());



            GetAllTables();
        }

        private void btnDisconnect_Click(object sender, EventArgs e)
        {
            if(m_src_db_connect_routine == true)
            {
                m_src_db_manager.db_disconnect();
                m_src_db_connect_routine = false;
            }

            if(m_tar_db_connect_routine == true)
            {
                m_tar_db_manager.db_disconnect();
                m_tar_db_connect_routine = false;
            }

            lisTable.Items.Clear();
            lisColList.Items.Clear();

            MPCF.ShowMsgBox("Disconnet to database.");
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Dispose();
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            int iRet;
            OleDbCommand srcCommand;
            OleDbCommand tarCommand;
            string sMVTable, sRepTable;

            object obj1 = null;

            srcCommand = null;
            tarCommand = null;

            if (lisTable.SelectedItems.Count < 1)
                return;

            if (MPCF.ShowMsgBox(MPCF.GetMessage(251), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes) return;

            if (rbSource.Checked == true)
            {
                sMVTable = txtPrefix.Text.Trim() + lisTable.SelectedItems[0].Text;
                sRepTable = "R" + lisTable.SelectedItems[0].Text.Substring(1, lisTable.SelectedItems[0].Text.Length - 1 ) ;
            }
            else
            {
                sMVTable = lisTable.SelectedItems[0].Text;
                sRepTable = "R" + lisTable.SelectedItems[0].SubItems[1].Text.Substring(1,lisTable.SelectedItems[0].SubItems[1].Text.Length - 1);
            }

            //Drop
            if (rbSource.Checked == true)
            {
                try
                {
                    srcCommand = new OleDbCommand();
                    srcCommand.Connection = m_src_db_manager.get_db_connection();

                    srcCommand.CommandText = "SELECT COUNT(*) FROM ALL_MVIEW_LOGS WHERE MASTER = \'" + lisTable.SelectedItems[0].Text + "\'";
                    obj1 = srcCommand.ExecuteScalar();
                    iRet = int.Parse(obj1.ToString());
                    if (iRet > 0)
                    {
                        if (txtSchema.Text.Trim() != "" && txtSchema.Text.Trim() != txtSrcUserID.Text.Trim())
                            srcCommand.CommandText = "DROP MATERIALIZED VIEW LOG ON " + txtSchema.Text.Trim() + "." + lisTable.SelectedItems[0].Text;
                        else
                            srcCommand.CommandText = "DROP MATERIALIZED VIEW LOG ON " + lisTable.SelectedItems[0].Text;
                        iRet = srcCommand.ExecuteNonQuery();
                    }
                    srcCommand.Dispose();
                    MPCF.ShowMsgBox("Log Delete Complete");
                }
                catch (Exception ex)
                {
                    MPCF.ShowMsgBox(ex.Message);
                }
                finally
                {
                    srcCommand.Dispose();
                }

            }

            try
            {
                tarCommand = new OleDbCommand();
                tarCommand.Connection = m_tar_db_manager.get_db_connection();

                if (rbSource.Checked == true)
                {
                    tarCommand.CommandText = "SELECT COUNT(*) FROM USER_MVIEWS WHERE MVIEW_NAME LIKE \'%" + sMVTable + "\'";
                    obj1 = tarCommand.ExecuteScalar();
                    iRet = int.Parse(obj1.ToString());
                    if (iRet > 0)
                    {
                        tarCommand.CommandText = "DROP MATERIALIZED VIEW " + sMVTable;
                        iRet = tarCommand.ExecuteNonQuery();
                    }
                }
                else
                {
                    tarCommand.CommandText = "SELECT COUNT(*) FROM USER_TRIGGERS WHERE TRIGGER_NAME LIKE \'%" + sMVTable + "_TRG0\'";
                    obj1 = tarCommand.ExecuteScalar();
                    iRet = int.Parse(obj1.ToString());
                    if (iRet > 0)
                    {
                        tarCommand.CommandText = "DROP TRIGGER " + sMVTable + "_TRG0";
                        iRet = tarCommand.ExecuteNonQuery();
                    }
                }

                tarCommand.CommandText = "SELECT COUNT(*) FROM USER_TABLES WHERE TABLE_NAME = \'" + sRepTable  + "\'";
                obj1 = tarCommand.ExecuteScalar();
                iRet = int.Parse(obj1.ToString());
                if (iRet > 0)
                {
                    tarCommand.CommandText = "DROP TABLE " + sRepTable + " CASCADE CONSTRAINTS PURGE";
                    iRet = tarCommand.ExecuteNonQuery();
                }
                tarCommand.Dispose();
                if (rbSource.Checked == true)
                    MPCF.ShowMsgBox("MView and Replication Table Deleted Complete");
                else
                    MPCF.ShowMsgBox("Trigger and Replication Table Deleted Complete");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            finally
            {
                tarCommand.Dispose();
            }

            GetAllTables();
        }

        private void btnExecute_Click(object sender, EventArgs e)
        {
            int iRet;
            bool DBLink = false;
            bool bLog = false;
            bool bMView = false;
            string sCode;
            OleDbCommand srcCommand;
            OleDbCommand tarCommand;
            object obj1 = null;
            string sMVTable, sRepTable;
            string tmpErrMsg = string.Empty;

            if (lisTable.SelectedItems.Count < 1)
                return;

            this.Cursor = Cursors.WaitCursor;

            if (rbSource.Checked == true)
            {
                sMVTable = txtPrefix.Text.Trim() + lisTable.SelectedItems[0].Text;
                sRepTable = "R" + lisTable.SelectedItems[0].Text.Substring(1, lisTable.SelectedItems[0].Text.Length - 1);
            }
            else
            {
                sMVTable = lisTable.SelectedItems[0].Text;
                sRepTable = "R" + lisTable.SelectedItems[0].SubItems[1].Text.Substring(1, lisTable.SelectedItems[0].SubItems[1].Text.Length - 1);
            }

            srcCommand = new OleDbCommand();
            srcCommand.Connection = m_src_db_manager.get_db_connection();
            tarCommand = new OleDbCommand();
            tarCommand.Connection = m_tar_db_manager.get_db_connection();

            if (rbTarget.Checked == true)
            {
                try
                {
                    tarCommand.CommandText = "SELECT COUNT(*) FROM USER_TABLES WHERE TABLE_NAME = \'" + sRepTable + "\'";
                    obj1 = tarCommand.ExecuteScalar();
                    iRet = int.Parse(obj1.ToString());
                    if (iRet > 0)
                    {
                        tarCommand.CommandText = "DROP TABLE " + sRepTable + " CASCADE CONSTRAINTS PURGE";
                        iRet = tarCommand.ExecuteNonQuery();
                    }
                }
                catch (Exception ex)
                {
                    this.Cursor = Cursors.Default;
                    MPCF.ShowMsgBox(ex.Message);
                }

                if (cbRTable.Checked == true)
                {
                    GetRepTblScript();
                    sCode = sbSQL1.ToString();
                    sCode = sCode.Replace(";", "");
                    tarCommand.CommandText = sCode;
                    iRet = tarCommand.ExecuteNonQuery();
                    sCode = sbSQL2.ToString();
                    sCode = sCode.Replace(";", "");
                    tarCommand.CommandText = sCode;
                    iRet = tarCommand.ExecuteNonQuery();
                    sCode = sbSQL4.ToString();
                    sCode = sCode.Replace(";", "");
                    tarCommand.CommandText = sCode;
                    iRet = tarCommand.ExecuteNonQuery();
                    sCode = sbSQL3.ToString();
                    tarCommand.CommandText = sCode;
                    iRet = tarCommand.ExecuteNonQuery();
                }
                this.Cursor = Cursors.Default;
                MPCF.ShowMsgBox("Success to generate Trigger and Repllication Table.", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Information);
                GetAllTables();
                return;
            }

            if (btnExecute.Text == "Execute" && txtInterval.Text.Trim() == "")
            {
                this.Cursor = Cursors.Default;
                MPCF.ShowMsgBox("Input time Interval", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                txtInterval.Focus();
                return;
            }

            if (lisTable.SelectedItems.Count == 0)
            {
                this.Cursor = Cursors.Default;
                MPCF.ShowMsgBox("Select the table", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                lisTable.Focus();
                return;
            }

            //Drop
            try
            {
                srcCommand.CommandText = "SELECT COUNT(*) FROM ALL_MVIEW_LOGS WHERE MASTER = \'" + lisTable.SelectedItems[0].Text + "\'";
                obj1 = srcCommand.ExecuteScalar();
                iRet = int.Parse(obj1.ToString());
                if (iRet > 0)
                {
                    if (txtSchema.Text.Trim() != "" && txtSchema.Text.Trim() != txtSrcUserID.Text.Trim())
                        srcCommand.CommandText = "DROP MATERIALIZED VIEW LOG ON " + txtSchema.Text.Trim() + "." + lisTable.SelectedItems[0].Text;
                    else
                        srcCommand.CommandText = "DROP MATERIALIZED VIEW LOG ON " + lisTable.SelectedItems[0].Text;
                    iRet = srcCommand.ExecuteNonQuery();
                }

            }
            catch (Exception ex)
            {
                this.Cursor = Cursors.Default;
                MPCF.ShowMsgBox(ex.Message);
            }

            try
            {
                tarCommand.CommandText = "SELECT COUNT(*) FROM USER_MVIEWS WHERE MVIEW_NAME LIKE \'%" + lisTable.SelectedItems[0].Text + "\'";
                obj1 = tarCommand.ExecuteScalar();
                iRet = int.Parse(obj1.ToString());
                if (iRet > 0)
                {
                    tarCommand.CommandText = "DROP MATERIALIZED VIEW " + sMVTable ;
                    iRet = tarCommand.ExecuteNonQuery();
                }
            }
            catch (Exception ex)
            {
                this.Cursor = Cursors.Default;
                MPCF.ShowMsgBox(ex.Message);
            }

            if (MPCF.Trim(txtDBLink.Text) != "")
            {
                try
                {
                    tarCommand.CommandText = "SELECT COUNT(*) FROM USER_DB_LINKS WHERE DB_LINK LIKE \'" + MPCF.Trim(txtDBLink.Text).ToUpper() + "%\'";
                    obj1 = tarCommand.ExecuteScalar();
                    iRet = int.Parse(obj1.ToString());
                    if (iRet > 0)
                    {
                        DBLink = true;
                    }
                }
                catch (Exception ex)
                {
                    this.Cursor = Cursors.Default;
                    MPCF.ShowMsgBox(ex.Message);
                }

                if (DBLink == false)
                {
                    try
                    {
                        //Log
                        sCode = GetDBLinkScript();
                        sCode = sCode.Replace(";", "");
                        tarCommand.CommandText = sCode;
                        iRet = tarCommand.ExecuteNonQuery();
                    }
                    catch (Exception ex)
                    {
                        this.Cursor = Cursors.Default;
                        MPCF.ShowMsgBox(ex.Message, "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                    }
                }
            }

            try
            {
                tarCommand.CommandText = "SELECT COUNT(*) FROM USER_TABLES WHERE TABLE_NAME = \'" + sRepTable + "\'";
                obj1 = tarCommand.ExecuteScalar();
                iRet = int.Parse(obj1.ToString());
                if (iRet > 0)
                {
                    tarCommand.CommandText = "DROP TABLE " + sRepTable + " CASCADE CONSTRAINTS PURGE";
                    iRet = tarCommand.ExecuteNonQuery();
                }
            }
            catch (Exception ex)
            {
                this.Cursor = Cursors.Default;
                MPCF.ShowMsgBox(ex.Message);
            }

            try
            {
                //Log
                sCode = GetLogScript();
                sCode = sCode.Replace(";", "");
                srcCommand.CommandText = sCode;
                iRet = srcCommand.ExecuteNonQuery();
                bLog = true;

                //MView
                sCode = GetMViewScript();
                sCode = sCode.Replace(";", "");
                tarCommand.CommandText = sCode;
                iRet = tarCommand.ExecuteNonQuery();
                bMView = true;

                //Index
                sCode = GetConstraintScript();
                sCode = sCode.Replace(";", "");
                tarCommand.CommandText = sCode;
                iRet = tarCommand.ExecuteNonQuery();

                if (cbRTable.Checked == true)
                {
                    GetRepTblScript();
                    sCode = sbSQL1.ToString();
                    sCode = sCode.Replace(";", "");
                    tarCommand.CommandText = sCode;
                    iRet = tarCommand.ExecuteNonQuery();
                    sCode = sbSQL2.ToString();
                    sCode = sCode.Replace(";", "");
                    tarCommand.CommandText = sCode;
                    iRet = tarCommand.ExecuteNonQuery();

                    sCode = sbSQL4.ToString();
                    sCode = sCode.Replace(";", "");
                    tarCommand.CommandText = sCode;
                    iRet = tarCommand.ExecuteNonQuery();
                    
                    sCode = sbSQL3.ToString();
                    tarCommand.CommandText = sCode;
                    iRet = tarCommand.ExecuteNonQuery();
                }
                this.Cursor = Cursors.Default;
                MPCF.ShowMsgBox("Success to generate materialize view.", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Information);

            }
            catch (Exception ex)
            {
                this.Cursor = Cursors.Default;
                if (ex.Message.Substring(0, 9) == "ORA-01841")
                    tmpErrMsg = " \r\n Please check data in the source database. Data value is wrong format in date format field";

                MPCF.ShowMsgBox(ex.Message + tmpErrMsg, "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                if (bLog == true)
                {
                    if (txtSchema.Text.Trim() != "" && txtSchema.Text.Trim() != txtSrcUserID.Text.Trim())
                        srcCommand.CommandText = "DROP MATERIALIZED VIEW LOG ON " + txtSchema.Text.Trim() + "." + lisTable.SelectedItems[0].Text;
                    else
                        srcCommand.CommandText = "DROP MATERIALIZED VIEW LOG ON " + lisTable.SelectedItems[0].Text;
                    iRet = srcCommand.ExecuteNonQuery();

                }
                if (bMView == true)
                {
                    tarCommand.CommandText = "DROP MATERIALIZED VIEW " + txtPrefix.Text.Trim() + lisTable.SelectedItems[0].Text;
                    iRet = tarCommand.ExecuteNonQuery();
                }
            }

            srcCommand.Dispose();
            tarCommand.Dispose();

            GetAllTables();

            this.Cursor = Cursors.Default;
        }

        private void btnCodeGen_Click(object sender, EventArgs e)
        {
            string sCode;

            if (lisTable.SelectedItems.Count < 1)
                return;

            if (txtInterval.Enabled == true && txtInterval.Visible == true && txtInterval.Text.Trim() == "")
            {
                MPCF.ShowMsgBox("Input time Interval", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                txtInterval.Focus();
                return;
            }

            if (lisTable.SelectedItems.Count == 0)
            {
                MPCF.ShowMsgBox("Select the table", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                lisTable.Focus();
                return;
            }

            sCode = "";
            if (cbMView.Checked == true)
            {
                sCode = GetLogScript();
                sCode = sCode + GetMViewScript();
                sCode = sCode + GetConstraintScript();
            }
            if (cbRTable.Checked == true )
                sCode = sCode + GetRepTblScript();

            txtScript.Text = sCode;

            tabColumns.SelectedIndex = 2;
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            System.Windows.Forms.SaveFileDialog saveFileDlg = new System.Windows.Forms.SaveFileDialog();
            string sFileName = "";

            saveFileDlg.Filter = "DB Script File(*.sql)|*.sql";
            saveFileDlg.Title = "DB Script Save";

            saveFileDlg.CreatePrompt = false;
            saveFileDlg.OverwritePrompt = true;

            if (saveFileDlg.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                sFileName = saveFileDlg.FileName;

                sFileName = sFileName.Substring(0, sFileName.Length - 4);
                if (save_file_class(sFileName) == false)
                {
                    return;
                }
                MPCF.ShowMsgBox("Success to save DB Library.", "SQL Save Success", MessageBoxButtons.OK, (int)MessageBoxIcon.Information);
            }
            else
            {
                MPCF.ShowMsgBox("Cancel to save DB Library.", "SQL Save Cancel", MessageBoxButtons.OK, (int)MessageBoxIcon.Information);
            }

            txtFileName.Text = sFileName;
        }

        private void rbClass_CheckedChanged(object sender, EventArgs e)
        {
            if (rbOnDemand.Checked == true)
            {
                txtInterval.Enabled = false;
            }
            else
            {
                txtInterval.Enabled = true;
                txtInterval.Text = "60";
            }
        }

        private void lisTable_ColumnClick(object sender, ColumnClickEventArgs e)
        {
            if (GetAllTables() == false)
            {
                MPCF.ShowMsgBox("Fail to read database information.", "DB Info Error", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                return;
            }
        }

        private void lisTable_Click(object sender, EventArgs e)
        {
            if (lisTable.SelectedItems.Count > 0)
            {
                lisColList.Items.Clear();
                System.Windows.Forms.Cursor.Current = Cursors.WaitCursor;

                txtScript.Text = "";
                if (tabColumns.SelectedTab == pageCode)
                {
                    tabColumns.SelectedTab = pageColList;
                }

                m_table.init();
                m_table.TableName = lisTable.SelectedItems[0].Text;
                m_table.DBType = m_src_db_type;
                if (GetAllFields(m_table.TableName) == false)
                {
                    return;
                }
                if (rbTarget.Checked == true)
                {
                    if (lisTable.SelectedItems[0].SubItems[1].Text == "")
                    {
                        btnCodeGen.Enabled = false;
                        btnDelete.Enabled = false;
                        btnExecute.Enabled = false;
                    }
                    else
                    {
                        btnCodeGen.Enabled = true;
                        btnDelete.Enabled = true;
                        btnExecute.Enabled = true;
                    }
                }
                else
                {
                    if (lisTable.SelectedItems[0].SubItems[1].Text == "LOG")
                    {
                        btnCodeGen.Enabled = false;
                        btnDelete.Enabled = true;
                        btnExecute.Enabled = false;
                    }
                    else
                    {
                        btnCodeGen.Enabled = true;
                        btnDelete.Enabled = false;
                        btnExecute.Enabled = true;
                    }
                }
                System.Windows.Forms.Cursor.Current = Cursors.Default;
            }
        }

        private void tabColumns_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (m_src_db_connect_routine == false || m_tar_db_connect_routine == false)
            {
                tabColumns.SelectedIndex = 0;
            }
        }

        private void rbTable_CheckedChanged(object sender, EventArgs e)
        {
            if (m_src_db_connect_routine == true && rbSource.Checked == true)
            {
                lisTable.Columns[1].Text = "Type";
                GetAllTables();
            }
            cbMView.Checked = true;
            rbOnDemand.Visible = true;
            rbOracleJob.Visible = true;
            lblInterval.Visible = true;
            txtInterval.Visible = true;
            Label3.Visible = true;
            cbRTable.Enabled = true;
            btnExecute.Enabled = true;
            btnDelete.Enabled = true;
            btnCodeGen.Enabled = true;
        }

        private void lisColList_ItemCheck(object sender, ItemCheckEventArgs e)
        {
            if (e.Index < 0)
            {
                return;
            }

            if (lisColList.Items[e.Index].ForeColor == Color.Red)
            {
                e.NewValue = CheckState.Checked;
                return;
            }
            if (AMGV.GetFieldInfo == false)
            {
                if (e.NewValue == CheckState.Checked)
                {
                    ((clsFieldInfo)m_table[e.Index]).Selected = true;
                    m_table.SelectedCount++;
                }
                else if (e.NewValue == CheckState.Unchecked)
                {
                    ((clsFieldInfo)m_table[e.Index]).Selected = false;
                    m_table.SelectedCount--;
                }
            }
        }

        private void rbView_CheckedChanged(object sender, EventArgs e)
        {
            if (m_tar_db_connect_routine == true && rbTarget.Checked == true)
            {
                lisTable.Columns[1].Text = "MASTER";
                GetAllTables();
            }
            cbMView.Checked = false;
            rbOnDemand.Visible = false;
            rbOracleJob.Visible = false;
            lblInterval.Visible = false;
            txtInterval.Visible = false;
            Label3.Visible = false;
            cbRTable.Checked = true;
            cbRTable.Enabled = false;
        }

#endregion

#region "Procedure and Function"


        private bool GetAllTables()
        {
            OleDbDataReader adoReader;
            OleDbCommand adoCommand;
            StringBuilder strQuery = new StringBuilder();

            //Clear ListView Items
            lisTable.Items.Clear();
            lisColList.Items.Clear();
            tabColumns.SelectedIndex = 1;

            adoReader = null;
            adoCommand = null;

            adoCommand = new OleDbCommand();

            try
            {
                if (rbSource.Checked == true)
                {
                    if (m_src_db_manager.get_is_connect() == false)
                        return false;

                    adoCommand.Connection = m_src_db_manager.get_db_connection();
                    strQuery = strQuery.Append("SELECT T.TNAME, NVL(L.MASTER, ' ') FROM TAB T, ALL_MVIEW_LOGS L WHERE T.TNAME = L.MASTER(+) AND T.TNAME NOT LIKE 'BIN$%' ORDER BY TNAME");
                    //strQuery = strQuery.Append("SELECT T.TABLE_NAME, NVL(L.MASTER, ' ') FROM USER_TABLES T, USER_MVIEW_LOGS L WHERE T.TABLE_NAME = L.MASTER(+) ORDER BY TABLE_NAME");
                    adoCommand.CommandText = strQuery.ToString();
                    adoReader = adoCommand.ExecuteReader();

                    while (adoReader.Read())
                    {
                        if (adoReader.GetString(0).Length < 5)
                        {
                            ListViewItem item1 = new ListViewItem(adoReader.GetString(0).Trim());
                            item1.SubItems.Add("");
                            lisTable.Items.Add(item1);
                        }
                        else
                        {
                            if (adoReader.GetString(0).Substring(0, 5) != "MLOG$")
                            {
                                ListViewItem item1 = new ListViewItem(adoReader.GetString(0).Trim());

                                if (MPCF.Trim(adoReader.GetString(1)) == "")
                                    item1.SubItems.Add("");
                                else
                                    item1.SubItems.Add("LOG");

                                lisTable.Items.Add(item1);
                            }
                        }
                    }
                }
                else if (rbTarget.Checked == true)
                {
                    if (m_tar_db_manager.get_is_connect() == false)
                        return false;

                    adoCommand = new OleDbCommand();
                    adoCommand.Connection = m_tar_db_manager.get_db_connection();

                    if (txtDBLink.Text.Trim() == "")
                        strQuery = strQuery.Append("SELECT T.TABLE_NAME, NVL(M.MASTER, ' ') FROM USER_TABLES T,(SELECT A.NAME, B.MASTER FROM ALL_REGISTERED_MVIEWS A, ALL_BASE_TABLE_MVIEWS B");
                    else
                        strQuery = strQuery.AppendFormat("SELECT T.TABLE_NAME, NVL(M.MASTER, ' ') FROM USER_TABLES T,(SELECT A.NAME, B.MASTER FROM ALL_REGISTERED_MVIEWS@{0} A, ALL_BASE_TABLE_MVIEWS@{1} B", txtDBLink.Text.Trim().ToString(), txtDBLink.Text.Trim().ToString());
                    strQuery = strQuery.Append(" WHERE A.MVIEW_ID = B.MVIEW_ID) M WHERE T.TABLE_NAME = M.NAME(+) AND T.TABLE_NAME NOT LIKE 'BIN$%' ORDER BY NVL(M.MASTER, ' ') DESC, T.TABLE_NAME ASC");
                    adoCommand.CommandText = strQuery.ToString();

                    adoReader = adoCommand.ExecuteReader();

                    while (adoReader.Read())
                    {
                        ListViewItem item1 = new ListViewItem(adoReader.GetString(0).Trim());
                        item1.SubItems.Add(adoReader.GetString(1).Trim());
                        lisTable.Items.Add(item1);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message, "GetAllTables", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
            }
            adoCommand.Dispose();
            return true;
        }

        private bool GetAllFields(string tableName)
	    {
		    int i;
		    DataRow[] schemaRow;
		    DataRow[] schemaPKRow;
		    ListViewItem item = null;
		    clsFieldInfo fieldInfo = null;
    		
		    try
		    {
			    // Clear ListView Items
			    lisColList.Items.Clear();
			    tabColumns.SelectedIndex = 1;
    			
			    // Getting Field Info
			    AMGV.GetFieldInfo = true;
    			
			    if (rbSource.Checked == true)
			    {
				    schemaRow = m_src_db_manager.get_field_list(tableName);
				    if (schemaRow == null)
				    {
					    return false;
				    }
    				
				    schemaPKRow = m_src_db_manager.get_PK_list(tableName);
				    if (schemaPKRow == null)
				    {
					    return false;
				    }
    				
			    }
			    else
			    {
				    schemaRow = m_tar_db_manager.get_field_list(tableName);
				    if (schemaRow == null)
				    {
					    return false;
				    }
    				
				    schemaPKRow = m_tar_db_manager.get_PK_list(tableName);
				    if (schemaPKRow == null)
				    {
					    return false;
				    }
    				
			    }
    			
			    if (m_table.add_field_info(schemaRow, schemaPKRow) == false)
			    {
				    return false;
			    }
    			
			    for (i = 0; i < m_table.Count; i++)
			    {
				    fieldInfo = (clsFieldInfo) m_table[i];
				    if (fieldInfo.Selected == true)
				    {
					    item = new ListViewItem("", 4);
					    item.Checked = true ;
					    item.ForeColor = Color.Red;
				    }
				    else
				    {
					    item = new ListViewItem("", 3);
					    item.Checked = true;
				    }
				    item.SubItems.Add(fieldInfo.Sequence.ToString());
				    item.SubItems.Add(fieldInfo.FieldName);
                    item.SubItems.Add(clsCommon.ConvertDataTypeToString(fieldInfo.DataType));
				    if (fieldInfo.IsNull == true)
				    {
					    item.SubItems.Add("Y");
				    }
				    else
				    {
					    item.SubItems.Add("N");
				    }
				    if (fieldInfo.Size == - 1)
				    {
					    item.SubItems.Add("");
				    }
				    else
				    {
					    item.SubItems.Add(fieldInfo.Size.ToString());
				    }
				    if (fieldInfo.NumericScale == - 1)
				    {
					    item.SubItems.Add("");
				    }
				    else
				    {
					    item.SubItems.Add(fieldInfo.NumericScale.ToString());
				    }
				    if (fieldInfo.Precision == - 1)
				    {
					    item.SubItems.Add("");
				    }
				    else
				    {
					    item.SubItems.Add(fieldInfo.Precision.ToString());
				    }
    				
				    lisColList.Items.Add(item);
			    }
    			
		    }
		    catch (Exception ex)
		    {
			    AMGV.GetFieldInfo = false;
			    MPCF.ShowMsgBox(ex.Message, "GetAllFieldList", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
			    return false;
		    }
            AMGV.GetFieldInfo = false;

            return true;
	    }

        private string GetDBLinkScript()
        {
            StringBuilder sb_script;

            sb_script = new StringBuilder();

            if(MPCF.Trim(txtDBLink.Text) == "")
            {
                return string.Empty;
            }

            if (MPCF.Trim(txtSrcUserID.Text) == "")
            {
                return string.Empty;
            }

            if (MPCF.Trim(txtSrcPassword.Text) == "")
            {
                return string.Empty;
            }

            if (MPCF.Trim(txtSrcDBName.Text) == "")
            {
                return string.Empty;
            }
            sb_script.Append("CREATE DATABASE LINK " + MPCF.Trim(txtDBLink.Text).ToUpper() + "\r\n");
            sb_script.Append(" CONNECT TO " + MPCF.Trim(txtSrcUserID.Text) + "\r\n");
            sb_script.Append(" IDENTIFIED BY \"" + MPCF.Trim(txtSrcPassword.Text) + "\"\r\n");
            sb_script.Append(" USING \'" + MPCF.Trim(txtSrcDBName.Text) + "\'\r\n");

            return sb_script.ToString();
        }

        private string GetLogScript()
        {
            StringBuilder sb_script;

            sb_script = new StringBuilder();
            if (lisTable.SelectedItems.Count <= 0)
            {
                return "";
            }

            //Create Log
            if(txtSchema.Text.Trim() != "" && txtSchema.Text.Trim() != txtSrcUserID.Text.Trim())
                sb_script.Append("CREATE MATERIALIZED VIEW LOG ON " + txtSchema.Text.Trim() + "." + lisTable.SelectedItems[0].Text + "\r\n");
            else
                sb_script.Append("CREATE MATERIALIZED VIEW LOG ON " + lisTable.SelectedItems[0].Text + "\r\n");
            if (txtLogTablespace.Text != "")
            {
                sb_script.Append(" TABLESPACE " + txtLogTablespace.Text.Trim());
            }
            sb_script.Append(" STORAGE(INITIAL 10M) WITH ROWID EXCLUDING NEW VALUES;" + "\r\n");

            return sb_script.ToString();
        }

        private string GetMViewScript()
        {
            int i;
            int iFieldCount;
            StringBuilder sb_script;

            sb_script = new StringBuilder();
            if (lisTable.SelectedItems.Count <= 0)
            {
                return null;
            }

            //Create MView
            sb_script.Append("CREATE MATERIALIZED VIEW " + txtPrefix.Text.Trim() + lisTable.SelectedItems[0].Text);
            if (txtViewTablespace.Text != "")
            {
                sb_script.Append(" TABLESPACE " + txtViewTablespace.Text.Trim());
            }
            sb_script.Append(" STORAGE(INITIAL 10M) " + "\r\n");
            sb_script.Append(" BUILD IMMEDIATE" + "\r\n");
            sb_script.Append(" USING INDEX");
            if (txtViewTablespace.Text != "")
            {
                sb_script.Append(" TABLESPACE " + txtViewTablespace.Text.Trim());
            }
            sb_script.Append(" STORAGE(INITIAL 10M) REFRESH FAST");
            if (rbOnDemand.Checked == true)
            {
                sb_script.Append(" ON DEMAND WITH ROWID" + "\r\n");
            }
            else if (rbOracleJob.Checked == true)
            {
                //START WITH SYSDATE NEXT sysdate  + 5/86400 WITH ROWID
                sb_script.Append(" START WITH SYSDATE NEXT sysdate + " + txtInterval.Text.Trim() + "/86400 WITH ROWID" + "\r\n");
            }
            sb_script.Append(" AS SELECT " + "\r\n");
            iFieldCount = 0;
            for (i = 0; i < lisColList.Items.Count; i++)
            {
                if (lisColList.Items[i].Checked == false)
                {
                    continue;
                }
                sb_script.Append("A." + lisColList.Items[i].SubItems[2].Text);
                iFieldCount++;
                if (i < lisColList.Items.Count - 1)
                {
                    sb_script.Append(",");
                }

            }

            if (sb_script.ToString().Substring(sb_script.Length - 1,1) == ",")
            {
                sb_script.Remove(sb_script.Length - 1, 1);
            }

            if (iFieldCount == 0)
            {
                if (txtDBLink.Text.Trim() == "")
                {
                    sb_script.Append(" FROM " + txtSrcUserID.Text.Trim() + "." + lisTable.SelectedItems[0].Text + " A;" + "\n\n");
                }
                else
                {
                    sb_script.Append(" A.*  FROM " + lisTable.SelectedItems[0].Text + "@" + txtDBLink.Text.Trim() + " A;" + "\n\n");
                }

            }
            else
            {
                if (txtDBLink.Text.Trim() == "")
                {
                    sb_script.Append(" FROM " + txtSrcUserID.Text.Trim() + "." + lisTable.SelectedItems[0].Text + " A;" + "\n\n");
                }
                else
                {
                    sb_script.Append(" FROM " + lisTable.SelectedItems[0].Text + "@" + txtDBLink.Text.Trim() + " A;" + "\n\n");
                }

            }

            return sb_script.ToString();
        }

        private string GetConstraintScript()
        {
            int i;
            StringBuilder sb_script;

            sb_script = new StringBuilder();
            if (lisTable.SelectedItems.Count <= 0)
            {
                return null;
            }

            sb_script.Append("ALTER TABLE " + txtPrefix.Text.Trim() + lisTable.SelectedItems[0].Text + "\n");
            sb_script.Append("   ADD CONSTRAINT " + txtPrefix.Text.Trim() + lisTable.SelectedItems[0].Text + "_PK\n");
            sb_script.Append("   PRIMARY KEY (");
            
            for (i = 0; i < lisColList.Items.Count; i++)
            {
                if (lisColList.Items[i].ForeColor != Color.Red)
                {
                    continue;
                }
                sb_script.Append(lisColList.Items[i].SubItems[2].Text + ", ");
            }

            sb_script.Remove(sb_script.Length - 2, 2);
            sb_script.Append("\n ) USING INDEX ");
            if (txtViewTablespace.Text != "")
            {
                sb_script.Append("\n TABLESPACE " + txtViewTablespace.Text.Trim() + " STORAGE(INITIAL 10M)");
            }
            sb_script.Append(";\n");

            return sb_script.ToString();
        }

        private string GetRepTblScript()
        {
            int i;
            string sRepTable;
            string sMVTable;
            string sDataType;
            StringBuilder sbPriKey;
            StringBuilder sbColList;
            StringBuilder sbTrgLn1;
            StringBuilder sbTrgLn2;
            StringBuilder sbTrgLn3;
            StringBuilder sbTrgLn4;
            StringBuilder sbTrgLn5;
            StringBuilder sbTrgLn6;
            StringBuilder sbTrgLn7;
            StringBuilder sbTrgLn8;
            StringBuilder sbTrgLn9;
            StringBuilder sbTrgLn10;
            StringBuilder sbTrgLn11;

            sbPriKey = new StringBuilder();
            sbColList = new StringBuilder();
            sbTrgLn1 = new StringBuilder();
            sbTrgLn2 = new StringBuilder();
            sbTrgLn3 = new StringBuilder();
            sbTrgLn4 = new StringBuilder();
            sbTrgLn5 = new StringBuilder();
            sbTrgLn6 = new StringBuilder();
            sbTrgLn7 = new StringBuilder();
            sbTrgLn8 = new StringBuilder();
            sbTrgLn9 = new StringBuilder();
            sbTrgLn10 = new StringBuilder();
            sbTrgLn11 = new StringBuilder();

            sbSQL1.Remove(0, sbSQL1.Length);
            sbSQL2.Remove(0, sbSQL2.Length);
            sbSQL3.Remove(0, sbSQL3.Length);
            sbSQL4.Remove(0, sbSQL4.Length);

            if (lisTable.SelectedItems.Count <= 0)
            {
                return null;
            }

            if (rbSource.Checked == true)
            {
                sMVTable = txtPrefix.Text.Trim() + lisTable.SelectedItems[0].Text;
                sRepTable = "R" + lisTable.SelectedItems[0].Text.Substring(1, lisTable.SelectedItems[0].Text.Length - 1);
            }
            else
            {
                sMVTable = lisTable.SelectedItems[0].Text;
                sRepTable = "R" + lisTable.SelectedItems[0].SubItems[1].Text.Substring(1, lisTable.SelectedItems[0].SubItems[1].Text.Length - 1);
            }

            //Create Replication Table
            sbSQL1.Append("CREATE TABLE " + sRepTable + "(\r\n");

            for (i = 0; i < lisColList.Items.Count; i++)
            {
                if (lisColList.Items[i].Checked == false)
                {
                    continue;
                }

                if (lisColList.Items[i].ForeColor == Color.Red  )
                {
                    sbPriKey.Append(lisColList.Items[i].SubItems[2].Text + ", ");
                    sbTrgLn1.Append("         v_" + lisColList.Items[i].SubItems[2].Text + "\t" + sRepTable + "." + lisColList.Items[i].SubItems[2].Text + "%TYPE := :new." + lisColList.Items[i].SubItems[2].Text + ";\n");
                    sbTrgLn2.Append(" '   " + lisColList.Items[i].SubItems[2].Text + "=' || :old." + lisColList.Items[i].SubItems[2].Text + " || ");
                    sbTrgLn3.Append(lisColList.Items[i].SubItems[2].Text + " = :NEW." + lisColList.Items[i].SubItems[2].Text + " AND ");
                    sbTrgLn6.Append(lisColList.Items[i].SubItems[2].Text + " = :OLD." + lisColList.Items[i].SubItems[2].Text + " AND ");
                    sbTrgLn7.Append("v_" + lisColList.Items[i].SubItems[2].Text + " := :OLD." + lisColList.Items[i].SubItems[2].Text + "; ");
                    sbTrgLn8.Append("'" + lisColList.Items[i].SubItems[2].Text + "='''||:OLD." + lisColList.Items[i].SubItems[2].Text + "||''' ' ");
                    sbTrgLn9.Append("'" + lisColList.Items[i].SubItems[2].Text + "='''||:NEW." + lisColList.Items[i].SubItems[2].Text + "||''' ' ");
                    sbTrgLn10.Append("'" + lisColList.Items[i].SubItems[2].Text + "='''||v_" + lisColList.Items[i].SubItems[2].Text + "||''' ' ");
                }

                sDataType = "";
                if (lisColList.Items[i].SubItems[3].Text == "VARCHAR2")
                {
                    if (lisColList.Items[i].SubItems[5].Text == "14")
                    {
                        sDataType = "DATE";
                    }
                    else
                    {
                        sDataType =  "VARCHAR2(" + lisColList.Items[i].SubItems[5].Text + ")";
                    }
                }
                else if (lisColList.Items[i].SubItems[3].Text == "NUMERIC")
                {
                    if (lisColList.Items[i].SubItems[7].Text != "")
                    {
                        sDataType = "NUMBER(" + lisColList.Items[i].SubItems[6].Text + "," + lisColList.Items[i].SubItems[7].Text + ")";
                    }
                    else
                    {
                        sDataType = "NUMBER(" + lisColList.Items[i].SubItems[6].Text + ")";
                    }
                }
                else if (lisColList.Items[i].SubItems[3].Text == "CHAR")
                {
                    sDataType = "CHAR(" + lisColList.Items[i].SubItems[5].Text + ")";
                }
                else if (lisColList.Items[i].SubItems[3].Text == "TIMESTAMP")
                {
                    sDataType = "DATE";
                }
                else
                {
                    sDataType = lisColList.Items[i].SubItems[3].Text;
                }

                if (sDataType == "DATE" && lisColList.Items[i].SubItems[3].Text == "VARCHAR2")
                {
                    if (lisColList.Items[i].ForeColor != Color.Red)
                    {
                        sbTrgLn4.Append("     " + lisColList.Items[i].SubItems[2].Text);
                        sbTrgLn4.Append(" = TO_DATE(DECODE(TRIM(:NEW." + lisColList.Items[i].SubItems[2].Text + "), NULL, NULL, ");
                        sbTrgLn4.Append(":NEW." + lisColList.Items[i].SubItems[2].Text + "), 'YYYYMMDDHH24MISS')");

                        //sbTrgLn4.Append(" = DECODE(TRIM(:NEW." + lisColList.Items[i].SubItems[2].Text + "), NULL, NULL, ");
                        //sbTrgLn4.Append(" TO_DATE(:NEW." + lisColList.Items[i].SubItems[2].Text + ", 'YYYYMMDDHH24MISS'))");
                    }
                    sbTrgLn5.Append(" TO_DATE(DECODE(TRIM(:NEW." + lisColList.Items[i].SubItems[2].Text + "), NULL, NULL, ");
                    sbTrgLn5.Append(":NEW." + lisColList.Items[i].SubItems[2].Text + "), 'YYYYMMDDHH24MISS')");

                    //sbTrgLn5.Append(" DECODE(TRIM(:NEW." + lisColList.Items[i].SubItems[2].Text + "), NULL, NULL, ");
                    //sbTrgLn5.Append(" TO_DATE(:NEW." + lisColList.Items[i].SubItems[2].Text + ", 'YYYYMMDDHH24MISS'))");
                }
                else
                {
                    if (lisColList.Items[i].ForeColor != Color.Red)
                    {
                        sbTrgLn4.Append("     " + lisColList.Items[i].SubItems[2].Text + " = DECODE(TRIM(:NEW." + lisColList.Items[i].SubItems[2].Text + "), NULL, NULL,");
                        sbTrgLn4.Append(" :NEW." + lisColList.Items[i].SubItems[2].Text + ")");

                        sbTrgLn5.Append("DECODE(TRIM(:NEW." + lisColList.Items[i].SubItems[2].Text + "), NULL, NULL, ");
                        sbTrgLn5.Append(":NEW." + lisColList.Items[i].SubItems[2].Text + ")");
                    }
                    else
                    {
                        sbTrgLn5.Append(":NEW." + lisColList.Items[i].SubItems[2].Text);
                    }
                }

                sbSQL1.Append("   " + lisColList.Items[i].SubItems[2].Text + " " + sDataType + ", ");
                sbColList.Append(lisColList.Items[i].SubItems[2].Text);
                if (i < lisColList.Items.Count - 1)
                {
                    if (lisColList.Items[i].ForeColor != Color.Red)
                        sbTrgLn4.Append(",\r\n");
                    sbTrgLn5.Append(", ");
                    sbColList.Append(", ");
                    sbTrgLn8.Append("||' AND '|| ");
                }
                sbSQL1.Append("\r\n");
            }
            sbSQL1.Append("  MES_ERASE_TIME DATE)");

            sbTrgLn3.Remove(sbTrgLn3.Length - 4, 4);
            sbTrgLn6.Remove(sbTrgLn6.Length - 4, 4);
            sbPriKey.Remove(sbPriKey.Length - 2, 2);

            if (txtRepTblTablespace.Text != "")
            {
                sbSQL1.Append("\n TABLESPACE " + txtRepTblTablespace.Text.Trim());
            }
            sbSQL1.Append(";\n");

            sbSQL2.Append("ALTER TABLE " + sRepTable + "\n");
            sbSQL2.Append("   ADD CONSTRAINT " + sRepTable + "_PK\n");
            sbSQL2.Append("   PRIMARY KEY (" + sbPriKey + ") USING INDEX");
            if (txtRepIdxTablespace.Text != "")
            {
                sbSQL2.Append("\n TABLESPACE " + txtRepIdxTablespace.Text.Trim());
            }
            sbSQL2.Append(";\r\n");

            sbSQL4.Append("INSERT INTO " + sRepTable + "\r\n");
            sbSQL4.Append("  (" + sbColList + ") \r\n");
            sbTrgLn11.Append(sbTrgLn5.ToString());
            sbSQL4.Append("  SELECT " + sbTrgLn11.Replace(":NEW.","") + "\r\n");
            sbSQL4.Append("  FROM " + sMVTable + ";\r\n");

            sbSQL3.Append("CREATE OR REPLACE TRIGGER " + sMVTable + "_TRG0 AFTER INSERT OR UPDATE OR DELETE\r\n");
            sbSQL3.Append("  ON " + sMVTable + " REFERENCING NEW AS NEW OLD AS OLD FOR EACH ROW\r\n");
            sbSQL3.Append("DECLARE  v_dml         VARCHAR2(1);\r\n");
            sbSQL3.Append("         v_cnt         NUMBER;\r\n");
            sbSQL3.Append("         v_err_usr_msg varchar2(2000);\r\n");
            sbSQL3.Append("         v_action varchar2(10);\r\n");
            sbSQL3.Append("         err_code varchar2(10);\r\n");
            sbSQL3.Append("         err_msg varchar2(200);\r\n");
            sbSQL3.Append(sbTrgLn1);
            sbSQL3.Append("BEGIN\r\n");
            sbSQL3.Append("  IF UPDATING THEN\r\n");
            sbSQL3.Append("     v_action := 'Updating';\r\n");
            sbSQL3.Append("     UPDATE " + sRepTable + " SET\r\n");
            sbSQL3.Append(sbTrgLn4 + "\r\n");
            sbSQL3.Append("     WHERE " + sbTrgLn3 + ";\r\n");
            sbSQL3.Append("  END IF;\r\n");
            sbSQL3.Append("  IF INSERTING THEN\r\n");
            sbSQL3.Append("     v_action := 'Inserting';\r\n");
            sbSQL3.Append("     v_cnt := 0;\r\n");
            sbSQL3.Append("     SELECT count(*) into v_cnt FROM " + sRepTable + "\r\n");
            sbSQL3.Append("       WHERE " + sbTrgLn3 + ";\r\n");
            sbSQL3.Append("   IF v_cnt = 0 THEN\r\n");
            sbSQL3.Append("     INSERT INTO " + sRepTable + "\r\n");
            sbSQL3.Append("       (" + sbColList + ")\r\n");
            sbSQL3.Append("     VALUES ( " + sbTrgLn5 + ");\r\n");
            sbSQL3.Append("   ELSE UPDATE " + sRepTable + " SET\r\n");
            sbSQL3.Append(sbTrgLn4 + ",\r\n");
            sbSQL3.Append("     MES_ERASE_TIME = NULL\r\n");
            sbSQL3.Append("     WHERE " + sbTrgLn3 + ";\r\n");
            sbSQL3.Append("   END IF;\r\n");
            sbSQL3.Append("  END IF;\r\n");
            sbSQL3.Append("  IF DELETING THEN\r\n");
            sbSQL3.Append("     v_action := 'Deleting';\r\n");
            sbSQL3.Append("     DELETE FROM " + sRepTable + "\r\n");
            sbSQL3.Append("     WHERE " + sbTrgLn6 + ";\r\n");
            sbSQL3.Append("  END IF;\r\n");
            sbSQL3.Append("EXCEPTION\r\n");
            sbSQL3.Append("  WHEN others THEN\r\n");
            sbSQL3.Append("     err_code := sqlcode;\r\n");
            sbSQL3.Append("     err_msg := substr(SQLERRM, 1, 200);\r\n");
            sbSQL3.Append("     v_err_usr_msg := " + sbTrgLn2 + "\r\n");
            sbSQL3.Append("         ' MSG=fail to execute trigger on ' || v_action ||\r\n");
            sbSQL3.Append("         ' from table, " + sRepTable + ".';\r\n");
            sbSQL3.Append("     insert into TRIG_ERR_TAB\r\n");
            sbSQL3.Append("         (ERR_DATE, ERR_NUM, ERR_TAB_NAM, ERR_ORA_MSG, ERR_USR_MSG)\r\n");
            sbSQL3.Append("         values (SYSDATE,err_code, '" + sRepTable + "', err_msg, v_err_usr_msg);\r\n");
            sbSQL3.Append("END;\r\n");

            return sbSQL1.ToString() + "\r\n" + sbSQL2.ToString() + "\r\n" + sbSQL4.ToString() + "\r\n" + sbSQL3.ToString();
        }


        private bool save_file_class(string sFileName)
        {
            try
            {
                FileStream fs = new FileStream(sFileName + ".sql", FileMode.Create);
                StreamWriter sw = new StreamWriter(fs, Encoding.GetEncoding(0));
                sw.Write(txtScript.Text);
                sw.Close();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message, "SQL Save Fail", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                return false;
            }

            return true;
        }

        public void set_table_info(clsTableInfo table)
        {
            m_table = table;
        }

        public void set_db_manager(clsDBManager db_manager)
        {
            m_src_db_manager = db_manager;
        }

#endregion

        private void btnClose_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void btnCreateView_Click(object sender, EventArgs e)
        {
            Form f;
            int i;
            bool isLoaded;
            isLoaded = false;
            for (i = 0; i < this.ParentForm.MdiChildren.Length; i++)
            {
                if (this.ParentForm.MdiChildren[i].Name == "frmDBViewTrig")
                    isLoaded = true;
            }
            if (!isLoaded)
            {
                f = new frmDBViewTrig(this);
                f.MdiParent = this.ParentForm;
                f.Show();
            }
            else
                this.ParentForm.MdiChildren[1].Activate();
        }

    }
}