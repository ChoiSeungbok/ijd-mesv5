
#ifndef _SPMCORE_COMMON_H
#define _SPMCORE_COMMON_H

/*
** MESplus include files
*/

#include <MESCore_common.h>

/*
** Constant Definitions
*/



/*
** Function Prototype Definitions
*/

/****************************************************************************************************************/
/*    SPM Common Function Prototypes                                                                            */
/****************************************************************************************************************/

extern int SPM_UPDATE_SPEC(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int SPM_UPDATE_SPEC_CHARACTER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int SPM_COPY_SPEC_VERSION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int SPM_VIEW_SPEC_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int SPM_VIEW_SPEC_VERSION(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int SPM_VIEW_SPEC_VERSION_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int SPM_VIEW_SPEC_CHARACTER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int SPM_VIEW_SPEC_CHARACTER_LIST(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int SPM_VIEW_SPEC_LIMIT(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int SPM_VIEW_SPEC_ATTACH_FILE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int SPM_COPY_SPEC_REL_VER(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int SPM_VIEW_SPEC_VALUE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);
extern int SPM_COMPARE_SPEC_VALUE(char *s_msg_code, TRSNode *in_node, TRSNode *out_node);

#endif /* _SPMCORE_COMMON_H */

