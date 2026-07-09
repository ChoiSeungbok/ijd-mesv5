using DevExpress.XtraPrinting.Native;
using FarPoint.Win.Spread;
using Miracom.CliFrx;
using Miracom.DNMCore;
using Miracom.MESCore;
using Miracom.TRSCore;
using System;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace CUS_COM
{
    public partial class frmPopMaterialList : frmViewForm01
    {
        public frmPopMaterialList()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum MAT_LIST
        {
            CHK,                    // 1 : CHECK
            MAT_ID,                 // 2 : 자재코드
            MAT_DESC,               // 3 : 자재명
            MAT_TYPE,               // 4 : 자재종류
            UNIT,                   // 5 : 단위
            MAT_GRP_1,              // 6 : 사업부
            MAT_VER,          // 7 : 제품 VER
            MAT_CMF6,               // 8 : 환산계수
            MAT_CMF6_BTN,        //9 :환산계수 수정
            MAT_CMF3,               // 12 : Grade
            MAT_CMF3_BTN,        //13 :Grade 수정
            MAT_CMF2,               // 10 : size
            MAT_CMF2_BTN,        //11 :size 수정


        }

        #endregion

        #region " Variable Definition "

        public string sMat_id = "";
        public string sMat_Desc = "";
        public string sMat_ver = "";

        public string sArea_id = "";
        public string sArea_desc = "";

        public string sType_id = "";
        public string sType_desc = "";

        public string sUnit = string.Empty;

        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnSelect.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //자재 리스트 조회 함수
        private void ViewMatList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";                
                string sMatDesc = "";
                string sSqlText = "";
                string sExcludeWord = "";
                StringBuilder sb = new StringBuilder();
                int i = 0;                 

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "MAT_TYPE";
                dvcArgu[2].sCondition_Value = cdvMatType.Text;

                //dvcArgu[3].sCondition_ID = "MAT_DESC";
                //dvcArgu[3].sCondition_Value = txtMatDesc.Text;


                //제품명 & 제품코드
                sMatDesc = MPCF.Trim(txtMatDesc.Text);
                string[] split_data = sMatDesc.Split(new string[] { string.Format("{0}", "%") }, StringSplitOptions.RemoveEmptyEntries);
                  
                if (split_data.Length > 0)
                {
                    sb.Append(" AND (");
                    for (int j = 0; j < split_data.Length; j++)
                    {
                        if (j > 0)
                        {
                            sb.Append(" OR ");
                        }
                        sb.Append($"(MAT_DESC LIKE '%' || '{split_data[j]}' || '%' OR MAT_ID LIKE '%' || '{split_data[j]}' || '%')");
                    }
                    sb.Append(")");
                }
                sSqlText = sSqlText + sb.ToString();       // 결과 문자열 

                // 제외문자
                sExcludeWord = MPCF.Trim(txtExcludeWord.Text);
                string[] split_data2 = sExcludeWord.Split(new string[] { string.Format("{0}", "-") }, StringSplitOptions.RemoveEmptyEntries);
                for (int k = 0; k < split_data2.Count(); k++)
                {                    
                    sSqlText = sSqlText + " AND MAT_DESC NOT LIKE '%' || '" + split_data2[k] + "' || '%'";
                }
                
                dvcArgu[3].sCondition_ID = "SQL_TEXT";
                dvcArgu[3].sCondition_Type = "TEXT"; 

                if (sSqlText == "")
                {
                    dvcArgu[3].sCondition_Value = "AND 1=1";
                }
                else
                {
                    dvcArgu[3].sCondition_Value = sSqlText;
                }

                if (TPDR.GetDataOne("", ref dt, "CCOM3001-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdmatList);
                    return;
                }

                MPCF.ClearList(spdmatList);
                FarPoint.Win.Spread.CellType.CheckBoxCellType checkBoxCellType = new FarPoint.Win.Spread.CellType.CheckBoxCellType();
                spdmatList_Sheet1.Columns.Get((int)MAT_LIST.CHK).CellType = checkBoxCellType;

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdmatList_Sheet1.RowCount++;

                    spdmatList_Sheet1.SetValue(i, (int)MAT_LIST.CHK, false);
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.MAT_TYPE].Value = dt.Rows[i]["MAT_TYPE"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.MAT_GRP_1].Value = dt.Rows[i]["MAT_GRP_1"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.MAT_CMF6].Value = dt.Rows[i]["MAT_CMF6"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.MAT_CMF3].Value = dt.Rows[i]["MAT_CMF3"];
                    spdmatList_Sheet1.Cells[i, (int)MAT_LIST.MAT_CMF2].Value = dt.Rows[i]["MAT_CMF2"];


                }

                MPCF.FitColumnHeader(spdmatList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmPopMaterialList_Load(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Text = sArea_id;
                cdvDept.DisplayText = sArea_desc;

                cdvMatType.Text = sType_id;
                cdvMatType.DisplayText = sType_desc;
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

                cdvDept.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvMatType.Init();
                MPCF.InitListView(cdvMatType.GetListView);
                cdvMatType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvMatType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvMatType.SelectedSubItemIndex = 0;
                cdvMatType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvMatType.GetListView, '1', MPGC.MP_WIP_MATERIAL_TYPE) == false)
                {
                    return;
                }

                cdvMatType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //수정
        private void spdmatList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {

                

                if (e.ColumnHeader)
                    return;
                //if (e.Column == (int)MAT_LIST.CHK)
                //   return;


                for (int i = 0; i < spdmatList.ActiveSheet.RowCount; i++)
                {
                    spdmatList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdmatList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);

                switch (e.Column)
                {
                    case (int)MAT_LIST.MAT_CMF2_BTN:
                    case (int)MAT_LIST.MAT_CMF3_BTN:
                    case (int)MAT_LIST.MAT_CMF6_BTN:
                    case (int)MAT_LIST.MAT_CMF2:
                    case (int)MAT_LIST.MAT_CMF3:
                    case (int)MAT_LIST.MAT_CMF6:

                        break;
                    default:

                        SheetView sv = spdmatList.ActiveSheet;

                        for (int i = 0; i < sv.RowCount; i++)
                        {
                            sv.Cells[i, (int)MAT_LIST.CHK].Value = false;
                        }

                        sv.Cells[e.Row, (int)MAT_LIST.CHK].Value = true;
                       // this.Close();
                        break;
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
                //if (MPCF.Trim(cdvDept.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                //    cdvDept.Focus();
                //    return;
                //}

                ViewMatList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void spdmatList_CellDoubleClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader)
                    return;

                switch (e.Column)
                {
                    case (int)MAT_LIST.MAT_CMF2_BTN:
                    case (int)MAT_LIST.MAT_CMF3_BTN:
                    case (int)MAT_LIST.MAT_CMF6_BTN:
                    case (int)MAT_LIST.MAT_CMF2:
                    case (int)MAT_LIST.MAT_CMF3:
                    case (int)MAT_LIST.MAT_CMF6:
                    case (int)MAT_LIST.CHK:

                        break;
                    default:
                        sMat_id = spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.MAT_ID].Text;
                        sMat_Desc = spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.MAT_DESC].Text;
                        sMat_ver = spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.MAT_VER].Text;
                        sType_id = spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.MAT_TYPE].Text;
                        sUnit = spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.UNIT].Text;

                        this.DialogResult = DialogResult.OK;
                        this.Close();
                        break;
                }


            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnSelect_Click(object sender, EventArgs e)
        {
            try
            {
                for (int i = 0; i < spdmatList.ActiveSheet.RowCount; i++)
                {
                    if (spdmatList.ActiveSheet.Cells[i, (int)MAT_LIST.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        sMat_id = spdmatList.ActiveSheet.Cells[i, (int)MAT_LIST.MAT_ID].Text;
                        sMat_Desc = spdmatList.ActiveSheet.Cells[i, (int)MAT_LIST.MAT_DESC].Text;
                        sMat_ver = spdmatList.ActiveSheet.Cells[i, (int)MAT_LIST.MAT_VER].Text;
                        sType_id = spdmatList.ActiveSheet.Cells[i, (int)MAT_LIST.MAT_TYPE].Text;
                        sUnit = spdmatList.ActiveSheet.Cells[i, (int)MAT_LIST.UNIT].Text;

                        this.DialogResult = DialogResult.OK;
                        break;
                    }
                }

                if (this.DialogResult == DialogResult.OK)
                    this.Close();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void txtMatDesc_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == (char)13)
            {
                ViewMatList();
            }
        }

        private void spdmatList_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            //if (e.Column == (int)MAT_LIST.CHK)
            //{
            //    SheetView sv = spdmatList.ActiveSheet;

            //    for (int i = 0; i < sv.RowCount; i++)
            //    {
            //        if (sv.GetValue(i, 0) != null && bool.Parse(sv.GetValue(i, 0).ToString()))
            //            sv.SetValue(i, 0, false); 
            //    }

            //    sv.SetValue(e.Row, 0, true);

            //    return;
            //}

            string ssql = "";
            string sCmfName = "";
            string sCmfValue = "";


            try
            {

                switch (e.Column)
                {
                    case (int)(int)MAT_LIST.CHK:
                        SheetView sv = spdmatList.ActiveSheet;

                            for (int i = 0; i < sv.RowCount; i++)
                            {
                                if (sv.GetValue(i, 0) != null && bool.Parse(sv.GetValue(i, 0).ToString()))
                                    sv.SetValue(i, 0, false); 
                            }

                            sv.SetValue(e.Row, 0, true);
                        break;

                    case (int)MAT_LIST.MAT_CMF2_BTN:
                    case (int)MAT_LIST.MAT_CMF3_BTN:
                    case (int)MAT_LIST.MAT_CMF6_BTN:


                        if (e.Column == (int)MAT_LIST.MAT_CMF2_BTN)  //size
                        {
                            sCmfName = "MAT_CMF_2";
                            if (spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.MAT_CMF2].Text.Trim() == "")
                            {
                                sCmfValue = " ";
                            }
                            else
                            {
                                sCmfValue = spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.MAT_CMF2].Text;
                            }

                        }
                        if (e.Column == (int)MAT_LIST.MAT_CMF3_BTN)  //grade
                        {
                            sCmfName = "MAT_CMF_3";
                            if (spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.MAT_CMF3].Text.Trim() == "")
                            {
                                sCmfValue = " ";
                            }
                            else
                            {
                                sCmfValue = spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.MAT_CMF3].Text;
                            }
                        }
                        if (e.Column == (int)MAT_LIST.MAT_CMF6_BTN)  //환산
                        {
                            sCmfName = "MAT_CMF_6";
                            if (spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.MAT_CMF6].Text.Trim() == "")
                            {
                                sCmfValue = "1";
                            }
                            else
                            {
                                sCmfValue = spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.MAT_CMF6].Text;
                            }
                        }


                        ssql = "UPDATE MWIPMATDEF SET " + sCmfName + " = '" + sCmfValue + "' WHERE FACTORY = '" + MPGV.gsFactory + "' AND MAT_ID = '" + spdmatList.ActiveSheet.Cells[e.Row, (int)MAT_LIST.MAT_ID].Text + "'";

                        TRSNode in_node = new TRSNode("TRAN_IN");
                        TRSNode out_node = new TRSNode("TRAN_OUT");

                        MPCR.SetInMsg(in_node);

                        in_node.ProcStep = '1';
                        in_node.AddString("SQL", ssql);


                        if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                        {
                            return;
                        }

                        MPCR.ShowSuccessMsg(out_node);

                        break;
                    default:

                        break;
                }





            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

        }



        #endregion

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdmatList, "LotMaterialList");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }
    }
}
