using System;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Globalization;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using DevExpress.CodeParser.Diagnostics;

namespace CUS_COM
{
    public partial class frmPopMesVersionUp : frmViewForm01
    {
        public frmPopMesVersionUp()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum GCM_INFO
        {
            CHECK_COL,     //0;
            KEY_1_COL,     //1;
            KEY_1_BTN,     //2;
            KEY_2_COL,     //3;
            KEY_2_BTN,     //4;
            KEY_3_COL,     //5;
            KEY_3_BTN,     //6;
            KEY_4_COL,     //7;
            KEY_4_BTN,     //8;
            KEY_5_COL,     //9;
            KEY_5_BTN,     //10;
            KEY_6_COL,     //11;
            KEY_6_BTN,     //12;
            KEY_7_COL,     //13;
            KEY_7_BTN,     //14;
            KEY_8_COL,     //15;
            KEY_8_BTN,     //16;
            KEY_9_COL,     //17;
            KEY_9_BTN,     //18;
            KEY_10_COL,    //19;
            KEY_10_BTN,    //20;
            DATA_1_COL,    //21;
            DATA_1_BTN,    //22;
            DATA_2_COL,    //23;
            DATA_2_BTN,    //24;
            DATA_3_COL,    //25;
            DATA_3_BTN,    //26;
            DATA_4_COL,    //27;
            DATA_4_BTN,    //28;
            DATA_5_COL,    //29;
            DATA_5_BTN,    //30;
            DATA_6_COL,    //31;
            DATA_6_BTN,    //32;
            DATA_7_COL,    //33;
            DATA_7_BTN,    //34;
            DATA_8_COL,    //35;
            DATA_8_BTN,    //36;
            DATA_9_COL,    //37;
            DATA_9_BTN,    //38;
            DATA_10_COL,   //39;
            DATA_10_BTN    //40;
        }


        private enum HIST_INFO
        {
            TRANS_TIME,
            SYSTEM_NAME,
            AFTER_VERSION,
            BEFORE_VERSION,
            REMARKS
        }


        private struct Format
        {
            public string Col_Fmt;
            public int Col_Size;
        };

        private const string COLUMN_KEY = "KEY";
        private const string COLUMN_DATA = "DATA";
        private const string GCM_TBL_DAT = "MGCMTBLDAT";
        private const string GCM_TBL_LAG = "MGCMLAGDAT";
        private const int MAX_DATA_COUNT = 1000;

        #endregion

        #region " Variable Definition "

        private TRSNode TABLE;
        private Format[] FormatTbl = new Format[41];
        private float[] d_prev_col_size = new float[40];
        private bool b_reload_data_flag;
        private int i_last_filtered_column;
        private string s_last_filtered_string;
        private bool b_load_flag = false;
        private int i_last_selected_idx;
        private int i_last_selected_desc_idx;

