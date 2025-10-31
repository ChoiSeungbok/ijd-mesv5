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

namespace CUS_ORD
{
    public partial class frmTranLotMapping : frmTranForm03
    {
        public frmTranLotMapping()
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
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;


                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;


                dvcArgu[2].sCondition_ID = "OPER";
                dvcArgu[2].sCondition_Value = cdvInvOper.Text;


                dvcArgu[3].sCondition_ID = "LOT_ID";
                dvcArgu[3].sCondition_Value = txtLotID.Text + "%";


                dvcArgu[4].sCondition_ID = "MAT_ID";
                dvcArgu[4].sCondition_Value = txtLotID.Text + "%";



                //   dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                //   dvcArgu[2].sCondition_Value = cdvWorkPlace.Text;

                // dvcArgu[4].sCondition_ID = "ORDER_ID";
                //   dvcArgu[4].sCondition_Value = cdvOrder.Text + "%";

                //  dvcArgu[5].sCondition_ID = "RES_ID";
                // dvcArgu[5].sCondition_Value = cdvResource.Text + "%";


                if (TPDR.GetDataOne("", ref dt, "CORD2003-001", dvcArgu, false, false, ref sSql) == false)
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

        private void frmTranLotMapping_Load(object sender, EventArgs e)
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

                chkMulti.Checked = true;

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
                if (SaveLotOrder('1') == true)
                {
                    if(SaveLotOrder('2') == true)
                    {
                      
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private bool SaveLotOrder(char sStep)
        {
            try
            {



                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                TRSNode Lot_list;
                TRSNode Worker_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("ORDER_ID", cdvOrder.Text);
                in_node.AddString("RES_ID", cdvResource.Text);
                in_node.AddString("COMMENT", "");

                //in_node.AddString("TO_OPER", spdLotList.ActiveSheet.Cells[iActiceRow, (int)LOT_INFO.TO_OPER].Text);


                for (int iRow = 0; iRow < spdLotList.ActiveSheet.RowCount; iRow++)
                {

                    if (spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        Lot_list = in_node.AddNode("LOT_TBL");
                        Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.LOT_ID].Text);
                        Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.QTY].Text));
                        Lot_list.AddDouble("GOOD_QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[iRow, (int)LOT_INFO.QTY].Text));
                        Lot_list.AddDouble("LOSS_QTY_1", 0);
                        Lot_list.AddString("COMMENT", "");

                        Worker_list = in_node.AddNode("WORKER_TBL");
                        Worker_list.AddString("WORKER_ID", "");

                    }

                }


                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Process_Lot", in_node, ref out_node) == false)
                {
                    return false;
                }
                else
                {
                    MPCR.ShowSuccessMsg(out_node);

                    return true;
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }





        #endregion

        private void cdvInvOper_ButtonPress(object sender, EventArgs e)
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


                TRSNode in_node = new TRSNode("SQL_IN");
                TRSNode out_node = new TRSNode("SQL_OUT");

                MPCF.InitListView(cdvInvOper.GetListView);

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';



             //   string sOperSql = "";
              //  sOperSql = " AND OPER_CMF_12 = 'INV' ";


                in_node.AddString("SQL", "SELECT OPER AS CODE "
                                       + "      ,OPER_DESC AS VALUE FROM MWIPOPRDEF"
                                       + "  WHERE FACTORY ='" + MPGV.gsFactory + "' AND AREA_ID = '" + cdvDept.Text + "' AND OPER_CMF_12 = 'INV'  ORDER BY 1,2");


                do
                {
                    if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                    {
                        return;
                    }

                    MPCR.FillDataView(cdvInvOper.GetListView, out_node);

                    in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
                } while (out_node.GetInt("NEXT_ROW") > 0);


                cdvInvOper.InsertEmptyRow(0, 1);




            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }
    }
}
