using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using CUS_COM;
using Miracom.MESCore;
using Miracom.TRSCore;
using Miracom.CliFrx;
using Miracom.DNMCore;
using System.IO;        //추가
using FarPoint.Win.Spread;

namespace CUS_WIP
{
    public partial class frmTranTransferResInfoRe : CUS_COM.frmTranForm01
    {
        public frmTranTransferResInfoRe()
        {

            InitializeComponent();
            InitControl();


        }

        #region " Constant Definition "

        private enum LOT_LIST
        {
            
            CHK,             // 0   :체크
            TRANS_MASTER_ID, // 1   :그룹ID
            LOT_ID,          //2    :LOT ID
            MASTER_LOT_ID,   //3   :마스터LOT
            ORDER_ID,
            MAT_ID,
            MAT_DESC,
            MACHINE,         //4    : 설비
            ATTRIBUTE01,     //5    :ATT1
            ATTRIBUTE02,     //6    :ATT2
            ATTRIBUTE03,     //7   :ATT3
            ATTRIBUTE04,     //8   :ATT4
            ATTRIBUTE05,     //9   :ATT5
            ATTRIBUTE06,     //10   :ATT6
            ATTRIBUTE07,     //11   :ATT7
            ATTRIBUTE08,     //12   :ATT8
            ATTRIBUTE09,     //13   :ATT9
            ATTRIBUTE10,     //14   :ATT10
            IF_YN,           //15   :IF_YN

        }

        #endregion

        #region " Variable Definition "

        public string sArea_id = "";
        public string sArea_desc = "";
        public string sSub_area_id = "";
        public string sSub_area_desc = "";
        public string sOper_id = "";
        public string sOper_desc = "";
        public string sOrder_id = "";
        string sCupOper = "";
        string s_Cup_YN = "";
        string sImpOper = "";
        string s_Imp_YN = "";

        #endregion

        #region " Function Definition "

        //form 초기화시 사용. 버튼 위치 세팅 - 버튼이 날아가는 VS에러로 인한 코딩 추가. 
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnProcess.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                dtpToWorkDate.Value = DateTime.Now;
                dtpFromWorkDate.Value = dtpToWorkDate.Value.AddDays(-1);
                txtPath.Text = Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        public static bool ViewGCMListbyKey1(Control control, string sKey1)
        {
            string sViewID = "";

            try
            {
                ListViewItem itmX;

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                sViewID = "CWIP2022-001";
                //sViewID = "CWIP4001-001";


                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "KEY_1";
                dvcArgu[1].sCondition_Value = sKey1;

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                if (dt == null)
                    return false;

                foreach (DataRow row in dt.Rows)
                {
                    if (control is ListView)
                    {
                        itmX = new ListViewItem(row["KEY_2"].ToString(), (int)SMALLICON_INDEX.IDX_KEY);

                        if (((ListView)control).Columns.Count > 1)
                        {
                            itmX.SubItems.Add(row["DATA_1"].ToString());
                        }
                        ((ListView)control).Items.Add(itmX);
                    }
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        private void SheetVisable()
        {
            switch (cdvOper.Text)
            {

                case "OC04020":  //레이저



                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ORDER_ID).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_ID).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_DESC).Visible = false;

                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;


                    spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE02, "W/O");
                    spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE03, "GRADE");


