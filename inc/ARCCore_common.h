
#ifndef _ARCCORE_COMMON_H
#define _ARCCORE_COMMON_H

#include <MESCore_common.h>
#include <ADB_common.h>

/* Global Option GCM Table Name */
#define MP_DATABASE_LINK            ("ARCHIVE_DB_LINK     ")

#define MP_LINK_NAME                ("BACKUPDB            ")

/*Archive 소스 자료 삭제 여부*/
#define ARC_SOURCE_DELETE            ('D')
#define ARC_SOURCE_UNDELETE            ('U')

/*'Rollback segment 사용 여부*/
#define ARC_ROLLBACK_USE            ('R')
#define ARC_ROLLBACK_NOTUSE            ('N')

/*'Archive Backup Type*/
#define ARC_BACKUP_FILE             ('F')
#define ARC_BACKUP_DB               ('D')
#define ARC_BACKUP_FILE_DB          ('B')

extern int ARC_DEARCHIVE_TABLE(char *s_msg_code,
                        TRSNode *in_node,
                        TRSNode *out_node);

extern int ARC_INSERT_ARCHIVE_RUNNING_LIST(char *s_msg_code,
                                    TRSNode *in_node,
                                    TRSNode *out_node);

extern int ARC_UPDATE_ARCHIVE_OPT(char *s_msg_code,
                                  TRSNode *in_node, 
                                  TRSNode *out_node);

extern int ARC_UPDATE_ARCHIVE_TABLE(char *s_msg_code,
                                    TRSNode *in_node, 
                                    TRSNode *out_node);
/* Added By YJ Jung 2012.01.19 */
extern int ARC_View_Archive_Opt_Detail_Main(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int ARC_View_Archive_Opt_List_Main(char *s_msg_code, 
                                    TRSNode *in_node, 
                                    TRSNode *out_node);

extern int ARC_View_Archive_Table_Detail_Main(char *s_msg_code,
                                       TRSNode *in_node,
                                       TRSNode *out_node);

extern int ARC_View_Archive_Table_List_Main(char *s_msg_code,
                                     TRSNode *in_node,
                                     TRSNode *out_node);

extern int ARC_View_Column_List_Main(char *s_msg_code,
                             TRSNode *in_node,
                             TRSNode *out_node);

extern int ARC_View_Factory_List_Main(char *s_msg_code,
                               TRSNode *in_node,
                               TRSNode *out_node) ;

extern int ARC_View_Table_List_Main(char *s_msg_code,
                             TRSNode *in_node,
                             TRSNode *out_node);
/* End Added YJ Jung*/

#endif /* _ARCCORE_COMMON_H */
