using CUS_COM;
using FarPoint.Win.Spread;
using Miracom.CliFrx;
using Miracom.DNMCore;
using Miracom.MESCore;
using Miracom.TRSCore;
using System;
using System.Collections.Generic;
using System.Data;
using System.IO.Ports;
using System.Windows.Forms;

namespace CUS_WIP
{
    public partial class frmTranChangeItem : frmTranForm01
    {
        public frmTranChangeItem()
        {
            InitializeComponent();
            InitControl();
        }

        private void frmTranChangeItem_Load(object sender, EventArgs e)
        {
            string[] s_port;
            bool bSkip = false;

            try
            {
                cdvWearHouse.ButtonPress += cdvWearHouse_ButtonPress;
                //chkNew.Checked = true; //우선 신규방식으로 채번을 체크한다.
                chkExist.Checked = true; //우선 신규방식으로 채번을 체크한다.

                s_port = SerialPort.GetPortNames();

                for (int i = 0; i < s_port.Length; i++)
                {
                    bSkip = false;

                    for (int k = 0; k < cboPort.Items.Count; k++)
                    {
                        if (cboPort.Items[k].ToString() == s_port[i])
                        {
                            bSkip = true;
                            break;
                        }
                    }

                    if (bSkip != true)
                    {
                        cboPort.Items.Add(s_port[i]);
                    }
                }
                cboPort.Items.Add("");

                rh_Sanner = new ReceivedHandler(rhText);

                if (cboPort.Text != "")
                {
                    Open_Port(cboPort.Text, 'N');
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        #region " Constant Definition "
        private enum BEFORE_LOT_INFO : int
        {
            CHECK,             // 1 : 선택
            LOT_ID,            // 2 : LOT ID
            MAT_ID,            // 3 : 품목코드
            MAT_DESC,          // 4 : 품목명
            MAT_TYPE,          // 5 : 품목유형
            QTY,               // 6 : 수량
            UNIT,              // 7 : 단위
            OPER_DESC,         // 8 : 창고명
            AREA_ID,           // 9 : 사업부
            SUB_AREA_ID,       // 10 : 작업장    
            OPER,              // 11 : 창고
            CREATE_CODE,       // 12 : 생성코드
            CREATE_CODE_DESC   // 13 : 생성코드
        }

        private enum AFTER_LOT_INFO : int
        {
            CHECK,             // 1 : 선택
            BEFORE_LOT_ID,     // 2 : BEFORE LOT ID
            AFTER_LOT_ID,      // 3 : AFTER LOT ID
            BEFORE_MAT_ID,     // 4 : BEFORE MAT ID
            AFTER_MAT_ID,      // 5 : AFTER_MAT_ID
            MAT_DESC,          // 6 : 품목명
            MAT_TYPE,          // 7 : 품목유형
            QTY,               // 8 : 수량
            UNIT,              // 9 : 단위
            OPER_DESC,         // 10 : 창고명
            CREATE_METHOD,     // 11 : LOT채번방식
            AREA_ID,           // 12 : 사업부
            SUB_AREA_ID,       // 13 : 작업장    
            OPER,              // 14 : 창고
            CREATE_CODE,       // 15 : 생성코드
            CREATE_CODE_DESC   // 16 : 생성코드
        }
        #endregion

        #region " Variable Definition "
        private string c_AfterMatType = string.Empty;
        #endregion

        #region " Grid/Button Event "

        private void cdvWearHouse_ButtonPress(object sender, EventArgs e)
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

                cdvWearHouse.Init();
                    MPCF.InitListView(cdvWearHouse.GetListView);
                cdvWearHouse.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWearHouse.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWearHouse.SelectedSubItemIndex = 0;
                cdvWearHouse.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvWearHouse.GetListView, '7', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }

                /*
                if (COM_LIST.ViewOperationList(cdvWearHouse.GetListView, 'T', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
                    {
                        return;
                    }
                    */

                cdvWearHouse.InsertEmptyRow(0, 1);
                }
                catch (Exception ex)
                {
                    MPCF.ShowMsgBox(ex.Message);
                }


            /*
             *             try
        {


            if (string.IsNullOrEmpty(cdvDept.Text))
                return;



            if (string.IsNullOrEmpty(cdvWorkPlace.Text))
                return;



            cdvWearHouse.Init();
            MPCF.InitListView(cdvWearHouse.GetListView);
            cdvWearHouse.Columns.Add("Operation", 50, HorizontalAlignment.Left);
            cdvWearHouse.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvWearHouse.SelectedSubItemIndex = 0;
            cdvWearHouse.DisplaySubItemIndex = 1;

            //창고 조회 부분
            int i;
            ListViewItem itmX;
            TRSNode in_node = new TRSNode("VIEW_OPERATION_LIST_IN");
            TRSNode out_node;


            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            in_node.AddString("AREA_ID", cdvDept.Text);
            in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
            in_node.AddChar("INV_FLAG", 'Y');

            in_node.AddString("NEXT_OPER", "");
            do
            {
                out_node = new TRSNode("VIEW_OPERATION_LIST_OUT");

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Oper_List", in_node, ref out_node) == false)
                {
                    return;
                }

                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    itmX = new ListViewItem(out_node.GetList(0)[i].GetString("OPER"), (int)SMALLICON_INDEX.IDX_OPER);
                    if (((ListView)cdvWearHouse.GetListView).Columns.Count > 1)
                    {
                        itmX.SubItems.Add(out_node.GetList(0)[i].GetString("OPER_DESC"));
                        itmX.SubItems.Add(out_node.GetList(0)[i].GetString("OPER_SHORT_DESC"));
                    }

                    ((ListView)cdvWearHouse.GetListView).Items.Add(itmX);
                }

                in_node.SetString("NEXT_OPER", out_node.GetString("NEXT_OPER"));

            } while (in_node.GetString("NEXT_OPER") != "");

            cdvWearHouse.InsertEmptyRow(0, 1);
        }
        catch (Exception ex)
        {
            MPCF.ShowMsgBox(ex.Message);
        }
        */
        }

