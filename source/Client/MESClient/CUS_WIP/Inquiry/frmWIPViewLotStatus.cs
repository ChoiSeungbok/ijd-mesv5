using System;
using System.Collections.Generic;
using System.Data;
using System.Windows.Forms;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using FarPoint.Win.Spread;
using System.IO;
using System.IO.Ports;

namespace CUS_WIP
{
    public partial class frmWIPViewLotStatus : frmViewForm01
    {
        public frmWIPViewLotStatus()
        {
            InitializeComponent();
        }

        #region " Constant Definition "

        private enum LOT_INFO
        {
            CHK,                    // 1 : CHK
            OPER,                   // 2 : 공정
            LOT_ID,                 // 3 : LOT ID
            MAT_TYPE,               // 4 : 제품타입
            MAT_TYPE_DESC,          // 5 : 제품 타입명
            MAT_ID,                 // 6 : 제품코드
            MAT_DESC,               // 7 : 제품명            
            PROD_QTY,               // 8 : 생산수량
            WORK_TYPE,              // 9 : 작업 타입
            AREA_ID,                // 10: 사업부
            SUB_AREA_ID,            // 11:사업장
            ORDER_ID,               // 12:작업지시
            ORDER_STATUS,           // 13:작업지시 상태 
            INPUT_STATUS,           // 14:투입 여부
            GROUP_ID,               // 15:그룹 ID
            CREATE_TIME,            // 16:생성 시간
            INV_FLAG,               // 17:자재여부
            INSP_RESULT_DESC,       // 18:검사결과
            RESV_FIELD_3,
            COMMENT,
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

        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            SheetView sv = spdSearchLotList.ActiveSheet;
            int iCheckCount = 0;

            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            if (Convert.ToBoolean(sv.Cells[i, 0] == null ? false : sv.Cells[i, 0].Value))
                            {
                                if (sv.Cells[i, 1].Value != null && !string.IsNullOrEmpty(MPCF.Trim(sv.Cells[i, 1])))
                                {
                                    iCheckCount++;
                                }
                            }
                        }

