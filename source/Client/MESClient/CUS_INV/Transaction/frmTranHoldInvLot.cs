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

namespace CUS_INV
{
    public partial class frmTranHoldInvLot : CUS_COM.frmViewForm01
    {
        public frmTranHoldInvLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        #endregion

        #region " Variable Definition "

        string inv_lot_id = "";

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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
                if (MPCF.Trim(txtInvLotID.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblInvLotId.Text + "]");
                    txtInvLotID.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:          
                        break;

                    case CSGC.CHECK.SAVE:
                        if (inv_lot_id == "") return false;

                        if (MPCF.Trim(cdvHoldCode.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblHoldCode.Text + "]");
                            txtInvLotID.Focus();
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

        //자재 LOT정보 초기화
        private void ClearInvLot()
        {
            try
            {
                txtMatId.Text = "";
                txtMatDesc.Text = "";
                txtOper.Text = "";
                txtOperDesc.Text = "";
                txtQty.Text = "";
                txtHoldFlag.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //자재 LOT정보 조회
        private void ViewInvLot(string invLotId)
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CINV2006-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INV_LOT_ID";
                dvcArgu[1].sCondition_Value = invLotId;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    txtInvLotID.SelectAll();
                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    txtMatId.Text = dt.Rows[i]["MAT_ID"].ToString();
                    txtMatDesc.Text = dt.Rows[i]["MAT_DESC"].ToString();
                    txtAreaId.Text = dt.Rows[i]["AREA_DESC"].ToString();
                    txtSubAreaId.Text = dt.Rows[i]["SUB_AREA_DESC"].ToString();
                    txtOper.Text = dt.Rows[i]["OPER"].ToString(); 
                    txtOperDesc.Text = dt.Rows[i]["OPER_DESC"].ToString();
                    txtQty.Text = dt.Rows[i]["QTY"].ToString();
                    txtUnit.Text = dt.Rows[i]["UNIT"].ToString();
                    txtInvLotType.Text = dt.Rows[i]["INV_LOT_TYPE"].ToString();
                    txtInvLotStatus.Text = dt.Rows[i]["INV_LOT_STATUS"].ToString();
                    txtHoldFlag.Text = dt.Rows[i]["HOLD_FLAG"].ToString(); 
                }

                txtInvLotID.SelectAll();
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //자재 잠금
        private bool HoldLot()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode inv_lot_list;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                inv_lot_list = in_node.AddNode("INV_LOT_LIST");
                inv_lot_list.AddString("INV_LOT_ID", inv_lot_id);

                in_node.AddString("HOLD_CODE", cdvHoldCode.Text);
                in_node.AddString("TRAN_COMMENT", txtTranComment.Text);

                if (MPCR.CallService("CUS_INV", "CUS_INV_Hold_Lot", in_node, ref out_node) == false)
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

        #endregion

        #region " Event Definition "
        private void cdvHoldCode_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvHoldCode.Init();
                MPCF.InitListView(cdvHoldCode.GetListView);
                cdvHoldCode.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvHoldCode.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvHoldCode.SelectedSubItemIndex = 0;
                cdvHoldCode.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvHoldCode.GetListView, '1', CSGC.CP_GCM_INV_HOLD_CODE) == false)
                {
                    return;
                }

                cdvHoldCode.InsertEmptyRow(0, 1);
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

                if (HoldLot())
                {
                    ClearInvLot();
                    ViewInvLot(inv_lot_id);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtInvLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (CheckCondition(CSGC.CHECK.VIEW) == false)
                        return;

                    inv_lot_id = MPCF.Trim(txtInvLotID.Text);

                    ClearInvLot();
                    ViewInvLot(inv_lot_id);
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
