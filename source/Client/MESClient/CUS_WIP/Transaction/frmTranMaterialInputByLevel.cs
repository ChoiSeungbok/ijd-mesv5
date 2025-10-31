using System;
using System.Data;
using System.Windows.Forms;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

namespace CUS_WIP
{
    public partial class frmTranMaterialInputByLevel : CUS_COM.frmTranForm03
    {
        public frmTranMaterialInputByLevel()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum WORKORDER
        {
            ORDER_ID,               // 1 : 작업지시번호
            START_DATE,             // 2 : 시작일
            END_DATE,               // 3 : 완료일
            MAT_ID,                 // 4 : 제품코드
            MAT_DESC,               // 5 : 제품명
            ORDER_QTY,              // 6 : 지시수량
            PROD_QTY,               // 7 : 생산수량
            STOCK,                  // 8 : 창고
            STOCK_DESC,             // 9 : 창고명
            CREATE_CODE,            //10 : 작업지시 종류 
            CREATE_CODE_DESC        //11 : 작업지시 종류명
        }

        private enum BOM
        {
            OPER,                   // 1 : 공정명
            OPER_DESC,              // 2 : ERP공정코드
            MAT_ID,                 // 3 : 자재코드
            MAT_DESC,               // 4 : 자재명
            UNIT_QTY,               // 5 : 단위소요량
            TOTAL_QTY,              // 6 : 총소요량
            UNIT,                   // 7 : 단위
            TO_STOCK                // 8 : 출고창고
        }

        private enum STOCK
        {
            CHK,                    // 1 : 공정명
            MAT_ID,                 // 3 : 자재코드
            MAT_DESC,               // 4 : 자재명
            QTY,                    // 5 : 총소요량
            UNIT,                   // 6 : 단위
            LOT_TYPE,               // 7 : LOT 타입
            LOT_ID,                  // 2 : LOT ID
            VENDOR_LOT_ID,
            VENDOR_DESC,
            OUT_OPER,
            CREATE_CODE,            //
            CREATE_CODE_DESC,        //
            LOT_DESC
        }

        private enum INPUT
        {
            CHK,                    // 1 : 공정명
            MAT_ID,                 // 3 : 자재코드
            MAT_DESC,               // 4 : 자재명
            QTY,                    // 5 : 총소요량
            UNIT,                   // 6 : 단위
            INPUT_QTY,              // 7 : 투입 수량
            UNIT_QTY,               // 8 : 단위 수량
            LOT_TYPE,               // 9 : LOT 타입
            INPUT_TYPE,             //10 : 투입 방식
            INPUT_TYPE_SELECT,      //11 : 투입 방식 선택
            LOT_ID,                  // 2 : LOT ID
            VENDOR_LOT_ID,
            VENDOR_DESC,
            OUT_OPER,
            CREATE_CODE,            //
            CREATE_CODE_DESC,        //
            LOT_DESC,

        }

        #endregion

        #region " Variable Definition "

        public string sArea_id = "";
        public string sArea_desc = "";
        public string sSub_area_id = "";
        public string sSub_area_desc = "";
        public string sOper_id = "";
        public string sOper_desc = "";
        public string sOrder_id = "";
        public string sRes_id = "";
        public string sRes_desc = "";

        bool bDeleteWipLot = false;

        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
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

