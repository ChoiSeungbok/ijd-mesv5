/*******************************************************************************

    System      : MESplus
    Module      : MESCore
    File Name   : MESCore_defines.h
    Description : Common Macro definition of MESplus Server

    MES Version : 4.0.0

    Function List
        - 

    Detail Description
        - 

    History
    Seq   Date        Developer      Description                        
    ---------------------------------------------------------------------------
    1     2004/12/16  SK Jin         Create

    Copyright(C) 1998-2004 Miracom,Inc.
    All rights reserved.

*******************************************************************************/

#ifndef _MESCORE_DEFINES_H
#define _MESCORE_DEFINES_H

#include <TRSCore_common.h>

/****************************************************/
/* System Constant                                  */
/****************************************************/

/* Central Factory */
#define CENTRAL_FACTORY           ("SYSTEM    ")
#define DEFAULT_ADMIN_FUNCTION    ("DEFAULT_ADMIN_FUNC")

/****************************************************/
/* Transaction 결과를 알리는 상수                   */
/****************************************************/

/****************************************************/
/* Transaction Code                                 */
/****************************************************/
#define MP_TRAN_CODE_CREATE       ("CREATE      ")
#define MP_TRAN_CODE_START        ("START       ")
#define MP_TRAN_CODE_END          ("END         ")
#define MP_TRAN_CODE_MOVE         ("MOVE        ")
#define MP_TRAN_CODE_SKIP         ("SKIP        ")
#define MP_TRAN_CODE_REWORK       ("REWORK      ")
#define MP_TRAN_CODE_REPAIR       ("REPAIR      ")
#define MP_TRAN_CODE_REPAIR_END   ("REPAIR_END  ")
#define MP_TRAN_CODE_LOCAL_REPAIR ("LOCAL_REPAIR")
#define MP_TRAN_CODE_LOSS         ("LOSS        ")
#define MP_TRAN_CODE_BONUS        ("BONUS       ")
#define MP_TRAN_CODE_SPLIT        ("SPLIT       ")
#define MP_TRAN_CODE_MERGE        ("MERGE       ")
#define MP_TRAN_CODE_COMBINE      ("COMBINE     ")
#define MP_TRAN_CODE_HOLD         ("HOLD        ")
#define MP_TRAN_CODE_RELEASE      ("RELEASE     ")
#define MP_TRAN_CODE_SHIP         ("SHIP        ")
#define MP_TRAN_CODE_TRANSFER     ("TRANSFER    ")
#define MP_TRAN_CODE_RECEIVE      ("RECEIVE     ")
#define MP_TRAN_CODE_ADAPT        ("ADAPT       ")
#define MP_TRAN_CODE_ATTRIBUTE    ("ATTRIBUTE   ")
#define MP_TRAN_CODE_LOTEDC       ("LOTEDC      ")
#define MP_TRAN_CODE_RESEDC       ("RESEDC      ")
#define MP_TRAN_CODE_CHANGE_CMF   ("CHANGE_CMF  ")
//Add by J.S. 2009.02.26
#define MP_TRAN_CODE_SCRIBE       ("SCRIBE      ")
#define MP_TRAN_CODE_TRANSIT      ("TRANSIT     ")
//Add by Aiden. 2010.02.22
#define MP_TRAN_CODE_REGENERATE   ("REGENERATE  ")

#define MP_TRAN_CODE_IN_INV       ("IN INV      ")
#define MP_TRAN_CODE_OUT_INV      ("OUT INV     ")
#define MP_TRAN_CODE_TRANSFER_INV ("TRANS INV   ")
#define MP_TRAN_CODE_CONV_TO_LOT  ("CONV TO LOT ")
#define MP_TRAN_CODE_CONV_TO_INV  ("CONV TO INV ")
#define MP_TRAN_CODE_CONSUME      ("CONSUME     ")
#define MP_TRAN_CODE_SCRAP        ("SCRAP       ")
#define MP_TRAN_CODE_REVERSE      ("REVERSE     ")

#define MP_TRAN_CODE_SORT         ("SORT        ")
#define MP_TRAN_CODE_STORE        ("STORE       ")
#define MP_TRAN_CODE_UNSTORE      ("UNSTORE     ")
#define MP_TRAN_CODE_TERMINATE    ("TERMINATE   ")
#define MP_TRAN_CODE_RESERVE      ("RESERVE     ")
#define MP_TRAN_CODE_UNRESERVE    ("UNRESERVE   ")
#define MP_TRAN_CODE_CV           ("CV          ")
#define MP_TRAN_CODE_GRADE        ("GRADE       ")
#define MP_TRAN_CODE_LOTBDC       ("LOTBDC      ")

#define MP_TRAN_CODE_RAISE_ALARM        ("RAISE ALARM")
#define MP_TRAN_CODE_INPUT_ATTRIBUTE    ("INPUT ATTRIBUTE")
#define MP_TRAN_CODE_CUSTOM_ACTION      ("CUSTOM ACTION")
#define MP_TRAN_CODE_ERROR_ACTION       ("ERROR ACTION")

/* 2006.01.12. CM Koo. Sublot Resume Transaction */
#define MP_TRAN_CODE_RESUME         ("RESUME      ")

#define MP_TRAN_CODE_COLLECT_DEFECT ("COLLECT_DFT ")
#define MP_TRAN_CODE_CLEAN_DEFECT   ("CLEAR_DFT   ")

/* 2015.08 MHIM. Abort Start Lot Transaction */
#define MP_TRAN_CODE_ABORT_START    ("ABORT_START ")


/* 2012.05.24. hans INV Transaction Code */
/**********************************************************/
/* INV Transaction Code                                   */
/**********************************************************/
#define MP_INV_TRAN_CODE_IN				("IN          ")
#define MP_INV_TRAN_CODE_OUT			("OUT         ")
#define MP_INV_TRAN_CODE_TRANSFER		("TRANSFER    ")
#define MP_INV_TRAN_CODE_INSPECTION		("INSPECTION  ")
#define MP_INV_TRAN_CODE_IQC			("IQC         ")
#define MP_INV_TRAN_CODE_ASSY			("ASSY        ")
#define MP_INV_TRAN_CODE_DISASSY		("DISASSY     ")
#define MP_INV_TRAN_CODE_HOLD			("HOLD        ")
#define MP_INV_TRAN_CODE_RELEASE		("RELEASE     ")
#define MP_INV_TRAN_CODE_SPLIT			("SPLIT       ")
#define MP_INV_TRAN_CODE_LOSS			("LOSS        ")
#define MP_INV_TRAN_CODE_DEFECT			("DEFECT      ")
#define MP_INV_TRAN_CODE_ADAPT			("ADAPT       ")
#define MP_INV_TRAN_CODE_MERGE			("MERGE       ")

/* 2012.05.29. hans INV Transaction Type */
/**********************************************************/
/* INV Transaction Type                                   */
/**********************************************************/
#define MP_INV_TRAN_TYPE_MAT_IN			("MAT_IN    ")
#define MP_INV_TRAN_TYPE_ETC_IN			("ETC_IN    ")
#define MP_INV_TRAN_TYPE_CHG_IN			("CHG_IN    ")
#define MP_INV_TRAN_TYPE_MAT_OUT		("MAT_OUT   ")
#define MP_INV_TRAN_TYPE_ETC_OUT		("ETC_OUT   ")
#define MP_INV_TRAN_TYPE_CHG_OUT		("CHG_OUT   ")
#define MP_INV_TRAN_TYPE_RET_OUT		("RET_OUT   ")
#define MP_INV_TRAN_TYPE_MAT_TRN		("MAT_TRN   ")
#define MP_INV_TRAN_TYPE_SPE_TRN		("SPE_TRN   ")
#define MP_INV_TRAN_TYPE_WIP_TRN		("WIP_TRN   ")
#define MP_INV_TRAN_TYPE_RET_TRN		("RET_TRN   ")

/****************************************************/
/* Process Step 상수                                */
/****************************************************/
#define MP_STEP_CREATE            ('I')
#define MP_STEP_UPDATE            ('U')
#define MP_STEP_DELETE            ('D')
#define MP_STEP_CONFIRM           ('F')
#define MP_STEP_DELETE_FORCE      ('X')
#define MP_STEP_COPY              ('C')
#define MP_STEP_UNDELETE          ('R')
#define MP_STEP_APPROVAL          ('A')
#define MP_STEP_RELEASE           ('E')
#define MP_STEP_CANCEL_APPROVAL   ('P')
#define MP_STEP_CANCEL_RELEASE    ('W')
#define MP_STEP_SCRAP             ('S')
#define MP_STEP_RETURN            ('N')
#define MP_STEP_REGENERATE        ('G')
#define MP_STEP_EXCLUDE_DATA      ('D')
#define MP_STEP_INCLUDE_DATA      ('L')
#define MP_STEP_VERSION_UP        ('V')
#define MP_STEP_TERMINATE         ('M')
#define MP_STEP_SUPERVISOR        ('$')

/****************************************************/
/* CMF 코드및 및 Transaction 코드를 나타내는 상수들 */
/****************************************************/

/* Setup Related CMF */
#define MP_CMF_MATERIAL           ("CMF_MATERIAL        ")
#define MP_CMF_FLOW               ("CMF_FLOW            ")
#define MP_CMF_OPERATION          ("CMF_OPER            ")
#define MP_CMF_STEP               ("CMF_STEP            ")
#define MP_CMF_RESOURCE           ("CMF_RESOURCE        ")
#define MP_CMF_CARRIER            ("CMF_CARRIER         ")
#define MP_CMF_PORT               ("CMF_PORT            ")
#define MP_CMF_USER               ("CMF_USER            ")
#define MP_CMF_CHARACTER          ("CMF_CHARACTER       ")
#define MP_CMF_COL_SET            ("CMF_COL_SET         ")
#define MP_CMF_ORDER              ("CMF_ORDER           ")
#define MP_CMF_BOM_SET            ("CMF_BOM_SET         ")
#define MP_CMF_PART               ("CMF_PART            ")
#define MP_CMF_RECIPE             ("CMF_RECIPE          ")
#define MP_CMF_LABEL              ("CMF_LABEL           ")
#define MP_CMF_SMP_PROC           ("CMF_SMP_PROC        ")
#define MP_CMF_INSP_ITEM          ("CMF_INSP_ITEM       ")
#define MP_CMF_INSP_SET           ("CMF_INSP_SET        ")
#define MP_CMF_QUEUETIME          ("CMF_QUEUETIME       ")

#define MP_CMF_RULE_RELATION      ("CMF_RULE_RELATION   ")
#define MP_CMF_SERVICE            ("CMF_SERVICE         ")

#define MP_CMF_CHKLIST            ("CMF_CHKLIST         ")

/* Transaction Related CMF */
#define MP_CMF_LOT                ("CMF_LOT             ")
#define MP_CMF_SUBLOT             ("CMF_SUBLOT          ")