        public string sTable_name = "";
        public string sTable_name_desc = "";
        public string sComment = "";


        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnUpdate.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnExcel.Anchor = AnchorStyles.Top | AnchorStyles.Left;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool MakeColumnHeader()
        {
            FarPoint.Win.Spread.CellType.TextCellType text_type;
            FarPoint.Win.Spread.CellType.ButtonCellType button_type;
            int i;

            try
            {
        
                  //  txtPwd.Enabled = false;
          

                if (spdData.ActiveSheet.Columns.Count > 0)
                {
                    spdData.ActiveSheet.Columns.Add(0, 1);
                }
                else
                {
                    spdData.ActiveSheet.ColumnCount = 41;
                }

                for (i = 1; i <= 40; i++)
                {
                    spdData.ActiveSheet.ColumnHeader.Columns[i].Width = 0;
                    spdData.ActiveSheet.ColumnHeader.Columns[i].Resizable = false;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, i].Value = "";


                    //20220915 추가
  
                    spdData.ActiveSheet.Columns.Get(i).AllowAutoFilter = true;
                    spdData.ActiveSheet.Columns.Get(i).AllowAutoSort = true;

                    FormatTbl[i].Col_Fmt = "";
                    FormatTbl[i].Col_Size = 0;
                }

                //체크 부분
                spdData.ActiveSheet.ColumnHeader.Cells[0, 0].Value = "Sel";
                spdData.ActiveSheet.Columns.Get(0).CellType = new FarPoint.Win.Spread.CellType.CheckBoxCellType();
                spdData.ActiveSheet.Columns.Get(0).HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                spdData.ActiveSheet.Columns.Get(0).VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                spdData.ActiveSheet.Columns.Get(0).Width = 30;
                spdData.ActiveSheet.Columns[(int)GCM_INFO.CHECK_COL].Locked = false;




                if (TABLE.GetString("KEY_1_PRT") != "")
                {
                    text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                    //text_type.WordWrap = true;
                    text_type.MaxLength = 100;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_1_COL].CellType = text_type;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_1_COL].Value = " " + TABLE.GetString("KEY_1_PRT") + " ";
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_1_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_1_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_1_COL].Width = 180;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_1_COL].Visible = true;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_1_COL].Locked = true;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_1_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_1_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_1_COL].CellType = text_type;
                    FormatTbl[(int)GCM_INFO.KEY_1_COL].Col_Fmt = TABLE.GetChar("KEY_1_FMT").ToString();
                    FormatTbl[(int)GCM_INFO.KEY_1_COL].Col_Size = TABLE.GetInt("KEY_1_SIZE");



                    


                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_1_COL].Tag = COLUMN_KEY;
                    if (TABLE.GetString("KEY_1_TBL") != "")
                    {
                        button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                        button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                        button_type.Text = "...";
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_1_BTN].Width = 20;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_1_BTN].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_1_BTN].CellType = button_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_1_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("KEY_1_TBL"), TABLE.GetString("KEY_1_COL"));
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_1_COL].ColumnSpan = 2;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_1_BTN].Locked = true;
                    }
                }

                if (TABLE.GetString("KEY_2_PRT") != "")
                {
                    text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                    //text_type.WordWrap = true;
                    text_type.MaxLength = 100;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_2_COL].CellType = text_type;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_2_COL].Value = " " + TABLE.GetString("KEY_2_PRT") + " ";
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_2_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_2_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_2_COL].Width = 180;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_2_COL].Visible = true;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_2_COL].Locked = true;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_2_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_2_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_2_COL].CellType = text_type;
                    FormatTbl[(int)GCM_INFO.KEY_2_COL].Col_Fmt = TABLE.GetChar("KEY_2_FMT").ToString();
                    FormatTbl[(int)GCM_INFO.KEY_2_COL].Col_Size = TABLE.GetInt("KEY_2_SIZE");



                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_2_COL].Tag = COLUMN_KEY;

                    if (TABLE.GetString("KEY_2_TBL") != "")
                    {
                        button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                        button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                        button_type.Text = "...";
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_2_BTN].Width = 20;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_2_BTN].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_2_BTN].CellType = button_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_2_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("KEY_2_TBL"), TABLE.GetString("KEY_2_COL"));
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_2_COL].ColumnSpan = 2;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_2_BTN].Locked = true;
                    }
                }

                if (TABLE.GetChar("TABLE_TYPE") == 'E' || TABLE.GetChar("TABLE_TYPE") == 'L')
                {
                    if (TABLE.GetString("KEY_3_PRT") != "")
                    {
                        text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                        //text_type.WordWrap = true;
                        text_type.MaxLength = 100;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_3_COL].CellType = text_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_3_COL].Value = " " + TABLE.GetString("KEY_3_PRT") + " ";
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_3_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_3_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_3_COL].Width = 180;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_3_COL].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_3_COL].Locked = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_3_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_3_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_3_COL].CellType = text_type;
                        FormatTbl[(int)GCM_INFO.KEY_3_COL].Col_Fmt = TABLE.GetChar("KEY_3_FMT").ToString();
                        FormatTbl[(int)GCM_INFO.KEY_3_COL].Col_Size = TABLE.GetInt("KEY_3_SIZE");

                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_3_COL].Tag = COLUMN_KEY;
                        if (TABLE.GetString("KEY_3_TBL") != "")
                        {
                            button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                            button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                            button_type.Text = "...";
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_3_BTN].Width = 20;
                            spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_3_BTN].Visible = true;
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_3_BTN].CellType = button_type;
                            spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_3_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("KEY_3_TBL"), TABLE.GetString("KEY_3_COL"));
                            spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_3_COL].ColumnSpan = 2;
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_3_BTN].Locked = true;
                        }
                    }
                    if (TABLE.GetString("KEY_4_PRT") != "")
                    {
                        text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                        //text_type.WordWrap = true;
                        text_type.MaxLength = 100;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_4_COL].CellType = text_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_4_COL].Value = " " + TABLE.GetString("KEY_4_PRT") + " ";
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_4_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_4_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_4_COL].Width = 180;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_4_COL].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_4_COL].Locked = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_4_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_4_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_4_COL].CellType = text_type;
                        FormatTbl[(int)GCM_INFO.KEY_4_COL].Col_Fmt = TABLE.GetChar("KEY_4_FMT").ToString();
                        FormatTbl[(int)GCM_INFO.KEY_4_COL].Col_Size = TABLE.GetInt("KEY_4_SIZE");

                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_4_COL].Tag = COLUMN_KEY;
                        if (TABLE.GetString("KEY_4_TBL") != "")
                        {
                            button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                            button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                            button_type.Text = "...";
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_4_BTN].Width = 20;
                            spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_4_BTN].Visible = true;
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_4_BTN].CellType = button_type;
                            spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_4_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("KEY_4_TBL"), TABLE.GetString("KEY_4_COL"));
                            spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_4_COL].ColumnSpan = 2;
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_4_BTN].Locked = true;
                        }
                    }
                    if (TABLE.GetString("KEY_5_PRT") != "")
                    {
                        text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                        //text_type.WordWrap = true;
                        text_type.MaxLength = 100;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_5_COL].CellType = text_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_5_COL].Value = " " + TABLE.GetString("KEY_5_PRT") + " ";
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_5_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_5_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_5_COL].Width = 180;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_5_COL].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_5_COL].Locked = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_5_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_5_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_5_COL].CellType = text_type;
                        FormatTbl[(int)GCM_INFO.KEY_5_COL].Col_Fmt = TABLE.GetChar("KEY_5_FMT").ToString();
                        FormatTbl[(int)GCM_INFO.KEY_5_COL].Col_Size = TABLE.GetInt("KEY_5_SIZE");

                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_5_COL].Tag = COLUMN_KEY;
                        if (TABLE.GetString("KEY_5_TBL") != "")
                        {
                            button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                            button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                            button_type.Text = "...";
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_5_BTN].Width = 20;
                            spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_5_BTN].Visible = true;
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_5_BTN].CellType = button_type;
                            spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_5_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("KEY_5_TBL"), TABLE.GetString("KEY_5_COL"));
                            spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_5_COL].ColumnSpan = 2;
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_5_BTN].Locked = true;
                        }
                    }
                    if (TABLE.GetString("KEY_6_PRT") != "")
                    {
                        text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                        //text_type.WordWrap = true;
                        text_type.MaxLength = 100;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_6_COL].CellType = text_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_6_COL].Value = " " + TABLE.GetString("KEY_6_PRT") + " ";
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_6_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_6_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_6_COL].Width = 180;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_6_COL].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_6_COL].Locked = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_6_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_6_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_6_COL].CellType = text_type;
                        FormatTbl[(int)GCM_INFO.KEY_6_COL].Col_Fmt = TABLE.GetChar("KEY_6_FMT").ToString();
                        FormatTbl[(int)GCM_INFO.KEY_6_COL].Col_Size = TABLE.GetInt("KEY_6_SIZE");

                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_6_COL].Tag = COLUMN_KEY;
                        if (TABLE.GetString("KEY_6_TBL") != "")
                        {
                            button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                            button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                            button_type.Text = "...";
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_6_BTN].Width = 20;
                            spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_6_BTN].Visible = true;
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_6_BTN].CellType = button_type;
                            spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_6_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("KEY_6_TBL"), TABLE.GetString("KEY_6_COL"));
                            spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_6_COL].ColumnSpan = 2;
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_6_BTN].Locked = true;
                        }
                    }
                    if (TABLE.GetString("KEY_7_PRT") != "")
                    {
                        text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                        //text_type.WordWrap = true;
                        text_type.MaxLength = 100;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_7_COL].CellType = text_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_7_COL].Value = " " + TABLE.GetString("KEY_7_PRT") + " ";
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_7_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_7_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_7_COL].Width = 180;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_7_COL].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_7_COL].Locked = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_7_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_7_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_7_COL].CellType = text_type;
                        FormatTbl[(int)GCM_INFO.KEY_7_COL].Col_Fmt = TABLE.GetChar("KEY_7_FMT").ToString();
                        FormatTbl[(int)GCM_INFO.KEY_7_COL].Col_Size = TABLE.GetInt("KEY_7_SIZE");

                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_7_COL].Tag = COLUMN_KEY;
                        if (TABLE.GetString("KEY_7_TBL") != "")
                        {
                            button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                            button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                            button_type.Text = "...";
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_7_BTN].Width = 20;
                            spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_7_BTN].Visible = true;
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_7_BTN].CellType = button_type;
                            spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_7_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("KEY_7_TBL"), TABLE.GetString("KEY_7_COL"));
                            spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_7_COL].ColumnSpan = 2;
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_7_BTN].Locked = true;
                        }
                    }
                    if (TABLE.GetString("KEY_8_PRT") != "")
                    {
                        text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                        //text_type.WordWrap = true;
                        text_type.MaxLength = 100;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_8_COL].CellType = text_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_8_COL].Value = " " + TABLE.GetString("KEY_8_PRT") + " ";
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_8_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_8_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_8_COL].Width = 180;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_8_COL].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_8_COL].Locked = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_8_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_8_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_8_COL].CellType = text_type;
                        FormatTbl[(int)GCM_INFO.KEY_8_COL].Col_Fmt = TABLE.GetChar("KEY_8_FMT").ToString();
                        FormatTbl[(int)GCM_INFO.KEY_8_COL].Col_Size = TABLE.GetInt("KEY_8_SIZE");

                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_8_COL].Tag = COLUMN_KEY;
                        if (TABLE.GetString("KEY_8_TBL") != "")
                        {
                            button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                            button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                            button_type.Text = "...";
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_8_BTN].Width = 20;
                            spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_8_BTN].Visible = true;
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_8_BTN].CellType = button_type;
                            spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_8_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("KEY_8_TBL"), TABLE.GetString("KEY_8_COL"));
                            spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_8_COL].ColumnSpan = 2;
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_8_BTN].Locked = true;
                        }
                    }
                    if (TABLE.GetString("KEY_9_PRT") != "")
                    {
                        text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                        //text_type.WordWrap = true;
                        text_type.MaxLength = 100;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_9_COL].CellType = text_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_9_COL].Value = " " + TABLE.GetString("KEY_9_PRT") + " ";
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_9_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_9_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_9_COL].Width = 180;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_9_COL].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_9_COL].Locked = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_9_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_9_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_9_COL].CellType = text_type;
                        FormatTbl[(int)GCM_INFO.KEY_9_COL].Col_Fmt = TABLE.GetChar("KEY_9_FMT").ToString();
                        FormatTbl[(int)GCM_INFO.KEY_9_COL].Col_Size = TABLE.GetInt("KEY_9_SIZE");

                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_9_COL].Tag = COLUMN_KEY;
                        if (TABLE.GetString("KEY_9_TBL") != "")
                        {
                            button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                            button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                            button_type.Text = "...";
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_9_BTN].Width = 20;
                            spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_9_BTN].Visible = true;
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_9_BTN].CellType = button_type;
                            spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_9_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("KEY_9_TBL"), TABLE.GetString("KEY_9_COL"));
                            spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_9_COL].ColumnSpan = 2;
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_9_BTN].Locked = true;
                        }
                    }
                    if (TABLE.GetString("KEY_10_PRT") != "")
                    {
                        text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                        //text_type.WordWrap = true;
                        text_type.MaxLength = 100;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_10_COL].CellType = text_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_10_COL].Value = " " + TABLE.GetString("KEY_10_PRT") + " ";
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_10_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_10_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_10_COL].Width = 180;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_10_COL].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_10_COL].Locked = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_10_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_10_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_10_COL].CellType = text_type;
                        FormatTbl[(int)GCM_INFO.KEY_10_COL].Col_Fmt = TABLE.GetChar("KEY_10_FMT").ToString();
                        FormatTbl[(int)GCM_INFO.KEY_10_COL].Col_Size = TABLE.GetInt("KEY_10_SIZE");

                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_10_COL].Tag = COLUMN_KEY;
                        if (TABLE.GetString("KEY_10_TBL") != "")
                        {
                            button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                            button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                            button_type.Text = "...";
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_10_BTN].Width = 20;
                            spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.KEY_10_BTN].Visible = true;
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_10_BTN].CellType = button_type;
                            spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_10_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("KEY_10_TBL"), TABLE.GetString("KEY_10_COL"));
                            spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.KEY_10_COL].ColumnSpan = 2;
                            spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_10_BTN].Locked = true;
                        }
                    }
                }

                if (TABLE.GetString("DATA_1_PRT") != "")
                {
                    text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                    //text_type.WordWrap = true;
                    text_type.MaxLength = 1000;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_1_COL].CellType = text_type;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_1_COL].Value = " " + TABLE.GetString("DATA_1_PRT") + " ";
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_1_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_1_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_1_COL].Width = 180;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_1_COL].Visible = true;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_1_COL].Locked = false;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_1_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_1_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_1_COL].CellType = text_type;
                    FormatTbl[(int)GCM_INFO.DATA_1_COL].Col_Fmt = TABLE.GetChar("DATA_1_FMT").ToString();
                    FormatTbl[(int)GCM_INFO.DATA_1_COL].Col_Size = TABLE.GetInt("DATA_1_SIZE");

                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_1_COL].Tag = COLUMN_DATA;
                    if (TABLE.GetString("DATA_1_TBL") != "")
                    {
                        button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                        button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                        button_type.Text = "...";
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_1_BTN].Width = 20;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_1_BTN].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_1_BTN].CellType = button_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_1_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("DATA_1_TBL"), TABLE.GetString("DATA_1_COL"));
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_1_COL].ColumnSpan = 2;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_1_BTN].Locked = false;

                    }
                }
                if (TABLE.GetString("DATA_2_PRT") != "")
                {
                    text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                    //text_type.WordWrap = true;
                    text_type.MaxLength = 1000;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_2_COL].CellType = text_type;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_2_COL].Value = " " + TABLE.GetString("DATA_2_PRT") + " ";
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_2_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_2_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_2_COL].Width = 180;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_2_COL].Visible = true;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_2_COL].Locked = false;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_2_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_2_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_2_COL].CellType = text_type;
                    FormatTbl[(int)GCM_INFO.DATA_2_COL].Col_Fmt = TABLE.GetChar("DATA_2_FMT").ToString();
                    FormatTbl[(int)GCM_INFO.DATA_2_COL].Col_Size = TABLE.GetInt("DATA_2_SIZE");

                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_2_COL].Tag = COLUMN_DATA;
                    if (TABLE.GetString("DATA_2_TBL") != "")
                    {
                        button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                        button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                        button_type.Text = "...";
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_2_BTN].Width = 20;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_2_BTN].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_2_BTN].CellType = button_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_2_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("DATA_2_TBL"), TABLE.GetString("DATA_2_COL"));
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_2_COL].ColumnSpan = 2;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_2_BTN].Locked = false;
                    }
                }
                if (TABLE.GetString("DATA_3_PRT") != "")
                {
                    text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                    //text_type.WordWrap = true;
                    text_type.MaxLength = 1000;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_3_COL].CellType = text_type;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_3_COL].Value = " " + TABLE.GetString("DATA_3_PRT") + " ";
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_3_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_3_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_3_COL].Width = 180;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_3_COL].Visible = true;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_3_COL].Locked = false;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_3_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_3_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_3_COL].CellType = text_type;
                    FormatTbl[(int)GCM_INFO.DATA_3_COL].Col_Fmt = TABLE.GetChar("DATA_3_FMT").ToString();
                    FormatTbl[(int)GCM_INFO.DATA_3_COL].Col_Size = TABLE.GetInt("DATA_3_SIZE");

                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_3_COL].Tag = COLUMN_DATA;
                    if (TABLE.GetString("DATA_3_TBL") != "")
                    {
                        button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                        button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                        button_type.Text = "...";
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_3_BTN].Width = 20;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_3_BTN].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_3_BTN].CellType = button_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_3_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("DATA_3_TBL"), TABLE.GetString("DATA_3_COL"));
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_3_COL].ColumnSpan = 2;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_3_BTN].Locked = false;
                    }
                }
                if (TABLE.GetString("DATA_4_PRT") != "")
                {
                    text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                    //text_type.WordWrap = true;
                    text_type.MaxLength = 1000;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_4_COL].CellType = text_type;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_4_COL].Value = " " + TABLE.GetString("DATA_4_PRT") + " ";
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_4_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_4_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_4_COL].Width = 180;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_4_COL].Visible = true;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_4_COL].Locked = false;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_4_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_4_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_4_COL].CellType = text_type;
                    FormatTbl[(int)GCM_INFO.DATA_4_COL].Col_Fmt = TABLE.GetChar("DATA_4_FMT").ToString();
                    FormatTbl[(int)GCM_INFO.DATA_4_COL].Col_Size = TABLE.GetInt("DATA_4_SIZE");

                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_4_COL].Tag = COLUMN_DATA;
                    if (TABLE.GetString("DATA_4_TBL") != "")
                    {
                        button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                        button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                        button_type.Text = "...";
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_4_BTN].Width = 20;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_4_BTN].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_4_BTN].CellType = button_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_4_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("DATA_4_TBL"), TABLE.GetString("DATA_4_COL"));
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_4_COL].ColumnSpan = 2;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_4_BTN].Locked = false;
                    }
                }
                if (TABLE.GetString("DATA_5_PRT") != "")
                {
                    text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                    //text_type.WordWrap = true;
                    text_type.MaxLength = 1000;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_5_COL].CellType = text_type;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_5_COL].Value = " " + TABLE.GetString("DATA_5_PRT") + " ";
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_5_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_5_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_5_COL].Width = 180;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_5_COL].Visible = true;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_5_COL].Locked = false;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_5_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_5_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_5_COL].CellType = text_type;
                    FormatTbl[(int)GCM_INFO.DATA_5_COL].Col_Fmt = TABLE.GetChar("DATA_5_FMT").ToString();
                    FormatTbl[(int)GCM_INFO.DATA_5_COL].Col_Size = TABLE.GetInt("DATA_5_SIZE");

                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_5_COL].Tag = COLUMN_DATA;
                    if (TABLE.GetString("DATA_5_TBL") != "")
                    {
                        button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                        button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                        button_type.Text = "...";
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_5_BTN].Width = 20;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_5_BTN].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_5_BTN].CellType = button_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_5_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("DATA_5_TBL"), TABLE.GetString("DATA_5_COL"));
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_5_COL].ColumnSpan = 2;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_5_BTN].Locked = false;
                    }
                }
                if (TABLE.GetString("DATA_6_PRT") != "")
                {
                    text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                    //text_type.WordWrap = true;
                    text_type.MaxLength = 1000;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_6_COL].CellType = text_type;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_6_COL].Value = " " + TABLE.GetString("DATA_6_PRT") + " ";
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_6_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_6_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_6_COL].Width = 180;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_6_COL].Visible = true;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_6_COL].Locked = false;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_6_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_6_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_6_COL].CellType = text_type;
                    FormatTbl[(int)GCM_INFO.DATA_6_COL].Col_Fmt = TABLE.GetChar("DATA_6_FMT").ToString();
                    FormatTbl[(int)GCM_INFO.DATA_6_COL].Col_Size = TABLE.GetInt("DATA_6_SIZE");

                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_6_COL].Tag = COLUMN_DATA;
                    if (TABLE.GetString("DATA_6_TBL") != "")
                    {
                        button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                        button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                        button_type.Text = "...";
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_6_BTN].Width = 20;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_6_BTN].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_6_BTN].CellType = button_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_6_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("DATA_6_TBL"), TABLE.GetString("DATA_6_COL"));
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_6_COL].ColumnSpan = 2;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_6_BTN].Locked = false;
                    }
                }
                if (TABLE.GetString("DATA_7_PRT") != "")
                {
                    text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                    //text_type.WordWrap = true;
                    text_type.MaxLength = 1000;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_7_COL].CellType = text_type;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_7_COL].Value = " " + TABLE.GetString("DATA_7_PRT") + " ";
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_7_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_7_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_7_COL].Width = 180;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_7_COL].Visible = true;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_7_COL].Locked = false;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_7_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_7_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_7_COL].CellType = text_type;
                    FormatTbl[(int)GCM_INFO.DATA_7_COL].Col_Fmt = TABLE.GetChar("DATA_7_FMT").ToString();
                    FormatTbl[(int)GCM_INFO.DATA_7_COL].Col_Size = TABLE.GetInt("DATA_7_SIZE");

                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_7_COL].Tag = COLUMN_DATA;
                    if (TABLE.GetString("DATA_7_TBL") != "")
                    {
                        button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                        button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                        button_type.Text = "...";
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_7_BTN].Width = 20;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_7_BTN].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_7_BTN].CellType = button_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_7_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("DATA_7_TBL"), TABLE.GetString("DATA_7_COL"));
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_7_COL].ColumnSpan = 2;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_7_BTN].Locked = false;
                    }
                }
                if (TABLE.GetString("DATA_8_PRT") != "")
                {
                    text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                    //text_type.WordWrap = true;
                    text_type.MaxLength = 1000;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_8_COL].CellType = text_type;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_8_COL].Value = " " + TABLE.GetString("DATA_8_PRT") + " ";
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_8_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_8_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_8_COL].Width = 180;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_8_COL].Visible = true;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_8_COL].Locked = false;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_8_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_8_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_8_COL].CellType = text_type;
                    FormatTbl[(int)GCM_INFO.DATA_8_COL].Col_Fmt = TABLE.GetChar("DATA_8_FMT").ToString();
                    FormatTbl[(int)GCM_INFO.DATA_8_COL].Col_Size = TABLE.GetInt("DATA_8_SIZE");

                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_8_COL].Tag = COLUMN_DATA;
                    if (TABLE.GetString("DATA_8_TBL") != "")
                    {
                        button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                        button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                        button_type.Text = "...";
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_8_BTN].Width = 20;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_8_BTN].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_8_BTN].CellType = button_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_8_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("DATA_8_TBL"), TABLE.GetString("DATA_8_COL"));
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_8_COL].ColumnSpan = 2;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_8_BTN].Locked = false;
                    }
                }
                if (TABLE.GetString("DATA_9_PRT") != "")
                {
                    text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                    //text_type.WordWrap = true;
                    text_type.MaxLength = 1000;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_9_COL].CellType = text_type;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_9_COL].Value = " " + TABLE.GetString("DATA_9_PRT") + " ";
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_9_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_9_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_9_COL].Width = 180;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_9_COL].Visible = true;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_9_COL].Locked = false;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_9_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_9_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_9_COL].CellType = text_type;
                    FormatTbl[(int)GCM_INFO.DATA_9_COL].Col_Fmt = TABLE.GetChar("DATA_9_FMT").ToString();
                    FormatTbl[(int)GCM_INFO.DATA_9_COL].Col_Size = TABLE.GetInt("DATA_9_SIZE");

                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_9_COL].Tag = COLUMN_DATA;
                    if (TABLE.GetString("DATA_9_TBL") != "")
                    {
                        button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                        button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                        button_type.Text = "...";
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_9_BTN].Width = 20;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_9_BTN].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_9_BTN].CellType = button_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_9_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("DATA_9_TBL"), TABLE.GetString("DATA_9_COL"));
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_9_COL].ColumnSpan = 2;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_9_BTN].Locked = false;
                    }
                }
                if (TABLE.GetString("DATA_10_PRT") != "")
                {
                    text_type = new FarPoint.Win.Spread.CellType.TextCellType();
                    //text_type.WordWrap = true;
                    text_type.MaxLength = 1000;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_10_COL].CellType = text_type;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_10_COL].Value = " " + TABLE.GetString("DATA_10_PRT") + " ";
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_10_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_10_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_10_COL].Width = 180;
                    spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_10_COL].Visible = true;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_10_COL].Locked = false;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_10_COL].HorizontalAlignment = FarPoint.Win.Spread.CellHorizontalAlignment.Left;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_10_COL].VerticalAlignment = FarPoint.Win.Spread.CellVerticalAlignment.Center;
                    spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_10_COL].CellType = text_type;
                    FormatTbl[(int)GCM_INFO.DATA_10_COL].Col_Fmt = TABLE.GetChar("DATA_10_FMT").ToString();
                    FormatTbl[(int)GCM_INFO.DATA_10_COL].Col_Size = TABLE.GetInt("DATA_10_SIZE");

                    spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_10_COL].Tag = COLUMN_DATA;
                    if (TABLE.GetString("DATA_10_TBL") != "")
                    {
                        button_type = new FarPoint.Win.Spread.CellType.ButtonCellType();
                        button_type.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                        button_type.Text = "...";
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_10_BTN].Width = 20;
                        spdData.ActiveSheet.ColumnHeader.Columns[(int)GCM_INFO.DATA_10_BTN].Visible = true;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_10_BTN].CellType = button_type;
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_10_BTN].Tag = String.Format("{0}:{1}", TABLE.GetString("DATA_10_TBL"), TABLE.GetString("DATA_10_COL"));
                        spdData.ActiveSheet.ColumnHeader.Cells[0, (int)GCM_INFO.DATA_10_COL].ColumnSpan = 2;
                        spdData.ActiveSheet.Columns[(int)GCM_INFO.DATA_10_BTN].Locked = false;
                    }
                }

                if (AutoCalWidth() == false)
                {
                    return false;
                }

                spdData.ActiveSheet.ColumnHeader.Rows[0].Height = spdData.ActiveSheet.ColumnHeader.Rows[0].GetPreferredHeight();
                spdData.ActiveSheet.SetColumnAllowAutoSort(1, 40, true);
                spdData.ActiveSheet.SetColumnAllowFilter(1, 40, true);

                spdData.ActiveSheet.RowCount++;
                for (i = 1; i <= 40; i++)
                {
                    if (MPCF.Trim(spdData.ActiveSheet.ColumnHeader.Cells[0, i].Tag) == COLUMN_DATA)
                    {
                        spdData.ActiveSheet.Columns[i].BackColor = System.Drawing.Color.White;
                    }
                    else
                    {
                        spdData.ActiveSheet.Columns[i].BackColor = System.Drawing.Color.Lavender;
                        spdData.ActiveSheet.Cells[spdData.ActiveSheet.RowCount - 1, i].BackColor = System.Drawing.Color.WhiteSmoke;
                        spdData.ActiveSheet.Cells[spdData.ActiveSheet.RowCount - 1, i].Locked = false;
                    }
                }

                //btnSelect.Text = MPCF.FindLanguage("Select All Rows", 1);

                SetheaderName();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
            return true;
        }

        private bool AutoCalWidth()
        {
            int i = 0;
            int iSpreadWidth = 0;
            int iColumnWidth = 0;
            int iColumnCount = 0;

            float iColumnHeaderWidth = 0;
            float iRowHeaderWidth = 0;

            if (b_reload_data_flag == true)
            {
                for (i = 0; i < 40; i++)
                {
                    spdData.ActiveSheet.ColumnHeader.Columns[i + 1].Width = d_prev_col_size[i];
                    spdData.ActiveSheet.ColumnHeader.Columns[i + 1].Resizable = true;
                }
            }
            else
            {
                if (spdData.ActiveSheet.ColumnHeader.Columns.Count > 0)
                    iColumnHeaderWidth = spdData.ActiveSheet.ColumnHeader.Columns[0].Width;

                if (spdData.ActiveSheet.RowHeader.Columns.Count > 0)
                    iRowHeaderWidth = spdData.ActiveSheet.RowHeader.Columns[0].Width;

                iSpreadWidth = (int)(spdData.Width - iColumnHeaderWidth - iRowHeaderWidth - 25);

                if (iSpreadWidth <= 0)
                {
                    return false;
                }
                for (i = 1; i < spdData.ActiveSheet.ColumnCount; i++)
                {
                    if (spdData.ActiveSheet.ColumnHeader.Columns[i].Width > 0)
                    {
                        iColumnCount++;
                    }
                }

                if (iColumnCount > 0)
                    iColumnWidth = iSpreadWidth / iColumnCount;
                else
                    iColumnCount = iSpreadWidth;

                if (iColumnWidth < 120)
                {
                    iColumnWidth = 120;
                }
                for (i = 1; i < spdData.ActiveSheet.ColumnCount; i++)
                {
                    if (spdData.ActiveSheet.ColumnHeader.Columns[i].Width > 0)
                    {
                        if (MPCF.Trim(spdData.ActiveSheet.ColumnHeader.Cells[0, i].Tag) == COLUMN_KEY ||
                            MPCF.Trim(spdData.ActiveSheet.ColumnHeader.Cells[0, i].Tag) == COLUMN_DATA)
                        {
                            spdData.ActiveSheet.ColumnHeader.Columns[i].Width = iColumnWidth;
                            spdData.ActiveSheet.ColumnHeader.Columns[i].Resizable = true;
                        }
                    }
                }
            }

            return true;
        }

        private DataTable FillDataTable(DataTable dt, TRSNode out_node)
        {
            int c;
            int r;
            DataColumn dc;
            DataRow dr;
            List<TRSNode> data_list;

            /*** #753 GCM Reference (2012.04.04 by JYPARK) ***/
            data_list = out_node.GetList("DATA_LIST");
            if (dt == null)
            {
                if (data_list.Count < 1) return null;
                dt = new DataTable("DataTable");
                for (c = 0; c < 40; c++)
                {
                    dc = new DataColumn();
                    dc.DataType = System.Type.GetType("System.String");
                    dc.DefaultValue = "";

                    dt.Columns.Add(dc);
                }
            }

          //  for (r = 0; r < data_list.Count; r++)
         //   {

                r = 0;

                dr = dt.NewRow();

                dr[0] = data_list[r].GetString("KEY_1");
                dr[1] = "";
                dr[2] = data_list[r].GetString("KEY_2");
                dr[3] = "";
                dr[4] = data_list[r].GetString("KEY_3");
                dr[5] = "";
                dr[6] = data_list[r].GetString("KEY_4");
                dr[7] = "";
                dr[8] = data_list[r].GetString("KEY_5");
                dr[9] = "";
                dr[10] = data_list[r].GetString("KEY_6");
                dr[11] = "";
                dr[12] = data_list[r].GetString("KEY_7");
                dr[13] = "";
                dr[14] = data_list[r].GetString("KEY_8");
                dr[15] = "";
                dr[16] = data_list[r].GetString("KEY_9");
                dr[17] = "";
                dr[18] = data_list[r].GetString("KEY_10");
                dr[19] = "";

                dr[20] = data_list[r].GetString("DATA_1");
                dr[21] = "";
                dr[22] = data_list[r].GetString("DATA_2");
                dr[23] = "";
                dr[24] = data_list[r].GetString("DATA_3");
                dr[25] = "";
                dr[26] = data_list[r].GetString("DATA_4");
                dr[27] = "";
                dr[28] = data_list[r].GetString("DATA_5");
                dr[29] = "";
                dr[30] = data_list[r].GetString("DATA_6");
                dr[31] = "";
                dr[32] = data_list[r].GetString("DATA_7");
                dr[33] = "";
                dr[34] = data_list[r].GetString("DATA_8");
                dr[35] = "";
                dr[36] = data_list[r].GetString("DATA_9");
                dr[37] = "";
                dr[38] = data_list[r].GetString("DATA_10");
                dr[39] = "";

                dt.Rows.Add(dr);
          //  }
            /*** End of Modification (2012.04.04) ***/

            return dt;
        }

        private bool ViewDataList(string[] sArgu)
        {
            TRSNode in_node = new TRSNode("VIEW_DATA_LIST_IN");
            TRSNode out_node;

            DataTable dt = null;
            ArrayList a_list = new ArrayList();
            FarPoint.Win.Spread.FpSpread spd;
            int i;

            try
            {
                if (b_reload_data_flag == true)
                {
                    for (i = 0; i < 40; i++)
                    {
                        d_prev_col_size[i] = spdData.ActiveSheet.ColumnHeader.Columns[i + 1].Width;
                    }
                }

                spd = spdData;
                
                MPCF.ClearList(spd);
                spd.SuspendLayout();
                spd.ActiveSheet.ColumnCount = 0;
                spd.ResumeLayout();

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("TABLE_NAME", "UPGRADE_OPTION");

                /* 2013.06.12. Aiden. 10000 개 이상의 Data 가 존재하는 경우 Filter 를 통해 Data List 를 가져오도록 변경 */


                if(rdIClient.Checked == true)
                {
                    in_node.AddString("KEY_1", "MESClient" + "%");
                    lblComment.Text = "MES Client 버전 변경은 Admin 관리자만 변경가능합니다.";
                    spdData.Visible = true;
                }
                else
                {
                    in_node.AddString("KEY_1", "MESServer" + "%");
                    lblComment.Text = "MES Server 변경정보는 배포파일 변경발생시 자동 기록됩니다..";
                    spdData.Visible = false;
                }


                if (sArgu != null)
                {
                    for (i = 0; i < sArgu.Length; i++)
                    {
                        TRSNode node = in_node.AddNode("ARGU_LIST");
                        node.AddString("ARGUMENT", sArgu[i]);
                    }
                }

                spd.SuspendLayout();

                do
                {
                    out_node = new TRSNode("VIEW_DATA_LIST_OUT");

                    if (MPCR.CallService("BAS", "BAS_View_Data_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    a_list.Add(out_node);

                    in_node.SetString("NEXT_KEY_1", out_node.GetString("NEXT_KEY_1"));
                    in_node.SetString("NEXT_KEY_2", out_node.GetString("NEXT_KEY_2"));
                    in_node.SetString("NEXT_KEY_3", out_node.GetString("NEXT_KEY_3"));
                    in_node.SetString("NEXT_KEY_4", out_node.GetString("NEXT_KEY_4"));
                    in_node.SetString("NEXT_KEY_5", out_node.GetString("NEXT_KEY_5"));
                    in_node.SetString("NEXT_KEY_6", out_node.GetString("NEXT_KEY_6"));
                    in_node.SetString("NEXT_KEY_7", out_node.GetString("NEXT_KEY_7"));
                    in_node.SetString("NEXT_KEY_8", out_node.GetString("NEXT_KEY_8"));
                    in_node.SetString("NEXT_KEY_9", out_node.GetString("NEXT_KEY_9"));
                    in_node.SetString("NEXT_KEY_10", out_node.GetString("NEXT_KEY_10"));
                    in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));


                } while (in_node.GetString("NEXT_KEY_1") != "" ||
                         in_node.GetString("NEXT_KEY_2") != "" ||
                         in_node.GetString("NEXT_KEY_3") != "" ||
                         in_node.GetString("NEXT_KEY_4") != "" ||
                         in_node.GetString("NEXT_KEY_5") != "" ||
                         in_node.GetString("NEXT_KEY_6") != "" ||
                         in_node.GetString("NEXT_KEY_7") != "" ||
                         in_node.GetString("NEXT_KEY_8") != "" ||
                         in_node.GetString("NEXT_KEY_9") != "" ||
                         in_node.GetString("NEXT_KEY_10") != "" ||
                         in_node.GetInt("NEXT_ROW") > 0);

                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;

                    dt = FillDataTable(dt, out_node);                    
                }

                spd.DataSource = dt;
                MakeColumnHeader();
                
                spd.ResumeLayout();
                //txtExpTable.Text = lisTable.SelectedItems[0].Text;

                spd.ActiveSheet.RowCount = 1;
                GcmHisSearch();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }


        private void GcmHisSearch()
        {
            try
            {


                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";
                DataTable dt = null;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = "SYSTEM";
                dvcArgu[1].sCondition_ID = "KEY_1";

                if (rdIClient.Checked == true)
                {
                    dvcArgu[1].sCondition_Value = "MESClient";

                }
                else
                {

                    dvcArgu[1].sCondition_Value = "MESServer";
                }

                if (TPDR.GetDataOne("", ref dt, "BAS-04", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdGcmHistory);
                    return;
                }

                MPCF.ClearList(spdGcmHistory);

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    spdGcmHistory_Sheet1.RowCount++;

                    spdGcmHistory_Sheet1.Cells[i, (int)HIST_INFO.TRANS_TIME].Value = dt.Rows[i]["TRANS_TIME"];
                    spdGcmHistory_Sheet1.Cells[i, (int)HIST_INFO.SYSTEM_NAME].Value = dt.Rows[i]["SYSTEM_NAME"];
                    spdGcmHistory_Sheet1.Cells[i, (int)HIST_INFO.AFTER_VERSION].Value = dt.Rows[i]["AFTER_VERSION"];
                    spdGcmHistory_Sheet1.Cells[i, (int)HIST_INFO.BEFORE_VERSION].Value = dt.Rows[i]["BEFORE_VERSION"];
                    spdGcmHistory_Sheet1.Cells[i, (int)HIST_INFO.REMARKS].Value = dt.Rows[i]["REMARKS"];
                }
                



                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        private bool ViewGCMDataListExt(ListView lisList, string table_name, string[] Argu)
        {
            ListViewItem itmX;
            int i;
            int j;
            string s_col_name;
            ArrayList a_list;
            List<TRSNode> data_list;

            TRSNode in_node = new TRSNode("VIEW_DATA_LIST_IN");
            TRSNode out_node;

            a_list = new ArrayList();

            MPCF.InitListView(lisList);

            if (lisList is Miracom.UI.Controls.MCCodeView.MCCodeDropList)
            {
                ((Miracom.UI.Controls.MCCodeView.MCCodeDropList)lisList).GCMTableName = table_name;
            }

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            in_node.AddString("TABLE_NAME", table_name);
            in_node.AddString("NEXT_KEY_1", "");
            in_node.AddString("NEXT_KEY_2", "");

            if (Argu != null)
            {
                for (i = 0; i < Argu.Length; i++)
                {
                    TRSNode node = in_node.AddNode("ARGU_LIST");
                    node.AddString("ARGUMENT", Argu[i]);
                }
            }

            do
            {
                out_node = new TRSNode("VIEW_DATA_LIST_OUT");

                if (MPCR.CallService("BAS", "BAS_View_Data_List", in_node, ref out_node) == false)
                {
                    return false;
                }

                a_list.Add(out_node);

                in_node.SetString("NEXT_KEY_1", out_node.GetString("NEXT_KEY_1"));
                in_node.SetString("NEXT_KEY_2", out_node.GetString("NEXT_KEY_2"));
                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));

            } while (in_node.GetString("NEXT_KEY_1") != "" || in_node.GetString("NEXT_KEY_2") != "" || in_node.GetInt("NEXT_ROW") > 0);

            foreach (object obj in a_list)
            {
                out_node = null;
                out_node = (TRSNode)obj;

                data_list = out_node.GetList("DATA_LIST");
                for (i = 0; i < data_list.Count; i++)
                {
                    s_col_name = lisList.Columns[0].Text;

                    itmX = new ListViewItem();
                    itmX.Text = data_list[i].GetString(s_col_name);
                    itmX.ImageIndex = (int)SMALLICON_INDEX.IDX_CODE_DATA;
                    for (j = 1; j < lisList.Columns.Count; j++)
                    {
                        s_col_name = lisList.Columns[j].Text;
                        itmX.SubItems.Add(data_list[i].GetString(s_col_name));
                    }
                    lisList.Items.Add(itmX);
                }
            }

            return true;
        }

        private bool UpdateDataList(char ProcStep)
        {
            int i = 0;
            TRSNode in_node = new TRSNode("UPDATE_DATA_LIST_IN");
            TRSNode out_node = new TRSNode("CMN_OUT");
            TRSNode node;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = ProcStep;
                in_node.AddString("TABLE_NAME", "UPGRADE_OPTION");
                //in_node.AddString("TABLE_PASSWORD", MPCF.Trim(txtPwd.Text).ToUpper(), true);

                for (i = 0; i < spdData.ActiveSheet.RowCount; i++)
                {
                    if (spdData.ActiveSheet.Cells[i, 0].Value == null) continue;
                    if (Convert.ToBoolean(spdData.ActiveSheet.Cells[i, 0].Value) == false) continue;

                    node = in_node.AddNode("DATA_LIST");

                    node.AddString("KEY_1", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_1_COL].Value));
                    node.AddString("KEY_2", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_2_COL].Value));
                    node.AddString("KEY_3", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_3_COL].Value));
                    node.AddString("KEY_4", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_4_COL].Value));
                    node.AddString("KEY_5", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_5_COL].Value));
                    node.AddString("KEY_6", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_6_COL].Value));
                    node.AddString("KEY_7", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_7_COL].Value));
                    node.AddString("KEY_8", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_8_COL].Value));
                    node.AddString("KEY_9", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_9_COL].Value));
                    node.AddString("KEY_10", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_10_COL].Value));

                    node.AddString("DATA_1", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.DATA_1_COL].Value));
                    node.AddString("DATA_2", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.DATA_2_COL].Value));
                    node.AddString("DATA_3", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.DATA_3_COL].Value));
                    node.AddString("DATA_4", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.DATA_4_COL].Value));
                    node.AddString("DATA_5", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.DATA_5_COL].Value));
                    node.AddString("DATA_6", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.DATA_6_COL].Value));
                    node.AddString("DATA_7", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.DATA_7_COL].Value));
                    node.AddString("DATA_8", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.DATA_8_COL].Value));
                    node.AddString("DATA_9", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.DATA_9_COL].Value));
                    node.AddString("DATA_10", MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.DATA_10_COL].Value));
                }

                if (MPCR.CallService("BAS", "BAS_Update_Data_List", in_node, ref out_node) == false)
                {
                    return false;
                }
                else 
                    MPCR.ShowSuccessMsg(out_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }

        private bool ViewTable()
        {
            TRSNode in_node = new TRSNode("VIEW_TABLE_IN");

            try
            {
                if (TABLE == null)
                {
                    TABLE = new TRSNode("VIEW_TABLE_OUT");
                }

                TABLE.Init();

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("TABLE_NAME", "UPGRADE_OPTION");

                if (MPCR.CallService("BAS", "BAS_View_Table", in_node, ref TABLE) == false)
                {
                    return false;
                }
                
                if (IsBigDataList(TABLE.GetString("TABLE_NAME"), TABLE.GetChar("TABLE_TYPE")) == true)
                {


                    MPCF.ClearList(spdData);
                    MakeColumnHeader();               
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }

        private bool CheckGCMTable(string sTableName, out string sQuery, out string dTable)
        {
            TRSNode in_node = new TRSNode("VIEW_TABLE_IN");
            TRSNode out_node = new TRSNode("VIEW_TABLE_OUT");

            sQuery = String.Empty;
            dTable = String.Empty;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("TABLE_NAME", sTableName);
                in_node.AddChar("INCLUDE_CENTRAL_TABLE_FLAG", 'Y');

                if (MPCR.CallService("BAS", "BAS_View_Table", in_node, ref out_node) == false)
                {
                    return false;
                }

                if (out_node.GetChar("USE_SQL_FLAG") == 'Y')
                {
                    sQuery = out_node.GetString("SQL_1") + out_node.GetString("SQL_2") + out_node.GetString("SQL_3")
                             + out_node.GetString("SQL_4") + out_node.GetString("SQL_5");
                }

                if (out_node.GetChar("TABLE_TYPE") == 'L')
                    dTable = GCM_TBL_LAG;
                else
                    dTable = GCM_TBL_DAT;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }

            return true;
        }

        private bool IsBigDataList(string s_table_name, char c_table_type)
        {
            StringBuilder sb = new StringBuilder();
            int i_count;

            sb.Append("SELECT COUNT(*) AS DCOUNT FROM ");

            if (c_table_type == 'L')
            {
                sb.Append("MGCMLAGDAT ");
            }
            else
            {
                sb.Append("MGCMTBLDAT ");
            }

            sb.Append("WHERE FACTORY = '" + MPGV.gsFactory + "' AND TABLE_NAME = '" + s_table_name + "'");

            i_count = MPCR.GetDataCountBySQL(sb.ToString());
            if (i_count > 10000)
            {
                return true;
            }

            return false;
        }

        private bool GetQueryArgument(string sQuery, out string[] sArgu)
        {
            int i, j, i_count;
            string[] sWord = null;
            bool b_exist_flag = false;

            sArgu = null;

            if (MPCF.Trim(sQuery) != "")
            {
                Miracom.BASCore.frmBASSubSetupTable form = new Miracom.BASCore.frmBASSubSetupTable();

                sWord = sQuery.Split(new Char[] { ' ', '\n', '\r' });
                i_count = 0;
                for (i = 0; i < sWord.Length; i++)
                {
                    if (sWord[i].IndexOf("$") >= 0)
                    {
                        if (MPCF.Trim(sWord[i]).ToUpper().Contains("$FACTORY") == false)
                        {
                            i_count++;
                        }
                    }
                }
                if (i_count > 0)
                {
                    sArgu = new string[i_count];
                }

                i_count = 0;
                for (i = 0; i < sWord.Length; i++)
                {
                    if (sWord[i].IndexOf("$") >= 0)
                    {
                        b_exist_flag = false;
                        if (MPCF.Trim(sWord[i]).ToUpper().Contains("$FACTORY") == false)
                        {
                            for (j = 0; j < sArgu.Length; j++)
                            {
                                if (sArgu[j] == sWord[i])
                                {
                                    b_exist_flag = true;
                                }
                            }
                            if (b_exist_flag == false)
                            {
                                sArgu[i_count] = sWord[i];
                                i_count++;
                            }
                        }
                    }
                }
                if (i_count > 0)
                {
                    form.ViewQueryArgument(sArgu, i_count);
                    if (form.ShowDialog(this) != DialogResult.OK)
                    {
                        if (form.IsDisposed == false) form.Dispose();
                        return false;
                    }
                    sArgu = new string[i_count];
                    for (i = 0; i < sArgu.Length; i++)
                    {
                        sArgu[i] = form.ArgValue[i, 1];
                    }
                }
            }

            return true;
        }

        //컬럼헤더 캡션 변경
        private void SetheaderName()
        {
            string sTmp = "";
            string sCOL_Name = "";

            try
            {
                for (int i = 0; i < spdData.ActiveSheet.ColumnCount; i++)
                {
                    sCOL_Name = spdData.ActiveSheet.ColumnHeader.Cells.Get(0, i).Value.ToString();

                    sTmp = MPCF.FindLanguage(sCOL_Name, CAPTION_TYPE.LABEL);

                    spdData.ActiveSheet.ColumnHeader.Cells.Get(0, i).Value = sTmp;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CheckCondition(string FuncName, char ProcStep)
        {
            int i = 0;
            int j = 0;
            int iChkCnt = 0;

            try
            {
                switch (MPCF.Trim(FuncName))
                {
                    case "Update_Data_List":


                        for (i = 0; i < spdData.ActiveSheet.RowCount; i++)
                        {
                            if (spdData.ActiveSheet.Cells[i, (int)GCM_INFO.CHECK_COL].Value != null)
                            {
                                if (Convert.ToBoolean(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.CHECK_COL].Value) == true)
                                {

                                    iChkCnt++;

                                    if (MPCF.Trim(spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_1_COL].Value) == "")
                                    {
                                        MPCF.ShowMsgBox(MPCF.GetMessage(108));
                                        spdData.ActiveSheet.SetActiveCell(i, (int)GCM_INFO.KEY_1_COL);
                                        spdData.Select();
                                        return false;
                                    }

                                    for (j = i + 1; j < spdData.ActiveSheet.RowCount; j++)
                                    {
                                        if (spdData.ActiveSheet.Cells[j, (int)GCM_INFO.CHECK_COL].Value != null)
                                        {
                                            if (Convert.ToBoolean(spdData.ActiveSheet.Cells[j, (int)GCM_INFO.CHECK_COL].Value) == true)
                                            {
                                                if (spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_1_COL].Value == spdData.ActiveSheet.Cells[j, (int)GCM_INFO.KEY_1_COL].Value &&
                                                    spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_2_COL].Value == spdData.ActiveSheet.Cells[j, (int)GCM_INFO.KEY_2_COL].Value &&
                                                    spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_3_COL].Value == spdData.ActiveSheet.Cells[j, (int)GCM_INFO.KEY_3_COL].Value &&
                                                    spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_4_COL].Value == spdData.ActiveSheet.Cells[j, (int)GCM_INFO.KEY_4_COL].Value &&
                                                    spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_5_COL].Value == spdData.ActiveSheet.Cells[j, (int)GCM_INFO.KEY_5_COL].Value &&
                                                    spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_6_COL].Value == spdData.ActiveSheet.Cells[j, (int)GCM_INFO.KEY_6_COL].Value &&
                                                    spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_7_COL].Value == spdData.ActiveSheet.Cells[j, (int)GCM_INFO.KEY_7_COL].Value &&
                                                    spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_8_COL].Value == spdData.ActiveSheet.Cells[j, (int)GCM_INFO.KEY_8_COL].Value &&
                                                    spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_9_COL].Value == spdData.ActiveSheet.Cells[j, (int)GCM_INFO.KEY_9_COL].Value &&
                                                    spdData.ActiveSheet.Cells[i, (int)GCM_INFO.KEY_10_COL].Value == spdData.ActiveSheet.Cells[j, (int)GCM_INFO.KEY_10_COL].Value)
                                                {
                                                    MPCF.ShowMsgBox(MPCF.GetMessage(111));
                                                    spdData.ActiveSheet.SetActiveCell(i, (int)GCM_INFO.KEY_1_COL);
                                                    spdData.Select();
                                                    return false;
                                                }
                                            }
                                        }
                                    }

                                }
                            }
                        }

                        if (iChkCnt == 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(133));
                            spdData.Select();
                            return false;
                        }
                        else if (iChkCnt > MAX_DATA_COUNT)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(134));
                            spdData.Select();
                            return false;
                        }

                        switch (MPCF.ToChar(MPCF.Trim(ProcStep)))
                        {
                            case MPGC.MP_STEP_UPDATE:

                                break;

                            case MPGC.MP_STEP_DELETE:

                                break;

                        }
                        break;
                    case "VIEW_TABLE":

                        break;

                }
                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        #endregion

        #region " Event Definition "

        private void frmPopMesVersionUp_Load(object sender, EventArgs e)
        {
            try
            {

    

                ViewTable();
                ViewDataList(null);

                //ADMIN만 버전 업데이트 가능
                if(MPGV.gsUserID == "ADMIN")
                {
                   btnUpdate.Visible = true;
                }
                else
                {
                    btnUpdate.Visible = false;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }








        private void frmPopMesVersionUp_Activated(object sender, EventArgs e)
        {
            try
            {
                if (b_load_flag == false)
                {
                    i_last_filtered_column = -1;
                    s_last_filtered_string = null;
                    b_reload_data_flag = false;
                    b_load_flag = true;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdData_EnterCell(object sender, FarPoint.Win.Spread.EnterCellEventArgs e)
        {
            /*
            try
            {
                if (spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_1_COL].Visible == false)
                {
                    return;
                }
                if (e.Row == spdData.ActiveSheet.RowCount - 1)
                {
                    if (MPCF.Trim(spdData.ActiveSheet.Cells[e.Row, (int)GCM_INFO.KEY_1_COL].Value) != "")
                    {
                        spdData.ActiveSheet.RowCount++;
                        int i = 0;
                        
                        for (i = 1; i <= 20; i++)
                        {
                            spdData.ActiveSheet.Cells[spdData.ActiveSheet.RowCount - 1, i].BackColor = System.Drawing.Color.WhiteSmoke;
                            spdData.ActiveSheet.Cells[spdData.ActiveSheet.RowCount - 1, i].Locked = false;
                        }                        
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

            */
        }

        private void spdData_EditModeOff(object sender, EventArgs e)
        {
            string sValue;
            int i_col;
            int i_row;

            try
            {
                i_col = spdData.ActiveSheet.ActiveColumnIndex;
                i_row = spdData.ActiveSheet.ActiveRowIndex;

                if (i_col < 1) return;

                spdData.ActiveSheet.SetValue(i_row, 0, true);

                sValue = MPCF.Trim(spdData.ActiveSheet.Cells[i_row, i_col].Value);

                if (MPCF.ByteLen(sValue) > FormatTbl[i_col].Col_Size)
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(153));
                    spdData.ActiveSheet.SetValue(i_row, i_col, "");
                    spdData.ActiveSheet.SetActiveCell(i_row, i_col);
                    return;
                }

                switch (FormatTbl[i_col].Col_Fmt)
                {
                    case "F":

                        if (MPCF.CheckNumeric(sValue) == false)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(139));
                            spdData.ActiveSheet.SetValue(i_row, i_col, "");
                            spdData.ActiveSheet.SetActiveCell(i_row, i_col);
                            return;
                        }
                        break;

                    case "N":

                        if (MPCF.CheckNumeric(sValue) == false)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(139));
                            spdData.ActiveSheet.SetValue(i_row, i_col, "");
                            spdData.ActiveSheet.SetActiveCell(i_row, i_col);
                            return;
                        }
                        if (sValue.IndexOf(CultureInfo.CurrentCulture.NumberFormat.NumberDecimalSeparator) >= 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(140));
                            spdData.ActiveSheet.SetValue(i_row, i_col, "");
                            spdData.ActiveSheet.SetActiveCell(i_row, i_col);
                            return;
                        }
                        break;
                }
                /*
                //Add 1 Row
                if (spdData.ActiveSheet.Columns[(int)GCM_INFO.KEY_1_COL].Visible == false)
                {
                    return;
                }

                if (i_row == spdData.ActiveSheet.RowCount - 1)
                {
                    if (MPCF.Trim(spdData.ActiveSheet.Cells[i_row, (int)GCM_INFO.KEY_1_COL].Value) != "")
                    {
                        spdData.ActiveSheet.RowCount++;
                        int i = 0;

                        for (i = 1; i <= 20; i++)
                        {
                            spdData.ActiveSheet.Cells[spdData.ActiveSheet.RowCount - 1, i].BackColor = System.Drawing.Color.WhiteSmoke;
                            spdData.ActiveSheet.Cells[spdData.ActiveSheet.RowCount - 1, i].Locked = false;
                        }                       
                    }
                }
                */

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdData_AutoFilteredColumn(object sender, FarPoint.Win.Spread.AutoFilteredColumnEventArgs e)
        {
            int i;

            try
            {
                if (e.Column != i_last_filtered_column || e.FilterString != s_last_filtered_string)
                {
                    for (i = 0; i < spdData.ActiveSheet.RowCount; i++)
                    {
                        if (spdData.ActiveSheet.RowFilter.IsRowFilteredOut(i) == true)
                        {
                            spdData.ActiveSheet.SetValue(i, 0, false);
                        }
                    }

                    i_last_filtered_column = e.Column;
                    s_last_filtered_string = e.FilterString;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdData_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            ListView lisTmp = new ListView();
            string[] sTmp = null;
            string[] sArgu = null;
            string sQuery = "";
            string dTable = null;
            i_last_selected_idx = 0;
            i_last_selected_desc_idx = -1;

            try
            {
                if (e.Column == (int)GCM_INFO.KEY_1_BTN || e.Column == (int)GCM_INFO.KEY_2_BTN || e.Column == (int)GCM_INFO.KEY_3_BTN || e.Column == (int)GCM_INFO.KEY_4_BTN 
                    || e.Column == (int)GCM_INFO.KEY_5_BTN || e.Column == (int)GCM_INFO.KEY_6_BTN || e.Column == (int)GCM_INFO.KEY_7_BTN || e.Column == (int)GCM_INFO.KEY_8_BTN 
                    || e.Column == (int)GCM_INFO.KEY_9_BTN || e.Column == (int)GCM_INFO.KEY_10_BTN || e.Column == (int)GCM_INFO.DATA_1_BTN || e.Column == (int)GCM_INFO.DATA_2_BTN 
                    || e.Column == (int)GCM_INFO.DATA_3_BTN || e.Column == (int)GCM_INFO.DATA_4_BTN || e.Column == (int)GCM_INFO.DATA_5_BTN || e.Column == (int)GCM_INFO.DATA_6_BTN 
                    || e.Column == (int)GCM_INFO.DATA_7_BTN || e.Column == (int)GCM_INFO.DATA_8_BTN || e.Column == (int)GCM_INFO.DATA_9_BTN || e.Column == (int)GCM_INFO.DATA_10_BTN)
                {
                    if (MPCF.Trim(spdData.ActiveSheet.ColumnHeader.Cells[0, e.Column].Tag) == "") return;

                    sTmp = MPCF.Trim(spdData.ActiveSheet.ColumnHeader.Cells[0, e.Column].Tag).Split(':');
                    lisTmp.Columns.Add("COLUMN");
                    lisTmp.Columns.Add("PROMPT");

                    cdvDataList.Init();
                    cdvDataList.ViewPosition = Control.MousePosition;
                    MPCF.InitListView(cdvDataList.GetListView);

                    if (CheckGCMTable(sTmp[0], out sQuery, out dTable))
                    {
                        if (sTmp.Length == 3)
                        {
                            int iPos = MPCF.Trim(spdData.ActiveSheet.ColumnHeader.Cells[0, e.Column].Tag).LastIndexOf(":");
                            spdData.ActiveSheet.ColumnHeader.Cells[0, e.Column].Tag = MPCF.Trim(spdData.ActiveSheet.ColumnHeader.Cells[0, e.Column].Tag).Remove(iPos) + ":" + sQuery;
                        }
                        else
                        {
                            if (MPCF.Trim(sQuery) != "")
                                spdData.ActiveSheet.ColumnHeader.Cells[0, e.Column].Tag += ":" + sQuery;
                        }
                        sTmp = MPCF.Trim(spdData.ActiveSheet.ColumnHeader.Cells[0, e.Column].Tag).Split(':');
                    }
                    if (sTmp.Length == 3)
                    {
                        if (GetQueryArgument(sQuery, out sArgu) == false)
                        {
                            return;
                        }

                        BASLIST.ViewGCMTablePromptList(lisTmp, sTmp[0], true, true);
                        for (int i = 0; i < lisTmp.Items.Count; i++)
                        {
                            if (lisTmp.Items[i].Text == sTmp[1])
                                i_last_selected_idx = i;

                            if (lisTmp.Items[i].Text == "DATA_1")
                                i_last_selected_desc_idx = i;

                            cdvDataList.Columns.Add(lisTmp.Items[i].Text, 50, HorizontalAlignment.Left);
                        }
                    }
                    else
                    {
                        BASLIST.ViewGCMTablePromptList(lisTmp, sTmp[0], true, true);
                        for (int i = 0; i < lisTmp.Items.Count; i++)
                        {
                            if (lisTmp.Items[i].Text == sTmp[1])
                                i_last_selected_idx = i;

                            if (lisTmp.Items[i].Text == "DATA_1")
                                i_last_selected_desc_idx = i;

                            cdvDataList.Columns.Add(lisTmp.Items[i].Text, 50, HorizontalAlignment.Left);
                        }
                    }
                    ViewGCMDataListExt(cdvDataList.GetListView, sTmp[0], sArgu);
                    if (cdvDataList.Items.Count > 0)
                    {
                        cdvDataList.InsertEmptyRow(0, 1);
                        if (cdvDataList.ShowPopupList(e.Row, e.Column) == false)
                        {
                            return;
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDataList_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (MPCF.Trim(spdData.ActiveSheet.Cells[e.Row, e.Col - 1].Value) != e.SelectedItem.SubItems[i_last_selected_idx].Text)
                {
                    spdData.ActiveSheet.Cells[e.Row, e.Col - 1].Value = e.SelectedItem.SubItems[i_last_selected_idx].Text;
                    if (e.SelectedItem.SubItems.Count > 1)
                    {
                        int iDescCol = -1;
                        for (int i = e.Col; i < spdData.ActiveSheet.ColumnCount; i++)
                        {
                            if (MPCF.Trim(spdData.ActiveSheet.ColumnHeader.Cells[0, i].Tag) == COLUMN_DATA &&
                                spdData.ActiveSheet.Columns[i].Visible == true &&
                                i < spdData.ActiveSheet.ColumnCount - 1)
                            {
                                // 2 column has same reference GCM table, fill description
                                string[] sTmp1 = MPCF.Trim(spdData.ActiveSheet.ColumnHeader.Cells[0, e.Col].Tag).Split(':');
                                string[] sTmp2 = MPCF.Trim(spdData.ActiveSheet.ColumnHeader.Cells[0, i + 1].Tag).Split(':');

                                if (sTmp1[0] == sTmp2[0] && sTmp1[1] != sTmp2[1] && i_last_selected_desc_idx >= 0)
                                {
                                    iDescCol = i;
                                    spdData.ActiveSheet.Cells[e.Row, iDescCol].Value = e.SelectedItem.SubItems[i_last_selected_desc_idx].Text;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //클릭보드 이벤트
        private void spdData_ClipboardPasting(object sender, FarPoint.Win.Spread.ClipboardPastingEventArgs e)
        {

            /*
            string clipboardText;
            string[] clipboardRows, clipboardCols = new string[] { };
            int iActiveRowIndex, iActiveColumnIndex;
            int iClipboardRowLength = 0;
            int iValueCol = 0;
            int iMaxValueCol = 0;
            bool bFoundValueCol;

            try
            {
                e.Handled = true;

                if (!Clipboard.ContainsData(DataFormats.Text))
                    return;

                iActiveRowIndex = spdData.ActiveSheet.ActiveRowIndex;
                iActiveColumnIndex = spdData.ActiveSheet.ActiveColumnIndex;

                clipboardText = Clipboard.GetText(TextDataFormat.UnicodeText) as string;
                clipboardText = clipboardText.Replace("\r\n", Convert.ToChar(13).ToString());
                clipboardRows = clipboardText.Split(new Char[] { Convert.ToChar(13) });

                if (clipboardRows.Length > 1)
                    iClipboardRowLength = clipboardRows.Length - 1;
                else
                    iClipboardRowLength = clipboardRows.Length;

                for (int i_row = 0; i_row < iClipboardRowLength; i_row++)
                {
                    if (spdData.ActiveSheet.RowCount - 1 < i_row + iActiveRowIndex)
                    {
                        spdData.ActiveSheet.RowCount++;
                        for (int i = 1; i <= 20; i++)
                        {
                            spdData.ActiveSheet.Cells[spdData.ActiveSheet.RowCount - 1, i].BackColor = System.Drawing.Color.WhiteSmoke;
                            spdData.ActiveSheet.Cells[spdData.ActiveSheet.RowCount - 1, i].Locked = false;
                        }
                    }

                    clipboardCols = clipboardRows[i_row].Split(new Char[] { Convert.ToChar(9) });
                    iValueCol = iActiveColumnIndex;

                    for (int i_col = 0; i_col < clipboardCols.Length; i_col++)
                    {
                        spdData.ActiveSheet.Cells[iActiveRowIndex + i_row, iValueCol].Value = clipboardCols[i_col];

                        if (iValueCol > iMaxValueCol) iMaxValueCol = iValueCol;
                        if (i_col + 1 >= clipboardCols.Length) break;

                        bFoundValueCol = false;
                        for (int i = iValueCol + 1; i < spdData.ActiveSheet.ColumnCount; i++)
                        {
                            if (spdData.ActiveSheet.ColumnHeader.Columns[i].Width > 0.0005)
                            {
                                switch (i)
                                {
                                    case (int)GCM_INFO.KEY_1_COL:
                                    case (int)GCM_INFO.KEY_2_COL:
                                    case (int)GCM_INFO.KEY_3_COL:
                                    case (int)GCM_INFO.KEY_4_COL:
                                    case (int)GCM_INFO.KEY_5_COL:
                                    case (int)GCM_INFO.KEY_6_COL:
                                    case (int)GCM_INFO.KEY_7_COL:
                                    case (int)GCM_INFO.KEY_8_COL:
                                    case (int)GCM_INFO.KEY_9_COL:
                                    case (int)GCM_INFO.KEY_10_COL:
                                    case (int)GCM_INFO.DATA_1_COL:
                                    case (int)GCM_INFO.DATA_2_COL:
                                    case (int)GCM_INFO.DATA_3_COL:
                                    case (int)GCM_INFO.DATA_4_COL:
                                    case (int)GCM_INFO.DATA_5_COL:
                                    case (int)GCM_INFO.DATA_6_COL:
                                    case (int)GCM_INFO.DATA_7_COL:
                                    case (int)GCM_INFO.DATA_8_COL:
                                    case (int)GCM_INFO.DATA_9_COL:
                                    case (int)GCM_INFO.DATA_10_COL:
                                        iValueCol = i;
                                        bFoundValueCol = true;
                                        break;
                                }
                            }

                            if (bFoundValueCol == true)
                                break;
                        }

                        if (bFoundValueCol == false)
                            break;
                    }

                    spdData.ActiveSheet.Cells[iActiveRowIndex + i_row, 0].Value = 1;            // Check Box Check
                    spdData.ActiveSheet.SetActiveCell(iActiveRowIndex + i_row, iActiveColumnIndex);
                } //end for

                spdData.ActiveSheet.SetActiveCell(iActiveRowIndex, iActiveColumnIndex);

                spdData.ActiveSheet.ClearSelection();
                spdData.ActiveSheet.AddSelection(iActiveRowIndex, iActiveColumnIndex, iClipboardRowLength, iMaxValueCol - iActiveColumnIndex + 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

            */
        }


        private void spdData_ClipboardChanging(object sender, EventArgs e)
        {
            /*
            mb_from_spread_clipboard = true;
            */
        }

        private void spdData_ClipboardChanged(object sender, EventArgs e)
        {

            /*
            int i;
            int i_row;
            int i_col;
            FarPoint.Win.Spread.Model.CellRange[] cr;
            StringBuilder sb = new StringBuilder();
            string s_data;

            try
            {
                if (mb_from_spread_clipboard == false)
                    return;

                mb_from_spread_clipboard = false;

                Clipboard.Clear();

                if (spdData.ActiveSheet.SelectionCount < 1)
                    return;

                cr = spdData.ActiveSheet.GetSelections();

                for (i = 0; i < cr.Length; i++)
                {
                    for (i_row = cr[i].Row; i_row < cr[i].Row + cr[i].RowCount; i_row++)
                    {
                        s_data = "";

                        for (i_col = cr[i].Column; i_col < cr[i].Column + cr[i].ColumnCount; i_col++)
                        {
                            if (spdData.ActiveSheet.ColumnHeader.Columns[i_col].Width > 0.0005)
                            {
                                switch (i_col)
                                {
                                    case (int)GCM_INFO.KEY_1_COL:
                                    case (int)GCM_INFO.KEY_2_COL:
                                    case (int)GCM_INFO.KEY_3_COL:
                                    case (int)GCM_INFO.KEY_4_COL:
                                    case (int)GCM_INFO.KEY_5_COL:
                                    case (int)GCM_INFO.KEY_6_COL:
                                    case (int)GCM_INFO.KEY_7_COL:
                                    case (int)GCM_INFO.KEY_8_COL:
                                    case (int)GCM_INFO.KEY_9_COL:
                                    case (int)GCM_INFO.KEY_10_COL:
                                    case (int)GCM_INFO.DATA_1_COL:
                                    case (int)GCM_INFO.DATA_2_COL:
                                    case (int)GCM_INFO.DATA_3_COL:
                                    case (int)GCM_INFO.DATA_4_COL:
                                    case (int)GCM_INFO.DATA_5_COL:
                                    case (int)GCM_INFO.DATA_6_COL:
                                    case (int)GCM_INFO.DATA_7_COL:
                                    case (int)GCM_INFO.DATA_8_COL:
                                    case (int)GCM_INFO.DATA_9_COL:
                                    case (int)GCM_INFO.DATA_10_COL:
                                        if (i_col > cr[i].Column) s_data += "\t";
                                        s_data += MPCF.Trim(spdData.ActiveSheet.Cells[i_row, i_col].Value);
                                        break;
                                }
                            }
                        }

                        s_data += "\r\n";
                        sb.Append(s_data);
                    }
                }

                Clipboard.SetDataObject(sb.ToString());
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            */
        }

        //조회버튼
        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {

                
              //  ViewDataList(null);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //수정버튼
        private void btnUpdate_Click(object sender, EventArgs e)
        {
            int ActiveRow = 0;

            try
            {
                if (CheckCondition("Update_Data_List", '1') == true)
                {
                    ActiveRow = spdData.Sheets[0].ActiveRowIndex;

                    if (UpdateDataList(MPGC.MP_STEP_UPDATE) == false)
                    {
                        return;
                    }

                    b_reload_data_flag = true;
                    ViewDataList(null);
                    
                    spdData.Sheets[0].ActiveColumnIndex = 0;
                    spdData.Sheets[0].ActiveRowIndex = ActiveRow;
                    spdData.ShowActiveCell(FarPoint.Win.Spread.VerticalPosition.Top, FarPoint.Win.Spread.HorizontalPosition.Left);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //삭제버튼



        #endregion

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdGcmHistory, "MES_VERSION_HISTORY");  //spread 객체, 기본 파일명

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void pnlStsCond3_Paint(object sender, PaintEventArgs e)
        {

        }

        private void rdIClient_CheckedChanged(object sender, EventArgs e)
        {
            ViewDataList(null);
        }

        private void rdIServer_CheckedChanged(object sender, EventArgs e)
        {
            ViewDataList(null);
        }
    }
}
