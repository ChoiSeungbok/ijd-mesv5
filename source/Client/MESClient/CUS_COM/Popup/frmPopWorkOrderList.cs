using FarPoint.Win.Spread;
using Miracom.CliFrx;
using Miracom.DNMCore;
using Miracom.MESCore;
using Miracom.TRSCore;
using System;
using System.Data;
using System.Windows.Forms;

namespace CUS_COM.Popup
{
    public partial class frmPopWorkOrderList : frmTranForm02
    {
        public frmPopWorkOrderList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "
        private enum WORK_ORDER_LIST
        {
            CHECK,              // 1 : 체크박스
            WORK_DATE,          // 2 : 작업일자
            WORK_ORDER,         // 3 : 작업지시
            PO_NO,              
            PO_SEQ,
            MAT_ID,             // 4 : 품목코드
            MAT_DESC,           // 5 : 품목명
            FLOW,               // 6 : 플로우
            FLOW_DESC,          // 7 : 플로우명
            ORD_QTY,            // 8 : 작업지시 수량
            UNIT,               // 9 : 단위
            AREA_CODE,          // 10 : 사업부코드
            AREA_DESC,          // 11 : 사업부명
            SUB_AREA_CODE,      // 12 : 작업장코드
            SUB_AREA_DESC,      // 13 : 작업장명
            OPER_CODE,          // 14 : 창고코드
            OPER_DESC,          // 15 : 창고명
            PLAN_START_TIME,    // 16 : 계획시작일자
            PLAN_END_TIME,      // 17 : 계획종료일자
            EXPIRE_DATE,        // 18 : 만기일자
            ORD_STATUS_FLAG,    // 19 : 상태값
            ORD_STATUS_DESC,    // 20 : 상태명
        }
        
        #endregion

        #region " Variable Definition "

        public string g_AreaCode = string.Empty;
        public string g_AreaDesc = string.Empty;
        public string g_SubAreaCode = string.Empty;
        public string g_SubAreaDesc = string.Empty;
        public string g_OperCode = string.Empty;
        public string g_OperDesc = string.Empty;
        public string g_WorkOrder = string.Empty;
        public string g_PoNo = string.Empty;
        public string g_PoSeq = string.Empty;
        public string g_PoYn = string.Empty;
        public string g_AutoSearchYn = string.Empty;
        public string g_FromDt = string.Empty;
        public string g_ToDt = string.Empty;
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

