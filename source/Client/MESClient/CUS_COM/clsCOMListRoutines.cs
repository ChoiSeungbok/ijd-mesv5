using System;
using System.Data;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Windows.Forms;
using System.Drawing;

using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.UI.Controls.MCCodeView;

using Miracom.TRSCore;
using Miracom.MESCore;
using Miracom.DNMCore; 

namespace CUS_COM
{
    public sealed class COM_LIST
    {

        /// <summary>
        /// 공통코드 콤보박스 클릭시 리스트 조회
        /// </summary>
        /// <param name="control"></param>
        /// <param name="sTableName"></param>
        /// <returns></returns>
        public static bool ViewGcmCodeList(Control control, string sTableName)
        {
            string sViewID = "";

            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;
                
                dvcArgu[1].sCondition_ID = "TABLE_NAME";
                dvcArgu[1].sCondition_Value = sTableName;

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
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

                            if(MPCF.Trim(row["DATA_2"].ToString()) != "")
                                itmX.SubItems.Add(row["DATA_2"].ToString());
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

        /// <summary>
        /// 공정 리스트 조회 step 1 : 사업부,사업장별 공정 조회
        ///                  step 2 : 사업부별 공정조회
        ///                  step 3 : 사업부 작업장별 자재 창고 + 생산 창고 + 위탁 창고
        ///                  step 4 : 사업부 작업장별 생산 창고
        ///                  step 5 : 사업부별 출하 창고
        ///                  step 6 : 사업부별 완제품 창고
        ///                  step 7 : 사업부에 해당하는 모든 창고
        ///                  step A : Flow별 공정조회
        ///                  step B : 사업부별 반품 창고
        ///                  step C : 사업부별 자재 창고
        ///                  step D : 사업부 작업장별 생산 창고 + 완제품 창고 + 반품 창고
        ///                  step E : 외주 공정
        ///                  step F : 사업부별 생산 창고 + 자재 창고 + 자재과 반납창고 + 위탁 창고 + 금형 창고 + 완제품 창고
        ///                  step G : 사업부별 자재 창고 + 위탁 창고
        ///                  step H : 사업부별 생산 창고 + 자재 창고 + 자재과 반납창고
        ///                  step J : P급 창고
        ///                  step K : 사업부 작업장별 생산 창고 + 완제품 창고
        ///                  step M : 사업부 작업장 별 창고 + 생산 공정
        ///                  step O : 사업부 별 자재 창고 + 생산 창고 + 완제품 창고 + 반품 창고
        ///                  step P : 사업부 별 자재 창고 + 생산 창고 + 완제품 창고
        ///                  step Q : 사업부 별 완제품 창고 + 출하 대기 창고 + 반품 창고
        ///                  step T : 사업부 작업장별 생산 창고 + 완제품 창고 + 반품 창고 + P급 창고
        ///                  step U : 사업부 별 위탁 창고 
        /// 20200721_lwg 
        /// </summary>
        /// <param name="control"></param>
        /// <param name="c_step"></param>
        /// <param name="sArea"></param>
        /// <param name="aSubArea"></param>
        /// <param name="sFlow"></param>
        /// <param name="sMatId"></param>
        /// <param name="cInv_flag"></param>
        /// <param name="Ext_Factory"></param>
        /// <returns></returns>
        public static bool ViewOperationList(Control control, char c_step, string sArea, string aSubArea = "", string sFlow = "", string sMatId = "", char cInv_flag = ' ', string Ext_Factory = "", char cEnd_Oper_flag = ' ', char cShip_flag = ' ')
        {
            int i;
            ListViewItem itmX;
            TRSNode in_node = new TRSNode("VIEW_OPERATION_LIST_IN");
            TRSNode out_node;
            
            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }
            
            MPCR.SetInMsg(in_node);
            in_node.ProcStep = c_step;

            if (Ext_Factory != "")
            {
                in_node.Factory = Ext_Factory;
            }

            in_node.AddString("AREA_ID", sArea);

            in_node.AddString("NEXT_OPER", "");

            if (c_step == '1' || c_step == 'E')
            {
                in_node.AddString("SUB_AREA_ID", aSubArea);
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == '3')
            {
                in_node.AddString("SUB_AREA_ID", aSubArea);
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == '4')
            {
                in_node.AddString("SUB_AREA_ID", aSubArea);
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == '5')
            {
                in_node.AddChar("INV_FLAG", cInv_flag);
                in_node.AddChar("SHIP_FLAG", cShip_flag);
            }
            else if (c_step == '6')
            {
                in_node.AddChar("INV_FLAG", cInv_flag);
                in_node.AddChar("END_OPER_FLAG", cEnd_Oper_flag);
            }
            else if (c_step == '7')
            {
                in_node.AddString("SUB_AREA_ID", aSubArea);
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == '9')
            {
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == 'A')
            {
                in_node.AddString("FLOW", sFlow);
            }
            else if (c_step == 'B')
            {
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == 'C')
            {
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == 'D')
            {
                in_node.AddString("SUB_AREA_ID", aSubArea);
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == 'F')
            {
                in_node.AddString("SUB_AREA_ID", aSubArea);
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == 'G')
            {
                in_node.AddString("SUB_AREA_ID", aSubArea);
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == 'H')
            {
                in_node.AddString("SUB_AREA_ID", aSubArea);
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == 'I')
            {
                in_node.AddString("SUB_AREA_ID", aSubArea);
            }
            else if (c_step == 'J')
            {
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == 'K')
            {
                in_node.AddString("SUB_AREA_ID", aSubArea);
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == 'L')
            {
            }
            else if (c_step == 'M')
            {
                in_node.AddString("SUB_AREA_ID", aSubArea);
            }
            else if (c_step == 'O')
            {
                in_node.AddString("SUB_AREA_ID", aSubArea);
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == 'P')
            {
                in_node.AddString("SUB_AREA_ID", aSubArea);
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == 'Q')
            {
                in_node.AddString("SUB_AREA_ID", aSubArea);
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == 'R')
            {
                in_node.AddString("SUB_AREA_ID", aSubArea);
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == 'T')
            {
                in_node.AddString("SUB_AREA_ID", aSubArea);
                in_node.AddChar("INV_FLAG", cInv_flag);
            }
            else if (c_step == 'U')
            {
                in_node.AddChar("INV_FLAG", cInv_flag);
            }

            do
            {
                out_node = new TRSNode("VIEW_OPERATION_LIST_OUT");

                if (MPCR.CallService("CUS_WIP", "CUS_WIP_View_Oper_List", in_node, ref out_node) == false)
                {
                    return false;
                }

                

                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(out_node.GetList(0)[i].GetString("OPER"), (int)SMALLICON_INDEX.IDX_OPER);
                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetString("OPER_DESC"));
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetString("OPER_SHORT_DESC"));
                        }

