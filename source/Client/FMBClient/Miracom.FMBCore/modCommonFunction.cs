
using System;
using System.Data;
using System.Drawing;
using System.Windows.Forms;
using System.Collections;
using System.Diagnostics;
using Miracom.UI.Controls;
using Miracom.FMBUI;
using Miracom.FMBUI.Controls;
using Infragistics.Win.UltraWinEditors;
using System.Globalization;
using System.Reflection;

using Miracom.CliFrx;
using Miracom.MsgHandler;
using Miracom.MESCore;
using Miracom.TRSCore;


//-----------------------------------------------------------------------------
//
//   System      : FMBClient
//   File Name   : FMBCF.vb
//   Description : Common Function Definition Module
//
//   FMB Version : 1.0.0
//
//   Function List
//       - MakeErrorMsg() : Make error message
//       - FieldClear() : Control included field clear
//       - GetStringBySeperator() : Get string by seperator
//       - InitListView() : Clear Listview and Set Icon source
//       - FindListItem() : ListView에서 특정 Item을 찾는다.
//       - MakeDateFormat() : 일반 문자열을 Time Format으로 변환
//       - DestroyDateFormat() : 날짜 형식의 문자열을 일반 문자열로 변환한다.
//       - RefreshFactoryList() : Refresh Factory List of trvDesignList
//       - RefreshDesignList() : Refresh Design List
//       - RefreshUdrGroupList() : Refresh User Define Group List
//       - SetEnumList() : Make Enum to List
//       - SetTagTypeList() : Make Miracom.FMBUI.Enums.eToolType Enum to List
//       - SetFontSize() : Set Font Size
//       - GetIndexedControl() : parentControl 위에 있는 동일한 Prefix이름을 가진 control만을 이름순으로 정렬하여 리스트로 만든다.
//       - PublishMsgTune() : Publish Message Tune
//       - ChangeFromDateFormat() : Change 14 byte DateTime format of DateTimePicker
//       - ChangeToDateFormat() : Change 14 byte DateTime format of DateTimePicker
//       - GetChildForm() : Child Form이 있는지 확인한다
//       - GetScale() : Get Scale
//       - StartTimerProgress() : Start Timer
//       - StopTimerProgress() : Stop Timer
//       - SelectText() : Select Text of the TextBox
//       - GetControl() : Get Control from the panel
//       - RefreshControl() : Refresh Control Status
//       -MPCF.ShowMsgBox() : Show Message Box
//       - CheckGRPCMFValue() : Check Group/Cmf Value
//       - FieldVisableStatus() : Change Field Visible
//       - CheckCMFKeyPress() : Check Cmf CodeView Key Press Event
//       - InitGRPCMFControl() : initial Group/Cmf Control
//       - ClearList() : Clear List Control
//       - FindTreeNode() : Find Tree Node
//       - GetFactoryNode() : Get Factory Node
//       - SetStatusMsg() : Set Statusbar Message
//       - ToAsc() : String to Ascii
//       - ToChar() : String to Character
//       - GetTextboxStyle() : Set Textbox Style by Option
//       - Client_Upgrade() : Upgrade Client
//       - GetHelpURL() : Get Help URL
//       - CheckSecurityFormControl() : Check Security Form Control
//       - CheckAvailableFunction() : Check Available Function
//        - ByteLen() : Get byte length in String
//        - ByteMid() : Get Middle String at byte length in String
//        - CheckMaxLength() : check byte text length in TextBox
//       - CheckValue() :  Check the value is correct
//       - UpdateResourceLocation() :  Update Resource Location
//       - UpdateUDRResourceLocation() :  Update User Define Resource Location
//       - ViewLayOut() :  View Layout Information
//       - ViewUDRGroup() : View User Define Group Information
//       - ConvertColorToString() :  Convert color to string
//       - ConvertStringToColor() :  Convert string to color
//       - ViewGlobalOption() :  View Global Options
//       - CheckAllFactoryOption() :  Set All Factory Option
//
//   Detail Description
//       -
//
//   History
//       - 2005-02-01 : Created by Laverwon
//       - 2005-02-01 : Insert MakeErrorMsg() by Laverwon
//       - 2005-02-11 : Insert FieldClear() by Hkyung
//       - 2005-02-11 : Insert GetStringBySeperator() by Laverwon
//       - 2005-02-12 : Insert RefreshFactoryList() by Laverwon
//
//   Copyright(C) 1998-2004 MIRACOM,INC.
//   All rights reserved.
//
//-----------------------------------------------------------------------------

namespace Miracom.FMBCore
{
    public sealed class FMBPublish : ServiceDispatcher
    {

        public bool dispatch(string s_service_name, TRSNode in_node, TRSNode out_node)
        {
            if (s_service_name.Equals("RAS_Event_Publish"))
                RAS_Event_Publish(in_node);
            else if (s_service_name.Equals("RAS_Port_Event_Publish"))
                RAS_Port_Event_Publish(in_node);
            else if (s_service_name.Equals("RAS_Sub_Resource_Event_Publish"))
                RAS_Sub_Resource_Event_Publish(in_node);
            else if (s_service_name.Equals("RAS_Tool_Event_Publish"))
                RAS_Tool_Event_Publish(in_node);
            else
                return false;

            return true;

        }

        // RAS_Event_Publish()
        //       - RAS Event Publish Message Process
        // Return Value
        //       - Integer : MP_SUCCESS or MP_FAIL
        // Arguments
        //       - ByRef FMB_Event_Publish_Msg_In As FMB_Event_Publish_Msg_In_Tag
        //
        public void RAS_Event_Publish(TRSNode node)
        {
            try
            {
                if (node.ProcStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    FMBFI.gIMdiForm.CreateResourceEvent(node.GetString("FACTORY"), node.GetString("RES_ID"), node.GetChar("RES_UP_DOWN_FLAG").ToString());
                }
                else if (node.ProcStep == modGlobalConstant.MP_STEP_DELETE)
                {
                    FMBFI.gIMdiForm.DeleteResourceEvent(node.GetString("FACTORY"), node.GetString("RES_ID"));
                }

                foreach (Form frmChild in MPGV.gfrmMDI.MdiChildren)
                {
                    if (frmChild is frmFMBDesign)
                    {
                        Miracom.FMBUI.clsCtrlStatus ResourceStatus = new Miracom.FMBUI.clsCtrlStatus();
                        ResourceStatus.ToolType = Miracom.FMBUI.Enums.eToolType.Resource;
                        ResourceStatus.IsUserGroupDesign = (System.Convert.ToString(((frmFMBDesign)frmChild).Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT) ? false : true;
                        ResourceStatus.Factory = node.GetString("FACTORY");
                        ResourceStatus.Key = node.GetString("RES_ID");
                        ResourceStatus.LastEvent = node.GetString("LAST_EVENT_ID");
                        ResourceStatus.PrimaryStatus = node.GetString("RES_PRI_STS");
                        ResourceStatus.ProcMode = node.GetString("RES_PROC_MODE");
                        ResourceStatus.CtrlMode = node.GetString("RES_CTRL_MODE");
                        ResourceStatus.ResourceType = node.GetString("RES_TYPE");
                        ResourceStatus.AreaID = node.GetString("AREA_ID");
                        ResourceStatus.SubAreaID = node.GetString("SUB_AREA_ID");
                        ResourceStatus.UpDownFlag = node.GetChar("RES_UP_DOWN_FLAG").ToString();
                        ResourceStatus.IsDeleteRes = (node.GetChar("DELETE_FLAG") == 'Y') ? true : false;
                        if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(ResourceStatus.Factory, clsOptionData.Options.IsProcessMode)) == "P")
                        {
                            ResourceStatus.IsProcessMode = true;
                        }
                        else
                        {
                            ResourceStatus.IsProcessMode = false;
                        }
                        if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(ResourceStatus.Factory, clsOptionData.Options.UseEventColor)) == "Y")
                        {
                            ResourceStatus.IsUseEventColor = true;
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(ResourceStatus.Factory, clsOptionData.Options.BackColorOpt)) == "EVENT")
                            {
                                ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(ResourceStatus.Factory, ResourceStatus.ToolType.ToString(), ResourceStatus.LastEvent).ToArgb();
                            }
                            else
                            {
                                ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(ResourceStatus.Factory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                            }
                        }
                        else
                        {
                            ResourceStatus.IsUseEventColor = false;
                        }                        
                        
