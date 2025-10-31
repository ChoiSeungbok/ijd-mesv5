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

namespace CUS_COM
{
    public partial class frmPopPackLotList : frmTranForm03
    {
        public frmPopPackLotList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT_INFO
        {
            CHK,                    // 1 : CHECK
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 제품코드
            MAT_DESC,               // 4 : 제품명            
            QTY,                    // 5 : 생산수량
            UNIT,                   // 6 : 생산수량
            OPER,                   // 7 : 마지막 트랜잭션
            OPER_DESC               // 8 : 마지막 주석
        }

        #endregion

        #region " Variable Definition "
        
        public string sArea_id = "";
        public string sArea_desc = "";
        public string sOper_id = "";       
        public string sOper_desc = "";
        public string sMat_id = "";
        public bool b_Stop_Flag = false;
        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //LOT ID 조회 함수
        private void ViewLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvPackOper.Text;

                dvcArgu[3].sCondition_ID = "MAT_ID";
                dvcArgu[3].sCondition_Value = cdvMatID.Text;



                if (TPDR.GetDataOne("", ref dt, "CCOM3007-001", dvcArgu, false, false, ref sSql) == false)
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
                    spdLotList_Sheet1.RowCount++;

                    spdLotList_Sheet1.SetValue(i, (int)LOT_INFO.CHK, false);
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.QTY].Value = dt.Rows[i]["QTY_1"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.UNIT].Value = dt.Rows[i]["UNIT_1"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                }

                MPCF.FitColumnHeader(spdLotList);

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

                        if (MPCF.Trim(cdvPackOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblPackOper.Text + "]");
                            cdvPackOper.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvMatID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMatID.Text + "]");
                            cdvMatID.Focus();
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

        private void CheckCount()
        {
            double dSumQty = 0;
            int iCount = 0;

            try
            {
                for (int i = 0; i < spdLotList_Sheet1.RowCount; i++)
                {
                    if (spdLotList_Sheet1.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.QTY].Text);
                    }
                }

                spdLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT_INFO.CHK].Value = iCount;
                spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT_INFO.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmPopPackLotList_Load(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Text = sArea_id;
                cdvDept.DisplayText = sArea_desc;
                cdvPackOper.Text = sOper_id;
                cdvPackOper.DisplayText = sOper_desc;
                cdvMatID.Text = sMat_id;

                btnView_Click(null, null);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtCheckCount_KeyPress(object sender, KeyPressEventArgs e)
        {
            int iCheckCount = 1;
            int iCount = 0;

            try
            {
                iCheckCount = MPCF.ToInt(txtCheckCount.Text);
                
                if (iCheckCount == 0)
                    iCheckCount = 1;

               
                for (int k = 0; k < spdLotList.ActiveSheet.RowCount; k++)
                {
                    if (iCheckCount <= iCount)
                        break;

                    spdLotList.ActiveSheet.Cells[k, (int)LOT_INFO.CHK].Value = true;

                    iCount++;
                }

                CheckCount();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        
        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdLotList, e.Row, e.Column, true, true, false);
                }

                CheckCount();
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewLotList();
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
                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        CSGV.l_lot_list.Add(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);

                        if(b_Stop_Flag == true)
                        {
                            break;
                        }
                    }                        
                }

                if(CSGV.l_lot_list.Count > 0)
                    this.DialogResult = DialogResult.OK;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            try
            {
                CheckCount();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                CheckCount();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion
    }
}
