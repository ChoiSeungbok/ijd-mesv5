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
using FarPoint.Win.Spread;
using System.IO;
using System.Net;

namespace CUS_QCM
{
    public partial class frmViewInspectionDataGritMp : CUS_COM.frmViewForm01
    {

        public string ftpUser = "";
        public string ftpPassword = "";
        public string ftpServer = "FTP://197.200.11.142:10024" + "/LOT"; // FTP 서버 주소


        public frmViewInspectionDataGritMp()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "
        private enum LOT_INFO
        {
            INSP_REQ_TIME,
            JUDGE_DATE,
            RECEIPT_TIME,
            INSP_STATUS,
            LOT_ID,
            VENDOR_LOT_ID,
            DETAIL,
            IMG,
            GRADE,
            SIZES,
            QTY,
            INSP_JUDGE_DESC,
            INSP_OPER,
            INSP_OPER_DESC,
            MAT_ID,
            MAT_DESC,


            //220220620 추가
            PSD_COUNT,
            TI_COUNT,
            TTI_COUNT,
            HLF_COUNT,

            O_CON_VALUE,   //O 함량
            GOQC203,          //진밀도




            WT_TOTAL,
            WT_TI,
            WT_NI,

            EDS_P,
            EDS_NI,

            MEAN, 
            SD,
            PSD_D5,
            PSD_D50,
            PSD_D95,
            PSD_LP,
            
            COATING_PSD_D5,
            COATING_PSD_D50,
            COATING_PSD_D95,
            COATING_PSD_LP,


            MICR_MEAN,
            MICR_SD,
            MICR_PSD_D5,
            MICR_PSD_D50,
            MICR_PSD_D95,
            MICR_PSD_LP,
            CPS_MEAN,
            CPS_SD,
            CPS_PSD_D5,
            CPS_PSD_D50,
            CPS_PSD_D95,
            CPS_PSD_LP,






            ASPECT_RATIO,
            CIRCULARITY,
            ROUGHNESS,
            SYMMETRY,






            INSP_COMMENT,

            LOSS_GBAD028,
            LOSS_GBAD029,
            LOSS_GBAD030,
            LOSS_GBAD031,
            LOSS_GBAD032,
            LOSS_GBAD033,
            LOSS_GBAD034,
            LOSS_GBAD035,
            LOSS_GBAD036,
            LOSS_GBAD037,
            LOSS_GBAD038,
            LOSS_GBAD039,
            LOSS_GBAD040,
            LOSS_GBAD041,
            LOSS_GBAD042,
            LOT_CREATE_USER,
            LOT_JUDGE_USER


        }
        #endregion

        #region " Function Definition"
        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnFileManager.Anchor = AnchorStyles.Top | AnchorStyles.Right;