#define MP_CMF_TRN_ADAPT          ("CMF_TRN_ADAPT       ")
#define MP_CMF_TRN_BONUS          ("CMF_TRN_BONUS       ")
#define MP_CMF_TRN_LOSS           ("CMF_TRN_LOSS        ")
#define MP_CMF_TRN_CREATE         ("CMF_TRN_CREATE      ")
#define MP_CMF_TRN_START          ("CMF_TRN_START       ")
#define MP_CMF_TRN_END            ("CMF_TRN_END         ")
#define MP_CMF_TRN_MOVE           ("CMF_TRN_MOVE        ")
#define MP_CMF_TRN_SKIP           ("CMF_TRN_SKIP        ")
#define MP_CMF_TRN_REWORK         ("CMF_TRN_REWORK      ")
#define MP_CMF_TRN_REPAIR         ("CMF_TRN_REPAIR      ")
#define MP_CMF_TRN_REPAIR_END     ("CMF_TRN_REPAIR_END  ")
#define MP_CMF_TRN_LOCAL_REPAIR   ("CMF_TRN_LOCAL_REPAIR")
#define MP_CMF_TRN_SPLIT          ("CMF_TRN_SPLIT       ")
#define MP_CMF_TRN_COMBINE        ("CMF_TRN_COMBINE     ")
#define MP_CMF_TRN_MERGE          ("CMF_TRN_MERGE       ")
#define MP_CMF_TRN_HOLD           ("CMF_TRN_HOLD        ")
#define MP_CMF_TRN_RELEASE        ("CMF_TRN_RELEASE     ")
#define MP_CMF_TRN_SHIP           ("CMF_TRN_SHIP        ")
#define MP_CMF_TRN_RECEIVE        ("CMF_TRN_RECEIVE     ")
#define MP_CMF_TRN_ASSEMBLY       ("CMF_TRN_ASSEMBLY    ")
#define MP_CMF_TRN_DISASSEMBLE    ("CMF_TRN_DISASSEMBLE ")
#define MP_CMF_TRN_REPLACE        ("CMF_TRN_REPLACE     ")
#define MP_CMF_TRN_LOTEDC         ("CMF_TRN_LOTEDC      ")
#define MP_CMF_TRN_EVENT          ("CMF_TRN_EVENT       ")
#define MP_CMF_TRN_SORT           ("CMF_TRN_SORT        ")
#define MP_CMF_TRN_STORE          ("CMF_TRN_STORE       ")
#define MP_CMF_TRN_UNSTORE        ("CMF_TRN_UNSTORE     ")
#define MP_CMF_TRN_TERMINATE      ("CMF_TRN_TERMINATE   ")
#define MP_CMF_TRN_RESERVE        ("CMF_TRN_RESERVE     ")
#define MP_CMF_TRN_UNRESERVE      ("CMF_TRN_UNRESERVE   ")
//Add by J.S. 2009.02.26
#define MP_CMF_TRN_SCRIBE         ("CMF_TRN_SCRIBE      ")
#define MP_CMF_TRN_CV             ("CMF_TRN_CV          ")
//Add by J.S. 2009.02.26
#define MP_CMF_TRN_REGENERATE     ("CMF_TRN_REGENERATE  ")

#define MP_CMF_TRN_COLLECT_DEFECT ("CMF_TRN_COLLECT_DFT ")
#define MP_CMF_TRN_CLEAN_DEFECT   ("CMF_TRN_CLEAN_DFT   ")

//port change
#define MP_CMF_TRN_CHANGE_PORT    ("CMF_TRN_CHANGE_PORT ")
#define MP_CMF_TRN_ABORT_START    ("CMF_TRN_ABORT_START ")

//QCM
#define MP_CMF_TRN_QCM_BATCH      ("CMF_TRN_QCM_BATCH   ")
#define MP_CMF_TRN_QCM_RESULT     ("CMF_TRN_QCM_RESULT  ")
#define MP_CMF_TRN_QCM_FINAL      ("CMF_TRN_QCM_FINAL   ")
#define MP_CMF_TRN_QCM_MERGE      ("CMF_TRN_QCM_MERGE   ")
#define MP_CMF_TRN_QCM_SPLIT      ("CMF_TRN_QCM_SPLIT   ")

/* Inventory related CMF */
#define MP_CMF_TRN_IN_INV         ("CMF_TRN_IN_INV      ")
#define MP_CMF_TRN_OUT_INV        ("CMF_TRN_OUT_INV     ")
#define MP_CMF_TRN_TRANS_INV      ("CMF_TRN_TRANS_INV   ")
#define MP_CMF_TRN_CONV_TO_LOT    ("CMF_TRN_CONV_TO_LOT ")
#define MP_CMF_TRN_CONV_TO_INV    ("CMF_TRN_CONV_TO_INV ")
#define MP_CMF_TRN_CONSUME        ("CMF_TRN_CONSUME     ")
#define MP_CMF_TRN_SCRAP          ("CMF_TRN_SCRAP       ")
#define MP_CMF_CHART              ("CMF_CHART           ")
#define MP_CMF_CHART_SET          ("CMF_CHART_SET       ")
#define MP_CMF_CALENDAR           ("CMF_CALENDAR        ")
#define MP_CMF_ALARM              ("CMF_ALARM           ")

/* BIN related CMF */
#define MP_CMF_BIN_DEF            ("CMF_BIN_DEF         ")
#define MP_CMF_BIN_UNIT           ("CMF_BIN_UNIT        ")
#define MP_CMF_BIN_GRADE          ("CMF_BIN_GRADE       ")
#define MP_CMF_TRN_BIN_COL        ("CMF_TRN_BIN_COL     ")

//Add by Kelly Jung 20121201
//Inventory Material/Operation
#define MP_CMF_INV_MATERIAL       ("CMF_INV_MATERIAL    ")
#define MP_CMF_INV_OPERATION      ("CMF_INV_OPER        ")
#define MP_CMF_INV_TRN_ADAPT      ("CMF_INV_TRN_ADAPT   ")

//Add by JJ.OH 2013/01/08
#define MP_CMF_INV_LOT            ("CMF_INV_LOT         ")
#define MP_INV_UNIT_TABLE         ("INV_UNIT            ")
#define MP_INV_LOT_TYPE           ("INV_LOT_TYPE        ")

/* Group Definition related CMF */
#define MP_GRP_FLOW               ("GRP_FLOW            ")
#define MP_GRP_MATERIAL           ("GRP_MATERIAL        ")
#define MP_GRP_OPERATION          ("GRP_OPER            ")
#define MP_GRP_RESOURCE           ("GRP_RESOURCE        ")
#define MP_GRP_EVENT              ("GRP_EVENT           ") 
#define MP_GRP_CHARACTER          ("GRP_CHARACTER       ")
#define MP_GRP_USER               ("GRP_USER            ")
#define MP_GRP_COL_SET            ("GRP_COL_SET         ")
#define MP_GRP_BOM_SET            ("GRP_BOM_SET         ")
#define MP_GRP_RECIPE             ("GRP_RECIPE          ")
#define MP_GRP_INSP_SET           ("GRP_INSP_SET        ")
#define MP_GRP_CHART              ("GRP_CHART           ")
#define MP_GRP_CHART_SET          ("GRP_CHART_SET       ")
#define MP_GRP_STEP               ("GRP_STEP            ")
#define MP_GRP_BIN_DEF            ("GRP_BIN_DEF         ")
#define MP_GRP_CALENDAR           ("GRP_CALENDAR        ")
#define MP_GRP_ALARM              ("GRP_ALARM           ")
#define MP_GRP_CHKLIST            ("GRP_CHKLIST         ")

//Add by Kelly Jung 20121201
//Inventory Material/Operation
#define MP_GRP_INV_MATERIAL       ("GRP_INV_MATERIAL    ")
#define MP_GRP_INV_OPERATION      ("GRP_INV_OPER        ")


//Add by JJ.OH 2013-01-03
//Inventory Material Type
#define MP_INV_MATERIAL_TYPE      ("INV_MATERIAL_TYPE   ")

/****************************************************/
/* GCM Table Name                                   */
/****************************************************/

/* Upgrade Option GCM Table Name */
#define MP_UPGRADE_OPTION         ("UPGRADE_OPTION      ")

/* CMF Definition GCM Table Name */
#define MP_CMF_ITEM_NAME          ("CMF_ITEM_NAME       ")
/* GROUP Definition GCM Table Name */
#define MP_GROUP_ITEM_NAME        ("GROUP_ITEM_NAME     ")

/* Global Option Name */
#define MP_OPTION_AUTO_CALC_DUE_DATE                ("MP_AutoCalDueDate")
#define MP_OPTION_PROCESS_ZERO_QTY_LOT              ("MP_AllowProcessZeroQtyLot")
#define MP_OPTION_DIFF_BOM_SET_VERSION              ("MP_AllowDiffBomSetVersion")
#define MP_OPTION_MERGE_DIFF_MAT_ID                 ("MP_AllowMergeDiffMatID")
#define MP_OPTION_MERGE_DIFF_MAT_VERSION            ("MP_AllowMergeDiffMatVersion")
#define MP_OPTION_MERGE_DIFF_OPER                   ("MP_AllowMergeDiffOper")
//Add by J.S. 2011.04.07 Merge시 Start flag가 달라도 허용
#define MP_OPTION_MERGE_DIFF_PROCESS_STATUS         ("MP_AllowMergeDiffProcessStatus")

