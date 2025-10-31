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
using FarPoint.Win.Spread;
using FarPoint.Excel;

//CWIP2035
namespace CUS_WIP
{
    public partial class frmTranChangeTestLotProdLot : CUS_COM.frmTranForm06
    {
        public frmTranChangeTestLotProdLot()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT_INFO : int
        {
            CHECK,                      // 1 : 선택
            LOT_ID,                     // 2 : LOT ID
            JUDGMENT,                   //판정
            JUDGMENT_DESC,
            MAT_ID,                     // 3 : 품목코드
            MAT_DESC,                   // 4 : 품목명
            MAT_TYPE,                   // 5 : 품목유형
            QTY,                        // 6 : 수량
            UNIT,                       // 7 : 단위
            OPER_DESC,                  // 8 : 창고명
            CREATE_CODE_DESC,           // 
            TO_CREATE_CODE,             //             
            TO_CREATE_CODE_DESC,        // 
            TO_CREATE_CODE_SELECT,      // 
            CHANGE_LOT                  // 
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
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;

                btnPrint.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                cdvLabel.Anchor = AnchorStyles.Top | AnchorStyles.Left;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void ViewLotList(int iSearchType)
        {
            try
            {
                if (iSearchType == 2)
                {
                    if (txtLotID.Text.Trim() == "")
                    {
                        return;
                    }
                }





                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int i = 0;
                string sOverlap_check = "N";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvOper.Text;

                dvcArgu[4].sCondition_ID = "CREATE_CODE";
                dvcArgu[4].sCondition_Value = cdvOrderType.Text;

                dvcArgu[5].sCondition_ID = "MAT_ID";
                dvcArgu[5].sCondition_Value = "%" + cdvMatId.Text + "%";


                if (iSearchType == 2)
                {
                    dvcArgu[6].sCondition_ID = "LOT_ID";
                    dvcArgu[6].sCondition_Value = txtLotID.Text;
                }
                else
                {
                    dvcArgu[6].sCondition_ID = "LOT_ID";
                    dvcArgu[6].sCondition_Value = txtLotID.Text + "%";
                }

                if (TPDR.GetDataOne("", ref dt, "CWIP2035-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    if (iSearchType != 2)
                    {
                        MPCF.ClearList(spdLotList);
                    }

                    return;
                }



                if (iSearchType == 2)
                {

                    for (i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text == dt.Rows[0]["LOT_ID"].ToString())
                        {
                            spdLotList.ActiveSheet.SetValue(i, (int)LOT_INFO.CHECK, true);
                            sOverlap_check = "Y";
                        }
                    }

                    if (sOverlap_check == "N")
                    {

                        spdLotList.ActiveSheet.RowCount++;
                        spdLotList.ActiveSheet.SetValue(spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.CHECK, true);
                        spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.LOT_ID].Value = dt.Rows[0]["LOT_ID"];
                        spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.JUDGMENT].Value = dt.Rows[0]["JUDGMENT"];
                        spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.JUDGMENT_DESC].Value = dt.Rows[0]["JUDGMENT_DESC"];
                        spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.MAT_ID].Value = dt.Rows[0]["MAT_ID"];
                        spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[0]["MAT_DESC"];
                        spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.MAT_TYPE].Value = dt.Rows[0]["MAT_TYPE"];
                        spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.QTY].Value = dt.Rows[0]["QTY"];
                        spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.UNIT].Value = dt.Rows[0]["UNIT"];
                        spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.OPER_DESC].Value = dt.Rows[0]["OPER_DESC"];
                        spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.CREATE_CODE_DESC].Value = dt.Rows[0]["CREATE_CODE_DESC"];
                        //spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.TO_CREATE_CODE].Value = dt.Rows[i]["TO_CREATE_CODE"];
                        //spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.TO_CREATE_CODE].Value = "";
                        //spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.TO_CREATE_CODE_DESC].Value = dt.Rows[i]["TO_CREATE_CODE_DESC"];
                        //spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.TO_CREATE_CODE_DESC].Value = "";


                        //20210726 양산품으로 고정 변경되도록 변경.
                        spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.TO_CREATE_CODE].Value = "PROD";
                        spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.TO_CREATE_CODE_DESC].Value = "Product Lot";
                        spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.CHANGE_LOT].Value = dt.Rows[0]["CHANGE_LOT"];

                    }

                }
                else
                {


                    MPCF.ClearList(spdLotList);

                    for (i = 0; i < dt.Rows.Count; i++)
                    {
                        spdLotList.ActiveSheet.RowCount++;
                        spdLotList.ActiveSheet.SetValue(i, (int)LOT_INFO.CHECK, false);
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.JUDGMENT].Value = dt.Rows[i]["JUDGMENT"];
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.JUDGMENT_DESC].Value = dt.Rows[i]["JUDGMENT_DESC"];
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_TYPE].Value = dt.Rows[i]["MAT_TYPE"];
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.QTY].Value = dt.Rows[i]["QTY"];
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.UNIT].Value = dt.Rows[i]["UNIT"];
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CREATE_CODE_DESC].Value = dt.Rows[i]["CREATE_CODE_DESC"];
                        //spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.TO_CREATE_CODE].Value = dt.Rows[i]["TO_CREATE_CODE"];
                        //spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.TO_CREATE_CODE].Value = "";
                        //spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.TO_CREATE_CODE_DESC].Value = dt.Rows[i]["TO_CREATE_CODE_DESC"];
                        //spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.TO_CREATE_CODE_DESC].Value = "";


                        //20210726 양산품으로 고정 변경되도록 변경.
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.TO_CREATE_CODE].Value = "PROD";
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.TO_CREATE_CODE_DESC].Value = "Product Lot";
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHANGE_LOT].Value = dt.Rows[i]["CHANGE_LOT"];

                    }

                    MPCF.FitColumnHeader(spdLotList);
                }

                lblSaveYn.Text = "N";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool SaveType()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode lot_list;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1';
                in_node.AddString("COMMENT", txtComment.Text);

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHECK].Value.ToString().ToUpper() == "TRUE")
                    {
                        lot_list = in_node.AddNode("LOT_LIST");

                        lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                        lot_list.AddString("TO_CREATE_CODE", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.TO_CREATE_CODE].Text);
                    }
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Change_Test_Prod_Lot", in_node, ref out_node) == false)
                {
                    return false;
                }
                else
                {
                    MPCR.ShowSuccessMsg(out_node);
                }


                lblSaveYn.Text = "Y";
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
            int iCheckCount = 0;

            try
            {
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }
                /*
                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return false;
                }
                */

                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return false;
                }



                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        break;


                    case CSGC.CHECK.SAVE:

                        for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                        {
                            if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHECK].Value.ToString().ToUpper() == "TRUE")
                            {
                                if (MPCF.Trim(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.TO_CREATE_CODE].Value.ToString().ToUpper()) == "")
                                {
                                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOrderType.Text + "]");
                                    return false;
                                }


                                //if (cdvDept.Text == CSGC.CP_AREA_CTM)
                                if (cdvDept.Text == "CTM") //한국 CTM만
                                {

                                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.JUDGMENT].Text != "P" && spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.JUDGMENT].Text != "S")
                                    {

                                        //CMN 585 INFO - 합격 혹은 특채 판정만 양산품 전환 가능합니다.
                                        MPCF.ShowMsgBox(MPCF.GetMessage(585));

                                        /*
                                        MPCF.ShowMsgBox("CMN585 INFO - 합격 혹은 특채 판정만 양산품 전환 가능합니다.");
                                        return false;
                                        */
                                    }
                                }

                                iCheckCount++;
                            }
                        }

                        if (iCheckCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305));
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

        private void PrintLable(string sPrintLabel)
        {
            try
            {


                if (sPrintLabel == "")
                {

                    //CMN519 INFO - 라벨종류를 선택하지 않았습니다. 라벨 종류를 선택하세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(519));
                    return;
                }

                TRSNode print_node = new TRSNode("Print_In");
                TRSNode Print_Lot_list;
                MPCR.SetInMsg(print_node);

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {


                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Value != spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHANGE_LOT].Value && lblSaveYn.Text == "N")
                    {
                        MPCF.ShowMsgBox("해당창고는 저장후 조회 가능합니다.");
                        return;
                    }

                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHECK].Value.ToString().ToUpper() == "TRUE")
                    {
                        Print_Lot_list = print_node.AddNode("LOT_LIST");
                        Print_Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHANGE_LOT].Text);

                        // Print_Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                    }
                }

                CSCF.ViewLabelList(sPrintLabel, print_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }



        private void searchLot()
        {
            try
            {

                if (spdLotList.ActiveSheet.RowCount == 0)
                {
                    lblSaveYn.Text = "N";
                }

                if (lblSaveYn.Text == "Y")
                {
                    MPCF.ShowMsgBox(MPCF.GetMessage(550));
                }

                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[7];
                DataTable dt = null;
                string sSql = "";
                int i = 0;


                for (i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Value.ToString() == txtLotID.Text)
                    {
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHECK].Value = true;
                        return;
                    }
                }

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = cdvWorkPlace.Text;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = cdvOper.Text;

                dvcArgu[4].sCondition_ID = "CREATE_CODE";
                dvcArgu[4].sCondition_Value = cdvOrderType.Text;

                dvcArgu[5].sCondition_ID = "MAT_ID";
                dvcArgu[5].sCondition_Value = "%" + cdvMatId.Text + "%";

                dvcArgu[6].sCondition_ID = "LOT_ID";
                dvcArgu[6].sCondition_Value = txtLotID.Text + "%";

                if (TPDR.GetDataOne("", ref dt, "CWIP2035-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();
                    return;
                }


                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList.ActiveSheet.RowCount++;
                    spdLotList.ActiveSheet.SetValue(spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.CHECK, true);
                    spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.MAT_TYPE].Value = dt.Rows[i]["MAT_TYPE"];
                    spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.UNIT].Value = dt.Rows[i]["UNIT"];
                    spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.OPER_DESC].Value = dt.Rows[i]["OPER_DESC"];
                    spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.CREATE_CODE_DESC].Value = dt.Rows[i]["CREATE_CODE_DESC"];
                    //spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.TO_CREATE_CODE].Value = dt.Rows[i]["TO_CREATE_CODE"];
                    //spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.TO_CREATE_CODE].Value = "";
                    //spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.TO_CREATE_CODE_DESC].Value = dt.Rows[i]["TO_CREATE_CODE_DESC"];
                    //spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.TO_CREATE_CODE_DESC].Value = "";


                    //20210726 양산품으로 고정 변경되도록 변경.
                    spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.TO_CREATE_CODE].Value = "PROD";
                    spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.TO_CREATE_CODE_DESC].Value = "Product Lot";
                    spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.RowCount - 1, (int)LOT_INFO.CHANGE_LOT].Value = dt.Rows[i]["CHANGE_LOT"];

                }

                lblSaveYn.Text = "N";

                MPCF.FitColumnHeader(spdLotList);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        #endregion

        #region " Event Definition "

        private void frmTranChangeTestLotProdLot_Load(object sender, EventArgs e)
        {
            try
            {

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
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return;
                }

                cdvOper.Init();
                MPCF.InitListView(cdvOper.GetListView);
                cdvOper.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOper.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOper.SelectedSubItemIndex = 0;
                cdvOper.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewOperationList(cdvOper.GetListView, 'K', cdvDept.Text, cdvWorkPlace.Text, "", "", 'Y') == false)
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

        private void cdvOrderType_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvOrderType.Init();
                MPCF.InitListView(cdvOrderType.GetListView);
                cdvOrderType.Columns.Add("Operation", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOrderType.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvOrderType.SelectedSubItemIndex = 0;
                cdvOrderType.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvOrderType.GetListView, '1', MPGC.MP_WIP_CREATE_CODE) == false)
                    return;

                //양산품은 뺀다.
                for (int i = cdvOrderType.GetListView.Items.Count; i > 0; i--)
                {
                    if (cdvOrderType.GetListView.Items[i - 1].SubItems[0].Text == "PROD")
                    {
                        cdvOrderType.GetListView.Items[i - 1].Remove();
                    }
                }

                cdvOrderType.InsertEmptyRow(0, 1);
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
                popup.Width = 900;
                popup.Height = 500;
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
                if (e.Column == (int)LOT_INFO.TO_CREATE_CODE_SELECT)
                {
                    cdvGridButton1.Init();
                    MPCF.InitListView(cdvGridButton1.GetListView);
                    cdvGridButton1.Columns.Add("Code", 50, System.Windows.Forms.
                        HorizontalAlignment.Left);
                    cdvGridButton1.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);

                    if (BASLIST.ViewGCMDataList(cdvGridButton1.GetListView, '1', MPGC.MP_WIP_CREATE_CODE) == false)
                        return;

                    //양산품만 보이도록 한다
                    for (int i = cdvGridButton1.GetListView.Items.Count; i > 0; i--)
                    {
                        if (cdvGridButton1.GetListView.Items[i - 1].SubItems[0].Text != "PROD")
                        {
                            cdvGridButton1.GetListView.Items[i - 1].Remove();
                        }
                    }

                    cdvGridButton1.ShowPopupList(e.Row, e.Column);
                    cdvGridButton1.AddEmptyRow(1);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvGridButton1_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (spdLotList.ActiveSheet.ActiveColumnIndex == (int)LOT_INFO.TO_CREATE_CODE_SELECT)
                {
                    spdLotList.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.TO_CREATE_CODE, e.SelectedItem.SubItems[0].Text);
                    spdLotList.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.TO_CREATE_CODE_DESC, e.SelectedItem.SubItems[1].Text);

                    spdLotList.ActiveSheet.SetValue(e.Row, (int)LOT_INFO.CHECK, true);
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
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewLotList(1);
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

                if (SaveType() == true)
                {

                    //저장후 그냥 상태 그냥 나두는걸로.
                    /*
                    if(cdvLabel.Text != "")
                    {
                        PrintLable(cdvLabel.Text);
                    }

                    if (MPCF.ShowMsgBox(MPCF.GetMessage(549), MessageBoxButtons.YesNo, 1) == System.Windows.Forms.DialogResult.No)
                    {
                        return;
                    }
                    else
                    {
                        ViewLotList();
                    }

                    */
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            int i = 0;
            SheetView sv = spdLotList.ActiveSheet;

            if (sv.Rows.Count == 0)
            {
                return;
            }

            if (e.Row >= 0 && Convert.ToBoolean(sv.Cells[e.Row, (int)LOT_INFO.CHECK] == null ? false : sv.Cells[e.Row, (int)LOT_INFO.CHECK].Value))
            {
                sv.Cells[e.Row, (int)LOT_INFO.CHECK].Value = true;

            }
            else
            {

            }



            if (e.ColumnHeader == false)
            {
                return;
            }

            if (e.Column != 0)
            {
                return;
            }
            bool allChecked = false;
            if (sv.ColumnHeader.Cells[0, 0].Value == null || Convert.ToBoolean(sv.ColumnHeader.Cells[0, 0].Value == null ? false : sv.ColumnHeader.Cells[0, 0].Value) == false)
            {
                allChecked = false;
            }
            else
            {
                allChecked = true;
            }

            if (allChecked == true)
            {
                for (i = 0; i < sv.RowCount; i++)
                {
                    sv.Cells[i, 0].Value = false;
                }

                sv.ColumnHeader.Cells[0, 0].Value = false;
            }
            else
            {
                for (i = 0; i < sv.RowCount; i++)
                {
                    sv.Cells[i, 0].Value = true;
                }
                sv.ColumnHeader.Cells[0, 0].Value = true;
            }


        }

        public void btnPrint_Click(object sender, EventArgs e)
        {
            PrintLable(cdvLabel.Text);
        }

        private void cdvLabel_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvLabel.Init();
                MPCF.InitListView(cdvLabel.GetListView);
                cdvLabel.Columns.Add("Size", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvLabel.Columns.Add("Desc", 100, System.Windows.Forms.HorizontalAlignment.Left);
                cdvLabel.Columns.Add("Code", 50, System.Windows.Forms.HorizontalAlignment.Left);
                cdvLabel.SelectedSubItemIndex = 2;
                cdvLabel.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewLabelGCMList(cdvLabel.GetListView, cdvDept.Text, CSGC.CP_LABEL_TYPE_OPER) == false)
                {
                    return;
                }

                cdvLabel.InsertEmptyRow(0, 1);
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
                    searchLot();
                    txtLotID.Text = "";
                    txtLotID.Focus();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_Change(object sender, ChangeEventArgs e)
        {

        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            MPCF.ClearList(spdLotList);
            lblSaveYn.Text = "N";
        }

        private void txtLotID_KeyPress_1(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    ViewLotList(2);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion





        /*
        private void chkBackColor(int i)
        {

            if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHECK].Value.ToString().ToUpper() == "TRUE")
            {
                spdLotList.ActiveSheet.Rows[i].BackColor = Color.WhiteSmoke;
            }
            else
            {
                spdLotList.ActiveSheet.Rows[i].BackColor = Color.White;
            }
        }
        */

    }
}
