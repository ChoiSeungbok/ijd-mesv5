
using System.Drawing;
using System.Data;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using System;
using FarPoint.Win.Spread;
using Infragistics.Win.UltraWinEditors;
using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.MESCore;
using Miracom.TRSCore;

//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : modListRoutine.vb
//   Description : Common List Routine Module
//
//   FMB Version : 1.0.0
//
//   Function List
//        - ViewLayOutList()    : View LayOut List
//        - ViewUDR_GroupList()    : View User Define Resource Group List
//        - ViewFactoryList()    : View All Factory List
//        - ViewFacCmfData() : View FACCMF Table Item Data
//       - ViewResourceList() : View all Resource List
//       - ViewResEventList()  : View Resource - Event Relation List
//       - ViewResLotList() : View Lot List by Resource
//       - ViewResourceHistory()  : View Resource History
//       - ViewResOperList()  : View Resource - Operation Relation List
//       - ViewLotByResList()  : View Lot List by Resource
//        - ViewGCMDataList() : View General Code Table Data list
//        - ViewResourceListDetail() : View Reource List By Area/SubArea Condition
//        - ViewMaterialList() : View All Material List
//        - ViewFlowList() : View All Flow List
//        - ViewOperationList() : View All Operation List
//        - ViewLotListDetail() : View Lot List By Operation Condition
//       - ViewSecGroupList() : View All Security Group List
//       - ViewUserList() : View User List
//       - FindColSetVersion() : Find Collection Set Version
//       - ViewAttachCharacterList() : View Attach Character List
//       - ViewDefaultUnitList() : View Default Unit List
//       - ViewGlobalOptionList() : View Global Option List
//       - ViewEventColorList() : View Event Color List
//       - ViewResourceImageList() : View Resource Image List
//
//   Detail Description
//       -
//
//   History
//       - 2005-02-14 : Created by H.K.Kim
//
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

namespace Miracom.FMBCore
{
    public sealed class modListRoutine
    {

        #region "Const Definition"

        private const int VALUE_START_COL = 11;

        #endregion

        #region "Enum Definition"

        private enum CHAR_COLUMN
        {
            CHAR_COL = 0,
            CHAR_DESC_COL = 1,
            SPEC_COL = 2,
            OPT_INPUT_COL = 3,
            VALUE_TYPE_COL = 4,
            VALUE_COUNT_COL = 5,
            DEF_UNIT_OVR_FLAG_COL = 6,
            DEF_VALUE_COL = 7,
            UNIT_TBL_COL = 8,
            VALUE_TBL_COL = 9,
            UNIT_COL = 10,
            VALUE_1_COL = 11,
            VALUE_2_COL = 12,
            VALUE_3_COL = 13,
            VALUE_4_COL = 14,
            VALUE_5_COL = 15,
            VALUE_6_COL = 16,
            VALUE_7_COL = 17,
            VALUE_8_COL = 18,
            VALUE_9_COL = 19,
            VALUE_10_COL = 20,
            VALUE_11_COL = 21,
            VALUE_12_COL = 22,
            VALUE_13_COL = 23,
            VALUE_14_COL = 24,
            VALUE_15_COL = 25,
            VALUE_16_COL = 26,
            VALUE_17_COL = 27,
            VALUE_18_COL = 28,
            VALUE_19_COL = 29,
            VALUE_20_COL = 30,
            VALUE_21_COL = 31,
            VALUE_22_COL = 32,
            VALUE_23_COL = 33,
            VALUE_24_COL = 34,
            VALUE_25_COL = 35,
            SPC_CHART_COL = 36
        }

        #endregion

