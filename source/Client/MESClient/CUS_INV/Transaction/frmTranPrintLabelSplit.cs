using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using FarPoint.Win.Spread;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;


namespace CUS_INV
{
    public partial class frmTranPrintLabelSplit : CUS_COM.frmTranForm05
    {
        public frmTranPrintLabelSplit()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "


        // LOT LIST
        private enum LOT_INFO
        {
            FACTORY,
            AREA_ID,
            FILE_NAME,
            SEQ,
            LABEL_SIZE,
            PRINT_DATE,
            LOT_ID,
            ITEM_CODE,
            ITEM_NAME,
            INPUT_DATE,
            LOT_QTY,
            UOM,
            VENDOR_NAME,
            SUPPLIER_LOT_ID,
            CELL_NO,
            WO_NO,
            PC0201,
            PC0202,
            PC0203,
            PC0204,
            MAIN_LOT_ID,
            GRADE,
            ITEM_UOM,
            REMARKS,
            GROUP_ID,
            ITEM_NAME2,
            TYPE,
            SPEC,
            BOX_COUNT,
            ITEM_NAME1,
            ITEM,
            PO_NUMBER,
            MN_NO,
            DRAWING_FLAG,
            COAT,
            GROSS
        }


        private enum CBASLBLDAT
        {
            FACTORY,
            AREA_ID,
            FILE_NAME,
            SEQ,
            LABEL_SIZE,
            PRINT_DATE,
            LOT_ID,
            ITEM_CODE,
            ITEM_NAME,
            INPUT_DATE,
            LOT_QTY,
            UOM,
            VENDOR_NAME,
            SUPPLIER_LOT_ID,
            CELL_NO,
            WO_NO,
            PC0201,
            PC0202,
            PC0203,
            PC0204,
            MAIN_LOT_ID,
            GRADE,
            ITEM_UOM,
            REMARKS,
            GROUP_ID,
            ITEM_NAME2,
            TYPE,
            SPEC,
            BOX_COUNT,
            ITEM_NAME1,
            ITEM,
            PO_NUMBER,
            MN_NO,
            DRAWING_FLAG,
            COAT,
            GROSS
        }





        #endregion

        #region " Variable Definition "

        SheetView sv = null;
        FpSpread sp = null;

        string file_name = "";
        string area_id = "";
        string label_size = "";
        string s_area_desc = "";
        string s_label_name = "";



        private void ViewLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;

                dvcArgu[3].sCondition_ID = "MAT_ID";
                dvcArgu[3].sCondition_Value = cdvMatid.Text;

                dvcArgu[4].sCondition_ID = "FROM_DATE";
                dvcArgu[4].sCondition_Value = dtpFrDate.Text;

                dvcArgu[5].sCondition_ID = "TO_DATE";
                dvcArgu[5].sCondition_Value = dtpToDate.Text;


                dvcArgu[6].sCondition_ID = "MAT_DESC";
                dvcArgu[6].sCondition_Value = txtMatDesc.Text;