                if (MPCF.GetRegSetting(System.Windows.Forms.Application.ProductName, this.Name, chkFTPFile.Name) == "Y")
                {
                    chkFTPFile.Checked = true;
                }
                else
                {
                    chkFTPFile.Checked = false;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void ViewInspectionDataList()
        {
            try
            {
                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[12];
                DataTable dt = null;
                string sSql = "";
                int i = 0;

                string strFromJudgeDate = "";
                string strToJudgeDate = "";
                string strFromInspReqTime = "";
                string strToInspReqTime = "";


                FarPoint.Win.Spread.CellType.ButtonCellType buttonCellType1 = new FarPoint.Win.Spread.CellType.ButtonCellType();
                buttonCellType1.ButtonColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
                buttonCellType1.ButtonColor2 = System.Drawing.SystemColors.ButtonFace;
                buttonCellType1.Text = "Click";
                buttonCellType1.UseVisualStyleBackColor = false;

                if (rdoJudge.Checked)
                {
                    strFromJudgeDate = string.IsNullOrEmpty(dtpFromJudgeDate.Text.Trim()) ? "19000101" : dtpFromJudgeDate.Text.Replace("-", "");
                    strToJudgeDate = dtpToJudgeDate.Text.Replace("-", "");

                    strFromInspReqTime = "19000101";
                    strToInspReqTime = "29990101";
                }
                else
                {
                    strFromJudgeDate = "";
                    strToJudgeDate = "29990101";

                    strFromInspReqTime = string.IsNullOrEmpty(dtpFromJudgeDate.Text.Trim()) ? "19000101" : dtpFromJudgeDate.Text.Replace("-", "");
                    strToInspReqTime = dtpToJudgeDate.Text.Replace("-", "");
                }

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FROM_JUDGE_DATE";
                dvcArgu[1].sCondition_Value = strFromJudgeDate;

                dvcArgu[2].sCondition_ID = "TO_JUDGE_DATE";
                dvcArgu[2].sCondition_Value = strToJudgeDate;

                dvcArgu[3].sCondition_ID = "FROM_INSP_REQ_DATE";
                dvcArgu[3].sCondition_Value = strFromInspReqTime;

                dvcArgu[4].sCondition_ID = "TO_INSP_REQ_DATE";
                dvcArgu[4].sCondition_Value = strToInspReqTime;

                dvcArgu[5].sCondition_ID = "MAT_DESC";
                dvcArgu[5].sCondition_Value = "%" + txtMatDesc.Text + "%";

                dvcArgu[6].sCondition_ID = "LOT_ID";
                dvcArgu[6].sCondition_Value = txtLotID.Text + "%";

                dvcArgu[7].sCondition_ID = "INSP_STATUS";
                dvcArgu[7].sCondition_Value = cdvStatus.Text + "%";

                dvcArgu[8].sCondition_ID = "INSP_OPER";
                dvcArgu[8].sCondition_Value = cdvOper.Text + "%";

                dvcArgu[9].sCondition_ID = "INSP_TYPE";
                dvcArgu[9].sCondition_Value = cdvInspectionType.Text + "%";

                dvcArgu[10].sCondition_ID = "GRADE";
                dvcArgu[10].sCondition_Value = "%" + txtGrade.Text + "%";

                dvcArgu[11].sCondition_ID = "SIZE";
                dvcArgu[11].sCondition_Value =  txtSize.Text;

                if (TPDR.GetDataOne("", ref dt, "CQCM3007-003", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();

                    MPCF.ClearList(spdInspectionData);
                    return;
                }

                MPCF.ClearList(spdInspectionData);

                for (i = 0; i < dt.Rows.Count; i++)
                {
                    spdInspectionData.ActiveSheet.RowCount++;


                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_REQ_TIME].Value = dt.Rows[i]["INSP_REQ_TIME"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.JUDGE_DATE].Value = dt.Rows[i]["JUDGE_DATE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.RECEIPT_TIME].Value = dt.Rows[i]["RECEIPT_TIME"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_STATUS].Value = dt.Rows[i]["INSP_STATUS"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].Value = dt.Rows[i]["LOT_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.VENDOR_LOT_ID].Value = dt.Rows[i]["VENDOR_LOT_ID"];
                    　

                    if (dt.Rows[i]["IMG_REG_YN"].ToString() == "Y")
                    {
                        this.spdInspectionData_Sheet1.Cells.Get(i, (int)LOT_INFO.IMG).CellType = buttonCellType1;
                    }


                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.GRADE].Value = dt.Rows[i]["GRADE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SIZES].Value = dt.Rows[i]["SIZES"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.QTY].Value = dt.Rows[i]["QTY"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_JUDGE_DESC].Value = dt.Rows[i]["INSP_JUDGE_DESC"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_OPER].Value = dt.Rows[i]["INSP_OPER"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_OPER_DESC].Value = dt.Rows[i]["INSP_OPER_DESC"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_ID].Value = dt.Rows[i]["MAT_ID"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MAT_DESC].Value = dt.Rows[i]["MAT_DESC"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.PSD_COUNT].Value = dt.Rows[i]["PSD_COUNT"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.TI_COUNT].Value = dt.Rows[i]["TI_COUNT"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.TTI_COUNT].Value = dt.Rows[i]["TTI_COUNT"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.HLF_COUNT].Value = dt.Rows[i]["HLF_COUNT"];


                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.O_CON_VALUE].Value = dt.Rows[i]["O_CON_VALUE"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.GOQC203].Value = dt.Rows[i]["GOQC203"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.WT_TOTAL].Value = dt.Rows[i]["WT_TOTAL"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.WT_TI].Value = dt.Rows[i]["WT_TI"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.WT_NI].Value = dt.Rows[i]["WT_NI"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.EDS_P].Value = dt.Rows[i]["EDS_P"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.EDS_NI].Value = dt.Rows[i]["EDS_NI"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MEAN].Value = dt.Rows[i]["MEAN"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SD].Value = dt.Rows[i]["SD"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.PSD_D5].Value = dt.Rows[i]["PSD_D5"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.PSD_D50].Value = dt.Rows[i]["PSD_D50"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.PSD_D95].Value = dt.Rows[i]["PSD_D95"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.PSD_LP].Value = dt.Rows[i]["PSD_LP"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.COATING_PSD_D5].Value = dt.Rows[i]["COATING_PSD_D5"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.COATING_PSD_D50].Value = dt.Rows[i]["COATING_PSD_D50"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.COATING_PSD_D95].Value = dt.Rows[i]["COATING_PSD_D95"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.COATING_PSD_LP].Value = dt.Rows[i]["COATING_PSD_LP"];


                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MICR_MEAN].Value = dt.Rows[i]["MICR_MEAN"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MICR_SD].Value = dt.Rows[i]["MICR_SD"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MICR_PSD_D5].Value = dt.Rows[i]["MICR_PSD_D5"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MICR_PSD_D50].Value = dt.Rows[i]["MICR_PSD_D50"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MICR_PSD_D95].Value = dt.Rows[i]["MICR_PSD_D95"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.MICR_PSD_LP].Value = dt.Rows[i]["MICR_PSD_LP"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CPS_MEAN].Value = dt.Rows[i]["CPS_MEAN"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CPS_SD].Value = dt.Rows[i]["CPS_SD"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CPS_PSD_D5].Value = dt.Rows[i]["CPS_PSD_D5"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CPS_PSD_D50].Value = dt.Rows[i]["CPS_PSD_D50"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CPS_PSD_D95].Value = dt.Rows[i]["CPS_PSD_D95"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CPS_PSD_LP].Value = dt.Rows[i]["CPS_PSD_LP"];






                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.ASPECT_RATIO].Value = dt.Rows[i]["ASPECT_RATIO"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.CIRCULARITY].Value = dt.Rows[i]["CIRCULARITY"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.ROUGHNESS].Value = dt.Rows[i]["ROUGHNESS"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.SYMMETRY].Value = dt.Rows[i]["SYMMETRY"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.INSP_COMMENT].Value = dt.Rows[i]["INSP_COMMENT"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_GBAD028].Value = dt.Rows[i]["LOSS_GBAD028"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_GBAD029].Value = dt.Rows[i]["LOSS_GBAD029"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_GBAD030].Value = dt.Rows[i]["LOSS_GBAD030"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_GBAD031].Value = dt.Rows[i]["LOSS_GBAD031"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_GBAD032].Value = dt.Rows[i]["LOSS_GBAD032"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_GBAD033].Value = dt.Rows[i]["LOSS_GBAD033"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_GBAD034].Value = dt.Rows[i]["LOSS_GBAD034"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_GBAD035].Value = dt.Rows[i]["LOSS_GBAD035"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_GBAD036].Value = dt.Rows[i]["LOSS_GBAD036"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_GBAD037].Value = dt.Rows[i]["LOSS_GBAD037"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_GBAD038].Value = dt.Rows[i]["LOSS_GBAD038"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_GBAD039].Value = dt.Rows[i]["LOSS_GBAD039"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_GBAD040].Value = dt.Rows[i]["LOSS_GBAD040"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_GBAD041].Value = dt.Rows[i]["LOSS_GBAD041"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOSS_GBAD042].Value = dt.Rows[i]["LOSS_GBAD042"];

                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_CREATE_USER].Value = dt.Rows[i]["LOT_CREATE_USER"];
                    spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_JUDGE_USER].Value = dt.Rows[i]["LOT_JUDGE_USER"];

