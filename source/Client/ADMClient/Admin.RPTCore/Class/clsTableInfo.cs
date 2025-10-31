using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Data;
using System.Data.OleDb;
using System.Windows.Forms;

using Miracom.CliFrx;

//-----------------------------------------------------------------------------
//
//   System      : DEV
//   File Name   : clsTableInfo.vb
//   Description :
//
//   MES Version : 4.0.0
//
//   Function List
//       -
//
//   Detail Description
//       -
//
//   History
//       - **** Do Not Modify in Site!!! ****
//       -
//
//   Copyright(C) 1998-2007 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

namespace Admin.RPTCore
{
    public class clsTableInfo : ArrayList
    {

        public clsTableInfo()
        {
            init();
        }

        public void init()
        {
            Clear();
        }

        private string m_sTableName = "";
        private int m_iSelectedCount = 0;
        private AMGV.DBTYPE m_eDBType;
    	
        public string TableName
        {
            get
            {
                return m_sTableName;
            }
            set
            {
                m_sTableName = value;
            }
        }
    	
        public int SelectedCount
        {
            get
            {
                return m_iSelectedCount;
            }
            set
            {
                m_iSelectedCount = value;
            }
        }
    	
        public AMGV.DBTYPE DBType
        {
            get
            {
                return m_eDBType;
            }
            set
            {
                m_eDBType = value;
            }
        }
    	
    	
        public bool add_field_info(DataRow[] schemaRow, DataRow[] schemaPKRow)
        {
    		
            int i = 0;
            int j = 0;
            bool bPrimaryKey = false;
            int iSequence = 0;
            string sFieldName = "";
            string sDataType = "";
            AMGV.DATATYPE eDataType = AMGV.DATATYPE.UNKNOWN_TYPE;
            bool bIsNull = false;
            int iSize = 0;
            int iNumericScale = 0;
            int iPrecision = 0;
    		
            try
            {
                init();
    			
                SelectedCount = schemaPKRow.Length;
    			
                for (i = 0; i < schemaRow.Length; i++)
                {
                    bPrimaryKey = false;

                    // FieldName
                    if (schemaRow[i][3] != null)
                    {
                        sFieldName = schemaRow[i][3].ToString();
                    } else
                        continue;

                    // Is PrimaryKey
                    for (j = 0; j < SelectedCount; j++)
                    {
                        if (schemaPKRow[j][3].ToString() == sFieldName)
                        {
                            bPrimaryKey = true;
                            break;
                        }
                    }

                    // Sequence
                    if (schemaRow[i][6] != null)
                    {
                        iSequence = MPCF.ToInt(schemaRow[i][6]);
                    } else
                        continue;

                    // DataType
                    if (schemaRow[i][11] != null)
                    {
                        OleDbType ColType = (OleDbType)(Convert.ToDecimal(schemaRow[i][11]));

                        sDataType = ColType.ToString().ToUpper();

                        if (sDataType == "WCHAR" && MPCF.ToInt(schemaRow[i][13]) == 1)
                            sDataType = "CHAR";

                        //sDataType = schemaRow[i][11].ToString().ToUpper();
                        if (sDataType == "CHAR")
                        {
                            if (MPCF.ToInt(schemaRow[i][9]) == 16 || MPCF.ToInt(schemaRow[i][13]) == 1)
                            {
                                eDataType = AMGV.DATATYPE.CHAR_TYPE;
                            }
                            else
                            {
                                eDataType = AMGV.DATATYPE.VARCHAR_TYPE;
                            }
                        }
                        else
                        {
                            eDataType = clsCommon.ConvertDataTypeToEnum(sDataType);
                        }
                    } else
                        continue;

                    if (schemaRow[i][10] != null)
                    {
                        if (schemaRow[i][10].ToString().ToUpper() == "TRUE")
                        {
                            bIsNull = true;
                        }
                        else
                        {
                            bIsNull = false;
                        }
                    } else
                        continue;

                    // Size
                    if (schemaRow[i][13] != null)
                    {
                        iSize = MPCF.ToInt(schemaRow[i][13]);
                    }
                    else
                    {
                        iSize = - 1;
                    }

                    // Numeric Scale
                    if (schemaRow[i][15] != null)
                    {
                        iNumericScale = MPCF.ToInt(schemaRow[i][15]);
                    }
                    else
                    {
                        iNumericScale = - 1;
                    }

                    // Precision
                    if (schemaRow[i][16] != null)
                    {
                        iPrecision = MPCF.ToInt(schemaRow[i][16]);
                    }
                    else
                    {
                        iPrecision = - 1;
                    }
    				
                    clsFieldInfo fieldInfo = new clsFieldInfo();
                    fieldInfo.Selected = bPrimaryKey;
                    fieldInfo.Sequence = iSequence;
                    fieldInfo.FieldName = sFieldName;
                    fieldInfo.DataType = eDataType;
                    fieldInfo.IsNull = bIsNull;
                    fieldInfo.Size = iSize;
                    fieldInfo.NumericScale = iNumericScale;
                    fieldInfo.Precision = iPrecision;
    				
                    Add(fieldInfo);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message, "AddFieldInfo()", MessageBoxButtons.OK, (int)MessageBoxIcon.Error);
                return false;
            }
    		
            return true;
    		
        }
            
    }
}
