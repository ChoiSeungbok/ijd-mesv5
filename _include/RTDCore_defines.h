#ifndef _RTDCORE_DEFINES_H
#define _RTDCORE_DEFINES_H

/* RTD Lot Rule */
#define MP_KEY_PRIORITY_LEVEL         ("PRIORITY_LEVEL      ")
#define MP_KEY_REWORK_CODE_MATCH      ("REWORK_CODE_MATCH   ")
#define MP_KEY_OWNER_CODE_MATCH       ("OWNER_CODE_MATCH    ")
#define MP_KEY_CREATE_CODE_MATCH      ("CREATE_CODE_MATCH   ")
#define MP_KEY_LOT_STATUS_MATCH       ("LOT_STATUS_MATCH    ")
#define MP_KEY_MOST_LOT_QUANTITY1     ("MOST_LOT_QUANTITY1  ")
#define MP_KEY_MOST_LOT_QUANTITY2     ("MOST_LOT_QUANTITY2  ")
#define MP_KEY_MOST_LOT_QUANTITY3     ("MOST_LOT_QUANTITY3  ")
#define MP_KEY_NSTD_LOT               ("NSTD_LOT            ")
#define MP_KEY_STARTED_LOT            ("STARTED_LOT         ")
#define MP_KEY_LONGEST_WAIT_TIME      ("LONGEST_WAIT_TIME   ")
#define MP_KEY_SHORTEST_DUE_TIME      ("SHORTEST_DUE_TIME   ")
#define MP_KEY_EARLIEST_START_TIME    ("EARLIEST_START_TIME ")
#define MP_KEY_SMALL_NEXT_OPER_WIP    ("SMALL_NEXT_OPER_WIP ")
#define MP_KEY_NEXT_RESOURCE_UP       ("NEXT_RESOURCE_UP    ")
#define MP_KEY_MATERIAL_MATCH         ("MATERIAL_MATCH      ")
#define MP_KEY_RECIPE_MATCH           ("RECIPE_MATCH        ")
#define MP_KEY_TOOL_MATCH             ("TOOL_MATCH          ")
#define MP_KEY_ORDER_MATCH            ("ORDER_MATCH         ")
#define MP_KEY_LOT_INFO_MATCH         ("LOT_INFO_MATCH      ")
#define MP_KEY_SCH_START_TIME         ("SCH_START_TIME      ")

#define MP_KEY_CRITICAL_RATIO         ("MIN_CRITICAL_RATIO  ")
#define MP_KEY_LAST_MATERIAL_MATCH    ("LAST_MATERIAL_MATCH ")
#define MP_KEY_LESS_WIP_FOLLOW_OPER   ("LESS_WIP_FOLLOW_OPER")
#define MP_KEY_LAST_RECIPE_MATCH      ("LAST_RECIPE_MATCH   ")

/* RTD Resource Rule */
#define MP_KEY_UP_DOWN_STATUS         ("UP_DOWN_STATUS      ")
#define MP_KEY_PRIMARY_STATUS         ("PRIMARY_STATUS      ")
#define MP_KEY_RES_TYPE_MATCH         ("RESOURCE_TYPE_MATCH ")
#define MP_KEY_LAST_EVENT_MATCH       ("LAST_EVENT_MATCH    ")
#define MP_KEY_RES_INFO_MATCH         ("RES_INFO_MATCH      ")

struct RTD_DSP_TARGET_TAG
{
    int dsp_list_count;
    struct
    {
        char res_id[20];
        char oper_id[10];
        char dsp_id[20];
        char reference_oper[10];
    } rtd_dsp_list[1000];    
} rtd_dsp_target;


struct RTD_CYCLE_TIME_CACHE_TAG
{
    char factory[10];
    char mat_id[30];
    int  mat_ver;
    char flow[20];
    int  flow_seq_num;
    char oper[10];
    char cache_time[14];
    int  cycle_time;
};

#define RTD_MAX_DISPATCH_BUFFER_COUNT 1000
struct RTD_LESS_WIP_CACHE_TAG
{
    char factory[10];
    char mat_id[30];
    int  mat_ver;
    char flow[20];
    int  flow_seq_num;
    char oper[10];
    char cache_time[14];
    int  oper_count;
    char rwk_flag;
    char rwk_ret_flow[20];
    int  rwk_ret_flow_seq_num;
    char nstd_flag;
    char nstd_ret_flow[20];
    int  nstd_ret_flow_seq_num;
    int  score;
};
struct LOTPDS_LIST_TAG LOTPDS_LIST_ARRAY[RTD_MAX_DISPATCH_BUFFER_COUNT];


struct PDS_CMF_TBL_TAG
{
    char pds_cmf_1[30];
    char pds_cmf_2[30];
    char pds_cmf_3[30];
    char pds_cmf_4[30];
    char pds_cmf_5[30];
    char pds_cmf_6[30];
    char pds_cmf_7[30];
    char pds_cmf_8[30];
    char pds_cmf_9[30];
    char pds_cmf_10[30];
};

#endif /* _RTDCORE_DEFINES_H */


