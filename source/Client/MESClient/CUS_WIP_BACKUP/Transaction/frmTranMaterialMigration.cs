using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Reflection;

using Miracom.CliFrx;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.DNMCore;

using CUS_COM;
using System.IO;
using System.Diagnostics;

namespace CUS_WIP
{
    public partial class frmTranMaterialMigration : CUS_COM.frmViewForm01
    {
        public frmTranMaterialMigration()
        {
            InitializeComponent();
        }

        private enum INV
        {
            SEL,
            LOT_ID,
            MAT_ID,
            QTY,
            OPER,
            VENDOR,
            VENDOR_SITE_ID,
            VENDOR_LOT_ID,
            PROC_STATUS
        }

        private enum WIP
        {
            SEL,
            LOT_ID,
            MAT_ID,
            QTY,
            OPER,
            WO,
            PROC_STATUS
        }

        private enum S_G
        {
            SEL,
            LOT_ID,
            MAT_ID,
            QTY,
            OPER,
            LOT_SEQ,
            WH_CODE,
            PROC_STATUS
        }

        private enum F_G
        {
            SEL,
            LOT_ID,
            MAT_ID,
            QTY,
            OPER,
            PROC_STATUS
        }

        private enum OUTGOING
        {
            SEL,
            LOT_ID,
            MAT_ID,
            QTY,
            OPER,
            PROC_STATUS
        }

        /// <summary>
        /// Lot 생성
        /// </summary>
        /// <returns></returns>
        private bool Create_Lot()
        {
            TRSNode in_node = new TRSNode("Inventory_Survey_In");
            TRSNode out_node = new TRSNode("Inventory_Survey_Out");

            int i = 0, j = 0;
            int iMatCnt = 0, iWipCnt = 0, iProdCnt = 0, iOutGoingCnt = 0;
            int iCol = 0;

            try
            {
                if(spdLotList_Material.RowCount == 0 && spdLotList_WIP.RowCount == 0 &&  spdLotList_Semi_Goods.RowCount == 0 && spdLotList_Finished_Goods.RowCount == 0)
                {
                    // CMN463 INFO  - 처리할 데이터가 없습니다. Excel Upload 후 다시 하세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(463));
                    return false;
                }

                for (j = 0; j < 4; j++)
                {
                    if (spdLotList.Sheets[j].RowCount > 0)
                    {
                        for (i = 0; i < spdLotList.Sheets[j].RowCount; i++)
                        {
                            if (Convert.ToBoolean(spdLotList.Sheets[j].Cells[i, 0].Value))
                            {
                                spdLotList.ActiveSheet = spdLotList.Sheets[j];
                                
                                if (j == 0)
                                    iMatCnt++;
                                else if (j == 1)
                                    iWipCnt++;
                                else if (j == 2)
                                    iProdCnt++;
                                else if (j == 3)
                                    iOutGoingCnt++;
                            }
                        }
                    }
                }

                if(iMatCnt + iWipCnt + iProdCnt + iOutGoingCnt == 0)
                {
                    // CMN199 ERROR - 선택된 Lot이 없습니다. 먼저 Lot을 선택하여 주세요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(199));
                    return false;
                }

                for (j = 0; j < 5; j++)
                {
                    if (j == 0)
                        iCol = (int)INV.PROC_STATUS;
                    else if(j == 1)
                        iCol = (int)WIP.PROC_STATUS;
                    else if(j == 2)
                        iCol = (int)S_G.PROC_STATUS;
                    else
                        iCol = (int)F_G.PROC_STATUS;

                    if (spdLotList.Sheets[j].RowCount > 0)
                    {
                        spdLotList.ActiveSheet = spdLotList.Sheets[j];

                        for (i = 0; i < spdLotList.Sheets[j].RowCount; i++)
                        {
                            if (Convert.ToBoolean(spdLotList.Sheets[j].Cells[i, (int)F_G.SEL].Value))
                            {
                                in_node.Init();
                                MPCR.SetInMsg(in_node);

                                // 1 : 자재
                                // 2 : 재공
                                // 3 : 반제품
                                // 4 : 완제품
                                // 5 : 출하대기
                                in_node.ProcStep =  MPCF.ToChar(j + 1);

                                in_node.AddString("LOT_ID", spdLotList.Sheets[j].Cells[i, (int)F_G.LOT_ID].Value);
                                in_node.AddString("MAT_ID", spdLotList.Sheets[j].Cells[i, (int)F_G.MAT_ID].Value);
                                in_node.AddDouble("QTY", spdLotList.Sheets[j].Cells[i, (int)F_G.QTY].Value);
                                in_node.AddString("OPER", spdLotList.Sheets[j].Cells[i, (int)F_G.OPER].Value);

                                // 자재일때
                                if(in_node.ProcStep == '1')
                                {
                                    in_node.AddString("VENDOR_ID", spdLotList.Sheets[j].Cells[i, (int)INV.VENDOR].Value);
                                    in_node.AddString("VENDOR_SITE_ID", spdLotList.Sheets[j].Cells[i, (int)INV.VENDOR_SITE_ID].Value);
                                    in_node.AddString("VENDOR_LOT_ID", spdLotList.Sheets[j].Cells[i, (int)INV.VENDOR_LOT_ID].Value);
                                }
                                else if(in_node.ProcStep == '2')
                                {
                                    in_node.AddString("ORDER_ID", spdLotList.Sheets[j].Cells[i, (int)WIP.WO].Value);
                                }
                                else if(in_node.ProcStep == '3')
                                {
                                    in_node.AddInt("LOT_SEQ", spdLotList.Sheets[j].Cells[i, (int)S_G.LOT_SEQ].Value);
                                    in_node.AddString("WH_CODE", spdLotList.Sheets[j].Cells[i, (int)S_G.WH_CODE].Value);
                                }

                                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Create_Stock_In_Oper", in_node, ref out_node, true) == false)
                                {
                                    spdLotList.Sheets[j].Cells[i, iCol].Value = out_node.GetString(TRSDefine.OUT_MSG);
                                }
                                else
                                {
                                    spdLotList.Sheets[j].Cells[i, iCol].Value = MPCF.FindLanguage("SUCCESS", 0);
                                    spdLotList.Sheets[j].Cells[i, 0].Value = false;
                                }

                                CSCF.SetPosition(spdLotList, i, 0);
                            }
                        }
                    }
                }

                MPCF.ShowMsgBox(MPCF.GetMessage(52));

                return true;
            }
            catch (Exception ex)
            {

                MPCF.ShowMsgBox($"Create_Lot() : {ex.Message}");
                return false;
            }
        }

