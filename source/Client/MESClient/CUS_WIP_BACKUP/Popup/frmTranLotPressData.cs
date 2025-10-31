using System;
using System.Data;
using System.Drawing;
using System.Collections.Generic;
using System.Windows.Forms;
using FarPoint.Win.Spread;

using CUS_COM;
using Miracom.CliFrx;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.DNMCore;

namespace CUS_WIP
{
    public partial class frmTranLotPressData : frmTranForm01
    {
        public frmTranLotPressData()
        {
            InitializeComponent();

            InitControl();
        }

        #region Constant

        // 작업자 정보
        private enum LOT_PRESS_INFO : int
        {
            CHECK,              // 1 : 선택
            LOT_ID,             // 2 : LOT번호
            HIST_SEQ,           // 3 : 이력순번
            PROFILE,            // 4 : 프로파일
            STEP,               // 5 : 순번
            PERIOD_SEC,         // 6 : 주기SECs
            OPER,               // 7 : 창고
            MAT_ID,             // 8 : 품목코드
            FLOW,               // 9 : 플로우
            FLOW_SEQ_NUM,       // 10 : 플로우공정 순번
            GRADE,              // 11 : 등급
            RES_ID,             // 12 : 설비코드
            WORK_DATE,          // 13 : 작업날짜 
            WORK_SHIFT,         // 14 : 작업조 
            PRESSURE_S,         // 15: 압력 설정  
            PRESSURE_C,         // 16: 압력 현재  
            POWER_S,            // 17: 전력 설정  
            POWER_C,            // 18: 전력 현재
            CURRENT_S,          // 19: 전류 설정    
            CURRENT_C,          // 20: 전류 현재
            VOLTAGE_C,          // 21: 전압 현재     
            RESITANCE_C,        // 22: 저항 현재
            INCH1,              // 23: 인치1     
            INCH2,              // 24: 인치2
            PROCESS_TIME,       // 25: 수집시간_처리시간
            MOLD_TEMP,          // 26: 금형온도
        }

        #endregion

        #region Variable

        public string c_Area= "";
        public string c_Area_desc = "";
        public string c_Sub_area_id = "";
        public string c_Sub_area_desc = "";
        public string c_Oper_id = "";
        public string c_Oper_desc = "";
        public string c_ResId = "";
        public string c_Res_desc = "";
        public string c_Profile = "";
        #endregion

        #region Function
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
                SheetView sv = spdPressData.ActiveSheet;

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        if (MPCF.Trim(txtLotID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotId.Text + "]");
                            txtLotID.Focus();
                            return false;
                        }

                        break;

                    case CSGC.CHECK.SAVE:

