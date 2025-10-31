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
    public partial class frmViewInvLotHistory : CUS_COM.frmViewForm01
    {
        public frmViewInvLotHistory()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum INV_LOT : int
        {
            INV_LOT_ID,             // 1 . 자재 LOT ID
            HIST_SEQ,               // 2 . 이력 순번
            TRAN_CODE,              // 3 . 처리 코드        
            TRAN_TIME,              // 4 . 처리 시간                     
            INV_LOT_STATUS,         // 5 . 자재 LOT 상태
            INV_LOT_PRIORITY,       // 6 . 자재 LOT 우선순위
            MAT_ID,                 // 7 . 제품
            MAT_VER,                // 8 . 제품버전
            MAT_DESC,               // 9 . 제품명
            QTY,                    // 10. 수량
            UNIT,                   // 11. 단위
            VENDOR_ID,              // 12. 업체
            VENDOR_SITE_ID,         // 13. 업체 SITE ID
            VENDOR_LOT_ID,          // 14. 공급사 LOT ID
            AREA_DESC,              // 15. 사업부
            SUB_AREA_DESC,          // 16. 작업장
            OPER,                   // 17. 공정
            OPER_DESC,              // 18. 공정명
            RECV_DATE,              // 19. 입고 일자
            RECV_QTY,               // 20. 입고 수량
            DELETE_FLAG,            // 21. 삭제 여부
            DELETE_CODE,            // 22. 삭제 코드
            DELETE_TIME,            // 23. 삭제시간
            HOLD_FLAG,              // 24. 보류 여부
            HOLD_CODE,              // 25. 보류 코드
            INSP_FLAG,              // 26. 검사 여부
            INSP_ID,                // 27. 검사 코드
            INSP_RESULT_FLAG,       // 28. 검사 결과 플래그
            INV_CMF_1,              // 29. 금형 모델            
            INV_CMF_2,              // 30. 금형 구분
            INV_CMF_3,              // 31. 이전 공정    
            INV_CMF_4,              // 32. Kitting ID
            INV_CMF_5,              // 33. 기타 입고 유형
            INV_CMF_6,              // 34. 기타 출고 유형
            INV_CMF_7,              // 35. 출고일자
            LOAD_FLAG,              // 36. 투입 여부
            LOT_ID,                 // 37. LOT ID
            RES_ID,                 // 38. 설비 ID
            ORDER_ID,               // 39. 작업지시 번호
            INV_CMF_8,              // 40. 투입작업장
            INV_CMF_9,              // 41. 투입공정
            INV_CMF_10,             // 42. 여유필드 10
            ORG_INV_LOT_ID,         // 43. Original 자재 LOT ID 
            OLD_MAT_ID,             // 44. 이전 제품
            OLD_MAT_DESC,           // 45. 이전 제품명
            OLD_AREA_DESC,          // 46. 이전 사업부
            OLD_SUB_AREA_DESC,      // 47. 이전 작업장
            OLD_OPER,               // 48. 이전 공정
            OLD_QTY,                // 49. 이전 수량
            OLD_UNIT,               // 50. 이전 단위
            CREATE_TIME,            // 51. 생성시간
            UPDATE_TIME,            // 52. 삭제시간
            HIST_DEL_FLAG,          // 53. 삭제 여부
            TRAN_USER_ID            // 54. 처리 사용자
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

        // 초기화
        private void ClearData(string sType)
        {
            try
            {
                switch (sType)
                {
                    case "VIEW":
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //벨리데이션 체크
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        if (MPCF.Trim(txtInvLotID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblInvLotId.Text + "]");
                            txtInvLotID.Focus();
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

        // 자재 LOT 이력 조회
        public bool ViewInLotHistory()
        {
            TRSNode in_node = new TRSNode("VIEW_INV_LOT_HISTORY_IN ");
            TRSNode out_node = new TRSNode("VIEW_INV_LOT_HISTORY_OUT");

            int iRow = 0;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                in_node.AddString("INV_LOT_ID", MPCF.Trim(txtInvLotID.Text));

                MPCF.ClearList(spdInvLotList);

                do
                {
                    if (MPCR.CallService("CUS_INV", "CUS_INV_View_Lot_History_List", in_node, ref out_node) == false)
                    {
                        txtInvLotID.SelectAll();
                        return false;
                    }

                    for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                    {
                        iRow = spdInvLotList_Sheet1.RowCount;

                        spdInvLotList_Sheet1.RowCount++;

                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.INV_LOT_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("INV_LOT_ID");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.HIST_SEQ].Value = out_node.GetList("LOT_TBL")[i].GetInt("HIST_SEQ");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.TRAN_CODE].Value = out_node.GetList("LOT_TBL")[i].GetString("TRAN_CODE");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.TRAN_TIME].Value = MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("TRAN_TIME"), DATE_TIME_FORMAT.DATETIME);
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.INV_LOT_STATUS].Value = out_node.GetList("LOT_TBL")[i].GetString("INV_LOT_STATUS");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.INV_LOT_PRIORITY].Value = out_node.GetList("LOT_TBL")[i].GetChar("INV_LOT_PRIORITY");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.MAT_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("MAT_ID");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.MAT_VER].Value = out_node.GetList("LOT_TBL")[i].GetInt("MAT_VER");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.MAT_DESC].Value = out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.QTY].Value = out_node.GetList("LOT_TBL")[i].GetDouble("QTY");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.UNIT].Value = out_node.GetList("LOT_TBL")[i].GetString("UNIT");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.VENDOR_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("VENDOR_ID");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.VENDOR_SITE_ID].Value = out_node.GetList("LOT_TBL")[i].GetInt("VENDOR_SITE_ID");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.VENDOR_LOT_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("VENDOR_LOT_ID");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.AREA_DESC].Value = out_node.GetList("LOT_TBL")[i].GetString("AREA_DESC");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.SUB_AREA_DESC].Value = out_node.GetList("LOT_TBL")[i].GetString("SUB_AREA_DESC");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.OPER].Value = out_node.GetList("LOT_TBL")[i].GetString("OPER");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.OPER_DESC].Value = out_node.GetList("LOT_TBL")[i].GetString("OPER_DESC");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.RECV_DATE].Value = MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("RECV_DATE"), DATE_TIME_FORMAT.DATE);
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.RECV_QTY].Value = out_node.GetList("LOT_TBL")[i].GetDouble("RECV_QTY");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.DELETE_FLAG].Value = out_node.GetList("LOT_TBL")[i].GetChar("DELETE_FLAG");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.DELETE_CODE].Value = out_node.GetList("LOT_TBL")[i].GetString("DELETE_CODE");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.DELETE_TIME].Value = MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("DELETE_TIME"), DATE_TIME_FORMAT.DATETIME);
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.HOLD_FLAG].Value = out_node.GetList("LOT_TBL")[i].GetChar("HOLD_FLAG");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.HOLD_CODE].Value = out_node.GetList("LOT_TBL")[i].GetString("HOLD_CODE");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.INSP_FLAG].Value = out_node.GetList("LOT_TBL")[i].GetChar("INSP_FLAG");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.INSP_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("INSP_ID");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.INSP_RESULT_FLAG].Value = out_node.GetList("LOT_TBL")[i].GetChar("INSP_RESULT_FLAG");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.INV_CMF_1].Value = out_node.GetList("LOT_TBL")[i].GetString("INV_CMF_1");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.INV_CMF_2].Value = out_node.GetList("LOT_TBL")[i].GetString("INV_CMF_2");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.INV_CMF_3].Value = out_node.GetList("LOT_TBL")[i].GetString("INV_CMF_3");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.INV_CMF_4].Value = out_node.GetList("LOT_TBL")[i].GetString("INV_CMF_4");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.INV_CMF_5].Value = out_node.GetList("LOT_TBL")[i].GetString("INV_CMF_5");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.INV_CMF_6].Value = out_node.GetList("LOT_TBL")[i].GetString("INV_CMF_6");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.INV_CMF_7].Value = MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("INV_CMF_7"), DATE_TIME_FORMAT.DATE);
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.LOAD_FLAG].Value = out_node.GetList("LOT_TBL")[i].GetChar("LOAD_FLAG");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.LOT_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("ORDER_ID");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.RES_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("RES_ID");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.ORDER_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("ORDER_ID");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.INV_CMF_8].Value = out_node.GetList("LOT_TBL")[i].GetString("INV_CMF_8");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.INV_CMF_9].Value = out_node.GetList("LOT_TBL")[i].GetString("INV_CMF_9");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.INV_CMF_10].Value = out_node.GetList("LOT_TBL")[i].GetString("INV_CMF_10");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.ORG_INV_LOT_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("ORG_INV_LOT_ID");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.OLD_MAT_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("OLD_MAT_ID");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.OLD_MAT_DESC].Value = out_node.GetList("LOT_TBL")[i].GetString("OLD_MAT_DESC");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.OLD_AREA_DESC].Value = out_node.GetList("LOT_TBL")[i].GetString("OLD_AREA_DESC");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.OLD_SUB_AREA_DESC].Value = out_node.GetList("LOT_TBL")[i].GetString("OLD_SUB_AREA_DESC");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.OLD_OPER].Value = out_node.GetList("LOT_TBL")[i].GetString("OLD_OPER");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.OLD_QTY].Value = out_node.GetList("LOT_TBL")[i].GetDouble("OLD_QTY");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.OLD_UNIT].Value = out_node.GetList("LOT_TBL")[i].GetString("OLD_UNIT");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.CREATE_TIME].Value = MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("CREATE_TIME"), DATE_TIME_FORMAT.DATETIME);
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.UPDATE_TIME].Value = MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("UPDATE_TIME"), DATE_TIME_FORMAT.DATETIME);
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.HIST_DEL_FLAG].Value = out_node.GetList("LOT_TBL")[i].GetChar("HIST_DEL_FLAG");
                        spdInvLotList_Sheet1.Cells[iRow, (int)INV_LOT.TRAN_USER_ID].Value = out_node.GetList("LOT_TBL")[i].GetString("TRAN_USER_ID");
                    }

                    if (out_node.GetString("NEXT_INV_LOT_ID") != "")
                        in_node.SetString("NEXT_INV_LOT_ID", out_node.GetString("NEXT_INV_LOT_ID"));
                    else
                        in_node.SetString("NEXT_INV_LOT_ID", "");

                } while (in_node.GetString("NEXT_INV_LOT_ID") != "");

                MPCF.FitColumnHeader(spdInvLotList);

                txtInvLotID.SelectAll();

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        #endregion


        private void btnView_Click(object sender, EventArgs e)
        {
            if (CheckCondition(CSGC.CHECK.VIEW) == false)
                return;

            ViewInLotHistory();
        }

        private void txtInvLotID_KeyDown(object sender, KeyEventArgs e)
        {
            try
            {
                if (e.KeyCode == Keys.Enter)
                {
                    if (CheckCondition(CSGC.CHECK.VIEW) == false)
                        return;

                    ViewInLotHistory();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdInvLotList, "InvLotHistory");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void spdInvLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == false && e.ColumnFooter == false)
                {
                    EXTFUC.SetSelectRowColor(spdInvLotList, e.Row);
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void frmViewInvLotHistory_Load(object sender, EventArgs e)
        {
            try
            {
                MPCF.FitColumnHeader(spdInvLotList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}
