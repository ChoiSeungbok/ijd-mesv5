
#ifndef _SPCCORE_COMMON_H
#define _SPCCORE_COMMON_H

/*
** MESplus include files
*/

#include <MESCore_common.h>
#include "SPCCore_defines.h"

#include <WIPCore_common.h>
#include <RASCore_common.h>
#include <EDCCore_common.h>

#ifdef _ALM
#include <ALMCore_common.h>
#endif /* _ALM */

#include <math.h>
#include <limits.h>
/* MESPlus SPC Module */

struct CHECK_RULE_TAG 
{
    double Check_Value[MP_SIZE_VALUE];
    int Value_Count;
    int Rule_Type;
    int UnitSeq;
    int Spec_Out_Count;
    char XR_Check_Flag;
    char Spec_Check_Type;
    char Insert_After_Flag;
    char GraphType[10];
    char TranTime[14];
    double UZone_A[MP_SIZE_VALUE];
    double UZone_B[MP_SIZE_VALUE];
    double UZone_C[MP_SIZE_VALUE];
    double LZone_A[MP_SIZE_VALUE];
    double LZone_B[MP_SIZE_VALUE];
    double LZone_C[MP_SIZE_VALUE];
    double UCL[MP_SIZE_VALUE];
    double CL[MP_SIZE_VALUE];
    double LCL[MP_SIZE_VALUE];
    double USL[MP_SIZE_VALUE];
    double TARGET[MP_SIZE_VALUE];
    double LSL[MP_SIZE_VALUE];
    char OOCType[MP_SIZE_VALUE];
    char OOCType2[MP_SIZE_VALUE];
    int Check_Index;
    char Sync_EDC_Flag;
};



extern int SPC_UPDATE_DATA(char *s_msg_code,
                           TRSNode *in_node, 
                           TRSNode *out_node);

extern int SPC_COLLECT_EDC_DATA(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);


