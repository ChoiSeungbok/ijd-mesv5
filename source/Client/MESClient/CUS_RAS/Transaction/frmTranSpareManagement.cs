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

using System.Diagnostics;
using System.IO;



namespace CUS_RAS
{
    public partial class frmTranSpareManagement : CUS_COM.frmViewForm01
    {
        string gBeforeVal = "";
        #region ""
        public frmTranSpareManagement()
        {
            InitializeComponent();

            InitControl();


            // CELL정보 GCM으로 바꿀거임
            /*
            FarPoint.Win.Spread.CellType.ComboBoxCellType comboBoxCellType1 = new FarPoint.Win.Spread.CellType.ComboBoxCellType();
            FarPoint.Win.Spread.CellType.ComboBoxCellType comboBoxCellType2 = new FarPoint.Win.Spread.CellType.ComboBoxCellType();
            comboBoxCellType1.Items = new string[] { "M", "N", "O" };
            comboBoxCellType2.Items = new string[] { "1", "2", "3" };
            SpdSpareList_Sheet1.Columns.Get((int)SPARE.LOCATION_1).CellType = comboBoxCellType1;
            SpdSpareList_Sheet1.Columns.Get((int)SPARE.LOCATION_2).CellType = comboBoxCellType2;
            SpdSpareList_Sheet1.Columns.Get((int)SPARE.LOCATION_3).CellType = comboBoxCellType2;
            */


        }
        #endregion

        #region " Constant Definition "

        private enum SPARE
        {
            CHK,                    // 1 : 선택 
            SPARE_ID,               // 2 : 스페어 ID 
            LOCATION_1,             // 3 : 적재위치
            LOCATION_1_SELECT,      // 4 : 적재위치  
            LOCATION_2,             // 5 : 열 
            LOCATION_2_SELECT,      // 6 : 적재위치
            LOCATION_3,             // 7 : 행 
            LOCATION_3_SELECT,      // 8 : 적재위치
            SPARE_TYPE,             // 9 : 분류  
            SPARE_TYPE_DESC,
            SPARE_TYPE_SELECT,      // 10 : 분류   
            SPARE_MAT_ID,
            SPARE_MAT_ID_DESC,             // 11 : 품명 
            SPARE_MAT_ID_SELECT,      // 12 : 품명
            SPEC,                   // 13: 사용 규격 
            SPEC_DESC,
            SPEC_SELECT,            // 14 : 품명
            MANUFACTURER_ID,           // 15 : 제조사
            MANUFACTURER_ID_DESC,
            MANUFACTURER_SELECT,    // 16 : 제조사 
            RES_ID,                 // 17 : 설비명 
            RES_ID_DESC,
            RES_ID_SELECT,          // 18 : 제조사 
            STOCK_QTY,              // 19 : 재고량 
        }


        #endregion

        #region " Variable Definition "



        #endregion

        #region " Function Definition "