                if (TPDR.GetDataOne("", ref dt, "CBAS2002-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLotList);
                    return;
                }

                MPCF.ClearList(spdLotList);
                MPCF.ClearList(spdSplitList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Sheet1.RowCount++;

                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.FACTORY].Value = dt.Rows[i]["FACTORY"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.FILE_NAME].Value = dt.Rows[i]["FILE_NAME"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.SEQ].Value = dt.Rows[i]["SEQ"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.LABEL_SIZE].Value = dt.Rows[i]["LABEL_SIZE"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.PRINT_DATE].Value = dt.Rows[i]["PRINT_DATE"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.ITEM_CODE].Value = dt.Rows[i]["ITEM_CODE"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.ITEM_NAME].Value = dt.Rows[i]["ITEM_NAME"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.INPUT_DATE].Value = dt.Rows[i]["INPUT_DATE"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.UOM].Value = dt.Rows[i]["UOM"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.VENDOR_NAME].Value = dt.Rows[i]["VENDOR_NAME"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.SUPPLIER_LOT_ID].Value = dt.Rows[i]["SUPPLIER_LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.CELL_NO].Value = dt.Rows[i]["CELL_NO"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.WO_NO].Value = dt.Rows[i]["WO_NO"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.PC0201].Value = dt.Rows[i]["PC0201"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.PC0202].Value = dt.Rows[i]["PC0202"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.PC0203].Value = dt.Rows[i]["PC0203"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.PC0204].Value = dt.Rows[i]["PC0204"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.MAIN_LOT_ID].Value = dt.Rows[i]["MAIN_LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.ITEM_UOM].Value = dt.Rows[i]["ITEM_UOM"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.REMARKS].Value = dt.Rows[i]["REMARKS"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.GROUP_ID].Value = dt.Rows[i]["GROUP_ID"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.ITEM_NAME2].Value = dt.Rows[i]["ITEM_NAME2"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.TYPE].Value = dt.Rows[i]["TYPE"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.SPEC].Value = dt.Rows[i]["SPEC"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.BOX_COUNT].Value = dt.Rows[i]["BOX_COUNT"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.ITEM_NAME1].Value = dt.Rows[i]["ITEM_NAME1"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.ITEM].Value = dt.Rows[i]["ITEM"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.PO_NUMBER].Value = dt.Rows[i]["PO_NUMBER"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.MN_NO].Value = dt.Rows[i]["MN_NO"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.DRAWING_FLAG].Value = dt.Rows[i]["DRAWING_FLAG"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.COAT].Value = dt.Rows[i]["COAT"];
                    spdLotList_Sheet1.Cells[i, (int)CBASLBLDAT.GROSS].Value = dt.Rows[i]["GROSS"];

                }

