using System;
using System.Windows.Forms;
using Miracom.CliFrx;
using Miracom.MESCore;


using Miracom.TRSCore;
using Miracom.DNMCore;
using System.Data;

namespace CUS_COM
{
    public partial class frmTranForm05 : Miracom.CliFrx.BaseForm03
    {
        public frmTranForm05()
        {
            InitializeComponent();
            chkFavorite.Anchor = AnchorStyles.Top | AnchorStyles.Left;
        }

        public bool IsActivated { get; set; }
        public Controls.udcScanTextBox ScanTextBox { get; set; }

        private void frmTranForm05_Load(object sender, EventArgs e)
        {
            string formName = this.Name;
            //Clipboard.SetText(formName);
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
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
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }

        private void frmTranForm05_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (!SaveRegistry.ContainsKey(cdvDept.Name))
                this.SaveRegistry.Add(cdvDept.Name, cdvDept.Text + ';' + cdvDept.DisplayText);
        }

        protected override void OnActivated(EventArgs e)
        {
            IsActivated = true;
            base.OnActivated(e);


            DataTable dt = null;
            FuncNameSearch(ref dt, ' ');
            chkFavorite.Anchor = AnchorStyles.Top | AnchorStyles.Left;
            this.chkFavorite.CheckedChanged += new System.EventHandler(this.chkFavorite_CheckedChanged);
        }

        protected override void OnDeactivate(EventArgs e)
        {
            try
            {
                IsActivated = false;
                base.OnDeactivate(e);
            }
            catch
            {
            }
        }



        #region " Favorite add "
        //20210712 즐겨찾기 추가
        private void chkFavorite_CheckedChanged(object sender, EventArgs e)
        {
            if (chkFavorite.Checked == true)
            {
                Update_Favorites(MPGC.MP_STEP_CREATE);
            }
            else
            {
                Update_Favorites(MPGC.MP_STEP_DELETE);
            }

            //Add by J.S. 2009.02.13
            //favorites수정시 LotListMain, ResourceListMain시 submenu를 refresh하기위한 변수 
            MPGV.gbFavoriteChangeForLotListMain = true;
            MPGV.gbFavoriteChangeForResourceListMain = true;

            MPGV.gIMdiForm.FavoritesRefresh();
        }



        private void FuncNameSearch(ref DataTable dt, char cStep_Flag)
        {
            try
            {


                TPDR.DirectViewCond[] dvcArgu = new TPDR.DirectViewCond[4];
                string sSql = "";

                dvcArgu[0].sCondition_ID = "FACTORY";
                dvcArgu[0].sCondition_Value = MPGV.gsFactory;

                dvcArgu[1].sCondition_ID = "FUNC_NAME";
                dvcArgu[1].sCondition_Value = this.Name.ToString();



                dvcArgu[2].sCondition_ID = "PROGRAM_ID";
                dvcArgu[2].sCondition_Value = MPGV.gsProgramID;

                dvcArgu[3].sCondition_ID = "USER_ID";
                dvcArgu[3].sCondition_Value = MPGV.gsUserID;


                if (TPDR.GetDataOne("", ref dt, "BAS-03", dvcArgu, false, false, ref sSql) == false)
                {
                    if (dt != null)
                        dt.Dispose();

                    GC.Collect();
                    if (cStep_Flag != MPGC.MP_STEP_CREATE && cStep_Flag != MPGC.MP_STEP_DELETE)
                    {
                        chkFavorite.Checked = false;
                    }
                    return;
                }

                if (cStep_Flag != MPGC.MP_STEP_CREATE && cStep_Flag != MPGC.MP_STEP_DELETE)
                {
                    if (MPCF.ToInt(dt.Rows[0]["INSERT_YN"]) > 0)
                    {
                        chkFavorite.Checked = true;
                    }
                    else
                    {
                        chkFavorite.Checked = false;
                    }
                }


                return;
            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }


        private void Update_Favorites(char cStep_Flag)
        {
            try
            {

                string sPgmID = MPGV.gsProgramID;
                DataTable dt = null;

                TRSNode in_node = new TRSNode("UPDATE_FAVORITES_IN");
                TRSNode out_node = new TRSNode("CMN_OUT");

                //System.Windows.Forms.ColumnHeader;



                FuncNameSearch(ref dt, cStep_Flag);

                //MPGC.MP_STEP_DELETE
                //MPGC.MP_STEP_CREATE;

                if (cStep_Flag == MPGC.MP_STEP_CREATE && MPCF.ToInt(dt.Rows[0]["INSERT_YN"]) > 0)
                {
                    //이미 즐겨찾기 되어있음 리턴.
                    return;
                }

                if (cStep_Flag == MPGC.MP_STEP_DELETE && MPCF.ToInt(dt.Rows[0]["INSERT_YN"]) == 0)
                {
                    //이미 즐겨찾기 없음 리턴.
                    return;
                }

                MPCR.SetInMsg(in_node);
                in_node.ProcStep = cStep_Flag;
                in_node.AddString("PROGRAM_ID", sPgmID);
                in_node.AddInt("SEQ_NUM", MPCF.ToInt(dt.Rows[0]["SEQ_NUM"]));
                in_node.AddString("FUNC_NAME", dt.Rows[0]["FUNC_NAME"]);
                in_node.AddString("USER_FUNC_DESC", dt.Rows[0]["USER_FUNC_DESC"]);



                if (MPCR.CallService("SEC", "SEC_Update_Favorites", in_node, ref out_node) == false)
                {
                    return;
                }

            }
            catch (Exception ex)
            {
                MPCF.ShowMsgBox(ex.Message);
            }
        }
            #endregion


        }
    }