#define MP_OPTION_SPLIT_DIFF_MAT_ID                 ("MP_AllowSplitDiffMatID")
#define MP_OPTION_SPLIT_DIFF_MAT_VERSION            ("MP_AllowSplitDiffMatVersion")
#define MP_OPTION_SPLIT_DIFF_OPER                   ("MP_AllowSplitDiffOper")
#define MP_OPTION_USE_BACK_DATE                     ("MP_AllowUseBackDate")
#define MP_OPTION_USE_SAMLL_LETTER                  ("MP_AllowUseSmallLetter")
#define MP_OPTION_USE_ANY_RESOURCE                  ("MP_AllowUseAnyResource")
#define MP_OPTION_REWORK_BY_DEFINITION              ("MP_ReworkByDefinition")
//이상발생 처리 절차를 따를 것인지 결정, 이 Option이 설정되면 조치사항까지 입력해야 Release를 할 수 있다
#define MP_OPTION_USE_TROUBLE_LOT_PROCESS           ("MP_AllowTroubleLotProcess")
//Pull 공정에서 재작업시 바로 재작업 공정으로 보낼것인지 재작업 플래그만 설정하고 대기할지를 결정.
//이 Option이 설정되면 재작업 공정으로 Lot을 보낸다.
#define MP_OPTION_SEND_TO_REWORK_IN_PULL            ("MP_SendToReworkInPullOper")
//Cycle Time Setup 시 시간의 Unit 설정
#define MP_OPTION_CYCLE_TIME_UNIT                   ("MP_CycleTimeUnit")
//Password가 없는 사용자 ID 생성이 가능한지 설정
#define MP_OPTION_ALLOW_EMPTY_USER_PASSWORD         ("MP_AllowEmptyUserPassword")
// DLLH 시에 Lot의 Attribute도 함께 삭제하는지 설정
#define MP_OPTION_DEL_ATTR_HIST_BY_LOT              ("MP_DelAttributeHistByLot")
// DLRH 시에 Res의 Attribute도 함께 삭제하는지 설정
#define MP_OPTION_DEL_ATTR_HIST_BY_RES              ("MP_DelAttributeHistByRes")
// DLLH 시에 SubLot의 Attribute도 함께 삭제하는지 설정
#define MP_OPTION_DEL_ATTR_HIST_BY_SUBLOT           ("MP_DelAttributeHistBySubLot")
// Queue Time Setup 시 시간의 Unit 설정
#define MP_OPTION_QUEUE_TIME_UNIT                   ("MP_QueueTimeUnit")
// Summary Temp History 생성 여부
#define MP_OPTION_MAKE_SUM_TEMP_HISTORY             ("MP_MakeSumTempHistory")
// Multi Hold를 사용할지 여부를 설정
#define MP_OPTION_ALLOW_MULTI_HOLD                  ("MP_AllowMultiHold")
#define MP_OPTION_MAKE_HISTORY_CMF_CHANGE           ("MP_MakeHistoryCMFChange")
#define MP_OPTION_CARRIER_USAGE_COUNT_POINT         ("MP_CarrierUsageCountPoint")
#define MP_OPTION_CARRIER_USAGE_INCREASE_COUNT      ("MP_CarrierUsageIncreaseCount")
#define MP_OPTION_USE_PM_SHEET                      ("MP_UsePMSheet")
#define MP_OPTION_STORE_DSP_EVENT_HISTORY           ("MP_StoreDspEventHistory")
#define MP_OPTION_STORE_DSP_RESULT_HISTORY          ("MP_StoreDspResultHistory")
// Lot Qty2 에 대해 Qty1 의 배수로 설정할지 여부를 결정하고
// Sublot에 대해 Cell Grade를 관리할지를 결정
#define MP_OPTION_USE_CELL_GRADE                    ("MP_UseCellGrade")
// BackTime에 미래시간 허용 여부
#define MP_OPTION_ALLOW_FUTURE_DATETIME             ("MP_AllowFutureDateTime")
//Lot의 같은 History Sequence에 대해 연속된 EDC 발생 시 매번 LOTEDC 이력을 쌓을지 or 한개만 쌓을지 여부 결정 
#define MP_OPTION_STORE_ALL_LOTEDC_HISTORY          ("MP_StoreAllLOTEDCHistory")
//Carrier 의 Usage 를 Core 에서 체크할 것인지 여부를 결정
#define MP_OPTION_CHECK_CARRIER_USAGE_LIMIT         ("MP_CheckCarrierUsageLimit")
// Tool Event Check 시 사용할 시간 단위
#define MP_OPTION_TOOL_EVENT_CHECK_TIME_UNIT        ("MP_ToolEventCheckTimeUnit")
// Tool Status중 현재 사용중인 장비를 저장한 Status 의 Prompt 값을 가져오는 Option
#define MP_OPTION_TOOL_INSTALL_RESOURCE_PROMPT      ("MP_ToolInstallResourcePrompt")
//Add by J.S. 2011.11.08 ADAPT에서 FLOW가 바뀌는 경우 OPER IN TIME 변경여부
#define MP_OPTION_KEEP_OPER_IN_TIME_FLOW_CHG_ADAPT  ("MP_KeepOperInTimeFlowChgAdapt")
//Add by J.S. 2012.06.13 RTD Setup시 자동으로 redispatching 해주는 것을 Off하는 옵
#define MP_OPTION_OFF_AUTOMATIC_REDISPATCHING       ("MP_OffAutomaticReDispatching")
//Add by JU.Heo 2012.11.20 Resource의 process count를 새로 계산 할지 여부 체크
#define MP_CAL_RESOURCE_PROCESS_COUNT               ("MP_CalResourceProcessCount")
// Use Lot Extension Table or nor
#define MP_OPTION_USE_LOTEXT                        ("MP_UseExtensionLotInfo")
// Use Lot Extension Table or nor
#define MP_OPTION_CHILDLOT_INHERIT_MOTHER_TIME      ("MP_ChildLotInheritMotherTime")

#define MP_OPTION_COMBINE_DIFF_MAT_ID               ("MP_AllowCombineDiffMatID")
#define MP_OPTION_COMBINE_DIFF_MAT_VERSION          ("MP_AllowCombineDiffMatVersion")
#define MP_OPTION_COMBINE_DIFF_OPER                 ("MP_AllowCombineDiffOper")
#define MP_OPTION_COMBINE_DIFF_PROCESS_STATUS       ("MP_AllowCombineDiffProcStatus")
#define MP_OPTION_CHECK_QUEUE_TIME_BY_TRANS         ("MP_CheckQueueTimeByTransaction")
#define MP_OPTION_STORE_ALL_LOTBDC_HISTORY          ("MP_StoreAllLOTBDCHistory")
#define MP_OPTION_USE_SINGLE_TARGET_AT_SPM          ("MP_UseSingleTargetAtSPM")
#define MP_OPTION_USE_BIN_MANAGEMENT                ("MP_UseBinManagement")
#define MP_OPTION_INDEPENDENT_SUBAREA               ("MP_IndependentSubarea")
#define MP_OPTION_ONE_TO_ONE_RESOURCE_AND_GOUP      ("MP_OneToOneResourceAndGroup")
/* 2013.06.14. Aiden. Checking sublot quantity when LOSS, BONUS, CV */
#define MP_OPTION_ALLOW_DIFF_LOT_QTY23_WITH_SUBLOT  ("MP_AllowDiffLotQty23WithSublot")
/* 2013.06.14. Aiden. How to assign sublot quantity when create sublot */
#define MP_OPTION_GEN_SUBLOT_QTY2_BY_LOT            ("MP_GenerateSubLotQty2ByLot")
#define MP_OPTION_CHECK_NSTD_STATUS_ADAPT           ("MP_CheckNSTDStatusAtAdaptLot")
/* 2013.09.05 Chris. Option whether to recalculate lot with zero quantity in RTD */
#define MP_OPTION_RECALCULATE_ZERO_QTY_LOT_RTD      ("MP_RecalculateZeroQtyLotinRTD")
/* 2014.03.04 Aiden. Option whether to check queue time violation comes from operation only */
#define MP_OPTION_CHECK_QUEUE_TIME_COMES_FROM_ONLY  ("MP_CheckQ-TimeComesFromOnly")
/* 2014.03.04 Aiden. Option whether to make from point queue time information */
#define MP_OPTION_MAKE_FROM_QUEUE_TIME_INFOR        ("MP_MakeFromQueueTimeInfor")
/* 2015.06.02 Aiden. Allow Duplicate Flow at the Material */
#define MP_OPTION_ALLOW_DUPLICATE_FLOW              ("MP_AllowDuplicateFlow")
/* 2015.07.31 Chris. Option whether to recalculate lot with zero quantity in RTD */
#define MP_OPTION_RECALCULATE_PROC_LOT_RTD			("MP_RecalculateProcLotinRTD")
/* 2015.07.31 Chris. Option whether to use operatorin RTD */
#define MP_OPTION_USE_OPERATOR_RULE					("MP_UseOperatorinRule")
/* 2015.08.28 Aiden. Option whether to use custom mail contents or not */
#define MP_OPTION_USE_CUSTOM_MAIL_CONTENTS          ("MP_UseCustomMailContents")
/* 2016.04.05 Aiden. Option whether to change port state with lot transaction or not */
#define MP_OPTION_CHANGE_PORT_STATE_WITH_LOT        ("MP_ChangePortStateWithLotTran")

/* System MEssage Group GCM Table */
#define MP_GCM_MSGGRP_TBL         ("MESSAGE_GROUP       ")

/* Collection Set Group Table 1~10 */
#define MP_GCM_COL_GRP_1          ("COL_GRP_1           ")
#define MP_GCM_COL_GRP_2          ("COL_GRP_2           ")
#define MP_GCM_COL_GRP_3          ("COL_GRP_3           ")
#define MP_GCM_COL_GRP_4          ("COL_GRP_4           ")
#define MP_GCM_COL_GRP_5          ("COL_GRP_5           ")
#define MP_GCM_COL_GRP_6          ("COL_GRP_6           ")
#define MP_GCM_COL_GRP_7          ("COL_GRP_7           ")
#define MP_GCM_COL_GRP_8          ("COL_GRP_8           ")
#define MP_GCM_COL_GRP_9          ("COL_GRP_9           ")
#define MP_GCM_COL_GRP_10         ("COL_GRP_10          ")

/* Character Group Table 1~10 */
#define MP_GCM_CHAR_GRP_1         ("CHAR_GRP_1          ")
#define MP_GCM_CHAR_GRP_2         ("CHAR_GRP_2          ")
#define MP_GCM_CHAR_GRP_3         ("CHAR_GRP_3          ")
#define MP_GCM_CHAR_GRP_4         ("CHAR_GRP_4          ")
#define MP_GCM_CHAR_GRP_5         ("CHAR_GRP_5          ")
#define MP_GCM_CHAR_GRP_6         ("CHAR_GRP_6          ")
#define MP_GCM_CHAR_GRP_7         ("CHAR_GRP_7          ")
#define MP_GCM_CHAR_GRP_8         ("CHAR_GRP_8          ")
#define MP_GCM_CHAR_GRP_9         ("CHAR_GRP_9          ")
#define MP_GCM_CHAR_GRP_10        ("CHAR_GRP_10         ")

/* Resource Group Table 1~10 */
#define MP_GCM_RES_GRP_1          ("RES_GRP_1           ")
#define MP_GCM_RES_GRP_2          ("RES_GRP_2           ")
#define MP_GCM_RES_GRP_3          ("RES_GRP_3           ")
#define MP_GCM_RES_GRP_4          ("RES_GRP_4           ")
#define MP_GCM_RES_GRP_5          ("RES_GRP_5           ")
#define MP_GCM_RES_GRP_6          ("RES_GRP_6           ")
#define MP_GCM_RES_GRP_7          ("RES_GRP_7           ")
#define MP_GCM_RES_GRP_8          ("RES_GRP_8           ")
#define MP_GCM_RES_GRP_9          ("RES_GRP_9           ")
#define MP_GCM_RES_GRP_10         ("RES_GRP_10          ")

/* Material Group Table 1~10 */
#define MP_GCM_MATERIAL_GRP_1     ("MATERIAL_GRP_1      ")
#define MP_GCM_MATERIAL_GRP_2     ("MATERIAL_GRP_2      ")
#define MP_GCM_MATERIAL_GRP_3     ("MATERIAL_GRP_3      ")
#define MP_GCM_MATERIAL_GRP_4     ("MATERIAL_GRP_4      ")
#define MP_GCM_MATERIAL_GRP_5     ("MATERIAL_GRP_5      ")
#define MP_GCM_MATERIAL_GRP_6     ("MATERIAL_GRP_6      ")
#define MP_GCM_MATERIAL_GRP_7     ("MATERIAL_GRP_7      ")
#define MP_GCM_MATERIAL_GRP_8     ("MATERIAL_GRP_8      ")
#define MP_GCM_MATERIAL_GRP_9     ("MATERIAL_GRP_9      ")
#define MP_GCM_MATERIAL_GRP_10    ("MATERIAL_GRP_10     ")

/*Inventory Material Group Table 1~10*/
#define MP_GCM_INV_MATERIAL_GRP_1     ("INV_MATERIAL_GRP_1  ")
#define MP_GCM_INV_MATERIAL_GRP_2     ("INV_MATERIAL_GRP_2  ")
#define MP_GCM_INV_MATERIAL_GRP_3     ("INV_MATERIAL_GRP_3  ")
#define MP_GCM_INV_MATERIAL_GRP_4     ("INV_MATERIAL_GRP_4  ")
#define MP_GCM_INV_MATERIAL_GRP_5     ("INV_MATERIAL_GRP_5  ")
#define MP_GCM_INV_MATERIAL_GRP_6     ("INV_MATERIAL_GRP_6  ")
#define MP_GCM_INV_MATERIAL_GRP_7     ("INV_MATERIAL_GRP_7  ")
#define MP_GCM_INV_MATERIAL_GRP_8     ("INV_MATERIAL_GRP_8  ")
#define MP_GCM_INV_MATERIAL_GRP_9     ("INV_MATERIAL_GRP_9  ")
#define MP_GCM_INV_MATERIAL_GRP_10    ("INV_MATERIAL_GRP_10 ")