        private void ViewWorkOrderList()
        {
            string sViewId = "";
            string sSql = "";
            int i = 0;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[11];
                SheetView svOrder = spdWorkOrder.ActiveSheet;
                DataTable dt = null;

                if (MPCF.Trim(cdvOrderStatus.Text) == "")
                    sViewId = "CCOM3003-002";
                else 
                    sViewId = "CCOM3003-001";

                dvcArgu[0].sCondition_ID = "P_FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "P_AREA";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "P_SUB_AREA";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[3].sCondition_ID = "P_OPER";
                dvcArgu[3].sCondition_Value = cdvOper.Text;

                dvcArgu[4].sCondition_ID = "P_START_DATE";
                dvcArgu[4].sCondition_Value = dtpFromDate.Text.Replace("-", "");

                dvcArgu[5].sCondition_ID = "P_END_DATE";
                dvcArgu[5].sCondition_Value = dtpToDate.Text.Replace("-", "");

                dvcArgu[6].sCondition_ID = "P_WORK_ORDER_ID";
                dvcArgu[6].sCondition_Value = txtWorkOrderId.Text;

                dvcArgu[7].sCondition_ID = "P_ORDER_STATUS_FLAG";
                dvcArgu[7].sCondition_Value = cdvOrderStatus.Text;


                dvcArgu[8].sCondition_ID = "PO_NO";
                dvcArgu[8].sCondition_Value = txtPoNum.Text;


                dvcArgu[9].sCondition_ID = "PO_SEQ";
                dvcArgu[9].sCondition_Value = txtPoSeq.Text;

                dvcArgu[10].sCondition_ID = "MAT_ID";
                dvcArgu[10].sCondition_Value = txtMatId.Text;


                if (TPDR.GetDataOne("", ref dt, sViewId, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }
                
                for (i = 0; i < dt.Rows.Count; i++)
                {
                    svOrder.RowCount++;

                    svOrder.Cells[i, (int)WORK_ORDER_LIST.CHECK].Value = false;
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.WORK_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.WORK_ORDER].Value = dt.Rows[i]["WORK_ORDER"];
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.PO_NO].Value = dt.Rows[i]["PO_NO"];
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.PO_SEQ].Value = dt.Rows[i]["PO_SEQ"];
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.FLOW].Value = dt.Rows[i]["FLOW"];
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.FLOW_DESC].Value = dt.Rows[i]["FLOW_DESC"];
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.ORD_QTY].Value = String.Format("{0:#,0.##}", dt.Rows[i]["ORD_QTY"]); //추후 형식에 맞게 변경
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.UNIT].Value = dt.Rows[i]["UNIT"];
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.AREA_CODE].Value = dt.Rows[i]["AREA_CODE"];
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.AREA_DESC].Value = dt.Rows[i]["AREA_DESC"];
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.SUB_AREA_CODE].Value = dt.Rows[i]["SUB_AREA_CODE"];
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.SUB_AREA_DESC].Value = dt.Rows[i]["SUB_AREA_DESC"];
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.OPER_CODE].Value = dt.Rows[i]["OPER"];
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.PLAN_START_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["PLAN_START_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.PLAN_END_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["PLAN_END_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.EXPIRE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["EXPIRE_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.ORD_STATUS_FLAG].Value = dt.Rows[i]["ORD_STATUS_FLAG"];
                    svOrder.Cells[i, (int)WORK_ORDER_LIST.ORD_STATUS_DESC].Value = dt.Rows[i]["ORD_STATUS_DESC"];
                }

                MPCF.FitColumnHeader(spdWorkOrder);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                SheetView svOrder = spdWorkOrder.ActiveSheet;

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        if (string.IsNullOrEmpty(MPCF.Trim(cdvDept.Text)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }

                        //시작일자 또는 종료일자의 우선순위가 안맞으면 에러
                        if (int.Parse(dtpFromDate.Text.Replace("-", "")) > int.Parse(dtpToDate.Text.Replace("-", "")))
                        {
                            //CMN484 INFO - 날짜 선후관계를 확인하세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(484));
                            dtpFromDate.Focus();
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

        #endregion

        #region " Event Definition "

        private void frmPopWorkOrderList_Load(object sender, EventArgs e)
        {
            try
            {






                 cdvDept.Text = g_AreaCode;
                cdvDept.DisplayText = g_AreaDesc;
                cdvWorkPlace.Text = g_SubAreaCode;
                cdvWorkPlace.DisplayText = g_SubAreaDesc;
                cdvOper.Text = g_OperCode;
                cdvOper.DisplayText = g_OperDesc;
                txtWorkOrderId.Text = g_WorkOrder;
                txtPoNum.Text = g_PoNo;
                txtPoSeq.Text = g_PoSeq;



                if (g_FromDt == string.Empty)
                {
                    dtpFromDate.Text = DateTime.Now.AddDays(-7).ToShortDateString();
                }
                else
                {

                    dtpFromDate.Text = g_FromDt;
                }

                if (g_ToDt == string.Empty)
                {
                    dtpToDate.Text = DateTime.Now.ToShortDateString();
                }
                else
                {
                    dtpToDate.Text = g_ToDt;
                }


                if (g_PoYn == "Y")
                {
                    spdWorkOrder_Sheet1.Columns[(int)WORK_ORDER_LIST.PO_NO].Visible = true;
                    spdWorkOrder_Sheet1.Columns[(int)WORK_ORDER_LIST.PO_SEQ].Visible = true;
                }
                else
                {
                    spdWorkOrder_Sheet1.Columns[(int)WORK_ORDER_LIST.PO_NO].Visible = false;
                    spdWorkOrder_Sheet1.Columns[(int)WORK_ORDER_LIST.PO_SEQ].Visible = false;
                }

                if(g_AutoSearchYn == "Y")
                {
                    ViewWorkOrderList();
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        
        private void cdvOrderStatus_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOrderStatus.Init();
                MPCF.InitListView(cdvOrderStatus.GetListView);
                cdvOrderStatus.Columns.Add("Ore Flag", 50, HorizontalAlignment.Left);
                cdvOrderStatus.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                cdvOrderStatus.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvOrderStatus.GetListView, '1', MPGC.MP_WIP_ORDER_STATUS) == false)
                {
                    return;
                }

                cdvOrderStatus.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdWorkOrder_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                SheetView svOrder = spdWorkOrder.ActiveSheet;

                if (e.ColumnHeader)
                    return;

                for (int i = 0; i < svOrder.RowCount; i++)
                {
                    svOrder.SetValue(i, (int)WORK_ORDER_LIST.CHECK, false);
                }

                svOrder.SetValue(e.Row, (int)WORK_ORDER_LIST.CHECK, true);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdWorkOrder_CellDoubleClick(object sender, CellClickEventArgs e)
        {
            try
            {
                SheetView svOrder = spdWorkOrder.ActiveSheet;

                if (e.ColumnHeader)
                    return;

                g_WorkOrder = svOrder.GetValue(e.Row, (int)WORK_ORDER_LIST.WORK_ORDER).ToString();
                g_PoNo = svOrder.GetValue(e.Row, (int)WORK_ORDER_LIST.PO_NO).ToString();
                g_PoSeq = svOrder.GetValue(e.Row, (int)WORK_ORDER_LIST.PO_SEQ).ToString();

                this.DialogResult = DialogResult.OK;
                this.Close();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtWorkOrderId_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                MPCF.ClearList(spdWorkOrder);

                ViewWorkOrderList();
            }
        }

        private void btnView_Click(object sender, System.EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                MPCF.ClearList(spdWorkOrder);

                ViewWorkOrderList();
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
                SheetView svOrder = spdWorkOrder.ActiveSheet;
                int iSelect = 0;

                for (int i = 0; i < svOrder.RowCount; i++)
                {
                    if (Convert.ToBoolean(svOrder.Cells[i, (int)WORK_ORDER_LIST.CHECK].Value))
                    {
                        iSelect++;
                        g_WorkOrder = svOrder.GetValue(i, (int)WORK_ORDER_LIST.WORK_ORDER).ToString();
                        g_PoNo = svOrder.GetValue(i, (int)WORK_ORDER_LIST.PO_NO).ToString();
                        g_PoSeq = svOrder.GetValue(i, (int)WORK_ORDER_LIST.PO_SEQ).ToString();

                        break;
                    }
                }

                if (iSelect <= 0)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    spdWorkOrder.Focus();
                    return;
                }

                if (iSelect > 0)
                {
                    this.DialogResult = DialogResult.OK;
                    this.Close();
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
