using System;
using System.Collections.Generic;
using System.Collections;
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
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using Miracom.CliFrx;
using Miracom.DNMCore;


namespace CUS_WIP
{
    public partial class frmTranTestSongK : Miracom.MESCore.TranForm02
    {
        public frmTranTestSongK()
        {
            InitializeComponent();
        }

        private string BonusTable = "";
        private string LossTable = "";


        #region "이벤트"
        private void SpdTotalList_KeyUp(object sender, KeyEventArgs e)
        {
            if (spdTotalList_Sheet1.RowCount != 0)
            {
                View_Lot();
            }
        }
        private void SpdTotalList_MouseUp(object sender, MouseEventArgs e)
        {
            if (spdTotalList_Sheet1.RowCount != 0)
            {
                View_Lot();
            }
        }


        private void cbvMaterial_ButtonPress(object sender, EventArgs e)
        {
            try
            {

                View_cbvMtl();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }


        private void cbvFlow_ButtonPress(object sender, EventArgs e)
        {
            try
            {
           
                View_cbvFlow();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void cdvOperation_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                View_cdvOperation();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        private void cbvHold_ButtonPress(object sender, EventArgs e)
        {
            View_Hold();
        }

        private void cbvBonusCode_ButtonPress(object sender, EventArgs e)
        {
            View_cbvBonusCode();
        }

        private void cbvLoss_ButtonPress(object sender, EventArgs e)
        {
            View_Loss();
        }


        private void btnView_Click(object sender, EventArgs e)
        {
            View_TotalList();
            if (spdTotalList_Sheet1.RowCount != 0)
            {
                View_Lot();
            }
        }

        private void btnSkip_Click(object sender, EventArgs e)
        {
            Skip_Lot('8');
            View_Lot();
        }
        private void btnLoss_Click(object sender, EventArgs e)
        {
            Loss_Lot('7');
            View_Lot();
        }
        private void btnBouus_Click(object sender, EventArgs e)
        {
            Bounce_Lot('6');
            View_Lot();
        }
        private void btnHold_Click(object sender, EventArgs e)
        {
            Hold_Lot('5');
            View_Lot();
        }

        private void btnApt_Click(object sender, EventArgs e)
        {
            Adp_Lot('4');
            View_Lot();
        }
        private void btnEnd_Click(object sender, EventArgs e)
        {
             End_Lot('3');
            View_Lot();
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
             Start_Lot('2');
            View_Lot();
        }

        private void btnCreate_Click(object sender, EventArgs e)
        {
            Create_Lot('1');
            View_Lot();
        }
        #endregion


        #region "조회"
        private void View_cbvMtl()
        {
            try
            {
                cbvMaterial.Init();
                MPCF.InitListView(cbvMaterial.GetListView);  //MPCF
                cbvMaterial.SelectedSubItemIndex = 0; //
                if (WIPLIST.ViewMaterialList(cbvMaterial.GetListView, '2', "", ' ', ' ', "", true, null, "") == false)
                {
                    return;
                }
                //WIPLIST.ViewFlowList(cbvFlow.GetListView, ListCond_Step, ListCond_MatID, ListCond_MatVersion, ListCond_Filter, null, ListCond_ExtFactory);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }





        private void View_cbvFlow()
        {
            try
            {
                string sMat = cbvMaterial.Text;
                cbvFlow.Init();
                MPCF.InitListView(cbvFlow.GetListView);  //MPCF
                cbvFlow.SelectedSubItemIndex = 0; 
                if (WIPLIST.ViewFlowList(cbvFlow.GetListView, '2', sMat, 1, "", null, "") == false)
                {
                    return;
                }
                //WIPLIST.ViewFlowList(cbvFlow.GetListView, ListCond_Step, ListCond_MatID, ListCond_MatVersion, ListCond_Filter, null, ListCond_ExtFactory);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }
        private void View_cdvOperation()
        {
            string sFlow = cbvFlow.Text;
            try
            {
                if(sFlow == null)
                {
                    return;
                }


                /*아래 기본 형식*/
                cdvOperation.Init();
                MPCF.InitListView(cdvOperation.GetListView);  //MPCF
                cdvOperation.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOperation.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOperation.SelectedSubItemIndex = 0; //

                if (WIPLIST.ViewOperationList(cdvOperation.GetListView, '2', "", 0, sFlow, "", null, "") == false) //WIPLIST플로우 조회
                {
                    return;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void View_Hold()
        {

            cbvHold.Init();
            MPCF.InitListView(cbvHold.GetListView);
           // cbvHold.Columns.Add("Initial ID", 50, HorizontalAlignment.Left);
           // cbvHold.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cbvHold.SelectedSubItemIndex = 0;
           // MPGC.MP_WIP_HOLD_CODE
            if (BASLIST.ViewGCMDataList(cbvHold.GetListView, '1', MPGC.MP_WIP_HOLD_CODE) == false)
            {
                
                return;
            }
        }

        private void View_cbvBonusCode()
        {
            /*
            if (spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 3].Value == "")
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [Operation]");
                return;
            }
            */

            //공정정보 가져오기
            TRSNode in_node = new TRSNode("VIEW_OPERATION_IN");
            TRSNode out_node = new TRSNode("VIEW_OPERATION_OUT");

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';
            in_node.AddString("OPER", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 3].Value);

            if (MPCR.CallService("WIP", "WIP_View_Operation", in_node, ref out_node) == false)
            {
                return;
            }

            BonusTable = out_node.GetString("BONUS_TBL");
            if (BonusTable == "")
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(248));
                return;
            }

            //clear the bonus code list first

            cbvBonusCode.Init();
            cbvBonusCode.Text = "";


            cbvBonusCode.Columns.Add("Code", 50, HorizontalAlignment.Left);
            cbvBonusCode.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cbvBonusCode.SelectedSubItemIndex = 0;

            BASLIST.ViewGCMDataList(cbvBonusCode.GetListView, '1', BonusTable);
        }


        private void View_Loss()
        {


            //공정정보 가져오기
            TRSNode in_node = new TRSNode("VIEW_LOSS_IN");
            TRSNode out_node = new TRSNode("VIEW_LOSS_OUT");

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';
            in_node.AddString("OPER", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 3].Value);

            if (MPCR.CallService("WIP", "WIP_View_Operation", in_node, ref out_node) == false)
            {
                return;
            }

            LossTable = out_node.GetString("LOSS_TBL");
            if (LossTable == "")
            {
                MPCF.ShowMsgBox(MPCF.GetMessage(248));
                return;
            }


            //clear the bonus code list first

            cbvLoss.Init();
            cbvLoss.Text = "";


            cbvLoss.Columns.Add("Code", 50, HorizontalAlignment.Left);
            cbvLoss.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cbvLoss.SelectedSubItemIndex = 0;

            BASLIST.ViewGCMDataList(cbvLoss.GetListView, '1', LossTable);
        }

        private void View_TotalList()
        {
            string sView_Id = "";

            try
            {

                //TPDR.GetDataOne 다이렉트 쿼리
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "TEST_004"; //쿼리번호(뷰아이디)

                dvcArgu[0].sCondition_ID = "FACTORY"; //조건코드
                dvcArgu[0].sCondition_Value = MPGV.gsFactory; //값



                dvcArgu[1].sCondition_ID = "MAT_ID"; //조건코드

                if (cbvMaterial.Text != "")
                {
                    dvcArgu[1].sCondition_Value = cbvMaterial.Text; //값
                }
                else
                {
                    dvcArgu[1].sCondition_Value = ""; //값
                }


                dvcArgu[2].sCondition_ID = "FLOW"; //조건코드

                if (cbvFlow.Text != "")
                {
                    dvcArgu[2].sCondition_Value = cbvFlow.Text; //값
                }
                else
                {
                    dvcArgu[2].sCondition_Value = ""; //값
                }



                dvcArgu[3].sCondition_ID = "OPER"; //조건코드

                if(cdvOperation.Text != "")
                {
                    dvcArgu[3].sCondition_Value = cdvOperation.Text; //값
                }
                else
                {
                    dvcArgu[3].sCondition_Value = ""; //값
                }


                MPCF.ClearList(SpdTotalList);
                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }



                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdTotalList_Sheet1.RowCount++;


                    spdTotalList_Sheet1.Cells[i, 0].Value = (i + 1).ToString();
                    spdTotalList_Sheet1.Cells[i, 1].Value = dt.Rows[i]["MAT_ID"].ToString();
                    spdTotalList_Sheet1.Cells[i, 2].Value = dt.Rows[i]["FLOW"].ToString();
                    spdTotalList_Sheet1.Cells[i, 3].Value = dt.Rows[i]["OPER"].ToString();
                    spdTotalList_Sheet1.Cells[i, 4].Value = dt.Rows[i]["LOT_COUNT"].ToString();
                    spdTotalList_Sheet1.Cells[i, 5].Value = dt.Rows[i]["SUM_QTY"].ToString();
                }

                MPCF.FitColumnHeader(SpdTotalList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }





        private void View_Lot()
        {
            string sView_Id = "";

            try
            {

                //TPDR.GetDataOne 다이렉트 쿼리
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "TEST_002"; //쿼리번호(뷰아이디)

                dvcArgu[0].sCondition_ID = "FACTORY"; //조건코드
                dvcArgu[0].sCondition_Value = MPGV.gsFactory; //값

                //spdTotalList_Sheet1.ActiveRowIndex;
                //           iColumn = spdData.ActiveSheet.ActiveColumnIndex;
                //  iRow = spdData.ActiveSheet.ActiveRowIndex;

                dvcArgu[1].sCondition_ID = "OPER"; //조건코드
                //dvcArgu[1].sCondition_Value = cdvOperation.Text; //값
                dvcArgu[1].sCondition_Value = spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 3].Value; //값

                MPCF.ClearList(spdLotInfo);
                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }



                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotInfo_Sheet1.RowCount++;


                    spdLotInfo_Sheet1.Cells[i, 0].Value = (i + 1).ToString();
                    spdLotInfo_Sheet1.Cells[i, 1].Value = dt.Rows[i]["LOT_ID"].ToString();
                    spdLotInfo_Sheet1.Cells[i, 2].Value = dt.Rows[i]["LOT_STATUS"].ToString();
                    spdLotInfo_Sheet1.Cells[i, 3].Value = dt.Rows[i]["QTY_1"].ToString();
                }

                MPCF.FitColumnHeader(spdLotInfo);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion


        #region "기타"
        private bool Create_Lot(char c_ProcStep)
        {
            //int i;
 

            TRSNode in_node = new TRSNode("Create_Lot_In");
            TRSNode out_node = new TRSNode("Create_Lot_Out");

            MPCR.SetInMsg(in_node);  //생성 1번 진행 2번 완료 3번
            in_node.ProcStep = c_ProcStep;
            //in_node.AddString("CREATE_COUNT", Int32.Parse(textBox1.Text));
            in_node.AddInt("CREATE_COUNT", textBox1.Text);

            in_node.AddString("OPER", cdvOperation.Text); //T901
            in_node.AddString("FLOW", cbvFlow.Text); //F002
            in_node.AddString("MAT_ID", cbvMaterial.Text); //TDIA002
          //  in_node.AddString("OPER", cdvOperation.Text); //T901
          //  in_node.AddString("FLOW", "F002"); //F002
          //  in_node.AddString("MAT_ID", txtMatid.Text); //TDIA002

            try
            {
                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Test_Songk", in_node, ref out_node) == false)
                {
                    return false;
                }

                //btnView_Click(null,null);


                /*
                MPCF.ClearList(spdLotInfo);
                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    spdLotInfo_Sheet1.Cells[i, 0].Value = out_node.GetList(0)[i].GetString("LOT_ID"); //순번
                    spdLotInfo_Sheet1.Cells[i, 1].Value = out_node.GetList(0)[i].GetString("OPER"); //LOT
                    spdLotInfo_Sheet1.Cells[i, 2].Value = out_node.GetList(0)[i].GetString("LOT_STATUS "); //상태
                }
                MPCF.FitColumnHeader(spdLotInfo);
                */
                /*
                for (i = 0; i < Int32.Parse(textBox1.Text); i++)
                {   // CUS_WIP_CREATE_LOT CUS_WIP_TEST_PROCESS
                    if (MPCR.CallService("CUS_WIP", "CUS_WIP_CREATE_LOT", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                }
                */

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool Start_Lot(char c_ProcStep)
        {
            int i;


            TRSNode in_node = new TRSNode("Start_Lot_In");
            TRSNode out_node = new TRSNode("Start_Lot_Out");
            TRSNode list_lot;

            MPCR.SetInMsg(in_node);  //생성 1번 진행 2번 완료 3번
            in_node.ProcStep = c_ProcStep;
            //in_node.AddString("CREATE_COUNT", Int32.Parse(textBox1.Text));
            //in_node.AddInt("LOT_LIST", textBox1.Text);


            in_node.AddString("OPER", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 3].Value); //T901
            in_node.AddString("FLOW", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 2].Value); //F002
            in_node.AddString("MAT_ID", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 1].Value); //TDIA002


            for (i = 0; i < spdLotInfo_Sheet1.RowCount; i++)
            {
                if (spdLotInfo_Sheet1.IsSelected(i, 1) == true)
                {
                    list_lot = in_node.AddNode("LOT_LIST");
                    list_lot.AddString("LOT_ID", spdLotInfo_Sheet1.Cells[i, 1].Value);
                }
            }

            try
            {
                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Test_Songk", in_node, ref out_node) == false)
                {
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
        private bool End_Lot(char c_ProcStep)
        {
            int i;


            TRSNode in_node = new TRSNode("End_Lot_In");
            TRSNode out_node = new TRSNode("End_Lot_Out");
            TRSNode list_lot;

            MPCR.SetInMsg(in_node);  //생성 1번 진행 2번 완료 3번
            in_node.ProcStep = c_ProcStep;
            //in_node.AddString("CREATE_COUNT", Int32.Parse(textBox1.Text));
            //in_node.AddInt("LOT_LIST", textBox1.Text);


            in_node.AddString("OPER", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 3].Value); //T901
            in_node.AddString("FLOW", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 2].Value); //F002
            in_node.AddString("MAT_ID", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 1].Value); //TDIA002

            in_node.AddString("LOT_CMF_1", txtCmf1.Text);
            in_node.AddString("LOT_CMF_2", txtCmf2.Text);
            in_node.AddString("LOT_CMF_3", txtCmf3.Text);
            in_node.AddString("LOT_CMF_4", txtCmf4.Text);
            in_node.AddString("LOT_CMF_5", txtCmf5.Text);



            for (i = 0; i < spdLotInfo_Sheet1.RowCount; i++)
            {
                if(spdLotInfo_Sheet1.IsSelected(i, 1) == true)
                { 
                    list_lot = in_node.AddNode("LOT_LIST");
                    list_lot.AddString("LOT_ID", spdLotInfo_Sheet1.Cells[i, 1].Value);
                }
            }

            try
            {
                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Test_Songk", in_node, ref out_node) == false)
                {
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

        private bool Adp_Lot(char c_ProcStep)
        {
            int i;


            TRSNode in_node = new TRSNode("Adp_Lot_In");
            TRSNode out_node = new TRSNode("Adp_Lot_Out");
            TRSNode list_lot;

            MPCR.SetInMsg(in_node);  //생성 1번 진행 2번 완료 3번
            in_node.ProcStep = c_ProcStep;
            //in_node.AddString("CREATE_COUNT", Int32.Parse(textBox1.Text));
            //in_node.AddInt("LOT_LIST", textBox1.Text);


          //  in_node.AddString("OPER", cdvOperation.Text); //T901
          //  in_node.AddString("FLOW", "F002"); //F002
          //  in_node.AddString("MAT_ID", txtMatid.Text); //TDIA002

            in_node.AddString("LOT_CMF_1", txtCmf1.Text);
            in_node.AddString("LOT_CMF_2", txtCmf2.Text);
            in_node.AddString("LOT_CMF_3", txtCmf3.Text);
            in_node.AddString("LOT_CMF_4", txtCmf4.Text);
            in_node.AddString("LOT_CMF_5", txtCmf5.Text);

            



            for (i = 0; i < spdLotInfo_Sheet1.RowCount; i++)
            {
                if (spdLotInfo_Sheet1.IsSelected(i, 1) == true)
                {
                    list_lot = in_node.AddNode("LOT_LIST");
                    list_lot.AddString("LOT_ID", spdLotInfo_Sheet1.Cells[i, 1].Value);
                }
            }

            try
            {
                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Test_Songk", in_node, ref out_node) == false)
                {
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


        private bool Hold_Lot(char c_ProcStep)
        {
            int i;


            TRSNode in_node = new TRSNode("Hold_Lot_In");
            TRSNode out_node = new TRSNode("Hold_Lot_Out");
            TRSNode list_lot;

            MPCR.SetInMsg(in_node);  //생성 1번 진행 2번 완료 3번
            in_node.ProcStep = c_ProcStep;
            //in_node.AddString("CREATE_COUNT", Int32.Parse(textBox1.Text));
            //in_node.AddInt("LOT_LIST", textBox1.Text);



            in_node.AddString("OPER", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 3].Value); //T901
            in_node.AddString("FLOW", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 2].Value); //F002
            in_node.AddString("MAT_ID", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 1].Value); //TDIA002
            in_node.AddString("HOLD_CODE", cbvHold.Text); //Hold



            for (i = 0; i < spdLotInfo_Sheet1.RowCount; i++)
            {
                if (spdLotInfo_Sheet1.IsSelected(i, 1) == true)
                {
                    list_lot = in_node.AddNode("LOT_LIST");
                    list_lot.AddString("LOT_ID", spdLotInfo_Sheet1.Cells[i, 1].Value);
                }
            }

            try
            {
                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Test_Songk", in_node, ref out_node) == false)
                {
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

        private bool Bounce_Lot(char c_ProcStep)
        {
            TRSNode in_node = new TRSNode("Bounce_Lot_In");
            TRSNode out_node = new TRSNode("Bounce_Lot_Out");
            //TRSNode list_bonus;

            MPCR.SetInMsg(in_node);  //생성 1번 진행 2번 완료 3번
            in_node.ProcStep = c_ProcStep;
            //in_node.AddString("CREATE_COUNT", Int32.Parse(textBox1.Text));
            //in_node.AddInt("LOT_LIST", textBox1.Text);


            //필수값
            // in_node.AddString("BACK_TIME", " ");
            in_node.AddString("LOT_ID", spdLotInfo_Sheet1.Cells[spdLotInfo_Sheet1.ActiveRowIndex, 1].Value);
            in_node.AddString("OPER", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 3].Value);
            in_node.AddString("RES_ID", " ");
            //in_node.AddDouble("OUT_QTY_1", Convert.ToDouble(spdLotInfo_Sheet1.Cells[spdLotInfo_Sheet1.ActiveRowIndex, 3].Value));
            in_node.AddDouble("OUT_QTY_1", Convert.ToDouble(txtBonus.Text));
            in_node.AddDouble("OUT_QTY_2", 0);
            in_node.AddDouble("OUT_QTY_3", 0);
            in_node.AddString("CAUSE_FLOW", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 2].Value);
            in_node.AddString("CAUSE_OPER", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 3].Value);
            in_node.AddString("CAUSE_RES_ID", " ");

            //일단 보너스list로 안하고 한개만 넣어봄 ..원래는 리스트로 하는게 맞는듯
            //   list_bonus = in_node.AddNode("UNIT");
            //   list_bonus.AddString("BONUS_CODE", cbvBonusCode.Text);
            //   list_bonus.AddDouble("BONUS_QTY", Convert.ToDouble(txtBonus.Text));

            in_node.AddString("BONUS_CODE", cbvBonusCode.Text);
            in_node.AddDouble("BONUS_QTY", Convert.ToDouble(txtBonus.Text) - Convert.ToDouble(spdLotInfo_Sheet1.Cells[spdLotInfo_Sheet1.ActiveRowIndex, 3].Value));
            in_node.AddString("LOSS_COMMENT", "TEST입니다.");



            try
            {
                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Test_Songk", in_node, ref out_node) == false)
                {
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
        private bool Loss_Lot(char c_ProcStep)
        {
            TRSNode in_node = new TRSNode("Loss_Lot_In");
            TRSNode out_node = new TRSNode("Loss_Lot_Out");
            //TRSNode list_Loss;

            MPCR.SetInMsg(in_node);  //생성 1번 진행 2번 완료 3번
            in_node.ProcStep = c_ProcStep;
            //in_node.AddString("CREATE_COUNT", Int32.Parse(textBox1.Text));
            //in_node.AddInt("LOT_LIST", textBox1.Text);


            //필수값
            // in_node.AddString("BACK_TIME", " ");
            in_node.AddString("LOT_ID", spdLotInfo_Sheet1.Cells[spdLotInfo_Sheet1.ActiveRowIndex, 1].Value);
            in_node.AddString("OPER", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 3].Value);
            in_node.AddString("RES_ID", " ");
            //in_node.AddDouble("OUT_QTY_1", Convert.ToDouble(spdLotInfo_Sheet1.Cells[spdLotInfo_Sheet1.ActiveRowIndex, 3].Value));
            in_node.AddDouble("OUT_QTY_1", Convert.ToDouble(spdLotInfo_Sheet1.Cells[spdLotInfo_Sheet1.ActiveRowIndex, 3].Value) - Convert.ToDouble(txtLoss.Text));
            in_node.AddDouble("OUT_QTY_2", 0);
            in_node.AddDouble("OUT_QTY_3", 0);
            in_node.AddString("CAUSE_FLOW", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 2].Value);
            in_node.AddString("CAUSE_OPER", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 3].Value);
            in_node.AddString("CAUSE_RES_ID", " ");

            //일단 보너스list로 안하고 한개만 넣어봄 ..원래는 리스트로 하는게 맞는듯
            //   list_bonus = in_node.AddNode("UNIT");
            //   list_bonus.AddString("BONUS_CODE", cbvBonusCode.Text);
            //   list_bonus.AddDouble("BONUS_QTY", Convert.ToDouble(txtBonus.Text));

            in_node.AddString("LOSS_CODE", cbvLoss.Text);
            in_node.AddDouble("LOSS_QTY", Convert.ToDouble(txtLoss.Text));
            in_node.AddString("LOSS_COMMENT", "TEST입니다.");



            try
            {
                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Test_Songk", in_node, ref out_node) == false)
                {
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


        private bool Skip_Lot(char c_ProcStep)
        {
            TRSNode in_node = new TRSNode("Skip_Lot_In");
            TRSNode out_node = new TRSNode("Skip_Lot_Out");

            MPCR.SetInMsg(in_node);  //생성 1번 진행 2번 완료 3번
            in_node.ProcStep = c_ProcStep;
            //in_node.AddString("CREATE_COUNT", Int32.Parse(textBox1.Text));
            //in_node.AddInt("LOT_LIST", textBox1.Text);


            //필수값
            // in_node.AddString("BACK_TIME", " ");
            in_node.AddString("LOT_ID", spdLotInfo_Sheet1.Cells[spdLotInfo_Sheet1.ActiveRowIndex, 1].Value);
            in_node.AddString("TO_OPER", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 3].Value);
            in_node.AddString("TO_FLOW", spdTotalList_Sheet1.Cells[spdTotalList_Sheet1.ActiveRowIndex, 2].Value);



            try
            {
                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Test_Songk", in_node, ref out_node) == false)
                {
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

        #endregion


    }
}
