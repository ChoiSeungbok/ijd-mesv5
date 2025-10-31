using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

namespace CUS_WIP
{
    public partial class frmTranInputMaterials : CUS_COM.frmTranForm03
    {
        public frmTranInputMaterials()
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
            STOCK_DESC              // 9 : 창고명
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
            LOT_ID,                 // 2 : LOT ID
            VENDOR_LOT_ID,
            MAT_ID,                 // 3 : 자재코드
            MAT_DESC,               // 4 : 자재명
            QTY,                    // 5 : 총소요량
            UNIT,                   // 6 : 단위
            LOT_TYPE,                // 7 : LOT 타입
            VENDOR_DESC
        }

        private enum INPUT
        {
            CHK,                    // 1 : 공정명
            LOT_ID,                 // 2 : LOT ID
            VENDOR_LOT_ID,
            MAT_ID,                 // 3 : 자재코드
            MAT_DESC,               // 4 : 자재명
            QTY,                    // 5 : 총소요량
            UNIT,                   // 6 : 단위
            LOT_TYPE,               // 7 : LOT 타입
            INPUT_TYPE,             // 8 : 투입 방식
            INPUT_TYPE_SELECT,       // 9 : 투입 방식 선택
            VENDOR_DESC
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
                pnlGCM.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                pnlGCM2.Anchor = AnchorStyles.Top | AnchorStyles.Left;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
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

                if (TPDR.GetDataOne("", ref dt, "CWIP2002-001", dvcArgu, false, false, ref sSql) == false)
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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORDER_ID";
                dvcArgu[1].sCondition_Value = sOrder_id;

                if (TPDR.GetDataOne("", ref dt, "CWIP2002-002", dvcArgu, false, false, ref sSql) == false)
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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;

                if(bDeleteWipLot == false)
                    sViewID = "CWIP2002-003";
                else
                    sViewID = "CWIP2002-005";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvWarehouse.Text;

                //dvcArgu[2].sCondition_ID = "ORDER_ID";
                //dvcArgu[2].sCondition_Value = cdvOrder.Text;

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
                    spdMatList_Sheet1.Cells[i, (int)STOCK.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.QTY].Value = dt.Rows[i]["QTY"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                }

