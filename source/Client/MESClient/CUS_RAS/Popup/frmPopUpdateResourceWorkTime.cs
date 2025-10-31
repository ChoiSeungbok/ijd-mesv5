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

//CRAS0002
namespace CUS_RAS
{
    public partial class frmPopUpdateResourceWorkTime : CUS_COM.frmViewForm01
    { 
        public frmPopUpdateResourceWorkTime()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT_INFO : int
        {
            CHK,
            LOT_ID,
            START_TIME,
            END_TIME
        }

        #endregion

        #region " Variable Definition "

        public string sLot_ID = "";
        public string sOper = "";
        public string sOper_desc = "";
        public string sRes_ID = "";
        public string sRes_desc = "";

        string sMultikey = "";
        string sTrancode = "";

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSave.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewLotInfo()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";

                sMultikey = "";
                sTrancode = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = txtLotID.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CRAS0002-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                txtStartTime.Text = MPCF.MakeDateFormat(dt.Rows[0]["START_TIME"].ToString());
                txtEndTime.Text = MPCF.MakeDateFormat(dt.Rows[0]["END_TIME"].ToString());

                //기본 저장된 시간으로 보여준다.
                if (MPCF.Trim(dt.Rows[0]["START_TIME"].ToString()) != "")
                {
                    dtpFromDate.Value = MPCF.ToDate(dt.Rows[0]["START_TIME"].ToString());
                    dtpFromTime.Value = MPCF.ToDate(dt.Rows[0]["START_TIME"].ToString());
                }

                if (MPCF.Trim(dt.Rows[0]["END_TIME"].ToString()) != "")
                {
                    dtpToDate.Value = MPCF.ToDate(dt.Rows[0]["END_TIME"].ToString());
                    dtpEndTime.Value = MPCF.ToDate(dt.Rows[0]["END_TIME"].ToString());
                }

                if (MPCF.Trim(cdvResId.Text) == "")
                {
                    cdvResId.Text= dt.Rows[0]["RES_ID"].ToString();
                    cdvResId.DisplayText = dt.Rows[0]["RES_DESC"].ToString();
                }
                
                sMultikey = dt.Rows[0]["MULTI_TR_KEY"].ToString();
                sTrancode = dt.Rows[0]["TRAN_CODE"].ToString();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                int i = 0;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = txtLotID.Text;

                dvcArgu[2].sCondition_ID = "MULTI_TR_KEY";
                dvcArgu[2].sCondition_Value = sMultikey;

                dvcArgu[3].sCondition_ID = "TRAN_CODE";
                dvcArgu[3].sCondition_Value = sTrancode;

                if (TPDR.GetDataOne("", ref dt, "CRAS0002-002", dvcArgu, false, false, ref sSql) == false)
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
                    spdLotList.ActiveSheet.RowCount++;

                    spdLotList.ActiveSheet.SetValue(i, (int)LOT_INFO.CHK, false);
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.START_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["START_TIME"].ToString()); ;
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.END_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["END_TIME"].ToString());
                }

                MPCF.FitColumnHeader(spdLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool SaveLotTime()
        {
            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                TRSNode Lot_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                //in_node.AddString("LOT_ID", txtLotID.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("RES_ID", cdvResId.Text);

                Lot_list = in_node.AddNode("LOT_TBL");
                Lot_list.AddString("LOT_ID", txtLotID.Text);

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        Lot_list = in_node.AddNode("LOT_TBL");
                        Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                    }
                }

                in_node.AddString("START_TIME", dtpFromDate.Text.Replace("-", "") + dtpFromTime.Text.Replace(":", "") + "00");
                in_node.AddString("END_TIME", dtpToDate.Text.Replace("-", "") + dtpEndTime.Text.Replace(":", "") + "00");

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Update_Lot_Res_Worktime", in_node, ref out_node) == false)
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
            try
            {
                string sStartTime = "";
                string sEndTime = "";

                if (MPCF.Trim(txtLotID.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotID.Text + "]");
                    txtLotID.Focus();
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

                    case CSGC.CHECK.SAVE:

                        sStartTime = dtpFromDate.Text.Replace("-", "") + dtpFromTime.Text.Replace(":", "");
                        sEndTime = dtpToDate.Text.Replace("-", "") + dtpEndTime.Text.Replace(":", "");

                        if (MPCF.ToDbl(sStartTime) > MPCF.ToDbl(sEndTime))
                        {
                            //CMN108 ERROR - 시작 시간이 완료 시간보다 큽니다. 시간을 확인하세요.
                            MPCF.ShowMsgBox("시작 시간이 완료 시간보다 큽니다. 시간을 확인하세요.");                            
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

        private void frmPopUpdateResourceWorkTime_Load(object sender, EventArgs e)
        {
            try
            {
                txtLotID.Text = sLot_ID;
                cdvOper.Text = sOper;
                cdvOper.DisplayText = sOper_desc;
                cdvResId.Text = sRes_ID;
                cdvResId.DisplayText = sRes_desc;

                if (MPCF.Trim(txtLotID.Text) != "" && MPCF.Trim(cdvOper.Text) != "")
                {
                    btnView_Click(null, null);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)LOT_INFO.CHK)
                    {
                        CSCF.CheckSpreadCell(spdLotList, 0, 0, true, true);
                    }
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

                ViewLotInfo();

                if (MPCF.Trim(sMultikey) != "")
                {
                    ViewLotList();                
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SaveLotTime())
                {
                    btnView.PerformClick();
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