extern int SPC_FIND_SPEC_VERSION(char *s_msg_code,
                                      TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_LOGIN(char *s_msg_code,
                         TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_UPDATE_CHART(char *s_msg_code,
                                TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_UPDATE_SPEC(char *s_msg_code,
                                TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_COLLECT_EDC_DATA(char *s_msg_code,
                                     TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_OOC_HISTORY(char *s_msg_code,
                              TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_AUTO_CALCULATION_CONTROL_LIMIT(char *s_msg_code,
                                                   TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_UPDATE_CHART_USER(char *s_msg_code,
                                      TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_EXCLUDE_EDC_DATA(char *s_msg_code,
                                     TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_ACK_ALARM(char *s_msg_code,
                       TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_CLEAR_ALARM(char *s_msg_code,
                       TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_UPDATE_CHART_SET(char *s_msg_code,
                              TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_ATTACH_CHART_SET(char *s_msg_code,
                              TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_EXCLUDE_EDC_DATA(char *s_msg_code,
                              TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_COLLECT_CHARTSET_DATA(char *s_msg_code,
                                   TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_UPDATE_PROMPT(char *s_msg_code,
                              TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_UPDATE_DEFAULT_UNIT_LIST(char *s_msg_code,
                                      TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_UPDATE_MFO_CHART(char *s_msg_code,
                               TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_UPDATE_MFO_CHART_LIST(char *s_msg_code,
                                   TRSNode *in_node, 
                                    TRSNode *out_node);


extern int SPC_VIEW_ALARM_HISTORY(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int SPC_VIEW_ATTACH_CHART_SET_LIST(char *s_msg_code,
                                          TRSNode *in_node, 
                                          TRSNode *out_node);

extern int SPC_VIEW_CHART_USER_LIST(char *s_msg_code,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_VIEW_CHART(char *s_msg_code,
                          TRSNode *in_node, 
                          TRSNode *out_node);

extern int SPC_VIEW_CHART_LIST(char *s_msg_code,
                               TRSNode *in_node, 
                               TRSNode *out_node);

extern int SPC_VIEW_CHART_LIST_DETAIL(char *s_msg_code,
                                      TRSNode *in_node, 
                                      TRSNode *out_node);

extern int SPC_VIEW_CHART_SET(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);

extern int SPC_VIEW_CHART_SET_LIST(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int SPC_VIEW_CONTROLCHART(char *s_msg_code,
                                 TRSNode *in_node, 
                                 TRSNode *out_node);

extern int SPC_VIEW_DEFAULT_UNIT_LIST(char *s_msg_code,
                                      TRSNode *in_node, 
                                      TRSNode *out_node);

extern int SPC_VIEW_EDC_DATA(char *s_msg_code,
                             TRSNode *in_node, 
                             TRSNode *out_node);

extern int SPC_VIEW_EDC_DATA_CHARTSET(char *s_msg_code,
                                      TRSNode *in_node, 
                                      TRSNode *out_node);

extern int SPC_VIEW_EXCLUDE_HISTORY(char *s_msg_code,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int SPC_VIEW_EXCLUDE_HISTORY_LIST(char *s_msg_code,
                                         TRSNode *in_node, 
                                         TRSNode *out_node);

extern int SPC_VIEW_MFO_CHART(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);

extern int SPC_VIEW_MFO_CHART_LIST(char *s_msg_code,
                                   TRSNode *in_node, 
                                   TRSNode *out_node);

extern int SPC_VIEW_OOC_HISTORY(char *s_msg_code,
                                TRSNode *in_node, 
                                TRSNode *out_node);

extern int SPC_VIEW_OOC_HISTORY_DETAIL(char *s_msg_code,
                                       TRSNode *in_node, 
                                       TRSNode *out_node);

extern int SPC_VIEW_PROCESS_CAPABILITY(char *s_msg_code,
                                       TRSNode *in_node, 
                                       TRSNode *out_node);

extern int SPC_VIEW_PROMPT(char *s_msg_code,
                           TRSNode *in_node, 
                           TRSNode *out_node);

extern int SPC_VIEW_RAW_DATA(char *s_msg_code,
                             TRSNode *in_node, 
                             TRSNode *out_node);

extern int SPC_VIEW_SPEC(char *s_msg_code,
                         TRSNode *in_node, 
                         TRSNode *out_node);

extern int SPC_VIEW_SPEC_HISTORY(char *s_msg_code,
                                 TRSNode *in_node, 
                                 TRSNode *out_node);

extern int SPC_VIEW_SPEC_LIST(char *s_msg_code,
                              TRSNode *in_node, 
                              TRSNode *out_node);



extern int Calculation_ControlLimit(char *s_msg_code,
                                    struct MSPCCHTDEF_TAG *MSPCCHTDEF,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern void Set_Rule_Description(char c_ruletype, char *s_rule_desc, struct MSPCRULEXT_TAG *MSPCRULEXT, char c_xr_flag);


extern int Data_Rule_Check(int i_step,
                    struct MSPCCHTDEF_TAG *MSPCCHTDEF,
                    char *s_msg_code,
                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int Rule_Violation_Action(char *s_msg_code,
                         TRSNode *in_node, 
                                    TRSNode *out_node);

extern void InitDbl(double *dValues, int iSize);

extern char Get_Rule_Type(int iRuleType);

extern void Check_Rule_by_Type(int iRuleIndex,
                        struct CHECK_RULE_TAG *Check_Rule, 
                        TRSNode *in_node, 
                                    TRSNode *out_node);

extern void SPC_Check_Rule(struct CHECK_RULE_TAG *CheckRule, 
                           TRSNode *in_node, 
                                    TRSNode *out_node);

extern void SPC_Zone_Calculation(struct CHECK_RULE_TAG *Check_Rule, int i_index);

extern int SPC_EDC_Data_Calculation(struct CHECK_RULE_TAG *Check_Rule,
                                    char *s_msg_code,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int Find_Spec_Information(char *s_msg_code, TRSNode *out_node, char *sBackTime, struct MSPCSPEHIS_TAG *MSPCSPEHIS);

#endif /* _SPCCORE_COMMON_H */

