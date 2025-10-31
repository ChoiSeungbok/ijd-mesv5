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
    public partial class frmTranKittingInvLot : CUS_COM.frmTranForm01
    {
        public frmTranKittingInvLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT
        {
            CHK,                     // 1 : CHECK
            INV_LOT_ID,              // 2 : 자재 LOT ID
            QTY,                     // 3 : 수량
            UNIT,                    // 4 : 단위
            OPER,                    // 5 : 창고
            OPER_DESC,               // 6 : 창고명
            MAT_ID,                  // 7 : 제품
            MAT_DESC                 // 8 : 제품명
        }

        private enum KIT_LOT
        {
            CHK,                     // 1 : CHECK
            INV_LOT_ID,              // 2 : 자재 LOT ID
            QTY,                     // 3 : 수량
            KITTING_QTY,             // 4 : KITTING 수량
            UNIT,                    // 5 : 단위
            OPER,                    // 6 : 창고
            OPER_DESC,               // 7 : 창고명
            MAT_ID,                  // 8 : 제품
            MAT_DESC,                // 9 : 제품명
            KITTING_ID               // 10 : KITTING ID
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
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnKitting.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnUnKitting.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnNew.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //이동 자재 LOT LIST 조회 함수
        private void ViewInvLotList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                double dSumQty = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;
                
                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = cdvMatID.Text;

                dvcArgu[2].sCondition_ID = "AREA_ID";
                dvcArgu[2].sCondition_Value = cdvDept.Text;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvFromOper.Text;

                dvcArgu[4].sCondition_ID = "INV_LOT_ID";
                dvcArgu[4].sCondition_Value = "";

                if (TPDR.GetDataOne("", ref dt, "CINV2014-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInvLotList);
                    return;
                }

                MPCF.ClearList(spdInvLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdInvLotList_Sheet1.RowCount++;

                    spdInvLotList_Sheet1.SetValue(i, (int)LOT.CHK, false);
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Value = dt.Rows[i]["INV_LOT_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.OPER].Value = dt.Rows[i]["OPER"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT. MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdInvLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                }
                MPCF.FitColumnHeader(spdInvLotList);

                for (i = 0; i < spdInvLotList_Sheet1.RowCount; i++)
                {
                    dSumQty += MPCF.ToDbl(spdInvLotList.ActiveSheet.Cells[i, (int)LOT.QTY].Text);
                }

                spdInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void CheckCount()
        {
            double dSumQty = 0;
            int iCount = 0;

            try
            {
                for (int i = 0; i < spdInvLotList_Sheet1.RowCount; i++)
                {
                    if (spdInvLotList_Sheet1.Cells[i, (int)LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdInvLotList_Sheet1.Cells[i, (int)LOT.QTY].Text);
                    }
                }

                spdInvLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.CHK].Value = iCount;
                spdInvLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.QTY].Value = dSumQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void CheckCount2()
        {
            double dSumQty = 0;
            double dSumKitQty = 0;
            int iCount = 0;

            try
            {
                for (int i = 0; i < spdKittingList_Sheet1.RowCount; i++)
                {
                    if (spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.QTY].Text);
                        dSumKitQty += MPCF.ToDbl(spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.KITTING_QTY].Text);
                    }
                }

                spdKittingList_Sheet1.ColumnFooter.Cells[0, (int)KIT_LOT.CHK].Value = iCount;
                spdKittingList_Sheet1.ColumnFooter.Cells[0, (int)KIT_LOT.QTY].Value = dSumQty;
                spdKittingList_Sheet1.ColumnFooter.Cells[0, (int)KIT_LOT.KITTING_QTY].Value = dSumKitQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 입력 자재 LOT 정보 조회 후 데이터 추가
        private void InputInvLot()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i_Row = 0;
                
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_ID";
                dvcArgu[1].sCondition_Value = "";

                dvcArgu[2].sCondition_ID = "AREA_ID";
                dvcArgu[2].sCondition_Value = cdvDept.Text;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvFromOper.Text;

                dvcArgu[4].sCondition_ID = "INV_LOT_ID";
                dvcArgu[4].sCondition_Value = txtInvLotID.Text;

                if (TPDR.GetDataOne("", ref dt, "CINV2014-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    txtInvLotID.SelectAll();

                    return;
                }

                for (int i = 0; i < spdInvLotList_Sheet1.RowCount; i++)
                {
                    // FROM 그리드에 데이터 제거
                    if (string.Equals(spdInvLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Text, dt.Rows[0]["INV_LOT_ID"]))
                    {
                        spdInvLotList_Sheet1.RemoveRows(i, 1);
                        break;
                    }
                }
                
                // TO 그리드에 데이터 삽입
                i_Row = spdKittingList_Sheet1.RowCount++;

                spdKittingList_Sheet1.SetValue(i_Row, (int)KIT_LOT.CHK, true);
                spdKittingList_Sheet1.Cells[i_Row, (int)KIT_LOT.INV_LOT_ID].Value = dt.Rows[0]["INV_LOT_ID"];
                spdKittingList_Sheet1.Cells[i_Row, (int)KIT_LOT.QTY].Value = dt.Rows[0]["QTY"];
                spdKittingList_Sheet1.Cells[i_Row, (int)KIT_LOT.KITTING_QTY].Value = "";
                spdKittingList_Sheet1.Cells[i_Row, (int)KIT_LOT.UNIT].Value = dt.Rows[0]["UNIT"];
                spdKittingList_Sheet1.Cells[i_Row, (int)KIT_LOT.OPER].Value = dt.Rows[0]["OPER"];
                spdKittingList_Sheet1.Cells[i_Row, (int)KIT_LOT.OPER_DESC].Value = dt.Rows[0]["OPER_DESC"];
                spdKittingList_Sheet1.Cells[i_Row, (int)KIT_LOT.MAT_ID].Value = dt.Rows[0]["MAT_ID"];
                spdKittingList_Sheet1.Cells[i_Row, (int)KIT_LOT.MAT_DESC].Value = dt.Rows[0]["MAT_DESC"];
                spdKittingList_Sheet1.Cells[i_Row, (int)KIT_LOT.KITTING_ID].Value = "";
                MPCF.FitColumnHeader(spdKittingList_Sheet1);

                txtInvLotID.SelectAll();

                CheckCount();
                CheckCount2();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        
        // KITTING LIST 조회
        private void ViewKittingList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                double dSumQty = 0;
                double dSumKitQty = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "KITTING_ID";
                dvcArgu[1].sCondition_Value = txtKittingID.Text;

                if (TPDR.GetDataOne("", ref dt, "CINV2014-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdKittingList);

                    txtKittingID.SelectAll();
                    return;
                }

                MPCF.ClearList(spdKittingList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdKittingList_Sheet1.RowCount++;

                    spdKittingList_Sheet1.SetValue(i, (int)KIT_LOT.CHK, false);
                    spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.INV_LOT_ID].Value = dt.Rows[i]["INV_LOT_ID"];
                    spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.KITTING_QTY].Value = dt.Rows[i]["KITTING_QTY"];
                    spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.OPER].Value = dt.Rows[i]["OPER"];
                    spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.KITTING_ID].Value = dt.Rows[i]["KITTING_ID"];

                    if(i == 0)
                    {
                        cdvDept.Text = dt.Rows[i]["AREA_ID"].ToString();
                        cdvDept.DisplayText = dt.Rows[i]["AREA_ID"].ToString();
                        cdvFromOper.Text = dt.Rows[i]["OPER"].ToString();
                        cdvFromOper.DisplayText = dt.Rows[i]["OPER_DESC"].ToString();
                    }
                }

                MPCF.FitColumnHeader(spdKittingList);

                txtKittingID.SelectAll();

                for (i = 0; i < spdKittingList_Sheet1.RowCount; i++)
                {
                    dSumQty += MPCF.ToDbl(spdKittingList.ActiveSheet.Cells[i, (int)KIT_LOT.QTY].Text);
                    dSumKitQty += MPCF.ToDbl(spdKittingList.ActiveSheet.Cells[i, (int)KIT_LOT.KITTING_QTY].Text);
                }

                spdKittingList.ActiveSheet.ColumnFooter.Cells[0, (int)KIT_LOT.QTY].Value = dSumQty;
                spdKittingList.ActiveSheet.ColumnFooter.Cells[0, (int)KIT_LOT.KITTING_QTY].Value = dSumKitQty;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //자재 LOT 이동
        private bool MoveInvLot()
        {
            TRSNode in_node = new TRSNode("move_InvLot_In");
            TRSNode out_node = new TRSNode("move_InvLot_Out");
            TRSNode Inv_Lot_list;
            bool send_flag = false;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '3';
                in_node.AddString("KITTING_ID", txtKittingID.Text);
                in_node.AddString("TO_OPER", cdvToOper.Text);
                in_node.AddString("TRAN_COMMENT", txtComment.Text);

                for (int i = 0; i < spdKittingList_Sheet1.RowCount; i++)
                {
                    if(MPCF.Trim(spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.KITTING_ID].Text) != "")
                    {
                        Inv_Lot_list = in_node.AddNode("INV_LOT_LIST");
                        Inv_Lot_list.AddString("INV_LOT_ID", spdKittingList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Text);
                        send_flag = true;
                    }
                }

                if (send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_INV", "CUS_INV_Move_Lot", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void PrintLabel(string sKittingId)
        {
            try
            {
                TRSNode in_node = new TRSNode("print_label_Request_In");
                TRSNode out_node = new TRSNode("print_label_Request_Out");
                TRSNode kitting_List;
                string sFileName = "kittingLabel";

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '3';
                
                kitting_List = in_node.AddNode("KITTING_LIST");
                kitting_List.AddString("KITTING_ID", sKittingId);

                //라벨 출력
                CSCF.ViewLabelList(sFileName, in_node, 'I');
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        //자재 KITTING
        private bool KittingInvLot()
        {
            TRSNode in_node = new TRSNode("kitting_InvLot_In");
            TRSNode out_node = new TRSNode("kitting_InvLot_Out");
            TRSNode Inv_Lot_list;
            bool send_flag = false;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("KITTING_ID", txtKittingID.Text);

                for (int i = 0; i < spdKittingList_Sheet1.RowCount; i++)
                {
                    if (spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if(MPCF.Trim(spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.KITTING_ID].Text) != "")
                        {
                            continue;
                        }

                        Inv_Lot_list = in_node.AddNode("INV_LOT_LIST");
                        Inv_Lot_list.AddString("INV_LOT_ID", spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.INV_LOT_ID].Text);
                        Inv_Lot_list.AddDouble("KITTING_QTY", MPCF.ToDbl(spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.KITTING_QTY].Text));

                        // 재고 수량, 요청 수량 Validation
                        if (MPCF.ToDbl(spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.KITTING_QTY].Text) <= 0)
                        {
                            //CMN114 ERROR -0보다 큰 값을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(114));
                            return false;
                        }

                        send_flag = true;
                    }
                }

                if(send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_INV", "CUS_INV_Kitting_Lot", in_node, ref out_node) == false)
                    return false;

                txtKittingID.Text = out_node.GetString("KITTING_ID");

                MPCR.ShowSuccessMsg(out_node);

                PrintLabel(txtKittingID.Text);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //자재 UNKITTING
        private bool UnKittingInvLot()
        {
            TRSNode in_node = new TRSNode("unkitting_InvLot_In");
            TRSNode out_node = new TRSNode("unkitting_InvLot_Out");
            TRSNode Inv_Lot_list;
            bool send_flag = false;
            double lot_count = 0;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '2';
                in_node.AddString("KITTING_ID", txtKittingID.Text);

                for (int i = 0; i < spdKittingList_Sheet1.RowCount; i++)
                {
                    if (spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (MPCF.Trim(spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.KITTING_ID].Text) == "")
                        {
                            continue;
                        }

                        Inv_Lot_list = in_node.AddNode("INV_LOT_LIST");
                        Inv_Lot_list.AddString("INV_LOT_ID", spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.INV_LOT_ID].Text);

                        send_flag = true;
                    }
                }

                if(send_flag == false)
                {
                    //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(109));
                    return false;
                }

                if (MPCR.CallService("CUS_INV", "CUS_INV_Kitting_Lot", in_node, ref out_node) == false)
                    return false;

                lot_count = out_node.GetDouble("LOT_COUNT");

                MPCR.ShowSuccessMsg(out_node);

                if(lot_count != 0)
                {
                    PrintLabel(txtKittingID.Text);
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //벨리데이션 체크
        private bool CheckCondition(string sType)
        {
            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }

                switch (sType)
                {
                    case "VIEW":
                        if (MPCF.Trim(cdvFromOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblFromOper.Text + "]");
                            cdvFromOper.Focus();
                            return false;
                        }

                        //if (MPCF.Trim(cdvMatID.Text) == "")
                        //{
                        //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMatID.Text + "]");
                        //    cdvMatID.Focus();
                        //    return false;
                        //}

                        break;

                    case "MOVE":
                        if (MPCF.Trim(txtKittingID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblKittingID.Text + "]");
                            txtKittingID.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvToOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToOper.Text + "]");
                            cdvToOper.Focus();
                            return false;
                        }

                        break;

                    case "KITTING":
                        if (spdKittingList_Sheet1.RowCount == 0)
                        {
                            return false;
                        }

                        break;

                    case "UNKITTING":
                        if (spdKittingList_Sheet1.RowCount == 0)
                        {
                            return false;
                        }

                        break;

                    case "INPUT":
                        if (MPCF.Trim(txtInvLotID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblInvLotID.Text + "]");
                            txtInvLotID.Focus();
                            return false;
                        }

                        break;

                    case "KITTING_INPUT":
                        if (MPCF.Trim(txtKittingID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblKittingID.Text + "]");
                            txtKittingID.Focus();
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

        //초기화 함수
        private void ClearList(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":

                        MPCF.ClearList(spdInvLotList);
                        spdInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;

                        this.txtInvLotID.Text = "";
                        //this.txtKittingID.Text = "";
                        this.cdvToOper.Text = "";
                        this.txtComment.Text = "";
                        break;
                        
                    case "ALL":

                        MPCF.ClearList(spdInvLotList);
                        MPCF.ClearList(spdKittingList);
                        spdInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;
                        spdKittingList.ActiveSheet.ColumnFooter.Cells[0, (int)KIT_LOT.CHK].Value = 0;
                        spdKittingList.ActiveSheet.ColumnFooter.Cells[0, (int)KIT_LOT.QTY].Value = 0;
                        spdKittingList.ActiveSheet.ColumnFooter.Cells[0, (int)KIT_LOT.KITTING_QTY].Value = 0;

                        this.cdvDept.Text = "";
                        this.cdvMatID.Text = "";
                        this.cdvFromOper.Text = "";
                        this.txtInvLotID.Text = "";
                        this.txtKittingID.Text = "";
                        this.cdvToOper.Text = "";
                        this.txtComment.Text = "";
                        break;

                    case "NEW":

                        MPCF.ClearList(spdKittingList);
                        spdKittingList.ActiveSheet.ColumnFooter.Cells[0, (int)KIT_LOT.CHK].Value = 0;
                        spdKittingList.ActiveSheet.ColumnFooter.Cells[0, (int)KIT_LOT.QTY].Value = 0;
                        spdKittingList.ActiveSheet.ColumnFooter.Cells[0, (int)KIT_LOT.KITTING_QTY].Value = 0;

                        this.txtInvLotID.Text = "";
                        this.txtKittingID.Text = "";
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "
        private void frmTranKittingInvLot_Load(object sender, EventArgs e)
        {
            try
            {
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        

        //전체 클리어
        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                ClearList("ALL");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        

        private void cdvMatID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                // 제품 팝업으로 변경
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMatID.Text = popup.sMat_id;
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

        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("VIEW") == false)
                    return;

                ClearList("VIEW");

                ViewInvLotList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            try
            {
                int iRow = 0;
                string sInvLotId = "";
                bool addFlag = true;

                for (int i = spdInvLotList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdInvLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        addFlag = true;

                        sInvLotId = spdInvLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Text;

                        for (int k = 0; k < spdKittingList_Sheet1.RowCount; k++)
                        {
                            if (string.Equals(spdKittingList_Sheet1.Cells[k, (int)LOT.INV_LOT_ID].Text, sInvLotId))
                            {
                                addFlag = false;
                                continue;
                            }
                        }

                        if (addFlag == true)
                        {
                            iRow = spdKittingList_Sheet1.RowCount++;

                            spdKittingList_Sheet1.SetValue(iRow, (int)KIT_LOT.CHK, true);
                            spdKittingList_Sheet1.Cells[iRow, (int)KIT_LOT.INV_LOT_ID].Value = spdInvLotList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Text;
                            spdKittingList_Sheet1.Cells[iRow, (int)KIT_LOT.QTY].Value = spdInvLotList_Sheet1.Cells[i, (int)LOT.QTY].Text;
                            spdKittingList_Sheet1.Cells[iRow, (int)KIT_LOT.KITTING_QTY].Value = "0";
                            spdKittingList_Sheet1.Cells[iRow, (int)KIT_LOT.UNIT].Value = spdInvLotList_Sheet1.Cells[i, (int)LOT.UNIT].Text;
                            spdKittingList_Sheet1.Cells[iRow, (int)KIT_LOT.OPER].Value = spdInvLotList_Sheet1.Cells[i, (int)LOT.OPER].Text;
                            spdKittingList_Sheet1.Cells[iRow, (int)KIT_LOT.OPER_DESC].Value = spdInvLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Text;
                            spdKittingList_Sheet1.Cells[iRow, (int)KIT_LOT.MAT_ID].Value = spdInvLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Text;
                            spdKittingList_Sheet1.Cells[iRow, (int)KIT_LOT.MAT_DESC].Value = spdInvLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Text;
                            spdKittingList_Sheet1.Cells[iRow, (int)KIT_LOT.KITTING_ID].Value = "";
                        }  

                        spdInvLotList_Sheet1.RemoveRows(i, 1);
                    }
                }

                MPCF.FitColumnHeader(spdKittingList);

                CheckCount();
                CheckCount2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDel_Click(object sender, EventArgs e)
        {
            try
            {
                int iRow = 0;
                string sInvLotId = "";
                bool addFlag = true;

                for (int i = spdKittingList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if(MPCF.Trim(spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.KITTING_ID].Text) != "")
                        {
                            continue;
                        }

                        addFlag = true;

                        sInvLotId = spdKittingList_Sheet1.Cells[i, (int)LOT.INV_LOT_ID].Text;

                        for (int k = 0; k < spdInvLotList_Sheet1.RowCount; k++)
                        {
                            if (string.Equals(spdInvLotList_Sheet1.Cells[k, (int)LOT.INV_LOT_ID].Text, sInvLotId))
                            {
                                addFlag = false;
                                continue;
                            }
                        }

                        if (addFlag == true)
                        {
                            iRow = spdInvLotList_Sheet1.RowCount++;

                            spdInvLotList_Sheet1.SetValue(iRow, (int)LOT.CHK, false);
                            spdInvLotList_Sheet1.Cells[iRow, (int)LOT.INV_LOT_ID].Value = spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.INV_LOT_ID].Text;
                            spdInvLotList_Sheet1.Cells[iRow, (int)LOT.QTY].Value = spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.QTY].Text;
                            spdInvLotList_Sheet1.Cells[iRow, (int)LOT.UNIT].Value = spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.UNIT].Text;
                            spdInvLotList_Sheet1.Cells[iRow, (int)LOT.OPER].Value = spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.OPER].Text;
                            spdInvLotList_Sheet1.Cells[iRow, (int)LOT.OPER_DESC].Value = spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.OPER_DESC].Text;
                            spdInvLotList_Sheet1.Cells[iRow, (int)LOT.MAT_ID].Value = spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.MAT_ID].Text;
                            spdInvLotList_Sheet1.Cells[iRow, (int)LOT.MAT_DESC].Value = spdKittingList_Sheet1.Cells[i, (int)KIT_LOT.MAT_DESC].Text;
                        }   

                        spdKittingList_Sheet1.RemoveRows(i, 1);
                    }
                }

                MPCF.FitColumnHeader(spdInvLotList);

                CheckCount();
                CheckCount2();
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
                if (CheckCondition("MOVE") == false)
                    return;

                if (MoveInvLot())
                {
                    ClearList("VIEW");
                    MPCF.ClearList(spdKittingList);
                    ViewInvLotList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnKitting_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("KITTING") == false)
                    return;

                if (KittingInvLot())
                {
                    ViewKittingList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnUnKitting_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition("UNKITTING") == false)
                    return;

                if (UnKittingInvLot())
                {
                    ViewKittingList();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnNew_Click(object sender, EventArgs e)
        {
            try
            {
                ClearList("NEW");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdFromInvLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdInvLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdInvLotList, e.Row, e.Column, true, true, false);
                }

                CheckCount();
            }
        }

        private void spdKittingList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdKittingList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdKittingList, e.Row, e.Column, true, true, false);
                }

                CheckCount2();
            }
        }

        private void txtInvLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (CheckCondition("INPUT") == false)
                        return;

                    InputInvLot();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtKittingID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (CheckCondition("KITTING_INPUT") == false)
                        return;

                    ViewKittingList();

                    txtInvLotID.Text = "";
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvFromOper_ButtonPress(object sender, EventArgs e)
        {
            cdvFromOper.Init();
            MPCF.InitListView(cdvToOper.GetListView);
            cdvFromOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
            cdvFromOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvFromOper.SelectedSubItemIndex = 0;
            cdvFromOper.DisplaySubItemIndex = 1;

            if (COM_LIST.ViewOperationList(cdvFromOper.GetListView, '4', cdvDept.Text, "", "", "", 'Y') == false)
            {
                return;
            }

            cdvFromOper.InsertEmptyRow(0, 1);
        }

        private void cdvToOper_ButtonPress(object sender, EventArgs e)
        {
            cdvToOper.Init();
            MPCF.InitListView(cdvToOper.GetListView);
            cdvToOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
            cdvToOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvToOper.SelectedSubItemIndex = 0;
            cdvToOper.DisplaySubItemIndex = 1;

            if (COM_LIST.ViewOperationList(cdvToOper.GetListView, '3', cdvDept.Text, "", "", "", 'Y') == false)
            {
                return;
            }

            cdvToOper.InsertEmptyRow(0, 1);
        }
        
        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                ClearList("ALL");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(txtKittingID.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblKittingID.Text + "]");
                    txtKittingID.Focus();
                    return;
                }

                //라벨 출력
                PrintLabel(txtKittingID.Text);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdInvLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
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

        private void spdInvLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
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

        private void spdKittingList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                CheckCount2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdKittingList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            try
            {
                CheckCount2();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }        

        private void cdvMatID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatID.DisplayText == "")
                cdvMatID.Text = "";
        }

        #endregion
    }
}
