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
using System.Drawing.Drawing2D;
using System.Drawing.Imaging;
using Miracom.CliFrx;
using Miracom.DNMCore;
using System.Threading;

namespace CUS_WIP
{
    public partial class frmTranNonOperationBAK : CUS_COM.frmTranForm03
    {
        #region ""
        public frmTranNonOperationBAK()
        {
            InitializeComponent();
            InitControl();
        }
        #endregion


        #region " Variable Definition "



        #endregion

        #region " Function Definition "


        private void InitControl()
        {
            try
            {

                lblLv1.Text = "";
                lblLv1.Tag = "";
                lblLv2.Text = "";
                lblLv2.Tag = "";
                lblLv3.Text = "";
                lblLv3.Tag = "";
                lblsession1.Text = "";
                lblsession2.Text = "";
                txtResStatus.Text = "";
                lblHistSeq.Text = "";
                lblSeq.Text = "";
                lblPath.Text = "L1";


                dtpDownStartTime.Value = DateTime.Now;
                dtpDownEndTime.Value = DateTime.Now;

                lblPath.Anchor = AnchorStyles.Top | AnchorStyles.Left;
                lblHistSeq.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblSeq.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                lblDownStartTime.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
                lblDownEndTime.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
                dtpDownStartTime.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
                dtpDownEndTime.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
                chkEditDate.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
                txtResStatus.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;
                chkTimer.Anchor = AnchorStyles.Bottom | AnchorStyles.Left;


                dtpDownStartTime.Enabled = false;
                dtpDownEndTime.Enabled = false;

                chkEditDate.Checked = false;
                chkTimer.Checked = false;
                tmrTimer.Start();



                lblDownStartTime.Visible = false;
                lblDownEndTime.Visible = false;
                dtpDownStartTime.Visible = false;
                dtpDownEndTime.Visible = false;
                chkEditDate.Visible = false;
                btnNonStart.Visible = false;
                btnNonEnd.Visible = false;
                btnBack.Visible = false;


                //MPCF.FitColumnHeader(SpdSpareList);
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
                        if (string.IsNullOrEmpty(lblLv2.Text) == true)
                        {
                            MPCF.ShowMsgBox("설비입력은 필수입니다.");
                            return false;
                        }
                        break;
                    case CSGC.CHECK.START:

                        if (View_Res_Id('2') == false)
                        {
                            return false;
                        };

                        break;
                    case CSGC.CHECK.END:

                        if (View_Res_Id('3') == false)
                        {
                            return false;
                        };

                        break;
                    case CSGC.CHECK.ADD:

                        break;
                    case CSGC.CHECK.DELETE:

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

        private bool View_Res_Id(char c_ProcStep)

        {

            string sView_Id = "";

            switch (c_ProcStep)
            {
                case '1':

                    // 일반조회
                    try
                    {

                        //TPDR.GetDataOne 다이렉트 쿼리
                        TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                        DataTable dt = null;
                        string sSql = "";

                        sView_Id = "CWIP2005-001"; //쿼리번호(뷰아이디)

                        dvcArgu[0].sCondition_ID = "FACTORY"; //조건코드
                        dvcArgu[0].sCondition_Value = MPGV.gsFactory; //값


                        dvcArgu[1].sCondition_ID = "RES_ID"; //조건코드
                        dvcArgu[1].sCondition_Value = cdvResource.Text; //값

                        dvcArgu[2].sCondition_ID = "AREA_ID"; //조건코드
                        dvcArgu[2].sCondition_Value = cdvDept.Text; //값

                        dvcArgu[3].sCondition_ID = "SUB_AREA_ID"; //조건코드
                        dvcArgu[3].sCondition_Value = cdvWorkPlace.Text; //값

                        dvcArgu[4].sCondition_ID = "OPER"; //조건코드
                        dvcArgu[4].sCondition_Value = cdvOper.Text; //값

                        // MPCF.ClearList(spdNonOper);
                        if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                        {
                        }
                        if (dt.Rows.Count == 0)
                        {
                            //cdvDept.Text = dt.Rows[0]["AREA_ID"].ToString();
                            //cdvWorkPlace.Text = dt.Rows[0]["SUB_AREA_ID"].ToString();
                            //cdvOper.Text = dt.Rows[0]["OPER"].ToString();
                            txtResStatus.Text = "가동중";
                            txtResStatus.Tag = "E";
                            lblHistSeq.Text = "";
                            lblSeq.Text = "";

                            dtpDownStartTime.Value = DateTime.Now;
                            dtpDownEndTime.Text = null;
                            dtpDownStartTime.Enabled = false;
                            dtpDownEndTime.Enabled = false;
                            chkEditDate.Checked = false;

                            dt.Dispose();
                            GC.Collect();
                        }
                        else
                        {
                            //cdvDept.Text = dt.Rows[0]["AREA_ID"].ToString();
                            //cdvWorkPlace.Text = dt.Rows[0]["SUB_AREA_ID"].ToString();
                            //cdvOper.Text = dt.Rows[0]["OPER"].ToString();
                            txtResStatus.Text = dt.Rows[0]["DOWN_TYPE_3_DIS"].ToString();
                            txtResStatus.Tag = dt.Rows[0]["DOWN_TYPE_3"].ToString();
                            lblHistSeq.Text = dt.Rows[0]["HIST_SEQ"].ToString();
                            lblSeq.Text = dt.Rows[0]["SEQ"].ToString();


                            if (string.IsNullOrEmpty(dt.Rows[0]["DOWN_START_TIME"].ToString()) == true)
                            {
                                dtpDownStartTime.Value = DateTime.Now;
                            }
                            else
                            {

                                //  MPCF.ToDate(out_node.GetString("APPLY_START_TIME"));
                                dtpDownStartTime.Value = MPCF.ToDate(dt.Rows[0]["DOWN_START_TIME"].ToString());
                                // dtpDownStartTime.Value = Convert.ToDateTime(dt.Rows[0]["DOWN_START_TIME"].ToString());

                            }


                            if (string.IsNullOrEmpty(dt.Rows[0]["DOWN_END_TIME"].ToString()) == true)
                            {
                                dtpDownEndTime.Value = DateTime.Now;
                            }
                            else
                            {
                                dtpDownEndTime.Value = MPCF.ToDate(dt.Rows[0]["DOWN_END_TIME"].ToString());
                                //   dtpDownEndTime.Value = Convert.ToDateTime(dt.Rows[0]["DOWN_END_TIME"].ToString());
                            }

                            dtpDownStartTime.Enabled = false;
                            dtpDownEndTime.Enabled = false;
                            chkEditDate.Checked = false;

                            dt.Dispose();
                            GC.Collect();
                        }
                    }
                    catch (Exception ex)
                    {
                        MPCF.ShowMsgBox(ex.Message);
                        return false;
                    }
                    break;
                case '2':

                    // START
                    try
                    {

                        if (string.IsNullOrEmpty(lblLv3.Tag.ToString()) == true)
                        {
                            MPCF.ShowMsgBox("비가동 TYPE이 전부 입력되지않았습니다.");
                            return false;
                        }

                        //TPDR.GetDataOne 다이렉트 쿼리
                        TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                        DataTable dt = null;
                        string sSql = "";

                        sView_Id = "CWIP2005-001"; //쿼리번호(뷰아이디)

                        dvcArgu[0].sCondition_ID = "FACTORY"; //조건코드
                        dvcArgu[0].sCondition_Value = MPGV.gsFactory; //값


                        dvcArgu[1].sCondition_ID = "RES_ID"; //조건코드
                        dvcArgu[1].sCondition_Value = cdvResource.Text; //값

                        dvcArgu[2].sCondition_ID = "AREA_ID"; //조건코드
                        dvcArgu[2].sCondition_Value = cdvDept.Text; //값

                        dvcArgu[3].sCondition_ID = "SUB_AREA_ID"; //조건코드
                        dvcArgu[3].sCondition_Value = cdvWorkPlace.Text; //값

                        dvcArgu[4].sCondition_ID = "OPER"; //조건코드
                        dvcArgu[4].sCondition_Value = cdvOper.Text; //값

                        // MPCF.ClearList(spdNonOper);
                        if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                        {
                        }
                        if (dt.Rows.Count == 0)
                        {
          
                        }
                        else
                        {
                            

                            txtResStatus.Text = dt.Rows[0]["DOWN_TYPE_3_DIS"].ToString();
                            txtResStatus.Tag = dt.Rows[0]["DOWN_TYPE_3"].ToString();
                            lblHistSeq.Text = dt.Rows[0]["HIST_SEQ"].ToString();
                            lblSeq.Text = dt.Rows[0]["SEQ"].ToString();

                            dtpDownStartTime.Enabled = false;
                            dtpDownEndTime.Enabled = false;
                            chkEditDate.Checked = false;

                            dt.Dispose();
                            GC.Collect();
                        }
                    }
                    catch (Exception ex)
                    {
                        MPCF.ShowMsgBox(ex.Message);
                        return false;
                    }
                    break;
                case '3':

                    // END
                    try
                    {

                        //TPDR.GetDataOne 다이렉트 쿼리
                        TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                        DataTable dt = null;
                        string sSql = "";

                        sView_Id = "CWIP2005-001"; //쿼리번호(뷰아이디)

                        dvcArgu[0].sCondition_ID = "FACTORY"; //조건코드
                        dvcArgu[0].sCondition_Value = MPGV.gsFactory; //값


                        dvcArgu[1].sCondition_ID = "RES_ID"; //조건코드
                        dvcArgu[1].sCondition_Value = cdvResource.Text; //값

                        dvcArgu[2].sCondition_ID = "AREA_ID"; //조건코드
                        dvcArgu[2].sCondition_Value = cdvDept.Text; //값

                        dvcArgu[3].sCondition_ID = "SUB_AREA_ID"; //조건코드
                        dvcArgu[3].sCondition_Value = cdvWorkPlace.Text; //값

                        dvcArgu[4].sCondition_ID = "OPER"; //조건코드
                        dvcArgu[4].sCondition_Value = cdvOper.Text; //값

                        // MPCF.ClearList(spdNonOper);
                        if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                        {
                        }
                        if (dt.Rows.Count == 0)
                        {

                        }
                        else
                        {
                            if (dtpDownEndTime.Value < MPCF.ToDate(dt.Rows[0]["DOWN_START_TIME"].ToString()))
                            {
                                MPCF.ShowMsgBox("시각시간보다 종료시간이 빠를수 없습니다.");
                                return false;
                            }

                            txtResStatus.Text = dt.Rows[0]["DOWN_TYPE_3_DIS"].ToString();
                            txtResStatus.Tag = dt.Rows[0]["DOWN_TYPE_3"].ToString();
                            lblHistSeq.Text = dt.Rows[0]["HIST_SEQ"].ToString();
                            lblSeq.Text = dt.Rows[0]["SEQ"].ToString();

                            dtpDownStartTime.Enabled = false;
                            dtpDownEndTime.Enabled = false;
                            chkEditDate.Checked = false;

                            dt.Dispose();
                            GC.Collect();
                        }
                    }
                    catch (Exception ex)
                    {
                        MPCF.ShowMsgBox(ex.Message);
                        return false;
                    }
                    break;
            }
            return true;
        }



        private void Update_Non_Operation(char c_ProcStep)
        {

            try
            {

                if (c_ProcStep == MPGC.MP_STEP_CREATE)
                {
                    if (CheckCondition(CSGC.CHECK.START) == false)
                    {
                        return;
                    }
                }
                else if (c_ProcStep == MPGC.MP_STEP_UPDATE)
                {
                    if (CheckCondition(CSGC.CHECK.END) == false)
                    {
                        return;
                    }
                }

                TRSNode in_node = new TRSNode("Update_Spare_In");
                TRSNode out_node = new TRSNode("Update_Spare_Out");


                MPCR.SetInMsg(in_node);  //생성 1번 진행 2번 완료 3번
                in_node.ProcStep = c_ProcStep;
                in_node.AddString("FACTORY", MPGV.gsFactory);
                in_node.AddString("FLOW","");
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddInt("HIST_SEQ", lblHistSeq.Text);
                in_node.AddInt("SEQ", lblSeq.Text);
                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("DOWN_CODE", lblLv3.Tag.ToString());
                in_node.AddString("DOWN_TYPE_1", lblLv1.Tag.ToString());
                in_node.AddString("DOWN_TYPE_2", lblLv2.Tag.ToString());
                in_node.AddString("DOWN_TYPE_3", lblLv3.Tag.ToString());

                if (c_ProcStep == MPGC.MP_STEP_CREATE)
                {
                    in_node.AddChar("DOWN_STATUS", "S");
                    in_node.AddString("RES_ID", cdvResource.Text);
                }
                else
                {
                    in_node.AddChar("DOWN_STATUS", "E");
                    in_node.AddString("RES_ID", cdvResource.Text);
                }


                if (chkEditDate.Checked == true)
                {
                    in_node.AddString("DOWN_START_TIME", MPCF.ToStandardTime(DateTime.Now, MPGC.MP_CONVERT_DATE_FORMAT) + MPCF.ToStandardTime(DateTime.Now, MPGC.MP_CONVERT_TIME_FORMAT));
                }
                else
                {
                    in_node.AddString("DOWN_START_TIME", MPCF.ToStandardTime(dtpDownStartTime.Value, MPGC.MP_CONVERT_DATE_FORMAT) + MPCF.ToStandardTime(dtpDownStartTime.Value, MPGC.MP_CONVERT_TIME_FORMAT));
                }

                if (chkEditDate.Checked == true)
                {
                    in_node.AddString("DOWN_END_TIME", MPCF.ToStandardTime(DateTime.Now, MPGC.MP_CONVERT_DATE_FORMAT) + MPCF.ToStandardTime(DateTime.Now, MPGC.MP_CONVERT_TIME_FORMAT));
                }
                else
                {
                    in_node.AddString("DOWN_END_TIME", MPCF.ToStandardTime(dtpDownEndTime.Value, MPGC.MP_CONVERT_DATE_FORMAT) + MPCF.ToStandardTime(dtpDownEndTime.Value, MPGC.MP_CONVERT_TIME_FORMAT));
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_non_operation", in_node, ref out_node) == false)
                {
                    if (View_Res_Id('1') == false)
                    {
                        
                    };
                }
                if (View_Res_Id('1') == false)
                {
                    
                };
                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void spdRowColChange(string gcmName)
        {

            try
            {


                /* --일단주석처리
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                {
                    return;
                }
                */

                //TPDR.GetDataOne 다이렉트 쿼리
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[5];
                DataTable dt = null;
                string sSql = "";
                string sView_Id = "";

                sView_Id = "CWIP2005-002"; //쿼리번호(뷰아이디)

                switch (gcmName)
                {
                    case "C_NOP_GRP_1":

                        dvcArgu[0].sCondition_ID = "FACTORY"; //조건코드
                        dvcArgu[0].sCondition_Value = MPGV.gsFactory; //값

                        dvcArgu[1].sCondition_ID = "TABLE_NAME"; //테이블명
                        dvcArgu[1].sCondition_Value = gcmName; //값

                        dvcArgu[2].sCondition_ID = "KEY_1"; //KEY_1
                        dvcArgu[2].sCondition_Value = ""; //값

                        dvcArgu[3].sCondition_ID = "KEY_2"; //KEY_1
                        dvcArgu[3].sCondition_Value = ""; //값

                        dvcArgu[4].sCondition_ID = "KEY_3"; //KEY_1
                        dvcArgu[4].sCondition_Value = ""; //값

                        break;
                    case "C_NOP_GRP_2":
                        dvcArgu[0].sCondition_ID = "FACTORY"; //조건코드
                        dvcArgu[0].sCondition_Value = MPGV.gsFactory; //값

                        dvcArgu[1].sCondition_ID = "TABLE_NAME"; //테이블명
                        dvcArgu[1].sCondition_Value = gcmName; //값

                        dvcArgu[2].sCondition_ID = "KEY_1"; //KEY_1
                        dvcArgu[2].sCondition_Value = lblLv1.Tag.ToString(); //값

                        dvcArgu[3].sCondition_ID = "KEY_2"; //KEY_1
                        dvcArgu[3].sCondition_Value = ""; //값

                        dvcArgu[4].sCondition_ID = "KEY_3"; //KEY_1
                        dvcArgu[4].sCondition_Value = ""; //값
                        break;
                    case "C_NOP_GRP_3":
                        dvcArgu[0].sCondition_ID = "FACTORY"; //조건코드
                        dvcArgu[0].sCondition_Value = MPGV.gsFactory; //값

                        dvcArgu[1].sCondition_ID = "TABLE_NAME"; //테이블명
                        dvcArgu[1].sCondition_Value = gcmName; //값

                        dvcArgu[2].sCondition_ID = "KEY_1"; //KEY_1
                        dvcArgu[2].sCondition_Value = lblLv1.Tag.ToString(); //값

                        dvcArgu[3].sCondition_ID = "KEY_2"; //KEY_1
                        dvcArgu[3].sCondition_Value = lblLv2.Tag.ToString(); //값

                        dvcArgu[4].sCondition_ID = "KEY_3"; //KEY_1
                        dvcArgu[4].sCondition_Value = ""; //값
                        break;
                }

                MPCF.ClearList(spdNonOper);
                if (TPDR.GetDataOne("", ref dt, sView_Id, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return;
                }
                int iCol = 0;
                int btCol = 0;
                int btRow = 0;
                int btRowCount = 0;


                spdNonOper_Sheet1.RowCount = 0;
                spdNonOper_Sheet1.ColumnCount = 0;

                btRowCount = Convert.ToInt32(Math.Ceiling(Convert.ToDouble(dt.Rows.Count) / 4.0));
                spdNonOper_Sheet1.AddRows(0, btRowCount);
                spdNonOper_Sheet1.AddColumns(0, 4);
                // spdNonOper_Sheet1.AddRows(0, 1);
                for (iCol = 0; iCol < dt.Rows.Count; iCol++)
                {

                    if (iCol <= 3)
                    {
                        btCol = iCol;
                    }
                    else
                    {
                        btCol = iCol - btRow * 4;
                    }


                    FarPoint.Win.Spread.CellType.ButtonCellType buttonCellType1 = new FarPoint.Win.Spread.CellType.ButtonCellType();
                    buttonCellType1.Text = dt.Rows[iCol]["DATA_1"].ToString();
                    buttonCellType1.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                    buttonCellType1.WordWrap = true;
                    spdNonOper_Sheet1.Cells.Get(btRow, btCol).CellType = buttonCellType1;

                    switch (gcmName)
                    {
                        case "C_NOP_GRP_1":
                            spdNonOper_Sheet1.Cells[btRow, btCol].Tag = dt.Rows[iCol]["KEY_1"].ToString();
                            break;
                        case "C_NOP_GRP_2":
                            spdNonOper_Sheet1.Cells[btRow, btCol].Tag = dt.Rows[iCol]["KEY_2"].ToString();
                            break;
                        case "C_NOP_GRP_3":
                            spdNonOper_Sheet1.Cells[btRow, btCol].Tag = dt.Rows[iCol]["KEY_3"].ToString();
                            break;
                    }
                    spdNonOper_Sheet1.Cells[btRow, btCol].Column.Width = spdNonOper.Width /4 ;  //200;
                    spdNonOper_Sheet1.Cells[btRow, btCol].Row.Height = 100;//spdNonOper.Height / btRow;  //100;



                    if (btCol == 3)
                    {
                        btRow = btRow + 1;
                    }

                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }

        }



        private void lblLvLovation(string lbltag, string lbltext)
        {


            try
            {
                FarPoint.Win.Spread.CellType.ButtonCellType buttonCellType1 = new FarPoint.Win.Spread.CellType.ButtonCellType();

                switch (lblPath.Text)
                {
                    case "L0":
                        lblPath.Text = "L1";
                        spdRowColChange("C_NOP_GRP_1");
                        lblLv1.Text = "";
                        lblLv1.Tag = "";
                        lblLv2.Text = "";
                        lblLv2.Tag = "";
                        lblLv3.Text = "";
                        lblLv3.Tag = "";


                        lblDownStartTime.Visible = false;
                        lblDownEndTime.Visible = false;
                        dtpDownStartTime.Visible = false;
                        dtpDownEndTime.Visible = false;
                        chkEditDate.Visible = false;
                        btnNonStart.Visible = false;
                        btnNonEnd.Visible = false;
                        btnBack.Visible = false;

                        break;
                    case "L1":
                        //  if (lbltag.GetType() == buttonCellType1.GetType())
                        //  {
                        lblLv1.Text = lbltext;
                        //  }
                        lblLv1.Tag = lbltag;
                        lblPath.Text = "L2";
                        lblLv2.Text = "";
                        lblLv2.Tag = "";
                        lblLv3.Text = "";
                        lblLv3.Tag = "";
                        spdRowColChange("C_NOP_GRP_2");

                        lblDownStartTime.Visible = false;
                        lblDownEndTime.Visible = false;
                        dtpDownStartTime.Visible = false;
                        dtpDownEndTime.Visible = false;
                        chkEditDate.Visible = false;
                        btnNonStart.Visible = false;
                        btnNonEnd.Visible = false;
                        btnBack.Visible = true;

                        break;
                    case "L2":

                        //   if (lbltext.GetType() == buttonCellType1.GetType())
                        //   {
                        lblLv2.Text = lbltext;
                        //   }
                        lblLv2.Tag = lbltag;
                        spdRowColChange("C_NOP_GRP_3");
                        lblPath.Text = "L3";
                        lblLv3.Text = "";
                        lblLv3.Tag = "";

                        lblDownStartTime.Visible = true;
                        lblDownEndTime.Visible = true;
                        dtpDownStartTime.Visible = true;
                        dtpDownEndTime.Visible = true;
                        chkEditDate.Visible = true;
                        btnNonStart.Visible = true;
                        btnNonEnd.Visible = true;
                        lblDownStartTime.Visible = true;
                        lblDownEndTime.Visible = true;
                        dtpDownStartTime.Visible = true;
                        dtpDownEndTime.Visible = true;
                        btnBack.Visible = true;
                        break;
                    case "L3":
                        //    if (lbltext.GetType() == buttonCellType1.GetType())
                        //    {
                        lblLv3.Text = lbltext;
                        //    }
                        lblLv3.Tag = lbltag;
                        //조회추가해아함


                        if (CheckCondition(CSGC.CHECK.END) == false)
                        {
                            return;
                        }


                        if (string.IsNullOrEmpty(txtResStatus.Text) == false)
                        {
                            if (MPCF.ShowMsgBox("현재 " + txtResStatus.Text + "로 비가동 상태입니다. END 후 " + lblLv3.Text + "으로 START 하시겠습니까?", MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                            {
                                Update_Non_Operation(MPGC.MP_STEP_UPDATE);
                                Update_Non_Operation(MPGC.MP_STEP_CREATE);
                            }
                        }
                        else
                        {
                            Update_Non_Operation(MPGC.MP_STEP_CREATE);
                        }
                        break;

                }


                if (string.IsNullOrEmpty(lblLv2.Text) == false)
                {
                    lblsession1.Text = "->";
                }
                else
                {
                    lblsession1.Text = "";
                }

                if (string.IsNullOrEmpty(lblLv3.Text) == false)
                {
                    lblsession2.Text = "->";
                }
                else
                {
                    lblsession2.Text = "";
                }



                lblLv1.AutoSize = true;
                lblsession1.AutoSize = true;
                lblLv2.AutoSize = true;
                lblsession2.AutoSize = true;
                lblLv3.AutoSize = true;

                lblLv1.Location = new System.Drawing.Point(lblLv1.Location.X, lblLv1.Location.Y);
                lblsession1.Location = new System.Drawing.Point(lblLv1.Location.X + lblLv1.Size.Width + 10, lblLv1.Location.Y);
                lblLv2.Location = new System.Drawing.Point(lblsession1.Location.X + lblsession1.Size.Width + 10, lblLv1.Location.Y);
                lblsession2.Location = new System.Drawing.Point(lblLv2.Location.X + lblLv2.Size.Width + 10, lblLv1.Location.Y);
                lblLv3.Location = new System.Drawing.Point(lblsession2.Location.X + lblsession2.Size.Width + 10, lblLv1.Location.Y);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }





        }

        #endregion
        #region " Event Definition "
        private void btnView_Click(object sender, EventArgs e)
        {

        }



        private void spdNonOper_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {

            try
            {

                FarPoint.Win.Spread.CellType.ButtonCellType buttonCellType1 = new FarPoint.Win.Spread.CellType.ButtonCellType();
                string sText = ((FarPoint.Win.Spread.CellType.ButtonCellType)spdNonOper.ActiveSheet.GetCellType(e.Row, e.Column)).Text;
                string sTag = spdNonOper_Sheet1.Cells[e.Row, e.Column].Tag.ToString();

                lblLvLovation(sTag,sText);

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

     

        private void lblLv1_Click(object sender, EventArgs e)
        {
            lblPath.Text = "L0";
            lblLvLovation(null,null);
            spdRowColChange("C_NOP_GRP_1");
        }

        private void lblLv2_Click(object sender, EventArgs e)
        {
            lblPath.Text = "L1";
            lblLvLovation(lblLv1.Tag.ToString(), lblLv1.Text);
            spdRowColChange("C_NOP_GRP_2");
        }

        private void lblLv3_Click(object sender, EventArgs e)
        {

            if (CheckCondition(CSGC.CHECK.END) == false){
                return;
            }


            if (string.IsNullOrEmpty(txtResStatus.Text) == false)
            {
                if (MPCF.ShowMsgBox("현재 " + txtResStatus.Text + "로 비가동 상태입니다. END후 " + lblLv3.Text + "으로 START 하시겠습니까?", MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
                {
                    Update_Non_Operation(MPGC.MP_STEP_UPDATE);
                    Update_Non_Operation(MPGC.MP_STEP_CREATE);
                }
            }
            else
            {
                Update_Non_Operation(MPGC.MP_STEP_CREATE);
            }

        }

        #endregion

        private void cdvResource_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            if (View_Res_Id('1') == false)
            {

            };
            lblPath.Text = "L0";
            lblLvLovation(null, null);
            spdRowColChange("C_NOP_GRP_1");
        }

        private void cdvResource_TextBoxKeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                if (View_Res_Id('1') == false)
                {

                };
                lblPath.Text = "L0";
                lblLvLovation(null, null);
                spdRowColChange("C_NOP_GRP_1");
            }
        }
        private void btnProcess_Click(object sender, EventArgs e)
        {

        }

        private void pnlBottom_SizeChanged(object sender, EventArgs e)
        {
            if(spdNonOper_Sheet1.Rows.Count > 0)
            {
                spdNonOper_Sheet1.Columns[0].Width = spdNonOper.Width / 4;
                spdNonOper_Sheet1.Columns[1].Width = spdNonOper.Width / 4;
                spdNonOper_Sheet1.Columns[2].Width = spdNonOper.Width / 4;
                spdNonOper_Sheet1.Columns[3].Width = spdNonOper.Width / 4;
            }

        }

        private void dtpDownEndTime_ValueChanged(object sender, EventArgs e)
        {
            //chkEditDate.Checked = false;
        }
        private void chkEditDate_CheckedChanged(object sender, EventArgs e)
        {
            if(chkEditDate.Checked == true)
            {
                dtpDownStartTime.Enabled = true;
                dtpDownEndTime.Enabled = true;

            }
            else
            {
                dtpDownStartTime.Enabled = false;
                dtpDownEndTime.Enabled = false;
            }
        }

        private void btnNonStart_Click(object sender, EventArgs e)
        {
            if (CheckCondition(CSGC.CHECK.START) == false)
            {
                return;
            }

            if (string.IsNullOrEmpty(txtResStatus.Text) == false)
            {
                MPCF.ShowMsgBox("현재 비가동 상태가.(" + lblLv3.Text + ") 입니다. 종료후 START 바랍니다." );
                return;
            }

            if (MPCF.ShowMsgBox(cdvResource.DisplayText + "(" + lblLv3.Text + ")  " + " START 하시겠습니까?", MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
            {

                Update_Non_Operation(MPGC.MP_STEP_CREATE);
            }

        }

        private void btnEnd_Click(object sender, EventArgs e)
        {
            if (CheckCondition(CSGC.CHECK.END) == false)
            {
                return;
            }

            if (string.IsNullOrEmpty(txtResStatus.Text) == true)
            {
                MPCF.ShowMsgBox("현재 비가동으로 등록된 정보가 없습니다.");
                return;
            }

            if (MPCF.ShowMsgBox(cdvResource.DisplayText + "(" + lblLv3.Text + ")  " + "  END 하시겠습니까?", MessageBoxButtons.YesNo, 1) == DialogResult.Yes)
            {
                Update_Non_Operation(MPGC.MP_STEP_UPDATE);
            }
        }

        private void btnBack_Click(object sender, EventArgs e)
        {

            switch (lblPath.Text)
            {
                case "L1":
                  //  lblPath.Text = "L0";
                  //  lblLvLovation(null, null);
                 //   spdRowColChange("C_NOP_GRP_1");
                 //   lblPath.Text = "L1";
                    break;
                case "L2":
                    lblPath.Text = "L0";
                    lblLvLovation(null, null);
                   // lblLvLovation(lblLv1.Tag.ToString(), lblLv1.Text);
                    spdRowColChange("C_NOP_GRP_1");
                    lblPath.Text = "L1";
                    break;
                case "L3":
                    lblPath.Text = "L1";
                    // lblLvLovation(lblLv2.Tag.ToString(), lblLv2.Text);
                    lblLvLovation(lblLv1.Tag.ToString(), lblLv1.Text);
                    spdRowColChange("C_NOP_GRP_2");
                    lblPath.Text = "L2";
                    break;
            }
        }

        private void frmTranNonOperationBAK_ResizeEnd(object sender, EventArgs e)
        {

        }

        private void frmTranNonOperationBAK_SizeChanged(object sender, EventArgs e)
        {
            if (spdNonOper_Sheet1.Rows.Count > 0)
            {
                spdNonOper_Sheet1.Columns[0].Width = spdNonOper.Width / 4 -1;
                spdNonOper_Sheet1.Columns[1].Width = spdNonOper.Width / 4 -1;
                spdNonOper_Sheet1.Columns[2].Width = spdNonOper.Width / 4 -1;
                spdNonOper_Sheet1.Columns[3].Width = spdNonOper.Width / 4 -1;
            }
        }

        private void tmrTimer_Tick(object sender, EventArgs e)
        {

            try
            {
                if(chkTimer.Checked == true)
                {
                    if (View_Res_Id('1') == false)
                    {

                    };
                }
                if (txtResStatus.Tag.ToString() == "E")
                {
                    dtpDownStartTime.Value = DateTime.Now;
                }
                dtpDownEndTime.Value = DateTime.Now;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

    }
}