                    break;
                case "OC05060":  //라운드

                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ORDER_ID).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_ID).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_DESC).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;
                    break;
                case "OC03050":  //컵조립
                case "OC03055":  //컵조립 

                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ORDER_ID).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_ID).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_DESC).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;

                    spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE01, "RECIPE");
                    spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE02, "QTY");

                    break;
                case "OC03060":  //임팩트

                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ORDER_ID).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_ID).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_DESC).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;


                    spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE01, "RECIPE");
                    spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE02, "QTY");

                    break;
                default:
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = true;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ORDER_ID).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_ID).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_DESC).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                    spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;
                    break;

            }
        }

        private void ViewLotList()
        {
            string sViewId = "";

            try
            {



                switch (cdvOper.Text)
                {

                    case "OC04020":  //레이저



                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ORDER_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_DESC).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;


                        spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE02, "W/O");
                        spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE03, "GRADE");


                        break;
                    case "OC05060":  //라운드

                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ORDER_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_DESC).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;
                        break;
                    case "OC03050":  //컵조립
                    case "OC03055":  //컵조립 

                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ORDER_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_DESC).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;

                        spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE01, "RECIPE");
                        spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE02, "QTY");

                        break;
                    case "OC03060":  //임팩트

                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ORDER_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_DESC).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;


                        spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE01, "RECIPE");
                        spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE02, "QTY");

                        break;


                    case "OC03061":  //E-Beam컵조립

                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ORDER_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_DESC).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;


                        break;

                    default:
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ORDER_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_DESC).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;
                        break;

                }






                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;


                dvcArgu[1].sCondition_ID = "MACHINE"; //설비

                switch (cdvOper.Text)
                {

                    case "OC04020":  //레이저
                        dvcArgu[1].sCondition_Value = "CILAM002"; 
                        break;
                    case "OC05060":  //라운드
                        dvcArgu[1].sCondition_Value = "CIRUD001";
                        break;
                    case "OC03055":  //컵조립
                    case "OC03050":
                        dvcArgu[1].sCondition_Value = "CPCFM002";
                        break;
                    case "OC03060":  //임팩트
                        dvcArgu[1].sCondition_Value = "CPIMP007";
                        break;
                    case "OC03061":  //E-Beam컵조립
                        dvcArgu[1].sCondition_Value = "";
                        break;
                    default:
                        return;
                        //break;

                }



                dvcArgu[2].sCondition_ID = "FR_DATE";
                dvcArgu[2].sCondition_Value = dtpFromWorkDate.Text.Replace("-", "");

                dvcArgu[3].sCondition_ID = "TO_DATE";
                dvcArgu[3].sCondition_Value = dtpToWorkDate.Text.Replace("-", "");




                switch (cdvOper.Text)
                {
                    case "OC03061":
                    case "OC03062":
                        sViewId = "CWIP4001-004";

                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ORDER_ID).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Always;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_ID).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Restricted;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_DESC).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.Restricted;
                        break;
                    default:
                        sViewId = "CWIP4001-001";

                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ORDER_ID).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.None;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_ID).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.None;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MAT_DESC).MergePolicy = FarPoint.Win.Spread.Model.MergePolicy.None;
                        break;

                }





                if (TPDR.GetDataOne("", ref dt, sViewId, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdLotList);
                    return;
                }

                MPCF.ClearList(spdLotList);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdLotList.ActiveSheet.RowCount++;

                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].Value = false;
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.TRANS_MASTER_ID].Value = dt.Rows[i]["TRANS_MASTER_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.MASTER_LOT_ID].Value = dt.Rows[i]["MASTER_LOT_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ORDER_ID].Value = dt.Rows[i]["ORDER_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.MACHINE].Value = dt.Rows[i]["MACHINE"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE01].Value = dt.Rows[i]["ATTRIBUTE01"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE02].Value = dt.Rows[i]["ATTRIBUTE02"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE03].Value = dt.Rows[i]["ATTRIBUTE03"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE04].Value = dt.Rows[i]["ATTRIBUTE04"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE05].Value = dt.Rows[i]["ATTRIBUTE05"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE06].Value = dt.Rows[i]["ATTRIBUTE06"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE07].Value = dt.Rows[i]["ATTRIBUTE07"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE08].Value = dt.Rows[i]["ATTRIBUTE08"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE09].Value = dt.Rows[i]["ATTRIBUTE09"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE10].Value = dt.Rows[i]["ATTRIBUTE10"];
                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.IF_YN].Value = dt.Rows[i]["IF_YN"];



                    if (i != 0)
                    {
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ORDER_ID].Text == spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_LIST.ORDER_ID].Text)
                        {
                            spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ORDER_ID, i, spdLotList.ActiveSheet.ColumnCount - 1].BackColor = spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_LIST.ORDER_ID, i - 1, spdLotList.ActiveSheet.ColumnCount - 1].BackColor;
                        }
                        else
                        {
                            if (spdLotList.ActiveSheet.Cells[i - 1, (int)LOT_LIST.ORDER_ID].BackColor == Color.WhiteSmoke)
                            {
                                spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ORDER_ID, i, spdLotList.ActiveSheet.ColumnCount - 1].BackColor = Color.White;
                            }
                            else
                            {
                                spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ORDER_ID, i, spdLotList.ActiveSheet.ColumnCount - 1].BackColor = Color.WhiteSmoke;
                            }
                        }
                    }

                }

     
                switch (cdvOper.Text)
                {

                    case "OC04020":  //레이저



                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;

                        
                        spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE02, "W/O");
                        spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE03, "GRADE");


                        break;
                    case "OC05060":  //라운드

                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;
                        break;
                    case "OC03050":  //컵조립
                    case "OC03055":  //컵조립 

                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;

                        spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE01, "RECIPE");
                        spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE02, "QTY");

                        break;
                    case "OC03060":  //임팩트

                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;


                        spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE01, "RECIPE");
                        spdLotList.ActiveSheet.SetColumnLabel(0, (int)LOT_LIST.ATTRIBUTE02, "QTY");

                        break;

                    case "OC03061":  //E-Beam컵조립

                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;

                        break;

                    default:
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.CHK).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.TRANS_MASTER_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.LOT_ID).Visible = true;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MASTER_LOT_ID).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.MACHINE).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE01).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE02).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE03).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE04).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE05).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE06).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE07).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE08).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE09).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.ATTRIBUTE10).Visible = false;
                        spdLotList.ActiveSheet.Columns.Get((int)LOT_LIST.IF_YN).Visible = false;
                        break;

                }

                MPCF.FitColumnHeader(spdLotList);

                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private bool CheckOperOption(string sOper)
        {
            sCupOper = "";
            s_Cup_YN = "";
            sImpOper = "";
            s_Imp_YN = "";

            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                DataTable dt = null;
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper.Text;

                if (TPDR.GetDataOne("", ref dt, "CWIP2022-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    return false;
                }

                if (dt.Rows.Count > 0)
                {
                    sCupOper = dt.Rows[0]["CUP_OPER"].ToString();
                    s_Cup_YN = dt.Rows[0]["CUP_SEND_YN"].ToString();
                    sImpOper = dt.Rows[0]["INPECT_OPER"].ToString();
                    s_Imp_YN = dt.Rows[0]["INPECT_SEND_YN"].ToString();
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        // step 1 : standard lot 발번
        // step 2 : 설비 정보 전송
        private void SendResInfo()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[9];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                for (i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {

                    if (spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].Text.ToString().ToUpper() == "TRUE")
                    {



                        dvcArgu[0].sCondition_ID = "TRANS_ID";   
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.TRANS_MASTER_ID].Value == null)
                        {
                            dvcArgu[0].sCondition_Value = " ";
                        }
                        else
                        {
                            dvcArgu[0].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.TRANS_MASTER_ID].Value;
                        }
         

                        dvcArgu[1].sCondition_ID = "OPER";
                        if (cdvOper.Text == null)
                        {
                            dvcArgu[1].sCondition_Value = " ";
                        }
                        else
                        {
                            dvcArgu[1].sCondition_Value = cdvOper.Text;
                        }



                        dvcArgu[2].sCondition_ID = "LOT_ID";
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.LOT_ID].Value == null)
                        {
                            dvcArgu[2].sCondition_Value = " ";
                        }
                        else
                        {
                            dvcArgu[2].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.LOT_ID].Value;
                        }



                        dvcArgu[3].sCondition_ID = "ATT1";
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE01].Value == null)
                        {
                            dvcArgu[3].sCondition_Value = " ";
                        }
                        else
                        {
                            dvcArgu[3].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE01].Value;
                        }



                        dvcArgu[4].sCondition_ID = "ATT2";
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE02].Value == null)
                        {
                            dvcArgu[4].sCondition_Value = " ";
                        }
                        else
                        {
                            dvcArgu[4].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE02].Value;
                        }


                        dvcArgu[5].sCondition_ID = "ATT3";
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE03].Value == null)
                        {
                            dvcArgu[5].sCondition_Value = " ";
                        }
                        else
                        {
                            dvcArgu[5].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE03].Value;
                        }



                        dvcArgu[6].sCondition_ID = "ATT4";
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE04].Value == null)
                        {
                            dvcArgu[6].sCondition_Value = " ";
                        }
                        else
                        {
                            dvcArgu[6].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE04].Value;
                        }


                        dvcArgu[7].sCondition_ID = "ATT5";
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE05].Value == null)
                        {
                            dvcArgu[7].sCondition_Value = " ";
                        }
                        else
                        {
                            dvcArgu[7].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE05].Value;
                        }
                    

                        dvcArgu[8].sCondition_ID = "ATT6";
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE06].Value == null)
                        {
                            dvcArgu[8].sCondition_Value = " ";
                        }
                        else
                        {
                            dvcArgu[8].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE06].Value;
                        }
  

                        /*
                        dvcArgu[0].sCondition_ID = "FACTORY";
                        dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                        dvcArgu[1].sCondition_ID = "INTERFACE_TYPE";
                        dvcArgu[1].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE10].Value;

                        dvcArgu[2].sCondition_ID = "TRNAS_ID";
                        dvcArgu[2].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.TRANS_MASTER_ID].Value;


                        dvcArgu[2].sCondition_ID = "OPER";
                        dvcArgu[2].sCondition_Value = "L";

                        dvcArgu[3].sCondition_ID = "ATT1";
                        dvcArgu[3].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE01].Value;

                        dvcArgu[4].sCondition_ID = "ATT2";
                        dvcArgu[4].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE02].Value;

                        dvcArgu[5].sCondition_ID = "ATT3";
                        dvcArgu[5].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE03].Value;

                        dvcArgu[6].sCondition_ID = "ATT4";
                        dvcArgu[6].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE04].Value;

                        dvcArgu[7].sCondition_ID = "ATT5";
                        dvcArgu[7].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE05].Value;

                        dvcArgu[8].sCondition_ID = "ATT6";
                        dvcArgu[8].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE06].Value;

                        dvcArgu[9].sCondition_ID = "ATT7";
                        dvcArgu[9].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE07].Value;

                        dvcArgu[10].sCondition_ID = "ATT8";
                        dvcArgu[10].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE08].Value;

                        dvcArgu[11].sCondition_ID = "ATT9";
                        dvcArgu[11].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE09].Value;

                        dvcArgu[12].sCondition_ID = "ATT10";
                        dvcArgu[12].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.ATTRIBUTE10].Value;

                        dvcArgu[13].sCondition_ID = "IF_YN";
                        dvcArgu[13].sCondition_Value = spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.IF_YN].Value;
                        */

                        if (TPDR.GetDataOne("", ref dt, "CWIP4001-002", dvcArgu, false, false, ref sSql) == false)
                        {
                            if (dt != null)
                                dt.Dispose();

                            GC.Collect();

                        }
    
                    }

                }
                MPCF.ShowMsgBox("설비로 인터페이스 되었습니다.");

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //벨리데이션 체크
        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {

                /*
                if (MPCF.Trim(cdvDept.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblDept.Text + "]");
                    cdvDept.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvWorkPlace.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                    cdvWorkPlace.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return false;
                }

                if (MPCF.Trim(cdvOrder.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOrder.Text + "]");
                    cdvOrder.Focus();
                    return false;
                }
                */
                /*
                switch (CHECK)
                {

                    case CSGC.CHECK.NONE:

                        break;


                    case CSGC.CHECK.SAVE:

                        if (s_Cup_YN == "Y")
                        {


                        }

                        if (s_Imp_YN == "Y")
                        {

                        }

                        if (MPCF.ToInt(txtCreateQty.Text) == 0 || MPCF.Trim(txtCreateQty.Text) == "")
                        {
                            //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                            MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblCreateQty.Text + "]");
                            txtCreateQty.Focus();
                            return false;
                        }

                        break;
                }
                */
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }

        //화면 클리어
        private void ClearData(CSGC.CHECK CHECK)
        {
            try
            {
                switch (CHECK)
                {
                    case CSGC.CHECK.SAVE:


                        txtCreateQty.Text = "0";
                        MPCF.ClearList(spdLotList);

                        break;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        #region " Event Definition "

        private void frmTranTransferResInfoRe_Load(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Text = sArea_id;
                cdvDept.DisplayText = sArea_desc;
                cdvWorkPlace.Text = sSub_area_id;
                cdvWorkPlace.DisplayText = sSub_area_desc;
                cdvOper.Text = sOper_id;
                cdvOper.DisplayText = sOper_desc;
                cdvOrder.Text = sOrder_id;

                if (MPCF.Trim(cdvOper.Text) != "")
                {
                    CheckOperOption(cdvOper.Text);
                }

                if (s_Cup_YN == "Y")
                {
                    spdLotList.Enabled = false;
                }
                else
                {
                    spdLotList.Enabled = true;
                }

                if (s_Imp_YN == "Y")
                {

                }
                else
                {
                }

                txtCreateQty.Text = "0";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOrder_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                if (MPCF.Trim(cdvOper.Text) == "")
                {
                    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                    cdvOper.Focus();
                    return;
                }

                cdvOrder.Init();
                MPCF.InitListView(cdvOrder.GetListView);
                cdvOrder.Columns.Add("Order", 50, HorizontalAlignment.Left);
                cdvOrder.Columns.Add("Start_date", 50, HorizontalAlignment.Left);
                cdvOrder.Columns.Add("End_date", 50, HorizontalAlignment.Left);
                cdvOrder.SelectedSubItemIndex = 0;



                cdvOrder.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvResource_ButtonPress(object sender, EventArgs e)
        {

        }

        private void cdvResource1_ButtonPress(object sender, EventArgs e)
        {
            try
            {

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvRecipe_ButtonPress(object sender, EventArgs e)
        {
            try
            {

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvRecipe1_ButtonPress(object sender, EventArgs e)
        {
            try
            {

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvAuto_ButtonPress(object sender, EventArgs e)
        {

        }

        private void cdvOnlyCup_ButtonPress(object sender, EventArgs e)
        {
            try
            {

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvOnlyCup_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            try
            {

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_ButtonClicked(object sender, FarPoint.Win.Spread.EditorNotifyEventArgs e)
        {
            try
            {
                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (i == e.Row)
                    {
                        continue;
                    }

                    spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].Value = false;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnGen_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.NONE) == false)
                    return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnViewLotList_Click(object sender, EventArgs e)
        {
            try
            {
                ViewLotList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnProcess_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.SAVE) == false)
                    return;


                if (cdvOper.Text == "OC03061")
                {

                    txtfileSave();
                }
                else
                {
                    SendResInfo();
                }
      

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }



        private void txtCreateQty_KeyPress(object sender, KeyPressEventArgs e)
        {
            int i;

            for (i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
            {
                spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].Value = false;
            }

            for (i = spdLotList.ActiveSheet.ActiveRowIndex; i < Convert.ToInt32(txtCreateQty.Text); i++)
            {
                spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].Value = true;

            }
        }

        private void spdLotList_CellClick(object sender, FarPoint.Win.Spread.CellClickEventArgs e)
        {


            SheetView sv = spdLotList.ActiveSheet;

            try
            {
                if (e.ColumnHeader == true)
                {
                    if (sv.ColumnHeader.Cells[e.Row, e.Column].CellType is FarPoint.Win.Spread.CellType.CheckBoxCellType)
                    {
                        CSCF.CheckSpreadCell(spdLotList, e.Row, e.Column, true, true, false);
                    }
                }
                else
                {
                    if (cdvOper.Text == "OC03061")
                    {
                        CSCF.CheckSpreadCell(spdLotList, 0, 0, false, false);
                    }

                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }








            /*

            int i = 0;
            int ichkCount = 0;
            bool allChecked = false;

            if(e.Column == (int)LOT_LIST.CHK)
            {
                if(e.Row == 0)
                {
                    
                    if (e.ColumnHeader == false)
                    {
                        return;
                    }
                    

                    if (e.Column != 0)
                    {
                        return;
                    }

                    allChecked = spdLotList_Sheet1.ColumnHeader.Cells[0, 0].Value == null ? false : (bool)spdLotList_Sheet1.ColumnHeader.Cells[0, 0].Value;

                    for (i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        if(allChecked == true)
                        {
                            spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].Value = true;
                            ichkCount = ichkCount + 1;
                        }
                        else
                        {
                            spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].Value = false;
                            ichkCount = 0;
                        } 
                    }
                }
                else
                {
                    for (i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                    {
                        if (spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].Text.ToString().ToUpper() == "TRUE")
                        {
                            ichkCount = ichkCount + 1;
                        }

                      
                    }

                    CSCF.CheckSpreadCell(spdLotList, 0, 0, false, false);

                }



                txtCreateQty.Text = ichkCount.ToString();
            }
            */

        }


        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            try
            {
                MPCF.ClearList(spdLotList);
                spdLotList_Sheet1.RowCount++;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return;
            }
        }

        private void btnRowDel_Click(object sender, EventArgs e)
        {
            try
            {
                if (Convert.ToBoolean(spdLotList_Sheet1.Cells[spdLotList_Sheet1.ActiveRowIndex, (int)LOT_LIST.CHK] == null ? false : spdLotList_Sheet1.Cells[spdLotList_Sheet1.ActiveRowIndex, (int)LOT_LIST.CHK].Value))
                {
                    if (MPCF.Trim(spdLotList_Sheet1.Cells[spdLotList_Sheet1.ActiveRowIndex, (int)LOT_LIST.TRANS_MASTER_ID].Value) == "")
                    {
                        spdLotList_Sheet1.RemoveRows(spdLotList_Sheet1.ActiveRowIndex, 1);
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_KeyDown(object sender, KeyEventArgs e)
        {

            if (e.Control && e.KeyCode == Keys.V)
            {
                e.Handled = true;

                string data;
                string[] rows, cols = new string[] { };
                int rowNum, colNum;

                MPCF.ClearList(spdLotList);

                if (!Clipboard.ContainsData(DataFormats.Text)) return;

                rowNum = 0; //spdLotList_Sheet1.ActiveRowIndex;
                colNum = 1; // spdLotList_Sheet1.ActiveColumnIndex;


                data = Clipboard.GetData(DataFormats.Text) as string;
                data = data.Replace("\r\n", Convert.ToChar(13).ToString());


                rows = data.Split(new Char[] { Convert.ToChar(13) });
                for (int rowLoop = 0; rowLoop < rows.Length - 1; rowLoop++)
                {
                    spdLotList_Sheet1.RowCount++;

                    cols = rows[rowLoop].Split(new Char[] { Convert.ToChar(9) });

                    spdLotList_Sheet1.Cells[rowNum + rowLoop, (int)LOT_LIST.CHK].Value = true;
                    for (int colLoop = 0; colLoop < cols.Length; colLoop++)
                    {
                        spdLotList_Sheet1.Cells[rowNum + rowLoop, colNum + colLoop].Value = cols[colLoop];
                    }

                    spdLotList_Sheet1.SetActiveCell(rowNum + rowLoop, colNum);
                }

                spdLotList_Sheet1.ClearSelection();
                spdLotList_Sheet1.SetActiveCell(rowNum, colNum);
                spdLotList_Sheet1.AddSelection(rowNum, colNum, rows.Length - 1, cols.Length);
            }
        }


        private void cdvOper_SelectedItemChanged(object sender, Miracom.UI.MCCodeViewSelChanged_EventArgs e)
        {
            ViewLotList();
        }

        private void btnIfClear_Click(object sender, EventArgs e)
        {
            string sViewID = "";

            try
            {

                DataTable dt = null;
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[2];
                string sSql = "";

                sViewID = "CWIP4001-003";
                //sViewID = "CWIP4001-001";


                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "OPER";
                dvcArgu[1].sCondition_Value = cdvOper;

                if (TPDR.GetDataOne("", ref dt, sViewID, dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                }

                MPCF.ShowMsgBox(dt.Rows[0][0].ToString());
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void spdLotList_Change(object sender, FarPoint.Win.Spread.ChangeEventArgs e)
        {
            /*
            if (cdvOper.Text == "OC03061")
            {
                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (i == spdLotList.ActiveSheet.ActiveRowIndex)
                    {
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].Value = true;

                    }
                    else
                    {
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].Value = false;

                    }
                }
            }
            */
        }

        private void txtfileSave()
        {

            StreamWriter writer;
            // writer = File.CreateText(txtPath.Text + "/" + "writeTest.txt");        //Text File이 저장될 위치(파일명)

            File.Delete(txtPath.Text + "/" + "eBeam.txt");

            writer = File.AppendText(txtPath.Text + "/" + "eBeam.txt");        //Text File이 저장될 위치(파일명)

            for (int i = 0; i < spdLotList_Sheet1.RowCount; i++)
            {
                if (spdLotList_Sheet1.Cells[i, (int)LOT_LIST.CHK].Value.ToString().ToUpper() == "TRUE")
                {

                    //  writer.WriteLine(MPCF.Trim(spdLotList_Sheet1.Cells[i, (int)LOT_INFO.LOT_ID].Text) + "\r\n");
                    writer.WriteLine(MPCF.Trim(spdLotList_Sheet1.Cells[i, (int)LOT_LIST.ATTRIBUTE01].Text));
                    writer.WriteLine(MPCF.Trim(spdLotList_Sheet1.Cells[i, (int)LOT_LIST.ATTRIBUTE02].Text));
                    writer.WriteLine(MPCF.Trim(spdLotList_Sheet1.Cells[i, (int)LOT_LIST.ATTRIBUTE03].Text));
                    writer.WriteLine(MPCF.Trim(spdLotList_Sheet1.Cells[i, (int)LOT_LIST.ATTRIBUTE04].Text));
                    writer.WriteLine(MPCF.Trim(spdLotList_Sheet1.Cells[i, (int)LOT_LIST.ATTRIBUTE05].Text));
                    writer.WriteLine(MPCF.Trim(spdLotList_Sheet1.Cells[i, (int)LOT_LIST.ATTRIBUTE06].Text));
                    writer.WriteLine(MPCF.Trim(spdLotList_Sheet1.Cells[i, (int)LOT_LIST.ATTRIBUTE07].Text));
                    writer.WriteLine(MPCF.Trim(spdLotList_Sheet1.Cells[i, (int)LOT_LIST.ATTRIBUTE08].Text));
                    writer.WriteLine(MPCF.Trim(spdLotList_Sheet1.Cells[i, (int)LOT_LIST.ATTRIBUTE09].Text));

                }
            }

            writer.Close();

        }

        private void spdLotList_TextChanged(object sender, EventArgs e)
        {
            /*
            if (cdvOper.Text == "OC03061")
            {
                for (int i = 0; i < spdLotList.ActiveSheet.RowCount; i++)
                {
                    if (i == spdLotList.ActiveSheet.ActiveRowIndex)
                    {
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].Value = true;

                    }
                    else
                    {
                        spdLotList.ActiveSheet.Cells[i, (int)LOT_LIST.CHK].Value = false;

                    }
                }
            }
            */
        }
        #endregion


    }
}
