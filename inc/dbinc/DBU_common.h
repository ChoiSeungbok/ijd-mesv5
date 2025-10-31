#ifndef _DBU_COMMON_LOADED
#define _DBU_COMMON_LOADED

#include <DBC_common.h> 
#include <dbu_q_cond_n.h>

struct DBU_Q_COND_TAG {
    char FROM_DATE[8];
    char TO_DATE[8];
    char FROM_TIME[14];
    char TO_TIME[14];
    char MAT_TYPE[20];
    char MAT_GRP[20];
    char RES_ID[20];
    char OPER[10];
    char SPC_SUMMARY_KEY[12];
    int FROM_SEQ;
    int TO_SEQ;    
    int PRIO_LEVEL;
    char PRIO_KEY[20];
    char ERR_MSG[200];

    char KEY_1[50];
    char KEY_2[50];
    char KEY_3[50];
    char KEY_4[50];
    char KEY_5[50];
    char KEY_6[50];
    char KEY_7[50];
    char KEY_8[50];
    char KEY_9[50];
    char KEY_10[50];
    char KEY_11[50];
    char KEY_12[50];
    char KEY_13[50];
    char KEY_14[50];
    char KEY_15[50];
    char KEY_16[50];
    char KEY_17[50];
    char KEY_18[50];
    char KEY_19[50];
    char KEY_20[50];
    char KEY_21[50];
    char KEY_22[50];
    char KEY_23[50];
    char KEY_24[50];
    char KEY_25[50];
    char KEY_26[50];
    char KEY_27[50];
    char KEY_28[50];
    char KEY_29[50];
    char KEY_30[50];

    int NUM_1;
    int NUM_2;
    int NUM_3;
    int NUM_4;
    int NUM_5;
    int NUM_6;
    int NUM_7;
    int NUM_8;
    int NUM_9;
    int NUM_10;
    int NUM_11;
    int NUM_12;
    int NUM_13;
    int NUM_14;
    int NUM_15;
};

extern struct DBU_Q_COND_TAG DBU_Q_COND;

extern void DBU_init_condition(struct DBU_Q_COND_TAG *DBU_Q_COND);
extern void DBU_add_null_condition(struct DBU_Q_COND_TAG *DBU_Q_COND, struct DBU_Q_COND_N_TAG *DBU_Q_COND_N);
extern void DBU_del_null_condition(struct DBU_Q_COND_TAG *DBU_Q_COND, struct DBU_Q_COND_N_TAG *DBU_Q_COND_N);

extern void DBU_get_date(int iValue, char *sDate);

//Custom BOM Fuction

