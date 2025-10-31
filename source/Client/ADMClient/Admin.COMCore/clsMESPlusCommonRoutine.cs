using System;
using System.IO;
using System.Windows.Forms;
using System.Drawing;
using System.Collections.Generic;

using FarPoint.Win;
using FarPoint.Win.Spread;
using Miracom.MsgHandler;
using Miracom.CliFrx;
using Miracom.MESCore;
using Miracom.TRSCore;

//-----------------------------------------------------------------------------
//
//   System      : MES
//   File Name   : modCommonRoutine.vb
//   Description : Client Common Routine Module
//
//   MES Version : 4.1.0.0
//
//   Function List
//       - InitGRPCMFControl()           : Group/ Cmf Control?ㅼ쓣 珥덇린???쒕떎.
//       - SetGRPItem()                  : Group Control??Group媛믪쓣 ?뺤쓽 ?쒕떎.
//       - SetCMFItem()                  : Cmf Control??Cmf媛믪쓣 ?뺤쓽 ?쒕떎.
//       - ProcGRPCMFButtonPress()       : Group / Cmf CodeView Control?먯꽌??ButtonPress?대깽?몃? 泥섎━?쒕떎.
//       - CheckCMFKeyPress()            : Cmf Control?먯꽌??KeyPress?대깽?몄뿉???낅젰臾몄옄 Format??留욌뒗吏 ?뺤씤?쒕떎.
//       - CheckGRPCMFValue()            : ?낅젰??Group/ Cmf媛믩뱾??留욌뒗吏 ?뺤씤?쒕떎.
//       - SetLotInfoSpreadInit()        : Lot??湲곕낯?뺣낫 Spread瑜?珥덇린?뷀븳??
//       - SetLotInfoSpread()            : Lot??湲곕낯?뺣낫 Spread??Lot ?뺣낫瑜?梨꾩슫??
//       - FindColSetVersion()           : Collection Set??????뚮쭪? Version ?뺣낫瑜?李얘퀬 Character ?뺣낫瑜?肉뚮젮以??
//       - ViewAttachCharacterList()     : Collection Set Version??Attach??Character List?ㅼ쓣 spreadsheet??肉뚮젮以??
//       - ViewMFOColSet()               : MFO???좊떦??Collection Set??蹂댁뿬以??
//
//   Detail Description
//       -
//
//   History
//       - **** Do Not Modify in Site!!! ****
//       - 2004-06-17 : Created by CM Koo
//
//
//   Copyright(C) 1998-2005 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------


namespace Admin.COMCore
{
	public sealed class ADCM
	{
		
#region "Const Definition"
		
		private const int VALUE_START_COL = 12;
        private const int DEFAULT_COL_COUNT = 12;
        private static string NUMBER_TYPE = "NUMBER";
		
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
			UNIT_SEQ_COL = 10,
            UNIT_COL = 11,
			VALUE_START_COL = 12
		}
		
#endregion
		
#region " Variable Definition "
		
		public static int iFieldSeq;
		
#endregion
		
        // ViewColumnList()
        //       - View Column List
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control					: List媛 ?ㅼ뼱媛?control
        //		- ByVal sStep As String						: ?뺤옣 Process Step
        //       - Optional ByVal sTableName As String = "" : Material Type
        //		- Optional ByVal sTreeItem As String = ""	: TreeView ?먯꽌 異붽???Node??Text
        //
        public static bool ViewColumnList(Control control, char sStep, string sTableName, TreeNode parentNode)
        {

            int i;
            ListViewItem itmX;
            TreeNode nodeX;

            TRSNode in_node = new TRSNode("VIEW_COLUMN_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_COLUMN_LIST_OUT");

            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }
            else if (!(control is TreeView))
            {
                MPCF.ClearList(control);
            }

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = sStep;
            in_node.AddString("TNAME", sTableName);
            in_node.AddString("NEXT_COLUMN_NAME", "");

