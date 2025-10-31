using System;
using System.Collections.Generic;
using System.Text;

namespace Admin.RPTCore
{
    class clsCommon
    {
	    public static AMGV.DATATYPE ConvertDataTypeToEnum(string sDataType)
	    {
		    switch (sDataType.ToUpper())
		    {
			    case "CHAR":
    				
				    return AMGV.DATATYPE.CHAR_TYPE;
                case "WCHAR":

                    return AMGV.DATATYPE.VARCHAR_TYPE;
                case "VARCHAR":

                    return AMGV.DATATYPE.VARCHAR_TYPE;
                case "INTEGER":

                    return AMGV.DATATYPE.INTEGER_TYPE;
                case "NUMERIC":

                    return AMGV.DATATYPE.NUMERIC_TYPE;
                case "NUMBER":

                    return AMGV.DATATYPE.NUMERIC_TYPE;
                case "VARNUMERIC":

                    return AMGV.DATATYPE.NUMERIC_TYPE;
                case "DOUBLE":

                    return AMGV.DATATYPE.DOUBLE_TYPE;
                case "DECIMAL":

                    return AMGV.DATATYPE.NUMERIC_TYPE;
                case "FLOAT":

                    return AMGV.DATATYPE.FLOAT_TYPE;
                case "DBTIMESTAMP":

                    return AMGV.DATATYPE.TIMESTAMP_TYPE;
                default:

                    return AMGV.DATATYPE.UNKNOWN_TYPE;
            }

        }

        public static string ConvertDataTypeToString(AMGV.DATATYPE eDataType)
        {

            switch (eDataType)
            {
                case AMGV.DATATYPE.CHAR_TYPE:

                    return "CHAR";
                case AMGV.DATATYPE.VARCHAR_TYPE:

                    return "VARCHAR2";
                case AMGV.DATATYPE.INTEGER_TYPE:

                    return "INTEGER";
                case AMGV.DATATYPE.NUMERIC_TYPE:

                    return "NUMERIC";
                case AMGV.DATATYPE.DOUBLE_TYPE:

                    return "DOUBLE";
                case AMGV.DATATYPE.FLOAT_TYPE:

                    return "FLOAT";
                case AMGV.DATATYPE.TIMESTAMP_TYPE:

                    return "TIMESTAMP";
                default:

                    return "";
            }

        }

        public static string ConvertDataTypeToString4CS(AMGV.DATATYPE eDataType)
        {

            switch (eDataType)
            {
                case AMGV.DATATYPE.CHAR_TYPE:

                    return "CHAR";
                case AMGV.DATATYPE.VARCHAR_TYPE:

                    return "VARCHAR";
                case AMGV.DATATYPE.INTEGER_TYPE:

                    return "INTEGER";
                case AMGV.DATATYPE.NUMERIC_TYPE:

                    return "NUMERIC";
                case AMGV.DATATYPE.DOUBLE_TYPE:

                    return "DOUBLE";
                case AMGV.DATATYPE.FLOAT_TYPE:

                    return "FLOAT";
                case AMGV.DATATYPE.TIMESTAMP_TYPE:

                    return "TIMESTAMP";
                default:

                    return "";
            }
        }
    }
}
