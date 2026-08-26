using System;
using System.Data;
using System.Collections.Generic;
using System.Windows.Forms;
using Microsoft.Win32;

using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.UI.Controls.MCCodeView;
using FarPoint.Win.Spread;

using Miracom.TRSCore;
using Miracom.MESCore;
using Miracom.DNMCore;
using System.IO;
using System.Diagnostics;
using CUS_COM.Reports;
using System.Reflection;
using System.Drawing;

using xExcel = Microsoft.Office.Interop.Excel;



namespace CUS_COM
{
    public sealed class CSCF
    {
        private static List<string> randomChannelValues = new List<string>();
        private static readonly Random random = new Random();
        private static readonly object syncLock = new object();
        //'********************************************************************
        //'*  Function Name   :   RoundF
        //'*  File Name       :   MPlusCOMN00.bas
        //'*  Program ID      :   MES Client
        //'*  Description     :   입력값을 원하는 소숫점 자리를 남겨두고 반올림한다.
        //'*                      VB에서 제공하는 ROUND는 정수부분이 홀수 일 경우는 제대로 동작하나
        //'*                      정수 부분이 짝수인 경우에는 제대로 동작하지 않기 때문에 사용에
        //'*                      문제가 있어 Format 함수를 사용한 MESClient만의 Round 함수를 따로 만든것이
        //'*                      바로 이 함수 RoundF 이다.
        //'*  Input Parameter :   vNum as Variant : 반올림할 값
        //'*                      DecimalCnt as integer : 소숫점 자릿수
        //'*  Output Value    :   None
        //'*  Special Logic Notes :
        //'*  Modification History    :
        //'*  VERSION     DATE            AUTHOR      DESCRIPTION
        //'*  ---------   -------------   ----------  ---------------
        //'*  V1.0.0      Jun 07, 2005    SK Jin      Create
        //'*******************************************************************
        public static double RoundF(object vNum, int DecimalCnt = 0)
        {
            double dResult = 0;
            string sTempVal;

            string sFormatStr;

            if (MPCF.CheckNumeric(vNum) == false)
                return dResult;

            sFormatStr = "####00";
            if (DecimalCnt > 0)
                sFormatStr = sFormatStr + "." + "0".PadRight(DecimalCnt, '0');

            sTempVal = MPCF.Format(sFormatStr, vNum);

            if (MPCF.CheckNumeric(sTempVal))
                dResult = MPCF.ToDbl(sTempVal);


            return dResult;
        }

