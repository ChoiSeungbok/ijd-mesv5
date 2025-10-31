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

        private enum MOVE_INFO
        {
            LOT_ID,                 // 1 : LOT ID
            MAT_ID,                 // 2 : 자재코드
            MAT_DESC,               // 3 : 자재명
            QTY,                    // 4 : 총소요량
            CREATE_DATE             // 5 : 생성일자
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

                    return;
                }

                if (dt.Rows.Count > 0)
                {
                    cdvDept.Text = dt.Rows[0]["TO_AREA_ID"].ToString();
                    cdvDept.DisplayText = dt.Rows[0]["TO_AREA_DESC"].ToString();
                    cdvWorkPlace.Text = dt.Rows[0]["TO_SUB_AREA_ID"].ToString();
                    cdvWorkPlace.DisplayText = dt.Rows[0]["TO_SUB_AREA_DESC"].ToString();
                    cdvOper.Text = dt.Rows[0]["TO_OPER"].ToString();
                    cdvOper.DisplayText = dt.Rows[0]["TO_OPER_DESC"].ToString();
                    cdvFromWorkPlace.Text = dt.Rows[0]["FROM_AREA_ID"].ToString();
                    cdvFromWorkPlace.DisplayText = dt.Rows[0]["FROM_SUB_AREA_ID"].ToString();
                    cdvFromOper.Text = dt.Rows[0]["FROM_OPER"].ToString();
                    cdvFromOper.DisplayText = dt.Rows[0]["FROM_OPER_DESC"].ToString();

                    if (dt.Rows[0]["MERGE_FLAG"].ToString() == "Y")
                        chkMerge.Checked = true;
                    else
                        chkMerge.Checked = false;
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //이동지시 lot 리스트 조회 함수
        private void ViewMoveLotList()
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
                dvcArgu[1].sCondition_Value = txtMoveOrder.Text;

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

                in_node.AddString("MOVE_ID", txtMoveOrder.Text);
                //in_node.AddString("TO_OPER", cdvOper.Text);

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
                if (MPCF.Trim(txtMoveOrder.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMoveOrder.Text + "]");
                    cdvOper.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

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

        // 초기화 함수
        private void ClearData()
        {
            try
            {
                MPCF.ClearList(spdMoveLotList);

                chkMerge.Checked = false;
                txtMoveOrder.Text = "";
                cdvDept.Text = "";
                cdvWorkPlace.Text = "";
                cdvOper.Text = "";
                cdvFromWorkPlace.Text = "";
                cdvFromOper.Text = "";

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

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, '1', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
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

        private void cdvFromWorkPlace_ButtonPress(object sender, EventArgs e)
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

                cdvFromWorkPlace.Init();
                MPCF.InitListView(cdvFromWorkPlace.GetListView);
                cdvFromWorkPlace.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvFromWorkPlace.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvFromWorkPlace.SelectedSubItemIndex = 0;
                cdvFromWorkPlace.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList_AREA(cdvFromWorkPlace.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, cdvDept.Text) == false)
                {
                    return;
                }

                cdvFromWorkPlace.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvFromOper_ButtonPress(object sender, EventArgs e)
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

                if (MPCF.Trim(cdvFromWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFromWorkPlace.Text + "]");
                    cdvFromWorkPlace.Focus();
                    return;
                }

                cdvFromOper.Init();
                MPCF.InitListView(cdvFromOper.GetListView);
                cdvFromOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvFromOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvFromOper.SelectedSubItemIndex = 0;
                cdvFromOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvFromOper.GetListView, 'D', cdvDept.Text, cdvFromWorkPlace.Text, "", "", 'Y') == false)
                {
                    return;
                }

                cdvFromOper.InsertEmptyRow(0, 1);
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
                    btnView.PerformClick();
                }
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

                ViewMoveInfo();
                ViewMoveLotList();
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
                    ClearData();
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
