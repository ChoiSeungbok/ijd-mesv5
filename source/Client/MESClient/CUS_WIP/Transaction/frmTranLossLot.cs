using System;
using System.Data;
using System.Drawing;
using System.Windows.Forms;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

namespace CUS_WIP
{
    public partial class frmTranLossLot : CUS_COM.frmTranForm01
    {
        public frmTranLossLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOSS_INFO
        {
            LOSS_CODE,              // 1 : 불량코드
            LOSS_DESC,              // 2 : 불량명
            LOSS_QTY                // 3 : 불량수량
        }

        private enum LOT_INFO
        {
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 제품코드
            MAT_DESC,               // 4 : 제품명            
            CREATE_DATE,            //
            QTY,                    // 5 : 생산수량
            RES_ID,                 // 8 : 불량등록
            RES_DESC,               // 9 : 생성일자
            COMMENT                 //
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
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //조회조건으로 lot 리스트를 조회하는 함수
        private void ViewLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvOper.Text;

                dvcArgu[4].sCondition_ID = "ORDER_ID";
                dvcArgu[4].sCondition_Value = cdvOrder.Text + "%";

                if (TPDR.GetDataOne("", ref dt, "CWIP2004-001", dvcArgu, false, false, ref sSql) == false)
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
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.QTY].Value = dt.Rows[i]["QTY_1"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.COMMENT].Value = dt.Rows[i]["LAST_COMMENT"];
                }
                MPCF.FitColumnHeader(spdLotList);

                //첫번쨰 Row 자동 선택.
                spdLotList.ActiveSheet.ActiveRowIndex = 0;
                spdLotList.ActiveSheet.Rows[0].BackColor = Color.FromArgb(255, 192, 255);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //lot id로 lot정보 및 조회조건 정보를 찾아오는 함수
        private void ViewLotInfo()
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
                dvcArgu[1].sCondition_Value = txtLotID.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2004-003", dvcArgu, false, false, ref sSql) == false)
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
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.QTY].Value = dt.Rows[i]["QTY_1"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.RES_DESC].Value = dt.Rows[i]["RES_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.COMMENT].Value = dt.Rows[i]["LAST_COMMENT"];
                }

                MPCF.FitColumnHeader(spdLotList);

                cdvDept.Text = dt.Rows[0]["AREA_ID"].ToString();
                cdvDept.DisplayText = dt.Rows[0]["AREA_DESC"].ToString();
                cdvWorkPlace.Text = dt.Rows[0]["SUB_AREA_ID"].ToString();
                cdvWorkPlace.DisplayText = dt.Rows[0]["SUB_AREA_DESC"].ToString();
                cdvOper.Text = dt.Rows[0]["OPER"].ToString(); 
                cdvOper.DisplayText = dt.Rows[0]["OPER_DESC"].ToString();
                cdvOrder.Text = dt.Rows[0]["ORDER_ID"].ToString();

                //첫번쨰 Row 자동 선택.
                spdLotList.ActiveSheet.ActiveRowIndex = 0;
                spdLotList.ActiveSheet.Rows[0].BackColor = Color.FromArgb(255, 192, 255);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //불량 코드 조회 함수
        private void ViewLossCodeList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2004-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLoss);
                    return;
                }

                MPCF.ClearList(spdLoss);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLoss_Sheet1.RowCount++;

                    spdLoss_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_CODE].Value = dt.Rows[i]["LOSS_CODE"];
                    spdLoss_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_DESC].Value = dt.Rows[i]["LOSS_DESC"];
                    spdLoss_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_QTY].Value = dt.Rows[i]["LOSS_QTY"];
                }

                MPCF.FitColumnHeader(spdLoss);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //불량 실적 저장 하는 함수
        private bool LossLot()
        {
            TRSNode in_node = new TRSNode("loss_Code_In");
            TRSNode out_node = new TRSNode("loss_Code_Out");
            TRSNode loss_list;

            int i = 0;
            double d_loss_qty = 0;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text);
                in_node.AddString("CUASE_OPER", cdvCauseOper.Text);
                in_node.AddString("RES_ID", spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.RES_ID].Text);

                for (i = 0; i < spdLoss_Sheet1.RowCount; i++)
                {
                    if (MPCF.ToDbl(spdLoss_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_QTY].Text) != 0)
                    {
                        loss_list = in_node.AddNode("LOSS_TBL");
                        loss_list.AddString("CODE", spdLoss_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_CODE].Text);
                        loss_list.AddDouble("VALUE", spdLoss_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_QTY].Text);

                        d_loss_qty += MPCF.ToDbl(spdLoss_Sheet1.Cells[i, (int)LOSS_INFO.LOSS_QTY].Value);
                    }
                }

                in_node.AddDouble("OUT_QTY_1", d_loss_qty);
                in_node.AddString("COMMENT", txtComment.Text);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Update_Lot_Loss", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);

                return true;               
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //벨리데이션 체크 함수
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


                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
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

                        if (spdLotList.ActiveSheet.RowCount == 0)
                        {
                            //CMN199 ERROR - 선택된 Lot이 없습니다. 먼저 Lot을 선택하여 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(199));
                            return false;
                        }

                        for (int k = 0; k < spdLoss.ActiveSheet.RowCount; k++)
                        {
                            if (MPCF.ToDbl(spdLoss.ActiveSheet.Cells[k, (int)LOSS_INFO.LOSS_QTY].Text) != 0)
                                iCount++;
                        }

                        if (iCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305));
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
        private void ClearList()
        {
            try
            {
                MPCF.ClearList(spdLotList);
                MPCF.ClearList(spdLoss);

                cdvCauseOper.Text = "";
                txtComment.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmTranLossLot_Load(object sender, EventArgs e)
        {
            try
            {

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //공정 선택시 원인 공정 자동 입력 및 불량코드 조회
        private void cdvOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                ViewLossCodeList();

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
                ViewLossCodeList();

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
                cdvOrder.Init();
                MPCF.InitListView(cdvOrder.GetListView);
                cdvOrder.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOrder.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOrder.SelectedSubItemIndex = 0;
                cdvOrder.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOrderList(cdvOrder.GetListView, '1', cdvDept.Text, cdvWorkPlace.Text, cdvOper.Text) == false)
                {
                    return;
                }

                cdvOrder.InsertEmptyRow(0, 1);
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

        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (MPCF.Trim(txtLotID.Text) != "")
                    {
                        ViewLotInfo();
                    }
                    else
                    {
                        ViewLotList();
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //lot 선택시 선택된 lot 표시
        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                    return;

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    spdLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdLotList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //조회버튼
        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewLotList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //저장 버튼
        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (LossLot())
                {
                    ClearList();

                    ViewLossCodeList();

                    if (MPCF.Trim(txtLotID.Text) != "")
                    {
                        ViewLotInfo();
                    }
                    else
                    {
                        ViewLotList();
                    }
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