        private void cdvBeforeMatId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.Width = 900;
                popup.Height = 500;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvBeforeMatId.Text = popup.sMat_id;
                    cdvBeforeMatId.DisplayText = popup.sMat_Desc;
                    cdvBeforeMatId.Tag = popup.sUnit;
                    popup = null;
                }
                else
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvAfterMatId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.Width = 900;
                popup.Height = 500;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvAfterMatId.Text = popup.sMat_id;
                    cdvAfterMatId.DisplayText = popup.sMat_Desc;
                    cdvAfterMatId.Tag = popup.sUnit;
                    c_AfterMatType = popup.sType_id;
                    popup = null;
                }
                else
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvPrintType_ButtonPress(object sender, EventArgs e)
        {
            string sViewId = "CWIP2021-002";
            string sSql = "";

            try
            {
                cdvPrintType.Init();
                MPCF.InitListView(cdvPrintType.GetListView);
                cdvPrintType.Columns.Add("Print Key", 50, HorizontalAlignment.Left);
                cdvPrintType.Columns.Add("Print Type", 100, HorizontalAlignment.Left);
                cdvPrintType.Columns.Add("Print Size", 50, HorizontalAlignment.Center);
                cdvPrintType.DisplaySubItemIndex = 1;

                ListViewItem itmX;

                TPDR.DirectViewCond[] dvcPrintType = new TPDR.DirectViewCond[2];
                DataTable dt = new DataTable();

                dvcPrintType[0].sCondition_ID = "P_FACTORY";
                dvcPrintType[0].sCondition_Value = MPGV.gsFactory;

                dvcPrintType[1].sCondition_ID = "P_AREA_ID";
                dvcPrintType[1].sCondition_Value = cdvDept.Text;

                if (TPDR.GetDataOne("", ref dt, sViewId, dvcPrintType, false, false, ref sSql) == false)
                {
                    if (dt == null || dt.Rows.Count == 0)
                    {
                        //추후 메시지 필요하면 추가하는 것으로 현재 다른화면도 없음
                    }
                    else
                    {
                        dt.Dispose();
                    }
                    return;
                }

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    itmX = new ListViewItem(dt.Rows[i]["PRINT_KEY"].ToString(), (int)SMALLICON_INDEX.IDX_SETUP);
                    if (((ListView)cdvPrintType.GetListView).Columns.Count > 1)
                    {
                        itmX.SubItems.Add(dt.Rows[i]["PRINT_TYPE"].ToString());
                        itmX.SubItems.Add(dt.Rows[i]["PRINT_SIZE"].ToString());
                    }

                    ((ListView)cdvPrintType.GetListView).Items.Add(itmX);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdBeforeLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)BEFORE_LOT_INFO.CHECK)
                    {
                        CSCF.CheckSpreadCell(spdBeforeLotList, 0, 0, true, true);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdAfterLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {              
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)AFTER_LOT_INFO.CHECK)
                    {
                        CSCF.CheckSpreadCell(spdAfterLotList, 0, 0, true, true);
                    }
                }    
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void chkNew_CheckedChanged(object sender, EventArgs e)
        {
            if (((CheckBox)sender).Checked)
            {
                chkInput.Checked = !((CheckBox)sender).Checked;
                chkExist.Checked = !((CheckBox)sender).Checked;
            }
        }

        private void chkInput_CheckedChanged(object sender, EventArgs e)
        {
            if (((CheckBox)sender).Checked)
            {
                chkNew.Checked = !((CheckBox)sender).Checked;
                chkExist.Checked = !((CheckBox)sender).Checked;

                txtLotId.Text = string.Empty;
                txtLotId.Enabled = ((CheckBox)sender).Checked;
            }
            else
            {
                txtLotId.Enabled = ((CheckBox)sender).Checked;
            }
        }

        private void chkExist_CheckedChanged(object sender, EventArgs e)
        {
            if (((CheckBox)sender).Checked)
            {
                chkNew.Checked = !((CheckBox)sender).Checked;
                chkInput.Checked = !((CheckBox)sender).Checked;
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.ADD) == false)
                    return;

                AddLot();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnDel_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.DELETE) == false)
                    return;

                DeleteLot();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.PRINT) == false)
                    return;

                PrintLot();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
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
                return;
            }
        }

        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if(ChangeItem())
                {
                    //ViewLotList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void txtBeforeLotID_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                ViewLot(txtBeforeLotID.Text);
                txtBeforeLotID.SelectAll();
            }
        }

        private void btnDelRow_Click(object sender, EventArgs e)
        {
            //txtBeforeLotID.Text = "";
            //cdvBeforeMatId.Text = "";
            //cdvBeforeMatId.DescText = "";

            for (int i = spdBeforeLotList_Sheet1.RowCount - 1; i >= 0; i--)
            {
                if (Convert.ToBoolean(spdBeforeLotList_Sheet1.Cells[i, (int)BEFORE_LOT_INFO.CHECK].Value))
                {
                    spdBeforeLotList_Sheet1.Rows[i].Remove();
                }
            }
        }

        private void txtBeforeLotID_Enter(object sender, EventArgs e)
        {
            txtBeforeLotID.SelectAll();
        }

        private void txtBeforeLotID_MouseDown(object sender, MouseEventArgs e)
        {
            txtBeforeLotID.SelectAll();
        }

        private void cdvBeforeMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvBeforeMatId.DisplayText == "")
                cdvBeforeMatId.Text = "";
        }

        private void cdvAfterMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvAfterMatId.DisplayText == "")
                cdvAfterMatId.Text = "";
        }

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

        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                SheetView svBeforeLot = spdBeforeLotList.ActiveSheet;
                SheetView svAfterLot = spdAfterLotList.ActiveSheet;
                int iCheckCount = 0;

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        if (string.IsNullOrEmpty(MPCF.Trim(cdvDept.Text)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }
                        /*
                        if (string.IsNullOrEmpty(MPCF.Trim(cdvWorkPlace.Text)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                            cdvWorkPlace.Focus();
                            return false;
                        }
                        */
                        /*
                        if (string.IsNullOrEmpty(MPCF.Trim(cdvWearHouse.Text)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvWearHouse.Focus();
                            return false;
                        }
                        */
                        //if (string.IsNullOrEmpty(MPCF.Trim(cdvBeforeMatId.Text)))
                        //{
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblBeforeMatId.Text + "]");
                        //    cdvBeforeMatId.Focus();
                        //    return false;
                        //}
                        break;
                    case CSGC.CHECK.ADD:
                        //변경 후 품목을 선택했는지 확인
                        if (string.IsNullOrEmpty(cdvAfterMatId.Text))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblAfterMatId.Text + "]");
                            cdvAfterMatId.Focus();
                            return false;
                        }

                        for (int i = 0; i < svBeforeLot.RowCount; i++)
                        {
                            //체크항목만 확인
                            if (Convert.ToBoolean(svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.CHECK].Value))
                            {
                                iCheckCount++;

                                string sBeforeUnit = svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.UNIT].Value.ToString();
                                string sBeforeMatType = svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.MAT_TYPE].Value.ToString();


                                /*
                                //단위가 똑같아야 ADD가능
                                if (cdvAfterMatId.Tag == null || sBeforeUnit != cdvAfterMatId.Tag.ToString())
                                {
                                    //CMN476 INFO - 변경하려는 품목의 단위가 다릅니다.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(476) + " [" + lblAfterMatId.Text + "]");
                                    cdvAfterMatId.Focus();
                                    return false;
                                }
                                */

                                //자재종류 확인 
                                //20210914 상품에서 재품으로 변경해야 되는 케이스 발생.으로 해당 체크 부분 삭제
                                /*
                                if (sBeforeMatType != c_AfterMatType)
                                {
                                    //CMN477 INFO - 변경하려는 품목의 종류가 다릅니다.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(477) + " [" + lblAfterMatId.Text + "]");
                                    cdvAfterMatId.Focus();
                                    return false;
                                }
                                */

                                for (int j = 0; j < svAfterLot.RowCount; j++)
                                {
                                    string sBeforeLot = svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.LOT_ID].Value.ToString();
                                    string sAfterBeforeLot = svAfterLot.Cells[i, (int)AFTER_LOT_INFO.BEFORE_LOT_ID].Value.ToString();

                                    if (sBeforeLot == sAfterBeforeLot)
                                    {
                                        //CMN111 ERROR - 데이타가 다른 데이타와 중복됩니다.
                                        MPCF.ShowMsgBox(j.ToString() + " - " + sBeforeLot + " : " + MPCF.GetMessage(111));
                                        spdAfterLotList.Focus();
                                        return false;
                                    }
                                }
                            }
                        }

                        if (iCheckCount <= 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(grpLotInfo.Text + " : " +MPCF.GetMessage(109));
                            return false;
                        }

                        //수기입력이체크되어있는경우 체크항목 하나만 옮길수 있도록 변경
                        if(chkInput.Checked)
                        {
                            if(string.IsNullOrEmpty(txtLotId.Text))
                            {
                                //CMN479 INFO - 수기입력방식인경우 LotID를 지정해주셔야 합니다.
                                MPCF.ShowMsgBox(MPCF.GetMessage(479));
                                txtLotId.Focus();
                                return false;
                            }

                            if(iCheckCount != 1)
                            {
                                //CMN480 INFO - 수기입력방식인경우 한 항목만 추가할수 있습니다.
                                MPCF.ShowMsgBox(MPCF.GetMessage(480));
                                spdBeforeLotList.Focus();
                                return false;
                            }
                        }
                        
                        break;

                    case CSGC.CHECK.DELETE:

                        for (int i = 0; i < svAfterLot.RowCount; i++)
                        {
                            //체크항목만 확인
                            if (Convert.ToBoolean(svAfterLot.Cells[i, (int)AFTER_LOT_INFO.CHECK].Value))
                            {
                                iCheckCount++;
                                for (int j = 0; j < svBeforeLot.RowCount; j++)
                                {
                                    string sBeforeLot = svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.LOT_ID].Value.ToString();
                                    string sAfterBeforeLot = svAfterLot.Cells[i, (int)AFTER_LOT_INFO.BEFORE_LOT_ID].Value.ToString();

                                    if (sBeforeLot == sAfterBeforeLot)
                                    {
                                        //CMN111 ERROR - 데이타가 다른 데이타와 중복됩니다.
                                        MPCF.ShowMsgBox(j.ToString() + " - " + sBeforeLot + " : " + MPCF.GetMessage(111));
                                        spdAfterLotList.Focus();
                                        return false;
                                    }
                                }
                            }
                        }

                        if (iCheckCount <= 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(grpLotInfo.Text + " : " + MPCF.GetMessage(109));
                            return false;
                        }

                        break;

                    case CSGC.CHECK.SAVE:
                        for (int i = 0; i < svAfterLot.RowCount; i++)
                        {
                            //체크항목만 확인
                            if (Convert.ToBoolean(svAfterLot.Cells[i, (int)AFTER_LOT_INFO.CHECK].Value))
                            {
                                iCheckCount++;
                            }
                        }

                        if (iCheckCount <= 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(grpLotInfo.Text + " : " + MPCF.GetMessage(109));
                            return false;
                        }

                        break;
                    case CSGC.CHECK.PRINT:

                        if (string.IsNullOrEmpty(MPCF.Trim(cdvPrintType.Text)))
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblPrintType.Text + "]");
                            cdvPrintType.Focus();
                            return false;
                        }

                        for (int i = 0; i < svAfterLot.RowCount; i++)
                        {
                            //체크항목만 확인
                            if (Convert.ToBoolean(svAfterLot.Cells[i, (int)AFTER_LOT_INFO.CHECK].Value))
                            {
                                string sAfterLot = svAfterLot.Cells[i, (int)AFTER_LOT_INFO.AFTER_LOT_ID].Value == null ? string.Empty : svAfterLot.Cells[i, (int)AFTER_LOT_INFO.AFTER_LOT_ID].Value.ToString();

                                if(string.IsNullOrEmpty(sAfterLot))
                                {
                                    
                                    //CMN483 INFO - LOT이 존재하지 않아 출력이 불가합니다.
                                    MPCF.ShowMsgBox(i.ToString() + " : " + MPCF.GetMessage(483));
                                    spdAfterLotList.Focus();
                                    return false;
                                    
                                }

                                iCheckCount++;
                            }
                        }

                        if (iCheckCount <= 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(grpLotInfo.Text + " : " + MPCF.GetMessage(109));
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

        private void ViewLotList()
        {
            string sSql = "";
            SheetView svBeforeLot = spdBeforeLotList.ActiveSheet;
            SheetView svAfterLot = spdAfterLotList.ActiveSheet;

            try
            {
                MPCF.ClearList(spdBeforeLotList);
                MPCF.ClearList(spdAfterLotList);
                svBeforeLot.ColumnHeader.Cells[0, (int)BEFORE_LOT_INFO.CHECK].Value = false;
                svAfterLot.ColumnHeader.Cells[0, (int)BEFORE_LOT_INFO.CHECK].Value = false;

                TPDR.DirectViewCond[] dvcItemList = new TPDR.DirectViewCond[4];
                DataTable dt = new DataTable();

                dvcItemList[0].sCondition_ID = "P_FACTORY";
                dvcItemList[0].sCondition_Value = MPGV.gsFactory;

                dvcItemList[1].sCondition_ID = "P_AREA_ID";
                dvcItemList[1].sCondition_Value = cdvDept.Text;

                dvcItemList[2].sCondition_ID = "P_OPER";
                dvcItemList[2].sCondition_Value = cdvWearHouse.Text;

                dvcItemList[3].sCondition_ID = "P_MAT_ID";
                dvcItemList[3].sCondition_Value = cdvBeforeMatId.Text == "" ? "%" : cdvBeforeMatId.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2021-001", dvcItemList, false, false, ref sSql) == false)
                {
                    if (dt == null || dt.Rows.Count == 0)
                    {
                        //추후 메시지 필요하면 추가하는 것으로 현재 다른화면도 없음
                    }
                    else
                    {
                        dt.Dispose();
                    }
                    return;
                }

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    svBeforeLot.RowCount++;
                    svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.CHECK].Value = false;
                    svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.MAT_TYPE].Value = dt.Rows[i]["MAT_TYPE"];
                    svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.UNIT].Value = dt.Rows[i]["UNIT"];
                    svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_ID"];
                    svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.CREATE_CODE_DESC].Value = dt.Rows[i]["CREATE_CODE_DESC"];
                }

                MPCF.FitColumnHeader(spdBeforeLotList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void AddLot()
        {
            try
            {
                SheetView svBeforeLot = spdBeforeLotList.ActiveSheet;
                SheetView svAfterLot = spdAfterLotList.ActiveSheet;

                int iAfterCount = svAfterLot.RowCount;
                int k = iAfterCount;

                for (int i = svBeforeLot.RowCount - 1; i >= 0; i--)
                {
                    //체크항목 추가
                    if (Convert.ToBoolean(svBeforeLot.Cells[i, (int)BEFORE_LOT_INFO.CHECK].Value))
                    {
                        

                        svAfterLot.RowCount++;
                        svAfterLot.Cells[k, (int)AFTER_LOT_INFO.CHECK].Value = true;
                        svAfterLot.Cells[k, (int)AFTER_LOT_INFO.BEFORE_LOT_ID].Value = svBeforeLot.GetValue(i, (int)BEFORE_LOT_INFO.LOT_ID);
                        svAfterLot.Cells[k, (int)AFTER_LOT_INFO.BEFORE_MAT_ID].Value = svBeforeLot.GetValue(i, (int)BEFORE_LOT_INFO.MAT_ID);
                        svAfterLot.Cells[k, (int)AFTER_LOT_INFO.AFTER_MAT_ID].Value = cdvAfterMatId.Text;
                        svAfterLot.Cells[k, (int)AFTER_LOT_INFO.MAT_DESC].Value = cdvAfterMatId.DisplayText;
                        svAfterLot.Cells[k, (int)AFTER_LOT_INFO.MAT_TYPE].Value = svBeforeLot.GetValue(i, (int)BEFORE_LOT_INFO.MAT_TYPE);
                        svAfterLot.Cells[k, (int)AFTER_LOT_INFO.QTY].Value = svBeforeLot.GetValue(i, (int)BEFORE_LOT_INFO.QTY);
                        svAfterLot.Cells[k, (int)AFTER_LOT_INFO.UNIT].Value = svBeforeLot.GetValue(i, (int)BEFORE_LOT_INFO.UNIT);
                        svAfterLot.Cells[k, (int)AFTER_LOT_INFO.OPER_DESC].Value = svBeforeLot.GetValue(i, (int)BEFORE_LOT_INFO.OPER_DESC);


                        //N : NEW, I : INPUT, E : EXIST
                        if (chkNew.Checked)
                        {
                            svAfterLot.Cells[k, (int)AFTER_LOT_INFO.CREATE_METHOD].Value = chkNew.Text; //방식명
                            svAfterLot.Cells[k, (int)AFTER_LOT_INFO.CREATE_METHOD].Tag = chkNew.Tag; //방식 타입 N
                        }
                        else
                        {
                            if (chkInput.Checked)
                            {
                                svAfterLot.Cells[k, (int)AFTER_LOT_INFO.CREATE_METHOD].Value = chkInput.Text; //방식명
                                svAfterLot.Cells[k, (int)AFTER_LOT_INFO.CREATE_METHOD].Tag = chkInput.Tag; //방식 타입 I
                                svAfterLot.Cells[k, (int)AFTER_LOT_INFO.AFTER_LOT_ID].Value = txtLotId.Text; //수기입력
                            }
                            else
                            {
                                if (chkExist.Checked)
                                {
                                    svAfterLot.Cells[k, (int)AFTER_LOT_INFO.CREATE_METHOD].Value = chkExist.Text; //방식명
                                    svAfterLot.Cells[k, (int)AFTER_LOT_INFO.CREATE_METHOD].Tag = chkExist.Tag; //방식 타입 E
                                }
                            }
                        }
                        
                        svAfterLot.Cells[k, (int)AFTER_LOT_INFO.AREA_ID].Value = svBeforeLot.GetValue(i, (int)BEFORE_LOT_INFO.AREA_ID);
                        svAfterLot.Cells[k, (int)AFTER_LOT_INFO.SUB_AREA_ID].Value = svBeforeLot.GetValue(i, (int)BEFORE_LOT_INFO.SUB_AREA_ID);
                        svAfterLot.Cells[k, (int)AFTER_LOT_INFO.OPER].Value = svBeforeLot.GetValue(i, (int)BEFORE_LOT_INFO.OPER);
                        svAfterLot.Cells[k, (int)AFTER_LOT_INFO.CREATE_CODE].Value = svBeforeLot.GetValue(i, (int)BEFORE_LOT_INFO.CREATE_CODE);
                        svAfterLot.Cells[k, (int)AFTER_LOT_INFO.CREATE_CODE_DESC].Value = svBeforeLot.GetValue(i, (int)BEFORE_LOT_INFO.CREATE_CODE_DESC);

                        svBeforeLot.RemoveRows(i, 1);

                        k++;
                    }
                }

                if (chkInput.Checked)
                    txtLotId.Text = string.Empty;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void DeleteLot()
        {
            try
            {
                SheetView svBeforeLot = spdBeforeLotList.ActiveSheet;
                SheetView svAfterLot = spdAfterLotList.ActiveSheet;

                int iBeforeCount = svBeforeLot.RowCount;
                int k = iBeforeCount;

                for (int i = svAfterLot.RowCount - 1; i >= 0; i--)
                {
                    //체크항목 추가
                    if (Convert.ToBoolean(svAfterLot.Cells[i, (int)AFTER_LOT_INFO.CHECK].Value))
                    {
                        svBeforeLot.RowCount++;
                        svBeforeLot.Cells[k, (int)BEFORE_LOT_INFO.CHECK].Value = false;
                        svBeforeLot.Cells[k, (int)BEFORE_LOT_INFO.LOT_ID].Value = svAfterLot.GetValue(i, (int)AFTER_LOT_INFO.BEFORE_LOT_ID);
                        svBeforeLot.Cells[k, (int)BEFORE_LOT_INFO.MAT_ID].Value = svAfterLot.GetValue(i, (int)AFTER_LOT_INFO.BEFORE_MAT_ID);
                        svBeforeLot.Cells[k, (int)BEFORE_LOT_INFO.MAT_DESC].Value = svAfterLot.GetValue(i, (int)AFTER_LOT_INFO.MAT_DESC);
                        svBeforeLot.Cells[k, (int)BEFORE_LOT_INFO.MAT_TYPE].Value = svAfterLot.GetValue(i, (int)AFTER_LOT_INFO.MAT_TYPE);
                        svBeforeLot.Cells[k, (int)BEFORE_LOT_INFO.QTY].Value = svAfterLot.GetValue(i, (int)AFTER_LOT_INFO.QTY);
                        svBeforeLot.Cells[k, (int)BEFORE_LOT_INFO.UNIT].Value = svAfterLot.GetValue(i, (int)AFTER_LOT_INFO.UNIT);
                        svBeforeLot.Cells[k, (int)BEFORE_LOT_INFO.OPER_DESC].Value = svAfterLot.GetValue(i, (int)AFTER_LOT_INFO.OPER_DESC);
                        svBeforeLot.Cells[k, (int)BEFORE_LOT_INFO.AREA_ID].Value = svAfterLot.GetValue(i, (int)AFTER_LOT_INFO.AREA_ID);
                        svBeforeLot.Cells[k, (int)BEFORE_LOT_INFO.SUB_AREA_ID].Value = svAfterLot.GetValue(i, (int)AFTER_LOT_INFO.SUB_AREA_ID);
                        svBeforeLot.Cells[k, (int)BEFORE_LOT_INFO.OPER].Value = svAfterLot.GetValue(i, (int)AFTER_LOT_INFO.OPER);
                        svBeforeLot.Cells[k, (int)BEFORE_LOT_INFO.CREATE_CODE].Value = svAfterLot.GetValue(i, (int)AFTER_LOT_INFO.CREATE_CODE);
                        svBeforeLot.Cells[k, (int)BEFORE_LOT_INFO.CREATE_CODE_DESC].Value = svAfterLot.GetValue(i, (int)AFTER_LOT_INFO.CREATE_CODE_DESC);

                        svAfterLot.RemoveRows(i, 1);

                        k++;
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool ChangeItem()
        {
            SheetView svAfterLot = spdAfterLotList.ActiveSheet;

            try
            {


                TRSNode in_node = new TRSNode("Change_In");
                TRSNode out_node = new TRSNode("Change_Out");
                TRSNode change_list;
                List<TRSNode> out_list = new List<TRSNode>();

                MPCR.SetInMsg(in_node);
                
                in_node.ProcStep = '1';

                for (int i = 0; i < svAfterLot.RowCount; i++)
                {
                    //체크된 항목 전송
                    if(Convert.ToBoolean(svAfterLot.Cells[i, (int)AFTER_LOT_INFO.CHECK].Value))
                    {
                        change_list = in_node.AddNode("CHANGE_LIST");
                        change_list.AddString("BEFORE_LOT_ID", svAfterLot.Cells[i, (int)AFTER_LOT_INFO.BEFORE_LOT_ID].Text);
                        change_list.AddString("BEFORE_MAT_ID", svAfterLot.Cells[i, (int)AFTER_LOT_INFO.BEFORE_MAT_ID].Text);
                        change_list.AddString("AFTER_MAT_ID", svAfterLot.Cells[i, (int)AFTER_LOT_INFO.AFTER_MAT_ID].Text);
                        change_list.AddString("AFTER_LOT_ID", svAfterLot.Cells[i, (int)AFTER_LOT_INFO.AFTER_LOT_ID].Text);
                        change_list.AddChar("CHANGE_FLAG", svAfterLot.Cells[i, (int)AFTER_LOT_INFO.CREATE_METHOD].Tag);
                    }
                }
                
                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Change_Item", in_node, ref out_node) == false)
                {
                    return false;
                }
                
                out_list = out_node.GetList("CHANGE_LIST");

                for (int i = 0; i < out_list.Count; i++)
                {
                    TRSNode node = out_list[i];

                    svAfterLot.Cells[i, (int)AFTER_LOT_INFO.AFTER_LOT_ID].Value = node.GetString("AFTER_LOT_ID");
                }
                
                MPCF.ShowMsgBox(out_node.Msg);
                return true;


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool PrintLot()
        {
            try
            {
                SheetView svAfterLot = spdAfterLotList.ActiveSheet;
                
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");

                MPCR.SetInMsg(in_node);

                //나중에 유형에 따라서 더 추가되어야 함
                //현재 컴이나 다른것에 대해 안되어있음

                for (int i = 0; i < svAfterLot.RowCount; i++)
                {
                    if (Convert.ToBoolean(svAfterLot.Cells[i, (int)AFTER_LOT_INFO.CHECK].Value))
                    {
                        label_list = in_node.AddNode("LOT_LIST");
                        label_list.AddString("LOT_ID", svAfterLot.GetValue(i, (int)AFTER_LOT_INFO.AFTER_LOT_ID));
                    }
                }

                CSCF.ViewLabelList(cdvPrintType.Text, in_node);
                
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        #endregion

        #region "Serial Definition"
        public delegate void ReceivedHandler(string sText);
        ReceivedHandler rh_Sanner;

        private void Open_Port(string s_port, char c_MsgYN)
        {
            try
            {
                if (spScanner.IsOpen == true)
                {
                    spScanner.Close();
                }

                spScanner.PortName = s_port;
                spScanner.BaudRate = 9600;
                spScanner.DataBits = 8;
                spScanner.Parity = Parity.None;
                spScanner.StopBits = StopBits.One;
                spScanner.Handshake = Handshake.None;
                spScanner.RtsEnable = false;
                spScanner.DtrEnable = false;

                spScanner.Open();
                if (spScanner.IsOpen == true)
                {
                    if (c_MsgYN == 'Y')
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(500));
                    }
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return;
            }
        }
        private void ViewLot(string as_lot_id)
        {
            TPDR.DirectViewCond[] dvcPrintType = new TPDR.DirectViewCond[4];
            DataTable dt = null;
            string sSql = "";

            int IRow = 0;

            try
            {
                if (string.IsNullOrEmpty(MPCF.Trim(cdvAfterMatId.Text)))
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblAfterMatId.Text + "]");
                    cdvAfterMatId.Focus();
                    return;
                }

                dvcPrintType[0].sCondition_ID = "P_FACTORY";
                dvcPrintType[0].sCondition_Value = MPGV.gsFactory;

                dvcPrintType[1].sCondition_ID = "P_AREA_ID";
                dvcPrintType[1].sCondition_Value = cdvDept.Text;

                dvcPrintType[2].sCondition_ID = "P_OPER";
                dvcPrintType[2].sCondition_Value = cdvWearHouse.Text;

                dvcPrintType[3].sCondition_ID = "LOT_ID";
                dvcPrintType[3].sCondition_Value = as_lot_id;

                if (TPDR.GetDataOne("", ref dt, "CWIP2021-003", dvcPrintType, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    // CMN515 INFO -해당 Lot을 찾수 없습니다. 조회 조건을 확인해세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(515));

                    return;
                }

                for (int i = 0; i < dt.Rows.Count; i++)
                {
                    IRow = spdAfterLotList.ActiveSheet.RowCount;

                    spdAfterLotList.ActiveSheet.RowCount++;
                    spdAfterLotList.ActiveSheet.Cells[i+IRow, (int)AFTER_LOT_INFO.CHECK].Value = true;
                    spdAfterLotList.ActiveSheet.Cells[i+IRow, (int)AFTER_LOT_INFO.BEFORE_LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdAfterLotList.ActiveSheet.Cells[i+IRow, (int)AFTER_LOT_INFO.BEFORE_MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdAfterLotList.ActiveSheet.Cells[i+IRow, (int)AFTER_LOT_INFO.AFTER_MAT_ID].Value = cdvAfterMatId.Text;
                    spdAfterLotList.ActiveSheet.Cells[i+IRow, (int)AFTER_LOT_INFO.MAT_DESC].Value = cdvAfterMatId.DisplayText;
                    spdAfterLotList.ActiveSheet.Cells[i+IRow, (int)AFTER_LOT_INFO.MAT_TYPE].Value = dt.Rows[i]["MAT_TYPE"];
                    spdAfterLotList.ActiveSheet.Cells[i+IRow, (int)AFTER_LOT_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdAfterLotList.ActiveSheet.Cells[i+IRow, (int)AFTER_LOT_INFO.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdAfterLotList.ActiveSheet.Cells[i+IRow, (int)AFTER_LOT_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];

                    //N : NEW, I : INPUT, E : EXIST
                    if (chkNew.Checked)
                    {
                        spdAfterLotList.ActiveSheet.Cells[i+IRow, (int)AFTER_LOT_INFO.CREATE_METHOD].Value = chkNew.Text; //방식명
                        spdAfterLotList.ActiveSheet.Cells[i+ IRow, (int)AFTER_LOT_INFO.CREATE_METHOD].Tag = chkNew.Tag; //방식 타입 N
                    }
                    else
                    {
                        if (chkInput.Checked)
                        {
                            spdAfterLotList.ActiveSheet.Cells[i+IRow, (int)AFTER_LOT_INFO.CREATE_METHOD].Value = chkInput.Text; //방식명
                            spdAfterLotList.ActiveSheet.Cells[i+IRow, (int)AFTER_LOT_INFO.CREATE_METHOD].Tag = chkInput.Tag; //방식 타입 I
                            spdAfterLotList.ActiveSheet.Cells[i+ IRow, (int)AFTER_LOT_INFO.AFTER_LOT_ID].Value = txtLotId.Text; //수기입력
                        }
                        else
                        {
                            if (chkExist.Checked)
                            {
                                spdAfterLotList.ActiveSheet.Cells[i+IRow, (int)AFTER_LOT_INFO.CREATE_METHOD].Value = chkExist.Text; //방식명
                                spdAfterLotList.ActiveSheet.Cells[i+ IRow, (int)AFTER_LOT_INFO.CREATE_METHOD].Tag = chkExist.Tag; //방식 타입 E
                            }
                        }
                    }

                    spdAfterLotList.ActiveSheet.Cells[i+IRow, (int)AFTER_LOT_INFO.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdAfterLotList.ActiveSheet.Cells[i+IRow, (int)AFTER_LOT_INFO.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_ID"];
                    spdAfterLotList.ActiveSheet.Cells[i+ IRow, (int)AFTER_LOT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    spdAfterLotList.ActiveSheet.Cells[i + IRow, (int)AFTER_LOT_INFO.CREATE_CODE].Value = dt.Rows[i]["CREATE_CODE"];
                    spdAfterLotList.ActiveSheet.Cells[i + IRow, (int)AFTER_LOT_INFO.CREATE_CODE_DESC].Value = dt.Rows[i]["CREATE_CODE_DESC"];

                    MPCF.FitColumnHeader(spdBeforeLotList);
                                       
                    //CSCF.SetPosition(spdBeforeLotList, IRow, iCol);
                    txtBeforeLotID.Text = "";

                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void btnPortOpen_Click(object sender, EventArgs e)
        {
            try
            {
                Open_Port(cboPort.Text, 'Y');
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmTranChangeItem_FormClosed(object sender, FormClosedEventArgs e)
        {
            try
            {
                spScanner.Close();

                if (cboPort.SelectedIndex != -1)
                    MPCF.SaveRegSetting(Application.ProductName, this.Name, cboPort.Name, cboPort.SelectedItem.ToString());
                else
                    MPCF.SaveRegSetting(Application.ProductName, this.Name, cboPort.Name, "");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void rhText(string sText)
        {
            ViewLot(sText);
        }

        private void cboPort_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if (cboPort.Text == "")
                {
                    if (spScanner.IsOpen == true)
                    {
                        spScanner.Close();
                    }
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void spScanner_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            string input = "";

            try
            {
                System.Threading.Thread.Sleep(100);

                input = spScanner.ReadExisting();

                if (!string.IsNullOrEmpty(input))
                {
                    string[] sInputData = input.Split('\r');

                    IAsyncResult result = BeginInvoke(rh_Sanner, sInputData[0]);
                    EndInvoke(result);
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        #endregion


    }
}