                        if (sv.Rows.Count <= 0)
                        {
                            //CMN466 INFO - 리스트가 존재하지 않습니다. 확인해주세요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(466));
                            cdvDept.Focus();
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

        public  bool ViewProFile(Control control)
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
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2018-002", dvcArgu, false, false, ref sSql) == false)
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
                        itmX = new ListViewItem(row["KEY_2"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

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

        private bool ViewLotPressList()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                SheetView sv = spdPressData.ActiveSheet;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '1'; //Valid 후 View데이터 가져옴

                in_node.AddString("LOT_ID", MPCF.Trim(txtLotID.Text));          //LOT 번호
                in_node.AddString("AREA", cdvDept.Text);                        //사업부
                in_node.AddString("RES_ID", cdvResource.Text);                  //설비
                in_node.AddString("PROFILE", cdvProfile.Text);                  //PROFILE

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Lot_Press_Data", in_node, ref out_node) == false)
                {
                    return false;
                }

                List<TRSNode> press_lot_list = out_node.GetList("PRESS_DATA_LIST");
                int iRowHistory;

                for (int i = 0; i < press_lot_list.Count; i++)
                {
                    iRowHistory = sv.RowCount;
                    sv.RowCount++;

                    TRSNode press_node = press_lot_list[i];

                    sv.SetValue(iRowHistory, (int)LOT_PRESS_INFO.CHECK, false);
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.LOT_ID].Value = MPCF.Trim(txtLotID.Text.ToString());
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.HIST_SEQ].Value = press_node.GetInt("HIST_SEQ").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PROFILE].Value = press_node.GetString("PROFILE").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.STEP].Value = press_node.GetString("STEP").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PERIOD_SEC].Value = press_node.GetInt("PERIOD_SEC").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.OPER].Value = press_node.GetString("OPER").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.MAT_ID].Value = press_node.GetString("MAT_ID").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.FLOW].Value = press_node.GetString("FLOW").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.FLOW_SEQ_NUM].Value = press_node.GetInt("FLOW_SEQ_NUM").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.GRADE].Value = press_node.GetString("GRADE").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.RES_ID].Value = MPCF.Trim(c_ResId);
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.WORK_DATE].Value = MPCF.MakeDateFormat(press_node.GetString("WORK_TIME"), DATE_TIME_FORMAT.DATETIME);
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.WORK_SHIFT].Value = MPCF.Trim(press_node.GetString("WORK_SHIFT"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PRESSURE_S].Value = MPCF.Trim(press_node.GetDouble("PRESSURE_S"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PRESSURE_C].Value = MPCF.Trim(press_node.GetDouble("PRESSURE_C"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.POWER_S].Value = MPCF.Trim(press_node.GetDouble("POWER_S"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.POWER_C].Value = MPCF.Trim(press_node.GetDouble("POWER_C"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.CURRENT_S].Value = MPCF.Trim(press_node.GetDouble("CURRENT_S"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.CURRENT_C].Value = MPCF.Trim(press_node.GetDouble("CURRENT_C"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.VOLTAGE_C].Value = MPCF.Trim(press_node.GetDouble("VOLTAGE_C"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.RESITANCE_C].Value = MPCF.Trim(press_node.GetDouble("RESITANCE_C"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.INCH1].Value = MPCF.Trim(press_node.GetDouble("INCH1"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.INCH2].Value = MPCF.Trim(press_node.GetDouble("INCH2"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PROCESS_TIME].Value = press_node.GetString("PROCESS_TIME").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.MOLD_TEMP].Value = MPCF.Trim(press_node.GetDouble("MOLD_TEMP"));
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool ViewLotPressList_PDC()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                SheetView sv = spdPressData.ActiveSheet;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '2'; //Valid 후 View데이터 가져옴

                in_node.AddString("LOT_ID", MPCF.Trim(txtLotID.Text));          //LOT 번호
                in_node.AddString("AREA", cdvDept.Text);                        //사업부
                in_node.AddString("RES_ID", cdvResource.Text);                  //설비
                in_node.AddString("PROFILE", cdvProfile.Text);                  //PROFILE

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Lot_Press_Data", in_node, ref out_node) == false)
                {
                    return false;
                }

                List<TRSNode> press_lot_list = out_node.GetList("PRESS_DATA_LIST");
                int iRowHistory;

                for (int i = 0; i < press_lot_list.Count; i++)
                {
                    iRowHistory = sv.RowCount;
                    sv.RowCount++;

                    TRSNode press_node = press_lot_list[i];

                    sv.SetValue(iRowHistory, (int)LOT_PRESS_INFO.CHECK, false);
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.LOT_ID].Value = MPCF.Trim(txtLotID.Text.ToString());
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.HIST_SEQ].Value = press_node.GetInt("HIST_SEQ").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PROFILE].Value = press_node.GetString("PROFILE").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.STEP].Value = press_node.GetString("STEP").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PERIOD_SEC].Value = press_node.GetInt("PERIOD_SEC") == 0 ? "" : press_node.GetInt("PERIOD_SEC").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.OPER].Value = press_node.GetString("OPER").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.MAT_ID].Value = press_node.GetString("MAT_ID").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.FLOW].Value = press_node.GetString("FLOW").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.FLOW_SEQ_NUM].Value = press_node.GetInt("FLOW_SEQ_NUM").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.GRADE].Value = press_node.GetString("GRADE").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.RES_ID].Value = MPCF.Trim(c_ResId);
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.WORK_DATE].Value = MPCF.MakeDateFormat(press_node.GetString("WORK_TIME"), DATE_TIME_FORMAT.DATETIME);
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.WORK_SHIFT].Value = MPCF.Trim(press_node.GetString("WORK_SHIFT"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PRESSURE_S].Value = MPCF.Trim(press_node.GetDouble("PRESSURE_S"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PRESSURE_C].Value = MPCF.Trim(press_node.GetDouble("PRESSURE_C"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.POWER_S].Value = MPCF.Trim(press_node.GetDouble("POWER_S"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.POWER_C].Value = MPCF.Trim(press_node.GetDouble("POWER_C"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.CURRENT_S].Value = MPCF.Trim(press_node.GetDouble("CURRENT_S"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.CURRENT_C].Value = MPCF.Trim(press_node.GetDouble("CURRENT_C"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.VOLTAGE_C].Value = MPCF.Trim(press_node.GetDouble("VOLTAGE_C"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.RESITANCE_C].Value = MPCF.Trim(press_node.GetDouble("RESITANCE_C"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.INCH1].Value = MPCF.Trim(press_node.GetDouble("INCH1"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.INCH2].Value = MPCF.Trim(press_node.GetDouble("INCH2"));
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PROCESS_TIME].Value = press_node.GetString("PROCESS_TIME").ToString();
                    sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.MOLD_TEMP].Value = MPCF.Trim(press_node.GetDouble("MOLD_TEMP"));
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private bool SaveLotPress()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode lot_press_list;
                SheetView sv = spdPressData.ActiveSheet;
                int iCheckCount = 0;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '3'; //Valid 후 저장

                in_node.AddString("AREA", cdvDept.Text);                      //사업부
                in_node.AddString("PROFILE", cdvProfile.Text);                //PROFILE
                in_node.AddString("RES_ID", cdvResource.Text);                   //설비

                for (int i = 0; i < sv.RowCount; i++)
                {
                    if (Convert.ToBoolean(sv.Cells[i, (int)LOT_PRESS_INFO.CHECK] == null ? false : sv.Cells[i, (int)LOT_PRESS_INFO.CHECK].Value))
                    {
                        lot_press_list = in_node.AddNode("DATA_LIST");

                        in_node.AddString("LOT_ID", MPCF.Trim(sv.Cells[i, (int)LOT_PRESS_INFO.LOT_ID].Value));

                        lot_press_list.AddString("LOT_ID", MPCF.Trim(sv.Cells[i, (int)LOT_PRESS_INFO.LOT_ID].Value));           //LOT 번호
                        lot_press_list.AddString("STEP", MPCF.Trim(sv.Cells[i, (int)LOT_PRESS_INFO.STEP].Value));               //STEP
                        lot_press_list.AddDouble("PRESSURE_S", MPCF.ToDbl(sv.Cells[i, (int)LOT_PRESS_INFO.PRESSURE_S].Value));
                        lot_press_list.AddDouble("PRESSURE_C", MPCF.ToDbl(sv.Cells[i, (int)LOT_PRESS_INFO.PRESSURE_C].Value));
                        lot_press_list.AddDouble("POWER_S", MPCF.ToDbl(sv.Cells[i, (int)LOT_PRESS_INFO.POWER_S].Value));
                        lot_press_list.AddDouble("POWER_C", MPCF.ToDbl(sv.Cells[i, (int)LOT_PRESS_INFO.POWER_C].Value));
                        lot_press_list.AddDouble("CURRENT_S", MPCF.ToDbl(sv.Cells[i, (int)LOT_PRESS_INFO.CURRENT_S].Value));
                        lot_press_list.AddDouble("CURRENT_C", MPCF.ToDbl(sv.Cells[i, (int)LOT_PRESS_INFO.CURRENT_C].Value));
                        lot_press_list.AddDouble("VOLTAGE_C", MPCF.ToDbl(sv.Cells[i, (int)LOT_PRESS_INFO.VOLTAGE_C].Value));
                        lot_press_list.AddDouble("RESITANCE_C", MPCF.ToDbl(sv.Cells[i, (int)LOT_PRESS_INFO.RESITANCE_C].Value));
                        lot_press_list.AddDouble("INCH1", MPCF.ToDbl(sv.Cells[i, (int)LOT_PRESS_INFO.INCH1].Value));
                        lot_press_list.AddDouble("INCH2", MPCF.ToDbl(sv.Cells[i, (int)LOT_PRESS_INFO.INCH2].Value));
                        lot_press_list.AddDouble("MOLD_TEMP", MPCF.ToDbl(sv.Cells[i, (int)LOT_PRESS_INFO.MOLD_TEMP].Value));

                        iCheckCount++;
                    }
                }

                if (iCheckCount > 0)
                {
                    if (MPCR.CallService("CUS_WIP", "CUS_WIP_Lot_Press_Data", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                }
                else
                {
                    //체크항목이 존재하지 않습니다. 확인해주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(465));
                    return false;
                }

                List<TRSNode> press_lot_list = out_node.GetList("PRESS_DATA_LIST");
                int iRowList;

                for (int i = 0; i < press_lot_list.Count; i++)
                {
                    iRowList = sv.RowCount;
                    sv.RowCount++;

                    TRSNode press_node = press_lot_list[i];

                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.LOT_ID].Value = MPCF.Trim(txtLotID.Text.ToString());
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.HIST_SEQ].Value = press_node.GetInt("HIST_SEQ").ToString();
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.PROFILE].Value = press_node.GetString("PROFILE").ToString();
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.STEP].Value = press_node.GetString("STEP").ToString();
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.PERIOD_SEC].Value = press_node.GetInt("PERIOD_SEC").ToString();
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.OPER].Value = press_node.GetString("OPER").ToString();
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.MAT_ID].Value = press_node.GetString("MAT_ID").ToString();
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.FLOW].Value = press_node.GetString("FLOW").ToString();
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.FLOW_SEQ_NUM].Value = press_node.GetInt("FLOW_SEQ_NUM").ToString();
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.GRADE].Value = press_node.GetString("GRADE").ToString();
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.RES_ID].Value = MPCF.Trim(c_ResId);
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.WORK_DATE].Value = MPCF.MakeDateFormat(press_node.GetString("WORK_DATE"), DATE_TIME_FORMAT.DATETIME);
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.WORK_SHIFT].Value = MPCF.Trim(press_node.GetString("WORK_SHIFT"));
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.PRESSURE_S].Value = MPCF.Trim(press_node.GetDouble("PRESSURE_S"));
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.PRESSURE_C].Value = MPCF.Trim(press_node.GetDouble("PRESSURE_C"));
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.POWER_S].Value = MPCF.Trim(press_node.GetDouble("POWER_S"));
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.POWER_C].Value = MPCF.Trim(press_node.GetDouble("POWER_C"));
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.CURRENT_S].Value = MPCF.Trim(press_node.GetDouble("CURRENT_S"));
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.CURRENT_C].Value = MPCF.Trim(press_node.GetDouble("CURRENT_C"));
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.VOLTAGE_C].Value = MPCF.Trim(press_node.GetDouble("VOLTAGE_C"));
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.RESITANCE_C].Value = MPCF.Trim(press_node.GetDouble("RESITANCE_C"));
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.INCH1].Value = MPCF.Trim(press_node.GetDouble("INCH1"));
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.INCH2].Value = MPCF.Trim(press_node.GetDouble("INCH2"));
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.PROCESS_TIME].Value = press_node.GetString("PROCESS_TIME").ToString();
                    sv.Cells[iRowList, (int)LOT_PRESS_INFO.MOLD_TEMP].Value = MPCF.Trim(press_node.GetDouble("MOLD_TEMP"));
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


        #region Grid / Button Event

        private void frmTranLotPressData_Load(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Text = c_Area;
                cdvDept.DisplayText = c_Area_desc;
                cdvWorkPlace.Text = c_Sub_area_id;
                cdvWorkPlace.DisplayText = c_Sub_area_desc;
                cdvOper.Text = c_Oper_id;
                cdvOper.DisplayText = c_Oper_desc;
                cdvProfile.Text = c_Profile;
                cdvResource.Text = c_ResId;
                cdvResource.DisplayText = c_Res_desc;

                SheetView sv = spdPressData.ActiveSheet;
                bool bLock = false;

                //수동 설비인지 자동 설비인지 체크 로직 필요
                //if (c_Area != CSGC.CP_AREA_PDC)
                //{
                //    bLock = true;
                //}

                sv.ColumnHeader.Cells[0, (int)LOT_PRESS_INFO.CHECK].Locked = bLock;
                sv.Columns[(int)LOT_PRESS_INFO.CHECK].Locked = bLock;
                sv.Columns[(int)LOT_PRESS_INFO.PRESSURE_S].Locked = bLock;
                sv.Columns[(int)LOT_PRESS_INFO.PRESSURE_C].Locked = bLock;
                sv.Columns[(int)LOT_PRESS_INFO.POWER_S].Locked = bLock;
                sv.Columns[(int)LOT_PRESS_INFO.POWER_C].Locked = bLock;
                sv.Columns[(int)LOT_PRESS_INFO.CURRENT_S].Locked = bLock;
                sv.Columns[(int)LOT_PRESS_INFO.CURRENT_C].Locked = bLock;
                sv.Columns[(int)LOT_PRESS_INFO.VOLTAGE_C].Locked = bLock;
                sv.Columns[(int)LOT_PRESS_INFO.RESITANCE_C].Locked = bLock;
                sv.Columns[(int)LOT_PRESS_INFO.MOLD_TEMP].Locked = bLock;
                btnProcess.Enabled = !bLock;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
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

        private void cdvProfile_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvProfile.Init();
                MPCF.InitListView(cdvProfile.GetListView);
                cdvProfile.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvProfile.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvProfile.SelectedSubItemIndex = 0;
                cdvProfile.DisplaySubItemIndex = 1;

                if (ViewProFile(cdvProfile.GetListView) == false)
                    return;

                cdvProfile.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdPressData_CellClick(object sender, CellClickEventArgs e)
        {
            try
            {
                if (e.ColumnHeader == true)
                {
                    if (e.Column == (int)LOT_PRESS_INFO.CHECK)
                    {
                        CSCF.CheckSpreadCell(spdPressData, 0, 0, true, true);
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

                MPCF.ClearList(spdPressData);

                if(c_Area != CSGC.CP_AREA_PDC)
                {
                    ViewLotPressList();
                }
                else
                {
                    ViewLotPressList_PDC();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;

                if (SaveLotPress())
                {
                    MPCF.ClearList(spdPressData);

                    ViewLotPressList_PDC();

                    MPCF.ShowMsgBox(MPCF.GetMessage(52));
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