                        ((ListView)control).Items.Add(itmX);                        
                    }                
                }

                in_node.SetString("NEXT_OPER", out_node.GetString("NEXT_OPER"));

            } while (in_node.GetString("NEXT_OPER") != "");

            return true;

        }

        /// <summary>
        /// 작업지시 리스트 조회 
        /// </summary>
        /// <param name="control"></param>
        /// <param name="c_step"></param>
        /// <param name="sArea"></param>
        /// <param name="aSubArea"></param>
        /// <param name="sOper"></param>
        /// <param name="Ext_Factory"></param>
        /// <returns></returns>
        public static bool ViewOrderList(Control control, char c_step, string sArea, string aSubArea, string sOper, string Ext_Factory = "", string sFrom_Date = "", string sTo_date = "")
        {
            int i;
            ListViewItem itmX;
            TRSNode in_node = new TRSNode("VIEW_ORDER_LIST_IN");
            TRSNode out_node;


            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = c_step;

            if (Ext_Factory != "")
            {
                in_node.Factory = Ext_Factory;
            }

            in_node.AddString("AREA_ID", sArea);                      
            in_node.AddString("SUB_AREA_ID", aSubArea);
            in_node.AddString("OPER", sOper);
            in_node.AddString("NEXT_ORDER", "");

            if(sFrom_Date != "")
                in_node.AddString("FROM_DATE", sFrom_Date);

            if (sTo_date != "")
                in_node.AddString("TO_DATE", sTo_date);

            do
            {
                out_node = new TRSNode("VIEW_ORDER_LIST_OUT");

                if (MPCR.CallService("CUS_ORD", "CUS_ORD_View_Order_List", in_node, ref out_node) == false)
                {
                    return false;
                }

                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(out_node.GetList(0)[i].GetString("ORDER_ID"), (int)SMALLICON_INDEX.IDX_ORDER);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("PLAN_START_TIME"), DATE_TIME_FORMAT.DATE));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("PLAN_END_TIME"), DATE_TIME_FORMAT.DATE));
                        }

                        ((ListView)control).Items.Add(itmX);
                    }
                }

                in_node.SetString("NEXT_ORDER", out_node.GetString("NEXT_ORDER"));

            } while (in_node.GetString("NEXT_ORDER") != "");

            return true;

        }

        /// <summary>
        /// 작업자 리스트 조회
        /// </summary>
        /// <param name="control"></param>
        /// <param name="sViewID"></param>
        /// <param name="sArea"></param>
        /// <param name="sSubArea"></param>
        /// <returns></returns>
        public static bool ViewWorkerList(Control control, string sViewID, string sArea, string aSubArea="")
        {
            try
            {
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }
                
                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea;

                dvcArgu[2].sCondition_ID = "SUB_AREA_ID";
                dvcArgu[2].sCondition_Value = aSubArea;

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
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
                        itmX = new ListViewItem(row["WORKER_ID"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["WORKER_DESC"].ToString());
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

        /// <summary>
        /// 설비 리스트 조회 
        /// </summary>
        /// <param name="control"></param>
        /// <param name="c_step"></param>
        /// <param name="sOper"></param>
        /// <param name="Ext_Factory"></param>
        /// <returns></returns>
        public static bool ViewResourceList(Control control, char c_step, string sOper, string sSubArea = "", string Ext_Factory = "")
        {
            int i;
            ListViewItem itmX;
            TRSNode in_node = new TRSNode("VIEW_ORDER_LIST_IN");
            TRSNode out_node;


            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = c_step;

            if (Ext_Factory != "")
            {
                in_node.Factory = Ext_Factory;
            }

            in_node.AddString("OPER", sOper);
            in_node.AddString("SUB_AREA_ID", sSubArea);
            in_node.AddString("NEXT_RES_ID", "");

            do
            {
                out_node = new TRSNode("VIEW_RESOURCE_LIST_OUT");

                if (MPCR.CallService("CUS_RAS", "CUS_RAS_View_Resource_List", in_node, ref out_node) == false)
                {
                    return false;
                }

                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(out_node.GetList(0)[i].GetString("RES_ID"), (int)SMALLICON_INDEX.IDX_RESOURCE);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetString("RES_DESC"));                            
                        }

                        ((ListView)control).Items.Add(itmX);
                    }
                }

                in_node.SetString("NEXT_RES_ID", out_node.GetString("NEXT_RES_ID"));

            } while (in_node.GetString("NEXT_RES_ID") != "");

            return true;
        }

        public static bool ViewResourceListByGroup(Control control, string sGroup, string sArea, string Ext_Factory = "")
        {
            int i;
            ListViewItem itmX;
            TRSNode in_node = new TRSNode("VIEW_ORDER_LIST_IN");
            TRSNode out_node;


            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '2';

            if (Ext_Factory != "")
            {
                in_node.Factory = Ext_Factory;
            }

            in_node.AddString("RES_GRP_1", sGroup);
            in_node.AddString("AREA_ID", sArea);
            in_node.AddString("NEXT_RES_ID", "");

            do
            {
                out_node = new TRSNode("VIEW_RESOURCE_LIST_OUT");

                if (MPCR.CallService("CUS_RAS", "CUS_RAS_View_Resource_List", in_node, ref out_node) == false)
                {
                    return false;
                }

                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(out_node.GetList(0)[i].GetString("RES_ID"), (int)SMALLICON_INDEX.IDX_RESOURCE);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetString("RES_DESC"));
                        }

                        ((ListView)control).Items.Add(itmX);
                    }
                }

                in_node.SetString("NEXT_RES_ID", out_node.GetString("NEXT_RES_ID"));

            } while (in_node.GetString("NEXT_RES_ID") != "");

            return true;
        }

        /// <summary>
        /// 라벨 GCM 데이터 조회
        /// </summary>
        /// <param name="control"></param>
        /// <param name="sArea"></param>
        /// <param name="sLabelType"></param>
        /// <returns></returns>
        public static bool ViewLabelGCMList(Control control, string sArea, string sLabelType, string sLabelType2 = "")
        {
            string sViewID = "";

            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                string sSql = "";

                sViewID = "CLBL1001-002";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "KEY_1";
                dvcArgu[1].sCondition_Value = sArea;

                dvcArgu[2].sCondition_ID = "DATA_2";
                dvcArgu[2].sCondition_Value = sLabelType;

                dvcArgu[3].sCondition_ID = "DATA_2_1";
                dvcArgu[3].sCondition_Value = sLabelType2;

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
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
                        itmX = new ListViewItem(row["DATA_3"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["DATA_1"].ToString());
                            itmX.SubItems.Add(row["KEY_2"].ToString());
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

        /// <summary>
        /// 기타유형 조회
        /// </summary>
        /// <param name="control"></param>
        /// <param name="sViewID"></param>
        /// <param name="sArea"></param>
        /// <param name="sFlag"></param>
        /// <returns></returns>
        public static bool ViewEtcTypeList(Control control, string sViewID, string sArea, string sFlag)
        {
            try
            {
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea;

                dvcArgu[2].sCondition_ID = "ISSUE_RECEIPT_FLAG";
                dvcArgu[2].sCondition_Value = sFlag;

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
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
                        itmX = new ListViewItem(row["TRAN_SRC_DESC"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["TRAN_TYPE_ID"].ToString());
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

        /// <summary>
        /// 협력사 조회
        /// </summary>
        /// <param name="control"></param>
        /// <param name="sViewID"></param>
        /// <returns></returns>
        public static bool ViewVendorList(Control control, string sViewID)
        {
            try
            {
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
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
                            itmX.SubItems.Add(row["KEY_2"].ToString());
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

        /// <summary>
        /// GRT P급 품목 조회
        /// </summary>
        /// <param name="control"></param>
        /// <param name="sViewID"></param>
        /// <param name="sArea"></param>
        /// <returns></returns>
        public static bool ViewPMaterialList(Control control, string sViewID, string sArea)
        {
            try
            {
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[3];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "AREA_ID";
                dvcArgu[1].sCondition_Value = sArea;

                dvcArgu[2].sCondition_ID = "MAT_CMF_8";
                dvcArgu[2].sCondition_Value = "Y";

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
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
                        itmX = new ListViewItem(row["MAT_DESC"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["MAT_ID"].ToString());
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
    }
}
