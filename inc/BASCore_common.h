

#ifndef _BASCORE_COMMON_H
#define _BASCORE_COMMON_H


#include <MESCore_common.h>


extern int BAS_SQL_Query(TRSNode *Sql_In, 
                         TRSNode *Sql_Out);


extern int BAS_attribute_delete_history(char *s_msg_code, TRSNode *out_node,
                                        char *s_factory, char *s_user_id, char *s_comment,
                                        char *s_attr_type, int i_attr_type_size, 
                                        char *s_attr_key, int i_attr_key_size,
                                        int i_key_hist_seq);

extern int BAS_attribute_delete_status(char *s_msg_code, TRSNode *out_node,
                                 char *s_factory,
                                 char *s_attr_type, int i_attr_type_size, 
                                 char *s_attr_key, int i_attr_key_size);

extern int BAS_get_attribute_value(char *s_msg_code, TRSNode *out_node, 
                            char *s_factory_t, char *s_attr_type_t, char *s_attr_name_t, char *s_attr_key_t, int i_attr_key_size,
                            char *s_attr_value);
extern int BAS_set_attribute_value(char *s_msg_code, TRSNode *out_node, 
                            char *s_factory_t, char *s_attr_type_t, char *s_attr_name_t,
                            char *s_attr_key_t, int i_attr_key_size, char *s_attr_value_t, int i_attr_value_size);


extern int BAS_insert_gcm_table_history(char *s_msg_code, 
                                        char *s_sys_time,
                                        TRSNode *in_node, 
                                        TRSNode *out_node,
                                        struct MGCMTBLDEF_TAG MGCMTBLDEF);

extern int BAS_insert_gcm_data_history(char *s_msg_code, 
                                       char *s_sys_time,
                                       TRSNode *in_node, 
                                       TRSNode *data_node,
                                       TRSNode *out_node,
                                       char c_large_flag);


extern int BAS_CHECK_VERSION(char *s_msg_code,
                           TRSNode *In_node,
                           TRSNode *out_node);

extern int BAS_COPY_TABLE(char *s_msg_code,
                        TRSNode *In_node,
                        TRSNode *out_node);

extern int BAS_DELETE_CALENDAR_LIST(char *s_msg_code,
                                  TRSNode *In_node,
                                  TRSNode *out_node);

extern int BAS_SQL_MULTI_QUERY(char *s_msg_code,
                       TRSNode *Sql_In,
                       TRSNode *out_node);

extern int BAS_SQL_QUERY(char *s_msg_code,
                       TRSNode *Sql_In,
                       TRSNode *Sql_Out);

extern int BAS_UPDATE_ATTRIBUTE(char *s_msg_code,
                               TRSNode *In_node, 
                               TRSNode *out_node);

extern int BAS_UPDATE_ATTRIBUTE_VALUE(char *s_msg_code,
                               TRSNode *In_node, 
                               TRSNode *out_node);

extern int BAS_UPDATE_CALENDAR_LIST(char *s_msg_code,
                                  TRSNode *In_node,
                                  TRSNode *out_node);

extern int BAS_UPDATE_DATA_LIST(char *s_msg_code,
                              TRSNode *In_node,
                              TRSNode *out_node);

extern int BAS_UPDATE_MESSAGE(char *s_msg_code,
                               TRSNode *In_node, 
                               TRSNode *out_node);

extern int BAS_UPDATE_TABLE(char *s_msg_code,
                          TRSNode *In_node,
                          TRSNode *out_node);

extern int BAS_UPDATE_BBS_MSG(char *s_msg_code,
                               TRSNode *in_node, 
                               TRSNode *out_node);


extern int BAS_VIEW_ATTRIBUTE(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);

extern int BAS_VIEW_ATTRIBUTE_HISTORY(char *s_msg_code,
                                      TRSNode *in_node, 
                                      TRSNode *out_node);

extern int BAS_VIEW_ATTRIBUTE_HISTORY_LIST(char *s_msg_code,
                                           TRSNode *in_node, 
                                           TRSNode *out_node);

