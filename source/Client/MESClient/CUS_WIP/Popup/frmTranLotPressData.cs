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
            RES_ID,             // 12 : 설비코드
            PROCESS_TIME,       // 13: 수집시간_처리시간
            WORK_DATE,          // 14 : 작업날짜 
            WORK_SHIFT,         // 15 : 작업조 
            PRESSURE_S,         // 16: 압력 설정  
            PRESSURE_C,         // 17: 압력 현재  
            POWER_S,            // 18: 전력 설정  
            POWER_C,            // 19: 전력 현재
            CURRENT_S,          // 20: 전류 설정    
            CURRENT_C,          // 21: 전류 현재
            VOLTAGE_C,          // 22: 전압 현재     
            RESITANCE_C,        // 23: 저항 현재
            INCH1,              // 24: 인치1     
            INCH2,              // 25: 인치2
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
        public bool b_Auto_Res_Flag = false;
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

                        if (MPCF.Trim(txtLotID.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblLotId.Text + "]");
                            txtLotID.Focus();
                            return false;
                        }

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

        public bool ViewProfile()
        {
            try
            {
                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = cdvDept.Text;

                dvcArgu[2].sCondition_ID = "LOT_ID";
                dvcArgu[2].sCondition_Value = txtLotID.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2018-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }
                
                cdvProfileData.Text = dt.Rows[0]["KEY_2"].ToString();
                cdvProfileData.DisplayText = dt.Rows[0]["DATA_1"].ToString();


                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }            
        }

        public  bool ViewProFileList(Control control)
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
                // Lot의 Profile 조회
                ViewProfile();

                MPCF.ClearList(spdPressData);
                
                if(b_Auto_Res_Flag == true)
                {
                    TRSNode in_node = new TRSNode("TRAN_IN");
                    TRSNode out_node = new TRSNode("TRAN_OUT");
                    SheetView sv = spdPressData.ActiveSheet;

                    MPCR.SetInMsg(in_node);

                    in_node.ProcStep = '1'; //Valid 후 View데이터 가져옴

                    in_node.AddString("LOT_ID", MPCF.Trim(txtLotID.Text));          //LOT 번호
                    in_node.AddString("AREA", cdvDept.Text);                        //사업부
                    in_node.AddString("RES_ID", cdvResource.Text);                  //설비
                    in_node.AddString("PROFILE", cdvProfileData.Text);                  //PROFILE

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
                        sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.RES_ID].Value = MPCF.Trim(c_ResId);
                        sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PROCESS_TIME].Value = press_node.GetString("PROCESS_TIME").ToString();
                        sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.WORK_DATE].Value = MPCF.MakeDateFormat(press_node.GetString("WORK_TIME"), DATE_TIME_FORMAT.DATETIME);
                        sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.WORK_SHIFT].Value = MPCF.Trim(press_node.GetString("DAY_NIGHT"));
                        sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PRESSURE_S].Value = press_node.GetDouble("PRESSURE_S");
                        sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PRESSURE_C].Value = press_node.GetDouble("PRESSURE_C");
                        sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.POWER_S].Value = press_node.GetDouble("POWER_S");
                        sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.POWER_C].Value = press_node.GetDouble("POWER_C");
                        sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.CURRENT_S].Value = press_node.GetDouble("CURRENT_S");
                        sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.CURRENT_C].Value = press_node.GetDouble("CURRENT_C");
                        sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.VOLTAGE_C].Value = press_node.GetDouble("VOLTAGE_C");
                        sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.RESITANCE_C].Value = press_node.GetDouble("RESITANCE_C");
                        sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.INCH1].Value = press_node.GetDouble("INCH1");
                        sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.INCH2].Value = press_node.GetDouble("INCH2");
                        sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.MOLD_TEMP].Value = press_node.GetDouble("MOLD_TEMP");
                    }

                    MPCF.FitColumnHeader(spdPressData);
                }
                else
                {
                    TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[6];
                    DataTable dt = null;
                    string sSql = "";

                    dvcArgu[0].sCondition_ID = "FACTORY";
                    dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                    dvcArgu[1].sCondition_ID = "RES_ID";
                    dvcArgu[1].sCondition_Value = cdvResource.Text;

                    dvcArgu[2].sCondition_ID = "OPER";
                    dvcArgu[2].sCondition_Value = cdvOper.Text;

                    dvcArgu[3].sCondition_ID = "AREA_ID";
                    dvcArgu[3].sCondition_Value = cdvDept.Text;

                    dvcArgu[4].sCondition_ID = "PROFILE_DATA";
                    dvcArgu[4].sCondition_Value = cdvProfileData.Text;

                    dvcArgu[5].sCondition_ID = "LOT_ID";
                    dvcArgu[5].sCondition_Value = txtLotID.Text;

                    if (TPDR.GetDataOne("", ref dt, "CWIP2018-005", dvcArgu, false, false, ref sSql) == false)
                    {
                        if (dt != null)
                            dt.Dispose();

                        GC.Collect();

                        MPCF.ClearList(spdPressData);
                        return false;
                    }

                    MPCF.ClearList(spdPressData);

                    for (int i = 0; i < dt.Rows.Count; i++)
                    {
                        spdPressData_Sheet1.RowCount++;

                        spdPressData_Sheet1.SetValue(i, (int)LOT_PRESS_INFO.CHECK, false);
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.HIST_SEQ].Value = dt.Rows[i]["HIST_SEQ"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.PROFILE].Value = dt.Rows[i]["PROFILE"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.STEP].Value = dt.Rows[i]["STEP"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.PERIOD_SEC].Value = dt.Rows[i]["PERIOD_SEC"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.OPER].Value = dt.Rows[i]["OPER"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.FLOW].Value = dt.Rows[i]["FLOW"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.FLOW_SEQ_NUM].Value = dt.Rows[i]["FLOW_SEQ_NUM"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.RES_ID].Value = dt.Rows[i]["RES_ID"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.PROCESS_TIME].Value = MPCF.MakeDateFormat(dt.Rows[i]["PROCESS_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.WORK_DATE].Value = MPCF.MakeDateFormat(dt.Rows[i]["WORK_TIME"].ToString(), DATE_TIME_FORMAT.DATETIME);
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.WORK_SHIFT].Value = dt.Rows[i]["DAY_NIGHT"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.PRESSURE_S].Value = dt.Rows[i]["PRESSURE_S"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.PRESSURE_C].Value = dt.Rows[i]["PRESSURE_C"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.POWER_S].Value = dt.Rows[i]["POWER_S"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.POWER_C].Value = dt.Rows[i]["POWER_C"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.CURRENT_S].Value = dt.Rows[i]["CURRENT_S"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.CURRENT_C].Value = dt.Rows[i]["CURRENT_C"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.VOLTAGE_C].Value = dt.Rows[i]["VOLTAGE_C"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.RESITANCE_C].Value = dt.Rows[i]["RESITANCE_C"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.INCH1].Value = dt.Rows[i]["INCH_1"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.INCH2].Value = dt.Rows[i]["INCH_2"];
                        spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.MOLD_TEMP].Value = dt.Rows[i]["MOLD_TEMP"];
                    }

                    MPCF.FitColumnHeader(spdPressData);
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //private bool ViewLotPressList_PDC()
        //{
        //    try
        //    {
        //        TRSNode in_node = new TRSNode("TRAN_IN");
        //        TRSNode out_node = new TRSNode("TRAN_OUT");
        //        SheetView sv = spdPressData.ActiveSheet;

        //        MPCR.SetInMsg(in_node);

        //        in_node.ProcStep = '2'; //Valid 후 View데이터 가져옴

        //        in_node.AddString("LOT_ID", MPCF.Trim(txtLotID.Text));          //LOT 번호
        //        in_node.AddString("AREA", cdvDept.Text);                        //사업부
        //        in_node.AddString("RES_ID", cdvResource.Text);                  //설비
        //        in_node.AddString("PROFILE", cdvProfile.Text);                  //PROFILE

        //        if (MPCR.CallService("CUS_WIP", "CUS_WIP_Lot_Press_Data", in_node, ref out_node) == false)
        //        {
        //            return false;
        //        }

        //        List<TRSNode> press_lot_list = out_node.GetList("PRESS_DATA_LIST");
        //        int iRowHistory;

        //        for (int i = 0; i < press_lot_list.Count; i++)
        //        {
        //            iRowHistory = sv.RowCount;
        //            sv.RowCount++;

        //            TRSNode press_node = press_lot_list[i];

        //            sv.SetValue(iRowHistory, (int)LOT_PRESS_INFO.CHECK, false);
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.LOT_ID].Value = MPCF.Trim(txtLotID.Text.ToString());
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.HIST_SEQ].Value = press_node.GetInt("HIST_SEQ").ToString();
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PROFILE].Value = press_node.GetString("PROFILE").ToString();
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.STEP].Value = press_node.GetString("STEP").ToString();
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PERIOD_SEC].Value = press_node.GetInt("PERIOD_SEC") == 0 ? "" : press_node.GetInt("PERIOD_SEC").ToString();
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.OPER].Value = press_node.GetString("OPER").ToString();
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.MAT_ID].Value = press_node.GetString("MAT_ID").ToString();
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.FLOW].Value = press_node.GetString("FLOW").ToString();
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.FLOW_SEQ_NUM].Value = press_node.GetInt("FLOW_SEQ_NUM").ToString();
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.RES_ID].Value = MPCF.Trim(c_ResId);
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.WORK_DATE].Value = MPCF.MakeDateFormat(press_node.GetString("WORK_TIME"), DATE_TIME_FORMAT.DATETIME);
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.WORK_SHIFT].Value = MPCF.Trim(press_node.GetString("WORK_SHIFT"));
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PRESSURE_S].Value = MPCF.Trim(press_node.GetDouble("PRESSURE_S"));
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PRESSURE_C].Value = MPCF.Trim(press_node.GetDouble("PRESSURE_C"));
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.POWER_S].Value = MPCF.Trim(press_node.GetDouble("POWER_S"));
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.POWER_C].Value = MPCF.Trim(press_node.GetDouble("POWER_C"));
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.CURRENT_S].Value = MPCF.Trim(press_node.GetDouble("CURRENT_S"));
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.CURRENT_C].Value = MPCF.Trim(press_node.GetDouble("CURRENT_C"));
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.VOLTAGE_C].Value = MPCF.Trim(press_node.GetDouble("VOLTAGE_C"));
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.RESITANCE_C].Value = MPCF.Trim(press_node.GetDouble("RESITANCE_C"));
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.INCH1].Value = MPCF.Trim(press_node.GetDouble("INCH1"));
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.INCH2].Value = MPCF.Trim(press_node.GetDouble("INCH2"));
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.PROCESS_TIME].Value = press_node.GetString("PROCESS_TIME").ToString();
        //            sv.Cells[iRowHistory, (int)LOT_PRESS_INFO.MOLD_TEMP].Value = MPCF.Trim(press_node.GetDouble("MOLD_TEMP"));
        //        }

        //        return true;
        //    }
        //    catch (Exception ex)
        //    {
        //        MPCF.ShowMsgBox(ex.Message);
        //        return false;
        //    }
        //}

        private bool SaveLotPress()
        {
            try
            {
                TRSNode in_node = new TRSNode("TRAN_IN");
                TRSNode out_node = new TRSNode("TRAN_OUT");
                TRSNode lot_press_list;
                int iCheckCount = 0;

                MPCR.SetInMsg(in_node);

                in_node.ProcStep = '3'; //Valid 후 저장
                in_node.AddString("AREA", cdvDept.Text);                      //사업부
                in_node.AddString("PROFILE", cdvProfileData.Text);                //PROFILE
                in_node.AddString("RES_ID", cdvResource.Text);                   //설비
                in_node.AddString("LOT_ID", txtLotID.Text);

                for (int i = 0; i < spdPressData_Sheet1.RowCount; i++)
                {
                    if (spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.CHECK].Text.ToString().ToUpper() == "TRUE")
                    {
                        lot_press_list = in_node.AddNode("DATA_LIST");
                        
                        lot_press_list.AddString("LOT_ID", MPCF.Trim(spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.LOT_ID].Value));
                        lot_press_list.AddString("STEP", MPCF.Trim(spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.STEP].Value));
                        lot_press_list.AddDouble("PRESSURE_S", MPCF.ToDbl(spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.PRESSURE_S].Value));
                        lot_press_list.AddDouble("PRESSURE_C", MPCF.ToDbl(spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.PRESSURE_C].Value));
                        lot_press_list.AddDouble("POWER_S", MPCF.ToDbl(spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.POWER_S].Value));
                        lot_press_list.AddDouble("POWER_C", MPCF.ToDbl(spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.POWER_C].Value));
                        lot_press_list.AddDouble("CURRENT_S", MPCF.ToDbl(spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.CURRENT_S].Value));
                        lot_press_list.AddDouble("CURRENT_C", MPCF.ToDbl(spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.CURRENT_C].Value));
                        lot_press_list.AddDouble("VOLTAGE_C", MPCF.ToDbl(spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.VOLTAGE_C].Value));
                        lot_press_list.AddDouble("RESITANCE_C", MPCF.ToDbl(spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.RESITANCE_C].Value));
                        lot_press_list.AddDouble("INCH1", MPCF.ToDbl(spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.INCH1].Value));
                        lot_press_list.AddDouble("INCH2", MPCF.ToDbl(spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.INCH2].Value));
                        lot_press_list.AddDouble("MOLD_TEMP", MPCF.ToDbl(spdPressData_Sheet1.Cells[i, (int)LOT_PRESS_INFO.MOLD_TEMP].Value));

                        iCheckCount++;
                    }
                }

                if (iCheckCount <= 0)
                {
                    //체크항목이 존재하지 않습니다. 확인해주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(465));
                    return false;
                }

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Lot_Press_Data", in_node, ref out_node) == false)
                    return false;

                MPCR.ShowSuccessMsg(out_node);

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        /// <summary>
        /// 자동 설비 여부 확인
        /// </summary>
        /// <param name="as_res_id"></param>
        /// <returns></returns>
        private bool isAutoResource(string as_res_id)
        {
            TRSNode in_node = new TRSNode("Res_In");
            TRSNode out_node = new TRSNode("Res_Out");

            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("RES_ID", as_res_id);

                if (MPCR.CallService("RAS", "RAS_View_Resource", in_node, ref out_node) == false)
                    return false;

                if (out_node.GetString("RES_CMF_1") == "Y")
                {
                    b_Auto_Res_Flag = true;
                    return true;
                }   
                else
                {
                    b_Auto_Res_Flag = false;
                    return false;
                }
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
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
                cdvProfileData.Text = c_Profile;
                cdvProfileData.DisplayText = "";
                cdvResource.Text = c_ResId;
                cdvResource.DisplayText = c_Res_desc;

                ViewProfile();

                SheetView sv = spdPressData.ActiveSheet;
                bool bLock = false;

                b_Auto_Res_Flag = false;

                //수동 설비인지 자동 설비인지 체크
                if (isAutoResource(c_ResId))
                    bLock = true;

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
                cdvProfileData.Init();
                MPCF.InitListView(cdvProfileData.GetListView);
                cdvProfileData.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvProfileData.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvProfileData.SelectedSubItemIndex = 0;
                cdvProfileData.DisplaySubItemIndex = 1;

                if (ViewProFileList(cdvProfileData.GetListView) == false)
                    return;

                cdvProfileData.InsertEmptyRow(0, 1);
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

                ViewLotPressList();
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
                    ViewLotPressList();

                    //MPCF.ClearList(spdPressData);

                    //ViewLotPressList_PDC();

                    //MPCF.ShowMsgBox(MPCF.GetMessage(52));
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
