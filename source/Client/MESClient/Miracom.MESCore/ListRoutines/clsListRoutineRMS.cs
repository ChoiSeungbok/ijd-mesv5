
using Miracom.H101Core;
using System.Data;
using Miracom.CliFrx;
using System.Collections;

using System.Diagnostics;
using System;
using System.Windows.Forms;
using System.Drawing;
using Miracom.UI.Controls.MCCodeView;

//-----------------------------------------------------------------------------
//
//   System      : MES
//   File Name   : modRMSListRoutine.vb
//   Description : Client Common List function RMS Module
//
//   MES Version : 4.1.0.0
//
//   Function List
//        -
//
//   Detail Description
//       -
//
//   History
//       - **** Do Not Modify in Site!!! ****
//       - 2004-06-09 : Created by HK, Kim
//
//
//   Copyright(C) 1998-2005 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------
//#If _RMS = True Then

namespace Miracom.MESCore
{
    public sealed class RMSLIST
    {
        
        // ViewEquipTypeList()
        //       - View Equipment Type list
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control                    : List媛 ?ㅼ뼱媛?control
        //        - ByVal c_step As String                        : ?뺤옣 Process Step
        //       - Optional ByValsTreeItem As String =""     : TreeView ?먯꽌 異붽???Node??Text
        //        - Optional ByVal sExt_Factory As String = "": ?꾩옱 Factory媛 ?꾨땶寃쎌슦??Factory
        //        - Optional ByVal bIgnoreError As Boolean = False: Error 臾댁떆 ?щ?
        //
        public static bool ViewEquipTypeList(Control control, char c_step, TreeNode parentNode, string sExt_Factory, RMS_TYPE eRMSType)
        {
            
            int i;
            ListViewItem itmX;
            TreeNode nodeX;
            
            RMS_View_Equip_Type_List_In_Tag View_Equip_Type_List_In = new RMS_View_Equip_Type_List_In_Tag();
            RMS_View_Equip_Type_List_Out_Tag View_Equip_Type_List_Out = new RMS_View_Equip_Type_List_Out_Tag();
            
            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }
            else if (!(control is TreeView))
            {
                MPCF.ClearList(control, true);
            }

            View_Equip_Type_List_In.h_proc_step = c_step; 
            View_Equip_Type_List_In.h_passport = MPGV.gsPassport;
            View_Equip_Type_List_In.h_language = MPGV.gcLanguage;
            if (sExt_Factory != "")
            {
                View_Equip_Type_List_In.h_factory = sExt_Factory;
            }
            else
            {
                View_Equip_Type_List_In.h_factory = MPGV.gsFactory;
            }
            View_Equip_Type_List_In.h_user_id = MPGV.gsUserID;
            View_Equip_Type_List_In.h_password = MPGV.gsPassword;
            View_Equip_Type_List_In.next_eq_type = "";
            
            do
            {
                if (RMSCaster.RMS_View_Equip_Type_List(View_Equip_Type_List_In, ref View_Equip_Type_List_Out) == false)
                {
                    MPCF.ShowMsgBox(h101stub.StatusMessage);
                    return false;
                }
                if (View_Equip_Type_List_Out.h_status_value != MPGC.MP_SUCCESS_STATUS)
                {
                    MPCF.ShowMsgBox(MPCF.MakeErrorMsg(View_Equip_Type_List_Out.h_msg_code, View_Equip_Type_List_Out.h_msg, View_Equip_Type_List_Out.h_db_err_msg, View_Equip_Type_List_Out.h_field_msg));
                    return false;
                }
                
                for (i = 0; i <= View_Equip_Type_List_Out.count - 1; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(MPCF.Trim(View_Equip_Type_List_Out.eqtype_list[i].eq_type), (int)SMALLICON_INDEX.IDX_EQ_TYPE);
                        if (((ListView) control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(MPCF.Trim(View_Equip_Type_List_Out.eqtype_list[i].eq_type_desc));
                        }
                        itmX.Tag = MPCF.Trim(View_Equip_Type_List_Out.eqtype_list[i].module_flag);
                        ((ListView) control).Items.Add(itmX);
                    }
                    else if (control is TreeView)
                    {
                        nodeX = new TreeNode(MPCF.Trim(View_Equip_Type_List_Out.eqtype_list[i].eq_type) + " : " + MPCF.Trim(View_Equip_Type_List_Out.eqtype_list[i].eq_type_desc), (int)SMALLICON_INDEX.IDX_EQ_TYPE, (int)SMALLICON_INDEX.IDX_EQ_TYPE);
                        if (eRMSType != RMS_TYPE.RMS_NULL)
                        {
                            clsRMSTag nodeTag = new clsRMSTag(eRMSType);
                            nodeTag.Factory = View_Equip_Type_List_In.h_factory;
                            nodeTag.EQType = MPCF.Trim(View_Equip_Type_List_Out.eqtype_list[i].eq_type);
                            if (MPCF.Trim(View_Equip_Type_List_Out.eqtype_list[i].module_flag) == "Y")
                            {
                                nodeTag.HasModule = true;
                            }
                            else
                            {
                                nodeTag.HasModule = false;
                            }
                            nodeX.Tag = nodeTag;
                        }
                        if (!(parentNode == null))
                        {
                            parentNode.Nodes.Add(nodeX);
                        }
                        else
                        {
                            ((TreeView) control).Nodes.Add(nodeX);
                        }
                    }
                    else if (control is ComboBox)
                    {
                        ((ComboBox) control).Items.Add(MPCF.Trim(View_Equip_Type_List_Out.eqtype_list[i].eq_type));
                        
                    }
                }
                
                View_Equip_Type_List_In.next_eq_type = View_Equip_Type_List_Out.next_eq_type;

            } while (string.IsNullOrEmpty(View_Equip_Type_List_In.next_eq_type) == false);
            
            return true;
            
        }
        
        // ViewAttachEquipList()
        //       - View Attach Equipment list
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control                    : List媛 ?ㅼ뼱媛?control
        //        - ByVal c_step As String                        : ?뺤옣 Process Step
        //       - Optional ByValsTreeItem As String =""     : TreeView ?먯꽌 異붽???Node??Text
        //        - Optional ByVal sExt_Factory As String = "": ?꾩옱 Factory媛 ?꾨땶寃쎌슦??Factory
        //        - Optional ByVal bIgnoreError As Boolean = False: Error 臾댁떆 ?щ?
        //
        public static bool ViewAttachEquipList(Control control, char c_step, string sEquipType, TreeNode parentNode, string sExt_Factory, RMS_TYPE eRMSType)
        {
            
            int i;
            ListViewItem itmX;
            TreeNode nodeX;
            
            RMS_View_Attach_Equip_List_In_Tag View_Attach_Equip_List_In = new RMS_View_Attach_Equip_List_In_Tag();
            RMS_View_Attach_Equip_List_Out_Tag View_Attach_Equip_List_Out = new RMS_View_Attach_Equip_List_Out_Tag();
            
            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }
            else if (!(control is TreeView))
            {
                MPCF.ClearList(control, true);
            }

