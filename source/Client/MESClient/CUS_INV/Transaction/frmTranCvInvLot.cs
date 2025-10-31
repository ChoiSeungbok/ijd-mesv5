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
    public partial class frmTranCvInvLot : CUS_COM.frmViewForm01
    {
        public frmTranCvInvLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT_INFO
        {
            CHK,                   
            INV_LOT_ID,             
            QTY,                
            CHG_QTY,              
            SAVE_YN
        }                                                    

        #endregion

        #region " Variable Definition "

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

        private void ViewLotInfo()
        {
            int iRow = 0;

            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '2';
                in_node.AddString("LOT_ID", txtInvLotID.Text);
                in_node.AddChar("SKIP_DELL_FLAG", 'Y');

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_Info", in_node, ref out_node) == false)
                {
                    return;
                }
                for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                {
                    iRow = spdInvLot.ActiveSheet.RowCount;

                    spdInvLot.ActiveSheet.RowCount++;
                    spdInvLot.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CHK, false);
                    spdInvLot.ActiveSheet.SetValue(iRow, (int)LOT_INFO.INV_LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                    spdInvLot.ActiveSheet.SetValue(iRow, (int)LOT_INFO.QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                    spdInvLot.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CHG_QTY, 0);
                    spdInvLot.ActiveSheet.SetValue(iRow, (int)LOT_INFO.SAVE_YN, "");               
                }

                MPCF.FitColumnHeader(spdInvLot);

                txtInvLotID.Text = "";

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private bool TranCv()
        {
            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");

                for (int i = 0; i < spdInvLot.ActiveSheet.RowCount; i++)
                {
                    if (spdInvLot.ActiveSheet.Cells[i,(int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        in_node.Init();
                        MPCR.SetInMsg(in_node);
                        in_node.ProcStep = '1';

                        in_node.AddString("INV_LOT_ID", spdInvLot.ActiveSheet.Cells[i, (int)LOT_INFO.INV_LOT_ID].Text);
                        in_node.AddDouble("QTY_1", spdInvLot.ActiveSheet.Cells[i, (int)LOT_INFO.CHG_QTY].Text);

                        if (MPCR.CallService("CUS_INV", "CUS_INV_Tran_Multi_Cv_Lot", in_node, ref out_node, true) == false)
                        {
                            spdInvLot.ActiveSheet.Cells[i, (int)LOT_INFO.SAVE_YN].Value = MPCF.FindLanguage("NG", 0);
                        }
                        else
                        {
                            spdInvLot.ActiveSheet.Cells[i, (int)LOT_INFO.SAVE_YN].Value = MPCF.FindLanguage("SUCCESS", 0);
                            spdInvLot.ActiveSheet.Cells[i, 0].Value = false;
                        }
                    }

                    CSCF.SetPosition(spdInvLot, i, 0);
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

        private void frmTranCvInvLot_Load(object sender, EventArgs e)
        {

        }

        private void txtInvLotID_KeyPress(object sender, KeyPressEventArgs e)
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

        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                MPCF.ClearList(spdInvLot);
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
                TranCv();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}
