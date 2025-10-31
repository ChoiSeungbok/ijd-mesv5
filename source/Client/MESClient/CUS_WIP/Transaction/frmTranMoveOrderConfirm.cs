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
    public partial class frmTranMoveOrderConfirm : CUS_COM.frmTranForm01
    {
        public frmTranMoveOrderConfirm()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum MOVE_LIST
        {
            MOVE_ORDER_ID,          // 1 : 이동지시 번호
            FROM_AREA_ID,           // 2 : FROM 사업부
            FROM_SUB_AREA_ID,       // 3 : FROM 사업장
            FROM_SUB_AREA_DESC,     // 3 : FROM 사업장
            FROM_OPER,              // 4 : FROM 공정
            FROM_OPER_DESC,         // 4 : FROM 공정
            TO_AREA_ID,             // 5 : TO 사업부
            TO_AREA_DESC,           // 6 : TO 사업부
            TO_SUB_AREA_ID,         // 7 : TO 사업장
            TO_SUB_AREA_DESC,       // 8 : TO 사업장
            TO_OPER,                // 9 : TO 공정
            TO_OPER_DESC,           //10 : TO 공정
            MOVE_STATUS,            //11 : 상태
            MERGE_FLAG              //12 : 병합 여부
        }

        private enum MOVE_INFO
        {
            LOT_ID,                 // 1 : LOT ID
            MAT_ID,                 // 2 : 자재코드
            MAT_DESC,               // 3 : 자재명
            QTY,                    // 4 : 총소요량
            CREATE_DATE,            // 5 : 생성일자
            CREATE_CODE,            // 6 : 생성 코드
            CREATE_CODE_DESC
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
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //이동지시 정보 함수
        private void ViewMoveInfo()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MOVE_ID";
                dvcArgu[1].sCondition_Value = txtMoveOrder.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2011-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdMoveList);
                    return;
                }

                if (dt.Rows.Count > 0)
                {
                    MPCF.ClearList(spdMoveList);

                    //조회조건 
                    cdvDept.Text = dt.Rows[0]["TO_AREA_ID"].ToString();
                    cdvDept.DisplayText = dt.Rows[0]["TO_AREA_DESC"].ToString();
                    cdvToWorkPlace.Text = dt.Rows[0]["TO_SUB_AREA_ID"].ToString();
                    cdvToWorkPlace.DisplayText = dt.Rows[0]["TO_SUB_AREA_DESC"].ToString();
                    cdvToOper.Text = dt.Rows[0]["TO_OPER"].ToString();
                    cdvToOper.DisplayText = dt.Rows[0]["TO_OPER_DESC"].ToString();

                    cdvFrWorkPlace.Text = dt.Rows[0]["FROM_SUB_AREA_ID"].ToString();
                    cdvFrWorkPlace.DisplayText = dt.Rows[0]["FROM_SUB_AREA_DESC"].ToString();
                    cdvFrOper.Text = dt.Rows[0]["FROM_OPER"].ToString();
                    cdvFrOper.DisplayText = dt.Rows[0]["FROM_OPER_DESC"].ToString();

                    //그리드
                    spdMoveList_Sheet1.RowCount++;
                    spdMoveList_Sheet1.Cells[0, (int)MOVE_LIST.MOVE_ORDER_ID].Value = dt.Rows[0]["MOVE_ID"];
                    spdMoveList_Sheet1.Cells[0, (int)MOVE_LIST.FROM_AREA_ID].Value = dt.Rows[0]["FROM_AREA_ID"];
                    spdMoveList_Sheet1.Cells[0, (int)MOVE_LIST.FROM_SUB_AREA_ID].Value = dt.Rows[0]["FROM_SUB_AREA_ID"];
                    spdMoveList_Sheet1.Cells[0, (int)MOVE_LIST.FROM_SUB_AREA_DESC].Value = dt.Rows[0]["FROM_SUB_AREA_DESC"];
                    spdMoveList_Sheet1.Cells[0, (int)MOVE_LIST.FROM_OPER].Value = dt.Rows[0]["FROM_OPER"];
                    spdMoveList_Sheet1.Cells[0, (int)MOVE_LIST.FROM_OPER_DESC].Value = dt.Rows[0]["FROM_OPER_DESC"];
                    spdMoveList_Sheet1.Cells[0, (int)MOVE_LIST.TO_AREA_ID].Value = dt.Rows[0]["TO_AREA_ID"];
                    spdMoveList_Sheet1.Cells[0, (int)MOVE_LIST.TO_AREA_DESC].Value = dt.Rows[0]["TO_AREA_DESC"];
                    spdMoveList_Sheet1.Cells[0, (int)MOVE_LIST.TO_SUB_AREA_ID].Value = dt.Rows[0]["TO_SUB_AREA_ID"];
                    spdMoveList_Sheet1.Cells[0, (int)MOVE_LIST.TO_SUB_AREA_DESC].Value = dt.Rows[0]["TO_SUB_AREA_DESC"];
                    spdMoveList_Sheet1.Cells[0, (int)MOVE_LIST.TO_OPER].Value = dt.Rows[0]["TO_OPER"];
                    spdMoveList_Sheet1.Cells[0, (int)MOVE_LIST.TO_OPER_DESC].Value = dt.Rows[0]["TO_OPER_DESC"];
                    spdMoveList_Sheet1.Cells[0, (int)MOVE_LIST.MOVE_STATUS].Value = dt.Rows[0]["MOVE_STATUS"];
                    spdMoveList_Sheet1.Cells[0, (int)MOVE_LIST.MERGE_FLAG].Value = dt.Rows[0]["MERGE_FLAG"];

                    spdMoveList.ActiveSheet.ActiveRowIndex = 0;
                    spdMoveList.ActiveSheet.Rows[0].BackColor = Color.FromArgb(255, 192, 255);
                    txtMoveOrder1.Text = spdMoveList.ActiveSheet.Cells[0, (int)MOVE_LIST.MOVE_ORDER_ID].Text;
                    txtFromWorkPlace.Text = spdMoveList.ActiveSheet.Cells[0, (int)MOVE_LIST.FROM_SUB_AREA_DESC].Text;
                    txtFromOper.Text = spdMoveList.ActiveSheet.Cells[0, (int)MOVE_LIST.FROM_OPER_DESC].Text;
                    txtToWorkPlace.Text = spdMoveList.ActiveSheet.Cells[0, (int)MOVE_LIST.TO_SUB_AREA_DESC].Text;
                    txtToOper.Text = spdMoveList.ActiveSheet.Cells[0, (int)MOVE_LIST.TO_OPER_DESC].Text;

                    if (dt.Rows[0]["MERGE_FLAG"].ToString() == "Y")
                        chkMerge.Checked = true;
                    else
                        chkMerge.Checked = false;

                    ViewMoveLotList(txtMoveOrder1.Text);
                }
                else
                {
                    MPCF.ClearList(spdMoveList);
                    MPCF.ClearList(spdMoveLotList);
                    txtMoveOrder1.Text = "";
                    txtFromWorkPlace.Text = "";
                    txtFromOper.Text = "";
                    txtToWorkPlace.Text = "";
                    txtToOper.Text = "";
                    chkMerge.Checked = false;
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewMoveList()
        {
            try
            {
                MPCF.ClearList(spdMoveLotList);

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvToWorkPlace.Text;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvToOper.Text;


                dvcArgu[4].sCondition_ID = "FROM_SUB_AREA_ID";
                dvcArgu[4].sCondition_Value = cdvFrWorkPlace.Text;

                dvcArgu[5].sCondition_ID = "FROM_OPER";
                dvcArgu[5].sCondition_Value = cdvFrOper.Text;


                dvcArgu[6].sCondition_ID = "MOVE_ID";
                dvcArgu[6].sCondition_Value = txtMoveOrder.Text + "%";



                if (TPDR.GetDataOne("", ref dt, "CWIP2011-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdMoveList);
                    return;
                }

                MPCF.ClearList(spdMoveList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMoveList_Sheet1.RowCount++;

                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.MOVE_ORDER_ID].Value = dt.Rows[i]["MOVE_ID"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.FROM_AREA_ID].Value = dt.Rows[i]["FROM_AREA_ID"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.FROM_SUB_AREA_ID].Value = dt.Rows[i]["FROM_SUB_AREA_ID"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.FROM_SUB_AREA_DESC].Value = dt.Rows[i]["FROM_SUB_AREA_DESC"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.FROM_OPER].Value = dt.Rows[i]["FROM_OPER"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.FROM_OPER_DESC].Value = dt.Rows[i]["FROM_OPER_DESC"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_AREA_ID].Value = dt.Rows[i]["TO_AREA_ID"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_AREA_DESC].Value = dt.Rows[i]["TO_AREA_DESC"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_SUB_AREA_ID].Value = dt.Rows[i]["TO_SUB_AREA_ID"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_SUB_AREA_DESC].Value = dt.Rows[i]["TO_SUB_AREA_DESC"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_OPER].Value = dt.Rows[i]["TO_OPER"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.TO_OPER_DESC].Value = dt.Rows[i]["TO_OPER_DESC"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.MOVE_STATUS].Value = dt.Rows[i]["MOVE_STATUS"];
                    spdMoveList_Sheet1.Cells[i, (int)MOVE_LIST.MERGE_FLAG].Value = dt.Rows[i]["MERGE_FLAG"];
                }

                MPCF.FitColumnHeader(spdMoveList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        //이동지시 lot 리스트 조회 함수
        private void ViewMoveLotList(string sMove_id)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MOVE_ID";
                dvcArgu[1].sCondition_Value = sMove_id;

                if (TPDR.GetDataOne("", ref dt, "CWIP2011-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdMoveLotList);
                    return;
                }

                MPCF.ClearList(spdMoveLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMoveLotList_Sheet1.RowCount++;

                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    spdMoveLotList_Sheet1.Cells[i, (int)MOVE_INFO.CREATE_CODE_DESC].Value = dt.Rows[i]["CREATE_CODE_DESC"];
                }

                MPCF.FitColumnHeader(spdMoveLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //이동 처리 함수
        private bool MoveLot()
        {
            TRSNode in_node = new TRSNode("MoveLot_In");
            TRSNode out_node = new TRSNode("MoveLot_Out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '3';

                in_node.AddString("MOVE_ID", txtMoveOrder1.Text);
                //in_node.AddString("TO_OPER", cdvToOper.Text);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Move_Lot_Order", in_node, ref out_node) == false)
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

        //벨이데이션 함수
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

                        break;

                    case CSGC.CHECK.SAVE:

                        if (MPCF.Trim(txtMoveOrder1.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMoveOrder1.Text + "]");
                            txtMoveOrder1.Focus();
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

        // 초기화 함수
        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "END":

                        MPCF.ClearList(spdMoveLotList);
                        txtFromWorkPlace.Text = "";
                        txtFromOper.Text = "";
                        txtToWorkPlace.Text = "";
                        txtToOper.Text = "";
                        txtMoveOrder1.Text = "";
                        chkMerge.Checked = false;

                        break;
                        
                    case "ALL":

                        MPCF.ClearList(spdMoveList);
                        MPCF.ClearList(spdMoveLotList);

                        chkMerge.Checked = false;
                        txtMoveOrder.Text = "";
                        cdvDept.Text = "";
                        cdvToWorkPlace.Text = "";
                        cdvToOper.Text = "";
                        txtFromWorkPlace.Text = "";
                        txtFromOper.Text = "";
                        txtToWorkPlace.Text = "";
                        txtToOper.Text = "";
                        txtMoveOrder1.Text = "";

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

        private void frmTranMoveOrderConfirm_Load(object sender, EventArgs e)
        {
            try
            {

                txtMoveOrder.Focus();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }




        private void spdMoveList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                    return;

                for (int i = 0; i < spdMoveList.ActiveSheet.RowCount; i++)
                {
                    spdMoveList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdMoveList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                txtMoveOrder1.Text = spdMoveList.ActiveSheet.Cells[e.Row, (int)MOVE_LIST.MOVE_ORDER_ID].Text;
                txtFromWorkPlace.Text = spdMoveList.ActiveSheet.Cells[e.Row, (int)MOVE_LIST.FROM_SUB_AREA_DESC].Text;
                txtFromOper.Text = spdMoveList.ActiveSheet.Cells[e.Row, (int)MOVE_LIST.FROM_OPER_DESC].Text;
                txtToWorkPlace.Text = spdMoveList.ActiveSheet.Cells[e.Row, (int)MOVE_LIST.TO_SUB_AREA_DESC].Text;
                txtToOper.Text = spdMoveList.ActiveSheet.Cells[e.Row, (int)MOVE_LIST.TO_OPER_DESC].Text;

                if (spdMoveList.ActiveSheet.Cells[e.Row, (int)MOVE_LIST.MERGE_FLAG].Text == "Y")
                {
                    chkMerge.Checked = true;
                }
                else
                {
                    chkMerge.Checked = false;
                }

                ViewMoveLotList(txtMoveOrder1.Text);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtMoveOrder_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (MPCF.Trim(txtMoveOrder.Text) != "")
                        ViewMoveInfo();
                    else
                        btnView.PerformClick();
                }
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

                //ViewMoveInfo();
                ViewMoveList();                
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

                if (MoveLot())
                {
                    ClearData("END");
                    ViewMoveList();
                }

                txtMoveOrder.Focus();
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
                /*
                cdvToWorkPlace.Text = "";
                cdvToOper.Text = "";
                */
                cdvFrWorkPlace.Text = "";
                cdvFrOper.Text = "";

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvFrWorkPlace_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvFrOper.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void cdvFrWorkPlace_ButtonPress(object sender, EventArgs e)
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

                cdvFrWorkPlace.Init();
                MPCF.InitListView(cdvFrWorkPlace.GetListView);
                cdvFrWorkPlace.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvFrWorkPlace.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvFrWorkPlace.SelectedSubItemIndex = 0;
                cdvFrWorkPlace.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList_AREA(cdvFrWorkPlace.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, cdvDept.Text) == false)
                {
                    return;
                }

                //특정 사업장인 경우 Tag에 저장된 사업부를 제외하고 보이지 않기 위해
                if (MPCF.Trim(cdvFrWorkPlace.Tag) != "")
                {
                    for (int i = cdvFrWorkPlace.GetListView.Items.Count; i > 0; i--)
                    {
                        if (cdvFrWorkPlace.GetListView.Items[i - 1].SubItems[0].Text != cdvFrWorkPlace.Tag.ToString())
                        {
                            cdvFrWorkPlace.GetListView.Items[i - 1].Remove();
                        }
                    }
                }

                cdvFrWorkPlace.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvFrOper_ButtonPress(object sender, EventArgs e)
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
                
                
                cdvFrOper.Init();
                MPCF.InitListView(cdvFrOper.GetListView);
                cdvFrOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvFrOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvFrOper.SelectedSubItemIndex = 0;
                cdvFrOper.DisplaySubItemIndex = 1;
                if (COM_LIST.ViewOperationList(cdvFrOper.GetListView, 'K', cdvDept.Text, cdvFrWorkPlace.Text, "", "", 'Y') == false)
                {
                    return;
                }

                cdvFrOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void cdvToWorkPlace_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvToOper.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToOper_ButtonPress(object sender, EventArgs e)
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

                cdvToOper.Init();
                MPCF.InitListView(cdvToOper.GetListView);
                cdvToOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToOper.SelectedSubItemIndex = 0;
                cdvToOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvToOper.GetListView, 'K', cdvDept.Text, cdvToWorkPlace.Text, "", "", 'Y') == false)
                {
                    return;
                }

                cdvToOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvToWorkPlace_ButtonPress(object sender, EventArgs e)
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

                cdvToWorkPlace.Init();
                MPCF.InitListView(cdvToWorkPlace.GetListView);
                cdvToWorkPlace.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToWorkPlace.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToWorkPlace.SelectedSubItemIndex = 0;
                cdvToWorkPlace.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList_AREA(cdvToWorkPlace.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, cdvDept.Text) == false)
                {
                    return;
                }

                //특정 사업장인 경우 Tag에 저장된 사업부를 제외하고 보이지 않기 위해
                if (MPCF.Trim(cdvToWorkPlace.Tag) != "")
                {
                    for (int i = cdvToWorkPlace.GetListView.Items.Count; i > 0; i--)
                    {
                        if (cdvToWorkPlace.GetListView.Items[i - 1].SubItems[0].Text != cdvToWorkPlace.Tag.ToString())
                        {
                            cdvToWorkPlace.GetListView.Items[i - 1].Remove();
                        }
                    }
                }

                cdvToWorkPlace.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion



  


    }
}