            View_Attach_Equip_List_In.h_proc_step = c_step; 
            View_Attach_Equip_List_In.h_passport = MPGV.gsPassport;
            View_Attach_Equip_List_In.h_language = MPGV.gcLanguage;
            if (sExt_Factory != "")
            {
                View_Attach_Equip_List_In.h_factory = sExt_Factory;
            }
            else
            {
                View_Attach_Equip_List_In.h_factory = MPGV.gsFactory;
            }
            View_Attach_Equip_List_In.h_user_id = MPGV.gsUserID;
            View_Attach_Equip_List_In.h_password = MPGV.gsPassword;
            View_Attach_Equip_List_In.eq_type = sEquipType;
            View_Attach_Equip_List_In.next_eq_id = "";
            
            do
            {
                if (RMSCaster.RMS_View_Attach_Equip_List(View_Attach_Equip_List_In, ref View_Attach_Equip_List_Out) == false)
                {
                    MPCF.ShowMsgBox(h101stub.StatusMessage);
                    return false;
                }
                if (View_Attach_Equip_List_Out.h_status_value != MPGC.MP_SUCCESS_STATUS)
                {
                    MPCF.ShowMsgBox(MPCF.MakeErrorMsg(View_Attach_Equip_List_Out.h_msg_code, View_Attach_Equip_List_Out.h_msg, View_Attach_Equip_List_Out.h_db_err_msg, View_Attach_Equip_List_Out.h_field_msg));
                    return false;
                }
                
                for (i = 0; i <= View_Attach_Equip_List_Out.count - 1; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(MPCF.Trim(View_Attach_Equip_List_Out.equip_list[i].eq_id), (int)SMALLICON_INDEX.IDX_RESOURCE);
                        if (((ListView) control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(MPCF.Trim(View_Attach_Equip_List_Out.equip_list[i].eq_desc));
                        }
                        ((ListView) control).Items.Add(itmX);
                    }
                    else if (control is TreeView)
                    {
                        nodeX = new TreeNode(MPCF.Trim(View_Attach_Equip_List_Out.equip_list[i].eq_id) + " : " + MPCF.Trim(View_Attach_Equip_List_Out.equip_list[i].eq_desc), (int)SMALLICON_INDEX.IDX_RESOURCE, (int)SMALLICON_INDEX.IDX_RESOURCE);
                        if (eRMSType != RMS_TYPE.RMS_NULL)
                        {
                            clsRMSTag nodeTag = new clsRMSTag(eRMSType);
                            nodeTag.Factory = View_Attach_Equip_List_In.h_factory;
                            nodeTag.EQType = sEquipType;
                            nodeTag.Equipment = MPCF.Trim(View_Attach_Equip_List_Out.equip_list[i].eq_id);
                            nodeTag.HasModule = ((clsRMSTag) parentNode.Tag).HasModule;
                            nodeX.Tag = nodeTag;
                        }
                        if (!(parentNode == null))
                        {
                            parentNode.Nodes.Add(nodeX);
                        }
                        else
                        {
                            ((TreeView) control).Nodes.Add(nodeX);
                        }
                    }
                    else if (control is ComboBox)
                    {
                        ((ComboBox) control).Items.Add(MPCF.Trim(View_Attach_Equip_List_Out.equip_list[i].eq_id));
                        
                    }
                }
                
                View_Attach_Equip_List_In.next_eq_id = View_Attach_Equip_List_Out.next_eq_id;

            } while (string.IsNullOrEmpty(View_Attach_Equip_List_In.next_eq_id) == false);
            