        /// <summary>
        /// Spread 전체 선택
        /// </summary>
        /// <param name="spdData"></param>
        /// <param name="i_ColHeaderRow"></param>
        /// <param name="i_Col"></param>
        /// <param name="b_checked"></param>
        /// <param name="b_isColHeaderCheckBox"></param>
        /// <param name="b_LockRowCheckException"></param>
        /// <returns></returns>
        public static bool CheckSpreadCell(FarPoint.Win.Spread.FpSpread spdData, int i_ColHeaderRow, int i_Col, bool b_checked, bool b_isColHeaderCheckBox, bool b_LockRowCheckException = false)
        {
            try
            {
                if (b_isColHeaderCheckBox)
                {
                    if (spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Locked = false;

                        if (spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Value == null ||
                        spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Value.Equals(" ") ||
                        spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Value.Equals(false))
                        {
                            spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Value = true;
                        }
                        else
                        {
                            spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Value = !Convert.ToBoolean(spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Value);
                        }

                        for (int i = 0; i < spdData.ActiveSheet.RowCount; i++)
                        {
                            // 잠금 되어있는 스프로드 로우에 대해서 체크 제외 여부
                            if (b_LockRowCheckException == false)
                                spdData.ActiveSheet.Cells[i, i_Col].Value = spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Value;
                            else
                            {
                                if (spdData.ActiveSheet.Rows[i].Locked == false)
                                    spdData.ActiveSheet.Cells[i, i_Col].Value = spdData.ActiveSheet.ColumnHeader.Cells[i_ColHeaderRow, i_Col].Value;
                            }
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < spdData.ActiveSheet.RowCount; i++)
                    {
                        spdData.ActiveSheet.Cells[i, i_Col].Value = b_checked;
                    }
                }

                return true;
            }
            catch (System.Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        /// <summary>
        /// 조회 조건 Registry에 저장
        /// </summary>
        /// <param name="control"></param>
        /// <returns></returns>
        public static bool SaveCondition(Control control, Dictionary<string, string> preDic)
        {
            try
            {
                foreach (KeyValuePair<string, string> item in preDic)
                {
                    MPCF.SaveRegSetting(Application.ProductName, control.Name, item.Key, item.Value);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("SaveCondition() : " + ex.Message);
                return false;
            }

            return true;
        }

        /// <summary>
        /// 레지그트리에 저장된 컨트롤의 값을 가져와 Dictionary 에 담는다. 
        /// </summary>
        /// <param name="AppName"></param>
        /// <param name="Section"></param>
        /// <returns></returns>
        public static Dictionary<string, string> GetRegList(string AppName, string Section)
        {
            RegistryKey subkeys = null;
            string[] valueNames = null;
            Dictionary<string, string> DicReg = new Dictionary<string, string>();
            string values = "";

            try
            {
                subkeys = Registry.CurrentUser.OpenSubKey("Software\\VB and VBA Program Settings\\" + AppName + "\\" + Section);

                if (subkeys != null)
                {
                    int icount = subkeys.ValueCount;
                    valueNames = subkeys.GetValueNames();

                    foreach (string subkey in valueNames)
                    {
                        values = subkeys.GetValue(subkey).ToString();


                        //한국베트남 같이 쓰는 유저 경우 사업부때문에 혼란 있어서..디스플레이는 둘다 CTM인데,값은 CTM,CTV이다보니...같이열어서 쓰면 조회안되고 그런케이스 많음
                        //그래서 이부분 하드코딩 강제로 바꿈.(2024-03-14 syw)
                        if (MPGV.gsSiteID == "IDV1") //베트남이라면
                        {
                            if (values == "CTM;CTM")
                            {
                                values = "CTV;CTM";
                            }
                            else if (values == "PDC;PDC")
                            {
                                values = "PDV;PDC";
                            }
                        }
                        else
                        {
                            if (values == "CTV;CTM")
                            {
                                values = "CTM;CTM";
                            }
                            else if (values == "PDV;PDC")
                            {
                                values = "PDC;PDC";
                            }
                        }

                        DicReg.Add(subkey, values);
                    }

                    subkeys.Close();
                }

                return DicReg;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("MPCF.GetRegSetting(" + AppName + "\\" + Section + ")\n" + ex.Message);
                return DicReg;
            }
        }

        /// <summary>
        /// 레지스트리에 담았던 값을 컨트롤 text 값에 담아준다.
        /// </summary>
        /// <param name="control"></param>
        /// <returns></returns>
        public static bool GetCondition(Control control)
        {
            List<CSGV.SearchCondition> scConditions = new List<CSGV.SearchCondition>();
            Dictionary<string, string> DicReg = new Dictionary<string, string>();
            Control[] ctrls = null;
            Control ctrl = null;
            string[] sSplit = null;

            try
            {
                DicReg = GetRegList(Application.ProductName, control.Name);

                if (DicReg != null)
                {
                    foreach (KeyValuePair<string, string> item in DicReg)
                    {
                        ctrls = control.Controls.Find(item.Key, true);

                        if (ctrls == null)
                            ctrl = null;
                        else if (ctrls.Length == 0)
                            ctrl = null;
                        else
                            ctrl = ctrls[0];

                        if (ctrl is RadioButton)
                        {
                            (ctrl as RadioButton).Checked = item.Value == "TRUE" ? true : false;
                        }
                        else if (ctrl is Miracom.UI.Controls.MCCodeView.MCCodeView)
                        {
                            sSplit = item.Value.Split(';');

                            if (sSplit != null)
                            {
                                (ctrl as Miracom.UI.Controls.MCCodeView.MCCodeView).Text = sSplit[0];
                                (ctrl as Miracom.UI.Controls.MCCodeView.MCCodeView).DisplayText = sSplit[1];
                            }
                        }
                        else if (ctrl is DateTimePicker)
                        {
                            (ctrl as DateTimePicker).Value = MPCF.ToDate(item.Value);
                        }
                        else if (ctrl is ComboBox)
                        {
                            if (item.Value.ToString() != "")
                            {
                                (ctrl as ComboBox).Items.Add(item.Value);
                                (ctrl as ComboBox).SelectedIndex = 0;
                            }
                        }
                    }
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //스프레드 범위 지정 후 초기화
        public static void ClearSpread(FarPoint.Win.Spread.FpSpread c_Spread, int iStartRow, int iStartColumn, string sSetValue)
        {
            int iRow;
            int iCol;

            try
            {
                iRow = iStartRow;
                iCol = iStartColumn;

                if (iRow > c_Spread.ActiveSheet.RowCount || iCol > c_Spread.ActiveSheet.ColumnCount)
                    return;

                for (int i = iRow; i < c_Spread.ActiveSheet.RowCount; i++)
                {
                    for (int k = iCol; k < c_Spread.ActiveSheet.ColumnCount; k++)
                    {
                        c_Spread.ActiveSheet.SetValue(i, k, sSetValue);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public static bool PrintLabel(string sLotID, string sOper, string sLabelName, char c_reprint_flag, int i_copies)
        {
            TRSNode print_node = new TRSNode("View_Label_Design_In");
            TRSNode out_node = new TRSNode("View_Label_Design_Out");
            bool bResult = false;

            try
            {
                MPCR.SetInMsg(print_node);
                if (c_reprint_flag == ' ')
                    print_node.ProcStep = '1';
                else
                    print_node.ProcStep = '2';

                print_node.SetString("LOT_ID", sLotID);
                print_node.SetString("OPER", sOper);
                print_node.AddString("SCREEN_ID", sLabelName);
                print_node.AddString("CRR_ID", sLotID);

                Miracom.MESCore.Controls.udcFlexibleScreen pUdcScreen = new Miracom.MESCore.Controls.udcFlexibleScreen();

                pUdcScreen.ScreenID = sLabelName;
                pUdcScreen.LotID = sLotID;

                bResult = pUdcScreen.LoadDesign();
                if (bResult == false)
                    return false;

                pUdcScreen.SetServiceData(print_node, ref out_node);

                pUdcScreen.ScreenSpread.ActiveSheet.PrintInfo.ShowBorder = false;
                pUdcScreen.ScreenSpread.ActiveSheet.RowHeaderVisible = false;
                pUdcScreen.ScreenSpread.ActiveSheet.ColumnHeaderVisible = false;

                //pUdcScreen.ScreenSpread.ActiveSheet.PrintInfo.Preview = true;
                for (int i = 0; i < i_copies; i++)
                {
                    pUdcScreen.ScreenSpread.PrintSheet(0, false);
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        /// 지정한 Cell로 포커스 이동
        /// </summary>
        /// <param name="fps"></param>
        /// <param name="iRow"></param>
        /// <param name="iCol"></param>
        public static void SetPosition(FarPoint.Win.Spread.FpSpread fps, int iRow, int iCol)
        {
            fps.ActiveSheet.ActiveRowIndex = iRow;
            fps.ActiveSheet.ActiveColumnIndex = iCol;
            //fps.ActiveSheet.Models.Selection.SetSelection(iRow, 0, 1, fps.ActiveSheet.ColumnCount);
            fps.ShowCell(fps.GetActiveRowViewportIndex()
                            , fps.GetActiveColumnViewportIndex()
                            , iRow
                            , iCol
                            , FarPoint.Win.Spread.VerticalPosition.Center
                            , FarPoint.Win.Spread.HorizontalPosition.Left);
        }

        /// <summary>
        /// 라벨 데이터 출력  type I : 입고 후 원자재 라벨, 자재이동
        ///                   type R : 반품후 공정라벨 
        ///                   type B : BOX 포장후 출하라벨
        ///                   type C : 대 BOX 포장후 출하라벨
        ///                   type L : 수기 라벨 발행
        ///                   type D : 반품 후 출하라벨 발행
        ///                   type E : 포장 취소 출하라벨 발행 
        /// </summary>
        /// <param name="control"></param>
        /// <param name="sFileName"></param>
        /// <param name="in_node"></param>
        /// <param name="dt"></param>
        /// <param name="cType"></param>
        /// <returns></returns>
        public static bool ViewLabelList(string sFileName, TRSNode in_node, char cType = ' ')
        {
            DataTable dt = new DataTable();
            DataTable sub_dt = new DataTable();
            DataRow row = null;
            DataRow sub_row = null;
            TRSNode out_node;
            string s_input_date = "";
            string s_box_count = "";
            string s_qr_data = "";
            string s_grade = "";
            string s_spec = "";
            string s_label_type = "";
            char c_step = ' ';
            char c_type = ' ';
            double coating_rate = 0;
            double gross = 0;
            double temp_coating_rate = 0;
            string subFileName = "move_sub";
            string s_addingLabel = "N";
            string s_addingCusLabel = "N";

            MPCR.SetInMsg(in_node);

            try
            {
                switch (sFileName)
                {
                    #region [자재라벨]

                    case "mtl100p":
                        dt.Columns.Add(new DataColumn("ITEM_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("INPUT_DATE", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("VENDOR_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("SUPPLIER_LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));

                        c_step = '1';

                        //입고 후 원자재 라벨
                        if (cType == 'I')
                        {
                            c_step = '2';
                        }

                        //외주 라벨 
                        if (cType == 'T')
                        {
                            c_step = 'T';
                        }

                        break;

                    //입하라벨
                    case "mtl100pa":
                        dt.Columns.Add(new DataColumn("ITEM_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("INPUT_DATE", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("VENDOR_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("SUPPLIER_LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));

                        c_step = '9';

                        break;

                    #endregion

                    #region [공정라벨]

                    //CTM 공정라벨(CELL 라벨)
                    case "prd996t":
                        dt.Columns.Add(new DataColumn("CELL_NO", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("WO_NO", typeof(string)));
                        dt.Columns.Add(new DataColumn("PC0201", typeof(string)));
                        dt.Columns.Add(new DataColumn("PC0202", typeof(string)));
                        dt.Columns.Add(new DataColumn("PC0203", typeof(string)));
                        dt.Columns.Add(new DataColumn("PC0204", typeof(string)));

                        c_step = '4';

                        break;

                    case "prd996t_2":
                        dt.Columns.Add(new DataColumn("MAIN_LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("GRADE", typeof(string)));
                        dt.Columns.Add(new DataColumn("WO_NO", typeof(string)));
                        dt.Columns.Add(new DataColumn("REMARKS", typeof(string)));


                        cType = 'H';

                        c_step = 'H';

                        break;

                    //CTM 공정라벨(가공라벨 LOT)
                    case "prd106vp":
                        dt.Columns.Add(new DataColumn("MAIN_LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("GRADE", typeof(string)));
                        dt.Columns.Add(new DataColumn("WO_NO", typeof(string)));
                        dt.Columns.Add(new DataColumn("REMARKS", typeof(string)));

                        c_step = '3';



                        break;

                    //CTM 공정라벨(가공라벨 ITEM)
                    case "prd106vpitem":
                        dt.Columns.Add(new DataColumn("GROUP_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));

                        c_step = '3';

                        break;

                    //GRIT 공정라벨
                    case "prd205p":
                        dt.Columns.Add(new DataColumn("MAIN_LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("WO_NO", typeof(string)));
                        dt.Columns.Add(new DataColumn("REMARKS", typeof(string)));

                        c_step = '3';

                        break;

                    //GRIT 공정라벨_원자재
                    case "prd205p_2":
                        dt.Columns.Add(new DataColumn("ITEM_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("INPUT_DATE", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("VENDOR_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("SUPPLIER_LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));

                        c_step = 'G';

                        break;

                    //PDC 공정라벨
                    case "prd205ppdc":
                        dt.Columns.Add(new DataColumn("MAIN_LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("GRADE", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("WO_NO", typeof(string)));
                        dt.Columns.Add(new DataColumn("GROUP_ID", typeof(string)));

                        c_step = '3';

                        break;

                    #endregion

                    #region [출하라벨]

                    //CTM 출하라벨(66x90)
                    case "mtl900hm3p":
                    case "mtl900hm3_2p":
                    case "mtl900hm3_4p":
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("GRADE", typeof(string)));
                        dt.Columns.Add(new DataColumn("TYPE", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME2", typeof(string)));

                        c_step = '5';

                        break;

                    //CTM 출하라벨(66x90)2
                    case "mtl900hm3_1p":
                    case "mtl900hm3_3p":
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME2", typeof(string)));

                        c_step = '5';

                        break;

                    //CTM 출하라벨(30x85_INSERT제품)
                    case "mtl900hm6p":
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("GRADE", typeof(string)));
                        dt.Columns.Add(new DataColumn("TYPE", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_UOM", typeof(string)));

                        c_step = '5';

                        break;

                    //HM 출하라벨(45x55)
                    case "mdprd860phmbp":
                    case "mdprd860phmbp_2":
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("GRADE", typeof(string)));
                        dt.Columns.Add(new DataColumn("SPEC", typeof(string)));
                        dt.Columns.Add(new DataColumn("BOX_TYPE", typeof(string)));

                        s_addingLabel = "Y";
                        s_label_type = "HM";
                        c_step = '5';

                        break;




                    //HM 출하라벨(90x22)
                    case "mdprd860phmap":
                    case "mdprd860phmap_2":
                    case "mdprd860phmap_4":
                    case "mdprd860phmap_5":
                    case "mdprd860phmap_6":

                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("GRADE", typeof(string)));
                        dt.Columns.Add(new DataColumn("SPEC", typeof(string)));
                        dt.Columns.Add(new DataColumn("BOX_TYPE", typeof(string)));

                        s_addingLabel = "Y";
                        s_label_type = "HM";
                        c_step = '5';

                        break;

                    //HM 출하라벨(90x95)
                    case "mtl215p_8":
                    case "mtl215p_8_2":
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("BOX_COUNT", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME1", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME2", typeof(string)));
                        dt.Columns.Add(new DataColumn("BOX_TYPE", typeof(string)));

                        s_addingLabel = "Y";
                        s_label_type = "HM";
                        c_step = '5';

                        break;

                    //GRIT 출하라벨(76x26)
                    case "840Sample":
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("GRADE", typeof(string)));
                        dt.Columns.Add(new DataColumn("TYPE", typeof(string)));
                        dt.Columns.Add(new DataColumn("COAT", typeof(string)));
                        dt.Columns.Add(new DataColumn("GROSS", typeof(string)));
                        dt.Columns.Add(new DataColumn("DRAWING_FLAG", typeof(string)));

                        c_step = '5';

                        break;


                    //HM 출하라벨(45x55 고객사용(밀러))
                    case "mdprd860phmbp_3":
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("GRADE", typeof(string)));
                        dt.Columns.Add(new DataColumn("SPEC", typeof(string)));
                        dt.Columns.Add(new DataColumn("BOX_TYPE", typeof(string)));
                        dt.Columns.Add(new DataColumn("CUS_MAT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("CUS_LABEL", typeof(string)));
                        dt.Columns.Add(new DataColumn("CUS_SIZE", typeof(string)));
                        dt.Columns.Add(new DataColumn("CUS_QTY", typeof(string)));

                        s_addingLabel = "Y";
                        s_label_type = "HM";
                        c_step = '5';
                        s_addingCusLabel = "Y";

                        break;




                    //HM 출하라벨(90x22 고객사용(밀러))
                    case "mdprd860phmap_3":
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("GRADE", typeof(string)));
                        dt.Columns.Add(new DataColumn("SPEC", typeof(string)));
                        dt.Columns.Add(new DataColumn("BOX_TYPE", typeof(string)));
                        dt.Columns.Add(new DataColumn("CUS_MAT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("CUS_LABEL", typeof(string)));
                        dt.Columns.Add(new DataColumn("CUS_SIZE", typeof(string)));
                        dt.Columns.Add(new DataColumn("CUS_QTY", typeof(string)));

                        s_addingLabel = "Y";
                        s_label_type = "HM";
                        c_step = '5';
                        s_addingCusLabel = "Y";

                        break;

                    //HM 출하라벨(90x95 고객사용(밀러))
                    case "mtl215p_8_3":
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("BOX_COUNT", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME1", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME2", typeof(string)));
                        dt.Columns.Add(new DataColumn("BOX_TYPE", typeof(string)));
                        dt.Columns.Add(new DataColumn("CUS_MAT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("CUS_LABEL", typeof(string)));
                        dt.Columns.Add(new DataColumn("CUS_SIZE", typeof(string)));
                        dt.Columns.Add(new DataColumn("CUS_QTY", typeof(string)));

                        s_addingLabel = "Y";
                        s_label_type = "HM";
                        c_step = '5';
                        s_addingCusLabel = "Y";

                        break;



                    //GRIT 출하라벨(120x90)
                    case "prd840grtp3":
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("GRADE", typeof(string)));
                        dt.Columns.Add(new DataColumn("TYPE", typeof(string)));
                        dt.Columns.Add(new DataColumn("DRAWING_FLAG", typeof(string)));

                        c_step = '5';

                        break;

                    //GRIT 출하라벨(62x43)
                    case "prd840grtp5":
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("GRADE", typeof(string)));
                        dt.Columns.Add(new DataColumn("TYPE", typeof(string)));
                        dt.Columns.Add(new DataColumn("COAT", typeof(string)));
                        dt.Columns.Add(new DataColumn("GROSS", typeof(string)));
                        dt.Columns.Add(new DataColumn("DRAWING_FLAG", typeof(string)));

                        c_step = '5';

                        break;

                    //GRIT 출하라벨(62x43_QR)
                    case "prd840grtp2_DM":
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("GRADE", typeof(string)));
                        dt.Columns.Add(new DataColumn("TYPE", typeof(string)));
                        dt.Columns.Add(new DataColumn("COAT", typeof(string)));
                        dt.Columns.Add(new DataColumn("GROSS", typeof(string)));
                        dt.Columns.Add(new DataColumn("DRAWING_FLAG", typeof(string)));
                        dt.Columns.Add(new DataColumn("QR_DATA", typeof(string)));

                        c_step = '5';

                        break;

                    //PDC 출하라벨(92x88)
                    case "mtl900hm5p":
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("GRADE", typeof(string)));
                        dt.Columns.Add(new DataColumn("TYPE", typeof(string)));

                        c_step = '5';

                        break;


                    //PDC 출하라벨(92x88)
                    case "mtl900hm7p":
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("GRADE", typeof(string)));
                        dt.Columns.Add(new DataColumn("TYPE", typeof(string)));

                        dt.Columns.Add(new DataColumn("CMF_3", typeof(string)));
                        dt.Columns.Add(new DataColumn("CMF_4", typeof(string)));
                        dt.Columns.Add(new DataColumn("CMF_5", typeof(string)));
                        dt.Columns.Add(new DataColumn("CMF_6", typeof(string)));

                        c_step = '5';

                        break;

                    //PDC 출하라벨(49x55)
                    case "mtl900hm9p":
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("PO_NUMBER", typeof(string)));
                        dt.Columns.Add(new DataColumn("MN_NO", typeof(string)));

                        c_step = '5';

                        break;

                    #endregion

                    #region [T-CARD]

                    case "t_card":
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("OP_DESC", typeof(string)));
                        dt.Columns.Add(new DataColumn("SEQ_NUM", typeof(int)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("ORG_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("WIP_ENTITY_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("JOB_DATE", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("PLAN_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("START_TIME", typeof(string)));
                        dt.Columns.Add(new DataColumn("GOOD_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("LOSS_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("WC_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("REMARKS", typeof(string)));
                        dt.Columns.Add(new DataColumn("MC_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME110", typeof(string)));
                        dt.Columns.Add(new DataColumn("TOTAL_QUANTITY", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM_UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("NAME110", typeof(string)));


                        dt.Columns.Add(new DataColumn("DIAMETER_TARGET", typeof(string)));
                        dt.Columns.Add(new DataColumn("DIAMETER_UPPER", typeof(string)));
                        dt.Columns.Add(new DataColumn("DIAMETER_LOWER", typeof(string)));
                        dt.Columns.Add(new DataColumn("LENGTH_TARGET", typeof(string)));
                        dt.Columns.Add(new DataColumn("LENGTH_UPPER", typeof(string)));
                        dt.Columns.Add(new DataColumn("LENGTH_LOWER", typeof(string)));


                        c_step = '6';

                        break;

                    case "t_card_multi":
                        dt.Columns.Add(new DataColumn("GROUP_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("ORG_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("WC_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("WO_NO", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("NO", typeof(int)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME110", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_NO", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_QTY", typeof(double)));

                        c_step = '7';
                        break;

                    // BlENDING T-CARD
                    case "t_card_b":


                        dt.Columns.Add(new DataColumn("GROUP_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("ORG_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("WC_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("WIP_ENTITY_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("OP_DESC", typeof(string)));
                        dt.Columns.Add(new DataColumn("SEQ_NUM", typeof(int)));
                        dt.Columns.Add(new DataColumn("REMARKS", typeof(string)));
                        dt.Columns.Add(new DataColumn("JOB_DATE", typeof(string)));
                        dt.Columns.Add(new DataColumn("PLAN_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("GOOD_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("LOSS_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("MC_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("START_TIME", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME110", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("NAME110", typeof(string)));

                        //2026-07-16 블렌딩 T-Card 검사데이터 추가
                        dt.Columns.Add(new DataColumn("SIZE_NAME", typeof(string)));  //SIZE
                        dt.Columns.Add(new DataColumn("ROWNUM", typeof(int)));        //NO.
                        dt.Columns.Add(new DataColumn("ITEM_NAME2", typeof(string)));  //CLP NO.
                        //dt.Columns.Add(new DataColumn("LOT_ID", typeof(string)));   //LOT NO.
                        //dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));  //중량
                        dt.Columns.Add(new DataColumn("PSD_UP", typeof(double)));
                        dt.Columns.Add(new DataColumn("SS", typeof(double)));
                        dt.Columns.Add(new DataColumn("OS", typeof(double)));
                        dt.Columns.Add(new DataColumn("PSD_LO", typeof(double)));

                        dt.Columns.Add(new DataColumn("TI", typeof(double)));
                        dt.Columns.Add(new DataColumn("BI", typeof(double)));
                        dt.Columns.Add(new DataColumn("TTI", typeof(double)));
                        dt.Columns.Add(new DataColumn("MA", typeof(double)));
                        dt.Columns.Add(new DataColumn("HLT", typeof(double)));
                        dt.Columns.Add(new DataColumn("EILLPT", typeof(double))); 
                        //dt.Columns.Add(new DataColumn("REMARKS", typeof(string)));


                        c_step = 'F';
                        break;

                    #endregion

                    //창고 이동 출고증
                    case "prd702q":
                        dt.Columns.Add(new DataColumn("TRANS_SEQ2", typeof(string)));
                        dt.Columns.Add(new DataColumn("TRANS_SEQ", typeof(string)));
                        dt.Columns.Add(new DataColumn("REG_DATE", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE1", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME1", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_NO1", typeof(string)));
                        dt.Columns.Add(new DataColumn("UOM1", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY1", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE2", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME2", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_NO2", typeof(string)));
                        dt.Columns.Add(new DataColumn("UOM2", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY2", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE3", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME3", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_NO3", typeof(string)));
                        dt.Columns.Add(new DataColumn("UOM3", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY3", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE4", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME4", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_NO4", typeof(string)));
                        dt.Columns.Add(new DataColumn("UOM4", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY4", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE5", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME5", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_NO5", typeof(string)));
                        dt.Columns.Add(new DataColumn("UOM5", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY5", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE6", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME6", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_NO6", typeof(string)));
                        dt.Columns.Add(new DataColumn("UOM6", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY6", typeof(double)));
                        dt.Columns.Add(new DataColumn("FR_WH_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("TO_WH_CODE", typeof(string)));

                        c_step = '8';

                        //자재불출요청 창고이동 출고증
                        if (cType == 'I')
                        {
                            c_step = '0';
                        }

                        break;

                    //출하 출고증
                    case "sal510q":
                        dt.Columns.Add(new DataColumn("PAGE_NO", typeof(int)));
                        dt.Columns.Add(new DataColumn("SHIP_ID", typeof(string)));
                        dt.Columns.Add(new DataColumn("SHIP_ID2", typeof(string)));
                        dt.Columns.Add(new DataColumn("TAB_NO", typeof(int)));
                        dt.Columns.Add(new DataColumn("CUSTOMER_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE1", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME1", typeof(string)));
                        dt.Columns.Add(new DataColumn("UOM1", typeof(string)));
                        dt.Columns.Add(new DataColumn("QTY1", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE2", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME2", typeof(string)));
                        dt.Columns.Add(new DataColumn("UOM2", typeof(string)));
                        dt.Columns.Add(new DataColumn("QTY2", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE3", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME3", typeof(string)));
                        dt.Columns.Add(new DataColumn("UOM3", typeof(string)));
                        dt.Columns.Add(new DataColumn("QTY3", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE4", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME4", typeof(string)));
                        dt.Columns.Add(new DataColumn("UOM4", typeof(string)));
                        dt.Columns.Add(new DataColumn("QTY4", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE5", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME5", typeof(string)));
                        dt.Columns.Add(new DataColumn("UOM5", typeof(string)));
                        dt.Columns.Add(new DataColumn("QTY5", typeof(double)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE6", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME6", typeof(string)));
                        dt.Columns.Add(new DataColumn("UOM6", typeof(string)));
                        dt.Columns.Add(new DataColumn("QTY6", typeof(double)));

                        c_step = 'J';

                        break;

                    //이동지시서(집계 포함)
                    case "move_order":
                        dt.Columns.Add(new DataColumn("TRANS_SEQ", typeof(string)));
                        dt.Columns.Add(new DataColumn("ORG_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("NO", typeof(int)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_NO", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("REMARKS", typeof(double)));
                        dt.Columns.Add(new DataColumn("FR_WH_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("TO_WH_CODE", typeof(string)));

                        c_step = '8';

                        //자재 이동 지시서
                        if (cType == 'I')
                        {
                            c_step = cType;
                        }

                        c_type = 'D';

                        break;

                    //이동지시서
                    case "move_order_1":
                        dt.Columns.Add(new DataColumn("TRANS_SEQ", typeof(string)));
                        dt.Columns.Add(new DataColumn("ORG_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("FR_WH_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("TO_WH_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("NO", typeof(int)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_NO", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("REMARKS", typeof(double)));
                        break;

                    case "kittingLabel":
                        dt.Columns.Add(new DataColumn("TRANS_SEQ", typeof(string)));
                        dt.Columns.Add(new DataColumn("ORG_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("NO", typeof(int)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_NO", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));

                        c_step = 'A';
                        c_type = 'D';

                        break;

                    case "move_order_multi":

                        dt.Columns.Add(new DataColumn("TRANS_SEQ", typeof(string)));
                        dt.Columns.Add(new DataColumn("ORG_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("NO", typeof(int)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_NO", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_UOM", typeof(string)));
                        dt.Columns.Add(new DataColumn("LOT_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("REMARKS", typeof(char)));
                        dt.Columns.Add(new DataColumn("REMARKS2", typeof(string)));
                        dt.Columns.Add(new DataColumn("FR_WH_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("TO_WH_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("TOTAL_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("RES_DESC", typeof(string)));
                        dt.Columns.Add(new DataColumn("SUMMARY_ITEM_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("SUMMARY_ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("SUMMARY_ITEM_QTY", typeof(double)));
                        dt.Columns.Add(new DataColumn("SUMMARY_REMARKS", typeof(char)));
                        dt.Columns.Add(new DataColumn("SUMMARY_ITEM_CODE2", typeof(string)));
                        dt.Columns.Add(new DataColumn("SUMMARY_ITEM_NAME2", typeof(string)));
                        dt.Columns.Add(new DataColumn("SUMMARY_ITEM_QTY2", typeof(double)));
                        dt.Columns.Add(new DataColumn("SUMMARY_REMARKS2", typeof(char)));

                        c_step = 'M';

                        break;

                    //미출고 내역
                    case "sal450q":
                        dt.Columns.Add(new DataColumn("SECTION_GBN", typeof(string)));
                        dt.Columns.Add(new DataColumn("SECTION_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("BOOKED_DATE", typeof(string)));
                        dt.Columns.Add(new DataColumn("ORDER_NUMBER", typeof(string)));
                        dt.Columns.Add(new DataColumn("LINE_NUMBER", typeof(int)));
                        dt.Columns.Add(new DataColumn("LABEL_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("CUSTOMER_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("DRAWING_FLAG", typeof(string)));
                        dt.Columns.Add(new DataColumn("ORDER_TYPE", typeof(string)));
                        dt.Columns.Add(new DataColumn("REQUEST_DATE", typeof(string)));
                        dt.Columns.Add(new DataColumn("SCHEDULE_SHIP_DATE", typeof(string)));
                        dt.Columns.Add(new DataColumn("UNPACKED_QUANTITY", typeof(double)));
                        dt.Columns.Add(new DataColumn("UNPACKED_ONHAND_QUANTITY", typeof(double)));
                        dt.Columns.Add(new DataColumn("ORDER_DATE", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_CODE", typeof(string)));
                        dt.Columns.Add(new DataColumn("ITEM_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("END_SHIP_TO_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("PACKING_INSTRUCTIONS", typeof(string)));
                        dt.Columns.Add(new DataColumn("FIXED_YN", typeof(string)));
                        dt.Columns.Add(new DataColumn("USER_NAME", typeof(string)));
                        dt.Columns.Add(new DataColumn("REMAIN_QTY", typeof(double)));

                        c_step = 'S';

                        break;
                }

                //L: 수기 라벨
                //R: 반품 후 공정
                //B: 중박스
                //C: 대박스
                //D: 반품 후 출하
                if (cType != 'I' && cType != ' ')
                {
                    c_step = cType;
                }

                in_node.ProcStep = c_step;
                in_node.AddChar("LABEL_TYPE", c_type);

                double iSumQty = 0;

                out_node = new TRSNode("VIEW_LABEL_LIST_OUT");

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Label_List", in_node, ref out_node) == false)
                {
                    return false;
                }

                for (int i = 0; i < out_node.GetList(0).Count; i++)
                {
                    row = dt.NewRow();

                    for (int j = 0; j < dt.Columns.Count; j++)
                    {

                        if (s_addingLabel == "Y") // HM 출하라벨 마지막에 수량 SUM된 라벨 수량 나오도록. 
                        {
                            if (string.Equals(dt.Columns[j].ColumnName, "LOT_QTY"))
                            {
                                iSumQty = iSumQty + out_node.GetList(0)[i].GetDouble(dt.Columns[j].ColumnName);
                            }
                        }



                        if (string.Equals(dt.Columns[j].ColumnName, "COAT"))
                        {
                            if (MPCF.Trim(out_node.GetList(0)[i].GetString(dt.Columns[j].ColumnName)) != "")
                            {
                                coating_rate = Convert.ToDouble(out_node.GetList(0)[i].GetString(dt.Columns[j].ColumnName));
                            }
                        }

                        if (string.Equals(dt.Columns[j].ColumnName, "INPUT_DATE"))
                        {
                            if (MPCF.Trim(out_node.GetList(0)[i].GetString(dt.Columns[j].ColumnName)) != "")
                            {
                                s_input_date = out_node.GetList(0)[i].GetString(dt.Columns[j].ColumnName).Substring(0, 4) + "년 " +
                                            out_node.GetList(0)[i].GetString(dt.Columns[j].ColumnName).Substring(4, 2) + "월 " +
                                            out_node.GetList(0)[i].GetString(dt.Columns[j].ColumnName).Substring(6, 2) + "일";

                                row[dt.Columns[j].ColumnName] = s_input_date;
                            }
                            else
                            {
                                row[dt.Columns[j].ColumnName] = "";
                            }
                        }
                        else if (string.Equals(dt.Columns[j].ColumnName, "JOB_DATE") || string.Equals(dt.Columns[j].ColumnName, "REG_DATE")
                            || string.Equals(dt.Columns[j].ColumnName, "BOOKED_DATE") || string.Equals(dt.Columns[j].ColumnName, "ORDER_DATE")
                            || string.Equals(dt.Columns[j].ColumnName, "REQUEST_DATE") || string.Equals(dt.Columns[j].ColumnName, "SCHEDULE_SHIP_DATE"))
                        {
                            if (MPCF.Trim(out_node.GetList(0)[i].GetString(dt.Columns[j].ColumnName)) != "")
                            {
                                s_input_date = out_node.GetList(0)[i].GetString(dt.Columns[j].ColumnName).Substring(0, 4) + "-" +
                                            out_node.GetList(0)[i].GetString(dt.Columns[j].ColumnName).Substring(4, 2) + "-" +
                                            out_node.GetList(0)[i].GetString(dt.Columns[j].ColumnName).Substring(6, 2);

                                row[dt.Columns[j].ColumnName] = s_input_date;
                            }
                            else
                            {
                                row[dt.Columns[j].ColumnName] = "";
                            }
                        }
                        else if (string.Equals(dt.Columns[j].ColumnName, "START_TIME"))
                        {
                            if (MPCF.Trim(out_node.GetList(0)[i].GetString(dt.Columns[j].ColumnName)) != "")
                            {
                                s_input_date = MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString(dt.Columns[j].ColumnName), DATE_TIME_FORMAT.DATETIME);

                                row[dt.Columns[j].ColumnName] = s_input_date;
                            }
                        }
                        else if (string.Equals(dt.Columns[j].ColumnName, "BOX_COUNT"))
                        {
                            s_box_count = (i + 1) + "/" + out_node.GetList(0)[i].GetInt(dt.Columns[j].ColumnName);

                            row[dt.Columns[j].ColumnName] = s_box_count;

                        }
                        else if (string.Equals(dt.Columns[j].ColumnName, "GROSS"))
                        {
                            //코팅률이 없을 경우 GROSS 표기 안되게
                            if (coating_rate == 0)
                            {
                                row[dt.Columns[j].ColumnName] = "";
                            }
                            else
                            {
                                gross = Math.Truncate((out_node.GetList(0)[i].GetDouble("LOT_QTY") * 100) / (100 - coating_rate));
                                row[dt.Columns[j].ColumnName] = Convert.ToString(gross);
                            }
                        }
                        else if (string.Equals(dt.Columns[j].ColumnName, "SPEC") && s_label_type == "HM") //HM 스팩
                        {
                            int iComLo;
                            if (out_node.GetList(0)[i].GetString("SPEC").ToString().Contains(" "))
                            {
                                iComLo = out_node.GetList(0)[i].GetString("SPEC").ToString().IndexOf(" ", out_node.GetList(0)[i].GetString("SPEC").ToString().IndexOf(" ", 0));
                                s_spec = out_node.GetList(0)[i].GetString("SPEC").Substring(iComLo + 1);
                                row[dt.Columns[j].ColumnName] = Convert.ToString(s_spec);
                            }
                            else if (out_node.GetList(0)[i].GetString("SPEC").ToString().Contains("."))
                            {
                                iComLo = out_node.GetList(0)[i].GetString("SPEC").ToString().IndexOf(".", out_node.GetList(0)[i].GetString("SPEC").ToString().IndexOf(".", 0));
                                s_spec = out_node.GetList(0)[i].GetString("SPEC").Substring(iComLo + 1);
                                row[dt.Columns[j].ColumnName] = Convert.ToString(s_spec);
                            }


                        }
                        else if (string.Equals(dt.Columns[j].ColumnName, "GRADE") && s_label_type == "HM") //HM GRADE
                        {
                            int iComLo;
                            if (out_node.GetList(0)[i].GetString("SPEC").ToString().Contains(" "))
                            {
                                iComLo = out_node.GetList(0)[i].GetString("SPEC").ToString().IndexOf(" ", out_node.GetList(0)[i].GetString("SPEC").ToString().IndexOf(" ", 0));
                                s_grade = out_node.GetList(0)[i].GetString("SPEC").Substring(0, iComLo);
                                row[dt.Columns[j].ColumnName] = Convert.ToString(s_grade);
                            }
                            else if (out_node.GetList(0)[i].GetString("SPEC").ToString().Contains("."))
                            {
                                iComLo = out_node.GetList(0)[i].GetString("SPEC").ToString().IndexOf(".", out_node.GetList(0)[i].GetString("SPEC").ToString().IndexOf(".", 0));
                                s_grade = out_node.GetList(0)[i].GetString("SPEC").Substring(0, iComLo);
                                row[dt.Columns[j].ColumnName] = Convert.ToString(s_grade);
                            }

                        }

                        else if (string.Equals(dt.Columns[j].ColumnName, "QR_DATA"))
                        {
                            string data = "";

                            if (string.Equals(out_node.GetList(0)[i].GetString("QR_DATA"), ""))
                            {
                                data = "QTY NET : ";
                            }
                            else
                            {
                                data = "QTY GROSS/NET : " + gross + "/";
                            }

                            data += out_node.GetList(0)[i].GetDouble("LOT_QTY");

                            s_qr_data =
                                "LABEL TYPE : " + out_node.GetList(0)[i].GetString("GRADE") + "   " + out_node.GetList(0)[i].GetString("TYPE") + "   "
                                + "LOT SERIAL : " + out_node.GetList(0)[i].GetString("LOT_ID") + "   "
                                + data + "   "
                                + "CUSTOMER ITEM :" + out_node.GetList(0)[i].GetString("LINE_DESC") + "   ";

                            row[dt.Columns[j].ColumnName] = s_qr_data;

                        }
                        else if (string.Equals(dt.Columns[j].ColumnName, "COAT"))
                        {
                            // 코팅퍼센트 정수값으로 출력되야함.
                            if (coating_rate == 0)
                            {
                                row[dt.Columns[j].ColumnName] = "";
                            }
                            else
                            {
                                //
                                temp_coating_rate = Math.Truncate(Convert.ToDouble(out_node.GetList(0)[i].GetString(dt.Columns[j].ColumnName)));
                                row[dt.Columns[j].ColumnName] = Convert.ToString(temp_coating_rate);
                            }

                        }
                        //in_node의 MESH_FLAG = 'N'일 때, 데이터 출력X
                        else if (string.Equals(dt.Columns[j].ColumnName, "ITEM_NAME2") || string.Equals(dt.Columns[j].ColumnName, "TYPE"))
                        {
                            if (in_node.GetChar("MESH_DELETE_FLAG") == 'Y')
                            {
                                row[dt.Columns[j].ColumnName] = "";
                            }
                            else
                            {
                                row[dt.Columns[j].ColumnName] = out_node.GetList(0)[i].GetString(dt.Columns[j].ColumnName);
                            }
                        }
                        else if (string.Equals(dt.Columns[j].ColumnName, "BOX_TYPE") && (c_step == 'B' || c_step == 'C'))  //출하라벨이 박스일 경우 표기
                        {
                            row[dt.Columns[j].ColumnName] = "BOX";
                        }
                        else if (dt.Columns[j].DataType == typeof(double))
                        {
                            row[dt.Columns[j].ColumnName] = out_node.GetList(0)[i].GetDouble(dt.Columns[j].ColumnName);
                        }
                        else if (dt.Columns[j].DataType == typeof(string))
                        {
                            row[dt.Columns[j].ColumnName] = out_node.GetList(0)[i].GetString(dt.Columns[j].ColumnName);
                        }
                        else if (dt.Columns[j].DataType == typeof(int))
                        {
                            row[dt.Columns[j].ColumnName] = out_node.GetList(0)[i].GetInt(dt.Columns[j].ColumnName);
                        }
                        else if (dt.Columns[j].DataType == typeof(char))
                        {
                            row[dt.Columns[j].ColumnName] = out_node.GetList(0)[i].GetChar(dt.Columns[j].ColumnName);
                        }
                    }

                    dt.Rows.Add(row);
                }

                if (s_addingLabel == "Y") // HM 출하라벨 마지막에 수량 SUM된 라벨 수량 나오도록. 
                {

                    TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                    DataTable dt_add = null;
                    string sSql = "";
                    string sViewID = "CSHP3004-005";


                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                    dvcArgu[1].sCondition_ID = "LOT_ID";
                    dvcArgu[1].sCondition_Value = dt.Rows[0]["LOT_ID"].ToString();

                    if (TPDR.GetDataOne("", ref dt_add, sViewID, dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt_add != null)
                            dt_add.Dispose();
                    }
                    else
                    {


                        DataRow NewRow = dt.NewRow();
                        dt.Rows.InsertAt(NewRow, 0);

                        for (int j = 0; j < dt.Columns.Count; j++)
                        {
                            dt.Rows[0][j] = dt.Rows[1][j];
                        }
                        dt.Rows[0]["LOT_QTY"] = iSumQty;
                        dt.Rows[0]["LOT_ID"] = dt_add.Rows[0]["LOT_ID"];

                        switch (sFileName)
                        {
                            case "mtl215p_8":
                            case "mtl215p_8_2":
                            case "mtl215p_8_3":
                                dt.Rows[0]["ITEM_NAME1"] = dt_add.Rows[0]["SPEC"];
                                break;
                            default:
                                dt.Rows[0]["GRADE"] = dt_add.Rows[0]["GRADE"];
                                dt.Rows[0]["SPEC"] = dt_add.Rows[0]["SPEC"];
                                break;
                        }
                        if (s_addingCusLabel == "Y")
                        {

                            if (dt_add.Rows[0]["CUS_MAT_ID"].ToString() == " ")
                            {
                                MPCF.ShowMsgBox("CUSTOMER IS NOT ITEM ID(고객사 품목코드가 없습니다.)");
                                return false;
                            }


                            for (int i = 0; i < dt.Rows.Count; i++)
                            {
                                dt.Rows[i]["CUS_MAT_ID"] = dt_add.Rows[0]["CUS_MAT_ID"];
                                dt.Rows[i]["CUS_LABEL"] = dt_add.Rows[0]["CUS_LABEL"];
                                dt.Rows[i]["CUS_SIZE"] = dt_add.Rows[0]["CUS_SIZE"];
                                dt.Rows[i]["CUS_QTY"] = dt_add.Rows[0]["CUS_QTY"];
                            }
                        }

                    }
                }

                if (sFileName == "t_card")
                {

                    TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                    DataTable dt_udate = null;
                    string sSql = "";
                    string sViewID = "CWIP0001-009";


                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                    dvcArgu[1].sCondition_ID = "ORDER_ID";
                    dvcArgu[1].sCondition_Value = dt.Rows[0]["WIP_ENTITY_NAME"].ToString();

                    if (TPDR.GetDataOne("", ref dt_udate, sViewID, dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt_udate != null)
                            dt_udate.Dispose();
                    }
                    else
                    {

                        for (int i = 0; i < dt.Rows.Count; i++)
                        {
                            dt.Rows[i]["DIAMETER_TARGET"] = dt_udate.Rows[0]["DIAMETER_TARGET"];
                            dt.Rows[i]["DIAMETER_UPPER"] = dt_udate.Rows[0]["DIAMETER_UPPER"];
                            dt.Rows[i]["DIAMETER_LOWER"] = dt_udate.Rows[0]["DIAMETER_LOWER"];
                            dt.Rows[i]["LENGTH_TARGET"] = dt_udate.Rows[0]["LENGTH_TARGET"];
                            dt.Rows[i]["LENGTH_UPPER"] = dt_udate.Rows[0]["LENGTH_UPPER"];
                            dt.Rows[i]["LENGTH_LOWER"] = dt_udate.Rows[0]["LENGTH_LOWER"];

                        }
                        /*
                        dt.Rows[0]["DIAMETER_TARGET"] = dt_udate.Rows[0]["DIAMETER_TARGET"];
                        dt.Rows[0]["DIAMETER_UPPER"] = dt_udate.Rows[0]["DIAMETER_UPPER"];
                        dt.Rows[0]["DIAMETER_LOWER"] = dt_udate.Rows[0]["DIAMETER_LOWER"];
                        dt.Rows[0]["LENGTH_TARGET"] = dt_udate.Rows[0]["LENGTH_TARGET"];
                        dt.Rows[0]["LENGTH_UPPER"] = dt_udate.Rows[0]["LENGTH_UPPER"];
                        dt.Rows[0]["LENGTH_LOWER"] = dt_udate.Rows[0]["LENGTH_LOWER"];
                        */


                    }
                }
                 
                if (dt == null)
                    return false;


                for (int i = 0; i < out_node.GetList("SUB_LIST").Count; i++)
                {
                    sub_row = sub_dt.NewRow();

                    for (int j = 0; j < sub_dt.Columns.Count; j++)
                    {
                        if (sub_dt.Columns[j].DataType == typeof(double))
                        {
                            sub_row[sub_dt.Columns[j].ColumnName] = out_node.GetList("SUB_LIST")[i].GetDouble(sub_dt.Columns[j].ColumnName);
                        }
                        else if (sub_dt.Columns[j].DataType == typeof(string))
                        {
                            sub_row[sub_dt.Columns[j].ColumnName] = out_node.GetList("SUB_LIST")[i].GetString(sub_dt.Columns[j].ColumnName);
                        }
                        else if (sub_dt.Columns[j].DataType == typeof(int))
                        {
                            sub_row[sub_dt.Columns[j].ColumnName] = out_node.GetList("SUB_LIST")[i].GetInt(sub_dt.Columns[j].ColumnName);
                        }
                    }
                    sub_dt.Rows.Add(sub_row);
                }





                if (out_node.GetList("SUB_LIST").Count == 0)
                    DevReport.PreviewXtraReport(dt, sFileName);
                else
                    DevReport.PreviewXtraSubReport(dt, sub_dt, sFileName, subFileName);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }




        public static void ShowMsg(string sMsg)
        {
            StackTrace stackTrace = new StackTrace();
            StackFrame stackFrame = stackTrace.GetFrame(1);
            MethodBase methodBase = stackFrame.GetMethod();

            MPCF.ShowMsgBox($"{methodBase.Name}() : {sMsg}");
        }

        public static string GetFileName(string filepath)
        {
            string returnValue = "";
            int i = 0;
            int pos = 0;

            returnValue = filepath;

            for (i = filepath.Length; i >= 1; i--)
            {
                if (filepath.Substring(i - 1, 1) == "\\")
                {
                    pos = i;
                    break;
                }
            }
            returnValue = filepath.Substring(filepath.Length - (filepath.Length - pos), filepath.Length - pos);
            return returnValue;
        }


        public static void fnGetGlobalArea()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';

                if (MPCR.CallService("CUS_BAS", "CUS_BAS_View_Global_Area_List", in_node, ref out_node) == false)
                {
                    return;
                }
                for (int i = 0; i < out_node.GetList("GCM_TBL").Count; i++)
                {
                    if (out_node.GetList("GCM_TBL")[i].GetString("KEY_1") == CSGC.CP_AREA_CTM)
                    {
                        CSGV.gs_area_ctm = out_node.GetList("GCM_TBL")[i].GetString("DATA_1");
                    }

                    if (out_node.GetList("GCM_TBL")[i].GetString("KEY_1") == CSGC.CP_AREA_PDC)
                    {
                        CSGV.gs_area_pdc = out_node.GetList("GCM_TBL")[i].GetString("DATA_1");
                    }

                    if (out_node.GetList("GCM_TBL")[i].GetString("KEY_1") == CSGC.CP_AREA_HM)
                    {
                        CSGV.gs_area_hm = out_node.GetList("GCM_TBL")[i].GetString("DATA_1");
                    }

                    if (out_node.GetList("GCM_TBL")[i].GetString("KEY_1") == CSGC.CP_AREA_GRT)
                    {
                        CSGV.gs_area_grit = out_node.GetList("GCM_TBL")[i].GetString("DATA_1");
                    }
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        public static void ViewSelectionListSum(FarPoint.Win.Spread.FpSpread spd, int iCol, ref string sCnt, ref string sSum)
        {
            // 현재 활성화된 시트 가져오기
            FarPoint.Win.Spread.SheetView sheet = spd.ActiveSheet;

            // 선택된 영역(Range) 정보 가져오기
            FarPoint.Win.Spread.Model.CellRange range = sheet.GetSelection(0);

            if (range == null) return;

            int count = 0;
            double sum = 0;

            // 선택된 행과 열의 범위를 순회
            for (int r = range.Row; r < range.Row + range.RowCount; r++)
            {

                for (int c = range.Column; c < range.Column + range.ColumnCount; c++)
                {
                    var cellValue = sheet.GetValue(r, c);

                    if (range.Column == iCol)
                    {
                        if (cellValue != null && double.TryParse(cellValue.ToString(), out double num))
                        {
                            sum += num; // 숫자 변환이 가능한 경우 합계에 누적
                        }
                    }

                    count++; // 선택된 총 셀 개수 카운트
                }
            }

            // 결과 출력 또는 레이블에 표시
            //lblCount.Text = $"개수: {count}";
            //lblSum.Text = $"합계: {sum}";
            sCnt = $"{count}";
            sSum = $"{sum}";
        }
    }

    public static class EXTFUC
    {
        /// <summary>
        /// 문자열이 데이터중에 존재하는지 확인
        /// </summary>
        public static bool Include(this string value, params string[] data)
        {
            foreach (string s in data)
            {
                if (value == s)
                {
                    return true;
                }
            }
            return false;
        }

        /// <summary>
        /// 엑셀 파일 저장
        /// </summary>
        /// <param name="sFileName"></param>
        /// <returns></returns>
        public static string ShowFileOpenDialog(string sFileName)
        {
            try
            {
                //파일오픈창 생성 및 설정
                SaveFileDialog sfd = new SaveFileDialog();
                sfd.Title = "파일 위치 지정";
                sfd.FileName = MPCF.Trim(sFileName.Replace(" ", "_")) + "_" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".xlsx";
                sfd.Filter = "엑셀 파일 (*.xls, *.xlsx) | *.xls; *.xlsx | 모든 파일 (*.*) | *.*";

                //파일 오픈창 로드
                DialogResult dr = sfd.ShowDialog();

                //OK버튼 클릭시
                if (dr == DialogResult.OK)
                {
                    //File 명과 확장자를 가지고 온다.
                    //string fileName = ofd.SafeFileName;
                    //File 경로와 File 명을 모두 가지고 온다.
                    string fileFullName = sfd.FileName;
                    //File 경로만 가지고 온다.
                    //string filePath = fileFullName.Replace(fileName, "");

                    return fileFullName;
                }
                //취소버튼 클릭시 또는 ESC키로 파일창을 종료 했을경우
                else if (dr == DialogResult.Cancel)
                {
                    return string.Empty;
                }

                return string.Empty;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return string.Empty;
            }
        }

        /// <summary>
        /// 엑셀저장후 열어줍니다
        /// </summary>
        public static void SaveExcelAndShow(this FpSpread spdObj, string fileNameOnly = "")
        {
            string filename = string.Empty;
            bool protect;
            string path = Path.Combine(Application.StartupPath, "Temp");

            try
            {
                if (!Directory.Exists(path))
                    Directory.CreateDirectory(path);

                if (!string.IsNullOrEmpty(fileNameOnly))
                    filename = Path.Combine(path, fileNameOnly);
                else
                    filename = Path.Combine(path, DateTime.Now.ToString("yyyyMMddHHmmss"));

                if (!Path.GetExtension(filename).Include(".xlsx"))
                {
                    filename = $"{filename}.xlsx";
                }
                //else if (Path.GetExtension(filename).Include(".xlsx"))
                //{
                //    // 문서 확장자가 excel 97인 경우 2003으로 변경
                //    filename = $"{Path.GetFileNameWithoutExtension(filename)}.xls";
                //}


                protect = spdObj.ActiveSheet.Protect;
                spdObj.ActiveSheet.Protect = false;
                spdObj.SaveExcel(filename, FarPoint.Excel.ExcelSaveFlags.SaveCustomColumnHeaders | FarPoint.Excel.ExcelSaveFlags.UseOOXMLFormat);
                //spdObj.SaveExcel(filename, FarPoint.Excel.ExcelSaveFlags.SaveCustomColumnHeaders);

                spdObj.ActiveSheet.Protect = protect;
                Process.Start(filename);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("SaveExcelAndShow() : " + ex.Message);
            }
        }

        public static void SaveExcelAndShow(string filename, Control _ctrl, bool proc_flag)
        {
            bool protect = false;
            string path = Path.Combine(Application.StartupPath, "Temp");
            string tmp_file_name = string.Empty;

            if (!Directory.Exists(path))
                Directory.CreateDirectory(path);

            if (string.IsNullOrEmpty(filename))
                tmp_file_name = DateTime.Now.ToString("yyyyMMddHHmmss");
            else
                tmp_file_name = filename;

            tmp_file_name = Path.Combine(path, tmp_file_name);
            // 확장자 붙이기
            if (!Path.GetExtension(tmp_file_name).Include(".xlsx"))
            {
                tmp_file_name = $"{tmp_file_name}.xlsx";
            }

            FpSpread spread = _ctrl as FpSpread;
            if (spread == null)
                return;

            //true 일경우 엑셀 실행 false 일경우 엑셀 저장
            if (proc_flag == true)
            {
                Process.Start(tmp_file_name);
            }
            else
            {
                protect = spread.ActiveSheet.Protect;
                spread.ActiveSheet.Protect = false;
                spread.SaveExcel(tmp_file_name, FarPoint.Excel.ExcelSaveFlags.SaveCustomColumnHeaders | FarPoint.Excel.ExcelSaveFlags.UseOOXMLFormat);
            }

            return;
        }


        /// <summary>
        /// 엑셀 다운로드
        /// </summary>
        /// <param name="_ctrl">FpSpread 객체</param>
        /// <param name="filename">파일 명</param>
        /// <param name="show_flag">default : true-자동 오픈, false-저장 후 오픈</param>
        /// <returns></returns>
        public static bool SaveExcel(Control _ctrl, string filename, bool show_flag = true)
        {
            try
            {
                string sFileName = string.Empty;

                FpSpread excelSp = new FpSpread();
                FpSpread spread = _ctrl as FpSpread;
                SheetView sv = new SheetView();

                if (spread == null)
                    return false;

                if (show_flag == false) //파일 저장
                {
                    sFileName = EXTFUC.ShowFileOpenDialog(filename);
                }
                else  //파일 바로 오픈
                {
                    string path = Path.Combine(Application.StartupPath, "Temp");

                    if (!Directory.Exists(path))
                        Directory.CreateDirectory(path);

                    if (string.IsNullOrEmpty(filename))
                        filename = DateTime.Now.ToString("yyyyMMddHHmmss");
                    else
                        filename = string.Format("{0}_{1}", filename, DateTime.Now.ToString("yyyyMMddHHmmss"));

                    sFileName = Path.Combine(path, filename);
                    // 확장자 붙이기
                    if (!Path.GetExtension(sFileName).Include(".xlsx"))
                    {
                        sFileName = $"{sFileName}.xlsx";
                    }
                }


                for (int i = 0; i < spread.Sheets.Count; i++)
                {
                    sv = spread.Sheets[i];


                    //   sv.SheetName = string.Format("Sheet{0}", (i + 1));
                    sv.ColumnCount = spread.Sheets[i].ColumnCount;
                    sv.RowCount = spread.Sheets[i].RowCount;
                    sv.Protect = false;
                    excelSp.Sheets.Add(sv);

                }
                // File 명에 / 있으면 Error 발생해서 수정함
                sFileName = sFileName.Replace("/", "-");


                // excelSp.SaveExcel(sFileName, FarPoint.Excel.ExcelSaveFlags.SaveCustomColumnHeaders | FarPoint.Excel.ExcelSaveFlags.UseOOXMLFormat);
                //2025-05-09 syw Sort 변경한경우 변경된 Sort로 출력되도록 변경
                excelSp.SaveExcel(sFileName, FarPoint.Excel.ExcelSaveFlags.SaveCustomColumnHeaders | FarPoint.Excel.ExcelSaveFlags.SaveAsViewed | FarPoint.Excel.ExcelSaveFlags.UseOOXMLFormat);

                for (int i = 0; i < spread.Sheets.Count; i++)
                {
                    sv = spread.Sheets[i];
                    sv.Protect = true;
                }
                if (show_flag)
                {
                    Process.Start(sFileName);
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }


        public static bool SaveExcel2(Control _ctrl, string filename, bool show_flag = true)
        {
            try
            {
                string empty = string.Empty;
                FpSpread fpSpread = new FpSpread();
                if (!(_ctrl is FpSpread fpSpread2))
                {
                    return false;
                }
                if (!show_flag)
                {
                    empty = ShowFileOpenDialog(filename);
                }
                else
                {
                    string text = Path.Combine(System.Windows.Forms.Application.StartupPath, "Temp");
                    if (!Directory.Exists(text))
                    {
                        Directory.CreateDirectory(text);
                    }
                    filename = ((!string.IsNullOrEmpty(filename)) ? string.Format("{0}_{1}", filename, DateTime.Now.ToString("yyyyMMddHHmmss")) : DateTime.Now.ToString("yyyyMMddHHmmss"));
                    empty = Path.Combine(text, filename);
                    if (!Include(Path.GetExtension(empty), ".xlsx"))
                    {
                        empty += ".xlsx";
                    }
                }
                for (int i = 0; i < fpSpread2.Sheets.Count; i++)
                {
                    SheetView sheetView = fpSpread2.Sheets[i];
                    SheetView sheetView2 = new SheetView();
                    List<int> list = new List<int>();
                    for (int j = 0; j < sheetView.ColumnCount; j++)
                    {
                        FarPoint.Win.Spread.CellType.ICellType cellType = sheetView.Columns[j].CellType;
                        if (!(cellType is FarPoint.Win.Spread.CellType.ButtonCellType) && sheetView.Columns[j].Visible)
                        {
                            list.Add(j);
                        }
        


                    }
                    sheetView2.RowCount = sheetView.RowCount;
                    sheetView2.ColumnCount = list.Count;
                    sheetView2.SheetName = sheetView.SheetName;
                    sheetView2.Protect = false;
                    sheetView2.ColumnHeaderRowCount = sheetView.ColumnHeaderRowCount;
                    for (int k = 0; k < list.Count; k++)
                    {
                        int column = list[k];
                        sheetView2.Columns[k].Width = sheetView.Columns[column].Width;
                        for (int l = 0; l < sheetView.ColumnHeader.RowCount; l++)
                        {
                            sheetView2.ColumnHeader.Cells[l, k].Value = sheetView.ColumnHeader.Cells[l, column].Value;
                            sheetView2.ColumnHeader.Cells[l, k].Font = sheetView.ColumnHeader.Cells[l, column].Font;
                            sheetView2.ColumnHeader.Cells[l, k].HorizontalAlignment = sheetView.ColumnHeader.Cells[l, column].HorizontalAlignment;
                            sheetView2.ColumnHeader.Cells[l, k].VerticalAlignment = sheetView.ColumnHeader.Cells[l, column].VerticalAlignment;
                            sheetView2.ColumnHeader.Cells[l, k].BackColor = sheetView.ColumnHeader.Cells[l, column].BackColor;
                            sheetView2.ColumnHeader.Cells[l, k].RowSpan = sheetView.ColumnHeader.Cells[l, column].RowSpan;
                            sheetView2.ColumnHeader.Cells[l, k].ColumnSpan = sheetView.ColumnHeader.Cells[l, column].ColumnSpan;
                        }
                        for (int m = 0; m < sheetView.RowCount; m++)
                        {
                            FarPoint.Win.Spread.Cell cell = sheetView.Cells[m, column];
                            FarPoint.Win.Spread.Cell cell2 = sheetView2.Cells[m, k];
                            cell2.Value = cell.Value;
                            cell2.CellType = cell.CellType;
                            cell2.Font = cell.Font;
                            cell2.BackColor = cell.BackColor;
                            cell2.ForeColor = cell.ForeColor;
                            cell2.HorizontalAlignment = cell.HorizontalAlignment;
                            cell2.VerticalAlignment = cell.VerticalAlignment;
                            cell2.Locked = false;
                        }
                    }
                    fpSpread.Sheets.Add(sheetView2);
                }
                empty = empty.Replace("/", "-");
                fpSpread.SaveExcel(empty, FarPoint.Excel.ExcelSaveFlags.SaveAsViewed | FarPoint.Excel.ExcelSaveFlags.SaveCustomColumnHeaders | FarPoint.Excel.ExcelSaveFlags.UseOOXMLFormat);
 
                if (show_flag)
                {
                    Process.Start(empty);
                }
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }



        /// <summary>
        /// 선택된 ROW로 이동
        /// </summary>
        /// <param name="spd"></param>
        /// <param name="iActiveRowIdx"></param>
        public static void SetSelectSheet(FarPoint.Win.Spread.FpSpread spd, int iActiveRowIdx)
        {
            try
            {
                SheetView sv = spd.ActiveSheet;

                sv.ClearSelection();
                sv.AddSelection(iActiveRowIdx, 0, 1, sv.ColumnCount);
                spd.ShowRow(0, iActiveRowIdx, VerticalPosition.Nearest);
                sv.SetActiveCell(iActiveRowIdx, 1);
                sv.Rows[iActiveRowIdx].BackColor = Color.FromArgb(255, 192, 255);
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        /// <summary>
        ///선택된 ROW로 배경색 변경
        /// </summary>
        /// <param name="spd"></param>
        /// <param name="iActiveRowIndex"></param>
        public static void SetSelectRowColor(FarPoint.Win.Spread.FpSpread spd, int iActiveRowIndex)
        {
            try
            {
                SheetView sv = spd.ActiveSheet;

                for (int i = 0; i < sv.RowCount; i++)
                {
                    sv.Rows[i].BackColor = Color.FromArgb(255, 255, 255);


                }
                sv.Rows[iActiveRowIndex].BackColor = Color.FromArgb(255, 192, 255);



            }
            catch (Exception ex)
            {
                throw ex;
            }
        }



        //20220519 Excel Report기능 추가.
        public static void PreviewExcelReport(DataTable dt, string reportName)
        {


            string sCurrentPath = "";
            string sfilePath = "";
            string sfileName = "";
            string sFolderName = "\\Report\\";


            xExcel.Application XApp = null;
            xExcel.Workbooks XBooks = null;
            xExcel.Workbook XBook = null;
            xExcel.Worksheet XSheet = null;
            xExcel.Sheets XSheets = null;


            string path = Path.Combine(Application.StartupPath, "Temp");


            try
            {
                if (reportName == "")
                    return;

                sCurrentPath = $"{System.Windows.Forms.Application.StartupPath}{sFolderName}";

                //로컬에 폴더가 있는지 체크한다. 없으면 폴더 생성
                if (Directory.Exists(sCurrentPath) == false)
                {
                    Directory.CreateDirectory(sCurrentPath);
                }

                //최종 파일 경로
                sfilePath = $"{sCurrentPath}{reportName}.Xlsx";

                if (CheckFileVersion(sfilePath, reportName) == false)
                {
                    return;
                }


                XApp = new xExcel.Application();

                XBooks = XApp.Workbooks;
                XBook = XApp.Workbooks.Open(sfilePath);



                XSheets = XBook.Worksheets;
                XSheet = XSheets.get_Item(1) as xExcel.Worksheet;




                //dt 컬럼 0:sheet, 1:Col ,2:Row , 3:data
                for (int i = 0; i < dt.Rows.Count; i++)
                {

                    XSheet.Cells[MPCF.ToInt(dt.Rows[i][2].ToString()), dt.Rows[i][1].ToString()] = dt.Rows[i][3].ToString();

                }



                sfileName = $"{Path.Combine(path, DateTime.Now.ToString("yyyyMMddHHmmss"))}.xlsx";

                XBook.SaveAs(sfileName);
                XApp.Visible = true;


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            finally
            {
                ReleasExcelObject(XSheet);
                ReleasExcelObject(XBook);
                ReleasExcelObject(XApp);
            }

        }
        public static void ReleasExcelObject(object obj)
        {
            try
            {
                if (obj != null)
                {
                    System.Runtime.InteropServices.Marshal.ReleaseComObject(obj);
                    obj = null;
                }
            }
            catch (Exception ex)
            {
                obj = null;
                throw ex;
            }
            finally
            {
                GC.Collect();
            }
        }


        public static bool CheckFileVersion(string filePath, string fileName)
        {
            string sCreateTime;

            long iFileSize;
            DateTime create_time;
            TRSNode in_node = new TRSNode("View_File_IN");
            TRSNode out_node = new TRSNode("View_File_OUT");

            try
            {
                FileInfo fi = new FileInfo(filePath);

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = 'D';
                in_node.AddString("FILE_NAME", $"{fileName}.Xlsx");

                if (fi.Exists == false)
                {
                    in_node.AddString("CREATION_TIME", "19001231000000");
                    in_node.AddInt("FILE_SIZE", 0);
                }
                else
                {
                    create_time = fi.CreationTime;
                    sCreateTime = MPCF.ToStandardTime(create_time, MPGC.MP_CONVERT_DATETIME_FORMAT);
                    iFileSize = fi.Length;

                    in_node.AddString("CREATION_TIME", sCreateTime);
                    in_node.AddInt("FILE_SIZE", iFileSize);
                }

                if (MPCR.CallService("CUS_BAS", "CUS_BAS_Update_Reports_File", in_node, ref out_node) == false)
                {
                    return false;
                }

                if (out_node.GetChar("UPDATE_YN") == 'Y')
                    DownReport(out_node, filePath);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox($"ViewScreen() : {ex.Message}");
                return false;
            }
        }



        private static bool DownReport(TRSNode out_node, string filePath)
        {
            FileStream fs = null;
            BinaryWriter bw = null;

            try
            {
                string sPath = $"{filePath}";
                fs = File.Open($"{sPath}", FileMode.Create);
                bw = new BinaryWriter(fs);
                byte[] buffer;
                DateTime dt_create_time;

                fs.Flush();
                buffer = out_node.GetBlob(MPGC.MP_BIN_DATA_3);
                bw.Write(buffer);

                bw.Close();
                fs.Close();

                dt_create_time = MPCF.ToDate(out_node.GetString("D_CREATION_TIME"));
                File.SetCreationTime($"{sPath}", dt_create_time);

                //MPCR.ZipDecompress(sPath);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox($"UpdateRepx() : {ex.Message}");
                return false;
            }
            finally
            {
                if (bw != null)
                {
                    bw.Dispose();
                    bw = null;
                }

                if (fs != null)
                {
                    fs.Dispose();
                    fs = null;
                }
            }
        }


    }
}
