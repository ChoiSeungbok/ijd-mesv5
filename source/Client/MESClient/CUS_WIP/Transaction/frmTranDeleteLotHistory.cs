using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using FarPoint.Win.Spread;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

namespace CUS_WIP
{
    public partial class frmTranDeleteLotHistory : frmViewForm01
    {
        public frmTranDeleteLotHistory()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT_INFO
        {
            SEQ,                    // 1 : HISTORY SEQ 
            OPER,                   // 2 : 공정코드
            OPER_DESC,              // 3 : 공정명
            TRAN_CODE,              // 4 : 트랜젝션코드
            MAT_ID,                 // 5 : 제품코드
            MAT_DESC,               // 6 : 제품명            
            QTY_1,                  // 7 : 생산수량
            ORDER_ID,               // 8 : 작업지시
            START_TIME,             // 9 : 시작시간
            START_RES_DESC,         //10 : 시작설비
            END_TIME,               //11 : 완료시간
            END_RES_DESC,           //12 : 완료설비
            LOT_ID,                 //13 : LOT ID
            GROUP_ID,               //14 : 그룹 ID
            FROM_TO_LOT_ID,         //15 : FROM TO LOT ID
            HIST_DEL_FLAG           //16 : 이력삭제여부
        }

        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
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

        private void ViewLotHistory()
        {
            int iRow = 0;

            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("LOT_ID", txtLotID.Text);

                if(chkIncDelFlag.Checked == true)
                    in_node.AddChar("INCLUDE_HIST_DEL", 'Y');

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_History", in_node, ref out_node) == false)
                {
                    //txtLotID.Text = "";
                    MPCF.ClearList(spdLotList);
                    return;
                }

                MPCF.ClearList(spdLotList);

                for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                {                  
                    iRow = spdLotList.ActiveSheet.RowCount;
                    spdLotList.ActiveSheet.RowCount++;
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.SEQ, out_node.GetList("LOT_TBL")[i].GetInt("HIST_SEQ"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.OPER, out_node.GetList("LOT_TBL")[i].GetString("OPER"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.OPER_DESC, out_node.GetList("LOT_TBL")[i].GetString("OPER_DESC"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.TRAN_CODE, out_node.GetList("LOT_TBL")[i].GetString("TRAN_CODE"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_ID, out_node.GetList("LOT_TBL")[i].GetString("MAT_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_DESC, out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.QTY_1, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.ORDER_ID, out_node.GetList("LOT_TBL")[i].GetString("ORDER_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.START_TIME, MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("START_TIME"), DATE_TIME_FORMAT.DATETIME));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.START_RES_DESC, out_node.GetList("LOT_TBL")[i].GetString("START_RES_DESC"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.END_TIME, MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("END_TIME"), DATE_TIME_FORMAT.DATETIME));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.END_RES_DESC, out_node.GetList("LOT_TBL")[i].GetString("END_RES_DESC"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.GROUP_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_CMF_1"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.FROM_TO_LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("FROM_TO_LOT_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.HIST_DEL_FLAG, out_node.GetList("LOT_TBL")[i].GetChar("HIST_DEL_FLAG"));

                    if (out_node.GetList("LOT_TBL")[i].GetChar("HIST_DEL_FLAG") == 'Y')
                    {
                        spdLotList.ActiveSheet.Rows[iRow].ForeColor = Color.Red;
                    }
                }

                MPCF.FitColumnHeader(spdLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }





        private bool DeleteLotHistiry2(string sLotID)
        {
            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';





                in_node.AddString("LOT_ID", sLotID);






                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Delete_Lot_History", in_node, ref out_node) == false)
                    return false;
                else
                //    MPCR.ShowSuccessMsg(out_node);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }





        private bool DeleteLotHistiry()
        {
            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';





                in_node.AddString("LOT_ID", txtLotID.Text);






                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Delete_Lot_History", in_node, ref out_node) == false)
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
                if (MPCF.Trim(txtLotID.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotID.Text + "]");
                    txtLotID.Focus();
                    return false;
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
                chkIncDelFlag.Checked = false;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmTranDeleteLotHistory_Load(object sender, EventArgs e)
        {
            try
            {
                // 20.12.21 minjae.go
                MPCF.FitColumnHeader(spdLotList);
                //
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
                if (CheckCondition(CSGC.CHECK.NONE) == false)
                    return;

                ViewLotHistory();                
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

                if (tabControl1.SelectedIndex == 0)
                {
                    if (CheckCondition(CSGC.CHECK.NONE) == false)
                        return;

                    if (DeleteLotHistiry() == true)
                    {
                        btnView.PerformClick();
                    }
                }
                else
                {
                    for (int iRow = 0; iRow < spdSearchLotList.ActiveSheet.RowCount; iRow++)
                    {
                        if (spdSearchLotList_Sheet1.Cells[iRow, 1].Text.Replace(" ", "").Length != 0)
                        {
                            DeleteLotHistiry2(spdSearchLotList_Sheet1.Cells[iRow, 1].Text);
                        }
                    }

                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdSearchLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == 1)
                    {
                        CSCF.CheckSpreadCell(spdSearchLotList, 0, 0, true, true);
                    }
                }
                spdSearchLotList.ActiveSheet.Cells[spdSearchLotList.ActiveSheet.RowCount - 1, 0].Value = false;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdSearchLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            if (e.Column == 1 && e.Row == spdSearchLotList_Sheet1.RowCount - 1)
            {
                if (spdSearchLotList_Sheet1.Cells[e.Row, 1].ToString() != "")
                {
                    SheetView sv = spdSearchLotList.ActiveSheet;
                    sv.RowCount++;
                }
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


                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

            e.Handled = true;
        }




        #endregion


    }
}
