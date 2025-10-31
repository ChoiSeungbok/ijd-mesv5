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
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using FarPoint.Excel;
using System.IO;
using FarPoint.Win.Spread;

namespace CUS_WIP
{
    public partial class frmTranCupCellMappingCTV : CUS_COM.frmTranForm01
    {
        public frmTranCupCellMappingCTV()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT_LIST
        {
            CHK,                    // 1 : 체크
            GROUP_ID,               // 2 : 그룹ID
            MAPPING_SEQ,            // 3 : MAPPING 순서
            D12_ID,                 // 4 : D12 ID
            LOT_ID,                 // 5 : LOT ID
            MAT_ID,                 // 6 : 제품코드
            MAT_DESC,               // 7 : 제품명
            QTY_1,                  // 8 : 수량
            CREATE_DATE,            // 9 : 생산일
            LOSS_DESC, 
            LOSS_SELECT, 
            LOSS_CODE,
            COMMENT,
            PRESS_RES_DESC,         // 프레스 설비
            CAR_DESC,                // CAR
            CELL_WEIGHT,
            CELL_HEIGHT,
            OUT_OPER,
            LOT_TYPE,
            ETC_ACCOUNT
        }

        private enum WORKER_INFO
        {
            CHK,                    // 1 : CHECK
            WORKER,                 // 2 : 이름
            WORKER_ID               // 3 : 사번
        }


        #endregion

        #region " Variable Definition "

        int iMappingCount = 0;  //mapping 되는 count 변수
        string sCheckOption = "";

