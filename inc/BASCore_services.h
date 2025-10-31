
#ifndef _BASCORE_SERVICES_H
#define _BASCORE_SERVICES_H

extern int BAS_Check_Version(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Copy_Table(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Delete_Calendar_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Attribute(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Attribute_Value(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Calendar_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Data_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Message(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Table(TRSNode *in_node,TRSNode *out_node);
extern int BAS_SQL_Query(TRSNode *in_node,TRSNode *out_node);
extern int BAS_SQL_Multi_Query(TRSNode *in_node,TRSNode *out_node);
extern int BAS_Update_BBS_Msg(TRSNode *in_node, TRSNode *out_node);

extern int BAS_View_Attribute(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Attribute_History(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Attribute_History_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Attribute_Name(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Attribute_Name_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Attribute_Value(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Attribute_Value_Brief(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Calendar(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Calendar_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Data(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Data_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Message_Group_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Message_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Message(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Table(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Table_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_BBS_Msg(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_BBS_Msg_List(TRSNode *in_node, TRSNode *out_node);

extern int BAS_Update_Global_Option(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Global_Option_Prompt(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Global_Option(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Global_Option_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Global_Option_Prompt(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Global_Option_Prompt_List(TRSNode *in_node, TRSNode *out_node);

/* Added by ICBAE 2011.01.13 */
extern int BAS_View_Screen_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Screen(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Screen_Info(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Check_Screen(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Inquiry_Screen_Relation_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Inquiry_Screen_Relation(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Inquiry_Screen_Relation(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Process_Flexible_Screen(TRSNode *in_node, TRSNode *out_node);

/* Added by dyOh 2011.02.21 */
extern int BAS_View_Flexible_Condition_List(TRSNode *in_node, TRSNode *out_node);
/* Added by dyOh 2011.02.23 */
extern int BAS_View_Query_Result_List(TRSNode *in_node, TRSNode *out_node);
//Add by J.S. 2011.09.19
extern int BAS_Update_Flexible_Condition(TRSNode *in_node, TRSNode *out_node);
//Add by J.S. 2012.04.17
extern int BAS_Upload_BBS_File(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Download_BBS_File(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_BBS_File_List(TRSNode *in_node, TRSNode *out_node);

/* Added by Patrick Choi 2012.04.10 */
extern int BAS_Update_Document_Design(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Document_Format(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Document_Template(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Document_Design(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Document_Design_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Document_Format(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Document_Format_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Document_Template(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Document_Template_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Check_DocTemp(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Check_Document(TRSNode *in_node, TRSNode *out_node);

#if defined(_DEBUG)
    //Add by J.S. 2011.09.19
extern int BAS_Tester(TRSNode *in_node, TRSNode *out_node);
#endif

/* Added by BS.KWAK 2012.04.19 */
extern int BAS_View_Tcard_Info(TRSNode *in_node, TRSNode *out_node);

// Add by ICBAE 2012.05.11
extern int BAS_View_Menu_Group(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Menu_Group_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Menu_Group(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Menu_Group_Relation(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Menu_List(TRSNode *in_node, TRSNode *out_node);

// Add by DM KIM 2012.05.14
extern int BAS_Check_Shift(TRSNode *in_node, TRSNode *out_node);

// Add by YG SON 2012.11.16 ~ MHIM 2013.02.15
extern int BAS_Update_Check_Query(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Checklist(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Checklist_Answer(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Checklist_Query(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Checklist_Relation(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Checklist_Answer(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Check_Query_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Check_Query(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Checklist_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Checklist(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Checklist_Query_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Checklist_Relation(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Checklist_Relation_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Checklist_History(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Checklist_Answer(TRSNode *in_node, TRSNode *out_node);

//Add by J.S. 2013.06.18
extern int BAS_Upgrade_Msg(TRSNode *in_node, TRSNode *out_node);

// Add by DM KIM 2013.08.20
extern int BAS_View_Batch_Job_Processor_List(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Batch_Job_Processor(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Batch_Job_Processor_Status(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Batch_Job_Processor_History(TRSNode *in_node, TRSNode *out_node);
extern int BAS_Update_Batch_Job_Processor(TRSNode *in_node, TRSNode *out_node);


extern int BAS_View_Table_History(TRSNode *in_node, TRSNode *out_node);
extern int BAS_View_Data_History(TRSNode *in_node, TRSNode *out_node);
#endif /* _BASCORE_SERVICES_H */
