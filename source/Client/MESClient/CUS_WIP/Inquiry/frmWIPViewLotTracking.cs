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
using System.Drawing;

namespace CUS_WIP
{
    public partial class frmWIPViewLotTracking : frmViewForm01
    {

        System.Drawing.Color colColor = new System.Drawing.Color();


        public frmWIPViewLotTracking()
        {
            InitializeComponent();
        }

        #region " Constant Definition "

        private enum LOT_INFO
        {


            SEARCH_LOT_ID,
            LV_SEQ,
            TO_LOT,
            TO_MAT_ID,
            TO_MAT_DESC,
            FR_LOT,
            FR_MAT_ID,
            FR_MAT_DESC,
            TRAN_TIME,
            TRAN_QTY,
            TRANS_NAME,
            MG_SP_HISTORY,
            FR_LOT_BOM,
            FR_LOT_ORDER,
            FR_LOT_QC_JUDGE,
            FR_LOT_SHIPPING,
            FR_LOT_DLV


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
                colColor = Color.WhiteSmoke;
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

        private void ViewOperLotList(string sLotId)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                int iCount = 0;
                string sViewID = "CWIP3040-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = sLotId;

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLotList);
                    return;
                }

                iCount = spdLotList.ActiveSheet.RowCount;

                if (colColor == Color.WhiteSmoke)
                {
                    colColor = Color.White;
                }
                else
                {
                    colColor = Color.WhiteSmoke;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList.ActiveSheet.RowCount++;

                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.SEARCH_LOT_ID, i + iCount, (int)LOT_INFO.FR_LOT_DLV].BackColor = colColor;
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.SEARCH_LOT_ID, i + iCount, (int)LOT_INFO.FR_LOT_DLV].LockBackColor = colColor;
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.SEARCH_LOT_ID].Value = dt.Rows[i]["SEARCH_LOT_ID"];
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.LV_SEQ].Value = dt.Rows[i]["LV_SEQ"];
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.TO_LOT].Value = dt.Rows[i]["TO_LOT"];
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.TO_MAT_ID].Value = dt.Rows[i]["TO_MAT_ID"];
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.TO_MAT_DESC].Value = dt.Rows[i]["TO_MAT_DESC"];
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.FR_LOT].Value = dt.Rows[i]["FR_LOT"];
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.FR_MAT_ID].Value = dt.Rows[i]["FR_MAT_ID"];
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.FR_MAT_DESC].Value = dt.Rows[i]["FR_MAT_DESC"];
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.TRAN_TIME].Value = dt.Rows[i]["TRAN_TIME"];
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.TRAN_QTY].Value = dt.Rows[i]["TRAN_QTY"];
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.TRANS_NAME].Value = dt.Rows[i]["TRANS_NAME"];
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.MG_SP_HISTORY].Value = dt.Rows[i]["MG_SP_HISTORY"];
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.FR_LOT_BOM].Value = dt.Rows[i]["FR_LOT_BOM"];
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.FR_LOT_ORDER].Value = dt.Rows[i]["FR_LOT_ORDER"];
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.FR_LOT_QC_JUDGE].Value = dt.Rows[i]["FR_LOT_QC_JUDGE"];
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.FR_LOT_SHIPPING].Value = dt.Rows[i]["FR_LOT_SHIPPING"];
                    spdLotList.ActiveSheet.Cells[i + iCount, (int)LOT_INFO.FR_LOT_DLV].Value = dt.Rows[i]["FR_LOT_DLV"];

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
                    if (sv.Cells[i, 1].Value != null)
                        chkLotList.Add(sv.Cells[i, 1].Value.ToString());
                    /*
                    if (Convert.ToBoolean(sv.Cells[i, 0] == null ? false : sv.Cells[i, 0].Value))
                    {
                        if (sv.Cells[i, 1].Value != null)
                            chkLotList.Add(sv.Cells[i, 1].Value.ToString());
                    }
                    else
                    {
                        if(sv.Cells[i, 1].Value!=null)
                            chkLotList.Remove(sv.Cells[i, 1].Value.ToString());
                    }
                    */
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

        private void frmWIPViewLotTracking_Load(object sender, EventArgs e)
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
                    if (e.Column == 0)
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


        private void btnRawAdd_Click(object sender, EventArgs e)
        {
            SheetView sv = spdSearchLotList.ActiveSheet;
            sv.RowCount++;
        }

        private void btnRowDel_Click(object sender, EventArgs e)
        {
            SheetView sv = spdSearchLotList.ActiveSheet;
            if (sv.RowCount != 0)
            {
                sv.RowCount = sv.RowCount - 1;
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


                SheetView sv = spdSearchLotList_Sheet1;

                MPCF.ClearList(spdLotList);

                for (int i = 0; i < sv.RowCount; i++)
                {
                    //if (Convert.ToBoolean(sv.Cells[i, 0] == null ? false : sv.Cells[i, 0].Value))
                    // {
                    if (sv.Cells[i, 1].Text.Trim() != "")
                    {

                        ViewOperLotList(sv.Cells[i, 1].Value.ToString());

                    }
                    // }

                }


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

        private void frmWIPViewLotTracking_FormClosed(object sender, FormClosedEventArgs e)
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
