using CUS_COM;
using FarPoint.Win.Spread;
using Miracom.CliFrx;
using Miracom.DNMCore;
using Miracom.MESCore;
using Miracom.TRSCore;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CUS_QCM
{
    public partial class frmViewInspectionLBadCtm : CUS_COM.frmViewForm02
    {
        public frmViewInspectionLBadCtm()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "
        private enum INSPECTION_LIST
        {
            INSP_ID,
            INSP_TYPE,
            LOT_ID,
            MAT_GRADE,
            MAT_SIZE,
            REQUEST_TIME,
            JUDGE_TIME,
            INSP_STATUS,
            INSP_JUDGE,
            MAT_ID,
            MAT_DESC,
            UNIT,
            QTY,
            VENDOR_LOT_ID
        }

        private enum COLLECTION_DATA
        {
            CHAR_COL,
            CHAR_DESC_COL,
            CHAR_SEQ,
            LOWER_SPEC_LIMIT,
            TARGET_VALUE,
            UPPER_SPEC_LIMIT,
            SPEC_COL,
            OPT_INPUT_COL,
            VALUE_TYPE_COL,
            VALUE_COUNT_COL,
            DEF_UNIT_FLAG_COL,
            DEF_UNIT_OVR_FLAG_COL,
            DEF_VALUE_COL,
            UNIT_TBL_COL,
            VALUE_TBL_COL,
            UNIT_SEQ_COL,
            UNIT_COL,
            VALUE_START_COL
        }

        #endregion

        #region " Variable Definition"

        private const int DEFAULT_COL_COUNT = 17;

        private const int MAX_DATA_COUNT = 5000;

        private int sheet_st_column_count = 0;


        #endregion

        #region " Function Definition"

        private void InitControl()
        {
            try
            {
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnExcel.Anchor = AnchorStyles.Top | AnchorStyles.Right;


                sheet_st_column_count = spdInspectionList_Sheet1.ColumnCount;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool viewInspStatusList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';


            in_node.AddString("SQL", "SELECT KEY_1 AS CODE, "
                                                + "   DATA_1 AS VALUE "
                                              + " FROM MGCMTBLDAT "
                                            + " WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                            + "  AND TABLE_NAME = '" + CSGC.CP_GCM_INSP_STATUS + "' "
                                            + "  AND KEY_1 != 'C' "
                                            + " ORDER BY DATA_3");


            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCR.FillDataView(listView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);



            return true;
        }

        private void ClearList(string sType)
        {

            /*
            switch (sType)
            {
                case
                "COL_SET_CHANGED":

                    MPCF.ClearList(spdDataCollection);
                    txtColSetVer.Text = "";
                    spdDataCollection.ActiveSheet.ColumnCount = DEFAULT_COL_COUNT;

                    break;
            }
            */

        }
        private bool viewOperList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            /*
            in_node.AddString("SQL", "SELECT OPER AS CODE, "
                                                + "               OPER_DESC AS NAME "
                                                + "         FROM MWIPOPRDEF "
                                                + "        WHERE AREA_ID = '" + cdvDept.Text + "' "
                                                + "          AND SUB_AREA_ID = '" + cdvWorkPlace.Text + "' "
                                                + "          AND OPER_GRP_2 <> 'NONE' "
                                                + "         AND OPER_GRP_2 > ' ' "
                                                + "        ORDER BY OPER"); */


            in_node.AddString("SQL", "SELECT OPER AS CODE, "
                                               + "               OPER_DESC AS NAME "
                                               + "         FROM MWIPOPRDEF "
                                               + "        WHERE AREA_ID = '" + cdvDept.Text + "' "
                                               + "          AND OPER_GRP_2 <> 'NONE' "
                                               + "         AND OPER_GRP_2 > ' ' "
                                               + "        ORDER BY OPER");


            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCR.FillDataView(listView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);

            return true;
        }

        #endregion

        #region " Event Definition"
        private void cdvInspectionType_ButtonPress(object sender, EventArgs e)
        {
            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(cdvInspectionType.GetListView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            in_node.AddString("SQL", "SELECT KEY_1 AS CODE, "
                                                  + "         DATA_1 AS VALUE "
                                                  + "   FROM MGCMTBLDAT   "
                                                  + "  WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                                  + "  AND TABLE_NAME = 'C_INSP_TYPE' "
                                                  + "  AND KEY_1 != 'IQC' "
                                                  + "  ORDER BY DATA_2 ");

            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return;
                }

                MPCR.FillDataView(cdvInspectionType.GetListView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);

        }
        private void btnView_Click(object sender, EventArgs e)
        {

            if (MPCF.Trim(cdvDept.Text) == "")
            {
                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                cdvDept.Focus();
                return;
            }






        }
        private void cdvOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }
                /*
                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return;
                }*/

                viewOperList(cdvOper.GetListView);

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                FpSpread excelSp = new FpSpread();
                spdInspectionList_Sheet1.SheetName = "Sheet1";
                excelSp.Sheets.Add(spdInspectionList_Sheet1);

                //병합된 칼럼 색깔이 안나와서
             /*  for (int i = 0; i < excelSp.Sheets[1].ColumnCount; i++)
                {
                    excelSp.Sheets[1].ColumnHeader.Columns[i].BackColor = Color.FromArgb(14, 86, 155);
                } */

                EXTFUC.SaveExcel(excelSp, "InspectionList");
                
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }
        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            cdvOper.Text = "";

        }
        private void btnClose_Click(object sender, EventArgs e)
        {

        }
        private void cdvSearchType_ButtonPressed(object sender, Miracom.UI.MCCodeViewButtonPressed_EventArgs e)
        {

        }
        private void cdvMat_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {

        }
        private void lblMat_Click(object sender, EventArgs e)
        {

        }
        private void btnLotListHidden_MouseMove(object sender, MouseEventArgs e)
        {

            // 현업요청땜시 만들기는 했는데 별로 실용성이 그냥 클릭으로 바꿈20210913 별로 실용성이
            /*
            if (e.Button == MouseButtons.Left)
            {

                if (ix < Convert.ToInt32(e.Location.X))
                {
                    if(tableLayoutPanel1.ColumnStyles[0].Width < 220 && tableLayoutPanel1.ColumnStyles[0].Width >= 0)
                    {
                        tableLayoutPanel1.ColumnStyles[0].Width = tableLayoutPanel1.ColumnStyles[0].Width + 4;//tableLayoutPanel1.ColumnStyles[0].Width + (ix - Convert.ToInt32(e.Location.X));
                    }
                }
                else
                {
                    if (tableLayoutPanel1.ColumnStyles[0].Width > 0)
                    {
                        tableLayoutPanel1.ColumnStyles[0].Width = tableLayoutPanel1.ColumnStyles[0].Width - 4;//tableLayoutPanel1.ColumnStyles[0].Width - (ix + Convert.ToInt32(e.Location.X));
                    }
                }
            }

            ix = Convert.ToInt32(e.Location.X);

            */
        }
        private void btnLotListHidden_MouseClick(object sender, MouseEventArgs e)
        {
            if (tableLayoutPanel1.ColumnStyles[0].Width == 0)
            {
                tableLayoutPanel1.ColumnStyles[0].Width = 220;
            }
            else
            {
                tableLayoutPanel1.ColumnStyles[0].Width = 0;

            }
        }
        private void spdSearchLotList_CellClick(object sender, CellClickEventArgs e)
        {

        }
        private void spdSearchLotList_Change(object sender, ChangeEventArgs e)
        {

        }
        private void spdSearchLotList_KeyDown(object sender, KeyEventArgs e)
        {

        }
        private void fpSpread1_CellClick(object sender, CellClickEventArgs e)
        {

        }
        #endregion
    }
}
