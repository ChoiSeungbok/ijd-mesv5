using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;

namespace CUS_RAS
{
    public partial class frmTranMoldStoreRegistration : CUS_COM.frmTranForm05
    {
        public frmTranMoldStoreRegistration()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum MOLD_INFO : int
        {
            CHECK,              // 1. 선택
            DLV_NO,             // 2. 입고 번호
            DLV_LOT_ID,         // 3. 입하 LOT ID
            MAT_ID,             // 4. 제품
            MAT_DESC,           // 5. 제품명
            UNIT,               // 6. 단위
            QTY,                // 7. 수량
            VENDOR_ID,          // 8. 협력사 ID
            VENDOR_DESC,        // 9. 협력사명           
            AREA_ID,            // 10.사업부
            SUB_AREA_ID,        // 11.작업장
            VENDOR_LOT_ID,      // 요청으로 밴더추가
            INSP_FLAG,          // 20210929 요청으로 판정정보 추가
            INSP_FLAG_NAME      // 20210929 요청으로 판정정보 추가

        }

        private enum LOT_INFO : int
        {
            MOLD_LOT_ID,        // 1. MOLD_LOT_ID(금형 번호)
            QTY,                // 2. 수량
            MOLD_MODEL,         // 3. 모델
            MOLD_MODEL_DESC,    // 4. 모델 명
            MOLD_TYPE,          // 5. 금형 구분
            MOLD_TYPE_DESC,     // 6. 금형 구분명
            VENDOR_ID,          // 7. 협력사 ID
            VENDOR_DESC,        // 8. 협력사명
            REMARK              // 9. 비고
        }

        #endregion

        #region " Variable Definition "

        //선택할 열 
        int selected_row = -1;
        //저장 여부
        bool is_saved = false;

        string mold_lot_id = "";

        #endregion

        #region " Function Defintion "

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
                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:
                        if (MPCF.Trim(cdvDept.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }
          
                        break;

                    case CSGC.CHECK.ADD:
                        if (MPCF.Trim(cdvModel.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblModel.Text + "]");
                            cdvModel.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvMoldType.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblModel.Text + "]");
                            cdvMoldType.Focus();
                            return false;
                        }

                        //일단 주석 필요해지면 주석 풀것20210928
                        /*
                        if (spdMoldList_Sheet1.Cells[selected_row, (int)MOLD_INFO.INSP_FLAG].ToString() != "P")
                        {
                            
                            MPCF.ShowMsgBox("해당검사판정은 입고가 불가능합니다.");
                            cdvMoldType.Focus();
                            return false;
                        }
                        */

                        if(selected_row < 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(133));
                            return false;
                        }

                        break;

                    case CSGC.CHECK.SAVE:
                        if (selected_row < 0)
                        {
                            MPCF.ShowMsgBox(MPCF.GetMessage(133));
                            return false;
                        }

                        if(spdLotList_Sheet1.RowCount == 0)
                        {
                            return false;
                        }

                        for (int i=0;i<spdLotList_Sheet1.RowCount;i++)
                        {
                            if (spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MOLD_LOT_ID].Text == "")
                            {
                                MPCF.ShowMsgBox(MPCF.GetMessage(525));
                                return false;
                            } 