                MPCF.FitColumnHeader(spdMatList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //투입리스트 조회 함수
        private void ViewInputList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                dvcArgu[2].sCondition_ID = "ORDER_ID";
                dvcArgu[2].sCondition_Value = cdvOrder.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2002-004", dvcArgu, false, false, ref sSql) == false)
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
                    spdInputList_Sheet1.Cells[i, (int)INPUT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.QTY].Value = dt.Rows[i]["QTY"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.INPUT_TYPE].Value = dt.Rows[i]["INPUT_TYPE"];
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

            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '2';
                in_node.AddString("LOT_ID", txtLotID.Text);
                in_node.AddString("OPER", cdvOper.Text);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_Info", in_node, ref out_node) == false)
                {
                    return;
                }
                for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                {
                    //lot 정보가 이미 있는경우 넘어간다.
                    sLotId = out_node.GetList("LOT_TBL")[i].GetString("LOT_ID");
                    for (int k = 0; k < spdInputList.ActiveSheet.RowCount; k++)
                    {
                        if (sLotId == spdInputList.ActiveSheet.Cells[k, (int)INPUT.LOT_ID].Text)
                        {
                            continue;
                        }
                    }

                    for (int j = spdMatList.ActiveSheet.RowCount; j > 0; j--)
                    {
                        if (spdMatList.ActiveSheet.Cells[j - 1, (int)STOCK.LOT_ID].Text == sLotId)
                        {
                            spdMatList.ActiveSheet.RemoveRows(j - 1, 1);
                        }
                    }

                    iRow = spdInputList.ActiveSheet.RowCount;

                    spdInputList.ActiveSheet.RowCount++;
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.CHK, true);
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.VENDOR_LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("VENDOR_LOT_ID"));  //고객사LOT 추가 24/3/14
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.VENDOR_DESC, out_node.GetList("LOT_TBL")[i].GetString("VENDOR_DESC"));  //고객사LOT 추가 24/3/14
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.MAT_ID, out_node.GetList("LOT_TBL")[i].GetString("MAT_ID"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.MAT_DESC, out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.UNIT, out_node.GetList("LOT_TBL")[i].GetString("UNIT_1"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.LOT_TYPE, out_node.GetList("LOT_TBL")[i].GetString("LOT_TYPE"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_TYPE, CSGC.CP_MAT_INPUT_TYPE_BOM);
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

                if (TPDR.GetDataOne("", ref dt, "CWIP2002-006", dvcArgu, false, false, ref sSql) == false)
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

        //자재 투입처리 함수
        private bool InputMat()
        {
            TRSNode in_node = new TRSNode("input_In");
            TRSNode out_node = new TRSNode("input_Out");
            TRSNode input_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("OUT_OPER", cdvWarehouse.Text);
                in_node.AddString("ORDER_ID", cdvOrder.Text);
                in_node.AddString("RES_ID", cdvResource.Text);

                for (int i = 0; i < spdInputList.ActiveSheet.RowCount; i++)
                {
                    input_list = in_node.AddNode("LIST_TBL");
                    input_list.AddString("LOT_ID", spdInputList.ActiveSheet.Cells[i, (int)INPUT.LOT_ID].Text);
                    input_list.AddString("MAT_ID", spdInputList.ActiveSheet.Cells[i, (int)INPUT.MAT_ID].Text);
                    input_list.AddDouble("QTY", spdInputList.ActiveSheet.Cells[i, (int)INPUT.QTY].Text);
                    input_list.AddString("LOT_TYPE", spdInputList.ActiveSheet.Cells[i, (int)INPUT.LOT_TYPE].Text);
                    input_list.AddString("INPUT_TYPE", spdInputList.ActiveSheet.Cells[i, (int)INPUT.INPUT_TYPE].Text);
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
            int iCount = 0;

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

                if (MPCF.Trim(cdvOrder.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOrder.Text + "]");
                    cdvOrder.Focus();
                    return false;
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

                        for (int i = 0; i < spdInputList.ActiveSheet.RowCount; i++)
                        {
                            if(spdInputList.ActiveSheet.Cells[i, (int)INPUT.CHK].Value.ToString().ToUpper() == "TRUE")
                                iCount++;
                        }

                        //if (iCount == 0)
                        //{
                        //    //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(305));
                        //    return false;
                        //}

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

        private void frmTranInputMaterials_Load(object sender, EventArgs e)
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
                cdvResource.Text = sRes_id;
                cdvResource.DisplayText = sRes_desc;

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

                if (COM_LIST.ViewOperationList(cdvWarehouse.GetListView, '1', cdvDept.Text, cdvWorkPlace.Text,"","",'Y') == false)
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
        //로직 넣을 것.
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

                //spdInputList.ActiveSheet.SetValue(spdInputList.ActiveSheet.ActiveRowIndex, (int)INPUT.CHK, true);
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

            try
            {
                for (int i = spdMatList.ActiveSheet.RowCount ; i > 0 ; i--)
                {
                    if (spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        sTmp = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.LOT_ID].Text;

                        for (int k = 0; k < spdInputList.ActiveSheet.RowCount; k++)
                        {
                            if (spdInputList.ActiveSheet.Cells[k, (int)INPUT.LOT_ID].Text == sTmp)
                                continue;
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
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.LOT_TYPE].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.LOT_TYPE].Text;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.INPUT_TYPE].Value = CSGC.CP_MAT_INPUT_TYPE_BOM;
                        spdMatList.ActiveSheet.RemoveRows(i - 1, 1);
                    }
                }
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

            try
            {
                if (MPCF.Trim(cdvWarehouse.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWarehouse.Text + "]");
                    cdvWarehouse.Focus();
                    return;
                }

                for (int i = spdInputList.ActiveSheet.RowCount ; i > 0; i--)
                {
                    if (spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        sTmp = spdInputList.ActiveSheet.Cells[i - 1, (int)INPUT.LOT_ID].Text;

                        for (int k = 0; k < spdMatList.ActiveSheet.RowCount; k++)
                        {
                            if (spdMatList.ActiveSheet.Cells[k, (int)STOCK.LOT_ID].Text == sTmp)
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

                ViewOrder();
                ViewBom(cdvOrder.Text);

                if (MPCF.Trim(cdvWarehouse.Text) != "")
                {
                    ViewMatList();
                }
                else
                {
                    MPCF.ClearList(spdMatList);
                }

                ViewInputList();
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
                    btnMatView.PerformClick();
                    ViewInputList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
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
                    popup.sTable_name_desc = "Automatic input items by process";
                    popup.sComment = "해당화면에 설정된 품목은 해당 창고에 이동시 자동으로 공정투입예정품목으로 등록됩니다.";

                }
                else
                {
                    popup.sTable_name_desc = "Default WeareWhouse";
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


        #endregion

    }
}