#include "DBU_cbascptdef.h"
#include "DBU_crassprsts.h"
#include "DBU_mwiplotstsx.h"
#include "DBU_mwiplothisx.h"
#include "DBU_mwipoprdef.h"
#include "DBU_mwipmatdef.h"
#include "DBU_mrasresdef.h"
#include "DBU_mrasreshis.h"
#include "DBU_mrasresmfo.h"
#include "DBU_mrastoldef.h"
#include "DBU_mwipflwdef.h"
#include "DBU_mwipflwopr.h"
#include "DBU_mwipmatflw.h"
#include "DBU_crasrprsts.h"
#include "DBU_crasrprspr.h"
#include "DBU_crasrprwrk.h"
#include "DBU_mwipordsts.h"
#include "DBU_cwiperpopr.h"
#include "DBU_cwipoprwrk.h"
#include "DBU_cwipordbom.h"
#include "DBU_cwipwrkdef.h"
#include "DBU_cwipwrkgrp.h"
#include "DBU_cwiplotlst.h"
#include "DBU_minvdlvdtl.h"
#include "DBU_minvdlvmst.h"
#include "DBU_minvlothis.h"
#include "DBU_minvlothld.h"
#include "DBU_minvlotiss.h"
#include "DBU_minvlotmvh.h"
#include "DBU_minvlotsts.h"
#include "DBU_minvlotswh.h"
#include "DBU_minvmatiss.h"
#include "DBU_minvreqdtl.h"
#include "DBU_minvreqmst.h"
#include "DBU_mgcmtbldat.h"
#include "DBU_mgcmtbldef.h"
#include "DBU_minvdlvlbl.h"
#include "DBU_minvdlvlot.h"
#include "DBU_mwipcoldef.h"
#include "DBU_cwipinvlod.h"
#include "DBU_cbasfildef.h"
#include "DBU_cwiplotmvm.h"
#include "DBU_cwiplotmvc.h"
#include "DBU_cwiplotmvr.h"
#include "DBU_minvreqlot.h"
#include "DBU_cwipdwnsts.h"
#include "DBU_cwipgrpsts.h"
#include "DBU_cwipgrplot.h"
#include "DBU_cpakordsts.h"
#include "DBU_cpaklotsts.h"
#include "DBU_cshpordmst.h"
#include "DBU_cshporddtl.h"
#include "DBU_cretordsts.h"
#include "DBU_crasdspreq.h"
#include "DBU_crasdsptol.h"
#include "DBU_cbaschkdef.h"
#include "DBU_medclotdat.h"
#include "DBU_medccolver.h"
#include "DBU_medccolchr.h"
#include "DBU_medccoldef.h"
#include "DBU_medcchrdef.h"
#include "DBU_medcresdat.h"
#include "DBU_cqcmispsts.h"
#include "DBU_cqcmispcol.h"
#include "DBU_cqcmispdat.h"
#include "DBU_cqcmisplos.h"
#include "DBU_cqcmispwrk.h"
#include "DBU_if_po_rcv_header.h"
#include "DBU_if_po_rcv_txns.h"
#include "DBU_if_po_rcv_txn_lots.h"
#include "DBU_if_inv_txns.h"
#include "DBU_if_inv_txn_lots.h"
#include "DBU_if_move_trx.h"
#include "DBU_if_move_trx_save.h"
#include "DBU_if_completion_trx.h"
#include "DBU_if_completion_trx_save.h"
#include "DBU_if_comp_issue_trx.h"
#include "DBU_if_comp_issue_trx_save.h"
#include "DBU_if_om_txns.h"
#include "DBU_if_om_txn_lots.h"
#include "DBU_if_om_ship_headers.h"
#include "DBU_if_om_ship_lines.h"
#include "DBU_if_om_ship_line_lots.h"
#include "DBU_if_po_rma_headers.h"
#include "DBU_if_po_rma_txns.h"
#include "DBU_if_po_rma_txn_lots.h"
#include "DBU_if_om_promise_date.h"
#include "DBU_if_std_bom_def.h"
#include "DBU_if_uom_conv_def.h"
#include "DBU_if_mat_def.h"
#include "DBU_if_vendor_def.h"
#include "DBU_if_customer_def.h"
#include "DBU_if_wh_def.h"
#include "DBU_if_sub_area_def.h"
#include "DBU_if_txn_type_def.h"
#include "DBU_if_po_info.h"
#include "DBU_if_wo_bom_info.h"
#include "DBU_if_wo_info.h"
#include "DBU_if_so_mst.h"
#include "DBU_if_so_dtl.h"
#include "DBU_if_ro_info.h"
#include "DBU_if_po_consign_txns.h"
#include "DBU_cwipgrtcss.h"
#include "DBU_cwipgrtbld.h"
#include "DBU_if_customer_def_his.h"
#include "DBU_if_mat_def_his.h"
#include "DBU_if_po_info_his.h"
#include "DBU_if_ro_info_his.h"
#include "DBU_if_so_dtl_his.h"
#include "DBU_if_so_mst_his.h"
#include "DBU_if_std_bom_def_his.h"
#include "DBU_if_sub_area_def_his.h"
#include "DBU_if_txn_type_def_his.h"
#include "DBU_if_uom_conv_def_his.h"
#include "DBU_if_vendor_def_his.h"
#include "DBU_if_wh_def_his.h"
#include "DBU_if_wo_bom_info_his.h"
#include "DBU_if_wo_info_his.h"
#include "DBU_if_pack_info.h"
#include "DBU_if_pack_info_his.h"
#include "DBU_if_p_wo_info.h"
#include "DBU_if_p_wo_info_his.h"
#include "DBU_if_po_requests_receipts.h"
#include "DBU_cwiplotcum.h"
#include "DBU_cwiplotdry.h"
#include "DBU_csecusedat.h"
#include "DBU_cwipgrtcls.h"
#include "DBU_cbastxndef.h"
#include "DBU_cqcmgrtsiv.h"
#include "DBU_cqcmgrthlt.h"
#include "DBU_cqcmgrtcot.h"
#include "DBU_mwipcaldef.h"
#include "DBU_cqcmgrtasp.h"
#include "DBU_cwiplotprs.h"
#include "DBU_cordprdpln.h"
#include "DBU_cwiprcpdef.h"