                        ((frmFMBDesign)frmChild).RefreshControlEvent(((frmFMBDesign)frmChild).pnlFMBDesign.Controls, ref ResourceStatus, 2);
                    }
                }

            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }


        public void RAS_Tool_Event_Publish(TRSNode node)
        {

            try
            {
                if (node.ProcStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    FMBFI.gIMdiForm.CreateToolEvent(MPCF.RTrim(node.GetString("FACTORY")), MPCF.RTrim(node.GetString("TOOL_ID")));
                }
                else if (node.ProcStep == modGlobalConstant.MP_STEP_DELETE)
                {
                    FMBFI.gIMdiForm.DeleteToolEvent(MPCF.RTrim(node.GetString("FACTORY")), MPCF.RTrim(node.GetString("TOOL_ID")));
                }

                System.Windows.Forms.Form frmChild;
                foreach (System.Windows.Forms.Form tempLoopVar_frmChild in MPGV.gfrmMDI.MdiChildren)
                {
                    frmChild = tempLoopVar_frmChild;
                    if (frmChild is frmFMBDesign)
                    {
                        Miracom.FMBUI.clsCtrlStatus ResourceStatus = new Miracom.FMBUI.clsCtrlStatus();
                        ResourceStatus.ToolType = Miracom.FMBUI.Enums.eToolType.Tool;
                        ResourceStatus.IsUserGroupDesign = (System.Convert.ToString(((frmFMBDesign)frmChild).Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT) ? false : true;
                        ResourceStatus.Factory = MPCF.RTrim(node.GetString("FACTORY"));
                        ResourceStatus.Key = MPCF.RTrim(node.GetString("TOOL_ID"));
                        ResourceStatus.MotherResourceID =  MPCF.RTrim(node.GetString("RES_ID"));
                        ResourceStatus.ResourceType =  MPCF.RTrim(node.GetString("TOOL_TYPE"));
                        ResourceStatus.AreaID =  MPCF.RTrim(node.GetString("AREA_ID"));
                        ResourceStatus.SubAreaID =  MPCF.RTrim(node.GetString("SUB_AREA_ID"));
                        ResourceStatus.PrimaryStatus =  MPCF.RTrim(node.GetString("TOOL_STATUS"));
                        ResourceStatus.IsDeleteRes = (MPCF.RTrim(node.GetChar("DELETE_FLAG")) == "Y") ? true : false;
                        ResourceStatus.LastEvent =  MPCF.RTrim(node.GetString("LAST_TOOL_EVENT_ID"));
                                               
                        if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(ResourceStatus.Factory, clsOptionData.Options.UseEventColor)) == "Y")
                        {
                            ResourceStatus.IsUseEventColor = true;
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(ResourceStatus.Factory, clsOptionData.Options.BackColorOpt)) == "EVENT")
                            {
                                ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(ResourceStatus.Factory, ResourceStatus.ToolType.ToString(), ResourceStatus.LastEvent).ToArgb();
                            }
                            else
                            {
                                ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(ResourceStatus.Factory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                            }
                        }
                        else
                        {
                            ResourceStatus.IsUseEventColor = false;
                        }
                        ((frmFMBDesign)frmChild).RefreshControlEvent(((frmFMBDesign)frmChild).pnlFMBDesign.Controls, ref ResourceStatus, 2);
                   }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("FMBCF.RAS_Tool_Event_Publish()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
        }
        
        // RAS_Port_Event_Publish()
        //       - RAS Port Event Publish Message Process
        // Return Value
        //       - Integer : MP_SUCCESS or MP_FAIL
        // Arguments
        //       - ByRef FMB_Port_Event_Publish_Msg_In As FMB_Event_Publish_Msg_In_Tag
        //
        public void RAS_Port_Event_Publish(TRSNode node)
        {

            try
            {
                if (node.ProcStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    FMBFI.gIMdiForm.CreatePortEvent(MPCF.RTrim(node.GetString("FACTORY")), MPCF.RTrim(node.GetString("PORT_ID")));
                }
                else if (node.ProcStep == modGlobalConstant.MP_STEP_DELETE)
                {
                    FMBFI.gIMdiForm.DeleteResourceEvent(MPCF.RTrim(node.GetString("FACTORY")), MPCF.RTrim(node.GetString("PORT_ID")));
                }

                System.Windows.Forms.Form frmChild;
                foreach (System.Windows.Forms.Form tempLoopVar_frmChild in MPGV.gfrmMDI.MdiChildren)
                {
                    frmChild = tempLoopVar_frmChild;
                    if (frmChild is frmFMBDesign)
                    {
                        Miracom.FMBUI.clsCtrlStatus ResourceStatus = new Miracom.FMBUI.clsCtrlStatus();
                        ResourceStatus.ToolType = Miracom.FMBUI.Enums.eToolType.Port;
                        ResourceStatus.IsUserGroupDesign = (System.Convert.ToString(((frmFMBDesign)frmChild).Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT) ? false : true;
                        ResourceStatus.Factory = MPCF.RTrim(node.GetString("FACTORY"));
                        ResourceStatus.Key = MPCF.RTrim(node.GetString("PORT_ID"));
                        ResourceStatus.MotherResourceID = MPCF.RTrim(node.GetString("RES_ID"));
                        ResourceStatus.ResourceType = MPCF.RTrim(node.GetChar("PORT_TYPE"));
                        ResourceStatus.PrimaryStatus = MPCF.RTrim(node.GetString("TRS_STATE"));
                       
                        if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(ResourceStatus.Factory, clsOptionData.Options.UseEventColor)) == "Y")
                        {
                            ResourceStatus.IsUseEventColor = true;
                            ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(ResourceStatus.Factory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                        }
                        else
                        {
                            ResourceStatus.IsUseEventColor = false;
                        }
                        ((frmFMBDesign)frmChild).RefreshControlEvent(((frmFMBDesign)frmChild).pnlFMBDesign.Controls, ref ResourceStatus, 2);
                   }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("FMBCF.RAS_Port_Event_Publish()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
        }

        // RAS_Sub_ResourceEvent_Publish()
        //       - RAS Sub Resource Event Publish Message Process
        // Return Value
        //       - Integer : MP_SUCCESS or MP_FAIL
        // Arguments
        //       - ByRef FMB_Sub_Resource_Event_Publish_Msg_In As FMB_Event_Publish_Msg_In_Tag
        //
        public void RAS_Sub_Resource_Event_Publish(TRSNode node)
        {

            try
            {
                if (node.ProcStep == modGlobalConstant.MP_STEP_CREATE)
                {
                    FMBFI.gIMdiForm.CreateSubResourceEvent(MPCF.RTrim(node.GetString("FACTORY")),  MPCF.RTrim(node.GetString("RES_ID")), MPCF.RTrim(node.GetString("SUBRES_ID")), node.GetChar("RES_UP_DOWN_FLAG").ToString());
                }
                else if (node.ProcStep == modGlobalConstant.MP_STEP_DELETE)
                {
                    FMBFI.gIMdiForm.DeleteSubResourceEvent(MPCF.RTrim(node.GetString("FACTORY")), MPCF.RTrim(node.GetString("RES_ID")), MPCF.RTrim(node.GetString("SUBRES_ID")));
                }

                System.Windows.Forms.Form frmChild;
                foreach (System.Windows.Forms.Form tempLoopVar_frmChild in MPGV.gfrmMDI.MdiChildren)
                {
                    frmChild = tempLoopVar_frmChild;
                    if (frmChild is frmFMBDesign)
                    {
                        Miracom.FMBUI.clsCtrlStatus ResourceStatus = new Miracom.FMBUI.clsCtrlStatus();
                        ResourceStatus.ToolType = Miracom.FMBUI.Enums.eToolType.SubResource;
                        ResourceStatus.IsUserGroupDesign = (System.Convert.ToString(((frmFMBDesign)frmChild).Tag) == modGlobalConstant.FMB_CATEGORY_LAYOUT) ? false : true;
                        ResourceStatus.Factory =  MPCF.RTrim(node.GetString("FACTORY"));
                        ResourceStatus.Key =  MPCF.RTrim(node.GetString("SUBRES_ID"));
                        ResourceStatus.MotherResourceID =  MPCF.RTrim(node.GetString("RES_ID"));
                        ResourceStatus.LastEvent =  MPCF.RTrim(node.GetString("LAST_EVENT_ID"));
                        ResourceStatus.PrimaryStatus =  MPCF.RTrim(node.GetString("SUBRES_PRI_STS"));
                        ResourceStatus.ResourceType =  MPCF.RTrim(node.GetString("SUBRES_TYPE"));
                        ResourceStatus.UpDownFlag =  MPCF.RTrim(node.GetChar("SUBRES_UP_DOWN_FLAG"));
                        ResourceStatus.IsDeleteRes= (MPCF.RTrim(node.GetChar("DELETE_FLAG")) == "Y") ? true : false;
                        ResourceStatus.LastEvent =  MPCF.RTrim(node.GetString("LAST_EVENT_ID"));
                                             
                        if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(ResourceStatus.Factory, clsOptionData.Options.UseEventColor)) == "Y")
                        {
                            ResourceStatus.IsUseEventColor = true;
                            if (System.Convert.ToString(modGlobalVariable.gGlobalOptions.GetOptions(ResourceStatus.Factory, clsOptionData.Options.BackColorOpt)) == "EVENT")
                            {
                                ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(ResourceStatus.Factory, ResourceStatus.ToolType.ToString(), ResourceStatus.LastEvent).ToArgb();
                            }
                            else
                            {
                                ResourceStatus.EventBackColor = modGlobalVariable.gGlobalOptions.GetOptions(ResourceStatus.Factory, ResourceStatus.ToolType.ToString(), ResourceStatus.PrimaryStatus).ToArgb();
                            }
                        }
                        else
                        {
                            ResourceStatus.IsUseEventColor = false;
                        }
                        ((frmFMBDesign)frmChild).RefreshControlEvent(((frmFMBDesign)frmChild).pnlFMBDesign.Controls, ref ResourceStatus, 2);
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("FMBCF.RAS_Sub_Resource_Event_Publish()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
            }
        }
    }
    public sealed class FMBCF
    {

        #region " Variable Definition"
        #endregion

      
        // GetStringBySeperator()
        //       - Get string by seperator
        // Return Value
        //       - String : Return string
        // Arguments
        //       - ByVal sSource As String  : Source String Data
        //       - ByVal sSeperator As String : Seperator
        //       - ByVal iPosition As Integer : Seperator Position
        //
        public static string GetStringBySeperator(string sSource, string sSeperator, int iPosition)
        {

            string sReturn = "";

            try
            {
                int i = 0;
                int iStartPos = 0;
                int iFindPos = 0;
                if (sSource.IndexOf(sSeperator) < 0)
                {
                    return sReturn;
                }
                while (i < iPosition)
                {
                    iFindPos = sSource.IndexOf(sSeperator, iStartPos);
                    if (iFindPos < 0)
                    {
                        sReturn = sSource.Substring(iStartPos);
                        break;
                    }
                    else
                    {
                        sReturn = sSource.Substring(iStartPos, iFindPos - iStartPos);
                    }
                    iStartPos = iFindPos + sSeperator.Length;
                    i++;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("FMBCF.GetStringBySeperator()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                sReturn = "";
            }

            return sReturn;

        }

      
        // SetEnumList()
        //       - Enum to List
        // Return Value
        //       -
        // Arguments
        //       - ByVal cboTarget As ComboBox   :  Combo Box
        //       - ByVal enumType As Type        :  Type
        //
        public static void SetEnumList(ComboBox cboTarget, Type enumType)
        {

            try
            {
                cboTarget.Items.Clear();
                foreach (string sEnumString in @Enum.GetNames(enumType))
                {
                    cboTarget.Items.Add(sEnumString);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("FMBCF.SetEnumList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        // SetEnumList()
        //       - Enum to List
        // Return Value
        //       -
        // Arguments
        //       - ByVal cboTarget As Infragistics.Win.UltraWinEditors.UltraComboEditor   :  Combo Box
        //       - ByVal enumType As Type        :  Type
        //
        public static void SetEnumList(Infragistics.Win.UltraWinEditors.UltraComboEditor cboTarget, Type enumType)
        {

            try
            {
                cboTarget.Items.Clear();
                foreach (string sEnumString in @Enum.GetNames(enumType))
                {
                    cboTarget.Items.Add(sEnumString);
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("FMBCF.SetEnumList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        // SetTagTypeList()
        //       - Miracom.FMBUI.Enums.eToolType Enum to List
        // Return Value
        //       -
        // Arguments
        //       - ByVal cboShape As ComboBox   :  Combo Box
        //
        public static void SetTagTypeList(ComboBox cboShape)
        {

            try
            {
                cboShape.Items.Clear();
                foreach (string sToolType in @Enum.GetNames(typeof(Miracom.FMBUI.Enums.eToolType)))
                {
                    if (sToolType != Miracom.FMBUI.Enums.eToolType.Resource.ToString() && sToolType != Miracom.FMBUI.Enums.eToolType.Null.ToString())
                    {
                        cboShape.Items.Add(sToolType);
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("FMBCF.SetTagTypeList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        // SetTagTypeList()
        //       - Miracom.FMBUI.Enums.eToolType Enum to List
        // Return Value
        //       -
        // Arguments
        //       - ByVal cboShape As Infragistics.Win.UltraWinEditors.UltraComboEditor   :  Combo Box
        //
        public static void SetTagTypeList(Infragistics.Win.UltraWinEditors.UltraComboEditor cboShape)
        {

            try
            {
                cboShape.Items.Clear();
                string sToolType;
                foreach (string tempLoopVar_sToolType in @Enum.GetNames(typeof(Miracom.FMBUI.Enums.eToolType)))
                {
                    sToolType = tempLoopVar_sToolType;
                    if (sToolType != System.Convert.ToString(Miracom.FMBUI.Enums.eToolType.Resource) && sToolType != System.Convert.ToString(Miracom.FMBUI.Enums.eToolType.Null)
                        && sToolType != System.Convert.ToString(Miracom.FMBUI.Enums.eToolType.SubResource) && sToolType != System.Convert.ToString(Miracom.FMBUI.Enums.eToolType.Port)
                        &&sToolType != System.Convert.ToString(Miracom.FMBUI.Enums.eToolType.Tool))
                    {
                        cboShape.Items.Add(sToolType);
                    }
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("FMBCF.SetTagTypeList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        public static void SetResShapeList(Infragistics.Win.UltraWinEditors.UltraComboEditor cboShape)
        {

            try
            {
                cboShape.Items.Clear();
                string sResShape;
                foreach (string tempLoopVar_sResShape in @Enum.GetNames(typeof(Miracom.FMBUI.Enums.eResourceShape)))
                {
                    sResShape = tempLoopVar_sResShape;
                    cboShape.Items.Add(sResShape);
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("FMBCF.SetTagTypeList()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        // SetFontSize()
        //       - Set Font Size
        // Return Value
        //       -
        // Arguments
        //       - ByVal cboFontSize As ComboBox   :  Combo Box
        //
        public static void SetFontSize(ComboBox cboFontSize)
        {

            int i;

            try
            {
                cboFontSize.Items.Clear();
                for (i = 5; i <= 20; i++)
                {
                    cboFontSize.Items.Add(i);
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("FMBCF.SetFontSize()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        // SetFontSize()
        //       - Set Font Size
        // Return Value
        //       -
        // Arguments
        //       - ByVal cboFontSize As Infragistics.Win.UltraWinEditors.UltraComboEditor   :  Combo Box
        //
        public static void SetFontSize(Infragistics.Win.UltraWinEditors.UltraComboEditor cboFontSize)
        {

            int i;

            try
            {
                cboFontSize.Items.Clear();
                for (i = 5; i <= 20; i++)
                {
                    cboFontSize.Items.Add(i);
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("FMBCF.SetFontSize()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        // GetIndexedControl()
        //       - parentControl 위에 있는 동일한 Prefix이름을 가진 control만을 이름순으로 정렬하여 리스트로 만든다.
        // Return Value
        //       - ArrayLiat : 이름으로 정렬된 control의 리스트
        // Arguments
        //       - ByVal sControlName As String : Control의 Prefix이름
        //        - ByVal parentControl As Control : Control들이 올라가 있는 parentControl
        //
        public static ArrayList GetIndexedControl(string sControlName, Control parentControl)
        {

            try
            {
                Control control;
                ArrayList alControl = new ArrayList();
                ControlNameSort nameSort = new ControlNameSort();

                foreach (Control tempLoopVar_control in parentControl.Controls)
                {
                    control = tempLoopVar_control;
                    if (control.Name.Length > sControlName.Length)
                    {
                        if (control.Name.ToUpper().Substring(0, sControlName.Length) == sControlName.ToUpper())
                        {
                            alControl.Add(control);
                        }
                    }
                }
                alControl.Sort(nameSort);
                return alControl;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.GetIndexedControl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return null;
            }

        }

        // PublishMsgTune()
        //       - Publish Message Tune
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       -
        //
        public static bool PublishMsgTune()
        {

            try
            {
                string sPublishChannel;

                sPublishChannel = "/" + MPGV.gsSiteID;
                sPublishChannel += "/FMB";
                sPublishChannel += "/" + MPGV.gsFactory;

                MPMH.registerDispatcher("FMB", new FMBPublish()); 
                if (true != MPMH.tune(sPublishChannel, true, false))
                {
                    MPCF.ShowMsgBox("Message Tuning " + MPMH.StatusMessage, "Message Tuning", MessageBoxButtons.OK, 1);
                    return false;
                }

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.PublishMsgTune()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

            return true;

        }

        // ChangeFromDateFormat()
        //       -   Change 14 byte DateTime format of DateTimePicker
        // Return Value
        //       - String : 14 byte DateTime
        // Arguments
        //       - ByVal dtpTime As DateTimePicker
        //
        public static string ChangeFromDateFormat(DateTimePicker dtpTime)
        {

            try
            {
                string sDateTime = "";
                DateTime DTime;

                DTime = dtpTime.Value;

                sDateTime = DTime.Year.ToString("0000");
                sDateTime = sDateTime + DTime.Month.ToString("00");
                sDateTime = sDateTime + DTime.Day.ToString("00");
                sDateTime = sDateTime + DTime.Hour.ToString("00");
                sDateTime = sDateTime + DTime.Minute.ToString("00");
                sDateTime = sDateTime + DTime.Second.ToString("00");

                return sDateTime;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.ChangeFromDateFormat()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return "";
            }

        }

        // ChangeToDateFormat()
        //       -   Change 14 byte DateTime format of DateTimePicker
        // Return Value
        //       - String : 14 byte DateTime
        // Arguments
        //       - ByVal dtpTime As DateTimePicker
        //
        public static string ChangeToDateFormat(DateTimePicker dtpTime)
        {

            try
            {
                string sDateTime = "";
                DateTime DTime;

                DTime = dtpTime.Value;

                sDateTime = DTime.Year.ToString("0000");
                sDateTime = sDateTime + DTime.Month.ToString("00");
                sDateTime = sDateTime + DTime.Day.ToString("00");
                sDateTime = sDateTime + "235959";

                return sDateTime;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.ChangeToDateFormat()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return "";
            }

        }

        // GetChildForm()
        //       - Child Form이 있는지 확인한다
        // Return Value
        //       - True or False
        // Arguments
        //       - ByVal MDIForm As Form : MDI Parent Form
        //       - ByVal ChildForm As String : 현재 띄울 Child Form Name
        //
        static public Form GetChildForm(Form MDIForm, string ChildForm)
        {

            Form SForm;
            int iCount;

            try
            {
                ChildForm = ChildForm.ToUpper();
                iCount = 0;
                //if (!(MDIForm.ActiveForm == null))
                if (MDIForm.ActiveMdiChild != null)
                {
                   // foreach (Form tempLoopVar_SForm in MDIForm.ActiveForm.MdiChildren)
                    foreach (Form tempLoopVar_SForm in MDIForm.MdiChildren)
                    {
                        SForm = tempLoopVar_SForm;
                        if (SForm.Name.ToUpper() == ChildForm)
                        {
                            if (iCount < 9 && (ChildForm == "FRMFMBVIEWRESOURCESTATUS" || ChildForm == "FRMFMBVIEWRESOURCEHISTORY"))
                            {
                                iCount++;
                            }
                            else
                            {
                                SForm.Activate();
                                return SForm;
                            }
                        }
                    }
                }

                return null;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.GetChildForm()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }
            return null;
        }

        // GetScale()
        //       - Get Scale
        // Return Value
        //       - Double : 비율
        // Arguments
        //       - ByVal iZoomScale As Integer : case
        //
        public static double GetScale(int iZoomScale)
        {

            double dScale = 1;

            try
            {
                switch (iZoomScale)
                {
                    case 5:

                        dScale = 2;
                        break;
                    case 4:

                        dScale = 1.8;
                        break;
                    case 3:

                        dScale = 1.6;
                        break;
                    case 2:

                        dScale = 1.4;
                        break;
                    case 1:

                        dScale = 1.2;
                        break;
                    case 0:

                        dScale = 1;
                        break;
                    case -1:

                        dScale = 0.9;
                        break;
                    case -2:

                        dScale = 0.8;
                        break;
                    case -3:

                        dScale = 0.7;
                        break;
                    case -4:

                        dScale = 0.6;
                        break;
                    case -5:

                        dScale = 0.5;
                        break;
                }

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.GetScale()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

            return dScale;

        }

        // GetControl()
        //       - Get Control from the panel
        // Return Value
        //       - udcCtrlBase : Control which named skey
        // Arguments
        //        - ByVal sKey As String : Name of the control to get
        //
        public static udcCtrlBase GetControl(Control.ControlCollection CtrlCollection, string sKey, Enums.eToolType ToolType)
        {

            try
            {
                Control ctrl = null;
                foreach (Control tempLoopVar_ctrl in CtrlCollection)
                {
                    ctrl = tempLoopVar_ctrl;
                    if (ctrl is udcCtrlBase)
                    {
                        if (((udcCtrlBase)ctrl).Name == sKey && ((udcCtrlBase)ctrl).CtrlStatus.ToolType == ToolType)
                        {
                            return ((udcCtrlBase)ctrl);
                        }
                    }
                }

                return null;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("frmFMBDesign.GetControl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return null;
            }

        }

        public static udcCtrlBase GetControl(Control.ControlCollection CtrlCollection, string sKey, string sSubKey, Enums.eToolType ToolType)
        {

            try
            {
                Control ctrl = null;
                foreach (Control tempLoopVar_ctrl in CtrlCollection)
                {
                    ctrl = tempLoopVar_ctrl;
                    if (ctrl is udcCtrlBase)
                    {
                        if (((udcCtrlBase)ctrl).Name == sKey && ((udcCtrlBase)ctrl).CtrlStatus.MotherResourceID == sSubKey && ((udcCtrlBase)ctrl).CtrlStatus.ToolType == ToolType)
                        {
                            return ((udcCtrlBase)ctrl);
                        }
                    }
                }

                return null;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("frmFMBDesign.GetControl()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return null;
            }

        }


         // CheckGRPCMFValue()
        //       - Check Group/Cmf Value
        // Return Value
        //       -
        // Arguments
        //       - ByVal sLabelName As String    : Label Control Name
        //       - ByVal sCodeViewName As String : CodeView Control Name
        //       - ByVal parentControl As Control : Parent Control
        //
        public static bool CheckGRPCMFValue(string sLabelName, string sCodeViewName, Control parentControl)
        {
            ArrayList lblList;
            ArrayList cdvList;
            Label lblTemp;
            Miracom.UI.Controls.MCCodeView.MCCodeView cdvTemp;
            int i;

            try
            {
                lblList = GetIndexedControl(sLabelName, parentControl);
                cdvList = GetIndexedControl(sCodeViewName, parentControl);

                for (i = 0; i <= lblList.Count - 1; i++)
                {
                    lblTemp = (Label)lblList[i];

                    if (lblTemp.Text != "" && lblTemp.Font.Bold == true)
                    {
                        cdvTemp = (Miracom.UI.Controls.MCCodeView.MCCodeView)cdvList[i];
                        if (cdvTemp.Tag.ToString() == "A")
                        {
                            if (cdvTemp.Text == "")
                            {
                               MPCF.ShowMsgBox(MPCF.GetMessage(36) + " [" + lblTemp.Text + "]", Application.ProductName, MessageBoxButtons.OK, 1);
                                return false;
                            }
                        }
                        else
                        {
                            if (MPCF.CheckNumeric(cdvTemp.Text) == false)
                            {
                               MPCF.ShowMsgBox(MPCF.GetMessage(14) + " [" + lblTemp.Text + "]", Application.ProductName, MessageBoxButtons.OK, 1);
                                return false;
                            }
                        }
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.CheckGRPCMFValue()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

       
        // SetCMFItem()
        //       - Setting Cmf Control Property
        // Return Value
        //       -
        // Arguments
        //       - ByVal sItemName As String             : Group Item Name
        //       - ByVal sLabelName As String            : Label Control Prefix Name
        //        - ByVal sCodeViewName As String            : CodeView Control Prefix Name
        //        - ByVal parentControl As Control        : ParentControl
        //
        // ProcGRPCMFButtonPress()
        //       - Process Group/Cmf CodeView Button Press Event
        // Return Value
        //       -
        // Arguments
        //       - ByVal sender As Object    : Occur ButtonPress Event CodeView
        //
        public static void ProcGRPCMFButtonPress(Miracom.UI.Controls.MCCodeView.MCCodeView sender)
        {

            try
            {
                Miracom.UI.Controls.MCCodeView.MCCodeView cdvTemp;
                string sTableName;

                cdvTemp = (Miracom.UI.Controls.MCCodeView.MCCodeView)sender;
                if (System.Convert.ToString(cdvTemp.Tag) != "")
                {
                    sTableName = System.Convert.ToString(cdvTemp.Tag);
                    sTableName = sTableName.Substring(1, sTableName.Length - 1);
                    BASLIST.ViewGCMDataList(cdvTemp.GetListView, '2', sTableName, -1,null, MPGV.gsFactory);
                }

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.ProcGRPCMFButtonPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        // CheckCMFKeyPress()
        //       - Check Cmf CodeView Key Press Event
        // Return Value
        //       -
        // Arguments
        //       - ByVal sender As Object    : Occur KeyPress Event CodeView
        //       - ByVal e As System.Windows.Forms.KeyPressEventArgs : KeyPress Event Argument
        public static void CheckCMFKeyPress(Miracom.UI.Controls.MCCodeView.MCCodeView sender, System.Windows.Forms.KeyPressEventArgs e)
        {

            try
            {
                Miracom.UI.Controls.MCCodeView.MCCodeView cdvTemp;
                string sFormat;

                cdvTemp = (Miracom.UI.Controls.MCCodeView.MCCodeView)sender;

                if (System.Convert.ToString(cdvTemp.Tag) != "")
                {
                    sFormat = System.Convert.ToString(cdvTemp.Tag);
                    sFormat = sFormat.Substring(0, 1);
                    if (sFormat == "N" || sFormat == "F")
                    {
                        if (e.KeyChar < (char)48 || e.KeyChar > (char)57)
                        {
                            if (!(e.KeyChar == (char)43 || e.KeyChar == (char)45 || e.KeyChar == (char)8))
                            {
                                if (sFormat == "F")
                                {
                                    if (!(e.KeyChar == (char)46))
                                    {
                                        e.Handled = true;
                                    }
                                }
                                else
                                {
                                    e.Handled = true;
                                }
                            }
                        }
                    }
                }

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.CheckCMFKeyPress()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        // InitGRPCMFControl()
        //       - initial Group/Cmf Control
        // Return Value
        //       -
        // Arguments
        //       - ByVal sLabelName As String            : Label Control Prefix Name
        //        - ByVal sCodeViewName As String            : CodeView Control Prefix Name
        //        - ByVal parentControl As Control        : ParentControl
        public static void InitGRPCMFControl(string sLabelName, string sCodeViewName, Control parentControl)
        {

            try
            {
                ArrayList controls;
                Miracom.UI.Controls.MCCodeView.MCCodeView cdvTemp;
                int i;

                controls = GetIndexedControl(sLabelName, parentControl);
                for (i = 0; i <= controls.Count - 1; i++)
                {
                    ((Label)controls[i]).Visible = false;
                    ((Label)controls[i]).Text = "";
                }

                controls = GetIndexedControl(sCodeViewName, parentControl);
                for (i = 0; i <= controls.Count - 1; i++)
                {
                    cdvTemp = (Miracom.UI.Controls.MCCodeView.MCCodeView)controls[i];
                    cdvTemp.Init();

                    cdvTemp.ReadOnly = true;
                    cdvTemp.VisibleButton = true;
                    cdvTemp.Visible = false;

                    MPCF.InitListView(cdvTemp.GetListView);
                    cdvTemp.Columns.Add("Value", 100, HorizontalAlignment.Left);
                    cdvTemp.Columns.Add("Desc", 200, HorizontalAlignment.Left);
                    cdvTemp.SelectedSubItemIndex = 0;
                }

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.InitGRPCMFControl()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        // DeleteResource()
        //       - Delete Resource
        // Return Value
        //       - Boolean : True / False
        // Arguments
        //       - ByVal sCategory As String        :  Category
        //       - ByVal sFactory As String         :  Factory
        //       - ByVal sLayout As String          :  Layout or Group
        //       - ByVal sResource As String        :  Resource
        //       - ByVal sType As String            :  Resource or Tag Type
        //
        public static bool DeleteResource(string sCategory, string sFactory, string sLayout, string sResource, char sType)
        {

            try
            {
                TRSNode in_node = new TRSNode("Update_ResLoc_In");
                TRSNode out_node = new TRSNode("Cmn_Out");

                MPCR.SetInMsg(in_node);
                
                if (sCategory == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {
                    in_node.Factory = sFactory;
                    in_node.ProcStep = modGlobalConstant.MP_STEP_DELETE;
                    in_node.AddChar("RES_TYPE", sType);
                    in_node.AddString("LAYOUT_ID", sLayout);

                    if (sType == 'L')
                    {
                        in_node.AddString("TOOL_ID", sResource);
                    }
                    else
                    {
                        in_node.AddString("RES_ID", sResource);
                    }

                    if (MPCR.CallService("FMB", "FMB_Update_Resource_Location", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                }
                else if (sCategory == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    in_node.ProcStep = modGlobalConstant.MP_STEP_DELETE;
                    in_node.AddChar("RES_TYPE", sType);
                    in_node.AddString("GROUP_ID", sLayout);

                    if (sType == 'L')
                    {
                        in_node.AddString("TOOL_ID", sResource);
                    }
                    else
                    {
                        in_node.AddString("RES_ID", sResource);
                    }
                    if (MPCR.CallService("FMB", "FMB_Update_UDR_ResLoc", in_node, ref out_node) == false)
                    {
                        return false;
                    }

                }

                return true;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.DeleteResource()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }
         public static bool DeleteSubResource(string sCategory, string sFactory, string sLayout, string sResource, string sSubResource, char sType)
        {

            try
            {
                TRSNode in_node = new TRSNode("UPDATE_RESLOC_IN");
                TRSNode out_node = new TRSNode("CMN_OUT");

                MPCR.SetInMsg(in_node);
                if (sCategory == modGlobalConstant.FMB_CATEGORY_LAYOUT)
                {                  
                    in_node.Factory = sFactory;
                    in_node.ProcStep = modGlobalConstant.MP_STEP_DELETE;
                    in_node.AddString("RES_ID", sResource);
                    in_node.AddChar("RES_TYPE", sType);
                    in_node.AddString("LAYOUT_ID", sLayout);


                    if (sType == 'S')
                    {
                        in_node.AddString("SUBRES_ID", sSubResource);
                    }
                    else if (sType == 'P')
                    {
                        in_node.AddString("PORT_ID", sSubResource);
                    }

                    if (MPCR.CallService("FMB", "FMB_Update_Resource_Location", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                }
                else if (sCategory == modGlobalConstant.FMB_CATEGORY_GROUP)
                {
                    in_node.Factory = MPGV.gsFactory;
                    in_node.ProcStep = modGlobalConstant.MP_STEP_DELETE;
                    in_node.AddString("GROUP_ID", sLayout);
                    in_node.AddString("RES_ID", sResource);
                    in_node.AddChar("RES_TYPE", sType);
                    
                    if (sType == 'S')
                    {
                        in_node.AddString("SUBRES_ID", sSubResource);
                    }
                    else if (sType == 'P')
                    {
                        in_node.AddString("PORT_ID", sSubResource);
                    }

                    if (MPCR.CallService("FMB", "FMB_Update_UDR_ResLoc", in_node, ref out_node) == false)
                    {
                        return false;
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("FMBCF.DeleteResource()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return false;
            }

        }


        public static TreeNode FindTreeNode(TreeView trvCtrl, TreeNode nodeParent, string sSubKey, string sKey, bool bSubTreeSearch)
        {

            try
            {
                //int i = 0;
                TreeNode nodeCurrent = null;
                TreeNode nodeFinded = null;
                if (nodeParent == null)
                {
                    foreach (TreeNode tempLoopVar_nodeCurrent in trvCtrl.Nodes)
                    {
                        nodeCurrent = tempLoopVar_nodeCurrent;
                        if (((clsDesignListTag)nodeCurrent.Tag).SubKey == sSubKey)
                        {
                            if (((clsDesignListTag)nodeCurrent.Tag).Key == sKey)
                            {
                                return nodeCurrent;
                            }
                        }
                        else
                        {
                            if (bSubTreeSearch == true)
                            {
                                nodeFinded = FindTreeNode(trvCtrl, nodeCurrent, sKey, sSubKey, true);
                                if (!(nodeFinded == null))
                                {
                                    return nodeFinded;
                                }
                            }
                        }
                    }
                }
                else
                {
                    foreach (TreeNode tempLoopVar_nodeCurrent in nodeParent.Nodes)
                    {
                        nodeCurrent = tempLoopVar_nodeCurrent;
                        if (((clsDesignListTag)nodeCurrent.Tag).SubKey == sSubKey)
                        {
                            if (((clsDesignListTag)nodeCurrent.Tag).Key == sKey)
                            {
                                return nodeCurrent;
                            }
                        }
                        else
                        {
                            if (bSubTreeSearch == true)
                            {
                                nodeFinded = FindTreeNode(trvCtrl, nodeCurrent, sKey, sSubKey, true);
                                if (!(nodeFinded == null))
                                {
                                    return nodeFinded;
                                }
                            }
                        }
                    }
                }

                return null;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox("modCommonFunction.FindTreeNode()" + "\r\n" + ex.Message, "FMB Client", MessageBoxButtons.OK, 1);
                return null;
            }

        }
        // FindTreeNode()
        //       - Find Tree Node
        // Return Value
        //       - TreeNode
        // Arguments
        //       - ByRef trvCtrl As TreeView : TreeView
        //       - ByRef nodeParent As TreeNode : Parent Node
        //       - ByVal sKey As String : Key to Find
        //
        public static TreeNode FindTreeNode(TreeView trvCtrl, TreeNode nodeParent, string sKey, bool bSubTreeSearch)
        {

            try
            {
                //int i = 0;
                TreeNode nodeCurrent = null;
                TreeNode nodeFinded = null;
                if (nodeParent == null)
                {
                    foreach (TreeNode tempLoopVar_nodeCurrent in trvCtrl.Nodes)
                    {
                        nodeCurrent = tempLoopVar_nodeCurrent;
                        if (((clsDesignListTag)nodeCurrent.Tag).Key == sKey)
                        {
                            return nodeCurrent;
                        }
                        else
                        {
                            if (bSubTreeSearch == true)
                            {
                                nodeFinded = FindTreeNode(trvCtrl, nodeCurrent, sKey, true);
                                if (!(nodeFinded == null))
                                {
                                    return nodeFinded;
                                }
                            }
                        }
                    }
                }
                else
                {
                    foreach (TreeNode tempLoopVar_nodeCurrent in nodeParent.Nodes)
                    {
                        nodeCurrent = tempLoopVar_nodeCurrent;
                        if (((clsDesignListTag)nodeCurrent.Tag).Key == sKey)
                        {
                            return nodeCurrent;
                        }
                        else
                        {
                            if (bSubTreeSearch == true)
                            {
                                nodeFinded = FindTreeNode(trvCtrl, nodeCurrent, sKey, true);
                                if (!(nodeFinded == null))
                                {
                                    return nodeFinded;
                                }
                            }
                        }
                    }
                }

                return null;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.FindTreeNode()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return null;
            }

        }

        // GetFactoryNode()
        //       - Get Factory Tree Node
        // Return Value
        //       - TreeNode
        // Arguments
        //       - ByRef trvParent As TreeView : TreeView
        //       - ByVal sFactory As String : Factory to Find
        //
        public static TreeNode GetFactoryNode(ref TreeView trvParent, string sFactory)
        {

            try
            {
                int i = 0;
                for (i = 0; i <= trvParent.GetNodeCount(false) - 1; i++)
                {
                    if (((clsDesignListTag)trvParent.Nodes[i].Tag).Key == sFactory)
                    {
                        return trvParent.Nodes[i];
                    }
                }

                return null;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.GetFactoryNode()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return null;
            }

        }

        // SetStatusMsg()
        //       - Set Statusbar Message
        // Return Value
        //       -
        // Arguments
        //       - ByVal msg As String : Message
        //
        public static void SetStatusMsg(string msg)
        {

            try
            {
                if (MPGV.gfrmMDI != null)
                {
                    FMBFI.gIMdiForm.SetStatusMessage(msg);
                }

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.SetStatusMsg()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

        // ToAsc()
        //       - String to Ascii
        // Return Value
        //       - String
        // Arguments
        //       - ByVal sText As String
        //
        public static string ToAsc(string sText)
        {

            try
            {
                string sOutputText = "";
                int i;
                for (i = 0; i <= sText.Length - 1; i++)
                {
                    sOutputText += sText[i].ToString();
                    if (i < sText.Length - 1)
                    {
                        sOutputText += "|";
                    }
                }

                return sOutputText;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("frmFMBDesign.ToAsc()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return null;
            }

        }

        // ToChar()
        //       - String to Character
        // Return Value
        //       - String
        // Arguments
        //       - ByVal sText As String
        //
        public static string ToChar(string sText)
        {

            try
            {
                string[] sTextArray;
                sTextArray = sText.Split('|');
                string sOutputText = "";
                int i = 0;
                for (i = 0; i <= sTextArray.Length - 1; i++)
                {
                    sOutputText += sTextArray[i];
                }

                return sOutputText;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("frmFMBDesign.ToChar()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return null;
            }

        }

        // GetTextboxStyle()
        //       - Set Textbox Style
        // Return Value
        //       - Boolean : True of False
        // Arguments
        //       - ByRef colControl As System.Windows.Forms.Control.ControlCollection
        //
        public static bool GetTextboxStyle(System.Windows.Forms.Control.ControlCollection colControl)
        {

            try
            {
                Control l_Control;

                l_Control = null;

                foreach (Control tempLoopVar_l_Control in colControl)
                {
                    l_Control = tempLoopVar_l_Control;
                    if (l_Control is Panel)
                    {
                        GetTextboxStyle(l_Control.Controls);
                    }
                    else if (l_Control is GroupBox)
                    {
                        GetTextboxStyle(l_Control.Controls);
                    }
                    else if (l_Control is TabControl)
                    {
                        GetTextboxStyle(l_Control.Controls);
                    }
                    else if (l_Control is TextBox)
                    {
                        if (MPGV.gsStyleName == "FLAT")
                        {
                            ((TextBox)l_Control).BorderStyle = BorderStyle.FixedSingle;
                        }
                        else
                        {
                            ((TextBox)l_Control).BorderStyle = BorderStyle.Fixed3D;
                        }
                    }
                    else if (l_Control is UltraTextEditor)
                    {
                        if (MPGV.gsStyleName == "FLAT")
                        {
                            ((UltraTextEditor)l_Control).UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
                        }
                        else
                        {
                            ((UltraTextEditor)l_Control).UseFlatMode = Infragistics.Win.DefaultableBoolean.False;
                        }
                    }
                    else if (l_Control is Miracom.UI.Controls.MCCodeView.MCCodeView)
                    {
                        if (MPGV.gsStyleName == "FLAT")
                        {
                            ((Miracom.UI.Controls.MCCodeView.MCCodeView)l_Control).StyleBorder = BorderStyle.FixedSingle;
                        }
                        else
                        {
                            ((Miracom.UI.Controls.MCCodeView.MCCodeView)l_Control).StyleBorder = BorderStyle.Fixed3D;
                        }
                    }
                    else if (l_Control is UltraCheckEditor)
                    {
                        if (MPGV.gsStyleName == "FLAT")
                        {
                            ((UltraCheckEditor)l_Control).UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
                        }
                        else
                        {
                            ((UltraCheckEditor)l_Control).UseFlatMode = Infragistics.Win.DefaultableBoolean.False;
                        }
                    }
                    else if (l_Control is UltraComboEditor)
                    {
                        if (MPGV.gsStyleName == "FLAT")
                        {
                            ((UltraComboEditor)l_Control).UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
                        }
                        else
                        {
                            ((UltraComboEditor)l_Control).UseFlatMode = Infragistics.Win.DefaultableBoolean.False;
                        }
                    }
                    else if (l_Control is UltraColorPicker)
                    {
                        if (MPGV.gsStyleName == "FLAT")
                        {
                            ((UltraColorPicker)l_Control).UseFlatMode = Infragistics.Win.DefaultableBoolean.True;
                        }
                        else
                        {
                            ((UltraColorPicker)l_Control).UseFlatMode = Infragistics.Win.DefaultableBoolean.False;
                        }
                    }
                    else if (l_Control is FarPoint.Win.Spread.FpSpread)
                    {
                        if (MPGV.gsStyleName == "FLAT")
                        {
                            ((FarPoint.Win.Spread.FpSpread)l_Control).BorderStyle = BorderStyle.FixedSingle;
                        }
                        else
                        {
                            ((FarPoint.Win.Spread.FpSpread)l_Control).BorderStyle = BorderStyle.Fixed3D;
                        }
                    }
                }

                return true;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.GetTextboxStyle()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // Client_Upgrade()
        //       - Client Upgrade
        // Return Value
        //       - Integer : -1 - Occur error
        //                   0  - Server version same Client version
        //                   1  - Client Upgrade
        // Arguments
        //       -
        //
        //public static int Client_Upgrade(int iStep)
        //{

        //    BAS_Check_Version_In_Tag Check_Version_In = new BAS_Check_Version_In_Tag();
        //    BAS_Check_Version_Out_Tag Check_Version_Out = new BAS_Check_Version_Out_Tag();
        //    FileVersionInfo UpgradeExe;
        //    string UpgradeVersion;
        //    Ftp ftp = new Ftp();
            
        //    try
        //    {
        //        Check_Version_In._C.h_passport = MPGV.gsPassport;
        //        Check_Version_In._C.h_language = MPGV.gcLanguage;
        //        Check_Version_In._C.h_factory = MPGV.gsFactory;
        //        Check_Version_In._C.h_user_id = MPGV.gsUserID;
        //        Check_Version_In._C.h_password = MPGV.gsPassword;
        //        Check_Version_In._C.h_proc_step = '1';
        //        Check_Version_In._C.h_program_id = Application.ProductName;
                
        //        // Retern Value : -1 -> Occur error
        //        //                0  -> version same
        //        //                1  -> Client upgrade

        //        if (BASCaster.BAS_Check_Version(Check_Version_In, ref Check_Version_Out) == false)
        //        {
        //            MPCF.ShowMsgBox(h101stub.StatusMessage);
        //            return -1;
        //        }
            
        //        if (Check_Version_Out._C.h_status_value != modGlobalConstant.MP_SUCCESS_STATUS)
        //        {
        //           MPCF.ShowMsgBox(MPCF.MakeErrorMsg(Check_Version_Out._C.h_msg_code, Check_Version_Out._C.h_msg, Check_Version_Out._C.h_db_err_msg, Check_Version_Out._C.h_field_msg), Application.ProductName, MessageBoxButtons.OK, 1);
        //            return - 1;
        //        }
                
        //        MPGV.gsServerVersion = Check_Version_Out._C.server_version;
                
        //        // iStep = 1 : 버전 check 후 틀리면 업그레이드
        //        // iStep = 2 : 버전에 상관없이 업그레이드
        //        if (iStep == 1 && MPGV.gsServerVersion == MPGV.gsClientVersion)
        //        {
        //            return 0;
        //        }
        //        if (iStep == 1)
        //        {
        //            MPCF.ShowMsgBox(MPCF.GetMessage(38), Application.ProductName, MessageBoxButtons.OK, 1);
        //        }
        //        //'message를 사용하여 upgrade device connect_string notuse notuse
        //        //If (RTrim(Check_Version_Out.upgrade_address) = "" And _
        //        //    RTrim(Check_Version_Out.upgrade_directory) = "" And _
        //        //    RTrim(Check_Version_Out.upgrade_user_id) = "" And _
        //        //    RTrim(Check_Version_Out.upgrade_password) = "") Then
                
        //        //   MPCF.ShowMsgBox(GetMessage(36), , MessageBoxButtons.OK)
                
        //        //    Shell(Application.StartupPath & "\" & "BizmekaMESUpgradeMsg.exe" & " """ & _
        //        //        Trim(gsSiteID) & """ """ & Trim(gsRemoteAddress) & """ """ & """ """ & _
        //        //        """ """ & """ """ & "MESClient.exe" & """", vbNormalFocus)
        //        //Else
        //        //Ftp를 이용하여 upgrade address user password directory


        //        ftp.RemoteHost = Check_Version_Out._C.upgrade_address;
        //        ftp.RemoteUser = Check_Version_Out._C.upgrade_user_id;
        //        ftp.RemotePassword = Check_Version_Out._C.upgrade_password;
        //        ftp.RemotePath = Check_Version_Out._C.upgrade_directory;
        //        ftp.RemotePort = 21;
                
        //        if ((Microsoft.VisualBasic.FileSystem.Dir(Application.StartupPath + "\\" + MPGV.gsUpgradeFile, 0) != ""))
        //        {
        //            UpgradeExe = System.Diagnostics.FileVersionInfo.GetVersionInfo(Application.StartupPath + "\\" + MPGV.gsUpgradeFile);
        //            UpgradeVersion = UpgradeExe.FileVersion;
        //        }
        //        else
        //        {
        //            UpgradeVersion = "0.0.0.0";
        //        }
                
        //        if ((Microsoft.VisualBasic.FileSystem.Dir(Application.StartupPath + "\\" + MPGV.gsUpgradeFile + ".old", 0) != ""))
        //        {
        //            Microsoft.VisualBasic.FileSystem.Kill(Application.StartupPath + "\\" + MPGV.gsUpgradeFile + ".old");
        //        }
                
        //        if (UpgradeVersion == "0.0.0.0")
        //        {
        //            //Upgrade Program 을 FTP로 받는다
        //            if (ftp.DownloadFile(Application.StartupPath + "\\" + MPGV.gsUpgradeFile, MPGV.gsUpgradeFile) == false)
        //            {
        //                //Upgrade Program 갱신하지 못할 경우에 대한 에러처리
        //                return - 1;
        //            }
        //        }
        //        else if (UpgradeVersion != Check_Version_Out._C.upgrade_version)
        //        {
        //            Microsoft.VisualBasic.FileSystem.Rename(Application.StartupPath + "\\" + MPGV.gsUpgradeFile, Application.StartupPath + "\\" + MPGV.gsUpgradeFile + ".old");
        //            //Upgrade Program 을 FTP로 받는다
        //            if (ftp.DownloadFile(Application.StartupPath + "\\" + MPGV.gsUpgradeFile, MPGV.gsUpgradeFile) == false)
        //            {
        //                //Upgrade Program 갱신하지 못할 경우에 대한 에러처리
        //                return - 1;
        //            }
        //        }
                
        //        //Shell(Application.StartupPath & "\" & "MESplusUpgradeFtp.exe" & " """ & _
        //        //    Trim(Check_Version_Out._C.upgrade_address) & """ """ & Trim(Check_Version_Out._C.upgrade_user_id) & _
        //        //    """ """ & Trim(Check_Version_Out._C.upgrade_password) & """ """ & Trim(Check_Version_Out._C.upgrade_directory) & _
        //        //    """ """ & """ """ & "MESClient.exe" & """", vbNormalFocus)
                
        //        ProcessStartInfo StartInfo = new ProcessStartInfo();
        //        StartInfo.FileName = Application.StartupPath + "\\" + MPGV.gsUpgradeFile;
        //        StartInfo.Arguments = Check_Version_Out._C.upgrade_address + " " + Check_Version_Out._C.upgrade_user_id + " " + Check_Version_Out._C.upgrade_password + " " + Check_Version_Out._C.upgrade_directory + " " + MPGV.gsDownloadFileList;
                
        //        System.Diagnostics.Process.Start(StartInfo);
                
        //        //End If
                
        //    }
        //    catch (Exception ex)
        //    {
        //        MPCF.ShowMsgBox("FMBCF.Client_Upgrade()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
        //        return - 1;
        //    }
            
        //    return 1;
            
        //}

      
        public struct FuncCtrlList
        {
            public string ctrlName;
            public string ctrlValue;
        }

       // CheckValue()
        //       - Check space of the specific control
        // Return Value
        //       - Boolean : True of False
        // Arguments
        //       -
        //
        public static bool CheckValue(Control Form_control, int _Step, bool Not_Confirm_Flag, bool Not_Focus_Flag, string message, string Cond1, string Cond2)
        {
            bool returnValue;

            try
            {
                returnValue = false;

                if (message == "")
                {
                    if (_Step == 1)
                    {
                        message = MPCF.GetMessage(27);
                    }
                    else if (_Step == 2 || _Step == 3)
                    {
                        message = MPCF.GetMessage(29);
                    }
                }

                if ((Form_control is TextBox) || (Form_control is Label) || (Form_control is UltraTextEditor))
                {
                    if (_Step == 1)
                    {
                        if (Form_control.Text != "")
                        {
                            returnValue = true;
                        }
                    }
                    else if (_Step == 2)
                    {
                        if (MPCF.CheckNumeric(Form_control.Text) == true)
                        {
                            returnValue = true;
                        }
                    }
                    else if (_Step == 3)
                    {
                        if (MPCF.CheckNumeric(Form_control.Text) == true)
                        {
                            if (Form_control.Text.IndexOf(".", 0) < 0)
                            {
                                returnValue = true;
                            }
                        }
                    }
                }
                else if (Form_control is ComboBox)
                {
                    if (_Step == 1)
                    {
                        if (Form_control.Text != "")
                        {
                            returnValue = true;
                        }
                    }
                    else if (_Step == 2)
                    {
                        if (MPCF.CheckNumeric(Form_control.Text) == true)
                        {
                            returnValue = true;
                        }
                    }
                    else if (_Step == 3)
                    {
                        if (MPCF.CheckNumeric(Form_control.Text) == true)
                        {
                            if (Form_control.Text.IndexOf(".", 0) < 0)
                            {
                                returnValue = true;
                            }
                        }
                    }
                }
                else if (Form_control is Miracom.UI.Controls.MCCodeView.MCCodeView)
                {
                    if (_Step == 1)
                    {
                        if (MPCF.Trim(((Miracom.UI.Controls.MCCodeView.MCCodeView)Form_control).Text) != "")
                        {
                            returnValue = true;
                        }
                    }
                    else if (_Step == 2)
                    {
                        if (MPCF.CheckNumeric(((Miracom.UI.Controls.MCCodeView.MCCodeView)Form_control).Text) == true)
                        {
                            returnValue = true;
                        }
                    }
                    else if (_Step == 3)
                    {
                        if (MPCF.CheckNumeric(((Miracom.UI.Controls.MCCodeView.MCCodeView)Form_control).Text) == true)
                        {
                            if (((Miracom.UI.Controls.MCCodeView.MCCodeView)Form_control).Text.IndexOf(".", 0) < 0)
                            {
                                returnValue = true;
                            }
                        }
                    }
                }
                else if (Form_control is Infragistics.Win.UltraWinEditors.UltraNumericEditor)
                {
                    if (_Step == 1)
                    {
                        if (MPCF.Trim(((Infragistics.Win.UltraWinEditors.UltraNumericEditor)Form_control).Text) != "")
                        {
                            returnValue = true;
                        }
                    }
                    else if (_Step == 2)
                    {
                        if (MPCF.CheckNumeric(((Infragistics.Win.UltraWinEditors.UltraNumericEditor)Form_control).Text) == true)
                        {
                            returnValue = true;
                        }
                    }
                    else if (_Step == 3)
                    {
                        if (MPCF.CheckNumeric(((Infragistics.Win.UltraWinEditors.UltraNumericEditor)Form_control).Text) == true)
                        {
                            if (((Infragistics.Win.UltraWinEditors.UltraNumericEditor)Form_control).Text.IndexOf(".", 0) < 0)
                            {
                                returnValue = true;
                            }
                        }
                    }
                }

                if (returnValue == false)
                {
                    if (Not_Confirm_Flag == false)
                    {
                       MPCF.ShowMsgBox(message, Application.ProductName, MessageBoxButtons.OK, 1);
                        if (Not_Focus_Flag == false)
                        {
                            if (Form_control.Visible == true && Form_control.Enabled == true)
                            {
                                Form_control.Focus();
                            }
                        }
                    }
                    return returnValue;
                }

                return returnValue;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.CheckValue()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }
        }

        // CheckMaxLength()
        //       - check byte text length in TextBox
        // Return Value
        //       - boolean : True / False
        // Arguments
        //       - ByVal txt As Object            : TextBox Control
        //        - ByVal iMaxLength As Integer    : Max byte length
        //
        public static bool CheckMaxLength(object txt, int iMaxLength)
        {

            try
            {
                int iByteLen;
                string sText = "";

                if (iMaxLength <= 0)
                {
                    if (txt is System.Windows.Forms.TextBox)
                    {
                        iMaxLength = ((System.Windows.Forms.TextBox)txt).MaxLength;
                        sText = ((System.Windows.Forms.TextBox)txt).Text;
                    }
                }

                if (iMaxLength == 0)
                {
                    return false;
                }

                iByteLen = ByteLen(sText);
                if (iByteLen > iMaxLength)
                {
                    if (txt is System.Windows.Forms.TextBox)
                    {
                        ((System.Windows.Forms.TextBox)txt).Text = ByteMid(sText, 0, iMaxLength);
                        ((System.Windows.Forms.TextBox)txt).SelectionStart = sText.Length;
                    }

                    return false;
                }

                return true;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.CheckMaxLength()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // ByteLen()
        //       - Get byte length in String
        // Return Value
        //       - Integer : byte length
        // Arguments
        //       - ByVal sStr As String : String
        //
        public static int ByteLen(string sStr)
        {

            try
            {
               // System.Text.Encoding encoding;
                System.Text.Encoding twobyte;

                twobyte = System.Text.Encoding.GetEncoding(949);
                return twobyte.GetByteCount(sStr);

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.ByteLen()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return 0;
            }

        }

        // ByteMid()
        //       - Get Middle String at byte length in String
        // Return Value
        //       - String : Middle String
        // Arguments
        //       - ByVal sStr As String            : Source String
        //        - ByVal iStartIndex As Integer    : Start Index
        //        - ByVal iLength As Integer        : Middle String byte length
        //
        public static string ByteMid(string sStr, int iStartIndex, int iLength)
        {

            try
            {
               // System.Text.Encoding encoding;
                System.Text.Encoding twobyte;
                string sTemp;
                byte[] bTemp;

                twobyte = System.Text.Encoding.GetEncoding(949);

                sTemp = "";
                bTemp = twobyte.GetBytes(sStr);
                if (bTemp.Length < iStartIndex + iLength)
                {
                    iLength = bTemp.Length - iStartIndex;
                }

                sTemp = twobyte.GetString(bTemp, iStartIndex, iLength);

                return sTemp;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.ByteLen()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return "";
            }

        }

        // UpdateResourceLocation()
        //       - Create/Update/Delete Resource Location
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep as String  : Proc Step
        //       - ByVal sFactory As String
        //       - ByVal sLayoutID As String
        //       - ByVal sTagID As String
        //       - ByVal sResType As String
        //       - ByVal sText As String
        //       - ByVal iTagType As Integer
        //       - ByVal iTextSize As Integer
        //       - ByVal sTextStyle As String
        //       - ByVal iTextColor As Integer
        //       - ByVal iBackColor As Integer
        //       - ByVal iLocX As Integer
        //       - ByVal iLocY As Integer
        //       - ByVal iLocWidth As Integer
        //       - ByVal iLocHeight As Integer
        //       - ByVal sNoMouseEvent As String

        public static bool UpdateResourceLocation(char sStep, string sFactory, string sLayoutID, string sTagID, char sResType, string sText, int iTagType, int iTextSize, char sTextStyle, int iTextColor, int iBackColor, int iLocX, int iLocY, int iLocWidth, int iLocHeight, char sNoMouseEvent, char sSignalFlag)
        {

            try
            {
                TRSNode in_node = new TRSNode("Update_ResLoc_In");
                TRSNode out_node = new TRSNode("Cmn_Out");

                MPCR.SetInMsg(in_node);
                in_node.Factory = sFactory;
                in_node.ProcStep = sStep;
             
                in_node.AddString("RES_ID", sTagID);
                in_node.AddChar("RES_TYPE", sResType);
                in_node.AddString("TEXT", sText);
                in_node.AddInt("TAG_TYPE", iTagType);
                in_node.AddInt("TEXT_COLOR", iTextColor);
                in_node.AddInt("TEXT_SIZE", iTextSize);
                in_node.AddChar("TEXT_STYLE", sTextStyle);
                in_node.AddInt("BACK_COLOR", iBackColor);
                in_node.AddString("LAYOUT_ID", sLayoutID);
                in_node.AddInt("LOC_X", iLocX);
                in_node.AddInt("LOC_Y", iLocY);
                in_node.AddInt("LOC_WIDTH", iLocWidth);
                in_node.AddInt("LOC_HEIGHT", iLocHeight);
                in_node.AddChar("NO_MOUSE_EVENT", sNoMouseEvent);
                in_node.AddChar("SIGNAL_FLAG", sSignalFlag);

                if (MPCR.CallService("FMB", "FMB_Update_Resource_Location", in_node, ref out_node) == false)
                {
                    return false;
                }

                return true;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.UpdateResourceLocation()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // UpdateUDRResourceLocation()
        //       - Create/Update/Delete User Define Resource Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - sStep as String    : Proc Step
        //       - ByVal sFactory As String
        //       - ByVal sLayoutID As String
        //       - ByVal sTagID As String
        //       - ByVal sResType As String
        //       - ByVal sText As String
        //       - ByVal iTagType As Integer
        //       - ByVal iTextSize As Integer
        //       - ByVal sTextStyle As String
        //       - ByVal iTextColor As Integer
        //       - ByVal iBackColor As Integer
        //       - ByVal iLocX As Integer
        //       - ByVal iLocY As Integer
        //       - ByVal iLocWidth As Integer
        //       - ByVal iLocHeight As Integer
        //       - ByVal sNoMouseEvent As String

        public static bool UpdateUDRResourceLocation(char sStep, string sFactory, string sLayoutID, string sTagID, char sResType, string sText, int iTagType, int iTextSize, char sTextStyle, int iTextColor, int iBackColor, int iLocX, int iLocY, int iLocWidth, int iLocHeight, char sNoMouseEvent, char sSignalFlag)
        {

            try
            {
                TRSNode in_node = new TRSNode("Update_ResLoc_In");
                TRSNode out_node = new TRSNode("Cmn_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = sStep;
                in_node.AddString("GROUP_ID", sLayoutID);

                in_node.AddString("RES_ID", sTagID);
                in_node.AddChar("RES_TYPE", sResType);
                in_node.AddString("TEXT", sText);
                in_node.AddInt("TEXT_COLOR", iTextColor);
                in_node.AddInt("TAG_TYPE", iTagType);

                in_node.AddInt("TEXT_SIZE", iTextSize);
                in_node.AddChar("TEXT_STYLE", sTextStyle);

                in_node.AddInt("BACK_COLOR", iBackColor);
                in_node.AddInt("LOC_X", iLocX);
                in_node.AddInt("LOC_Y", iLocY);

                in_node.AddInt("LOC_WIDTH", iLocWidth);
                in_node.AddInt("LOC_HEIGHT", iLocHeight);
                in_node.AddChar("NO_MOUSE_EVENT", sNoMouseEvent);
                in_node.AddChar("SIGNAL_FLAG", sSignalFlag);

                if (MPCR.CallService("FMB", "FMB_Update_UDR_ResLoc", in_node, ref out_node) == false)
                {
                    return false;
                }

                return true;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.UpdateUDRResourceLocation()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // ViewLayOut()
        //       - View Layout Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - ByVal sFactory As String
        //       - ByVal sLayoutID As String
        //       - ByRef iWidth As Integer
        //       - ByRef iHeight As Integer
        //
        public static bool ViewLayOut(string sFactory, string sLayoutID, ref int iWidth, ref int iHeight)
        {

            try
            {
                TRSNode in_node = new TRSNode("View_LayOut_In");
                TRSNode out_node = new TRSNode("View_LayOut_Out");

                MPCR.SetInMsg(in_node);
                in_node.Factory = sFactory;
                in_node.ProcStep = '1';
                in_node.AddString("LAYOUT_ID", sLayoutID);

                if (MPCR.CallService("FMB", "FMB_View_LayOut", in_node, ref out_node) == false)
                {
                    return false;
                }

                iWidth = out_node.GetInt("WIDTH");
                iHeight = out_node.GetInt("HEIGHT");

                return true;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.ViewLayOut()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // ViewUDRGroup()
        //       - View User Define Resource Group Information
        // Return Value
        //       - Boolean : Return True/False
        // Arguments
        //       - ByVal sLayoutID As String
        //       - ByRef iWidth As Integer
        //       - ByRef iHeight As Integer
        //
        public static bool ViewUDRGroup(string sLayoutID, ref int iWidth, ref int iHeight)
        {

            try
            {
                TRSNode in_node = new TRSNode("View_UDR_Group_In");
                TRSNode out_node = new TRSNode("View_UDR_Group_Out");

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("GROUP_ID", sLayoutID);

                if (MPCR.CallService("FMB", "FMB_View_UDR_Group", in_node, ref out_node) == false)
                {
                    return false;
                }

                iWidth = out_node.GetInt("WIDTH");
                iHeight = out_node.GetInt("HEIGHT");

                return true;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.ViewUDRGroup()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // ConvertColorToString()
        //       - Convert Color to String
        // Return Value
        //       - String
        // Arguments
        //       - ByVal crSource As Color
        //
        public static string ConvertColorToString(Color crSource)
        {

            try
            {
                string sDest = "";

                sDest = "(";
                sDest += int.Parse(crSource.R.ToString()).ToString();
                sDest += ",";
                sDest += int.Parse(crSource.G.ToString()).ToString();
                sDest += ",";
                sDest += int.Parse(crSource.B.ToString()).ToString();
                sDest += ")";

                return sDest;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.ConvertColorToString()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return string.Empty;
            }

        }

        // ConvertStringToColor()
        //       - Convert String To Color
        // Return Value
        //       - Integer
        // Arguments
        //       - ByVal sSource As String
        //
        public static int ConvertStringToColor(string sSource)
        {

            try
            {
                int iDestColor;
                string sTemp = sSource;
                string[] arrSource;
                sTemp = sTemp.Substring(1, sTemp.Length - 2);
                arrSource = sTemp.Split(',');
                iDestColor = Color.FromArgb(255, MPCF.ToInt(arrSource[0]), MPCF.ToInt(arrSource[1]), MPCF.ToInt(arrSource[2])).ToArgb();

                return iDestColor;

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.ConvertStringToColor()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return Color.Empty.ToArgb();
            }

        }

        // ViewGlobalOption()
        //       - Set Global Options
        // Return Value
        //       - Boolean : True or False
        // Arguments
        //       - ByVal sFactory As String
        //
        public static bool ViewGlobalOption(string sFactory)
        {

            try
            {
                TRSNode in_node = new TRSNode("View_Environment_In");
                TRSNode out_node = new TRSNode("View_Environment_Out");
                Size cSize;

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.Factory = MPCF.RTrim(sFactory);

                if (MPCR.CallService("FMB", "FMB_View_Environment", in_node, ref out_node) == false)
                {
                    return false;
                }

                modGlobalVariable.gGlobalOptions.RemoveOptions(MPCF.RTrim(sFactory));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.Factory, out_node.GetString("FACTORY"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultFontName, out_node.GetString("FONT_FAMILY"));
                cSize = new Size(out_node.GetInt("LAYOUT_WIDTH"), out_node.GetInt("LAYOUT_HEIGHT"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultLayoutSize, cSize);
                cSize = new Size(out_node.GetInt("UDR_WIDTH"), out_node.GetInt("UDR_HEIGHT"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultUDRSize, cSize);
                cSize = new Size(out_node.GetInt("RES_WIDTH"), out_node.GetInt("RES_HEIGHT"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultResourceSize, cSize);
                cSize = new Size(out_node.GetInt("SUBRES_WIDTH"), out_node.GetInt("SUBRES_HEIGHT"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultSubResourceSize, cSize);
                cSize = new Size(out_node.GetInt("PORT_WIDTH"), out_node.GetInt("PORT_HEIGHT"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultPortSize, cSize);
                cSize = new Size(out_node.GetInt("TOOL_WIDTH"), out_node.GetInt("TOOL_HEIGHT"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultToolSize, cSize);
                
                cSize = new Size(out_node.GetInt("RTG_WIDTH"), out_node.GetInt("RTG_HEIGHT"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultRectangleSize, cSize);
                cSize = new Size(out_node.GetInt("ELP_WIDTH"), out_node.GetInt("ELP_HEIGHT"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultEllipseSize, cSize);
                cSize = new Size(out_node.GetInt("TRI_WIDTH"), out_node.GetInt("TRI_HEIGHT"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultTriangleSize, cSize);
                cSize = new Size(out_node.GetInt("VER_WIDTH"), out_node.GetInt("VER_HEIGHT"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultVerticalLineSize, cSize);
                cSize = new Size(out_node.GetInt("HOR_WIDTH"), out_node.GetInt("HOR_HEIGHT"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultHorizontalLineSize, cSize);
                cSize = new Size(out_node.GetInt("PIE1_WIDTH"), out_node.GetInt("PIE1_HEIGHT"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultPie1Size, cSize);
                cSize = new Size(out_node.GetInt("PIE2_WIDTH"), out_node.GetInt("PIE2_HEIGHT"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultPie2Size, cSize);
                cSize = new Size(out_node.GetInt("PIE3_WIDTH"), out_node.GetInt("PIE3_HEIGHT"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultPie3Size, cSize);
                cSize = new Size(out_node.GetInt("PIE4_WIDTH"), out_node.GetInt("PIE4_HEIGHT"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultPie4Size, cSize);
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.UseEventColor, out_node.GetChar("EVENT_COLOR_FLAG"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.IsProcessMode, out_node.GetChar("SIGNAL_FLAG"));
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.BackColorOpt, out_node.GetString("BACK_OPT").ToUpper());
                if (MPCF.RTrim(out_node.GetChar("EVENT_COLOR_FLAG")) == "Y")
                {
                    if (modListRoutine.ViewEventColorList('2', out_node.GetString("FACTORY")) == false)
                    {
                        return false;
                    }
                }
                if (out_node.GetInt("TEXT_COLOR") < 0)
                {
                    modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultTextColor, System.Drawing.Color.FromArgb(out_node.GetInt("TEXT_COLOR")));
                }
                else if (out_node.GetInt("TEXT_COLOR") > 0)
                {
                    modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultTextColor, System.Drawing.Color.FromKnownColor((KnownColor)out_node.GetInt("TEXT_COLOR")));
                }
                else
                {
                    modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultTextColor, SystemColors.Control);
                }
                if (out_node.GetInt("BACK_COLOR") < 0)
                {
                    modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultBackColor, System.Drawing.Color.FromArgb(out_node.GetInt("BACK_COLOR")));
                }
                else if (out_node.GetInt("BACK_COLOR") > 0)
                {
                    modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultBackColor, System.Drawing.Color.FromKnownColor((KnownColor)out_node.GetInt("BACK_COLOR")));
                }
                else
                {
                    modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultBackColor, SystemColors.Control);
                }
                modGlobalVariable.gGlobalOptions.AddOption(out_node.GetString("FACTORY"), clsOptionData.Options.DefaultTextSize, out_node.GetInt("TEXT_SIZE"));

                return true;
            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("FMBCF.ViewGlobalOption()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
                return false;
            }

        }

        // CheckAllFactoryOption()
        //       - Set All Factory Option
        // Return Value
        //       -
        // Arguments
        //       - ByRef ctrlFactory As Control
        //
        public static void CheckAllFactoryOption(Control ctrlFactory)
        {

            try
            {
                if (modGlobalVariable.gbAllFactory == false)
                {
                    if (ctrlFactory is Miracom.UI.Controls.MCCodeView.MCCodeView)
                    {
                        ((Miracom.UI.Controls.MCCodeView.MCCodeView)ctrlFactory).Text = MPGV.gsFactory;
                        ((Miracom.UI.Controls.MCCodeView.MCCodeView)ctrlFactory).VisibleButton = false;
                        ((Miracom.UI.Controls.MCCodeView.MCCodeView)ctrlFactory).ReadOnly = true;
                        ((Miracom.UI.Controls.MCCodeView.MCCodeView)ctrlFactory).BackColor = SystemColors.Control;
                    }
                    else if (ctrlFactory is UltraTextEditor)
                    {
                        ((UltraTextEditor)ctrlFactory).Text = MPGV.gsFactory;
                        ((UltraTextEditor)ctrlFactory).ReadOnly = true;
                    }
                }
                else
                {
                    if (ctrlFactory is Miracom.UI.Controls.MCCodeView.MCCodeView)
                    {
                        ((Miracom.UI.Controls.MCCodeView.MCCodeView)ctrlFactory).VisibleButton = true;
                        ((Miracom.UI.Controls.MCCodeView.MCCodeView)ctrlFactory).ReadOnly = false;
                        ((Miracom.UI.Controls.MCCodeView.MCCodeView)ctrlFactory).BackColor = SystemColors.Window;
                    }
                    else if (ctrlFactory is UltraTextEditor)
                    {
                        ((UltraTextEditor)ctrlFactory).ReadOnly = false;
                    }
                }

            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("frmFMBCreateLayOut.AllFactory()" + "\r\n" + ex.Message, Application.ProductName, MessageBoxButtons.OK, 1);
            }

        }

       // ChangeStringToDate()
        //       -   Change 14 byte DateTime format of DateTimePicker
        // Return Value
        //       - String : 14 byte DateTime
        // Arguments
        //       - ByVal dtpTime As DateTimePicker
        public static DateTime ToDate(string str)
        {
            try
            {
                string sTime = str.Trim();
                DateTime DTime;

                int year;
                int month;
                int day;
                int hour;
                int minute;
                int second;

                year = 0;
                month = 0;
                day = 0;
                hour = 0;
                minute = 0;
                second = 0;

                if (MPCF.CheckNumeric(sTime) == true)
                {
                    if (sTime.Length >= 8)
                    {
                        year = MPCF.ToInt(sTime.Substring(0, 4));
                        month = MPCF.ToInt(sTime.Substring(4, 2));
                        day = MPCF.ToInt(sTime.Substring(6, 2));
                    }
                    if (sTime.Length >= 14)
                    {
                        hour = MPCF.ToInt(sTime.Substring(8, 2));
                        minute = MPCF.ToInt(sTime.Substring(10, 2));
                        second = MPCF.ToInt(sTime.Substring(12, 2));
                    }

                    DTime = new DateTime(year, month, day, hour, minute, second);
                }
                else
                {
                    DTime = DateTime.Now;
                }
                
                return DTime;


            }
            catch (Exception ex)
            {
               MPCF.ShowMsgBox("MPCF.ToDate()\n" + ex.Message);
                return DateTime.Now;
            }
        }

        // ToDate()
        //       -   Change 14 byte DateTime format of DateTimePicker
        // Return Value
        //       - String : 14 byte DateTime
        // Arguments
        //       - ByVal dtpTime As DateTimePicker
        public static string ToDate(DateTimePicker dtpTime)
        {
            string sDateTime = "";
            DateTime DTime;

            DTime = dtpTime.Value;

            if (MPGV.gShiftInfor.bVariableShift == false)
            {
                if (MPGV.gShiftInfor.cShift1DayFlag == 'T')
                {
                    DTime = DTime.AddDays(+1);
                }
            }
            else
            {
                DTime = DTime.AddDays(+1);
            }
            sDateTime = DTime.ToString("yyyyMMdd");
            sDateTime = sDateTime + MPGV.gShiftInfor.sShift1StartTime;

            return sDateTime;
        }
    }

}
