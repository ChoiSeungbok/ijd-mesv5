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

namespace CUS_BAS
{
    public partial class frmSetupRegisterCheckSheet : CUS_COM.frmTranForm01
    {
        public frmSetupRegisterCheckSheet()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum CHECKSHEET
        {
            SELECT,         // 1 : 선택
            SEQ,            // 2 : 순번
            CHK_COMMENT,    // 3 : 체크 항목
            CHK_UNIT        // 4 : 체크 단위
        }

        #endregion

        #region " Variable Definition "

        int checksheet_row = 0;
        string area_id = "";
        string subArea_id = "";
        string oper = "";
        string mat_id = "";

        #endregion

        #region " Function Definition "

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
        // 초기화
        private void ClearData()
        {
            try
            {
                checksheet_row = 0;

                MPCF.ClearList(spdCheckSheet);
            }
            catch(Exception ex)
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

                        if (MPCF.Trim(cdvOper.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                            cdvOper.Focus();
                            return false;
                        }

                        if (MPCF.Trim(cdvMat.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblMat.Text + "]");
                            cdvMat.Focus();
                            return false;
                        }

                        break;

                    case CSGC.CHECK.SAVE:
                        if (area_id == "" || subArea_id==""||oper==""||mat_id=="")
                        {
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

        //체크시트 조회
        private void ViewCheckSheet(string sArea, string aSubArea, string sOper, string sMat)
        {
            string sView_Id = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                sView_Id = "CBAS1002-001";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = aSubArea;

                dvcArgu[3].sCondition_ID = "OPER";
                dvcArgu[3].sCondition_Value = sOper;

                dvcArgu[4].sCondition_ID = "MAT_ID";
                dvcArgu[4].sCondition_Value = sMat;

                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                checksheet_row = dt.Rows.Count;

                for (i = 0; i < checksheet_row; i++)
                {
                    spdCheckSheet_Sheet1.RowCount++;

                    spdCheckSheet_Sheet1.SetValue(i, (int)CHECKSHEET.SELECT, true);
                    spdCheckSheet_Sheet1.Cells[i, (int)CHECKSHEET.SEQ].Value = dt.Rows[i]["SEQ"];
                    spdCheckSheet_Sheet1.Cells[i, (int)CHECKSHEET.CHK_COMMENT].Value = dt.Rows[i]["CHK_COMMENT"];
                    spdCheckSheet_Sheet1.Cells[i, (int)CHECKSHEET.CHK_UNIT].Value = dt.Rows[i]["CHK_UNIT"];                 
                }

                MPCF.FitColumnHeader(spdCheckSheet);
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //체크시트 저장
        private bool SaveCheckSheet()
        {
            TRSNode in_node = new TRSNode("Checksheet_In");
            TRSNode out_node = new TRSNode("Checksheet_Out");
            TRSNode check_list;

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';

                in_node.AddString("OPER", oper);
                in_node.AddString("MAT_ID", mat_id);

                for (int i = 0; i < spdCheckSheet.ActiveSheet.RowCount; i++)
                {
                    if (spdCheckSheet_Sheet1.Cells[i, (int)CHECKSHEET.SELECT].Text.ToString().ToUpper() == "TRUE")
                    {
                        if (CheckRow(i) == false)
                        {
                            return false;
                        }

                        check_list = in_node.AddNode("CHECK_LIST");
                        check_list.AddString("CHK_COMMENT", spdCheckSheet.ActiveSheet.Cells[i, (int)CHECKSHEET.CHK_COMMENT].Text);
                        check_list.AddString("CHK_UNIT", spdCheckSheet.ActiveSheet.Cells[i, (int)CHECKSHEET.CHK_UNIT].Text);
                    }
                }

                if (MPCR.CallService("CUS_BAS", "CUS_BAS_Register_Checksheet", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);
                return true;
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool CheckRow(int iRow)
        {
            try
            {
                if(MPCF.Trim(spdCheckSheet_Sheet1.Cells[iRow, (int)CHECKSHEET.CHK_COMMENT].Text)=="")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                    spdCheckSheet.ActiveSheet.SetActiveCell(iRow, (int)CHECKSHEET.CHK_COMMENT);
                    return false;
                }

                if (MPCF.Trim(spdCheckSheet_Sheet1.Cells[iRow, (int)CHECKSHEET.CHK_UNIT].Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108));
                    spdCheckSheet.ActiveSheet.SetActiveCell(iRow, (int)CHECKSHEET.CHK_UNIT);
                    return false;
                }

                return true;
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }            
        }

        #endregion


        private void cdvMat_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                frmPopMaterialList popup = new frmPopMaterialList();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.sArea_id = cdvDept.Text;
                popup.sArea_desc = cdvDept.DisplayText;

                if (popup.ShowDialog() == DialogResult.OK)
                {
                    this.cdvMat.Text = popup.sMat_id;
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
      
        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            int iRow = spdCheckSheet_Sheet1.RowCount;

            try
            {
                spdCheckSheet_Sheet1.RowCount++;
                spdCheckSheet_Sheet1.SetValue(iRow, (int)CHECKSHEET.SELECT, true);
                spdCheckSheet_Sheet1.Cells[iRow, (int)CHECKSHEET.SEQ].Value = iRow + 1;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnRowDel_Click(object sender, EventArgs e)
        {
            int iRow = 0;
            try
            {
                iRow = spdCheckSheet_Sheet1.RowCount - 1;

                if (iRow < 0) return;

                if (spdCheckSheet_Sheet1.Cells[iRow, (int)CHECKSHEET.SELECT].Text.ToString().ToUpper() == "TRUE")
                {
                    if(iRow >= checksheet_row)
                    {
                        spdCheckSheet_Sheet1.RemoveRows(iRow, 1);
                    }    
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

                ClearData();

                area_id = cdvDept.Text;
                subArea_id = cdvWorkPlace.Text;
                oper = cdvOper.Text;
                mat_id = cdvMat.Text;

                ViewCheckSheet(area_id, subArea_id, oper, mat_id);
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

                if(SaveCheckSheet())
                {
                    ClearData();
                    ViewCheckSheet(area_id, subArea_id, oper, mat_id);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvMat_TextBoxTextChanged(object sender, EventArgs e)
        {
            if (cdvMat.DisplayText == "")
                cdvMat.Text = "";
        }
    }
}
