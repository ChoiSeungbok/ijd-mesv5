using System;
using System.Windows.Forms;
using Miracom.CliFrx;
using Miracom.MESCore;
using Miracom.TRSCore;
using CUS_COM;
using System.IO;


namespace CUS_WIP
{
    public partial class frmTranInventorySurvey : CUS_COM.frmViewForm01
    {
        public frmTranInventorySurvey()
        {
            InitializeComponent();
        }

        #region " Variable Definition "
        string s_base_path = Application.StartupPath + "\\Screen\\";
        string s_screen_file = "Inventory_Survey_Template";
        #endregion

        #region " Constant Definition "
        private enum INV
        {
            SEL,
            LOT_ID,
            MAT_ID,
            QTY,
            OPER,
            VENDOR,
            VENDOR_SITE_ID,
            VENDOR_LOT_NO,
            PROC_STATUS
        }

        private enum MAT
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
        #endregion


        #region " Function Definition "
        private bool Create_Lot()
        {
            TRSNode in_node = new TRSNode("Inventory_Survey_In");
            TRSNode out_node = new TRSNode("Inventory_Survey_Out");

            int i = 0, j = 0;
            int iMatCnt = 0, iWipCnt = 0, iProdCnt = 0, iOutGoingCnt = 0;
            int iCol = 0;

            try
            {
                if(spdLotList_Material.RowCount == 0 && spdLotList_WIP.RowCount == 0 &&  spdLotList_Production.RowCount == 0 && spdLotList_Outgoing.RowCount == 0)
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

                                if (spdLotList.Sheets[j].Cells[i, (int)MAT.LOT_ID].Text == "")
                                {
                                    CSCF.SetPosition(spdLotList, i, (int)MAT.LOT_ID);
                                    MPCF.ShowMsgBox($"{MPCF.GetMessage(108)} : Lot ID");
                                    return false;
                                }
                                else if (spdLotList.Sheets[j].Cells[i, (int)MAT.MAT_ID].Text == "")
                                {
                                    CSCF.SetPosition(spdLotList, i, (int)MAT.MAT_ID);
                                    MPCF.ShowMsgBox($"{MPCF.GetMessage(108)} : Material");
                                    return false;
                                }
                                else if (spdLotList.Sheets[j].Cells[i, (int)MAT.QTY].Text == "")
                                {
                                    CSCF.SetPosition(spdLotList, i, (int)MAT.QTY);
                                    MPCF.ShowMsgBox($"{MPCF.GetMessage(108)} : Quantity");
                                    return false;
                                }
                                else if (spdLotList.Sheets[j].Cells[i, (int)MAT.OPER].Text == "")
                                {
                                    CSCF.SetPosition(spdLotList, i, (int)MAT.OPER);
                                    MPCF.ShowMsgBox($"{MPCF.GetMessage(108)} : Inventory");
                                    return false;
                                }

                                if (j == 0)
                                {
                                    if (spdLotList.Sheets[j].Cells[i, (int)INV.VENDOR].Text == "")
                                    {
                                        CSCF.SetPosition(spdLotList, i, (int)INV.VENDOR);
                                        MPCF.ShowMsgBox($"{MPCF.GetMessage(108)} : Vendor");
                                        return false;
                                    }
                                    else if (spdLotList.Sheets[j].Cells[i, (int)INV.VENDOR_SITE_ID].Text == "")
                                    {
                                        CSCF.SetPosition(spdLotList, i, (int)INV.VENDOR_SITE_ID);
                                        MPCF.ShowMsgBox($"{MPCF.GetMessage(108)} : Vendor Site ID");
                                        return false;
                                    }
                                    else if (spdLotList.Sheets[j].Cells[i, (int)INV.VENDOR_LOT_NO].Text == "")
                                    {
                                        CSCF.SetPosition(spdLotList, i, (int)INV.VENDOR_LOT_NO);
                                        MPCF.ShowMsgBox($"{MPCF.GetMessage(108)} : Vendor Lot No");
                                        return false;
                                    }

                                    iMatCnt++;
                                }
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

                for (j = 0; j < 4; j++)
                {
                    if (j == 0)
                        iCol = (int)INV.PROC_STATUS;
                    else
                        iCol = (int)MAT.PROC_STATUS;

                    if (spdLotList.Sheets[j].RowCount > 0)
                    {
                        spdLotList.ActiveSheet = spdLotList.Sheets[j];

                        for (i = 0; i < spdLotList.Sheets[j].RowCount; i++)
                        {
                            if (Convert.ToBoolean(spdLotList.Sheets[j].Cells[i, (int)MAT.SEL].Value))
                            {
                                in_node.Init();
                                MPCR.SetInMsg(in_node);

                                // 1 : 자재
                                // 2 : 재공
                                // 3 : 제품
                                // 4 : 출하대기
                                in_node.ProcStep =  MPCF.ToChar(j + 1);

                                in_node.AddString("LOT_ID", spdLotList.Sheets[j].Cells[i, (int)MAT.LOT_ID].Value);
                                in_node.AddString("MAT_ID", spdLotList.Sheets[j].Cells[i, (int)MAT.MAT_ID].Value);
                                in_node.AddDouble("QTY", spdLotList.Sheets[j].Cells[i, (int)MAT.QTY].Value);
                                in_node.AddString("OPER", spdLotList.Sheets[j].Cells[i, (int)MAT.OPER].Value);

                                // 자재일때
                                if(in_node.ProcStep == '1')
                                {
                                    in_node.AddString("VENDOR_ID", spdLotList.Sheets[j].Cells[i, (int)INV.VENDOR].Value);
                                    in_node.AddString("VENDOR_SITE_ID", spdLotList.Sheets[j].Cells[i, (int)INV.VENDOR_SITE_ID].Value);
                                    in_node.AddString("VENDOR_LOT_ID", spdLotList.Sheets[j].Cells[i, (int)INV.VENDOR_LOT_NO].Value);
                                }

                                if (MPCR.CallService("CUS_WIP", "CUS_WIP_Inventory_Survey", in_node, ref out_node, true) == false)
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

        private bool UpdateScreenXML(TRSNode out_node)
        {
            FileStream fs = null;
            BinaryWriter bw = null;

            try
            {
                string sPath = $"{s_base_path}{s_screen_file}";
                fs = File.Open($"{sPath}.gzip", FileMode.Create);
                bw = new BinaryWriter(fs);
                byte[] buffer;
                DateTime dt_create_time;

                fs.Flush();
                buffer = out_node.GetBlob(MPGC.MP_BIN_DATA_2);
                bw.Write(buffer);

                bw.Close();
                fs.Close();

                dt_create_time = MPCF.ToDate(out_node.GetString("CREATION_TIME"));
                File.SetCreationTime($"{sPath}.gzip", dt_create_time);

                MPCR.ZipDecompress(sPath);
                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox($"UpdateScreenXML() : {ex.Message}");
                return false;
            }
            finally
            {
                if(bw != null)
                {
                    bw.Dispose();
                    bw = null;
                }

                if (fs != null)
                {
                    fs.Dispose();
                    fs = null;
                }
            }
        }

        private bool ViewScreen()
        {
            string sPathZip;
            string sPathXML;
            string sCreateTime;

            long iFileSize;
            DateTime create_time;
            TRSNode in_node = new TRSNode("View_Screen_IN");
            TRSNode out_node = new TRSNode("View_Screen_OUT");

            try
            {
                sPathZip = $"{s_base_path}{s_screen_file}.gzip";
                if (Directory.Exists(s_base_path) == false)
                {
                    Directory.CreateDirectory(s_base_path);
                }

                FileInfo fi = new FileInfo(sPathZip);

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = '1';
                in_node.AddString("SCREEN_ID", s_screen_file);

                if (fi.Exists == false)
                {
                    in_node.AddString("CREATION_TIME", "19001231000000");
                    in_node.AddInt("FILE_SIZE", 0);
                }
                else
                {
                    create_time = fi.CreationTime;
                    sCreateTime = MPCF.ToStandardTime(create_time, MPGC.MP_CONVERT_DATETIME_FORMAT);
                    iFileSize = fi.Length;

                    in_node.AddString("CREATION_TIME", sCreateTime);
                    in_node.AddInt("FILE_SIZE", iFileSize);
                }

                if (MPCR.CallService("BAS", "BAS_Check_Screen", in_node, ref out_node) == false)
                {
                    return false;
                }

                if(out_node.GetChar("NEED_UPDATE") == 'Y')
                    UpdateScreenXML(out_node);

                sPathXML = $"{s_base_path}{s_screen_file}.xml";
                spdTemplate.Open(sPathXML);
                spdTemplate.Visible = false;

                return true;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox($"ViewScreen() : {ex.Message}");
                return false;
            }
        }

        #endregion

        #region " Event Definition "
        private void btnDownloadTemplate_Click(object sender, EventArgs e)
        {
            if (ViewScreen())
            {
                if (sfdFile.ShowDialog() == DialogResult.OK)
                {
                    spdTemplate.SaveExcelAndShow(sfdFile.FileName);
                }
            }
        }

        private void btnUploadExcel_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofdFile = new OpenFileDialog();

            int i = 0, j = 0;

            try
            {
                ofdFile.Filter = "Excel File |*.xlsx";
                if (ofdFile.ShowDialog() == DialogResult.OK)
                {
                    spdTemplate.OpenExcel(ofdFile.FileName);

                    for (j = 0; j < 4; j++)
                    {
                        if (spdTemplate.Sheets[j].NonEmptyRowCount > 0)
                        {
                            spdLotList.Sheets[j].RowCount = 0;
                            spdLotList.Sheets[j].RowCount = spdTemplate.Sheets[j].NonEmptyRowCount - 1;

                            for (i = 1; i < spdTemplate.Sheets[j].NonEmptyRowCount; i++)
                            {
                                spdLotList.Sheets[j].Cells[i - 1, (int)MAT.SEL].Value = true;
                                spdLotList.Sheets[j].Cells[i - 1, (int)MAT.LOT_ID].Value = spdTemplate.Sheets[j].Cells[i, (int)MAT.LOT_ID - 1].Value;
                                spdLotList.Sheets[j].Cells[i - 1, (int)MAT.MAT_ID].Value = spdTemplate.Sheets[j].Cells[i, (int)MAT.MAT_ID - 1].Value;
                                spdLotList.Sheets[j].Cells[i - 1, (int)MAT.QTY].Value = spdTemplate.Sheets[j].Cells[i, (int)MAT.QTY - 1].Value;
                                spdLotList.Sheets[j].Cells[i - 1, (int)MAT.OPER].Value = spdTemplate.Sheets[j].Cells[i, (int)MAT.OPER - 1].Value;

                                // 자재 일때
                                if(j == 0)
                                {
                                    spdLotList.Sheets[j].Cells[i - 1, (int)INV.VENDOR].Value = spdTemplate.Sheets[j].Cells[i, (int)INV.VENDOR - 1].Value;
                                    spdLotList.Sheets[j].Cells[i - 1, (int)INV.VENDOR_SITE_ID].Value = spdTemplate.Sheets[j].Cells[i, (int)INV.VENDOR_SITE_ID - 1].Value;
                                    spdLotList.Sheets[j].Cells[i - 1, (int)INV.VENDOR_LOT_NO].Value = spdTemplate.Sheets[j].Cells[i, (int)INV.VENDOR_LOT_NO - 1].Value;
                                }
                            }
                        }
                    }
                }
            }
            catch(Exception ex)
            {
                CSCF.ShowMsg(ex.Message);
            }
        }

        private void btnView_Click(object sender, EventArgs e)
        {
            Create_Lot();
        }

        private void btnAddRow_Click(object sender, EventArgs e)
        {
            spdLotList.ActiveSheet.RowCount++;
        }

        private void btnDeleteRow_Click(object sender, EventArgs e)
        {
            int i = 0;
            int iCnt = 0;

            try
            {
                for(i = spdLotList.ActiveSheet.RowCount - 1 ; i > -1; i--)
                {
                    if(Convert.ToBoolean(spdLotList.ActiveSheet.Cells[i, 0].Value))
                    {
                        iCnt++;
                        spdLotList.ActiveSheet.Rows[i].Remove();
                    }
                }

                if(iCnt == 0)
                {
                    // CMN482 INFO - 삭제할 데이터가 없습니다.
                    MPCF.ShowMsgBox(MPCF.GetMessage(482));
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox($"btnDeleteRow_Click() : {ex.Message}");
            }
        }

        private void frmTranInventorySurvey_Load(object sender, EventArgs e)
        {
            try
            {
                // 20.12.21 minjae.go
                MPCF.FitColumnHeader(spdLotList_Outgoing);
                MPCF.FitColumnHeader(spdLotList_Production);
                MPCF.FitColumnHeader(spdLotList_WIP);
                MPCF.FitColumnHeader(spdLotList_Material);
                //
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
        #endregion
    }
}
