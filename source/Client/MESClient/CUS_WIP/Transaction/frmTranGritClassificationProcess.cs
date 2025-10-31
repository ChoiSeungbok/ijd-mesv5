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

//CWIP2009
namespace CUS_WIP
{
    public partial class frmTranGritClassificationProcess : CUS_COM.frmTranForm01
    {
        public frmTranGritClassificationProcess()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum LOT_INFO
        {
            CHK,                    // 1 : CHECK
            LOT_ID,                 // 2 : LOT ID
            LOT_TYPE,               // 3 : LOT 타입
            MAT_ID,                 // 4 : 제품코드
            MAT_DESC,               // 5 : 제품명   
            MAT_GRP_2,              // 6 : 제품군
            CREATE_TIME,            // 7 : 생성시간
            PROD_QTY,               // 8 : 생산수량
            ORDER_ID,               // 9 : 작업지시
            SIZE_CLASS,
            SIZE_VALUE,
            MAGN_CLASS,
            MAGN_VALUE,
            CUP_CLASS,
            CUP_VALUE,
            OPER,
            START_TIME
        }

        private enum WORKER_INFO
        {
            CHK,                    // 1 : CHECK
            WORKER,                 // 2 : 이름
            WORKER_ID               // 3 : 사번
        }

        private enum SIZE_INFO
        {
            CLASS,                  // 1 : 분류
            CLASS_DESC,             // 2 : 분류
            QTY,                    // 3 : 수량
            LOSS_CONFIRM_CODE,
            LOSS_CONFIRM_NAME,
            LOSS_CONFIRM_SELECT
        }

        private enum MAG_INFO
        {
            CLASS,                  // 1 : 분류
            CLASS_DESC,             // 2 : 분류
            QTY                     // 3 : 수량
        }

        private enum SHAPE_INFO
        {
            CLASS,                   // 1 : 분류
            CLASS_DESC,              // 2 : 분류
            QTY,                     // 3 : 수량
            LOSS_CONFIRM_CODE,
            LOSS_CONFIRM_NAME,
            LOSS_CONFIRM_SELECT
        }

        #endregion

        #region " Variable Definition "

        string sClassType = "";
        string sClassNum = "";
        string sMixLotOper = "";
        string sMergeInStartLot = "";