/* Flow Group Table 1~10 */
#define MP_GCM_FLOW_GRP_1         ("FLOW_GRP_1          ")
#define MP_GCM_FLOW_GRP_2         ("FLOW_GRP_2          ")
#define MP_GCM_FLOW_GRP_3         ("FLOW_GRP_3          ")
#define MP_GCM_FLOW_GRP_4         ("FLOW_GRP_4          ")
#define MP_GCM_FLOW_GRP_5         ("FLOW_GRP_5          ")
#define MP_GCM_FLOW_GRP_6         ("FLOW_GRP_6          ")
#define MP_GCM_FLOW_GRP_7         ("FLOW_GRP_7          ")
#define MP_GCM_FLOW_GRP_8         ("FLOW_GRP_8          ")
#define MP_GCM_FLOW_GRP_9         ("FLOW_GRP_9          ")
#define MP_GCM_FLOW_GRP_10        ("FLOW_GRP_10         ")

/* Operation Group Table 1~10 */
#define MP_GCM_OPER_GRP_1         ("OPER_GRP_1          ")
#define MP_GCM_OPER_GRP_2         ("OPER_GRP_2          ")
#define MP_GCM_OPER_GRP_3         ("OPER_GRP_3          ")
#define MP_GCM_OPER_GRP_4         ("OPER_GRP_4          ")
#define MP_GCM_OPER_GRP_5         ("OPER_GRP_5          ")
#define MP_GCM_OPER_GRP_6         ("OPER_GRP_6          ")
#define MP_GCM_OPER_GRP_7         ("OPER_GRP_7          ")
#define MP_GCM_OPER_GRP_8         ("OPER_GRP_8          ")
#define MP_GCM_OPER_GRP_9         ("OPER_GRP_9          ")
#define MP_GCM_OPER_GRP_10        ("OPER_GRP_10         ")

/*Step Group Table 1~10 */
#define MP_GCM_STEP_GRP_1         ("STEP_GRP_1          ")
#define MP_GCM_STEP_GRP_2         ("STEP_GRP_2          ")
#define MP_GCM_STEP_GRP_3         ("STEP_GRP_3          ")
#define MP_GCM_STEP_GRP_4         ("STEP_GRP_4          ")
#define MP_GCM_STEP_GRP_5         ("STEP_GRP_5          ")
#define MP_GCM_STEP_GRP_6         ("STEP_GRP_6          ")
#define MP_GCM_STEP_GRP_7         ("STEP_GRP_7          ")
#define MP_GCM_STEP_GRP_8         ("STEP_GRP_8          ")
#define MP_GCM_STEP_GRP_9         ("STEP_GRP_9          ")
#define MP_GCM_STEP_GRP_10        ("STEP_GRP_10         ")

/* User Group Table 1~10 */
#define MP_GCM_USER_GRP_1         ("USER_GRP_1          ")
#define MP_GCM_USER_GRP_2         ("USER_GRP_2          ")
#define MP_GCM_USER_GRP_3         ("USER_GRP_3          ")
#define MP_GCM_USER_GRP_4         ("USER_GRP_4          ")
#define MP_GCM_USER_GRP_5         ("USER_GRP_5          ")
#define MP_GCM_USER_GRP_6         ("USER_GRP_6          ")
#define MP_GCM_USER_GRP_7         ("USER_GRP_7          ")
#define MP_GCM_USER_GRP_8         ("USER_GRP_8          ")
#define MP_GCM_USER_GRP_9         ("USER_GRP_9          ")
#define MP_GCM_USER_GRP_10        ("USER_GRP_10         ")

#define MP_GCM_EVN_GRP_1          ("EVN_GRP_1           ")
#define MP_GCM_EVN_GRP_2          ("EVN_GRP_2           ")
#define MP_GCM_EVN_GRP_3          ("EVN_GRP_3           ")
#define MP_GCM_EVN_GRP_4          ("EVN_GRP_4           ")
#define MP_GCM_EVN_GRP_5          ("EVN_GRP_5           ")
#define MP_GCM_EVN_GRP_6          ("EVN_GRP_6           ")
#define MP_GCM_EVN_GRP_7          ("EVN_GRP_7           ")
#define MP_GCM_EVN_GRP_8          ("EVN_GRP_8           ")
#define MP_GCM_EVN_GRP_9          ("EVN_GRP_9           ")
#define MP_GCM_EVN_GRP_10         ("EVN_GRP_10          ")

/* BOM Set Group Table 1~10 */
#define MP_GCM_BOM_GRP_1          ("BOM_GRP_1           ")
#define MP_GCM_BOM_GRP_2          ("BOM_GRP_2           ")
#define MP_GCM_BOM_GRP_3          ("BOM_GRP_3           ")
#define MP_GCM_BOM_GRP_4          ("BOM_GRP_4           ")
#define MP_GCM_BOM_GRP_5          ("BOM_GRP_5           ")
#define MP_GCM_BOM_GRP_6          ("BOM_GRP_6           ")
#define MP_GCM_BOM_GRP_7          ("BOM_GRP_7           ")
#define MP_GCM_BOM_GRP_8          ("BOM_GRP_8           ")
#define MP_GCM_BOM_GRP_9          ("BOM_GRP_9           ")
#define MP_GCM_BOM_GRP_10         ("BOM_GRP_10          ")

/* Recipe Group Table 1~10 */
#define MP_GCM_RCP_GRP_1          ("RCP_GRP_1           ")
#define MP_GCM_RCP_GRP_2          ("RCP_GRP_2           ")
#define MP_GCM_RCP_GRP_3          ("RCP_GRP_3           ")
#define MP_GCM_RCP_GRP_4          ("RCP_GRP_4           ")
#define MP_GCM_RCP_GRP_5          ("RCP_GRP_5           ")
#define MP_GCM_RCP_GRP_6          ("RCP_GRP_6           ")
#define MP_GCM_RCP_GRP_7          ("RCP_GRP_7           ")
#define MP_GCM_RCP_GRP_8          ("RCP_GRP_8           ")
#define MP_GCM_RCP_GRP_9          ("RCP_GRP_9           ")
#define MP_GCM_RCP_GRP_10         ("RCP_GRP_10          ")

/* Inspection Set Group Table 1~10 */
#define MP_GCM_INSP_SET_GRP_1     ("INSP_SET_GRP_1      ")
#define MP_GCM_INSP_SET_GRP_2     ("INSP_SET_GRP_2      ")
#define MP_GCM_INSP_SET_GRP_3     ("INSP_SET_GRP_3      ")
#define MP_GCM_INSP_SET_GRP_4     ("INSP_SET_GRP_4      ")
#define MP_GCM_INSP_SET_GRP_5     ("INSP_SET_GRP_5      ")
#define MP_GCM_INSP_SET_GRP_6     ("INSP_SET_GRP_6      ")
#define MP_GCM_INSP_SET_GRP_7     ("INSP_SET_GRP_7      ")
#define MP_GCM_INSP_SET_GRP_8     ("INSP_SET_GRP_8      ")
#define MP_GCM_INSP_SET_GRP_9     ("INSP_SET_GRP_9      ")
#define MP_GCM_INSP_SET_GRP_10    ("INSP_SET_GRP_10     ")

/* Chart Group Table 1~10 */
#define MP_GCM_CHT_GRP_1          ("CHT_GRP_1           ")
#define MP_GCM_CHT_GRP_2          ("CHT_GRP_2           ")
#define MP_GCM_CHT_GRP_3          ("CHT_GRP_3           ")
#define MP_GCM_CHT_GRP_4          ("CHT_GRP_4           ")
#define MP_GCM_CHT_GRP_5          ("CHT_GRP_5           ")
#define MP_GCM_CHT_GRP_6          ("CHT_GRP_6           ")
#define MP_GCM_CHT_GRP_7          ("CHT_GRP_7           ")
#define MP_GCM_CHT_GRP_8          ("CHT_GRP_8           ")
#define MP_GCM_CHT_GRP_9          ("CHT_GRP_9           ")
#define MP_GCM_CHT_GRP_10         ("CHT_GRP_10          ")

/* Chart Set Group Table 1~10 */
#define MP_GCM_CHTSET_GRP_1       ("CHTSET_GRP_1        ")
#define MP_GCM_CHTSET_GRP_2       ("CHTSET_GRP_2        ")
#define MP_GCM_CHTSET_GRP_3       ("CHTSET_GRP_3        ")
#define MP_GCM_CHTSET_GRP_4       ("CHTSET_GRP_4        ")
#define MP_GCM_CHTSET_GRP_5       ("CHTSET_GRP_5        ")
#define MP_GCM_CHTSET_GRP_6       ("CHTSET_GRP_6        ")
#define MP_GCM_CHTSET_GRP_7       ("CHTSET_GRP_7        ")
#define MP_GCM_CHTSET_GRP_8       ("CHTSET_GRP_8        ")
#define MP_GCM_CHTSET_GRP_9       ("CHTSET_GRP_9        ")
#define MP_GCM_CHTSET_GRP_10      ("CHTSET_GRP_10       ")

/* BIN Definition Group Table 1~10 */
#define MP_GCM_BIN_DEF_GRP_1      ("BIN_DEF_GRP_1       ")
#define MP_GCM_BIN_DEF_GRP_2      ("BIN_DEF_GRP_2       ")
#define MP_GCM_BIN_DEF_GRP_3      ("BIN_DEF_GRP_3       ")
#define MP_GCM_BIN_DEF_GRP_4      ("BIN_DEF_GRP_4       ")
#define MP_GCM_BIN_DEF_GRP_5      ("BIN_DEF_GRP_5       ")
#define MP_GCM_BIN_DEF_GRP_6      ("BIN_DEF_GRP_6       ")
#define MP_GCM_BIN_DEF_GRP_7      ("BIN_DEF_GRP_7       ")
#define MP_GCM_BIN_DEF_GRP_8      ("BIN_DEF_GRP_8       ")
#define MP_GCM_BIN_DEF_GRP_9      ("BIN_DEF_GRP_9       ")
#define MP_GCM_BIN_DEF_GRP_10     ("BIN_DEF_GRP_10      ")

/* Calendar Group Table 1~10 */
#define MP_GCM_CAL_GRP_1          ("CALENDAR_GRP_1      ")
#define MP_GCM_CAL_GRP_2          ("CALENDAR_GRP_2      ")
#define MP_GCM_CAL_GRP_3          ("CALENDAR_GRP_3      ")
#define MP_GCM_CAL_GRP_4          ("CALENDAR_GRP_4      ")
#define MP_GCM_CAL_GRP_5          ("CALENDAR_GRP_5      ")
#define MP_GCM_CAL_GRP_6          ("CALENDAR_GRP_6      ")
#define MP_GCM_CAL_GRP_7          ("CALENDAR_GRP_7      ")
#define MP_GCM_CAL_GRP_8          ("CALENDAR_GRP_8      ")
#define MP_GCM_CAL_GRP_9          ("CALENDAR_GRP_9      ")
#define MP_GCM_CAL_GRP_10         ("CALENDAR_GRP_10     ")