        //조회
        private void InitControl()
        {
            try
            {



                if (BASLIST.ViewGCMDataList(cdvLocation1.GetListView, '1', CSGC.CP_GCM_SPARE_LOCATION_1) == false)
                {
                    return;
                }

                if (BASLIST.ViewGCMDataList(cdvLocation2.GetListView, '1', CSGC.CP_GCM_SPARE_LOCATION_2) == false)
                {
                    return;
                }


                if (BASLIST.ViewGCMDataList(cdvLocation3.GetListView, '1', CSGC.CP_GCM_SPARE_LOCATION_2) == false)
                {
                    return;
                }

                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnUpdate.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnRowAdd.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnRowDelete.Anchor = AnchorStyles.Top | AnchorStyles.Right;


                //MPCF.FitColumnHeader(SpdSpareList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void View_Spare(char c_ProcStep)
        {

            string sView_Id = "";

            try
            {

                //TPDR.GetDataOne 다이렉트 쿼리
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[9];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CRAS_001"; //쿼리번호(뷰아이디)

                dvcArgu[0].sCondition_ID = "FACTORY"; //조건코드
                dvcArgu[0].sCondition_Value = MPGV.gsFactory; //값

                dvcArgu[1].sCondition_ID = "LOCATION_1"; //조건코드
                dvcArgu[1].sCondition_Value = cdvLocation1.Text; //값

                dvcArgu[2].sCondition_ID = "LOCATION_2"; //조건코드
                dvcArgu[2].sCondition_Value = cdvLocation2.Text; //값

                dvcArgu[3].sCondition_ID = "LOCATION_3"; //조건코드
                dvcArgu[3].sCondition_Value = cdvLocation3.Text; //값

                dvcArgu[4].sCondition_ID = "SPARE_TYPE"; //조건코드
                dvcArgu[4].sCondition_Value = cdvSpareType.Text; //값

                dvcArgu[5].sCondition_ID = "SPARE_MAT_ID"; //조건코드
                dvcArgu[5].sCondition_Value = cdvSpareDesc.Text; //값

                dvcArgu[6].sCondition_ID = "SPARE_SPEC_ID"; //조건코드
                dvcArgu[6].sCondition_Value = cdvSpec.Text; //값

                dvcArgu[7].sCondition_ID = "MANUFACTURER_ID"; //조건코드
                dvcArgu[7].sCondition_Value = cdvManudactirerId.Text; //값

                dvcArgu[8].sCondition_ID = "RES_ID"; //조건코드
                dvcArgu[8].sCondition_Value = cdvResId.Text; //값



                MPCF.ClearList(SpdSpareList);
                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }



                for (i = 0; i < dt.Rows.Count; i++)
                {
                    SpdSpareList_Sheet1.RowCount++;

                    /*
                    if (BASLIST.ViewGCMDataList(SpdSpareList, '1', CSGC.CP_GCM_SPARE_LOCATION_1, -1, null, "", false, (int)SPARE.LOCATION_1, i, null) == false)
                    {
                        return;

                    }
                    if (BASLIST.ViewGCMDataList(SpdSpareList, '1', CSGC.CP_GCM_SPARE_LOCATION_2, -1, null, "", false, (int)SPARE.LOCATION_2, i, null) == false)
                    {
                        return;

                    }
                    if (BASLIST.ViewGCMDataList(SpdSpareList, '1', CSGC.CP_GCM_SPARE_LOCATION_2, -1, null, "", false, (int)SPARE.LOCATION_3, i, null) == false)
                    {
                        return;

                    }
                    */
                    //  SpdSpareList_Sheet1.Cells[i, 0].Value = (i + 1).ToString();



                    SpdSpareList_Sheet1.Cells[i, (int)SPARE.SPARE_TYPE_DESC].Text = dt.Rows[i]["SPARE_TYPE_DESC"].ToString();
                    SpdSpareList_Sheet1.Cells[i, (int)SPARE.SPARE_MAT_ID_DESC].Text = dt.Rows[i]["SPARE_MAT_ID_DESC"].ToString();
                    SpdSpareList_Sheet1.Cells[i, (int)SPARE.SPEC_DESC].Text = dt.Rows[i]["SPARE_SPEC_ID_DESC"].ToString();
                    SpdSpareList_Sheet1.Cells[i, (int)SPARE.MANUFACTURER_ID_DESC].Text = dt.Rows[i]["MANUFACTURER_ID_DESC"].ToString();
                    SpdSpareList_Sheet1.Cells[i, (int)SPARE.RES_ID_DESC].Text = dt.Rows[i]["RES_ID"].ToString();

                    SpdSpareList_Sheet1.Cells[i, (int)SPARE.CHK].Value = dt.Rows[i]["CHK"].ToString();
                    SpdSpareList_Sheet1.Cells[i, (int)SPARE.SPARE_ID].Value = dt.Rows[i]["SPARE_ID"].ToString();
                    SpdSpareList_Sheet1.Cells[i, (int)SPARE.LOCATION_1].Value = dt.Rows[i]["LOCATION_1"].ToString();
                    SpdSpareList_Sheet1.Cells[i, (int)SPARE.LOCATION_2].Value = dt.Rows[i]["LOCATION_2"].ToString();
                    SpdSpareList_Sheet1.Cells[i, (int)SPARE.LOCATION_3].Value = dt.Rows[i]["LOCATION_3"].ToString();
                    SpdSpareList_Sheet1.Cells[i, (int)SPARE.SPARE_TYPE].Value = dt.Rows[i]["SPARE_TYPE"].ToString();
                    SpdSpareList_Sheet1.Cells[i, (int)SPARE.SPARE_MAT_ID].Value = dt.Rows[i]["SPARE_MAT_ID"].ToString();
                    SpdSpareList_Sheet1.Cells[i, (int)SPARE.SPEC].Value = dt.Rows[i]["SPARE_SPEC_ID"].ToString();
                    SpdSpareList_Sheet1.Cells[i, (int)SPARE.MANUFACTURER_ID].Value = dt.Rows[i]["MANUFACTURER_ID"].ToString();
                    SpdSpareList_Sheet1.Cells[i, (int)SPARE.RES_ID].Value = dt.Rows[i]["RES_ID"].ToString();
                    SpdSpareList_Sheet1.Cells[i, (int)SPARE.STOCK_QTY].Value = dt.Rows[i]["STOCK_QTY"].ToString();

                    


                }

               // MPCF.FitColumnHeader(SpdSpareList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }




        private void Create_Spare(char c_ProcStep, int i_Row)
        {

            int iRow = i_Row;


            TRSNode in_node = new TRSNode("Create_Spare_In");
            TRSNode out_node = new TRSNode("Create_Spare_Out");

            MPCR.SetInMsg(in_node);  //생성 1번 진행 2번 완료 3번
            in_node.ProcStep = c_ProcStep;
            in_node.AddString("FACTORY", MPGV.gsFactory);
            in_node.AddString("SPARE_ID", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.SPARE_ID].Value);
            in_node.AddString("LOCATION_1", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.LOCATION_1].Value);
            in_node.AddString("LOCATION_2", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.LOCATION_2].Value);
            in_node.AddString("LOCATION_3", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.LOCATION_3].Value);
            in_node.AddString("SPARE_TYPE", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.SPARE_TYPE].Value);
            in_node.AddString("SPARE_MAT_ID", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.SPARE_MAT_ID].Value);
            in_node.AddString("SPARE_SPEC_ID", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.SPEC].Value);
            in_node.AddString("MANUFACTURER_ID", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.MANUFACTURER_ID].Value);
            in_node.AddString("RES_ID", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.RES_ID].Value);
            in_node.AddInt("STOCK_QTY", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.STOCK_QTY].Value);

            try
            {
                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Spare_Management", in_node, ref out_node) == false)
                {
                    return;
                }
                SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.SPARE_ID].Value = out_node.GetString("SPARE_ID");
                SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.CHK].Value = false;
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }



        private void Update_Spare(char c_ProcStep, int i_Row)
        {
            int iRow = i_Row;

            TRSNode in_node = new TRSNode("Update_Spare_In");
            TRSNode out_node = new TRSNode("Update_Spare_Out");

            MPCR.SetInMsg(in_node);  //생성 1번 진행 2번 완료 3번
            in_node.ProcStep = c_ProcStep;

            in_node.AddString("FACTORY", MPGV.gsFactory);
            in_node.AddString("SPARE_ID", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.SPARE_ID].Value);
            in_node.AddString("LOCATION_1", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.LOCATION_1].Value);
            in_node.AddString("LOCATION_2", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.LOCATION_2].Value);
            in_node.AddString("LOCATION_3", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.LOCATION_3].Value);
            in_node.AddString("SPARE_TYPE", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.SPARE_TYPE].Value);
            in_node.AddString("SPARE_MAT_ID", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.SPARE_MAT_ID].Value);
            in_node.AddString("SPARE_SPEC_ID", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.SPEC].Value);
            in_node.AddString("MANUFACTURER_ID", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.MANUFACTURER_ID].Value);
            in_node.AddString("RES_ID", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.RES_ID].Value);
            in_node.AddInt("STOCK_QTY", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.STOCK_QTY].Value);





            try
            {
                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Spare_Management", in_node, ref out_node) == false)
                {
                    return;
                }
                SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.CHK].Value = false;
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void Delete_Spare(char c_ProcStep, int i_Row)
        {

            int iRow = i_Row;


            TRSNode in_node = new TRSNode("Update_Spare_In");
            TRSNode out_node = new TRSNode("Update_Spare_Out");

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = c_ProcStep;

            in_node.AddString("FACTORY", MPGV.gsFactory);
            in_node.AddString("SPARE_ID", SpdSpareList_Sheet1.Cells[iRow, (int)SPARE.SPARE_ID].Value);


            try
            {
                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Spare_Management", in_node, ref out_node) == false)
                {
                    return;
                }

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }



        //벨리데이션 체크
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            int iCount = 0;

            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.SAVE:

                        for (int i = 0; i < SpdSpareList.ActiveSheet.RowCount; i++)
                        {
                            if (Convert.ToBoolean(SpdSpareList_Sheet1.Cells[i, (int)SPARE.CHK].Text) == true)
                            {
                                if (string.IsNullOrEmpty(SpdSpareList.ActiveSheet.Cells[i, (int)SPARE.LOCATION_1].Text) == true)
                                {
                                    MPCF.ShowMsgBox("(" + SpdSpareList_Sheet1.Columns.Get((int)SPARE.LOCATION_1).Label + ") \r\n " + MPCF.GetMessage(108));
                                    return false;
                                }
                                if (string.IsNullOrEmpty(SpdSpareList.ActiveSheet.Cells[i, (int)SPARE.LOCATION_2].Text) == true)
                                {
                                    MPCF.ShowMsgBox("(" + SpdSpareList_Sheet1.Columns.Get((int)SPARE.LOCATION_2).Label + ") \r\n" + MPCF.GetMessage(108));
                                    return false;
                                }
                                if (string.IsNullOrEmpty(SpdSpareList.ActiveSheet.Cells[i, (int)SPARE.LOCATION_3].Text) == true)
                                {
                                    MPCF.ShowMsgBox("(" + SpdSpareList_Sheet1.Columns.Get((int)SPARE.LOCATION_3).Label + ") \r\n" + MPCF.GetMessage(108));
                                    return false;
                                }
                                iCount++;
                            }
                        }

                        if (iCount == 0)
                        {
                            //CMN133 ERROR - 최소한 1개 이상의 아이템을 선택해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(133));
                            return false;
                        }

                        break;
                    case CSGC.CHECK.VIEW:

                        break;
                    case CSGC.CHECK.ADD:
                        break;
                    case CSGC.CHECK.DELETE:
                        if (SpdSpareList_Sheet1.RowCount == 0)
                        {
                            //192 ERROR - 삭제할 데이터가 없습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(192));
                            return false;
                        }
                        if (string.IsNullOrEmpty(SpdSpareList.ActiveSheet.Cells[SpdSpareList.ActiveSheet.ActiveRowIndex, (int)SPARE.SPARE_ID].Text) == false)
                        {

                            //192 ERROR - 삭제할 데이터가 없습니다.(이미저장된거는 삭제 안하고 그냥 패스)
                            // MPCF.ShowMsgBox(MPCF.GetMessage(192));
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
        private void btnView_Click(object sender, EventArgs e)
        {

            if (CheckCondition(CSGC.CHECK.VIEW) == false)
            {
                return;
            }
            View_Spare('1');
        }

        private void btnRowAdd_Click(object sender, EventArgs e)
        {

            if (CheckCondition(CSGC.CHECK.ADD) == false)
            {
                return;
            }

            int sRow;
            if (SpdSpareList.ActiveSheet.ActiveRowIndex == -1)
            {
                sRow = 0;
            }
            else
            {
                sRow = SpdSpareList.ActiveSheet.ActiveRowIndex;
            }
            SpdSpareList.ActiveSheet.AddRows(sRow, 1);

            SpdSpareList_Sheet1.Cells[sRow, (int)SPARE.CHK].Value = true;
            SpdSpareList_Sheet1.Cells[sRow, (int)SPARE.STOCK_QTY].Value = 0;

            /*
            FarPoint.Win.Spread.CellType.ComboBoxCellType comboBoxCellType1 = new FarPoint.Win.Spread.CellType.ComboBoxCellType();
            FarPoint.Win.Spread.CellType.ComboBoxCellType comboBoxCellType2 = new FarPoint.Win.Spread.CellType.ComboBoxCellType();
            comboBoxCellType1.Items = new string[] {"M","N","O"};
            comboBoxCellType2.Items = new string[] { "1", "2", "3" };
           

            //SpdSpareList_Sheet1.RowCount++;
            SpdSpareList.ActiveSheet.AddRows(SpdSpareList.ActiveSheet.ActiveRowIndex, 1);
            SpdSpareList_Sheet1.Cells[SpdSpareList.ActiveSheet.ActiveRowIndex, (int)SPARE.CHK].Value = true;
            SpdSpareList_Sheet1.Columns.Get((int)SPARE.LOCATION_1).CellType = comboBoxCellType1;
            SpdSpareList_Sheet1.Columns.Get((int)SPARE.LOCATION_2).CellType = comboBoxCellType2;
            SpdSpareList_Sheet1.Columns.Get((int)SPARE.LOCATION_3).CellType = comboBoxCellType2;
            */


        }

        private void btnRowDel_Click(object sender, EventArgs e)
        {
            if (CheckCondition(CSGC.CHECK.DELETE) == false)
            {
                return;
            }
            //SpdSpareList_Sheet1.RowCount--;
            SpdSpareList.ActiveSheet.RemoveRows(SpdSpareList.ActiveSheet.ActiveRowIndex, 1);
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                {
                    return;
                }
                int i;
                for (i = 0; i < SpdSpareList_Sheet1.Rows.Count; i++)
                {

                    if (Convert.ToBoolean(SpdSpareList_Sheet1.Cells[i, (int)SPARE.CHK].Text) == true)
                    {
                        if (string.IsNullOrEmpty(SpdSpareList_Sheet1.Cells[i, (int)SPARE.SPARE_ID].Text) == true)
                        {
                            Create_Spare(MPGC.MP_STEP_CREATE, i);
                        }
                        else
                        {

                            Update_Spare(MPGC.MP_STEP_UPDATE, i);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
            //View_Spare('1');

        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            int i;

            //정말삭제하시겠습니까?
            if (MPCF.ShowMsgBox(MPCF.GetMessage(453), MessageBoxButtons.YesNo, 1) == DialogResult.No)
            {
                return;
            }
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                {
                    return;
                }
                for (i = 0; i < SpdSpareList_Sheet1.Rows.Count; i++)
                {
                    if (Convert.ToBoolean(SpdSpareList_Sheet1.Cells[i, (int)SPARE.CHK].Text) == true)
                    {
                        if (string.IsNullOrEmpty(SpdSpareList_Sheet1.Cells[i, (int)SPARE.SPARE_ID].Text) == false)
                        {
                            Delete_Spare(MPGC.MP_STEP_DELETE, i);
                            SpdSpareList.ActiveSheet.RemoveRows(i, 1);
                        }
                        else
                        {
                            //SpdSpareList_Sheet1.RowCount--;
                            SpdSpareList.ActiveSheet.RemoveRows(i, 1);
                        }
                    }

                }
                //View_Spare('1');
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

        }


        private void pnlMID_Paint(object sender, PaintEventArgs e)
        {

        }



        private void cdvLocation1_ButtonPress(object sender, EventArgs e)
        {
            cdvLocation1.Init();
            MPCF.InitListView(cdvLocation1.GetListView);
            cdvLocation1.Columns.Add("CODE", 50, HorizontalAlignment.Left);
            //  cdvLocation1.Columns.Add("DATA", 100, HorizontalAlignment.Left);
            cdvLocation1.SelectedSubItemIndex = 0;
            cdvLocation1.DisplaySubItemIndex = 0;

            if (BASLIST.ViewGCMDataList(cdvLocation1.GetListView, '1', CSGC.CP_GCM_SPARE_LOCATION_1) == false)
            {
                return;
            }
            cdvLocation1.InsertEmptyRow(0, 1);
        }

        private void cdvLocation2_ButtonPress(object sender, EventArgs e)
        {
            cdvLocation2.Init();
            MPCF.InitListView(cdvLocation2.GetListView);
            cdvLocation2.Columns.Add("CODE", 50, HorizontalAlignment.Left);
            //  cdvLocation2.Columns.Add("DATA", 100, HorizontalAlignment.Left);
            cdvLocation2.SelectedSubItemIndex = 0;
            cdvLocation2.DisplaySubItemIndex = 0;

            if (BASLIST.ViewGCMDataList(cdvLocation2.GetListView, '1', CSGC.CP_GCM_SPARE_LOCATION_2) == false)
            {
                return;
            }
            cdvLocation2.InsertEmptyRow(0, 1);

        }

        private void cdvLocation3_ButtonPress(object sender, EventArgs e)
        {
            cdvLocation3.Init();
            MPCF.InitListView(cdvLocation3.GetListView);
            cdvLocation3.Columns.Add("CODE", 50, HorizontalAlignment.Left);
            // cdvLocation3.Columns.Add("DATA", 100, HorizontalAlignment.Left);
            cdvLocation3.SelectedSubItemIndex = 0;
            cdvLocation3.DisplaySubItemIndex = 0;

            if (BASLIST.ViewGCMDataList(cdvLocation3.GetListView, '1', CSGC.CP_GCM_SPARE_LOCATION_2) == false)
            {
                return;
            }
            cdvLocation3.InsertEmptyRow(0, 1);

        }

        private void cdvLocation1_TextBoxKeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar != (char)13) return;
            View_Spare('1');
        }

        private void cdvLocation2_TextBoxKeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar != (char)13) return;
            View_Spare('1');
        }

        private void cdvLocation3_TextBoxKeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar != (char)13) return;
            View_Spare('1');
        }

        private void SpdSpareList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {


                switch (e.Column)
                {


                    case (int)SPARE.LOCATION_1_SELECT:
                        //적재위치
                        cdvGridButton.Init();
                        MPCF.InitListView(cdvGridButton.GetListView);
                        cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                        cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);


                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', CSGC.CP_GCM_SPARE_LOCATION_1) == false)
                        {
                            return;
                        }

                        break;
                    case (int)SPARE.LOCATION_2_SELECT:
                        //행
                        cdvGridButton.Init();
                        MPCF.InitListView(cdvGridButton.GetListView);
                        cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                        cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);

                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', CSGC.CP_GCM_SPARE_LOCATION_2) == false)
                        {
                            return;
                        }
                        break;
                    case (int)SPARE.LOCATION_3_SELECT:

                        //열
                        cdvGridButton.Init();
                        MPCF.InitListView(cdvGridButton.GetListView);
                        cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                        cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);

                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', CSGC.CP_GCM_SPARE_LOCATION_2) == false)
                        {
                            return;
                        }
                        break;

                    case (int)SPARE.SPARE_TYPE_SELECT:
                        // 분류  
                        cdvGridButton.Init();
                        MPCF.InitListView(cdvGridButton.GetListView);
                        cdvGridButton.Columns.Add("SPARE_TYPE", 50, HorizontalAlignment.Left);
                        cdvGridButton.Columns.Add("SPARE_TYPE_DESC", 50, HorizontalAlignment.Left);
                        


                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', CSGC.CP_GCM_SPARE_TYPE) == false)
                        {
                            return;
                        }

                        break;
                    case (int)SPARE.SPARE_MAT_ID_SELECT:
                        // 품명 
                        cdvGridButton.Init();
                        MPCF.InitListView(cdvGridButton.GetListView);
                        cdvGridButton.Columns.Add("SPARE_TYPE", 50, HorizontalAlignment.Left);
                        cdvGridButton.Columns.Add("SPARE_MAT_ID", 50, HorizontalAlignment.Left);
                        cdvGridButton.Columns.Add("SPARE_MAT_DESC", 50, HorizontalAlignment.Left);

                        if (SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.SPARE_MAT_ID].Value == null)
                        {
                            if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', CSGC.CP_GCM_SPARE_MAT_ID) == false)
                            {
                                return;
                            }
                        }
                        else
                        {
                            if (BASLIST.ViewGCMDataList_AREA(cdvGridButton.GetListView, '1', CSGC.CP_GCM_SPARE_MAT_ID, -1, null, "", true, -1, -1, null, SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.SPARE_TYPE].Text) == false)
                            {
                                return;
                            }
                        }
                        break;
                    case (int)SPARE.SPEC_SELECT:
                        // 사용 규격 
                        cdvGridButton.Init();
                        MPCF.InitListView(cdvGridButton.GetListView);
                        cdvGridButton.Columns.Add("SPARE_SPEC_ID", 50, HorizontalAlignment.Left);
                        cdvGridButton.Columns.Add("SPARE_SPEC_DESC", 50, HorizontalAlignment.Left);
                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', CSGC.CP_GCM_SPARE_SPEC_ID) == false)
                        {
                            return;
                        }
                        break;
                    case (int)SPARE.MANUFACTURER_SELECT:
                        // 제조사 
                        cdvGridButton.Init();
                        MPCF.InitListView(cdvGridButton.GetListView);
                        cdvGridButton.Columns.Add("MANUFACTURE_CODE", 50, HorizontalAlignment.Left);
                        cdvGridButton.Columns.Add("MANAUFACTURE_DESC", 50, HorizontalAlignment.Left);
                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', CSGC.CP_GCM_MANUFACTURE_CODE) == false)
                        {
                            return;
                        }
                        break;
                    case (int)SPARE.RES_ID_SELECT:
                        // 설비명 
                        if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', CSGC.CP_GCM_SPARE_LOCATION_2) == false)
                        {
                            return;
                        }
                        break;


                }
                cdvGridButton.ShowPopupList(e.Row, e.Column);
                cdvGridButton.InsertEmptyRow(0, 1);

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
                if (SpdSpareList.ActiveSheet.ActiveColumnIndex == (int)SPARE.LOCATION_1_SELECT)
                {
                    if (SpdSpareList.ActiveSheet.Cells[SpdSpareList.ActiveSheet.ActiveRowIndex, (int)SPARE.LOCATION_1].Text == e.SelectedItem.SubItems[0].Text)
                    {
                        return;
                    }
                    else
                    {
                        SpdSpareList_Sheet1.SetValue(e.Row, (int)SPARE.LOCATION_1, e.SelectedItem.SubItems[0].Text);
                      //  SpdSpareList_Sheet1.SetText(e.Row, (int)SPARE.LOCATION_1, e.SelectedItem.SubItems[1].Text);
                        if (Convert.ToBoolean(SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Text) != true)
                        {
                            SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Value = true;
                        }
                    }

                }
                if (SpdSpareList.ActiveSheet.ActiveColumnIndex == (int)SPARE.LOCATION_2_SELECT)
                {
                    if (SpdSpareList.ActiveSheet.Cells[SpdSpareList.ActiveSheet.ActiveRowIndex, (int)SPARE.LOCATION_2].Text == e.SelectedItem.SubItems[0].Text)
                    {
                        return;
                    }
                    else
                    {
                        SpdSpareList_Sheet1.SetValue(e.Row, (int)SPARE.LOCATION_2, e.SelectedItem.SubItems[0].Text);
                     //   SpdSpareList_Sheet1.SetText(e.Row, (int)SPARE.LOCATION_2, e.SelectedItem.SubItems[1].Text);
                        if (Convert.ToBoolean(SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Text) != true)
                        {
                            SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Value = true;
                        }
                    }
                }
                if (SpdSpareList.ActiveSheet.ActiveColumnIndex == (int)SPARE.LOCATION_3_SELECT)
                {
                    if (SpdSpareList.ActiveSheet.Cells[SpdSpareList.ActiveSheet.ActiveRowIndex, (int)SPARE.LOCATION_3].Text == e.SelectedItem.SubItems[0].Text)
                    {
                        return;
                    }
                    else
                    {
                        SpdSpareList_Sheet1.SetValue(e.Row, (int)SPARE.LOCATION_3, e.SelectedItem.SubItems[0].Text);
                     //   SpdSpareList_Sheet1.SetText(e.Row, (int)SPARE.LOCATION_3, e.SelectedItem.SubItems[1].Text);
                        if (Convert.ToBoolean(SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Text) != true)
                        {
                            SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Value = true;
                        }
                    }
                }


                if (SpdSpareList.ActiveSheet.ActiveColumnIndex == (int)SPARE.SPARE_TYPE_SELECT)
                {
                    if (SpdSpareList.ActiveSheet.Cells[SpdSpareList.ActiveSheet.ActiveRowIndex, (int)SPARE.SPARE_TYPE].Text == e.SelectedItem.SubItems[0].Text)
                    {
                        return;
                    }
                    else
                    {
                        SpdSpareList_Sheet1.SetValue(e.Row, (int)SPARE.SPARE_TYPE, e.SelectedItem.SubItems[0].Text);
                        SpdSpareList_Sheet1.SetValue(e.Row, (int)SPARE.SPARE_TYPE_DESC, e.SelectedItem.SubItems[1].Text);
                        if (Convert.ToBoolean(SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Text) != true)
                        {
                            SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Value = true;
                        }
                    }
                }


                if (SpdSpareList.ActiveSheet.ActiveColumnIndex == (int)SPARE.SPARE_MAT_ID_SELECT)
                {
                    if (SpdSpareList.ActiveSheet.Cells[SpdSpareList.ActiveSheet.ActiveRowIndex, (int)SPARE.SPARE_MAT_ID].Text == e.SelectedItem.SubItems[0].Text)
                    {
                        return;
                    }
                    else
                    {
                        SpdSpareList_Sheet1.SetValue(e.Row, (int)SPARE.SPARE_MAT_ID, e.SelectedItem.SubItems[0].Text);
                        SpdSpareList_Sheet1.SetValue(e.Row, (int)SPARE.SPARE_MAT_ID_DESC, e.SelectedItem.SubItems[1].Text);
                        if (Convert.ToBoolean(SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Text) != true)
                        {
                            SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Value = true;
                        }
                    }
                }

                if (SpdSpareList.ActiveSheet.ActiveColumnIndex == (int)SPARE.SPEC_SELECT)
                {
                    if (SpdSpareList.ActiveSheet.Cells[SpdSpareList.ActiveSheet.ActiveRowIndex, (int)SPARE.SPEC].Text == e.SelectedItem.SubItems[0].Text)
                    {
                        return;
                    }
                    else
                    {
                        SpdSpareList_Sheet1.SetValue(e.Row, (int)SPARE.SPEC, e.SelectedItem.SubItems[0].Text);
                        SpdSpareList_Sheet1.SetValue(e.Row, (int)SPARE.SPEC_DESC, e.SelectedItem.SubItems[1].Text);
                        if (Convert.ToBoolean(SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Text) != true)
                        {
                            SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Value = true;
                        }
                    }
                }

                if (SpdSpareList.ActiveSheet.ActiveColumnIndex == (int)SPARE.MANUFACTURER_SELECT)
                {
                    if (SpdSpareList.ActiveSheet.Cells[SpdSpareList.ActiveSheet.ActiveRowIndex, (int)SPARE.MANUFACTURER_ID].Text == e.SelectedItem.SubItems[0].Text)
                    {
                        return;
                    }
                    else
                    {
                        SpdSpareList_Sheet1.SetValue(e.Row, (int)SPARE.MANUFACTURER_ID, e.SelectedItem.SubItems[0].Text);
                        SpdSpareList_Sheet1.SetValue(e.Row, (int)SPARE.MANUFACTURER_ID_DESC, e.SelectedItem.SubItems[1].Text);
                        if (Convert.ToBoolean(SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Text) != true)
                        {
                            SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Value = true;
                        }
                    }
                }

                if (SpdSpareList.ActiveSheet.ActiveColumnIndex == (int)SPARE.RES_ID_SELECT)
                {
                    if (SpdSpareList.ActiveSheet.Cells[SpdSpareList.ActiveSheet.ActiveRowIndex, (int)SPARE.RES_ID].Text == e.SelectedItem.SubItems[0].Text)
                    {
                        return;
                    }
                    else
                    {
                        SpdSpareList_Sheet1.SetValue(e.Row, (int)SPARE.RES_ID, e.SelectedItem.SubItems[0].Text);
                        SpdSpareList_Sheet1.SetValue(e.Row, (int)SPARE.RES_ID_DESC, e.SelectedItem.SubItems[1].Text);
                        if (Convert.ToBoolean(SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Text) != true)
                        {
                            SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Value = true;
                        }
                    }
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        private void SpdSpareList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {

            ListView lisTmp = new ListView();
            string sGcmName;

            lisTmp = new ListView();

            if (SpdSpareList.ActiveSheet.Cells[e.Row, e.Column].Text == gBeforeVal)
            {
                return;
            }
            else
            {
                switch (e.Column)
                {
                    case (int)SPARE.LOCATION_1:
                    case (int)SPARE.LOCATION_2:
                    case (int)SPARE.LOCATION_3:

                        if (e.Column == (int)SPARE.LOCATION_1)
                        {
                            sGcmName = CSGC.CP_GCM_SPARE_LOCATION_1;
                        }
                        else
                        {
                            sGcmName = CSGC.CP_GCM_SPARE_LOCATION_2;
                        }


                        if (BASLIST.ViewGCMDataList(lisTmp, '1', sGcmName) == true)
                        {

                            ListViewItem itmFound = lisTmp.FindItemWithText(SpdSpareList.ActiveSheet.Cells[e.Row, e.Column].Text);
                            if (itmFound == null)
                            {
                                //CMN257 ERROR - Data 문자열의 입력이 잘못되었습니다.
                                MPCF.ShowMsgBox("(" + SpdSpareList_Sheet1.Columns.Get(e.Column).Label + " : " + SpdSpareList.ActiveSheet.Cells[e.Row, e.Column].Text + ") \r\n " + MPCF.GetMessage(257));
                                SpdSpareList.ActiveSheet.Cells[e.Row, e.Column].Text = gBeforeVal;
                                return;
                            }
                            if (Convert.ToBoolean(SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Text) != true)
                            {
                                SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Value = true;
                            }
                        }
                        break;
                    case (int)SPARE.CHK:
                    case (int)SPARE.SPARE_TYPE:

                    case (int)SPARE.SPARE_MAT_ID:

                    case (int)SPARE.SPEC:

                    case (int)SPARE.MANUFACTURER_ID:

                    case (int)SPARE.RES_ID:



                        break;
                    default:
                        if (Convert.ToBoolean(SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Text) != true)
                        {
                            SpdSpareList_Sheet1.Cells[e.Row, (int)SPARE.CHK].Value = true;
                        }
                        break;
                }

            }
        }


        private void SpdSpareList_EditModeStarting(object sender, FarPoint.Win.Spread.EditModeStartingEventArgs e)
        {
            gBeforeVal = SpdSpareList.ActiveSheet.Cells[SpdSpareList.ActiveSheet.ActiveRowIndex, SpdSpareList.ActiveSheet.ActiveColumnIndex].Text;
        }

        #endregion






        private void cdvSpareType_ButtonPress(object sender, EventArgs e)
        {
            cdvSpareType.Init();
            MPCF.InitListView(cdvSpareType.GetListView);
            cdvSpareType.Columns.Add("SPARE_TYPE", 50, HorizontalAlignment.Left);
            cdvSpareType.Columns.Add("SPARE_TYPE_DESC", 50, HorizontalAlignment.Left);
            cdvSpareType.SelectedSubItemIndex = 0;
            cdvSpareType.DisplaySubItemIndex = 1;

            if (BASLIST.ViewGCMDataList(cdvSpareType.GetListView, '1', CSGC.CP_GCM_SPARE_TYPE) == false)
            {
                return;
            }
            cdvSpareType.InsertEmptyRow(0, 1);
        }
        private void cdvSpareDesc_ButtonPress(object sender, EventArgs e)
        {
            cdvSpareDesc.Init();
            MPCF.InitListView(cdvSpareDesc.GetListView);
            cdvSpareDesc.Columns.Add("SPARE_TYPE", 50, HorizontalAlignment.Left);
            cdvSpareDesc.Columns.Add("SPARE_MAT_ID", 50, HorizontalAlignment.Left);
            cdvSpareDesc.Columns.Add("SPARE_MAT_DESC", 50, HorizontalAlignment.Left);



            if (cdvSpareType.Text == "")
            {
                cdvSpareDesc.SelectedSubItemIndex = 0;
                cdvSpareDesc.DisplaySubItemIndex = 1;


                if (BASLIST.ViewGCMDataList(cdvSpareDesc.GetListView, '1', CSGC.CP_GCM_SPARE_MAT_ID) == false)
                {
                    return;
                }
               

            }
            else
            {
                cdvSpareDesc.SelectedSubItemIndex = 0;
                cdvSpareDesc.DisplaySubItemIndex = 1;
                if (BASLIST.ViewGCMDataList_AREA(cdvSpareDesc.GetListView, '1', CSGC.CP_GCM_SPARE_MAT_ID, -1, null, "", true, -1, -1, null, cdvSpareType.Text) == false)
                {
                     return;
                 }

            }
            cdvSpareDesc.InsertEmptyRow(0, 1);
        }

        private void cdvSpec_ButtonPress(object sender, EventArgs e)
        {
            cdvSpec.Init();
            MPCF.InitListView(cdvSpec.GetListView);
            cdvSpec.Columns.Add("SPARE_SPEC_ID", 50, HorizontalAlignment.Left);
            cdvSpec.Columns.Add("SPARE_SPEC_DESC", 50, HorizontalAlignment.Left);
            //  cdvLocation1.Columns.Add("DATA", 100, HorizontalAlignment.Left);
            cdvSpec.SelectedSubItemIndex = 0;
            cdvSpec.DisplaySubItemIndex = 1;

            if (BASLIST.ViewGCMDataList(cdvSpec.GetListView, '1', CSGC.CP_GCM_SPARE_SPEC_ID) == false)
            {
                return;
            }
            cdvSpec.InsertEmptyRow(0, 1);
        }

        private void cdvManudactirerId_ButtonPress(object sender, EventArgs e)
        {
            cdvManudactirerId.Init();
            MPCF.InitListView(cdvManudactirerId.GetListView);
            cdvManudactirerId.Columns.Add("MANUFACTURE_CODE", 50, HorizontalAlignment.Left);
            cdvManudactirerId.Columns.Add("MANAUFACTURE_DESC", 50, HorizontalAlignment.Left);
            //  cdvLocation1.Columns.Add("DATA", 100, HorizontalAlignment.Left);
            cdvManudactirerId.SelectedSubItemIndex = 0;
            cdvManudactirerId.DisplaySubItemIndex = 1;

            if (BASLIST.ViewGCMDataList(cdvManudactirerId.GetListView, '1', CSGC.CP_GCM_MANUFACTURE_CODE) == false)
            {
                return;
            }
            cdvManudactirerId.InsertEmptyRow(0, 1);
        }

        private void cdvResId_ButtonPress(object sender, EventArgs e)
        {
            cdvResId.Init();
            MPCF.InitListView(cdvManudactirerId.GetListView);
            cdvResId.Columns.Add("RES_ID", 50, HorizontalAlignment.Left);
            cdvResId.Columns.Add("RED_DESC", 50, HorizontalAlignment.Left);
            //  cdvLocation1.Columns.Add("DATA", 100, HorizontalAlignment.Left);
            cdvResId.SelectedSubItemIndex = 0;
            cdvResId.DisplaySubItemIndex = 1;

            if (BASLIST.ViewGCMDataList(cdvResId.GetListView, '1', CSGC.CP_GCM_SPARE_LOCATION_1) == false)
            {
                return;
            }
            cdvResId.InsertEmptyRow(0, 1);
        }
    }
}