                        if (iCheckCount == 0 && cdvMatId.Text == "")
                        {
                            //CMN517 INFO - 적어도 Lot ID 또는 제품을 입력해주세요.                   
                            MPCF.ShowMsgBox(MPCF.GetMessage(517));
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

        private void ViewOperLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                string sViewID = "CWIP3009-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatId.Text;

                dvcArgu[3].sCondition_ID = "IN_LIST";
                dvcArgu[3].sCondition_Type = "TEXT";
                dvcArgu[3].sCondition_Value = string.Format("'{0}'", string.Join("','", GetLotList()));

                if (GetLotList().Count == 0)
                    sViewID = "CWIP3009-003";

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
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
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.OPER].Value = dt.Rows[i]["OPER_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_TYPE].Value = dt.Rows[i]["MAT_TYPE"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_TYPE_DESC].Value = dt.Rows[i]["MAT_TYPE_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Value = dt.Rows[i]["PROD_QTY"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.WORK_TYPE].Value = dt.Rows[i]["WORK_TYPE_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.AREA_ID].Value = dt.Rows[i]["AREA_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.ORDER_STATUS].Value = dt.Rows[i]["ORDER_STATUS"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.INPUT_STATUS].Value = dt.Rows[i]["INPUT_STATUS"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.GROUP_ID].Value = dt.Rows[i]["GROUP_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CREATE_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.INV_FLAG].Value = dt.Rows[i]["INV_FLAG_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_RESULT_DESC].Value = dt.Rows[i]["INSP_RESULT_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.RESV_FIELD_3].Value = dt.Rows[i]["RESV_FIELD_3"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.COMMENT].Value = dt.Rows[i]["LAST_COMMENT"];
                }
                //MPCF.FitColumnHeader(spdLotList);

                return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private List<string> GetLotList()
        {
            List<string> chkLotList = new List<string>();

            SheetView sv = spdSearchLotList_Sheet1;
            try
            {
                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (Convert.ToBoolean(sv.Cells[i, 0] == null ? false : sv.Cells[i, 0].Value))
                    {
                        if (sv.Cells[i, 1].Value != null)
                            chkLotList.Add(sv.Cells[i, 1].Value.ToString());
                    }
                    else
                    {
                        if (sv.Cells[i, 1].Value != null)
                            chkLotList.Remove(sv.Cells[i, 1].Value.ToString());
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

            return chkLotList;
        }

        private void ValidLotInfo(string sLotID)
        {
            try
            {
                SheetView sv = spdSearchLotList.ActiveSheet;
                int idxRow = spdSearchLotList.ActiveSheet.RowCount;

                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", sLotID);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_Info", in_node, ref out_node) == false)
                {
                    return;
                }
                if (out_node.GetList("LOT_TBL").Count > 0)
                {
                    for (int i = 0; i < out_node.ListCount; i++)
                    {
                        spdSearchLotList.ActiveSheet.SetValue(idxRow - 1, 0, true);
                        spdSearchLotList.ActiveSheet.Cells[idxRow - 1, 1].Value = out_node.GetList("LOT_TBL")[0].GetString("LOT_ID");

                        spdSearchLotList.ActiveSheet.RowCount++;
                    }
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }


        private void fnCalData()
        {
            int iCount = 0;
            SheetView sv = spdSearchLotList.ActiveSheet;

            try
            {
                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (Convert.ToBoolean(sv.Cells[i, 0] == null ? false : sv.Cells[i, 0].Value))
                    {
                        iCount++;
                    }
                }

                sv.ColumnFooter.Cells[0, 1].Value = iCount;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmWIPViewLotStatus_Load(object sender, EventArgs e)
        {
            try
            {
                GetPortList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdOperLotList_CellClick(object sender, CellClickEventArgs e)
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

        private void spdSearchLotList_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)LOT_INFO.CHK)
                    {
                        CSCF.CheckSpreadCell(spdSearchLotList, 0, 0, true, true);
                    }
                }
                spdSearchLotList.ActiveSheet.Cells[spdSearchLotList.ActiveSheet.RowCount - 1, 0].Value = false;

                fnCalData();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Init();
                MPCF.InitListView(cdvDept.GetListView);
                cdvDept.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvDept.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDept.SelectedSubItemIndex = 0;
                cdvDept.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDept.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                {
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                MPCF.ClearList(spdLotList);
                //MPCF.ClearList(spdSearchLotList);
                //spdSearchLotList.ActiveSheet.RowCount++;
                //spdSearchLotList.ActiveSheet.SetValue(0, 0, false);                
                //spdSearchLotList.ActiveSheet.Cells[0, 1].Value = "";                
                //spdSearchLotList.ActiveSheet.ColumnFooter.Cells[0, 1].Value = 0;

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

                ViewOperLotList();

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdSearchLotList_KeyDown(object sender, KeyEventArgs e)
        {
            try
            {
                SheetView sv = spdSearchLotList.ActiveSheet;

                if (e.Control && e.KeyCode == Keys.V)
                {
                    int iActiveRow = sv.ActiveRowIndex;

                    if (iActiveRow < 0)
                        return;

                    //줄바꿈을 자르고 마지막은 빈값이므로 포함안시킴
                    string[] rowSeparators = new string[] { "\r\n" };
                    string sClipboard = Clipboard.GetText();
                    string[] sList = sClipboard.Split(rowSeparators, StringSplitOptions.None);

                    for (int i = 0; i < sList.Length - 1; i++)
                    {
                        if (sv.RowCount > 1000)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(510));//최대 검색개수 1000개를 초과했습니다.
                            return;
                        }
                        else
                        {
                            //이제 열로 구분된 값을 다시 잘라서 각 ROW에 넣어준다.
                            string[] columnSeparators = new string[] { "\t" };
                            string[] sColumnList = sList[i].Split(columnSeparators, StringSplitOptions.None);

                            //체크박스 선택
                            sv.Cells[iActiveRow, 0].Value = true;
                            sv.Cells[iActiveRow, 1].Value = sColumnList[0];

                            iActiveRow++;
                            if ((sv.RowCount - 1) < iActiveRow)
                                sv.RowCount++;
                        }
                    }

                    //sv.RemoveRows(iActiveRow, (sv.RowCount - iActiveRow - 1) == 0 ? 1 : (sv.RowCount - iActiveRow - 1));

                    // if (sv.RowCount - iActiveRow - 1 != 0)
                    // {
                    //     sv.RowCount++;
                    // }

                    fnCalData();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

            e.Handled = true;
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                // cdvDept.Text = "";
                MPCF.ClearList(spdLotList);
                MPCF.ClearList(spdSearchLotList);
                spdSearchLotList.ActiveSheet.RowCount++;
                spdSearchLotList.ActiveSheet.SetValue(0, 0, false);
                spdSearchLotList.ActiveSheet.Cells[0, 1].Value = "";
                spdSearchLotList.ActiveSheet.ColumnFooter.Cells[0, 1].Value = 0;
                txtLotID.Text = "";

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdSearchLotList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            try
            {
                fnCalData();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdSearchLotList_Change(object sender, ChangeEventArgs e)
        {
            try
            {
                fnCalData();
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
                    if (MPCF.Trim(txtLotID.Text) == "")
                        return;

                    ValidLotInfo(txtLotID.Text);
                    txtLotID.Focus();
                    txtLotID.Text = "";
                    //txtLotID.SelectAll();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMatId.Text = popup.sMat_id;
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

        private void cdvMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            //if (cdvMatId.DisplayText == "")
            //    cdvMatId.Text = "";
        }
        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdLotList, "LotStatusList");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        #endregion

        #region " Serial Definition "

        public delegate void ReceivedHandler(string sText);
        ReceivedHandler rh_Sanner;

        private void GetPortList()
        {
            string[] s_port;
            bool bSkip = false;

            try
            {
                s_port = SerialPort.GetPortNames();
                //cboPort.Items.Clear();
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
                MPCF.ShowMsgBox(ex.Message);
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

        private void frmWIPViewLotStatus_FormClosed(object sender, FormClosedEventArgs e)
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
                MPCF.ShowMsgBox(ex.Message);
            }
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
                MPCF.ShowMsgBox(ex.Message);
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
                    string[] sInputData = input.Split('\n');

                    IAsyncResult result = BeginInvoke(rh_Sanner, sInputData[0]);
                    EndInvoke(result);
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

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
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void rhText(string sText)
        {
            txtLotID.Text = sText.Replace("\r", "").Replace("\n", "").Replace("\r\n", "");
            ValidLotInfo(txtLotID.Text);
            txtLotID.Focus();
            txtLotID.Text = "";
            //txtLotID.SelectAll();

        }


        #endregion

    }
}