/* Alarm Group Table 1~10 */
#define MP_GCM_ALARM_GRP_1        ("ALARM_GRP_1         ")
#define MP_GCM_ALARM_GRP_2        ("ALARM_GRP_2         ")
#define MP_GCM_ALARM_GRP_3        ("ALARM_GRP_3         ")
#define MP_GCM_ALARM_GRP_4        ("ALARM_GRP_4         ")
#define MP_GCM_ALARM_GRP_5        ("ALARM_GRP_5         ")
#define MP_GCM_ALARM_GRP_6        ("ALARM_GRP_6         ")
#define MP_GCM_ALARM_GRP_7        ("ALARM_GRP_7         ")
#define MP_GCM_ALARM_GRP_8        ("ALARM_GRP_8         ")
#define MP_GCM_ALARM_GRP_9        ("ALARM_GRP_9         ")
#define MP_GCM_ALARM_GRP_10       ("ALARM_GRP_10        ")

/* Checklist Group Table 1~10 */
#define MP_GCM_CHKLIST_GRP_1      ("CHKLIST_GRP_1       ")
#define MP_GCM_CHKLIST_GRP_2      ("CHKLIST_GRP_2       ")
#define MP_GCM_CHKLIST_GRP_3      ("CHKLIST_GRP_3       ")
#define MP_GCM_CHKLIST_GRP_4      ("CHKLIST_GRP_4       ")
#define MP_GCM_CHKLIST_GRP_5      ("CHKLIST_GRP_5       ")
#define MP_GCM_CHKLIST_GRP_6      ("CHKLIST_GRP_6       ")
#define MP_GCM_CHKLIST_GRP_7      ("CHKLIST_GRP_7       ")
#define MP_GCM_CHKLIST_GRP_8      ("CHKLIST_GRP_8       ")
#define MP_GCM_CHKLIST_GRP_9      ("CHKLIST_GRP_9       ")
#define MP_GCM_CHKLIST_GRP_10     ("CHKLIST_GRP_10      ")

#define MP_GCM_MENU_GROUP         ("MENU_GROUP          ")
#define MP_GCM_PROGRAM_TBL        ("PROGRAM_LIST        ")

/* Checklist Type */
#define MP_GCM_CHECK_LIST_TYPE    ("CHECK_LIST_TYPE     ")
#define MP_GCM_CHECK_QUERY_TYPE   ("CHECK_QUERY_TYPE    ")

#define MP_GCM_BBS_MAIN_MENU      ("BBS_MAIN_MENU       ")
#define MP_GCM_BBS_SUB_MENU       ("BBS_SUB_MENU        ")
#define MP_GCM_BBS_MSG_TYPE       ("BBS_MSG_TYPE        ")

/* System Code Table */
#define MP_WIP_FACTORY_TYPE       ("FACTORY_TYPE        ")
#define MP_WIP_CREATE_CODE        ("CREATE_CODE         ")
#define MP_WIP_OWNER_CODE         ("OWNER_CODE          ")
#define MP_WIP_LOT_TYPE           ("LOT_TYPE            ")
#define MP_WIP_SUBLOT_TYPE        ("SUBLOT_TYPE         ")
#define MP_WIP_MATERIAL_TYPE      ("MATERIAL_TYPE       ")
#define MP_WIP_MATERIAL_PACKTYPE  ("MATERIAL_PACK_TYPE  ")
#define MP_WIP_BATCH_TYPE         ("BATCH_TYPE          ")

#define MP_WIP_UNIT_TABLE         ("UNIT                ")
#define MP_WIP_SHIP_CODE          ("SHIP_CODE           ")
#define MP_WIP_HOLD_CODE          ("HOLD_CODE           ")
#define MP_WIP_REPAIR_CODE        ("REPAIR_CODE         ")
#define MP_WIP_RESULT_CODE        ("RESULT_CODE         ")
#define MP_WIP_ACTION_CODE        ("ACTION_CODE         ")
#define MP_WIP_RELEASE_CODE       ("RELEASE_CODE        ")
#define MP_WIP_ORDER_STATUS       ("ORDER_STATUS        ")
#define MP_WIP_TERMINATE_CODE     ("TERMINATE_CODE      ")
#define MP_WIP_SUBLOT_GRADE_CODE  ("SUBLOT_GRADE        ")
#define MP_WIP_CV_CODE            ("CV_CODE             ")

#define MP_INV_SCRAP_CODE         ("SCRAP_CODE          ")
#define MP_INV_CV_CODE            ("INV_CV_CODE         ")

#define MP_RAS_RES_TYPE           ("RES_TYPE            ")
#define MP_RAS_SUBRES_TYPE        ("SUBRES_TYPE         ")
#define MP_RAS_AREA_CODE          ("AREA                ")
#define MP_RAS_SUBAREA_CODE       ("SUB_AREA            ")
#define MP_RAS_WORK_POSITION      ("WORK_POSITION       ")
#define MP_RAS_PM_PERIOD          ("PM_PERIOD           ")
#define MP_RAS_PM_EVENT           ("PM_EVENT            ")
#define MP_RAS_TOOL_STATUS        ("TOOL_STATUS         ")
#define MP_RAS_TOOL_GRP           ("TOOL_GRP            ")
#define MP_RAS_TOOL_GRADE         ("TOOL_GRADE          ")
#define MP_RAS_TOOL_DEFECT        ("TOOL_DEFECT         ")
#define MP_RAS_CHAMBER_GROUP      ("CHAMBER_GROUP       ")

#define MP_RAS_CRR_TYPE1          ("CRR_TYPE1           ")
#define MP_RAS_CRR_TYPE2          ("CRR_TYPE2           ")
#define MP_RAS_CRR_TYPE3          ("CRR_TYPE3           ")

#define MP_RMA_CREATE_CODE        ("RMA_CREATE_CODE     ")
#define MP_RMA_RESULT_CODE        ("RMA_RESULT_CODE     ")

/* Port 상태 */
#define MP_PORT_STATE             ("PORT_STATE          ")
#define MP_WIP_LOT_DEFECT_CODE    ("LOT_DEFECT_CODE     ")

/* Sheet 관련 GCM Table */
#define MP_SHEET_QUERY_TYPE       ("SHEET_QUERY_TYPE    ")
#define MP_SHEET_SHEET_TYPE       ("SHEET_SHEET_TYPE    ")
#define MP_SHEET_DATA_TYPE        ("SHEET_DATA_TYPE     ")

#define MP_SHEET_TYPE_DEFINE      ("SHEET_TYPE_DEFINE   ")
#define MP_SHEET_TRAN_DEFINE      ("SHEET_TRAN_DEFINE   ")

#define MP_SHEET_GRP_CAPTION      ("GROUP_CAPTION       ")
#define MP_SHEET_GRP_TABLE        ("GROUP_TABLE         ")
#define MP_SHEET_TRN_CAPTION      ("TRAN_CAPTION        ")
#define MP_SHEET_TRN_TABLE        ("TRAN_TABLE          ")

/* Flexible Screen */
#define MP_SCREEN_GRP             ("SCREEN_GROUP        ")

/* Sheet Format */
#define MP_DOC_TYPE               ("DOC_TYPE            ")
#define MP_PAPER_TYPE             ("PAPER_TYPE          ")

#define MP_INV_IQC_REQUEST        ('R')
#define MP_INV_IQC_CONFIRM        ('C')
#define MP_INV_IQC		          ('I')
#define MP_INV_ALL		          ('A')

#define MP_INV_STATUS_OPEN           ('O')
#define MP_INV_STATUS_REVOKE         ('R')
#define MP_INV_STATUS_COMPLETE       ('C')
#define MP_INV_STATUS_PROCESSING     ('P')


/* BIN */
#define MP_WIP_BIN_TRANS_CODE	  ("BIN_TRAN_CODE       ")
#define MP_WIP_BIN_CALC_TYPE	  ("BIN_CALC_TYPE       ")
#define MP_WIP_BIN_YIELD_BASE	  ("BIN_YIELD_BASE      ")
#define MP_WIP_BIN_SEQ			  ("BIN_SEQ             ")
#define MP_WIP_BIN_PROMPT	      ("BIN_PROMPT          ")
#define MP_WIP_BIN_TYPE			  ("BIN_TYPE            ")
#define MP_GCM_YESNO			  ("BIN_GCM_YESNO       ")
#define MP_WIP_BIN_GROUP		  ("BIN_GROUP           ")
#define MP_WIP_BIN_OPERATOR		  ("BIN_OPERATOR        ")
#define MP_WIP_BIN_BASE_CUROPRIN  ("CUROPRIN  ")
#define MP_WIP_BIN_BASE_CURQTY    ("CURQTY    ")
#define MP_WIP_BIN_BASE_FACIN     ("FACIN     ")
#define MP_WIP_BIN_BASE_OPRIN     ("OPRIN     ")

/* Priority */
#define MP_WIP_PRIORITY_TYPE_BIN        ("BIN_PRIORITY        ")
#define MP_WIP_PRIORITY_TYPE_TEST_PGM   ("TEST_PGM            ")
#define MP_WIP_PRIORITY_TYPE_QUEUE_TIME             ("QUEUE_TIME          ")

//Add by Kelly 20121226
//Low Yield defines
/*Low Yield*/
#define MP_GCM_LYD_BASE_TYPE        ("LYD_BASE_TYPE       ")
#define MP_GCM_LYD_UNIT             ("LYD_UNIT            ")
#define MP_GCM_LYD_UNIT_TYPE        ("LYD_UNIT_TYPE       ")
#define MP_GCM_LYD_TYPE             ("LYD_TYPE            ")
#define MP_GCM_LYD_CHECK_TRANS      ("LYD_CHECK_TRANS     ")
#define MP_GCM_LYD_AQL_TYPE         ("LYD_AQL_TYPE        ")
#define MP_GCM_LYD_AQL_TBL          ("LYD_AQL_TBL         ")

#define MP_WIP_LYD_BASE_CREATE      ("CREATE              ")
#define MP_WIP_LYD_BASE_OPER_IN     ("OPER_IN             ")
#define MP_WIP_LYD_BASE_OPER_START  ("OPER_START          ")
#define MP_WIP_LYD_BASE_OPER_OUT    ("OPER_OUT            ")
#define MP_WIP_LYD_BASE_CUR_OPER_IN ("CUR_OPER_IN         ")
#define MP_WIP_LYD_BASE_START       ("CUR_OPER_START      ")
#define MP_WIP_LYD_BASE_CURRENT     ("CURRENT             ")
#define MP_WIP_LYD_BASE_LOT_EXT     ("LOT_EXT             ")
#define MP_WIP_LYD_BASE_LOT_STS     ("LOT_STS             ")

#define MP_WIP_LYD_UNIT_QTY         ("QTY       ")
#define MP_WIP_LYD_UNIT_YIELD       ("YIELD     ")
#define MP_WIP_LYD_UNIT_AQL         ("AQL       ")

#define MP_WIP_LYD_TYPE_BL           ("BL        ")
#define MP_WIP_LYD_TYPE_BC           ("BC        ")
#define MP_WIP_LYD_TYPE_LC           ("LC        ")
#define MP_WIP_LYD_TYPE_OL           ("OL        ")
#define MP_WIP_LYD_TYPE_OC           ("OC        ")
#define MP_WIP_LYD_TYPE_OB           ("OB        ")
#define MP_WIP_LYD_TYPE_ALL          ("ALL       ")

#define MP_PRI_LOW_YIELD            ("LYD_PRIORITY        ")

