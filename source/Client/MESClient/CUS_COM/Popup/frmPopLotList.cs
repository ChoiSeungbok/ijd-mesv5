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
    public partial class frmPopLotList : frmTranForm03
    {
        public frmPopLotList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT_INFO
        {
            CHK,                    // 1 : CHECK
            ORDER_ID, 
            LOT_ID,                 // 2 : LOT ID
            MAT_ID,                 // 3 : 제품코드
            MAT_DESC,               // 4 : 제품명            
            QTY,                    // 5 : 생산수량
            UNIT,                   // 6 : 생산수량
            LAST_TRAN_CODE,         // 7 : 마지막 트랜잭션
            LAST_COMMENT,           // 8 : 마지막 주석
            CREATE_DATE,            // 9 : 생성일자
            GROUP_ID,               // 10: 그룹번호
            GROUP_SEQ               // 11: 그룹번호 순번
        }

        #endregion

        #region " Variable Definition "

        public string sLot_id = "";

        public string sArea_id = "";
        public string sArea_desc = "";
        public string sSub_area_id = "";
        public string sSub_area_desc = "";
        public string sOper_id = "";       
        public string sOper_desc = "";
        public string sOrder_id = "";
        public string sRes_id = "";
        public string sRes_desc = "";

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

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvOper.Text + "%";

                dvcArgu[4].sCondition_ID = "ORDER_ID";
                dvcArgu[4].sCondition_Value = cdvOrder.Text + "%";

                dvcArgu[5].sCondition_ID = "RES_ID";
                dvcArgu[5].sCondition_Value = cdvResource.Text + "%";

                dvcArgu[6].sCondition_ID = "LOT_ID";
                dvcArgu[6].sCondition_Value = txtLotID.Text + "%";

                if (TPDR.GetDataOne("", ref dt, "CCOM3002-001", dvcArgu, false, false, ref sSql) == false)
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
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.QTY].Value = dt.Rows[i]["QTY_1"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.UNIT].Value = dt.Rows[i]["UNIT_1"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LAST_TRAN_CODE].Value = dt.Rows[i]["LAST_TRAN_CODE"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LAST_COMMENT].Value = dt.Rows[i]["LAST_COMMENT"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.GROUP_ID].Value = dt.Rows[i]["GROUP_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.GROUP_SEQ].Value = dt.Rows[i]["GROUP_SEQ"];
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

                        if (MPCF.Trim(cdvWorkPlace.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                            cdvWorkPlace.Focus();
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

        #endregion

        #region " Event Definition "

        private void frmPopLotList_Load(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Text = sArea_id;
                cdvDept.DisplayText = sArea_desc;
                cdvWorkPlace.Text = sSub_area_id;
                cdvWorkPlace.DisplayText = sSub_area_desc;
                cdvOper.Text = sOper_id;
                cdvOper.DisplayText = sOper_desc;
                cdvOrder.Text = sOrder_id;
                cdvResource.Text = sRes_id;
                cdvResource.DisplayText = sRes_desc;

                chkMulti.Checked = false;

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
                if (chkMulti.Checked == false)
                {
                    for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        if (i == e.Row)
                            continue;

                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value = false;
                    }
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
                if (chkMulti.Checked == true)
                {
                    if (e.ColumnHeader)
                    {
                        if (e.Column == (int)LOT_INFO.CHK)
                        {
                            if (spdLotList.ActiveSheet.ColumnHeader.Cells[0, e.Column].Value == null ||
                                spdLotList.ActiveSheet.ColumnHeader.Cells[0, e.Column].Value.Equals(" ") ||
                                spdLotList.ActiveSheet.ColumnHeader.Cells[0, e.Column].Value.Equals(false))
                            {
                                spdLotList.ActiveSheet.ColumnHeader.Cells[0, e.Column].Value = true;
                            }
                            else
                            {
                                spdLotList.ActiveSheet.ColumnHeader.Cells[0, e.Column].Value = !Convert.ToBoolean(spdLotList.ActiveSheet.ColumnHeader.Cells[0, e.Column].Value);
                            }

                            for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                            {
                                spdLotList.ActiveSheet.Cells[i, e.Column].Value = spdLotList.ActiveSheet.ColumnHeader.Cells[0, e.Column].Value;

                            }
                        }
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
                if (chkMulti.Checked == false)
                {
                    for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                        {
                            sLot_id = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text;

                            this.DialogResult = DialogResult.OK;
                            break;
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                        {
                            //spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text;
                            CSGV.l_lot_list.Add(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                        }                        
                    }

                    if(CSGV.l_lot_list.Count > 0)
                        this.DialogResult = DialogResult.OK;
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
