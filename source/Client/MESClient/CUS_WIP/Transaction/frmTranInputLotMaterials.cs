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
    public partial class frmTranInputLotMaterials : CUS_COM.frmTranForm01
    {
        public frmTranInputLotMaterials()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

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
            CREATE_CODE,
            CREATE_CODE_DESC,
            LOT_DESC
        }

        private enum INPUT
        {
            CHK,                    // 1 : 공정명
            MAT_ID,                 // 3 : 자재코드
            MAT_DESC,               // 4 : 자재명
            QTY,                    // 5 : 총소요량            
            INPUT_QTY,              // 7 : 투입 수량
            UNIT,                   // 6 : 단위
            UNIT_QTY,               // 8 : 단위 수량
            LOT_ID,                 // 2 : LOT ID
            VENDOR_LOT_ID,
            VENDOR_DESC,
            LOT_TYPE,               // 9 : LOT 타입
            INPUT_TYPE,
            REL_LEVEL,
            OUT_OPER,
            CREATE_CODE,
            CREATE_CODE_DESC,
            LOT_DESC
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
        public string sLot_id = "";
        public double sLot_Qty = 0;
        public bool bOsp_YN = false;
        public bool bAddNonInput = false;
        public string sLoadYn = "Y";

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
                lblGCM.Anchor = AnchorStyles.Top | AnchorStyles.Left;
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

                if (TPDR.GetDataOne("", ref dt, "CWIP2024-001", dvcArgu, false, false, ref sSql) == false)
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
                
                sViewID = "CWIP2024-002";

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
                    spdMatList_Sheet1.Cells[i, (int)STOCK.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.QTY].Value = dt.Rows[i]["QTY"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.OUT_OPER].Value = dt.Rows[i]["OPER"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.CREATE_CODE_DESC].Value = dt.Rows[i]["CREATE_CODE_DESC"];
                    spdMatList_Sheet1.Cells[i, (int)STOCK.LOT_DESC].Value = dt.Rows[i]["LOT_DESC"];                    
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
            int i = 0;
            double dInputQty = 0;
            double dLotQty = 0;
            string sTmpMat = "";
            string sViewID = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                dvcArgu[2].sCondition_ID = "LOT_ID";
                dvcArgu[2].sCondition_Value = txtProdLotID.Text;

                if (CheckInputYN() == false)
                {
                    sViewID = "CWIP2024-003";
                }
                else
                {
                    sViewID = "CWIP2024-005";
                }

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInputList);
                    return;
                }

                MPCF.ClearList(spdInputList);

                dLotQty = MPCF.ToDbl(txtLotQty.Text);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdInputList_Sheet1.RowCount++;

                    spdInputList_Sheet1.SetValue(i, (int)INPUT.CHK, false);
                    spdInputList_Sheet1.Cells[i, (int)INPUT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.QTY].Value = dt.Rows[i]["QTY"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.UNIT_QTY].Value = dt.Rows[i]["UNIT_QTY"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.INPUT_TYPE].Value = dt.Rows[i]["INPUT_TYPE"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.REL_LEVEL].Value = dt.Rows[i]["REL_LEVEL"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.OUT_OPER].Value = dt.Rows[i]["OPER"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.CREATE_CODE_DESC].Value = dt.Rows[i]["CREATE_CODE_DESC"];
                    spdInputList_Sheet1.Cells[i, (int)INPUT.LOT_DESC].Value = dt.Rows[i]["LOT_DESC"];

                    if (sTmpMat != dt.Rows[i]["MAT_ID"].ToString())
                    {
                        sTmpMat = dt.Rows[i]["MAT_ID"].ToString();
                        dInputQty = dLotQty * MPCF.ToDbl(dt.Rows[i]["UNIT_QTY"]);
                    }

                    if (dt.Rows[i]["REL_LEVEL"].ToString() == "1")
                        spdInputList_Sheet1.Cells[i, (int)INPUT.INPUT_QTY].Value = dt.Rows[i]["INPUT_QTY"];
                    else
                    {
                        if (dInputQty > MPCF.ToDbl(dt.Rows[i]["QTY"]))
                        {
                            spdInputList_Sheet1.Cells[i, (int)INPUT.INPUT_QTY].Value = dt.Rows[i]["QTY"];
                            dInputQty = dInputQty - MPCF.ToDbl(dt.Rows[i]["QTY"]);
                        }
                        else
                        {
                            spdInputList_Sheet1.Cells[i, (int)INPUT.INPUT_QTY].Value = dInputQty;
                            dInputQty = 0;
                        }
                    }                    
                }

                MPCF.FitColumnHeader(spdInputList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CheckInputYN()
        {
            bool bReturn = false;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                dvcArgu[2].sCondition_ID = "LOT_ID";
                dvcArgu[2].sCondition_Value = txtProdLotID.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2024-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }

                if (dt.Rows.Count > 0)
                {
                    if(MPCF.ToInt(dt.Rows[0]["INPUT_COUNT"].ToString()) > 0)
                        bReturn = true;
                    else
                        bReturn = false;
                }
               
                return bReturn;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void CheckCommentTrans()
        {

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;


                if (TPDR.GetDataOne("", ref dt, "CWIP2024-008", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt.Rows.Count > 0)
                {
                    if (MPCF.ToInt(dt.Rows[0]["OPER_COUNT"].ToString()) > 0)
                        chkWipRemark.Checked = true;
                    else
                        chkWipRemark.Checked = false;
                }

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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = txtProdLotID.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2024-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }

                if(dt.Rows.Count > 0)
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

        //LOT ID / Kitting ID 조회 함수
        private void ViewLotInfo()
        {
            int iRow = 0;
            string sLotId = "";
            double dUnitQty = 0;
            string sMatTmp = "";
            bool bBom = false;

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
                    bBom = false;

                    //lot 정보가 이미 있는경우 넘어간다.
                    sLotId = out_node.GetList("LOT_TBL")[i].GetString("LOT_ID");
                    sMatTmp = out_node.GetList("LOT_TBL")[i].GetString("MAT_ID");

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

                    for (int j = 0; j < spdBom.ActiveSheet.RowCount; j++)
                    {
                        if (spdBom.ActiveSheet.Cells[j, (int)BOM.MAT_ID].Text == sMatTmp)
                        {
                            dUnitQty = MPCF.ToDbl(spdBom.ActiveSheet.Cells[j, (int)BOM.UNIT_QTY].Text);
                            bBom = true;
                        }
                    }

                    if (bBom == false)
                    {
                        //CMN507 INFO - BOM 상에 있는 자재가 아닙니다. 정말 투입하시겠습니까?
                        if (MPCF.ShowMsgBox(MPCF.GetMessage(507) + "[ " + sMatTmp + " ]", MessageBoxButtons.YesNo, 1) == DialogResult.No)
                        {
                            return;
                        }
                    }

                    iRow = spdInputList.ActiveSheet.RowCount;

                    spdInputList.ActiveSheet.RowCount++;
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.CHK, true);
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.VENDOR_LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("VENDOR_LOT_ID"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.VENDOR_DESC, out_node.GetList("LOT_TBL")[i].GetString("VENDOR_DESC"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.MAT_ID, out_node.GetList("LOT_TBL")[i].GetString("MAT_ID"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.MAT_DESC, out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.UNIT, out_node.GetList("LOT_TBL")[i].GetString("UNIT_1"));
                    //spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));

                    if (dUnitQty != 0)
                    {
                        //CTV 절단공정 투입소재 소요량 기준정보가 0.9996 이렇게 나옴,이거 정상 1개투입되어야되는게 맞아서,(화면에서 계쏙바꿔줘야 되는 번거러움 떄문에 해당공정은 일단 Default1이 되도록 수정(20240311)
                        if (cdvOper.Text == "OC06010" && Math.Round(dUnitQty) != 1)
                        {
                            spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.INPUT_QTY].Value = out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1");
                        }
                        else
                        {
                            if (out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1") > dUnitQty * MPCF.ToDbl(txtLotQty.Text))
                                spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.INPUT_QTY].Value = dUnitQty * MPCF.ToDbl(txtLotQty.Text);
                            else
                                spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.INPUT_QTY].Value = out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1");
                        }

                    }
                    else
                    {
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.INPUT_QTY].Value = out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1");                        
                    }

                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.UNIT_QTY, dUnitQty);

                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.LOT_TYPE, out_node.GetList("LOT_TBL")[i].GetString("LOT_TYPE"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.INPUT_TYPE, CSGC.CP_MAT_INPUT_TYPE_LOT);
                    spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.REL_LEVEL].Value = "1";
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.OUT_OPER, out_node.GetList("LOT_TBL")[i].GetString("OPER"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.LOT_DESC, out_node.GetList("LOT_TBL")[i].GetString("LAST_COMMENT"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.CREATE_CODE, out_node.GetList("LOT_TBL")[i].GetString("CREATE_CODE"));
                    spdInputList.ActiveSheet.SetValue(iRow, (int)INPUT.CREATE_CODE_DESC, out_node.GetList("LOT_TBL")[i].GetString("CREATE_CODE_DESC"));
                }

                MPCF.FitColumnHeader(spdInputList);

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
            double dQty = 0;

            try
            {
                MPCR.SetInMsg(in_node);

                //일반 자재 투입인 경우 step 4 , 자재 미투입 화면인 경우 step 5 
                if (bAddNonInput == false)
                    in_node.ProcStep = '4';
                else
                    in_node.ProcStep = '5';

                in_node.AddString("ORDER_ID", cdvOrder.Text);
                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("OUT_OPER", cdvWarehouse.Text);
                in_node.AddString("LOT_ID", txtProdLotID.Text);
                in_node.AddChar("REL_LEVEL", '1');


                if (chkWipRemark.Checked)
                {
                    in_node.AddChar("COMMENT_WIP", 'Y');
                }


                for (int i = 0; i < spdInputList.ActiveSheet.RowCount; i++)
                {
                    dQty = MPCF.ToDbl(spdInputList.ActiveSheet.Cells[i, (int)INPUT.INPUT_QTY].Text);

                    if (dQty == 0)
                        continue;

                    input_list = in_node.AddNode("LIST_TBL");
                    input_list.AddString("LOT_ID", spdInputList.ActiveSheet.Cells[i, (int)INPUT.LOT_ID].Text);
                    input_list.AddString("MAT_ID", spdInputList.ActiveSheet.Cells[i, (int)INPUT.MAT_ID].Text);
                    //input_list.AddDouble("QTY", MPCF.ToDbl(spdInputList.ActiveSheet.Cells[i, (int)INPUT.QTY].Text));
                    input_list.AddString("LOT_TYPE", spdInputList.ActiveSheet.Cells[i, (int)INPUT.LOT_TYPE].Text);
                    input_list.AddDouble("QTY", MPCF.ToDbl(spdInputList.ActiveSheet.Cells[i, (int)INPUT.INPUT_QTY].Text));
                    input_list.AddDouble("BOM_QTY", MPCF.ToDbl(spdInputList.ActiveSheet.Cells[i, (int)INPUT.UNIT_QTY].Text));
                    input_list.AddString("INPUT_TYPE", CSGC.CP_MAT_INPUT_TYPE_LOT);
                    input_list.AddString("OUT_OPER", spdInputList.ActiveSheet.Cells[i, (int)INPUT.OUT_OPER].Text);
                    input_list.AddString("COMMENT", spdInputList.ActiveSheet.Cells[i, (int)INPUT.LOT_DESC].Text);

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

                if (MPCF.Trim(txtProdLotID.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblProdLotID.Text + "]");
                    txtProdLotID.Focus();
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

        //BOM 수량과 비교 2개공정만 : OG07110(Sputter-세척), OG07210(MVD-혼합) 
        private bool CheckBomQty()
        {
            string sBomMat = ""; 
            double dBomQty = 0;            

            try
            { 
                for (int i = 0; i < spdBom.ActiveSheet.RowCount; i++)
                {
                    double dInputQty = 0;
                    sBomMat = MPCF.Trim(spdBom.ActiveSheet.Cells[i, (int)BOM.MAT_ID].Text);
                    dBomQty = MPCF.ToDbl(spdBom.ActiveSheet.Cells[i, (int)BOM.TOTAL_QTY].Text);
                    
                    for (int j = 0; j < spdInputList.ActiveSheet.RowCount; j++)
                    {                        
                        if (MPCF.Trim(spdInputList.ActiveSheet.Cells[j, (int)INPUT.MAT_ID].Text) == sBomMat)
                        {
                            dInputQty = dInputQty + MPCF.ToDbl(spdInputList.ActiveSheet.Cells[j, (int)INPUT.INPUT_QTY].Value);
                        }                            
                    }
                    
                    //if(dBomQty <> dInputQty) 
                    if(dBomQty != dInputQty)
                    {
                        //CMN624 ERROR - 투입 수량과 BOM 수량이 일치하지 않습니다. 투입수량을 확인하십시오. 
                        //MPCF.ShowMsgBox(MPCF.GetMessage(108) + " BOM 수량 [" + dBomQty + "], 투입 수량 [" + dInputQty + "]");
                        return false; 
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

        #endregion

        #region " Event Definition "

        private void frmTranInputLotMaterials_Load(object sender, EventArgs e)
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
                txtProdLotID.Text = sLot_id;
                txtLotQty.Text = sLot_Qty.ToString();

                if(bOsp_YN == false)
                    fnGetWarehouse();

                if (bAddNonInput == true)
                {

                    lblFormName.Text = MPCF.FindLanguage("Not Input Material Add", CAPTION_TYPE.LABEL);
                    btnProcess.Text = MPCF.FindLanguage("Confirm", CAPTION_TYPE.BUTTON);
                }

                btnView.PerformClick();

                CheckCommentTrans();
                sLoadYn = "N";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOrder_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }

                CUS_COM.Popup.frmPopWorkOrderList popup = new CUS_COM.Popup.frmPopWorkOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_AreaCode = cdvDept.Text;
                popup.g_AreaDesc = cdvDept.DisplayText;
                popup.g_SubAreaCode = cdvWorkPlace.Text;
                popup.g_SubAreaDesc = cdvWorkPlace.DisplayText;
                popup.g_OperCode = cdvOper.Text;
                popup.g_OperDesc = cdvOper.DisplayText;
                popup.g_WorkOrder = cdvOrder.Text;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvOrder.Text = popup.g_WorkOrder;
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

                if (bOsp_YN == false)
                {
                    if (COM_LIST.ViewOperationList(cdvWarehouse.GetListView, '1', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
                    {
                        return;
                    }
                }
                else
                {
                    //외주 공정인 경우 외주 창고만 보여주기 위해
                    if (COM_LIST.ViewOperationList(cdvWarehouse.GetListView, 'S', cdvDept.Text) == false)
                    {
                        return;
                    }
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

        private void spdInputList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            //double d_InputQty = 0;
            //double d_UnitQty = 0;
            //double d_LotQty = 0;

            try
            {
                if (e.Column == (int)INPUT.INPUT_QTY)
                {
                    //d_LotQty = MPCF.ToDbl(txtLotQty.Text);
                    //d_InputQty = MPCF.ToDbl(spdInputList.ActiveSheet.Cells[e.Row, e.Column].Text);
                    //d_UnitQty = Math.Round(d_InputQty / d_LotQty, 5);
                    //spdInputList.ActiveSheet.SetValue(e.Row, (int)INPUT.UNIT_QTY, d_UnitQty);
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
            double dQty = 0;
            string sMatTmp = "";
            bool bBom = false;

            try
            {
                for (int i = spdMatList.ActiveSheet.RowCount ; i > 0 ; i--)
                {
                    dUnitQty = 0;
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
                                bBom = true;
                            }
                        }

                        if (bBom == false)
                        {
                            //CMN507 INFO - BOM 상에 있는 자재가 아닙니다. 정말 투입하시겠습니까?
                            if (MPCF.ShowMsgBox(MPCF.GetMessage(507) + "[ " + sMatTmp + " ]", MessageBoxButtons.YesNo, 1) == DialogResult.No)
                            {
                                return;
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
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.OUT_OPER].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.OUT_OPER].Text;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.CREATE_CODE].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.CREATE_CODE].Text;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.CREATE_CODE_DESC].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.CREATE_CODE_DESC].Text;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.LOT_DESC].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.LOT_DESC].Text;





                        if (dUnitQty != 0)
                        {
                            dQty = MPCF.ToDbl(spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.QTY].Value);


                            //CTV 절단공정 투입소재 소요량 기준정보가 0.9996 이렇게 나옴,이거 정상 1개투입되어야되는게 맞아서,(화면에서 계쏙바꿔줘야 되는 번거러움 떄문에 해당공정은 일단 Default1이 되도록 수정(20240311)
                            if (cdvOper.Text == "OC06010" && Math.Round(dUnitQty) != 1)
                            {
                                spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.INPUT_QTY].Value = dQty;
                            }
                            else
                            {
                                if (dQty >= dUnitQty * MPCF.ToDbl(txtLotQty.Text))
                                {
                                    spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.INPUT_QTY].Value = dUnitQty * MPCF.ToDbl(txtLotQty.Text);
                                }
                                else
                                {
                                    spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.INPUT_QTY].Value = dQty;
                                }
                            }



                            spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.UNIT_QTY].Value = dUnitQty;
                        }
                        else
                        {
                            spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.INPUT_QTY].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.QTY].Value;
                            //spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.UNIT_QTY].Value = MPCF.ToDbl(spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.QTY].Value) / MPCF.ToDbl(txtLotQty.Text);
                            spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.UNIT_QTY].Value = dUnitQty;
                        }

                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.LOT_TYPE].Value = spdMatList.ActiveSheet.Cells[i - 1, (int)STOCK.LOT_TYPE].Text;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.INPUT_TYPE].Value = CSGC.CP_MAT_INPUT_TYPE_LOT;
                        spdInputList.ActiveSheet.Cells[iRow, (int)INPUT.REL_LEVEL].Value = "1";

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

                        bCheck = false;
                    }
                }

                spdMatList.ActiveSheet.SortRows((int)STOCK.LOT_ID, true, false);
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

                // GRIT팀 요청건 2개공정인 경우 OG07110(Sputter-세척), OG07210(MVD - 혼합) BOM 소수점까지 모두 체크하여 다를 경우 메세지
                if (cdvOper.Text == "OG07110" || cdvOper.Text == "OG07210")
                {
                    if (CheckBomQty() == false) 
                    {
                        //CMN624 ERROR - 투입 수량과 BOM 수량이 일치하지 않습니다. 투입수량을 확인하십시오. 
                        if (MPCF.ShowMsgBox(MPCF.GetMessage(624), MessageBoxButtons.YesNo, 2) == DialogResult.No)
                        {
                            MPCF.ClearList(spdInputList);
                            return;
                        } 
                    }
                }

                if (InputMat())
                {
                    if (bOsp_YN == false)
                    {
                        btnMatView.PerformClick();
                    }

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

        private void chkWipRemark_CheckedChanged(object sender, EventArgs e)
        {
            string ssql = "";

            try
            {

                if (sLoadYn != "Y")
                {

                    if (chkWipRemark.Checked == true)
                    {
                        ssql = "UPDATE MWIPOPRDEF SET OPER_CMF_11 ='Y' WHERE FACTORY = '" + MPGV.gsFactory + "' AND OPER = '" + cdvOper.Text + "'";
                    }
                    else
                    {
                        ssql = "UPDATE MWIPOPRDEF SET OPER_CMF_11 =' ' WHERE FACTORY = '" + MPGV.gsFactory + "' AND OPER = '" + cdvOper.Text + "'";
                    }

                    TRSNode in_node = new TRSNode("TRAN_IN");
                    TRSNode out_node = new TRSNode("TRAN_OUT");

                    MPCR.SetInMsg(in_node);

                    in_node.ProcStep = '1';
                    in_node.AddString("SQL", ssql);


                    if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                    {
                        return;
                    }

                }
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