        /// <summary>
        /// Legacy System의 자재 조회
        /// </summary>
        /// <returns></returns>
        private bool View_Raw_Material()
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                spdLotList_Material.RowCount = 0;
                if (TPDR.GetDataOne("", ref dt, "CWIP2023-001", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                spdLotList_Material.RowCount = dt.Rows.Count;
                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Material.Cells[i, (int)INV.SEL].Value = false;
                    spdLotList_Material.Cells[i, (int)INV.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Material.Cells[i, (int)INV.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Material.Cells[i, (int)INV.QTY].Value = dt.Rows[i]["LOT_QTY"];
                    spdLotList_Material.Cells[i, (int)INV.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotList_Material.Cells[i, (int)INV.VENDOR].Value = dt.Rows[i]["VENDOR_ID"];
                    spdLotList_Material.Cells[i, (int)INV.VENDOR_SITE_ID].Value = dt.Rows[i]["VENDOR_SITE_ID"];
                    spdLotList_Material.Cells[i, (int)INV.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                }

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        /// <summary>
        /// 재공 Lot 조회
        /// </summary>
        /// <returns></returns>
        private bool View_WIP()
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                spdLotList_WIP.RowCount = 0;

                if (TPDR.GetDataOne("", ref dt, "CWIP2023-002", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                spdLotList_WIP.RowCount = dt.Rows.Count;

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_WIP.Cells[i, (int)WIP.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_WIP.Cells[i, (int)WIP.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_WIP.Cells[i, (int)WIP.QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_WIP.Cells[i, (int)WIP.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotList_WIP.Cells[i, (int)WIP.WO].Value = dt.Rows[i]["ORDER_ID"];
                }

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        /// <summary>
        /// 반제품 조회
        /// </summary>
        /// <returns></returns>
        private bool View_Semi_Goods()
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                spdLotList_Semi_Goods.RowCount = 0;

                if (TPDR.GetDataOne("", ref dt, "CWIP2023-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                spdLotList_Semi_Goods.RowCount = dt.Rows.Count;

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Semi_Goods.Cells[i, (int)S_G.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Semi_Goods.Cells[i, (int)S_G.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Semi_Goods.Cells[i, (int)S_G.QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_Semi_Goods.Cells[i, (int)S_G.OPER].Value = dt.Rows[i]["OPER"];
                    spdLotList_Semi_Goods.Cells[i, (int)S_G.LOT_SEQ].Value = dt.Rows[i]["LOT_SEQ"];
                    spdLotList_Semi_Goods.Cells[i, (int)S_G.WH_CODE].Value = dt.Rows[i]["WH_CODE"];
                }

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        /// <summary>
        /// 완제품 창고 Lot 조회
        /// </summary>
        /// <returns></returns>
        private bool View_Product()
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                spdLotList_Finished_Goods.RowCount = 0;
                if (TPDR.GetDataOne("", ref dt, "CWIP2023-004", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                spdLotList_Finished_Goods.RowCount = dt.Rows.Count;

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Finished_Goods.Cells[i, (int)F_G.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Finished_Goods.Cells[i, (int)F_G.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Finished_Goods.Cells[i, (int)F_G.QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_Finished_Goods.Cells[i, (int)F_G.OPER].Value = dt.Rows[i]["OPER"];
                }

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        /// <summary>
        /// 출하대기 Lot 조회
        /// </summary>
        /// <returns></returns>
        private bool View_Outgoing()
        {
            TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[1];
            DataTable dt = null;
            string sSql = "";
            int i = 0;

            try
            {
                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                spdLotList_Outgoing.RowCount = 0;
                if (TPDR.GetDataOne("", ref dt, "CWIP2023-005", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    return false;
                }

                spdLotList_Outgoing.RowCount = dt.Rows.Count;

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList_Outgoing.Cells[i, (int)OUTGOING.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList_Outgoing.Cells[i, (int)OUTGOING.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList_Outgoing.Cells[i, (int)OUTGOING.QTY].Value = dt.Rows[i]["QTY"];
                    spdLotList_Outgoing.Cells[i, (int)OUTGOING.OPER].Value = dt.Rows[i]["OPER"];
                }

                return true;
            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
                return false;
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            // 원자재 Lot 조회
            View_Raw_Material();

            // 재공 조회
            View_WIP();

            // 반제품 조회
            View_Semi_Goods();

            // 완제품 창고 조회
            View_Product();

            // 출하대기 창고 조회
            View_Outgoing();
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            Create_Lot();
        }

        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {
            if(e.ColumnHeader)
            {
                if(e.Column == 0)
                {
                    CSCF.CheckSpreadCell(spdLotList, 0, 0, true, true);
                }
            }
        }
    }
}
