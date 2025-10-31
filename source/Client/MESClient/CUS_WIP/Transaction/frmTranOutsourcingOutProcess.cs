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
    public partial class frmTranOutsourcingOutProcess : CUS_COM.frmViewForm01
    {
        public frmTranOutsourcingOutProcess()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum WORKORDER
        {
            ORDER_ID,               // 1 : 작업지시번호
            PO_ID,                  // 2 : po
            VENDOR_ID,              // 3 : 협력사코드
            VENDOR_DESC,            // 4 : 협력사명
            START_DATE,             // 5 : 시작일
            END_DATE,               // 6 : 완료일
            MAT_ID,                 // 7 : 제품코드
            MAT_DESC,               // 8 : 제품명
            UNIT,                   // 9 : 단위
            ORDER_QTY,              //10 : 지시수량
            PROD_QTY,               //11 : 생산수량
            STOCK,                  //12 : 창고
            FLOW
        }

        private enum LOT_INFO
        {
            CHK,                    // 1 : CHECK
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 제품코드
            MAT_DESC,               // 4 : 제품명            
            FLOW,                   // 5 : 플로우
            FLOW_DESC,              // 6 : 플로우 명
            OPER,                   // 7 : 공정
            OPER_DESC,              // 8 : 공정 명
            CREATE_DATE,            // 9 : 생성일자
            PROD_QTY                //10 : 수량
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
                btnOut.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnInputMat.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

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

                if (TPDR.GetDataOne("", ref dt, "CWIP2007-002", dvcArgu, false, false, ref sSql) == false)
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

        private void ViewLotInfo(string sLot_ID)
        {
            string sLotId = "";
            int iRow = 0;
            bool bContinueFlag = false;

            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", sLot_ID);
                //in_node.AddString("OPER", cdvOper.Text);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_Info", in_node, ref out_node) == false)
                {
                    return;
                }
                for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                {
                    bContinueFlag = false;

                    //lot 정보가 이미 있는경우 넘어간다.
                    sLotId = out_node.GetList("LOT_TBL")[i].GetString("LOT_ID");
                    for (int k = 0; k < spdLotList.ActiveSheet.RowCount; k++)
                    {
                        if (sLotId == spdLotList.ActiveSheet.Cells[k, (int)LOT_INFO.LOT_ID].Text)
                        {
                            bContinueFlag = true;
                            continue;
                        }
                    }

                    if (bContinueFlag == true)
                        continue;

                    iRow = spdLotList.ActiveSheet.RowCount;

                    spdLotList.ActiveSheet.RowCount++;
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CHK, true);
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_ID, out_node.GetList("LOT_TBL")[i].GetString("MAT_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_DESC, out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.FLOW, out_node.GetList("LOT_TBL")[i].GetString("FLOW"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.FLOW_DESC, out_node.GetList("LOT_TBL")[i].GetString("FLOW_DESC"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.OPER, out_node.GetList("LOT_TBL")[i].GetString("OPER"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.OPER_DESC, out_node.GetList("LOT_TBL")[i].GetString("OPER_DESC"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CREATE_DATE, MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("CREATE_TIME"), DATE_TIME_FORMAT.DATETIME));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.PROD_QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));                  
                }

                MPCF.FitColumnHeader(spdLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void ViewOrderList()
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
                dvcArgu[3].sCondition_Value = cdvOrder.Text;

                dvcArgu[4].sCondition_ID = "VENDOR_ID";
                dvcArgu[4].sCondition_Value = cdvVendor.Text;

                dvcArgu[5].sCondition_ID = "MAT_ID";
                dvcArgu[5].sCondition_Value = cdvMatid.Text;

                dvcArgu[6].sCondition_ID = "PO_NO";
                dvcArgu[6].sCondition_Value = txtPo.Text + "%";
           
                if (TPDR.GetDataOne("", ref dt, "CWIP2007-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdWorkOrder);
                    return;
                }

                MPCF.ClearList(spdWorkOrder);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdWorkOrder.ActiveSheet.RowCount++;

                    spdWorkOrder.ActiveSheet.Cells[i, (int)WORKORDER.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdWorkOrder.ActiveSheet.Cells[i, (int)WORKORDER.PO_ID].Value = dt.Rows[i]["PO_NO"];
                    spdWorkOrder.ActiveSheet.Cells[i, (int)WORKORDER.VENDOR_ID].Value = dt.Rows[i]["VENDOR_ID"];
                    spdWorkOrder.ActiveSheet.Cells[i, (int)WORKORDER.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdWorkOrder.ActiveSheet.Cells[i, (int)WORKORDER.START_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["START_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdWorkOrder.ActiveSheet.Cells[i, (int)WORKORDER.END_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["END_DATE"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdWorkOrder.ActiveSheet.Cells[i, (int)WORKORDER.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdWorkOrder.ActiveSheet.Cells[i, (int)WORKORDER.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdWorkOrder.ActiveSheet.Cells[i, (int)WORKORDER.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdWorkOrder.ActiveSheet.Cells[i, (int)WORKORDER.ORDER_QTY].Value = dt.Rows[i]["ORDER_QTY"];
                    spdWorkOrder.ActiveSheet.Cells[i, (int)WORKORDER.PROD_QTY].Value = dt.Rows[i]["PROD_QTY"];
                    spdWorkOrder.ActiveSheet.Cells[i, (int)WORKORDER.STOCK].Value = dt.Rows[i]["STOCK"];
                    spdWorkOrder.ActiveSheet.Cells[i, (int)WORKORDER.FLOW].Value = dt.Rows[i]["FLOW_DESC"];
                }
                MPCF.FitColumnHeader(spdWorkOrder);

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
            double dSumQty = 0;

            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                TRSNode Lot_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = c_step;

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("ORDER_ID", cdvOrder.Text == "" ? spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_ID].Text : cdvOrder.Text);

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        dSumQty = dSumQty + MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text);

                        Lot_list = in_node.AddNode("LOT_TBL");
                        Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                        Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text));
                    }
                }

                in_node.AddDouble("SUM_QTY", dSumQty);

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

                //if (MPCF.Trim(cdvWorkPlace.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                //    cdvWorkPlace.Focus();
                //    return false;
                //}

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        break;

                    case CSGC.CHECK.SAVE:

                        for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                        {
                            if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                                iLotCount++;
                        }

                        if (iLotCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305));
                            return false;
                        }

                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
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

        private void CreaData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "ALL":

                        cdvOrder.Text = "";

                        txtLotID.Text = "";
                        cdvVendor.Text = "";
                        cdvMatid.Text = "";
                        txtPo.Text = "";

                        MPCF.ClearList(spdWorkOrder);
                        MPCF.ClearList(spdLotList);

                        break;

                    case "SAVE":

                        txtLotID.Text = "";

                        MPCF.ClearList(spdWorkOrder);
                        MPCF.ClearList(spdLotList);

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

        private void frmTranOutsourcingOutProcess_Load(object sender, EventArgs e)
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

                MPCF.ClearList(spdWorkOrder);
                MPCF.ClearList(spdLotList);
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

                MPCF.ClearList(spdWorkOrder);
                MPCF.ClearList(spdLotList);
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

                //if (MPCF.Trim(cdvWorkPlace.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                //    cdvWorkPlace.Focus();
                //    return;
                //}

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
                MPCF.ClearList(spdWorkOrder);
                MPCF.ClearList(spdLotList);
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
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
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

        private void spdWorkOrder_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            string sOrder_id = "";

            try
            {
                if (e.ColumnHeader)
                    return;

                for (int i = 0; i < spdWorkOrder.ActiveSheet.RowCount; i++)
                {
                    spdWorkOrder.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdWorkOrder.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                sOrder_id = spdWorkOrder.ActiveSheet.Cells[e.Row, (int)WORKORDER.ORDER_ID].Text;

                if (MPCF.Trim(sOrder_id) != "")
                {
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        //자재 투입 버튼 클릭
        private void btnInputMat_Click(object sender, EventArgs e)
        {
            try
            {
                if (spdWorkOrder.ActiveSheet.RowCount == 0)
                {
                    //CMN452 CONFIRM  - 선택된 작업지시가 없습니다. 작업지시를 선택하세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(452));
                    return;
                }

                frmTranOutsourcingInputMaterials popup = new frmTranOutsourcingInputMaterials();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                popup.sSub_area_id = cdvWorkPlace.Text;
                popup.sSub_area_desc = cdvWorkPlace.DisplayText;
                popup.sOper_id = cdvOper.Text;
                popup.sOper_desc = cdvOper.DisplayText;
                popup.sOrder_id = MPCF.Trim(cdvOrder.Text) == "" ? spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.ORDER_ID].Text : cdvOrder.Text;
                popup.sPo_id = MPCF.Trim(txtPo.Text) == "" ? spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.PO_ID].Text : txtPo.Text;
                popup.sVendor_id = MPCF.Trim(cdvVendor.Text) =="" ? spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.VENDOR_ID].Text : cdvVendor.Text;
                popup.sVendor_desc = MPCF.Trim(cdvVendor.DisplayText) == ""? spdWorkOrder.ActiveSheet.Cells[spdWorkOrder.ActiveSheet.ActiveRowIndex, (int)WORKORDER.VENDOR_DESC].Text : cdvVendor.DisplayText;

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

        private void txtLotID_ButtonClick(object sender, Infragistics.Win.Misc.AlertButtonClickedEventArgs e)
        {
            try
            {
                txtLotID.sArea_id = cdvDept.Text;
                txtLotID.sArea_desc = cdvDept.DisplayText;
                txtLotID.sSub_Area_id = cdvWorkPlace.Text;
                txtLotID.sSub_Area_desc = cdvWorkPlace.DisplayText;
                txtLotID.sOper_id = cdvOper.Text;
                txtLotID.sOper_desc = cdvOper.DisplayText;
                //txtLotID.sRes_id = cdvResource.Text;
                //txtLotID.sRes_desc = cdvResource.DisplayText;
                txtLotID.sOrder = cdvOrder.Text;
                txtLotID.sOperReadOnly = "N";
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
                    if (MPCF.Trim(txtLotID.Text) == "")
                        return;

                    ViewLotInfo(txtLotID.Text);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //초기화 버튼 클릭
        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                CreaData("ALL");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //조회버튼 클릭
        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewOrderList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //외주 출고 버튼 클릭
        private void btnOut_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SaveProcess('1') == true)
                {
                    CreaData("SAVE");
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatid_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatid.DisplayText == "")
                cdvMatid.Text = "";
        }

        #endregion


    }
}