        string sPrintLabelID = "";

        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnStart.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClear.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnLotData.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnNonOper.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnWorker.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //lot 정보조회 함수
        private void ViewLotInfo(string sLot_ID , char c_Step)
        {
            string sLotId = "";
            int iRow = 0;
            bool bContinueFlag = false;

            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = c_Step;
                in_node.AddString("LOT_ID", sLot_ID);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("RES_ID", cdvResource.Text);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Lot_Info", in_node, ref out_node) == false)
                {
                    return;
                }
                for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                {
                    bContinueFlag = false;

                    //lot 정보가 이미 있는경우 넘어간다.
                    sLotId = out_node.GetList("LOT_TBL")[i].GetString("LOT_ID");
                    for (int k = 0; k < spdLotList.ActiveSheet.RowCount; k++)
                    {
                        if (sLotId == spdLotList.ActiveSheet.Cells[k, (int)LOT_INFO.LOT_ID].Text)
                        {
                            bContinueFlag = true;
                            continue;
                        }
                    }

                    if (MPCF.Trim(sMixLotOper) != "Y")
                    {
                        if (spdLotList.ActiveSheet.RowCount == 1)
                        {
                            //CMN511 INFO - 하나의 lot만 진행 할 수 있는 공정입니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(511));
                            return;
                        }
                    }

                    if (spdLotList.ActiveSheet.RowCount == 0)
                    {
                        if (out_node.GetList("LOT_TBL")[i].GetString("START_TIME") != "")
                        {
                            cdvDept.Text = out_node.GetList("LOT_TBL")[0].GetString("AREA_ID");
                            cdvDept.DisplayText = out_node.GetList("LOT_TBL")[0].GetString("AREA_DESC");
                            cdvWorkPlace.Text = out_node.GetList("LOT_TBL")[0].GetString("SUB_AREA_ID");
                            cdvWorkPlace.DisplayText = out_node.GetList("LOT_TBL")[0].GetString("SUB_AREA_DESC");
                            cdvOper.Text = out_node.GetList("LOT_TBL")[0].GetString("OPER");
                            cdvOper.DisplayText = out_node.GetList("LOT_TBL")[0].GetString("OPER_DESC");
                            cdvResource.Text = out_node.GetList("LOT_TBL")[0].GetString("RES_ID");
                            cdvResource.DisplayText = out_node.GetList("LOT_TBL")[0].GetString("RES_DESC");
                        }
                    }
                    else
                    {
                        //시작된 LOT이 1개 이상 선택된 경우 설비가 다르면 에러
                        if (out_node.GetList("LOT_TBL")[i].GetString("START_TIME") != "")
                        {
                            if (cdvResource.Text != out_node.GetList("LOT_TBL")[0].GetString("RES_ID"))
                            {
                                //CMN536 INFO -  투입된 설비가 다릅니다. LOT의 시작 설비를 확인하세요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(536));
                                return;
                            }

                            if (cdvOper.Text != out_node.GetList("LOT_TBL")[0].GetString("OPER"))
                            {
                                //CMN438 ERROR -공정이 일치하지 않습니다.
                                MPCF.ShowMsgBox(MPCF.GetMessage(438));
                                return;
                            }
                        }
                    }

                    if (bContinueFlag == true)
                        continue;

                    iRow = spdLotList.ActiveSheet.RowCount;

                    spdLotList.ActiveSheet.RowCount++;
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CHK, true);
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.LOT_ID, out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.LOT_TYPE, out_node.GetList("LOT_TBL")[i].GetString("LOT_TYPE"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_ID, out_node.GetList("LOT_TBL")[i].GetString("MAT_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_DESC, out_node.GetList("LOT_TBL")[i].GetString("MAT_DESC"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAT_GRP_2, out_node.GetList("LOT_TBL")[i].GetString("MAT_GRP_2"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CREATE_TIME, MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("CREATE_TIME"), DATE_TIME_FORMAT.DATETIME));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.PROD_QTY, out_node.GetList("LOT_TBL")[i].GetDouble("QTY_1"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.ORDER_ID, out_node.GetList("LOT_TBL")[i].GetString("ORDER_ID"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.SIZE_CLASS, out_node.GetList("LOT_TBL")[i].GetString("GRT_CMF_1"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.SIZE_VALUE, MPCF.ToDbl(out_node.GetList("LOT_TBL")[i].GetString("GRT_CMF_2")));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAGN_CLASS, out_node.GetList("LOT_TBL")[i].GetString("GRT_CMF_3"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.MAGN_VALUE, MPCF.ToDbl(out_node.GetList("LOT_TBL")[i].GetString("GRT_CMF_4")));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CUP_CLASS, out_node.GetList("LOT_TBL")[i].GetString("GRT_CMF_5"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.CUP_VALUE, MPCF.ToDbl(out_node.GetList("LOT_TBL")[i].GetString("GRT_CMF_6")));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.OPER, out_node.GetList("LOT_TBL")[i].GetString("OPER_DESC"));
                    spdLotList.ActiveSheet.SetValue(iRow, (int)LOT_INFO.START_TIME, MPCF.MakeDateFormat(out_node.GetList("LOT_TBL")[i].GetString("START_TIME"), DATE_TIME_FORMAT.DATETIME));

                    if (spdLotList.ActiveSheet.RowCount == 1)
                    {
                        fnCheckMatClass(out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));
                    }
                }

                MPCF.FitColumnHeader(spdLotList);

                //class 값 보이도록 한다.
                CalClassQty();
                CalSumQty();

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        //작업자 조회 함수
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

                if (TPDR.GetDataOne("", ref dt, "CWIP2009-001", dvcArgu, false, false, ref sSql) == false)
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

        //자재lot 인지 체크 하는 함수
        public bool fnCheckINVLot()
        {
            bool bCheck = false;

            try
            {
                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "INV_LOT_ID";
                dvcArgu[1].sCondition_Value = txtLotID.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2009-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }

                if (dt == null)
                    bCheck = false;

                if (dt.Rows.Count > 0)
                {
                    if (MPCF.ToInt(dt.Rows[0]["CHK"].ToString()) == 1)
                    {
                        bCheck = true;
                    }
                }

                return bCheck;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //사이즈 분류정보 조회
        private void ViewSizeClassList(string sMat_Grouop)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_GROUP";
                dvcArgu[1].sCondition_Value = sMat_Grouop;

                dvcArgu[2].sCondition_ID = "CLASS_TYPE";
                dvcArgu[2].sCondition_Value = CSGC.CP_CLASS_SIZE;

                if (TPDR.GetDataOne("", ref dt, "CWIP2009-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdSize);
                    return;
                }

                MPCF.ClearList(spdSize);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdSize.ActiveSheet.RowCount++;

                    spdSize.ActiveSheet.Cells[i, (int)SIZE_INFO.CLASS].Value = dt.Rows[i]["CLASS_CODE"];
                    spdSize.ActiveSheet.Cells[i, (int)SIZE_INFO.CLASS_DESC].Value = dt.Rows[i]["CLASS_DESC"];
                    spdSize.ActiveSheet.Cells[i, (int)SIZE_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdSize.ActiveSheet.Cells[i, (int)SIZE_INFO.LOSS_CONFIRM_CODE].Value = dt.Rows[i]["LOSS_CONFIRM_CODE"];
                    spdSize.ActiveSheet.Cells[i, (int)SIZE_INFO.LOSS_CONFIRM_NAME].Value = dt.Rows[i]["LOSS_CONFIRM_NAME"];
                }

                //MPCF.FitColumnHeader(spdSize);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //자성 분류정보 조회
        private void ViewMagnClassList(string sMat_Grouop)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_GROUP";
                dvcArgu[1].sCondition_Value = sMat_Grouop;

                dvcArgu[2].sCondition_ID = "CLASS_TYPE";
                dvcArgu[2].sCondition_Value = CSGC.CP_CLASS_MAGN;

                if (TPDR.GetDataOne("", ref dt, "CWIP2009-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdMagnet);
                    return;
                }

                MPCF.ClearList(spdMagnet);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdMagnet.ActiveSheet.RowCount++;

                    spdMagnet.ActiveSheet.Cells[i, (int)MAG_INFO.CLASS].Value = dt.Rows[i]["CLASS_CODE"];
                    spdMagnet.ActiveSheet.Cells[i, (int)MAG_INFO.CLASS_DESC].Value = dt.Rows[i]["CLASS_DESC"];
                    spdMagnet.ActiveSheet.Cells[i, (int)MAG_INFO.QTY].Value = dt.Rows[i]["QTY"];
                }

                //MPCF.FitColumnHeader(spdMagnet);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //형상분류
        private void ViewShapeClassList(string sMat_Grouop)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "MAT_GROUP";
                dvcArgu[1].sCondition_Value = sMat_Grouop;

                dvcArgu[2].sCondition_ID = "CLASS_TYPE";
                dvcArgu[2].sCondition_Value = CSGC.CP_CLASS_CUP;

                if (TPDR.GetDataOne("", ref dt, "CWIP2009-005", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdShape);
                    return;
                }

                MPCF.ClearList(spdShape);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdShape.ActiveSheet.RowCount++;

                    spdShape.ActiveSheet.Cells[i, (int)SHAPE_INFO.CLASS].Value = dt.Rows[i]["CLASS_CODE"];
                    spdShape.ActiveSheet.Cells[i, (int)SHAPE_INFO.CLASS_DESC].Value = dt.Rows[i]["CLASS_DESC"];
                    spdShape.ActiveSheet.Cells[i, (int)SHAPE_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdShape.ActiveSheet.Cells[i, (int)SHAPE_INFO.LOSS_CONFIRM_CODE].Value = dt.Rows[i]["LOSS_CONFIRM_CODE"];
                    spdShape.ActiveSheet.Cells[i, (int)SHAPE_INFO.LOSS_CONFIRM_NAME].Value = dt.Rows[i]["LOSS_CONFIRM_NAME"];
                }

                //MPCF.FitColumnHeader(spdShape);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //분류 작업장 조회 함수
        public bool ViewSubArea_Class(Control control, string sArea_id)
        {
            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea_id;

                if (TPDR.GetDataOne("", ref dt, "CWIP2009-006", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return false;

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["KEY_1"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["DATA_1"].ToString());
                        }
                        ((ListView)control).Items.Add(itmX);
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

        //공정 선택 후 화면 컨트롤 함수
        public void fnCheckClass()
        {
            bool bCheck = false;

            try
            {
                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2009-007", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return;

                if (dt.Rows.Count > 0)
                {
                    sClassType = dt.Rows[0]["CLASS_CODE"].ToString();
                    sClassNum = dt.Rows[0]["CLASS_NUM"].ToString();
                    sMixLotOper = dt.Rows[0]["MIX_LOT_OPER"].ToString();
                    sMergeInStartLot = dt.Rows[0]["MERGE_YN_BY_START"].ToString();

                    //사이즈
                    if (sClassType == CSGC.CP_CLASS_SIZE)
                    {
                        spdSize.Enabled = true;
                        spdSize.ActiveSheet.Columns[0, 2].BackColor = Color.White;
                        spdMagnet.Enabled = false;
                        spdMagnet.ActiveSheet.Columns[0, 2].BackColor = Color.WhiteSmoke;
                        spdShape.Enabled = false;
                        spdShape.ActiveSheet.Columns[0, 5].BackColor = Color.WhiteSmoke;

                        bCheck = true;
                    }
                    //자성
                    else if (sClassType == CSGC.CP_CLASS_MAGN)
                    {
                        spdSize.Enabled = false;
                        spdSize.ActiveSheet.Columns[0, 2].BackColor = Color.WhiteSmoke;
                        spdMagnet.Enabled = true;
                        spdMagnet.ActiveSheet.Columns[0, 2].BackColor = Color.White;
                        spdShape.Enabled = false;
                        spdShape.ActiveSheet.Columns[0, 5].BackColor = Color.WhiteSmoke;

                        bCheck = true;
                    }
                    //형상
                    else if (sClassType == CSGC.CP_CLASS_CUP)
                    {
                        spdSize.Enabled = false;
                        spdSize.ActiveSheet.Columns[0, 2].BackColor = Color.WhiteSmoke;
                        spdMagnet.Enabled = false;
                        spdMagnet.ActiveSheet.Columns[0, 2].BackColor = Color.WhiteSmoke;
                        spdShape.Enabled = true;
                        spdShape.ActiveSheet.Columns[0, 5].BackColor = Color.White;

                        bCheck = true;
                    }
                    //그외
                    else
                    {
                        spdSize.Enabled = false;
                        spdSize.ActiveSheet.Columns[0, 2].BackColor = Color.WhiteSmoke;
                        MPCF.ClearList(spdSize);
                        spdMagnet.Enabled = false;
                        spdMagnet.ActiveSheet.Columns[0, 2].BackColor = Color.WhiteSmoke;
                        MPCF.ClearList(spdMagnet);
                        spdShape.Enabled = false;
                        spdShape.ActiveSheet.Columns[0, 5].BackColor = Color.WhiteSmoke;
                        MPCF.ClearList(spdShape);

                        bCheck = false;
                    }
                }
                else
                {
                    spdSize.Enabled = false;
                    spdSize.ActiveSheet.Columns[0, 2].BackColor = Color.WhiteSmoke;
                    MPCF.ClearList(spdSize);
                    spdMagnet.Enabled = false;
                    spdMagnet.ActiveSheet.Columns[0, 2].BackColor = Color.WhiteSmoke;
                    MPCF.ClearList(spdMagnet);
                    spdShape.Enabled = false;
                    spdShape.ActiveSheet.Columns[0, 5].BackColor = Color.WhiteSmoke;
                    MPCF.ClearList(spdShape);
                }

                if (bCheck == true)
                {
                    ViewSizeClassList(dt.Rows[0]["MAT_GROUP"].ToString());
                    ViewMagnClassList(dt.Rows[0]["MAT_GROUP"].ToString());
                    ViewShapeClassList(dt.Rows[0]["MAT_GROUP"].ToString());
                }

                if (sMergeInStartLot == "Y")
                    btnMerge.Visible = true;
                else
                    btnMerge.Visible = false;

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public void fnCheckMatClass(string sLot)
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "LOT_ID";
                dvcArgu[1].sCondition_Value = sLot;
                
                if (TPDR.GetDataOne("", ref dt, "CWIP2009-008", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return;
                }

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    if (dt.Rows[i]["CLASS_TYPE"].ToString() == CSGC.CP_CLASS_SIZE)
                    {
                        for (int k = 0; k < spdSize.ActiveSheet.RowCount; k++)
                        {
                            if (dt.Rows[i]["CLASS_VALUE"].ToString() == "ALL")
                            {
                                spdSize.ActiveSheet.Cells[k, (int)SIZE_INFO.CLASS_DESC].Font = new Font(this.Font, FontStyle.Bold);
                            }
                            else
                            {
                                if (dt.Rows[i]["CLASS_VALUE"].ToString() == spdSize.ActiveSheet.Cells[k, (int)SIZE_INFO.CLASS].Text)
                                {
                                    spdSize.ActiveSheet.Cells[k, (int)SIZE_INFO.CLASS_DESC].Font = new Font(this.Font, FontStyle.Bold);
                                    break;
                                }
                            }
                        }
                    }
                    else if (dt.Rows[i]["CLASS_TYPE"].ToString() == CSGC.CP_CLASS_MAGN)
                    {
                        for (int k = 0; k < spdMagnet.ActiveSheet.RowCount; k++)
                        {
                            if (dt.Rows[i]["CLASS_VALUE"].ToString() == "ALL")                                
                            {
                                spdMagnet.ActiveSheet.Cells[k, (int)MAG_INFO.CLASS_DESC].Font = new Font(this.Font, FontStyle.Bold);
                            }
                            else
                            {
                                if (dt.Rows[i]["CLASS_VALUE"].ToString() == spdMagnet.ActiveSheet.Cells[k, (int)MAG_INFO.CLASS].Text)
                                {
                                    spdMagnet.ActiveSheet.Cells[k, (int)MAG_INFO.CLASS_DESC].Font = new Font(this.Font, FontStyle.Bold);
                                    break;
                                }
                            }
                        }
                    }
                    else if (dt.Rows[i]["CLASS_TYPE"].ToString().Contains(CSGC.CP_CLASS_CUP))
                    {
                        for (int k = 0; k < spdShape.ActiveSheet.RowCount; k++)
                        {
                            if (dt.Rows[i]["CLASS_VALUE"].ToString() == "ALL")
                            {
                                spdShape.ActiveSheet.Cells[k, (int)SHAPE_INFO.CLASS_DESC].Font = new Font(this.Font, FontStyle.Bold);
                            }
                            else
                            {
                                if (dt.Rows[i]["CLASS_VALUE"].ToString() == spdShape.ActiveSheet.Cells[k, (int)SHAPE_INFO.CLASS].Text)
                                {
                                    spdShape.ActiveSheet.Cells[k, (int)SHAPE_INFO.CLASS_DESC].Font = new Font(this.Font, FontStyle.Bold);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //step 1 : 시작, 2 : 완료
        private bool SaveProcess(char c_step)
        {
            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                TRSNode Lot_list;
                TRSNode Worker_list;
                TRSNode Class_list;

                double d_ClassSumQty = 0;
                double d_GoodQty = 0;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = c_step;

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("RES_ID", cdvResource.Text);

                if (sClassType == CSGC.CP_CLASS_CUP)
                {
                    //IMD-T인 경우 형상 1,2,3이므로
                    if (MPCF.Trim(sClassNum) != "" && MPCF.ToInt(sClassNum) != 0)
                    {
                        in_node.AddString("CLASS_TYPE", sClassType + sClassNum);
                    }
                    else
                    {
                        in_node.AddString("CLASS_TYPE", sClassType);
                    }
                }
                else
                {
                    in_node.AddString("CLASS_TYPE", sClassType);
                }

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        Lot_list = in_node.AddNode("LOT_TBL");
                        Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                        Lot_list.AddString("MAT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Text);
                        Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text));
                        Lot_list.AddString("LOT_TYPE", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_TYPE].Text);            
                    }
                }

                //작업자 리스트
                for (int k = 0; k < spdWorkerList.ActiveSheet.RowCount; k++)
                {
                    if (spdWorkerList.ActiveSheet.Cells[k, (int)WORKER_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        Worker_list = in_node.AddNode("WORKER_TBL");
                        Worker_list.AddString("WORKER_ID", spdWorkerList.ActiveSheet.Cells[k, (int)WORKER_INFO.WORKER_ID].Text);
                    }
                }

                if (sClassType == CSGC.CP_CLASS_SIZE)
                {
                    for (int i = 0; i < spdSize.ActiveSheet.RowCount; i++)
                    {
                        if (MPCF.ToDbl(spdSize.ActiveSheet.Cells[i, (int)SIZE_INFO.QTY].Text) != 0 &&
                            MPCF.Trim(spdSize.ActiveSheet.Cells[i, (int)SIZE_INFO.LOSS_CONFIRM_CODE].Text) != "")
                        {
                            Class_list = in_node.AddNode("CLASS_TBL");
                            Class_list.AddString("CLASS", spdSize.ActiveSheet.Cells[i, (int)SIZE_INFO.CLASS].Text);
                            Class_list.AddDouble("QTY", MPCF.ToDbl(spdSize.ActiveSheet.Cells[i, (int)SIZE_INFO.QTY].Text));
                            Class_list.AddString("LOSS_CONFIRM", spdSize.ActiveSheet.Cells[i, (int)SIZE_INFO.LOSS_CONFIRM_CODE].Text);

                            d_ClassSumQty = d_ClassSumQty + MPCF.ToDbl(spdSize.ActiveSheet.Cells[i, (int)SIZE_INFO.QTY].Text);

                            if (spdSize.ActiveSheet.Cells[i, (int)SIZE_INFO.LOSS_CONFIRM_CODE].Text == "OK")
                            {
                                d_GoodQty = d_GoodQty + MPCF.ToDbl(spdSize.ActiveSheet.Cells[i, (int)SIZE_INFO.QTY].Text);
                            }
                        }
                    }
                }
                else if (sClassType == CSGC.CP_CLASS_MAGN)
                {
                    for (int i = 0; i < spdMagnet.ActiveSheet.RowCount; i++)
                    {
                        if (MPCF.ToDbl(spdMagnet.ActiveSheet.Cells[i, (int)MAG_INFO.QTY].Text) != 0)
                        {
                            Class_list = in_node.AddNode("CLASS_TBL");
                            Class_list.AddString("CLASS", spdMagnet.ActiveSheet.Cells[i, (int)MAG_INFO.CLASS].Text);
                            Class_list.AddDouble("QTY", MPCF.ToDbl(spdMagnet.ActiveSheet.Cells[i, (int)MAG_INFO.QTY].Text));

                            d_ClassSumQty = d_ClassSumQty + MPCF.ToDbl(spdMagnet.ActiveSheet.Cells[i, (int)MAG_INFO.QTY].Text);
                        }
                    }
                }
                else if (sClassType == CSGC.CP_CLASS_CUP)
                {
                    for (int i = 0; i < spdShape.ActiveSheet.RowCount; i++)
                    {
                        if (MPCF.ToDbl(spdShape.ActiveSheet.Cells[i, (int)SHAPE_INFO.QTY].Text) != 0 && 
                            MPCF.Trim(spdShape.ActiveSheet.Cells[i, (int)SHAPE_INFO.LOSS_CONFIRM_CODE].Text) != "")
                        {
                            Class_list = in_node.AddNode("CLASS_TBL");
                            Class_list.AddString("CLASS", spdShape.ActiveSheet.Cells[i, (int)SHAPE_INFO.CLASS].Text);
                            Class_list.AddDouble("QTY", MPCF.ToDbl(spdShape.ActiveSheet.Cells[i, (int)SHAPE_INFO.QTY].Text));
                            Class_list.AddString("LOSS_CONFIRM", spdShape.ActiveSheet.Cells[i, (int)SHAPE_INFO.LOSS_CONFIRM_CODE].Text);

                            d_ClassSumQty = d_ClassSumQty + MPCF.ToDbl(spdShape.ActiveSheet.Cells[i, (int)SHAPE_INFO.QTY].Text);

                            if (spdShape.ActiveSheet.Cells[i, (int)SHAPE_INFO.LOSS_CONFIRM_CODE].Text == "OK")
                            {
                                d_GoodQty = d_GoodQty + MPCF.ToDbl(spdShape.ActiveSheet.Cells[i, (int)SHAPE_INFO.QTY].Text);
                            }
                        }
                    }
                }

                in_node.AddDouble("SUM_CLASS_QTY", d_ClassSumQty);
                in_node.AddDouble("SUM_GOOD_QTY", d_GoodQty);

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Grit_Class_Process", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);

                if (c_step == '1')
                {
                    txtLotID.Text = out_node.GetString("LOT_ID");
                }
                else if (c_step == '2')
                {
                    CheckPrintOption(cdvOper.Text, "");                        
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
        
        //step 3 : merge
        private bool MergeLot(char c_step)
        {
            string sTmp = "";
            string sTmpLot = "";

            try
            {
                TRSNode in_node = new TRSNode("Process_In");
                TRSNode out_node = new TRSNode("Process_Out");
                TRSNode Lot_list;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = c_step;

                in_node.AddString("AREA_ID", cdvDept.Text);
                in_node.AddString("SUB_AREA_ID", cdvWorkPlace.Text);
                in_node.AddString("OPER", cdvOper.Text);
                in_node.AddString("RES_ID", cdvResource.Text);

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        if (MPCF.Trim(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.START_TIME].Text) != "")
                        {
                            if (sTmp == "")
                            {
                                sTmp = MPCF.Trim(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.START_TIME].Text.Replace("-","").Replace(":","").Replace(" ", ""));
                                sTmpLot = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text;
                            }
                            else
                            {
                                if (MPCF.ToInt(sTmp) > MPCF.ToInt(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.START_TIME].Text.Replace("-", "").Replace(":", "").Replace(" ", "")))
                                {
                                    sTmp = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.START_TIME].Text.Replace("-", "").Replace(":", "").Replace(" ", "");
                                    sTmpLot = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text;
                                }
                            }
                        }
                    }
                }

                if (sTmpLot == "")
                {
                    sTmpLot = spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.LOT_ID].Text;
                }

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        Lot_list = in_node.AddNode("LOT_TBL");
                        Lot_list.AddString("LOT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                        Lot_list.AddString("MAT_ID", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Text);
                        Lot_list.AddDouble("QTY_1", MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text));
                        Lot_list.AddString("LOT_TYPE", spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_TYPE].Text);

                        if (sTmpLot == spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Text)
                        {
                            Lot_list.AddChar("MAIN_YN", 'Y');
                        }
                    }
                }
                
                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Grit_Class_Process", in_node, ref out_node) == false)
                    return false;
                else
                    MPCR.ShowSuccessMsg(out_node);
                
                txtLotID.Text = out_node.GetString("LOT_ID");

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //sum 계산
        private void CalSumQty()
        {
            double d_SumQty = 0;

            try
            {
                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    d_SumQty = d_SumQty + MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.PROD_QTY].Text);
                }

                txtSumQty.Text = d_SumQty.ToString();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //분류 정보 수량 조회
        private void CalClassQty()
        {
            double dTmpQty = 0;
            string sTmp = "";

            try
            {                
                //그리드 수량 초기화
                for (int k = 0; k < spdSize.ActiveSheet.RowCount; k++)
                {
                    spdSize.ActiveSheet.SetValue(k, (int)SIZE_INFO.QTY, 0);
                }
                for (int k = 0; k < spdMagnet.ActiveSheet.RowCount; k++)
                {
                    spdMagnet.ActiveSheet.SetValue(k, (int)MAG_INFO.QTY, 0);
                }
                for (int k = 0; k < spdShape.ActiveSheet.RowCount; k++)
                {
                    spdShape.ActiveSheet.SetValue(k, (int)SHAPE_INFO.QTY, 0);
                }

                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (sClassType != CSGC.CP_CLASS_SIZE)
                    {
                        if (MPCF.Trim(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.SIZE_CLASS].Text) != "")
                        {
                            sTmp = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.SIZE_CLASS].Text;

                            for (int k = 0; k < spdSize.ActiveSheet.RowCount; k++)
                            {
                                if (spdSize.ActiveSheet.Cells[k, (int)SIZE_INFO.CLASS].Text == sTmp)
                                {
                                    dTmpQty = MPCF.ToDbl(spdSize.ActiveSheet.Cells[k, (int)SIZE_INFO.QTY].Text);
                                    dTmpQty = dTmpQty + MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.SIZE_VALUE].Text);
                                    spdSize.ActiveSheet.SetValue(k, (int)SIZE_INFO.QTY, dTmpQty);
                                }
                            }
                        }
                    }

