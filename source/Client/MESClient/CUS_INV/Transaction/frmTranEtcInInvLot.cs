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
using GrapeCity.Win.Spread.InputMan.CellType;

namespace CUS_INV
{
    public partial class frmTranEtcInInvLot : CUS_COM.frmTranForm01
    {
        public frmTranEtcInInvLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum MAT
        {
            MAT_ID,                 // 1 : 제품
            MAT_VER,                // 2 : 버전
            MAT_DESC,               // 3 : 제품명
            MAT_TYPE,               // 4 : 타입
            UNIT                    // 5 : 단위
        }

        private enum LOT
        {
            CHK,                    // 1 : CHECK
            LOT_ID,                 // 2 : 자재 LOT ID or 공정 LOT ID
            PROD_CHK,               // 3 : 그릿 제품 lot id 룰 여부 
            SEQ,                    // 4 : 순번
            QTY,                    // 5 : 수량
            UNIT,                   // 6 : 단위
            SUB_AREA_ID,            // 7 : 작업장
            OPER,                   // 8 : 창고
            OPER_DESC,              // 9 : 창고명
            MAT_ID,                 //10 : 제품
            MAT_VER,                //11 : 버전
            MAT_DESC,               //12 : 제품명
            ARRIVAL_DATE,           //13 : 입고일
            IN_TYPE,                //14 : 입고 유형
            VENDOR_ID,              //15 : 협력사
            VENDOR_SITE_ID,         //15 : 협력사 SITE ID
            VENDOR_LOT_ID,          //17 : 업체 LOT NO 
            CREATE_FLAG,            //18 : 생성여부
            COMMENT                 //19 : 주석 (COMMENT)
        }

        #endregion

        #region " Variable Definition "
        
        bool s_raw_material_flag = false;
        string s_vendor_id = "";
        string s_vendor_site_id = "";

        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                lblLableSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                cdvLabelSize.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Right;
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

        //사업부 별 제품 LIST
        private void ViewMaterialList()
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

                dvcArgu[2].sCondition_ID = "MAT_ID";
                dvcArgu[2].sCondition_Value = cdvMatID.Text;

                dvcArgu[3].sCondition_ID = "MAT_TYPE";
                dvcArgu[3].sCondition_Value = cdvMatType.Text;

                dvcArgu[4].sCondition_ID = "MAT_DESC";
                dvcArgu[4].sCondition_Value = txtMatDesc.Text;

