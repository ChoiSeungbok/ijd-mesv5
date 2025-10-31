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
    public partial class frmTranMergeInvLot : CUS_COM.frmViewForm01
    {
        public frmTranMergeInvLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        #endregion

        #region " Variable Definition "

        string to_inv_lot_id = "";
        string from_inv_lot_id = "";
        bool sFlag = false;

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

        //To 자재 LOT정보 초기화
        private void ClearToInvLot()
        {
            try
            {
                txtToMatId.Text = "";
                txtToMatDesc.Text = "";
                txtToAreaId.Text = "";
                txtToSubAreaId.Text = "";
                txtToOper.Text = "";
                txtToOperDesc.Text = "";
                txtToHoldFlag.Text = "";
                txtToQty.Text = "";
                txtToUnit.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //From 자재 LOT정보 초기화
        private void ClearFromInvLot()
        {
            try
            {
                txtFromMatId.Text = "";
                txtFromMatDesc.Text = "";
                txtFromAreaId.Text = "";
                txtFromSubAreaId.Text = "";
                txtFromOper.Text = "";
                txtFromOperDesc.Text = "";
                txtFromHoldFlag.Text = "";
                txtFromQty.Text = "";
                txtFromUnit.Text = "";
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
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        break;

                    case CSGC.CHECK.SAVE:
                        if (MPCF.Trim(txtToInvLotID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToInvLotId.Text + "]");
                            txtToInvLotID.Focus();
                            return false;
                        }

                        if (MPCF.Trim(txtFromInvLotID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFromInvLotId.Text + "]");
                            txtFromInvLotID.Focus();
                            return false;
                        }
                        
                        if (to_inv_lot_id=="" || from_inv_lot_id=="")
                        {
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

                        if (sFlag==false)
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

        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "TO_INV_VIEW":
                        sFlag = false; 
                        ClearToInvLot();
                        break;

                    case "FROM_INV_VIEW":
                        sFlag = false;
                        ClearFromInvLot();
                        break;
                     
                    case "SAVE":
                        ClearToInvLot();
                        ClearFromInvLot();
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
               
        //To 자재 LOT정보 조회
        private void ViewToInvLot(string invLotId)
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

                    txtToInvLotID.SelectAll();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    txtToMatId.Text = dt.Rows[i]["MAT_ID"].ToString();
                    txtToMatDesc.Text =  dt.Rows[i]["MAT_DESC"].ToString();
                    txtToAreaId.Text = dt.Rows[i]["AREA_DESC"].ToString();
                    txtToSubAreaId.Text = dt.Rows[i]["SUB_AREA_DESC"].ToString();
                    txtToOper.Text = dt.Rows[i]["OPER"].ToString();
                    txtToOperDesc.Text = dt.Rows[i]["OPER_DESC"].ToString();
                    txtToHoldFlag.Text = dt.Rows[i]["HOLD_FLAG"].ToString();
                    txtToQty.Text = dt.Rows[i]["QTY"].ToString();
                    txtToUnit.Text = dt.Rows[i]["UNIT"].ToString();
                }

                txtToInvLotID.SelectAll();
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //From 자재 LOT정보 조회
        private void ViewFromInvLot(string invLotId)
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

                    txtFromInvLotID.SelectAll();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    txtFromMatId.Text = dt.Rows[i]["MAT_ID"].ToString();
                    txtFromMatDesc.Text = dt.Rows[i]["MAT_DESC"].ToString();
                    txtFromAreaId.Text = dt.Rows[i]["AREA_DESC"].ToString();
                    txtFromSubAreaId.Text = dt.Rows[i]["SUB_AREA_DESC"].ToString();
                    txtFromOper.Text = dt.Rows[i]["OPER"].ToString();
                    txtFromOperDesc.Text = dt.Rows[i]["OPER_DESC"].ToString();
                    txtFromHoldFlag.Text = dt.Rows[i]["HOLD_FLAG"].ToString();
                    txtFromQty.Text = dt.Rows[i]["QTY"].ToString();
                    txtFromUnit.Text = dt.Rows[i]["UNIT"].ToString();                    
                }

                txtFromInvLotID.SelectAll();
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool MergeLot()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                //TO 자재
                in_node.AddString("TO_INV_LOT_ID", to_inv_lot_id);
                //INTO 자재
                in_node.AddString("FROM_INV_LOT_ID", from_inv_lot_id);

                if (MPCR.CallService("CUS_INV", "CUS_INV_Merge_Lot", in_node, ref out_node) == false)
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
                label_list.AddString("INV_LOT_ID", to_inv_lot_id);

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
        

        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (MergeLot())
                {
                    sFlag = true;

                    ClearData("SAVE");

                    ViewToInvLot(to_inv_lot_id);
                    ViewFromInvLot(from_inv_lot_id);
                    btnPrint_Click(null, null);
                }
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
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

        private void txtToInvLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (CheckCondition(CSGC.CHECK.VIEW) == false)
                        return;

                    to_inv_lot_id = MPCF.Trim(txtToInvLotID.Text);

                    ClearData("TO_INV_VIEW");
                    ViewToInvLot(to_inv_lot_id);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtFromInvLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (CheckCondition(CSGC.CHECK.VIEW) == false)
                        return;

                    from_inv_lot_id = MPCF.Trim(txtFromInvLotID.Text);

                    ClearData("FROM_INV_VIEW");
                    ViewFromInvLot(from_inv_lot_id);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}