#include "DBU_cretlotsts.h"
#include "DBU_cwiplotrim.h"
#include "DBU_cwiplotrnd.h"
#include "DBU_cwiplotimp.h"
#include "DBU_cwiplotcup.h"
#include "DBU_cwiplotlmk.h"

#include "DBU_cwiplotcls.h"
#include "DBU_cwiplottrc.h"
#include "DBU_cwiplotbas.h"

#include "DBU_cwipordrwk.h"
#include "DBU_cbomstddef.h"

#include "DBU_ct_sal110t.h"
#include "DBU_ct_packing_v.h" 
#include "DBU_csumlotdat.h"
#include "DBU_mwiplotlos.h"
#include "DBU_cbaslbldat.h"
#include "DBU_cqcmrptctm.h"
#include "DBU_cqcmrpthmm.h"
#include "DBU_cbastaktim.h"
#include "DBU_minvmovsts.h"
#include "DBU_minvmovlot.h"

#include "DBU_cqcmrptgnp.h"
#include "DBU_cqcmrptgny.h"
#include "DBU_cqcmrptgrn.h"
#include "DBU_csumreswip.h"
#include "DBU_cwipprsrun.h"
#include "DBU_cwipuoplot.h"
#include "DBU_ct_mtl510t.h"
#include "DBU_mwipidghis.h"
#include "DBU_cqcmrptgrm.h"
#include "DBU_cqcmrptgmp.h"

#include "DBU_cwipordopr.h"
#include "DBU_cqcmcstspm.h"
#include "DBU_cwipinvldm.h"
#include "DBU_cqcmcstspg.h"
#include "DBU_mgcmlagdat.h" 
#include "DBU_cwipprdgol.h"
#include "DBU_batch_job.h"
#include "DBU_mrastevdef.h"
#include "DBU_esecusrdef.h"
#include "DBU_ct_mtl100t.h"
#include "DBU_cwiplotrec.h"
#include "DBU_ct_prd210t.h"
#include "DBU_ct_prd200t.h"
#include "DBU_ct_mold_v.h"
#include "DBU_cinvuoplot.h"
#include "DBU_cwipwrkinp.h"


#include "DBU_minvetclot.h"
#include "DBU_cwiplotchg.h"
#include "DBU_cpaklothis.h"
#include "DBU_ishplotiss.h"
#include "DBU_ishplotrcv.h"
#include "DBU_cwipbldavg.h"
#include "DBU_crasbasdat.h"
#include "DBU_cbasshpbom.h"
#include "DBU_crastolbrk.h"
#include "DBU_mrastolhis.h"
#include "DBU_cwippryer.h"
#include "DBU_ishpispiss.h"
#include "DBU_ishpisprcv.h"
#include "DBU_crashitfnc.h"
#include "DBU_cerpaststs.h"

#include "DBU_crasmdextd.h"
#include "DBU_crasvcmfnc.h"
#include "DBU_cras5thprs.h"
#include "DBU_cras4hrprs.h"
#include "DBU_craspntmix.h"
#include "DBU_crasbalmil.h"
#include "DBU_crasbalmil.h"

#include "DBU_cqcmcplmst.h"
#include "DBU_cqcmsplmst.h"
#include "DBU_cqcmvocmst.h"
#include "DBU_cqcmcusspe.h"

#include "DBU_cwiplotrmk.h"
#include "DBU_csecusrdef.h"



#endif
