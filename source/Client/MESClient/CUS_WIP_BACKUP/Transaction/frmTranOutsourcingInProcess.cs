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

//CWIP2016
namespace CUS_WIP
{
    public partial class frmTranOutsourcingInProcess : CUS_COM.frmViewForm01
    {
        public frmTranOutsourcingInProcess()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum PO_INFO
        {   
            PO_NO,                  // 1 : po 번호
            PO_QTY,                 // 2 : po 수량
            PO_REMAIN_QTY,          // 3 : po 잔량
            ORDER_ID,               // 4 : 작업지시
            MAT_ID,                 // 5 : 제품코드
            MAT_DESC,               // 6 : 제품명
            UNIT,                   // 7 : 단위
            VENDOR,                 // 8 : 협력사코드
            VENDOR_DESC             // 9 : 협력사 
        }

        private enum LOT_INFO
        {
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 제품코드
            MAT_DESC,               // 4 : 제품명      
            QTY_1,                  // 5 : 출고수량      
            PROD_QTY,               // 5 : 입고수량    
            GOOD_QTY,               // 6 : 양품수량
            BAD_QTY,                // 7 : 불량 
            START_TIME              // 9 : 출고시간
        }

        private enum IN_INFO
        {
            CHK,                    // 1 : CHECK
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 제품코드
            MAT_DESC,               // 4 : 제품명      
            IN_QTY                  // 5 : 입고수량    
        }

        private enum LOSS_INFO
        {
            LOSS_CODE,              // 1 : 불량코드
            LOSS_DESC,              // 2 : 불량명
            LOSS_QTY                // 3 : 불량수량
        }


        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnIn.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnLotData.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //외주 작업장 조회
        public static bool ViewSubArea_Outsourcing(Control control, string sArea_id)
        {
            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea_id;

                if (TPDR.GetDataOne("", ref dt, "CWIP2016-001", dvcArgu, false, false, ref sSql) == false)
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
        
        //Loss정보 조회 함수
        private void ViewLossList(string sLotID)
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

                dvcArgu[2].sCondition_ID = "LOT_ID";
                dvcArgu[2].sCondition_Value = sLotID;

                if (TPDR.GetDataOne("", ref dt, "CWIP2016-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLossList);
                    return;
                }

                MPCF.ClearList(spdLossList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLossList_Sheet1.RowCount++;

                    spdLossList_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_CODE].Value = dt.Rows[i]["LOSS_CODE"];
                    spdLossList_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_DESC].Value = dt.Rows[i]["LOSS_DESC"];
                    spdLossList_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_QTY].Value = dt.Rows[i]["LOSS_QTY"];

                }
                MPCF.FitColumnHeader(spdLossList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //불량정보 저장
        private bool SaveLossData()
        {
            try
            {
                TRSNode in_node = new TRSNode("loss_Code_In");
                TRSNode out_node = new TRSNode("loss_Code_Out");
                TRSNode loss_list;

                double d_loss_qty = 0;
                double d_prod_qty = 0;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text);
                //in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("CUASE_OPER", cdvCauseOper.Text);
                //in_node.AddString("RES_ID", cdvResource.Text);

                for (int i = 0; i < spdLossList.ActiveSheet.RowCount; i++)
                {
                    if (MPCF.ToDbl(spdLossList.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_QTY].Text) != 0)
                    {
                        loss_list = in_node.AddNode("LOSS_TBL");
                        loss_list.AddString("CODE", spdLossList.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_CODE].Text);
                        loss_list.AddDouble("VALUE", spdLossList.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_QTY].Text);
                        loss_list.AddChar("QTY_FLAG", '1');

                        d_loss_qty += MPCF.ToDbl(spdLossList.ActiveSheet.Cells[i, (int)LOSS_INFO.LOSS_QTY].Value);
                    }
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Update_Lot_Loss", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                d_prod_qty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.PROD_QTY].Value);

                spdLotList.ActiveSheet.SetValue(spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.BAD_QTY, d_loss_qty);
                spdLotList.ActiveSheet.SetValue(spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.GOOD_QTY, d_prod_qty - d_loss_qty);

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //PO정보 조회 함수
        private void ViewPOList()
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

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[3].sCondition_ID = "ORDER_ID";
                dvcArgu[3].sCondition_Value = cdvOrder.Text + "%";

                dvcArgu[4].sCondition_ID = "VENDOR_ID";
                dvcArgu[4].sCondition_Value = cdvVendor.Text + "%";