            return true;
            
        }
        
        // ViewModuleList()
        //       - View Attach Equipment list
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control                    : List媛 ?ㅼ뼱媛?control
        //        - ByVal c_step As String                        : ?뺤옣 Process Step
        //       - Optional ByValsTreeItem As String =""     : TreeView ?먯꽌 異붽???Node??Text
        //        - Optional ByVal sExt_Factory As String = "": ?꾩옱 Factory媛 ?꾨땶寃쎌슦??Factory
        //        - Optional ByVal bIgnoreError As Boolean = False: Error 臾댁떆 ?щ?
        //
        public static bool ViewModuleList(Control control, char c_step, string sEquipType, string sEquip, TreeNode parentNode, string sExt_Factory, RMS_TYPE eRMSType)
        {
            
            int i;
            ListViewItem itmX;
            TreeNode nodeX;
            
            RMS_View_Module_List_In_Tag View_Module_List_In = new RMS_View_Module_List_In_Tag();
            RMS_View_Module_List_Out_Tag View_Module_List_Out = new RMS_View_Module_List_Out_Tag();
            
            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }
            else if (!(control is TreeView))
            {
                MPCF.ClearList(control, true);
            }

            View_Module_List_In.h_proc_step = c_step; 
            View_Module_List_In.h_passport = MPGV.gsPassport;
            View_Module_List_In.h_language = MPGV.gcLanguage;
            if (sExt_Factory != "")
            {
                View_Module_List_In.h_factory = sExt_Factory;
            }
            else
            {
                View_Module_List_In.h_factory = MPGV.gsFactory;
            }
            View_Module_List_In.h_user_id = MPGV.gsUserID;
            View_Module_List_In.h_password = MPGV.gsPassword;
            View_Module_List_In.eq_type = sEquipType;
            View_Module_List_In.next_eq_mod_id = "";
            
            do
            {
                if (RMSCaster.RMS_View_Module_List(View_Module_List_In, ref View_Module_List_Out) == false)
                {
                    MPCF.ShowMsgBox(h101stub.StatusMessage);
                    return false;
                }
                if (View_Module_List_Out.h_status_value != MPGC.MP_SUCCESS_STATUS)
                {
                    MPCF.ShowMsgBox(MPCF.MakeErrorMsg(View_Module_List_Out.h_msg_code, View_Module_List_Out.h_msg, View_Module_List_Out.h_db_err_msg, View_Module_List_Out.h_field_msg));
                    return false;
                }
                
                for (i = 0; i <= View_Module_List_Out.count - 1; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(MPCF.Trim(View_Module_List_Out.mod_list[i].eq_mod_id), (int)SMALLICON_INDEX.IDX_MODULE);
                        if (((ListView) control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(MPCF.Trim(View_Module_List_Out.mod_list[i].eq_mod_desc));
                        }
                        ((ListView) control).Items.Add(itmX);
                    }
                    else if (control is TreeView)
                    {
                        nodeX = new TreeNode(MPCF.Trim(View_Module_List_Out.mod_list[i].eq_mod_id) + " : " + MPCF.Trim(View_Module_List_Out.mod_list[i].eq_mod_desc), (int)SMALLICON_INDEX.IDX_MODULE, (int)SMALLICON_INDEX.IDX_MODULE);
                        if (eRMSType != RMS_TYPE.RMS_NULL)
                        {
                            clsRMSTag nodeTag = new clsRMSTag(eRMSType);
                            nodeTag.Factory = View_Module_List_In.h_factory;
                            nodeTag.EQType = sEquipType;
                            nodeTag.Equipment = sEquip;
                            nodeTag.ModuleName = MPCF.Trim(View_Module_List_Out.mod_list[i].eq_mod_id);
                            nodeTag.HasModule = ((clsRMSTag) parentNode.Tag).HasModule;
                            nodeX.Tag = nodeTag;
                        }
                        if (!(parentNode == null))
                        {
                            parentNode.Nodes.Add(nodeX);
                        }
                        else
                        {
                            ((TreeView) control).Nodes.Add(nodeX);
                        }
                    }
                    else if (control is ComboBox)
                    {
                        ((ComboBox) control).Items.Add(MPCF.Trim(View_Module_List_Out.mod_list[i].eq_mod_id));
                        
                    }
                }
                
                View_Module_List_In.next_eq_mod_id = View_Module_List_Out.next_eq_mod_id;

            } while (string.IsNullOrEmpty(View_Module_List_In.next_eq_mod_id) == false);
            
            return true;
            
        }
        
        // ViewParameterList()
        //       - View Parameter list
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control                    : List媛 ?ㅼ뼱媛?control
        //                                                   : ListView, MCCodeView, TreeView, ComboBox, FpSpread
        //        - ByVal c_step As String                        : ?뺤옣 Process Step
        //         Step 1 : All Parameter ID List
        //         Step 2 : Control Parameter ID List
        //         Step 3 : Static Parameter ID List
        //       - Optional ByValsTreeItem As String =""     : TreeView ?먯꽌 異붽???Node??Text
        //        - Optional ByVal sExt_Factory As String = "": ?꾩옱 Factory媛 ?꾨땶寃쎌슦??Factory
        //        - Optional ByVal bIgnoreError As Boolean = False: Error 臾댁떆 ?щ?
        //
        public static bool ViewParameterList(Control control, char c_step, string sEquipType, TreeNode parentNode, string sExt_Factory, RMS_TYPE eRMSType)
        {
            
            int i;
            ListViewItem itmX;
            TreeNode nodeX;
            FarPoint.Win.Spread.SheetView sheetX;
            int iRow;
            int iCol;
            
            RMS_View_Parameter_List_In_Tag View_Parameter_List_In = new RMS_View_Parameter_List_In_Tag();
            RMS_View_Parameter_List_Out_Tag View_Parameter_List_Out = new RMS_View_Parameter_List_Out_Tag();
            
            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }
            else if (control is MCCodeView)
            {
                MPCF.InitListView(((MCCodeView) control).GetListView);
            }
            else if (!(control is TreeView))
            {
                MPCF.ClearList(control, true);
            }

            View_Parameter_List_In.h_proc_step = c_step; 
            View_Parameter_List_In.h_passport = MPGV.gsPassport;
            View_Parameter_List_In.h_language = MPGV.gcLanguage;
            if (sExt_Factory != "")
            {
                View_Parameter_List_In.h_factory = sExt_Factory;
            }
            else
            {
                View_Parameter_List_In.h_factory = MPGV.gsFactory;
            }
            View_Parameter_List_In.h_user_id = MPGV.gsUserID;
            View_Parameter_List_In.h_password = MPGV.gsPassword;
            View_Parameter_List_In.eq_type = sEquipType;
            View_Parameter_List_In.next_para_id = "";
            
            do
            {
                if (RMSCaster.RMS_View_Parameter_List(View_Parameter_List_In, ref View_Parameter_List_Out) == false)
                {
                    MPCF.ShowMsgBox(h101stub.StatusMessage);
                    return false;
                }
                if (View_Parameter_List_Out.h_status_value != MPGC.MP_SUCCESS_STATUS)
                {
                    MPCF.ShowMsgBox(MPCF.MakeErrorMsg(View_Parameter_List_Out.h_msg_code, View_Parameter_List_Out.h_msg, View_Parameter_List_Out.h_db_err_msg, View_Parameter_List_Out.h_field_msg));
                    return false;
                }
                
                for (i = 0; i <= View_Parameter_List_Out.count - 1; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(MPCF.Trim(View_Parameter_List_Out.para_list[i].para_id), (int)SMALLICON_INDEX.IDX_CHARACTER);
                        if (((ListView) control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(MPCF.Trim(View_Parameter_List_Out.para_list[i].para_desc));
                            itmX.SubItems.Add(MPCF.Trim(View_Parameter_List_Out.para_list[i].ctrl_para_flag));
                        }
                        itmX.SubItems.Add(MPCF.Trim(View_Parameter_List_Out.para_list[i].unit));
                        itmX.SubItems.Add(MPCF.Trim(View_Parameter_List_Out.para_list[i].data_type));
                        itmX.SubItems.Add(MPCF.Trim(View_Parameter_List_Out.para_list[i].data_source));
                        ((ListView) control).Items.Add(itmX);
                    }
                    else if (control is MCCodeView)
                    {
                        itmX = new ListViewItem(MPCF.Trim(View_Parameter_List_Out.para_list[i].para_id), (int)SMALLICON_INDEX.IDX_CHARACTER);
                        if (((MCCodeView) control).GetListView.Columns.Count > 1)
                        {
                            itmX.SubItems.Add(MPCF.Trim(View_Parameter_List_Out.para_list[i].para_desc));
                        }
                        ((MCCodeView) control).GetListView.Items.Add(itmX);
                    }
                    else if (control is TreeView)
                    {
                        nodeX = new TreeNode(MPCF.Trim(View_Parameter_List_Out.para_list[i].para_id) + " : " + MPCF.Trim(View_Parameter_List_Out.para_list[i].para_desc), (int)SMALLICON_INDEX.IDX_CHARACTER, (int)SMALLICON_INDEX.IDX_CHARACTER);
                        if (eRMSType != RMS_TYPE.RMS_NULL)
                        {
                            clsRMSTag nodeTag = new clsRMSTag(eRMSType);
                            nodeTag.Factory = View_Parameter_List_In.h_factory;
                            nodeTag.EQType = sEquipType;
                            nodeTag.Parameter = MPCF.Trim(View_Parameter_List_Out.para_list[i].para_id);
                            if (MPCF.Trim(View_Parameter_List_Out.para_list[i].ctrl_para_flag) == "Y")
                            {
                                nodeTag.IsControlParameter = true;
                            }
                            else
                            {
                                nodeTag.IsControlParameter = false;
                            }
                            nodeTag.HasModule = ((clsRMSTag) parentNode.Tag).HasModule;
                            nodeX.Tag = nodeTag;
                        }
                        if (!(parentNode == null))
                        {
                            parentNode.Nodes.Add(nodeX);
                        }
                        else
                        {
                            ((TreeView) control).Nodes.Add(nodeX);
                        }
                    }
                    else if (control is ComboBox)
                    {
                        ((ComboBox) control).Items.Add(MPCF.Trim(View_Parameter_List_Out.para_list[i].para_id));
                    }
                    else if (control is FarPoint.Win.Spread.FpSpread)
                    {
                        sheetX = ((FarPoint.Win.Spread.FpSpread) control).ActiveSheet;
                        iRow = sheetX.RowCount;
                        sheetX.RowCount++;
                        
                        iCol = 0;
                        
                        sheetX.Cells[iRow, iCol].Value = MPCF.Trim(View_Parameter_List_Out.para_list[i].para_id);
                        
                        iCol++;
                        sheetX.Cells[iRow, iCol].Value = MPCF.Trim(View_Parameter_List_Out.para_list[i].para_desc);
                        
                        iCol++;
                        sheetX.Cells[iRow, iCol].Value = MPCF.Trim(View_Parameter_List_Out.para_list[i].unit);
                        
                        iCol++;
                        sheetX.Cells[iRow, iCol].Value = MPCF.Trim(View_Parameter_List_Out.para_list[i].data_type);
                        
                        iCol++;
                        sheetX.Cells[iRow, iCol].Value = MPCF.Trim(View_Parameter_List_Out.para_list[i].data_source);
                        
                        iCol++;
                    }
                }
                
                View_Parameter_List_In.next_para_id = View_Parameter_List_Out.next_para_id;

            } while (string.IsNullOrEmpty(View_Parameter_List_In.next_para_id) == false);
            
            return true;
            
        }
        
        //
        // ViewEqTypeUserList()
        //       - View Equipment Type - User Relation List
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       - ByVal control As Control                    : List媛 ?ㅼ뼱媛?control
        //        - ByVal c_step As String                        : ?뺤옣 Process Step
        //        - ByVal sKey As String                        : Key 媛?(step='1' ?쇨꼍??Prv_Grp_ID, step='2' ??寃쎌슦 User_ID)
        //        - Optional ByVal sExt_Factory As String = "": ?꾩옱 Factory媛 ?꾨땶寃쎌슦??Factory
        //
        public static bool ViewEqTypeUserList(Control control, char c_step, string sKey, TreeNode parentNode, string sExtFactory, RMS_TYPE eRMSType)
        {
            
            int i;
            ListViewItem itmX;
            TreeNode nodeX;
            string sAuthor = "";
            
            RMS_View_EquipType_User_List_In_Tag View_EquipType_User_List_In = new RMS_View_EquipType_User_List_In_Tag() ;
            RMS_View_EquipType_User_List_Out_Tag View_EquipType_User_List_Out = new RMS_View_EquipType_User_List_Out_Tag();
            
            try
            {
                if (control is ListView)
                {
                    MPCF.InitListView((ListView)control);
                }
                if (control is TreeView)
                {
                    MPCF.ClearList(control, true);
                }

                View_EquipType_User_List_In.h_proc_step = c_step; 
                View_EquipType_User_List_In.h_passport = MPGV.gsPassport;
                View_EquipType_User_List_In.h_language = MPGV.gcLanguage;
                View_EquipType_User_List_In.h_user_id = MPGV.gsUserID;
                View_EquipType_User_List_In.h_password = MPGV.gsPassword;
                
                if (sExtFactory != "")
                {
                    View_EquipType_User_List_In.h_factory = sExtFactory;
                }
                else
                {
                    View_EquipType_User_List_In.h_factory = MPGV.gsFactory;
                }
                View_EquipType_User_List_In.next_user_id = "";
                View_EquipType_User_List_In.next_eq_type = "";
                
                if (c_step == '1')
                {
                    View_EquipType_User_List_In.next_eq_type = sKey;
                }
                else if (c_step == '2')
                {
                    View_EquipType_User_List_In.next_user_id = sKey;
                }
                
                do
                {
                    if (RMSCaster.RMS_View_EquipType_User_List(View_EquipType_User_List_In,  ref View_EquipType_User_List_Out) == false)
                    {
                        MPCF.ShowMsgBox(h101stub.StatusMessage);
                        return false;
                    }
                    
                    if (View_EquipType_User_List_Out.h_status_value != MPGC.MP_SUCCESS_STATUS)
                    {
                        MPCF.ShowMsgBox(MPCF.MakeErrorMsg(View_EquipType_User_List_Out.h_msg_code, View_EquipType_User_List_Out.h_msg, View_EquipType_User_List_Out.h_db_err_msg, View_EquipType_User_List_Out.h_field_msg));
                        return false;
                    }
                    
                    for (i = 0; i <= View_EquipType_User_List_Out.count - 1; i++)
                    {
                        sAuthor = "";
                        sAuthor += MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].author_1);
                        sAuthor += MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].author_2);
                        sAuthor += MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].author_3);
                        sAuthor += MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].author_4);
                        sAuthor += MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].author_5);
                        sAuthor += MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].author_6);
                        sAuthor += MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].author_7);
                        sAuthor += MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].author_8);
                        sAuthor += MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].author_9);
                        //sAuthor &= RTrim(View_EquipType_User_List_Out.equiptype_user_list[i].author_10)
                        if (c_step == '1')
                        {
                            if (control is ListView)
                            {
                                itmX = new ListViewItem(MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].user_id), (int)SMALLICON_INDEX.IDX_USER);
                                if (((ListView) control).Columns.Count > 2)
                                {
                                    itmX.SubItems.Add(sAuthor);
                                    itmX.SubItems.Add(MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].user_desc));
                                }
                                ((ListView) control).Items.Add(itmX);
                            }
                            else if (control is TreeView)
                            {
                                nodeX = new TreeNode(MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].user_id) + " : " + MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].user_desc), (int)SMALLICON_INDEX.IDX_USER, (int)SMALLICON_INDEX.IDX_USER);
                                if (eRMSType != RMS_TYPE.RMS_NULL)
                                {
                                    clsRMSTag nodeTag = new clsRMSTag(eRMSType);
                                    nodeTag.Factory = View_EquipType_User_List_In.h_factory;
                                    nodeTag.EQType = sKey;
                                    nodeTag.User = MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].user_id);
                                    nodeTag.HasModule = ((clsRMSTag) parentNode.Tag).HasModule;
                                    nodeX.Tag = nodeTag;
                                }
                                if (!(parentNode == null))
                                {
                                    parentNode.Nodes.Add(nodeX);
                                }
                                else
                                {
                                    ((TreeView) control).Nodes.Add(nodeX);
                                }
                            }
                            else if (control is ComboBox)
                            {
                                ((ComboBox) control).Items.Add(MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].user_id));
                            }
                        }
                        else if (c_step == '2')
                        {
                            if (control is ListView)
                            {
                                itmX = new ListViewItem(MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].eq_type), (int)SMALLICON_INDEX.IDX_EQ_TYPE);
                                if (((ListView) control).Columns.Count > 2)
                                {
                                    itmX.SubItems.Add(sAuthor);
                                    itmX.SubItems.Add(MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].eq_type_desc));
                                }
                                ((ListView) control).Items.Add(itmX);
                            }
                            else if (control is TreeView)
                            {
                                nodeX = new TreeNode(MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].eq_type) + " : " + MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].eq_type_desc), (int)SMALLICON_INDEX.IDX_EQ_TYPE, (int)SMALLICON_INDEX.IDX_EQ_TYPE);
                                if (eRMSType != RMS_TYPE.RMS_NULL)
                                {
                                    clsRMSTag nodeTag = new clsRMSTag(eRMSType);
                                    nodeTag.Factory = View_EquipType_User_List_In.h_factory;
                                    nodeTag.EQType = MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].eq_type);
                                    nodeTag.User = sKey;
                                    nodeTag.HasModule = ((clsRMSTag) parentNode.Tag).HasModule;
                                    nodeX.Tag = nodeTag;
                                }
                                if (!(parentNode == null))
                                {
                                    parentNode.Nodes.Add(nodeX);
                                }
                                else
                                {
                                    ((TreeView) control).Nodes.Add(nodeX);
                                }
                            }
                            else if (control is ComboBox)
                            {
                                ((ComboBox) control).Items.Add(MPCF.Trim(View_EquipType_User_List_Out.equiptype_user_list[i].eq_type));
                            }
                        }
                    }
                    
                    View_EquipType_User_List_In.next_user_id = View_EquipType_User_List_Out.next_user_id;
                    View_EquipType_User_List_In.next_eq_type = View_EquipType_User_List_Out.next_eq_type;
                } while (string.IsNullOrEmpty(View_EquipType_User_List_Out.next_user_id) == false ||
                         string.IsNullOrEmpty(View_EquipType_User_List_Out.next_eq_type) == false);
                
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
            
        }
        
        // ViewMasterRecipeList()
        //       - View Master Recipe list
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control                    : List媛 ?ㅼ뼱媛?control
        //        - ByVal c_step As String                        : ?뺤옣 Process Step
        //       - Optional ByValsTreeItem As String =""     : TreeView ?먯꽌 異붽???Node??Text
        //        - Optional ByVal sExt_Factory As String = "": ?꾩옱 Factory媛 ?꾨땶寃쎌슦??Factory
        //        - Optional ByVal bIgnoreError As Boolean = False: Error 臾댁떆 ?щ?
        //
        public static bool ViewMasterRecipeList(Control control, char c_step, string sEquipType, string sModule, TreeNode parentNode, string sExt_Factory, RMS_TYPE eRMSType)
        {
            
            int i;
            ListViewItem itmX;
            TreeNode nodeX;
            
            RMS_View_Master_Recipe_List_In_Tag View_Master_Recipe_List_In = new RMS_View_Master_Recipe_List_In_Tag();
            RMS_View_Master_Recipe_List_Out_Tag View_Master_Recipe_List_Out = new RMS_View_Master_Recipe_List_Out_Tag();
            
            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }
            else if (!(control is TreeView))
            {
                MPCF.ClearList(control, true);
            }

            View_Master_Recipe_List_In.h_proc_step = c_step; 
            View_Master_Recipe_List_In.h_passport = MPGV.gsPassport;
            View_Master_Recipe_List_In.h_language = MPGV.gcLanguage;
            if (sExt_Factory != "")
            {
                View_Master_Recipe_List_In.h_factory = sExt_Factory;
            }
            else
            {
                View_Master_Recipe_List_In.h_factory = MPGV.gsFactory;
            }
            View_Master_Recipe_List_In.h_user_id = MPGV.gsUserID;
            View_Master_Recipe_List_In.h_password = MPGV.gsPassword;
            View_Master_Recipe_List_In.eq_type = sEquipType;
            View_Master_Recipe_List_In.eq_mod_id = sModule;
            View_Master_Recipe_List_In.next_recipe = "";
            
            do
            {
                if (RMSCaster.RMS_View_Master_Recipe_List(View_Master_Recipe_List_In, ref View_Master_Recipe_List_Out) == false)
                {
                    MPCF.ShowMsgBox(h101stub.StatusMessage);
                    return false;
                }
                if (View_Master_Recipe_List_Out.h_status_value != MPGC.MP_SUCCESS_STATUS)
                {
                    MPCF.ShowMsgBox(MPCF.MakeErrorMsg(View_Master_Recipe_List_Out.h_msg_code, View_Master_Recipe_List_Out.h_msg, View_Master_Recipe_List_Out.h_db_err_msg, View_Master_Recipe_List_Out.h_field_msg));
                    return false;
                }
                
                for (i = 0; i <= View_Master_Recipe_List_Out.count - 1; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(MPCF.Trim(View_Master_Recipe_List_Out.recipe_list[i].recipe), (int)SMALLICON_INDEX.IDX_RECIPE);
                        if (((ListView) control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(MPCF.Trim(View_Master_Recipe_List_Out.recipe_list[i].recipe_desc));
                        }
                        ((ListView) control).Items.Add(itmX);
                    }
                    else if (control is TreeView)
                    {
                        nodeX = new TreeNode(MPCF.Trim(View_Master_Recipe_List_Out.recipe_list[i].recipe) + " : " + MPCF.Trim(View_Master_Recipe_List_Out.recipe_list[i].recipe_desc), (int)SMALLICON_INDEX.IDX_RECIPE, (int)SMALLICON_INDEX.IDX_RECIPE);
                        if (eRMSType != RMS_TYPE.RMS_NULL)
                        {
                            clsRMSTag nodeTag = new clsRMSTag(eRMSType);
                            nodeTag.Factory = View_Master_Recipe_List_In.h_factory;
                            nodeTag.EQType = sEquipType;
                            nodeTag.ModuleName = sModule;
                            nodeTag.Recipe = MPCF.Trim(View_Master_Recipe_List_Out.recipe_list[i].recipe);
                            nodeTag.HasModule = ((clsRMSTag) parentNode.Tag).HasModule;
                            nodeX.Tag = nodeTag;
                        }
                        if (!(parentNode == null))
                        {
                            parentNode.Nodes.Add(nodeX);
                        }
                        else
                        {
                            ((TreeView) control).Nodes.Add(nodeX);
                        }
                    }
                    else if (control is ComboBox)
                    {
                        ((ComboBox) control).Items.Add(MPCF.Trim(View_Master_Recipe_List_Out.recipe_list[i].recipe));
                    }
                }
                
                View_Master_Recipe_List_In.next_recipe = View_Master_Recipe_List_Out.next_recipe;

            } while (string.IsNullOrEmpty(View_Master_Recipe_List_In.next_recipe) == false);
            
            return true;
            
        }
        
        // ViewRecipeVersionList()
        //       - View Master Recipe list
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control                    : List媛 ?ㅼ뼱媛?control
        //        - ByVal c_step As String                        : ?뺤옣 Process Step
        //       - Optional ByValsTreeItem As String =""     : TreeView ?먯꽌 異붽???Node??Text
        //        - Optional ByVal sExt_Factory As String = "": ?꾩옱 Factory媛 ?꾨땶寃쎌슦??Factory
        //        - Optional ByVal bIgnoreError As Boolean = False: Error 臾댁떆 ?щ?
        //
        public static bool ViewMasterRecipeVersionList(Control control, char c_step, string sEquipType, string sModule, string sRecipe, TreeNode parentNode, string sExt_Factory, RMS_TYPE eRMSType)
        {
            
            int i;
            ListViewItem itmX;
            TreeNode nodeX;
            
            RMS_View_Recipe_Version_List_In_Tag View_Recipe_Version_List_In = new RMS_View_Recipe_Version_List_In_Tag() ;
            RMS_View_Recipe_Version_List_Out_Tag View_Recipe_Version_List_Out = new RMS_View_Recipe_Version_List_Out_Tag();
            
            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }
            else if (!(control is TreeView))
            {
                MPCF.ClearList(control, true);
            }

            View_Recipe_Version_List_In.h_proc_step = c_step; 
            View_Recipe_Version_List_In.h_passport = MPGV.gsPassport;
            View_Recipe_Version_List_In.h_language = MPGV.gcLanguage;
            if (sExt_Factory != "")
            {
                View_Recipe_Version_List_In.h_factory = sExt_Factory;
            }
            else
            {
                View_Recipe_Version_List_In.h_factory = MPGV.gsFactory;
            }
            View_Recipe_Version_List_In.h_user_id = MPGV.gsUserID;
            View_Recipe_Version_List_In.h_password = MPGV.gsPassword;
            View_Recipe_Version_List_In.eq_type = sEquipType;
            View_Recipe_Version_List_In.eq_mod_id = sModule;
            View_Recipe_Version_List_In.recipe = sRecipe;
            View_Recipe_Version_List_In.next_recipe_version = "99999999999999";
            
            do
            {
                if (RMSCaster.RMS_View_Recipe_Version_List(View_Recipe_Version_List_In, ref View_Recipe_Version_List_Out) == false)
                {
                    MPCF.ShowMsgBox(h101stub.StatusMessage);
                    return false;
                }
                if (View_Recipe_Version_List_Out.h_status_value != MPGC.MP_SUCCESS_STATUS)
                {
                    MPCF.ShowMsgBox(MPCF.MakeErrorMsg(View_Recipe_Version_List_Out.h_msg_code, View_Recipe_Version_List_Out.h_msg, View_Recipe_Version_List_Out.h_db_err_msg, View_Recipe_Version_List_Out.h_field_msg));
                    return false;
                }
                
                for (i = 0; i <= View_Recipe_Version_List_Out.count - 1; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].recipe_version));
                        if (((ListView) control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].approval_flag));
                            itmX.SubItems.Add(MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].approval_user_id));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(View_Recipe_Version_List_Out.version_list[i].approval_time));
                            itmX.SubItems.Add(MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].activate_flag));
                            itmX.SubItems.Add(MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].activate_user_id));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(View_Recipe_Version_List_Out.version_list[i].activate_time));
                            itmX.SubItems.Add(MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].request_flag));
                            itmX.SubItems.Add(MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].request_user_id));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(View_Recipe_Version_List_Out.version_list[i].request_time));
                            itmX.SubItems.Add(MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].version_comment));
                            if (MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].activate_flag) == "Y")
                            {
                                itmX.BackColor = Color.LawnGreen;
                            }
                        }
                        if (MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].activate_flag) == "Y")
                        {
                            itmX.BackColor = Color.LawnGreen;
                            itmX.ImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_ACTIVATE;
                        }
                        else if (MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].approval_flag) == "Y")
                        {
                            itmX.ImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_APPROVAL;
                        }
                        else if (MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].request_flag) == "Y")
                        {
                            itmX.ImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_REQUEST;
                        }
                        else
                        {
                            itmX.ImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION;
                        }
                        ((ListView) control).Items.Add(itmX);
                    }
                    else if (control is TreeView)
                    {
                        nodeX = new TreeNode(MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].recipe_version));
                        if (MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].activate_flag) == "Y")
                        {
                            nodeX.ImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_ACTIVATE;
                            nodeX.SelectedImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_ACTIVATE;
                        }
                        else if (MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].approval_flag) == "Y")
                        {
                            nodeX.ImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_APPROVAL;
                            nodeX.SelectedImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_APPROVAL;
                        }
                        else if (MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].request_flag) == "Y")
                        {
                            nodeX.ImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_REQUEST;
                            nodeX.SelectedImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_REQUEST;
                        }
                        else
                        {
                            nodeX.ImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION;
                            nodeX.SelectedImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION;
                        }
                        if (eRMSType != RMS_TYPE.RMS_NULL)
                        {
                            clsRMSTag nodeTag = new clsRMSTag(eRMSType);
                            nodeTag.Factory = View_Recipe_Version_List_In.h_factory;
                            nodeTag.EQType = sEquipType;
                            nodeTag.ModuleName = sModule;
                            nodeTag.Recipe = sRecipe;
                            nodeTag.RecipeVersion = MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].recipe_version);
                            nodeTag.HasModule = ((clsRMSTag) parentNode.Tag).HasModule;
                            nodeX.Tag = nodeTag;
                        }
                        if (!(parentNode == null))
                        {
                            parentNode.Nodes.Add(nodeX);
                        }
                        else
                        {
                            ((TreeView) control).Nodes.Add(nodeX);
                        }
                    }
                    else if (control is ComboBox)
                    {
                        ((ComboBox) control).Items.Add(MPCF.Trim(View_Recipe_Version_List_Out.version_list[i].recipe_version));
                    }
                }
                
                View_Recipe_Version_List_In.next_recipe_version = View_Recipe_Version_List_Out.next_recipe_version;

            } while (string.IsNullOrEmpty(View_Recipe_Version_List_In.next_recipe_version) == false);
            
            return true;
            
        }
        
        // ViewEquipRecipeList()
        //       - View Equip Recipe list
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control                    : List媛 ?ㅼ뼱媛?control
        //        - ByVal c_step As String                        : ?뺤옣 Process Step
        //       - Optional ByValsTreeItem As String =""     : TreeView ?먯꽌 異붽???Node??Text
        //        - Optional ByVal sExt_Factory As String = "": ?꾩옱 Factory媛 ?꾨땶寃쎌슦??Factory
        //        - Optional ByVal bIgnoreError As Boolean = False: Error 臾댁떆 ?щ?
        //
        public static bool ViewEquipRecipeList(Control control, char c_step, string sEquipType, string sEquip, string sModule, TreeNode parentNode, string sExt_Factory, RMS_TYPE eRMSType)
        {
            
            int i;
            ListViewItem itmX;
            TreeNode nodeX;
            
            RMS_View_Equip_Recipe_List_In_Tag View_Equip_Recipe_List_In = new RMS_View_Equip_Recipe_List_In_Tag();
            RMS_View_Equip_Recipe_List_Out_Tag View_Equip_Recipe_List_Out = new RMS_View_Equip_Recipe_List_Out_Tag();
            
            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }
            else if (!(control is TreeView))
            {
                MPCF.ClearList(control, true);
            }

            View_Equip_Recipe_List_In.h_proc_step = c_step; 
            View_Equip_Recipe_List_In.h_passport = MPGV.gsPassport;
            View_Equip_Recipe_List_In.h_language = MPGV.gcLanguage;
            if (sExt_Factory != "")
            {
                View_Equip_Recipe_List_In.h_factory = sExt_Factory;
            }
            else
            {
                View_Equip_Recipe_List_In.h_factory = MPGV.gsFactory;
            }
            View_Equip_Recipe_List_In.h_user_id = MPGV.gsUserID;
            View_Equip_Recipe_List_In.h_password = MPGV.gsPassword;
            View_Equip_Recipe_List_In.eq_type = sEquipType;
            View_Equip_Recipe_List_In.eq_id = sEquip;
            View_Equip_Recipe_List_In.eq_mod_id = sModule;
            View_Equip_Recipe_List_In.next_recipe = "";
            
            do
            {
                if (RMSCaster.RMS_View_Equip_Recipe_List(View_Equip_Recipe_List_In, ref View_Equip_Recipe_List_Out) == false)
                {
                    MPCF.ShowMsgBox(h101stub.StatusMessage);
                    return false;
                }
                if (View_Equip_Recipe_List_Out.h_status_value != MPGC.MP_SUCCESS_STATUS)
                {
                    MPCF.ShowMsgBox(MPCF.MakeErrorMsg(View_Equip_Recipe_List_Out.h_msg_code, View_Equip_Recipe_List_Out.h_msg, View_Equip_Recipe_List_Out.h_db_err_msg, View_Equip_Recipe_List_Out.h_field_msg));
                    return false;
                }
                
                for (i = 0; i <= View_Equip_Recipe_List_Out.count - 1; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(MPCF.Trim(View_Equip_Recipe_List_Out.recipe_list[i].recipe));
                        if (((ListView) control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(MPCF.Trim(View_Equip_Recipe_List_Out.recipe_list[i].recipe_desc));
                            if (c_step == '2')
                            {
                                if (View_Equip_Recipe_List_Out.recipe_list[i].recipe_status == MPGC.RMS_RECIPE_STATUS_HOLD)
                                {
                                    itmX.SubItems.Add("HOLD");
                                }
                                else
                                {
                                    itmX.SubItems.Add(MPCF.Trim(View_Equip_Recipe_List_Out.recipe_list[i].recipe_status));
                                }
                                itmX.SubItems.Add(MPCF.Trim(View_Equip_Recipe_List_Out.recipe_list[i].hold_code));
                                itmX.SubItems.Add(MPCF.Trim(View_Equip_Recipe_List_Out.recipe_list[i].hold_engr));
                                itmX.SubItems.Add(MPCF.Trim(View_Equip_Recipe_List_Out.recipe_list[i].hold_comment));
                            }
                        }
                        if (View_Equip_Recipe_List_Out.recipe_list[i].recipe_status == MPGC.RMS_RECIPE_STATUS_HOLD)
                        {
                            itmX.ImageIndex =  (int)SMALLICON_INDEX.IDX_RCP_HOLD;
                        }
                        else
                        {
                            itmX.ImageIndex =  (int)SMALLICON_INDEX.IDX_RECIPE;
                        }
                        ((ListView) control).Items.Add(itmX);
                    }
                    else if (control is TreeView)
                    {
                        nodeX = new TreeNode(MPCF.Trim(View_Equip_Recipe_List_Out.recipe_list[i].recipe) + " : " + MPCF.Trim(View_Equip_Recipe_List_Out.recipe_list[i].recipe_desc));
                        if (View_Equip_Recipe_List_Out.recipe_list[i].recipe_status == MPGC.RMS_RECIPE_STATUS_HOLD)
                        {
                            nodeX.ImageIndex =  (int)SMALLICON_INDEX.IDX_RCP_HOLD;
                            nodeX.SelectedImageIndex =  (int)SMALLICON_INDEX.IDX_RCP_HOLD;
                        }
                        else
                        {
                            nodeX.ImageIndex =  (int)SMALLICON_INDEX.IDX_RECIPE;
                            nodeX.SelectedImageIndex =  (int)SMALLICON_INDEX.IDX_RECIPE;
                        }
                        if (eRMSType != RMS_TYPE.RMS_NULL)
                        {
                            clsRMSTag nodeTag = new clsRMSTag(eRMSType);
                            nodeTag.Factory = View_Equip_Recipe_List_In.h_factory;
                            nodeTag.EQType = sEquipType;
                            nodeTag.Equipment = sEquip;
                            nodeTag.ModuleName = sModule;
                            nodeTag.Recipe = MPCF.Trim(View_Equip_Recipe_List_Out.recipe_list[i].recipe);
                            nodeTag.HasModule = ((clsRMSTag) parentNode.Tag).HasModule;
                            nodeX.Tag = nodeTag;
                        }
                        if (!(parentNode == null))
                        {
                            parentNode.Nodes.Add(nodeX);
                        }
                        else
                        {
                            ((TreeView) control).Nodes.Add(nodeX);
                        }
                    }
                    else if (control is ComboBox)
                    {
                        ((ComboBox) control).Items.Add(MPCF.Trim(View_Equip_Recipe_List_Out.recipe_list[i].recipe));
                    }
                }
                
                View_Equip_Recipe_List_In.next_recipe = View_Equip_Recipe_List_Out.next_recipe;

            } while (string.IsNullOrEmpty(View_Equip_Recipe_List_In.next_recipe) == false);
            
            return true;
            
        }
        
        // ViewRecipeVersionList()
        //       - View Equip Recipe list
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal control As Control                    : List媛 ?ㅼ뼱媛?control
        //        - ByVal c_step As String                        : ?뺤옣 Process Step
        //       - Optional ByValsTreeItem As String =""     : TreeView ?먯꽌 異붽???Node??Text
        //        - Optional ByVal sExt_Factory As String = "": ?꾩옱 Factory媛 ?꾨땶寃쎌슦??Factory
        //        - Optional ByVal bIgnoreError As Boolean = False: Error 臾댁떆 ?щ?
        //
        public static bool ViewEquipRecipeVersionList(Control control, char c_step, string sEquipType, string sEquip, string sModule, string sRecipe, TreeNode parentNode, string sExt_Factory, RMS_TYPE eRMSType)
        {
            
            int i;
            ListViewItem itmX;
            TreeNode nodeX;
            
            RMS_View_Equip_Recipe_Version_List_In_Tag View_Equip_Recipe_Version_List_In = new RMS_View_Equip_Recipe_Version_List_In_Tag();
            RMS_View_Equip_Recipe_Version_List_Out_Tag View_Equip_Recipe_Version_List_Out = new RMS_View_Equip_Recipe_Version_List_Out_Tag();
            
            if (control is ListView)
            {
                MPCF.InitListView((ListView)control);
            }
            else if (!(control is TreeView))
            {
                MPCF.ClearList(control, true);
            }

            View_Equip_Recipe_Version_List_In.h_proc_step = c_step; 
            View_Equip_Recipe_Version_List_In.h_passport = MPGV.gsPassport;
            View_Equip_Recipe_Version_List_In.h_language = MPGV.gcLanguage;
            if (sExt_Factory != "")
            {
                View_Equip_Recipe_Version_List_In.h_factory = sExt_Factory;
            }
            else
            {
                View_Equip_Recipe_Version_List_In.h_factory = MPGV.gsFactory;
            }
            View_Equip_Recipe_Version_List_In.h_user_id = MPGV.gsUserID;
            View_Equip_Recipe_Version_List_In.h_password = MPGV.gsPassword;
            View_Equip_Recipe_Version_List_In.eq_type = sEquipType;
            View_Equip_Recipe_Version_List_In.eq_id = sEquip;
            View_Equip_Recipe_Version_List_In.eq_mod_id = sModule;
            View_Equip_Recipe_Version_List_In.recipe = sRecipe;
            View_Equip_Recipe_Version_List_In.next_recipe_version = "99999999999999";
            
            do
            {
                if (RMSCaster.RMS_View_Equip_Recipe_Version_List(View_Equip_Recipe_Version_List_In,  ref View_Equip_Recipe_Version_List_Out) == false)
                {
                    MPCF.ShowMsgBox(h101stub.StatusMessage);
                    return false;
                }
                if (View_Equip_Recipe_Version_List_Out.h_status_value != MPGC.MP_SUCCESS_STATUS)
                {
                    MPCF.ShowMsgBox(MPCF.MakeErrorMsg(View_Equip_Recipe_Version_List_Out.h_msg_code, View_Equip_Recipe_Version_List_Out.h_msg, View_Equip_Recipe_Version_List_Out.h_db_err_msg, View_Equip_Recipe_Version_List_Out.h_field_msg));
                    return false;
                }
                
                for (i = 0; i <= View_Equip_Recipe_Version_List_Out.count - 1; i++)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].recipe_version));
                        if (((ListView) control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].approval_flag));
                            itmX.SubItems.Add(MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].approval_user_id));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(View_Equip_Recipe_Version_List_Out.version_list[i].approval_time));
                            itmX.SubItems.Add(MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].activate_flag));
                            itmX.SubItems.Add(MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].activate_user_id));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(View_Equip_Recipe_Version_List_Out.version_list[i].activate_time));
                            itmX.SubItems.Add(MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].request_flag));
                            itmX.SubItems.Add(MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].request_user_id));
                            itmX.SubItems.Add(MPCF.MakeDateFormat(View_Equip_Recipe_Version_List_Out.version_list[i].request_time));
                            itmX.SubItems.Add(MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].version_comment));
                        }
                        if (MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].activate_flag) == "Y")
                        {
                            itmX.BackColor = Color.LawnGreen;
                            itmX.ImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_ACTIVATE;
                        }
                        else if (MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].approval_flag) == "Y")
                        {
                            itmX.ImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_APPROVAL;
                        }
                        else if (MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].request_flag) == "Y")
                        {
                            itmX.ImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_REQUEST;
                        }
                        else
                        {
                            itmX.ImageIndex = (int)SMALLICON_INDEX.IDX_VERSION;
                        }
                        ((ListView) control).Items.Add(itmX);
                    }
                    else if (control is TreeView)
                    {
                        nodeX = new TreeNode(MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].recipe_version));
                        if (MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].activate_flag) == "Y")
                        {
                            nodeX.ImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_ACTIVATE;
                            nodeX.SelectedImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_ACTIVATE;
                        }
                        else if (MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].approval_flag) == "Y")
                        {
                            nodeX.ImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_APPROVAL;
                            nodeX.SelectedImageIndex = (int)SMALLICON_INDEX.IDX_VERSION_APPROVAL;
                        }
                        else if (MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].request_flag) == "Y")
                        {
                            nodeX.ImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_REQUEST;
                            nodeX.SelectedImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION_REQUEST;
                        }
                        else
                        {
                            nodeX.ImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION;
                            nodeX.SelectedImageIndex =  (int)SMALLICON_INDEX.IDX_VERSION;
                        }
                        if (eRMSType != RMS_TYPE.RMS_NULL)
                        {
                            clsRMSTag nodeTag = new clsRMSTag(eRMSType);
                            nodeTag.Factory = View_Equip_Recipe_Version_List_In.h_factory;
                            nodeTag.EQType = sEquipType;
                            nodeTag.Equipment = sEquip;
                            nodeTag.ModuleName = sModule;
                            nodeTag.Recipe = sRecipe;
                            nodeTag.RecipeVersion = MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].recipe_version);
                            nodeTag.HasModule = ((clsRMSTag) parentNode.Tag).HasModule;
                            nodeX.Tag = nodeTag;
                        }
                        if (!(parentNode == null))
                        {
                            parentNode.Nodes.Add(nodeX);
                        }
                        else
                        {
                            ((TreeView) control).Nodes.Add(nodeX);
                        }
                    }
                    else if (control is ComboBox)
                    {
                        ((ComboBox) control).Items.Add(MPCF.Trim(View_Equip_Recipe_Version_List_Out.version_list[i].recipe_version));
                    }
                }
                
                View_Equip_Recipe_Version_List_In.next_recipe_version = View_Equip_Recipe_Version_List_Out.next_recipe_version;

            } while (string.IsNullOrEmpty(View_Equip_Recipe_Version_List_In.next_recipe_version) == false);
            
            return true;
            
        }
        
    }
    //#End If
}