        string sPrintStartYN = "";
        string sPrintEndYN = "";
        string sPrintLabelID = "";
        string sPrinListName = "";
        string sAutoSearch = "N";

        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {

                cdvDept.Text = "CTV";
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnStart.Anchor = AnchorStyles.Top | AnchorStyles.Right;

                btnInputMat.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnLotData.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnWorker.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                pnlInputMappingCount.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                chkNotBom.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnGCM.Anchor = AnchorStyles.Top | AnchorStyles.Right;


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //lot list를 불러오는 함수
        private void ViewLotList()
        {
            string sView_ID = "";
            int iMaxMappinSeq = 0;

            FarPoint.Win.Spread.CellType.CheckBoxCellType checkBox = new FarPoint.Win.Spread.CellType.CheckBoxCellType();

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                
                if (cdvWorkType.Text == CSGC.CP_WORK_TYPE_WAIT
                    ){
                    sView_ID = "CWIP2040-001";              //착공
                }
                else
                {
                    sView_ID = "CWIP2040-004";              //완공
                }
      
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                dvcArgu[2].sCondition_ID = "ORDER_ID";
                dvcArgu[2].sCondition_Value = cdvOrder.Text;

                dvcArgu[3].sCondition_ID = "GROUP_TYPE";
                dvcArgu[3].sCondition_Value = cdvGroupType.Text;

                dvcArgu[4].sCondition_ID = "LOT_STATUS";
                dvcArgu[4].sCondition_Value = cdvWorkType.Text;


                dvcArgu[5].sCondition_ID = "GROUP_ID";
                dvcArgu[5].sCondition_Value = txtGroupID.Text;



                if (TPDR.GetDataOne("", ref dt, sView_ID, dvcArgu, false, false, ref sSql) == false)
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
                    //착공

                    if (cdvWorkType.Text == CSGC.CP_WORK_TYPE_WAIT)  ////착공
                    {
     


                        for (int iCount = 1; iCount <= MPCF.ToInt(txtMappingCount.Text) ; iCount++)
                        {

                            spdLotList_Sheet1.RowCount++;

                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount -1, (int)LOT_LIST.GROUP_ID].Value = dt.Rows[i]["GROUP_ID"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.MAPPING_SEQ].Value = iCount.ToString();




                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.D12_ID].Value = dt.Rows[i]["GROUP_ID"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.LOT_ID].Value = dt.Rows[i]["LOT_ID"].ToString()  + "_" + iCount.ToString();
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.QTY_1].Value = dt.Rows[i]["QTY_1"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.LOSS_DESC].Value = dt.Rows[i]["LOSS_DESC"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.LOSS_CODE].Value = dt.Rows[i]["LOSS_CODE"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.COMMENT].Value = dt.Rows[i]["LOT_COMMENT"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.PRESS_RES_DESC].Value = dt.Rows[i]["PRESS_RES_DESC"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CAR_DESC].Value = dt.Rows[i]["CAR_DESC"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CELL_WEIGHT].Value = dt.Rows[i]["CELL_WEIGHT"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CELL_HEIGHT].Value = dt.Rows[i]["CELL_HEIGHT"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.OUT_OPER].Value = dt.Rows[i]["OUT_OPER"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.ETC_ACCOUNT].Value = dt.Rows[i]["ETC_ACCOUNT"];

                            if (iCount == 1)
                            {
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CHK].CellType = checkBox;
                                spdLotList_Sheet1.SetValue(spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CHK, false);
                            }
                            else
                            {
                                spdLotList_Sheet1.SetValue(spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CHK, "");
                            }



                        }

                    }
                    else//완공
                    {
                        spdLotList_Sheet1.RowCount++;

                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.GROUP_ID].Value = dt.Rows[i]["GROUP_ID"];
                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAPPING_SEQ].Value = dt.Rows[i]["MAPPING_SEQ"];


                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.D12_ID].Value = dt.Rows[i]["D12_ID"];
                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.QTY_1].Value = dt.Rows[i]["QTY_1"];
                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.LOSS_DESC].Value = dt.Rows[i]["LOSS_DESC"];
                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.LOSS_CODE].Value = dt.Rows[i]["LOSS_CODE"];
                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.COMMENT].Value = dt.Rows[i]["LOT_COMMENT"];
                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.PRESS_RES_DESC].Value = dt.Rows[i]["PRESS_RES_DESC"];
                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.CAR_DESC].Value = dt.Rows[i]["CAR_DESC"];
                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.CELL_WEIGHT].Value = dt.Rows[i]["CELL_WEIGHT"];
                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.CELL_HEIGHT].Value = dt.Rows[i]["CELL_HEIGHT"];
                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.OUT_OPER].Value = dt.Rows[i]["OUT_OPER"];
                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                        spdLotList_Sheet1.Cells[i, (int)LOT_LIST.ETC_ACCOUNT].Value = dt.Rows[i]["ETC_ACCOUNT"];


                        if (dt.Rows[i]["MAPPING_SEQ"].ToString() == "1")
                        {
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CHK].CellType = checkBox;
                            spdLotList_Sheet1.SetValue(spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CHK, false);
                        }
                        else
                        {
                            spdLotList_Sheet1.SetValue(spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CHK, "");
                        }


                        if(iMaxMappinSeq < MPCF.ToInt(spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAPPING_SEQ].Text))
                         {
                            iMaxMappinSeq = MPCF.ToInt(spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAPPING_SEQ].Text);
                        }

                    }


                }


                if (cdvWorkType.Text == CSGC.CP_WORK_TYPE_PROC)  ///완공
                {
                    txtMappingCount.Text = iMaxMappinSeq.ToString();
                }

                    /*


                        //완공시 착공에서 맵핑했던 seq의 마지막 값을 가져온다. 
                        //iMaxSeq
                        if (cdvWorkType.Text == CSGC.CP_WORK_TYPE_PROC)
                        {
                            iMaxSeq = 0;
                            sTmp = "";

                            for (i = 0; i < dt.Rows.Count; i++)
                            {
                                if (i == 0)
                                    sTmp = dt.Rows[i]["GROUP_ID"].ToString();
                                else
                                {
                                    if (sTmp != dt.Rows[i]["GROUP_ID"].ToString())
                                    {
                                        break;
                                    }
                                }

                                iMaxSeq++;

                                //if (MPCF.ToInt(dt.Rows[i]["MAPPING_SEQ"].ToString()) >= iMaxSeq )
                                //{
                                //    iMaxSeq = MPCF.ToInt(dt.Rows[i]["MAPPING_SEQ"].ToString());
                                //}
                            }

                            iMappingCount = iMaxSeq;
                            txtMappingCount.Text = iMappingCount.ToString();
                        }

                        for (i = 0; i < dt.Rows.Count; i++)
                        {
                            spdLotList_Sheet1.RowCount++;

                            //묶음 seq 나타낸다.
                            iSeq++;

                            //묶음의 첫번째 row 에는 check 박스를 만들고 나머지 부분은 공백으로 한다.
                            if (iSeq == 1)
                            {
                                spdLotList_Sheet1.Cells[i, (int)LOT_LIST.CHK].CellType = checkBox;
                                spdLotList_Sheet1.SetValue(i, (int)LOT_LIST.CHK, false);
                            }
                            else
                            {
                                spdLotList_Sheet1.SetValue(i, (int)LOT_LIST.CHK, "");
                            }

                            //GROUP_ID가 없는 경우 #1, #2 순으로 임시로 보여준다. 
                            if (MPCF.Trim(dt.Rows[i]["GROUP_ID"].ToString()) == "")
                            {
                                spdLotList_Sheet1.Cells[i, (int)LOT_LIST.GROUP_ID].Value = "#" + iGrpCount.ToString();

                            }
                            else
                                spdLotList_Sheet1.Cells[i, (int)LOT_LIST.GROUP_ID].Value = dt.Rows[i]["GROUP_ID"];

                            //D12인경우 MAPPING_SEQ를 각 lot 단위로 올려준다.
                            if (cdvGroupType.Text == CSGC.CP_MAPPING_GROUP_D12)
                            {
                                if (MPCF.ToInt(dt.Rows[i]["MAPPING_SEQ"].ToString()) == 0)
                                    spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAPPING_SEQ].Value = iSeq;
                                else
                                    spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAPPING_SEQ].Value = dt.Rows[i]["MAPPING_SEQ"];
                            }
                            else
                            {
                                //cell 인경우 D12 ID별 MAPPING_SEQ를 올려준다.
                                if (iSeq == 1)
                                    iLotCount = 1;
                                else
                                {
                                    if (dt.Rows[i]["D12_ID"].ToString() != spdLotList_Sheet1.Cells[i - 1, (int)LOT_LIST.D12_ID].Text)
                                        iLotCount++;
                                }

                                if (MPCF.ToInt(dt.Rows[i]["MAPPING_SEQ"].ToString()) == 0)
                                    spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAPPING_SEQ].Value = iLotCount;
                                else
                                    spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAPPING_SEQ].Value = dt.Rows[i]["MAPPING_SEQ"];
                            }

                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.D12_ID].Value = dt.Rows[i]["D12_ID"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.QTY_1].Value = dt.Rows[i]["QTY_1"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.LOSS_DESC].Value = dt.Rows[i]["LOSS_DESC"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.LOSS_CODE].Value = dt.Rows[i]["LOSS_CODE"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.COMMENT].Value = dt.Rows[i]["LOT_COMMENT"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.PRESS_RES_DESC].Value = dt.Rows[i]["PRESS_RES_DESC"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.CAR_DESC].Value = dt.Rows[i]["CAR_DESC"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.CELL_WEIGHT].Value = dt.Rows[i]["CELL_WEIGHT"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.CELL_HEIGHT].Value = dt.Rows[i]["CELL_HEIGHT"];

                            if (iSeq == iMappingCount)
                            {
                                //MAPPING COUNT 만큼 CHECK , MAPPING ID를 SPAN 처리 해준다. 
                                spdLotList_Sheet1.AddSpanCell(i - (iSeq - 1), (int)LOT_LIST.CHK, iSeq, 1);
                                spdLotList_Sheet1.AddSpanCell(i - (iSeq - 1), (int)LOT_LIST.PRESS_RES_DESC, iSeq, 1);
                                spdLotList_Sheet1.AddSpanCell(i - (iSeq - 1), (int)LOT_LIST.CAR_DESC, iSeq, 1);
                                spdLotList_Sheet1.AddSpanCell(i - (iSeq - 1), (int)LOT_LIST.CELL_WEIGHT, iSeq, 1);
                                spdLotList_Sheet1.AddSpanCell(i - (iSeq - 1), (int)LOT_LIST.CELL_HEIGHT, iSeq, 1);

                                iSeq = 0;
                                iLotCount = 0;
                                iGrpCount++;                        
                            }
                            else if ((i == dt.Rows.Count - 1) && (iSeq != iMappingCount))
                            {
                                spdLotList_Sheet1.AddSpanCell(i - (iSeq - 1), (int)LOT_LIST.CHK, iSeq, 1);

                                spdLotList_Sheet1.AddSpanCell(i - (iSeq - 1), (int)LOT_LIST.PRESS_RES_DESC, iSeq, 1);
                                spdLotList_Sheet1.AddSpanCell(i - (iSeq - 1), (int)LOT_LIST.CAR_DESC, iSeq, 1);
                                spdLotList_Sheet1.AddSpanCell(i - (iSeq - 1), (int)LOT_LIST.CELL_WEIGHT, iSeq, 1);
                                spdLotList_Sheet1.AddSpanCell(i - (iSeq - 1), (int)LOT_LIST.CELL_HEIGHT, iSeq, 1);
                            }
                        }

                        */




                    MPCF.FitColumnHeader(spdLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        private void ViewLotList2()
        {

            //테스트 작지 LOT 처리
            string sView_ID = "";
            int iMaxMappinSeq = 0;


            FarPoint.Win.Spread.CellType.CheckBoxCellType checkBox = new FarPoint.Win.Spread.CellType.CheckBoxCellType();

            try
            {

                string sSql = "";
                int i = 0;
                int iCellLotCount = 0;


                if (cdvWorkType.Text == CSGC.CP_WORK_TYPE_WAIT)
                {
                    MPCF.ClearList(spdLotList);

                    if (MPCF.ToInt(txtOrderRemaniQty.Text) % MPCF.ToInt(txtMappingCount.Text) != 0)
                    {
                        MPCF.ShowMsgBox("총수량과 분할수량이 맞지않습니다.");
                        return;
                    }


                    TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                    DataTable dt = null;

                    sView_ID = "CWIP2040-006";              


                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = MPGV.gsFactory;


                    dvcArgu[1].sCondition_ID = "OPER";
                    dvcArgu[1].sCondition_Value = cdvOper.Text;

                    dvcArgu[2].sCondition_ID = "ORDER_ID";
                    dvcArgu[2].sCondition_Value = cdvOrder.Text;


                    if (TPDR.GetDataOne("", ref dt, sView_ID, dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt != null)
                            dt.Dispose();

                        GC.Collect();

                        MPCF.ClearList(spdLotList);
                        return;
                    }




                    iCellLotCount = MPCF.ToInt(txtOrderRemaniQty.Text) / MPCF.ToInt(txtMappingCount.Text);


                    
                    if (MPCF.ToInt(dt.Rows[i]["REMAIN_QTY"].ToString()) < MPCF.ToInt(txtOrderRemaniQty.Text))
                    {
                        MPCF.ShowMsgBox("오더잔량보다 생성수량이 많습니다.");
                        return;
                    }
                    

                    txtOrderType.Text = dt.Rows[0]["CREATE_CODE"].ToString();


                    for (int iRow = 1; iRow  <= iCellLotCount; iRow++)
                    {
                        TRSNode in_node = new TRSNode("Create_Lot_In");
                        TRSNode out_node = new TRSNode("Create_Lot_Out");

                        MPCR.SetInMsg(in_node);
                        in_node.ProcStep = '2';
                        in_node.AddString("RULE_ID", "WIP_OPER_LOT_ID");
                        in_node.AddString("DATETIME", DateTime.Now.ToString("yyyyMMdd"));
                        in_node.AddString("OVR_TIME", DateTime.Now.ToString("yyyyMMdd"));
                        in_node.AddString("OPER", cdvOper.Text);
                        in_node.AddString("SEQ_KEY_10", DateTime.Now.ToString("yyyyMMdd"));


                        if (MPCR.CallService("CUS_WIP", "CUS_WIP_Generate_Id", in_node, ref out_node) == false)
                        {
                            return;
                        }




                        for (int iCount = 1; iCount <= MPCF.ToInt(txtMappingCount.Text); iCount++)
                        {

                            spdLotList_Sheet1.RowCount++;

                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.GROUP_ID].Value = out_node.GetList(0)[0].GetString("GEN_ID");
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.MAPPING_SEQ].Value = iCount.ToString();



                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.D12_ID].Value = out_node.GetList(0)[0].GetString("GEN_ID");
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.LOT_ID].Value = out_node.GetList(0)[0].GetString("GEN_ID") + "_" + iCount.ToString();
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.MAT_ID].Value = dt.Rows[0]["MAT_ID"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.MAT_DESC].Value = dt.Rows[0]["MAT_DESC"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.QTY_1].Value = dt.Rows[0]["QTY_1"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.LOSS_DESC].Value = dt.Rows[0]["LOSS_DESC"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.LOSS_CODE].Value = dt.Rows[0]["LOSS_CODE"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.COMMENT].Value = dt.Rows[0]["LOT_COMMENT"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.PRESS_RES_DESC].Value = dt.Rows[0]["PRESS_RES_DESC"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CAR_DESC].Value = dt.Rows[0]["CAR_DESC"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CELL_WEIGHT].Value = dt.Rows[0]["CELL_WEIGHT"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CELL_HEIGHT].Value = dt.Rows[0]["CELL_HEIGHT"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.OUT_OPER].Value = dt.Rows[0]["OUT_OPER"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.LOT_TYPE].Value = dt.Rows[0]["LOT_TYPE"];
                            spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.ETC_ACCOUNT].Value = dt.Rows[0]["ETC_ACCOUNT"];

                            if (iCount == 1)
                            {
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CHK].CellType = checkBox;
                                spdLotList_Sheet1.SetValue(spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CHK, false);
                            }
                            else
                            {
                                spdLotList_Sheet1.SetValue(spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CHK, "");
                            }

                        }
                    }

                }
                else
                {


                    TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                    DataTable dt = null;

                    sView_ID = "CWIP2040-004";              //완공


                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                    dvcArgu[1].sCondition_ID = "OPER";
                    dvcArgu[1].sCondition_Value = cdvOper.Text;

                    dvcArgu[2].sCondition_ID = "ORDER_ID";
                    dvcArgu[2].sCondition_Value = cdvOrder.Text;

                    dvcArgu[3].sCondition_ID = "GROUP_TYPE";
                    dvcArgu[3].sCondition_Value = cdvGroupType.Text;

                    dvcArgu[4].sCondition_ID = "LOT_STATUS";
                    dvcArgu[4].sCondition_Value = cdvWorkType.Text;


                    dvcArgu[5].sCondition_ID = "GROUP_ID";
                    dvcArgu[5].sCondition_Value = txtGroupID.Text;



                    if (TPDR.GetDataOne("", ref dt, sView_ID, dvcArgu, false, false, ref sSql) == false)
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
                        //착공

                        if (cdvWorkType.Text == CSGC.CP_WORK_TYPE_WAIT)  ////착공
                        {



                            for (int iCount = 1; iCount <= MPCF.ToInt(txtMappingCount.Text); iCount++)
                            {

                                spdLotList_Sheet1.RowCount++;

                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.GROUP_ID].Value = dt.Rows[i]["GROUP_ID"];
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.MAPPING_SEQ].Value = iCount.ToString();




                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.D12_ID].Value = dt.Rows[i]["GROUP_ID"];
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.LOT_ID].Value = dt.Rows[i]["LOT_ID"].ToString() + "_" + iCount.ToString();
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.QTY_1].Value = dt.Rows[i]["QTY_1"];
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.LOSS_DESC].Value = dt.Rows[i]["LOSS_DESC"];
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.LOSS_CODE].Value = dt.Rows[i]["LOSS_CODE"];
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.COMMENT].Value = dt.Rows[i]["LOT_COMMENT"];
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.PRESS_RES_DESC].Value = dt.Rows[i]["PRESS_RES_DESC"];
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CAR_DESC].Value = dt.Rows[i]["CAR_DESC"];
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CELL_WEIGHT].Value = dt.Rows[i]["CELL_WEIGHT"];
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CELL_HEIGHT].Value = dt.Rows[i]["CELL_HEIGHT"];
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.OUT_OPER].Value = dt.Rows[i]["OUT_OPER"];
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.ETC_ACCOUNT].Value = dt.Rows[i]["ETC_ACCOUNT"];

                                if (iCount == 1)
                                {
                                    spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CHK].CellType = checkBox;
                                    spdLotList_Sheet1.SetValue(spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CHK, false);
                                }
                                else
                                {
                                    spdLotList_Sheet1.SetValue(spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CHK, "");
                                }



                            }

                        }
                        else//완공
                        {
                            spdLotList_Sheet1.RowCount++;

                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.GROUP_ID].Value = dt.Rows[i]["GROUP_ID"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAPPING_SEQ].Value = dt.Rows[i]["MAPPING_SEQ"];


                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.D12_ID].Value = dt.Rows[i]["D12_ID"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.QTY_1].Value = dt.Rows[i]["QTY_1"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.CREATE_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["CREATE_TIME"].ToString(), DATE_TIME_FORMAT.DATE);
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.LOSS_DESC].Value = dt.Rows[i]["LOSS_DESC"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.LOSS_CODE].Value = dt.Rows[i]["LOSS_CODE"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.COMMENT].Value = dt.Rows[i]["LOT_COMMENT"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.PRESS_RES_DESC].Value = dt.Rows[i]["PRESS_RES_DESC"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.CAR_DESC].Value = dt.Rows[i]["CAR_DESC"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.CELL_WEIGHT].Value = dt.Rows[i]["CELL_WEIGHT"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.CELL_HEIGHT].Value = dt.Rows[i]["CELL_HEIGHT"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.OUT_OPER].Value = dt.Rows[i]["OUT_OPER"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.LOT_TYPE].Value = dt.Rows[i]["LOT_TYPE"];
                            spdLotList_Sheet1.Cells[i, (int)LOT_LIST.ETC_ACCOUNT].Value = dt.Rows[i]["ETC_ACCOUNT"];


                            if (dt.Rows[i]["MAPPING_SEQ"].ToString() == "1")
                            {
                                spdLotList_Sheet1.Cells[spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CHK].CellType = checkBox;
                                spdLotList_Sheet1.SetValue(spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CHK, false);
                            }
                            else
                            {
                                spdLotList_Sheet1.SetValue(spdLotList_Sheet1.RowCount - 1, (int)LOT_LIST.CHK, "");
                            }


                            if (iMaxMappinSeq < MPCF.ToInt(spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAPPING_SEQ].Text))
                            {
                                iMaxMappinSeq = MPCF.ToInt(spdLotList_Sheet1.Cells[i, (int)LOT_LIST.MAPPING_SEQ].Text);
                            }

                        }


                    }


                }

                if (cdvWorkType.Text == CSGC.CP_WORK_TYPE_PROC)  ///완공
                {
                    txtMappingCount.Text = iMaxMappinSeq.ToString();
                }

    



                MPCF.FitColumnHeader(spdLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }




        //공정별 loss 리스트 불러오는 함수
        public bool ViewOperLossList(Control control)
        {
            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2012-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return false;

                foreach (DataRow row in dt.Rows)
                {
                    if (control is System.Windows.Forms.ListView)
                    {
                        itmX = new ListViewItem(row["KEY_2"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((System.Windows.Forms.ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["DATA_1"].ToString());
                        }
                        ((System.Windows.Forms.ListView)control).Items.Add(itmX);
                    }
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //작업자 리스트 불러오는 함수
        private void ViewWorkerList()
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

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvOper.Text;

                dvcArgu[4].sCondition_ID = "WORKER_GROUP";
                dvcArgu[4].sCondition_Value = cdvWorkGroup.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2012-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdWorkerList);
                    return;
                }

                MPCF.ClearList(spdWorkerList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdWorkerList_Sheet1.RowCount++;

                    spdWorkerList_Sheet1.SetValue(i, (int)WORKER_INFO.CHK, false);
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER].Value = dt.Rows[i]["WORKER"];
                    spdWorkerList_Sheet1.Cells[i, (int)WORKER_INFO.WORKER_ID].Value = dt.Rows[i]["WORKER_ID"];
                }
                MPCF.FitColumnHeader(spdWorkerList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //저장 함수
        private bool SaveProcess(char c_step)
        {
            bool bCheck = false;
            int iCount = 0;
            bool bPrint = false;

            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                TRSNode Lot_list;
                TRSNode Worker_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = c_step;

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("ORDER_ID", cdvOrder.Text);
                in_node.AddString("GROUP_TYPE", cdvGroupType.Text);
                in_node.AddString("COMMENT", txtComment.Text);
                in_node.AddInt("MAPPING_COUNT", MPCF.ToInt(txtMappingCount.Text));

                if(chkNotBom.Checked == true)
                {
                    in_node.AddChar("INPUT_BOM", 'N');

                }
                else
                {
                    in_node.AddChar("INPUT_BOM", 'Y');
                }


                if (sCheckOption == "Y")
                {
                    in_node.AddString("PRESS_RES_ID", cdvResource.Text);
                    in_node.AddString("CAR", cdvCar.Text);
                }

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        bCheck = true;
                    }
                    if (bCheck == true)
                    {
                        Lot_list = in_node.AddNode("LOT_TBL");
                        Lot_list.AddString("GROUP_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.GROUP_ID].Text);
                        Lot_list.AddString("D12_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.D12_ID].Text);
                        Lot_list.AddInt("MAPPING_SEQ", spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.MAPPING_SEQ].Text);
                        Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.LOT_ID].Text);
                        Lot_list.AddString("LOSS_CODE", spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.LOSS_CODE].Text);
                        Lot_list.AddString("COMMENT", spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.COMMENT].Text);
                        Lot_list.AddString("OUT_OPER", spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.OUT_OPER].Text);



                        Lot_list.AddString("LOT_TYPE", spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.LOT_TYPE].Text);
                        Lot_list.AddString("INPUT_TYPE", CSGC.CP_MAT_INPUT_TYPE_BOM);
                        Lot_list.AddString("MAT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.MAT_ID].Text);
                        Lot_list.AddDouble("QTY_1", spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.QTY_1].Text);
                        Lot_list.AddDouble("BOM_QTY", MPCF.ToInt(spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.QTY_1].Text) /MPCF.ToInt(txtMappingCount.Text));



                        if (sCheckOption == "Y")
                        {
                            Lot_list.AddDouble("CELL_WEIGHT", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CELL_WEIGHT].Text));
                            Lot_list.AddDouble("CELL_HEIGHT", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CELL_HEIGHT].Text));
                        }

                        iCount++;
                    }
                    if (MPCF.ToInt(txtMappingCount.Text) == iCount)
                    {
                        iCount = 0;
                        bCheck = false;
                    }
                }

                if (c_step == '4')
                {
                    for (int k = 0; k < spdWorkerList.ActiveSheet.RowCount; k++)
                    {
                        if (spdWorkerList.ActiveSheet.Cells[k, (int)WORKER_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                        {
                            Worker_list = in_node.AddNode("WORKER_TBL");
                            Worker_list.AddString("WORKER_ID", spdWorkerList.ActiveSheet.Cells[k, (int)WORKER_INFO.WORKER_ID].Text);
                        }
                    }
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Cup_Cell_Process_Lot", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                if (c_step == '3')
                {
                    if (CheckPrintOption(cdvOper.Text, cdvOrder.Text))
                    {
                        if (sPrintStartYN == "Y")
                            bPrint = true;
                    }
                }
                else if (c_step == '4')
                {
                    if (CheckPrintOption(cdvOper.Text, cdvOrder.Text))
                    {
                        if (sPrintEndYN == "Y")
                            bPrint = true;
                    }
                }

                //프린트 공정인 경우 프린트 한다.
                if (bPrint == true)
                {
                    PrintLable(sPrintLabelID, out_node);
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //공정별 MAPPING TYPE을 가져오는 함수
        private void ViewMappingType()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2012-005", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    cdvGroupType.Text = "";
                    iMappingCount = 0;

                    return;
                }

                if (dt != null)
                {
                    cdvGroupType.Text = dt.Rows[i]["KEY_1"].ToString();
                    cdvGroupType.DisplayText = dt.Rows[i]["DATA_1"].ToString();
                    iMappingCount = MPCF.ToInt(dt.Rows[i]["DATA_2"].ToString());
                    sCheckOption = dt.Rows[i]["DATA_4"].ToString();
                }

                if (cdvGroupType.Text == CSGC.CP_MAPPING_GROUP_D12)
                {
                    spdLotList.ActiveSheet.Columns[(int)LOT_LIST.D12_ID].Visible = false;

                }
                else if (cdvGroupType.Text == CSGC.CP_MAPPING_GROUP_CELL)
                {
                    spdLotList.ActiveSheet.Columns[(int)LOT_LIST.D12_ID].Visible = true;
                }

                //txtMappingCount 추가로 인해 맵핑카운트 보여주도록 함.
                txtMappingCount.Enabled = false;
                chkAditMappingCount.Checked = false;
                btnApply.Enabled = false;
                txtMappingCount.Text = iMappingCount.ToString();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        //lot 위치 조정 함수
        private void LotPositionControl(string sType)
        {
            int iRowIndex = 0;
            int iMoveCount = 0;
            int iChangeColCount = 0;
            int iChangeRowCount = 0;
            int iStartColidx = 0;
            string tmp = "";
            int itmpRow = 0;

            int iMaxSeq = 0;
            int iMoveSeq = 0;

            try
            {
                iMaxSeq = MPCF.ToInt(txtMappingCount.Text);
                iMoveSeq = (int)(iMaxSeq / 2);

                iRowIndex = spdLotList.ActiveSheet.ActiveRowIndex;

                if (cdvGroupType.Text == CSGC.CP_MAPPING_GROUP_D12)
                {
                    if (sType == "UP")
                    {
                        //iMoveCount = -1;
                        iMoveCount = -iMoveSeq;

                        if (iRowIndex == 0)
                            return;                        
                    }
                    else if (sType == "DOWN")
                    {
                        //iMoveCount = 1;
                        iMoveCount = iMoveSeq;

                        if (iRowIndex == spdLotList.ActiveSheet.RowCount - iMoveCount)
                            return;                        
                    }

                    iChangeColCount = (int)LOT_LIST.COMMENT - (int)LOT_LIST.LOT_ID;
                    iStartColidx = (int)LOT_LIST.LOT_ID;
                    //iChangeRowCount = 1;
                    iChangeRowCount = iMoveSeq;
                }
                else
                {      
                    //D12 ID인 경우 두번째 lot을 선택 하더라고 D12 ID별로 움직여야 하므로 D12의 첫번째 lot의 row index로 바꿔준다.              
                    tmp = spdLotList.ActiveSheet.Cells[iRowIndex, (int)LOT_LIST.D12_ID].Text;

                    for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.D12_ID].Text == tmp)
                        {
                            itmpRow = i;
                            break;
                        }
                    }

                    if (itmpRow < iRowIndex)
                        iRowIndex = itmpRow;

                    if (sType == "UP")
                    {
                        //iMoveCount = -2;
                        iMoveCount = -iMoveSeq;

                        if (iRowIndex == 0)
                            return;
                    }
                    else if (sType == "DOWN")
                    {
                        //iMoveCount = 2;
                        iMoveCount = iMoveSeq;

                        if (iRowIndex == spdLotList.ActiveSheet.RowCount - iMoveCount)
                            return;                        
                    }
                           
                    iChangeColCount = (int)LOT_LIST.COMMENT - (int)LOT_LIST.D12_ID;
                    iStartColidx = (int)LOT_LIST.D12_ID;
                    //iChangeRowCount = 2;
                    iChangeRowCount = iMoveSeq;
                }
                
                //row별 데이터를 to row의 데이터와 swap 하여 데이터 위치를 바꾼다.
                spdLotList.ActiveSheet.SwapRange(iRowIndex, iStartColidx, iRowIndex + iMoveCount, iStartColidx, iChangeRowCount, iChangeColCount, true);
                
                //포커스 변경 및 포커스 row 색 변경
                spdLotList.ActiveSheet.ActiveRowIndex = iRowIndex + iMoveCount;

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    spdLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdLotList.ActiveSheet.Rows[iRowIndex + iMoveCount].BackColor = Color.FromArgb(255, 192, 255);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //벨리데이션 체크 함수
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            int iWorkerCount = 0;

            try
            {
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

                if (MPCF.Trim(cdvOrder.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOrder.Text + "]");
                    cdvOrder.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvGroupType.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblGroupType.Text + "]");
                    cdvGroupType.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvWorkType.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkType.Text + "]");
                    cdvWorkType.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:


                        break;

                    case CSGC.CHECK.START:

                        if (sCheckOption == "Y")
                        {

                            for (int k = 0; k < spdLotList.ActiveSheet.RowCount; k++)
                            {
                                if (spdLotList.ActiveSheet.Cells[k, (int)LOT_LIST.CHK].Value.ToString().ToUpper() == "TRUE")
                                {
                                    /*
                                    if (spdLotList.ActiveSheet.Cells[k, (int)LOT_LIST.ETC_ACCOUNT].Text.Trim() !="")
                                    {
                                        if (MPCF.ShowMsgBox("해당오더의 투입품은 기타출고됩니다. 기타출고명(" + spdLotList.ActiveSheet.Cells[k, (int)LOT_LIST.ETC_ACCOUNT].Text  + ") 계속 진행하시겠습니까?", MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                                        {
                                            return false;
                                        }
                                    }
                                    */
                                }
                            }


                                //if (MPCF.Trim(cdvResource.Text) == "")
                                //{
                                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblResource.Text + "]");
                                //    cdvResource.Focus();
                                //    return false;
                                //}

                                //if (MPCF.Trim(cdvCar.Text) == "")
                                //{
                                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblCar.Text + "]");
                                //    cdvCar.Focus();
                                //    return false;
                                //}

                                //for (int k = 0; k < spdLotList.ActiveSheet.RowCount; k++)
                                //{
                                //    if (spdLotList.ActiveSheet.Cells[k, (int)LOT_LIST.CHK].Value.ToString().ToUpper() == "TRUE")
                                //    {
                                //        if (MPCF.ToDbl(spdLotList.ActiveSheet.Cells[k, (int)LOT_LIST.CELL_HEIGHT].Text) == 0
                                //            || spdLotList.ActiveSheet.Cells[k, (int)LOT_LIST.CELL_HEIGHT].Text == "")
                                //        {
                                //            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                //            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblCellHeight.Text + "]");
                                //            txtCellHeight.Focus();
                                //            return false;
                                //        }

                                //        if (MPCF.ToDbl(spdLotList.ActiveSheet.Cells[k, (int)LOT_LIST.CELL_WEIGHT].Text) == 0
                                //            || spdLotList.ActiveSheet.Cells[k, (int)LOT_LIST.CELL_WEIGHT].Text == "")
                                //        {
                                //            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                //            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblCellWeight.Text + "]");
                                //            txtCellWeight.Focus();
                                //            return false;
                                //        }
                                //    }
                                //}
                        }

                        break;

                    case CSGC.CHECK.END:

                        if (sCheckOption == "Y")
                        {
                            /*
                            if (MPCF.Trim(cdvResource.Text) == "")
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblResource.Text + "]");
                                cdvResource.Focus();
                                return false;
                            }
                            */
                            /*
                            if (MPCF.Trim(cdvCar.Text) == "")
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblCar.Text + "]");
                                cdvCar.Focus();
                                return false;
                            }
                            */

                            for (int k = 0; k < spdLotList.ActiveSheet.RowCount; k++)
                            {
                                //if (spdLotList.ActiveSheet.Cells[k, (int)LOT_LIST.CHK].Value.ToString().ToUpper() == "TRUE")
                                //{
                                //    if (MPCF.ToDbl(spdLotList.ActiveSheet.Cells[k, (int)LOT_LIST.CELL_HEIGHT].Text) == 0
                                //    || spdLotList.ActiveSheet.Cells[k, (int)LOT_LIST.CELL_HEIGHT].Text == "")
                                //    {
                                //        //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                //        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblCellHeight.Text + "]");
                                //        txtCellHeight.Focus();
                                //        return false;
                                //    }

                                //    if (MPCF.ToDbl(spdLotList.ActiveSheet.Cells[k, (int)LOT_LIST.CELL_WEIGHT].Text) == 0
                                //        || spdLotList.ActiveSheet.Cells[k, (int)LOT_LIST.CELL_WEIGHT].Text == "")
                                //    {
                                //        //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                //        MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblCellWeight.Text + "]");
                                //        txtCellWeight.Focus();
                                //        return false;
                                //    }
                                //}
                            }
                        }
                        
                        //작업자 체크
                        for (int i = 0; i < spdWorkerList.ActiveSheet.RowCount; i++)
                        {
                            if (spdWorkerList.ActiveSheet.Cells[i, (int)WORKER_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                                iWorkerCount++;
                        }

                        if (iWorkerCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + grpWorkerInfo.Text + "]");
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
                txtCellWeight.Text = "0";
                txtCellHeight.Text = "0";
                cdvResource.Text = "";
                cdvCar.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //프린팅 여부 체크 
        private bool CheckPrintOption(string sOper, string sOrder)
        {
            sPrintStartYN = "";
            sPrintEndYN = "";
            sPrintLabelID = "";
            sPrinListName = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                dvcArgu[2].sCondition_ID = "ORDER_ID";
                dvcArgu[2].sCondition_Value = sOrder;

                if (TPDR.GetDataOne("", ref dt, "CWIP0001-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }

                if (dt.Rows.Count > 0)
                {
                    sPrintStartYN = dt.Rows[0]["START_YN"].ToString();
                    sPrintEndYN = dt.Rows[0]["END_YN"].ToString();
                    sPrintLabelID = dt.Rows[0]["LABLE_ID"].ToString();
                    sPrinListName = dt.Rows[0]["LIST_TYPE"].ToString();
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        public bool PrintLable(string sPrintLabel, TRSNode out_node)
        {
            try
            {
                TRSNode print_node = new TRSNode("Print_In");
                TRSNode Print_Lot_list;
                MPCR.SetInMsg(print_node);

                print_node.AddString("ORDER_ID", cdvOrder.Text);

                for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                {
                    Print_Lot_list = print_node.AddNode("CELL_LIST");
                    Print_Lot_list.AddString("GROUP_ID", out_node.GetList("LOT_TBL")[i].GetString("GROUP_ID"));
                }

                CSCF.ViewLabelList(sPrintLabel, print_node);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void InputMappingCount()
        {

            pnlInputMappingCount.Visible = true;
            txtInputMappingCount.Enabled = true;
            //   txtInputMappingCount.Focus();
            txtInputMappingCount.Select();


            if (chkNotBom.Checked == true)
            {
                lblDivision.Visible = true;
                txtOrderRemaniQty.Visible = true;
                txtOrderRemaniQty.Enabled = true;
                lblTotalandmappingQty.Visible = true;
                lblMapping.Visible = false;
                txtOrderRemaniQty.Focus();
            }
            else
            {
                lblDivision.Visible = false;
                txtOrderRemaniQty.Visible = false;
                lblTotalandmappingQty.Visible = false;
                lblTotalandmappingQty.Enabled = false;
                lblMapping.Visible = true;
                txtInputMappingCount.Focus();

            }

        }

        private void cdvWorkType_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {


                pnlInputMappingCount.Visible = false;

                //완료
                if (e.SelectedItem.SubItems[0].Text == CSGC.CP_WORK_TYPE_PROC)
                {
                    btnUp.Enabled = false;
                    btnDown.Enabled = false;

                    btnStart.Enabled = false;
                    btnProcess.Enabled = true;

                    //셀조립의 완공일 때만 press 호기 및 카 정보를 저장 할 수 있도록 한다.
                    if (cdvGroupType.Text == CSGC.CP_MAPPING_GROUP_CELL)
                    {
                        cdvResource.Enabled = true;
                        cdvCar.Enabled = true;
                    }
                }
                //시작
                else if (e.SelectedItem.SubItems[0].Text == CSGC.CP_WORK_TYPE_WAIT)
                {
                    btnUp.Enabled = true;
                    btnDown.Enabled = true;
                    btnStart.Enabled = true;
                    btnProcess.Enabled = false;

                    cdvResource.Enabled = false;
                    cdvCar.Enabled = false;



                    //시작으로 할때 mapping 카운드를 디폴트값으로 세팅해주기 위해
                    if (MPCF.Trim(cdvOper.Text) != "")
                    {
                        ViewMappingType();
                    }
                }
                else
                {
                    btnUp.Enabled = true;
                    btnDown.Enabled = true;
                    btnStart.Enabled = true;
                    btnProcess.Enabled = true;

                    cdvResource.Enabled = false;
                    cdvCar.Enabled = false;
                }

                cdvResource.Text = "";
                cdvCar.Text = "";
                txtMappingCount.Text = "";

                MPCF.ClearList(spdLotList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void SearchMappingLotId()
        {
            //  string sBomYn = "Y";
            pnlInputMappingCount.Visible = false;
            txtMappingCount.Text = txtInputMappingCount.Text;
            txtInputMappingCount.Text = "";
            //txtOrderRemaniQty.Text = "";

            if (chkNotBom.Checked == true)
            {
                ViewLotList2();
            }
            else
            {
                ViewLotList();
            }
            txtComment.Focus();
            txtComment.Select();


        }


        /*
        private bool OrderCheck(string sBomYn)
        {


            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "ORDER_ID";
                dvcArgu[1].sCondition_Value = cdvOrder.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2040-005", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }

                if (dt.Rows[0]["BOM_YN"].ToString() == "N")
                {
                    if (dt.Rows[0]["ORDER_TYPE"].ToString() == "PROD")
                    {

                        //양산품 오더는 반드시 투입 BOM이 있어야합니다.오더 확인해주세요.
                        MPCF.ShowMsgBox("양산품 오더는 반드시 BOM이 있어야합니다,오더 확인해주세요" + " [" + cdvOrder.Text + "]");

                        return false;
                    }
                    else
                    {
                        if (MPCF.ShowMsgBox("BOM이 없습니다, 계속 진행하시겠습니까?", MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.Yes)
                        {
                            sBomYn = "N";
                            return true;
                        }
                    }

                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        */
        private void chkNotBom_CheckedChanged(object sender, EventArgs e)
        {

            MPCF.ClearList(spdLotList);

        }

        #endregion


        #region " Event Definition "

        private void frmTranCupCellMappingCTV_Load(object sender, EventArgs e)
        {
            try
            {
                //load시 mapping type을 조회해온다.
                if (MPCF.Trim(cdvOper.Text) != "")
                {
                    ViewMappingType();

                    if (sCheckOption != "Y")
                    {
                        //cdvResource.Enabled = false;
                        //cdvCar.Enabled = false;
                        txtCellWeight.Enabled = false;
                        txtCellHeight.Enabled = false;
                    }
                    else
                    {
                        //cdvResource.Enabled = true;
                        //cdvCar.Enabled = true;
                        txtCellWeight.Enabled = true;
                        txtCellHeight.Enabled = true;
                    }

                    cdvResource.Enabled = false;
                    cdvCar.Enabled = false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                MPCF.ClearList(spdLotList);

                ViewMappingType();

                if (sCheckOption != "Y")
                {
                    //cdvResource.Enabled = false;
                    //cdvCar.Enabled = false;
                    txtCellWeight.Enabled = false;
                    txtCellHeight.Enabled = false;
                }
                else
                {
                    //cdvResource.Enabled = true;
                    //cdvCar.Enabled = true;
                    txtCellWeight.Enabled = true;
                    txtCellHeight.Enabled = true;
                }

                cdvOperResource.Text = "";
                cdvResource.Text= "";
                cdvCar.Text = "";
                txtCellWeight.Text = "0";
                txtCellHeight.Text = "0";

                if (MPCF.Trim(cdvWorkGroup.Text) != "")
                {
                    ViewWorkerList();
                }                
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOrder_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }

                CUS_COM.Popup.frmPopWorkOrderList popup = new CUS_COM.Popup.frmPopWorkOrderList();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.g_AreaCode = cdvDept.Text;
                popup.g_AreaDesc = cdvDept.DisplayText;
                popup.g_SubAreaCode = cdvWorkPlace.Text;
                popup.g_SubAreaDesc = cdvWorkPlace.DisplayText;
                popup.g_OperCode = cdvOper.Text;
                popup.g_OperDesc = cdvOper.DisplayText;
                popup.g_WorkOrder = cdvOrder.Text;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvOrder.Text = popup.g_WorkOrder;
                    popup = null;
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvWorkType.Init();
                MPCF.InitListView(cdvWorkType.GetListView);
                cdvWorkType.Columns.Add("Key_1", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvWorkType.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvWorkType.Columns.Add("Count", 0, System.Windows.Forms.HorizontalAlignment.Left);
                cdvWorkType.SelectedSubItemIndex = 0;
                cdvWorkType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvWorkType.GetListView, '1', CSGC.CP_GCM_WORK_TYPE) == false)
                {
                    return;
                }

                cdvWorkType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Key_1", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOper.Columns.Add("Option", 0, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, 'L', "", "") == false)
                {
                    return;
                }

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOperResource_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }

                cdvOperResource.Init();
                MPCF.InitListView(cdvOperResource.GetListView);
                cdvOperResource.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOperResource.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOperResource.SelectedSubItemIndex = 0;
                cdvOperResource.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewResourceList(cdvOperResource.GetListView, '1', cdvOper.Text) == false)
                    return;

                cdvOperResource.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        private void cdvGroupType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvGroupType.Init();
                MPCF.InitListView(cdvGroupType.GetListView);
                cdvGroupType.Columns.Add("Key_1", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvGroupType.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvGroupType.Columns.Add("Count", 0, System.Windows.Forms.HorizontalAlignment.Left);
                cdvGroupType.SelectedSubItemIndex = 0;
                cdvGroupType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvGroupType.GetListView, '1', CSGC.CP_GCM_MAPPING_GROUP_TYPE) == false)
                {
                    return;
                }

                cdvGroupType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvGroupType_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (e.SelectedItem.SubItems[0].Text == CSGC.CP_MAPPING_GROUP_D12)
                {
                    spdLotList.ActiveSheet.Columns[(int)LOT_LIST.D12_ID].Visible = false;

                }
                else if (e.SelectedItem.SubItems[0].Text == CSGC.CP_MAPPING_GROUP_CELL)
                {
                    spdLotList.ActiveSheet.Columns[(int)LOT_LIST.D12_ID].Visible = true;
                }

                iMappingCount = MPCF.ToInt(e.SelectedItem.SubItems[2].Text);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvResource_ButtonPress(object sender, EventArgs e)
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

                cdvResource.Init();
                MPCF.InitListView(cdvResource.GetListView);
                cdvResource.Columns.Add("Key_1", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvResource.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvResource.Columns.Add("Count", 0, System.Windows.Forms.HorizontalAlignment.Left);
                cdvResource.SelectedSubItemIndex = 0;
                cdvResource.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewResourceListByGroup(cdvResource.GetListView,  CSGC.CP_RESOURCE_GROUP_PRESS, cdvDept.Text) == false)
                    return;

                cdvResource.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvResource_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvCar.Text = "";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvCar_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvCar.Init();
                MPCF.InitListView(cdvCar.GetListView);
                cdvCar.Columns.Add("Key_1", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvCar.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvCar.Columns.Add("Count", 0, System.Windows.Forms.HorizontalAlignment.Left);
                cdvCar.SelectedSubItemIndex = 0;
                cdvCar.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvCar.GetListView, '1', CSGC.CP_GCM_CAR) == false)
                {
                    return;
                }

                cdvCar.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkGroup_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvWorkGroup.Init();
                MPCF.InitListView(cdvWorkGroup.GetListView);
                cdvWorkGroup.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvWorkGroup.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvWorkGroup.SelectedSubItemIndex = 0;
                cdvWorkGroup.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvWorkGroup.GetListView, '1', CSGC.CP_GCM_WORKER_GROUP) == false)
                {
                    return;
                }

                cdvWorkGroup.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkGroup_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvWorkGroup.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkGroup.Text + "]");
                    cdvWorkGroup.Focus();
                    return;
                }

                ViewWorkerList(); 
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
                if (e.Column == (int)LOT_LIST.LOSS_SELECT)
                {

                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Code", 50, System.Windows.Forms.HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);

                    if (ViewOperLossList(cdvGridButton.GetListView) == false)
                        return;

                    cdvGridButton.ShowPopupList(e.Row, e.Column);
                    //cdvGridButton.InsertEmptyRow(0, 1);                    
                    cdvGridButton.AddEmptyRow(1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_EditModeOff(object sender, EventArgs e)
        {
            int iRow = 0;
            int iCol = 0;
            FarPoint.Win.Spread.CellType.CheckBoxCellType checkBox = new FarPoint.Win.Spread.CellType.CheckBoxCellType();

            try
            {
                iRow = spdLotList.ActiveSheet.ActiveRowIndex;
                iCol = spdLotList.ActiveSheet.ActiveColumnIndex;

                if (iCol == (int)LOT_LIST.CELL_WEIGHT)
                {
                    spdLotList.ActiveSheet.SetActiveCell(iRow, (int)LOT_LIST.CELL_HEIGHT);

                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_LIST.CHK, true);

                }
                else if (iCol == (int)LOT_LIST.CELL_HEIGHT)
                {
                    for (int i = iRow; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        if (i == iRow)
                            continue;

                        if (spdLotList_Sheet1.GetCellType(i, (int)LOT_LIST.CHK).GetType().Name== checkBox.GetType().Name)
                        {
                            spdLotList.ActiveSheet.SetActiveCell(i, (int)LOT_LIST.CELL_WEIGHT);

                            for (int k = 0; k < spdLotList.ActiveSheet.RowCount; k++)
                            {
                                spdLotList.ActiveSheet.Rows[k].BackColor = Color.FromArgb(255, 255, 255);
                            }

                            spdLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 192, 255);

                            spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_LIST.CHK, true);

                            break;
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (spdLotList.ActiveSheet.ActiveColumnIndex == (int)LOT_LIST.LOSS_SELECT)
                {
                    spdLotList.ActiveSheet.SetValue(e.Row, (int)LOT_LIST.LOSS_CODE, e.SelectedItem.SubItems[0].Text);
                    spdLotList.ActiveSheet.SetValue(e.Row, (int)LOT_LIST.LOSS_DESC, e.SelectedItem.SubItems[1].Text);
                }               
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnWorker_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvWorkGroup.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkGroup.Text + "]");
                    cdvWorkGroup.Focus();
                    return;
                }

                frmTranWorkerRegistration popup = new frmTranWorkerRegistration();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                popup.sSub_area_id = cdvWorkPlace.Text;
                popup.sSub_area_desc = cdvWorkPlace.DisplayText;
                popup.sOper = cdvOper.Text;
                popup.sOper_desc = cdvOper.DisplayText;
                popup.sGroup_id = cdvWorkGroup.Text;
                popup.sGroup_desc = cdvWorkGroup.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    popup = null;
                    ViewWorkerList();
                }
                else
                {
                    ViewWorkerList();
                    return;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnInputMat_Click(object sender, EventArgs e)
        {
            try
            {
                frmTranMaterialInputByLevel popup = new frmTranMaterialInputByLevel();

                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                popup.sSub_area_id = cdvWorkPlace.Text;
                popup.sSub_area_desc = cdvWorkPlace.DisplayText;
                popup.sOper_id = cdvOper.Text;
                popup.sOper_desc = cdvOper.DisplayText;
                //popup.sRes_id = cdvResource.Text;
                //popup.sRes_desc = cdvResource.DisplayText;
                popup.sOrder_id = cdvOrder.Text;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    popup = null;
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtGroupID_KeyPress(object sender, KeyPressEventArgs e)
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

        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                {
                    if (e.Column == (int)LOT_LIST.CHK)
                    {
                        //CSCF.CheckSpreadCell(spdLotList, 0, 0, true, true);

                        if (spdLotList.ActiveSheet.ColumnHeader.Cells[0, (int)LOT_LIST.CHK].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                        {
                            if (spdLotList.ActiveSheet.ColumnHeader.Cells[0, (int)LOT_LIST.CHK].Value == null ||
                                spdLotList.ActiveSheet.ColumnHeader.Cells[0, (int)LOT_LIST.CHK].Value.Equals(" ") ||
                                spdLotList.ActiveSheet.ColumnHeader.Cells[0, (int)LOT_LIST.CHK].Value.Equals(false))
                            {
                                spdLotList.ActiveSheet.ColumnHeader.Cells[0, (int)LOT_LIST.CHK].Value = true;
                            }
                            else
                            {
                                spdLotList.ActiveSheet.ColumnHeader.Cells[0, (int)LOT_LIST.CHK].Value = false;
                            }

                            for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                            {
                                if (spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                                {
                                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].Value = spdLotList.ActiveSheet.ColumnHeader.Cells[0, (int)LOT_LIST.CHK].Value;                                   
                                }
                            }
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        spdLotList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                    }

                    spdLotList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                    txtCellWeight.Text = spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_LIST.CELL_WEIGHT].Text;
                    txtCellHeight.Text = spdLotList.ActiveSheet.Cells[e.Row, (int)LOT_LIST.CELL_HEIGHT].Text;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtCellWeight_KeyPress(object sender, KeyPressEventArgs e)
        {
            string sGroup = "";

            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (MPCF.ToDbl(txtCellWeight.Text) == 0 || txtCellWeight.Text == "" || spdLotList.ActiveSheet.ActiveRowIndex < 0)
                    {
                        return;
                    }

                    sGroup = spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_LIST.GROUP_ID].Text;

                    for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.GROUP_ID].Text == sGroup)
                        {
                            spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CELL_WEIGHT].Value = MPCF.ToDbl(txtCellWeight.Text);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtCellHeight_KeyPress(object sender, KeyPressEventArgs e)
        {
            string sGroup = "";

            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (MPCF.ToDbl(txtCellHeight.Text) == 0 || txtCellHeight.Text == "" || spdLotList.ActiveSheet.ActiveRowIndex < 0)
                    {
                        return;
                    }

                    sGroup = spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_LIST.GROUP_ID].Text;

                    for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.GROUP_ID].Text == sGroup)
                        {
                            spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CELL_HEIGHT].Value = MPCF.ToDbl(txtCellHeight.Text);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //맵핑되는 카운드가 변경되는 경우가 있어 옵션 추가. 
        //체크박스 체크 후 mapping 수량 변경하면 재조회 되면서 맵핑 수량이 바뀐다. 
        private void chkAditMappingCount_CheckedChanged(object sender, EventArgs e)
        {
            try
            {
                if (chkAditMappingCount.Checked == true)
                {
                    txtMappingCount.Enabled = true;
                    btnApply.Enabled = true;
                }
                else
                {
                    txtMappingCount.Enabled = false;
                    btnApply.Enabled = false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtMappingCount_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {

                if (e.KeyChar == (char)13)
                {
                    btnApply_Click(null, null);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnApply_Click(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(txtMappingCount.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + chkAditMappingCount.Text + "]");
                    txtMappingCount.Focus();
                    return;
                }

                if (txtMappingCount.Enabled == true)
                {
                    iMappingCount = MPCF.ToInt(txtMappingCount.Text);

                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnUp_Click(object sender, EventArgs e)
        {
            try
            {
                LotPositionControl("UP");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDown_Click(object sender, EventArgs e)
        {
            try
            {
                LotPositionControl("DOWN");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //조회번튼
        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                pnlInputMappingCount.Visible = false;

                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;


                if (cdvWorkType.Text == CSGC.CP_WORK_TYPE_WAIT)
                {
                    if(sAutoSearch == "Y") 
                    {
                        sAutoSearch = "N";
                        ViewLotList();
                        cdvWorkType.Text = CSGC.CP_WORK_TYPE_PROC;
                    }
                    else {
                        InputMappingCount();
                    }
                }
                else
                {              
                    ViewLotList();
      
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //시작버튼
        private void btnStart_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.START) == false)
                    return;

                if (SaveProcess('3'))
                {
                    sAutoSearch = "Y";
                    btnView.PerformClick();
                    ClearData();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //완료 버튼
        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.END) == false)
                    return;

                if (SaveProcess('4'))
                {
                    btnView.PerformClick();
                    ClearData();
                }
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

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtInputMappingCount_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {

                if (!(char.IsDigit(e.KeyChar) || e.KeyChar == Convert.ToChar(Keys.Back)))
                {
                    e.Handled = true;

                }

                if (e.KeyChar == (char)13)
                {

                    SearchMappingLotId();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void btnInputMappingCount_Click(object sender, EventArgs e)
        {
            SearchMappingLotId();
        }



        private void lblX_Click(object sender, EventArgs e)
        {
            pnlInputMappingCount.Visible = false;
        }

        private void btnGCM_Click(object sender, EventArgs e)
        {
            try
            {
                frmPopGcmData popup = new frmPopGcmData();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sTable_name = "TEST_ITEM_ISSUE2";

                if (MPGV.gcLanguage == '2')
                {
                    popup.sTable_name_desc = "품목별 TEST및RND 자재기타입출고 계정";
                    popup.sComment = "해당화면에서 등록된 품목은 생산진행시 자재소요에대해서 등록된 기타출고 계정으로 출고됩니다.";

                }
                else
                {
                    popup.sTable_name_desc = "Test / Rnd Etc Account";
                    popup.sComment = "Items registered will be Inputed to ETC In/Out accounts registered for material requirements during production.";

                }

                if (popup.ShowDialog() == DialogResult.OK)
                {

                    popup = null;
                }
                else
                    return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion


    }
}