/****************************************************/
/* POP 관련 상수                                    */
/****************************************************/
#define MP_POP_PRINTER_TYPE       ("PRINTER_TYPE        ")
#define MP_POP_RESOLUTION         ("RESOLUTION          ")
#define MP_POP_TEXT_FONT          ("TEXT_FONT           ")
#define MP_POP_BARCODE_FONT       ("BARCODE_FONT        ")
#define MP_POP_PRINT_VARIABLE     ("PRINT_VARIABLE      ")
#define MP_POP_ROTATE             ("ROTATE              ")
/****************************************************/
/* ALM 관련 상수                                    */
/****************************************************/
/* Alarm Type */
#define MP_ALM_NORMAL                  ('N')
#define MP_ALM_RESOURCE                ('R')
#define MP_ALM_AUTO_GATHER             ('A')

/* Alarm Level */
#define MP_ALM_LEVEL_INFO              ('I')
#define MP_ALM_LEVEL_WARN              ('W')
#define MP_ALM_LEVEL_ERROR             ('E')

/* Alarm Level */
#define MP_ALM_TRAN_START              ('S')
#define MP_ALM_TRAN_SPLIT              ('P')
#define MP_ALM_TRAN_END                ('E')
#define MP_ALM_TRAN_REWORK             ('R')
#define MP_ALM_TRAN_START_AFTER        ('1')
#define MP_ALM_TRAN_SPLIT_AFTER        ('2')
#define MP_ALM_TRAN_END_AFTER          ('3')
#define MP_ALM_TRAN_REWORK_AFTER       ('4')

/****************************************************/
/* QCM 관련 상수                                    */
/****************************************************/
#define MP_QCM_SMP_PROC_TYPE             ("SMP_PROC_TYPE       ")
#define MP_QCM_INSP_METHOD               ("QCM_INSP_METHOD     ")
#define MP_QCM_DEFECT_GRP                ("QCM_DEFECT_GRP      ")            
#define MP_QCM_INSP_TYPE                 ("QCM_INSP_TYPE       ")    
#define MP_QCM_VENDOR                    ("QCM_VENDOR          ")            
#define MP_QCM_CUSTOMER                  ("QCM_CUSTOMER        ")
/*Inspection Type*/
#define MP_QCM_INSP_TYPE_IQC             ("IQC       ")
#define MP_QCM_INSP_TYPE_PQC             ("PQC       ")
#define MP_QCM_INSP_TYPE_OQC             ("OQC       ")
#define MP_QCM_INSP_TYPE_RMA             ("RMA       ")
/*Sampling type*/
#define MP_QCM_SMP_TYPE_MANUAL           ("MN        ")
#define MP_QCM_SMP_TYPE_TOTAL_INSPECTION ("TI        ")
#define MP_QCM_SMP_TYPE_FIXED_SAMPLE     ("FS        ")
#define MP_QCM_SMP_TYPE_USED_PERCENTAGE  ("UP        ")
#define MP_QCM_SMP_TYPE_USED_SCHEME      ("US        ")
/*QC Inspection Step*/
#define MP_QCM_STEP_CREATE               ("CREATE    ")
#define MP_QCM_STEP_RESULT               ("RESULT    ")
#define MP_QCM_STEP_FINAL                ("FINAL     ")
/*QC Tran Code*/
#define MP_QCM_TRAN_CREATE               ("CREATE    ")
#define MP_QCM_TRAN_RESULT               ("RESULT    ")
#define MP_QCM_TRAN_SKIP_RESULT          ("S_RESULT  ")
#define MP_QCM_TRAN_ITEM_RESULT          ("I_RESULT  ")
#define MP_QCM_TRAN_ITEM_RESULT_D        ("I_RESULT_D")
#define MP_QCM_TRAN_FINAL                ("FINAL     ")
#define MP_QCM_TRAN_AUTO_FINAL           ("A_FINAL   ")
#define MP_QCM_TRAN_SPLIT                ("SPLIT     ")
#define MP_QCM_TRAN_MERGE                ("MERGE     ")
#define MP_QCM_TRAN_REINSP               ("REINSP    ")
/*Inspection Method*/
#define MP_QCM_INSP_METHOD_I             ("INDIVIDUAL")
#define MP_QCM_INSP_METHOD_Q             ("QUANTIRY  ")
/*Final Decision*/
#define MP_QCM_FINAL_ACCEPT              ("ACCEPT    ")
#define MP_QCM_FINAL_REJECT              ("REJECT    ")
/****************************************************/
/* SPC 관련 상수                                    */
/****************************************************/
/*OOC 발생시 Hold Code*/
#define MP_SPC_HOLD_CODE        ("SPC ERROR ")
#define MP_SPC_EVENT            ("SPC_DOWN    ")
/****************************************************/
/* 상태값을 나타내는 상수                           */
/****************************************************/

/* Lot Status */
#define MP_LOT_STATUS_WAIT          ("WAIT      ")
#define MP_LOT_STATUS_PROC          ("PROC      ")
#define MP_LOT_STATUS_RESV          ("RESV      ")

/* Resource Status */
#define MP_RESOURCE_STATUS_WAIT     ("WAIT      ")
#define MP_RESOURCE_STATUS_PROC     ("PROC      ")
#define MP_DEFAULT_RESOURCE_STATUS  ("WAIT      ")

/* Carrier Status */
#define MP_CARRIER_STATUS_INIT          ("INIT      ")
#define MP_CARRIER_STATUS_WAIT          ("WAIT      ")
#define MP_CARRIER_STATUS_PROC          ("PROC      ")
#define MP_CARRIER_STATUS_NEED_CLEAN    ("NEED_CLEAN")
#define MP_CARRIER_STATUS_CLEAN         ("CLEAN     ")
#define MP_CARRIER_STATUS_HOLD          ("HOLD      ")
#define MP_CARRIER_STATUS_TERM          ("TERM      ")
#define MP_CARRIER_STATUS_RESERVE       ("RESV      ")

/* Resource Up/Down status */
#define MP_RES_UP_FLAG                 ('U')
#define MP_RES_DOWN_FLAG               ('D')
#define MP_DEFAULT_RES_UP_DOWN_FLAG    ('U')

/* Unscheduled PM */
#define MP_PM_PERIOD_US                ("US    ")

/* Tool Status */
#define MP_TOOL_STATUS_WAIT         ("WAIT      ")

/* QC BATCH Status */
#define MP_QCM_BATCH_STATUS_WAIT    ("WAIT      ")
#define MP_QCM_BATCH_STATUS_PROC    ("PROC      ")
#define MP_QCM_BATCH_STATUS_END     ("END       ")

/****************************************************/
/* Event 관련 상수                                  */
/****************************************************/

/* Event 발생 조건 Check Method */
#define EVENT_CHECK_METHOD_NOT_CHECK   ('N')
#define EVENT_CHECK_METHOD_EQUAL       ('=')
#define EVENT_CHECK_METHOD_NOT_EQUAL   ('!')
#define EVENT_CHECK_METHOD_GREAT       ('>')
#define EVENT_CHECK_METHOD_LESS        ('<')
#define EVENT_CHECK_METHOD_TABLE       ('T')
#define EVENT_CHECK_METHOD_GREAT_EQUAL      ('G')
#define EVENT_CHECK_METHOD_LESS_EQUAL       ('L')
#define EVENT_CHECK_METHOD_TIME_GREAT       ('A')
#define EVENT_CHECK_METHOD_TIME_LESS        ('B')
#define EVENT_CHECK_METHOD_TIME_GREAT_EQUAL ('C')
#define EVENT_CHECK_METHOD_TIME_LESS_EQUAL  ('D')

/* Event 발생 후 상태값 변경 Method */
#define EVENT_CHANGE_METHOD_YES        ('Y')
#define EVENT_CHANGE_METHOD_NO         ('N')
#define EVENT_CHANGE_METHOD_PLUS       ('+')
#define EVENT_CHANGE_METHOD_MINUS      ('-')
#define EVENT_CHANGE_METHOD_OVERRIDE   ('O')
#define EVENT_CHANGE_METHOD_TIME       ('T')
#define EVENT_CHANGE_METHOD_RESET      ('R')
#define EVENT_CHANGE_METHOD_MULTIPLY   ('*')
#define EVENT_CHANGE_METHOD_DIVISION   ('/')
#define EVENT_CHANGE_METHOD_MOD        ('M')
#define EVENT_CHANGE_METHOD_POW        ('P')

/* Resource System Event */
#define EVENT_START_RUN           ("START_RUN   ")
#define EVENT_START_LOT           ("START_LOT   ")
#define EVENT_END_RUN             ("END_RUN     ")
#define EVENT_END_LOT             ("END_LOT     ")
#define EVENT_NO_WIP              ("NO_WIP      ")
#define EVENT_NO_OPER             ("NO_OPER     ")

/* 2015.08 MHIM. Abort Start Lot Transaction */
#define EVENT_ABORT_START         ("ABORT_START ")

/****************************************************/
/* Type Definition 상수                             */
/****************************************************/

/* Lot Type */
#define MP_LOT_TYPE_PROD          ('P')
#define MP_LOT_TYPE_TEST          ('T')
#define MP_LOT_TYPE_EMC           ('E')
#define MP_LOT_TYPE_DUMMY         ('D')
#define MP_LOT_TYPE_MONITOR       ('M')

/* Privilege Type */
#define MP_PRV_TYPE_RES           ("RESOURCE            ")
#define MP_PRV_TYPE_OPER          ("OPERATION           ")
#define MP_PRV_TYPE_GCMTBL        ("GCMTABLE            ")
#define MP_PRV_TYPE_SERVICE       ("SERVICE             ")
#define MP_PRV_TYPE_ATTRIBUTE     ("ATTRIBUTE           ")

/* Cmf Type */
#define MP_CMF_TYPE_LOT           ("LOT")
#define MP_CMF_TYPE_TRN           ("TRN")

#define MP_WIP_LOT_BASE_FLAG      ("__LOT_BASE")
#define MP_WIP_SUBLOT_FLAG        ("__SUBLOT_FLAG")

/****************************************************/
/* Mode Definition 상수                             */
/****************************************************/

/* Resource 진행 모드 */
#define MP_RES_PROC_MODE_MANUAL                 ("M         ")
#define MP_RES_PROC_MODE_SEMIAUTO               ("S         ")
#define MP_RES_PROC_MODE_FULLAUTO               ("F         ")
#define MP_DEFAULT_RES_PROC_MODE                (MP_RES_PROC_MODE_MANUAL)


/****************************************************/
/* 기타 상수                                        */
/****************************************************/

/* 최대 Slot 갯수 */
#define MP_MAX_SLOT_CNT                         (1000)

/* Sublot Good Grade */
#define MP_SUBLOT_GOOD_GRADE                    ('G')

/* Sublot Loss시 수량이 빠지는 Grade */
#define MP_SUBLOT_SCRAP_GRADE                   ('S')

/* Batch에 포함될수 있는 Lot의 최대 개수 */
#define MP_MAX_BATCH_CNT                        (12)

/* Lot Auto Terminate Code */
#define MP_WIP_AUTO_TERMINATE_CODE          ("AUTO_TERM ")

#define MP_DONT_CHECK_PASSWORD              ("DO_NOT_CHECK_PASSWORD")

#define MP_MAX_TRAN_TIME                    ("99991231235959")

