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
    public partial class frmDBViewTrig : BaseForm01
    {
#region "Variables"


        //Source DB
        private clsTableInfo m_table = null;
        //private intGenerator m_generator = null;
        private bool m_load_flag = false;
        private clsDBManager m_src_db_manager = null;
        private AMGV.DBTYPE m_src_db_type = AMGV.DBTYPE.ORACLE;

        //Target DB
        private clsDBManager m_tar_db_manager = null;
        private bool m_tar_db_connect_routine = false;
        //private AMGV.DBTYPE m_tar_db_type = AMGV.DBTYPE.ORACLE;

        private StringBuilder sbSQL1 = new StringBuilder();
        private StringBuilder sbSQL2 = new StringBuilder();

#endregion

        public frmDBViewTrig(frmDBReplicator frmRep)
        {
            InitializeComponent();
            txtTarDBName.Text = frmRep.txtTarDBName.Text;
            txtTarUserID.Text = frmRep.txtTarUserID.Text;
            txtTarPassword.Text = frmRep.txtTarPassword.Text;
        }
        public frmDBViewTrig()
        {
            InitializeComponent();
        }

#region "Form Event"

        private void frmDBViewTrig_Load(object sender, EventArgs e)
        {
        }

        private void frmDBViewTrig_Activated(object sender, EventArgs e)
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
            string data_source;
            string db_name;
            string user_id;
            string password;
            AMGV.DBTYPE db_type = AMGV.DBTYPE.ORACLE;
            
            m_table = new clsTableInfo();

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
                m_tar_db_connect_routine = false;
                m_tar_db_manager.dispose();
                MPCF.ShowMsgBox("Fail to connect DB." + " " + 
                                    m_tar_db_manager.get_data_source()  + " " +
                                    m_tar_db_manager.get_db_name() + " " +
                                    m_tar_db_manager.get_user_id() + " " +
                                    m_tar_db_manager.get_db_type());
                return;
            }

            m_tar_db_manager.set_db_view_type(AMGV.DB_VIEW_TYPE.TABLE);
            m_tar_db_connect_routine = true;

            MPCF.ShowMsgBox("Success to connect database." + " " +
                                m_tar_db_manager.get_data_source() + " " +
                                m_tar_db_manager.get_db_name() + " " +
                                m_tar_db_manager.get_user_id() + " " +
                                m_tar_db_manager.get_db_type());

            GetAllTables();
        }

        private void btnDisconnect_Click(object sender, EventArgs e)
        {
            if(m_tar_db_connect_routine == true)
            {
                m_tar_db_manager.db_disconnect();
                m_tar_db_connect_routine = false;
            }

            lisTable.Items.Clear();

            MPCF.ShowMsgBox("Disconnet to database.");
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Dispose();
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            int iRet;
            string sViewName, sTrigName;
            OleDbCommand tarCommand;

            object obj1 = null;

            tarCommand = null;

            if (MPCF.ShowMsgBox(MPCF.GetMessage(252), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes) return;

            if (rbView.Checked == true)
            {
                sViewName = lisTable.SelectedItems[0].Text.ToString().ToUpper().Trim();
                sTrigName = lisTable.SelectedItems[0].SubItems[1].Text.ToString().ToUpper().Trim() + "_TRG0";
            }
            else
            {
                sViewName = "MPL_" + lisTable.SelectedItems[0].Text.ToString().ToUpper().Trim();
                sTrigName = lisTable.SelectedItems[0].Text.ToString().ToUpper().Trim() + "_TRG0";
            }

            //Drop
            //if (rbView.Checked == true)
            //{
                try
                {
                    tarCommand = new OleDbCommand();
                    tarCommand.Connection = m_tar_db_manager.get_db_connection();

                    tarCommand.CommandText = "SELECT COUNT(*) FROM USER_VIEWS WHERE VIEW_NAME = '" + sViewName + "' ";
                    obj1 = tarCommand.ExecuteScalar();
                    iRet = int.Parse(obj1.ToString());
                    if (iRet > 0)
                    {
                        tarCommand.CommandText = "DROP VIEW " + sViewName;
                        iRet = tarCommand.ExecuteNonQuery();
                    }
                    tarCommand.CommandText = "SELECT COUNT(*) FROM USER_TRIGGERS WHERE TRIGGER_NAME = '" + sTrigName + "' ";
                    obj1 = tarCommand.ExecuteScalar();
                    iRet = int.Parse(obj1.ToString());
                    if (iRet > 0)
                    {
                        tarCommand.CommandText = "DROP TRIGGER " + sTrigName;
                        iRet = tarCommand.ExecuteNonQuery();
                    }
                    tarCommand.Dispose();
                    MPCF.ShowMsgBox("View and Trigger Delete Complete");
                }
                catch (Exception ex)
                {
                    MPCF.ShowMsgBox(ex.Message);
                }
                finally
                {
                    tarCommand.Dispose();
                }
            //}

            GetAllTables();
        }

        private void btnExecute_Click(object sender, EventArgs e)
        {
            int iRet;
            string sCode;
            string sTable;
            OleDbCommand tarCommand;

            if (rbView.Checked == true)
            {
                sTable = lisTable.SelectedItems[0].SubItems[1].Text;
            }
            else
            {
                sTable = lisTable.SelectedItems[0].Text;
            }

            this.Cursor = Cursors.WaitCursor;

            tarCommand = new OleDbCommand();
            tarCommand.Connection = m_tar_db_manager.get_db_connection();
            GetViewScript();
            try
            {
                sCode = sbSQL1.ToString() ;
                if (sCode.Trim() == "")
                    return;
                sCode = sCode.Replace(";", "");
                tarCommand.CommandText = sCode;
                iRet = tarCommand.ExecuteNonQuery();

                if (sbSQL2.ToString().Trim() == "")
                {
                    return;
                }
                else
                {
                    sCode = "CREATE TABLE TEMP_" + sTable + " AS SELECT * FROM " + sTable;
                    tarCommand.CommandText = sCode;
                    iRet = tarCommand.ExecuteNonQuery();

                    sCode = "TRUNCATE TABLE " + sTable;
                    tarCommand.CommandText = sCode;
                    iRet = tarCommand.ExecuteNonQuery(); 

                    sCode = sbSQL2.ToString();
                    tarCommand.CommandText = sCode;
                    iRet = tarCommand.ExecuteNonQuery();

                    sCode = "INSERT INTO " + sTable + " SELECT * FROM TEMP_" + sTable;
                    tarCommand.CommandText = sCode;
                    iRet = tarCommand.ExecuteNonQuery();

                    sCode = "DROP TABLE TEMP_" + sTable + " CASCADE CONSTRAINTS PURGE";
                    tarCommand.CommandText = sCode;
                    iRet = tarCommand.ExecuteNonQuery();

                    this.Cursor = Cursors.Default;
                    MPCF.ShowMsgBox("Successful created view and triggers", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Information);
                }
            }
            catch (Exception ex)
            {
                this.Cursor = Cursors.Default;
                MPCF.ShowMsgBox(ex.Message, "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
            }
            finally
            {
                tarCommand.Dispose();
            }

            this.Cursor = Cursors.Default;
            GetAllTables();
        }

        private void btnCodeGen_Click(object sender, EventArgs e)
        {
            string sCode;


            if (txtViewName.Text.Trim() == "")
            {
                MPCF.ShowMsgBox("Input view Name", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                txtViewName.Focus();
                return;
            }

            if (lisTable.SelectedItems.Count == 0)
            {
                MPCF.ShowMsgBox("Select the table", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                lisTable.Focus();
                return;
            }

            sCode = GetViewScript();

            if (sCode.Trim() != "")
            {
                txtScript.Text = sCode;
                tabColumns.SelectedIndex = 2;
            }
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
                if (rbTable.Checked == true)
                {
                    txtViewName.Text = lisTable.SelectedItems[0].Text;
                    if (lisTable.SelectedItems[0].SubItems[1].Text == "TRG0")
                    {
                        btnCodeGen.Enabled = true;
                        btnDelete.Enabled = true;
                        btnExecute.Enabled = false;
                        txtViewName.Enabled = false;
                        txtWhere.Enabled = false;
                        txtLogTable.Enabled = false;
                        spdViewCol.Enabled = true;
                    }
                    else
                    {
                        btnCodeGen.Enabled = true;
                        btnDelete.Enabled = false;
                        btnExecute.Enabled = true;
                        txtViewName.Enabled = true;
                        txtWhere.Enabled = true;
                        txtLogTable.Enabled = true;
                        spdViewCol.Enabled = true;
                    }
                }
                else
                {
                    btnCodeGen.Enabled = true;
                    btnDelete.Enabled = true;
                    btnExecute.Enabled = false;
                    txtViewName.Enabled = false;
                    txtWhere.Enabled = false;
                    txtLogTable.Enabled = false;
                    spdViewCol.Enabled = true;
                }

                System.Windows.Forms.Cursor.Current = Cursors.Default;

            }
        }

        private void tabColumns_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (m_tar_db_connect_routine == false)
            {
                tabColumns.SelectedIndex = 0;
            }
        }

        private void rbTable_CheckedChanged(object sender, EventArgs e)
        {
            if (m_tar_db_connect_routine == true && rbTable.Checked == true)
            {
                rbView.Checked = false;
                grbTableList.Text = "Table List";
                GetAllTables();
            }
        }
        
        private void lisColList_ItemCheck(object sender, ItemCheckEventArgs e)
        {
            if (e.Index < 0)
            {
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
            if (m_tar_db_connect_routine == true && rbView.Checked == true)
            {
                rbTable.Checked = false;
                grbTableList.Text = "View List";
                GetAllTables();
            }
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
            MPCF.ClearList(spdColList);
            MPCF.ClearList(spdViewCol);
            txtWhere.Text = "";
            spdViewCol.Sheets[0].RowCount = 300;
            tabColumns.SelectedIndex = 1;

            adoReader = null;
            adoCommand = null;

            if (rbTable.Checked == true)
            {
                if (m_tar_db_manager.get_is_connect() == false)
                    return false;

                adoCommand = new OleDbCommand();
                adoCommand.Connection = m_tar_db_manager.get_db_connection();

                strQuery = strQuery.Append("SELECT a.table_name, decode(b.table_name, NULL, ' ', 'TRG0') FROM user_tables a, user_mviews c, ");
                strQuery = strQuery.Append("(SELECT table_name FROM user_triggers WHERE trigger_name = table_name ||'_TRG0') b ");
                strQuery = strQuery.Append("WHERE a.table_name = b.table_name (+) ");
                strQuery = strQuery.Append("AND a.table_name = c.mview_name (+) AND c.mview_name is null ");
                strQuery = strQuery.Append("ORDER BY a.table_name ");
                adoCommand.CommandText = strQuery.ToString();

                adoReader = adoCommand.ExecuteReader();

                while (adoReader.Read())
                {
                    if (adoReader.GetString(0).Length > 5)
                    {
                        if (adoReader.GetString(0).Substring(0, 5) != "MLOG$")
                        {
                            ListViewItem item1 = new ListViewItem(adoReader.GetString(0).Trim());
                            item1.SubItems.Add(adoReader.GetString(1).Trim());
                            lisTable.Items.Add(item1);
                        }
                    }
                    else
                    {
                        ListViewItem item1 = new ListViewItem(adoReader.GetString(0).Trim());
                        item1.SubItems.Add(adoReader.GetString(1).Trim());
                        lisTable.Items.Add(item1);
                    }
                }
                btnDelete.Enabled = false;
            }
            else if (rbView.Checked == true)
            {
                if (m_tar_db_manager.get_is_connect() == false)
                    return false;

                adoCommand = new OleDbCommand();

                adoCommand.Connection = m_tar_db_manager.get_db_connection();

                strQuery = strQuery.Append("SELECT view_name, ' ' FROM user_views WHERE view_name like ");
                strQuery = strQuery.Append("'MPL_%' ORDER BY view_name ASC");
                adoCommand.CommandText = strQuery.ToString();
                adoReader = adoCommand.ExecuteReader();

                while (adoReader.Read())
                {
                    ListViewItem item1 = new ListViewItem(adoReader.GetString(0).Trim());
                    item1.SubItems.Add(adoReader.GetString(1).Trim());
                    lisTable.Items.Add(item1);
                }
                btnDelete.Enabled = true;
            }
            adoCommand.Dispose();
            return true;
        }

        private bool GetAllFields(string tableName)
        {

            int i, j;
            int iStart, iEnd, iMaxRow;
            int iCntBracket, iCntDQuote, iCntSQuote, iCntCommas, iCntSpace, iCntNick;
            string sText, sColName, sNickTable;
            string sViewName;
            DataRow[] schemaRow;
            DataRow[] viewRow;
            DataRow[] schemaPKRow;
            clsFieldInfo fieldInfo = null;
            FarPoint.Win.Spread.SheetView sheetX;
            FarPoint.Win.Spread.SheetView sheetY;
            int iRow;

            OleDbDataReader adoReader;
            OleDbCommand adoCommand;

            adoReader = null;
            adoCommand = null;

            try
            {
                // Clear ListView Items
                tabColumns.SelectedIndex = 1;

                // Getting Field Info
                AMGV.GetFieldInfo = true;
                MPCF.ClearList(spdColList);
                MPCF.ClearList(spdViewCol);
                txtWhere.Clear();
                txtViewName.Clear();
                sheetX = spdColList.ActiveSheet;
                sheetY = spdViewCol.ActiveSheet;
                sheetY.RowCount = 300;

                if (rbTable.Checked == true)
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

                    if (m_table.add_field_info(schemaRow, schemaPKRow) == false)
                    {
                        return false;
                    }

                    iRow = 0;
                    for (i = 0; i < m_table.Count; i++)
                    {
                        fieldInfo = (clsFieldInfo)m_table[i];
                        if (fieldInfo.Selected == true)
                        {
                            sheetY.Cells[iRow, 1].Value = fieldInfo.FieldName;
                            sheetY.Cells[iRow, 1].Locked = true;
                            sheetY.Cells[iRow, 1].ForeColor = Color.Red;
                            iRow++;
                        }
                        sheetX.RowCount++;
                        sheetX.Cells[i, 0].Value = fieldInfo.FieldName;
                        sheetX.Cells[i, 1].Value = clsCommon.ConvertDataTypeToString(fieldInfo.DataType);
                    }
                }
                else
                {
                    sViewName = tableName;
                    txtViewName.Text  = sViewName.Substring(4);
                    if (m_tar_db_manager.get_is_connect() == false)
                        return false;

                    adoCommand = new OleDbCommand();
                    adoCommand.Connection = m_tar_db_manager.get_db_connection();
                    adoCommand.CommandText = "SELECT text FROM user_views WHERE view_name = '" + sViewName + "'";
                    adoReader = adoCommand.ExecuteReader();
                    adoReader.Read();
                    sText = adoReader.GetString(0).Trim();
                    sText = sText.Remove(0, 7);
                    iStart = sText.ToUpper().IndexOf("FROM", 0);
                    iEnd = sText.ToUpper().IndexOf("WHERE", iStart + 1);
                    txtWhere.Text = "";
                    if (iEnd < 0)
                        iEnd = sText.Length;
                    else
                        txtWhere.Text = sText.Substring(iEnd + 6, sText.Length - iEnd - 6).Trim();
                    tableName = sText.ToUpper().Substring(iStart + 5, iEnd - iStart - 5).Trim();
                    if (tableName.IndexOf(",") > 0)
                    {
                        MPCF.ShowMsgBox("View Contain More than one Tables", "Replication View", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                        return false;
                    }
                    sText = sText.Replace("\n", " ");
                    sText = sText.Replace("\r", " ");
                    sText = sText.Substring(0, iStart - 1).Trim();
                    sNickTable = "";
                    iStart = tableName.IndexOf(" ");
                    if (iStart > 0)
                    {
                        sNickTable = tableName.Substring(iStart + 1, tableName.Length - iStart - 1).Trim()+".";
                        tableName = tableName.Substring(0, iStart).Trim();
                    }
                    lisTable.SelectedItems[0].SubItems[1].Text = tableName;
                    // if (sNickTable != "")
                    //    sText = sText.Replace(sNickTable + ".", "");
                    iRow = 0;
                    iCntBracket = 0;
                    iCntCommas = 0;
                    iCntDQuote = 0;
                    iCntSpace = 0;
                    iCntSQuote = 0;
                    iStart = 0;
                    if (sNickTable == "")
                        iCntNick = -1;
                    else
                        iCntNick = sText.ToUpper().IndexOf(sNickTable.ToUpper(), 0);
                    for (i = 0; i < sText.Length; i++ )
                    {
                        if (iCntNick == i)
                        {
                            if (iCntDQuote == 0 && iCntSQuote == 0)
                            {
                                if (i == 0)
                                    sText = " ".PadRight(sNickTable.Length, ' ') + sText.Substring(sNickTable.Length);
                                else
                                    sText = sText.Substring(0, i).PadRight(i + sNickTable.Length, ' ') + sText.Substring(i + sNickTable.Length);
                            }
                            iCntNick = sText.ToUpper().IndexOf(sNickTable.ToUpper(), iCntNick + 1);
                        }

                        if (sText.Substring(i, 1) == "(")
                            if (iCntDQuote == 0 && iCntSQuote == 0)
                                iCntBracket++;
                        if (sText.Substring(i, 1) == ")")
                            if (iCntDQuote == 0 && iCntSQuote == 0)
                                iCntBracket--;
                        if (sText.Substring(i, 1) == "\"" && iCntSQuote == 0)
                            if (iCntDQuote == 0)
                                iCntDQuote = 1;
                            else
                                iCntDQuote = 0;
                        if (sText.Substring(i, 1) == "'" && iCntDQuote == 0)
                            if (iCntSQuote == 0)
                                iCntSQuote = 1;
                            else
                                iCntSQuote = 0;

                        if (sText.Substring(i, 1) == " ")
                        {
                            if (i == iStart)
                                iStart = i + 1;
                            else
                            {
                                if (iCntDQuote == 0 && iCntSQuote == 0 && iCntBracket == 0)
                                    iCntSpace = i;
                            }
                        }
                        if (sText.Substring(i, 1) == ",")
                            if (iCntDQuote == 0 && iCntSQuote == 0 && iCntBracket == 0)
                                iCntCommas = 1;

                        if (iCntCommas == 1)
                        {
//                            if (iCntSpace == 0)
                                sColName = sText.Substring(iStart, i - iStart).Trim();
//                            else
//                                sColName = sText.Substring(iStart, iCntSpace - iStart).Trim();
//                            if (sColName.Length > 2)
//                                if (sColName.Substring(sColName.Length - 2, 2).ToUpper() == "AS")
//                                    sColName = sColName.Substring(0, sColName.Length - 2).Trim();
                            sheetY.Cells[iRow, 1].Value = sColName;
                            iRow++;
                            iCntBracket = 0;
                            iCntCommas = 0;
                            iCntDQuote = 0;
                            iCntSpace = 0;
                            iCntSQuote = 0;
                            iStart = i + 1;
                            j = i + 1;
                            do
                            {
                                if (sText.Substring(j, 1) == " ")
                                {
                                    j++;
                                    iStart = j;
                                    i = j-1;
                                }
                                else
                                    j = sText.Length;
                            } while (j < sText.Length);
                        }
                    }
                    if (iStart < sText.Length)
                    {
                        sColName = sText.Substring(iStart, i - iStart).Trim();
                        sheetY.Cells[iRow, 1].Value = sColName;
                    }
                    iMaxRow = iRow;
                    m_table.Clear();
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
                    if (m_table.add_field_info(schemaRow, schemaPKRow) == false)
                    {
                        return false;
                    }
                    for (i = 0; i < m_table.Count; i++)
                    {
                        fieldInfo = (clsFieldInfo)m_table[i];
                        sheetX.RowCount++;
                        sheetX.Cells[i, 0].Value = fieldInfo.FieldName.ToUpper();
                        sheetX.Cells[i, 1].Value = clsCommon.ConvertDataTypeToString(fieldInfo.DataType);

                        if (fieldInfo.Selected == true)
                        {
                            for (iRow = 0; iRow < iMaxRow; iRow++)
                            {
                                if (sheetY.Cells[iRow, 1].Value.ToString().ToUpper() == fieldInfo.FieldName.ToUpper() ||
                                    sheetY.Cells[iRow, 1].Value.ToString().ToUpper() == "\"" + fieldInfo.FieldName.ToUpper() + "\"")
                                {
                                    sheetY.Cells[iRow, 1].Locked = true;
                                    sheetY.Cells[iRow, 1].ForeColor = Color.Red;
                                    if (sheetY.Cells[iRow, 1].Value.ToString().ToUpper() == "\"" + fieldInfo.FieldName.ToUpper() + "\"")
                                        sheetY.Cells[iRow, 1].Value = fieldInfo.FieldName;
                                }
                            }
                        }
                    }

                    m_table.Clear();
                    viewRow = m_tar_db_manager.get_field_list(sViewName);
                    if (viewRow == null)
                    {
                        return false;
                    }
                    if (m_table.add_field_info(viewRow, schemaPKRow ) == false)
                    {
                        return false;
                    }

                    iRow = 0;
                    for (i = 0; i < m_table.Count; i++)
                    {
                        fieldInfo = (clsFieldInfo)m_table[i];
                        sheetY.Cells[iRow, 0].Value = fieldInfo.FieldName.ToUpper();
                        iRow++;
                    }
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

        private int FindNextColumn(int iStart, int iEnd, string sText)
        {
            string sColName;
            int cnt, i;

            sColName = sText.Substring(iStart, iEnd).Trim();
            cnt = 0;
            i = -1;
            do
            {
                i = sColName.IndexOf("(", i + 1);
                if (i > 0)
                    cnt++;
            } while (i > 0);
            while (cnt > 0)
                {
                    iEnd = sText.IndexOf(")", iEnd + 1);
                    cnt--;
                }
            return iEnd;
        }

        private string GetViewScript()
        {
            StringBuilder sb_script;
            StringBuilder sbTrgLn1;
            StringBuilder sbTrgLn2;
            StringBuilder sbTrgLn3;
            string sTable, sView;
            int  iIdRow;

            FarPoint.Win.Spread.SheetView sheetY;
            int iRow, iRow2;

            if (btnExecute.Text == "Execute" && txtViewName.Text.Trim() == "")
            {
                MPCF.ShowMsgBox("Input View Name", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                txtViewName.Focus();
                return "";
            }

            if (btnExecute.Text == "Execute" && txtLogTable.Text.Trim() == "")
            {
                MPCF.ShowMsgBox("Input Log Table Name", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                txtLogTable.Focus();
                return "";
            }

            if (lisTable.SelectedItems.Count == 0)
            {
                MPCF.ShowMsgBox("Select the table/view", "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                lisTable.Focus();
                return "";
            }

            sb_script = new StringBuilder();
            sbSQL1 = new StringBuilder();
            sbSQL2 = new StringBuilder();
            sbTrgLn1 = new StringBuilder();
            sbTrgLn2 = new StringBuilder();
            sbTrgLn3 = new StringBuilder();
            sbTrgLn3.Append("'");
            if (rbView.Checked == true)
            {
                sTable = lisTable.SelectedItems[0].SubItems[1].Text;
            }
            else
            {
                sTable = lisTable.SelectedItems[0].Text;
            }
            sView = "MPL_" + txtViewName.Text.Trim();

            sbSQL1.Append("CREATE OR REPLACE VIEW " + "MPL_" + txtViewName.Text.Trim() + " (\n   ");

            sheetY = spdViewCol.ActiveSheet;
            sheetY.RowCount = 300;

            iIdRow = -1;
            for (iRow = 0; iRow < 300; iRow++)
            {
                if (sheetY.Cells[iRow, 0].Text.Trim().ToUpper() == "ID")
                    iIdRow = iRow;
            }

            if (iIdRow != -1)
                sbSQL1.Append("\"" + sheetY.Cells[iIdRow, 0].Text.Trim() + "\", ");

            for (iRow = 0; iRow < 300; iRow ++)
            {
                if (sheetY.Cells[iRow, 0].Text.Trim() != "")
                {
                    if (sheetY.Cells[iRow, 0].Text.Trim().IndexOf("\"") > 0)
                    {
                        MPCF.ShowMsgBox("View Column Cannot contain \"", "Entry Error", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                        return "";
                    }
                    if (iRow != iIdRow )
                        sbSQL1.Append("\"" + sheetY.Cells[iRow, 0].Text.Trim() + "\", ");
                }
                if (sheetY.Cells[iRow, 1].Locked == true)
                {
                    for (iRow2 = 0; iRow2 < 300; iRow2++)
                    {
                        if (iRow2 != iRow)
                        {
                            if (sheetY.Cells[iRow, 1].Text.ToUpper().Trim() == sheetY.Cells[iRow2, 1].Text.ToUpper().Trim())
                            {
                                MPCF.ShowMsgBox("Cannot have duplicate primary key column. => " + sheetY.Cells[iRow2, 1].Text);
                                spdViewCol.Focus();
                                return "";
                            }
                        } 
                    }
                }
            }
            sbSQL1.Remove(sbSQL1.Length - 2, 2);
            sbSQL1.Append(") \n" + "   as SELECT ");
            if (iIdRow != -1)
                sbSQL1.Append(sheetY.Cells[iIdRow, 1].Text.Trim() + ", ");

            for (iRow = 0; iRow < 300; iRow++)
            {
                if (sheetY.Cells[iRow, 0].Text.Trim() != "" && sheetY.Cells[iRow, 1].Text.Trim() == "")
                {
                    MPCF.ShowMsgBox("Must enter source information for row number " + (iRow + 1), "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                    lisTable.Focus();
                    return "";
                }
                if (sheetY.Cells[iRow, 0].Text.Trim() == "" && sheetY.Cells[iRow, 1].Text.Trim() != "")
                {
                    MPCF.ShowMsgBox("Must enter View Column Name for row number " + (iRow + 1), "SQL Generator", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                    lisTable.Focus();
                    return "";
                }
                if (sheetY.Cells[iRow, 1].Text.Trim() != "")
                {
                    if (iRow != iIdRow)
                        sbSQL1.Append(sheetY.Cells[iRow, 1].Text.Trim() + ", ");
                    //if (sheetY.Cells[iRow, 1].ForeColor == Color.Red)
                    if (sheetY.Cells[iRow, 1].Locked == true)
                    {
                        sbTrgLn1.Append("         v_" + sheetY.Cells[iRow, 1].Text.Trim().Replace(" ","_") + "\t" + sTable + "." +sheetY.Cells[iRow, 1].Text.Trim()+"%TYPE := :new." + sheetY.Cells[iRow, 1].Text.Trim()+";\r\n" );
                        sbTrgLn2.Append("      v_" + sheetY.Cells[iRow, 1].Text.Trim().Replace(" ", "_") + " := :OLD." + sheetY.Cells[iRow, 1].Text.Trim() + "; \r\n");
                        sbTrgLn3.Append(sheetY.Cells[iRow, 0].Text.Trim() + "='''||v_" + sheetY.Cells[iRow, 1].Text.Trim().Replace(" ", "_") + "||''' and ");	
                    }
                }
            }

            sbSQL1.Remove(sbSQL1.Length - 2, 2);
            sbTrgLn3.Remove(sbTrgLn3.Length - 4, 4);
            sbTrgLn3.Append("' ");
            sbSQL1.Append("\n FROM " + sTable );
            if (txtWhere.Text.Trim() != "")
                sbSQL1.Append(" WHERE " + txtWhere.Text.Trim());
            sbSQL1.Append (";\n\n");

            sbSQL2.Append("CREATE OR REPLACE TRIGGER " + sTable + "_TRG0 AFTER INSERT OR UPDATE OR DELETE\r\n");
            sbSQL2.Append("  ON " + sTable + " REFERENCING NEW AS NEW OLD AS OLD FOR EACH ROW\r\n");
            sbSQL2.Append("DECLARE  v_dml         VARCHAR2(1);\r\n");
            sbSQL2.Append("         v_changekey   VARCHAR2(1);\r\n");
            sbSQL2.Append("         v_cnt         NUMBER;\r\n");
            sbSQL2.Append(sbTrgLn1);
            sbSQL2.Append("BEGIN\r\n");
            sbSQL2.Append("  IF INSERTING THEN\r\n");
            sbSQL2.Append("     v_dml := 'I';\r\n");
            sbSQL2.Append("  ELSIF UPDATING THEN\r\n");
            sbSQL2.Append("       v_dml := 'U';\r\n");
            sbSQL2.Append("  ELSIF DELETING THEN\r\n");
            sbSQL2.Append("       v_dml := 'D';\r\n");
            sbSQL2.Append(sbTrgLn2);
            sbSQL2.Append("  END IF;\r\n");
            sbSQL2.Append("     mppdb_log_data_ins_pkg.mppdb_log_data_ins_prc ('" + sView + "',\r\n");
            sbSQL2.Append("       " + sbTrgLn3 + ", v_dml);\r\n");
            sbSQL2.Append("END;\r\n");
            sbSQL2.Append("\r\n");

            return sbSQL1.ToString() + "\r\n" + sbSQL2.ToString();
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

        private void spdViewCol_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {//qqqq
            int iRow;

            for (iRow = 0; iRow < spdViewCol_Sheet1.RowCount; iRow++)
            {
                if (spdViewCol_Sheet1.Cells[iRow, 1].Locked == true)
                {
                    if (e.Row != iRow)
                    {
                        if (spdViewCol_Sheet1.Cells[e.Row, e.Column].Text.ToUpper().Trim() == spdViewCol_Sheet1.Cells[iRow, 0].Text.ToUpper().Trim())
                        {
                            MPCF.ShowMsgBox("Cannot have duplicate primary key column. => " + spdViewCol_Sheet1.Cells[e.Row, e.Column].Text);
                            spdViewCol_Sheet1.Cells[e.Row, e.Column].Text = "";
                            return;
                        }
                    }
                }
            }
        }
    }
}