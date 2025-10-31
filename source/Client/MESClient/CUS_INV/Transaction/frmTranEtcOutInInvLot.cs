using System;
using System.Data;
using System.Drawing;
using System.Windows.Forms;
using FarPoint.Win.Spread;
using MExcel = Microsoft.Office.Interop.Excel;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;


namespace CUS_INV
{
    public partial class frmTranEtcOutInInvLot : CUS_COM.frmTranForm05
    {
        public frmTranEtcOutInInvLot()
        {
            InitializeComponent();

            InitControl();
        }

        private void frmTranEtcOutInInvLot_Load(object sender, EventArgs e)
        {
            dtpOutDate.Text = DateTime.Now.ToShortDateString();
        }

        #region " Constant Definition "

        private enum MAT_INFO : int
        {
            OPER,                 // 1 : 창고 코드
            OPER_DESC,            // 2 : 창고명
            MAT_ID,               // 3 : 품목
            MAT_DESC,             // 4 : 품명
            QTY,                  // 5 : 수량
            UNIT,                 // 6 : 단위
            AREA,                 // 7 : 사업부
            MAT_TYPE,             // 8 : 품목유형
            SELECT,                // 9 : ROW 선택
            INV_FLAG             //10 :  자재 여부 (  조회시 MINVLOTSTS에서 조회된 리스트면 'Y'  이고 MWIPLOTSTS에서 조회된 리스트는 'N' 으로 바인딩 => 기타출고 서비스를 분기 시켜 호출하기 위한 구분 FLAG 값 )
        }

        private enum LOT
        {
            CHK,                     // 1 : CHECK
            LOT_ID,                  // 2 : LOT ID
            QTY,                     // 3 : 수량
            OUT_QTY,                 // 4 : 출고 수량
            VENDOR_LOT_ID,           // 5 : 업체 LOT NO
            UNIT,                    // 6 : 단위
            MAT_ID,                  // 7 : 제품
            MAT_DESC,                // 8 : 제품명
            OPER,                    // 9 : 창고
            OPER_DESC,               // 10 : 창고 명          
            COMMENT                  // 11 : 비고    
        }

        #endregion

        #region " Variable Definition "
        
        string c_Area = string.Empty;
        string c_Oper = string.Empty;
        string c_MatType = string.Empty;
        string c_MatId = string.Empty;
        string c_InvFlag = string.Empty;
        double out_qty = 0;

        #endregion

        #region " Function Definition "

        private void InitControl()
        {
            try
            {
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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
                out_qty = 0;

                switch (sType)
                {
                    case "VIEW":
                        cdvOutType.Text = string.Empty;
                        cdvInType.Text = string.Empty;
                        txtOutQty.Text = string.Empty;
                        cdvInMatId.Text = string.Empty;
                        txtInMatDesc.Text = string.Empty;

                        c_Area = string.Empty;
                        c_MatId = string.Empty;
                        c_MatType = string.Empty;
                        c_Oper = string.Empty;
                        c_InvFlag = string.Empty;

                        MPCF.ClearList(spdMatList);
                        MPCF.ClearList(spdLotList);
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.OUT_QTY].Value = 0;
                        break;

                    case "ALL":
                        chkERP.Checked = false;
                        cdvOutType.Enabled = true;
                        cdvOutType.Text = string.Empty;
                        cdvInType.Enabled = true;
                        cdvInType.Text = string.Empty;
                        txtOutQty.Text = string.Empty;
                        cdvInMatId.Text = string.Empty;
                        txtInMatDesc.Text = string.Empty;

                        c_Area = string.Empty;
                        c_MatId = string.Empty;
                        c_MatType = string.Empty;
                        c_Oper = string.Empty;
                        c_InvFlag = string.Empty;
                        
                        MPCF.ClearList(spdMatList);
                        MPCF.ClearList(spdLotList);
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.OUT_QTY].Value = 0;
                        break;

                    case "MAT_CLICK":
                        cdvOutType.Text = string.Empty;
                        cdvInType.Text = string.Empty;
                        txtOutQty.Text = string.Empty;
                        cdvInMatId.Text = string.Empty;
                        txtInMatDesc.Text = string.Empty;

                        MPCF.ClearList(spdLotList);
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.OUT_QTY].Value = 0;
                        break;