                if (TPDR.GetDataOne("", ref dt, "CINV2012-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdMatList);
                    return;
                }

                MPCF.ClearList(spdMatList);

                for (i = 0; i < dt.Rows.Count; i++)
                {

                    spdMatList_Sheet1.RowCount++;
                    
                    spdMatList_Sheet1.Cells[i, (int)MAT.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdMatList_Sheet1.Cells[i, (int)MAT.MAT_VER].Value = dt.Rows[i]["MAT_VER"];
                    spdMatList_Sheet1.Cells[i, (int)MAT.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdMatList_Sheet1.Cells[i, (int)MAT.MAT_TYPE].Value = dt.Rows[i]["MAT_TYPE"];
                    spdMatList_Sheet1.Cells[i, (int)MAT.UNIT].Value = dt.Rows[i]["UNIT_1"];


                }
                MPCF.FitColumnHeader(spdMatList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //자재 기타 입고
        private bool EtcInInvLot()
        {
            TRSNode in_node = new TRSNode("etc_in_InvLot_In");
            TRSNode out_node = new TRSNode("etc_in_InvLot_Out");
            TRSNode Inv_Lot_list;
            bool send_flag = false;
            string sDirMSgYN = "N";

            try
            {
                if(s_raw_material_flag == true  && chkERP.Checked == false)
                //20230411 자재로는 안들어가게 막음. 무조건 WIP으로
                //20250512 양산 원자재는 MINVLOTSTS 테스트나 RND 자재는 MWIPLOTSTS
               // if(2==1)
                {

                    //원자재 수기 입력 하는거는 이슈가 좀 있어서 .일단 보류

                    //CMN609 INFO - 원재료 및 저장품은 수기입력이 불가능합니다.(관리자에 문의해주세요)
                    if (chkDirLot.Checked == true)
                    {
                        MPCF.ShowMsgBox(MPCF.GetMessage(609));
                        return false;
                    }



                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '2';
                    in_node.AddString("AREA_ID", cdvDept.Text);
                    in_node.AddChar("ERP_FLAG", chkERP.Checked == true ? 'N' : 'Y');
                    in_node.AddString("VENDOR_ID", s_vendor_id);
                    in_node.AddString("VENDOR_SITE_ID", s_vendor_site_id);
                    in_node.AddChar("LOT_INPUT_FLAG", chkDirLot.Checked == true ? 'N' : 'Y');
                    for (int i = 0; i < spdInvLotList_Sheet1.RowCount; i++)
                    {
                        if (spdInvLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE" && spdInvLotList_Sheet1.Cells[i, (int)LOT.CREATE_FLAG].Text =="N")
                        {
                            if (chkDirLot.Checked == true  && sDirMSgYN =="N")
                            {
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(572), MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.No)
                                {
                                    return false;
                                }
                                sDirMSgYN = "Y";

                                if (spdInvLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text.Trim().Length == 0)
                                {
                                    // CMN479 INFO -수기입력방식인경우 LotID를 지정해주셔야 합니다.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(479));
                                    return false;

                                }
                            }


                            /*
                            if(chkDirLot.Checked == true)
                            {

                                //20230215 수기입력시에는 일단 경고 메세지를 날려줌.
                                //미래에 채번되않은 LOT을 미리 채번을 한경우 시스템에 오류를 발생시킬수 있음을 경고 처리. 
                                //CMN571 INFO -수기로 입력한 LOT은 나중에 시스템에 전체적인 오류를 발생시킬수도 있습니다. 주의가 필요합니다.(진행하시겠습니까 ? Yes / No)
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(571), MessageBoxButtons.YesNo, 2) != System.Windows.Forms.DialogResult.No)
                                {
                                    return false;
                                }



                                if (spdInvLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text.Trim().Length == 0)
                                {
                                    // CMN479 INFO -수기입력방식인경우 LotID를 지정해주셔야 합니다.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(479));
                                    return false;
                                }


                            }
                            */

                            Inv_Lot_list = in_node.AddNode("INV_LOT_LIST");
                            Inv_Lot_list.AddString("INV_LOT_ID", spdInvLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text);
                            //그릿에서 제품lot id 채번으로 만들지 여부                             
                            Inv_Lot_list.AddChar("PROD_CHK", 'N');
                            Inv_Lot_list.AddDouble("QTY", MPCF.ToDbl(spdInvLotList_Sheet1.Cells[i, (int)LOT.QTY].Text));
                            Inv_Lot_list.AddDouble("QTY_2", 0);
                            Inv_Lot_list.AddDouble("QTY_3", 0);
                            Inv_Lot_list.AddString("SUB_AREA_ID", spdInvLotList_Sheet1.Cells[i, (int)LOT.SUB_AREA_ID].Text);
                            Inv_Lot_list.AddString("OPER", spdInvLotList_Sheet1.Cells[i, (int)LOT.OPER].Text);
                            Inv_Lot_list.AddString("MAT_ID", spdInvLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Text);
                            Inv_Lot_list.AddInt("MAT_VER", MPCF.ToInt(spdInvLotList_Sheet1.Cells[i, (int)LOT.MAT_VER].Text));
                            Inv_Lot_list.AddString("ARRIVAL_DATE", spdInvLotList_Sheet1.Cells[i, (int)LOT.ARRIVAL_DATE].Text);
                            Inv_Lot_list.AddString("IN_TYPE", spdInvLotList_Sheet1.Cells[i, (int)LOT.IN_TYPE].Text);
                            Inv_Lot_list.AddString("VENDOR_ID", spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_ID].Text);
                            Inv_Lot_list.AddString("VENDOR_SITE_ID", spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_SITE_ID].Text);
                            Inv_Lot_list.AddString("VENDOR_LOT_ID", spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_LOT_ID].Text);
                            Inv_Lot_list.AddString("COMMENT", spdInvLotList_Sheet1.Cells[i, (int)LOT.COMMENT].Text);
                            send_flag = true;
                        }
                    }

                    if (send_flag == false)
                    {
                        //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(109));
                        return false;
                    }

                    if (MPCR.CallService("CUS_INV", "CUS_INV_Create_Lot", in_node, ref out_node) == false)
                        return false;

                    MPCR.ShowSuccessMsg(out_node);

                    MPCF.ClearList(spdInvLotList);

                    // 생성 정보 출력
                    for (int i = 0; i < out_node.GetList(0).Count; i++)
                    {

                        spdInvLotList_Sheet1.RowCount++;

                        spdInvLotList_Sheet1.SetValue(i, (int)LOT.CHK, true);
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Value = out_node.GetList(0)[i].GetString("LOT_ID");
                        spdInvLotList_Sheet1.SetValue(i, (int)LOT.PROD_CHK, false);
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.SEQ].Value = out_node.GetList(0)[i].GetInt("SEQ");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.QTY].Value = out_node.GetList(0)[i].GetDouble("QTY");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = out_node.GetList(0)[i].GetString("UNIT");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.SUB_AREA_ID].Value = out_node.GetList(0)[i].GetString("SUB_AREA_ID");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.OPER].Value = out_node.GetList(0)[i].GetString("OPER");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Value = out_node.GetList(0)[i].GetString("OPER_DESC");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Value = out_node.GetList(0)[i].GetString("MAT_ID");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.MAT_VER].Value = out_node.GetList(0)[i].GetInt("MAT_VER");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = out_node.GetList(0)[i].GetString("MAT_DESC");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.ARRIVAL_DATE].Value = MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("ARRIVAL_DATE"), DATE_TIME_FORMAT.DATE);
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.IN_TYPE].Value = out_node.GetList(0)[i].GetString("IN_TYPE");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_ID].Value = out_node.GetList(0)[i].GetString("VENDOR_ID");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_SITE_ID].Value = out_node.GetList(0)[i].GetString("VENDOR_SITE_ID");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_LOT_ID].Value = out_node.GetList(0)[i].GetString("VENDOR_LOT_ID");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.CREATE_FLAG].Value = "Y";
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.COMMENT].Value = out_node.GetList(0)[i].GetString("COMMENT");


                    }
                }
                else
                {
                    MPCR.SetInMsg(in_node);
                    in_node.ProcStep = '1';
                    in_node.AddString("AREA_ID", cdvDept.Text);
                    in_node.AddChar("ERP_FLAG", chkERP.Checked == true ? 'N' : 'Y');

                    if (chkDirLot.Checked == true)
                    {
                        in_node.AddChar("LOT_INPUT_FLAG", 'Y');
                    }
                    else
                    {
                        in_node.AddChar("LOT_INPUT_FLAG", 'N');
                    }




                    for (int i = 0; i < spdInvLotList_Sheet1.RowCount; i++)
                    {
                        if (spdInvLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE" && spdInvLotList_Sheet1.Cells[i, (int)LOT.CREATE_FLAG].Text == "N")
                        {

                            if (chkDirLot.Checked == true && sDirMSgYN == "N")
                            {
                                //20230215 수기입력시에는 일단 경고 메세지를 날려줌.
                                //미래에 채번되않은 LOT을 미리 채번을 한경우 시스템에 오류를 발생시킬수 있음을 경고 처리. 
                                //CMN571 INFO -수기로 입력한 LOT은 나중에 시스템에 전체적인 오류를 발생시킬수도 있습니다. 주의가 필요합니다.(진행하시겠습니까 ? Yes / No)
                                if (MPCF.ShowMsgBox(MPCF.GetMessage(571), MessageBoxButtons.YesNo, 2) == System.Windows.Forms.DialogResult.No)
                                {
                                    return false;
                                }
                                else
                                {
                                    sDirMSgYN = "Y";
                                }

                                if (spdInvLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text.Trim().Length == 0)
                                {
                                    // CMN479 INFO -수기입력방식인경우 LotID를 지정해주셔야 합니다.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(479));
                                    return false;
                                }

                            }


                            Inv_Lot_list = in_node.AddNode("LOT_LIST");
                            Inv_Lot_list.AddString("LOT_ID", spdInvLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text.Trim());
                            //그릿에서 제품lot id 채번으로 만들지 여부 
                            if (cdvDept.Text == CSGV.gs_area_grit)
                            {
                                Inv_Lot_list.AddChar("PROD_CHK", (bool)spdInvLotList_Sheet1.Cells[i, (int)LOT.PROD_CHK].Value == true ? 'Y' : 'N');
                            }

                            Inv_Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdInvLotList_Sheet1.Cells[i, (int)LOT.QTY].Text));
                            Inv_Lot_list.AddString("SUB_AREA_ID", spdInvLotList_Sheet1.Cells[i, (int)LOT.SUB_AREA_ID].Text);
                            Inv_Lot_list.AddString("OPER", spdInvLotList_Sheet1.Cells[i, (int)LOT.OPER].Text);
                            Inv_Lot_list.AddString("MAT_ID", spdInvLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Text);
                            Inv_Lot_list.AddInt("MAT_VER", MPCF.ToInt(spdInvLotList_Sheet1.Cells[i, (int)LOT.MAT_VER].Text));
                            Inv_Lot_list.AddString("IN_TYPE", spdInvLotList_Sheet1.Cells[i, (int)LOT.IN_TYPE].Text);
                            Inv_Lot_list.AddString("COMMENT", spdInvLotList_Sheet1.Cells[i, (int)LOT.COMMENT].Text);


                            if (cdvOrderType.Text == "PROD" || cdvOrderType.Text.Trim() == "")
                            {
                                Inv_Lot_list.AddChar("LOT_TYPE", 'P');
                                Inv_Lot_list.AddString("OWNER_CODE", "PROD");
                                Inv_Lot_list.AddString("CREATE_CODE", "PROD");
                            }
                            else
                            {
                                Inv_Lot_list.AddChar("LOT_TYPE", 'T');
                                Inv_Lot_list.AddString("OWNER_CODE", "DEVE");
                                Inv_Lot_list.AddString("CREATE_CODE", cdvOrderType.Text);
                            }

                            send_flag = true;
                        }
                    }

                    if (send_flag == false)
                    {
                        //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                        MPCF.ShowMsgBox(MPCF.GetMessage(109));
                        return false;
                    }

                    if (MPCR.CallService("CUS_WIP", "CUS_WIP_Etc_In_Lot", in_node, ref out_node) == false)
                        return false;

                    MPCR.ShowSuccessMsg(out_node);

                    MPCF.ClearList(spdInvLotList);

                    // 생성 정보 출력
                    for (int i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        spdInvLotList_Sheet1.RowCount++;

                        spdInvLotList_Sheet1.SetValue(i, (int)LOT.CHK, true);
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Value = out_node.GetList(0)[i].GetString("LOT_ID");
                        spdInvLotList_Sheet1.SetValue(i, (int)LOT.PROD_CHK, false);
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.SEQ].Value = i + 1;
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.QTY].Value = out_node.GetList(0)[i].GetDouble("QTY");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.UNIT].Value = out_node.GetList(0)[i].GetString("UNIT");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.SUB_AREA_ID].Value = out_node.GetList(0)[i].GetString("SUB_AREA_ID");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.OPER].Value = out_node.GetList(0)[i].GetString("OPER");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.OPER_DESC].Value = out_node.GetList(0)[i].GetString("OPER_DESC");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.MAT_ID].Value = out_node.GetList(0)[i].GetString("MAT_ID");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.MAT_VER].Value = out_node.GetList(0)[i].GetInt("MAT_VER");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.MAT_DESC].Value = out_node.GetList(0)[i].GetString("MAT_DESC");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.ARRIVAL_DATE].Value = "";
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.IN_TYPE].Value = out_node.GetList(0)[i].GetString("IN_TYPE");
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_ID].Value = "";
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_SITE_ID].Value = "";
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.VENDOR_LOT_ID].Value = "";
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.CREATE_FLAG].Value = "Y";
                        spdInvLotList_Sheet1.Cells[i, (int)LOT.COMMENT].Value = out_node.GetList(0)[i].GetString("COMMENT");
                    
                    }
                }

                btnPrint_Click(null, null);

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
                        if (MPCF.Trim(cdvMatType.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMatType.Text + "]");
                            cdvMatType.Focus();
                            return false;
                        }

                        break;

                    case "PROCESS":
                        if (spdMatList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdInvLotList_Sheet1.RowCount == 0)
                        {
                            return false;
                        }

                        if (cdvLabelSize.Visible == true && MPCF.Trim(cdvLabelSize.Text) == "")
                        {
                            /*
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLableSize.Text + "]");
                            cdvLabelSize.Focus();
                            return false;
                            */
                        }

                        break;

                    case "ADD":
                        if (spdMatList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }
                        
                        if(chkERP.Checked == false)
                        {
                            if (MPCF.Trim(this.cdvInType.Text) == "")
                            {
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblInType.Text + "]");
                                cdvInType.Focus();
                                return false;
                            }
                        }

                        //if (MPCF.Trim(this.cdvToWorkPlace.Text) == "")
                        //{
                        //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                        //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToWorkPlace.Text + "]");
                        //    cdvToWorkPlace.Focus();
                        //    return false;
                        //}

                        if (MPCF.Trim(this.cdvToOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblToOper.Text + "]");
                            cdvToOper.Focus();
                            return false;
                        }

                        if (MPCF.Trim(this.txtTotalQty.Text) == "" || MPCF.ToDbl(this.txtTotalQty.Text) == 0)
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblTotalQty.Text + "]");
                            txtTotalQty.Focus();
                            return false;
                        }

                        if (MPCF.Trim(this.txtLotSize.Text) == "" || MPCF.ToDbl(this.txtLotSize.Text) == 0)
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotSize.Text + "]");
                            txtLotSize.Focus();
                            return false;
                        }

                        if(s_raw_material_flag == true)
                        {
                            if (MPCF.Trim(this.cdvVendorID.Text) == "")
                            {

                                cdvVendorID.Text = "0";
                                /*
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblVendorID.Text + "]");
                                cdvVendorID.Focus();
                                return false;
                                */
                            }

                            if (MPCF.Trim(this.txtVendorLotNo.Text) == "")
                            {
                                cdvVendorID.Text = "X";
                                /*
                                //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblVendorLotNo.Text + "]");
                                txtVendorLotNo.Focus();
                                return false;
                                */
                            }
                        }

                        break;

                    case "PRINT":
                        if (spdMatList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (spdInvLotList.ActiveSheet.RowCount == 0)
                        {
                            //CMN109 ERROR - Item이 선택되지 않았습니다. Item을 선택해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(109));
                            return false;
                        }

                        if (cdvLabelSize.Visible == true && MPCF.Trim( cdvLabelSize.Text) == "" )
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLableSize.Text + "]");
                            cdvLabelSize.Focus();
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

                        MPCF.ClearList(spdMatList);
                        MPCF.ClearList(spdInvLotList);
                        spdInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;

                        //this.cdvInType.Text = "";
                        //this.cdvVendorID.Text = "";
                        //this.cdvToWorkPlace.Text = "";
                        //this.cdvToOper.Text = "";
                        //this.dtpArrivalDate.Value = DateTime.Now;
                        //this.txtVendorLotNo.Text = "";
                        //this.txtTotalQty.Text = "";
                        //this.txtLotSize.Text = "";
                        //s_vendor_id = "";
                        //s_vendor_site_id = "";
                        break;
                        
                    case "ALL":

                        MPCF.ClearList(spdMatList);
                        MPCF.ClearList(spdInvLotList);
                        spdInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;
                        spdInvLotList.ActiveSheet.Columns[(int)LOT.PROD_CHK].Visible = false;

                        this.chkERP.Checked = false;
                        this.cdvInType.Enabled = true;
                        this.cdvDept.Text = "";
                        this.cdvMatType.Text = "";
                        this.cdvMatID.Text = "";
                        this.cdvInType.Text = "";
                        this.cdvVendorID.Text = "";
                        this.cdvToWorkPlace.Text = "";
                        this.cdvToOper.Text = "";
                        this.dtpArrivalDate.Value = DateTime.Now;
                        this.txtVendorLotNo.Text = "";
                        this.txtTotalQty.Text = "";
                        this.txtLotSize.Text = "";
                        this.txtMatDesc.Text = "";
                        this.txtComment.Text = "";
                        s_vendor_id = "";
                        s_vendor_site_id = "";
                        break;

                    case "MAT_CLICK":

                        MPCF.ClearList(spdInvLotList);
                        spdInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.CHK].Value = 0;
                        spdInvLotList.ActiveSheet.ColumnFooter.Cells[0, (int)LOT.QTY].Value = 0;

                        this.cdvInType.Text = "";
                        this.cdvVendorID.Text = "";
                        this.cdvToWorkPlace.Text = "";
                        this.cdvToOper.Text = "";
                        this.dtpArrivalDate.Value = DateTime.Now;
                        this.txtVendorLotNo.Text = "";
                        this.txtTotalQty.Text = "";
                        this.txtLotSize.Text = "";
                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 라벨 프린트
        public bool ViewPrintLabel()
        {
            try
            {
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                string file_name = "";

                MPCR.SetInMsg(in_node);


                if(cdvLabelSize.Text.Trim() == "")
                {
                    return true;
                }

                file_name = cdvLabelSize.Text;
                for (int i = 0; i < spdInvLotList_Sheet1.RowCount; i++)
                {
                    if (spdInvLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        label_list = in_node.AddNode("LOT_LIST");
                        label_list.AddString("LOT_ID", spdInvLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text);
                    }
                }

                CSCF.ViewLabelList(file_name, in_node);
                
                
                /*
                if (s_raw_material_flag == true)
                {
                    file_name = "mtl100p";
                    for (int i = 0; i < spdInvLotList_Sheet1.RowCount; i++)
                    {
                        if (spdInvLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                        {
                            label_list = in_node.AddNode("INV_LOT_LIST");
                            label_list.AddString("INV_LOT_ID", spdInvLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text);
                        }
                    }

                    CSCF.ViewLabelList(file_name, in_node, 'I');
                }
                else
                {
                    file_name = cdvLabelSize.Text;
                    for (int i = 0; i < spdInvLotList_Sheet1.RowCount; i++)
                    {
                        if (spdInvLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                        {
                            label_list = in_node.AddNode("LOT_LIST");
                            label_list.AddString("LOT_ID", spdInvLotList_Sheet1.Cells[i, (int)LOT.LOT_ID].Text);
                        }
                    }

                    CSCF.ViewLabelList(file_name, in_node);
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

        #endregion

        #region Event
        private void frmTranEtcInInvLot_Load(object sender, EventArgs e)
        {
            try
            {
                //그릿 사업부일 때 그릿 완제품 lot id 룰 체크 컬럼을 보이게 한다.
                if (cdvDept.Text == CSGV.gs_area_grit)
                {
                    spdInvLotList.ActiveSheet.Columns[(int)LOT.PROD_CHK].Visible = true;
                }
                else
                {
                    spdInvLotList.ActiveSheet.Columns[(int)LOT.PROD_CHK].Visible = false;
                }
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
                if (MPCF.Trim(cdvMatType.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMatType.Text + "]");
                    cdvMatType.Focus();
                    return;
                }

                // 제품 팝업으로 변경
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;
                popup.sType_id = cdvMatType.Text;
                popup.sType_desc = cdvMatType.DisplayText;

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

                ViewMaterialList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            double d_total_Qty = 0;
            double d_lot_Qty = 0;
            int beforeRowCount = 0;
            int currentRowCount = 0;
            int i_activeRow = 0;
            int i_lot_count = 0;

            try
            {
                if (CheckCondition("ADD") == false)
                    return;

                i_activeRow = spdMatList.ActiveSheet.ActiveRowIndex;

                beforeRowCount = spdInvLotList_Sheet1.RowCount;

                d_total_Qty = MPCF.ToDbl(this.txtTotalQty.Text);
                d_lot_Qty = MPCF.ToDbl(this.txtLotSize.Text);
                i_lot_count = (int)(d_total_Qty / MPCF.ToDbl(this.txtLotSize.Text));

                if (i_lot_count * MPCF.ToDbl(this.txtLotSize.Text) < d_total_Qty)
                {
                    i_lot_count++;
                }

                if (d_total_Qty <= 0)
                {
                    //CMN126 ERROR -입력한 값이 한계값을 넘었습니다.다른 수를 입력해 주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(126) + " [" + lblTotalQty.Text + "]");
                    txtTotalQty.Focus();
                    return;
                }

                for (int i = 0; i < i_lot_count; i++)
                {
                    spdInvLotList_Sheet1.RowCount++;

                    currentRowCount = spdInvLotList_Sheet1.RowCount - 1;
                    spdInvLotList_Sheet1.SetValue(currentRowCount, (int)LOT.CHK, true);
                    spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.LOT_ID].Value = "";
                    spdInvLotList_Sheet1.SetValue(currentRowCount, (int)LOT.PROD_CHK, false);
                    spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.SEQ].Value = spdInvLotList_Sheet1.RowCount;

                    if (spdInvLotList_Sheet1.RowCount == i_lot_count + beforeRowCount)
                    {
                        spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.QTY].Value = d_total_Qty.ToString();
                    }
                    else
                    {
                        spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.QTY].Value = d_lot_Qty.ToString();
                        d_total_Qty -= d_lot_Qty;
                    }

                    spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.UNIT].Value = spdMatList.ActiveSheet.Cells[i_activeRow, (int)MAT.UNIT].Text;
                    spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.SUB_AREA_ID].Value = cdvToWorkPlace.Text;
                    spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.OPER].Value = cdvToOper.Text;
                    spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.OPER_DESC].Value = "";
                    spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.MAT_ID].Value = spdMatList.ActiveSheet.Cells[i_activeRow, (int)MAT.MAT_ID].Text;
                    spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.MAT_VER].Value = spdMatList.ActiveSheet.Cells[i_activeRow, (int)MAT.MAT_VER].Text;
                    spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.MAT_DESC].Value = spdMatList.ActiveSheet.Cells[i_activeRow, (int)MAT.MAT_DESC].Text;
                    spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.ARRIVAL_DATE].Value = MPCF.DestroyDateFormat(dtpArrivalDate.Text, DATE_TIME_FORMAT.DATE);
                    spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.IN_TYPE].Value = cdvInType.Text;
                    spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.VENDOR_ID].Value = s_vendor_id;
                    spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.VENDOR_SITE_ID].Value = s_vendor_site_id;
                    spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.VENDOR_LOT_ID].Value = txtVendorLotNo.Text;
                    spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.CREATE_FLAG].Value = "N";
                    spdInvLotList_Sheet1.Cells[currentRowCount, (int)LOT.COMMENT].Value = txtComment.Text;
                }

/*
                if(chkDirLot.Checked == true) {
                    spdInvLotList_Sheet1.Columns[(int)LOT.LOT_ID].Locked = false;
                }
                else {
                    spdInvLotList_Sheet1.Columns[(int)LOT.LOT_ID].Locked = true;
                }

*/

                if (chkDirLot.Checked == true)
                {
                    spdInvLotList_Sheet1.Columns[(int)LOT.LOT_ID].Locked = false;


                    for (int i = 0; i < spdInvLotList_Sheet1.RowCount; i++)
                    {
                        spdInvLotList_Sheet1.Cells[i, 1].BackColor = Color.FromArgb(255, 198, 198);
                      //  spdInvLotList_Sheet1.Cells[i, 1].ForeColor = Color.FromArgb(255, 198, 198);
                    }
                }

                else
                {
                    spdInvLotList_Sheet1.Columns[(int)LOT.LOT_ID].Locked = true;

                    for (int i = 0; i < spdInvLotList_Sheet1.RowCount; i++)
                    {
                        spdInvLotList_Sheet1.Cells[i, 1].BackColor = Color.FromArgb(255, 255, 255);
                       // spdInvLotList_Sheet1.Cells[i, 1].ForeColor = Color.FromArgb(255, 255, 255);
                    }
                }

                MPCF.FitColumnHeader(spdInvLotList);

                CheckCount();
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
                for (int i = spdInvLotList_Sheet1.RowCount - 1; i >= 0; i--)
                {
                    if (spdInvLotList_Sheet1.Cells[i, (int)LOT.CHK].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (spdInvLotList_Sheet1.Cells[i, (int)LOT.CREATE_FLAG].Text == "Y")
                        {
                            continue;
                        }

                        spdInvLotList_Sheet1.RemoveRows(i, 1);
                    }
                }

                MPCF.FitColumnHeader(spdInvLotList);

                CheckCount();
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
                if (CheckCondition("PROCESS") == false)
                    return;

                if (EtcInInvLot())
                {
                    
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdMatList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            try
            {
                if (e.Row < 0)
                {
                    return;
                }

                if (e.ColumnHeader == true)
                {
                    return;
                }

                //ClearList("MAT_CLICK");

                for (int i = 0; i < spdMatList.ActiveSheet.RowCount; i++)
                {
                    spdMatList.ActiveSheet.Rows[i].BackColor = Color.FromArgb(255, 255, 255);
                }

                spdMatList.ActiveSheet.Rows[e.Row].BackColor = Color.FromArgb(255, 192, 255);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdInvLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
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

        private void cdvVendorID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopVendorList popup = new frmPopVendorList();
                popup.StartPosition = FormStartPosition.CenterParent;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvVendorID.Text = popup.g_VendorId;
                    this.cdvVendorID.DisplayText = popup.g_VendorDesc;
                    s_vendor_id = popup.g_VendorId;
                    s_vendor_site_id = popup.g_VendorSiteId;
                    popup = null;

                    MPCF.ClearList(spdInvLotList);
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

        private void cdvToWorkPlace_ButtonPress(object sender, EventArgs e)
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

                cdvToWorkPlace.Init();
                MPCF.InitListView(cdvToWorkPlace.GetListView);
                cdvToWorkPlace.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToWorkPlace.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToWorkPlace.SelectedSubItemIndex = 0;
                cdvToWorkPlace.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList_AREA(cdvToWorkPlace.GetListView, '1', MPGC.MP_RAS_SUBAREA_CODE, -1, null, "", true, -1, -1, null, cdvDept.Text) == false)
                {
                    return;
                }

                cdvToWorkPlace.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvToOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvToOper.Init();
                MPCF.InitListView(cdvToOper.GetListView);
                cdvToOper.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvToOper.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvToOper.SelectedSubItemIndex = 0;
                cdvToOper.DisplaySubItemIndex = 1;

                if (s_raw_material_flag == true)
                {
                    //자재 LOT - 자재창고, 위탁창고, 생산창고
                    if (COM_LIST.ViewOperationList(cdvToOper.GetListView, '3', cdvDept.Text, cdvToWorkPlace.Text, "", "", 'Y') == false)
                    {
                        return;
                    }
                }
                else
                {
                    //생산 LOT - 생산창고, 완제품 창고
                    if (COM_LIST.ViewOperationList(cdvToOper.GetListView, 'K', cdvDept.Text, cdvToWorkPlace.Text, "", "", 'Y') == false)
                    {
                        return;
                    }
                }   

                cdvToOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnPrint_Click(object sender, EventArgs e)
        {
            int i_activeRow = 0;
            try
            {
                if (CheckCondition("PRINT") == false)
                    return;

                i_activeRow = spdMatList.ActiveSheet.ActiveRowIndex;
                
                if (ViewPrintLabel())
                {
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMatType_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (string.Equals(cdvMatType.Text, "FINISHED_GOODS") 
                    || string.Equals(cdvMatType.Text, "SEMI_FINISHED")
                    || string.Equals(cdvMatType.Text, "OSP")
                    || string.Equals(cdvMatType.Text, "PROTO_TYPE"))
                {
                    s_raw_material_flag = false;
                    this.cdvVendorID.Visible = false;
                    this.lblVendorID.Visible = false;
                    this.dtpArrivalDate.Visible = false;
                    this.lblArrivalDate.Visible = false;
                    this.txtVendorLotNo.Visible = false;
                    this.lblVendorLotNo.Visible = false;
                    this.lblLableSize.Visible = true;
                    this.cdvLabelSize.Visible = true;
                }
                else
                {
                    s_raw_material_flag = true;
                    this.cdvVendorID.Visible = true;
                    this.lblVendorID.Visible = true;
                    this.dtpArrivalDate.Visible = true;
                    this.lblArrivalDate.Visible = true;
                    this.txtVendorLotNo.Visible = true;
                    this.lblVendorLotNo.Visible = true;
                    this.lblLableSize.Visible = false;
                    this.cdvLabelSize.Visible = true;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void chkERP_CheckedChanged(object sender, EventArgs e)
        {
            if (chkERP.Checked == true)
            {
                cdvInType.Text = "";
                cdvInType.Enabled = false;
                cdvOrderType.Enabled = true;
                cdvOrderType.Text = "RND";

                //실수 및 문제될  우려가 있어서 해당 로직 주의 사항 메세지 출력.(2021/07/08)..계속문제되면 해당기능 죽일예정
                MPCF.ShowMsgBox(MPCF.GetMessage(545));
            }
            else
            {
                cdvInType.Enabled = true;
                cdvOrderType.Enabled = false;
                cdvOrderType.Text = "";
            }
        }

        private void cdvLabelSize_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvLabelSize.Init();
                MPCF.InitListView(cdvLabelSize.GetListView);
                cdvLabelSize.Columns.Add("Size", 50, HorizontalAlignment.Left);
                cdvLabelSize.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvLabelSize.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvLabelSize.SelectedSubItemIndex = 2;
                cdvLabelSize.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewLabelGCMList(cdvLabelSize.GetListView, cdvDept.Text, CSGC.CP_LABEL_TYPE_OPER) == false)
                {
                    return;
                }

                cdvLabelSize.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {
                cdvLabelSize.Text = "";

                //그릿 사업부인 경우 완제품 lot 채번 생성 여부 체크 박스 보이게 한다.
                if (cdvDept.Text == CSGV.gs_area_grit)
                {
                    spdInvLotList.ActiveSheet.Columns[(int)LOT.PROD_CHK].Visible = true;
                }
                else
                {
                    spdInvLotList.ActiveSheet.Columns[(int)LOT.PROD_CHK].Visible = false;
                }
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

        private void cdvMatID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMatID.DisplayText == "")
                cdvMatID.Text = "";
        }

        private void cdvVendorID_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvVendorID.DisplayText == "")
                cdvVendorID.Text = "";
        }

        #endregion

        private void chkDirLot_CheckedChanged(object sender, EventArgs e)
        {
            if (chkDirLot.Checked == true)
            {
                spdInvLotList_Sheet1.Columns[(int)LOT.LOT_ID].Locked = false;


                for (int i = 0; i < spdInvLotList_Sheet1.RowCount; i++)
                {
                    spdInvLotList_Sheet1.Cells[i, 1].BackColor = Color.FromArgb(255, 198, 198);
                  //  spdInvLotList_Sheet1.Cells[i, 1].ForeColor = Color.FromArgb(255, 198, 198);
                }
            }

            else
            {
                spdInvLotList_Sheet1.Columns[(int)LOT.LOT_ID].Locked = true;

                for (int i = 0; i < spdInvLotList_Sheet1.RowCount; i++)
                {
                    spdInvLotList_Sheet1.Cells[i, 1].BackColor = Color.FromArgb(255, 255, 255);
                  //  spdInvLotList_Sheet1.Cells[i, 1].ForeColor = Color.FromArgb(255, 255, 255);
                }
            }
        }

        private void cdvOrderType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOrderType.Init();
                MPCF.InitListView(cdvOrderType.GetListView);
                cdvOrderType.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvOrderType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvOrderType.SelectedSubItemIndex = 0;
                cdvOrderType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvOrderType.GetListView, '1', MPGC.MP_WIP_CREATE_CODE) == false)
                    return;

                cdvOrderType.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}
