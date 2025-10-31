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
    public partial class frmTranSplitInvLot : CUS_COM.frmViewForm01
    {
        public frmTranSplitInvLot()
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
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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

                        if (txtSplitQty.Text == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblSplitQty.Text + "]");
                            txtSplitQty.Focus();
                            return false;
                        }
                        //if(MPCF.ToInt(txtSplitQty.Text) <= 0)
                        //{
                        //    //CMN114 ERROR -0보다 큰 값을 입력해 주세요.
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(114));
                        //    txtSplitQty.Focus();
                        //    return false;
                        //}
                        if(MPCF.ToDbl(txtSplitQty.Text) < 0.00001)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(234) + "[ " + lblSplitQty.Text + " ]");
                            txtSplitQty.Focus();
                            return false;
                        }
                        break;

                    case CSGC.CHECK.PRINT:
                        //if (chkLabel.Checked == false)
                        //{
                        //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + chkLabel.Text + "]");
                        //    chkLabel.Focus();
                        //    return false;
                        //}

                        if (MPCF.Trim(txtSplitInvLotId.Text) == "")
                        {
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
                txtAreaId.Text = "";
                txtSubAreaId.Text = "";
                txtOper.Text = "";
                txtOperDesc.Text = "";
                txtQty.Text = "";
                txtUnit.Text = "";
                txtInvLotType.Text = "";
                txtInvLotStatus.Text = "";
                txtLastActiveHistSeq.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ClearData(string sType)
        {
            try
            {
                ClearInvLot();

                switch (sType)
                {
                    case "VIEW":                      
                        txtSplitQty.Text = "";
                        txtSplitInvLotId.Text = "";
                        txtOutSpliteLot.Text = "";

                        break;

                    case "SAVE":
                        break;
                }
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
                    txtLastActiveHistSeq.Text = dt.Rows[i]["LAST_ACTIVE_HIST_SEQ"].ToString();
                }

                txtInvLotID.SelectAll();
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //자재 분할
        private bool SplitLot()
        {
            try
            {


                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("INV_LOT_ID", inv_lot_id);

                if(MPCF.Trim(txtSplitInvLotId.Text).Length != 0)
                {
                    in_node.AddString("SPLIT_LOT_ID", MPCF.Trim(txtSplitInvLotId.Text));
                }

                
                in_node.AddInt("LAST_ACTIVE_HIST_SEQ", MPCF.ToInt(txtLastActiveHistSeq.Text));
                in_node.AddDouble("SPLIT_QTY", MPCF.ToDbl(txtSplitQty.Text));

                if (MPCR.CallService("CUS_INV", "CUS_INV_Split_Lot", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);

                txtSplitInvLotId.Text = "";

                txtOutSpliteLot.Text = out_node.GetString("SPLIT_LOT_ID");

              //  MPCF.ShowMsgBox( "Splite  Complete LOT: "  + out_node.GetString("SPLIT_LOT_ID"));

             //   txtSplitInvLotId.Text = out_node.GetString("SPLIT_LOT_ID");

                //   txtInvLotID.Text = out_node.GetString("SPLIT_LOT_ID");
                //  inv_lot_id = out_node.GetString("SPLIT_LOT_ID");



                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        // 라벨 프린트
        public bool ViewPrintLabel()
        {
            try
            {
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                string file_name = "mtl100p";

                MPCR.SetInMsg(in_node);
               
                label_list = in_node.AddNode("INV_LOT_LIST");
                label_list.AddString("INV_LOT_ID", inv_lot_id);

                label_list = in_node.AddNode("INV_LOT_LIST");
                label_list.AddString("INV_LOT_ID", txtOutSpliteLot.Text);

                CSCF.ViewLabelList(file_name, in_node, 'I');

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
        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;



                if (chkDirLot.Checked == true)
                {

                    //CMN571 INFO -수기로 입력한 LOT은 나중에 시스템에 전체적인 오류를 발생시킬수도 있습니다. 주의가 필요합니다.(진행하시겠습니까 ? Yes / No)
                    if (MPCF.ShowMsgBox(MPCF.GetMessage(571), MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.No)
                    {
                        return ;

                    }
                }
      
                    if (SplitLot())
                    {
                        ClearData("SAVE");
                        ViewInvLot(inv_lot_id);
                        ViewPrintLabel();
                    }




            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtSplitQty_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!(char.IsDigit(e.KeyChar) || e.KeyChar == Convert.ToChar(Keys.Back) || e.KeyChar == '.'))
            {
                e.Handled = true;
            }
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.PRINT) == false)
                    return;

                if (ViewPrintLabel())
                {
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

                    ClearData("VIEW");
                    ViewInvLot(inv_lot_id);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void chkDirLot_CheckedChanged(object sender, EventArgs e)
        {
            if (chkDirLot.Checked == true)
            {
                txtSplitInvLotId.ReadOnly = false;
                txtSplitInvLotId.Text = "";
                txtSplitInvLotId.BackColor = Color.FromArgb(255, 198, 198);
                txtSplitInvLotId.Focus();

            }
            else
            {
                txtSplitInvLotId.ReadOnly = true;
                txtSplitInvLotId.Text = "";
                txtSplitInvLotId.BackColor = Color.FromArgb(213, 213, 213);
                txtSplitQty.Focus();


            }
        }

        private void txtOutSpliteLot_DoubleClick(object sender, EventArgs e)
        {
            txtInvLotID.Text = txtOutSpliteLot.Text;

            inv_lot_id = MPCF.Trim(txtInvLotID.Text);

            ClearData("VIEW");
            ViewInvLot(inv_lot_id);

        }

        #endregion
    }
}