                dvcArgu[5].sCondition_ID = "MAT_ID";
                dvcArgu[5].sCondition_Value = cdvMatid.Text + "%";

                dvcArgu[6].sCondition_ID = "PO_NO";
                dvcArgu[6].sCondition_Value = txtPo.Text + "%";

                if (TPDR.GetDataOne("", ref dt, "CWIP2016-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdPoInfo);
                    return;
                }

                MPCF.ClearList(spdPoInfo);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdPoInfo.ActiveSheet.RowCount++;

                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.PO_NO].Value = dt.Rows[i]["PO_NO"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.PO_QTY].Value = dt.Rows[i]["PO_QTY"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.PO_REMAIN_QTY].Value = dt.Rows[i]["PO_REMAIN_QTY"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.VENDOR].Value = dt.Rows[i]["VENDOR_ID"];
                    spdPoInfo.ActiveSheet.Cells[i, (int)PO_INFO.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];                   
                }
                MPCF.FitColumnHeader(spdPoInfo);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //lot 정보 조회함수
        private void ViewLotList(string sOrder_id)
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

                if (TPDR.GetDataOne("", ref dt, "CWIP2016-005", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLotList);
                    return;
                }

                MPCF.ClearList(spdLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Sheet1.RowCount++;
              
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.QTY_1].Value = dt.Rows[i]["QTY_1"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.PROD_QTY].Value = dt.Rows[i]["PROD_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.GOOD_QTY].Value = dt.Rows[i]["GOOD_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.BAD_QTY].Value = dt.Rows[i]["BAD_QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.START_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["START_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                }
                MPCF.FitColumnHeader(spdLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewInLotList(string sLotID)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = sLotID;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2016-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInLotList);
                    return;
                }

                MPCF.ClearList(spdInLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdInLotList.ActiveSheet.RowCount++;

                    spdInLotList.ActiveSheet.SetValue(i, (int)IN_INFO.CHK, false);
                    spdInLotList.ActiveSheet.Cells[i, (int)IN_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdInLotList.ActiveSheet.Cells[i, (int)IN_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdInLotList.ActiveSheet.Cells[i, (int)IN_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdInLotList.ActiveSheet.Cells[i, (int)IN_INFO.IN_QTY].Value = dt.Rows[i]["QTY_1"];

                    if (spdInLotList.ActiveSheet.Cells[i, (int)IN_INFO.LOT_ID].Text != "")
                        spdInLotList.ActiveSheet.Cells[i, (int)IN_INFO.CHK].Locked = true;
                }
                MPCF.FitColumnHeader(spdInLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //작업 시작/종료 = > step 1 : 외주 출고 , step 2 : 외주입고
        private bool SaveProcess(char c_step)
        {  
            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                TRSNode Lot_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = c_step;

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("ORDER_ID", spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Text);
                in_node.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text);

                for (int i = 0; i < spdInLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdInLotList.ActiveSheet.Cells[i, (int)IN_INFO.CHK].Value.ToString().ToUpper() == "TRUE" &&
                        MPCF.Trim(spdInLotList.ActiveSheet.Cells[i, (int)IN_INFO.LOT_ID].Text) == "")
                    {
                        Lot_list = in_node.AddNode("LOT_TBL");
                        Lot_list.AddString("LOT_ID", spdInLotList.ActiveSheet.Cells[i, (int)IN_INFO.LOT_ID].Text);
                        Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdInLotList.ActiveSheet.Cells[i, (int)IN_INFO.IN_QTY].Text));
                    }
                }
                
                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Outsourcing_Process", in_node, ref out_node) == false)
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

        //lot 추가 삭제시 선택 lot의 수량을 조정 해 준다.
        private void CalLotQty()
        {
            double dLotQty = 0;
            double dLotLossQty = 0;
            double dSumSplitLotQty = 0;

            try
            {
                dLotQty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.QTY_1].Text);
                //dLotLossQty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.BAD_QTY].Text);

                for (int j = 0; j < spdLossList.ActiveSheet.RowCount; j++)
                {
                    dLotLossQty = dLotLossQty + MPCF.ToDbl(spdLossList.ActiveSheet.Cells[j, (int)LOSS_INFO.LOSS_QTY].Text);                    
                }

                for (int i = 0; i < spdInLotList.ActiveSheet.RowCount; i++)
                {
                    if (MPCF.Trim(spdInLotList.ActiveSheet.Cells[i, (int)IN_INFO.LOT_ID].Text) == "")
                    {
                        dSumSplitLotQty = dSumSplitLotQty + MPCF.ToDbl(spdInLotList.ActiveSheet.Cells[i, (int)IN_INFO.IN_QTY].Text);
                    }
                }

                spdLotList.ActiveSheet.SetValue(spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.PROD_QTY, dLotQty - dLotLossQty - dSumSplitLotQty);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        //벨리데이션 체크
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            int iLotCount = 0;

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

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:


                        break;

                    case CSGC.CHECK.END:

                        //lot 체크
                        if (MPCF.Trim(cdvOrder.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOrder.Text + "]");
                            cdvOrder.Focus();
                            return false;
                        }

                        for (int i = 0; i < spdInLotList.ActiveSheet.RowCount; i++)
                        {
                            if (spdInLotList.ActiveSheet.Cells[i, (int)IN_INFO.CHK].Value.ToString().ToUpper() == "TRUE" &&
                                MPCF.Trim(spdInLotList.ActiveSheet.Cells[i, (int)IN_INFO.LOT_ID].Text) == ""
                                )
                            {

                                iLotCount++;
                            }
                        }

                        if (iLotCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + grpLotInfo.Text + "]");
                            return false;
                        }

                        break;

                    case CSGC.CHECK.SAVE:

                        if (MPCF.Trim(cdvCauseOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblCauseOper.Text + "]");
                            cdvCauseOper.Focus();
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

        //초기화
        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "OPER":

                        MPCF.ClearList(spdLossList);
                        MPCF.ClearList(spdPoInfo);
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdInLotList);

                        break;

                    case "LOSS":

                        MPCF.ClearList(spdLossList);

                        break;

                    case "VIEW":

                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdInLotList);

                        break;

                    case "END":

                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdInLotList);

                        break;

                    case "ALL":

                        cdvCauseOper.Text = "";
                        txtPo.Text = "";
                        cdvVendor.Text = "";
                        cdvMatid.Text = "";
                        cdvOrder.Text = "";

                        MPCF.ClearList(spdLossList);
                        MPCF.ClearList(spdPoInfo);
                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdInLotList);

                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmTranOutsourcingInProcess_Load(object sender, EventArgs e)
        {
            try
            {

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Init();
                MPCF.InitListView(cdvDept.GetListView);
                cdvDept.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvDept.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDept.SelectedSubItemIndex = 0;
                cdvDept.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDept.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                {
                    return;
                }
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
                cdvWorkPlace.Text = "";
                cdvOper.Text = "";

                MPCF.ClearList(spdPoInfo);
                MPCF.ClearList(spdLotList);
                MPCF.ClearList(spdLossList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkPlace_ButtonPress(object sender, EventArgs e)
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

                cdvWorkPlace.Init();
                MPCF.InitListView(cdvWorkPlace.GetListView);
                cdvWorkPlace.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWorkPlace.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWorkPlace.SelectedSubItemIndex = 0;
                cdvWorkPlace.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList_AREA(cdvWorkPlace.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, cdvDept.Text) == false)
                {
                    return;
                }

                cdvWorkPlace.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkPlace_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvOper.Text = "";

                MPCF.ClearList(spdPoInfo);
                MPCF.ClearList(spdLotList);
                MPCF.ClearList(spdLossList);
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

                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, 'E', cdvDept.Text, cdvWorkPlace.Text) == false)
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

        private void cdvOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                ClearData("OPER");

                if (MPCF.Trim(cdvOper.Text) != "")
                    ViewLossList("");

                cdvCauseOper.Text = cdvOper.Text;
                cdvCauseOper.DisplayText = cdvOper.DisplayText;               
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOper_TextBoxTextChanged(object sender, EventArgs e)
        {
            try
            {
                cdvCauseOper.Text = cdvOper.Text;
                cdvCauseOper.DisplayText = cdvOper.DisplayText;
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
                //popup.g_WorkOrder = cdvOrder.Text;

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

        private void cdvVendor_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopVendorList popup = new frmPopVendorList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvVendor.Text = popup.g_VendorId;
                    this.cdvVendor.DisplayText = popup.g_VendorDesc;
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
                    cdvMatid.Text = popup.sMat_id;
                    cdvMatid.DisplayText = popup.sMat_Desc;
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

        private void cdvCauseOper_ButtonPress(object sender, EventArgs e)
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

                cdvCauseOper.Init();
                MPCF.InitListView(cdvCauseOper.GetListView);
                cdvCauseOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvCauseOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvCauseOper.SelectedSubItemIndex = 0;
                cdvCauseOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvCauseOper.GetListView, '2', cdvDept.Text) == false)
                {
                    return;
                }

                cdvCauseOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdPoInfo_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            string sOrder_id = "";

            try
            {
                if (e.ColumnHeader)
                    return;

                for (int i = 0; i < spdPoInfo.ActiveSheet.RowCount; i++)
                {
                    spdPoInfo.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdPoInfo.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                sOrder_id = spdPoInfo.ActiveSheet.Cells[e.Row, (int)PO_INFO.ORDER_ID].Text;

                if (MPCF.Trim(sOrder_id) != "")
                {
                    ViewLotList(sOrder_id);
                    MPCF.ClearList(spdInLotList);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            string sLot_id = "";

            try
            {
                if (e.ColumnHeader)
                    return;

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    spdLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdLotList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                sLot_id = spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_INFO.LOT_ID].Text;

                if (MPCF.Trim(sLot_id) != "")
                {
                    ViewLossList(sLot_id);
                    ViewInLotList(sLot_id);
                }                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdInLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    CSCF.CheckSpreadCell(spdInLotList, 0, 0, true, true);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnLotData_Click(object sender, EventArgs e)
        {
            try
            {                
                frmTranInputLotData popup = new frmTranInputLotData();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.cdvDept.Text = cdvDept.Text;
                popup.cdvDept.DisplayText = cdvDept.DisplayText;
                popup.cdvWorkPlace.Text = cdvWorkPlace.Text;
                popup.cdvWorkPlace.DisplayText = cdvWorkPlace.DisplayText;
                popup.cdvOper.Text = cdvOper.Text;
                popup.cdvOper.DisplayText = cdvOper.DisplayText;
                popup.txtLotID.Text = spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text;

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

        private void btnLossSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SaveLossData())
                {

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            int iRow = 0;
            double dLotQty = 0; 
            try
            {
                if (MPCF.ToDbl(txtProdQty.Text) == 0)
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblProdQty.Text + "]");
                    txtProdQty.Focus();
                    return;
                }

                dLotQty = MPCF.ToDbl(spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.GOOD_QTY].Text);

                if (MPCF.ToDbl(txtProdQty.Text) > dLotQty)
                {
                    //CMN485 INFO - 출고수량보다 더 많은 입고 수량을 입력 할 수 없습니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(485) + " [" + lblProdQty.Text + "]");
                    txtProdQty.Focus();
                    return;
                }

                iRow = spdInLotList.ActiveSheet.RowCount;
                spdInLotList.ActiveSheet.RowCount++;

                spdInLotList.ActiveSheet.SetValue(iRow, (int)IN_INFO.CHK, true);
                spdInLotList.ActiveSheet.SetValue(iRow, (int)IN_INFO.LOT_ID, "");
                spdInLotList.ActiveSheet.SetValue(iRow, (int)IN_INFO.MAT_ID, spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.MAT_ID].Text);
                spdInLotList.ActiveSheet.SetValue(iRow, (int)IN_INFO.MAT_DESC, spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.MAT_DESC].Text);
                spdInLotList.ActiveSheet.SetValue(iRow, (int)IN_INFO.IN_QTY, MPCF.ToDbl(txtProdQty.Text));

                txtProdQty.Text = "";

                CalLotQty();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                for (int i = spdInLotList.ActiveSheet.RowCount; i > 0; i--)
                {
                    if (spdInLotList.ActiveSheet.Cells[i-1, (int)IN_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        spdInLotList.ActiveSheet.RemoveRows(i - 1, 1);
                    }
                }

                CalLotQty();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                ClearData("ALL");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ClearData("VIEW");

                ViewPOList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnIn_Click(object sender, EventArgs e)
        {
            string sOrder = "";
            string sLot_id = "";

            try
            {
                if (CheckCondition(CSGC.CHECK.END) == false)
                    return;

                sOrder = spdPoInfo.ActiveSheet.Cells[spdPoInfo.ActiveSheet.ActiveRowIndex, (int)PO_INFO.ORDER_ID].Text;
                sLot_id = spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text;

                if (SaveProcess('2'))
                {
                    ClearData("END");
                    ViewLotList(sOrder);
                    //ViewInLotList(sLot_id);
                    ViewLossList("");
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        #endregion


    }
}