                    //if (cdvOper.Text == "OG05260")  //샘플 검사인경우에만..FTP폴더에 하나씩 파일 체크하는거라 속도가 느림..20250509

                    if (chkFTPFile.Checked == true)
                    {

                        if (dt.Rows[i]["LOT_ID"].ToString().Length >= 6)
                        {
                            string sftpFolderPath = ftpServer + "//" + "GRT" + "//" + dt.Rows[i]["LOT_ID"].ToString().Substring(0, 2) + "//" + dt.Rows[i]["LOT_ID"].ToString().Substring(2, 2) + "//" + dt.Rows[i]["LOT_ID"].ToString().Substring(4, 2) + "//" + dt.Rows[i]["LOT_ID"].ToString();

                            if (IsFtpFolderEmpty(sftpFolderPath) == false)
                            {
                                //  spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].BackColor = Color.Red;
                                spdInspectionData.ActiveSheet.Cells[i, (int)LOT_INFO.LOT_ID].ForeColor = Color.Red;
                            }
                        }

                    }
                }


               



                //MPCF.FitColumnHeader(spdInspectionData);

                return;

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //20250428 김태연 사원 FTP 폴더에 있는거는  색깔로 표시되게 요청.(일단 SAMPLE 검사만 표기되게 )
        private bool IsFtpFolderEmpty(string ftpFolderPath)
        {
            try
            {
                FtpWebRequest req = (FtpWebRequest)WebRequest.Create(ftpFolderPath);
                req.Method = WebRequestMethods.Ftp.ListDirectory;   // 이름만 간단히 받아옴
                req.Credentials = new NetworkCredential(ftpUser, ftpPassword);
                req.UsePassive = true;
                req.KeepAlive = false;
                req.Timeout = 5000;   // 5 초

                using (FtpWebResponse rsp = (FtpWebResponse)req.GetResponse())
                using (StreamReader reader = new StreamReader(rsp.GetResponseStream()))
                {
                    while (!reader.EndOfStream)
                    {
                        string line = reader.ReadLine()?.Trim();

                        // "."  ".." 같은 가상항목, 빈줄은 제외
                        if (!string.IsNullOrEmpty(line) && line != "." && line != "..")
                            return false;          // → 뭔가 있다!
                    }
                }
                return true;                       // → 끝까지 못 찾음 = 비어 있음
            }
            catch (WebException ex)
            {
                // 550 (File unavailable) 등: 폴더 자체가 없거나 접근 불가
                if (ex.Response is FtpWebResponse ftpResp &&
                    ftpResp.StatusCode == FtpStatusCode.ActionNotTakenFileUnavailable)
                {
                    // 폴더가 존재하지 않으면 "비어 있다"가 아니라 "없다"로 구분하고 싶으면 여기서 처리
                    return true;
                }
                // 그 외 오류는 필요에 따라 로그·메시지
                MPCF.ShowMsgBox(ex.Message);
                return true;   // 에러 났을 땐 비어 있다고 가정하거나 예외 다시 throw
            }
        }


        private bool CheckCondition(CSGC.CHECK CHECK)
        {
            try
            {

                //if (MPCF.Trim(cdvWorkPlace.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblWorkPlace.Text + "]");
                //    cdvWorkPlace.Focus();
                //    return false;
                //}

                //if (MPCF.Trim(cdvOper.Text) == "")
                //{
                //    //CMN108 ERROR - 이 필드는 입력이 필요한 필드입니다. 데이타를 입력해 주십시요.
                //    MPCF.ShowMsgBox(MPCF.GetMessage(108) + " [" + lblOper.Text + "]");
                //    cdvOper.Focus();
                //    return false;
                //}

                switch (CHECK)
                {
                    case CSGC.CHECK.VIEW:

                        break;
                }

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
                return false;
            }
        }
        private bool viewInspStatusList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';


            in_node.AddString("SQL", "SELECT KEY_1 AS CODE, "
                                                + "   DATA_1 AS VALUE "
                                              + " FROM MGCMTBLDAT "
                                            + " WHERE FACTORY = '" + MPGV.gsFactory + "' "
                                            + "  AND TABLE_NAME = '" + CSGC.CP_GCM_INSP_STATUS + "' "
                                            + "  AND KEY_1 != 'C' "
                                            + " ORDER BY DATA_3");


            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCR.FillDataView(listView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);



            return true;
        }
        private bool viewOperList(ListView listView)
        {

            TRSNode in_node = new TRSNode("SQL_IN");
            TRSNode out_node = new TRSNode("SQL_OUT");

            MPCF.InitListView(listView);

            MPCR.SetInMsg(in_node);
            in_node.ProcStep = '1';

            in_node.AddString("SQL", "SELECT OPER AS CODE, "
                                                 + "               OPER_DESC AS NAME "
                                                 + "         FROM MWIPOPRDEF "
                                                 + "        WHERE AREA_ID = '" + CSGV.gs_area_grit + "' "
                                                 + "          AND OPER_GRP_2 <> 'NONE' "
                                                 + "         AND OPER_GRP_2 > ' ' "
                                                 + "        ORDER BY OPER");



            do
            {
                if (MPCR.CallService("BAS", "BAS_SQL_Query", in_node, ref out_node) == false)
                {
                    return false;
                }

                MPCR.FillDataView(listView, out_node);

                in_node.SetInt("NEXT_ROW", out_node.GetInt("NEXT_ROW"));
            } while (out_node.GetInt("NEXT_ROW") > 0);

            return true;
        }
        #endregion

        #region " Event Definition"
        private void frmViewInspectionDataGritMp_Load(object sender, EventArgs e)
        {
            try
            {

                rdoJudge.Checked = true;

                this.dtpToJudgeDate.Value = DateTime.Now;
                // this.dtpFromJudgeDate.CustomFormat = " ";
                this.dtpFromJudgeDate.Value = dtpToJudgeDate.Value.AddDays(-30);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnView_Click(object sender, EventArgs e)
        {
            try
            {
                if (CheckCondition(CSGC.CHECK.VIEW) == false)
                    return;

                ViewInspectionDataList();
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void btnExcel_Click(object sender, EventArgs e)
        {
            try
            {
                EXTFUC.SaveExcel(spdInspectionData, "InspectionData(MP)");

            }
            catch (Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }
        private void cdvStatus_ButtonPress(object sender, EventArgs e)
        {
            viewInspStatusList(cdvStatus.GetListView);
            cdvStatus.InsertEmptyRow(0, 1);
        }
        private void dtpFromJudgeDate_ValueChanged(object sender, EventArgs e)
        {
            dtpFromJudgeDate.CustomFormat = "yyyy-MM-dd";
        }
        private void dtpFromJudgeDate_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.Delete:
                    dtpFromJudgeDate.CustomFormat = " ";
                    break;
            }
        }
        private void dtpFromJudgeDate_CloseUp(object sender, EventArgs e)
        {
            dtpFromJudgeDate.CustomFormat = "yyyy-MM-dd";
        }
        private void txtMatDesc_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void txtLotID_KeyPress(object sender, KeyPressEventArgs e)
        {
            try
            {
                if (e.KeyChar == (char)13)
                {
                    btnView.PerformClick();
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvOper_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                viewOperList(cdvOper.GetListView);

                cdvOper.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        private void cdvInspectionType_ButtonPress(object sender, EventArgs e)
        {
            cdvInspectionType.Init();
            MPCF.InitListView(cdvInspectionType.GetListView);
            cdvInspectionType.Columns.Add("InspType", 50, HorizontalAlignment.Left);
            cdvInspectionType.Columns.Add("Desc", 100, HorizontalAlignment.Left);
            cdvInspectionType.SelectedSubItemIndex = 0;
            cdvInspectionType.DisplaySubItemIndex = 1;


            if (BASLIST.ViewGCMDataList(cdvInspectionType.GetListView, '1', CSGC.CP_GCM_INSP_TYPE, -1, null, "", true, -1, -1, null, null) == false)
            {
                return;
            }

            cdvInspectionType.InsertEmptyRow(0, 1);
        }
        private void spdInspectionData_ButtonClicked(object sender, EditorNotifyEventArgs e)
        {
            if (e.Column == (int)LOT_INFO.DETAIL || e.Column == (int)LOT_INFO.IMG)
            {
                try
                {
                    frmTranInspectionRegistrationGRIT popup = new frmTranInspectionRegistrationGRIT();
                    popup.StartPosition = FormStartPosition.CenterParent;


                    popup.g_Dept = CSGV.gs_area_grit; ;
                    //popup.g_DeptDisplay = CSGV.gs_area_grit;
                    popup.g_Oper = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.INSP_OPER].Text;
                    popup.g_OperDisplay = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.INSP_OPER_DESC].Text;
                    popup.g_LotId = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text;
                    popup.g_PopYn = "Y";


                    if (e.Column == (int)LOT_INFO.DETAIL)
                    {
                        popup.g_SelectedTab = 0;
                    }
                    else
                    {
                        popup.g_SelectedTab = 8;
                    }



                    if (popup.ShowDialog() == DialogResult.OK)
                    {
                        popup = null;
                    }
                    else
                        return;
                }
                catch (Exception ex)
                {
                    MPCF.ShowMsgBox(ex.Message);
                }
            }
        }
        private void btnFileManager_Click(object sender, EventArgs e)
        {
            if (spdInspectionData.ActiveSheet.RowCount != 0)
            {




                frmPopFtpUpDown popup = new frmPopFtpUpDown();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.g_PopYn = "Y";
                popup.g_LotId = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text;
                popup.g_Mat_id = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.MAT_ID].Text;
                popup.g_Mat_Desc = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.MAT_DESC].Text;
                popup.g_Area_Id = CSGC.CP_AREA_GRT;
                popup.g_SearchType = "B";

                if (popup.ShowDialog() == DialogResult.OK)
                {

                    popup = null;
                }
                else
                {
                    return;
                }


            }
        }
        private void spdInspectionData_CellDoubleClick(object sender, CellClickEventArgs e)
        {
            if (spdInspectionData.ActiveSheet.RowCount != 0)
            {




                frmPopFtpUpDown popup = new frmPopFtpUpDown();
                popup.StartPosition = FormStartPosition.CenterParent;
                popup.g_PopYn = "Y";
                popup.g_LotId = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.LOT_ID].Text;
                popup.g_Mat_id = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.MAT_ID].Text;
                popup.g_Mat_Desc = spdInspectionData.ActiveSheet.Cells[spdInspectionData.ActiveSheet.ActiveRowIndex, (int)LOT_INFO.MAT_DESC].Text;
                popup.g_Area_Id = CSGC.CP_AREA_GRT;
                popup.g_SearchType = "B";

                if (popup.ShowDialog() == DialogResult.OK)
                {

                    popup = null;
                }
                else
                {
                    return;
                }


            }
        }
        #endregion

        private void chkFTPFile_CheckedChanged(object sender, EventArgs e)
        {
            if (chkFTPFile.Checked)
            {
                MPCF.SaveRegSetting(Application.ProductName, this.Name, chkFTPFile.Name, "Y");
            }
            else
            {
                MPCF.SaveRegSetting(Application.ProductName, this.Name, chkFTPFile.Name, "N");
            }
        }
    }
}