        // ViewLayOutList()
        //       - View LayOut List
        // Return Value
        //       - Boolean : True / False
        // Arguments
        //       - ByVal control As Control                    : List가 들어갈 control
        //        - ByVal sStep As String                        : 확장 Process Step
        //        - Optional ByVal sFactory As String = ""    : 현재 Factory가 아닌경우의 Factory
        //
        public static bool ViewLayOutList(Control control, char sStep, string sFactory)
        {

            try
            {
                TRSNode in_node = new TRSNode("FMB_View_LayOut_List_In");
                TRSNode out_node;
                int i;
                ListViewItem itmX;
                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;

                if (sFactory != "")
                {
                    in_node.Factory = sFactory;
                }
                else
                {
                    in_node.Factory = MPGV.gsFactory;
                }

                in_node.AddString("NEXT_LAYOUT_ID", "");

                do
                {
                    out_node = new TRSNode("FMB_View_LayOut_List_Out");

                    if (MPCR.CallService("FMB", "FMB_View_LayOut_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (control is ListView)
                        {
                            itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("LAYOUT_ID")), MPCF.ToInt(SMALLICON_INDEX.IDX_AREA));
                            if (((ListView)control).Columns.Count > 1)
                            {
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LAYOUT_DESC")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("WIDTH")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("HEIGHT")));
                            }
                            ((ListView)control).Items.Add(itmX);

                        }
                    }
                    
                    in_node.SetString("NEXT_LAYOUT_ID", out_node.GetString("NEXT_LAYOUT_ID"));
                } while (in_node.GetString("NEXT_LAYOUT_ID") != "");

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("modListRoutine.ViewLayOutList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // ViewUDR_GroupList()
        //       - View User Define Resource Group List
        // Return Value
        //       - Boolean : True / False
        // Arguments
        //       - ByVal control As Control                    : List가 들어갈 control
        //        - ByVal sStep As String                        : 확장 Process Step
        //
        public static bool ViewUDR_GroupList(Control control, char sStep)
        {

            try
            {
                TRSNode in_node = new TRSNode("View_UDR_Group_List_In");
                TRSNode out_node;
                int i;
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.AddString("NEXT_GROUP", "");

                do
                {
                     out_node = new TRSNode("FMB_View_UDR_Group_List_Out");
                    if (MPCR.CallService("FMB", "FMB_View_UDR_Group_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (control is ListView)
                        {
                            itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("GROUP_ID")), MPCF.ToInt(SMALLICON_INDEX.IDX_AREA));
                            if (((ListView)control).Columns.Count > 1)
                            {
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("GROUP_DESC")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("WIDTH")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("HEIGHT")));
                            }
                            ((ListView)control).Items.Add(itmX);

                        }
                    }
                    
                    in_node.SetString("NEXT_GROUP", out_node.GetString("NEXT_GROUP"));
                } while (in_node.GetString("NEXT_GROUP") != "");

                   
                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("modListRoutine.ViewUDR_GroupList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

      

        // ViewFacCmfData()
        //       - View FACCMF Table Item Data
        // Return Value
        //       - boolean : True / False
        // Arguments
        //        - ByVal sStep As String                        : 확장 Process Step
        //        - ByVal sItemName As String                    : 가져올 Item Name
        //        - ByRef View_FacCmf_Item_Out As FMB_View_FacCmf_Item_Out_Tag
        //                                                    : 가져온 Item Data의 구조체
        //        - Optional ByVal sExtFactory As String = ""    : 현재 Factory가 아닌경우
        //
        public static bool ViewFacCmfData(char sStep, string sItemName, ref TRSNode out_node, string sExtFactory, bool bShowError)
        {

            try
            {
                TRSNode in_node = new TRSNode("View_FacCmf_Item_In");
                
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;

                if (sExtFactory != "")
                {
                    in_node.Factory = sExtFactory;
                }

                in_node.AddString("ITEM_NAME", sItemName);

                if (MPCR.CallService("WIP", "WIP_View_Factory_Cmf_Item", in_node, ref out_node) == false)
                {
                    return false;
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("modListRoutine.ViewFacCmfData()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

         // ViewResLotList()
        //       - View Lot List by Resource Group
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control                    : List가 들어갈 control
        //        - ByVal sStep As String                        : 확장 Process Step
        //       - ByVal sResID As String                    : Resource ID
        //        - ByVal sExtFactory As String               : 현재 Factory가 아닌경우의 Factory
        //       - Optional ByVal sOper As String = ""       : Operation
        //
        public static bool ViewResLotList(Control control, char sStep, string sResID, string sExtFactory, string sOper, bool b_proc)
        {

            try
            {
                ListViewItem itmX;
                int i;

                TRSNode in_node = new TRSNode("View_ResLot_List_In");
                TRSNode out_node;
                ArrayList a_list = new ArrayList();

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.AddString("OPER", sOper);
                in_node.AddString("NEXT_RES_ID", sResID);
                in_node.AddString("NEXT_LOT_ID", "");
                in_node.Factory = sExtFactory;
                                
                do
                {
                    out_node = new TRSNode("View_ResLot_List_Out");
                    if (MPCR.CallService("RAS", "RAS_View_ResLot_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    a_list.Add(out_node);
                    
                    in_node.SetString("NEXT_LOT_ID", out_node.GetString("NEXT_LOT_ID"));
                } while (in_node.GetString("NEXT_LOT_ID") != "");

                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (control is ListView)
                        {
                            if (b_proc == true && MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_STATUS")) != "PROC")
                            {
                            }
                            else
                            {
                                itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_ID")), MPCF.ToInt(SMALLICON_INDEX.IDX_LOT));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_STATUS")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("MAT_ID")));
                                //itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("MAT_VER")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("FLOW")));
                                //itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("FLOW_SEQ_NUM")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("OPER")));

                                itmX.SubItems.Add(out_node.GetList(0)[i].GetDouble("QTY_1").ToString("##########0.000"));
                                itmX.SubItems.Add(out_node.GetList(0)[i].GetDouble("QTY_2").ToString("##########0.000"));
                                itmX.SubItems.Add(out_node.GetList(0)[i].GetDouble("QTY_3").ToString("##########0.000"));

                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("LOT_TYPE")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("LOT_PRIORITY")));

                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("CREATE_CODE")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("OWNER_CODE")));
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("HOLD_CODE")));

                                ((ListView)control).Items.Add(itmX);
                            }
                        }
                    }
                }
   
             
                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("modListRoutine.ViewResLotList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

         // ViewResourceHistory()
        //       - View Resource History
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control                    : List가 들어갈 control
        //        - ByVal sStep As String                        : 확장 Process Step
        //        - ByVal sResID As String                    : Resource id
        //        - Optional ByVal sFromTime As String = ""   : 시작 시간
        //        - Optional ByVal sToTime As String = ""     : 마지막 시간
        //        - Optional ByVal EventID As String            : Event id
        //        - Optional ByVal sExtFactory As String        : Factory
        //
        public static bool ViewResourceHistory(Control control, char sStep, string sResID, string FromDate, string ToDate, string EventID, char cIncludeDelHis, string sExtFactory)
        {

            try
            {
                ListViewItem itmX;
                int i;
                TRSNode in_node = new TRSNode("View_Resource_History_In");
                TRSNode out_node;
                ArrayList a_list = new ArrayList();

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.AddString("RES_ID", sResID);
                in_node.Factory = sExtFactory;

                in_node.AddInt("NEXT_HIST_SEQ", int.MaxValue);
                in_node.AddString("FROM_TIME", FromDate);
                in_node.AddString("TO_TIME", ToDate);
                in_node.AddString("EVENT_ID", EventID);
                in_node.AddChar("INCLUDE_DEL_HIST", cIncludeDelHis);

                do
                {
                     out_node = new TRSNode("View_Resource_History_Out");
                    if (MPCR.CallService("RAS", "RAS_View_Resource_History", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    a_list.Add(out_node);
                    
                    in_node.SetInt("NEXT_HIST_SEQ", out_node.GetInt("NEXT_HIST_SEQ"));
                } while (in_node.GetInt("NEXT_HIST_SEQ") != 0);
                
                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;
                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                    if (control is ListView)
                    {
                        if (MPCF.Trim(out_node.GetList(0)[i].GetChar("HIST_DEL_FLAG")) == "Y")
                        {
                            itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetInt("HIST_SEQ")), MPCF.ToInt(SMALLICON_INDEX.IDX_HISTORY_DELETE));
                            itmX.ForeColor = Color.Magenta;
                        }
                        else
                        {
                            itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetInt("HIST_SEQ")), MPCF.ToInt(SMALLICON_INDEX.IDX_HISTORY));
                        }

                        itmX.SubItems.Add(MPCF.MakeDateFormat(MPCF.Trim(out_node.GetList(0)[i].GetString("TRAN_TIME")), DATE_TIME_FORMAT.NONE));
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("EVENT_ID"))); //Add for V42
                        if (MPCF.Trim(out_node.GetList(0)[i].GetChar("NEW_UP_DOWN_FLAG")) == "D")
                        {
                            itmX.SubItems.Add("DOWN");
                        }
                        else if (MPCF.Trim(out_node.GetList(0)[i].GetChar("NEW_UP_DOWN_FLAG")) == "U")
                        {
                            itmX.SubItems.Add("UP");
                        }
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("NEW_PRI_STS")));
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("NEW_STS_1")));
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("NEW_STS_2")));
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("NEW_STS_3")));
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("NEW_STS_4")));
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("NEW_STS_5")));
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("NEW_STS_6")));
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("NEW_STS_7")));
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("NEW_STS_8")));
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("NEW_STS_9")));
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("NEW_STS_10")));
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("TRAN_USER_ID")));
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("TRAN_COMMENT")));
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("HIST_DEL_FLAG")));
                        itmX.SubItems.Add(MPCF.MakeDateFormat(MPCF.Trim(out_node.GetList(0)[i].GetString("HIST_DEL_TIME")), DATE_TIME_FORMAT.NONE));
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("hist_del_user_id")));
                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("hist_del_comment")));
                        ((ListView)control).Items.Add(itmX);

                    }
                  }
                        
                }
                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("modListRoutine.ViewResourceHistory()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

     
        // ViewLotByResList()
        //       -  View Lot List by Resource
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       - ByVal control As Control                    : List가 들어갈 control
        //        - ByVal sStep As String                        : 확장 Process Step
        //        - ByVal sRes As String                        : Resource ID
        //        - ByVal sOper As String                        : Operation
        //        - ByVal sExtFactory As String               : 현재 Factory가 아닌경우의 Factory
        //
        public static bool ViewLotByResList(Control control, char sStep, string sRes, string sOper, string sExtFactory)
        {

            try
            {
                ListViewItem itmX;
                int i;

                TRSNode in_node = new TRSNode("View_LotByRes_List_In");
                TRSNode out_node;
                ArrayList a_list = new ArrayList();

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.AddString("NEXT_LOT_ID", "");
                in_node.AddString("RES_ID", sRes);
                in_node.AddString("OPER", sOper);
                in_node.Factory = sExtFactory;


                do
                {
                     out_node = new TRSNode("View_LotByRes_List_Out");
                    if (MPCR.CallService("RAS", "RAS_View_LotByRes_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    a_list.Add(out_node);
                    
                    in_node.SetString("NEXT_LOT_ID", out_node.GetString("NEXT_LOT_ID"));
                } while (in_node.GetString("NEXT_LOT_ID") != "");

                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                     if (control is ListView)
                        {
                            itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_ID")), MPCF.ToInt(SMALLICON_INDEX.IDX_LOT));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_STATUS")));
                            if (MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_STATUS")) == "PROC")
                            {
                                itmX.SubItems[0].BackColor = Color.Yellow;
                            }
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("MAT_ID")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("FLOW")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("OPER")));

                            itmX.SubItems.Add(out_node.GetList(0)[i].GetDouble("QTY_1").ToString("##########0.000"));
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetDouble("QTY_2").ToString("##########0.000"));
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetDouble("QTY_3").ToString("##########0.000"));

                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("LOT_TYPE")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("LOT_PRIORITY")));

                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("CREATE_CODE")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("OWNER_CODE")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("HOLD_CODE")));

                            ((ListView)control).Items.Add(itmX);

                        }
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("modListRoutine.ViewLotByResList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

         // ViewResourceListDetail()
        //       - View Reource List By Area/SubArea Condition
        // Return Value
        //       -
        // Arguments
        //       - ByVal control As Control                                      : List가 들어갈 control
        //        - Optional ByVal sRes_Type As String = ""                     : Resource Type
        //        - Optional ByVal sRes_Grp As String = ""                      : Resource Group
        //        - Optional ByVal sArea_ID As String = ""                      : Area
        //        - Optional ByVal sSub_Area_ID As String = ""                  : Sub Area
        //        - Optional ByVal sFilter As String = ""                          : sFilter로 시작하는 Material
        //        - Optional ByVal bInclude_Delete_Resource As Boolean = False  : 삭제된 Resource 포함 여부
        //        - Optional ByVal sExtFactory As String = ""                   : Factory
        //        - Optional ByVal bIgnoreError As Boolean = False              : Error 무시 여부
        //
        public static bool ViewResourceListDetail(Control control, string sRes_Type, string sRes_Grp, string sArea_ID, string sSub_Area_ID, string sFilter, bool bInclude_Delete_Resource, string sExtFactory, bool bIgnoreError)
        {

            try
            {
                
                TRSNode in_node = new TRSNode("View_ResDetail_In");
                TRSNode out_node;
                ArrayList a_list = new ArrayList();
                int i;
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.Factory = sExtFactory;

                in_node.AddString("RES_TYPE", sRes_Type);
                in_node.AddString("RES_GRP", sRes_Grp);
                in_node.AddString("AREA_ID", sArea_ID);
                in_node.AddString("SUB_AREA_ID", sSub_Area_ID);
                in_node.AddString("FILTER", sFilter);
                in_node.AddChar("INCLUDE_DEL_RES", bInclude_Delete_Resource== true ? 'Y' : ' ');
                in_node.AddString("NEXT_RES_ID", "");


                do
                {
                    out_node = new TRSNode("View_ResDetail_Out");

                    if (MPCR.CallService("FMB", "FMB_View_ResDetail_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    a_list.Add(out_node);
                    
                    in_node.SetString("NEXT_RES_ID", out_node.GetString("NEXT_RES_ID"));
                } while (in_node.GetString("NEXT_RES_ID") != "");

                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;


                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (control is ListView)
                        {
                            itmX = new ListViewItem(System.Convert.ToString(i + 1), MPCF.ToInt(SMALLICON_INDEX.IDX_RESOURCE));

                            //itmX.SubItems.Add(Trim(.factory))
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_DESC")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_TYPE")));

                            if (MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PROC_MODE")) != "")
                            {
                                if (MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PROC_MODE")).PadLeft(1, ' ').Substring(0, 1) == "M")
                                {
                                    itmX.SubItems.Add("MANUAL");
                                }
                                else if (MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PROC_MODE")).PadLeft(1, ' ').Substring(0, 1) == "S")
                                {
                                    itmX.SubItems.Add("SEMI AUTO");
                                }
                                else if (MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PROC_MODE")).PadLeft(1, ' ').Substring(0, 1) == "F")
                                {
                                    itmX.SubItems.Add("FULL AUTO");
                                }
                                else
                                {
                                    itmX.SubItems.Add(" ");
                                }
                            }
                            else
                            {
                                itmX.SubItems.Add(" ");
                            }

                            if (MPCF.Trim(out_node.GetList(0)[i].GetString("RES_CTRL_MODE")) != "")
                            {
                                if (MPCF.Trim(out_node.GetList(0)[i].GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OL")
                                {
                                    itmX.SubItems.Add("ON LINE");
                                }
                                else if (MPCF.Trim(out_node.GetList(0)[i].GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OR")
                                {
                                    itmX.SubItems.Add("ON LINE REAL");
                                }
                                else if (MPCF.Trim(out_node.GetList(0)[i].GetString("RES_CTRL_MODE")).PadLeft(2, ' ').Substring(0, 2) == "OF")
                                {
                                    itmX.SubItems.Add("OFF LINE");
                                }
                                else
                                {
                                    itmX.SubItems.Add(" ");
                                }
                            }
                            else
                            {
                                itmX.SubItems.Add(" ");
                            }

                            if (MPCF.Trim(out_node.GetList(0)[i].GetChar("RES_UP_DOWN_FLAG")) == "U")
                            {
                                itmX.SubItems.Add("UP");
                            }
                            else
                            {
                                itmX.SubItems.Add("DOWN");
                            }

                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_PRI_STS")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_PRT_1")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_PRT_2")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_PRT_3")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_PRT_4")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_PRT_5")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_PRT_6")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_PRT_7")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_PRT_8")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_PRT_9")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_PRT_10")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_1")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_2")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_3")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_4")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_5")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_6")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_7")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_8")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_9")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_STS_10")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("USE_FAC_PRT_FLAG")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_EVENT_ID")));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("LAST_EVENT_TIME"), DATE_TIME_FORMAT.NONE));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("LAST_START_TIME"), DATE_TIME_FORMAT.NONE));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("LAST_END_TIME"), DATE_TIME_FORMAT.NONE));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("PROC_COUNT")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("MAX_PROC_COUNT")));

                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("LAST_ACTIVE_HIST_SEQ")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("LAST_HIST_SEQ")));
                          
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("CREATE_USER_ID")));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("CREATE_TIME"), DATE_TIME_FORMAT.NONE));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("UPDATE_USER_ID")));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("UPDATE_TIME"), DATE_TIME_FORMAT.NONE));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("RES_TAG_FLAG")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LAYOUT_ID")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("LOC_X")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("LOC_Y")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("LOC_WIDTH")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("LOC_HEIGHT")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("TEXT")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetInt("TEXT_SIZE")));
                            if (out_node.GetList(0)[i].GetInt("TEXT_COLOR") < 0)
                            {
                                itmX.SubItems.Add(System.Drawing.Color.FromArgb(out_node.GetList(0)[i].GetInt("TEXT_COLOR")).ToString());
                                itmX.SubItems[46].BackColor = System.Drawing.Color.FromArgb(out_node.GetList(0)[i].GetInt("TEXT_COLOR"));
                            }
                            else if (out_node.GetList(0)[i].GetInt("TEXT_COLOR") > 0)
                            {
                                itmX.SubItems.Add(System.Drawing.Color.FromKnownColor((KnownColor)out_node.GetList(0)[i].GetInt("TEXT_COLOR")).ToString());
                                itmX.SubItems[46].BackColor = System.Drawing.Color.FromKnownColor((KnownColor)out_node.GetList(0)[i].GetInt("TEXT_COLOR"));
                            }
                            else
                            {
                                itmX.SubItems.Add("0");
                            }

                            if (MPCF.Trim(out_node.GetList(0)[i].GetChar("TEXT_STYLE")) != "")
                            {
                                itmX.SubItems.Add(@Enum.GetName(typeof(FontStyle), @Enum.GetValues(typeof(FontStyle)).GetValue(MPCF.ToInt(out_node.GetList(0)[i].GetChar("TEXT_STYLE").ToString()))));
                            }
                            if (out_node.GetList(0)[i].GetInt("BACK_COLOR") < 0)
                            {
                                itmX.SubItems.Add(System.Drawing.Color.FromArgb(out_node.GetList(0)[i].GetInt("BACK_COLOR")).ToString());
                                itmX.SubItems[48].BackColor = System.Drawing.Color.FromArgb(out_node.GetList(0)[i].GetInt("BACK_COLOR"));
                            }
                            else if (out_node.GetList(0)[i].GetInt("BACK_COLOR") > 0)
                            {
                                itmX.SubItems.Add(System.Drawing.Color.FromKnownColor((KnownColor)out_node.GetList(0)[i].GetInt("BACK_COLOR")).ToString());
                                itmX.SubItems[48].BackColor = System.Drawing.Color.FromKnownColor((KnownColor)out_node.GetList(0)[i].GetInt("BACK_COLOR"));
                            }
                            else
                            {
                                itmX.SubItems.Add("0");
                            }

                            if (out_node.GetList(0)[i].GetChar("RES_UP_DOWN_FLAG") == 'U')
                            {
                                itmX.ImageIndex = MPCF.ToInt(SMALLICON_INDEX.IDX_RESOURCE);
                            }
                            else
                            {
                                itmX.ImageIndex = MPCF.ToInt(SMALLICON_INDEX.IDX_RESOURCE_DOWN);
                            }
                            ((ListView)control).Items.Add(itmX);
                            if (MPCF.Trim(out_node.GetList(0)[i].GetChar("DELETE_FLAG")) == "Y")
                            {
                                itmX.SubItems[0].ForeColor = Color.Magenta;
                            }
                        }
                       
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("modListRoutine.ViewResourceListDetail()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }
        // ViewLotListDetail()
        //       - View Lot List By Operation Condition
        // Return Value
        //       -
        // Arguments
        //       - ByVal control As Control                    : List가 들어갈 control
        //        - ByVal sStep As String                        : 확장 Process Step
        //        - ByVal sExtFactory As String               : Factory
        //        - Optional ByVal sMaterial As String                 : Material
        //        - Optional ByVal sFlow As String                     : Flow
        //        - Optional ByVal sOper As String                     : Operation
        //        - Optional ByVal bZeroQtyLot As Boolean              : Zero Qty Lot 여부
        //        - Optional ByVal bTerminateLot As Boolean            : 삭제된 Lot 포함 여부
        //
        public static bool ViewLotListDetail(Control control, string sStep, string sExtFactory, string sMaterial, int iVer, string sFlow, string sOper, bool bZeroQtyLot, bool bTerminateLot)
        {

            try
            {
                TRSNode in_node = new TRSNode("FMB_View_LayOut_List_In");
                TRSNode out_node;
                ArrayList a_list = new ArrayList();
                int i;
                int iRow;
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                
                in_node.Factory = sExtFactory;
                in_node.AddString("MAT_ID", sMaterial);
                in_node.AddInt("MAT_VER", iVer);
                in_node.AddString("FLOW", sFlow);
                in_node.AddString("OPER", sOper);
                in_node.AddChar("ZERO_QTY_FLAG", bZeroQtyLot== true ? 'Y' : ' ');
                in_node.AddChar("LOT_DEL_FLAG", bTerminateLot == true ? 'Y' : ' ');


                do
                {
                    out_node = new TRSNode("View_Lot_List_Out");
                    if (MPCR.CallService("WIP", "WIP_View_Lot_List_By_Operation", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    a_list.Add(out_node);
                    
                    in_node.SetString("NEXT_LOT_ID", out_node.GetString("NEXT_LOT_ID"));
                } while (in_node.GetString("NEXT_LOT_ID") != "");

                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (control is ListView)
                        {
                            iRow = ((ListView)control).Items.Count + 1;

                            itmX = new ListViewItem(iRow.ToString(), MPCF.ToInt(SMALLICON_INDEX.IDX_LOT));

                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_ID")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("MAT_ID")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("FLOW")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("OPER")));
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetDouble("QTY_1").ToString("##########0.000"));
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetDouble("QTY_2").ToString("##########0.000"));
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetDouble("QTY_3").ToString("##########0.000"));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("LOT_TYPE")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("OWNER_CODE")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("CREATE_CODE")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("LOT_PRIORITY")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_STATUS")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("HOLD_FLAG")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("HOLD_CODE")));

                            itmX.SubItems.Add(out_node.GetList(0)[i].GetDouble("CREATE_QTY_1").ToString("##########0.000"));
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetDouble("CREATE_QTY_2").ToString("##########0.000"));
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetDouble("CREATE_QTY_3").ToString("##########0.000"));

                            itmX.SubItems.Add(out_node.GetList(0)[i].GetDouble("OPER_IN_QTY_1").ToString("##########0.000"));
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetDouble("OPER_IN_QTY_2").ToString("##########0.000"));
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetDouble("OPER_IN_QTY_3").ToString("##########0.000"));


                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("INV_FLAG")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("TRANSIT_FLAG")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("UNIT_EXIST_FLAG")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("INV_UNIT")));

                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("RWK_FLAG")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RWK_CODE")));
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetInt("RWK_COUNT").ToString("##########0"));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RWK_RET_FLOW")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RWK_RET_OPER")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RWK_END_FLOW")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RWK_END_OPER")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("RWK_RET_CLEAR_FLAG")));

                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("NSTD_FLAG")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("NSTD_RET_FLOW")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("NSTD_RET_OPER")));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("NSTD_TIME"), DATE_TIME_FORMAT.NONE));

                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("START_FLAG")));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("START_TIME"), DATE_TIME_FORMAT.NONE));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("START_RES_ID")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("END_FLAG")));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("END_TIME"), DATE_TIME_FORMAT.NONE));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("END_RES_ID")));

                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("SAMPLE_FLAG")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("SAMPLE_WAIT_FLAG")));
                            switch (out_node.GetList(0)[i].GetChar("SAMPLE_RESULT"))
                            {
                                case 'Y':

                                    itmX.SubItems.Add("Good");
                                    break;
                                case 'N':

                                    itmX.SubItems.Add("No Good");
                                    break;
                                default:

                                    itmX.SubItems.Add("");
                                    break;
                            }
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("FROM_TO_LOT_ID")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("SHIP_CODE")));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("SHIP_TIME"), DATE_TIME_FORMAT.NONE));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("ORG_DUE_TIME"), DATE_TIME_FORMAT.NONE));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("SCH_DUE_TIME"), DATE_TIME_FORMAT.NONE));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("CREATE_TIME"), DATE_TIME_FORMAT.NONE));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("FAC_IN_TIME"), DATE_TIME_FORMAT.NONE));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("FLOW_IN_TIME"), DATE_TIME_FORMAT.NONE));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("OPER_IN_TIME"), DATE_TIME_FORMAT.NONE));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RESERVE_RES_ID")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("BATCH_ID")));
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetInt("BATCH_SEQ").ToString("#########0"));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("ORDER_ID")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_LOCATION")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_CMF_1")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_CMF_2")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_CMF_3")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_CMF_4")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_CMF_5")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_CMF_6")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_CMF_7")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_CMF_8")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_CMF_9")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_CMF_10")));

                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("LOT_DEL_FLAG")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LOT_DEL_CODE")));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("LOT_DEL_TIME"), DATE_TIME_FORMAT.NONE));

                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_TRAN_CODE")));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("LAST_TRAN_TIME"), DATE_TIME_FORMAT.NONE));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("LAST_COMMENT")));
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetInt("LAST_ACTIVE_HIST_SEQ").ToString("##########0"));
                            itmX.SubItems.Add(out_node.GetList(0)[i].GetInt("LAST_HIST_SEQ").ToString("##########0"));
                            ((ListView)control).Items.Add(itmX);
                            if (out_node.GetList(0)[i].GetChar("LOT_DEL_FLAG") == 'Y')
                            {
                                itmX.SubItems[0].ForeColor = Color.Magenta;
                            }
                        }
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("modListRoutine.ViewLotListDetail()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // ViewGlobalOptionList()
        //       - View Global Option List
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       -
        public static bool ViewGlobalOptionList()
        {

            try
            {
                TRSNode in_node = new TRSNode("View_Environment_List_In");
                TRSNode out_node;
                ArrayList a_list = new ArrayList();
                int i;
                Size cSize;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("NEXT_FACTORY", "");


                do
                {
                     out_node = new TRSNode("View_Environment_List_Out");
                    if (MPCR.CallService("FMB", "FMB_View_Environment_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    a_list.Add(out_node);
                    
                    in_node.SetString("NEXT_FACTORY", out_node.GetString("NEXT_FACTORY"));
                } while (in_node.GetString("NEXT_FACTORY") != "");

                foreach (object obj in a_list)
                {
                    out_node = null;
                    out_node = (TRSNode)obj;

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.Factory, out_node.GetList(0)[i].GetString("FACTORY"));
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultFontName, out_node.GetList(0)[i].GetString("FONT_FAMILY"));
                        cSize = new Size(out_node.GetList(0)[i].GetInt("LAYOUT_WIDTH"), out_node.GetList(0)[i].GetInt("LAYOUT_HEIGHT"));
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultLayoutSize, cSize);
                        cSize = new Size(out_node.GetList(0)[i].GetInt("UDR_WIDTH"), out_node.GetList(0)[i].GetInt("UDR_HEIGHT"));
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultUDRSize, cSize);
                        cSize = new Size(out_node.GetList(0)[i].GetInt("RES_WIDTH"), out_node.GetList(0)[i].GetInt("RES_HEIGHT"));
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultResourceSize, cSize);
                        cSize = new Size(out_node.GetList(0)[i].GetInt("RTG_WIDTH"), out_node.GetList(0)[i].GetInt("RTG_HEIGHT"));
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultRectangleSize, cSize);
                        cSize = new Size(out_node.GetList(0)[i].GetInt("ELP_WIDTH"), out_node.GetList(0)[i].GetInt("ELP_HEIGHT"));
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultEllipseSize, cSize);
                        cSize = new Size(out_node.GetList(0)[i].GetInt("TRI_WIDTH"), out_node.GetList(0)[i].GetInt("TRI_HEIGHT"));
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultTriangleSize, cSize);
                        cSize = new Size(out_node.GetList(0)[i].GetInt("VER_WIDTH"), out_node.GetList(0)[i].GetInt("VER_HEIGHT"));
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultVerticalLineSize, cSize);
                        cSize = new Size(out_node.GetList(0)[i].GetInt("HOR_WIDTH"), out_node.GetList(0)[i].GetInt("HOR_HEIGHT"));
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultHorizontalLineSize, cSize);
                        cSize = new Size(out_node.GetList(0)[i].GetInt("PIE1_WIDTH"), out_node.GetList(0)[i].GetInt("PIE1_HEIGHT"));
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultPie1Size, cSize);
                        cSize = new Size(out_node.GetList(0)[i].GetInt("PIE2_WIDTH"), out_node.GetList(0)[i].GetInt("PIE2_HEIGHT"));
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultPie2Size, cSize);
                        cSize = new Size(out_node.GetList(0)[i].GetInt("PIE3_WIDTH"), out_node.GetList(0)[i].GetInt("PIE3_HEIGHT"));
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultPie3Size, cSize);
                        cSize = new Size(out_node.GetList(0)[i].GetInt("PIE4_WIDTH"), out_node.GetList(0)[i].GetInt("PIE4_HEIGHT"));
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultPie4Size, cSize);
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.UseEventColor, out_node.GetList(0)[i].GetChar("EVENT_COLOR_FLAG"));
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.BackColorOpt, out_node.GetList(0)[i].GetString("BACK_OPT").ToUpper());

                        if (MPCF.Trim(out_node.GetList(0)[i].GetChar("EVENT_COLOR_FLAG")) == "Y")
                        {
                            if (ViewEventColorList('2', out_node.GetList(0)[i].GetString("FACTORY")) == false)
                            {
                                return false;
                            }
                        }
                        if (out_node.GetList(0)[i].GetInt("TEXT_COLOR") < 0)
                        {
                            modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultTextColor, System.Drawing.Color.FromArgb(out_node.GetList(0)[i].GetInt("TEXT_COLOR")));
                        }
                        else if (out_node.GetList(0)[i].GetInt("TEXT_COLOR") > 0)
                        {
                            modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultTextColor, System.Drawing.Color.FromKnownColor((KnownColor)out_node.GetList(0)[i].GetInt("TEXT_COLOR")));
                        }
                        else
                        {
                            modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultTextColor, SystemColors.Control);
                        }
                        if (out_node.GetList(0)[i].GetInt("BACK_COLOR") < 0)
                        {
                            modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultBackColor, System.Drawing.Color.FromArgb(out_node.GetList(0)[i].GetInt("BACK_COLOR")));
                        }
                        else if (out_node.GetList(0)[i].GetInt("BACK_COLOR") > 0)
                        {
                            modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultBackColor, System.Drawing.Color.FromKnownColor((KnownColor)out_node.GetList(0)[i].GetInt("BACK_COLOR")));
                        }
                        else
                        {
                            modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultBackColor, SystemColors.Control);
                        }
                        modGlobalVariable.gGlobalOptions.AddOption(out_node.GetList(0)[i].GetString("FACTORY"), clsOptionData.Options.DefaultTextSize, out_node.GetList(0)[i].GetInt("TEXT_SIZE"));
                   
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("modListRoutine.ViewGlobalOptionList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // ViewEventColorList()
        //       - View Event Color List
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal sStep As String       : Process Step
        //       - ByVal sFactory As String    : Factory
        //
        public static bool ViewEventColorList(char sStep, string sFactory)
        {

            int i;

            TRSNode in_node = new TRSNode("View_Event_Color_List_In");
            TRSNode out_node;
            string s_type = "";
            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.Factory = MPCF.RTrim(sFactory);
                in_node.AddString("NEXT_EVENT", "");


                do
                {
                    out_node = new TRSNode("View_Event_Color_List_Out");
                    if (MPCR.CallService("FMB", "FMB_View_Event_Color_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (MPCF.Trim(out_node.GetList(0)[i].GetString("RES_TYPE")) == "RES")
                        {
                            s_type = "Resource";
                        }
                        else if (MPCF.Trim(out_node.GetList(0)[i].GetString("RES_TYPE")) == "SUBRES")
                        {
                            s_type = "SubResource";
                        }
                        else if (MPCF.Trim(out_node.GetList(0)[i].GetString("RES_TYPE")) == "PORT")
                        {
                            s_type = "Port";
                        }
                        else if (MPCF.Trim(out_node.GetList(0)[i].GetString("RES_TYPE")) == "TOOL")
                        {
                            s_type = "Tool";
                        }
                        if (out_node.GetList(0)[i].GetInt("COLOR") < 0)
                        {
                            modGlobalVariable.gGlobalOptions.AddOption(sFactory,s_type,  MPCF.Trim(out_node.GetList(0)[i].GetString("EVENT_ID")), System.Drawing.Color.FromArgb(out_node.GetList(0)[i].GetInt("COLOR")));
                        }
                        else if (out_node.GetList(0)[i].GetInt("COLOR") > 0)
                        {
                            modGlobalVariable.gGlobalOptions.AddOption(sFactory, s_type, MPCF.Trim(out_node.GetList(0)[i].GetString("EVENT_ID")), System.Drawing.Color.FromKnownColor((KnownColor)out_node.GetList(0)[i].GetInt("COLOR")));
                        }
                        else
                        {
                            modGlobalVariable.gGlobalOptions.AddOption(sFactory, s_type, MPCF.Trim(out_node.GetList(0)[i].GetString("EVENT_ID")), SystemColors.Control);
                        }
                    }
                    
                    in_node.SetString("NEXT_EVENT", out_node.GetString("NEXT_EVENT"));
                } while (in_node.GetString("NEXT_EVENT") != "");
                
                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("modListRoutine.ViewEventColorList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // ViewEventColorList()
        //       - View Event Color List
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control    : Control
        //       - ByVal sStep As String       : Process Step
        //       - ByVal sFactory As String    : Factory
        //
        public static bool ViewEventColorList(Control control, char sStep, string sFactory)
        {


            int i;
            ListViewItem itmX;
            TRSNode in_node = new TRSNode("View_Event_Color_List_In");
            TRSNode out_node;
            
            try
            {
                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.Factory = MPCF.RTrim(sFactory);
                in_node.AddString("NEXT_EVENT", "");
               
                do
                {
                    out_node = new TRSNode("View_Event_Color_List_Out");
                    if (MPCR.CallService("FMB", "FMB_View_Event_Color_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (control is ListView)
                        {
                            itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("EVENT_ID")), 0);
                            if (((ListView)control).Columns.Count > 1)
                            {
                                if (out_node.GetList(0)[i].GetInt("COLOR") < 0)
                                {
                                    itmX.SubItems.Add(System.Drawing.Color.FromArgb(out_node.GetList(0)[i].GetInt("COLOR")).ToString());
                                    itmX.SubItems[0].BackColor = System.Drawing.Color.FromArgb(out_node.GetList(0)[i].GetInt("COLOR"));
                                }
                                else if (out_node.GetList(0)[i].GetInt("COLOR") > 0)
                                {
                                    itmX.SubItems.Add(System.Drawing.Color.FromKnownColor((KnownColor)out_node.GetList(0)[i].GetInt("COLOR")).ToString());
                                    itmX.SubItems[0].BackColor = System.Drawing.Color.FromKnownColor((KnownColor)out_node.GetList(0)[i].GetInt("COLOR"));
                                }
                                else
                                {
                                    itmX.SubItems.Add(SystemColors.Control.ToString());
                                    itmX.SubItems[0].BackColor = SystemColors.Control;
                                }

                            }
                            ((ListView)control).Items.Add(itmX);
                        }
                    }
                    
                    in_node.SetString("NEXT_EVENT", out_node.GetString("NEXT_EVENT"));
                } while (in_node.GetString("NEXT_EVENT") != "");
                
                  
                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("modListRoutine.ViewEventColorList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public static bool ViewResourceColorList(Control control, char sStep, string sFactory, string sType, string s_back_opt)
        {


            int i;
            ListViewItem itmX;
            TRSNode in_node = new TRSNode("View_Event_Color_List_In");
            TRSNode out_node;

            try
            {
                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.Factory = MPCF.RTrim(sFactory);
                in_node.AddString("NEXT_EVENT", "");
                in_node.AddString("RES_TYPE", sType);
                in_node.AddString("BACK_OPT", s_back_opt);

                do
                {
                    out_node = new TRSNode("View_Event_Color_List_Out");
                    if (MPCR.CallService("FMB", "FMB_View_Event_Color_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (control is ListView)
                        {
                            itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("EVENT_ID")), 0);
                            if (((ListView)control).Columns.Count > 1)
                            {
                                if (out_node.GetList(0)[i].GetInt("COLOR") < 0)
                                {
                                    itmX.SubItems.Add(System.Drawing.Color.FromArgb(out_node.GetList(0)[i].GetInt("COLOR")).ToString());
                                    itmX.SubItems[0].BackColor = System.Drawing.Color.FromArgb(out_node.GetList(0)[i].GetInt("COLOR"));
                                }
                                else if (out_node.GetList(0)[i].GetInt("COLOR") > 0)
                                {
                                    itmX.SubItems.Add(System.Drawing.Color.FromKnownColor((KnownColor)out_node.GetList(0)[i].GetInt("COLOR")).ToString());
                                    itmX.SubItems[0].BackColor = System.Drawing.Color.FromKnownColor((KnownColor)out_node.GetList(0)[i].GetInt("COLOR"));
                                }
                                else
                                {
                                    itmX.SubItems.Add(SystemColors.Control.ToString());
                                    itmX.SubItems[0].BackColor = SystemColors.Control;
                                }

                            }
                            ((ListView)control).Items.Add(itmX);
                        }
                    }

                    in_node.SetString("NEXT_EVENT", out_node.GetString("NEXT_EVENT"));
                } while (in_node.GetString("NEXT_EVENT") != "");


                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("modListRoutine.ViewEventColorList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // ViewResourceImageList()
        //       - View Resource Image List
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control    : Control
        //       - ByVal sStep As String       : Process Step
        //       - ByVal sFactory As String    : Factory
        //
        public static bool ViewResourceImageList(Control control, char sStep, string sFactory, string sResourceType, string sResource)
        {


            int i;
            ListViewItem itmX;
            TRSNode in_node = new TRSNode("View_Resource_Image_List_In");
            TRSNode out_node;
            try
            {
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.Factory = MPCF.RTrim(sFactory);
                in_node.AddString("NEXT_RES_ID", "");
                in_node.AddString("RES_ID", sResource);
                in_node.AddString("RES_TYPE", sResourceType);

                do
                {
                    out_node = new TRSNode("View_Resource_Image_List_Out");
                    if (MPCR.CallService("FMB", "FMB_View_Resource_Image_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (control is ListView)
                        {
                            if (out_node.GetList(0)[i].GetInt("IMAGE_IDX") == -1)
                            {
                                itmX = new ListViewItem("");
                            }
                            else
                            {
                                itmX = new ListViewItem("", out_node.GetList(0)[i].GetInt("IMAGE_IDX"));
                            }
                            if (((ListView)control).Columns.Count > 1)
                            {
                                itmX.SubItems.Add(out_node.GetList(0)[i].GetString("RES_ID"));
                                itmX.SubItems.Add(out_node.GetList(0)[i].GetString("RES_DESC"));
                            }
                            ((ListView)control).Items.Add(itmX);
                        }
                    }
                    
                    in_node.SetString("NEXT_RES_ID", out_node.GetString("NEXT_RES_ID"));
                } while (in_node.GetString("NEXT_RES_ID") != "");
                
                
                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("modListRoutine.ViewResourceImageList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        public static bool ViewFMBGroupList(Control control, char sStep, string sKey, string sExtFactory)
        {

            try
            {
                int i;
                ListViewItem itmX;
                TRSNode in_node = new TRSNode("View_FMB_Group_List_In");
                TRSNode out_node;
                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }
                  
                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.AddString("GROUP_ID", sKey);

                if (sExtFactory != "")
                {
                    in_node.Factory = MPCF.Trim(sExtFactory);
                }                
                
                if (sStep == '1')
                {
                    in_node.AddString("NEXT_USER", "", true);
                    in_node.AddString("NEXT_GROUP", sKey);
                }
                else if (sStep == '2')
                {
                    in_node.AddString("NEXT_GROUP", "");
                    in_node.AddString("NEXT_USER", sKey, true);
                }

                do
                {
                     out_node = new TRSNode("View_FMB_Group_List_Out");
                    if (MPCR.CallService("FMB", "FMB_View_FMB_Group_List", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                    for (i = 0; i < out_node.GetList(0).Count; i++)
                    {
                        if (control is ListView)
                        {
                            if (sStep == '1')
                            {
                                itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("USER_ID")), MPCF.ToInt(SMALLICON_INDEX.IDX_USER));
                                if (((ListView)control).Columns.Count > 1)
                                {
                                    itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("USER_DESC")));
                                }
                                ((ListView)control).Items.Add(itmX);
                            }
                            else if (sStep == '2')
                            {
                                itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("GROUP_ID")), MPCF.ToInt(SMALLICON_INDEX.IDX_SUB_AREA));
                                if (((ListView)control).Columns.Count > 1)
                                {
                                    itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("GROUP_DESC")));
                                }
                                ((ListView)control).Items.Add(itmX);
                            }

                        }
                    }
                    
                    in_node.SetString("NEXT_USER", out_node.GetString("NEXT_USER"));
                    in_node.SetString("NEXT_GROUP", out_node.GetString("NEXT_GROUP"));
                } while (in_node.GetString("NEXT_USER") != "" && in_node.GetString("NEXT_GROUP") != "");
                
                return true;
            }

            catch (Exception ex)
            {
                MPCF.ShowMsgBox("modListRoutine.ViewFMBGroupList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

         public static bool ViewResourceList(Control control, string sRes_Type, string sRes_Grp, string sArea_ID, string sSub_Area_ID, string sFilter, bool bInclude_Delete_Resource, string sExtFactory, bool bIgnoreError)
        {

            try
            {
                TRSNode in_node = new TRSNode("VIEW_RESDETAIL_IN");
                TRSNode out_node = new TRSNode("VIEW_RESDETAIL_OUT");
                int i;
                ListViewItem itmX;

                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.Factory = sExtFactory;

                in_node.AddString("RES_TYPE", sRes_Type);
                in_node.AddString("RES_GRP", sRes_Grp);
                in_node.AddString("AREA_ID", sArea_ID);
                in_node.AddString("SUB_AREA_ID", sSub_Area_ID);
                in_node.AddString("FILTER", sFilter);
                in_node.AddChar("INCLUDE_DEL_RES", bInclude_Delete_Resource == true ? 'Y' : ' ');
                in_node.AddString("NEXT_RES_ID", "");

                do
                {
                    if (MPCR.CallService("FMB", "FMB_View_ResDetail_List", in_node, ref out_node) == false)
                    {
                    	return false;
                    }
                    for (i = 0; i <= out_node.GetList(0).Count - 1; i++)
                    {
                        if (control is ListView)
                        {
                            itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_ID")), MPCF.ToInt(SMALLICON_INDEX.IDX_RESOURCE));

                            //itmX.SubItems.Add(Trim(.factory))
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("RES_DESC")));
                            ((ListView)control).Items.Add(itmX);
                        }

                    }

                    in_node.SetString("NEXT_RES_ID", in_node.GetString("NEXT_RES_ID"));
                } while (MPCF.Trim(in_node.GetString("NEXT_RES_ID")) != "");

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("modListRoutine.ViewResourceListDetail()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }


    }


}