                MPCF.FitColumnHeader(spdLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnRowAdd.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnRowDel.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                txtPrintQty.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                lblPrintQty.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                dtpToDate.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                dtpFrDate.Anchor = AnchorStyles.Top | AnchorStyles.Left;


                this.dtpToDate.Value = DateTime.Now;
                this.dtpFrDate.Value = dtpToDate.Value.AddDays(-7);




                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.FACTORY).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.FILE_NAME).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.SEQ).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.LABEL_SIZE).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.ITEM_CODE).Visible = true;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.ITEM_NAME).Visible = true;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.INPUT_DATE).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.UOM).Visible = true;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.VENDOR_NAME).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.SUPPLIER_LOT_ID).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.CELL_NO).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.WO_NO).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.PC0201).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.PC0202).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.PC0203).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.PC0204).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.MAIN_LOT_ID).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.GRADE).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.ITEM_UOM).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.REMARKS).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.GROUP_ID).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.ITEM_NAME2).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.TYPE).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.SPEC).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.BOX_COUNT).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.ITEM_NAME1).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.ITEM).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.PO_NUMBER).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.MN_NO).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.DRAWING_FLAG).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.COAT).Visible = false;
                spdLotList_Sheet1.Columns.Get((int)CBASLBLDAT.GROSS).Visible = false;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //초기화 함수
        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":
                        if (sp != null) MPCF.ClearList(sp);
                        break;

                    case "SAVE":
                        MPCF.ClearList(sp);
                        break;

                    case "DELETE":
                        MPCF.ClearList(sp);
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //벨리데이션 체크
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }
                if (MPCF.Trim(cdvLabelName.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLabelName.Text + "]");
                    cdvLabelName.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:


                        break;

                    case CSGC.CHECK.SAVE:


                        break;

                    case CSGC.CHECK.DELETE:


                        break;

                    case CSGC.CHECK.ADD:


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

        //라벨명 조회
        private bool ViewLabelNameGCMList(Control control, string sArea, string sLabelType = "")
        {
            string sViewID = "";

            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                string sSql = "";

                sViewID = "CLBL1001-003";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "KEY_1";
                dvcArgu[1].sCondition_Value = sArea;

                dvcArgu[2].sCondition_ID = "DATA_2";
                dvcArgu[2].sCondition_Value = sLabelType;

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return false;

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["DATA_1"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["DATA_3"].ToString());
                            itmX.SubItems.Add(row["KEY_2"].ToString());
                        }
                        ((ListView)control).Items.Add(itmX);
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

        //라벨사이즈 조회
        private bool ViewLabelSize(TextBox textbox, string sFileName)
        {
            string sViewID = "";

            try
            {
                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                sViewID = "CLBL1001-004";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "KEY_2";
                dvcArgu[1].sCondition_Value = sFileName;


                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return false;

                foreach (DataRow row in dt.Rows)
                {
                    textbox.Text = row["DATA_3"].ToString();
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //라벨 조회
        private void ViewLabel(string sAreaId, string sFileName)
        {
            try
            {
                sFileName = cdvLabelName.Text;


                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.FACTORY).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.AREA_ID).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.FILE_NAME).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.SEQ).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.LABEL_SIZE).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.PRINT_DATE).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.LOT_ID).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.ITEM_CODE).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.ITEM_NAME).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.INPUT_DATE).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.LOT_QTY).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.UOM).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.VENDOR_NAME).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.SUPPLIER_LOT_ID).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.CELL_NO).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.WO_NO).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.PC0201).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.PC0202).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.PC0203).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.PC0204).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.MAIN_LOT_ID).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.GRADE).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.ITEM_UOM).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.REMARKS).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.GROUP_ID).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.ITEM_NAME2).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.TYPE).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.SPEC).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.BOX_COUNT).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.ITEM_NAME1).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.ITEM).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.PO_NUMBER).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.MN_NO).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.DRAWING_FLAG).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.COAT).Visible = false;
                spdLotList.ActiveSheet.Columns.Get((int)LOT_INFO.GROSS).Visible = false;


                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.FACTORY).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.FILE_NAME).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.SEQ).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LABEL_SIZE).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_CODE).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.INPUT_DATE).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.UOM).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.VENDOR_NAME).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.SUPPLIER_LOT_ID).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.CELL_NO).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.WO_NO).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PC0201).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PC0202).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PC0203).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PC0204).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.MAIN_LOT_ID).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_UOM).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.REMARKS).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GROUP_ID).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME2).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.TYPE).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.SPEC).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.BOX_COUNT).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME1).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PO_NUMBER).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.MN_NO).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.DRAWING_FLAG).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.COAT).Visible = false;
                spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GROSS).Visible = false;


                switch (sFileName)
                {
                    //원자재입고라벨
                    case "mtl100p":
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_CODE).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.INPUT_DATE).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.UOM).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.VENDOR_NAME).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.SUPPLIER_LOT_ID).Visible = true;


                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_CODE).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.INPUT_DATE).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.UOM).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.VENDOR_NAME).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.SUPPLIER_LOT_ID).Visible = true;

                        break;

                    //CTM 공정라벨(CELL 라벨)
                    case "prd996t":

                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.CELL_NO).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.WO_NO).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PC0201).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PC0202).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PC0203).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PC0204).Visible = true;


                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.CELL_NO).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.WO_NO).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PC0201).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PC0202).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PC0203).Visible = true;
                        spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PC0204).Visible = true;

                        break;

                    //CTM 공정라벨(가공라벨 LOT)
                    case "prd106vp":

                             spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                             spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.MAIN_LOT_ID).Visible = true;
                             spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                             spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.WO_NO).Visible = true;


                             spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                             spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                             spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.MAIN_LOT_ID).Visible = true;
                             spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                             spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.WO_NO).Visible = true;
                        break;

                    //CTM 공정라벨(가공라벨 ITEM)
                    case "prd106vpitem":

                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.MAIN_LOT_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME).Visible = true;

                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.MAIN_LOT_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME).Visible = true;
                        break;

                    //GRIT 공정라벨
                    case "prd205p":

                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.MAIN_LOT_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_CODE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_UOM).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.WO_NO).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.REMARKS).Visible = true;


                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.MAIN_LOT_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_CODE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_UOM).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.WO_NO).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.REMARKS).Visible = true;

                        break;

                    //PDC 공정라벨
                    case "prd205ppdc":

                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.MAIN_LOT_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.WO_NO).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GROUP_ID).Visible = true;

                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.MAIN_LOT_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.WO_NO).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GROUP_ID).Visible = true;

                        break;

                    //CTM 출하라벨(66x90)
                    case "mtl900hm3p":
                    case "mtl900hm3_2p":
                    case "mtl900hm3_4p":

                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME2).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.TYPE).Visible = true;


                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME2).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.TYPE).Visible = true;

                        break;


                    //CTM 출하라벨(66x90)2
                    case "mtl900hm3_1p":
                    case "mtl900hm3_3p":

                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME2).Visible = true;



                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME2).Visible = true;

                        break;

                    //CTM 출하라벨(30x85_INSERT제품)
                    case "mtl900hm6p":

                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.TYPE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_UOM).Visible = true;



                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.TYPE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_UOM).Visible = true;

                        break;

                    //HM 출하라벨(45x55)
                    case "mdprd860phmbp":
                    case "mdprd860phmbp_2":


                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.SPEC).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.REMARKS).Visible = true;

                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.SPEC).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.REMARKS).Visible = true;

                        break;

                    //HM 출하라벨(90x22)
                    case "mdprd860phmap":
                    case "mdprd860phmap_2":
                    case "mdprd860phmap_4":
                    case "mdprd860phmap_5":
                    case "mdprd860phmap_6":

                        spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.SPEC).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.REMARKS).Visible = true;

                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.SPEC).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.REMARKS).Visible = true;

                        break;

                    //HM 출하라벨(90x95)
                    case "mtl215p_8":
                    case "mtl215p_8_2":

                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME1).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME2).Visible = true;


                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME1).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM_NAME2).Visible = true;

                        break;

                    //PDC 출하라벨(92x88)
                    case "mtl900hm5p":

                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.TYPE).Visible = true;

                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.TYPE).Visible = true;

                        break;

                    //PDC 출하라벨(49x55)
                    case "mtl900hm9p":

                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PO_NUMBER).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.MN_NO).Visible = true;


                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.ITEM).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PO_NUMBER).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.MN_NO).Visible = true;

                        break;

                    //GRIT 출하라벨(120x90)
                    case "prd840grtp3":

                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.TYPE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.DRAWING_FLAG).Visible = true;

                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.TYPE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.DRAWING_FLAG).Visible = true;

                        break;

                    //GRIT 출하라벨(62x43)
                    case "prd840grtp5":

                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.TYPE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.DRAWING_FLAG).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.COAT).Visible = true;


                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.TYPE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.DRAWING_FLAG).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.COAT).Visible = true;

                        break;

                    //GRIT 출하라벨(62x43_QR)
                    case "prd840grtp2_DM":

                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.TYPE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.DRAWING_FLAG).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.COAT).Visible = true;


                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.TYPE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.DRAWING_FLAG).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.COAT).Visible = true;


                        break;

                    //GRIT 출하라벨(76x26)
                    case "840Sample":

                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.TYPE).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.DRAWING_FLAG).Visible = true;
                            spdLotList.ActiveSheet.Columns.Get((int)CBASLBLDAT.COAT).Visible = true;



                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.AREA_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.PRINT_DATE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_ID).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.LOT_QTY).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.GRADE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.TYPE).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.DRAWING_FLAG).Visible = true;
                            spdSplitList.ActiveSheet.Columns.Get((int)CBASLBLDAT.COAT).Visible = true;



                        break;

                }
               
                MPCF.FitColumnHeader(sv);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //라벨 출력
        private void PrintLabel(string sPrintLabel, TRSNode out_node)
        {
            try
            {
                CSCF.ViewLabelList(sPrintLabel, out_node, 'L');
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        //출력 라벨 리스트 저장
        private bool SaveLabelList(string sAreaId, string sFileName)
        {
            TRSNode in_node = new TRSNode("Print_Label_List_In");
            TRSNode out_node = new TRSNode("Print_Label_List_Out");
            TRSNode label_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("AREA_ID", sAreaId);
                in_node.AddString("FILE_NAME", cdvLabelName);
                in_node.AddString("LABEL_SIZE", label_size);

                sFileName = cdvLabelName.Text;

                switch (sFileName)
                {
                    //원자재입고라벨
                    case "mtl100p":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_ID].Text);
                                label_list.AddString("ITEM_CODE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.ITEM_CODE].Text);
                                label_list.AddString("ITEM_NAME", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.ITEM_NAME].Text);
                                label_list.AddString("INPUT_DATE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.INPUT_DATE].Text.Replace("-", ""));
                                label_list.AddDouble("LOT_QTY", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_QTY].Text);
                                label_list.AddString("UOM", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.UOM].Text);
                                label_list.AddString("VENDOR_NAME", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.VENDOR_NAME].Text);
                                label_list.AddString("SUPPLIER_LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SUPPLIER_LOT_ID].Text);
                        }
                        break;

                    //CTM 공정라벨(CELL 라벨)
                    case "prd996t":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("CELL_NO", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.CELL_NO].Text);
                                label_list.AddString("ITEM_NAME", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.ITEM_NAME].Text);
                                label_list.AddString("WO_NO", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.WO_NO].Text);
                                label_list.AddString("PC0201", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.PC0201].Text);
                                label_list.AddString("PC0202", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.PC0202].Text);
                                label_list.AddString("PC0203", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.PC0203].Text);
                                label_list.AddString("PC0204", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.PC0204].Text);
                        }
                        break;

                    //CTM 공정라벨(가공라벨 LOT)
                    case "prd106vp":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("MAIN_LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.MAIN_LOT_ID].Text);
                                label_list.AddString("GRADE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.GRADE].Text);
                                label_list.AddString("WO_NO", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.WO_NO].Text);
                        }
                        break;

                    //CTM 공정라벨(가공라벨 ITEM)
                    case "prd106vpitem":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("MAIN_LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.MAIN_LOT_ID].Text);
                                label_list.AddString("ITEM_NAME", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.ITEM_NAME].Text);
                        }
                        break;

                    //GRIT 공정라벨
                    case "prd205p":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("MAIN_LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.MAIN_LOT_ID].Text);
                                label_list.AddString("ITEM_CODE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.ITEM_CODE].Text);
                                label_list.AddString("ITEM_NAME", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.ITEM_NAME].Text);
                                label_list.AddDouble("LOT_QTY", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_QTY].Text);
                                label_list.AddString("ITEM_UOM", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.ITEM_UOM].Text);
                                label_list.AddString("WO_NO", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.WO_NO].Text);
                                label_list.AddString("REMARKS", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.REMARKS].Text);
                        }
                        break;

                    //PDC 공정라벨
                    case "prd205ppdc":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("MAIN_LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.MAIN_LOT_ID].Text);
                                label_list.AddString("GRADE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.GRADE].Text);
                                label_list.AddDouble("LOT_QTY", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_QTY].Text);
                                label_list.AddString("WO_NO", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.WO_NO].Text);
                                label_list.AddString("GROUP_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.GROUP_ID].Text);
                        }
                        break;

                    //CTM 출하라벨(66x90)
                    case "mtl900hm3p":
                    case "mtl900hm3p_4p":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_QTY].Text);
                                label_list.AddString("ITEM_NAME", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.ITEM_NAME].Text);
                                label_list.AddString("ITEM_NAME2", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.ITEM_NAME2].Text);
                                label_list.AddString("GRADE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.GRADE].Text);
                                label_list.AddString("TYPE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.TYPE].Text);
                        }
                        break;


                    //CTM 출하라벨(66x90)2
                    case "mtl900hm3_1p":
                    case "mtl900hm3_3p":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_QTY].Text);
                                label_list.AddString("ITEM_NAME", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.ITEM_NAME].Text);
                                label_list.AddString("ITEM_NAME2", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.ITEM_NAME2].Text);
                        }
                        break;

                    //CTM 출하라벨(30x85_INSERT제품)
                    case "mtl900hm6p":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_QTY].Text);
                                label_list.AddString("GRADE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.GRADE].Text);
                                label_list.AddString("TYPE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.TYPE].Text);
                                label_list.AddString("ITEM_UOM", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.ITEM_UOM].Text);
                        }
                        break;

                    //HM 출하라벨(45x55)
                    case "mdprd860phmbp":
                    case "mdprd860phmbp_2":

                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_QTY].Text);
                                label_list.AddString("GRADE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.GRADE].Text);
                                label_list.AddString("SPEC", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SPEC].Text);

                        }
                        break;

                    //HM 출하라벨(90x22)
                    case "mdprd860phmap":
                    case "mdprd860phmap_2":
                    case "mdprd860phmap_4":
                    case "mdprd860phmap_5":
                    case "mdprd860phmap_6":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_QTY].Text);
                                label_list.AddString("GRADE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.GRADE].Text);
                                label_list.AddString("SPEC", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SPEC].Text);
                                label_list.AddString("REMARKS", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.REMARKS].Text);
 
                        }
                        break;

                    //HM 출하라벨(90x95)
                    case "mtl215p_8":
                    case "mtl215p_8_2":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_QTY].Text);
                                label_list.AddString("ITEM_NAME1", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.ITEM_NAME1].Text);
                        }
                        break;

                    //PDC 출하라벨(92x88)
                    case "mtl900hm5p":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_QTY].Text);
     
                        }
                        break;

                    //PDC 출하라벨(49x55)
                    case "mtl900hm9p":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_QTY].Text);
                                label_list.AddString("ITEM", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.ITEM].Text);
                                label_list.AddString("PO", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.PO_NUMBER].Text);
                                label_list.AddString("MN_NO", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.MN_NO].Text);
                        }
                        break;

                    //GRIT 출하라벨(120x90)
                    case "prd840grtp3":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_QTY].Text);
                                label_list.AddString("GRADE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.GRADE].Text);
                                label_list.AddString("TYPE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.TYPE].Text);
                                label_list.AddString("DRAWING_FLAG", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.DRAWING_FLAG].Text);
                        }
                        break;

                    //GRIT 출하라벨(62x43)
                    case "prd840grtp5":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_QTY].Text);
                                label_list.AddString("GRADE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.GRADE].Text);
                                label_list.AddString("TYPE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.TYPE].Text);
                                label_list.AddString("DRAWING_FLAG", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.DRAWING_FLAG].Text);
                                label_list.AddString("COAT", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.COAT].Text);

                        }
                        break;

                    //GRIT 출하라벨(62x43_QR)
                    case "prd840grtp2_DM":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_QTY].Text);
                                label_list.AddString("GRADE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.GRADE].Text);
                                label_list.AddString("TYPE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.TYPE].Text);
                                label_list.AddString("DRAWING_FLAG", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.DRAWING_FLAG].Text);
                                label_list.AddString("COAT", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.COAT].Text);
 
                        }
                        break;

                    //GRIT 출하라벨(76x26)
                    case "840Sample":
                        for (int i = 0; i < spdSplitList.ActiveSheet.RowCount; i++)
                        {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.SEQ].Value);
                                label_list.AddString("LOT_ID", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.LOT_QTY].Text);
                                label_list.AddString("GRADE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.GRADE].Text);
                                label_list.AddString("TYPE", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.TYPE].Text);
                                label_list.AddString("DRAWING_FLAG", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.DRAWING_FLAG].Text);
                                label_list.AddString("COAT", spdSplitList.ActiveSheet.Cells[i, (int)CBASLBLDAT.COAT].Text);
                        }
                        break;

                }

                if (MPCR.CallService("CUS_BAS", "CUS_BAS_Print_Label_List", in_node, ref out_node) == false)
                    return false;
                else
                {
                    MPCR.ShowSuccessMsg(out_node);
                }

                //라벨 출력
                PrintLabel(sFileName, out_node);

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
        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ClearList("VIEW");

                file_name = cdvLabelName.Text;
                area_id = cdvDept.Text;
                s_area_desc = cdvDept.DisplayText;
                s_label_name = cdvLabelName.DisplayText;
                label_size = txtLabelSize.Text;
                ViewLotList();
                ViewLabel(area_id, file_name);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SaveLabelList(area_id, file_name))
                {
                    ClearList("SAVE");
                    ViewLabel(area_id, file_name);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvLabelName_ButtonPress(object sender, EventArgs e)
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

                cdvLabelName.Init();
                MPCF.InitListView(cdvLabelName.GetListView);
                cdvLabelName.Columns.Add("Desc", 50, HorizontalAlignment.Left);
                cdvLabelName.Columns.Add("Size", 100, HorizontalAlignment.Left);
                cdvLabelName.Columns.Add("Code", 50, HorizontalAlignment.Left);

                cdvLabelName.SelectedSubItemIndex = 2;
                cdvLabelName.DisplaySubItemIndex = 0;

                if (ViewLabelNameGCMList(cdvLabelName.GetListView, cdvDept.Text) == false)
                {
                    return;
                }

                cdvLabelName.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvLabelName.Text = "";
                txtLabelSize.Text = "";
                MPCF.ClearList(spdSplitList);
                MPCF.ClearList(spdLotList);

                ClearList("VIEW");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvLabelName_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {

                txtLabelSize.Text = "";
                ViewLabelSize(txtLabelSize, cdvLabelName.Text);


                MPCF.ClearList(spdSplitList);


                file_name = cdvLabelName.Text;
                area_id = cdvDept.Text;
                s_area_desc = cdvDept.DisplayText;
                s_label_name = cdvLabelName.DisplayText;
                label_size = txtLabelSize.Text;

                ViewLabel(area_id, file_name);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, '7', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatid_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMatid.Text = popup.sMat_id;
                    popup = null;
                }
                else
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtMatDesc_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        private void btnAdd_Click(object sender, EventArgs e)
        {

            int i_total_Qty = 0;
            int i_lot_Qty = 0;
            int i_create_qty = 0;
            int beforeRowCount = 0;
            int currentRowCount = 0;
            int i_activeRow = 0;
            int i_lot_count = 0;

            try
            {
                MPCF.ClearList(spdSplitList);

                i_activeRow = spdLotList.ActiveSheet.ActiveRowIndex;

                beforeRowCount = spdSplitList_Sheet1.RowCount;

                for (int i = 0; i < spdSplitList_Sheet1.RowCount; i++)
                {
                    i_create_qty += MPCF.ToInt(spdSplitList_Sheet1.Cells[i, (int)CBASLBLDAT.LOT_QTY].Text);

                }

                i_total_Qty = MPCF.ToInt(spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.LOT_QTY].Text);
                i_lot_Qty = MPCF.ToInt(this.txtPrintQty.Text);
                i_lot_count = i_total_Qty / MPCF.ToInt(this.txtPrintQty.Text);


                if (i_total_Qty < i_lot_Qty)
                {
                    //CMN126 ERROR -입력한 값이 한계값을 넘었습니다.다른 수를 입력해 주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(126) + " [" + lblPrintQty.Text + "]");
                    txtPrintQty.Focus();
                    return;
                }


                if (i_lot_count * MPCF.ToInt(this.txtPrintQty.Text) < i_total_Qty)
                {
                    i_lot_count++;
                }



                for (int i = 0; i < i_lot_count; i++)
                {
                    spdSplitList_Sheet1.RowCount++;

                    currentRowCount = spdSplitList_Sheet1.RowCount - 1;


                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.FACTORY].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.FACTORY].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.AREA_ID].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.AREA_ID].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.FILE_NAME].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.FILE_NAME].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.SEQ].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.SEQ].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.LABEL_SIZE].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.LABEL_SIZE].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.PRINT_DATE].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.PRINT_DATE].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.LOT_ID].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.LOT_ID].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.ITEM_CODE].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.ITEM_CODE].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.ITEM_NAME].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.ITEM_NAME].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.INPUT_DATE].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.INPUT_DATE].Text;
                    if (spdSplitList_Sheet1.RowCount == i_lot_count + beforeRowCount)
                    {
                        spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.LOT_QTY].Value = i_total_Qty.ToString();
                    }
                    else
                    {
                        spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.LOT_QTY].Value = i_lot_Qty.ToString();
                        i_total_Qty -= i_lot_Qty;
                    }
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.UOM].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.UOM].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.VENDOR_NAME].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.VENDOR_NAME].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.SUPPLIER_LOT_ID].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.SUPPLIER_LOT_ID].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.CELL_NO].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.CELL_NO].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.WO_NO].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.WO_NO].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.PC0201].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.PC0201].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.PC0202].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.PC0202].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.PC0203].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.PC0203].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.PC0204].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.PC0204].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.MAIN_LOT_ID].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.MAIN_LOT_ID].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.GRADE].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.GRADE].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.ITEM_UOM].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.ITEM_UOM].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.REMARKS].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.REMARKS].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.GROUP_ID].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.GROUP_ID].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.ITEM_NAME2].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.ITEM_NAME2].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.TYPE].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.TYPE].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.SPEC].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.SPEC].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.BOX_COUNT].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.BOX_COUNT].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.ITEM_NAME1].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.ITEM_NAME1].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.ITEM].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.ITEM].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.PO_NUMBER].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.PO_NUMBER].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.MN_NO].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.MN_NO].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.DRAWING_FLAG].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.DRAWING_FLAG].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.COAT].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.COAT].Text;
                    spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.GROSS].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.GROSS].Text;



                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }


        }

        private void btnRowAdd_Click_1(object sender, EventArgs e)
        {
            int iRow = 0;
            int i_activeRow = 0;
            int currentRowCount = 0;
            try
            {
                if (CheckCondition(CSGC.CHECK.ADD) == false)
                    return;

                spdSplitList_Sheet1.RowCount++;
                iRow = spdSplitList_Sheet1.RowCount;
                i_activeRow = spdLotList.ActiveSheet.ActiveRowIndex;
                currentRowCount = spdSplitList_Sheet1.RowCount - 1;

                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.FACTORY].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.FACTORY].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.AREA_ID].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.AREA_ID].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.FILE_NAME].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.FILE_NAME].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.SEQ].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.SEQ].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.LABEL_SIZE].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.LABEL_SIZE].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.PRINT_DATE].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.PRINT_DATE].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.LOT_ID].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.LOT_ID].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.ITEM_CODE].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.ITEM_CODE].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.ITEM_NAME].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.ITEM_NAME].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.INPUT_DATE].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.INPUT_DATE].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.LOT_QTY].Value = 0;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.UOM].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.UOM].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.VENDOR_NAME].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.VENDOR_NAME].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.SUPPLIER_LOT_ID].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.SUPPLIER_LOT_ID].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.CELL_NO].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.CELL_NO].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.WO_NO].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.WO_NO].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.PC0201].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.PC0201].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.PC0202].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.PC0202].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.PC0203].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.PC0203].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.PC0204].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.PC0204].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.MAIN_LOT_ID].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.MAIN_LOT_ID].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.GRADE].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.GRADE].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.ITEM_UOM].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.ITEM_UOM].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.REMARKS].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.REMARKS].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.GROUP_ID].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.GROUP_ID].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.ITEM_NAME2].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.ITEM_NAME2].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.TYPE].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.TYPE].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.SPEC].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.SPEC].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.BOX_COUNT].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.BOX_COUNT].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.ITEM_NAME1].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.ITEM_NAME1].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.ITEM].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.ITEM].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.PO_NUMBER].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.PO_NUMBER].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.MN_NO].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.MN_NO].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.DRAWING_FLAG].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.DRAWING_FLAG].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.COAT].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.COAT].Text;
                spdSplitList_Sheet1.Cells[currentRowCount, (int)CBASLBLDAT.GROSS].Value = spdLotList.ActiveSheet.Cells[i_activeRow, (int)LOT_INFO.GROSS].Text;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

    }

        private void btnRowDel_Click(object sender, EventArgs e)
        {
            try
            {
                spdSplitList_Sheet1.RemoveRows(spdSplitList_Sheet1.ActiveRowIndex, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            try
            {
                MPCF.ClearList(spdSplitList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

        }

        #endregion
    }
}
