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

namespace CUS_WIP
{
    public partial class frmTranCreateTest : CUS_COM.frmViewForm01
    {
        public frmTranCreateTest()
        {
            InitializeComponent();

            InitControl();
        }

        #region " Constant Definition "

        private enum PACK_LOT
        {
            PACK_LOT_ID,
            ORG_LOT_ID,
            FLAG
        }

        #endregion

        #region " Variable Definition "

        #endregion

        #region " Function Defintion "

        private void InitControl()
        {
            try
            {
                btnView.Anchor = AnchorStyles.Top | AnchorStyles.Right;
                btnClose.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        #endregion

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        //PDC 검사성적서(PDC 출하성적서1)
        private void btnPDCReport1_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM3018-001";
                //string reportName = "pip550p_1";              
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }

        }

        //HM 검사성적서(HM 출하성적서)
        private void btnHMReport1_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM3019-001";
                //string reportName = "pip520pa";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //원자재입고라벨
        private void btnMatLabel_Click(object sender, EventArgs e)
        {
            try
            {
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                string file_name = "mtl100p";
               
                //입고 후 원자래
                if (TxtGroupId.Text == "2")
                {
                    label_list = in_node.AddNode("INV_LOT_LIST");
                    label_list.AddString("INV_LOT_ID", txtLotId.Text);

                    label_list = in_node.AddNode("INV_LOT_LIST");
                    label_list.AddString("INV_LOT_ID", txtLotId2.Text);

                    CSCF.ViewLabelList(file_name, in_node, 'I');

                    return;
                }

                in_node.AddString("DLV_LOT_ID", TxtGroupId.Text);

                label_list = in_node.AddNode("INV_LOT_LIST");
                label_list.AddString("INV_LOT_ID", txtLotId.Text);

                label_list = in_node.AddNode("INV_LOT_LIST");
                label_list.AddString("INV_LOT_ID", txtLotId2.Text);

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //CTM 공정라벨(가공라벨 ITEM)
        private void btnCtmOperItemLabel_Click(object sender, EventArgs e)
        {
            try
            {
                //string labelName = "prd106vpitem";
                string labelName = cdvLabelName.Text;

                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");

                label_list = in_node.AddNode("LOT_LIST");
                label_list.AddString("LOT_ID", txtLotId.Text);

                label_list = in_node.AddNode("LOT_LIST");
                label_list.AddString("LOT_ID", txtLotId2.Text);

                CSCF.ViewLabelList(labelName, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //CTM 공정라벨(CELL 라벨)
        private void btnCtmOperCellLabel_Click(object sender, EventArgs e)
        {
            try
            {
                string labelName = cdvLabelName.Text;

                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");

                label_list = in_node.AddNode("CELL_LIST");
                label_list.AddString("GROUP_ID", txtLotId.Text);

                label_list = in_node.AddNode("CELL_LIST");
                label_list.AddString("GROUP_ID", txtLotId2.Text);

                CSCF.ViewLabelList(labelName, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //CTM 공정라벨(가공라벨 LOT)
        private void btnCtmOperLotLabel_Click(object sender, EventArgs e)
        {
            try
            {
                string labelName = cdvLabelName.Text;

                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");

                label_list = in_node.AddNode("LOT_LIST");
                label_list.AddString("LOT_ID", txtLotId.Text);

                label_list = in_node.AddNode("LOT_LIST");
                label_list.AddString("LOT_ID", txtLotId2.Text);

                CSCF.ViewLabelList(labelName, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRIT 공정라벨
        private void btnGritOperLabel_Click(object sender, EventArgs e)
        {
            try
            {
                string labelName = cdvLabelName.Text;

                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");

                label_list = in_node.AddNode("LOT_LIST");
                label_list.AddString("LOT_ID", txtLotId.Text);

                label_list = in_node.AddNode("LOT_LIST");
                label_list.AddString("LOT_ID", txtLotId2.Text);

                CSCF.ViewLabelList(labelName, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //HM 공정라벨
        //현재無 라벨 개발혹은 기존 다른사업부꺼 같이써야함
        private void btnHmOperLabel_Click(object sender, EventArgs e)
        {
            string sFileName = "";
            TRSNode in_node = new TRSNode("move_Lot_In");
            MPCR.SetInMsg(in_node);

            in_node.AddString("BOX_ID", TxtGroupId.Text);
            in_node.AddString("FINAL_BOX_ID", TxtGroupId.Text);
            sFileName = "prd205p";
            CSCF.ViewLabelList(sFileName, in_node, 'B');
        }

        //PDC 공정라벨
        private void btnPdcOperLabel_Click(object sender, EventArgs e)
        {
            try
            {
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                // string file_name = "prd205ppdc";
                string file_name = cdvLabelName.Text;

                MPCR.SetInMsg(in_node);

                label_list = in_node.AddNode("LOT_LIST");
                label_list.AddString("LOT_ID", txtLotId.Text);

                label_list = in_node.AddNode("LOT_LIST");
                label_list.AddString("LOT_ID", txtLotId2.Text);

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //CTM 출하라벨(66x90)
        private void btnCtmShipLabel_Click(object sender, EventArgs e)
        {
            try
            {
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                //string file_name = "mtl900hm3p";
                string file_name = cdvShipLabel.Text;

                MPCR.SetInMsg(in_node);

                for(int i=0;i<spdShipLabel_Sheet1.RowCount;i++)
                {
                    label_list = in_node.AddNode("PACK_LOT_LIST");
                    label_list.AddString("PACK_LOT_ID", spdShipLabel_Sheet1.Cells[i,(int)PACK_LOT.PACK_LOT_ID].Value);
                    label_list.AddString("ORG_LOT_ID", spdShipLabel_Sheet1.Cells[i, (int)PACK_LOT.ORG_LOT_ID].Value);
                    label_list.AddChar("MESH_FLAG", spdShipLabel_Sheet1.Cells[i, (int)PACK_LOT.FLAG].Value);
                }
                CSCF.ViewLabelList(file_name, in_node);

                /*
                for (int i = 0; i < spdShipLabel_Sheet1.RowCount; i++)
                {
                    label_list = in_node.AddNode("LOT_LIST");
                    label_list.AddString("LOT_ID", spdShipLabel_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value);
                }
                CSCF.ViewLabelList(file_name, in_node, 'D');
                */
                /*
                for (int i = 0; i < spdShipLabel_Sheet1.RowCount; i++)
                {
                    label_list = in_node.AddNode("LOT_LIST");
                    label_list.AddString("LOT_ID", spdShipLabel_Sheet1.Cells[i, (int)PACK_LOT.PACK_LOT_ID].Value);
                }
                CSCF.ViewLabelList(file_name, in_node, 'E');
                */
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //CTM 출하라벨(66x90)2
        private void btnCtmShipLabel2_Click(object sender, EventArgs e)
        {
            try
            {
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                //string file_name = "mtl900hm3_1p";
                string file_name = cdvLabelName.Text;

                MPCR.SetInMsg(in_node);

                label_list = in_node.AddNode("PACK_LOT_LIST");
                label_list.AddString("PACK_LOT_ID", txtLotId.Text);
                label_list.AddString("ORG_LOT_ID", txtLotId2.Text);

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //CTM 출하라벨(30x85_INSERT제품)
        private void btnCtmShipInsertLabel_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CSHP2004-002";

                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                //string file_name = "mtl900hm6p";
                string file_name = cdvLabelName.Text;

                MPCR.SetInMsg(in_node);

                label_list = in_node.AddNode("PACK_LOT_LIST");
                label_list.AddString("PACK_LOT_ID", txtLotId.Text);
                label_list.AddString("ORG_LOT_ID", txtLotId2.Text);

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //HM 출하라벨(45x55)
        //합산수량,분할수량 라벨이 각각 나와야함
        private void btnHmShipLabel1_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CSHP2004-003";

                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                //string file_name = "mdprd860phmbp";
                string file_name = cdvLabelName.Text;

                MPCR.SetInMsg(in_node);

                label_list = in_node.AddNode("PACK_LOT_LIST");
                label_list.AddString("PACK_LOT_ID", txtLotId.Text);
                label_list.AddString("ORG_LOT_ID", txtLotId2.Text);

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //HM 출하라벨(90x22)
        //합산수량,분할수량 라벨이 각각 나와야함
        private void btnHmShipLabel2_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CSHP2004-003";

                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                //string file_name = "mdprd860phmap";
                string file_name = cdvLabelName.Text;

                MPCR.SetInMsg(in_node);

                label_list = in_node.AddNode("PACK_LOT_LIST");
                label_list.AddString("PACK_LOT_ID", txtLotId.Text);
                label_list.AddString("ORG_LOT_ID", txtLotId2.Text);

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //HM 출하라벨(90x95)
        private void btnHmShipLabel3_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CSHP2004-004";

                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                //string file_name = "mtl215p_8";
                string file_name = cdvLabelName.Text;

                MPCR.SetInMsg(in_node);

                label_list = in_node.AddNode("PACK_LOT_LIST");
                label_list.AddString("PACK_LOT_ID", txtLotId.Text);
                label_list.AddString("ORG_LOT_ID", txtLotId2.Text);

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRIT 출하라벨(76x26)
        //기본은 포장수량 라벨이나 동일양식의 잔량라벨도출력가능해야함
        private void btnGritShipLabel1_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CSHP2004-005";

                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                //string file_name = "840Sample";
                string file_name = cdvLabelName.Text;

                MPCR.SetInMsg(in_node);

                label_list = in_node.AddNode("PACK_LOT_LIST");
                label_list.AddString("PACK_LOT_ID", txtLotId.Text);
                label_list.AddString("ORG_LOT_ID", txtLotId2.Text);

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRIT 출하라벨(120x90)
        private void btnGritShipLabel2_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CSHP2004-009";

                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                string file_name = cdvLabelName.Text;
                //string file_name = "prd840grtp3";

                MPCR.SetInMsg(in_node);

                label_list = in_node.AddNode("PACK_LOT_LIST");
                label_list.AddString("PACK_LOT_ID", txtLotId.Text);
                label_list.AddString("ORG_LOT_ID", txtLotId2.Text);

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRIT 출하라벨(62x43)
        private void btnGritShipLabel3_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CSHP2004-010";

                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                //string file_name = "prd840grtp5";
                string file_name = cdvLabelName.Text;

                MPCR.SetInMsg(in_node);

                label_list = in_node.AddNode("PACK_LOT_LIST");
                label_list.AddString("PACK_LOT_ID", txtLotId.Text);
                label_list.AddString("ORG_LOT_ID", txtLotId2.Text);

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRIT 출하라벨(62x43_QR)
        private void btnGritShipQrLabel_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CSHP2004-006";

                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                //string file_name = "prd840grtp2_DM";
                string file_name = cdvLabelName.Text;

                MPCR.SetInMsg(in_node);

                label_list = in_node.AddNode("PACK_LOT_LIST");
                label_list.AddString("PACK_LOT_ID", txtLotId.Text);
                label_list.AddString("ORG_LOT_ID", txtLotId2.Text);

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //PDC 출하라벨(92x88)
        private void btnPdcShipLabel1_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CSHP2004-007";
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                //string file_name = "mtl900hm5p";
                string file_name = cdvLabelName.Text;

                MPCR.SetInMsg(in_node);

                label_list = in_node.AddNode("PACK_LOT_LIST");
                label_list.AddString("PACK_LOT_ID", txtLotId.Text);
                label_list.AddString("ORG_LOT_ID", txtLotId2.Text);

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //PDC 출하라벨(49x55)
        private void btnPdcShipLabel2_Click(object sender, EventArgs e)
        {
            try
            {                              
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                //string file_name = "mtl900hm9p";
                string file_name = cdvLabelName.Text;

                MPCR.SetInMsg(in_node);

                label_list = in_node.AddNode("PACK_LOT_LIST");
                label_list.AddString("PACK_LOT_ID", txtLotId.Text);
                label_list.AddString("ORG_LOT_ID", txtLotId2.Text);

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //T-CARD조회
        private void btnOrder_Click(object sender, EventArgs e)
        {           
            try
            {             
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                //string file_name = cdvLabelName.Text;

                string file_name = "t_card";

                MPCR.SetInMsg(in_node);

                label_list = in_node.AddNode("LOT_LIST");
                label_list.AddString("LOT_ID", txtLotId.Text);

                if (MPCF.Trim(txtLotId2.Text) != "")
                {
                    label_list = in_node.AddNode("LOT_LIST");
                    label_list.AddString("LOT_ID", txtLotId2.Text);
                }

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRT MP일반성적서1(GRT MP 기본성적서1)
        private void btnGritMPGeneral1_Click(object sender, EventArgs e)
        {
            try
            {
                //string reportName = "pip525p";
                //string reportNo = "Q202009150002";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRT MP 기본성적서1(SPEC)
        private void btnGritMPGeneralSpec1_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM3005-002";
                //string reportName = "pip525p_4";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRT MP일반성적서2(GRT MP 기본성적서2)
        private void btnGritMPGeneral2_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM3006-001";
                //string reportName = "pip525p_2";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRT MP 기본성적서2(SPEC)
        private void btnGritMPGeneralSpec2_Click_1(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM3006-002";
                //string reportName = "pip525p_5";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRT MP특수성적서1
        private void btnGritMPSpecial1_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM3007-001";
                //string reportName = "pip525p_8";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRT MP특수성적서2
        private void btnGritMPSpecial2_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM3007-001";
                //string reportName = "pip525p_9";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRT SPEC 성적서
        private void btnGritSpec_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM2102-010";
                //string reportName = "pip501p";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRT 일반성적서
        private void btnGritGeneral_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM3014-001";
                //string reportName = "pip502p";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRT HLT-TI성적서
        private void btnGritHLTTl_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM2102-010";
                //string reportName = "pip503p";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRT IMAGE성적서
        private void btnGritImage_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM3009-003";
                //string reportName = "pip504p";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRT SPEC 성적서(형상)
        private void btnGritSpecType_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM2102-012";
                //string reportName = "pip505p";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRT Asahi C50성적서
        private void btnGritAsahiC50_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM2102-010";
                //string reportName = "pip506p";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRT IMAGE성적서(TTI無)
        private void btnGritImageTTl_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM3009-006";
                //string reportName = "pip508p";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //GRT MAGE성적서(SPEC)
        private void btnGritMageSpec_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM3009-007";
                //string reportName = "pip509p";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //CTM 검사성적서 1(CTM 일반 라운드 제품 성적서)
        private void btnCTMReport1_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM3016-001";
                //string reportName = "pip510p";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //CTM 검사성적서 2(CTM 절단품 성적서)
        private void btnCTMReport2_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM3017-001";
                //string reportName = "pip511p";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //CTM MAPAL 라운드 성적서
        private void btnCTMReport3_Click(object sender, EventArgs e)
        {
            try
            {
                //string sView_Id = "CQCM3017-002";
                //string reportName = "pip512p";
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvLabelName_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvLabelName.Init();
                MPCF.InitListView(cdvLabelName.GetListView);  
                cdvLabelName.Columns.Add("Size", 50, HorizontalAlignment.Left);
                cdvLabelName.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvLabelName.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvLabelName.SelectedSubItemIndex = 2;
                cdvLabelName.DisplaySubItemIndex = 1;
 
                if (COM_LIST.ViewLabelGCMList(cdvLabelName.GetListView, cdvDept.Text, CSGC.CP_LABEL_TYPE_OPER) == false)
                {
                    return;
                }

                cdvLabelName.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvDept_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvDept.Init();
                MPCF.InitListView(cdvDept.GetListView);
                cdvDept.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvDept.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvDept.SelectedSubItemIndex = 0;
                cdvDept.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvDept.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                {
                    return;
                }

                //특정 사업부인 경우 Tag에 저장된 사업부를 제외하고 보이지 않기 위해
                if (MPCF.Trim(cdvDept.Tag) != "")
                {
                    for (int i = cdvDept.GetListView.Items.Count; i > 0; i--)
                    {
                        if (cdvDept.GetListView.Items[i - 1].SubItems[0].Text != cdvDept.Tag.ToString())
                        {
                            cdvDept.GetListView.Items[i - 1].Remove();
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        //T-Card Multi조회
        private void btnTCardM_Click(object sender, EventArgs e)
        {
            try
            {
                TRSNode label_list;
                TRSNode in_node = new TRSNode("print_label_In");
                string file_name = "t_card_b";

                MPCR.SetInMsg(in_node);

                label_list = in_node.AddNode("LOT_LIST");
                label_list.AddString("LOT_ID", TxtGroupId.Text);

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnMove_Click(object sender, EventArgs e)
        {
            try
            {
               
                string file_name = "prd702q";

               TRSNode in_node = new TRSNode("print_label_In");

               MPCR.SetInMsg(in_node);

              in_node.AddString("MOVE_ID", TxtGroupId.Text);

               CSCF.ViewLabelList(file_name, in_node);

               /*
                TRSNode in_node = new TRSNode("confirm_Issue_Request_In");
                TRSNode Req_Lot_list;

                MPCR.SetInMsg(in_node);

                in_node.AddString("REQ_NO",TxtGroupId.Text);


                Req_Lot_list = in_node.AddNode("REQ_LOT_LIST");
                Req_Lot_list.AddString("REQ_LOT_ID", txtLotId.Text);

                Req_Lot_list = in_node.AddNode("REQ_LOT_LIST");
                Req_Lot_list.AddString("REQ_LOT_ID", txtLotId2.Text);

                //라벨 출력
                CSCF.ViewLabelList(file_name, in_node, 'I');
                */
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnDlv_Click(object sender, EventArgs e)
        {
            try
            {
                string file_name = "mtl100pa";

                TRSNode in_node = new TRSNode("print_label_In");

                MPCR.SetInMsg(in_node);

                in_node.AddString("DLV_LOT_ID", txtLotId.Text);

                CSCF.ViewLabelList(file_name, in_node);
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvShipLabel_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvShipLabel.Init();
                MPCF.InitListView(cdvShipLabel.GetListView);
                cdvShipLabel.Columns.Add("Size", 50, HorizontalAlignment.Left);
                cdvShipLabel.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvShipLabel.Columns.Add("Code", 50, HorizontalAlignment.Left);
                cdvShipLabel.SelectedSubItemIndex = 2;
                cdvShipLabel.DisplaySubItemIndex = 1;

                if (COM_LIST.ViewLabelGCMList(cdvShipLabel.GetListView, cdvAreaID.Text, CSGC.CP_LABEL_TYPE_SHIP) == false)
                {
                    return;
                }

                cdvShipLabel.InsertEmptyRow(0, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnRowAdd_Click(object sender, EventArgs e)
        {
            try
            {
                spdShipLabel_Sheet1.RowCount++;
            }
            catch(Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void btnRowDel_Click(object sender, EventArgs e)
        {
            int iRow = 0;
            try
            {
                iRow = spdShipLabel_Sheet1.RowCount - 1;
                spdShipLabel_Sheet1.RemoveRows(iRow, 1);
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void cdvAreaID_ButtonPress(object sender, EventArgs e)
        {
            try
            {
                cdvAreaID.Init();
                MPCF.InitListView(cdvAreaID.GetListView);
                cdvAreaID.Columns.Add("Operation", 50, HorizontalAlignment.Left);
                cdvAreaID.Columns.Add("Desc", 100, HorizontalAlignment.Left);
                cdvAreaID.SelectedSubItemIndex = 0;
                cdvAreaID.DisplaySubItemIndex = 1;

                if (BASLIST.ViewGCMDataList(cdvAreaID.GetListView, '1', MPGC.MP_RAS_AREA_CODE) == false)
                {
                    return;
                }

                //특정 사업부인 경우 Tag에 저장된 사업부를 제외하고 보이지 않기 위해
                if (MPCF.Trim(cdvAreaID.Tag) != "")
                {
                    for (int i = cdvAreaID.GetListView.Items.Count; i > 0; i--)
                    {
                        if (cdvAreaID.GetListView.Items[i - 1].SubItems[0].Text != cdvAreaID.Tag.ToString())
                        {
                            cdvAreaID.GetListView.Items[i - 1].Remove();
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
    }
}