                            if (spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MOLD_MODEL].Text == "") return false;

                            if (spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MOLD_TYPE].Text == "") return false;
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

        //초기화
        private void ClearList(string sType)
        {
            try
            {
                switch(sType)
                {
                    case "VIEW":
                        selected_row = -1;
                        is_saved = false;
                        mold_lot_id = "";

                        cdvModel.Text = "";
                        cdvMoldType.Text = "";

                        MPCF.ClearList(spdLotList);
                        break;

                    case "APPLY":
                        MPCF.ClearList(spdLotList);
                        break;

                    case "SAVE":
                       // MPCF.ClearList(spdLotList);
                        selected_row = -1;
                        break;
                }             
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //금형 입고 정보 조회
        private void ViewMoldList()
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CRAS2004-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatId.Text;

                dvcArgu[3].sCondition_ID = "VENDOR_ID";
                dvcArgu[3].sCondition_Value = cdvVendorCode.Text;

                dvcArgu[4].sCondition_ID = "FROM_DATE";
                dvcArgu[4].sCondition_Value = dtpFromDate.Text.Replace("-", ""); 

                dvcArgu[5].sCondition_ID = "TO_DATE";
                dvcArgu[5].sCondition_Value = dtpToDate.Text.Replace("-", "");

                dvcArgu[6].sCondition_ID = "DLV_NO";
                dvcArgu[6].sCondition_Value = txtDvlNo.Text;

                MPCF.ClearList(spdMoldList);

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.FitColumnHeader(spdMoldList);
                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMoldList_Sheet1.RowCount++;
                    spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.DLV_NO].Value = dt.Rows[i]["DLV_NO"];
                    spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.DLV_LOT_ID].Value = dt.Rows[i]["DLV_LOT_ID"];
                    spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.VENDOR_ID].Value = dt.Rows[i]["VENDOR_ID"];
                    spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];                
                    spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.AREA_ID].Value = dt.Rows[i]["AREA_ID"];
                    spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.SUB_AREA_ID].Value = dt.Rows[i]["SUB_AREA_ID"];
                    spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    
                    //CTM 요청으로 판정추가
                    spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.INSP_FLAG].Value = dt.Rows[i]["INSP_FLAG"];
                    spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.INSP_FLAG_NAME].Value = dt.Rows[i]["INSP_FLAG_NAME"];

                }
                MPCF.FitColumnHeader(spdMoldList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // LOT 정보 생성
        private bool CreateLotInfo()
        {
            try
            {              
                is_saved = false;

                int i_total_qty = MPCF.ToInt(spdMoldList_Sheet1.Cells[selected_row, (int)MOLD_INFO.QTY].Text);
                spdLotList_Sheet1.RowCount = i_total_qty;

                for (int i = 0; i < i_total_qty; i++)
                {

                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.QTY].Value = 1;
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MOLD_MODEL].Text = cdvModel.Text;
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MOLD_MODEL_DESC].Text = cdvModel.DisplayText;
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MOLD_TYPE].Text = cdvMoldType.Text;
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MOLD_TYPE_DESC].Text = cdvMoldType.DisplayText;
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.VENDOR_ID].Value = spdMoldList_Sheet1.Cells[selected_row, (int)MOLD_INFO.VENDOR_ID].Text;
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.VENDOR_DESC].Value = spdMoldList_Sheet1.Cells[selected_row, (int)MOLD_INFO.VENDOR_DESC].Text;
                }

                

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool SaveLot()
        {
            TRSNode in_node = new TRSNode("Tran_In");
            TRSNode out_node = new TRSNode("Tran_Out");
            TRSNode lot_list;

            try
            {
                MPCR.SetInMsg(in_node);

                //cStep 1 : Save
                in_node.ProcStep = '1';

                int i = 0;
                in_node.AddString("DLV_LOT_ID", spdMoldList.ActiveSheet.Cells[selected_row, (int)MOLD_INFO.DLV_LOT_ID].Text);
                in_node.AddString("MOLD_MODEL", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MOLD_MODEL].Text);
                in_node.AddString("MOLD_TYPE", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MOLD_TYPE].Text);               
                in_node.AddString("TRAN_COMMENT", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.REMARK].Text);
                in_node.AddString("AREA_ID", spdMoldList.ActiveSheet.Cells[selected_row, (int)MOLD_INFO.AREA_ID].Text);
                in_node.AddString("SUB_AREA_ID", spdMoldList.ActiveSheet.Cells[selected_row, (int)MOLD_INFO.SUB_AREA_ID].Text);

                for (i = 0; i < spdLotList_Sheet1.RowCount; i++)
                {
                    lot_list = in_node.AddNode("INV_LOT_LIST");
                    lot_list.AddDouble("QTY", MPCF.ToDbl(spdLotList_Sheet1.Cells[i, (int)LOT_INFO.QTY].Text));
                    lot_list.AddString("INV_LOT_ID",spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MOLD_LOT_ID].Text);
                }

                if (MPCR.CallService("CUS_RAS", "CUS_RAS_Mold_Store_Registration", in_node, ref out_node) == false)
                {
                    return false;
                }

                //spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MOLD_LOT_ID].Value = out_node.GetString("MOLD_LOT_ID");
                mold_lot_id = out_node.GetString("MOLD_LOT_ID");
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //LOT 정보 조회
        private void ViewLotInfo(string moldlotId)
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CRAS2004-002";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INV_LOT_ID";
                dvcArgu[1].sCondition_Value = moldlotId;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.FitColumnHeader(spdLotList);
                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Sheet1.RowCount++;
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MOLD_LOT_ID].Value = dt.Rows[i]["INV_LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MOLD_MODEL].Value = dt.Rows[i]["MOLD_MODEL"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MOLD_MODEL_DESC].Value = dt.Rows[i]["MOLD_MODEL_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MOLD_TYPE].Value = dt.Rows[i]["MOLD_TYPE"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.MOLD_TYPE_DESC].Value = dt.Rows[i]["MOLD_TYPE_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.VENDOR_DESC].Value = dt.Rows[i]["VENDOR_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT_INFO.REMARK].Value = dt.Rows[i]["LAST_TRAN_COMMENT"];
                }
                MPCF.FitColumnHeader(spdLotList);

            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition"
        private void frmTranMoldWarehouseRegistration_Load(object sender, EventArgs e)
        {
            try
            {
                dtpFromDate.Value = dtpToDate.Value.AddDays(-7);
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

                ClearList("VIEW");

                ViewMoldList();         
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
                cdvMatId.Init();
                MPCF.InitListView(cdvMatId.GetListView);
                cdvMatId.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvMatId.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvMatId.SelectedSubItemIndex = 0;
                cdvMatId.DisplaySubItemIndex = 1;

                //품명 호출
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    cdvMatId.Text = popup.sMat_id;
                    cdvMatId.DisplayText = popup.sMat_Desc;

                    popup = null;
                }
                else
                {
                    return;
                }

               // cdvMatId.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvVendorId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopVendorList popup = new frmPopVendorList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvVendorCode.Text = popup.g_VendorId;
                    this.cdvVendorCode.DisplayText = popup.g_VendorDesc;
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

        private void cdvModel_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvModel.Init();
                MPCF.InitListView(cdvModel.GetListView);
                cdvModel.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvModel.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvModel.SelectedSubItemIndex = 0;
                cdvModel.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvModel.GetListView, '1', MPGC.MP_RAS_TOOL_GRP) == false)
                {
                    return;
                }

                cdvModel.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMoldType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvMoldType.Init();
                MPCF.InitListView(cdvMoldType.GetListView);
                cdvMoldType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvMoldType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvMoldType.SelectedSubItemIndex = 0;
                cdvMoldType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvMoldType.GetListView, '1', CSGC.CP_GCM_MOLD_TYPE) == false)
                {
                    return;
                }

                cdvMoldType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnApply_Click(object sender, EventArgs e)
        {
           // int iRow = 0;

            try
            {
                if (CheckCondition(CSGC.CHECK.ADD) == false)
                    return;

                ClearList("APPLY");               

                //iRow = spdLotList_Sheet1.RowCount;
                //spdLotList_Sheet1.RowCount++;

                CreateLotInfo();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            try
            {
                if (spdLotList_Sheet1.RowCount <= 0) return;

                if(is_saved==false)
                    spdLotList.ActiveSheet.RemoveRows(spdLotList.ActiveSheet.RowCount - 1, 1);
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

                if(SaveLot())
                {
                    ClearList("SAVE");
                    is_saved = true;

                   // ViewLotInfo(mold_lot_id);

                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
                }
                
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvMatId.Text = "";
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdMoldList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                ClearList("VIEW");

                if (e.Row < 0||e.Column>0)
                {
                    return;
                }

                selected_row = e.Row;
                for (int i = 0; i < spdMoldList_Sheet1.RowCount; i++)
                {
                    if(i!=selected_row)
                        spdMoldList_Sheet1.Cells[i, (int)MOLD_INFO.CHECK].Value = false;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatId.DisplayText == "")
                cdvMatId.Text = "";
        }

        #endregion
    }
}