extern int BAS_VIEW_ATTRIBUTE_NAME(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int BAS_VIEW_ATTRIBUTE_NAME_LIST(char *s_msg_code,
                                        TRSNode *in_node, 
                                        TRSNode *out_node);

extern int BAS_VIEW_CALENDAR(char *s_msg_code,
                             TRSNode *in_node,
                             TRSNode *out_node);

extern int BAS_VIEW_CALENDAR_LIST(char *s_msg_code,
                                  TRSNode *in_node,
                                  TRSNode *out_node);

extern int BAS_VIEW_DATA(char *s_msg_code,
                         TRSNode *in_node,
                         TRSNode *out_node);

extern int BAS_VIEW_DATA_LIST(char *s_msg_code,
                              TRSNode *in_node,
                              TRSNode *out_node);

extern int BAS_VIEW_MESSAGE(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int BAS_VIEW_MESSAGE_GROUP_LIST(char *s_msg_code,
                                       TRSNode *in_node, 
                                       TRSNode *out_node);

extern int BAS_VIEW_MESSAGE_LIST(char *s_msg_code,
                                 TRSNode *in_node, 
                                 TRSNode *out_node);

extern int BAS_VIEW_TABLE(char *s_msg_code,
                          TRSNode *in_node,
                          TRSNode *out_node);

extern int BAS_VIEW_TABLE_LIST(char *s_msg_code,
                               TRSNode *in_node,
                               TRSNode *out_node);


extern int BAS_VIEW_BBS_MSG(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int BAS_VIEW_BBS_MSG_LIST(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);

extern int BAS_UPDATE_GLOBAL_OPTION(char *s_msg_code, 
                             TRSNode *in_node, 
                             TRSNode *out_node);

extern int BAS_UPDATE_GLOBAL_OPTION_PROMPT(char *s_msg_code, 
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int BAS_VIEW_GLOBAL_OPTION(char *s_msg_code,
                           TRSNode *in_node,
                           TRSNode *out_node);

extern int BAS_VIEW_GLOBAL_OPTION_LIST(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node);

extern int BAS_VIEW_GLOBAL_OPTION_PROMPT(char *s_msg_code,
                                  TRSNode *in_node,
                                  TRSNode *out_node);

extern int BAS_VIEW_GLOBAL_OPTION_PROMPT_LIST(char *s_msg_code,
                                       TRSNode *in_node,
                                       TRSNode *out_node);

extern int BAS_VIEW_ATTRIBUTE_VALUE_BRIEF(char *s_msg_code,
                             TRSNode *in_node, 
                             TRSNode *out_node);

extern int BAS_VIEW_ATTRIBUTE_VALUE(char *s_msg_code,
                             TRSNode *in_node, 
                             TRSNode *out_node);

/* Added by ICBAE 2011.01.13 */
extern int BAS_VIEW_SCREEN_LIST(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);

extern int BAS_UPDATE_SCREEN(char *s_msg_code,
                             TRSNode *in_node, 
                             TRSNode *out_node);

extern int BAS_VIEW_SCREEN_INFO(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);

extern int BAS_CHECK_SCREEN(char *s_msg_code,
                            TRSNode *in_node, 
                            TRSNode *out_node);

extern int BAS_VIEW_INQUIRY_SCREEN_RELATION_LIST(char *s_msg_code,
                                                 TRSNode *in_node, 
                                                 TRSNode *out_node);

extern int BAS_VIEW_INQUIRY_SCREEN_RELATION(char *s_msg_code,
                                            TRSNode *in_node,
                                            TRSNode *out_node);

extern int BAS_UPDATE_INQUIRY_SCREEN_RELATION(char *s_msg_code,
                                             TRSNode *in_node,
                                             TRSNode *out_node);

extern int BAS_PROCESS_FLEXIBLE_SCREEN(char *s_msg_code,
                                       TRSNode *in_node,
                                       TRSNode *out_node);

//Add by J.S. 2011.09.19
extern int BAS_UPDATE_FLEXIBLE_CONDITION(char *s_msg_code,
                                         TRSNode *in_node, 
                                         TRSNode *out_node);

extern int BAS_VIEW_FLEXIBLE_CONDITION_LIST(char *s_msg_code,
                                     TRSNode *in_node, 
                                     TRSNode *out_node);

extern int BAS_VIEW_QUERY_RESULT_LIST(char *s_msg_code,
                               TRSNode *in_node, 
                               TRSNode *out_node);

/* Added by Patrick Choi 2012.04.10 */
extern int BAS_UPDATE_DOCUMENT_DESIGN(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);
extern int BAS_UPDATE_DOCUMENT_FORMAT(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);
extern int BAS_UPDATE_DOCUMENT_TEMPLATE(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);
extern int BAS_VIEW_DOCUMENT_DESIGN(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);
extern int BAS_VIEW_DOCUMENT_DESIGN_LIST(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);
extern int BAS_VIEW_DOCUMENT_FORMAT(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);
extern int BAS_VIEW_DOCUMENT_FORMAT_LIST(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);
extern int BAS_VIEW_DOCUMENT_TEMPLATE(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);
extern int BAS_VIEW_DOCUMENT_TEMPLATE_LIST(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);
extern int BAS_CHECK_DOCTEMP(char *s_msg_code,
                           TRSNode *In_node,
                           TRSNode *out_node);
extern int BAS_CHECK_DOCUMENT(char *s_msg_code,
                           TRSNode *In_node,
                           TRSNode *out_node);
                                                 
//Add by J.S. 2012.04.17
extern int BAS_UPLOAD_BBS_FILE(char *s_msg_code,
                                 TRSNode *in_node,
                                 TRSNode *out_node);

extern int BAS_DOWNLOAD_BBS_FILE(char *s_msg_code,
                                 TRSNode *in_node,
                                 TRSNode *out_node);

extern int BAS_VIEW_BBS_FILE_LIST(char *s_msg_code,
                                 TRSNode *in_node,
                                 TRSNode *out_node);

extern int BAS_VIEW_TCARD_INFO(char *s_msg_code,
                                 TRSNode *in_node,
                                 TRSNode *out_node);

//Add by ICBAE 2012.05.11
extern int BAS_VIEW_MENU_GROUP(char *s_msg_code,
                               TRSNode *in_node,
                               TRSNode *out_node);
extern int BAS_VIEW_MENU_GROUP_LIST(char *s_msg_code,
                                    TRSNode *in_node,
                                    TRSNode *out_node);
extern int BAS_UPDATE_MENU_GROUP(char *s_msg_code,
                                 TRSNode *in_node,
                                 TRSNode *out_node);
extern int BAS_VIEW_MENU_GROUP_RELATION(char *s_msg_code,
                                        TRSNode *in_node,
                                        TRSNode *out_node);
extern int BAS_UPDATE_MENU_LIST(char *s_msg_code,
                                TRSNode *in_node,
                                TRSNode *out_node);
extern int BAS_VIEW_MENU_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

// Add by DM KIM 2012.05.14
extern int BAS_CHECK_SHIFT(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);

// Add by YG SON 2012.11.16 ~ MHIM 2013.02.15
extern int BAS_UPDATE_CHECK_QUERY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_UPDATE_CHECKLIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_UPDATE_CHECKLIST_ANSWER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_UPDATE_CHECKLIST_QUERY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_UPDATE_CHECKLIST_RELATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_VIEW_CHECK_QUERY(char *s_msg_code, TRSNode *in_node,  TRSNode *out_node);
extern int BAS_VIEW_CHECK_QUERY_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_VIEW_CHECKLIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_VIEW_CHECKLIST_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_VIEW_CHECKLIST_QUERY_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_VIEW_CHECKLIST_RELATION_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_VIEW_CHECKLIST_RELATION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_VIEW_CHECKLIST_HISTORY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_VIEW_CHECKLIST_ANSWER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

//Add by J.S. 2013.06.18
extern int BAS_UPGRADE_MSG(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

//Add by DM KIM 2013.08.20
extern int BAS_VIEW_BATCH_JOB_PROCESSOR_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_VIEW_BATCH_JOB_PROCESSOR(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_VIEW_BATCH_JOB_PROCESSOR_STATUS(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_VIEW_BATCH_JOB_PROCESSOR_HISTORY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_UPDATE_BATCH_JOB_PROCESSOR(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);


extern int BAS_VIEW_TABLE_HISTORY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int BAS_VIEW_DATA_HISTORY(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
#endif /* _BASCORE_COMMON_H */
                        

                         