            do
            {
                if (MPCR.CallService("ARC", "ARC_View_Column_List", in_node, ref out_node) == false)
                {
                	return false;
                }

                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("COLUMN_NAME")), (int)SMALLICON_INDEX.IDX_CODE_DATA);
                        if (((ListView)control).Columns.Count >= 3)
                        {
                            if (out_node.GetList(0)[i].GetString("DATA_TYPE") == NUMBER_TYPE)
                            {
                                if (out_node.GetList(0)[i].GetInt("DATA_PRECISION") > 0 && out_node.GetList(0)[i].GetInt("DATA_SCALE") > 0)
                                {
                                    itmX.SubItems.Add(MPCF.RTrim(out_node.GetList(0)[i].GetString("DATA_TYPE")) + " (" + out_node.GetList(0)[i].GetInt("DATA_PRECISION").ToString() + "," + out_node.GetList(0)[i].GetInt("DATA_SCALE").ToString() + ")");
                                }
                                else if (out_node.GetList(0)[i].GetInt("DATA_PRECISION") > 0 && out_node.GetList(0)[i].GetInt("DATA_SCALE") == 0)
                                {
                                    itmX.SubItems.Add(MPCF.RTrim(out_node.GetList(0)[i].GetString("DATA_TYPE")) + " (" + out_node.GetList(0)[i].GetInt("DATA_PRECISION").ToString() + ")");
                                }
                                else
                                {
                                    itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("DATA_TYPE")));
                                }
                            }
                            else
                            {
                                itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("DATA_TYPE")) + " (" + out_node.GetList(0)[i].GetInt("DATA_LENGTH").ToString() + ")");
                            }
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("INDX_CODE")));

                            if (MPCF.Trim(out_node.GetList(0)[i].GetString("INDX_CODE")) != "")
                                itmX.ForeColor = Color.Red;
                        }
                        ((ListView)control).Items.Add(itmX);
                    }
                    else if (control is TreeView)
                    {
                        nodeX = new TreeNode(MPCF.Trim(out_node.GetList(0)[i].GetString("COLUMN_NAME")) + " : " + MPCF.Trim(out_node.GetList(0)[i].GetString("DATA_TYPE")), (int)SMALLICON_INDEX.IDX_CODE_DATA, (int)SMALLICON_INDEX.IDX_CODE_DATA);
                        if (!(parentNode == null))
                        {
                            parentNode.Nodes.Add(nodeX);
                        }
                        else
                        {
                            ((TreeView)control).Nodes.Add(nodeX);
                        }
                    }
                    else if (control is ComboBox)
                    {
                        ((ComboBox)control).Items.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("COLUMN_NAME")));

                    }
                }

                in_node.SetString("NEXT_COLUMN_NAME", out_node.GetString("NEXT_COLUMN_NAME"));
            } while (!(in_node.GetString("NEXT_COLUMN_NAME") == ""));


            return true;
        }


        // ViewTableList()
        //       - View Table List
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control					: List媛 ?ㅼ뼱媛?control
        //		- ByVal sStep As String						: ?뺤옣 Process Step
        //		- Optional ByVal sTreeItem As String = ""	: TreeView ?먯꽌 異붽???Node??Text
        //
        public static bool ViewTableList(Control control, char sStep, TreeNode parentNode)
        {

            int i;
            ListViewItem itmX;
            TreeNode nodeX;

            TRSNode in_node = new TRSNode("VIEW_TABLE_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_TABLE_LIST_OUT");

            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }
            else if (!(control is TreeView))
            {
                MPCF.ClearList(control);
            }

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = sStep;
            in_node.AddString("NEXT_TNAME", "");

            do
            {
                if (MPCR.CallService("ARC", "ARC_View_Table_List", in_node, ref out_node) == false)
                {
                	return false;
                }

                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("TNAME")), (int)SMALLICON_INDEX.IDX_CODE_TABLE);
                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("MODULE_NAME")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("TBL_TYPE")));
                        }

                        if (out_node.GetList(0)[i].GetChar("TBL_TYPE") == 'M')
                        {

                            itmX.ForeColor = Color.Red;
                            //'lisTable.Items(i).Font.Bold = True
                            itmX.ImageIndex = (int)SMALLICON_INDEX.IDX_COL_SET;

                        }
                        else if (out_node.GetList(0)[i].GetChar("TBL_TYPE") == 'S')
                        {
                            itmX.ImageIndex = (int)SMALLICON_INDEX.IDX_COL_SET_VERSION;
                        }
                        ((ListView)control).Items.Add(itmX);
                    }
                    else if (control is TreeView)
                    {
                        nodeX = new TreeNode(MPCF.Trim(out_node.GetList(0)[i].GetString("TNAME")) + " : " + MPCF.Trim(out_node.GetList(0)[i].GetString("TABTYPE")), (int)SMALLICON_INDEX.IDX_CODE_TABLE, (int)SMALLICON_INDEX.IDX_CODE_TABLE);
                        if (!(parentNode == null))
                        {
                            parentNode.Nodes.Add(nodeX);
                        }
                        else
                        {
                            ((TreeView)control).Nodes.Add(nodeX);
                        }
                    }
                    else if (control is ComboBox)
                    {
                        ((ComboBox)control).Items.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("TNAME")));

                    }
                }

                in_node.SetString("NEXT_TNAME", out_node.GetString("NEXT_TNAME"));
            } while (!(in_node.GetString("NEXT_TNAME") == ""));

            return true;

        }

        // ViewSessionList()
        //       - View Session List
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control					: List媛 ?ㅼ뼱媛?control
        //		- ByVal sStep As String						: ?뺤옣 Process Step
        //		- Optional ByVal sTreeItem As String = ""	: TreeView ?먯꽌 異붽???Node??Text
        //
        public static bool ViewSessionList(Control control, char sStep, TreeNode parentNode)
        {

            int i;
            ListViewItem itmX;
            TreeNode nodeX;

            TRSNode in_node = new TRSNode("VIEW_SESSION_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_SESSION_LIST_OUT");

            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }
            else if (!(control is TreeView))
            {
                MPCF.ClearList(control);
            }

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = sStep;

            do
            {
                if (MPCR.CallService("ADM", "ADM_View_Session_List", in_node, ref out_node) == false)
                {
                	return false;
                }

                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("SESSION_ID")), (int)SMALLICON_INDEX.IDX_CODE_TABLE);
                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("STATUS")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("USERNAME")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("OSUSER")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("MACHINE")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("PROGRAM")));
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("TYPE")));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(out_node.GetList(0)[i].GetString("LOGON_TIME")));
                        }
                        ((ListView)control).Items.Add(itmX);
                    }
                    else if (control is TreeView)
                    {
                        nodeX = new TreeNode(MPCF.Trim(out_node.GetList(0)[i].GetString("SESSION_ID")) + " : " + MPCF.Trim(out_node.GetList(0)[i].GetString("USERNAME")), (int)SMALLICON_INDEX.IDX_CODE_TABLE, (int)SMALLICON_INDEX.IDX_CODE_TABLE);
                        if (!(parentNode == null))
                        {
                            parentNode.Nodes.Add(nodeX);
                        }
                        else
                        {
                            ((TreeView)control).Nodes.Add(nodeX);
                        }
                    }
                    else if (control is ComboBox)
                    {
                        ((ComboBox)control).Items.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("SESSION_ID")));

                    }
                }

                in_node.SetString("NEXT_SESSION_ID", out_node.GetString("NEXT_SESSION_ID"));

            } while (!(in_node.GetString("NEXT_SESSION_ID") == ""));

            return true;

        }

        // ViewArchiveTableList()
        //       - View all Archive Table List
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control					: List媛 ?ㅼ뼱媛?control
        //		- ByVal sStep As String						: ?뺤옣 Process Step
        //		- Optional ByVal sMaterialType As String = "" : Material Type
        //		- Optional ByVal sFilter As String = ""		: sFilter濡??쒖옉?섎뒗 Material
        //		- Optional ByVal sTreeItem As String = ""	: TreeView ?먯꽌 異붽???Node??Text
        //		- Optional ByVal sExt_Factory As String = "" : ?꾩옱 Factory媛 ?꾨땶寃쎌슦?????Factory
        //
        public static bool ViewArchiveTableList(Control control, char sStep, string sModule, string sFilter, TreeNode parentNode, string sExtFactory)
        {

            int i;
            ListViewItem itmX;
            TreeNode nodeX;

            TRSNode in_node = new TRSNode("VIEW_ARCHIVE_TABLE_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_ARCHIVE_TABLE_LIST_OUT");

            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }
            else if (!(control is TreeView))
            {
                MPCF.ClearList(control);
            }

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = sStep;

            if (sExtFactory.Trim() != "")
            {
                in_node.Factory = sExtFactory.Trim();
            }
            else
            {
                in_node.Factory = MPGV.gsFactory;
            }

            in_node.AddString("MODULE_NAME", sModule.Trim());

            do
            {
                if (MPCR.CallService("ARC", "ARC_View_Archive_Table_List", in_node, ref out_node) == false)
                {
                	return false;
                }

                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("TBL_NAME")), (int)SMALLICON_INDEX.IDX_CODE_TABLE);
                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetChar("TBL_TYPE")));
                        }
                        ((ListView)control).Items.Add(itmX);
                    }
                    else if (control is TreeView)
                    {
                        nodeX = new TreeNode(MPCF.Trim(out_node.GetList(0)[i].GetString("TBL_NAME")) + " : " + MPCF.Trim(out_node.GetList(0)[i].GetChar("TBL_TYPE")), (int)SMALLICON_INDEX.IDX_CODE_TABLE, (int)SMALLICON_INDEX.IDX_CODE_TABLE);
                        if (!(parentNode == null))
                        {
                            parentNode.Nodes.Add(nodeX);
                        }
                        else
                        {
                            ((TreeView)control).Nodes.Add(nodeX);
                        }
                    }
                    else if (control is ComboBox)
                    {
                        ((ComboBox)control).Items.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("TBL_NAME")));
                    }
                }

                in_node.SetString("TBL_NAME", out_node.GetString("NEXT_TBL_NAME"));
            } while (!(in_node.GetString("TBL_NAME") == ""));

            return true;


        }

        // ViewFactoryList()
        //       - View Factory List
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control					: List媛 ?ㅼ뼱媛?control
        //		- ByVal sStep As String						: ?뺤옣 Process Step
        //		- Optional ByVal sTreeItem As String = ""	: TreeView ?먯꽌 異붽???Node??Text
        //
        public static bool ViewFactoryList(Control control, char sStep, TreeNode parentNode)
        {

            int i;
            ListViewItem itmX;
            TreeNode nodeX;

            TRSNode in_node = new TRSNode("VIEW_FACTORY_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_FACTORY_LIST_OUT");

            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }
            else if (!(control is TreeView))
            {
                MPCF.ClearList(control);
            }

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = sStep;
            in_node.AddString("NEXT_FACTORY", "");

            do
            {
                if (MPCR.CallService("ARC", "ARC_View_Factory_List", in_node, ref out_node) == false)
                {
                	return false;
                }


                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("FACTORY")), (int)SMALLICON_INDEX.IDX_FACTORY);
                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("FAC_DESC")));
                        }
                        ((ListView)control).Items.Add(itmX);
                    }
                    else if (control is TreeView)
                    {
                        nodeX = new TreeNode(MPCF.Trim(out_node.GetList(0)[i].GetString("FACTORY")) + " : " + MPCF.Trim(out_node.GetList(0)[i].GetString("FAC_DESC")), (int)SMALLICON_INDEX.IDX_FACTORY, (int)SMALLICON_INDEX.IDX_FACTORY);
                        if (!(parentNode == null))
                        {
                            parentNode.Nodes.Add(nodeX);
                        }
                        else
                        {
                            ((TreeView)control).Nodes.Add(nodeX);
                        }
                    }
                    else if (control is ComboBox)
                    {
                        ((ComboBox)control).Items.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("FACTORY")));

                    }
                }

                in_node.SetString("NEXT_FACTORY", out_node.GetString("NEXT_FACTORY"));
            } while (!(in_node.GetString("NEXT_FACTORY") == ""));

            return true;

        }

        public static bool CallService(string s_module_name, string s_service_name, TRSNode in_node, ref TRSNode out_node)
        {
            return CallService(s_module_name, s_service_name, in_node, ref out_node, "", 0, DeliveryMode.RReply, false);
        }
        public static bool CallService(string s_module_name, string s_service_name, TRSNode in_node, ref TRSNode out_node, bool b_ignore_message)
        {
            return CallService(s_module_name, s_service_name, in_node, ref out_node, "", 0, DeliveryMode.RReply, b_ignore_message);
        }
        public static bool CallService(string s_module_name, string s_service_name, TRSNode in_node, ref TRSNode out_node, DeliveryMode mode)
        {
            return CallService(s_module_name, s_service_name, in_node, ref out_node, "", 0, mode, false);
        }
        public static bool CallService(string s_module_name, string s_service_name, TRSNode in_node, ref TRSNode out_node, string channel)
        {
            return CallService(s_module_name, s_service_name, in_node, ref out_node, channel, 0, DeliveryMode.RReply, false);
        }
        public static bool CallService(string s_module_name, string s_service_name, TRSNode in_node, ref TRSNode out_node, DeliveryMode mode, bool b_ignore_message)
        {
            return CallService(s_module_name, s_service_name, in_node, ref out_node, "", 0, mode, b_ignore_message);
        }
        public static bool CallService(string s_module_name, string s_service_name, TRSNode in_node, ref TRSNode out_node, string channel, int ttl, DeliveryMode mode, bool b_ignore_message)
        {
            try
            {
                if (MessageCaster.CallService(s_module_name, s_service_name, in_node, ref out_node, channel, ttl, mode) == false)
                {
                    if (b_ignore_message == false)
                        MPCF.ShowMsgBox(MPMH.StatusMessage);

                    return false;
                }
                if (b_ignore_message == false)
                {
                    if (MPCR.CheckContinueProc(out_node) == false)
                    {
                        return false;
                    }
                }

                return true;
            }
            catch (Exception ex)
            {
                if (b_ignore_message == false)
                    MPCF.ShowMsgBox("MPCR.CallService()\n" + ex.Message);

                return false;
            }
        }

        public static bool CallService(string s_module_name, string s_service_name, TRSNode in_node)
        {
            return CallService(s_module_name, s_service_name, in_node, "", 0, DeliveryMode.Multicast, false);
        }
        public static bool CallService(string s_module_name, string s_service_name, TRSNode in_node, bool b_ignore_message)
        {
            return CallService(s_module_name, s_service_name, in_node, "", 0, DeliveryMode.Multicast, b_ignore_message);
        }
        public static bool CallService(string s_module_name, string s_service_name, TRSNode in_node, DeliveryMode mode)
        {
            return CallService(s_module_name, s_service_name, in_node, "", 0, mode, false);
        }
        public static bool CallService(string s_module_name, string s_service_name, TRSNode in_node, string channel)
        {
            return CallService(s_module_name, s_service_name, in_node, channel, 0, DeliveryMode.Multicast, false);
        }
        public static bool CallService(string s_module_name, string s_service_name, TRSNode in_node, DeliveryMode mode, bool b_ignore_message)
        {
            return CallService(s_module_name, s_service_name, in_node, "", 0, mode, b_ignore_message);
        }
        public static bool CallService(string s_module_name, string s_service_name, TRSNode in_node, string channel, int ttl, DeliveryMode mode, bool b_ignore_message)
        {
            try
            {
                if (MessageCaster.CallService(s_module_name, s_service_name, in_node, channel, ttl, mode) == false)
                {
                    if (b_ignore_message == false)
                        MPCF.ShowMsgBox(MPMH.StatusMessage);

                    return false;
                }

                return true;
            }
            catch (Exception ex)
            {
                if (b_ignore_message == false)
                    MPCF.ShowMsgBox("MPCR.CallService()\n" + ex.Message);

                return false;
            }
        }

        // ViewGCMDataList()
        //       - View General Code Data list
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal Form_control As Control				: List媛 ?ㅼ뼱媛?control
        //		- ByVal c_step As String						: ?뺤옣 Process Step
        //		- ByVal table_name As String				: BAS??Table_name
        //		- Optional ByVal Image_idx As Integer = -1	: List View???ㅼ뼱媛??꾩씠肄??몃뜳??
        //		- Optional ByVal Ext_Factory As String = ""	: ?꾩옱 Factory媛 ?꾨땶寃쎌슦??Factory
        //		- Optional ByVal TreeItem As String = ""	: TreeView ?먯꽌 異붽???Node??Text
        //       - Optional ByVal Col As Integer = -1        : Spread 而⑦듃濡ㅼ씪 寃쎌슦 ?곗씠?瑜?肉뚮젮以?Column Index (-1?대㈃ ?뱀젙 Row ?꾩껜??肉뚮젮以?
        //       - Optional ByVal Row As Integer = -1        : Spread 而⑦듃濡ㅼ씪 寃쎌슦 ?곗씠?瑜?肉뚮젮以?Row Index (-1?대㈃ ?뱀젙 Column ?꾩껜??肉뚮젮以?
        //
        public static bool ViewGCMDataList(Control Form_control, char c_step, string table_name)
        {
            return ViewGCMDataList(Form_control, c_step, table_name, -1, null, "", false, -1, -1, null);
        }
        public static bool ViewGCMDataList(Control Form_control, char c_step, string table_name, int Image_idx, TreeNode parentNode, string Ext_Factory)
        {
            return ViewGCMDataList(Form_control, c_step, table_name, Image_idx, parentNode, Ext_Factory, false, -1, -1, null);
        }
        public static bool ViewGCMDataList(Control Form_control, char c_step, string table_name, int Image_idx, TreeNode parentNode, string Ext_Factory, bool bIgnoreError, int Col, int Row, string[] Item)
        {

            ListViewItem itmX;
            TreeNode nodeX;
            FarPoint.Win.Spread.SheetView sheetX;
            int iRow;
            int iCol;
            int iDataCnt = 0;
            int i;
            int j;
            string[] strData = null;
            List<string> sList = new List<string>();
            FarPoint.Win.Spread.CellType.ComboBoxCellType cboCellType;

            TRSNode in_node = new TRSNode("VIEW_DATA_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_DATA_LIST_OUT");

            if (Form_control is ListView)
            {
                MPCF.InitListView((ListView)Form_control);
            }
            else if (Form_control is FarPoint.Win.Spread.FpSpread && (Col > 0 || Row > 0))
            {
                //Do Nothing
            }
            else if (!(Form_control is TreeView))
            {
                MPCF.ClearList(Form_control, true);
            }

            if (Image_idx == -1)
            {
                Image_idx = (int)SMALLICON_INDEX.IDX_CODE_DATA;
            }
            else
            {
                if (MPGV.gIMdiForm.GetSmallIconList().Images[Image_idx] == null)
                {
                    if (bIgnoreError == false)
                    {
                        MPCF.ShowMsgBox("Invalid Image Index");
                    }
                    return false;
                }
            }

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = c_step;

            if (Ext_Factory != "")
            {
                in_node.Factory = Ext_Factory;
            }

            in_node.AddString("TABLE_NAME", table_name);
            in_node.AddString("NEXT_KEY_1", "");
            in_node.AddString("NEXT_KEY_2", "");

            do
            {
                if (MPCR.CallService("BAS", "BAS_View_Data_List", in_node, ref out_node, false) == false)
                {
                    return false;
                }

                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    if (Form_control is ListView)
                    {
                        itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("KEY_1")), Image_idx);
                        if (((ListView)Form_control).Columns.Count > 1)
                        {
                            for (j = 0; j < ((ListView)Form_control).Columns.Count; j++)
                            {
                                switch (j)
                                {
                                    case 0:
                                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("DATA_1")));
                                        break;

                                    case 1:
                                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("DATA_2")));
                                        break;

                                    case 2:
                                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("DATA_3")));
                                        break;

                                    case 3:
                                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("DATA_4")));
                                        break;

                                    case 4:
                                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("DATA_5")));
                                        break;

                                    case 5:
                                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("DATA_6")));
                                        break;

                                    case 6:
                                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("DATA_7")));
                                        break;

                                    case 7:
                                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("DATA_8")));
                                        break;

                                    case 8:
                                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("DATA_9")));
                                        break;

                                    case 9:
                                        itmX.SubItems.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("DATA_10")));
                                        break;
                                }
                            }
                        }
                        ((ListView)Form_control).Items.Add(itmX);
                    }
                    else if (Form_control is TreeView)
                    {
                        nodeX = new TreeNode(MPCF.Trim(out_node.GetList(0)[i].GetString("KEY_1")) + " : " + MPCF.Trim(out_node.GetList(0)[i].GetString("DATA_1")), Image_idx, Image_idx);
                        if (!(parentNode == null))
                        {
                            parentNode.Nodes.Add(nodeX);
                        }
                        else
                        {
                            ((TreeView)Form_control).Nodes.Add(nodeX);
                        }
                    }
                    else if (Form_control is ComboBox)
                    {
                        ((ComboBox)Form_control).Items.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("KEY_1")));
                    }
                    else if (Form_control is FarPoint.Win.Spread.FpSpread)
                    {
                        sheetX = ((FarPoint.Win.Spread.FpSpread)Form_control).ActiveSheet;

                        if (sheetX.Columns.Count == 3)
                        {

                            iRow = sheetX.RowCount;
                            sheetX.RowCount++;

                            iCol = 0;

                            sheetX.Cells[iRow, iCol].Value = MPCF.Trim(out_node.GetList(0)[i].GetString("KEY_1"));

                            iCol++;
                            sheetX.Cells[iRow, iCol].Value = MPCF.Trim(out_node.GetList(0)[i].GetString("KEY_2"));

                            iCol++;
                            sheetX.Cells[iRow, iCol].Value = MPCF.Trim(out_node.GetList(0)[i].GetString("DATA_1"));

                            iCol++;

                        }
                        else
                        {
                            sList.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("KEY_1")));
                        }

                    }

                }

                iDataCnt += out_node.GetList(0).Count;

                in_node.SetString("NEXT_KEY_1", out_node.GetString("NEXT_KEY_1"));
                in_node.SetString("NEXT_KEY_2", out_node.GetString("NEXT_KEY_2"));
            } while (in_node.GetString("NEXT_KEY_1") != "" || in_node.GetString("NEXT_KEY_2") != "");

            if (Form_control is FarPoint.Win.Spread.FpSpread)
            {

                if (((FarPoint.Win.Spread.FpSpread)Form_control).ActiveSheet.Columns.Count == 3)
                {
                    return true;
                }

                if (Item != null)
                {
                    for (i = 0; i < Item.Length; i++)
                    {
                        if (sList.Count < 1)
                        {
                            sList.Add(Item[i]);
                        }
                        else
                        {
                            for (j = 0; j < sList.Count; j++)
                            {
                                if (sList.Contains(Item[i]) == true)
                                {
                                    break;
                                }
                            }

                            if (j >= sList.Count)
                            {
                                sList.Add(Item[i]);
                            }
                        }
                    }
                }
            }

            strData = new string[sList.Count + 1];
            for (i = 0; i < sList.Count; i++)
            {
                strData[i] = sList[i];
            }
            strData[i] = "";

            cboCellType = new FarPoint.Win.Spread.CellType.ComboBoxCellType();
            cboCellType.Items = strData;
            if (Row == -1 && Col == -1)
            {
                //Do Nothing
            }
            else if (Row == -1)
            {
                ((FarPoint.Win.Spread.FpSpread)Form_control).ActiveSheet.Columns.Get(Col).CellType = cboCellType;
            }
            else if (Col == -1)
            {
                ((FarPoint.Win.Spread.FpSpread)Form_control).ActiveSheet.Rows.Get(Row).CellType = cboCellType;
            }
            else
            {
                ((FarPoint.Win.Spread.FpSpread)Form_control).ActiveSheet.Cells.Get(Row, Col).CellType = cboCellType;
            }

            return true;


        }

        // ViewDirectoryName()
        //       - View All Directory Name for Batch Job
        // Return Value
        //       - boolean : True / False
        // Arguments
        //      - ByVal Form_control As Control				: 조회 결과 List를 보여 주기 위한 Control
        //		- ByVal c_step As String					: 처리 Process Step
        //
        public static bool ViewDirectoryName(Control Form_control, char c_step, TreeNode parentNode)
        {
            ListViewItem itmX;
            TreeNode nodeX;
            int iDataCnt = 0;
            int i;
            int Image_idx;
            List<string> sList = new List<string>();

            TRSNode in_node = new TRSNode("VIEW_DIRECTORY_LIST_IN");
            TRSNode out_node = new TRSNode("VIEW_DIRECTORY_LIST_OUT");

            if (Form_control is ListView)
            {
                MPCF.InitListView((ListView)Form_control);
            }
            else if (!(Form_control is TreeView))
            {
                MPCF.ClearList(Form_control, true);
            }

            Image_idx = (int)SMALLICON_INDEX.IDX_CODE_DATA;

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = c_step;
            in_node.AddString("DIRECTORY_NAME", "");
            in_node.AddString("NEXT_DIRECTORY_NAME", "");

            do
            {
                if (MPCR.CallService("ADM", "ADM_View_Directory_List", in_node, ref out_node, false) == false)
                {
                    return false;
                }

                for (i = 0; i < out_node.GetList(0).Count; i++)
                {
                    if (Form_control is ListView)
                    {
                        itmX = new ListViewItem(MPCF.Trim(out_node.GetList(0)[i].GetString("DIRECTORY_NAME")), Image_idx);

                        ((ListView)Form_control).Items.Add(itmX);
                    }
                    else if (Form_control is TreeView)
                    {
                        nodeX = new TreeNode(MPCF.Trim(out_node.GetList(0)[i].GetString("DIRECTORY_NAME")), Image_idx, Image_idx);
                        if (!(parentNode == null))
                        {
                            parentNode.Nodes.Add(nodeX);
                        }
                        else
                        {
                            ((TreeView)Form_control).Nodes.Add(nodeX);
                        }
                    }
                    else if (Form_control is ComboBox)
                    {
                        ((ComboBox)Form_control).Items.Add(MPCF.Trim(out_node.GetList(0)[i].GetString("DIRECTORY_NAME")));
                    }
                }

                iDataCnt += out_node.GetList(0).Count;

                in_node.SetString("NEXT_DIRECTORY_NAME", out_node.GetString("NEXT_DIRECTORY_NAME"));
            } while (in_node.GetString("NEXT_DIRECTORY_NAME") != "");

            return true;
        }

    } // end of class MPCR
}