                    if (sClassType != CSGC.CP_CLASS_MAGN)
                    {
                        if (MPCF.Trim(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAGN_CLASS].Text) != "")
                        {
                            sTmp = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAGN_CLASS].Text;

                            for (int k = 0; k < spdMagnet.ActiveSheet.RowCount; k++)
                            {
                                if (spdMagnet.ActiveSheet.Cells[k, (int)MAG_INFO.CLASS].Text == sTmp)
                                {
                                    dTmpQty = MPCF.ToDbl(spdMagnet.ActiveSheet.Cells[k, (int)MAG_INFO.QTY].Text);
                                    dTmpQty = dTmpQty + MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAGN_VALUE].Text);
                                    spdMagnet.ActiveSheet.SetValue(k, (int)MAG_INFO.QTY, dTmpQty);
                                }
                            }
                        }
                    }

                    if (sClassType != CSGC.CP_CLASS_CUP)
                    {
                        if (MPCF.Trim(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CUP_CLASS].Text) != "")
                        {
                            sTmp = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CUP_CLASS].Text;

                            for (int k = 0; k < spdShape.ActiveSheet.RowCount; k++)
                            {
                                if (spdShape.ActiveSheet.Cells[k, (int)SHAPE_INFO.CLASS].Text == sTmp)
                                {
                                    dTmpQty = MPCF.ToDbl(spdShape.ActiveSheet.Cells[k, (int)SHAPE_INFO.QTY].Text);
                                    dTmpQty = dTmpQty + MPCF.ToDbl(spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CUP_VALUE].Text);
                                    spdShape.ActiveSheet.SetValue(k, (int)SHAPE_INFO.QTY, dTmpQty);
                                }
                            }
                        }
                    }
                } 
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CheckPrintOption(string sOper, string sOrder)
        {
            sPrintLabelID = "";

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
                    sPrintLabelID = dt.Rows[0]["LABLE_ID"].ToString();
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void PrintLable(string sPrintLabel, TRSNode out_node)
        {
            try
            {
                TRSNode print_node = new TRSNode("Print_In");
                TRSNode Print_Lot_list;
                MPCR.SetInMsg(print_node);

                for (int i = 0; i < out_node.GetList("LOT_TBL").Count; i++)
                {                    
                    Print_Lot_list = print_node.AddNode("LOT_LIST");
                    Print_Lot_list.AddString("LOT_ID", out_node.GetList("LOT_TBL")[i].GetString("LOT_ID"));                                           
                }

                CSCF.ViewLabelList(sPrintLabel, print_node);
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
            int iLotCount = 0;
            int iWorkerCount = 0;
            double d_ClassSumQty = 0;
            string stmpMat = "";
            string stmpOper = "";

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

                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return false;
                }

                switch (CHECK)
                {
                    case CSGC.CHECK.START:

                        //MFO에 설비가 등록되어 있는 공정인지 체크한다.
                        if (CheckOperResource(cdvOper.Text) > 0)
                        {
                            if (MPCF.Trim(cdvResource.Text) == "")
                            {
                                //CMN428 CONFIRM - 설비 정보가 입력되지 않았습니다.
                                MPCF.ShowMsgBox(MPCF.GetMessage(428));
                                cdvResource.Focus();
                                return false;
                            }
                        }

                        for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                        {
                            if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                                iLotCount++;
                        }

                        if (iLotCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305));
                            return false;
                        }

                        break;

                    case CSGC.CHECK.END:

                        //MFO에 설비가 등록되어 있는 공정인지 체크한다.
                        if (CheckOperResource(cdvOper.Text) > 0)
                        {
                            if (MPCF.Trim(cdvResource.Text) == "")
                            {
                                //CMN428 CONFIRM - 설비 정보가 입력되지 않았습니다.
                                MPCF.ShowMsgBox(MPCF.GetMessage(428));
                                cdvResource.Focus();
                                return false;
                            }
                        }

                        //lot 체크
                        for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                        {
                            if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                                iLotCount++;
                        }

                        if (iLotCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + grpLotInfo.Text + "]");
                            return false;
                        }

                        if (iLotCount > 1)
                        {
                            //CMN134 ERROR - 선택된 아이템의 개수가 최대 개수를 초과했습니다.
                            MPCF.ShowMsgBox(MPCF.GetMessage(134) + " [ 1 ]");
                            return false;
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

                        if (sClassType == CSGC.CP_CLASS_SIZE)
                        {
                            for (int i = 0; i < spdSize.ActiveSheet.RowCount; i++)
                            {
                                if (MPCF.ToDbl(spdSize.ActiveSheet.Cells[i, (int)SIZE_INFO.QTY].Text) != 0 &&
                                    MPCF.Trim(spdSize.ActiveSheet.Cells[i, (int)SIZE_INFO.LOSS_CONFIRM_CODE].Text) == "")
                                {
                                    //CMN497 INFO - 손실 여부를 선택하지 않았습니다. 손실여부를 확인해 주세요.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(497));
                                    return false;
                                }

                                d_ClassSumQty = d_ClassSumQty + MPCF.ToDbl(spdSize.ActiveSheet.Cells[i, (int)SIZE_INFO.QTY].Text);
                            }
                        }
                        else if (sClassType == CSGC.CP_CLASS_MAGN)
                        {
                            for (int i = 0; i < spdMagnet.ActiveSheet.RowCount; i++)
                            {
                                d_ClassSumQty = d_ClassSumQty + MPCF.ToDbl(spdMagnet.ActiveSheet.Cells[i, (int)MAG_INFO.QTY].Text);

                            }
                        }
                        else if (sClassType == CSGC.CP_CLASS_CUP)
                        {
                            for (int i = 0; i < spdShape.ActiveSheet.RowCount; i++)
                            {
                                if (MPCF.ToDbl(spdShape.ActiveSheet.Cells[i, (int)SHAPE_INFO.QTY].Text) != 0 &&
                                    MPCF.Trim(spdShape.ActiveSheet.Cells[i, (int)SHAPE_INFO.LOSS_CONFIRM_CODE].Text) == "")
                                {
                                    //CMN497 INFO - 손실 여부를 선택하지 않았습니다. 손실여부를 확인해 주세요.
                                    MPCF.ShowMsgBox(MPCF.GetMessage(497));
                                    return false;
                                }

                                d_ClassSumQty = d_ClassSumQty + MPCF.ToDbl(spdShape.ActiveSheet.Cells[i, (int)SHAPE_INFO.QTY].Text);
                            }
                        }

                        if (sClassType == CSGC.CP_CLASS_CUP || sClassType == CSGC.CP_CLASS_SIZE || sClassType == CSGC.CP_CLASS_MAGN)
                        {
                            if (d_ClassSumQty != MPCF.ToDbl(txtSumQty.Text))
                            {
                                //CMN464 INFO  -  분류 수량과 lot의 수량이 일치하지 않습니다. 수량을 확인하세요.
                                MPCF.ShowMsgBox(MPCF.GetMessage(464));
                                return false;
                            }
                        }

                        break;

                    case CSGC.CHECK.SAVE:

                        //lot 체크
                        for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                        {
                            if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                                iLotCount++;
                        }

                        if (iLotCount == 0)
                        {
                            //CMN305 ERROR - 최소한 1개 이상의 아이템을 입력해 주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(305) + " [" + grpLotInfo.Text + "]");
                            return false;
                        }

                        for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                        {
                            if (i == 0)
                            {
                                stmpMat = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Text;
                                stmpOper = spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.OPER].Text;
                                continue;
                            }

                            if (spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.MAT_ID].Text != stmpMat ||
                                spdLotList.ActiveSheet.Cells[0, (int)LOT_INFO.OPER].Text != stmpOper)
                            {
                                //CMN512 INFO - 품목 또는 공정이 다르면 Lot을 병합 할 수 없습니다.
                                MPCF.ShowMsgBox(MPCF.GetMessage(512));
                                return false;
                            }
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

        //조기화 함수
        private void ClearData(string sType)
        {
            try
            {                
                switch (sType)
                {
                    case "ALL":

                        cdvResource.Text = "";

                        txtLotID.Text = "";
                        txtSumQty.Text = "0";                                                
                        cdvWorkGroup.Text = "";

                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdWorkerList);
                        MPCF.ClearList(spdSize);
                        MPCF.ClearList(spdMagnet);
                        MPCF.ClearList(spdShape);

                        break;

                    case "END":

                        txtLotID.Text = "";
                        txtSumQty.Text = "0";

                        MPCF.ClearList(spdLotList);
                        MPCF.ClearList(spdWorkerList);
                        MPCF.ClearList(spdSize);
                        MPCF.ClearList(spdMagnet);
                        MPCF.ClearList(spdShape);

                        break;
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        // 라벨 출력
        public bool ViewPrintLabel()
        {
            try
            {
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                string file_name = "prd205p";

                MPCR.SetInMsg(in_node);

                for (int i = 0; i < spdLotList_Sheet1.RowCount; i++)
                {
                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        label_list = in_node.AddNode("LOT_LIST");
                        label_list.AddString("LOT_ID", spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_ID].Text);
                    }
                }

                CSCF.ViewLabelList(file_name, in_node);
                
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //공정별 설비 유무 체크
        private int CheckOperResource(string sOper)
        {
            int iResult = 0;

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP0001-005", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return iResult;
                }

                if (dt.Rows.Count > 0)
                {
                    iResult = MPCF.ToInt(dt.Rows[0]["RES_COUNT"].ToString());
                }

                return iResult;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return iResult;
            }
        }

        #endregion

        #region " Event Definition "

        private void frmTranGritClassificationProcess_Load(object sender, EventArgs e)
        {
            try
            {
                // 20.12.21 minjae.go
                MPCF.FitColumnHeader(spdLotList);
                MPCF.FitColumnHeader(spdWorkerList);
                MPCF.FitColumnHeader(spdSize);
                MPCF.FitColumnHeader(spdMagnet);
                MPCF.FitColumnHeader(spdShape);
                //
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvWorkPlace_ButtonPress(object sender, EventArgs e)
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

                cdvWorkPlace.Init();
                MPCF.InitListView(cdvWorkPlace.GetListView);
                cdvWorkPlace.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWorkPlace.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvWorkPlace.SelectedSubItemIndex = 0;
                cdvWorkPlace.DisplaySubItemIndex = 1;

                if (ViewSubArea_Class(cdvWorkPlace.GetListView, cdvDept.Text) == false)
                {
                    return;
                }

                cdvWorkPlace.InsertEmptyRow(0, 1);
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
                if (MPCF.Trim(cdvOper.Text) != "")
                {
                    MPCF.ClearList(spdLotList);
                    cdvResource.Text = "";
                    fnCheckClass();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOper_TextBoxTextChanged(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) != "")
                {
                    MPCF.ClearList(spdLotList);
                    cdvResource.Text = "";
                    fnCheckClass();
                }
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
                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }

                cdvResource.Init();
                MPCF.InitListView(cdvResource.GetListView);
                cdvResource.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvResource.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvResource.SelectedSubItemIndex = 0;
                cdvResource.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewResourceList(cdvResource.GetListView, '1', cdvOper.Text) == false)
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
                if (MPCF.Trim(cdvResource.Text) != "")
                {
                    ViewLotInfo("", '4');
                }
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
                cdvWorkGroup.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvWorkGroup.Columns.Add("Desc", 100, HorizontalAlignment.Left);
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
                if (MPCF.Trim(cdvWorkGroup.Text) != "")
                    ViewWorkerList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            char s_step = ' ';

            try
            {
                if (e.KeyChar == (char)13)
                {
                    if (MPCF.Trim(txtLotID.Text) == "")
                        return;

                    if (fnCheckINVLot() == true)
                        s_step = '2';
                    else
                        s_step = '1';

                    ViewLotInfo(txtLotID.Text, s_step);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void txtLotID_ButtonClick(object sender, Infragistics.Win.Misc.AlertButtonClickedEventArgs e)
        {
            try
            {
                txtLotID.sArea_id = cdvDept.Text;
                txtLotID.sArea_desc = cdvDept.DisplayText;
                txtLotID.sSub_Area_id = cdvWorkPlace.Text;
                txtLotID.sSub_Area_desc = cdvWorkPlace.DisplayText;
                txtLotID.sOper_id = cdvOper.Text;
                txtLotID.sOper_desc = cdvOper.DisplayText;
                txtLotID.sRes_id = cdvResource.Text;
                txtLotID.sRes_desc = cdvResource.DisplayText;
                //txtLotID.sOrder = cdvOrder.Text;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdShape_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                if (e.Column == (int)SHAPE_INFO.LOSS_CONFIRM_SELECT)
                {

                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                    
                    if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', CSGC.CP_GCM_GRIT_CLASS_JUDGE) == false)
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

        private void spdSize_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                if (e.Column == (int)SHAPE_INFO.LOSS_CONFIRM_SELECT)
                {

                    cdvGridButton.Init();
                    MPCF.InitListView(cdvGridButton.GetListView);
                    cdvGridButton.Columns.Add("Code", 50, HorizontalAlignment.Left);
                    cdvGridButton.Columns.Add("Desc", 100, HorizontalAlignment.Left);

                    if (BASLIST.ViewGCMDataList(cdvGridButton.GetListView, '1', CSGC.CP_GCM_GRIT_CLASS_JUDGE) == false)
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

        private void cdvGridButton_SelectedItemChanged(object sender, Miracom.UI.MCSSCodeViewSelChanged_EventArgs e)
        {
            try
            {
                if (spdShape.ActiveSheet.ActiveColumnIndex == (int)SHAPE_INFO.LOSS_CONFIRM_SELECT)
                {
                    spdShape.ActiveSheet.SetValue(e.Row, (int)SHAPE_INFO.LOSS_CONFIRM_CODE, e.SelectedItem.SubItems[0].Text);
                    spdShape.ActiveSheet.SetValue(e.Row, (int)SHAPE_INFO.LOSS_CONFIRM_NAME, e.SelectedItem.SubItems[1].Text);
                }
                else if (spdSize.ActiveSheet.ActiveColumnIndex == (int)SIZE_INFO.LOSS_CONFIRM_SELECT)
                {
                    spdSize.ActiveSheet.SetValue(e.Row, (int)SIZE_INFO.LOSS_CONFIRM_CODE, e.SelectedItem.SubItems[0].Text);
                    spdSize.ActiveSheet.SetValue(e.Row, (int)SIZE_INFO.LOSS_CONFIRM_NAME, e.SelectedItem.SubItems[1].Text);
                }
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
                for (int i = spdLotList.ActiveSheet.RowCount; i > 0; i--)
                {
                    if (spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_INFO.CHK].Value.ToString().ToUpper() == "TRUE")
                    {
                        spdLotList.ActiveSheet.RemoveRows(i - 1, 1);
                    }
                }

                CalSumQty();
                CalClassQty();

                if (spdLotList.ActiveSheet.RowCount == 0)
                {
                    for (int k = 0; k < spdSize.ActiveSheet.RowCount; k++)
                    {
                        spdSize.ActiveSheet.Cells[k, (int)SIZE_INFO.CLASS_DESC].Font = new Font(this.Font, FontStyle.Regular);
                    }
                    for (int k = 0; k < spdMagnet.ActiveSheet.RowCount; k++)
                    {
                        spdMagnet.ActiveSheet.Cells[k, (int)MAG_INFO.CLASS_DESC].Font = new Font(this.Font, FontStyle.Regular);
                    }
                    for (int k = 0; k < spdShape.ActiveSheet.RowCount; k++)
                    {
                        spdShape.ActiveSheet.Cells[k, (int)SHAPE_INFO.CLASS_DESC].Font = new Font(this.Font, FontStyle.Regular);
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //merge  버튼 클릭
        private void btnMerge_Click(object sender, EventArgs e)
        {
            try
            {
                try
                {
                    if (CheckCondition(CSGC.CHECK.SAVE) == false)
                        return;

                    if (MergeLot('3'))
                    {
                        MPCF.ClearList(spdLotList);
                        ViewLotInfo(txtLotID.Text, '1');
                    }
                }
                catch (Exception ex)
                {
                    MPCF.ShowMsgBox(ex.Message);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //작업자 버튼 클릭
        private void btnWorker_Click(object sender, EventArgs e)
        {
            try
            {
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
                }
                else
                    return;

                ViewWorkerList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //비가동 버튼 클릭
        private void btnNonOper_Click(object sender, EventArgs e)
        {
            try
            {
                frmTranNonOperation popup = new frmTranNonOperation();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.cdvDept.Text = cdvDept.Text;
                popup.cdvDept.DisplayText = cdvDept.DisplayText;
                popup.cdvWorkPlace.Text = cdvWorkPlace.Text;
                popup.cdvWorkPlace.DisplayText = cdvWorkPlace.DisplayText;
                popup.cdvOper.Text = cdvOper.Text;
                popup.cdvOper.DisplayText = cdvOper.DisplayText;
                popup.cdvResource.Text = cdvResource.Text;
                popup.cdvResource.DisplayText = cdvResource.DisplayText;

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

        //lot data 버튼 클릭
        private void btnLotData_Click(object sender, EventArgs e)
        {
            try
            {
                frmTranInputLotData popup = new frmTranInputLotData();
                popup.StartPosition = FormStartPosition.CenterParent;

                popup.cdvDept.Text = cdvDept.Text;
                popup.cdvDept.DisplayText = cdvDept.DisplayText;
                popup.cdvWorkPlace.Text = cdvWorkPlace.Text;
                popup.cdvWorkPlace.DisplayText = cdvWorkPlace.DisplayText;
                popup.cdvOper.Text = cdvOper.Text;
                popup.cdvOper.DisplayText = cdvOper.DisplayText;
                popup.cdvResource.Text = cdvResource.Text;
                popup.cdvResource.DisplayText = cdvResource.DisplayText;
                popup.txtLotID.Text = spdLotList.ActiveSheet.Cells[spdLotList.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text;

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

        //초기화 버튼 클릭
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

        //조회 버튼 클릭
        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //시작 버튼 클릭
        private void btnStart_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.START) == false)
                    return;

                if (SaveProcess('1'))
                {
                    MPCF.ClearList(spdLotList);
                    ViewLotInfo(txtLotID.Text, '1');
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //완료 버튼 클릭
        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.END) == false)
                    return;

                if (SaveProcess('2'))
                {
                    ClearData("END");
                    fnCheckClass();
                    ViewWorkerList();
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
                if (ViewPrintLabel())
                {
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        #endregion


    }
}
