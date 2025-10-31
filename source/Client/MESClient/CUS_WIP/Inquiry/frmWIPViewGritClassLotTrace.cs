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
using FarPoint.Win.Spread;
//CWIP3023
namespace CUS_WIP
{
    public partial class frmWIPViewGritClassLotTrace : CUS_COM.frmViewForm03
    {
        public frmWIPViewGritClassLotTrace()
        {
            InitializeComponent();
            InitControl();
        }

        #region " Constant Definition "

        private enum LOT_INFO
        {
            LEVEL,
            OPER, 
            OPER_DESC, 
            FROM_LOT_ID,
            FROM_QTY_1,
            INPUT_MAT_ID, 
            INPUT_MAT_DESC, 
            OUT_LOT_ID,
            QTY_1,
            OUT_MAT_ID,            
            OUT_MAT_DESC,
            CLASS_TYPE,
            CLASS_TYPE_DESC,
            CLASS_VALUE,
            CLASS_VALUE_DESC
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
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewTrace()
        {
            string sViewID = "";
            string sSql = "";
             
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;

                if(rdoDwUp.Checked == true)
                    sViewID = "CWIP3023-001";
                else if (rdoUpDw.Checked == true)
                    sViewID = "CWIP3023-002";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "LOT_ID";
                dvcArgu[2].sCondition_Value = txtLotID.Text;

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLotList);
                    return;
                }

                MPCF.ClearList(spdLotList);

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList.ActiveSheet.RowCount++;

                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LEVEL].Value = dt.Rows[i]["LVL"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.FROM_LOT_ID].Value = dt.Rows[i]["FROM_LOT_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.FROM_QTY_1].Value = dt.Rows[i]["FROM_QTY_1"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.INPUT_MAT_ID].Value = dt.Rows[i]["INPUT_MAT_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.INPUT_MAT_DESC].Value = dt.Rows[i]["INPUT_MAT_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.OUT_LOT_ID].Value = dt.Rows[i]["OUT_LOT_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.QTY_1].Value = dt.Rows[i]["QTY_1"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.OUT_MAT_ID].Value = dt.Rows[i]["OUT_MAT_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.OUT_MAT_DESC].Value = dt.Rows[i]["OUT_MAT_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CLASS_TYPE].Value = dt.Rows[i]["CLASS_TYPE"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CLASS_TYPE_DESC].Value = dt.Rows[i]["CLASS_TYPE_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CLASS_VALUE].Value = dt.Rows[i]["CLASS_VALUE"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CLASS_VALUE_DESC].Value = dt.Rows[i]["CLASS_VALUE_DESC"];

                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.FROM_LOT_ID].Text == txtLotID.Text)                        
                    {
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.FROM_LOT_ID].Font = new Font(this.Font, FontStyle.Bold);
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.FROM_LOT_ID].BackColor = Color.Yellow;

                    }
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.OUT_LOT_ID].Text == txtLotID.Text)
                    {
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.OUT_LOT_ID].Font = new Font(this.Font, FontStyle.Bold);
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.OUT_LOT_ID].BackColor = Color.Yellow;
                    }
                }

                MPCF.FitColumnHeader(spdLotList);
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
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        if (MPCF.Trim(cdvDept.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }

                        if (MPCF.Trim(txtLotID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotID.Text + "]");
                            txtLotID.Focus();
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

        private void ClearData()
        {
            try
            {
                MPCF.ClearList(spdLotList);

                rdoDwUp.Checked = true;
                rdoUpDw.Checked = false;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmWIPViewGritClassLotTrace_Load(object sender, EventArgs e)
        {
            try
            {
                rdoDwUp.Checked = true;
                rdoUpDw.Checked = false;
                cdvDept.Text = CSGV.gs_area_grit;
                cdvDept.DisplayText = "Grit";
                cdvDept.Enabled = false;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void rdo_CheckedChanged(object sender, EventArgs e)
        {
            try
            {
                MPCF.ClearList(spdLotList);

                if (MPCF.Trim(txtLotID.Text) != "")
                {
                    btnView.PerformClick();
                }                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_CellDoubleClick(object sender, CellClickEventArgs e)
        {
            string sLot_id = "";

            try
            {
                if (e.ColumnHeader)
                    return;

                if (e.Column == (int)LOT_INFO.FROM_LOT_ID || e.Column == (int)LOT_INFO.OUT_LOT_ID)
                {
                    sLot_id = spdLotList.ActiveSheet.Cells[e.Row, e.Column].Text;

                    if (sLot_id != "")
                    {
                        txtLotID.Text = sLot_id;
                        btnView.PerformClick();
                    }
                }
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

                ViewTrace();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            string sFileName = "";

            try
            {
                sFileName = "GritClassLotTrace";

                EXTFUC.SaveExcel(spdLotList, sFileName);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion


    }
}