/* 값의 형태 */
#define MP_FORMAT_ASCII                ('A')
#define MP_FORMAT_NUMBER               ('N')
#define MP_FORMAT_FLOAT                ('F')
#define MP_FORMAT_DATETIME             ('D')
#define MP_FORMAT_DATE                 ('E')
#define MP_FORMAT_TIME                 ('T')

/* 대표 Tool Type 이름 */
#define CENTRAL_TOOL_TYPE              ("SYSTEM              ")

/* Tool System Event ID */
#define TOOL_EVENT_CREATE           ("CREATE      ")
#define TOOL_EVENT_UPDATE           ("UPDATE      ")
#define TOOL_EVENT_SCRAP            ("SCRAP       ")
#define TOOL_EVENT_RETURN           ("RETURN      ")
#define TOOL_EVENT_REGENERATE       ("REGENERATE  ")

/* Carrier System Event ID */
#define MP_TRAN_CRR_CREATE          ("CREATE      ")
#define MP_TRAN_CRR_RECREATE        ("RECREATE    ")
#define MP_TRAN_CRR_TERMINATE       ("TERMINATE   ")
#define MP_TRAN_CRR_CLEAN           ("CLEAN       ")
#define MP_TRAN_CRR_START           ("START       ")
#define MP_TRAN_CRR_END             ("END         ")
#define MP_TRAN_CRR_RESERVE         ("RESERVE     ")
#define MP_TRAN_CRR_UNRESERVE       ("UNRESERVE   ")
#define MP_TRAN_CRR_ATTACH_LOT      ("ATTACH_LOT  ")
#define MP_TRAN_CRR_DETACH_LOT      ("DETACH_LOT  ")
#define MP_TRAN_CRR_ATTACH_SUBLOT   ("ATTACH      ")
#define MP_TRAN_CRR_DETACH_SUBLOT   ("DETACH      ")
#define MP_TRAN_CRR_CHANGE_SUBLOT   ("CHANGE      ")
/**/
#define MP_TRAN_CRR_ABORT_START     ("ABORT_START ")


#define MP_TOOL_STS           ("TOOL_STS_")
#define MP_TOOL_STS_1         ("TOOL_STS_1                    ")
#define MP_TOOL_STS_2         ("TOOL_STS_2                    ")
#define MP_TOOL_STS_3         ("TOOL_STS_3                    ")
#define MP_TOOL_STS_4         ("TOOL_STS_4                    ")
#define MP_TOOL_STS_5         ("TOOL_STS_5                    ")
#define MP_TOOL_STS_6         ("TOOL_STS_6                    ")
#define MP_TOOL_STS_7         ("TOOL_STS_7                    ")
#define MP_TOOL_STS_8         ("TOOL_STS_8                    ")
#define MP_TOOL_STS_9         ("TOOL_STS_9                    ")
#define MP_TOOL_STS_10        ("TOOL_STS_10                   ")
#define MP_TOOL_STS_11        ("TOOL_STS_11                   ")
#define MP_TOOL_STS_12        ("TOOL_STS_12                   ")
#define MP_TOOL_STS_13        ("TOOL_STS_13                   ")
#define MP_TOOL_STS_14        ("TOOL_STS_14                   ")
#define MP_TOOL_STS_15        ("TOOL_STS_15                   ")
#define MP_TOOL_STS_16        ("TOOL_STS_16                   ")
#define MP_TOOL_STS_17        ("TOOL_STS_17                   ")
#define MP_TOOL_STS_18        ("TOOL_STS_18                   ")
#define MP_TOOL_STS_19        ("TOOL_STS_19                   ")
#define MP_TOOL_STS_20        ("TOOL_STS_20                   ")
#define MP_TOOL_STS_21        ("TOOL_STS_21                   ")
#define MP_TOOL_STS_22        ("TOOL_STS_22                   ")
#define MP_TOOL_STS_23        ("TOOL_STS_23                   ")
#define MP_TOOL_STS_24        ("TOOL_STS_24                   ")
#define MP_TOOL_STS_25        ("TOOL_STS_25                   ")
#define MP_TOOL_STS_26        ("TOOL_STS_26                   ")
#define MP_TOOL_STS_27        ("TOOL_STS_27                   ")
#define MP_TOOL_STS_28        ("TOOL_STS_28                   ")
#define MP_TOOL_STS_29        ("TOOL_STS_29                   ")
#define MP_TOOL_STS_30        ("TOOL_STS_30                   ")


/****************************************************/
/* GCM TABLE DATA CHECK FLAG                        */
/****************************************************/
#define MP_VALID_TBL_ALLOW          ('A')
#define MP_VALID_TBL_NOT_ALLOW      ('N')
#define MP_VALID_TBL_QUERY_RESULT   ('Q')

/****************************************************/
/* ATTRIBUTE MANAGE HISTORY KEY                     */
/****************************************************/
#define MP_ATTR_TYPE_TABLE           ("ATTRIBUTE_TYPE      ")
#define MP_ATTR_TYPE_LOT             ("LOT                 ")
#define MP_ATTR_TYPE_RESOURCE        ("RESOURCE            ")
#define MP_ATTR_TYPE_SUBLOT          ("SUBLOT              ")
#define MP_ATTR_TYPE_BOM             ("BOM                 ")
#define MP_ATTR_TYPE_MATERIAL        ("MATERIAL            ")
#define MP_ATTR_TYPE_INV_MATERIAL    ("INV_MATERIAL        ")
#define MP_ATTR_TYPE_FLOW            ("FLOW                ")
#define MP_ATTR_TYPE_OPER            ("OPER                ")
#define MP_ATTR_TYPE_FACTORY         ("FACTORY             ")
#define MP_ATTR_TYPE_CARRIER         ("CARRIER             ")
#define MP_ATTR_TYPE_ATTRIBUTE       ("ATTRIBUTE           ")
#define MP_ATTR_TYPE_SPEC            ("SPEC                ")

/****************************************************/
/* SYSTEM ATTRIBUTE DEFINITION                      */
/****************************************************/

#define MP_SYS_ATTR_BIN_HOLD_RELEASE_OPTION     ("MP_BIN_HOLD_RELEASE_OPTION")
#define MP_SYS_ATTR_BIN_HOLD_CODE               ("MP_BIN_HOLD_CODE")
#define MP_SYS_ATTR_QUEUE_TIME_HOLD_RELEASE_OPTION  ("MP_QUEUE_TIME_HOLD_RELEASE_OPTION")
#define MP_SYS_ATTR_QUEUE_TIME_HOLD_CODE            ("MP_QUEUE_TIME_HOLD_CODE")
#define MP_SYS_ATTR_QUEUE_TIME_HOLD_POINT           ("MP_QUEUE_TIME_HOLD_POINT")

/****************************************************/
/* MFO OPTION DEFINITION NAME                       */
/****************************************************/
#define MP_MFO_EXT_LOSS_TBL_DEF             ("EXT_LOSS_TBL_DEF")
#define MP_MFO_EXT_BONUS_TBL_DEF            ("EXT_BONUS_TBL_DEF")
#define MP_MFO_EXT_LOT_DEFECT_TBL           ("EXT_LOT_DEFECT_TBL")
#define MP_MFO_EXT_EXT_REWORK_TBL_DEF       ("EXT_REWORK_TBL_DEF")
#define MP_MFO_EXT_HOLD_TBL_DEF             ("EXT_HOLD_TBL_DEF")
#define MP_MFO_EXT_RELEASE_TBL_DEF          ("EXT_RELEASE_TBL_DEF")
#define MP_MFO_EXT_TERM_TBL_DEF             ("EXT_TERM_TBL_DEF")
#define MP_MFO_TRANSFER_OPER_DEF            ("TRANSFER_OPER_DEF")
#define MP_MFO_MENU_REALTION                ("MENU_RELATION")
#define MP_MFO_SUBLOT_PROCESS_OPT           ("SUBLOT_PROCESS_OPT")

/****************************************************/
/* ERROR MESSAGE CATEGORY                           */
/****************************************************/
#define MP_MSG_CATE_SUCCESS         ('S')
#define MP_MSG_CATE_WARN            ('W')
#define MP_MSG_CATE_ERROR           ('E')

/****************************************************/
/* FUTURE ACTION                                    */
/****************************************************/
#define MP_FAT_POINT_OPER_IN            ('I')
#define MP_FAT_POINT_OPER_AT            ('A')
#define MP_FAT_POINT_OPER_OUT           ('O')
#define MP_FAT_POINT_BEFORE             ('B')
#define MP_FAT_POINT_AFTER              ('A')

#define MP_FAT_ACTION_CUSTOM_ACTION                 ("CUSTOM ACTION")

#define MP_FAT_ACTION_TYPE_POSITIVE                 ('1')
#define MP_FAT_ACTION_TYPE_TRUE_FALSE               ('2')
#define MP_FAT_ACTION_TYPE_TO_FLOW_OPER_TRUE_FALSE  ('3')
#define MP_FAT_ACTION_TYPE_OPER_COUNT_TRUE_FALSE    ('4')

#define MP_FAT_COND_TYPE_LOT_STATUS                 ("LS")
#define MP_FAT_COND_TYPE_LOT_ATTRIBUTE              ("LA")
#define MP_FAT_COND_TYPE_SUBLOT_STATUS              ("SS")
#define MP_FAT_COND_TYPE_SUBLOT_ATTRIBUTE           ("SA")
#define MP_FAT_COND_TYPE_CUSTOM_CONDITION           ("CC")
#define MP_FAT_COND_TYPE_RES_STATUS                 ("RS")
#define MP_FAT_COND_TYPE_RES_ATTRIBUTE              ("RA")
#define MP_FAT_COND_TYPE_FACTORY                    ("FA")

#define MP_FAT_VALUE_TYPE_FIXED_VALUE               ("FV")
#define MP_FAT_VALUE_TYPE_GCM_TABLE                 ("GT")
#define MP_FAT_VALUE_TYPE_USER_SQL                  ("US")

/****************************************************/
/* Size Definition                                  */
/****************************************************/

/* Item Size Definition */
#define MP_SIZE_LOT_ID                              ( 25 )
#define MP_SIZE_RES_ID                              ( 20 )
#define MP_SIZE_FACTORY                             ( 10 )
#define MP_SIZE_BAY_ID                              ( 10 )
#define MP_SIZE_AREA_ID                             ( 20 )
#define MP_SIZE_CST_ID                              ( 25 )
#define MP_SIZE_MAT_ID                              ( 25 )
#define MP_SIZE_FLOW                                ( 20 )
#define MP_SIZE_OPER                                ( 10 )

#define MP_SIZE_FIELD_MSG                           ( 200 )
#define MP_SIZE_DB_ERROR_MSG                        ( 200 )

/****************************************************/
/* Call user routine shared library                 */
/****************************************************/

#define MP_UPOINT_PROLOGUE                          ( 1 )
#define MP_UPOINT_BEFORE                            ( 2 )
#define MP_UPOINT_AFTER                             ( 3 )
#define MP_UPOINT_EPILOGUE                          ( 4 )
#define MP_UPOINT_SUMMARY_LOT                       ( 5 )
#define MP_UPOINT_SUMMARY_RES                       ( 6 )
#define MP_UPOINT_SUMMARY_ATTRIBUTE                 ( 7 )
#define MP_UPOINT_GENERATE_SUBLOT                   ( 8 )
#define MP_UPOINT_SERVER_START                      ( 9 )
#define MP_UPOINT_SUMMARY_CARRIER                   ( 10 )
#define MP_UPOINT_FA_CUSTOM_ACTION                  ( 11 )
#define MP_UPOINT_FA_CUSTOM_CONDITION               ( 12 )
#define MP_UPOINT_STEP_ACTION_CUSTOM_ACTION         ( 13 )
#define MP_UPOINT_STEP_ACTION_CUSTOM_CONDITION      ( 14 )
#define MP_UPOINT_CUSTOM_MAIL_CONTENTS              ( 15 )
#define MP_UPOINT_SUMMARY_PORT                      ( 16 )

