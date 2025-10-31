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
    public partial class frmTranPrintLabel : CUS_COM.frmTranForm05
    {
        public frmTranPrintLabel()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        // 원자재입고라벨(mtl100p)
        private enum MTL100P : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            LOT_ID,             // 5 : LOT ID
            ITEM_CODE,          // 6 : 품목코드
            ITEM_NAME,          // 7 : 품명
            INPUT_DATE,         // 8 : 입고일자
            LOT_QTY,            // 9 : 수량
            UOM,                // 10: 단위
            VENDOR_NAME,        // 11: 업체명
            SUPPLIER_LOT_ID,    // 12: 업체 LOT,
            SEQ                 // 13: 순번
        }

        //CTM 공정라벨(CELL 라벨)(prd996t)
        private enum PRD996T : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            CELL_NO,            // 5 : CELL 번호
            ITEM_NAME,          // 6 : 품목명
            WO_NO,              // 7 : W/O번호
            PC0201,             // 8 : 셀높이
            PC0202,             // 9 : 셀중량
            PC0203,             // 10 : 프레스호기번호
            PC0204,             // 11: CAR번호
            SEQ                 // 12: 순번
        }

        //CTM 공정라벨(가공라벨 LOT)(prd106vp)
        private enum PRD106VP : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            MAIN_LOT_ID,        // 5 : LOT ID
            GRADE,              // 6 : 품목명
            WO_NO,              // 7 : W/O번호
            SEQ                 // 8 : 순번
        }

        //CTM 공정라벨(가공라벨 ITEM)(prd106vpitem)
        private enum PRD106VPITEM : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            MAIN_LOT_ID,        // 5 : LOT ID
            ITEM_NAME,          // 6 : 품목명
            SEQ                 // 7 : 순번
        }

        //GRIT 공정라벨(prd205p)
        private enum PRD205P : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            MAIN_LOT_ID,        // 5 : LOT ID        
            ITEM_CODE,          // 6 : 품목코드           
            ITEM_NAME,          // 7 : 품목명
            LOT_QTY,            // 8 : 수량
            ITEM_UOM,           // 9 : 단위
            WO_NO,              // 10: W/O번호
            REMARKS,            // 11: 특기사항
            SEQ                 // 12: 순번
        }

        //PDC 공정라벨(prd205ppdc)
        private enum PRD205PPDC : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            MAIN_LOT_ID,        // 5 : LOT ID
            ITEM_NAME,              // 6 : 품명
            LOT_QTY,            // 7 : 수량          
            WO_NO,              // 8 : W/O번호
            GROUP_ID,           // 9 : GROUP ID
            SEQ                 // 10: 순번
        }

        //CTM 출하라벨(66x90)(mtl900hm3p)
        private enum MTL900HM3P : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            LOT_ID,             // 5 : LOT ID
            LOT_QTY,            // 6 : 수량
            ITEM_NAME,          // 7 : 품명1(GRADE)
            ITEM_NAME2,         // 8 : 품명2(TYPE)
            GRADE,              // 9 :
            TYPE,               // 10:
            SEQ                 // 11: 순번
        }

        //CTM 출하라벨(66x90)2(mtl900hm3_1p)
        private enum MTL900HM3_1P : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            LOT_ID,             // 5 : LOT ID
            LOT_QTY,            // 6 : 수량
            ITEM_NAME,          // 7 : 품명1(GRADE)
            ITEM_NAME2,         // 8 : 품명2(TYPE)
            SEQ                 // 9 : 순번
        }


        //CTM 출하라벨(66x90)3(mtl900hm3_2p)
        private enum MTL900HM3_2P : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            LOT_ID,             // 5 : LOT ID
            LOT_QTY,            // 6 : 수량
            ITEM_NAME,          // 7 : 품명1(GRADE)
            ITEM_NAME2,         // 8 : 품명2(TYPE)
            SEQ                 // 9 : 순번
        }


        //CTM 출하라벨(66x90)2(mtl900hm3_3p)_QR들어간거
        private enum MTL900HM3_3P : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            LOT_ID,             // 5 : LOT ID
            LOT_QTY,            // 6 : 수량
            ITEM_NAME,          // 7 : 품명1(GRADE)
            ITEM_NAME2,         // 8 : 품명2(TYPE)
            SEQ                 // 9 : 순번
        }

        //CTM 출하라벨(30x85_INSERT제품)(mtl900hm6p)
        private enum MTL900HM6P : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            LOT_ID,             // 5 : LOT ID
            LOT_QTY,            // 6 : 수량
            GRADE,              // 7 : 품명1(GRADE)
            TYPE,               // 8 : 품명2(TYPE)
            ITEM_UOM,           // 9 : 단위
            SEQ                 // 10: 순번
        }

        //HM 출하라벨(45x55)(mdprd860phmbp)
        private enum MDPRD860PHMBP : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            LOT_ID,             // 5 : LOT ID
            LOT_QTY,            // 6 : 수량
            GRADE,              // 7 : 품명1(GRADE)
            SPEC,               // 8 : 품명2(SPEC)
            REMARKS,            // 9 : 비고
            SEQ                 // 10: 순번
        }

        //HM 출하라벨(90x22)(mdprd860phmap)
        private enum MDPRD860PHMAP : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            LOT_ID,             // 5 : LOT ID
            LOT_QTY,            // 6 : 수량
            GRADE,              // 7 : 품명1(GRADE)
            SPEC,               // 8 : 품명2(SPEC)
            REMARKS,            // 9 : 비고
            SEQ                 // 10: 순번
        }

        //HM 출하라벨(90x95)(mtl215p_8)
        private enum MTL215P_8 : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            LOT_ID,             // 5 : LOT ID
            LOT_QTY,            // 6 : 수량
            ITEM_NAME1,         // 7 : 품명1(GRADE)
            ITEM_NAME2,         // 8 : 품명2(SPEC)
            SEQ                 // 9 : 순번
        }

        //PDC 출하라벨(92x88)(mtl900hm5p)
        private enum MTL900HM5P : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            LOT_ID,             // 5 : LOT ID
            LOT_QTY,            // 6 : 수량
            GRADE,              // 7 : 품명1(GRADE)
            TYPE,               // 8 : 품명2(TYPE)
            SEQ                 // 9 : 순번
        }

        //PDC 출하라벨(49x55) (mtl900hm9p)
        private enum MTL900HM9P : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            LOT_ID,             // 5 : LOT ID
            LOT_QTY,            // 6 : 수량
            ITEM,               // 7 : 품명
            PO,                 // 8 : 포장 지시 번호
            MN_NO,              // 9 : 고객사
            SEQ                 // 10: 순번
        }

        //GRIT 출하라벨(120x90)(prd840grtp3)
        private enum PRD840GRTP3 : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            LOT_ID,             // 5 : LOT ID
            LOT_QTY,            // 6 : 수량
            GRADE,              // 7 : 품명1(GRADE)
            TYPE,               // 8 : 품명2(TYPE)
            DRAWING_FLAG,       // 9 : 도면 유무
            SEQ                 // 10: 순번
        }

        //GRIT 출하라벨(62x43)(prd840grtp5)
        private enum PRD840GRTP5 : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            LOT_ID,             // 5 : LOT ID
            LOT_QTY,            // 6 : 수량
            GRADE,              // 7 : 품명1(GRADE)
            TYPE,               // 8 : 품명2(TYPE)
            DRAWING_FLAG,       // 9 : 도면 유무
            COAT,               // 10: 코팅 퍼센트 
            SEQ                 // 11: 순번     
        }

        //GRIT 출하라벨(62x43_QR)(prd840grtp2_DM)
        private enum PRD840GRTP2_DM : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            LOT_ID,             // 5 : LOT ID
            LOT_QTY,            // 6 : 수량
            GRADE,              // 7 : 품명1(GRADE)
            TYPE,               // 8 : 품명2(TYPE)
            DRAWING_FLAG,       // 9 : 도면 유무
            COAT,               // 10: 코팅 퍼센트  
            SEQ                 // 11: 순번
        }

        //GRIT 출하라벨(76x26)(840Sample)
        private enum GRIT_SHIP_LABEL : int
        {
            CHECK,              // 1 : 선택
            AREA_DESC,          // 2 : 사업부
            PRINT_DATE,         // 3 : 발행날짜
            LABEL_NAME,         // 4 : 라벨명
            LOT_ID,             // 5 : LOT ID
            LOT_QTY,            // 6 : 수량
            GRADE,              // 7 : 품명1(GRADE)
            TYPE,               // 8 : 품명2(TYPE)
            DRAWING_FLAG,       // 9 : 도면 유무
            COAT,               // 10: 코팅 퍼센트  
            SEQ                 // 11: 순번


        }

        #endregion

        #region " Variable Definition "

        SheetView sv = null;
        FpSpread sp = null;

        string file_name = "";
        string area_id = "";
        string label_size = "";
        int row_count = 0;
        string s_area_desc = "";
        string s_label_name = "";

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        if (MPCF.Trim(cdvLabelName.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLabelName.Text + "]");
                            cdvLabelName.Focus();
                            return false;
                        }

                        break;

                    case CSGC.CHECK.SAVE:
                        if (sv == null)
                            return false;

                        if (file_name == "" || sv.RowCount == 0)
                        {
                            //CMN107 ERROR - 데이타가 입력되지 않았습니다. 필요한 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(107));
                            return false;
                        }

                        break;

                    case CSGC.CHECK.DELETE:
                        if (sv == null)
                            return false;

                        if (sv.RowCount == 0)
                        {
                            //CMN482 INFO - 삭제할 데이터가 없습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(482));
                            return false;
                        }

                        break;

                    case CSGC.CHECK.ADD:
                        if (sv == null)
                        {
                            return false;
                        }

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

        //해당 spread앞으로 가져오기
        private void BringToFrontSpread(string sFileName)
        {
            try
            {
                switch (sFileName)
                {
                    //원자재입고라벨
                    case "mtl100p":
                        sp = spdInvLabelList;
                        break;

                    //CTM 공정라벨(CELL 라벨)
                    case "prd996t":
                        sp = spdCellLabelList;
                        break;

                    //CTM 공정라벨(가공라벨 LOT)
                    case "prd106vp":
                        sp = spdLotLabelList;
                        break;

                    //CTM 공정라벨(가공라벨 ITEM)
                    case "prd106vpitem":
                        sp = spdItemLabelList;
                        break;

                    //GRIT 공정라벨
                    case "prd205p":
                        sp = spdGritOperLabelList;
                        break;

                    //PDC 공정라벨
                    case "prd205ppdc":
                        sp = spdPdcOperLabelList;
                        break;

                    //CTM 출하라벨(66x90)
                    case "mtl900hm3p":
                        sp = spdCtmShipLabelList;
                        break;

                    //CTM 출하라벨(66x90)2
                    case "mtl900hm3_1p":
                    case "mtl900hm3_2p":
                    case "mtl900hm3_3p":
                        sp = spdCtmShip2LabelList;
                        break;

                    //CTM 출하라벨(30x85_INSERT제품)
                    case "mtl900hm6p":
                        sp = spdCtmShipInsertLabelList;
                        break;

                    //HM 출하라벨(45x55)
                    case "mdprd860phmbp":
                    case "mdprd860phmbp_2":
                        sp = spdHmShip45LabelList;
                        break;

                    //HM 출하라벨(90x22)
                    case "mdprd860phmap":
                    case "mdprd860phmap_2":
                    case "mdprd860phmap_4":
                    case "mdprd860phmap_5":
                    case "mdprd860phmap_6":
                        sp = spdHmShip90LabelList;
                        break;

                    //HM 출하라벨(90x95)
                    case "mtl215p_8":
                    case "mtl215p_8_2":
                        sp = spdHmShip95LabelList;
                        break;

                    //PDC 출하라벨(92x88)
                    case "mtl900hm5p":
                        sp = spdPdcShip92LabelList;
                        break;

                    //PDC 출하라벨(49x55)
                    case "mtl900hm9p":
                        sp = spdPdcShip49LabelList;
                        break;

                    //GRIT 출하라벨(120x90)
                    case "prd840grtp3":
                        sp = spdGritShip120LabelList;
                        break;

                    //GRIT 출하라벨(62x43)
                    case "prd840grtp5":
                    case "840Sample":
                        sp = spdGritShip62LabelList;
                        break;

                    //GRIT 출하라벨(62x43_QR)
                    case "prd840grtp2_DM":
                        sp = spdGritShipQrLabelList;
                        break;

                    default:
                        sp = spdInvLabelList;
                        break;
                }

                sv = sp.ActiveSheet;
                sp.BringToFront();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //라벨 조회
        private void ViewLabel(string sAreaId, string sFileName)
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CBAS2001-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sAreaId;

                dvcArgu[2].sCondition_ID = "FILE_NAME";
                dvcArgu[2].sCondition_Value = sFileName;

                dvcArgu[3].sCondition_ID = "FROM_DATE";
                dvcArgu[3].sCondition_Value = dtpFromDate.Text.Replace("-", "");

                dvcArgu[4].sCondition_ID = "TO_DATE";
                dvcArgu[4].sCondition_Value = dtpToDate.Text.Replace("-", "");

                BringToFrontSpread(sFileName);

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                row_count = dt.Rows.Count;

                switch (sFileName)
                {
                    //원자재입고라벨
                    case "mtl100p":
                        for (i = 0; i < row_count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)MTL100P.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)MTL100P.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)MTL100P.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)MTL100P.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            sv.Cells[i, (int)MTL100P.ITEM_CODE].Value = dt.Rows[i]["ITEM_CODE"];
                            sv.Cells[i, (int)MTL100P.ITEM_NAME].Value = dt.Rows[i]["ITEM_NAME"];
                            sv.Cells[i, (int)MTL100P.INPUT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["INPUT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)MTL100P.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)MTL100P.UOM].Value = dt.Rows[i]["UOM"];
                            sv.Cells[i, (int)MTL100P.VENDOR_NAME].Value = dt.Rows[i]["VENDOR_NAME"];
                            sv.Cells[i, (int)MTL100P.SUPPLIER_LOT_ID].Value = dt.Rows[i]["SUPPLIER_LOT_ID"];
                            sv.Cells[i, (int)MTL100P.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //CTM 공정라벨(CELL 라벨)
                    case "prd996t":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)PRD996T.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)PRD996T.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)PRD996T.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)PRD996T.CELL_NO].Value = dt.Rows[i]["CELL_NO"];
                            sv.Cells[i, (int)PRD996T.ITEM_NAME].Value = dt.Rows[i]["ITEM_NAME"];
                            sv.Cells[i, (int)PRD996T.WO_NO].Value = dt.Rows[i]["WO_NO"];
                            sv.Cells[i, (int)PRD996T.PC0201].Value = dt.Rows[i]["PC0201"];
                            sv.Cells[i, (int)PRD996T.PC0202].Value = dt.Rows[i]["PC0202"];
                            sv.Cells[i, (int)PRD996T.PC0203].Value = dt.Rows[i]["PC0203"];
                            sv.Cells[i, (int)PRD996T.PC0204].Value = dt.Rows[i]["PC0204"];
                            sv.Cells[i, (int)PRD996T.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //CTM 공정라벨(가공라벨 LOT)
                    case "prd106vp":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)PRD106VP.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)PRD106VP.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)PRD106VP.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)PRD106VP.MAIN_LOT_ID].Value = dt.Rows[i]["MAIN_LOT_ID"];
                            sv.Cells[i, (int)PRD106VP.GRADE].Value = dt.Rows[i]["GRADE"];
                            sv.Cells[i, (int)PRD106VP.WO_NO].Value = dt.Rows[i]["WO_NO"];
                            sv.Cells[i, (int)PRD106VP.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //CTM 공정라벨(가공라벨 ITEM)
                    case "prd106vpitem":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)PRD106VPITEM.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)PRD106VPITEM.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)PRD106VPITEM.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)PRD106VPITEM.MAIN_LOT_ID].Value = dt.Rows[i]["MAIN_LOT_ID"];
                            sv.Cells[i, (int)PRD106VPITEM.ITEM_NAME].Value = dt.Rows[i]["ITEM_NAME"];
                            sv.Cells[i, (int)PRD106VPITEM.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //GRIT 공정라벨
                    case "prd205p":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)PRD205P.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)PRD205P.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)PRD205P.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)PRD205P.MAIN_LOT_ID].Value = dt.Rows[i]["MAIN_LOT_ID"];
                            sv.Cells[i, (int)PRD205P.ITEM_CODE].Value = dt.Rows[i]["ITEM_CODE"];
                            sv.Cells[i, (int)PRD205P.ITEM_NAME].Value = dt.Rows[i]["ITEM_NAME"];
                            sv.Cells[i, (int)PRD205P.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)PRD205P.ITEM_UOM].Value = dt.Rows[i]["ITEM_UOM"];
                            sv.Cells[i, (int)PRD205P.WO_NO].Value = dt.Rows[i]["WO_NO"];
                            sv.Cells[i, (int)PRD205P.REMARKS].Value = dt.Rows[i]["REMARKS"];
                            sv.Cells[i, (int)PRD205P.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //PDC 공정라벨
                    case "prd205ppdc":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)PRD205PPDC.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)PRD205PPDC.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)PRD205PPDC.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)PRD205PPDC.MAIN_LOT_ID].Value = dt.Rows[i]["MAIN_LOT_ID"];
                            sv.Cells[i, (int)PRD205PPDC.ITEM_NAME].Value = dt.Rows[i]["ITEM_NAME"];
                            sv.Cells[i, (int)PRD205PPDC.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)PRD205PPDC.WO_NO].Value = dt.Rows[i]["WO_NO"];
                            sv.Cells[i, (int)PRD205PPDC.GROUP_ID].Value = dt.Rows[i]["GROUP_ID"];
                            sv.Cells[i, (int)PRD205PPDC.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //CTM 출하라벨(66x90)
                    case "mtl900hm3p":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)MTL900HM3P.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)MTL900HM3P.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)MTL900HM3P.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)MTL900HM3P.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            sv.Cells[i, (int)MTL900HM3P.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)MTL900HM3P.ITEM_NAME].Value = dt.Rows[i]["ITEM_NAME"];
                            sv.Cells[i, (int)MTL900HM3P.ITEM_NAME2].Value = dt.Rows[i]["ITEM_NAME2"];
                            sv.Cells[i, (int)MTL900HM3P.GRADE].Value = dt.Rows[i]["GRADE"];
                            sv.Cells[i, (int)MTL900HM3P.TYPE].Value = dt.Rows[i]["TYPE"];
                            sv.Cells[i, (int)MTL900HM3P.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;


                    //CTM 출하라벨(66x90)2
                    case "mtl900hm3_1p":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)MTL900HM3_1P.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)MTL900HM3_1P.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)MTL900HM3_1P.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)MTL900HM3_1P.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            sv.Cells[i, (int)MTL900HM3_1P.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)MTL900HM3_1P.ITEM_NAME].Value = dt.Rows[i]["ITEM_NAME"];
                            sv.Cells[i, (int)MTL900HM3_1P.ITEM_NAME2].Value = dt.Rows[i]["ITEM_NAME2"];
                            sv.Cells[i, (int)MTL900HM3_1P.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //CTM 출하라벨(66x90)2
                    case "mtl900hm3_3p":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)MTL900HM3_1P.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)MTL900HM3_1P.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)MTL900HM3_1P.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)MTL900HM3_1P.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            sv.Cells[i, (int)MTL900HM3_1P.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)MTL900HM3_1P.ITEM_NAME].Value = dt.Rows[i]["ITEM_NAME"];
                            sv.Cells[i, (int)MTL900HM3_1P.ITEM_NAME2].Value = dt.Rows[i]["ITEM_NAME2"];
                            sv.Cells[i, (int)MTL900HM3_1P.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;
                    //CTM 출하라벨(66x90)2
                    case "mtl900hm3_2p":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)MTL900HM3_2P.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)MTL900HM3_2P.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)MTL900HM3_2P.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)MTL900HM3_2P.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            sv.Cells[i, (int)MTL900HM3_2P.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)MTL900HM3_2P.ITEM_NAME].Value = dt.Rows[i]["ITEM_NAME"];
                            sv.Cells[i, (int)MTL900HM3_2P.ITEM_NAME2].Value = dt.Rows[i]["ITEM_NAME2"];
                            sv.Cells[i, (int)MTL900HM3_2P.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //CTM 출하라벨(30x85_INSERT제품)
                    case "mtl900hm6p":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)MTL900HM6P.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)MTL900HM6P.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)MTL900HM6P.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)MTL900HM6P.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            sv.Cells[i, (int)MTL900HM6P.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)MTL900HM6P.GRADE].Value = dt.Rows[i]["GRADE"];
                            sv.Cells[i, (int)MTL900HM6P.TYPE].Value = dt.Rows[i]["TYPE"];
                            sv.Cells[i, (int)MTL900HM6P.ITEM_UOM].Value = dt.Rows[i]["ITEM_UOM"];
                            sv.Cells[i, (int)MTL900HM6P.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //HM 출하라벨(45x55)
                    case "mdprd860phmbp":
                    case "mdprd860phmbp_2":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)MDPRD860PHMBP.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)MDPRD860PHMBP.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)MDPRD860PHMBP.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)MDPRD860PHMBP.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            sv.Cells[i, (int)MDPRD860PHMBP.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)MDPRD860PHMBP.GRADE].Value = dt.Rows[i]["GRADE"];
                            sv.Cells[i, (int)MDPRD860PHMBP.SPEC].Value = dt.Rows[i]["SPEC"];
                            sv.Cells[i, (int)MDPRD860PHMBP.REMARKS].Value = dt.Rows[i]["REMARKS"];
                            sv.Cells[i, (int)MDPRD860PHMBP.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //HM 출하라벨(90x22)
                    case "mdprd860phmap":
                    case "mdprd860phmap_2":
                    case "mdprd860phmap_4":
                    case "mdprd860phmap_5":
                    case "mdprd860phmap_6":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)MDPRD860PHMAP.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)MDPRD860PHMAP.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)MDPRD860PHMAP.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)MDPRD860PHMAP.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            sv.Cells[i, (int)MDPRD860PHMAP.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)MDPRD860PHMAP.GRADE].Value = dt.Rows[i]["GRADE"];
                            sv.Cells[i, (int)MDPRD860PHMAP.SPEC].Value = dt.Rows[i]["SPEC"];
                            sv.Cells[i, (int)MDPRD860PHMAP.REMARKS].Value = dt.Rows[i]["REMARKS"];
                            sv.Cells[i, (int)MDPRD860PHMAP.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //HM 출하라벨(90x95)
                    case "mtl215p_8":
                    case "mtl215p_8_2":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)MTL215P_8.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)MTL215P_8.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)MTL215P_8.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)MTL215P_8.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            sv.Cells[i, (int)MTL215P_8.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)MTL215P_8.ITEM_NAME1].Value = dt.Rows[i]["ITEM_NAME1"];
                            sv.Cells[i, (int)MTL215P_8.ITEM_NAME2].Value = dt.Rows[i]["ITEM_NAME2"];
                            sv.Cells[i, (int)MTL215P_8.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //PDC 출하라벨(92x88)
                    case "mtl900hm5p":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)MTL900HM5P.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)MTL900HM5P.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)MTL900HM5P.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)MTL900HM5P.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            sv.Cells[i, (int)MTL900HM5P.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)MTL900HM5P.GRADE].Value = dt.Rows[i]["GRADE"];
                            sv.Cells[i, (int)MTL900HM5P.TYPE].Value = dt.Rows[i]["TYPE"];
                            sv.Cells[i, (int)MTL900HM5P.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //PDC 출하라벨(49x55)
                    case "mtl900hm9p":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)MTL900HM9P.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)MTL900HM9P.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)MTL900HM9P.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)MTL900HM9P.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            sv.Cells[i, (int)MTL900HM9P.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)MTL900HM9P.ITEM].Value = dt.Rows[i]["ITEM"];
                            sv.Cells[i, (int)MTL900HM9P.PO].Value = dt.Rows[i]["PO"];
                            sv.Cells[i, (int)MTL900HM9P.MN_NO].Value = dt.Rows[i]["MN_NO"];
                            sv.Cells[i, (int)MTL900HM9P.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //GRIT 출하라벨(120x90)
                    case "prd840grtp3":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)PRD840GRTP3.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)PRD840GRTP3.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)PRD840GRTP3.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)PRD840GRTP3.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            sv.Cells[i, (int)PRD840GRTP3.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)PRD840GRTP3.GRADE].Value = dt.Rows[i]["GRADE"];
                            sv.Cells[i, (int)PRD840GRTP3.TYPE].Value = dt.Rows[i]["TYPE"];
                            sv.Cells[i, (int)PRD840GRTP3.DRAWING_FLAG].Value = dt.Rows[i]["DRAWING_FLAG"];
                            sv.Cells[i, (int)PRD840GRTP3.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //GRIT 출하라벨(62x43)
                    case "prd840grtp5":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)PRD840GRTP5.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)PRD840GRTP5.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)PRD840GRTP5.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)PRD840GRTP5.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            sv.Cells[i, (int)PRD840GRTP5.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)PRD840GRTP5.GRADE].Value = dt.Rows[i]["GRADE"];
                            sv.Cells[i, (int)PRD840GRTP5.TYPE].Value = dt.Rows[i]["TYPE"];
                            sv.Cells[i, (int)PRD840GRTP5.DRAWING_FLAG].Value = dt.Rows[i]["DRAWING_FLAG"];
                            sv.Cells[i, (int)PRD840GRTP5.COAT].Value = dt.Rows[i]["COAT"];
                            sv.Cells[i, (int)PRD840GRTP5.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //GRIT 출하라벨(62x43_QR)
                    case "prd840grtp2_DM":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)PRD840GRTP2_DM.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)PRD840GRTP2_DM.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)PRD840GRTP2_DM.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)PRD840GRTP2_DM.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            sv.Cells[i, (int)PRD840GRTP2_DM.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)PRD840GRTP2_DM.GRADE].Value = dt.Rows[i]["GRADE"];
                            sv.Cells[i, (int)PRD840GRTP2_DM.TYPE].Value = dt.Rows[i]["TYPE"];
                            sv.Cells[i, (int)PRD840GRTP2_DM.DRAWING_FLAG].Value = dt.Rows[i]["DRAWING_FLAG"];
                            sv.Cells[i, (int)PRD840GRTP2_DM.COAT].Value = dt.Rows[i]["COAT"];
                            sv.Cells[i, (int)PRD840GRTP2_DM.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
                        break;

                    //GRIT 출하라벨(76x26)
                    case "840Sample":
                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            sv.RowCount++;

                            sv.Cells[i, (int)GRIT_SHIP_LABEL.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                            sv.Cells[i, (int)GRIT_SHIP_LABEL.PRINT_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["PRINT_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                            sv.Cells[i, (int)GRIT_SHIP_LABEL.LABEL_NAME].Value = dt.Rows[i]["LABEL_NAME"];
                            sv.Cells[i, (int)GRIT_SHIP_LABEL.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            sv.Cells[i, (int)GRIT_SHIP_LABEL.LOT_QTY].Value = dt.Rows[i]["LOT_QTY"];
                            sv.Cells[i, (int)GRIT_SHIP_LABEL.GRADE].Value = dt.Rows[i]["GRADE"];
                            sv.Cells[i, (int)GRIT_SHIP_LABEL.TYPE].Value = dt.Rows[i]["TYPE"];
                            sv.Cells[i, (int)GRIT_SHIP_LABEL.DRAWING_FLAG].Value = dt.Rows[i]["DRAWING_FLAG"];
                            sv.Cells[i, (int)GRIT_SHIP_LABEL.COAT].Value = dt.Rows[i]["COAT"];
                            sv.Cells[i, (int)GRIT_SHIP_LABEL.SEQ].Value = dt.Rows[i]["SEQ"];
                        }
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
                in_node.AddString("FILE_NAME", sFileName);
                in_node.AddString("LABEL_SIZE", label_size);

                switch (sFileName)
                {
                    //원자재입고라벨
                    case "mtl100p":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)MTL100P.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)MTL100P.SEQ].Value);
                                label_list.AddString("LOT_ID", sv.Cells[i, (int)MTL100P.LOT_ID].Text);
                                label_list.AddString("ITEM_CODE", sv.Cells[i, (int)MTL100P.ITEM_CODE].Text);
                                label_list.AddString("ITEM_NAME", sv.Cells[i, (int)MTL100P.ITEM_NAME].Text);
                                label_list.AddString("INPUT_DATE", sv.Cells[i, (int)MTL100P.INPUT_DATE].Text.Replace("-", ""));
                                label_list.AddDouble("LOT_QTY", sv.Cells[i, (int)MTL100P.LOT_QTY].Text);
                                label_list.AddString("UOM", sv.Cells[i, (int)MTL100P.UOM].Text);
                                label_list.AddString("VENDOR_NAME", sv.Cells[i, (int)MTL100P.VENDOR_NAME].Text);
                                label_list.AddString("SUPPLIER_LOT_ID", sv.Cells[i, (int)MTL100P.SUPPLIER_LOT_ID].Text);
                            }
                        }
                        break;

                    //CTM 공정라벨(CELL 라벨)
                    case "prd996t":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)PRD996T.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)PRD996T.SEQ].Value);
                                label_list.AddString("CELL_NO", sv.Cells[i, (int)PRD996T.CELL_NO].Text);
                                label_list.AddString("ITEM_NAME", sv.Cells[i, (int)PRD996T.ITEM_NAME].Text);
                                label_list.AddString("WO_NO", sv.Cells[i, (int)PRD996T.WO_NO].Text);
                                label_list.AddString("PC0201", sv.Cells[i, (int)PRD996T.PC0201].Text);
                                label_list.AddString("PC0202", sv.Cells[i, (int)PRD996T.PC0202].Text);
                                label_list.AddString("PC0203", sv.Cells[i, (int)PRD996T.PC0203].Text);
                                label_list.AddString("PC0204", sv.Cells[i, (int)PRD996T.PC0204].Text);
                            }
                        }
                        break;

                    //CTM 공정라벨(가공라벨 LOT)
                    case "prd106vp":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)PRD106VP.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)PRD106VP.SEQ].Value);
                                label_list.AddString("MAIN_LOT_ID", sv.Cells[i, (int)PRD106VP.MAIN_LOT_ID].Text);
                                label_list.AddString("GRADE", sv.Cells[i, (int)PRD106VP.GRADE].Text);
                                label_list.AddString("WO_NO", sv.Cells[i, (int)PRD106VP.WO_NO].Text);
                            }
                        }
                        break;

                    //CTM 공정라벨(가공라벨 ITEM)
                    case "prd106vpitem":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)PRD106VPITEM.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)PRD106VPITEM.SEQ].Value);
                                label_list.AddString("MAIN_LOT_ID", sv.Cells[i, (int)PRD106VPITEM.MAIN_LOT_ID].Text);
                                label_list.AddString("ITEM_NAME", sv.Cells[i, (int)PRD106VPITEM.ITEM_NAME].Text);
                            }
                        }
                        break;

                    //GRIT 공정라벨
                    case "prd205p":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)PRD205P.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)PRD205P.SEQ].Value);
                                label_list.AddString("MAIN_LOT_ID", sv.Cells[i, (int)PRD205P.MAIN_LOT_ID].Text);
                                label_list.AddString("ITEM_CODE", sv.Cells[i, (int)PRD205P.ITEM_CODE].Text);
                                label_list.AddString("ITEM_NAME", sv.Cells[i, (int)PRD205P.ITEM_NAME].Text);
                                label_list.AddDouble("LOT_QTY", sv.Cells[i, (int)PRD205P.LOT_QTY].Text);
                                label_list.AddString("ITEM_UOM", sv.Cells[i, (int)PRD205P.ITEM_UOM].Text);
                                label_list.AddString("WO_NO", sv.Cells[i, (int)PRD205P.WO_NO].Text);
                                label_list.AddString("REMARKS", sv.Cells[i, (int)PRD205P.REMARKS].Text);
                            }
                        }
                        break;

                    //PDC 공정라벨
                    case "prd205ppdc":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)PRD205PPDC.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)PRD205PPDC.SEQ].Value);
                                label_list.AddString("MAIN_LOT_ID", sv.Cells[i, (int)PRD205PPDC.MAIN_LOT_ID].Text);
                                label_list.AddString("ITEM_NAME", sv.Cells[i, (int)PRD205PPDC.ITEM_NAME].Text);
                                label_list.AddDouble("LOT_QTY", sv.Cells[i, (int)PRD205PPDC.LOT_QTY].Text);
                                label_list.AddString("WO_NO", sv.Cells[i, (int)PRD205PPDC.WO_NO].Text);
                                label_list.AddString("GROUP_ID", sv.Cells[i, (int)PRD205PPDC.GROUP_ID].Text);
                            }
                        }
                        break;

                    //CTM 출하라벨(66x90)
                    case "mtl900hm3p":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)MTL900HM3P.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)MTL900HM3P.SEQ].Value);
                                label_list.AddString("LOT_ID", sv.Cells[i, (int)MTL900HM3P.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", sv.Cells[i, (int)MTL900HM3P.LOT_QTY].Text);
                                label_list.AddString("ITEM_NAME", sv.Cells[i, (int)MTL900HM3P.ITEM_NAME].Text);
                                label_list.AddString("ITEM_NAME2", sv.Cells[i, (int)MTL900HM3P.ITEM_NAME2].Text);
                                label_list.AddString("GRADE", sv.Cells[i, (int)MTL900HM3P.GRADE].Text);
                                label_list.AddString("TYPE", sv.Cells[i, (int)MTL900HM3P.TYPE].Text);
                            }
                        }
                        break;


                    //CTM 출하라벨(66x90)2
                    case "mtl900hm3_1p":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)MTL900HM3_1P.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)MTL900HM3_1P.SEQ].Value);
                                label_list.AddString("LOT_ID", sv.Cells[i, (int)MTL900HM3_1P.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", sv.Cells[i, (int)MTL900HM3_1P.LOT_QTY].Text);
                                label_list.AddString("ITEM_NAME", sv.Cells[i, (int)MTL900HM3_1P.ITEM_NAME].Text);
                                label_list.AddString("ITEM_NAME2", sv.Cells[i, (int)MTL900HM3_1P.ITEM_NAME2].Text);
                            }
                        }
                        break;

                    //CTM 출하라벨(66x90)2
                    case "mtl900hm3_2p":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)MTL900HM3_1P.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)MTL900HM3_1P.SEQ].Value);
                                label_list.AddString("LOT_ID", sv.Cells[i, (int)MTL900HM3_1P.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", sv.Cells[i, (int)MTL900HM3_1P.LOT_QTY].Text);
                                label_list.AddString("ITEM_NAME", sv.Cells[i, (int)MTL900HM3_1P.ITEM_NAME].Text);
                                label_list.AddString("ITEM_NAME2", sv.Cells[i, (int)MTL900HM3_1P.ITEM_NAME2].Text);
                            }
                        }
                        break;

                    //CTM 출하라벨(30x85_INSERT제품)
                    case "mtl900hm6p":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)MTL900HM6P.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)MTL900HM6P.SEQ].Value);
                                label_list.AddString("LOT_ID", sv.Cells[i, (int)MTL900HM6P.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", sv.Cells[i, (int)MTL900HM6P.LOT_QTY].Text);
                                label_list.AddString("GRADE", sv.Cells[i, (int)MTL900HM6P.GRADE].Text);
                                label_list.AddString("TYPE", sv.Cells[i, (int)MTL900HM6P.TYPE].Text);
                                label_list.AddString("ITEM_UOM", sv.Cells[i, (int)MTL900HM6P.ITEM_UOM].Text);
                            }
                        }
                        break;

                    //HM 출하라벨(45x55)
                    case "mdprd860phmbp":
                    case "mdprd860phmbp_2":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)MDPRD860PHMBP.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)MDPRD860PHMBP.SEQ].Value);
                                label_list.AddString("LOT_ID", sv.Cells[i, (int)MDPRD860PHMBP.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", sv.Cells[i, (int)MDPRD860PHMBP.LOT_QTY].Text);
                                label_list.AddString("GRADE", sv.Cells[i, (int)MDPRD860PHMBP.GRADE].Text);
                                label_list.AddString("SPEC", sv.Cells[i, (int)MDPRD860PHMBP.SPEC].Text);
                                label_list.AddString("REMARKS", sv.Cells[i, (int)MDPRD860PHMBP.REMARKS].Text);
                            }
                        }
                        break;

                    //HM 출하라벨(90x22)
                    case "mdprd860phmap":
                    case "mdprd860phmap_2":
                    case "mdprd860phmap_4":
                    case "mdprd860phmap_5":
                    case "mdprd860phmap_6":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)MDPRD860PHMAP.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)MDPRD860PHMAP.SEQ].Value);
                                label_list.AddString("LOT_ID", sv.Cells[i, (int)MDPRD860PHMAP.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", sv.Cells[i, (int)MDPRD860PHMAP.LOT_QTY].Text);
                                label_list.AddString("GRADE", sv.Cells[i, (int)MDPRD860PHMAP.GRADE].Text);
                                label_list.AddString("SPEC", sv.Cells[i, (int)MDPRD860PHMAP.SPEC].Text);
                                label_list.AddString("REMARKS", sv.Cells[i, (int)MDPRD860PHMAP.REMARKS].Text);
                            }
                        }
                        break;

                    //HM 출하라벨(90x95)
                    case "mtl215p_8":
                    case "mtl215p_8_2":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)MTL215P_8.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)MTL215P_8.SEQ].Value);
                                label_list.AddString("LOT_ID", sv.Cells[i, (int)MTL215P_8.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", sv.Cells[i, (int)MTL215P_8.LOT_QTY].Text);
                                label_list.AddString("ITEM_NAME1", sv.Cells[i, (int)MTL215P_8.ITEM_NAME1].Text);
                                label_list.AddString("ITEM_NAME2", sv.Cells[i, (int)MTL215P_8.ITEM_NAME2].Text);
                            }
                        }
                        break;

                    //PDC 출하라벨(92x88)
                    case "mtl900hm5p":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)MTL900HM5P.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)MTL900HM5P.SEQ].Value);
                                label_list.AddString("LOT_ID", sv.Cells[i, (int)MTL900HM5P.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", sv.Cells[i, (int)MTL900HM5P.LOT_QTY].Text);
                                label_list.AddString("GRADE", sv.Cells[i, (int)MTL900HM5P.GRADE].Text);
                                label_list.AddString("TYPE", sv.Cells[i, (int)MTL900HM5P.TYPE].Text);
                            }
                        }
                        break;

                    //PDC 출하라벨(49x55)
                    case "mtl900hm9p":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)MTL900HM9P.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)MTL900HM9P.SEQ].Value);
                                label_list.AddString("LOT_ID", sv.Cells[i, (int)MTL900HM9P.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", sv.Cells[i, (int)MTL900HM9P.LOT_QTY].Text);
                                label_list.AddString("ITEM", sv.Cells[i, (int)MTL900HM9P.ITEM].Text);
                                label_list.AddString("PO", sv.Cells[i, (int)MTL900HM9P.PO].Text);
                                label_list.AddString("MN_NO", sv.Cells[i, (int)MTL900HM9P.MN_NO].Text);
                            }
                        }
                        break;

                    //GRIT 출하라벨(120x90)
                    case "prd840grtp3":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)PRD840GRTP3.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)PRD840GRTP3.SEQ].Value);
                                label_list.AddString("LOT_ID", sv.Cells[i, (int)PRD840GRTP3.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", sv.Cells[i, (int)PRD840GRTP3.LOT_QTY].Text);
                                label_list.AddString("GRADE", sv.Cells[i, (int)PRD840GRTP3.GRADE].Text);
                                label_list.AddString("TYPE", sv.Cells[i, (int)PRD840GRTP3.TYPE].Text);
                                label_list.AddString("DRAWING_FLAG", sv.Cells[i, (int)PRD840GRTP3.DRAWING_FLAG].Text);
                            }
                        }
                        break;

                    //GRIT 출하라벨(62x43)
                    case "prd840grtp5":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)PRD840GRTP5.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)PRD840GRTP5.SEQ].Value);
                                label_list.AddString("LOT_ID", sv.Cells[i, (int)PRD840GRTP5.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", sv.Cells[i, (int)PRD840GRTP5.LOT_QTY].Text);
                                label_list.AddString("GRADE", sv.Cells[i, (int)PRD840GRTP5.GRADE].Text);
                                label_list.AddString("TYPE", sv.Cells[i, (int)PRD840GRTP5.TYPE].Text);
                                label_list.AddString("DRAWING_FLAG", sv.Cells[i, (int)PRD840GRTP5.DRAWING_FLAG].Text);
                                label_list.AddString("COAT", sv.Cells[i, (int)PRD840GRTP5.COAT].Text);
                            }
                        }
                        break;

                    //GRIT 출하라벨(62x43_QR)
                    case "prd840grtp2_DM":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)PRD840GRTP2_DM.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)PRD840GRTP2_DM.SEQ].Value);
                                label_list.AddString("LOT_ID", sv.Cells[i, (int)PRD840GRTP2_DM.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", sv.Cells[i, (int)PRD840GRTP2_DM.LOT_QTY].Text);
                                label_list.AddString("GRADE", sv.Cells[i, (int)PRD840GRTP2_DM.GRADE].Text);
                                label_list.AddString("TYPE", sv.Cells[i, (int)PRD840GRTP2_DM.TYPE].Text);
                                label_list.AddString("DRAWING_FLAG", sv.Cells[i, (int)PRD840GRTP2_DM.DRAWING_FLAG].Text);
                                label_list.AddString("COAT", sv.Cells[i, (int)PRD840GRTP2_DM.COAT].Text);
                            }
                        }
                        break;

                    //GRIT 출하라벨(76x26)
                    case "840Sample":
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (sv.Cells[i, (int)GRIT_SHIP_LABEL.CHECK].Text.ToString().ToUpper() == "TRUE")
                            {
                                label_list = in_node.AddNode("LABEL_LIST");
                                label_list.AddInt("SEQ", sv.Cells[i, (int)GRIT_SHIP_LABEL.SEQ].Value);
                                label_list.AddString("LOT_ID", sv.Cells[i, (int)GRIT_SHIP_LABEL.LOT_ID].Text);
                                label_list.AddDouble("LOT_QTY", sv.Cells[i, (int)GRIT_SHIP_LABEL.LOT_QTY].Text);
                                label_list.AddString("GRADE", sv.Cells[i, (int)GRIT_SHIP_LABEL.GRADE].Text);
                                label_list.AddString("TYPE", sv.Cells[i, (int)GRIT_SHIP_LABEL.TYPE].Text);
                                label_list.AddString("DRAWING_FLAG", sv.Cells[i, (int)GRIT_SHIP_LABEL.DRAWING_FLAG].Text);
                                label_list.AddString("COAT", sv.Cells[i, (int)GRIT_SHIP_LABEL.COAT].Text);
                            }
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

        private bool DeleteLabelList(string sAreaId, string sFileName)
        {
            TRSNode in_node = new TRSNode("Print_Label_List_In");
            TRSNode out_node = new TRSNode("Print_Label_List_Out");
            TRSNode label_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("AREA_ID", sAreaId);
                in_node.AddString("FILE_NAME", sFileName);

                int column_count = sv.ColumnCount;

                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (sv.Cells[i, 0].Text.ToString().ToUpper() == "TRUE")
                    {
                        label_list = in_node.AddNode("LABEL_LIST");
                        label_list.AddInt("SEQ", sv.Cells[i, column_count - 1].Value);
                    }
                }

                if (MPCR.CallService("CUS_BAS", "CUS_BAS_Print_Label_List", in_node, ref out_node) == false)
                    return false;
                else
                {
                    MPCR.ShowSuccessMsg(out_node);
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool CheckCell(int iRow, int iColoumn)
        {
            try
            {
                if (sp == null)
                {
                    sp = spdInvLabelList;
                }

                if (iColoumn != 0)
                    return false;

                if (sp.ActiveSheet.ColumnHeader.Cells[iRow, iColoumn].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(sp, iRow, iColoumn, true, true, false);
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

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

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

        private void btnDel_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.DELETE) == false)
                    return;

                if (DeleteLabelList(area_id, file_name))
                {
                    ClearList("DELETE");
                    ViewLabel(area_id, file_name);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            int iRow = 0;
            try
            {
                if (CheckCondition(CSGC.CHECK.ADD) == false)
                    return;

                iRow = sv.RowCount;
                sv.RowCount++;
                sv.Cells[iRow, 0].Value = true;
                sv.Cells[iRow, 1].Value = s_area_desc;
                sv.Cells[iRow, 3].Value = s_label_name;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnRowDel_Click(object sender, EventArgs e)
        {
            int iRow = 0;
            try
            {
                iRow = (sv != null ? sv.RowCount : 0);

                for (int i = iRow - 1; i >= 0; i--)
                {
                    if (sv.Cells[i, 0].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (i < row_count)
                        {
                            return;
                        }

                        sv.RemoveRows(i, 1);
                    }
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

                ClearList("VIEW");

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

        private void spdInvLabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdHmShip45LabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdCtmShipInsertLabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdCellLabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdItemLabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdLotLabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdCtmShip2LabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdCtmShipLabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdPdcOperLabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdGritOperLabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdPdcShip49LabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdHmShip95LabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdGirtShip76LabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdGritShipQrLabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdGritShip62LabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdGritShip120LabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdPdcShip92LabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }

        private void spdHmShip90LabelList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader)
            {
                CheckCell(e.Row, e.Column);
            }
        }
    }
}
