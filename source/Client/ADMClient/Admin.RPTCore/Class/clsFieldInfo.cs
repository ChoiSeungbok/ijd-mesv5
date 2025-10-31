using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using Microsoft.VisualBasic;
using System.Diagnostics;
using System;

//-----------------------------------------------------------------------------
//
//   System      : DEV
//   File Name   : clsFieldInfo.vb
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
    class clsFieldInfo
    {
	    private int m_iSequence = 0;
	    private string m_sFieldName = "";
	    private AMGV.DATATYPE m_eDataType;
	    private bool m_bIsNull = false;
	    private int m_iSize = 0;
	    private int m_iNumericScale = 0;
	    private int m_iPrecision = 0;
	    private bool m_bSelected = false;
    	
	    public int Sequence
	    {
		    get
		    {
			    return m_iSequence;
		    }
		    set
		    {
			    m_iSequence = value;
		    }
	    }
    	
	    public string FieldName
	    {
		    get
		    {
			    return m_sFieldName;
		    }
		    set
		    {
			    m_sFieldName = value;
		    }
	    }
    	
	    public AMGV.DATATYPE DataType
	    {
		    get
		    {
			    return m_eDataType;
		    }
		    set
		    {
			    m_eDataType = value;
		    }
	    }
    	
	    public bool IsNull
	    {
		    get
		    {
			    return m_bIsNull;
		    }
		    set
		    {
			    m_bIsNull = value;
		    }
	    }
    	
	    public int Size
	    {
		    get
		    {
			    return m_iSize;
		    }
		    set
		    {
			    m_iSize = value;
		    }
	    }
    	
	    public int NumericScale
	    {
		    get
		    {
			    return m_iNumericScale;
		    }
		    set
		    {
			    m_iNumericScale = value;
		    }
	    }
    	
	    public int Precision
	    {
		    get
		    {
			    return m_iPrecision;
		    }
		    set
		    {
			    m_iPrecision = value;
		    }
	    }
    	
	    public bool Selected
	    {
		    get
		    {
			    return m_bSelected;
		    }
		    set
		    {
			    m_bSelected = value;
		    }
	    }
    }
}