                    case "PROC":
                        MPCF.ClearList(spdMatList);
                        MPCF.ClearList(spdLotList);
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.OUT_QTY].Value = 0;

                        break;

                    case "EXCEL_UPLOAD":
                        MPCF.ClearList(spdLotList);
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;
                        spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.OUT_QTY].Value = 0;
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
            SheetView svLotList = spdLotList.ActiveSheet;
            int iSelect = 0;

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

                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvMatType.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMatType.Text + "]");
                            cdvMatType.Focus();
                            return false;
                        }
                        break;

                    case CSGC.CHECK.SAVE:
                        if (svLotList.RowCount <= 0)
                        {
                            //CMN423 ERROR - 선택된 아이템이 없습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(423));
                            return false;
                        }

                        for (int i = 0; i < svLotList.RowCount; i++)
                        {
                            if(svLotList.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                            {
                                iSelect++;
                            }
                        }

                        if(iSelect <= 0)
                        {
                            //CMN423 ERROR - 선택된 아이템이 없습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(423));
                            return false;
                        }
                        
                        if(MPCF.Trim(txtOutQty.Text) == "" || MPCF.ToDbl(txtOutQty.Text)==0)
                        {
                            //CMN423 ERROR - 선택된 아이템이 없습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(423));
                            return false;
                        }

                        if (cdvOutType.Enabled)
                        {
                            if (string.IsNullOrEmpty(cdvOutType.Text))
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOutType.Text + "]");
                                cdvOutType.Focus();
                                return false;
                            }
                        }



                        if (cdvInType.Enabled)
                        {
                            if (string.IsNullOrEmpty(cdvInType.Text))
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblInType.Text + "]");
                                cdvInType.Focus();
                                return false;
                            }
                        }


                        if (string.IsNullOrEmpty(cdvInMatId.Text))
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblInMatid.Text + "]");
                            cdvInMatId.Focus();
                            return false;
                        }

           


                        break;
                    case CSGC.CHECK.ADD: //excel upload
                        if (MPCF.Trim(cdvDept.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                            cdvDept.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
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

        // 출고 정보 조회
        private void ViewMatInfo(string sArea, string sOper, string sMatType, string sMatId)
        {
            string sView_Id = "";
            SheetView svMat = spdMatList.ActiveSheet;
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CINV2013-001";

                dvcArgu[0].sCondition_ID = "P_FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "P_AREA_ID";
                dvcArgu[1].sCondition_Value = sArea;

                dvcArgu[2].sCondition_ID = "P_OPER";
                dvcArgu[2].sCondition_Value = sOper;

                dvcArgu[3].sCondition_ID = "P_MAT_TYPE";
                dvcArgu[3].sCondition_Value = sMatType;

                dvcArgu[4].sCondition_ID = "P_MAT_ID";
                dvcArgu[4].sCondition_Value = sMatId;

                // 조회 필수조건이 창고, Mat Type이므로   MWIPLOTSTS, MINVLOTSTS 에서 동일한 
              //  dvcArgu[5].sCondition_ID = "P_INV_FLAG";
              //  dvcArgu[5].sCondition_Value = sMatType == CSGC.CP_RAW_MATERIAL ? "Y" : "N";

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    svMat.RowCount++;

                    svMat.Cells[i, (int)MAT_INFO.OPER].Value = dt.Rows[i]["OPER"];
                    svMat.Cells[i, (int)MAT_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    svMat.Cells[i, (int)MAT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    svMat.Cells[i, (int)MAT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    svMat.Cells[i, (int)MAT_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    svMat.Cells[i, (int)MAT_INFO.UNIT].Value = dt.Rows[i]["UNIT"];
                    svMat.Cells[i, (int)MAT_INFO.AREA].Value = dt.Rows[i]["AREA_ID"];
                    svMat.Cells[i, (int)MAT_INFO.MAT_TYPE].Value = dt.Rows[i]["MAT_TYPE"];
                    svMat.Cells[i, (int)MAT_INFO.INV_FLAG].Value = dt.Rows[i]["INV_FLAG"];

                    //처리 전에 선택된 MAT_ID가 있는 경우 선택
                    if (c_MatId == dt.Rows[i]["MAT_ID"].ToString())
                    {
                        //색깔 변경
                        svMat.Rows[i].BackColor = Color.FromArgb(255, 192, 255);
                        svMat.Cells[i, (int)MAT_INFO.SELECT].Value = "Y";
                    }
                }

                MPCF.FitColumnHeader(spdMatList);

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
            double dSumOutQty = 0;
            int iCount = 0;

            try
            {
                for (int i = 0; i < spdLotList_Sheet1.RowCount; i++)
                {
                    if (spdLotList_Sheet1.Cells[i, (int)LOT.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        iCount++;
                        dSumQty += MPCF.ToDbl(spdLotList_Sheet1.Cells[i, (int)LOT.QTY].Text);
                        dSumOutQty += MPCF.ToDbl(spdLotList_Sheet1.Cells[i, (int)LOT.OUT_QTY].Text);
                    }
                }

                spdLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.CHK].Value = iCount;
                spdLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.QTY].Value = dSumQty;
                spdLotList_Sheet1.ColumnFooter.Cells[0, (int)LOT.OUT_QTY].Value = dSumOutQty;

                txtOutQty.Text = dSumOutQty.ToString();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //출고 자재 정보 조회
        private void ViewInvLotInfo(string sArea, string sOper, string sMatType, string sMatId, string sInvFlag)
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                double dSumQty = 0;

                sView_Id = "CINV2013-002";

                dvcArgu[0].sCondition_ID = "P_FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "P_AREA_ID";
                dvcArgu[1].sCondition_Value = sArea;

                dvcArgu[2].sCondition_ID = "P_OPER";
                dvcArgu[2].sCondition_Value = sOper;

                dvcArgu[3].sCondition_ID = "P_MAT_ID";
                dvcArgu[3].sCondition_Value = sMatId;

                //창고, 품목으로 minvlotsts, mwiplotsts 에 동시에 존재하지 않으므로  조건 주석처리
               // dvcArgu[4].sCondition_ID = "P_INV_FLAG";
               // dvcArgu[4].sCondition_Value = sMatType == CSGC.CP_RAW_MATERIAL ? "Y" : "N";

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }
             
                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Sheet1.RowCount++;
                    spdLotList_Sheet1.SetValue(i, (int)LOT.CHK, false);
                    spdLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.OUT_QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                }
                MPCF.FitColumnHeader(spdLotList);
           

                for (i = 0; i < spdLotList_Sheet1.RowCount; i++)
                {
                    dSumQty += MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT.QTY].Text);
                }

                spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = dSumQty;
                spdLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.OUT_QTY].Value = dSumQty;
                spdLotList_Sheet1.Columns[(int)LOT.COMMENT].Width = 300;
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 기타 출고 
        private bool SaveOutEtcInvLot()
        {
            SheetView svMat = spdMatList.ActiveSheet;
            SheetView svLotList = spdLotList.ActiveSheet;
            
            TRSNode in_node = new TRSNode("Etc_In");
            TRSNode out_node = new TRSNode("Etc_Out");
            TRSNode inv_lot_list;
            bool send_flag = false;

            string sArea = string.Empty;
            string sOper = string.Empty;
            string sMatId = string.Empty;
            string sMatType = string.Empty;
            string sInvFlag = string.Empty;

            try
            {
                MPCR.SetInMsg(in_node);
                
                for (int i = 0; i < svMat.RowCount; i++)
                {
                    if (svMat.Cells[i, (int)MAT_INFO.SELECT].Text == "Y")
                    {
                        sArea = svMat.Cells[i, (int)MAT_INFO.AREA].Value.ToString();
                        sOper = svMat.Cells[i, (int)MAT_INFO.OPER].Value.ToString();
                        sMatType = svMat.Cells[i, (int)MAT_INFO.MAT_TYPE].Value.ToString();
                        sMatId = svMat.Cells[i, (int)MAT_INFO.MAT_ID].Value.ToString();
                        sInvFlag = svMat.Cells[i, (int)MAT_INFO.INV_FLAG].Value.ToString(); // MINVLOTSTS에서 조회('Y')   MWIPLOTSTS에서 조회('N')
                        break;
                    }
                }

                //원자재인 경우 기존 INV 기타출고
                //원자재 아닌 경우 WIP 기타출고
                //혹시 달라질수 있으므로 분기해놓음
                //if(sMatType == CSGC.CP_RAW_MATERIAL)
                if(sInvFlag == "Y")
                {
                    in_node.ProcStep = '2';

                    //출고할 자재 리스트
                    for (int i = 0; i < svLotList.RowCount; i++)
                    {
                        if (svLotList.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                        {
                            if(MPCF.ToDbl(svLotList.Cells[i, (int)LOT.OUT_QTY].Text) <= 0)
                            {
                                //CMN495 INFO - 출고 수량은 0보다 큰 수량이어야 합니다.
                                MPCF.ShowMsgBox(MPCF.GetMessage(495));
                                return false;
                            }

                            inv_lot_list = in_node.AddNode("INV_LOT_LIST");

                            inv_lot_list.AddString("INV_LOT_ID", svLotList.Cells[i, (int)LOT.LOT_ID].Text.Trim());
                            inv_lot_list.AddDouble("OUT_QTY", MPCF.ToDbl(svLotList.Cells[i, (int)LOT.OUT_QTY].Text));
                            inv_lot_list.AddString("COMMENT", svLotList.Cells[i, (int)LOT.COMMENT].Text.Trim());
                            send_flag = true;
                        }
                    }

                    if (send_flag == false)
                    {
                        //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(109));
                        return false;
                    }

                    in_node.AddString("TERMINATE_CODE", "ETC_OUT");
                    in_node.AddString("OUT_DATE", MPCF.DestroyDateFormat(dtpOutDate.Text, DATE_TIME_FORMAT.DATE));
                    in_node.AddString("ETC_OUT_TYPE", cdvOutType.Text);
                    in_node.AddChar("ERP_FLAG", chkERP.Checked == true ? 'N' : 'Y');

                    if (MPCR.CallService("CUS_INV", "CUS_INV_Terminate_Lot", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                }
                else
                {
                    in_node.ProcStep = '2';

                    //출고할 자재 리스트
                    for (int i = 0; i < svLotList.RowCount; i++)
                    {
                        if (svLotList.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                        {
                            if (MPCF.ToDbl(svLotList.Cells[i, (int)LOT.OUT_QTY].Text) <= 0)
                            {
                                //CMN495 INFO - 출고 수량은 0보다 큰 수량이어야 합니다.
                                MPCF.ShowMsgBox(MPCF.GetMessage(495));
                                return false;
                            }

                            inv_lot_list = in_node.AddNode("LOT_LIST");

                            inv_lot_list.AddString("LOT_ID", svLotList.Cells[i, (int)LOT.LOT_ID].Text.Trim());
                            inv_lot_list.AddDouble("OUT_QTY", MPCF.ToDbl(svLotList.Cells[i, (int)LOT.OUT_QTY].Text));
                            inv_lot_list.AddString("COMMENT", svLotList.Cells[i, (int)LOT.COMMENT].Text.Trim());
                            send_flag = true;
                        }
                    }

                    if (send_flag == false)
                    {
                        //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(109));
                        return false;
                    }

                    in_node.AddString("TERMINATE_CODE", "ETC_OUT");
                    in_node.AddString("TO_MAT_ID", cdvInMatId.Text.Trim());
                    in_node.AddString("OUT_DATE", MPCF.DestroyDateFormat(dtpOutDate.Text, DATE_TIME_FORMAT.DATE));
                    in_node.AddString("ETC_OUT_TYPE", cdvOutType.Text);
                    in_node.AddString("ETC_IN_TYPE", cdvInType.Text);
                    in_node.AddChar("ERP_FLAG", chkERP.Checked == true ? 'N' : 'Y');

                    if (MPCR.CallService("CUS_WIP", "CUS_WIP_Etc_Out_Lot", in_node, ref out_node) == false)
                    {
                        return false;
                    }


                }














                
                //성공 후 다시 VIEW를 조회하기 위해서 지역변수에 등록
                c_Area = sArea;
                c_Oper = sOper;
                c_MatType = sMatType;
                c_MatId = sMatId;
                c_InvFlag = sInvFlag;

                MPCR.ShowSuccessMsg(out_node);

                return true;
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //엑셀 업로드
        private void UploadExcel()
        {

            MExcel.Application XApp = null;
            MExcel.Workbooks XBooks = null;
            MExcel.Workbook XBook = null;
            MExcel.Worksheet XSheet = null;
            MExcel.Sheets XSheets = null;

            OpenFileDialog ofdFile = new OpenFileDialog();

            try
            {
                ofdFile.Filter = "Excel Files(*.xls;*.xlsx)|*.xls;*.xlsx";
                ofdFile.DefaultExt = "xls,xlsx";

                if (ofdFile.ShowDialog() != DialogResult.OK)
                    return;

                XApp = new MExcel.Application();
                XApp.Interactive = false;
                XBooks = XApp.Workbooks;
                XBook = XBooks.Open(ofdFile.FileName);

                ((Excel.Worksheet)XBook.Sheets[1]).Select();

                XSheets = XBook.Worksheets;
                XSheet = XSheets.get_Item(1) as MExcel.Worksheet;

                //시트에서 사용된 셀범위
                MExcel.Range range = XSheet.UsedRange;

                //2차원 배열에 담기
                Object[,] data = range.Value;
                int row_count = range.Rows.Count;
                //spdLotList_Sheet1.RowCount = row_count - 1;

                double out_qty = 0.0d;

                for (int i = 2; i <= row_count; i++)
                {
                    if (data[i, (int)LOT.LOT_ID + 1].ToString().Trim() != "")
                    {
                        if (ValidLotInfo(data[i, (int)LOT.LOT_ID + 1].ToString().Trim(), data[i, (int)LOT.OPER + 1].ToString()) == false)
                            return;

                        spdLotList_Sheet1.RowCount++;
                        spdLotList_Sheet1.SetValue(i - 2, (int)LOT.CHK, true);
                        spdLotList_Sheet1.Cells[i - 2, (int)LOT.LOT_ID].Value = data[i, (int)LOT.LOT_ID + 1];
                        spdLotList_Sheet1.Cells[i - 2, (int)LOT.QTY].Value = data[i, (int)LOT.QTY + 1];
                        spdLotList_Sheet1.Cells[i - 2, (int)LOT.OUT_QTY].Value = data[i, (int)LOT.OUT_QTY + 1];
                        spdLotList_Sheet1.Cells[i - 2, (int)LOT.VENDOR_LOT_ID].Value = data[i, (int)LOT.VENDOR_LOT_ID + 1];
                        spdLotList_Sheet1.Cells[i - 2, (int)LOT.UNIT].Value = data[i, (int)LOT.UNIT + 1];
                        spdLotList_Sheet1.Cells[i - 2, (int)LOT.MAT_ID].Value = data[i, (int)LOT.MAT_ID + 1];
                        spdLotList_Sheet1.Cells[i - 2, (int)LOT.MAT_DESC].Value = data[i, (int)LOT.MAT_DESC + 1];
                        spdLotList_Sheet1.Cells[i - 2, (int)LOT.OPER].Value = data[i, (int)LOT.OPER + 1];
                        spdLotList_Sheet1.Cells[i - 2, (int)LOT.OPER_DESC].Value = data[i, (int)LOT.OPER_DESC + 1];
                        spdLotList_Sheet1.Cells[i - 2, (int)LOT.COMMENT].Value = data[i, (int)LOT.COMMENT + 1];

                        out_qty += MPCF.ToDbl(spdLotList_Sheet1.Cells[i - 2, (int)LOT.OUT_QTY].Value);
                    }
                }               

                txtOutQty.Text = out_qty.ToString();

                CheckCount();

                XBook.Close(true);
                XApp.Quit();

                MPCF.ShowMsgBox(MPCF.GetMessage(52));
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
            finally
            {
                ReleasExcelObject(XSheet);
                ReleasExcelObject(XBook);
                ReleasExcelObject(XApp);
            }
        }

        private string GetExcelString(string s)
        {
            string rtn = "";

            if (s.ToUpper() == "NULL") rtn = "";

            rtn = s;

            return rtn;
        }


        private bool ValidLotInfo(string sLotId, string sOper)
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";          

                sView_Id = "CINV2013-003";

                dvcArgu[0].sCondition_ID = "P_FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "P_LOT_ID";
                dvcArgu[1].sCondition_Value = sLotId;


                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    //CMN521 ERROR - 이 LOT은 존재 하지 않습니다. LOT을  확인 하세요.
                    MPCF.ShowMsgBox(string.Format("{1}[{0}]", sLotId, MPCF.GetMessage(521)));
                    return false;
                }
                if (dt.Rows.Count > 0)
                {
                    if (sOper.Trim() != dt.Rows[0]["OPER"].ToString().Trim())
                    {
                         //CMN457 ERROR - 이 LOT은 해당 공정에 존재하지 않습니다.
                        MPCF.ShowMsgBox(string.Format("{1}[{0}]", sLotId, MPCF.GetMessage(457)));
                        return false;
                    }
                }
                for (int i = 0; i < spdLotList_Sheet1.RowCount;i++)
                {
                    if (spdLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Value.ToString().Trim() == sLotId)
                    {   
                        //CMN164 ERROR - 이 Lot은 이미 존재 합니다. Lot을 확인 하세요.
                        MPCF.ShowMsgBox(string.Format("{1}[{0}]", sLotId, MPCF.GetMessage(164)));
                        return false;
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


        #endregion



        #region "Event Definition "

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

        private void cdvMatId_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                popup.sType_id = cdvMatType.Text;
                popup.sType_desc = cdvMatType.DisplayText;

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

        private void cdvOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, 'F', cdvDept.Text, "", "", "", 'Y') == false)
                {
                    return;
                }

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch(Exception ex)
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

                ClearData("VIEW");
                
                ViewMatInfo(cdvDept.Text, cdvOper.Text, cdvMatType.Text, cdvMatId.Text);

            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdMatList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            SheetView svMat = spdMatList.ActiveSheet;
            string sArea = string.Empty;
            string sOper = string.Empty;
            string sMatType = string.Empty;
            string sMatId = string.Empty;
            string sInvFlag = string.Empty;
           
            try
            {
                if (e.ColumnHeader || e.Row < 0)
                {
                    return;
                }

                for (int i = 0; i < svMat.RowCount; i++)
                {
                    svMat.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                    svMat.Cells[i, (int)MAT_INFO.SELECT].Value = "N";
                }
                
                svMat.Cells[e.Row, (int)MAT_INFO.SELECT].Value = "Y";
                svMat.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);
                sArea = svMat.Cells[e.Row, (int)MAT_INFO.AREA].Value == null ? string.Empty : svMat.Cells[e.Row, (int)MAT_INFO.AREA].Value.ToString();
                sOper = svMat.Cells[e.Row, (int)MAT_INFO.OPER].Value == null ? string.Empty : svMat.Cells[e.Row, (int)MAT_INFO.OPER].Value.ToString();
                sMatType = svMat.Cells[e.Row, (int)MAT_INFO.MAT_TYPE].Value == null ? string.Empty : svMat.Cells[e.Row, (int)MAT_INFO.MAT_TYPE].Value.ToString();
                sMatId = svMat.Cells[e.Row, (int)MAT_INFO.MAT_ID].Value == null ? string.Empty : svMat.Cells[e.Row, (int)MAT_INFO.MAT_ID].Value.ToString();
                sInvFlag = svMat.Cells[e.Row, (int)MAT_INFO.INV_FLAG].Value == null ? string.Empty : svMat.Cells[e.Row, (int)MAT_INFO.INV_FLAG].Value.ToString();

                ClearData("MAT_CLICK");

                ViewInvLotInfo(sArea, sOper, sMatType, sMatId, sInvFlag);
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
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if(SaveOutEtcInvLot())
                {
                    ClearData("PROC");

                    ViewMatInfo(c_Area, c_Oper, c_MatType, string.Empty);
                    ViewInvLotInfo(c_Area, c_Oper, c_MatType, c_MatId, c_InvFlag);

                    c_Area = string.Empty;
                    c_Oper = string.Empty;
                    c_MatType = string.Empty;
                    c_MatId = string.Empty;
                    c_InvFlag = string.Empty;
                }

            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdInvInfo_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                double qty = MPCF.ToDbl(spdLotList_Sheet1.Cells[e.Row, (int)LOT.OUT_QTY].Value);

                if (spdLotList_Sheet1.Cells[e.Row, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                {
                    out_qty += qty;
                }
                else if (spdLotList_Sheet1.Cells[e.Row, (int)LOT.CHK].Text.ToString().ToUpper() == "FALSE")
                {
                    out_qty -= qty;
                }

                txtOutQty.Text = out_qty.ToString();

                CheckCount();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOutType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOutType.Init();
                MPCF.InitListView(cdvOutType.GetListView);
                cdvOutType.Columns.Add("DESC", 50, HorizontalAlignment.Left);
                cdvOutType.Columns.Add("ID", 100, HorizontalAlignment.Left);
                cdvOutType.SelectedSubItemIndex = 1;
                cdvOutType.DisplaySubItemIndex = 0;

                if (COM_LIST.ViewEtcTypeList(cdvOutType.GetListView, "CINV2012-002", cdvDept.Text, "ISSUE") == false)
                {
                    return;
                }

                cdvOutType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_CellClick(object sender, CellClickEventArgs e)
        {
            if (e.ColumnHeader == true)
            {
                if (spdLotList.ActiveSheet.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                {
                    CSCF.CheckSpreadCell(spdLotList, e.Row, e.Column, true, true, false);
                }

                double qty = 0;

                for (int i = 0; i < spdLotList_Sheet1.RowCount; i++)
                {
                    qty = MPCF.ToDbl(spdLotList_Sheet1.Cells[i, (int)LOT.OUT_QTY].Value);

                    if (spdLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        out_qty += qty;
                    }
                    else if (spdLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "FALSE")
                    {
                        out_qty -= qty;
                    }
                } 

                txtOutQty.Text = out_qty.ToString();

                CheckCount();
            }
        }

        private void chkERP_CheckedChanged(object sender, EventArgs e)
        {
            if (chkERP.Checked == true)
            {
                cdvOutType.Text = "";
                cdvOutType.Enabled = false;
                cdvInType.Text = "";
                cdvInType.Enabled = false;

                //실수 및 문제될  우려가 있어서 해당 로직 주의 사항 메세지 출력.(2021/07/08)..계속문제되면 해당기능 죽일예정
                MPCF.ShowMsgBox(MPCF.GetMessage(545));
            }
            else
            {
                cdvOutType.Enabled = true;
                cdvInType.Enabled = true;
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                ClearData("ALL");
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_Change(object sender, ChangeEventArgs e)
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

        private void cdvMatId_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatId.DisplayText == "")
                cdvMatId.Text = "";
        }

        private void btnUploadExcel_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.ADD) == false)
                    return;

                ClearData("EXCEL_UPLOAD");
                UploadExcel();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ReleasExcelObject(object obj)
        {
            try
            {
                if (obj != null)
                {
                    System.Runtime.InteropServices.Marshal.ReleaseComObject(obj);
                    obj = null;
                }
            }
            catch (Exception ex)
            {
                obj = null;
                throw ex;
            }
            finally
            {
                GC.Collect();
            }
        }

        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {       
                spdLotList_Sheet1.Columns[(int)LOT.CHK].Visible = false;

                EXTFUC.SaveExcel(spdLotList, "EtcOutLotList");

                spdLotList_Sheet1.Columns[(int)LOT.CHK].Visible = true;

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void cdvInType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvInType.Init();
                MPCF.InitListView(cdvInType.GetListView);
                cdvInType.Columns.Add("DESC", 50, HorizontalAlignment.Left);
                cdvInType.Columns.Add("ID", 100, HorizontalAlignment.Left);
                cdvInType.SelectedSubItemIndex = 1;
                cdvInType.DisplaySubItemIndex = 0;

                if (COM_LIST.ViewEtcTypeList(cdvInType.GetListView, "CINV2012-002", cdvDept.Text, "RECEIPT") == false)
                {
                    return;
                }

                cdvInType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvInMatId_ButtonPress(object sender, EventArgs e)
        {
            try
            {


                // 제품 팝업으로 변경
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                popup.sType_id = cdvInMatId.Text;


                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvInMatId.Text = popup.sMat_id;
                    this.txtInMatDesc.Text = popup.sMat_Desc;
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

        private void grpOutInfo_Click(object sender, EventArgs e)
        {

        }

        #endregion
    }
}