        //load level 조회 함수
        public bool ViewLoadLevel(Control control)
        {
            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                if (TPDR.GetDataOne("", ref dt, "CWIP2025-007", dvcArgu, false, false, ref sSql) == false)
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
                        itmX = new ListViewItem(row["KEY_1"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["DATA_1"].ToString());
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

        //공정lot만 투입 공정인지 체크 하는 함수
        private bool ViewOperCheck()
        {
            bool bResult = false;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2025-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }

                if (dt.Rows.Count > 0)
                {
                    if (dt.Rows[0]["OPER_CMF_2"].ToString() == "Y")
                        bResult = true;
                    else
                        bResult = false;
                }

                return bResult;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //작업지시정보 조회함수
        private void ViewOrder()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORDER_ID";
                dvcArgu[1].sCondition_Value = cdvOrder.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2025-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdWorkOrder_Sheet1.RowCount++;

                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.START_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["START_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.END_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["END_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.ORDER_QTY].Value = dt.Rows[i]["ORDER_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.PROD_QTY].Value = dt.Rows[i]["PROD_QTY"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.STOCK].Value = dt.Rows[i]["STOCK"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.STOCK_DESC].Value = dt.Rows[i]["STOCK_DESC"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    spdWorkOrder_Sheet1.Cells[i, (int)WORKORDER.CREATE_CODE_DESC].Value = dt.Rows[i]["CREATE_CODE_DESC"];
                }

                MPCF.FitColumnHeader(spdWorkOrder);


                fnGetWarehouse();

                /*
                //창고는 자동 선택하도록 한다.
                if (spdWorkOrder_Sheet1.RowCount > 0)
                {
                    cdvWarehouse.Text = spdWorkOrder_Sheet1.Cells[0, (int)WORKORDER.STOCK].Text;
                    cdvWarehouse.DisplayText = spdWorkOrder_Sheet1.Cells[0, (int)WORKORDER.STOCK_DESC].Text;
                }
                */

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        //최초 창고 조회 함수
        private void fnGetWarehouse()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORDER_ID";
                dvcArgu[1].sCondition_Value = cdvOrder.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;


                if (TPDR.GetDataOne("", ref dt, "CWIP2024-007", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                if (dt.Rows.Count > 0)
                {
                    cdvWarehouse.Text = dt.Rows[i]["OPER"].ToString();
                    cdvWarehouse.DisplayText = dt.Rows[i]["OPER_DESC"].ToString();
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        //자재소요정보 조회 함수
        private void ViewBom(string sOrder_id)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORDER_ID";
                dvcArgu[1].sCondition_Value = sOrder_id;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2025-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdBom);
                    return;
                }

                MPCF.ClearList(spdBom);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdBom_Sheet1.RowCount++;

                    spdBom_Sheet1.Cells[i, (int)BOM.OPER].Value = dt.Rows[i]["OPER"];
                    spdBom_Sheet1.Cells[i, (int)BOM.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdBom_Sheet1.Cells[i, (int)BOM.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdBom_Sheet1.Cells[i, (int)BOM.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdBom_Sheet1.Cells[i, (int)BOM.UNIT_QTY].Value = dt.Rows[i]["UNIT_QTY"];
                    spdBom_Sheet1.Cells[i, (int)BOM.TOTAL_QTY].Value = dt.Rows[i]["TOTAL_QTY"];
                    spdBom_Sheet1.Cells[i, (int)BOM.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdBom_Sheet1.Cells[i, (int)BOM.TO_STOCK].Value = dt.Rows[i]["OUT_OPER_DESC"];
                }
                MPCF.FitColumnHeader(spdBom);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //재고리스트 조회 함수
        private void ViewMatList()
        {
            string sSql = "";
            string sViewID = "";
            int i = 0;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;

                if (bDeleteWipLot == false)
                    sViewID = "CWIP2025-003";
                else
                    sViewID = "CWIP2025-005";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvWarehouse.Text;

                dvcArgu[2].sCondition_ID = "MAT_DESC";
                dvcArgu[2].sCondition_Value = "%" + txtMatdesc.Text + "%";

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdMatList);
                    return;
                }

                MPCF.ClearList(spdMatList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMatList_Sheet1.RowCount++;

                    spdMatList_Sheet1.SetValue(i, (int)STOCK.CHK, false);
                    spdMatList_Sheet1.Cells[i, (int)STOCK.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.QTY].Value = dt.Rows[i]["QTY"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.OUT_OPER].Value = dt.Rows[i]["OPER"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.CREATE_CODE_DESC].Value = dt.Rows[i]["CREATE_CODE_DESC"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.LOT_DESC].Value = dt.Rows[i]["LOT_DESC"];
                }

                MPCF.FitColumnHeader(spdMatList);
                spdMatList_Sheet1.Columns[(int)STOCK.CHK].Width = 30;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //투입리스트 조회(작업지시) 함수
        private void ViewInputOrderList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REL_LEVEL";
                dvcArgu[1].sCondition_Value = cdvInputType.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;

                dvcArgu[3].sCondition_ID = "ORDER_ID";
                dvcArgu[3].sCondition_Value = cdvOrder.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2025-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInputList);
                    return;
                }

                MPCF.ClearList(spdInputList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdInputList_Sheet1.RowCount++;

                    spdInputList_Sheet1.SetValue(i, (int)INPUT.CHK, false);
                    spdInputList_Sheet1.Cells[i, (int)INPUT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.QTY].Value = dt.Rows[i]["QTY"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.INPUT_QTY].Value = dt.Rows[i]["INPUT_QTY"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.UNIT_QTY].Value = dt.Rows[i]["UNIT_QTY"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.INPUT_TYPE].Value = dt.Rows[i]["INPUT_TYPE"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.OUT_OPER].Value = dt.Rows[i]["OPER"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.CREATE_CODE_DESC].Value = dt.Rows[i]["CREATE_CODE_DESC"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.LOT_DESC].Value = dt.Rows[i]["LOT_DESC"];
                }

                MPCF.FitColumnHeader(spdInputList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //투입리스트 조회(공정) 함수
        private void ViewInputOperList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "REL_LEVEL";
                dvcArgu[1].sCondition_Value = cdvInputType.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2025-008", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInputList);
                    return;
                }

                MPCF.ClearList(spdInputList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdInputList_Sheet1.RowCount++;

                    spdInputList_Sheet1.SetValue(i, (int)INPUT.CHK, false);
                    spdInputList_Sheet1.Cells[i, (int)INPUT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.QTY].Value = dt.Rows[i]["QTY"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.INPUT_QTY].Value = dt.Rows[i]["INPUT_QTY"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.UNIT_QTY].Value = dt.Rows[i]["UNIT_QTY"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.INPUT_TYPE].Value = dt.Rows[i]["INPUT_TYPE"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.OUT_OPER].Value = dt.Rows[i]["OPER"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.CREATE_CODE_DESC].Value = dt.Rows[i]["CREATE_CODE_DESC"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.LOT_DESC].Value = dt.Rows[i]["LOT_DESC"];
                }

                MPCF.FitColumnHeader(spdInputList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //LOT ID / Kitting ID 조회 함수
        private void ViewLotInfo()
        {
            int iRow = 0;
            string sLotId = "";
            double dUnitQty = 0;
            double dTotalQty = 0;
            string sMatTmp = "";
            bool bBom = false;
            bool bSkip = false;
            string chkOper = cdvOper.Text;

            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '2';
                in_node.AddString("LOT_ID", txtLotID.Text);
                if (spdWorkOrder.ActiveSheet.RowCount > 0)
                    chkOper = spdWorkOrder_Sheet1.Cells[spdWorkOrder_Sheet1.ActiveRowIndex, (int)WORKORDER.STOCK].Text;
                in_node.AddString("OPER", chkOper);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_Info", in_node, ref out_node) == false)
                {
                    return;
                }
                for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                {
                    bBom = false;
                    bSkip = false;

                    //lot 정보가 이미 있는경우 넘어간다.
                    sLotId = out_node.GetList("LOT_TBL")[i].GetString("LOT_ID");
                    sMatTmp = out_node.GetList("LOT_TBL")[i].GetString("MAT_ID");

                    for (int k = 0; k < spdInputList.ActiveSheet.RowCount; k++)
                    {
                        if (sLotId == spdInputList.ActiveSheet.Cells[k, (int)INPUT.LOT_ID].Text)
                        {
                            bSkip = true;
                            continue;
                        }
                    }

                    if (bSkip == true)
                        continue;

                    for (int j = spdMatList.ActiveSheet.RowCount; j > 0; j--)
                    {
                        if (spdMatList.ActiveSheet.Cells[j - 1, (int)STOCK.LOT_ID].Text == sLotId)
                        {
                            spdMatList.ActiveSheet.RemoveRows(j - 1, 1);
                        }
                    }

                    for (int j = 0; j < spdBom.ActiveSheet.RowCount; j++)
                    {
                        if (spdBom.ActiveSheet.Cells[j, (int)BOM.MAT_ID].Text == sMatTmp)
                        {
                            dUnitQty = MPCF.ToDbl(spdBom.ActiveSheet.Cells[j, (int)BOM.UNIT_QTY].Text);
                            dTotalQty = MPCF.ToDbl(spdBom.ActiveSheet.Cells[j, (int)BOM.TOTAL_QTY].Text);
                            bBom = true;
                        }
                    }

                    if (cdvInputType.Text == "2")
                    {
                        if (bBom == false)
                        {
                            if (txtUnitQty.Text.ToString().Trim() == "")
                            {
                                //CMN505 INFO - BOM에 존재하지 않은 자재가 있습니다. BOM을 확인하세요.
                                MPCF.ShowMsgBox("If there is no BOM, please enter  Unit Qty");
                                txtUnitQty.Focus();
                                return;
                            }
                            else
                            {
                                dUnitQty = MPCF.ToDbl(txtUnitQty.Text.ToString().Trim());
                                bBom = true;
                            }
                            /*
                            //CMN505 INFO - BOM에 존재하지 않은 자재가 있습니다. BOM을 확인하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(505));
                            return;
                            */
                        }


                    }

                    iRow = spdInputList.ActiveSheet.RowCount;

                    spdInputList.ActiveSheet.RowCount++;
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.CHK, true);
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.VENDOR_LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("VENDOR_LOT_ID"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.VENDOR_DESC, out_node.GetList("LOT_TBL")[i].GetString("VENDOR_LOT_DESC"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.MAT_ID, out_node.GetList("LOT_TBL")[i].GetString("MAT_ID"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.MAT_DESC, out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC"));

                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.UNIT, out_node.GetList("LOT_TBL")[i].GetString("UNIT_1"));

                    if (cdvInputType.Text == "2")
                    {
                        if (bBom == false || dTotalQty == 0)
                        {

                            dTotalQty = dUnitQty * MPCF.ToDbl(spdWorkOrder_Sheet1.Cells[0, (int)WORKORDER.ORDER_QTY].Text);

                            if (dTotalQty != Math.Round(dTotalQty, 0))
                            {
                                if (out_node.GetList("LOT_TBL")[i].GetString("UNIT_1") == "EA")
                                {
                                    //CMN574 INFO -  단위가  "EA"이면서  총 입력 수량은 소수점을 갖습니다.정수로 변환(YES/NO)?
                                    if (MPCF.ShowMsgBox(MPCF.GetMessage(574) + " " + dTotalQty + "-->" + Math.Round(dTotalQty, 0), System.Windows.Forms.MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.Yes)
                                    {
                                        dTotalQty = Math.Round(dTotalQty, 0);
                                    }

                                }
                            }

                            /*
                            if(chkInteger.Checked == true)
                            {
                                dTotalQty = Math.Round(dTotalQty, 0);
                            }
                            */

                            spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                            spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_QTY, dTotalQty);


                            if (MPCF.ToDbl(out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1")) < dTotalQty)
                            {
                                spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                            }
                            else
                            {
                                spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_QTY, dTotalQty);
                            }

                        }
                        else
                        {
                            spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                            //   spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_QTY, dTotalQty);

                            if (MPCF.ToDbl(out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1")) < dTotalQty)
                            {
                                spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                            }
                            else
                            {
                                spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_QTY, dTotalQty);
                            }

                        }


                    }
                    else
                    {
                        spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                        spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                    }

                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.UNIT_QTY, dUnitQty);
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.LOT_TYPE, out_node.GetList("LOT_TBL")[i].GetString("LOT_TYPE"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_TYPE, CSGC.CP_MAT_INPUT_TYPE_BOM);
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.OUT_OPER, out_node.GetList("LOT_TBL")[i].GetString("OPER"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.CREATE_CODE, out_node.GetList("LOT_TBL")[i].GetString("CREATE_CODE"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.CREATE_CODE_DESC, out_node.GetList("LOT_TBL")[i].GetString("CREATE_CODE_DESC"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.LOT_DESC, out_node.GetList("LOT_TBL")[i].GetString("LAST_COMMENT"));
                }

                txtLotID.Text = "";

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        //자재 투입처리 함수
        private bool InputMat()
        {
            TRSNode in_node = new TRSNode("input_In");
            TRSNode out_node = new TRSNode("input_Out");
            TRSNode input_list;

            try
            {
                MPCR.SetInMsg(in_node);

                //작업지시별 투입
                if (cdvInputType.Text == "2")
                    in_node.ProcStep = '2';
                //공정별 투입
                else if (cdvInputType.Text == "3")
                    in_node.ProcStep = '3';

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("OUT_OPER", cdvWarehouse.Text);
                in_node.AddString("ORDER_ID", cdvOrder.Text);
                //in_node.AddString("RES_ID", cdvResource.Text);
                in_node.AddChar("REL_LEVEL", cdvInputType.Text);

                for (int i = 0; i < spdInputList.ActiveSheet.RowCount; i++)
                {
                    input_list = in_node.AddNode("LIST_TBL");
                    input_list.AddString("LOT_ID", spdInputList.ActiveSheet.Cells[i, (int)INPUT.LOT_ID].Text);
                    input_list.AddString("MAT_ID", spdInputList.ActiveSheet.Cells[i, (int)INPUT.MAT_ID].Text);
                    //input_list.AddDouble("QTY", spdInputList.ActiveSheet.Cells[i, (int)INPUT.QTY].Text);
                    input_list.AddString("LOT_TYPE", spdInputList.ActiveSheet.Cells[i, (int)INPUT.LOT_TYPE].Text);
                    input_list.AddDouble("QTY", MPCF.ToDbl(spdInputList.ActiveSheet.Cells[i, (int)INPUT.INPUT_QTY].Text));



                    input_list.AddDouble("BOM_QTY", MPCF.ToDbl(spdInputList.ActiveSheet.Cells[i, (int)INPUT.UNIT_QTY].Text));
                    input_list.AddString("INPUT_TYPE", spdInputList.ActiveSheet.Cells[i, (int)INPUT.INPUT_TYPE].Text);
                    input_list.AddString("OUT_OPER", spdInputList.ActiveSheet.Cells[i, (int)INPUT.OUT_OPER].Text);


                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Input_Material_Lot", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //벨리데이션 체크
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            //int iCount = 0;

            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return false;
                }

                if (cdvInputType.Text == "2")
                {
                    if (MPCF.Trim(cdvOrder.Text) == "")
                    {
                        //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOrder.Text + "]");
                        cdvOrder.Focus();
                        return false;
                    }
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        if (MPCF.Trim(cdvWarehouse.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWarehouse.Text + "]");
                            cdvWarehouse.Focus();
                            return false;
                        }

                        break;

                    case CSGC.CHECK.SAVE:


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

        private void frmTranMaterialInputByLevel_Load(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Text = sArea_id;
                cdvDept.DisplayText = sArea_desc;
                cdvWorkPlace.Text = sSub_area_id;
                cdvWorkPlace.DisplayText = sSub_area_desc;
                cdvOper.Text = sOper_id;
                cdvOper.DisplayText = sOper_desc;
                cdvOrder.Text = sOrder_id;

                cdvInputType.Text = "2";
                cdvInputType.DisplayText = "Work Order";

                if (MPCF.Trim(cdvOrder.Text) != "")
                {
                    btnView.PerformClick();
                }

                bDeleteWipLot = ViewOperCheck();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //투입 레벨 선택
        private void cdvInputType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvInputType.Init();
                MPCF.InitListView(cdvInputType.GetListView);
                cdvInputType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvInputType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvInputType.SelectedSubItemIndex = 0;
                cdvInputType.DisplaySubItemIndex = 1;

                if (ViewLoadLevel(cdvInputType.GetListView) == false)
                {
                    return;
                }

                //cdvInputType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvInputType_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                //2: 작업지시 , 3 : 공정
                if (cdvInputType.Text == "2")
                {
                    splitContainer2.Visible = true;
                }
                else if (cdvInputType.Text == "3")
                {
                    splitContainer2.Visible = false;
                }

                btnView.PerformClick();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWarehouse_ButtonPress(object sender, EventArgs e)
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

                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return;
                }

                cdvWarehouse.Init();
                MPCF.InitListView(cdvWarehouse.GetListView);
                cdvWarehouse.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWarehouse.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWarehouse.SelectedSubItemIndex = 0;
                cdvWarehouse.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvWarehouse.GetListView, '1', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
                {
                    return;
                }

                cdvWarehouse.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //자재 Lot 또는 Kitting ID 스캔
        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    ViewLotInfo();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                bDeleteWipLot = ViewOperCheck();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdMatList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)STOCK.CHK)
                    {
                        CSCF.CheckSpreadCell(spdMatList, 0, 0, true, true);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdInputList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)INPUT.CHK)
                    {
                        CSCF.CheckSpreadCell(spdInputList, 0, 0, true, true);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdInputList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                if (e.Column == (int)INPUT.INPUT_TYPE_SELECT)
                {

                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    //cdvGridButton.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                    if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', CSGC.CP_GCM_INV_INPUT_TYPE) == false)
                        return;

                    cdvGridButton.ShowPopupList(e.Row, e.Column);
                    //cdvGridButton.InsertEmptyRow(0, 1);                    
                    cdvGridButton.AddEmptyRow(1);

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (spdInputList.ActiveSheet.ActiveColumnIndex == (int)INPUT.INPUT_TYPE_SELECT)
                {
                    spdInputList.ActiveSheet.SetValue(e.Row, (int)INPUT.INPUT_TYPE, e.SelectedItem.SubItems[0].Text);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtMatdesc_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    btnMatView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            string sTmp = "";
            int iRow = 0;
            double dUnitQty = 0;
            string sMatTmp = "";
            bool bBom = false;
            double dTotalQty = 0;

            try
            {
                for (int i = spdMatList.ActiveSheet.RowCount; i > 0; i--)
                {

                    bBom = false;

                    if (spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        sTmp = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.LOT_ID].Text;
                        sMatTmp = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.MAT_ID].Text;

                        for (int k = 0; k < spdInputList.ActiveSheet.RowCount; k++)
                        {
                            if (spdInputList.ActiveSheet.Cells[k, (int)INPUT.LOT_ID].Text == sTmp)
                                continue;
                        }

                        for (int j = 0; j < spdBom.ActiveSheet.RowCount; j++)
                        {
                            if (spdBom.ActiveSheet.Cells[j, (int)BOM.MAT_ID].Text == sMatTmp)
                            {
                                dUnitQty = MPCF.ToDbl(spdBom.ActiveSheet.Cells[j, (int)BOM.UNIT_QTY].Text);
                                dTotalQty = MPCF.ToDbl(spdBom.ActiveSheet.Cells[j, (int)BOM.TOTAL_QTY].Text);
                                bBom = true;
                            }
                        }

                        if (cdvInputType.Text == "2")
                        {
                            if (bBom == false)
                            {

                                if (MPCF.ShowMsgBox(MPCF.GetMessage(507), System.Windows.Forms.MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.Yes)
                                {

                                    if (txtUnitQty.Text.ToString().Trim() == "")
                                    {

                                        MPCF.ShowMsgBox("please Input  Unit Qty(소요단위수량을 입력해주세요)");
                                        txtUnitQty.Focus();
                                        return;
                                    }

                                    dUnitQty = MPCF.ToDbl(txtUnitQty.Text.ToString().Trim());
                                    bBom = true;
                                }
                                else
                                {
                                    return;
                                }

                                /*
                                //CMN505 INFO - BOM에 존재하지 않은 자재가 있습니다. BOM을 확인하세요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(507));
                                return;
                                */
                            }


                        }

                        iRow = spdInputList.ActiveSheet.RowCount;
                        spdInputList.ActiveSheet.RowCount++;

                        spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.CHK, true);
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.LOT_ID].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.LOT_ID].Text;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.VENDOR_LOT_ID].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.VENDOR_LOT_ID].Text;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.VENDOR_DESC].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.VENDOR_DESC].Text;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.MAT_ID].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.MAT_ID].Text;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.MAT_DESC].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.MAT_DESC].Text;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.QTY].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.QTY].Value;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.UNIT].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.UNIT].Text;


                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.INPUT_QTY].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.QTY].Value;


                        if (cdvInputType.Text == "2")
                        {
                            if (bBom == false || dTotalQty == 0)
                            {

                                dTotalQty = dUnitQty * MPCF.ToDbl(spdWorkOrder_Sheet1.Cells[0, (int)WORKORDER.ORDER_QTY].Text);

                                if (dTotalQty != Math.Round(dTotalQty, 0))
                                {
                                    if (spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.UNIT].Text == "EA")
                                    {
                                        //CMN574 INFO -  단위가  "EA"이면서  총 입력 수량은 소수점을 갖습니다.정수로 변환(YES/NO)?
                                        if (MPCF.ShowMsgBox(MPCF.GetMessage(574) + " " + dTotalQty + "-->" + Math.Round(dTotalQty, 0), System.Windows.Forms.MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.Yes)
                                        {
                                            dTotalQty = Math.Round(dTotalQty, 0);
                                        }

                                    }
                                }

                                /*
                                if(chkInteger.Checked == true)
                                {
                                    dTotalQty = Math.Round(dTotalQty, 0);
                                }
                                */

                                spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.QTY, spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.QTY].Value);
                                // spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_QTY, dTotalQty);


                                if (MPCF.ToDbl(spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.QTY].Text) < dTotalQty)
                                {
                                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_QTY, spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.QTY].Value);
                                }
                                else
                                {
                                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_QTY, dTotalQty);
                                }
                            }
                            else
                            {

                                spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.QTY, spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.QTY].Value);
                                // spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_QTY, dTotalQty);

                                if (MPCF.ToDbl(spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.QTY].Text) < dTotalQty)
                                {
                                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_QTY, spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.QTY].Value);
                                }
                                else
                                {
                                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_QTY, dTotalQty);
                                }
                            }


                        }
                        else
                        {
                            spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.QTY, spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.QTY].Value);
                            spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_QTY, spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.QTY].Value);
                        }


                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.UNIT_QTY].Value = dUnitQty;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.LOT_TYPE].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.LOT_TYPE].Text;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.INPUT_TYPE].Value = CSGC.CP_MAT_INPUT_TYPE_BOM;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.OUT_OPER].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.OUT_OPER].Value;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.CREATE_CODE].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.CREATE_CODE].Value;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.CREATE_CODE_DESC].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.CREATE_CODE_DESC].Value;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.LOT_DESC].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.LOT_DESC].Value;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.VENDOR_LOT_ID].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.VENDOR_LOT_ID].Value;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.VENDOR_DESC].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.VENDOR_DESC].Value;

                        spdMatList.ActiveSheet.RemoveRows(i - 1, 1);
                    }
                }

                MPCF.FitColumnHeader(spdInputList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDel_Click(object sender, EventArgs e)
        {
            string sTmp = "";
            int iRow = 0;
            bool bCheck = false;

            try
            {
                if (MPCF.Trim(cdvWarehouse.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWarehouse.Text + "]");
                    cdvWarehouse.Focus();
                    return;
                }

                for (int i = spdInputList.ActiveSheet.RowCount; i > 0; i--)
                {
                    if (spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        sTmp = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.LOT_ID].Text;

                        for (int k = 0; k < spdMatList.ActiveSheet.RowCount; k++)
                        {
                            if (spdMatList.ActiveSheet.Cells[k, (int)STOCK.LOT_ID].Text == sTmp)
                                continue;
                        }


                        for (int j = 0; j < spdMatList.ActiveSheet.RowCount; j++)
                        {
                            if (spdMatList.ActiveSheet.Cells[j, (int)STOCK.LOT_ID].Text == sTmp)
                            {
                                bCheck = true;
                                break;
                            }
                        }

                        if (bCheck == true)
                        {
                            spdInputList.ActiveSheet.RemoveRows(i - 1, 1);
                            continue;
                        }

                        iRow = spdMatList.ActiveSheet.RowCount;
                        spdMatList.ActiveSheet.RowCount++;

                        spdMatList.ActiveSheet.SetValue(iRow, (int)STOCK.CHK, false);
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.LOT_ID].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.LOT_ID].Text;
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.VENDOR_LOT_ID].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.VENDOR_LOT_ID].Text;
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.VENDOR_DESC].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.VENDOR_DESC].Text;
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.MAT_ID].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.MAT_ID].Text;
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.MAT_DESC].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.MAT_DESC].Text;
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.QTY].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.QTY].Value;
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.UNIT].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.UNIT].Text;
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.LOT_TYPE].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.LOT_TYPE].Text;
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.OUT_OPER].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.OUT_OPER].Text;
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.CREATE_CODE].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.CREATE_CODE].Text;
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.CREATE_CODE_DESC].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.CREATE_CODE_DESC].Text;
                        spdMatList.ActiveSheet.Cells[iRow, (int)STOCK.LOT_DESC].Value = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.LOT_DESC].Text;

                        spdInputList.ActiveSheet.RemoveRows(i - 1, 1);
                    }
                }

                spdMatList.ActiveSheet.SortRows((int)STOCK.LOT_ID, true, false);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //재고리스트 조회
        private void btnMatView_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvWarehouse.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWarehouse.Text + "]");
                    cdvWarehouse.Focus();
                    return;
                }

                ViewMatList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //작업지시 조회
        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.NONE) == false)
                    return;

                //2: 작업지시 , 3 : 공정                
                if (cdvInputType.Text == "2")
                {
                    ViewOrder();
                    ViewBom(cdvOrder.Text);
                    ViewInputOrderList();
                }
                else if (cdvInputType.Text == "3")
                {
                    ViewInputOperList();
                }

                if (MPCF.Trim(cdvWarehouse.Text) != "")
                {
                    ViewMatList();
                }
                else
                {
                    MPCF.ClearList(spdMatList);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //저장버튼으로 자재 투입 실행
        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (InputMat())
                {
                    //btnMatView.PerformClick();
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOrder_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvOrder.DisplayText == "")
                cdvOrder.Text = "";
        }

        private void btnGCM_Click(object sender, EventArgs e)
        {

            try
            {

                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = "C_OPER_BOM_WH";

                if (MPGV.gcLanguage == '2')
                {
                    popup.sTable_name_desc = "Default 투입창고 등록";
                    popup.sComment = "투입창고가 지정되지 않은 공정은 FLOW기준완료 창고가 Default창고가 됩니다.";

                }
                else
                {
                    popup.sTable_name_desc = "Default WeareWhouse";
                    popup.sComment = "In the process where the input warehouse is not specified, the FLOW standard completion warehouse becomes the default warehouse.";

                }


                if (popup.ShowDialog() == DialogResult.OK)
                {

                    popup = null;
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        private void btnGCM2_Click(object sender, EventArgs e)
        {

            try
            {

                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = "C_AUTO_LDM_ITEM";

                if (MPGV.gcLanguage == '2')
                {
                    popup.sTable_name_desc = "자동투입 설정 품목";
                    popup.sComment = "해당화면에 설정된 품목은 해당 창고에 이동시 자동으로 공정투입예정품목으로 등록됩니다.";

                }
                else
                {
                    popup.sTable_name_desc = "Automatic input items by process";
                    popup.sComment = "The set items are automatically registered as scheduled for processing when they are moved to the registered warehouse.";

                }


                if (popup.ShowDialog() == DialogResult.OK)
                {

                    popup = null;
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnGCM3_Click(object sender, EventArgs e)
        {

            try
            {

                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;

                //한국은 생산품목기준 베트남은 투입품목기준
                if (MPGV.gsFactory == "IJDK1")
                {
                    popup.sTable_name = "TEST_ITEM_ISSUE";
                }
                else
                {
                    popup.sTable_name = "TEST_ITEM_ISSUE2";
                }


                if (MPGV.gcLanguage == '2')
                {
                    popup.sTable_name_desc = "품목별 TEST및RND 자재기타입출고 계정";
                    popup.sComment = "해당화면에서 등록된 품목은 생산진행시 자재소요에대해서 등록된 기타출고 계정으로 출고됩니다.";

                }
                else
                {
                    popup.sTable_name_desc = "Test / Rnd Etc Account";
                    popup.sComment = "Items registered will be Inputed to ETC In/Out accounts registered for material requirements during production.";

                }


                if (popup.ShowDialog() == DialogResult.OK)
                {

                    popup = null;
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnGCM4_Click(object sender, EventArgs e)
        {

            try
            {

                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;


                popup.sTable_name = "C_BOM_CHK_OPER";

                if (MPGV.gcLanguage == '2')
                {
                    popup.sTable_name_desc = "공정별 완료전 자재투입 정버 체크";
                    popup.sComment = "해당화면에서 등록된 공정은 생산 완료전 투입자재에 대한 정보를 체크합니다..";

                }
                else
                {
                    popup.sTable_name_desc = "Bom Check Operation";
                    popup.sComment = "The process registered on the screen checks information on input materials before production is completed.";

                }


                if (popup.ShowDialog() == DialogResult.OK)
                {

                    popup = null;
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        #endregion


    }
}