#define MP_SERVICE_CATE_SETUP                       ('S')
#define MP_SERVICE_CATE_TRAN                        ('T')
#define MP_SERVICE_CATE_INQUIRY                     ('I')

#define MP_UCOMM_FUNC_PROLOGUE                      ("UCMN_prologue")
#define MP_UCOMM_FUNC_EPILOGUE                      ("UCMN_epilogue")
#define MP_UCOMM_FUNC_SERVER_START                  ("UCMN_server_start")

#define MP_UWIP_FUNC_SUMMARY_LOT                    ("UWIP_Summary_Temp_Lot")
#define MP_URAS_FUNC_SUMMARY_RES                    ("URAS_Summary_Temp_Res")
#define MP_UBAS_FUNC_SUMMARY_ATTRIBUTE              ("UBAS_Summary_Temp_Attribute")
#define MP_URAS_FUNC_SUMMARY_CARRIER                ("URAS_Summary_Temp_Carrier")
#define MP_URAS_FUNC_SUMMARY_PORT                   ("URAS_Summary_Temp_Port")
#define MP_UWIP_FUNC_GENERATE_SUBLOT_ID             ("UWIP_Generate_Sublot_ID")

#define MP_UWIP_FUNC_FA_CUSTOM_ACTION               ("UWIP_Future_Action_Custom_Action")
#define MP_UWIP_FUNC_FA_CUSTOM_CONDITION            ("UWIP_Future_Action_Custom_Condition")

#define MP_UWEM_FUNC_STEP_ACTION_CUSTOM_ACTION      ("UWEM_Step_Action_Custom_Action")
#define MP_UWEM_FUNC_STEP_ACTION_CUSTOM_CONDITION   ("UWEM_Step_Action_Custom_Condition")

#define MP_UALM_FUNC_PROC_CUSTOM_MAIL_CONTENTS      ("UALM_Proc_Custom_Mail_Contents")

#define MP_UPOSTFIX_BEFORE                          ("_Before")
#define MP_UPOSTFIX_AFTER                           ("_After")

#define MP_USUM_TRAN_CODE_EDC_ADD                   ("EDC_ADD")
#define MP_USUM_TRAN_CODE_EDC_DEL                   ("EDC_DEL")
#define MP_USUM_TRAN_CODE_EDC_CHG                   ("EDC_CHG")

#define MP_ULIB_NAME_CMN                            ("MES_UserCMN")
#define MP_ULIB_NAME_ALM                            ("MES_UserALM")
#define MP_ULIB_NAME_BAS                            ("MES_UserBAS")
#define MP_ULIB_NAME_BOM                            ("MES_UserBOM")
#define MP_ULIB_NAME_EDC                            ("MES_UserEDC")
#define MP_ULIB_NAME_FMB                            ("MES_UserFMB")
#define MP_ULIB_NAME_INV                            ("MES_UserINV")
#define MP_ULIB_NAME_ORD                            ("MES_UserORD")
#define MP_ULIB_NAME_POP                            ("MES_UserPOP")
#define MP_ULIB_NAME_QCM                            ("MES_UserQCM")
#define MP_ULIB_NAME_RAS                            ("MES_UserRAS")
#define MP_ULIB_NAME_RCP                            ("MES_UserRCP")
#define MP_ULIB_NAME_RTD                            ("MES_UserRTD")
#define MP_ULIB_NAME_SEC                            ("MES_UserSEC")
#define MP_ULIB_NAME_SPC                            ("MES_UserSPC")
#define MP_ULIB_NAME_SVM                            ("MES_UserSVM")
#define MP_ULIB_NAME_WIP                            ("MES_UserWIP")
#define MP_ULIB_NAME_SPM                            ("MES_UserSPM")
#define MP_ULIB_NAME_WEM                            ("MES_UserWEM")



#define MP_ALARM_ACTION_USER                       ("SYSTEM_AL     ")
#define MP_FUTURE_ACTION_USER                      ("SYSTEM_FU     ")
#define MP_QUEUE_TIME_ACTION_USER                  ("SYSTEM_QU     ")
#define MP_STEP_ACTION_USER                        ("SYSTEM_SA     ")
#define MP_BIN_ACTION_USER                         ("SYSTEM_BU     ")
#define MP_SYSTEM_COMMON_USER                      ("SYSTEM_CU     ")

#define MP_BIN_DATA_1                              ("__BIN_DATA_1")
#define MP_BIN_DATA_2                              ("__BIN_DATA_2")
#define MP_BIN_DATA_3                              ("__BIN_DATA_3")
#define MP_BIN_DATA_4                              ("__BIN_DATA_4")
#define MP_BIN_DATA_5                              ("__BIN_DATA_5")
#define MP_BIN_DATA_6                              ("__BIN_DATA_6")
#define MP_BIN_DATA_7                              ("__BIN_DATA_7")
#define MP_BIN_DATA_8                              ("__BIN_DATA_8")
#define MP_BIN_DATA_9                              ("__BIN_DATA_9")
#define MP_BIN_DATA_10                             ("__BIN_DATA_10")

#define MP_KEEP_RESULT_MSG                         ("__KEEP_RESULT_MSG")
#define MP_NOTCHECK_PRIVILEGE                      ("__NOTCHECK_PRIVILEGE")


#define MP_MAX_MSG_LENGTH                          (20100100)
#define MP_DEFAULT_MSG_LENGTH                      (5100100)

#define MP_QA_SMP_TYPE_STATIC                       ( "STATIC    " )
#define MP_QA_SMP_TYPE_RANDOM                       ( "RANDOM    " )
#define MP_QA_SMP_TYPE_MANUAL                       ( "MANUAL    " )
#define MP_QA_SMP_TYPE_AQL                          ( "AQL       " )
#define MP_QA_SMP_TYPE_ALL                          ( "ALL       " )

#define MP_QA_AQL_TYPE                              ( "AQL_TYPE            " )
#define MP_QA_AQL_TBL                               ( "AQL_TBL             " )

#define MP_SMP_RULE_TYPE                            ( "SMP_RULE" )
#define MP_ACT_RULE_TYPE                            ( "ACT_RULE" )

#define MP_ACT_RULE_PASS                            ( "PASS      " )
#define MP_ACT_RULE_FAIL                            ( "FAIL      " )
#define MP_ACT_RULE_SKIP                            ( "SKIP      " )
#define MP_PASS_FLAG_DESC                           ( "Pass Count For Skip" )

#define MP_LOT_EXT_GCM_TBL                          ( "LOT_EXTENSION" )


/****************************************************/
/* BIN_RELEASE_OPTION                               */
/****************************************************/
#define MP_BIN_RELEASE_OPT_SKIP                     ("SKIP")
#define MP_BIN_RELEASE_OPT_PERMANENT                ("PERMANENT")
#define MP_BIN_RELEASE_OPT_FORCE                    ("FORCE")

/****************************************************/
/* QUEUE_TIME_RELEASE_OPTION                        */
/****************************************************/
#define MP_QUEUE_TIME_RELEASE_OPT_SKIP_POINT        ("SKIP_POINT")
#define MP_QUEUE_TIME_RELEASE_OPT_SKIP_OPER         ("SKIP_OPER")
#define MP_QUEUE_TIME_RELEASE_OPT_PERMANENT         ("PERMANENT")

/****************************************************/
/* QUEUE TIME POINT                                 */
/****************************************************/
#define MP_QUEUE_TIME_CHECK_POINT_OPER_IN       ('I')
#define MP_QUEUE_TIME_CHECK_POINT_OPER_OUT      ('O')
#define MP_QUEUE_TIME_CHECK_POINT_START         ('S')
#define MP_QUEUE_TIME_CHECK_POINT_END           ('E')

#define MP_QUEUE_TIME_FROM_POINT_OPER_IN        ('I')
#define MP_QUEUE_TIME_FROM_POINT_OPER_OUT       (' ')
#define MP_QUEUE_TIME_FROM_POINT_START          ('S')
#define MP_QUEUE_TIME_FROM_POINT_END            ('E')



/****************************************************/
/* Future Action Handler                            */
/****************************************************/
typedef int (*MES_FUTURE_ACTION_HANDLER)(char *s_msg_code,
                                         TRSNode *in_node,
                                         TRSNode *out_node);

/****************************************************/
/* Global Structure                                 */
/****************************************************/

struct log_type_tag
{
    char type;
    char e_type;
    char category;
};

/* COM_check_gcm_data, COM_check_gcm_code 함수에서 사용 */
struct key_list{
    char key_1[100];
    char key_2[100];
    char key_3[100];
    char key_4[100];
    char key_5[100];
    char key_6[100];
    char key_7[100];
    char key_8[100];
    char key_9[100];
    char key_10[100];
};

/* COM_check_gcm_data, COM_check_gcm_code 함수에서 사용 */
struct check_list{
    struct{
        char field_name[20];
        char field_value[30];
        char table_name[20];
    }list_tbl[20];
};

struct argu_list{
    struct{
        char argument[50];
    }list_tbl[20];
};

struct mfo_option_in_tag
{
    char factory[10];
    char mat_id[30];
    int mat_ver;
    char flow[20];
    char oper[10];
    char res_type[20]; /* optional value */
    char resg_id[20]; /* optional value */
    char res_id[20];
    char option_name[20]; /* optional value */
    int option_seq; /* From this sequence */
    char key_1[30]; /* optional value */
    char key_2[30]; /* optional value */
    char key_3[30]; /* optional value */
    char key_4[30]; /* optional value */
    char key_5[30]; /* optional value */
    char order_flag; /* A - Ascending, D - Descending */
    char first_last_flag; /* F - Get first one, L - Get last one , ' ' - depend on order flag */
    char base_flag; /* M - MFO -> Resource base, R - Resource -> MFO Base */
};

struct mfo_option_out_tag_data_list
{
    char option_name[20];
    int option_seq;
    char key_1[30];
    char key_2[30];
    char key_3[30];
    char key_4[30];
    char key_5[30];
    char data_1[50];
    char data_2[50];
    char data_3[50];
    char data_4[50];
    char data_5[50];
    char data_6[50];
    char data_7[50];
    char data_8[50];
    char data_9[50];
    char data_10[50];
    char data_11[50];
    char data_12[50];
    char data_13[50];
    char data_14[50];
    char data_15[50];
    char data_16[50];
    char data_17[50];
    char data_18[50];
    char data_19[50];
    char data_20[50];
};

struct mfo_option_out_tag
{
    int next_seq;
    int count;
    struct mfo_option_out_tag_data_list data[100];
};

struct channel_module_tag
{
    char s_channel[MP_SIZE_CHANNEL];
    char c_tune_mode;
    char s_allow_mod_list[50][30];
    int  i_allow_mod_count;
    unsigned short i_scheduler_weight;
    double d_heartbeat_interval;
    double d_activate_interval;
};

struct LOT_EXT_COL_INFO_TAG
{
    char s_col_name[31];
    char c_type;
};


#endif  /* _MESCORE_DEFINES_H */

